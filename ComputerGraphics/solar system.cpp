#include <glut.h>
#include <glu.h>
static int Day = 0, Time = 0;
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); // 단위행렬

	glPushMatrix(); // upper solar system
	glTranslatef(0, 0.5, 0);
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 20, 16); // sun

	glPushMatrix();
	glRotatef((GLfloat)Day, 0.0, 1.0, 0.0); // earth 공전
	glTranslatef(0.7, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); // earth 자전
	glColor3f(0.3, 0.8, 0.9);
	glutWireSphere(0.1, 10, 8); // earth

	glPushMatrix();
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); // moon 공전
	glTranslatef(0.2, 0.0, 0.0);
	glColor3f(0.9, 0.5, 0.9);
	glutWireSphere(0.04, 10, 8); // moon
	glPopMatrix();

	glPopMatrix();
	glPopMatrix(); // lower solar system

	glPushMatrix(); // upper solar system
	glTranslatef(0, -0.5, 0);
	glColor3f(1.0, 0.3, 0.3);
	glutWireSphere(0.2, 20, 16); // sun

	glPushMatrix();
	glRotatef((GLfloat)Day, 0.0, 1.0, 0.0); // earth 공전
	glTranslatef(0.7, 0.0, 0.0);
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); // earth 자전
	glColor3f(0.3, 0.8, 0.9);
	glutWireSphere(0.1, 10, 8); // earth

	glPushMatrix();
	glRotatef((GLfloat)Time, 0.0, 1.0, 0.0); // moon 공전
	glTranslatef(0.2, 0.0, 0.0);
	glColor3f(0.9, 0.5, 0.9);
	glutWireSphere(0.04, 10, 8); // moon
	glPopMatrix();

	glPopMatrix();
	glPopMatrix(); // lower solar system

	glutSwapBuffers();
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'd':
		Day = (Day + 10) % 360;
		break;
	case 't':
		Time = (Time + 5) % 360;
		break;
	default:
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Solar System");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutKeyboardFunc(MyKeyboard);
	glutMainLoop();
	return 0;
}
