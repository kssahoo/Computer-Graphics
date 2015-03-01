#include <GLUT/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include<string.h>
static double points[500][2],newpoint[5][2],currpoint[5][2],mousePoint[1000][2];
static double wx,wy,wz,wx1,wy1,wz1,wx2,wy2,wz2,xp,yp,dist=0,new_cordx =0.0,new_cordy=0.0,value1,value2;
static int r=0,c=0,npoints=0,index=0,localIndex;
static int status = 0,point=0;
int j;

void func_1();
void savePoints();
void drawPoint();
double funcCalc();
void drawTangent();


void display()
{
    //glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    //glClear(GL_DEPTH_BUFFER_BIT);
    glColor3f(000.0, 255.0/255.0, 255.0/255.0);
    glPointSize(8.0);
    
    glBegin(GL_POINTS);
    for( int i= 0;i<npoints;i++)
    {
        glVertex2d(points[i][0],points[i][1]);
        
    }
    glEnd();
    
    //glutSwapBuffers();
    //glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(255.0/255.0, 255.0/255.0,000.0/000.0);
    
    glBegin(GL_LINE_STRIP);
    if(npoints >3 && npoints%3==1)
    {
        int j=0;
        for(int k =0;k<(npoints-1)/3;k++)
        {
            func_1(j);
            j=j+3;
            //            //printf("npoints %d",npoints);
        }
        
    }
    if(npoints >3 && npoints%3==1)
    {
        //glBegin(GL_LINES);
        drawTangent(npoints);
        //glEnd();
        // glFlush();
        
    }
    glEnd();
    //glutSwapBuffers();
    glFlush();
    
}

void mouseFunc(int button,int state, int mx, int my)
{
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    if (state == GLUT_DOWN && button == GLUT_LEFT_BUTTON)
    {
        glGetIntegerv (GL_VIEWPORT, viewport);
        glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
        glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
        double realy = viewport[3] - (GLint) my-1;
        gluUnProject ((GLdouble) mx, (GLdouble) realy, 0.0,
                      mvmatrix, projmatrix, viewport, &wx, &wy, &wz);
        
        glutPostRedisplay();
        npoints++;
        savePoints(wx,wy);
        
    }
    if (state == GLUT_DOWN && button == GLUT_RIGHT_BUTTON)
    {
        //printf("inside the mouse func");
        glGetIntegerv (GL_VIEWPORT, viewport);
        glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
        glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
        double realy = viewport[3] - (GLint) my-1;
        gluUnProject ((GLdouble) mx, (GLdouble) realy, 0.0,
                      mvmatrix, projmatrix, viewport, &wx1, &wy1, &wz1);
        //mousePoint[localIndex][0] = wx1;
        //mousePoint[localIndex][1] = wy1;
        index = getIndex(wx1,wy1);
        
        //points[index][0] = wx1;
        //points[index][1] = wy1;
        //glutPostRedisplay();
        //index =0;
        printf("index is %d and npoints is %d",index,npoints);
    }
}

void savePoints(double wx,double wy)
{
    points[npoints-1][0]=wx;
    points[npoints-1][1]=wy;
    
    if((npoints%3) ==1 && npoints != 1)
    {
        //printf("npoints is %d",npoints);
        // glClear(GL_DEPTH_BUFFER_BIT);
        //drawTangent(npoints);
        glutPostRedisplay();
        
        //        status =6;
        //        glBegin(GL_LINES);
        //        drawTangent(npoints);
        //        glEnd();
        //        glFlush();
    }
}

int getIndex(double wx1, double wy1)
{
    //int n=0;
    double min=10;
    printf("wx1 is %f and wy1 is %f\n",wx1,wy1);
    //printf("inside calcPoint");
    for(int e=0;e<=npoints;e++)
    {
        //printf(" npoints is %d\n",npoints);
        //printf("points[e][0] is %f and points[e][1] is %f \n",points[e][0],points[e][1]);
        
        value1 = (((wx1)-(points[e][0]))*((wx1)-(points[e][0])))+(((wy1)-(points[e][1])) * ((wy1)-(points[e][1])));
        dist = sqrt(value1);
        if(dist < min)
        {
            
            min = dist;
            printf("e is %d",e);
            index = e;
        }
    }
    return index;
}


