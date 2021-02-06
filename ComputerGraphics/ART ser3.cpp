#include <glut.h>
double gTimeslot = -5, gBodyslot = 0;
bool flag = false;

void YourBackground();
void YourBody();
void YourFace();
void MyRightLeg();
void MyLeftLeg();
void MyRightArm(int angle);
void MyLeftArm(int angle);
void MyDisplay();
void MyTimer(int Value);
void MyReshape(int w, int h);
void Bong();

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	YourBackground();

	//gluLookAt(1, 0, 2, 0, 0, 0, 0, 1, 0);
	glTranslatef(0, 0, -5);

	glRotatef(-30, 0, 1, 0);

	MyRightArm(gTimeslot);

	glTranslatef(0, gBodyslot, 0);
	MyRightLeg();
	YourBody();
	YourFace();
	MyLeftLeg();
	glTranslatef(0, -gBodyslot, 0);

	MyLeftArm(gTimeslot);
	Bong();
	glutSwapBuffers();
}
void Bong() {
	// ¿ÞÂÊ ºÀ
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(-1.3, 0.2, 0);
	glScalef(0.1, 2.8, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	// ¿À¸¥ÂÊ ºÀ
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(1.3, 0.2, 0);
	glScalef(0.1, 2.8, 0.1);
	glutSolidCube(1);
	glPopMatrix();
	// °¡·Î ºÀ
	glPushMatrix();
	glColor3f(0.5, 0.5, 0.5);
	glTranslatef(0, 1.1, 0);
	glScalef(2.8, 0.1, 0.1);
	glutSolidCube(1);
	glPopMatrix();
}
void MyRightLeg() {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.125, -0.3, 0.0);
	//glRotatef(60, x, y, z); 
	glTranslatef(0, -0.2, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	//glRotatef(0, x, y, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glutSolidCube(1);	// ÇÏºÎ
	glPopMatrix();
	glScalef(0.15, 0.25, 0.15);	// »óºÎ
	glutSolidCube(1);
	glPopMatrix();
}
void MyLeftLeg() {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.125, -0.3, 0.0);
	//glRotatef( 60, x, y, z); 
	glTranslatef(0, -0.2, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	//glRotatef(0, x, y, z);
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glutSolidCube(1);	// ÇÏºÎ
	glPopMatrix();
	glScalef(0.15, 0.25, 0.15);	// »óºÎ
	glutSolidCube(1);
	glPopMatrix();
}
void MyRightArm(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(-0.35, 0.325, 0.0);
	glRotatef(-150, 0, 0, 1);
	glTranslatef(0, -0.125, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(0 - gTimeslot, 0, 0, 1); // -30±îÁö
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // »ì±¸»ö
	glutSolidCube(1);	// ÇÏºÎ
	glColor3f(0, 0, 0);
	glPopMatrix();
	glRotatef(gBodyslot * 170, 0, 0, 1);
	glTranslatef(-(gBodyslot * 0.3), 0, 0);
	glScalef(0.15, 0.25, 0.15);	// »óºÎ
	glutSolidCube(1);
	glPopMatrix();
}
void MyLeftArm(int angle) {
	glColor3f(0, 0, 0);
	glPushMatrix();
	glTranslatef(0.35, 0.325, 0.0);
	glRotatef(150, 0, 0, 1);
	glTranslatef(0, -0.125, 0);
	glPushMatrix();
	glTranslatef(0.0, -0.2, 0.0);
	glRotatef(0 + gTimeslot, 0, 0, 1); // 30±îÁö
	glTranslatef(0.0, -0.25, 0.0);
	glScalef(0.15, 0.45, 0.15);
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // »ì±¸»ö
	glutSolidCube(1);	// ÇÏºÎ
	glColor3f(0, 0, 0);
	glPopMatrix();
	glRotatef(-gBodyslot * 170, 0, 0, 1);
	glTranslatef(gBodyslot * 0.3, 0, 0);
	glScalef(0.15, 0.25, 0.15);	// »óºÎ
	glutSolidCube(1);
	glPopMatrix();
}
void YourFace() {
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // »ì±¸»ö
	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 30, 30);	// face
	glPopMatrix();

	if (flag) {
		glColor3f(0, 0, 0); // black
		glPushMatrix();
		glTranslatef(-0.125, 0.6, 0.1);
		glScalef(0.05, 0.05, 0.05);
		glutSolidSphere(0.5, 30, 30);	// ´«
		glPopMatrix();
		glPushMatrix();
		glTranslatef(0.125, 0.6, 0.1);
		glScalef(0.05, 0.05, 0.05);
		glutSolidSphere(0.5, 30, 30);	// ´«
		glPopMatrix();
		glPopMatrix();
	}
	else {
		glColor3f(0, 0, 0);
		glLineWidth(3);
		glBegin(GL_LINES); // ¿ÞÂÊ ´«¼·
		glVertex3f(0.05, 0.65, 0);
		glVertex3f(0.2, 0.7, 0);
		glEnd();
		glBegin(GL_LINES); // ¿ÞÂÊ ´«¼·
		glVertex3f(-0.05, 0.65, 0);
		glVertex3f(-0.2, 0.7, 0);
		glEnd();
		glBegin(GL_LINES); // ÀÔ
		glVertex3f(-0.1, 0.55, 0);
		glVertex3f(0.1, 0.55, 0);
		glEnd();


		glLineWidth(1);
	}
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
	glScalef(0.4, 0.65, 0.4); // ÃëÇâÂ÷ÀÌ
	glutSolidCube(1);
	glPopMatrix();
}
void MyTimer(int Value) {
	if (flag) {
		gTimeslot -= 1; gBodyslot -= 0.005;
		if (gTimeslot == 0) flag = false;
	}
	else {
		gTimeslot += 1; gBodyslot += 0.005;
		if (gTimeslot > 30) flag = true;
	}
	glutPostRedisplay();
	glutTimerFunc(100, MyTimer, 1);
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
	glutCreateWindow("Maximus do pull-up bar");
	glutTimerFunc(100, MyTimer, 1);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}