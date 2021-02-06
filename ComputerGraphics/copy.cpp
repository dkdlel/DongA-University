#include <glut.h>

GLUquadricObj* qobj = gluNewQuadric();

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);

	// 파란 주전자
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTeapot(1);

	// 구
	glColor3f(1.0, 1.0, 0.0);
	gluSphere(qobj, 0.7, 50, 50);

	// 빨간 주전자
	glColor3f(1.0, 0.0, 0.0);
	glutWireTeapot(0.5);

	glutSwapBuffers(); // (6)더블버퍼
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE); // (6)더블버퍼
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("GLU 및 GLUT 사용해보기"); // (7) 창의 타이틀
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glOrtho(-2.0, 2.0, -2.0, 2.0, -2.0, 2.0); // (2) 무대 범위
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}