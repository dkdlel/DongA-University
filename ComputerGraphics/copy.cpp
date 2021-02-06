#include <glut.h>

GLUquadricObj* qobj = gluNewQuadric();

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	// �Ķ� ������
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTeapot(1);

	// ��
	glColor3f(1.0, 1.0, 0.0);
	gluSphere(qobj, 0.7, 50, 50);

	// ���� ������
	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(0.5);

	glutSwapBuffers(); // (6)�������
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); // (6)�������
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("GLU �� GLUT ����غ���"); // (7) â�� Ÿ��Ʋ
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); // (2) ���� ����
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}