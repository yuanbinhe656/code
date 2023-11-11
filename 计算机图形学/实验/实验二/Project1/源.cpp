#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>

using namespace std;

int m0, n0, m1, n1;//声明全局变量，圆的坐标
float r; //圆的半径
int a, b; //椭圆的长半轴和短半轴
//int winwidth = 1024, winheight = 720;//窗口长宽
int winwidth = 800, winheight = 500;//窗口长宽
void DrawCircle(); //实际上画圆的函数
void MidpointCircle(int, int, int);
void MidpointCircle_pro(int, int, int);
void BresenhamCircle(int, int, int);

//数据交换
void swap(GLint& a, GLint& b) { GLint t = a; a = b; b = t; }

//在屏幕上画一个点
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

//实际上画圆的函数
void DrawCircle() {
	MidpointCircle(m0, n0, r);//中点划线法
	//MidpointCircle_pro(m0, n0, r);//中点划线法
	//BresenhamCircle(m0, n0, r);//BresenhamLine算法
}

//辅助画圆算法
void CirclePoints(int x, int y, int x0, int y0)
{
	glVertex2i(x + x0, y + y0); glVertex2i(y + x0, x + y0);
	glVertex2i(-x + x0, y + y0); glVertex2i(y + x0, -x + y0);
	glVertex2i(x + x0, -y + y0); glVertex2i(-y + x0, x + y0);
	glVertex2i(-x + x0, -y + y0); glVertex2i(-y + x0, -x + y0);
}

/*中心画圆法*/
void MidpointCircle(int x0, int y0, int r)
{
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口显示内容

	int x, y;
	x = 0, y = r;
	float d = 1.25 - r;
	//int d = 1 - r; //消除浮点数，将d改为整数
	glVertex2i(x0, y0);

	CirclePoints(x, y, x0, y0);
	while (x <= y)
	{
		if (d < 0)
			d += 2 * x + 3;
		else
		{
			d += 2 * (x - y) + 5;
			y--;
		}
		x++;
		glBegin(GL_POINTS);
		CirclePoints(x, y, x0, y0);
	}

	glEnd();
	glFlush();
}

/*中心画圆法的改进:消除浮点数*/
void MidpointCircle_pro(int x0, int y0, int r)
{
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口显示内容

	int x = 0, y = r;
	int d = 3 - 2 * r;
	glVertex2i(x0, y0);

	CirclePoints(x, y, x0, y0);
	while (x <= y) {
		CirclePoints(x, y, x0, y0);
		x++;

		if (d < 0)
			d += 4 * x + 6;
		else {
			d += 4 * (x - y) + 10;
			y--;
		}
		glBegin(GL_POINTS);

	}
	glEnd();
	glFlush();
}

/*BresenhamCircle算法*/
void BresenhamCircle(int x0, int y0, int r)
{
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口显示内容

	int x = 0, y = r;
	int delta, delta1, delta2;
	int direction; //表明选取的点，1为H,2为D，3为V
	delta = 2 * (1 - r); //初始值
	int Limit = 0;

	glVertex2i(x0, y0);

	while (y >= Limit) {
		glBegin(GL_POINTS);
		CirclePoints(x, y, x0, y0);
		if (delta < 0) {
			delta1 = 2 * (delta + y) - 1;
			if (delta1 < 0) { //取H点
				direction = 1;
			}
			else direction = 2; //取D点
		}
		else if (delta > 0) {
			delta2 = 2 * (delta - x) - 1;
			if (delta2 < 0) {
				direction = 2; //取D点
			}
			else
				direction = 3; //取V点
		}
		else
			direction = 2;//取D点	

		switch (direction)
		{
		case 1:
			x++;
			delta += 2 * x + 1;
			break;
		case 2:
			x++; y--;
			delta += 2 * x - 2 * y + 1;
			break;
		case 3:
			y--;
			delta += -2 * y + 1;
			break;
		}
		//glBegin(GL_POINTS);
	}

	glEnd();
	glFlush();
}

//int flag = 0; //flag为0时表示是圆心
//鼠标拖动
void dragmouse(int x, int y)
{
	m1 = x;
	n1 = y;
	r = sqrt((m1 - m0) * (m1 - m0) + (n1 - n0) * (n1 - n0));
	//printf("待定圆心坐标为：（%d，%d），半径为 %.2f 。\n", m0, n0, r);//把坐标打印出来
	DrawCircle(); //画线
	glFlush();
	//flag = 0;
}

//鼠标监听，画点
void mymouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		m1 = x;
		n1 = y;
		r = sqrt((m1 - m0) * (m1 - m0) + (n1 - n0) * (n1 - n0));
		printf("圆心坐标为：（%d，%d），半径为 %.2f \n", m0, n0, r);//把坐标打印出来
		DrawCircle(); //画圆
		glFlush();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //按下鼠标，是起点
		m0 = x;
		n0 = y;
	}
}

void init()
{
	glClearColor(1, 1, 1, 1);//设置绘制窗口颜色为白色
	glClear(GL_COLOR_BUFFER_BIT);//清除窗口内容
	glPointSize(3.0f);//设置点的大小
	/*设置为投影类型模式和其他观察参数*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winwidth, winheight, 0);
	glColor3f(0, 1, 1);//设置画点的颜色
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//初始化
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//设置绘制模式
	glutInitWindowPosition(350, 200);//设置窗口出现的位置
	glutInitWindowSize(winwidth, winheight);//设置窗口大小
	glutCreateWindow("画圆");//创建窗口
	init();

	glutDisplayFunc(DrawCircle);//绘制回调函数,glut机制，它觉得需要重新绘制的时候就会执行
	glutMouseFunc(mymouse);//鼠标监听回调函数
	glutMotionFunc(dragmouse);//鼠标拖动
	glutMainLoop();
}
