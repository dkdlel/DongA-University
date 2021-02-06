#include <stdlib.h>
#include <glut.h>
static int shoulderR = -20, elbowR = -50; // 빨간팔
static int shoulderW = 20, elbowW = 50; // 다른팔
GLfloat cubesize = 1;

void init(void) {
	glClearColor(0, 0, 0, 1);
	glShadeModel(GL_FLAT);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// 오른쪽팔(빨간색)
	glPushMatrix();
		glTranslatef(0.5, 1, 0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)shoulderR, 0, 0, 1); // 원점 기준 회전
		glTranslatef(1, 0, 0); // Pivot을 원점으로 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glColor3f(1, 0, 0);
				glScalef(2, 0.5, 1); // cube를 직사각형으로 만들기 위해서
				glutWireCube(cubesize); // 팔 상부
			glPopMatrix();
		glTranslatef(1, 0, 0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)elbowR, 0, 0, 1); // 원점 기준 회전
		glTranslatef(1, 0, 0); // Pivot을 원점으로 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glColor3f(1, 0, 0);
				glScalef(2, 0.4, 1);
				glutWireCube(cubesize); // 팔 하부
			glPopMatrix();
	glPopMatrix();

	// 왼쪽팔(흰색)
	glPushMatrix();
		glTranslatef(-0.5, 1, 0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)shoulderW, 0, 0, 1); // 원점 기준 회전
		glTranslatef(-1, 0, 0); // Pivot을 원점으로 이동
			glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glColor3f(1, 1, 1);
				glScalef(2, 0.5, 1); // cube를 직사각형으로 만들기 위해서
				glutWireCube(cubesize); // 팔 상부
			glPopMatrix();
		glTranslatef(-1, 0, 0); // Pivot 지정 및 객체 이동
		glRotatef((GLfloat)elbowW, 0, 0, 1); // 원점 기준 회전
		glTranslatef(-1, 0, 0); // Pivot을 원점으로 이동
		glPushMatrix(); // 원점을 기준으로 객체 생성 및 축소/확대
				glColor3f(1, 1, 1);
				glScalef(2, 0.4, 1);
				glutWireCube(cubesize); // 팔 하부
			glPopMatrix();
	glPopMatrix();

	// 몸통
	glPushMatrix();
		glTranslatef(0, 0.28, 0);
		glScalef(1.2, 2, 1);
		glutWireCube(cubesize);
	glPopMatrix();

	// 얼굴
	glPushMatrix();
		glTranslatef(0, 1.8, 0);
		glutWireSphere(0.6, 30, 30);
	glPopMatrix();

	glutSwapBuffers();
}
void reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(65, (GLfloat)w / (GLfloat)h, 1, 20); // 무대설정, 원근투영(glOrtho는 정사투영)
	// gluPerspective(x, y,near, far)
	glMatrixMode(GL_MODELVIEW); // display 앞부분에 있으나 여기있으나 큰 차이 없음
	glLoadIdentity();
	glTranslatef(0, 0, -5); // 무대 설정이 -1 ~ -20이기 때문에 무대 앞쪽에 생기는 모델들을 무대 안으로 밀었음
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'P':
		shoulderR = (shoulderR + 5) % 360; break; // 0 ~ 359 사이를 유지하기 위해서 %360 함
	case 'O':
		shoulderR = (shoulderR - 5) % 360; break;
	case 'p':
		elbowR = (elbowR + 5) % 360; break;
	case 'o':
		elbowR = (elbowR - 5) % 360; break;

	case 'R':
		shoulderW = (shoulderW + 5) % 360; break;
	case 'E':
		shoulderW = (shoulderW - 5) % 360; break;
	case 'r':
		elbowW = (elbowW + 5) % 360; break;
	case 'e':
		elbowW = (elbowW - 5) % 360; break;

	case 27: // esc
		exit(0); break;
	default:
		break;
	}
	glutPostRedisplay();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("[Maxibot] pore PORE");
	init();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}