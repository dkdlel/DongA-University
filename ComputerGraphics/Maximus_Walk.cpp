/*-----------------------------------------
14th week 2020. 6. 15


������ ����: ���ù��� �ȴ�!!

(1) blueleg �߰�
(2) BlackArm �߰�
(3) RedArm �߰�
(4) ���ù��� Ű�� ũ���ϱ� ���ؼ�, �ٸ� �Ϻθ� ���Ʒ��� �÷����� -> blueleg�� ����
(5) ���� �ø� -> �ٸ��� �Ȱ���
(6) ���ù��� run!!!!
(7) �౸�ϴ� ���ù���!!

(������ ������ kth, kwj ��ǰ�� �⺻���� ���ù����� �°� ������ �ҽ��Դϴ�.)
------------------------------------------*/

#include <glut.h>
#define _USE_MATH_DEFINES
#include <math.h>
const GLint x = 1, y = 0, z = 0;  // Ȥ�ó� ȸ���� ���� ���ؼ�
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
	YourBlackLeg(fabs(90 * cos(gTimeslot))); // Ʃ���� ���ļ� ���� ����!! 14-(6)

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
		glTranslatef(0.125, -0.95, 0.3); // blueleg�� ���� -> blueleg�� translate�Ѱ� ��
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
			glutSolidCube(1);	// �Ϻ�
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// ���
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
			glTranslatef(0.0, -0.25, 0.0); // 14-(5) -0.15 -> -0.25 ���Ʒ��� 0.1�� �þ�� ������ 1�� �������
			glScalef(0.15, 0.45, 0.15); // 14-(5) 0.25 --> 0.45 ���Ʒ��� 0.1�� �þ���Ƿ�
			glutSolidCube(1);	// �Ϻ�
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// ���
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
			glutSolidCube(1);	// �Ϻ�
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// ���
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
			glutSolidCube(1);	// �Ϻ�
		glPopMatrix();
		glScalef(0.15, 0.25, 0.15);	// ���
		glutSolidCube(1);
	glPopMatrix();
}
void YourFace() {
	glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // �챸��
	glPushMatrix();
	glTranslatef(0, 0.6, 0);
	glScalef(0.5, 0.5, 0.5);
	glutSolidSphere(0.5, 30, 30);	// face
	glPopMatrix();

	glColor3f(0, 0, 0); // black
	glPushMatrix();
	glTranslatef(-0.125, 0.6, 0.1);
	glScalef(0.05, 0.05, 0.05);
	glutSolidSphere(0.5, 30, 30);	// ��
	glPopMatrix();
	glPushMatrix();
	glTranslatef(0.125, 0.6, 0.1);
	glScalef(0.05, 0.05, 0.05);
	glutSolidSphere(0.5, 30, 30);	// ��
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
		glScalef(0.4, 0.65, 0.4); // ��������
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