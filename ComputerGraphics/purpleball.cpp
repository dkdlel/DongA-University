/*------------------------------------------------
��ġ �ű�� ����� ��

(1) �����ڵ� 1~5�� �ϼ��ϼ���.

(2) ȭ�� ũ�Ⱑ �ٲ� �� ����� ����/Ȧ�������� �ʵ��� glOrtho �����ϼ���~

(3) 2�� reshape�� �� ȭ��ũ�� ������ �÷��� ȸ���׸�� ���߾ӿ� ��ġ�ϴµ�
    ��������� ȭ��ũ�� ������ �÷��� ��ġ���� ���ϴ� ������ �� �� ������ �����ϼ���.

(4) glOrtho ����ũ�⸦ Maximus�� ����ũ��� �����ϰ� ���弼��.( -4 ~ 4, -3 ~ 3, -4 ~ 4)
    ���� ����� ���� ������ ���콺��ǿ� ���� ��ġ�� �� �ٲ�� ��!

(5) ȭ�� ũ�Ⱑ �ٲ� ����� ���� ��ġ�� �� �ٲٰ� �Ϸ��� ��� ���ľ� �ϴ°�?

---------------------------------------------------*/


#include <glut.h>

#define WIN_WIDTH 800  
#define WIN_HEIGHT 600
// ���� �ڵ�(1): �������� ���� gx gy
GLfloat gX = 0.0, gY = 0.0;
GLfloat gWidthFactor, gHeightFactor;
GLint gNewWidth, gNewHeight;
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.9, 0.5, 0.9);
    // ���� �ڵ�(2): �� �� translate(gx,gy,0)
    glTranslatef(gX, gY, 0);
    glutSolidSphere(0.5, 100, 100);

    glutSwapBuffers();

}

//
//���� �ڵ�(3): �ݹ��Լ� �ۼ� MyMotion
//
void MyMotion(GLint X, GLint Y) { // ���콺�� Z���� ǥ�� �� �� ���� ������ Z�� �ʿ����
    // ��������� �þ�� ������ x�� 0-8�� ���� ������, -4��ŭ �̵�, y�� 0-6���� ���� ���� -3��ŭ �̵�
    gX = (GLfloat)X / gNewWidth * 8 * gWidthFactor - 4 * gWidthFactor; // �Ѵ� int���̶� ����ȯ
    gY = (GLfloat)(gNewHeight - Y ) / gNewHeight * 6 * gHeightFactor - 3 * gHeightFactor;

    glutPostRedisplay();
}

void MyReshape(int NewWidth, int NewHeight) {
    glViewport(0, 0, NewWidth, NewHeight);
    GLfloat WidthFactor = (GLfloat)NewWidth / WIN_WIDTH;
    GLfloat HeightFactor = (GLfloat)NewHeight / WIN_HEIGHT;
    gWidthFactor = WidthFactor; gHeightFactor = HeightFactor;
    gNewWidth = NewWidth; gNewHeight = NewHeight;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-4 * WidthFactor, 4 * WidthFactor, -3 * HeightFactor, 3 * HeightFactor, -4, 4);
    //glOrtho(0*WidthFactor, 1 * WidthFactor, 0*HeightFactor, 1*HeightFactor, -1, 1); // * factor
    // 2�� reshpae�� ������ �߾ƿ� ��ġ�ϰ� ������ �þ�� ����� ������ �ʰ� ��ġ�� �߾��̵�
    // ������ 0~2�� �þ�� ������ 0.5�� �ƴϰ� 1�̱� ������ ������ ���� ��ġ
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // ���� �ڵ�(4):  �� ��, glutInitDisplayMode(GLUT_DOUBLE) ���߹��� ����
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("��ġ �ű�� ����� ��");
    glClearColor(0.7, 0.9, 0.9, 0.5);

    // ���� �ڵ�(5): �ݹ��Լ� �� �� ȣ�� display, reshape, motion ȣ��
   glutDisplayFunc(MyDisplay);
   glutReshapeFunc(MyReshape);
   glutPassiveMotionFunc(MyMotion); // ���콺�� Ŭ������ �ʾƵ� ���콺�� ��ġ�� ���� ��ü�� �̵�

    glutMainLoop();
    return 0;
}
