/*
�߰� ���׶�̴� ���� ������� ���� ������ ���� "�����ֱ�"��
(1) �߰� ���׶�� �׸��� 4���� ������ ��� �ǳ���?
 -> ���� ������� ������ ����. ���׶�� ��� ����ȿ���� �� ������ but ���׶�̰� ������ ������ ��ġ�� ������ �ʾ� �����ϱ� ������ �߰��� ���׶�̸� �׷���
(2) �߰� ���׶�� �׸� �� ������ ������ ������ ��� �ǳ���?
 -> ������ ���� glColor3f�Լ��� �� �۵� �Ǿ ���׶�̰� �� ���� but ������ ���� ������, ��Ȯ�� ������ ��ġ�� �ִ� �� ���׶�̴� ���� �� �Ⱥ���
(3) ���׶�̿� ���� ���� �� �����ϸ�?
 -> ��ġ�� ������ ��Ȯ�� ��ġ�̱� ������ ������ �ޱⰡ ���� ���� ��� ������ ���ִ°� ���� ȿ����

 Q5
 (1) ���� �༺ ����, �Ķ� �༺ ��ġ ��������(5,0,0)
 (2) ������ 2���̹Ƿ�, ��ġ �迭 ���� 2�� ����(��ġ�� ����)
 (3) ���� light0 ��ġ ����, ���񽺿� �ϴû� ���׶�� ��ġ�� ����
  -> Display �Լ����� glTranslate(-5,3,0) �ϳ� �߰�
 (4) Push/Pop �κ� ���� �� ��ġ����, light0��� light1�� ����, �迭 ������ pos0���� pos1�� ����, ���׶�� ���� ����
 (5) glEnable �Լ����� 0�� ���� �ܿ��� 1�� ���� �������
*/
#include <glut.h>

int window_width = 640;
int window_height = 480;

const GLfloat red[] = { 0.8f, 0.0, 0.0, 1.0 };
const GLfloat blue[] = { 0.0, 0.2f, 1.0, 1.0 };
const GLfloat white[] = { 1.0, 1.0, 1.0, 1.0 };
const GLfloat black[] = { 0.0, 0.0, 0.0, 1.0 };
const GLfloat polished[] = { 100.0 };
const GLfloat dull[] = { 0.0 };
// Q5-(2)
const GLfloat light_pos0[] = { 0.0, 0.0, 0.0, 1.0 }; // ������ ��ġ
const GLfloat light_pos1[] = { 0.0, 0.0, 0.0, 1.0 }; // ������ ��ġ
 // Light()�� ���� 3D���������� ������ ��ġ. ������ǥ���̹Ƿ� �������� w ����.
 // ������ ���� w=0�̸� �������� ��ǥ(x,y,z)�� ���ϴ� ���� ������ ���⼺ ����.
 // w�� 0�� �ƴϸ� ��ǥ (x/w, y/w, z/w)�� ��ġ�� ��ġ�� ����

