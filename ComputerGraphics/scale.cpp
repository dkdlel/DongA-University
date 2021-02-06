#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0, 0, 300, 300);
	glColor3f(1, 0, 1);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glScalef(1, 1, 2); // z���� ��û Ŀ���� ������ �߰��� ������ ����
	// �� ������ ������ �ʹ� Ŀ���� ���븦 ������ �Ǿ� ©���� ��
	// ���� ����ó�� �߻��ϰԵ�
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
