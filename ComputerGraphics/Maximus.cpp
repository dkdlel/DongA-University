/*-----------------------------------------------------------
  6th week (2020. 4. 20)

Keyboard
u a s : face
l k : blueleg
f d : blackleg
p o : right lower arm (90 ~ -90 restict)
r e : left lower arm
0 9 : 팔길이

Special
UP and DOWN : jump
LEFT and RIGHT : moving-X
F1~F3, F4~F6 : shear
F11, F12 : moving-Z

Motion
Menu

6주차
(1) 회전시키려면 어떤 기하변환 함수가 필요할까요? -> glRotatef(각도, x축, y축, z축);
(2) 방금 보신 영상에서 막시무스의 다리는 어느 축을 기준으로 회전하고 있나요? -> z축 기준
(3) blue leg만 회전시키고 다른 부분에 영향을 안주려면 어떤 함수를 호출해야 하나요? -> glPushMatrix(); glPopMatrix();
(4) 회전시키니까 다리가 몸체에서 분리됩니다. 그 원인은 뭘까요? -> 원점을 기준으로 회전하기 때문에, 다리가 원점이 아닌 다른 지점에서 돌고 싶어도 원점기준으로 회전
(5) 정확히 고관절을 중심으로 회전하려면 어떻게 하면 될까요?
	 -> 1.다리를 원점으로 이동 -> 2.회전 -> 3.원상복귀 (움직임의 순서)
	 코딩순서
	 push
	 3. 다리 시작지점 위치와 동일
	 2. 회전
	 1. 다리 시작지점 위치와 반대
	 다리(Begin ~ End)
	 pop

week 7
(1) 현재 팔꿈치 아래(forearm)만 움직입니다. 팔 전체 회전 기능을 추가하세요 (P O R E)
	변수명의 혼동이 예상되므로 gRedforearm -> gRedforearm, gBlackforearm -> gBlackforearm 으로
	팔 전체의 변수명은 gRedupperarm, gBlackupperarm으로
(2) 빨간팔에 늘어나는 기능을 추가
	'0'(zero) 누르면 점점 길어지고, '9' 누르면 점점 원상복귀하는 코드를 추가
(3) 만약 scale 함수가 translate 하지않고 바로 모델에 적용하면 결과는? -> 원점이 고정이 아니기 때문에 팔이 늘어나는게 아니고 점점 커짐
(4) 만약 scale 함수가 전체팔 감싸는 push/pop 보다 위에 있으면 결과는? -> 전체가 그냥 막 커짐
(5) 두 발의 끝위치를 고정하고 shear를 적용해보세요.
	전역변수 1개, 배열선언, 행렬곱 함수(위아래로 tanslate), special함수에서 F1,F2,F3 추가
(6) 2차원 배열을 MyDisplay 함수안에 지역변수로 선언했는데, 전역변수로 바꾸면 어떤 결과? 그이유는?
	-> 배열 선언 시 안에 변수가 들어있으면 그건 선언 당시 변수의 값이 들어있는거랑 동일, 전역변수로 선언하면 그냥 0이 들어있는거랑 동일, 지역변수면 함수 호출시마다 배열이 선언되므로
	special함수에서 바뀐 값이 초기값으로 들어가게 됨
(7) 다리에만 전단

week 9
(1) 6개의 전역변수 추가
	1.사탕의 위치(x,y) 2.화면크기가 변했을때의 새로운 x,y(gNewWidth, gNewHeight) 3.화면비율(gWidthFactor, gHeightFactor)
(2) MyCandy함수를 전체적으로 glTranslatef(gCandyX, gCandyY,0); 한줄 추가
(3) MyMotion함수 구현
(4) MyReshape함수에서 지역변수 4개를 전역변수에 넣어줌
(5) main에서 glutMotionFunc 호출

week 10
(1) menu 추가 - day, night (바탕색, 하늘, 초원, 매트 색 변경, 얼굴 톤 다운시킴)
(2) timer 추가 - rain 표현 (재귀함수의 특성을 이용해서 비내리는 밤 표현)

week 11

 4 ~ 9번까지 사용해본 Z-버퍼는 당분간 사용하지 않음
 (1) 매트를 바닥에 polygon으로 펼쳤는데, glOrtho로 하면 안보이는 이유?
 -> 폴리곤은 두께가 없으므로, 정사투영에서 정면에서 바라보면 면이 아예 안보임. 원근으로 하면 잘 보임 ^^
 (2) 꽃(사탕)을 motion으로 움직이면 전단할 때 발끝고정이 안되는 이유?
 -> 전단 중심 y값을 절대적인 위치로 넣었기 때문에 움직인 후에는 발끝고정이 안됨.
	꽃(사탕)의 상대적인 위치로 전단 위 아래 이동함수를 바꿔주면 됨.
 (3) glOrtho일때 잘 되던 motion이 원근 넣으니까 마우스 위치랑 조금 다르게 보이는 이유?
 -> 앞 영상에서는 눈/잎을 앞으로 z값 양의방향으로 이동했더니, 약간 위에 있는 것처럼 보임. 같은 이치임.
	마우스 커서 위치, 꽃위치 z값이 다르기 떄문에 미세하게 달라보임(틀린거 아님)

(4) Mydisplay glClear에 GL_DEPTH_BUFFER_BIT 추가
(5) Main InitDisplayMode에 GLUT_DEPTH추가
(6) MyInit에 glEnalbe(GL_DEPTH_TEST); 추가 -> 당분간 막시무스에는 적용하지 않을꺼기 때문에 주석 처리
(7) MYBackgroud에서 무대 범위들 -3.9로 변경 -> 가장자리 안맞아서
(8) 눈코입이 나오지 않는 이유 : solidspear가 z축을 가지고 있어서 얼굴 밑에 깔려있음
	-> EyeMouth에서 z축을 변경하기 위해 translate
(9) 매트를 3D형태로 바닥에 펼쳐진 매트로 전환

week 13
1. 조명 넣으려면, 서비스 차원의 달빛 넣어주고
2. 얼굴 위에서 조명 on, 얼굴 아래에서 조명 off
3. 조명받는 하에서 얼굴색은 glMaterialfv로 설정해주고
4. 만약 조명을 안꺼주면? -> 한번 materialfv함수가 작동되면, 계속 효과있음.
5. 현재 z-buffer는 켜지지 않는 상황. 조명 z값(앞뒤위치)이 예상치 못한 방향으로 나옴.
	빨간행성파랑행성은 z-buffer가 켜져있기 때문에, 광원이 앞뒤 이동할 때 조명을 잘 받음.
	==> 조명 on/off할 때 z-buffer도 on/off해주면, 앞뒤 이동시에도 조명이 잘 작동!!
6. 타이머를 이용한 혼자 움직이는 막시무스!! -> 아이들(함수), 타이머

(1) 전역변수 2개 선언(얼굴색, 광원의 위치)
(2) 달 그리기(background에)
(3) 조명키기(face에)
(4) z-buffer키기(init에서 켜도 되지만 face에서 조명과 함께 껏다 키고)
	-> 얼굴에만 조명을 넣기 때문에 눈코입에 조명이 상관없음
(5) mainmenu에 타이머 한개 추가, mytimerNight 함수 생성 

week 14
 (질문) Night에서 사탕이 더 부드럽게 움직이려면?
  -> 타이머에서 사탕은 시간 100마다 0.1씩 좌우로 이동 ==> 시간 10마다 0.001씩 움직인다면?

  막시무스가 스포트라이트를 받도록
  (1) Mainmenu, MyInit, MyBackground, MyDisplay에 1개 추가, 전역변수 4개추가
   ==> 다음주에 계속
-------------------------------------------------------------*/

