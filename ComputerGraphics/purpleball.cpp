/*------------------------------------------------
위치 옮기는 보라색 공

(1) 여기코딩 1~5를 완성하세요.

(2) 화면 크기가 바뀌어도 공 모양이 넙적/홀쭉해지지 않도록 glOrtho 수정하세요~

(3) 2장 reshape할 때 화면크기 옆으로 늘려도 회색네모는 정중앙에 위치하는데
    보라색공은 화면크기 옆으로 늘려도 위치변경 안하는 이유를 두 줄 정도로 서술하세요.

(4) glOrtho 무대크기를 Maximus의 무대크기와 동일하게 만드세요.( -4 ~ 4, -3 ~ 3, -4 ~ 4)
    물론 보라색 공은 여전히 마우스모션에 따라 위치를 잘 바꿔야 함!

(5) 화면 크기가 바뀌어도 보라색 공이 위치를 잘 바꾸게 하려면 어디를 고쳐야 하는가?

---------------------------------------------------*/


#include <glut.h>

#define WIN_WIDTH 800  
#define WIN_HEIGHT 600
// 여기 코딩(1): 전역변수 선언 gx gy
GLfloat gX = 0.0, gY = 0.0;
GLfloat gWidthFactor, gHeightFactor;
GLint gNewWidth, gNewHeight;
void MyDisplay() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(0.9, 0.5, 0.9);
    // 여기 코딩(2): 한 줄 translate(gx,gy,0)
    glTranslatef(gX, gY, 0);
    glutSolidSphere(0.5, 100, 100);

    glutSwapBuffers();

}

//
//여기 코딩(3): 콜백함수 작성 MyMotion
//
void MyMotion(GLint X, GLint Y) { // 마우스는 Z값을 표현 할 수 없기 때문에 Z는 필요없음
    // 무대범위가 늘어났기 때문에 x는 0-8로 만든 다음에, -4만큼 이동, y는 0-6으로 만든 다음 -3만큼 이동
    gX = (GLfloat)X / gNewWidth * 8 * gWidthFactor - 4 * gWidthFactor; // 둘다 int형이라서 형변환
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
    // 2장 reshpae는 원점은 중아에 위치하고 범위가 늘어나도 모양은 변하지 않고 위치가 중앙이됨
    // 범위가 0~2로 늘어나면 원점은 0.5가 아니고 1이기 때문에 좌측에 원이 위치
}


int main(int argc, char** argv) {
    glutInit(&argc, argv);
    // 여기 코딩(4):  한 줄, glutInitDisplayMode(GLUT_DOUBLE) 이중버퍼 선언
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(WIN_WIDTH, WIN_HEIGHT);
    glutInitWindowPosition(100, 50);
    glutCreateWindow("위치 옮기는 보라색 공");
    glClearColor(0.7, 0.9, 0.9, 0.5);

    // 여기 코딩(5): 콜백함수 세 개 호출 display, reshape, motion 호출
   glutDisplayFunc(MyDisplay);
   glutReshapeFunc(MyReshape);
   glutPassiveMotionFunc(MyMotion); // 마우스를 클릭하지 않아도 마우스의 위치에 따라 물체가 이동

    glutMainLoop();
    return 0;
}
