#include <glut.h>
void MyDisplay() { //glutDisplayFunc(MyDisplay)�� ���� ȣ��Ǿ���
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Display Callback");
	glClearColor(1.0, 1.0, 1.0, 1.0); // �� ����
	glutDisplayFunc(MyDisplay); //MyDisplay �Լ��� ȣ���Ͽ� Display Callback�� ����
	glutMainLoop();
	return 0;
}