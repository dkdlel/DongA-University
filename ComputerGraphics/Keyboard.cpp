#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'Q':
		exit(0); break;
	case 'q':
		exit(0); break;
	case 'w':
		glClearColor(1, 1, 1, 1); break;// ����ȭ��
	case 'g':
		glColor3f(0.5, 0.5, 0.5); break; // ���� ��
	case 'b':
		glColor3f(0, 0, 1); break;
	}
	glutPostRedisplay(); // MyDisplay();�� �ҷ��� ������ ��
	// Redisplay�� ���� ť�� ���̴µ� MyDisplay�� ���� ��� �������� ť���� ������ ��
}void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_F1:
		break;
	case GLUT_KEY_LEFT:
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.5, 0.5, 0.5);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Keyboard Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}