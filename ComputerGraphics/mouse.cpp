#include <glut.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
	glViewport(0, 0, 500, 500); // ȭ�����(����� ���� ����)
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(TopLeftX / 500.0, (500 - TopLeftY) / 500.0, 0.0);
	glVertex3f(TopLeftX / 500.0, (500 -BottomRightY) / 500.0, 0.0);
	glVertex3f(BottomRightX / 500.0, (500 -BottomRightY) / 500.0, 0.0);
	glVertex3f(BottomRightX / 500.0, (500 -TopLeftY) / 500.0, 0.0);
	glEnd();
	glFlush();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { // ��Ŭ���ϸ� �׸� ������ ��
		TopLeftX = X;
		TopLeftY = Y;
	}
	//else if(Button == GLUT_LEFT_BUTTON && State == GLUT_UP) glutPostRedisplay(); // �ǽð����� ������ ������ ���콺�� ���� �׸��� ��Ÿ��
}
void MyMouseMove(GLint X, GLint Y) {
	BottomRightX = X;
	BottomRightY = Y;
	glutPostRedisplay(); // ���콺�� �����϶� ���� ��� �ٲ�}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); // 3�忡�� ���
	glLoadIdentity(); // 3�忡�� ���
	glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Mouse Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMotionFunc(MyMouseMove);
	glutMainLoop();
	return 0;
}