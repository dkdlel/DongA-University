#include <glut.h>
#include <math.h>
#define Pi 3.1415
void MyDisplay() {
	GLfloat Size[2], Angle;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
	glPointSize(Size[0] * 10);
	glBegin(GL_LINES);
	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 20.0)
		glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
	glEnd();
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics Primitives");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}// 점들을 보다 촘촘하게//#include <glut.h>
//#include <math.h>
//#define Pi 3.1415
//void MyDisplay() {
//	GLfloat Size[2], Angle;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 0.0);
//	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
//	glPointSize(Size[0] * 10);
//	glBegin(GL_LINES);
//	for (Angle = 0.0; Angle <= 2.0 * Pi; Angle += Pi / 40.0)
//		glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Graphics Primitives");
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}// 반원//#include <glut.h>
//#include <math.h>
//#define Pi 3.1415
//void MyDisplay() {
//	GLfloat Size[2], Angle;
//	glClear(GL_COLOR_BUFFER_BIT);
//	glColor3f(0.0, 0.0, 0.0);
//	glGetFloatv(GL_POINT_SIZE_RANGE, Size);
//	glPointSize(Size[0] * 10);
//	glBegin(GL_POINTS);
//	for (Angle = 0.0; Angle <= Pi; Angle += Pi / 20.0) // 위로 반원
//  for (Angle = Pi ; Angle <= 2.0 * Pi ; Angle += Pi / 20.0)// 아래로 반원
//		glVertex3f(0.5 * cos(Angle), 0.5 * sin(Angle), 0.0);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Graphics Primitives");
//	glClearColor(1.0, 1.0, 1.0, 1.0);
//	glutDisplayFunc(MyDisplay);
//	glutMainLoop();
//	return 0;
//}