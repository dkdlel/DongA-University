#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glScalef(1, 1, 2); // z축이 엄청 커지면 주전자 중간에 공백이 생김
	// 그 이유는 범위가 너무 커져서 무대를 나가게 되어 짤리게 됨
	// 따라서 공백처럼 발생하게됨
	glutWireTeapot(0.3);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Composite Transformation");
	glClearColor(1, 1, 1, 1);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1, 1, -1, 1, -1, 1);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}
