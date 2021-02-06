/*-----------------------------------------------------------
  6th week (2020. 4. 20)

Keyboard
u a s : face
l k : blueleg
f d : blackleg
p o : right lower arm (90 ~ -90 restict)
r e : left lower arm
0 9 : �ȱ���

Special
UP and DOWN : jump
LEFT and RIGHT : moving-X
F1~F3, F4~F6 : shear
F11, F12 : moving-Z

Motion
Menu

6����
(1) ȸ����Ű���� � ���Ϻ�ȯ �Լ��� �ʿ��ұ��? -> glRotatef(����, x��, y��, z��);
(2) ��� ���� ���󿡼� ���ù����� �ٸ��� ��� ���� �������� ȸ���ϰ� �ֳ���? -> z�� ����
(3) blue leg�� ȸ����Ű�� �ٸ� �κп� ������ ���ַ��� � �Լ��� ȣ���ؾ� �ϳ���? -> glPushMatrix(); glPopMatrix();
(4) ȸ����Ű�ϱ� �ٸ��� ��ü���� �и��˴ϴ�. �� ������ �����? -> ������ �������� ȸ���ϱ� ������, �ٸ��� ������ �ƴ� �ٸ� �������� ���� �; ������������ ȸ��
(5) ��Ȯ�� ������� �߽����� ȸ���Ϸ��� ��� �ϸ� �ɱ��?
	 -> 1.�ٸ��� �������� �̵� -> 2.ȸ�� -> 3.���󺹱� (�������� ����)
	 �ڵ�����
	 push
	 3. �ٸ� �������� ��ġ�� ����
	 2. ȸ��
	 1. �ٸ� �������� ��ġ�� �ݴ�
	 �ٸ�(Begin ~ End)
	 pop

week 7
(1) ���� �Ȳ�ġ �Ʒ�(forearm)�� �����Դϴ�. �� ��ü ȸ�� ����� �߰��ϼ��� (P O R E)
	�������� ȥ���� ����ǹǷ� gRedforearm -> gRedforearm, gBlackforearm -> gBlackforearm ����
	�� ��ü�� �������� gRedupperarm, gBlackupperarm����
(2) �����ȿ� �þ�� ����� �߰�
	'0'(zero) ������ ���� �������, '9' ������ ���� ���󺹱��ϴ� �ڵ带 �߰�
(3) ���� scale �Լ��� translate �����ʰ� �ٷ� �𵨿� �����ϸ� �����? -> ������ ������ �ƴϱ� ������ ���� �þ�°� �ƴϰ� ���� Ŀ��
(4) ���� scale �Լ��� ��ü�� ���δ� push/pop ���� ���� ������ �����? -> ��ü�� �׳� �� Ŀ��
(5) �� ���� ����ġ�� �����ϰ� shear�� �����غ�����.
	�������� 1��, �迭����, ��İ� �Լ�(���Ʒ��� tanslate), special�Լ����� F1,F2,F3 �߰�
(6) 2���� �迭�� MyDisplay �Լ��ȿ� ���������� �����ߴµ�, ���������� �ٲٸ� � ���? ��������?
	-> �迭 ���� �� �ȿ� ������ ��������� �װ� ���� ��� ������ ���� ����ִ°Ŷ� ����, ���������� �����ϸ� �׳� 0�� ����ִ°Ŷ� ����, ���������� �Լ� ȣ��ø��� �迭�� ����ǹǷ�
	special�Լ����� �ٲ� ���� �ʱⰪ���� ���� ��
(7) �ٸ����� ����

week 9
(1) 6���� �������� �߰�
	1.������ ��ġ(x,y) 2.ȭ��ũ�Ⱑ ���������� ���ο� x,y(gNewWidth, gNewHeight) 3.ȭ�����(gWidthFactor, gHeightFactor)
(2) MyCandy�Լ��� ��ü������ glTranslatef(gCandyX, gCandyY,0); ���� �߰�
(3) MyMotion�Լ� ����
(4) MyReshape�Լ����� �������� 4���� ���������� �־���
(5) main���� glutMotionFunc ȣ��

week 10
(1) menu �߰� - day, night (������, �ϴ�, �ʿ�, ��Ʈ �� ����, �� �� �ٿ��Ŵ)
(2) timer �߰� - rain ǥ�� (����Լ��� Ư���� �̿��ؼ� �񳻸��� �� ǥ��)

week 11

 4 ~ 9������ ����غ� Z-���۴� ��а� ������� ����
 (1) ��Ʈ�� �ٴڿ� polygon���� ���ƴµ�, glOrtho�� �ϸ� �Ⱥ��̴� ����?
 -> �������� �β��� �����Ƿ�, ������������ ���鿡�� �ٶ󺸸� ���� �ƿ� �Ⱥ���. �������� �ϸ� �� ���� ^^
 (2) ��(����)�� motion���� �����̸� ������ �� �߳������� �ȵǴ� ����?
 -> ���� �߽� y���� �������� ��ġ�� �־��� ������ ������ �Ŀ��� �߳������� �ȵ�.
	��(����)�� ������� ��ġ�� ���� �� �Ʒ� �̵��Լ��� �ٲ��ָ� ��.
 (3) glOrtho�϶� �� �Ǵ� motion�� ���� �����ϱ� ���콺 ��ġ�� ���� �ٸ��� ���̴� ����?
 -> �� ���󿡼��� ��/���� ������ z�� ���ǹ������� �̵��ߴ���, �ణ ���� �ִ� ��ó�� ����. ���� ��ġ��.
	���콺 Ŀ�� ��ġ, ����ġ z���� �ٸ��� ������ �̼��ϰ� �޶���(Ʋ���� �ƴ�)

(4) Mydisplay glClear�� GL_DEPTH_BUFFER_BIT �߰�
(5) Main InitDisplayMode�� GLUT_DEPTH�߰�
(6) MyInit�� glEnalbe(GL_DEPTH_TEST); �߰� -> ��а� ���ù������� �������� �������� ������ �ּ� ó��
(7) MYBackgroud���� ���� ������ -3.9�� ���� -> �����ڸ� �ȸ¾Ƽ�
(8) �������� ������ �ʴ� ���� : solidspear�� z���� ������ �־ �� �ؿ� �������
	-> EyeMouth���� z���� �����ϱ� ���� translate
(9) ��Ʈ�� 3D���·� �ٴڿ� ������ ��Ʈ�� ��ȯ

week 13
1. ���� ��������, ���� ������ �޺� �־��ְ�
2. �� ������ ���� on, �� �Ʒ����� ���� off
3. ����޴� �Ͽ��� �󱼻��� glMaterialfv�� �������ְ�
4. ���� ������ �Ȳ��ָ�? -> �ѹ� materialfv�Լ��� �۵��Ǹ�, ��� ȿ������.
5. ���� z-buffer�� ������ �ʴ� ��Ȳ. ���� z��(�յ���ġ)�� ����ġ ���� �������� ����.
	�����༺�Ķ��༺�� z-buffer�� �����ֱ� ������, ������ �յ� �̵��� �� ������ �� ����.
	==> ���� on/off�� �� z-buffer�� on/off���ָ�, �յ� �̵��ÿ��� ������ �� �۵�!!
6. Ÿ�̸Ӹ� �̿��� ȥ�� �����̴� ���ù���!! -> ���̵�(�Լ�), Ÿ�̸�

(1) �������� 2�� ����(�󱼻�, ������ ��ġ)
(2) �� �׸���(background��)
(3) ����Ű��(face��)
(4) z-bufferŰ��(init���� �ѵ� ������ face���� ����� �Բ� ���� Ű��)
	-> �󱼿��� ������ �ֱ� ������ �����Կ� ������ �������
(5) mainmenu�� Ÿ�̸� �Ѱ� �߰�, mytimerNight �Լ� ���� 

week 14
 (����) Night���� ������ �� �ε巴�� �����̷���?
  -> Ÿ�̸ӿ��� ������ �ð� 100���� 0.1�� �¿�� �̵� ==> �ð� 10���� 0.001�� �����δٸ�?

  ���ù����� ����Ʈ����Ʈ�� �޵���
  (1) Mainmenu, MyInit, MyBackground, MyDisplay�� 1�� �߰�, �������� 4���߰�
   ==> �����ֿ� ���
-------------------------------------------------------------*/

