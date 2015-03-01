//
//  main.c
//  test
//
//  Created by Keerti Sekhar Sahoo on 2/1/14.
//  Copyright (c) 2014 Keerti Sekhar Sahoo. All rights reserved.
//

#include<GLUT/glut.h>
#include<stdlib.h>
#include<stdio.h>
void drawTriangle();
void drawQuad();
void drawPoint();
void drawLine();
void drawTriangle();
void drawQuad();
void drawPolygon();
void drawLineLoop();

static int x,y,n,i=0,j=0,npoints;
static float points[30][2];
static GLdouble wx, wy, wz;
static unsigned char key;
static int lineLoop;
int value;
int current_mode = 0;

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    if(current_mode == 1)
    {
        drawPoint();
    }
    if(current_mode == 5)
    {
        drawLine();
    }
    if(current_mode == 2)
    {
        drawTriangle();
    }
    else if (current_mode == 3)
    {
        drawQuad();
    }
    else if(current_mode == 4)
    {
        drawPolygon();
    }
   glFlush ();
    
}

void drawPoint()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,0.20,0.89);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    glVertex2d(points[0][0],points[0][1]);
    glEnd();
    glFlush();
}

void drawLine()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.0,1.0,1.0,1.0);
    glLineWidth(4.0);
    glBegin(GL_LINES);
    glVertex2d(points[0][0],points[0][1]);
    glVertex2d(points[1][0],points[1][1]);
    glEnd();
    glFlush();
}

void drawTriangle()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_TRIANGLES);
    glVertex2d(points[0][0],points[0][1]);
    glColor3f(0.25,1.0,0.56);
    glVertex2d(points[1][0],points[1][1]);
    glColor3f(1.0,0.20,0.89);
    glVertex2d(points[2][0],points[2][1]);
    glEnd();
    glFlush();
}

void drawQuad()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.0,1.0,1.0,1.0);
    glBegin(GL_QUADS);
    glVertex2d(points[0][0],points[0][1]);
    glColor4f(0.45,1.0,0.67,1.0);
    glVertex2d(points[1][0],points[1][1]);
    glColor4f(0.40,0.30,0.45,1.0);
    glVertex2d(points[2][0],points[2][1]);
    glColor4f(0.0,1.0,1.0,1.0);
    glVertex2d(points[3][0],points[3][1]);
    glEnd();
    glFlush();
}

void drawPolygon()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor4f(0.35,1.0,0.25,0.75);
    glBegin(GL_POLYGON);
    glVertex2d(points[0][0],points[0][1]);
    glColor4f(1.0,1.0,0.25,0.75);
    glVertex2d(points[1][0],points[1][1]);
    glColor4f(0.35,0.80,1.0,1.0);
    glVertex2d(points[2][0],points[2][1]);
    glColor4f(0.89,0.20,0.65,0.65);
    glVertex2d(points[3][0],points[3][1]);
    glColor4f(0.12,0.10,0.91,0.45);
    glVertex2d(points[4][0],points[4][1]);
    glEnd();
    glFlush();
}

void mymouse(int button,int state, int x, int y)
{
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
    {
        glGetIntegerv (GL_VIEWPORT, viewport);
        glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
        glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
        double realy = viewport[3] - (GLint) y-1;
        gluUnProject ((GLdouble) x, (GLdouble) realy, 0.0,
                      mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
        savePoints(wx,wy);
    }
}

int savePoints(double wx,double wy)
{
    points[i][j]=wx;
    j++;
    points[i][j]=wy;
    i++;
    j--;
    if(i == 1 && j==0 && npoints==1)
    {
        i=0;
        j=0;
        current_mode=1;
        glutPostRedisplay();
    }
    if(i == 2 && j==0 && npoints==2)
    {
        i=0;
        j=0;
        current_mode=5;
        glutPostRedisplay();
    }
    if(i == 3 && j==0 && npoints==3)
    {
        i=0;
        j=0;
        current_mode=2;
        glutPostRedisplay();
    }
    if( i== 4 && j==0 && npoints == 4)
    {
        i=0;
        j=0;
        current_mode=3;
        glutPostRedisplay();
    }
    if( i==5 && j==0 && npoints == 5)
    {
        i=0;
        j=0;
        current_mode=4;
        glutPostRedisplay();
    }
    return 0;
}

void keyboard(unsigned char key)
{
    switch (key)
    {
        case 'p':
            npoints = 1;
            break;
        case 'l':
            npoints = 2;
            break;
        case 't':
            npoints = 3;
            break;
        case 'q':
            npoints = 4;
            break;
        case 'P':
            npoints = 5;
            break;
        case 'c':
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            break;
        default:
            printf(" Please select a valid option ");
            
    }
    
}

void init (void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, 2.0, 0.0,2.0, -2.0, 2.0);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0,0);
    glutCreateWindow("My Paint Brush");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mymouse);
    glutMainLoop();
    return 0;
}

