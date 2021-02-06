/*-----------------------------------------
14th week 2020. 6. 15


오늘의 주제: 막시무스 걷다!!

(1) blueleg 추가
(2) BlackArm 추가
(3) RedArm 추가
(4) 막시무스 키를 크게하기 위해서, 다리 하부만 위아래로 늘려보기 -> blueleg에 설명
(5) 팔을 늘림 -> 다리랑 똑같음
(6) 막시무스 run!!!!
(7) 축구하는 막시무스!!

(여러분 선배인 kth, kwj 작품을 기본으로 막시무스에 맞게 편집한 소스입니다.)
------------------------------------------*/

#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
const GLint x = 1, y = 0, z = 0;  // 혹시나 회전축 변경 위해서
double gTimeslot = -5;

void YourBackground();
void YourBody();
void YourFace();
void YourBlackLeg(int angle);
void YourBlueLeg(int angle); //14-(1)
void YourBlackArm(int angle); //14-(2)
void YourRedArm(int angle); //14-(3)
void MyDisplay();
void MyTimer(int Value);
void MyReshape(int w, int h);
void YourSoccerBall(); // 14-(7)

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	YourBackground();

	gluLookAt(1, 0, 2, 0, 0, 0, 0, 1, 0);
	glTranslatef(0, 0, gTimeslot);

	//glRotatef(-30, 0, 1, 0);

	YourBlackArm(-fabs(90 * cos(gTimeslot))); // 14-(2)
	YourBlackLeg(fabs(90 * cos(gTimeslot))); // 튜닝을 거쳐서 나온 각도!! 14-(6)

	YourBody();
	YourFace();

	YourBlueLeg(fabs(90 * cos(gTimeslot + M_PI_2))); // 14-(1) 14-(6)
	YourRedArm(-fabs(90 * cos(gTimeslot + M_PI_2))); // 14-(3)

	YourSoccerBall();

	glutSwapBuffers();
}
void YourSoccerBall() {
	glColor3f(1, 1, 0);
	glPushMatrix();
		glTranslatef(0.125, -0.95, 0.3); // blueleg가 기준 -> blueleg에 translate한거 합
		glutSolidSphere(0.25, 30, 30);
	glPopMatrix();
}
void YourBlackLeg(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
		glTranslatef(-0.125, -0.3, 0.0);
		glRotatef(angle - 60, x, y, z); // 40 -> 60
		glTranslatef(0, -0.2, 0);
			glPushMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angle, x, y, z);
			glTranslatef(0.0, -0.25, 0.0);
			glScalef(0.15, 0.45, 0.15);
			glutSolidCube(1);	// 하부
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// 상부
		glutSolidCube(1);
	glPopMatrix();
}
void YourBlueLeg(int angle) { //14-(1)
	glColor3f(0, 0, 1);
	glPushMatrix();
		glTranslatef(0.125, -0.3, 0.0);
		glRotatef(angle - 60, x, y, z); // 40 -> 60
		glTranslatef(0, -0.2, 0);
			glPushMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angle, x, y, z);
			glTranslatef(0.0, -0.25, 0.0); // 14-(5) -0.15 -> -0.25 위아래로 0.1씩 늘어났기 떄문에 1을 빼줘야함
			glScalef(0.15, 0.45, 0.15); // 14-(5) 0.25 --> 0.45 위아래로 0.1씩 늘어났으므로
			glutSolidCube(1);	// 하부
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// 상부
		glutSolidCube(1);
	glPopMatrix();
}
void YourBlackArm(int angle) { //14-(2)
	glColor3f(0, 0, 0);
	glPushMatrix();
		glTranslatef(-0.35, 0.325, 0.0);
		glRotatef(angle + 60, x, y, z); // 15 - > 30 -> 60
		glTranslatef(0, -0.125, 0);
		glPushMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angle, x, y, z);
			glTranslatef(0.0, -0.25, 0.0);
			glScalef(0.15, 0.45, 0.15);
			glutSolidCube(1);	// 하부
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// 상부
		glutSolidCube(1);
	glPopMatrix();
}
void YourRedArm(int angle) { //14-(3)
	glColor3f(1, 0, 0);
	glPushMatrix();
		glTranslatef(0.35, 0.325, 0.0);
		glRotatef(angle + 60, x, y, z); // 15 - > 30 -> 60
		glTranslatef(0, -0.125, 0);
			glPushMatrix();
			glTranslatef(0.0, -0.2, 0.0);
			glRotatef(angle, x, y, z);
			glTranslatef(0.0, -0.25, 0.0);
			glScalef(0.15, 0.45, 0.15);
			glutSolidCube(1);	// 하부
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// 상부
		glutSolidCube(1);
	glPopMatrix();
}
void YourFace() {
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 30, 30);	// face
	glPopMatrix();

	glColor3f(0, 0, 0); // black
	glPushMatrix();
	glTranslatef(-0.125, 0.6, 0.1);
	glScalef(0.05, 0.05, 0.05);
	glutSolidSphere(0.5, 30, 30);	// 눈
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.125, 0.6, 0.1);
	glScalef(0.05, 0.05, 0.05);
	glutSolidSphere(0.5, 30, 30);	// 눈
	glPopMatrix();
	glPopMatrix();
}
void YourBackground() {
	glColor3f(0, 1, 1); // sky 
	glBegin(GL_POLYGON);
	glVertex3f(-10, 0, -7);
	glVertex3f(10, 0, -7);
	glVertex3f(10, 8, -7);
	glVertex3f(-10, 8, -7);
	glEnd();

	glColor3f(0, 1, 0); // green 
	glBegin(GL_POLYGON);
	glVertex3f(-10, -8, -7);
	glVertex3f(10, -8, -7);
	glVertex3f(10, 0, -7);
	glVertex3f(-10, 0, -7);
	glEnd();
}
void YourBody() {
	glColor3f(0.5, 0.5, 0.5);  // gray
	glPushMatrix();
		glScalef(0.4, 0.65, 0.4); // 취향차이
		glutSolidCube(1);
	glPopMatrix();
}
void MyTimer(int Value) {
	gTimeslot += 0.1;
	if (gTimeslot > 1.5)	gTimeslot = -5;
	glutPostRedisplay();
	glutTimerFunc(100, MyTimer, 1); // 14-(6) 100 ->20 
}
void MyReshape(int w, int h) {
	glClearColor(1, 1, 1, 1);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0.0, 100);

}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("Maximus Walking");
	glutTimerFunc(100, MyTimer, 1); // 14-(6) 100 -> 20
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}