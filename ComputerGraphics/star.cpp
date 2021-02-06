#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	//1번별
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.6, 0.6, 0.0); // 2
	glVertex3f(-0.5, 0.8, 0.0); // 3
	glVertex3f(-0.4, 0.6, 0.0); // 4
	glVertex3f(-0.2, 0.6, 0.0); // 5
	glVertex3f(-0.35, 0.45, 0.0); // 6
	glVertex3f(-0.3, 0.25, 0.0); // 7
	glVertex3f(-0.5, 0.35, 0.0); // 8
	glVertex3f(-0.7, 0.25, 0.0); // 9
	glVertex3f(-0.65, 0.45, 0.0); // 10
	glVertex3f(-0.8, 0.6, 0.0); // 1
	glEnd();
	// 2번별
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	glVertex3f(0.455, -0.4, 0.0); // 2
	glVertex3f(0.5, -0.35, 0.0); // 3
	glVertex3f(0.545, -0.4, 0.0); // 4
	glVertex3f(0.6, -0.4, 0.0); // 5
	glVertex3f(0.555, -0.46, 0.0); // 6
	glVertex3f(0.57, -0.55, 0.0); // 7
	glVertex3f(0.5, -0.5, 0.0); // 8
	glVertex3f(0.43, -0.55, 0.0); // 9
	glVertex3f(0.445, -0.46, 0.0); // 10
	glVertex3f(0.4, -0.4, 0.0); // 1
	glEnd();

	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("별 그리기");
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glutDisplayFunc(MyDisplay); 
	glutMainLoop();
	return 0;
}