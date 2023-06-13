#include <iostream>
#include<GL/gl.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <bits/stdc++.h>
#include<GL/gl.h>
#include<windows.h>
#include<math.h>

using namespace std;

const int width = 1500;
const int height = 1000;

GLfloat eyeX = 10;
GLfloat eyeY = 10;
GLfloat eyeZ = 45;

GLfloat lookX = 10;
GLfloat lookY = 2;
GLfloat lookZ = 0;

static GLfloat v_cube[8][3] =
{
    {0,0,0},
    {0,0,1},
    {0,1,0},
    {0,1,1},

    {1,0,0},
    {1,0,1},
    {1,1,0},
    {1,1,1}
};

static GLubyte c_ind[6][4] =
{
    {0,2,6,4},
    {1,5,7,3},
    {0,4,5,1},
    {2,3,7,6},
    {0,1,3,2},
    {4,6,7,5}
};

static void getNormal3p(GLfloat x1, GLfloat y1, GLfloat z1, GLfloat x2, GLfloat y2, GLfloat z2, GLfloat x3, GLfloat y3, GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void cube(float r,float g,float b)
{

    glBegin(GL_QUADS);
    glColor3d(r,g,b);
    for (GLint i = 0; i <6; i++)
    {
        getNormal3p(v_cube[c_ind[i][0]][0], v_cube[c_ind[i][0]][1], v_cube[c_ind[i][0]][2],
                    v_cube[c_ind[i][1]][0], v_cube[c_ind[i][1]][1], v_cube[c_ind[i][1]][2],
                    v_cube[c_ind[i][2]][0], v_cube[c_ind[i][2]][1], v_cube[c_ind[i][2]][2]);

        for (GLint j=0; j<4; j++)
        {
            glVertex3fv(&v_cube[c_ind[i][j]][0]);
        }
    }
    glEnd();
}

void drawGreenGound()
{
    glPushMatrix();
    /// height/width change
    glScaled(50,0.2,50);
    ///Color change
    cube(0.0,1.0,0.0);
    glPopMatrix();
}

void leftWindow()
{
    glPushMatrix();
    glTranslated(9.9,4.5,15);
    glScaled(0,3,2);
    cube(1.6,1.6,1.6);
    glPopMatrix();
}


void vaticalWallLeft()
{
    /// |
    glPushMatrix();
    glTranslated(10,0,10);
    glScaled(1,12,10);
    cube(0.0,0.5,0.0);
    glPopMatrix();

    leftWindow();
}

void vaticalWallNorth()
{
    glPushMatrix();
    glTranslated(10,0,9);
    glScaled(11,12,1);
    cube(1.0,0.6,1.0);
    glPopMatrix();
}

void vaticalWallRight()
{
    ///    |
    glPushMatrix();
    glTranslated(20,0,10);
    glScaled(1,12,10);
    cube(0.0,0.7,7.0);
    glPopMatrix();
}

void fontDoor()
{
    glPushMatrix();
    glTranslated(13,0,19.5);
    glScaled(2,8,2);
    cube(1.0,0.9,1.9);
    glPopMatrix();
}

void vaticalWallSouth()
{
    glPushMatrix();
    glTranslated(10,0,20);
    glScaled(11,12,1);
    cube(1.0,0.8,0.0);
    glPopMatrix();

    fontDoor();
}

void horizontalRoofTop()
{
    glPushMatrix();
    glTranslated(9,12,9);
    glScaled(13,1,13);
    cube(0.5,0.1,0.1);
    glPopMatrix();
}

void Siri()
{
    /// 12
    glPushMatrix();
    glTranslated(4,12,19);
    glScaled(5,1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    /// 11
    glPushMatrix();
    glTranslated(4,11,18);
    glScaled(3,1,1);
    cube(0.0,0.5,0.5);
    glPopMatrix();
     /// 10
    glPushMatrix();
    glTranslated(4,10,17);
    glScaled(3,1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    /// 9
    glPushMatrix();
    glTranslated(4,9,16);
    glScaled(3,1,1);
    cube(0.0,0.5,0.5);
    glPopMatrix();
    /// 8
    glPushMatrix();
    glTranslated(4,8,15);
    glScaled(3,1.1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    /// 7
    glPushMatrix();
    glTranslated(1,6.5,14);
    glScaled(6,1.5,-2);
    cube(0.0,0.5,0.5);
    glPopMatrix();
    /// 6
    glPushMatrix();
    glTranslated(1,6,15);
    glScaled(3,1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    /// 5
    glPushMatrix();
    glTranslated(1,5,16);
    glScaled(3,1,1);
    cube(0.0,0.5,0.5);
    glPopMatrix();
    /// 4
    glPushMatrix();
    glTranslated(1,4,17);
    glScaled(3,1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    /// 3
    glPushMatrix();
    glTranslated(1,3,18);
    glScaled(3,1,1);
    cube(0.0,0.5,0.5);
    glPopMatrix();
    /// 2
    glPushMatrix();
    glTranslated(1,2,19);
    glScaled(3,1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
    /// 1
    glPushMatrix();
    glTranslated(1,1,20);
    glScaled(3,1,1);
    cube(0.0,0.5,0.5);
    glPopMatrix();

    /// 0
    glPushMatrix();
    glTranslated(1,0,21);
    glScaled(3,1,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();





    /// siri piller

       /// small
    glPushMatrix();
    glTranslated(3.5,0,12);
    glScaled(1,6.5,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();

     /// big
    glPushMatrix();
    glTranslated(6,0,19);
    glScaled(1,12,1);
    cube(0.0,0.5,1.0);
    glPopMatrix();
}


void drawTree() {

    // Draw the trunk
    glPushMatrix();
    glTranslated(33,-5,25);
    glScaled(1,20,1);
    cube(0.6, 0.3, 0.0);
    glPopMatrix();

    // cirle one
    glPushMatrix();
    glTranslated(32,15,25);
    cube(0.0, 0.4, 0.0);
    glutSolidSphere(3.0, 32, 32);
    glPopMatrix();

     // cirle two
    glPushMatrix();
    glTranslated(32,12,25);
    cube(0.0, 0.4, 0.0);
    glutSolidSphere(3.0, 32, 32);
    glPopMatrix();

    // cirle tree
    glPushMatrix();
    glTranslated(34,12,25);
    cube(0.0, 0.4, 0.0);
    glutSolidSphere(3.0, 20, 20);
    glPopMatrix();
}

void drawTreeOne() {

    // Draw the trunk
    glPushMatrix();
    glTranslated(27,-5,20);
    glScaled(1,20,1);
    cube(0.6, 0.3, 0.0);
    glPopMatrix();

    // cirle one
    glPushMatrix();
    glTranslated(27,15,20);
    cube(0.0, 0.4, 0.0);
    glutSolidSphere(3.0, 32, 32);
    glPopMatrix();

     // cirle two
    glPushMatrix();
    glTranslated(27,12,20);
    cube(0.0, 0.4, 0.0);
    glutSolidSphere(3.0, 32, 32);
    glPopMatrix();
}


static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-3, 3, -3, 3, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX,eyeY,eyeZ, lookX,lookY,lookZ, 0,1,0);
    glViewport(0, 0, width, height);

    /// Dracula color gound
    glPushMatrix();
    glTranslated(-50,-0.5,-50);
    glScaled(100,0.2,100);
    cube(0.2,0.2,0.2);
    glPopMatrix();


//Ground
    drawGreenGound();


    vaticalWallLeft();

    vaticalWallRight();

    vaticalWallNorth();

    vaticalWallSouth();

    horizontalRoofTop();

    Siri();

    drawTree();
    drawTreeOne();


    glutSwapBuffers();
}

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {

    case 'w':
        eyeY=eyeY+0.1;
        break;
    case 's':
        eyeY=eyeY-0.1;
        break;
    case 'd':
        eyeX=eyeX+0.1;
        break;
    case 'a':
        eyeX=eyeX-0.1;
        break;

    case 'i':
        lookY=lookY+0.1;
        break;
    case 'k':
        lookY=lookY-0.1;
        break;
    case 'j':
        lookX=lookX+0.1;
        break;
    case 'l':
        lookX=lookX-0.1;
        break;


    case '+':
        eyeZ=eyeZ+0.1;
        break;
    case '-':
        eyeZ=eyeZ-0.1;
        break;

    }

    glutPostRedisplay();
}


int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1920,1080);
    glutCreateWindow("Triangle-Demo");

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );

    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMainLoop();

    return 0;
}
