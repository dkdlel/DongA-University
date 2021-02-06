#include <stdlib.h>
#include <glut.h>
#include <glu.h>

GLUquadricObj* qobj = gluNewQuadric(); //새로운 Quadrics를 생성하고 전역 변수 qobj를 선언
// 3D로 쉽게 갈수 있음

void MyInit(void) {
	GLfloat mat_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };
	GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };
	GLfloat model_ambient[] = { 0.5, 0.4, 0.3, 1.0 };
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
}
void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glEnable(GL_LIGHTING);
	glShadeModel(GL_SMOOTH);
	gluQuadricDrawStyle(qobj, GLU_FILL); // Quadrics에 원하는 Draw Style을 지정
	gluQuadricNormals(qobj, GLU_FLAT); // 법선벡터를 제어(빛에 대한 영향을 결정)
	gluQuadricOrientation(qobj, GLU_OUTSIDE); // 법선벡터의 방향 지정
	gluQuadricTexture(qobj, GL_FALSE); // Texture 좌표 생성 여부
	gluSphere(qobj, 1.5, 6, 6); // Sphere 생성 , begin end와 같은 기능 , new & 크기 & 정밀도
	glutSwapBuffers(); // 버퍼 바꾸기
	// 크기가 커지면 버퍼를 여러개 쓰는데 그 버퍼를 바꿀때 사용(더블 버퍼 사용중)
}
void Reshape(int w, int h) {
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.5, 2.5, -2.5 * (GLfloat)h / (GLfloat)w, 2.5 * (GLfloat)h / (GLfloat)w, -10.0, 10.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // RGB는 기본, DOUBLE : 더블 버퍼를 사용(SwapBuffer과 세트 / default : GLUT_SINGLE => glFlsush를 사용)
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Graphics Primitives");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(Reshape);
	glutMainLoop();
	return 0;
}