#include <glut.h>
#define WIN_WIDTH 1000  // window 4:3
#define WIN_HEIGHT 750

unsigned char gFace = 'u';   // u:usual  a:angry   s:smiling
GLfloat gY = 0.0;  // jump
GLfloat gX = 0.0;  // moving-X
GLfloat gZ = 0.0; // �յ��̵�
GLfloat gBlueleg = 0.0, gBlackleg = 0.0; // ȸ������
GLfloat gRedforearm = 0.0, gBlackforearm = 0.0, gRedupperarm = 0.0, gBlackupperarm = 0.0; // ȸ������
GLfloat gRedarmlength = 1; // �������� ����
GLfloat gShear = 0.0, gShearleg = 0.0; // 7-(5), 7-(7)
GLfloat gCandyShear = 0.0, gStickShear = 0.0; // ������ ������ ���� ����
// 9-(1)
GLfloat gCandyX = -2.8, gCandyY = -1.5;
GLfloat gWidthFactor, gHeightFactor;
GLint gNewWidth, gNewHeight;
unsigned char gBackground = 'D'; // ��
GLint gTimeslot = 0; // timer
// 13-(1)
const GLfloat gLight_pos[] = { 0, 0, 0, 1 }; // ������ ��ġ
const GLfloat gFace_color[] = { 251 / 255.0, 206 / 255.0, 177 / 255.0, 1 }; // �󱼻�(�챸��)
const GLfloat gBlack[] = { 0,0,0,1 }; // 14-(1)
const GLfloat gBlue[] = { 0,0,1,1 }; // 14-(1)
const GLfloat gRed[] = { 1,0,0,1 }; // 14-(1)
const GLfloat gGray[] = { 0.5,0.5,0.5,1 }; // 14-(1)

