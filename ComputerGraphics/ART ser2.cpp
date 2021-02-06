#include <stdlib.h>
#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
#include <stdio.h>
#define MAX 1000
#define RGB 255.0

float randx[MAX], randy[MAX];
const GLint x = 1, y = 0, z = 0;
double gTimeslot = -5, between = 0 , wave = 0.1;
int cnt = 0;
bool flag = false;

void YourBackground();
void BoyBody();
void BoyFace();
void GirlBody();
void GirlFace();
void BoyLeftLeg(int angle);
void BoyRightLeg(int angle);
void BoyLeftArm(int angle);
void BoyRightArm(int angle);
void GirlLeftLeg(int angle);
void GirlRightLeg(int angle);
void GirlLeftArm(int angle);
void GirlRightArm(int angle);
void MyDisplay();
void MyTimer(int Value);
void MyReshape(int w, int h);
void Dandelion();
void Star(int type);

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	YourBackground();

	gluLookAt(2, 0, 2, 0, 0, 0, 0, 1, 0);
	glTranslatef(0, 0, gTimeslot);

	//glRotatef(30, 0, 1, 0);

	glPushMatrix();
	glScalef(0.5, 0.5, 0.5);
	BoyLeftArm(-fabs(90 * cos(gTimeslot)));
	BoyLeftLeg(fabs(90 * cos(gTimeslot)));
	BoyBody();
	BoyFace();
	glScalef(0.5, 0.5, 0.5);
	BoyRightLeg(fabs(90 * cos(gTimeslot + M_PI_2)));
	BoyRightArm(-fabs(90 * cos(gTimeslot + M_PI_2)));
	glPopMatrix();

	if (cnt % 4 == 0 || cnt % 4 == 1) {
		glPushMatrix();
		glTranslatef(1.3 + between, 0, 0);
		GirlRightLeg(fabs(90 * cos(gTimeslot + M_PI_2)));
		GirlRightArm(-fabs(90 * cos(gTimeslot + M_PI_2)));
		GirlBody();
		GirlFace();
		glTranslatef(1.3 + between, 0, 0);
		GirlLeftArm(-fabs(90 * cos(gTimeslot)));
		GirlLeftLeg(fabs(90 * cos(gTimeslot)));
		glPopMatrix();
	}
	else if (cnt % 4 == 2) {
		glPushMatrix();
		glTranslatef(1.3 + between, 0, 1.5);
		GirlRightLeg(fabs(90 * cos(gTimeslot + M_PI_2)));
		GirlRightArm(-fabs(90 * cos(gTimeslot + M_PI_2)));
		GirlBody();
		GirlFace();
		glTranslatef(1.3 + between, 0, 1.5);
		GirlLeftArm(-fabs(90 * cos(gTimeslot)));
		GirlLeftLeg(fabs(90 * cos(gTimeslot)));
		glPopMatrix();
	}
	glutSwapBuffers();
}
void BoyLeftLeg(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.125, -0.3, 0.0);
	glRotatef(angle - 60, x, y, z);
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
void BoyRightLeg(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.125, -0.3, 0.0);
	glRotatef(angle - 60, x, y, z);
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
void BoyLeftArm(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.35, 0.325, 0.0);
	glRotatef(angle + 60, x, y, z);
	glTranslatef(0, -0.125, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(angle, x, y, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glutSolidCube(1);	// 하부
	glColor3f(0, 0, 0);
	glPopMatrix();
	glScalef(0.15, 0.25, 0.15);	// 상부
	glutSolidCube(1);
	glPopMatrix();
}
void BoyRightArm(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.35, 0.325, 0.0);
	glRotatef(angle + 60, x, y, z);
	glTranslatef(0, -0.125, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(angle, x, y, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glutSolidCube(1);	// 하부
	glColor3f(0, 0, 0);
	glPopMatrix();
	glScalef(0.15, 0.25, 0.15);	// 상부
	glutSolidCube(1);
	glPopMatrix();
}
void GirlLeftLeg(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.125, -0.3, 0.0);
	glRotatef(angle - 60, x, y, z);
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
void GirlRightLeg(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.125, -0.3, 0.0);
	glRotatef(angle - 60, x, y, z);
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
void GirlLeftArm(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.35, 0.325, 0.0);
	glRotatef(angle + 60, x, y, z);
	glTranslatef(0, -0.125, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(angle, x, y, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glutSolidCube(1);	// 하부
	glColor3f(0, 0, 0);
	glPopMatrix();
	glScalef(0.15, 0.25, 0.15);	// 상부
	glutSolidCube(1);
	glPopMatrix();
}
void GirlRightArm(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.35, 0.325, 0.0);
	glRotatef(angle + 60, x, y, z);
	glTranslatef(0, -0.125, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(angle, x, y, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glutSolidCube(1);	// 하부
	glColor3f(0, 0, 0);
	glPopMatrix();
	glScalef(0.15, 0.25, 0.15);	// 상부
	glutSolidCube(1);
	glPopMatrix();
}
void BoyFace() {
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 30, 30);	// face
	glPopMatrix();
	glColor3f(0, 0, 0); // black
	if(cnt % 4 == 0 || cnt % 4 == 2){
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
	}
	else if (cnt % 4 == 1) {
		glPushMatrix();
		glTranslatef(-0.15, 0.65, 0);
		glRotatef(-30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.1, 0.65, 0);
		glRotatef(30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.05, 0.65, 0);
		glRotatef(-30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.1, 0.65, 0);
		glRotatef(30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	else if (cnt % 4 == 3) {
		glPushMatrix();
		glTranslatef(-0.15, 0.65, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.02, 0.18, 0);
		glutSolidCube(1);
		glPopMatrix(); // 왼쪽 ㅡ

		glPushMatrix();
		glTranslatef(-0.18, 0.59, 0);
		glScalef(0.02, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix(); // 왼쪽의 왼쪽 ㅣ

		glPushMatrix();
		glTranslatef(-0.11, 0.59, 0);
		glScalef(0.02, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix(); // 왼쪽의 오른쪽 ㅣ

		glPushMatrix();
		glTranslatef(0.1, 0.65, 0);
		glRotatef(90, 0, 0, 1);
		glScalef(0.02, 0.18, 0);
		glutSolidCube(1);
		glPopMatrix(); // 오른쪽 ㅡ

		glPushMatrix();
		glTranslatef(0.08, 0.59, 0);
		glScalef(0.02, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix(); // 오른쪽의 왼쪽 ㅣ

		glPushMatrix();
		glTranslatef(0.14, 0.59, 0);
		glScalef(0.02, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix(); // 오른쪽의 오른쪽 ㅣ
	}
	glPopMatrix();
}
void BoyBody() {
	glColor3f(0.7, 0.7, 0.7);  // light gray
	glPushMatrix();
	glScalef(0.4, 0.65, 0.4);
	glutSolidCube(1);
	glPopMatrix();
}
void GirlFace() {
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 30, 30);	// face
	glPopMatrix();

	glColor3f(0, 0, 0); // black

	if (cnt % 4 == 1) {
		glTranslatef(-0.8, 0, 0);
		glPushMatrix();
		glTranslatef(0.6, 0.65, 0);
		glRotatef(-30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.65, 0.65, 0);
		glRotatef(30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.8, 0.65, 0);
		glRotatef(-30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.85, 0.65, 0);
		glRotatef(30, 0, 0, 1);
		glScalef(0.02, 0.12, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	else if (cnt % 4 == 2) {
		glTranslatef(-1.0, 0, -1.3);
		glPushMatrix();
		glTranslatef(1.2, 0.6, 1.5);
		glRotatef(-60, 0, 0, 1);
		glScalef(0.02, 0.18, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1.0, 0.6, 1.5);
		glRotatef(60, 0, 0, 1);
		glScalef(0.02, 0.18, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
	else {
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

}
void GirlBody() {
	glColor3f(238 / RGB, 130 / RGB, 238 / RGB);
	glPushMatrix();
	glScalef(0.4, 0.65, 0.4);
	glutSolidCube(1);
	glPopMatrix();
}
void Dandelion() {
	glPushMatrix();
	glTranslatef(0.7, -0.7, 0);
	glLineWidth(3);
	glColor3f(0, 0.7, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -3);
	glVertex3f(0, -0.3, -3);
	glEnd();
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -3);
	glScalef(0.2, 0.2, 0.2);
	glutWireSphere(0.3, 10, 10);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.8, -0.7, 0);
	glLineWidth(3);
	glColor3f(0, 0.7, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -3);
	glVertex3f(0, -0.2, -3);
	glEnd();
	glColor3f(1, 1, 1);
	glTranslatef(0, 0, -3);
	glScalef(0.15, 0.15, 0.2);
	glutWireSphere(0.3, 7, 7);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.75, -0.8, 0);
	glLineWidth(3);
	glColor3f(0, 0.7, 0);
	glBegin(GL_LINES);
	glVertex3f(0, 0, -3);
	glVertex3f(0, -0.18, -3);
	glEnd();
	glColor3f(1, 1, 0);
	glTranslatef(0, 0, -3);
	glScalef(0.15, 0.15, 0.2);
	glutWireSphere(0.3, 8, 8);
	glPopMatrix();
}
void Star(int type) {
	if (type == 0) {
		glColor3f(0.698039, 0.133333, 0.133333);
	}
	else if (type == 1) {
		glColor3f(0.823529, 0.711765, 0.117647);
	}
	else {
		glColor3f(1, 1, 0);
	}
	glPushMatrix();
	glScalef(0.2, 0.25, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.4, -0.7, 0.0);
	glVertex3f(-0.5, -0.5, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.3, -0.4, 0.0);
	glVertex3f(-0.5, -0.4, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.5, -0.4, 0.0);
	glVertex3f(-0.6, -0.2, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.6, -0.2, 0.0);
	glVertex3f(-0.7, -0.4, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.7, -0.4, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.7, -0.4, 0.0);
	glVertex3f(-0.9, -0.4, 0.0);
	glVertex3f(-0.6, -0.6, 0.0);
	glVertex3f(-0.7, -0.5, 0.0);
	glVertex3f(-0.8, -0.7, 0.0);
	glEnd();
	glPopMatrix();
}
void YourBackground() {
	// sky
	glColor3f(0, 1, 1);
	glBegin(GL_POLYGON);
	glVertex3f(-10, 0, -7);
	glVertex3f(10, 0, -7);
	glVertex3f(10, 8, -7);
	glVertex3f(-10, 8, -7);
	glEnd();
	// green
	glColor3f(0, 1, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-10, -8, -7);
	glVertex3f(10, -8, -7);
	glVertex3f(10, 1, -7);
	glVertex3f(-10, 1, -7);
	glEnd();

	// road
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-10, -3, -7);
	glVertex3f(10, 0.7, -7);
	glVertex3f(10, -0.3, -7);
	glVertex3f(-10, -5, -7);
	glEnd();
	if (cnt == 0) { // 봄
		// 나무 몸통
		glColor3f(139 / RGB, 0, 0);
		glPushMatrix();
		glTranslatef(-1, 0.3, -3);
		glScalef(0.2, 0.8, 0.2);
		glutSolidCube(1);
		glPopMatrix();
		// 나무 위
		glPushMatrix();
		glColor3f(219 / RGB, 112 / RGB, 147 / RGB);
		glTranslatef(-1, 1, -3);
		glutSolidSphere(0.5, 50, 50);
		glPopMatrix();
		// 민들레
		Dandelion();
	}
	else if (cnt == 1) { // 여름
		// sea
		glColor3f(30 / RGB, 144 / RGB, 255 / RGB);
		glBegin(GL_POLYGON);
		glVertex3f(-10, 0, -7);
		glVertex3f(10, 0, -7);
		glVertex3f(10, 8, -7);
		glVertex3f(-10, 8, -7);
		glEnd();
		// beach
		glColor3f(255 / RGB, 228 / RGB, 196 / RGB);
		glBegin(GL_POLYGON);
		glVertex3f(-10, -8, -7);
		glVertex3f(10, -8, -7);
		glVertex3f(10, 1 + wave, -7);
		glVertex3f(-10, 1 + wave, -7);
		glEnd();
		// road
		glColor3f(222 / RGB, 184 / RGB, 135 / RGB);
		glBegin(GL_POLYGON);
		glVertex3f(-10, -3, -7);
		glVertex3f(10, 0.7, -7);
		glVertex3f(10, -0.3, -7);
		glVertex3f(-10, -5, -7);
		glEnd();
		glColor3f(0.5, 0.5, 0.5);
		glLineWidth(7);
		glBegin(GL_LINE_STRIP);
		glVertex3f(-10, -3, -7);
		glVertex3f(10, 0.7, -7);
		glVertex3f(10, -0.3, -7);
		glVertex3f(-10, -5, -7);
		glEnd();
		glLineWidth(1);
		// 의자
		glColor3f(127 / RGB, 255 / RGB, 212 / RGB);
		glPushMatrix();
		glTranslatef(-0.8, 0.3, -3);
		glScalef(1, 0.2, 1);
		glutSolidSphere(0.2, 30, 30);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.75, 0.2, -3);
		glRotatef(10, 0, 0, 1);
		glScalef(0.1, 2, 1);
		glutSolidCube(0.1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.85, 0.2, -3);
		glRotatef(-10, 0, 0, 1);
		glScalef(0.1, 2, 1);
		glutSolidCube(0.1);
		glPopMatrix();
		// 파라솔
		glPushMatrix();
		glTranslatef(-0.6, 0.6, -3);
		glRotatef(10, 0, 0, 1);
		glLineWidth(5);
		glColor3f(1, 1, 1);
		glBegin(GL_LINES);
		glVertex3f(0, 0.0, 0);
		glVertex3f(0, -0.5, 0);
		glEnd();
		glPushMatrix();
		glColor3f(0.5, 0.5, 0.5);
		glScalef(0.4, 0.4, 0.4);
		glRotatef(-70, 1, 0, 0); 
		glColor3f(255 / RGB, 140 / RGB, 0);
		glutSolidCone(1.3, 0.8, 12, 12);
		glPopMatrix();
		glPopMatrix();
		// 하트
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(1, 1, -3);
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(-0.1, 0.08, 0);
		glVertex3f(-0.1, 0.15, 0);
		glVertex3f(-0.05, 0.2, 0);
		glVertex3f(0, 0.15, 0);
		glVertex3f(0.05, 0.2, 0);
		glVertex3f(0.1, 0.15, 0);
		glVertex3f(0.1, 0.08, 0);
		glEnd();
		glPopMatrix();
	}
	else if (cnt == 2) { // 가을
		// sky
		glColor3f(0, 1, 1);
		glBegin(GL_POLYGON);
		glVertex3f(-10, 0, -7);
		glVertex3f(10, 0, -7);
		glVertex3f(10, 8, -7);
		glVertex3f(-10, 8, -7);
		glEnd();
		// green
		glColor3f(204 / RGB, 102 / RGB, 51 / RGB);
		glBegin(GL_POLYGON);
		glVertex3f(-10, -8, -7);
		glVertex3f(10, -8, -7);
		glVertex3f(10, 1, -7);
		glVertex3f(-10, 1, -7);
		glEnd();
		// road
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_POLYGON);
		glVertex3f(-10, -3, -7);
		glVertex3f(10, 0.7, -7);
		glVertex3f(10, -0.3, -7);
		glVertex3f(-10, -5, -7);
		glEnd();
		// 하트
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(1, 1, -3);
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(-0.1, 0.08, 0);
		glVertex3f(-0.1, 0.15, 0);
		glVertex3f(-0.05, 0.2, 0);
		glVertex3f(0, 0.15, 0);
		glVertex3f(0.05, 0.2, 0);
		glVertex3f(0.1, 0.15, 0);
		glVertex3f(0.1, 0.08, 0);
		glEnd();
		glBegin(GL_LINE_STRIP);
		glLineWidth(2);
		glColor3f(0, 0, 0);
		glVertex3f(0, 0, 0);
		glVertex3f(0.03, 0.03, 0);
		glVertex3f(-0.03, 0.06, 0);
		glVertex3f(0.03, 0.09, 0);
		glVertex3f(-0.03, 0.12, 0);
		glVertex3f(0, 0.15, 0);
		glEnd();
		glLineWidth(1);
		glPopMatrix();

		//낙엽
		for (int i = 0; i < MAX; i++) {
			glTranslatef(randx[i], randy[i] + 0.3, -3);
			Star(i % 3);
			glTranslatef(-randx[i], -(randy[i] + 0.3), 3);
		}

		// 나무 위
		glColor3f(153 / RGB, 51 / RGB, 0);

		glPushMatrix();
		glTranslatef(-0.32, 0.75, -3);
		glRotatef(-90, 0, 0, 1);
		glScalef(0.05, 0.2, 0);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.5, 0.65, -3);
		glRotatef(-60, 0, 0, 1);
		glScalef(0.05, 0.2, 0);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.55, 1.1, -3);
		glRotatef(-60, 0, 0, 1);
		glScalef(0.05, 0.2, 0);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.65, 1.0, -3);
		glRotatef(35, 0, 0, 1);
		glScalef(0.08, 0.25, 0.2);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.45, 0.75, -3);
		glRotatef(20, 0, 0, 1);
		glScalef(0.08, 0.3, 0.2);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-0.7, 0.85, -3);
		glRotatef(110, 0, 0, 1);
		glScalef(0.08, 0.6, 0.2);
		glutSolidCube(1);
		glPopMatrix();

		glPushMatrix();
		glTranslatef(-1.2, 1.1, -3);
		glRotatef(50, 0, 0, 1);
		glScalef(0.08, 0.6, 0.2);
		glutSolidCube(1);
		glPopMatrix();

		// 나무 몸통
		glColor3f(139 / RGB, 0, 0);
		glPushMatrix();
		glTranslatef(-1, 0.7, -3);
		glScalef(0.2, 1.5, 0.2);
		glutSolidCube(1);
		glPopMatrix();
	}
	else if (cnt == 3) { // 겨울
		// sky
		glColor3f(0.8, 0.8, 0.8);
		glBegin(GL_POLYGON);
		glVertex3f(-10, 1, -7);
		glVertex3f(10, 1, -7);
		glVertex3f(10, 8, -7);
		glVertex3f(-10, 8, -7);
		glEnd();
		// green
		glColor3f(255 / RGB, 250 / RGB, 250 / RGB);
		glBegin(GL_POLYGON);
		glVertex3f(-10, -8, -7);
		glVertex3f(10, -8, -7);
		glVertex3f(10, 1, -7);
		glVertex3f(-10, 1, -7);
		glEnd();
		// road
		glColor3f(0.5, 0.5, 0.5);
		glBegin(GL_POLYGON);
		glVertex3f(-10, -3, -7);
		glVertex3f(10, 0.7, -7);
		glVertex3f(10, -0.3, -7);
		glVertex3f(-10, -5, -7);
		glEnd();

		// 하트
		glPushMatrix();
		glColor3f(1, 0, 0);
		glTranslatef(0.95, 1, -3);
		glBegin(GL_POLYGON);
		glVertex3f(0, 0, 0);
		glVertex3f(-0.1, 0.08, 0);
		glVertex3f(-0.1, 0.15, 0);
		glVertex3f(-0.05, 0.2, 0);
		glVertex3f(0, 0.15, 0);
		glVertex3f(-0.03, 0.12, 0);
		glVertex3f(0.03, 0.09, 0);
		glVertex3f(-0.03, 0.06, 0);
		glVertex3f(0.03, 0.03, 0);
		glEnd();
		glPopMatrix();
		glPushMatrix();
		glTranslatef(1.05, 1, -3);
		glBegin(GL_POLYGON);
		glVertex3f(0.03, 0.03, 0);
		glVertex3f(-0.03, 0.06, 0);
		glVertex3f(0.03, 0.09, 0);
		glVertex3f(-0.03, 0.12, 0);
		glVertex3f(0, 0.15, 0);
		glVertex3f(0.05, 0.2, 0);
		glVertex3f(0.1, 0.15, 0);
		glVertex3f(0.1, 0.08, 0);
		glVertex3f(0, 0, 0);
		glEnd();
		glPopMatrix();

		//눈사람
		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(-0.8, 0.7, -3);
		glutSolidSphere(0.2, 50, 50);
		glTranslatef(0.8, -0.7, 0);
		glTranslatef(-0.8, 0.3, 0);
		glutSolidSphere(0.3, 50, 50);
		glPopMatrix();
		// 눈사람 팔
		glColor3f(153 / RGB, 51 / RGB, 0);
		glPushMatrix();
		glTranslatef(-0.5, 0.5, -3);
		glRotatef(-60, 0, 0, 1);
		glScalef(0.03, 0.3, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.45, 0.58, -3);
		glScalef(0.03, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.4, 0.5, -3);
		glRotatef(60, 0, 0, 1);
		glScalef(0.03, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-1.1, 0.5, -3);
		glRotatef(60, 0, 0, 1);
		glScalef(0.03, 0.3, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-1.15, 0.58, -3);
		glScalef(0.03, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-1.2, 0.5, -3);
		glRotatef(-60, 0, 0, 1);
		glScalef(0.03, 0.1, 0);
		glutSolidCube(1);
		glPopMatrix();
		// 눈사람 눈
		glColor3f(0, 0, 0);
		glPushMatrix();
		glTranslatef(-0.85, 0.75, -3);
		glRotatef(30, 0, 0, 1);
		glScalef(0.008, 0.08, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.891, 0.75, -3);
		glRotatef(-30, 0, 0, 1);
		glScalef(0.008, 0.08, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.7, 0.75, -3);
		glRotatef(30, 0, 0, 1);
		glScalef(0.008, 0.08, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.741, 0.75, -3);
		glRotatef(-30, 0, 0, 1);
		glScalef(0.008, 0.08, 0);
		glutSolidCube(1);
		glPopMatrix();
		// ㅋ
		glPushMatrix();
		glTranslatef(-0.8, 0.45, 0);
		glRotatef(90, 0, 0, 1);
		glTranslatef(0, 0, -3);
		glScalef(0.03, 0.25, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.69, 0.31, 0);
		glTranslatef(0, 0, -3);
		glScalef(0.03, 0.25, 0);
		glutSolidCube(1);
		glPopMatrix();
		glPushMatrix();
		glTranslatef(-0.8, 0.35, 0);
		glRotatef(90, 0, 0, 1);
		glTranslatef(0, 0, -3);
		glScalef(0.03, 0.2, 0);
		glutSolidCube(1);
		glPopMatrix();
	}
}
void MyTimer(int Value) {
	gTimeslot += 0.1; 
	if (!flag) { // 아래로
		wave -= 0.01;
		if (wave <= -0.1) flag = true;
	}
	else if (flag) { // 위로
		wave += 0.01;
		if (wave >= 0.1) flag = false;
	}
	if (gTimeslot > 1.5) {
		gTimeslot = -5; flag = false;
		cnt++; cnt %= 4;
		if (cnt == 1) between -= 0.5;
		else if (cnt == 2) between += 0.3;
		else between = 0;
	}
	glutPostRedisplay();
	glutTimerFunc(100, MyTimer, 1);
}
void MyReshape(int w, int h) {
	glClearColor(1, 1, 1, 1);
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLsizei)w / (GLsizei)h, 0, 9);
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(100, 0);
	glutCreateWindow("사계");
	for (int i = 0; i < MAX; i++) {
		float x = (rand() % 2000) + 1; if (i % 2 == 0) x *= 0.01; else x *= -0.01; randx[i] = x;
		float y = (rand() % 200) + 1; if (i % 2 == 0) y *= -0.001; else y *=  0.001; randy[i] = y;
	}
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutTimerFunc(100, MyTimer, 1);
	glutMainLoop();
	return 0;
}