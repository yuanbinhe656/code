#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>
using namespace std;

int m0, n0, m1, n1;//声明全局变量
int mm, nn; //椭圆的中心点
int a, b; //椭圆的长半轴和短半轴
int winwidth = 800, winheight = 500;//窗口长宽
void DrawOval(); //实际上画圆的函数
void MidpointOval(int, int, int, int); //椭圆的中点算法

//实际上画圆的函数
void DrawOval() {
	MidpointOval(mm, nn, a, b); //椭圆的中点算法
}

//辅助画椭圆算法
void OvalPoints(int x, int y, int x0, int y0)
{
	glVertex2i(x + x0, y + y0);
	glVertex2i(-x + x0, y + y0);
	glVertex2i(x + x0, -y + y0);
	glVertex2i(-x + x0, -y + y0);
}

/*椭圆的中点算法*/
void MidpointOval(int x0, int y0, int a, int b)
{
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口显示内容
	glBegin(GL_POINTS);

	int x = 0, y = b;
	int a2 = a * a, b2 = b * b;
	float d1 = b2 + a2 * (0.25 - b);
	float d2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;

	OvalPoints(x, y, x0, y0);

	/*方法一*/
	while (a2 * y > b2 * x) { //注意！！！
		glBegin(GL_POINTS);
		OvalPoints(x, y, x0, y0);
		x++;
		//++x;
		if (d1 < 0) {
			d1 += b2 * (2 * x + 3);
		}
		else {
			y--;
			//--y;
			d1 += b2 * (2 * x + 3) + a2 * (2 - 2 * y);
		}

	}
	x--; y++;
	while (y > 0) {
		y--;
		if (d2 >= 0) { //取正下方的点
			d2 += a2 * (3 - 2 * y);
		}
		else {
			x++;
			d2 += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
		}
		glBegin(GL_POINTS);
		OvalPoints(x, y, x0, y0);
	}

	/*方法二*/
	//int flag = 0; //分成上下部分的标志
	//while (y>=0) {
	//	glBegin(GL_POINTS);
	//	OvalPoints(x, y, x0, y0);

	//	if (flag == 0) {
	//		if (a2*y<b2*x) flag = 1;
	//	}

	//	if (flag == 0) { //上半部分
	//		x++;
	//		if (d1 < 0) {
	//			d1 += b2 * (2 * x + 3);
	//		}
	//		else {
	//			y--;
	//			d1 += b2 * (2 * x + 3) + a2 * (2 - 2 * y);
	//		}
	//	}
	//	else { //下半部分
	//		y--;
	//		if (d2 >= 0) { //取正下方的点
	//			d2 += a2 * (3 - 2 * y);
	//		}
	//		else {
	//			x++;
	//			d2 += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
	//		}
	//	}
	//}

	glEnd();
	glFlush();
}


//鼠标拖动
void dragmouse(int x, int y) {
	m1 = x;
	n1 = y;
	mm = (m0 + m1) / 2;
	nn = (n0 + n1) / 2;
	a = abs(m1 - m0) / 2;
	b = abs(n1 - n0) / 2;
	DrawOval(); //画线
	glFlush();
}

//鼠标监听，画点
void mymouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		m1 = x;
		n1 = y;
		mm = (m0 + m1) / 2;
		nn = (n0 + n1) / 2;
		a = abs(m1 - m0) / 2;
		b = abs(n1 - n0) / 2;
		printf("椭圆起始点坐标为：（%d，%d），长半轴为：%d，短半轴为：%d\n", m0, n0, a, b);
		DrawOval();
		glFlush();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //按下鼠标，是起点
		m0 = x;
		n0 = y;
	}
}

void init() {
	glClearColor(1, 1, 1, 1);//设置绘制窗口颜色为白色
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口内容
	glPointSize(3.0f);//设置点的大小
	/*设置为投影类型模式和其他观察参数*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winwidth, winheight, 0);
	glColor3f(0, 1, 1);//设置画点的颜色
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);//初始化
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//设置绘制模式
	glutInitWindowPosition(350, 200);//设置窗口出现的位置
	glutInitWindowSize(winwidth, winheight);//设置窗口大小
	glutCreateWindow("画椭圆");//创建窗口
	init();

	glutDisplayFunc(DrawOval);//绘制回调函数,glut机制，它觉得需要重新绘制的时候就会执行
	glutMouseFunc(mymouse);//鼠标监听回调函数
	glutMotionFunc(dragmouse);//鼠标拖动
	glutMainLoop();
}
