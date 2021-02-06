#include <stdlib.h>
#include <glut.h>
static int shoulderR = -20, elbowR = -50; // ������
static int shoulderW = 20, elbowW = 50; // �ٸ���
GLfloat cubesize = 1;

void init(void) {
	glClearColor(0, 0, 0, 1);
	glShadeModel(GL_FLAT);
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	// ��������(������)
	glPushMatrix();
		glTranslatef(0.5, 1, 0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)shoulderR, 0, 0, 1); // ���� ���� ȸ��
		glTranslatef(1, 0, 0); // Pivot�� �������� �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
				glColor3f(1, 0, 0);
				glScalef(2, 0.5, 1); // cube�� ���簢������ ����� ���ؼ�
				glutWireCube(cubesize); // �� ���
			glPopMatrix();
		glTranslatef(1, 0, 0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)elbowR, 0, 0, 1); // ���� ���� ȸ��
		glTranslatef(1, 0, 0); // Pivot�� �������� �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
				glColor3f(1, 0, 0);
				glScalef(2, 0.4, 1);
				glutWireCube(cubesize); // �� �Ϻ�
			glPopMatrix();
	glPopMatrix();

	// ������(���)
	glPushMatrix();
		glTranslatef(-0.5, 1, 0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)shoulderW, 0, 0, 1); // ���� ���� ȸ��
		glTranslatef(-1, 0, 0); // Pivot�� �������� �̵�
			glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
				glColor3f(1, 1, 1);
				glScalef(2, 0.5, 1); // cube�� ���簢������ ����� ���ؼ�
				glutWireCube(cubesize); // �� ���
			glPopMatrix();
		glTranslatef(-1, 0, 0); // Pivot ���� �� ��ü �̵�
		glRotatef((GLfloat)elbowW, 0, 0, 1); // ���� ���� ȸ��
		glTranslatef(-1, 0, 0); // Pivot�� �������� �̵�
		glPushMatrix(); // ������ �������� ��ü ���� �� ���/Ȯ��
				glColor3f(1, 1, 1);
				glScalef(2, 0.4, 1);
				glutWireCube(cubesize); // �� �Ϻ�
			glPopMatrix();
	glPopMatrix();

	// ����
	glPushMatrix();
		glTranslatef(0, 0.28, 0);
		glScalef(1.2, 2, 1);
		glutWireCube(cubesize);
	glPopMatrix();

	// ��
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
	gluPerspective(65, (GLfloat)w / (GLfloat)h, 1, 20); // ���뼳��, ��������(glOrtho�� ��������)
	// gluPerspective(x, y,near, far)
	glMatrixMode(GL_MODELVIEW); // display �պκп� ������ ���������� ū ���� ����
	glLoadIdentity();
	glTranslatef(0, 0, -5); // ���� ������ -1 ~ -20�̱� ������ ���� ���ʿ� ����� �𵨵��� ���� ������ �о���
}
void keyboard(unsigned char key, int x, int y) {
	switch (key) {
	case 'P':
		shoulderR = (shoulderR + 5) % 360; break; // 0 ~ 359 ���̸� �����ϱ� ���ؼ� %360 ��
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