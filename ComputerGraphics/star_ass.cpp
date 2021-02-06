#include <glut.h>

GLfloat left = 0.0, right = 0.0;
GLboolean dir = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	//1번별
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.6, 0.6 + left, 0.0); // 2
	glVertex3f(-0.5, 0.8 + left, 0.0); // 3
	glVertex3f(-0.4, 0.6 + left, 0.0); // 4
	glVertex3f(-0.2, 0.6 + left, 0.0); // 5
	glVertex3f(-0.35, 0.45 + left, 0.0); // 6
	glVertex3f(-0.3, 0.25 + left, 0.0); // 7
	glVertex3f(-0.5, 0.35 + left, 0.0); // 8
	glVertex3f(-0.7, 0.25 + left, 0.0); // 9
	glVertex3f(-0.65, 0.45 + left, 0.0); // 10
	glVertex3f(-0.8, 0.6 + left, 0.0); // 1
	glEnd();

	// 2번별
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.455, -0.4 + right, 0.0); // 2
	glVertex3f(0.5, -0.35 + right, 0.0); // 3
	glVertex3f(0.545, -0.4 + right, 0.0); // 4
	glVertex3f(0.6, -0.4 + right, 0.0); // 5
	glVertex3f(0.555, -0.46 + right, 0.0); // 6
	glVertex3f(0.57, -0.55 + right, 0.0); // 7
	glVertex3f(0.5, -0.5 + right, 0.0); // 8
	glVertex3f(0.43, -0.55 + right, 0.0); // 9
	glVertex3f(0.445, -0.46 + right, 0.0); // 10
	glVertex3f(0.4, -0.4 + right, 0.0); // 1
	glEnd();

	glFlush();
}
void MyTimer(int Value) {

	if (dir) { // 왼쪽 별을 아래로, 오른쪽 별은 위로
		right += 0.025;
		left -= 0.04;
		if (right > 1.8) dir = false;
	}
	else { // 왼쪽 별은 위로, 오른쪽 별은 아래로
		right -= 0.025;
		left += 0.04;
		if (right < -1.5) dir = true;
	}

	glutPostRedisplay();
	glutTimerFunc(15, MyTimer, 1); // 재귀형태로 돌아감
}
void MyInit() {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, 1.0, -1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("move star");
	MyInit();
	
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(20, MyTimer, 1);

	glutMainLoop();
	return 0;
}