#include <glut.h>
#define WIN_WIDTH 1000  // window 4:3
#define WIN_HEIGHT 750

unsigned char gFace = 'u';   // u:usual  a:angry   s:smiling
GLfloat gY = 0.0;  // jump
GLfloat gX = 0.0;  // moving-X
GLfloat gZ = 0.0; // 앞뒤이동
GLfloat gBlueleg = 0.0, gBlackleg = 0.0; // 회전각도
GLfloat gRedforearm = 0.0, gBlackforearm = 0.0, gRedupperarm = 0.0, gBlackupperarm = 0.0; // 회전각도
GLfloat gRedarmlength = 1; // 빨간팔의 길이
GLfloat gShear = 0.0, gShearleg = 0.0; // 7-(5), 7-(7)
GLfloat gCandyShear = 0.0, gStickShear = 0.0; // 사탕의 전단을 위한 변수
// 9-(1)
GLfloat gCandyX = -2.8, gCandyY = -1.5;
GLfloat gWidthFactor, gHeightFactor;
GLint gNewWidth, gNewHeight;
unsigned char gBackground = 'D'; // 낮
GLint gTimeslot = 0; // timer
// 13-(1)
const GLfloat gLight_pos[] = { 0, 0, 0, 1 }; // 광원의 위치
const GLfloat gFace_color[] = { 251 / 255.0, 206 / 255.0, 177 / 255.0, 1 }; // 얼굴색(살구색)
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
	// 사탕의 윗부분
	glColor3f(255 / 255.0, 153 / 255.0, 255 / 255.0);
	// 9 -(2)
	glTranslatef(gCandyX, gCandyY, 0);

	glPushMatrix();
	glutSolidSphere(0.2, 50, 50);
	glPopMatrix();

	// 사탕의 아랫부분

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
	// 아래 세개는 항상 고정
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // 11-(4)
	glMatrixMode(GL_MODELVIEW); // display는 Modelview
	glLoadIdentity();

	glTranslatef(0, 0, -5); // 무대 좌표에 따라서 전체를 통으로 움직임
	//glScalef(1, -1, 1); // 2d에서 x축에 대한 반사
	//glScalef(-1, 1, 1); // 2d에서 y축에 대한 반사

	//배경 14-(1)
	if(gBackground != 'S'){
		MyBackground();
		MyMat();
	}

	//// y=x 에 대한 반사
	//glRotatef(-45, 0, 0, 1);
	//glScalef(-1, 1, 1);
	//glRotatef(45, 0, 0, 1);

	// 여기서부터는 Maximus
	//glTranslatef(2, 0, 0); // y=x에 대한 반사
	glPushMatrix();
	glTranslatef(gX, gY, gZ); // left, right, jump, 앞뒤
	GLfloat Shear_arr[4][4] = {
		{1,0,0,0},
		{gShear,1,0,0},
		{0,0,1,0},
		{0,0,0,1},
	};
	glTranslatef(0, -1, 0); // 막시무스의 발끝
	glMultMatrixf((float*)Shear_arr);
	glTranslatef(0, 1, 0);
	glPushMatrix();
	MyFace();
	glPopMatrix();

	MyEyeMouth();
	MyBody();
	MyUnbrlla();
	glPopMatrix();

	// 전단만 따라하는 작은 무언가
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
	else glColor3f(0.2, 0.2, 0.2); // 블랙그레이

	glBegin(GL_POLYGON);
	glVertex3f(-10, 0, -3.9);
	glVertex3f(10, 0, -3.9);
	glVertex3f(10, 8, -3.9);
	glVertex3f(-10, 8, -3.9);
	glEnd();

	if (gBackground == 'D') glColor3f(0, 1, 0); // green 
	else glColor3f(0, 0.3, 0); // 블랙그린

	glBegin(GL_POLYGON);
	glVertex3f(-10, -8, -3.9); // 11-(7)
	glVertex3f(10, -8, -3.9);
	glVertex3f(10, 0, -3.9);
	glVertex3f(-10, 0, -3.9);
	glEnd();

	if (gBackground == 'R') { // Rain
		glColor3f(0.9, 0.9, 0.9); // 비색
		if (gTimeslot % 3 == 0) {
			glBegin(GL_LINES);
			glVertex3f(-3, 2, 0);		glVertex3f(-3, 1.8, 0); // 좌측
			glVertex3f(3.3, 2.8, 0);	glVertex3f(3.3, 2.6, 0); // 우측
			glEnd();
		}
		else if (gTimeslot % 3 == 1) {
			glBegin(GL_LINES);
			glVertex3f(0, 2.7, 0);		glVertex3f(0, 2.5, 0); // 중간
			glEnd();
		}
		else {
			glBegin(GL_LINES);
			glVertex3f(-1, 1.7, 0);		glVertex3f(-1, 1.5, 0); // 좌측
			glVertex3f(2.9, 1.8, 0);	glVertex3f(2.9, 1.6, 0); // 우측
			glEnd();
		}

		// 우산 추가 --> 우산먼저 그리고 나중에 막시무스를 그렸기 때문에, 얼굴이 밖으로 나오기 때문에 추가하면 안됨
	}
	// 13-(2)
	if (gBackground == 'N') { // 밤이면
		glTranslatef(0, 3, 0); // 달위치 이동
		glLightfv(GL_LIGHT0, GL_POSITION, gLight_pos); // 원점에 있던 광원의 이동
		glColor3f(0.9, 0.9, 0.9); // 회색
		glutSolidSphere(0.05, 30, 30); // 달그림
		glTranslatef(0, -3, 0); // 다른거 영향 안받게 할라고
	}
}
void MyMat()
{

	if (gBackground == 'D') glColor3f(0xE4 / 255.0, 0xBE / 255.0, 0xFE / 255.0); // 연보라색	
	else glColor3f(0.3, 0, 0.3); // 블랙퍼플

	//glBegin(GL_POLYGON);
	//glVertex3f(-1.5, -1.3, 0); // 바닥에 펼쳐있어야 하는데, 아직 2D라서 공중에 떠있는 평행사변형
	//glVertex3f(1.2, -1.3, 0); // 3D로가면, 진짜 바닥에 펼쳐진 매트로 전환할 예정
	//glVertex3f(1.5, -0.8, 0);
	//glVertex3f(-1.2, -0.8, 0);
	//glEnd();

	glBegin(GL_POLYGON); // 11-(9), 두께가 없고 면만 있이서 정면에서 보면 안보임
	glVertex3f(-1.5, -1, 1.5); // 바닥에 펼쳐진 정사각형
	glVertex3f(1.5, -1, 1.5);
	glVertex3f(1.5, -1, -1.5);
	glVertex3f(-1.5, -1, -1.5);
	glEnd();

} // MyMat
void MyFace() {

	if (gBackground == 'D') glColor3f(251 / 255.0, 206 / 255.0, 177 / 255.0); // 살구색
	else glColor3f(0.6, 0.4, 0.4);

	if (gBackground == 'N') {
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, gFace_color);// 조명하의 얼굴색 넣는 함수
		glEnable(GL_DEPTH_TEST); // 13-(4)
	}
	// 실제 얼굴
	glPushMatrix(); // 행렬 스택(3장에서 자세히 배움)
	glTranslatef(0, 1, 0); // 구를 이동시키기 위해서
	glutSolidSphere(0.5, 50, 50); // glut는 원점을 기준으로 그려짐
	glPopMatrix(); // push를 했으면 pop

	// 조명 꺼주기
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

	//glTranslatef(0, 0, -0.5); // 앞으로 이동했다면 다른것에 영향을 주지 않기 위해 뒤로 이동

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


	glPushMatrix(); // red 큰 팔 시작
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
	glPopMatrix(); // 큰 팔 pop

	glPushMatrix(); // black 큰 팔 시작
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
	glPopMatrix(); // 큰 팔 pop

	// 다리만 전단
	glPushMatrix(); // 다리 두개 묶음
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
	glTranslatef(0.05, -0.3, 0.0); // (3) 다리를 원상복귀
	glRotatef(gBlueleg, 0, 0, 1); // (2) z축 기준으로 회전
	glTranslatef(-0.05, 0.3, 0.0); // (1) 다리가 원점에서 시작하도록 이동
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
	glPopMatrix(); // 두다리 전단한거 pop
	glLineWidth(1);  // line

} // MyBody
void MyKeyboard(unsigned char key, int x, int y) {

	switch (key) {

	case 'Q':
	case 'q':	exit(0);  break;

	case 'a':
	case 's':
	case 'u':   gFace = key;   break;	 // face

	case 'l':	gBlueleg += 10; break; // 다리회전
	case 'k':	gBlueleg -= 10; break;

	case 'f':	gBlackleg += 10; break; // 다리회전
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
		gRedforearm = 30; // 반시계
		gBlackforearm = -30; // 시계
		gBlueleg = -19.5; // 반시계
		gBlackleg = 19.5; // 시계
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
	case GLUT_KEY_F1: gShear = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = -0.5; break; // 전신 왼쪽
	case GLUT_KEY_F2: gShear = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gCandyShear = 0.0; break;
	case GLUT_KEY_F3: gShear = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = 0.5; break;

	case GLUT_KEY_F4: gShearleg = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = 0.5; break; // 다리 왼쪽 (전신과 부호가 다른 이유 : 상반신이 왼쪽으면 다리는 오른쪽)
	case GLUT_KEY_F5: gShearleg = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gStickShear = 0.0; break;
	case GLUT_KEY_F6: gShearleg = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = -0.5; break;


	case GLUT_KEY_F11:  if (gZ <= 3) gZ += 0.1; break;
	case GLUT_KEY_F12: if (gZ >= -3)gZ -= 0.1; break;
	}

	glutPostRedisplay();

} // MySpecial
void MyReshape(int NewWidth, int NewHeight) {

	glViewport(0, 0, NewWidth, NewHeight); // 좌측하단을 기준으로 창의 전체 크기 까지
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)WIN_WIDTH;
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)WIN_HEIGHT;
	// 사탕 움직이기 위한 변수 설정 9-(4)
	gWidthFactor = WidthFactor; gHeightFactor = HeightFactor;
	gNewWidth = NewWidth; gNewHeight = NewHeight;
	glMatrixMode(GL_PROJECTION); // reshape에는 projection
	glLoadIdentity();
	//glOrtho(-4.0 * WidthFactor, 4.0 * WidthFactor, -3.0 * HeightFactor, 3.0 * HeightFactor, 1, 9); // z축은 x랑 같은걸로 고정
	gluPerspective(65, (GLfloat)NewWidth / (GLfloat)NewHeight, 1, 9); // 원근투영 -1 ~ -9

} // MyReshape
void MyTimerRain(int Value) {
	if (gBackground == 'R') {
		gTimeslot = (gTimeslot + 1) % 100; // 0~99 반복
		//printf("gTimeslot : %d\n", gTimeslot);
		glutPostRedisplay();
		glutTimerFunc(400, MyTimerRain, 1);
	}
} // MyTimerRain
void MyTimerNight(int Value) {
	// 13-(5)
	if (gBackground != 'N') return; // 밤이 아닌경우 return

	gTimeslot = (gTimeslot + 1) % 120; // 0~119 반복
	// 막시무스의 움직임
	if (gTimeslot < 5) { // 점프
		gY = 1;
		gFace = 's';
		gRedforearm = 30; // 반시계
		gBlackforearm = -30; // 시계
		gBlueleg = -19.5; // 반시계
		gBlackleg = 19.5; // 시계
	}
	else if (gTimeslot < 10) { // 내려옴
		gY = 0;
		gFace = 'u';
		gRedforearm = gBlackforearm = gBlueleg = gBlackleg = 0;
	}
	else if ((gTimeslot < 30) || (gTimeslot >= 70 && gTimeslot < 90)) { // 20만큼 왼쪽, 40만큼 오른쪽, 20만큼 왼쪽 이동
		if (gY == 0) {
			gX -= 0.1;
			if (gX < -1.5 || gX > 1.5) gFace = 'a';
			else gFace = 'u';
		}
	}
	else if (gTimeslot < 70) { // 오른쪽으로 이동
		if (gY == 0) {
			gX += 0.1;
			if (gX < -1.5 || gX > 1.5) gFace = 'a';
			else gFace = 'u';
		}
	}
	else if (gTimeslot == 90 || gTimeslot == 91 || gTimeslot == 94 || gTimeslot == 95){ // 왼쪽 전단
		gShearleg = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = 0.5;// 다리 왼쪽 (전신과 부호가 다른 이유 : 상반신이 왼쪽으면 다리는 오른쪽)
	}
	else if (gTimeslot == 92 || gTimeslot == 93 || gTimeslot == 96 || gTimeslot == 97) { // 오른쪽 전단
		gShearleg = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gStickShear = -0.5;
	}
	else if(gTimeslot < 100) {
		gShearleg = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gStickShear = 0.0;
	}
	else if(gTimeslot < 107){ // 전신 왼쪽
	 gShear = -0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = -0.5;
	} 
	else if (gTimeslot < 114) {
		gShear = 0.5; gFace = 's'; gRedupperarm = 48; gBlackupperarm = -48; gCandyShear = 0.5;
	}
	else{ 
		gShear = 0.0; gFace = 'u'; gRedupperarm = 0; gBlackupperarm = 0; gCandyShear = 0.0;
	}

	// 사탕의 움직임
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
