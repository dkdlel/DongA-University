/*
중간 동그라미는 실제 조명과는 전혀 연관이 없는 "보여주기"용
(1) 중간 동그라미 그리는 4줄이 없으면 어떻게 되나요?
 -> 실제 조명과는 연관이 없음. 동그라미 없어도 조명효과는 잘 유지됨 but 동그라미가 없으면 광원의 위치가 보이지 않아 불편하기 때문에 추가로 동그라미를 그려줌
(2) 중간 동그라미 그릴 때 조명을 꺼주지 않으면 어떻게 되나요?
 -> 조명을 끄면 glColor3f함수가 잘 작동 되어서 동그라미가 잘 보임 but 조명을 끄지 않으면, 정확히 광원의 위치에 있는 이 동그라미는 눈에 잘 안보임
(3) 동그라미에 조명 색을 잘 지정하면?
 -> 위치가 광원의 정확한 위치이기 때문에 조명을 받기가 힘듬 따라서 잠시 조명을 꺼주는게 가장 효과적

 Q5
 (1) 빨간 행성 삭제, 파란 행성 위치 우측으로(5,0,0)
 (2) 광원이 2개이므로, 위치 배열 변수 2개 선언(위치는 원점)
 (3) 실제 light0 위치 조정, 서비스용 하늘생 동그라미 위치도 조정
  -> Display 함수에서 glTranslate(-5,3,0) 하나 추가
 (4) Push/Pop 부분 복사 후 위치조정, light0대신 light1로 변경, 배열 변수명도 pos0에서 pos1로 변경, 동그라미 색상도 변경
 (5) glEnable 함수에서 0번 조명 외에도 1번 조명도 켜줘야함
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
const GLfloat light_pos0[] = { 0.0, 0.0, 0.0, 1.0 }; // 광원의 위치
const GLfloat light_pos1[] = { 0.0, 0.0, 0.0, 1.0 }; // 광원의 위치
 // Light()에 대한 3D공간에서의 광원의 위치. 동차좌표계이므로 마지막에 w 있음.
 // 마지막 변수 w=0이면 원점에서 좌표(x,y,z)를 향하는 벡터 방향의 방향성 광원.
 // w가 0이 아니면 좌표 (x/w, y/w, z/w)에 위치한 위치성 광원

GLfloat move_y = 0.0;
GLfloat move_z = 0.0;
GLfloat const_att = 1.0; // 빛의 감쇠(Attenuation) 비율 지정

void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Z버퍼 켜져있음
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glShadeModel(GL_SMOOTH); // 지금당장은 생략해도 됨

    glTranslatef(0.0, 0.0, -20.0); // 무대에 중간에 위치시키려고 전체적으로 밀었음
    
    glPushMatrix(); // 없으면 밑에꺼 까지 실행하기 때문에 빨간공 파란공도 같이 움직임
    glTranslatef(-5, 3, 0); // 초기 위치 Q5-(3)
    glTranslatef(0.0, move_y, move_z);
    glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, const_att); // 빛의 감쇠율 적용 -> 0번 조명은 감쇠율이 const_att이다 / 매개변수 f : float
    glLightfv(GL_LIGHT0, GL_POSITION, light_pos0); // 광원의 위치 지정 -> 0번 조명의 위치는 light_pos이다 / 매개변수 fv : vector
    // 광원과는 상관없음. 서비스차원, 보여주기용 cuz 광원은 모양이 없기 때문에
    glDisable(GL_LIGHTING); // 광원을 활성하기 위해서는 조명을 비활성화
    glColor3f(0, 1, 1);
    glutSolidSphere(0.1, 10, 10); // 중간 작은 동그라미 -> 광원위치를 표현하기 위해서 표현
    glEnable(GL_LIGHTING); // 조명 활성화
    glPopMatrix();

    // Q5-(4)
    glPushMatrix();
    glTranslatef(-1, -4, 0); // 초기 위치 Q5-(3)
    glTranslatef(0.0, move_y, move_z);
    glLightf(GL_LIGHT1, GL_CONSTANT_ATTENUATION, const_att); 
    glLightfv(GL_LIGHT1, GL_POSITION, light_pos1); 
    glDisable(GL_LIGHTING);
    glColor3f(1, 1, 0); // 노란색
    glutSolidSphere(0.1, 10, 10); 
    glEnable(GL_LIGHTING); 
    glPopMatrix();

    // Q5-(1)
    //glTranslatef(-5.0, 0.0, 0.0);
    //glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, red); 
    //// 조명이 들어가기 시작하면 glColor3f는 사용하지 않고, glMaterialfv함수를 사용.
    //glMaterialfv(GL_FRONT, GL_SPECULAR, white); // 조명을 받는 배우의 옵션
    //glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    //glutSolidSphere(3.0, 40, 40); // 왼쪽 빨간 행성

    glTranslatef(5, 0, 0); // Q5-(1)
    glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, blue); 
    glMaterialfv(GL_FRONT, GL_SPECULAR, white);
    glMaterialfv(GL_FRONT, GL_SHININESS, polished);
    glutSolidSphere(3.0, 40, 40); // 오른쪽 파란 행성

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
void MySpecial(int key, int x, int y) { // 감쇠율
    if (key == GLUT_KEY_LEFT) {
        const_att *= 0.9f;
    }
    else if (key == GLUT_KEY_RIGHT) {
        const_att /= 0.9f;
    }

    glutPostRedisplay();
}
void MyInit() {
    glEnable(GL_LIGHTING); // 조명 효과 시작 -> 조명이란 기능을 사용하겠다
    glEnable(GL_LIGHT0); // 광원 활성화 -> 0번 조면 실행
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white); // 옵션 : 흰색 분산광
    glLightfv(GL_LIGHT0, GL_SPECULAR, white); // 옵션 : 흰색 반사광

    // Q5-(5)
    glEnable(GL_LIGHT1); // 광원 활성화 -> 0번 조면 실행
    glLightfv(GL_LIGHT1, GL_DIFFUSE, white); // 옵션 : 흰색 분산광
    glLightfv(GL_LIGHT1, GL_SPECULAR, white); // 옵션 : 흰색 반사광
    glEnable(GL_DEPTH_TEST); // Z버퍼 시작 -> 깊이 원근 조면실행중에 깊이버퍼만 끄면 : 
    // 원근이 있기 때문에 Z 값이 음수인(즉, 뒤에있는) 파란 행성이 작게 보이는건 유지
    // 깊이버퍼가 없으므로, 코딩순서상 파란행성이 앞에 나온것 처럼 보임
    // 앞에 있지만 크기는 작아보이는 파란행성
    // Z값이 엉키면서 조명효과도 Z값에 관련되어서는 예상외의 결과가 나옴.
    // 조명이 꺼지는건 아님
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