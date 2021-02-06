#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0, 0);
	// 아래 2개도 고정
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(0.5, 0.5, 0);
	glutSolidTeapot(0.3);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Composite Transformation");
	glClearColor(1, 1, 1, 1);

	// 3장에서는 (무대)위에 2개는 항상 고정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1, 1, -1, 1, -1, 1); // 무대
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}