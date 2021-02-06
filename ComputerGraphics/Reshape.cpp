#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0); glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0); glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
void MyReshape(int NewWidth, int NewHeight) { // ���������� Reshape Callback�� �����ϴ� �Լ�, (900,300)
	glViewport(0, 0, NewWidth, NewHeight); // ���� ��� -> graphics â �پ��ڴ� / �Ⱦ��ڴ�
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300; // 3
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300; // 1
	glMatrixMode(GL_PROJECTION); // ���� ��� -> ��ǥ�� ���Ҷ� ���
	glLoadIdentity(); // ���� ��� -> ��ǥ�� ���Ҷ� ���
	//glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	// âũ�⸦ �ø��� �簢���� ���¸� �״�� ����
	glOrtho(-1.0 * WidthFactor * WidthFactor, 1.0 * WidthFactor * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	// âũ�Ⱑ �þ����� ��������� �簢���� �۾� ���̰� �ϱ�
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Reshape Callback");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape); // Reshape Callback�� ������ �Լ�
	glutMainLoop();
	return 0;
}