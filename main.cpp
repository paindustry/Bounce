#include <GL/glut.h>
#include <math.h>
using namespace std;
#define baris 13
#define kolom 13
#define PI 3.1415926535897932384626433832795
float tX = 0.0f, tY = 0.0f, tZ = 0.0f;
static int radius = 1;
static GLubyte kotak[baris][kolom][13];

struct colours {
    int merah;
    int hijau;
    int biru;

} sbiru, shijau, slbiru, skuning, smerah, sputih;

void panel();
void objek();
void bola();
void papan();

void display(void);

void panel(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    bola();
    papan();
    objek();
}

void bola() {
    int i, j, c;
    for (i = 0; i < kolom; i++) {
        for (j = 0; j < baris; j++) {
            c = ((((i & 0x8) == 0)^((j & 0x8)) == 0))*255;
            kotak[i][j][0] = (GLubyte) c;
            kotak[i][j][1] = (GLubyte) c;
            kotak[i][j][2] = (GLubyte) c;
            kotak[i][j][3] = (GLubyte) c;
            kotak[i][j][4] = (GLubyte) c;
            kotak[i][j][5] = (GLubyte) c;
            kotak[i][j][6] = (GLubyte) c;
            kotak[i][j][7] = (GLubyte) c;
            kotak[i][j][8] = (GLubyte) c;
            kotak[i][j][9] = (GLubyte) c;
            kotak[i][j][10] = (GLubyte) c;
            kotak[i][j][11] = (GLubyte) c;
            kotak[i][j][12] = (GLubyte) 255;
        }
    }
    for (int i = 0; i < 12; i++) {
        glColor3f(0.2, 0.3, 0.5);
        glBegin(GL_POLYGON);
        for (double i = 0; i < 2 * PI; i += PI / 6)
            glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
        glEnd();
    }
}

void papan() {
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(-13, 13);
    glVertex2f(13, 13);
    glVertex2f(13, 13);
    glVertex2f(13, -13);
    glVertex2f(13, -13);
    glVertex2f(-13, -13);
    glVertex2f(-13, -13);
    glVertex2f(-13, 13);
    glEnd();
}

void objek() {
    glPushMatrix();
    glTranslatef(tX, tY, tZ);
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, 1);
    glVertex2f(1, -1);
    glVertex2f(1, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, -1);
    glVertex2f(-1, 1);
    glEnd();
    glPopMatrix();
    glFlush();
}

int warna() {
    sbiru.merah = 0;
    sbiru.hijau = 0;
    sbiru.biru = 255;
    shijau.merah = 0;
    shijau.hijau = 100;
    shijau.biru = 0;
    slbiru.merah = 0;
    slbiru.hijau = 255;
    slbiru.biru = 255;
    skuning.merah = 265;
    skuning.hijau = 140;
    skuning.biru = 0;
    smerah.merah = 1;
    smerah.hijau = 0;
    smerah.biru = 0;
    sputih.merah = 1;
    sputih.hijau = 1;
    sputih.biru = 1;
    colours array[6] = {sbiru, shijau, slbiru, skuning, smerah, sputih};
}

void atas() {
    tY += 2.0f;
    if (tY == 14) {
        tY -= 2.0f;
    }
    glutPostRedisplay();
}

void bawah() {
    tY -= 2.0f;
    if (tY == -14) {
        tY += 2.0f;
    }
    glutPostRedisplay();
}

void kiri() {
    tX -= 2.0f;
    if (tX == -14) {
        tX += 2.0f;
    }
    glutPostRedisplay();
}

void kanan() {
    tX += 2.0f;
    if (tX == 14) {
        tX -= 2.0f;
    }
    glutPostRedisplay();
}

void geser2(int key, int x, int y) {
    switch (key) {
        case GLUT_KEY_UP:
            atas();
            break;
        case GLUT_KEY_DOWN:
            bawah();
            break;
        case GLUT_KEY_LEFT:
            kiri();
            break;
        case GLUT_KEY_RIGHT:
            kanan();
            break;
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(300, 500);
    glClearColor(0, 0, 0, 0);
    glutCreateWindow("space bounce");
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-15, 15, -25, 25);
    glutDisplayFunc(panel);
    glutSpecialFunc(geser2);
    glutMainLoop();
    return 0;
}