GLfloat move_y = 0.0;
GLfloat move_z = 0.0;
GLfloat const_att = 1.0; // ���� ����(Attenuation) ���� ����

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Z���� ��������
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH); // ���ݴ����� �����ص� ��

    glTranslatef(0.0, 0.0, -20.0); // ���뿡 �߰��� ��ġ��Ű���� ��ü������ �о���
    
    glPushMatrix(); // ������ �ؿ��� ���� �����ϱ� ������ ������ �Ķ����� ���� ������
    glTranslatef(-5, 3, 0); // �ʱ� ��ġ Q5-(3)
    glTranslatef(0.0, move_y, move_z);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att); // ���� ������ ���� -> 0�� ������ �������� const_att�̴� / �Ű����� f : float
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos0); // ������ ��ġ ���� -> 0�� ������ ��ġ�� light_pos�̴� / �Ű����� fv : vector
    // �������� �������. ��������, �����ֱ�� cuz ������ ����� ���� ������
    glDisable(GL_LIGHTING); // ������ Ȱ���ϱ� ���ؼ��� ������ ��Ȱ��ȭ
    glColor3f(0, 1, 1);
    glutSolidSphere(0.1, 10, 10); // �߰� ���� ���׶�� -> ������ġ�� ǥ���ϱ� ���ؼ� ǥ��
    glEnable(GL_LIGHTING); // ���� Ȱ��ȭ
    glPopMatrix();

    // Q5-(4)
    glPushMatrix();
    glTranslatef(-1, -4, 0); // �ʱ� ��ġ Q5-(3)
    glTranslatef(0.0, move_y, move_z);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, const_att); 
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos1); 
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 0); // �����
    glutSolidSphere(0.1, 10, 10); 
    glEnable(GL_LIGHTING); 
    glPopMatrix();

    // Q5-(1)
    //glTranslatef(-5.0, 0.0, 0.0);
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red); 
    //// ������ ���� �����ϸ� glColor3f�� ������� �ʰ�, glMaterialfv�Լ��� ���.
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white); // ������ �޴� ����� �ɼ�
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    //glutSolidSphere(3.0, 40, 40); // ���� ���� �༺

    glTranslatef(5, 0, 0); // Q5-(1)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glutSolidSphere(3.0, 40, 40); // ������ �Ķ� �༺

    glutSwapBuffers();
    glFlush();
}
void Mouse_Movement(int x, int y) {
    move_z = (10.0 * x) / window_width;
    move_y = 5.0 - (10.0 * y) / window_height;

    glutPostRedisplay();
}
void MyReshape(int w, int h) {
    window_width = w;
    window_height = h;

    glViewport(0, 0, window_width, window_height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(35.0, GLfloat(window_width) / GLfloat(window_height), 1.0, 50.0);
    glutPostRedisplay();
}
void MySpecial(int key, int x, int y) { // ������
    if (key == GLUT_KEY_LEFT) {
        const_att *= 0.9f;
    }
    else if (key == GLUT_KEY_RIGHT) {
        const_att /= 0.9f;
    }

    glutPostRedisplay();
}
void MyInit() {
    glEnable(GL_LIGHTING); // ���� ȿ�� ���� -> �����̶� ����� ����ϰڴ�
    glEnable(GL_LIGHT0); // ���� Ȱ��ȭ -> 0�� ���� ����
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white); // �ɼ� : ��� �л걤
    glLightfv(GL_LIGHT0, GL_SPECULAR, white); // �ɼ� : ��� �ݻ籤

    // Q5-(5)
    glEnable(GL_LIGHT1); // ���� Ȱ��ȭ -> 0�� ���� ����
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white); // �ɼ� : ��� �л걤
    glLightfv(GL_LIGHT1, GL_SPECULAR, white); // �ɼ� : ��� �ݻ籤
    glEnable(GL_DEPTH_TEST); // Z���� ���� -> ���� ���� ��������߿� ���̹��۸� ���� : 
    // ������ �ֱ� ������ Z ���� ������(��, �ڿ��ִ�) �Ķ� �༺�� �۰� ���̴°� ����
    // ���̹��۰� �����Ƿ�, �ڵ������� �Ķ��༺�� �տ� ���°� ó�� ����
    // �տ� ������ ũ��� �۾ƺ��̴� �Ķ��༺
    // Z���� ��Ű�鼭 ����ȿ���� Z���� ���õǾ�� ������� ����� ����.
    // ������ �����°� �ƴ�
}
int main(int argc, char** argv) { 
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(window_width, window_height);
    glutCreateWindow("Two Lighting One Objects");
    MyInit();
    glutDisplayFunc(MyDisplay);
    glutMotionFunc(Mouse_Movement);
    glutReshapeFunc(MyReshape);
    glutSpecialFunc(MySpecial);

    glutMainLoop();
    return 0;
}