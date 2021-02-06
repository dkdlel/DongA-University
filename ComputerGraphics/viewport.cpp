#include <glut.h>
#include <gl.h>
#include <glu.h>

int Width, Height;

void InitLight() {
	GLfloat Light0_Ambient[] = { 0.9, 0.4, 0.3, 1.0 }; 			// 조명 특성	
	GLfloat Light0_Diffuse[] = { 0.8, 0.7, 0.6, 1.0 };
	GLfloat Light0_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat Light0_Position[] = { 1.0, 1.0, 1.0, 1.0 };			// 0번 광원위치

	GLfloat Material_Ambient[] = { 0.4, 0.4, 0.4, 1.0 };			// 물체 특성
	GLfloat Material_Diffuse[] = { 0.9, 0.9, 0.9, 1.0 };
	GLfloat Material_Specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat Material_Shininess[] = { 25.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, Light0_Ambient);			// 조명 특성 할당 
	glLightfv(GL_LIGHT0, GL_DIFFUSE, Light0_Diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, Light0_Specular);
	glLightfv(GL_LIGHT0, GL_POSITION, Light0_Position);

	glMaterialfv(GL_FRONT, GL_AMBIENT, Material_Ambient);		// 물체 특성 할당
	glMaterialfv(GL_FRONT, GL_DIFFUSE, Material_Diffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, Material_Specular);
	glMaterialfv(GL_FRONT, GL_SHININESS, Material_Shininess);

	glShadeModel(GL_SMOOTH);									// 구로 셰이딩		
	glEnable(GL_DEPTH_TEST);									// 깊이 버퍼 활성화
	glEnable(GL_LIGHTING);										// 조명 활성화
	glEnable(GL_LIGHT0);										// 0번 조명 활성화	
}

void DrawGround() {
	glColor3f(0.9, 0.9, 0.9);	// Bottom of Grid

	glBegin(GL_POLYGON);
	glVertex3f(-2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, 2.0);
	glVertex3f(2.0, -0.71, -2.0);
	glVertex3f(-2.0, -0.71, -2.0);
	glEnd();

	glColor3ub(50, 50, 50);		// Grid
	glBegin(GL_LINES);
	for (float x = -2.0; x <= 2.2; x += 0.2) {
		glVertex3f(x, -0.7, -2.0);
		glVertex3f(x, -0.7, 2.0);
	}

	for (float z = -2.0; z <= 2.2; z += 0.2) {
		glVertex3f(-2.0, -0.7, z);
		glVertex3f(2.0, -0.7, z);
	}
	glEnd();
}

void DrawScene() {
	glDisable(GL_LIGHTING);
	DrawGround();
	glEnable(GL_LIGHTING);

	glColor3f(0.3, 0.3, 0.7);
	glutSolidTeapot(1.0);
}

void MyDisplay() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);

	glViewport(0, Height / 2, Width / 2, Height / 2); // 좌상    		
	glPushMatrix();
	gluLookAt(0.0, 0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	glViewport(Width / 2, 0, Width / 2, Height / 2);	// 우하			
	glPushMatrix();
	gluLookAt(5.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();

	glViewport(0, 0, Width / 2, Height / 2);   // 좌하	
	glPushMatrix();
	gluLookAt(0.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, -1.0);
	DrawScene();
	glPopMatrix();

	glViewport(Width / 2, Height / 2, Width / 2, Height / 2); 	// 우상		
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	gluPerspective(30, 1.0, 3.0, 50.0);
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	DrawScene();
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glFlush();
}

void MyReshape(int w, int h) {
	Width = w;   Height = h;

	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.5, 5.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	Width = 500; Height = 500;
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(Width, Height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Viewport Partition");
	InitLight();
	glutDisplayFunc(MyDisplay);
	glutReshapeFunc(MyReshape);
	glutMainLoop();
	return 0;
}
