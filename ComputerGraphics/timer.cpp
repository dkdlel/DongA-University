#include <glut.h>

GLfloat Delta = 0.0;
char gDir = 'R';

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.5, 0.8);
	glVertex3f(-1.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, -0.5, 0.0);
	glVertex3f(0.0 + Delta, 0.5, 0.0);
	glVertex3f(-1.0 + Delta, 0.5, 0.0);
	glEnd();
	glutSwapBuffers();
}
void MyTimer(int Value) {

	if (gDir == 'R') {
		Delta += 0.01;
		if (Delta > 2.5) gDir = 'L';
	}
	else{
		Delta -= 0.01;
		if (Delta < -1.5) gDir = 'R';
	}

	glutPostRedisplay();
	glutTimerFunc(3, MyTimer, 1); // 재귀형태로 돌아감
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Timer Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(20, MyTimer, 1); // 1번째 인자 : 시간초(ms, 1/1000) 2번째 인자 : 함수명 3번째 인자: 사용안함(timer의 갯수)
	glutMainLoop();
	return 0;
}