#include <glut.h>
#include <math.h>
#define Pi 3.1415

unsigned char gKey = 'u'; // a:拳巢 u:乞家 s:眶澜
float gX, gY; // 捞悼 谅钎

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	switch (gKey) {
	case 'u':
		// 倔奔 屈
		glBegin(GL_POLYGON);
		glColor3f(255/255.0, 204/255.0, 153/255.0);
		for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
			glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glEnd();
		// 哭率 传界
		glBegin(GL_LINE_STRIP);
		glLineWidth(5.0);
		glVertex3f(-0.05, 0.15, 0.0);
		glVertex3f(-0.25, 0.2, 0.0);
		glVertex3f(-0.3, 0.15, 0.0);
		glEnd();
		// 坷弗率 传界
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.05, 0.15, 0.0);
		glVertex3f(0.25, 0.2, 0.0);
		glVertex3f(0.3, 0.15, 0.0);
		glEnd();
		// 哭率 传
		glBegin(GL_POLYGON);
		for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 40.0)
			glVertex3f(0.04 * cos(Angle) - 0.18, 0.04 * sin(Angle) + 0.07, 0.0);
		glEnd();
		// 坷弗率 传
		glBegin(GL_POLYGON);
		for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 40.0)
			glVertex3f(0.04 * cos(Angle) + 0.18, 0.04 * sin(Angle) + 0.07, 0.0);
		glEnd();
		// 内
		glBegin(GL_LINE_STRIP);
		glLineWidth(1.5);
		glVertex3f(0.0, 0.05, 0.0);
		glVertex3f(-0.03, -0.1, 0.0);
		glVertex3f(0.03, -0.1, 0.0);
		glEnd();
		// 涝
		glBegin(GL_LINE_STRIP);
		glVertex3f(-0.2, -0.25, 0.0);
		glVertex3f(0.0, -0.3, 0.0);
		glVertex3f(0.2, -0.25, 0.0);
		glEnd();
		break;
	case 'a':
		// 倔奔 屈
		glBegin(GL_POLYGON);
		glColor3f(204 / 255.0, 51 / 255.0, 51 / 255.0);
		for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
			glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glEnd();
		// 哭率 传界
		glBegin(GL_LINE_STRIP);
		glLineWidth(5.0);
		glVertex3f(-0.1, 0.10, 0.0);
		glVertex3f(-0.2, 0.18, 0.0);
		glVertex3f(-0.3, 0.25, 0.0);
		glEnd();
		// 坷弗率 传界
		glBegin(GL_LINE_STRIP);
		glVertex3f(0.1, 0.10, 0.0);
		glVertex3f(0.2, 0.18, 0.0);
		glVertex3f(0.3, 0.25, 0.0);
		glEnd();
		// 哭率 传
		glLineWidth(1.5);
		glBegin(GL_LINES);
		glVertex3f(-0.2, 0.07, 0.0);
		glVertex3f(-0.1, 0.07, 0.0);
		glEnd();
		// 坷弗率 传
		glBegin(GL_LINES);
		glVertex3f(0.1, 0.07, 0.0);
		glVertex3f(0.2, 0.07, 0.0);
		glEnd();
		// 内
		glLineWidth(1.0);
		glBegin(GL_LINE_STRIP);
		glLineWidth(1.5);
		glVertex3f(0.0, 0.05, 0.0);
		glVertex3f(-0.03, -0.1, 0.0);
		glVertex3f(0.03, -0.1, 0.0);
		glEnd();
		// 涝
		glBegin(GL_LINE_STRIP);
		glVertex3f(-0.2, -0.25, 0.0);
		glVertex3f(0.2, -0.25, 0.0);
		glEnd();
		break;
	case 's':
		// 倔奔 屈
		glBegin(GL_POLYGON);
		glColor3f(255 / 255.0, 204 / 255.0, 153 / 255.0);
		for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
			glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
		glColor3f(0.0, 0.0, 0.0);
		glEnd();
		// 哭率 传
		glBegin(GL_LINES);
		glVertex3f(-0.3, 0.18, 0.0);
		glVertex3f(-0.1, 0.18, 0.0);
		glVertex3f(-0.23, 0.18, 0.0);
		glVertex3f(-0.23, 0.13, 0.0);
		glVertex3f(-0.18, 0.18, 0.0);
		glVertex3f(-0.18, 0.13, 0.0);
		glEnd();
		// 坷弗率 传
		glBegin(GL_LINES);
		glVertex3f(0.3, 0.18, 0.0);
		glVertex3f(0.1, 0.18, 0.0);
		glVertex3f(0.23, 0.18, 0.0);
		glVertex3f(0.23, 0.13, 0.0);
		glVertex3f(0.18, 0.18, 0.0);
		glVertex3f(0.18, 0.13, 0.0);
		glEnd();
		// 内
		glBegin(GL_LINE_STRIP);
		glLineWidth(1.5);
		glVertex3f(0.0, 0.05, 0.0);
		glVertex3f(-0.03, -0.1, 0.0);
		glVertex3f(0.03, -0.1, 0.0);
		glEnd();
		// 涝
		glBegin(GL_LINE_STRIP);
		glVertex3f(-0.2, -0.25, 0.0);
		glVertex3f(0.0, -0.2, 0.0);
		glVertex3f(0.2, -0.25, 0.0);
		glEnd();
		break;
	}

	// 喊
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 0.0);
	glVertex3f(0.455 + gX, -0.4 + gY, 0.0); // 2
	glVertex3f(0.5 + gX, -0.35 + gY, 0.0); // 3
	glVertex3f(0.545 + gX, -0.4 + gY, 0.0); // 4
	glVertex3f(0.6 + gX, -0.4 + gY, 0.0); // 5
	glVertex3f(0.555 + gX, -0.46 + gY, 0.0); // 6
	glVertex3f(0.57 + gX, -0.55 + gY, 0.0); // 7
	glVertex3f(0.5 + gX, -0.5 + gY, 0.0); // 8
	glVertex3f(0.43 + gX, -0.55 + gY, 0.0); // 9
	glVertex3f(0.445 + gX, -0.46 + gY, 0.0); // 10
	glVertex3f(0.4 + gX, -0.4 + gY, 0.0); // 1
	glEnd();
	glColor3f(0.0, 0.0, 0.0);
	glutSwapBuffers();
}

void MyReshape(int NewWidth, int NewHeight) {
	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)500;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)500;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
}
void MyKeyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'a': case 'u': case 's': gKey = key;
	case 'W': glClearColor(1, 1, 1, 1); break;
	case 'G': glClearColor(0, 1, 0, 1); break;
	case 'R': glClearColor(1, 0, 0, 1); break;
	case 'B': glClearColor(0, 0, 1, 1); break;
	}
	glutPostRedisplay();
}
void MySpecial(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT: gX -= 1;  break;
	case GLUT_KEY_RIGHT: gX += 1;  break;
	case GLUT_KEY_UP: gY += 1;  break;
	case GLUT_KEY_DOWN: gY -= 1;  break;
	case GLUT_KEY_F5: gX = gY = 0; break;
	default: break;
	}
	glutPostRedisplay();
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(0.0, 0.0, 0.0);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("a:拳巢, s:眶澜, u:乞家, W:闰祸, G:檬废, R:弧碍, B:颇尔");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMainLoop();
	return 0;
}