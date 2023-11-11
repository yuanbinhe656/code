#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>

using namespace std;

int m0, n0, m1, n1;//����ȫ�ֱ�����Բ������
float r; //Բ�İ뾶
int a, b; //��Բ�ĳ�����Ͷ̰���
//int winwidth = 1024, winheight = 720;//���ڳ���
int winwidth = 800, winheight = 500;//���ڳ���
void DrawCircle(); //ʵ���ϻ�Բ�ĺ���
void MidpointCircle(int, int, int);
void MidpointCircle_pro(int, int, int);
void BresenhamCircle(int, int, int);

//���ݽ���
void swap(GLint& a, GLint& b) { GLint t = a; a = b; b = t; }

//����Ļ�ϻ�һ����
void setPixel(GLint x, GLint y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

//ʵ���ϻ�Բ�ĺ���
void DrawCircle() {
	MidpointCircle(m0, n0, r);//�е㻮�߷�
	//MidpointCircle_pro(m0, n0, r);//�е㻮�߷�
	//BresenhamCircle(m0, n0, r);//BresenhamLine�㷨
}

//������Բ�㷨
void CirclePoints(int x, int y, int x0, int y0)
{
	glVertex2i(x + x0, y + y0); glVertex2i(y + x0, x + y0);
	glVertex2i(-x + x0, y + y0); glVertex2i(y + x0, -x + y0);
	glVertex2i(x + x0, -y + y0); glVertex2i(-y + x0, x + y0);
	glVertex2i(-x + x0, -y + y0); glVertex2i(-y + x0, -x + y0);
}

/*���Ļ�Բ��*/
void MidpointCircle(int x0, int y0, int r)
{
	glClear(GL_COLOR_BUFFER_BIT);//���������ʾ����

	int x, y;
	x = 0, y = r;
	float d = 1.25 - r;
	//int d = 1 - r; //��������������d��Ϊ����
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

/*���Ļ�Բ���ĸĽ�:����������*/
void MidpointCircle_pro(int x0, int y0, int r)
{
	glClear(GL_COLOR_BUFFER_BIT);//���������ʾ����

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

/*BresenhamCircle�㷨*/
void BresenhamCircle(int x0, int y0, int r)
{
	glClear(GL_COLOR_BUFFER_BIT);//���������ʾ����

	int x = 0, y = r;
	int delta, delta1, delta2;
	int direction; //����ѡȡ�ĵ㣬1ΪH,2ΪD��3ΪV
	delta = 2 * (1 - r); //��ʼֵ
	int Limit = 0;

	glVertex2i(x0, y0);

	while (y >= Limit) {
		glBegin(GL_POINTS);
		CirclePoints(x, y, x0, y0);
		if (delta < 0) {
			delta1 = 2 * (delta + y) - 1;
			if (delta1 < 0) { //ȡH��
				direction = 1;
			}
			else direction = 2; //ȡD��
		}
		else if (delta > 0) {
			delta2 = 2 * (delta - x) - 1;
			if (delta2 < 0) {
				direction = 2; //ȡD��
			}
			else
				direction = 3; //ȡV��
		}
		else
			direction = 2;//ȡD��	

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

//int flag = 0; //flagΪ0ʱ��ʾ��Բ��
//����϶�
void dragmouse(int x, int y)
{
	m1 = x;
	n1 = y;
	r = sqrt((m1 - m0) * (m1 - m0) + (n1 - n0) * (n1 - n0));
	//printf("����Բ������Ϊ����%d��%d�����뾶Ϊ %.2f ��\n", m0, n0, r);//�������ӡ����
	DrawCircle(); //����
	glFlush();
	//flag = 0;
}

//������������
void mymouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		m1 = x;
		n1 = y;
		r = sqrt((m1 - m0) * (m1 - m0) + (n1 - n0) * (n1 - n0));
		printf("Բ������Ϊ����%d��%d�����뾶Ϊ %.2f \n", m0, n0, r);//�������ӡ����
		DrawCircle(); //��Բ
		glFlush();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //������꣬�����
		m0 = x;
		n0 = y;
	}
}

void init()
{
	glClearColor(1, 1, 1, 1);//���û��ƴ�����ɫΪ��ɫ
	glClear(GL_COLOR_BUFFER_BIT);//�����������
	glPointSize(3.0f);//���õ�Ĵ�С
	/*����ΪͶӰ����ģʽ�������۲����*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winwidth, winheight, 0);
	glColor3f(0, 1, 1);//���û������ɫ
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);//��ʼ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//���û���ģʽ
	glutInitWindowPosition(350, 200);//���ô��ڳ��ֵ�λ��
	glutInitWindowSize(winwidth, winheight);//���ô��ڴ�С
	glutCreateWindow("��Բ");//��������
	init();

	glutDisplayFunc(DrawCircle);//���ƻص�����,glut���ƣ���������Ҫ���»��Ƶ�ʱ��ͻ�ִ��
	glutMouseFunc(mymouse);//�������ص�����
	glutMotionFunc(dragmouse);//����϶�
	glutMainLoop();
}
