//#include <glut.h>
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT); // ������ ����
//	glColor3f(0.0, 0.0, 0.0); // ���� ��
//	glLineWidth(5.0); // ���� ����
//	glBegin(GL_LINE_STRIP);
//		glVertex3f(-0.5, -0.5, 0.0);
//		glVertex3f(0.5, -0.5, 0.0);
//		glVertex3f(0.5, 0.5, 0.0);
//		glVertex3f(-0.5, 0.5, 0.0);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 50);
//	glutCreateWindow("�׸� �׸���");
//	glClearColor(1.0, 1.0, 1.0, 1.0); // ������ ��û
//	glutDisplayFunc(MyDisplay); // ������ â�� ���� �ȵ�
//	glutMainLoop(); // ȭ�� ����
//	return 0;
//}

// ������ �׸���
#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glutSolidTeapot(0.5);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("�׸� �׸���");
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}