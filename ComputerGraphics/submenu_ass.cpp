#include <glut.h>

GLboolean isSphere = true;
GLboolean isSmall = true;
GLboolean isWire = true;

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.5);
	if (isSphere && isSmall && isWire) // sphere, small, wire
		glutWireSphere(0.5, 30, 30);
	else if (isSphere && isSmall && !isWire) // sphere, small, solid
		glutSolidSphere(0.5, 30, 30);
	else if (isSphere && !isSmall && isWire) // sphere, large, wire
		glutWireSphere(0.7, 30, 30);
	else if (isSphere && !isSmall && !isWire)// sphere, large, solid
		glutSolidSphere(0.7, 30, 30);
	else if (!isSphere && isSmall && isWire) // Torus, small, wire
		glutWireTorus(0.1, 0.3, 40, 20);
	else if (!isSphere && isSmall && !isWire) // Torus, small, solid
		glutSolidTorus(0.1, 0.3, 40, 20);
	else if (!isSphere && !isSmall && isWire) // Torus, large, wire
		glutWireTorus(0.2, 0.5, 40, 20);
	else if (!isSphere && !isSmall && !isWire) // Torus, large, solid
		glutSolidTorus(0.2, 0.5, 40, 20);

	glFlush();
}
void MyMainMenu(int entryID) {
	if (entryID == 1) isSphere = true;
	else if (entryID == 2) isSphere = false;
	else if (entryID == 3) exit(0);
	glutPostRedisplay();
}
void MySizeMenu(int entryID) {
	if (entryID == 1) isSmall = true;
	else if (entryID == 2) isSmall = false;
	glutPostRedisplay();
}
void MyStyleMenu(int entryID) {
	if (entryID == 1) isWire = true;
	else if (entryID == 2) isWire = false;
	glutPostRedisplay();
}
void MyInit() {
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	GLint MySizeID = glutCreateMenu(MySizeMenu);
	glutAddMenuEntry("Small", 1);
	glutAddMenuEntry("Large", 2);

	GLint MyStyleID = glutCreateMenu(MyStyleMenu);
	glutAddMenuEntry("Wire", 1);
	glutAddMenuEntry("Solid", 2);

	GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
	glutAddMenuEntry("Draw Sphere", 1);
	glutAddMenuEntry("Draw Torus", 2);

	glutAddSubMenu("Size", MySizeID);

	glutAddSubMenu("Style", MyStyleID);

	glutAddMenuEntry("Exit", 3);

	glutAttachMenu(GLUT_RIGHT_BUTTON); // 처음 시작할때만 필요
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Menu Callback");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}