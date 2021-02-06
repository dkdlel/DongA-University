#include <glut.h>

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1.0, 0, 0);
	// �Ʒ� 2���� ����
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

	// 3�忡���� (����)���� 2���� �׻� ����
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(-1, 1, -1, 1, -1, 1); // ����
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}