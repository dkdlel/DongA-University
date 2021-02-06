#include <glut.h>
#include <math.h>
#define Pi 3.1415
#define size 600
#define fsize 600.0
#define frgb 255.0

int gCount = 0;
float gX, gY;

void MyDisplay() {

	if (!gCount) glClear(GL_COLOR_BUFFER_BIT);

	else {
		glColor3f(255 / frgb, 223 / frgb, 0);
		glBegin(GL_POLYGON);
		for (GLfloat Angle = 0; Angle <= Pi; Angle += Pi / 20.0) glVertex3f(gX + 0.08 * cos(Angle), gY + 0.08 * sin(Angle), 0.0);
		glEnd();
		glLineWidth(5.0);
		glBegin(GL_LINES);
		glVertex3f(gX, gY, 0.0);
		glVertex3f(gX, gY - 0.08, 0.0);
		glEnd();

		glColor3f(0, 0, 1);
		glBegin(GL_POLYGON);
		for (GLfloat Angle = 0; Angle <= 2 * Pi; Angle += Pi / 20.0) glVertex3f(gX - 0.045 + 0.03 * cos(Angle), gY + 0.13 + 0.03 * sin(Angle), 0.0);
		glVertex3f(gX - 0.045, gY + 0.23, 0.0);
		glVertex3f(gX - 0.075, gY + 0.13, 0.0);
		glVertex3f(gX - 0.015, gY + 0.13, 0.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(gX - 0.045, gY + 0.23, 0.0);
		glVertex3f(gX - 0.075, gY + 0.13, 0.0);
		glVertex3f(gX - 0.015, gY + 0.13, 0.0);
		glEnd();

		glBegin(GL_POLYGON);
		for (GLfloat Angle = 0; Angle <= 2 * Pi; Angle += Pi / 20.0) glVertex3f(gX + 0.045 + 0.03 * cos(Angle), gY + 0.13 + 0.03 * sin(Angle), 0.0);
		glVertex3f(gX + 0.045, gY + 0.23, 0.0);
		glVertex3f(gX + 0.075, gY + 0.13, 0.0);
		glVertex3f(gX + 0.015, gY + 0.13, 0.0);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(gX + 0.045, gY + 0.23, 0.0);
		glVertex3f(gX + 0.075, gY + 0.13, 0.0);
		glVertex3f(gX + 0.015, gY + 0.13, 0.0);
		glEnd();

	}

	glFlush();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		gX = 2 * (X / fsize) - 1;
		gY = 2 * ((size - Y) / fsize) - 1;
		gCount++;

		glutPostRedisplay();
	}

}
void MyInit() {
	glClearColor(63 / frgb, 63 / frgb, 63 / frgb, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(size, size);
	glutInitWindowPosition(450, 0);
	glutCreateWindow("여름하면 장마!!(우산과 내리는 비 두개를 표현 / 총 3개)");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}