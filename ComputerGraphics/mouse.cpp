#include <glut.h>

GLint TopLeftX, TopLeftY, BottomRightX, BottomRightY;

void MyDisplay() {
	glViewport(0, 0, 500, 500); // 화면분할(현재는 분할 없음)
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
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) { // 좌클릭하면 네모 시작점 됨
		TopLeftX = X;
		TopLeftY = Y;
	}
	//else if(Button == GLUT_LEFT_BUTTON && State == GLUT_UP) glutPostRedisplay(); // 실시간으로 보이지 않지만 마우스를 때면 그림이 나타남
}
void MyMouseMove(GLint X, GLint Y) {
	BottomRightX = X;
	BottomRightY = Y;
	glutPostRedisplay(); // 마우스가 움직일때 마다 계속 바뀜}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION); // 3장에서 배움
	glLoadIdentity(); // 3장에서 배움
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