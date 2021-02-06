#include <glut.h>
#include <stdio.h>
#define size 600
#define fsize 600.0

/*
�̿ϼ����Դϴ�.
������ �κ��� ������ �����ϴ�.
(1) �𵨻� �����ϴ� �Լ��� �Ⱥ��̴� ������? / glColor3f�� default ���� ����̶�(���ϰ��) ����� �������� default

(2) Ŭ���� �� MyDisplay�Լ��� �� ���� call �Ǵ� ������ ���ϰ�, / MyMouseClick ��ü�� callback���·� �ι� ȣ�� �Ǿ��� ������ => ���콺�� ������ �ѹ�, �� �� �ѹ�
	�ѹ����� call�ǵ��� �����ϼ���. / if�� �ȿ��� glutPostRedisplay() ����

(3) glOrtho�Լ��� �ּ�ó�� �Ͽ��� ��, �Ȱ��� ������ �Ƿ��� ��� ���ľ� �ұ��? / default : -1 ~ 1 
	=> ��������� �ι�� �þ����Ƿ� , 2�� �����ְ�(������ 0~2), �� ���� ���� �������� 1�� �̵� (������ -1 ~ 1)

(4) glClear ��������? / ��쵵 ������ ������, ��� ������ ó�� �ѹ��� glClear �ִµ��� ����. �״��� ���ʹ� clear�� ���ϱ� ������ ����(����ȭ��� ���� �Ұ�)

(5) �����ε� ������� ����ϸ�? / Ȧ,¦ Ŭ�� Ƚ������ �ش� ��ȣ��� ���� => Ȧ����° Ŭ������ Ȧ��������, ¦����° Ŭ������ ¦��������
	=> Ȧ����° ��� ����, ¦����° ��� ���� ���� ���� �����
	�����̸鼭 ��������ε� �� �����ǰ� �Ϸ��� �پ��� ����� ����
	=> �����ϸ鼭 ������ ���: display�� �ι� call �ϸ� ���� ���ۿ� �� ����(but, Ŭ������ �߻����� ���� ���� �ﰢ���� ����� ���Ҵ�(��¦��¦)

(6) �� �� Ŭ���� ��, Ŭ���� �ֺ��� �� ���� snow�� ���⵵�� �ٲ㺸����. / begin end �Ἥ ��ó�� ������ ����

(7) �ܿ� ���� ������ ���� ��ȯ(ȭ�� Ÿ��Ʋ�� ��︮�� ����) / 
*/
int gCount = 0; // ���콺 Ŭ���� ����(snow����)
float gSnowX, gSnowY;

void MyDisplay() {

	printf("display ����\n");

	//(4)glClear(GL_COLOR_BUFFER_BIT); // glClear�� ����, ��쵵 �Ѹ� �ȳ����� ������
								// glClear�� ����, ��찡 �����ϸ� ó�� �ѹ��� �ִµ��� ����

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
		//(3)gSnowX = 2*(X / size.0); // 2�踸 ���ϸ� ��
		//(3)gSnowY = 2*((size - Y) / size.0); // 2�踸 ���ϸ� ��
		gSnowX = 2*(X / fsize) -1; // -1 �ϸ鼭 ��ǥ �̵�
		gSnowY = 2*((size - Y) / fsize) -1; // -1 �ϸ鼭 ��ǥ �̵�
		gCount++;
		printf("count: %d (%d, %d) (%g, %g) \n", gCount, X, Y, gSnowX, gSnowY);

		glutPostRedisplay(); // (2) �ѹ��� call �ǵ���
	}

	//(2)glutPostRedisplay();
}
void MyInit() {
	glClearColor(0, 0, 1, 1);
	//(3)glOrtho(0, 1, 0, 1, -1, 1);
	//(3)if : glOrtho(0, 2, 0, 2, -1, 1); => -1 ~ 1�����ϱ� x/y�� ������ �ι�� �þ
	/*(3)if : */glOrtho(-1, 1, -1, -1, -1, 1); //=> -1 ~ 1�����ϱ� x/y�� ������ �ι�� �þ
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(size, size);
	glutInitWindowPosition(450, 0);
	glutCreateWindow("Ŭ���ϸ� ��... ���ε�?");
	MyInit();
	glutDisplayFunc(MyDisplay);
	glutMouseFunc(MyMouseClick);
	glutMainLoop();
	return 0;
}