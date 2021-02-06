#include <glut.h>
#include <math.h>
#define RGB 255.0
#define Pi 3.1415

GLfloat ghour = 0, gminute = 0;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	
	// 중점 (0, 0.5)
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.6 + 0.5, 0.6, 0.0); // 2
	glVertex3f(-0.5 + 0.5, 0.8, 0.0); // 3
	glVertex3f(-0.4 + 0.5, 0.6, 0.0); // 4
	glVertex3f(-0.2 + 0.5, 0.6, 0.0); // 5
	glVertex3f(-0.35 + 0.5, 0.45, 0.0); // 6
	glVertex3f(-0.3 + 0.5, 0.25, 0.0); // 7
	glVertex3f(-0.5 + 0.5, 0.35, 0.0); // 8
	glVertex3f(-0.7 + 0.5, 0.25, 0.0); // 9
	glVertex3f(-0.65 + 0.5, 0.45, 0.0); // 10
	glVertex3f(-0.8 + 0.5, 0.6, 0.0); // 1
	glEnd();
	glColor3f(0, 0, 0);
	// 시침
	glLineWidth(4);
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glRotatef(ghour, 0, 0, 1);
	glTranslatef(0, -0.5, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, 0.5 + 0.08, 0);
	glEnd();
	glPopMatrix();
	// 분침
	glLineWidth(3);
	glPushMatrix();
	glTranslatef(0, 0.5, 0);
	glRotatef(gminute, 0, 0, 1);
	glTranslatef(0, -0.5, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0.5, 0);
	glVertex3f(0, 0.5 + 0.1, 0);
	glEnd();
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3f(102 / RGB, 102 / RGB, 102 / RGB);
	for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.01 * cos(Angle), 0.01 * sin(Angle) + 0.5, 0.0);
	glEnd();
	glLineWidth(1);
	glColor3f(0, 0, 0);

	// 중점 : (-0.5, -0.5)
	glColor3f(51 / RGB, 0 / RGB, 0 / RGB);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 - 0.3, -0.5 + 0.3, 0);
	glVertex3f(-0.5 + 0.3, -0.5 + 0.3, 0);
	glVertex3f(-0.5 + 0.3, -0.5 - 0.3, 0);
	glVertex3f(-0.5 - 0.3, -0.5 - 0.3, 0);
	glEnd();
	glColor3f(204 / RGB, 153 / RGB, 102 / RGB);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 - 0.25, -0.5 + 0.25, 0);
	glVertex3f(-0.5 + 0.25, -0.5 + 0.25, 0);
	glVertex3f(-0.5 + 0.25, -0.5 - 0.25, 0);
	glVertex3f(-0.5 - 0.25, -0.5 - 0.25, 0);
	glEnd();
	glColor3f(0, 0, 0);
	// 시침
	glLineWidth(6);
	glPushMatrix();
	glTranslatef(-0.5, -0.5, 0);
	glRotatef(ghour, 0, 0, 1);
	glTranslatef(0.5, 0.5, 0);
	glBegin(GL_LINES);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5 -0.1, -0.5 -0.05, 0);
	glEnd();
	glPopMatrix();
	// 분침
	glLineWidth(3);
	glPushMatrix();
	glTranslatef(-0.5, -0.5, 0);
	glRotatef(gminute, 0, 0, 1);
	glTranslatef(0.5, 0.5, 0);
	glBegin(GL_LINES);
	glVertex3f(-0.5, -0.5, 0);
	glVertex3f(-0.5, -0.5 + 0.15, 0);
	glEnd();
	glPopMatrix();

	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5 - 0.01, -0.5 + 0.01, 0);
	glVertex3f(-0.5 + 0.01, -0.5 + 0.01, 0);
	glVertex3f(-0.5 + 0.01, -0.5 - 0.01, 0);
	glVertex3f(-0.5 - 0.01, -0.5 - 0.01, 0);
	glEnd();
	glColor3f(0, 0, 0);

	// 중점(0.5,-0.5)
	glBegin(GL_POLYGON);
	for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.3 * cos(Angle) + 0.5, 0.35 * sin(Angle) - 0.5, 0.0);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.27 * cos(Angle) + 0.5, 0.32 * sin(Angle) - 0.5, 0.0);
	glEnd();
	glColor3f(0, 0, 0);
	// 시침
	glLineWidth(6);
	glPushMatrix();
	glTranslatef(0.5, -0.5, 0);
	glRotatef(ghour, 0, 0, 1);
	glTranslatef(-0.5, 0.5, 0);
	glBegin(GL_LINES);
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(0.5 + 0.07, -0.5 - 0.13, 0);
	glEnd();
	glPopMatrix();
	// 분침
	glLineWidth(3);
	glPushMatrix();
	glTranslatef(0.5, -0.5, 0);
	glRotatef(gminute, 0, 0, 1);
	glTranslatef(-0.5, 0.5, 0);
	glBegin(GL_LINES);
	glVertex3f(0.5, -0.5, 0);
	glVertex3f(0.5, -0.5 + 0.2, 0);
	glEnd();
	glPopMatrix();
	glBegin(GL_POLYGON);
	glColor3f(1, 0, 0);
	for (GLfloat Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.01 * cos(Angle) + 0.5, 0.01 * sin(Angle) - 0.5, 0.0);
	glEnd();
	glColor3f(0, 0, 0);

	glutSwapBuffers();
}
void MyTimer(int Value) {
	ghour -= 0.5; gminute -= 6;
	glutPostRedisplay();
	glutTimerFunc(100, MyTimer, 1); // 재귀형태로 돌아감
}
void MyInit() {
	glClearColor(51 / RGB, 204 / RGB, 0 / RGB, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(400, 100);
	glutCreateWindow("Korea : 00:00 / LA : 8:00 / Paris : 17:00");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutTimerFunc(100, MyTimer, 1); // 1번째 인자 : 시간초(ms, 1/1000) 2번째 인자 : 함수명 3번째 인자: 사용안함(timer의 갯수)
	glutMainLoop();
	return 0;
}