void mouseMotionFunc(int xm,int ym)
{
    printf("Z");
    GLint viewport[4];
    GLdouble mvmatrix[16], projmatrix[16];
    glGetIntegerv (GL_VIEWPORT, viewport);
    glGetDoublev (GL_MODELVIEW_MATRIX, mvmatrix);
    glGetDoublev (GL_PROJECTION_MATRIX, projmatrix);
    double realy = viewport[3] - (GLint) ym-1;
    gluUnProject ((GLdouble) xm, (GLdouble) realy, 0.0,
                  mvmatrix, projmatrix, viewport, &wx2, &wy2, &wz2);
    
    //    index = getIndex(wx2,wy2);
    //    printf("index is %d",index);
    //    points[index][0] = wx2;
    //    points[index][1] = wy2;
    //
    points[index][0] = wx2;
    points[index][1] = wy2;
    glutPostRedisplay();
    
}




void drawTangent(int npoints)
{
    //glClear(GL_DEPTH_BUFFER_BIT);
    glBegin(GL_LINES);
    glVertex2d(points[npoints-2][0], points[npoints-2][1]);
    glVertex2d(points[npoints-1][0], points[npoints-1][1]);
    //glEnd();
    //glFlush();
    new_cordx = ((-1 * points[npoints-2][0]) + (2* points[npoints-1][0]));
    new_cordy = ((-1 * points[npoints-2][1]) + (2* points[npoints-1][1]));
    points[npoints][0]= new_cordx;
    points[npoints][1]= new_cordy;
    
    glBegin(GL_LINES);
    glVertex2d(points[npoints-1][0], points[npoints-1][1]);
    glVertex2d(points[npoints][0],points[npoints][1]);
    glEnd();
    glFlush();
    npoints ++;
    // printf("npoints is %d",npoints);
}


void keyboardFunc(unsigned char key)
{
    switch (key)
    {
        case 'c':
            glClear(GL_COLOR_BUFFER_BIT);
            glFlush();
            //r=0,c=0;
            npoints=0;
            break;
        case 'a':
            status = 4;
            npoints ++;
            break;
        case 'e':
            //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            //status =6;
            break;
        default:
            printf(" Please select a valid option ");
            
    }
    
}
//void mouseMove

void func_2 (double t,int j)
{
    //glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //int j=0;
    //int j=npoints-4;
    //printf("npoints is %d and j=%d\n",npoints,j);
    xp= (points[j][0] * pow((1.0-t),3.0)) + (points[j+1][0] * 3.0 *t* pow((1.0-t),2.0)) + (points[j+2][0] *3.0 * (1.0-t) * pow(t,2.0))+ (points[j+3][0] *pow(t,3.0));
    yp= (points[j][1] * pow((1.0-t),3.0)) + (points[j+1][1] * 3.0 *t* pow((1.0-t),2.0)) + (points[j+2][1] *3.0 * (1.0-t) * pow(t,2.0))
    + (points[j+3][1] *pow(t,3.0));
    glVertex2d(xp, yp);
}

void func_1 (int j)
{
    double t;
	for (t=0.0; t<=1;t+=0.1)
    {
		func_2(t,j);
	}
}

void init (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0,0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable( GL_POINT_SMOOTH );
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_SMOOTH);
    // glShadeModel(GL_SMOOTH);
    //glOrtho(-2.0, 2.0, -2.0,2.0, 0.0, 2.0);
    glOrtho(0.0, 2.0, 0.0,2.0, -2.0, 2.0);
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bezier Curve");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardFunc);
    glutMouseFunc(mouseFunc);
    glutMotionFunc(mouseMotionFunc);
    
    //glutMotionFunc(mouseMotion);
	glutMainLoop();
    return 0;
}