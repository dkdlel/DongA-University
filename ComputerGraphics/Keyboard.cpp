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
		glClearColor(1, 1, 1, 1); break;// 바탕화면
	case 'g':
		glColor3f(0.5, 0.5, 0.5); break; // 도형 색
	case 'b':
		glColor3f(0, 0, 1); break;
	}
	glutPostRedisplay(); // MyDisplay();를 불러도 가능은 함
	// Redisplay를 쓰면 큐에 쌓이는데 MyDisplay를 돌면 재귀 느낌으로 큐에서 진행이 됨
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