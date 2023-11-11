#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <cmath>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

set< pair<int, int> > edgeMarks;

void resize(GLsizei w, GLsizei h) {
    if (h == 0) {
        h = 1;
    }

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
        glOrtho(0.0f, 200.0f, 0.0f, 200.f * h / w, 1.0f, -1.0f);
    }
    else {
        glOrtho(0.0f, 200.0f * w / h, 0.0f, 200.0f, 1.0f, -1.0f);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void drawPixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

// check 判断(x1, y1)是否是三点之中的极值点
bool check(int x0, int y0, int x1, int y1, int x2, int y2) {
    // x1 是否在中间？
    if (x1 >= x0 && x1 >= x2) {
        return false;
    }
    if (x1 <= x0 && x1 <= x2) {
        return false;
    }

    if (y0 > y1 && y2 > y1) {
        return true;
    }

    if (y0 < y1 && y2 < y1) {
        return true;
    }

    return false;
}

// BresenhamLine
void BresenhamLine(vector<int> p0, vector<int> p1) {
    int x0 = p0[0], y0 = p0[1],
        x1 = p1[0], y1 = p1[1];

    // 两种特殊情况: x0 == x1 || y0 == y1
    if (x0 == x1) {
        if (y0 > y1) {
            swap(y0, y1);
        }
        for (int i = y0; i <= y1; i++) {
            drawPixel(x0, i);
        }
        return;
    }
    else if (y0 == y1) {
        drawPixel(x0, y0);
        drawPixel(x1, y1);
        edgeMarks.insert(make_pair(x0, y0));
        edgeMarks.insert(make_pair(x1, y1));
        return;
    }

    int kRev = (y1 - y0) / (x1 - x0);

    bool isKGT1 = false; // 1 : K is greater than 1
    bool isKNeg = (y1 - y0) * (x1 - x0) >= 0 ? false : true; // 1 : K is negative
    if (abs(kRev) >= 1) { // |k| > 1
        swap(x0, y0);
        swap(x1, y1);
        isKGT1 = true;
    }

    if (isKGT1) {
        if (isKNeg) {
            if (y0 < y1) {
                swap(y0, y1);
                swap(x0, x1);
            }
        }
        else {
            if (y0 > y1) {
                swap(y0, y1);
                swap(x0, x1);
            }
        }

    }
    else {
        if (x0 > x1) {
            swap(y0, y1);
            swap(x0, x1);
        }
    }

    int x = x0, y = y0;
    int dx = x1 - x0, dy = y1 - y0;
    if (isKNeg) {
        dy = -dy;
    }

    int e = -dx;

    while (x <= x1) {
        if (isKGT1) {
            drawPixel(y, x);
            edgeMarks.insert(make_pair(y, x));
        }
        else {
            drawPixel(x, y);
            edgeMarks.insert(make_pair(x, y));
        }
        x++;
        e += 2 * dy;

        if (e > 0) {
            if (isKNeg) {
                y--;
            }
            else {
                y++;
            }
            e -= 2 * dx;
        }
    }


}

void edgeMarkFilling(vector< vector<int> > points) {
    // get y_min & y_max
    int y_min = points[0][1], y_max = points[0][1];
    int x_min = points[0][0], x_max = points[0][0];

    // draw lines
    for (unsigned int i = 1; i < points.size(); i++) {
        BresenhamLine(points[i - 1], points[i]);
        y_min = min(points[i][1], y_min);
        y_max = max(points[i][1], y_max);
        x_min = min(points[i][0], x_min);
        x_max = max(points[i][0], x_max);

        // 局部最低点 —— 0 个重叠的交点，局部最高点 —— 0个
        if (i < points.size() - 1) {
            if (check(points[i - 1][0], points[i - 1][1], points[i][0], points[i][1], points[i + 1][0], points[i + 1][1])) {
                edgeMarks.erase(make_pair(points[i][0], points[i][1]));
            }
        }

    }
    BresenhamLine(points[0], points[points.size() - 1]);
    int lastpoint = points.size() - 1;
    if (check(points[lastpoint - 1][0], points[lastpoint - 1][1], points[lastpoint][0], points[lastpoint][1], points[0][0], points[0][1])) {
        edgeMarks.erase(make_pair(points[lastpoint][0], points[lastpoint][1]));
    }
    if (check(points[lastpoint][0], points[lastpoint][1], points[0][0], points[0][1], points[1][0], points[1][1])) {
        edgeMarks.erase(make_pair(points[0][0], points[0][1]));
    }

    // filling
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_POINTS);
    for (int i = y_max; i >= y_min; i--) {
        bool isInside = false;
        for (int j = x_min; j < x_max; j++) {
            if (edgeMarks.count(make_pair(j, i)) == 1) {
                isInside = !isInside;
            }
            if (isInside) {
                glVertex2i(j, i);
                // cout << j << ' ' << i << endl;
            }
        }
    }
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(1, 0, 0);

    vector< vector<int> > points(3);
    vector<int> p0(2), p1(2), p2(2), p3(2), p4(2), p5(2), p6(2);
    p0[0] = 40, p0[1] = 40;
    p1[0] = 10, p1[1] = 10;
    p2[0] = 70, p2[1] = 10;

    points[0] = p0;
    points[1] = p1;
    points[2] = p2;

    edgeMarkFilling(points);

    glutSwapBuffers();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

    glutCreateWindow("EdgeMarkFilling");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);

    // setRC
    glClearColor(1, 1, 1, 1);

    glutMainLoop();

    return 0;
}