#include <glut.h>
void MyDisplay() { //glutDisplayFunc(MyDisplay)에 의해 호출되어짐
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0);
	glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("Display Callback");
	glClearColor(1.0, 1.0, 1.0, 1.0); // 흰 바탕
	glutDisplayFunc(MyDisplay); //MyDisplay 함수를 호출하여 Display Callback을 수행
	glutMainLoop();
	return 0;
}