#include <stdlib.h>
#include <stdio.h>
#include <glut.h>
#define WIN_WIDTH 1000 
#define WIN_HEIGHT 750
#define RGB 255.0
#define MAX 4000

float randx[MAX], randy[MAX];
GLfloat rightarmx, rightarmy, firstx = 0, firsty = 0, secondx = 0, secondy = 0;
GLint timeslot = 0;
const GLfloat light_pos[] = { 0, 0, 0, 1 }; // 광원의 위치
const GLfloat face_color[] = { 0.7, 0.7, 0.7, 1 };

void StreetLight() {
	// 가로등 빛
	glPushMatrix();
	glColor3f(1, 1, 0);
	glTranslatef(-2.44, -0.33, -3.9);
	glLightfv(GL_LIGHT0, GL_POSITION, light_pos); // 광원 이동
	glutSolidSphere(0.1, 50, 50);
	glTranslatef(2.44, 0.33, 3.9);
	glPopMatrix();
	// 가로등
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-3, 0, -4);
	glLineWidth(6);
	glBegin(GL_LINES);
	glVertex3f(0, -2, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0.5, -0.2, 0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_TRIANGLES);
	glVertex3f(0.5, -0.2, 0);
	glVertex3f(0.7, -0.3, 0);
	glVertex3f(0.3, -0.3, 0);
	glEnd();
	glPopMatrix();

}
void Bench() {
	// 벤치
	glPushMatrix();
	glColor3f(139 / RGB, 70 / RGB, 20 / RGB);
	glTranslatef(-2.1, -1.3, -3.7);
	glPushMatrix();
	glScalef(0.6, 0.4, 0.05);
	glutSolidCube(1);
	glPopMatrix(); // 벤치 뒷
	glPushMatrix();
	glTranslatef(0.145, -0.15, -0.1);
	glRotatef(260.0, 1, 0, 0);
	glScalef(0.5, 0.6, 0.05);
	glutSolidCube(1);
	glPopMatrix(); // 벤치 아래
	// 벤치 다리
	glPushMatrix();
	glTranslatef(-0.25, -0.4, 0);
	glScalef(0.1, 0.4, 0.05);
	glutSolidCube(1);
	glPopMatrix(); // 왼쪽 앞
	glPushMatrix();
	glTranslatef(0.25, -0.4, 0);
	glScalef(0.1, 0.4, 0.05);
	glutSolidCube(1);
	glPopMatrix(); // 오른쪽 앞
	glPushMatrix();
	glTranslatef(0.5, -0.28, 0);
	glScalef(0.1, 0.4, 0.05);
	glutSolidCube(1);
	glPopMatrix(); // 오른쪽 뒤
	glPushMatrix();
	glTranslatef(-0.05, -0.28, 0);
	glScalef(0.1, 0.4, 0.05);
	glutSolidCube(1);
	glPopMatrix(); // 왼쪽 뒤

	glPopMatrix(); // 벤치
}
void FaceBody() {
	// 얼굴
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, face_color);
	glEnable(GL_DEPTH_TEST);
	glPushMatrix();
	//glColor3f(0.2, 0.2, 0.2);
	glTranslatef(-2.15, -1, -3.9);
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	//팔
	glPushMatrix();
	glColor3f(251 / RGB, 206 / RGB, 177 / RGB);
	glTranslatef(-1.9, -2.15, -4);
	glLineWidth(3);
	glBegin(GL_LINE_STRIP); // 오른팔
	glVertex3f(-0.08, 1, 0);
	glVertex3f(-0.01, 1.05, 0);
	glVertex3f(-0.28 + rightarmx, 1.15 + rightarmy, 0);
	glEnd();
	glBegin(GL_LINE_STRIP); // 왼팔
	glVertex3f(-0.55, 1, 0);
	glVertex3f(-0.6, 1.05, 0);
	glVertex3f(-0.32, 1.15, 0);
	glEnd();
	glPopMatrix();

	// 다리
	glPushMatrix();
	glTranslatef(-2.5, -1.8, -4);
	glColor3f(251 / RGB, 206 / RGB, 177 / RGB);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex3f(0.4, 0, 0);
	glVertex3f(0.4, 0.3, 0);
	glEnd();
	glBegin(GL_LINES);
	glVertex3f(0.31, 0, 0);
	glVertex3f(0.31, 0.3, 0);
	glEnd();
	glPopMatrix();


}
void Star() {
	glColor3f(1, 1, 1);
	for (int i = 0; i < MAX; i++) {
		glTranslatef(randx[i], -1.5 + randy[i], -4);
		glutSolidSphere(0.01, 50, 50);
		glTranslatef(-randx[i], -(-1.5 + randy[i]), 4);
	}
}
void TimerStar(int Value) {

	timeslot = (timeslot + 1) % 120; // 0~119 반복

	if (timeslot <= 40) {
		rightarmx = 0; rightarmy = 0;
	}
	else if (timeslot <= 90) {
		rightarmx = 0.5; rightarmy = 0.2;
		if (timeslot >= 50) {
			firstx -= 0.1; firsty -= 0.01;
		}
		secondx -= 0.1; secondy -= 0.01;
		//printf("%d\n", timeslot);
	}
	else {
		rightarmx = 0; rightarmy = 0; firstx = 2.5; secondx = 2.5; firsty = 2.0; secondy = 2.0;
	}
	glutPostRedisplay();
	glutTimerFunc(500, TimerStar, 1);

} // MyTimerRain
void MyBackground() {
	// 밤하늘
	glColor3f(0, 0, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-10, -1.5, -3.9);
	glVertex3f(10, -1.5, -3.9);
	glVertex3f(10, 8, -3.9);
	glVertex3f(-10, 8, -3.9);
	glEnd();

	// 언덕
	glColor3f(0, 0.3, 0);
	glBegin(GL_POLYGON);
	glVertex3f(-10, -8, -3.9);
	glVertex3f(10, -8, -3.9);
	glVertex3f(10, -1.5, -3.9);
	glVertex3f(-10, -1.5, -3.9);
	glEnd();

	// 별똥별 좌표
	if (timeslot >= 40 && timeslot <= 90) {
		glPushMatrix();
		glLineWidth(1);
		glColor3f(1, 1, 0);
		glBegin(GL_POLYGON);
		glVertex3f(-0.05 + secondx, 0.05 + secondy, -4);
		glVertex3f(0.05 + secondx, 0.05 + secondy, -4);
		glVertex3f(secondx, -0.05 + secondy, -4);
		glEnd();
		glBegin(GL_POLYGON);
		glVertex3f(secondx, 0.1 + secondy, -4);
		glVertex3f(-0.05 + secondx, secondy, -4);
		glVertex3f(0.05 + secondx, secondy, -4);
		glEnd();
		glPopMatrix();
	}
	glLineWidth(3);
	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex3f(firstx, firsty, -4);
	glVertex3f(secondx, secondy, -4);
	glEnd();
	glLineWidth(1);

	Star();
	StreetLight();
	FaceBody();
	Bench();
	glutTimerFunc(500, TimerStar, 1);
}
void MySignature() {
	glPushMatrix();
	glColor3f(1, 1, 0); // 노란색
	// 좌측 상단을 기준으로 반시계 방향으로 좌표 생성
	glBegin(GL_LINE_STRIP);
	glVertex3f(-2, 1.3, -4);
	glVertex3f(-1.5, 0.5, -4);
	glVertex3f(0, -0.5, -4);
	glVertex3f(0.3, -0.3, -4);
	glVertex3f(2, 1.5, -4);
	glVertex3f(2.1, 1.7, -4);
	glVertex3f(-0.3, 1.15, -4);
	glVertex3f(-0.8, 1.23, -4);
	glVertex3f(-1.7, 1.25, -4);
	glVertex3f(-2, 1.3, -4);
	glEnd();

	glTranslatef(-2, 1.3, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(2, -1.3, 4);
	glTranslatef(-1.5, 0.5, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(1.5, -0.5, 4);
	glTranslatef(0, -0.5, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(0, 0.5, 4);
	glTranslatef(0.3, -0.3, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(-0.3, 0.3, 4);
	glTranslatef(2, 1.5, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(-2, -1.5, 4);
	glTranslatef(2.1, 1.7, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(-2.1, -1.7, 4);
	glTranslatef(-0.3, 1.15, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(0.3, -1.15, 4);
	glTranslatef(-0.8, 1.23, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(0.8, -1.23, 4);
	glTranslatef(-1.7, 1.25, -4);
	glutSolidSphere(0.03, 50, 50);
	glTranslatef(1.7, -1.25, 4);

	glPopMatrix();
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	MyBackground(); // 뒷 배경
	MySignature(); // 시그니처(염소자리)
	glutSwapBuffers();
}
void MyInit() {
	firstx = 2.5; secondx = 2.5; firsty = 2.0; secondy = 2.0;
	glClearColor(1.0, 1.0, 1.0, 1.0);
}
void MyReshape(int NewWidth, int NewHeight) {

	glViewport(0, 0, NewWidth, NewHeight);
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)WIN_WIDTH;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)WIN_HEIGHT;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, (GLfloat)NewWidth / (GLfloat)NewHeight, 1, 9);
}
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(150, 0);
	glutCreateWindow("시그니처 : 염소자리(생일에 해당하는 별자리)");
	// 별 좌표 생성
	for (int i = 0; i < MAX; i++) {
		float x = (rand() % 2000) + 1; if (i % 2 == 0) x *= 0.01; else x *= -0.01; randx[i] = x;
		float y = (rand() % 950) + 1; y *= 0.01; randy[i] = y;
	}
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}