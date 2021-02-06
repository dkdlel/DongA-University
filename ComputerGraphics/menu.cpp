#include <glut.h>

//GLboolean IsSphere = true;
char gWhat = 's';

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.5);

	switch (gWhat)
	{
	case 's':
		glutWireSphere(0.5, 30, 30);
		break;
	case 't':
		glutWireTorus(0.1, 0.3, 40, 20);
		break;
	case 'p':
		glutWireTeapot(0.5);
		break;
	}
	glFlush();
}
void MyMainMenu(int entryID) {
	if (entryID == 1)
		gWhat = 's';
	else if (entryID == 2)
		gWhat = 't';
	else if (entryID == 3)
		gWhat = 'p';
	else
		exit(0);
	glutPostRedisplay();
}void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	// 메뉴 선언 부
	glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);
	glutAddMenuEntry("Draw Teapot", 3);
	glutAddMenuEntry("Exit", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON); // 언제 메뉴를 나타낼래? (오른쪽 버튼을 누를때)
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	// keyboard나 callback같이 부르는 함수 호출이 MyInit에 있음
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}