#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<gl\glut.h>
using namespace std;

int m0, n0, m1, n1;//����ȫ�ֱ���
int mm, nn; //��Բ�����ĵ�
int a, b; //��Բ�ĳ�����Ͷ̰���
int winwidth = 800, winheight = 500;//���ڳ���
void DrawOval(); //ʵ���ϻ�Բ�ĺ���
void MidpointOval(int, int, int, int); //��Բ���е��㷨

//ʵ���ϻ�Բ�ĺ���
void DrawOval() {
	MidpointOval(mm, nn, a, b); //��Բ���е��㷨
}

//��������Բ�㷨
void OvalPoints(int x, int y, int x0, int y0)
{
	glVertex2i(x + x0, y + y0);
	glVertex2i(-x + x0, y + y0);
	glVertex2i(x + x0, -y + y0);
	glVertex2i(-x + x0, -y + y0);
}

/*��Բ���е��㷨*/
void MidpointOval(int x0, int y0, int a, int b)
{
	glClear(GL_COLOR_BUFFER_BIT);//���������ʾ����
	glBegin(GL_POINTS);

	int x = 0, y = b;
	int a2 = a * a, b2 = b * b;
	float d1 = b2 + a2 * (0.25 - b);
	float d2 = b2 * (x + 0.5) * (x + 0.5) + a2 * (y - 1) * (y - 1) - a2 * b2;

	OvalPoints(x, y, x0, y0);

	/*����һ*/
	while (a2 * y > b2 * x) { //ע�⣡����
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
		if (d2 >= 0) { //ȡ���·��ĵ�
			d2 += a2 * (3 - 2 * y);
		}
		else {
			x++;
			d2 += b2 * (2 * x + 2) + a2 * (3 - 2 * y);
		}
		glBegin(GL_POINTS);
		OvalPoints(x, y, x0, y0);
	}

	/*������*/
	//int flag = 0; //�ֳ����²��ֵı�־
	//while (y>=0) {
	//	glBegin(GL_POINTS);
	//	OvalPoints(x, y, x0, y0);

	//	if (flag == 0) {
	//		if (a2*y<b2*x) flag = 1;
	//	}

	//	if (flag == 0) { //�ϰ벿��
	//		x++;
	//		if (d1 < 0) {
	//			d1 += b2 * (2 * x + 3);
	//		}
	//		else {
	//			y--;
	//			d1 += b2 * (2 * x + 3) + a2 * (2 - 2 * y);
	//		}
	//	}
	//	else { //�°벿��
	//		y--;
	//		if (d2 >= 0) { //ȡ���·��ĵ�
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


//����϶�
void dragmouse(int x, int y) {
	m1 = x;
	n1 = y;
	mm = (m0 + m1) / 2;
	nn = (n0 + n1) / 2;
	a = abs(m1 - m0) / 2;
	b = abs(n1 - n0) / 2;
	DrawOval(); //����
	glFlush();
}

//������������
void mymouse(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		m1 = x;
		n1 = y;
		mm = (m0 + m1) / 2;
		nn = (n0 + n1) / 2;
		a = abs(m1 - m0) / 2;
		b = abs(n1 - n0) / 2;
		printf("��Բ��ʼ������Ϊ����%d��%d����������Ϊ��%d���̰���Ϊ��%d\n", m0, n0, a, b);
		DrawOval();
		glFlush();
	}
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //������꣬�����
		m0 = x;
		n0 = y;
	}
}

void init() {
	glClearColor(1, 1, 1, 1);//���û��ƴ�����ɫΪ��ɫ
	glClear(GL_COLOR_BUFFER_BIT);//�����������
	glPointSize(3.0f);//���õ�Ĵ�С
	/*����ΪͶӰ����ģʽ�������۲����*/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, winwidth, winheight, 0);
	glColor3f(0, 1, 1);//���û������ɫ
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);//��ʼ��
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//���û���ģʽ
	glutInitWindowPosition(350, 200);//���ô��ڳ��ֵ�λ��
	glutInitWindowSize(winwidth, winheight);//���ô��ڴ�С
	glutCreateWindow("����Բ");//��������
	init();

	glutDisplayFunc(DrawOval);//���ƻص�����,glut���ƣ���������Ҫ���»��Ƶ�ʱ��ͻ�ִ��
	glutMouseFunc(mymouse);//�������ص�����
	glutMotionFunc(dragmouse);//����϶�
	glutMainLoop();
}
