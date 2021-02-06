//#include <glut.h>
//void MyDisplay() {
//	glClear(GL_COLOR_BUFFER_BIT); // 바탕색 변경
//	glColor3f(0.0, 0.0, 0.0); // 선의 색
//	glLineWidth(5.0); // 선의 굵기
//	glBegin(GL_LINE_STRIP);
//		glVertex3f(-0.5, -0.5, 0.0);
//		glVertex3f(0.5, -0.5, 0.0);
//		glVertex3f(0.5, 0.5, 0.0);
//		glVertex3f(-0.5, 0.5, 0.0);
//	glEnd();
//	glFlush();
//}
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitWindowSize(500, 500);
//	glutInitWindowPosition(100, 50);
//	glutCreateWindow("네모 그리기");
//	glClearColor(1.0, 1.0, 1.0, 1.0); // 바탕색 요청
//	glutDisplayFunc(MyDisplay); // 없으면 창이 실행 안됨
//	glutMainLoop(); // 화면 유지
//	return 0;
//}

// 주전자 그리기
#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 1.0, 0.0);
	glutSolidTeapot(0.5);
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 50);
	glutCreateWindow("네모 그리기");
	glClearColor(0.5, 0.5, 0.5, 1.0);
	glutDisplayFunc(MyDisplay);
	glutMainLoop();
	return 0;
}