void MyBackground();
void MyMat();
void MyFace();
void MyEyeMouth();
void MyBody();
void MyCandy();
void MyMotion(GLint X, GLint Y);
void MyMainMenu(int entryID);
void MyUnbrlla();
void MyDisplay();
void MyKeyboard(unsigned char key, int x, int y);
void MySpecial(int key, int x, int y);
void MyReshape(int NewWidth, int NewHeight);
void MyTimerRain(int Value);
void MyTimerNight(int Value);
void MyInit();
void MyTimerFlower(int Value);
void MyCandy() {
	// ������ ���κ�
	glColor3f(255 / 255.0, 153 / 255.0, 255 / 255.0);
	// 9 -(2)
	glTranslatef(gCandyX, gCandyY, 0);

	glPushMatrix();
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	// ������ �Ʒ��κ�

	glPushMatrix();
	GLfloat CandyStick_arr[4][4] = {
		{1,0,0,0},
		{gStickShear,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	};
	glTranslatef(0, -0.2, 0);
	glMultMatrixf((float*)CandyStick_arr);
	glTranslatef(0, 0.2, 0);
	glColor3f(0.5, 0.5, 0.5);
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex3f(0, -0.2, 0);
	glVertex3f(0, -0.8, 0);
	glEnd();
	glLineWidth(1);
	glPopMatrix();
}
void MyMotion(GLint X, GLint Y) {
	// 9 - (3)
	gCandyX = (GLfloat)X / gNewWidth * 8 * gWidthFactor - 4 * gWidthFactor;
	gCandyY = (GLfloat)(gNewHeight - Y) / gNewHeight * 6 * gHeightFactor - 3 * gHeightFactor;

	glutPostRedisplay();
}
void MyUnbrlla() {
	if (gBackground == 'R') {
		gBlackforearm = -50;
		gBlackupperarm = 0;

		glPushMatrix();
		glTranslatef(-0.5, 1.5, 0);
		glPushMatrix();
		glLineWidth(3);
		glColor3f(0.5, 0.5, 0.5);
		glScalef(1.3, 0.4, 0.4);
		glRotatef(-45, 1, 0, 0);
		glutWireCone(1.0, 1.5, 12, 12);
		glPopMatrix();
		glBegin(GL_LINES);
		glVertex3f(0, 0.5, 0);
		glVertex3f(0, -1.5, 0);
		glEnd();
		glPopMatrix();
	}
}
void MyDisplay() {
	// �Ʒ� ������ �׻� ����
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 11-(4)
	glMatrixMode(GL_MODELVIEW); // display�� Modelview
	glLoadIdentity();

	glTranslatef(0, 0, -5); // ���� ��ǥ�� ���� ��ü�� ������ ������
	//glScalef(1, -1, 1); // 2d���� x�࿡ ���� �ݻ�
	//glScalef(-1, 1, 1); // 2d���� y�࿡ ���� �ݻ�

	//��� 14-(1)
	if(gBackground != 'S'){
		MyBackground();
		MyMat();
	}

	//// y=x �� ���� �ݻ�
	//glRotatef(-45, 0, 0, 1);
	//glScalef(-1, 1, 1);
	//glRotatef(45, 0, 0, 1);

	// ���⼭���ʹ� Maximus
	//glTranslatef(2, 0, 0); // y=x�� ���� �ݻ�
	glPushMatrix();
	glTranslatef(gX, gY, gZ); // left, right, jump, �յ�
	GLfloat Shear_arr[4][4] = {
		{1,0,0,0},
		{gShear,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	};
	glTranslatef(0, -1, 0); // ���ù����� �߳�
	glMultMatrixf((float*)Shear_arr);
	glTranslatef(0, 1, 0);
	glPushMatrix();
	MyFace();
	glPopMatrix();

	MyEyeMouth();
	MyBody();
	MyUnbrlla();
	glPopMatrix();

	// ���ܸ� �����ϴ� ���� ����
	glPushMatrix();
	GLfloat Candy_arr[4][4] = {
		{1,0,0,0},
		{gCandyShear,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	};

	glTranslatef(gCandyX, gCandyY - 0.8, 0); // 11-(2)
	glMultMatrixf((float*)Candy_arr);
	glTranslatef(-gCandyX, -(gCandyY - 0.8), 0);
	glPushMatrix();
	MyCandy();
	glPopMatrix();
	glPopMatrix();

	glutSwapBuffers();

} // MyDisplay
void MyBackground() {

	if (gBackground == 'D') glColor3f(0, 1, 1); // sky 
	else glColor3f(0.2, 0.2, 0.2); // ���׷���

	glBegin(GL_POLYGON);
	glVertex3f(-10, 0, -3.9);
	glVertex3f(10, 0, -3.9);
	glVertex3f(10, 8, -3.9);
	glVertex3f(-10, 8, -3.9);
	glEnd();

	if (gBackground == 'D') glColor3f(0, 1, 0); // green 
	else glColor3f(0, 0.3, 0); // ���׸�

	glBegin(GL_POLYGON);
	glVertex3f(-10, -8, -3.9); // 11-(7)
	glVertex3f(10, -8, -3.9);
	glVertex3f(10, 0, -3.9);
	glVertex3f(-10, 0, -3.9);
	glEnd();

	if (gBackground == 'R') { // Rain
		glColor3f(0.9, 0.9, 0.9); // ���
		if (gTimeslot % 3 == 0) {
			glBegin(GL_LINES);
			glVertex3f(-3, 2, 0);		glVertex3f(-3, 1.8, 0); // ����
			glVertex3f(3.3, 2.8, 0);	glVertex3f(3.3, 2.6, 0); // ����
			glEnd();
		}
		else if (gTimeslot % 3 == 1) {
			glBegin(GL_LINES);
			glVertex3f(0, 2.7, 0);		glVertex3f(0, 2.5, 0); // �߰�
			glEnd();
		}
		else {
			glBegin(GL_LINES);
			glVertex3f(-1, 1.7, 0);		glVertex3f(-1, 1.5, 0); // ����
			glVertex3f(2.9, 1.8, 0);	glVertex3f(2.9, 1.6, 0); // ����
			glEnd();
		}

		// ��� �߰� --> ������ �׸��� ���߿� ���ù����� �׷ȱ� ������, ���� ������ ������ ������ �߰��ϸ� �ȵ�
	}
	// 13-(2)
	if (gBackground == 'N') { // ���̸�
		glTranslatef(0, 3, 0); // ����ġ �̵�
		glLightfv(GL_LIGHT0, GL_POSITION, gLight_pos); // ������ �ִ� ������ �̵�
		glColor3f(0.9, 0.9, 0.9); // ȸ��
		glutSolidSphere(0.05, 30, 30); // �ޱ׸�
		glTranslatef(0, -3, 0); // �ٸ��� ���� �ȹް� �Ҷ��
	}
}
void MyMat()
{

	if (gBackground == 'D') glColor3f(0xE4 / 255.0, 0xBE / 255.0, 0xFE / 255.0); // �������	
	else glColor3f(0.3, 0, 0.3); // ������

	//glBegin(GL_POLYGON);
	//glVertex3f(-1.5, -1.3, 0); // �ٴڿ� �����־�� �ϴµ�, ���� 2D�� ���߿� ���ִ� ����纯��
	//glVertex3f(1.2, -1.3, 0); // 3D�ΰ���, ��¥ �ٴڿ� ������ ��Ʈ�� ��ȯ�� ����
	//glVertex3f(1.5, -0.8, 0);
	//glVertex3f(-1.2, -0.8, 0);
	//glEnd();

	glBegin(GL_POLYGON); // 11-(9), �β��� ���� �鸸 ���̼� ���鿡�� ���� �Ⱥ���
	glVertex3f(-1.5, -1, 1.5); // �ٴڿ� ������ ���簢��
	glVertex3f(1.5, -1, 1.5);
	glVertex3f(1.5, -1, -1.5);
	glVertex3f(-1.5, -1, -1.5);
	glEnd();

} // MyMat
void MyFace() {

	if (gBackground == 'D') glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // �챸��
	else glColor3f(0.6, 0.4, 0.4);

	if (gBackground == 'N') {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gFace_color);// �������� �󱼻� �ִ� �Լ�
		glEnable(GL_DEPTH_TEST); // 13-(4)
	}
	// ���� ��
	glPushMatrix(); // ��� ����(3�忡�� �ڼ��� ���)
	glTranslatef(0, 1, 0); // ���� �̵���Ű�� ���ؼ�
	glutSolidSphere(0.5, 50, 50); // glut�� ������ �������� �׷���
	glPopMatrix(); // push�� ������ pop

	// ���� ���ֱ�
	if (gBackground == 'N') {
		glDisable(GL_LIGHTING);
		glDisable(GL_DEPTH_TEST); // 13-(4)
	}

} // MyFace 
void MyEyeMouth() {

	//glTranslatef(0, 0, 0.5); // 11-(8)

	if (gFace == 'a') {  // angry

		glColor3f(0, 0, 0); // black
		glBegin(GL_LINES);
		glVertex3f(-0.3, 1.2, 0.0); // eye
		glVertex3f(-0.1, 1.0, 0.0);
		glVertex3f(0.1, 1.0, 0.0); // eye
		glVertex3f(0.3, 1.2, 0.0);
		glEnd();

		glBegin(GL_LINE_LOOP); // mouth
		glVertex3f(-0.1, 0.9, 0.0);
		glVertex3f(0.1, 0.9, 0.0);
		glVertex3f(0.1, 0.8, 0.0);
		glVertex3f(-0.1, 0.8, 0.0);
		glEnd();
	}
	else if (gFace == 's') { // smiling

		glColor3f(0, 0, 0); // black
		glBegin(GL_LINE_STRIP); // eye
		glVertex3f(-0.3, 1.1, 0.0);
		glVertex3f(-0.2, 1.15, 0.0);
		glVertex3f(-0.1, 1.1, 0.0);
		glEnd();

		glBegin(GL_LINE_STRIP);	// eye
		glVertex3f(0.1, 1.1, 0.0);
		glVertex3f(0.2, 1.15, 0.0);
		glVertex3f(0.3, 1.1, 0.0);
		glEnd();

		glColor3f(1, 0, 0); // red
		glBegin(GL_LINE_LOOP); // mouth
		glVertex3f(-0.1, 0.9, 0.0);
		glVertex3f(0.1, 0.9, 0.0);
		glVertex3f(0, 0.8, 0.0);
		glEnd();
	}
	else if (gFace == 'u') { // usual

		glColor3f(0, 0, 0); // black
		glBegin(GL_LINES);
		glVertex3f(-0.3, 1.1, 0.0); // eye
		glVertex3f(-0.1, 1.1, 0.0);
		glVertex3f(0.1, 1.1, 0.0); // eye
		glVertex3f(0.3, 1.1, 0.0);
		glVertex3f(-0.1, 0.9, 0.0); // mouth
		glVertex3f(0.1, 0.9, 0.0);
		glEnd();
	}

	//glTranslatef(0, 0, -0.5); // ������ �̵��ߴٸ� �ٸ��Ϳ� ������ ���� �ʱ� ���� �ڷ� �̵�

} // MyEyeMouth
void MyBody() {

	glColor3f(0, 0, 0); // black neck
	glBegin(GL_LINES);
	glVertex3f(0, 0.5, 0.0);
	glVertex3f(0, 0.3, 0.0);
	glEnd();

	glColor3f(0.5, 0.5, 0.5); // gray spine
	glBegin(GL_POLYGON);
	glVertex3f(-0.05, -0.3, 0.0);
	glVertex3f(0.05, -0.3, 0.0);
	glVertex3f(0.05, 0.3, 0.0);
	glVertex3f(-0.05, 0.3, 0.0);
	glEnd();


	glPushMatrix(); // red ū �� ����
	glTranslatef(0.05, 0.3, 0.0);
	glRotatef(gRedupperarm, 0, 0, 1);
	glScalef(gRedarmlength, gRedarmlength, 1);
	glTranslatef(-0.05, -0.3, 0.0);
	glLineWidth(3); // line 
	glColor3f(1, 0, 0); // red arm
	glBegin(GL_LINES); // upper
	glVertex3f(0.05, 0.3, 0.0);
	glVertex3f(0.25, 0.1, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(0.25, 0.1, 0.0);
	glRotatef(gRedforearm, 0, 0, 1);
	glTranslatef(-0.25, -0.1, 0.0);
	glBegin(GL_LINES); // lower	
	glVertex3f(0.25, 0.1, 0.0);
	glVertex3f(0.5, -0.2, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix(); // ū �� pop

	glPushMatrix(); // black ū �� ����
	glTranslatef(-0.05, 0.3, 0.0);
	glRotatef(gBlackupperarm, 0, 0, 1);
	glTranslatef(0.05, -0.3, 0.0);
	glColor3f(0, 0, 0); // black arm
	glBegin(GL_LINES); //upper
	glVertex3f(-0.05, 0.3, 0.0);
	glVertex3f(-0.25, 0.1, 0.0);
	glEnd();

	glPushMatrix();
	glTranslatef(-0.25, 0.1, 0.0);
	glRotatef(gBlackforearm, 0, 0, 1);
	glTranslatef(0.25, -0.1, 0.0);
	glBegin(GL_LINES); //lower
	glVertex3f(-0.25, 0.1, 0.0);
	glVertex3f(-0.5, -0.2, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix(); // ū �� pop

	// �ٸ��� ����
	glPushMatrix(); // �ٸ� �ΰ� ����
	GLfloat Shearleg_arr[4][4] = {
		{1,0,0,0},
		{gShearleg,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	};
	glTranslatef(0, -0.3, 0);
	glMultMatrixf((float*)Shearleg_arr);
	glTranslatef(0, 0.3, 0);

	glColor3f(0, 0, 1); // blue leg
	glPushMatrix();
	glTranslatef(0.05, -0.3, 0.0); // (3) �ٸ��� ���󺹱�
	glRotatef(gBlueleg, 0, 0, 1); // (2) z�� �������� ȸ��
	glTranslatef(-0.05, 0.3, 0.0); // (1) �ٸ��� �������� �����ϵ��� �̵�
	glBegin(GL_LINES);
	glVertex3f(0.05, -0.3, 0.0); // leg high point
	glVertex3f(0.3, -1.0, 0.0);
	glEnd();
	glPopMatrix();

	glColor3f(0, 0, 0); // black leg
	glPushMatrix();
	glTranslatef(-0.05, -0.3, 0.0);
	glRotatef(gBlackleg, 0, 0, 1);
	glTranslatef(0.05, 0.3, 0.0);
	glBegin(GL_LINES);
	glVertex3f(-0.05, -0.3, 0.0);
	glVertex3f(-0.3, -1.0, 0.0);
	glEnd();
	glPopMatrix();
	glPopMatrix(); // �δٸ� �����Ѱ� pop
	glLineWidth(1);  // line

} // MyBody
void MyKeyboard(unsigned char key, int x, int y) {

	switch (key) {

	case 'Q':
	case 'q':	exit(0);  break;

	case 'a':
	case 's':
	case 'u':   gFace = key;   break;	 // face

	case 'l':	gBlueleg += 10; break; // �ٸ�ȸ��
	case 'k':	gBlueleg -= 10; break;

	case 'f':	gBlackleg += 10; break; // �ٸ�ȸ��
	case 'd':	gBlackleg -= 10; break;

	case 'p':	if (gRedforearm < 90) gRedforearm += 3; break;
	case 'o':	if (gRedforearm > -90) gRedforearm -= 3; break;

	case 'r':	if (gBlackforearm < 90) gBlackforearm += 3; break;
	case 'e':	if (gBlackforearm > -90) gBlackforearm -= 3; break;

	case 'P':	if (gRedupperarm < 90) gRedupperarm += 3; break;
	case 'O':	if (gRedupperarm > -90) gRedupperarm -= 3; break;

	case 'R':	if (gBlackupperarm < 90) gBlackupperarm += 3; break;
	case 'E':	if (gBlackupperarm > -90) gBlackupperarm -= 3; break;

	case '0':	gRedarmlength *= 1.1; break;
	case '9':	if (gRedarmlength > 1) gRedarmlength /= 1.1; break;
	}

	glutPostRedisplay();

} // MyKeyboard
void MySpecial(int key, int x, int y) {

	switch (key) {

	case GLUT_KEY_UP:
		gY = 1;
		gFace = 's';
		gRedforearm = 30; // �ݽð�
		gBlackforearm = -30; // �ð�
		gBlueleg = -19.5; // �ݽð�
		gBlackleg = 19.5; // �ð�
		break;
	case GLUT_KEY_DOWN:
		gY = 0;
		gFace = 'u';
		gRedforearm = gBlackforearm = gBlueleg = gBlackleg = 0;
		break;
	case GLUT_KEY_LEFT:
		if (gY == 0) {
			gX -= 0.1;
			if (gX < -1.5 || gX > 1.5) gFace = 'a';
			else gFace = 'u';
		}
		break;
	case GLUT_KEY_RIGHT:
		if (gY == 0) {
			gX += 0.1;
			if (gX < -1.5 || gX > 1.5) gFace = 'a';
			else gFace = 'u';
		}
		break;
	case GLUT_KEY_F1: gShear = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = -0.5; break; // ���� ����
	case GLUT_KEY_F2: gShear = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gCandyShear = 0.0; break;
	case GLUT_KEY_F3: gShear = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = 0.5; break;

	case GLUT_KEY_F4: gShearleg = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = 0.5; break; // �ٸ� ���� (���Ű� ��ȣ�� �ٸ� ���� : ��ݽ��� �������� �ٸ��� ������)
	case GLUT_KEY_F5: gShearleg = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gStickShear = 0.0; break;
	case GLUT_KEY_F6: gShearleg = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = -0.5; break;


	case GLUT_KEY_F11:  if (gZ <= 3) gZ += 0.1; break;
	case GLUT_KEY_F12: if (gZ >= -3)gZ -= 0.1; break;
	}

	glutPostRedisplay();

} // MySpecial
void MyReshape(int NewWidth, int NewHeight) {

	glViewport(0, 0, NewWidth, NewHeight); // �����ϴ��� �������� â�� ��ü ũ�� ����
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)WIN_WIDTH;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)WIN_HEIGHT;
	// ���� �����̱� ���� ���� ���� 9-(4)
	gWidthFactor = WidthFactor; gHeightFactor = HeightFactor;
	gNewWidth = NewWidth; gNewHeight = NewHeight;
	glMatrixMode(GL_PROJECTION); // reshape���� projection
	glLoadIdentity();
	//glOrtho(-4.0 * WidthFactor, 4.0 * WidthFactor, -3.0 * HeightFactor, 3.0 * HeightFactor, 1, 9); // z���� x�� �����ɷ� ����
	gluPerspective(65, (GLfloat)NewWidth / (GLfloat)NewHeight, 1, 9); // �������� -1 ~ -9

} // MyReshape
void MyTimerRain(int Value) {
	if (gBackground == 'R') {
		gTimeslot = (gTimeslot + 1) % 100; // 0~99 �ݺ�
		//printf("gTimeslot : %d\n", gTimeslot);
		glutPostRedisplay();
		glutTimerFunc(400, MyTimerRain, 1);
	}
} // MyTimerRain
void MyTimerNight(int Value) {
	// 13-(5)
	if (gBackground != 'N') return; // ���� �ƴѰ�� return

	gTimeslot = (gTimeslot + 1) % 120; // 0~119 �ݺ�
	// ���ù����� ������
	if (gTimeslot < 5) { // ����
		gY = 1;
		gFace = 's';
		gRedforearm = 30; // �ݽð�
		gBlackforearm = -30; // �ð�
		gBlueleg = -19.5; // �ݽð�
		gBlackleg = 19.5; // �ð�
	}
	else if (gTimeslot < 10) { // ������
		gY = 0;
		gFace = 'u';
		gRedforearm = gBlackforearm = gBlueleg = gBlackleg = 0;
	}
	else if ((gTimeslot < 30) || (gTimeslot >= 70 && gTimeslot < 90)) { // 20��ŭ ����, 40��ŭ ������, 20��ŭ ���� �̵�
		if (gY == 0) {
			gX -= 0.1;
			if (gX < -1.5 || gX > 1.5) gFace = 'a';
			else gFace = 'u';
		}
	}
	else if (gTimeslot < 70) { // ���������� �̵�
		if (gY == 0) {
			gX += 0.1;
			if (gX < -1.5 || gX > 1.5) gFace = 'a';
			else gFace = 'u';
		}
	}
	else if (gTimeslot == 90 || gTimeslot == 91 || gTimeslot == 94 || gTimeslot == 95){ // ���� ����
		gShearleg = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = 0.5;// �ٸ� ���� (���Ű� ��ȣ�� �ٸ� ���� : ��ݽ��� �������� �ٸ��� ������)
	}
	else if (gTimeslot == 92 || gTimeslot == 93 || gTimeslot == 96 || gTimeslot == 97) { // ������ ����
		gShearleg = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = -0.5;
	}
	else if(gTimeslot < 100) {
		gShearleg = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gStickShear = 0.0;
	}
	else if(gTimeslot < 107){ // ���� ����
	 gShear = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = -0.5;
	} 
	else if (gTimeslot < 114) {
		gShear = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = 0.5;
	}
	else{ 
		gShear = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gCandyShear = 0.0;
	}

	// ������ ������
	//if (gTimeslot < 60) gCandyX += 0.1;
	//else gCandyX -= 0.1;

	glutPostRedisplay();
	glutTimerFunc(100, MyTimerNight, 1);

} // MyTimerRain
void MyTimerFlower(int Value) {
	if (gBackground != 'N') return;
	
	if (gTimeslot < 60) gCandyX += 0.01;
	else gCandyY -= 0.01;

	glutPostRedisplay();
	glutTimerFunc(10, MyTimerFlower, 1);
}
void MyMainMenu(int entryID) {
	if (entryID == 1) {
		glClearColor(1, 1, 1, 1); gBackground = 'D';
	}
	else if (entryID == 2) {
		glClearColor(0, 0, 0, 0); gBackground = 'N'; gTimeslot = 0;  glutTimerFunc(100, MyTimerNight, 1); glutTimerFunc(10, MyTimerFlower, 1);
	}
	else if (entryID == 3) {
		gBackground = 'R'; glClearColor(0, 0, 0, 0); gTimeslot = 0;  glutTimerFunc(400, MyTimerRain, 1);
	}
	else if (entryID == 4) { // 14-(1)
		gBackground = 'S'; glClearColor(0, 0, 0.5, 0); gTimeslot = 0;  //glutTimerFunc(400, MyTimerRain, 1);
	}
	glutPostRedisplay();
} // MyMainMenu
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	//glEnable(GL_DEPTH_TEST); // 11-(6), 13-(4)
	// menu callback 
	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Day", 1);
	glutAddMenuEntry("Night", 2);
	glutAddMenuEntry("Rain", 3);
	glutAddMenuEntry("Stage", 4); // 14-(1)
	glutAttachMenu(GLUT_RIGHT_BUTTON);
} // MyInit
int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // 11-(5)
	glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
	glutInitWindowPosition(150, 0);
	glutCreateWindow("[Maximus] asu, lkfd, pore, PORE, 09");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutKeyboardFunc(MyKeyboard);
	glutSpecialFunc(MySpecial);
	glutMotionFunc(MyMotion); // 9-(5)
	glutMainLoop();
	return 0;
}
