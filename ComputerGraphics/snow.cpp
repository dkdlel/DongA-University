#include <glut.h>
#include <stdio.h>
#define size 600
#define fsize 600.0

/*
미완성본입니다.
수정하 부분은 다음과 같습니다.
(1) 모델색 지정하는 함수가 안보이는 이유는? / glColor3f의 default 값은 흰색이라서(모델일경우) 배경은 검은색이 default

(2) 클릭할 때 MyDisplay함수가 두 번씩 call 되는 이유를 말하고, / MyMouseClick 자체가 callback형태로 두번 호출 되었기 때문에 => 마우스를 누를때 한번, 땔 때 한번
	한번씩만 call되도록 수정하세요. / if문 안에서 glutPostRedisplay() 실행

(3) glOrtho함수를 주석처리 하였을 때, 똑같은 실행이 되려면 어디를 고쳐야 할까요? / default : -1 ~ 1 
	=> 무대범위가 두배로 늘었으므로 , 2를 곱해주고(범위가 0~2), 그 다음 음의 방향으로 1씩 이동 (범위가 -1 ~ 1)

(4) glClear 빼버리면? / 배우도 없으면 검정색, 배우 있으면 처음 한번은 glClear 있는듯이 보임. 그다음 부터는 clear를 안하기 때문에 누적(바탕화면색 변경 불가)

(5) 누적인데 더블버퍼 사용하면? / 홀,짝 클릭 횟수마다 해당 번호대로 나옴 => 홀수번째 클릭에는 홀수번들이, 짝수번째 클릭에는 짝수번들이
	=> 홀수번째 배우 누적, 짝수번째 배우 누적 따로 따로 노는중
	누적이면서 더블버퍼인데 다 누적되게 하려면 다양한 방법이 있음
	=> 간단하면서 무식한 방법: display를 두번 call 하면 양쪽 버퍼에 다 누적(but, 클릭으로 발생하지 않은 최초 삼각형은 생겼다 말았다(반짝반짝)

(6) 한 번 클릭할 때, 클릭한 주변에 세 개씩 snow가 생기도록 바꿔보세요. / begin end 써서 근처에 나오게 생성

(7) 겨울 말고 봄으로 컨셉 전환(화면 타이틀도 어울리게 수정) / 
*/
int gCount = 0; // 마우스 클릭한 개수(snow개수)
float gSnowX, gSnowY;

void MyDisplay() {

	printf("display 시작\n");

	//(4)glClear(GL_COLOR_BUFFER_BIT); // glClear도 없고, 배우도 한명도 안나오면 검정색
								// glClear도 없고, 배우가 등장하면 처음 한번은 있는듯이 실행

	//(4)if (gCount > 0) {
		glBegin(GL_POLYGON);
		glVertex3f(gSnowX, gSnowY, 0);
		glVertex3f(gSnowX - 0.02, gSnowY - 0.04, 0);
		glVertex3f(gSnowX + 0.02, gSnowY - 0.04, 0);
		glEnd();
	//(4)}
	
	//(5)glFlush();
	glutSwapBuffers();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {

	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN) {
		//(3)gSnowX = X / size.0;
		//(3)gSnowY = (size - Y) / 600.0;
		//(3)gSnowX = 2*(X / size.0); // 2배만 곱하면 됨
		//(3)gSnowY = 2*((size - Y) / size.0); // 2배만 곱하면 됨
		gSnowX = 2*(X / fsize) -1; // -1 하면서 좌표 이동
		gSnowY = 2*((size - Y) / fsize) -1; // -1 하면서 좌표 이동
		gCount++;
		printf("count: %d (%d, %d) (%g, %g) \n", gCount, X, Y, gSnowX, gSnowY);

		glutPostRedisplay(); // (2) 한번만 call 되도록
	}

	//(2)glutPostRedisplay();
}
void MyInit() {
	glClearColor(0, 0, 1, 1);
	//(3)glOrtho(0, 1, 0, 1, -1, 1);
	//(3)if : glOrtho(0, 2, 0, 2, -1, 1); => -1 ~ 1까지니까 x/y축 범위가 두배로 늘어남
	/*(3)if : */glOrtho(-1, 1, -1, -1, -1, 1); //=> -1 ~ 1까지니까 x/y축 범위가 두배로 늘어남
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(size, size);
	glutInitWindowPosition(450, 0);
	glutCreateWindow("클릭하면 눈... 봄인데?");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}