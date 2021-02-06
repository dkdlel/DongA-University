#include <glut.h>
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	glVertex3f(-0.5, -0.5, 0.0); glVertex3f(0.5, -0.5, 0.0);
	glVertex3f(0.5, 0.5, 0.0); glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}
void MyReshape(int NewWidth, int NewHeight) { // 실제적으로 Reshape Callback을 수행하는 함수, (900,300)
	glViewport(0, 0, NewWidth, NewHeight); // 나중 배움 -> graphics 창 다쓰겠다 / 안쓰겠다
	GLfloat WidthFactor = (GLfloat)NewWidth / (GLfloat)300; // 3
	GLfloat HeightFactor = (GLfloat)NewHeight / (GLfloat)300; // 1
	glMatrixMode(GL_PROJECTION); // 나중 배움 -> 좌표가 변할때 사용
	glLoadIdentity(); // 나중 배움 -> 좌표가 변할때 사용
	//glOrtho(-1.0 * WidthFactor, 1.0 * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	// 창크기를 늘리면 사각형은 형태를 그대로 유지
	glOrtho(-1.0 * WidthFactor * WidthFactor, 1.0 * WidthFactor * WidthFactor, -1.0 * HeightFactor, 1.0 * HeightFactor, -1.0, 1.0);
	// 창크기가 늘었을때 상대적으로 사각형이 작아 보이게 하기
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Reshape Callback");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape); // Reshape Callback을 선언한 함수
	glutMainLoop();
	return 0;
}