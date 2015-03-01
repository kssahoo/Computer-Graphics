#include <GLUT/glut.h>
#include <stdlib.h>
#include<math.h>

static double wx,wy,wz,wx1,wy1,t=0.1,s=0.1,xCoord,yCoord,zCoord,surfacePoints[50][50][50],matrix[50][50][50];
//static int r=0,c=0,j=0,npoints=0,index;
static int count=0,counter=0;
int i=0,j=0,p=0,q=0;
void fun_1();
void fun_2();
void getVertical();
double points[4][4][3] = {
	{
		{ 0.0,0.0,0.0 },
		{ 0.3,0.0,0.0 },
		{ 0.6,0.0,0.0 },
		{ 1.0,0.0,0.0 }
	},
	{
		{ 0.0,0.0,0.3 },
		{ 0.3,1.0,0.3 },
		{ 0.6,1.0,0.3 },
		{ 1.0,0.0,0.3 }
	},
	{
		{ 0.0,0.0,0.6 },
		{ 0.3,1.0,0.6 },
		{ 0.6,1.5,0.6 },
		{ 1.0,0.0,0.6 }
	},
	{
		{ 0.0,0.0,1.0 },
		{ 0.3,0.0,1.0 },
		{ 0.6,0.0,1.0 },
		{ 1.0,0.0,1.0 }
	}
};



void display()
{

    //printf("inside the display funcs");
    //glClear(GL_COLOR_BUFFER_BIT);
    gluLookAt(0.6, 0.50, 2.0, -1.0, -1.0, -1.0, 0.0, 1.0, 0.0);
    fun_1();
    
   //getVertical();
//    
//    glBegin(GL_POINTS);
//
//    for(int i=0;i<10;i++)
//    {
//        for(int j=0;j<10;j++)
//        {
//           
//            glVertex3d(surfacePoints[i][j][0],surfacePoints[i][j][1],surfacePoints[i][j][2]);
//            
//        }
//        //j++;
//    }
//    glEnd();
    
//    glBegin(GL_POINTS);
//    
//    for(int p=0;p<10;p++)
//    {
//        for(int q=0;q<10;q++)
//        {
//    
//            glVertex3d(matrix[q][p][0],matrix[q][p][1],matrix[q][p][2]);
//    
//        }
//        //q++;
//   }
//
//    glEnd();
    glFlush();
    
}

void fun_1 ()
{
    
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0, 0.0, 0.0);
    for(s=0.0;s<1;s+=0.05)
    {
     
        for(t=0.0;t<1;t+=0.05)
        {
            //printf(" s is %f and t is %f\n",s,t);
            
            
            xCoord = pow(t,3)*((pow(s,3)*(((points[0][0][0] - ((3) * (points[1][0][0])) + ((3)* (points[2][0][0])) - points[3][0][0]) + (((-1) * (points[0][1][0]))+
                                                                                                                                         ((3)*(points[1][1][0]))-((3)*(points[2][1][0]))+ points[3][1][0])*(3) + (-3)*(((-1)*(points[0][2][0]))+((3)*(points[1][2][0])) -((3)*(points[2][2][0]))+points[3][2][0])
                                           +(((-1)*(points[0][3][0]))+((3)*(points[1][3][0])) - ((3)*(points[2][3][0])) +points[3][3][0])))) +
                               (pow(s,2))*(((((3)*(points[0][0][0])) -((6)*(points[1][0][0])) + ((3)*(points[2][0][0])))*(-1) + (3)*(((3)*(points[0][1][0])) - ((6)*(points[1][1][0])) +((3)*(points[2][1][0]))) +
                                            (-3)*(((3)*(points[0][2][0]))-((6)*(points[1][2][0]))+((3)*(points[2][2][0]))) + (((3)*(points[0][3][0]))-((6)*(points[1][3][0])) + ((3)*(points[2][3][0]))))) +
                               (s)*( (((3)*(points[0][0][0]))-((3)*(points[1][0][0]))+(3)*(((-3)*(points[0][1][0]))+((3)*(points[1][1][0]))) + (-3)*(((-3)*(points[0][2][0]))+((3)*(points[1][2][0])))+
                                      (((-3)*(points[0][3][0]))+((3)*(points[1][3][0]))))) + ((points[0][0][0])*(-1) + (points[0][1][0])*(3) + (points[0][2][0])*(-3) + points[0][3][0]))
            + pow(t,2)*(pow(s,3)*(((((-1)*(points[0][0][0])) +((3)*(points[1][0][0]))-((3)*(points[2][0][0]))+points[3][0][0])*(3) + (((-1)*(points[0][1][0])) + ((3)*(points[1][1][0])) -((3)*(points[2][1][0]))+points[3][1][0])*(-6) + (((-1)*(points[0][2][0])) +((3)*(points[1][2][0])) -((3)*(points[2][2][0])) +points[3][2][0])*(3)))
                        + pow(s,2)*( ((((3)*(points[0][0][0]))-((6)*(points[1][0][0]))+((3)*(points[2][0][0])))*(3) + (-6)*(((3)*(points[0][1][0]))-((6)*(points[1][1][0]))+((3)*(points[2][1][0]))) + (3)*(((3)*(points[0][2][0])) -((6)*(points[1][2][0]))+((3)*(points[2][2][0]))))) +
                        (s)*(((((-3)*(points[0][0][0])) +((3)*(points[1][0][0])))*(3) + (((-3)*(points[0][1][0])) +((3)*(points[1][1][0])))*(-6) + (((-3)*(points[0][2][0]))+((3)*(points[1][2][0])))*(3))) + ((points[0][0][0])*(3) + (points[0][1][0])*(-6) + (points[0][2][0])*(3)))
            + (t)*(pow(s,3)*(((((-1)*(points[0][0][0]))+((3)*(points[1][0][0]))-((3)*(points[2][0][0]))+points[3][0][0])*(-3) + (((-1)*(points[0][1][0]))+((3)*(points[1][1][0]))-((3)*(points[2][1][0]))+points[3][1][0])*(3))) +
                   pow(s,2)*( ((((3)*(points[0][0][0])) -((6)*(points[1][0][0]))+((3)*(points[2][0][0])))*(-3) + (3)*(((3)*(points[0][1][0]))-((6)*(points[1][1][0]))+((3)*(points[2][1][0]))))) +
                   (s)*(((((-3)*(points[0][0][0])) +((3)*(points[1][0][0])))*(-3) + (((-3)*(points[0][1][0]))+((3)*(points[1][1][0])))*(3))) +
                   ((points[0][0][0])*(-3) + (points[0][1][0])*(3))) +
            (pow(s,3)*((((-1)*(points[0][0][0])) + ((3)*(points[1][0][0]))-((3)*(points[2][0][0]))+points[3][0][0])) + pow(s,2)*((((3)*(points[0][0][0])) -((6)*(points[1][0][0]))+((3)*(points[2][0][0]))))+(s)*((((-3)*(points[0][0][0]))+((3)*(points[1][0][0])))) + (points[0][0][0]));
            
            
            yCoord = pow(t,3)*((pow(s,3)*(((points[0][0][1] - ((3) * (points[1][0][1])) + ((3)* (points[2][0][1])) - points[3][0][1]) + (((-1) * (points[0][1][1]))+
                                                                                                                                         ((3)*(points[1][1][1]))-((3)*(points[2][1][1]))+ points[3][1][1])*(3) + (-3)*(((-1)*(points[0][2][1]))+((3)*(points[1][2][1])) -((3)*(points[2][2][1]))+points[3][2][1])
                                           +(((-1)*(points[0][3][1]))+((3)*(points[1][3][1])) - ((3)*(points[2][3][1])) +points[3][3][1])))) +
                               (pow(s,2))*(((((3)*(points[0][0][1])) -((6)*(points[1][0][1])) + ((3)*(points[2][0][1])))*(-1) + (3)*(((3)*(points[0][1][1])) - ((6)*(points[1][1][1])) +((3)*(points[2][1][1]))) +
                                            (-3)*(((3)*(points[0][2][1]))-((6)*(points[1][2][1]))+((3)*(points[2][2][1]))) + (((3)*(points[0][3][1]))-((6)*(points[1][3][1])) + ((3)*(points[2][3][1]))))) +
                               (s)*( (((3)*(points[0][0][1]))-((3)*(points[1][0][1]))+(3)*(((-3)*(points[0][1][1]))+((3)*(points[1][1][1]))) + (-3)*(((-3)*(points[0][2][1]))+((3)*(points[1][2][1])))+
                                      (((-3)*(points[0][3][1]))+((3)*(points[1][3][1]))))) + ((points[0][0][1])*(-1) + (points[0][1][1])*(3) + (points[0][2][1])*(-3) + points[0][3][1]))
            + pow(t,2)*(pow(s,3)*(((((-1)*(points[0][0][1])) +((3)*(points[1][0][1]))-((3)*(points[2][0][1]))+points[3][0][1])*(3) + (((-1)*(points[0][1][1])) + ((3)*(points[1][1][1])) -((3)*(points[2][1][1]))+points[3][1][1])*(-6) + (((-1)*(points[0][2][1])) +((3)*(points[1][2][1])) -((3)*(points[2][2][1])) +points[3][2][1])*(3)))
                        + pow(s,2)*( ((((3)*(points[0][0][1]))-((6)*(points[1][0][1]))+((3)*(points[2][0][1])))*(3) + (-6)*(((3)*(points[0][1][1]))-((6)*(points[1][1][1]))+((3)*(points[2][1][1]))) + (3)*(((3)*(points[0][2][1])) -((6)*(points[1][2][1]))+((3)*(points[2][2][1]))))) +
                        (s)*(((((-3)*(points[0][0][1])) +((3)*(points[1][0][1])))*(3) + (((-3)*(points[0][1][1])) +((3)*(points[1][1][1])))*(-6) + (((-3)*(points[0][2][1]))+((3)*(points[1][2][1])))*(3))) + ((points[0][0][1])*(3) + (points[0][1][1])*(-6) + (points[0][2][1])*(3)))
            + (t)*(pow(s,3)*(((((-1)*(points[0][0][1]))+((3)*(points[1][0][1]))-((3)*(points[2][0][1]))+points[3][0][1])*(-3) + (((-1)*(points[0][1][1]))+((3)*(points[1][1][1]))-((3)*(points[2][1][1]))+points[3][1][1])*(3))) +
                   pow(s,2)*( ((((3)*(points[0][0][1])) -((6)*(points[1][0][1]))+((3)*(points[2][0][1])))*(-3) + (3)*(((3)*(points[0][1][1]))-((6)*(points[1][1][1]))+((3)*(points[2][1][1]))))) +
                   (s)*(((((-3)*(points[0][0][1])) +((3)*(points[1][0][1])))*(-3) + (((-3)*(points[0][1][1]))+((3)*(points[1][1][1])))*(3))) +
                   ((points[0][0][1])*(-3) + (points[0][1][1])*(3))) +
            (pow(s,3)*((((-1)*(points[0][0][1])) + ((3)*(points[1][0][1]))-((3)*(points[2][0][1]))+points[3][0][1])) + pow(s,2)*((((3)*(points[0][0][1])) -((6)*(points[1][0][1]))+((3)*(points[2][0][1]))))+(s)*((((-3)*(points[0][0][1]))+((3)*(points[1][0][1])))) + (points[0][0][1]));
            
            
            
            zCoord = pow(t,3)*((pow(s,3)*(((points[0][0][2] - ((3) * (points[1][0][2])) + ((3)* (points[2][0][2])) - points[3][0][2]) + (((-1) * (points[0][1][2]))+
                                                                                                                                         ((3)*(points[1][1][2]))-((3)*(points[2][1][2]))+ points[3][1][2])*(3) + (-3)*(((-1)*(points[0][2][2]))+((3)*(points[1][2][2])) -((3)*(points[2][2][2]))+points[3][2][2])
                                           +(((-1)*(points[0][3][2]))+((3)*(points[1][3][2])) - ((3)*(points[2][3][2])) +points[3][3][2])))) +
                               (pow(s,2))*(((((3)*(points[0][0][2])) -((6)*(points[1][0][2])) + ((3)*(points[2][0][2])))*(-1) + (3)*(((3)*(points[0][1][2])) - ((6)*(points[1][1][2])) +((3)*(points[2][1][2]))) +
                                            (-3)*(((3)*(points[0][2][2]))-((6)*(points[1][2][2]))+((3)*(points[2][2][2]))) + (((3)*(points[0][3][2]))-((6)*(points[1][3][2])) + ((3)*(points[2][3][2]))))) +
                               (s)*( (((3)*(points[0][0][2]))-((3)*(points[1][0][2]))+(3)*(((-3)*(points[0][1][2]))+((3)*(points[1][1][2]))) + (-3)*(((-3)*(points[0][2][2]))+((3)*(points[1][2][2])))+
                                      (((-3)*(points[0][3][2]))+((3)*(points[1][3][2]))))) + ((points[0][0][2])*(-1) + (points[0][1][2])*(3) + (points[0][2][2])*(-3) + points[0][3][2]))
            + pow(t,2)*(pow(s,3)*(((((-1)*(points[0][0][2])) +((3)*(points[1][0][2]))-((3)*(points[2][0][2]))+points[3][0][2])*(3) + (((-1)*(points[0][1][2])) + ((3)*(points[1][1][2])) -((3)*(points[2][1][2]))+points[3][1][2])*(-6) + (((-1)*(points[0][2][2])) +((3)*(points[1][2][2])) -((3)*(points[2][2][2])) +points[3][2][2])*(3)))
                        + pow(s,2)*( ((((3)*(points[0][0][2]))-((6)*(points[1][0][2]))+((3)*(points[2][0][2])))*(3) + (-6)*(((3)*(points[0][1][2]))-((6)*(points[1][1][2]))+((3)*(points[2][1][2]))) + (3)*(((3)*(points[0][2][2])) -((6)*(points[1][2][2]))+((3)*(points[2][2][2]))))) +
                        (s)*(((((-3)*(points[0][0][2])) +((3)*(points[1][0][2])))*(3) + (((-3)*(points[0][1][2])) +((3)*(points[1][1][2])))*(-6) + (((-3)*(points[0][2][2]))+((3)*(points[1][2][2])))*(3))) + ((points[0][0][2])*(3) + (points[0][1][2])*(-6) + (points[0][2][2])*(3)))
            + (t)*(pow(s,3)*(((((-1)*(points[0][0][2]))+((3)*(points[1][0][2]))-((3)*(points[2][0][2]))+points[3][0][2])*(-3) + (((-1)*(points[0][1][2]))+((3)*(points[1][1][2]))-((3)*(points[2][1][2]))+points[3][1][2])*(3))) +
                   pow(s,2)*( ((((3)*(points[0][0][2])) -((6)*(points[1][0][2]))+((3)*(points[2][0][2])))*(-3) + (3)*(((3)*(points[0][1][2]))-((6)*(points[1][1][2]))+((3)*(points[2][1][2]))))) +
                   (s)*(((((-3)*(points[0][0][2])) +((3)*(points[1][0][2])))*(-3) + (((-3)*(points[0][1][2]))+((3)*(points[1][1][2])))*(3))) +
                   ((points[0][0][2])*(-3) + (points[0][1][2])*(3))) +
            (pow(s,3)*((((-1)*(points[0][0][2])) + ((3)*(points[1][0][2]))-((3)*(points[2][0][2]))+points[3][0][2])) + pow(s,2)*((((3)*(points[0][0][2])) -((6)*(points[1][0][2]))+((3)*(points[2][0][2]))))+(s)*((((-3)*(points[0][0][2]))+((3)*(points[1][0][2])))) + (points[0][0][2]));
            
            surfacePoints[i][j][0] = xCoord;
            surfacePoints[i][j][1] = yCoord;
            surfacePoints[i][j][2] = zCoord;
            //i++;
            
            count ++;
            //printf("xp is %f",xCoord);
            //printf("xp is %f , yp is %f and zp is %f\n",xCoord,yCoord,zCoord);
            printf("Surf points : (%f, %f, %f) \n",surfacePoints[i][j][0],surfacePoints[i][j][1],surfacePoints[i][j][2]);
            glVertex3d(xCoord, yCoord, zCoord);
            j++;
        }
        i++;
    }
    printf("count is %d ",count);
    glEnd();
    glFlush();
}

void getVertical()
{
    //int p=0,q=0;
    for(p=0;p<10;p++)
    {
        for(q=0;q<10;q++)
        {
            printf("p is %d",p);
            matrix[q][p][0] = surfacePoints[p][q][0];
            matrix[q][p][1] = surfacePoints[p][q][1];
            matrix[q][p][2] = surfacePoints[p][q][2];
            printf("surface points : (%f, %f, %f) \n",surfacePoints[p][q][0],surfacePoints[p][q][1],surfacePoints[p][q][2]);
            printf(" p %d and q %d are matrix points : (%f, %f, %f) \n",p,q,matrix[q][p][0],matrix[q][p][1],matrix[q][p][2]);
            counter ++;
            
        }
    }
    printf("counter is %d ",counter);
    
}

//void fun_2()
//{
//    for(int k=0;k<count;k++)
//    {
//        printf("Surf points : (%f, %f, %f) ",surfacePoints[i][j][0],surfacePoints[i][j][1],surfacePoints[i][j][2]);
//    }
//}

void init (void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor (0.0, 0.0,0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glEnable( GL_POINT_SMOOTH );
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_SMOOTH);
    //glOrtho(0.0, 4.0, -4.0, 4.0, 0.0, 1.0);
    //glOrtho(0.0, 2.0, 0.0,2.0, -2.0, 2.0);

    glOrtho(0.0, 2.0, 0.0,2.0, -2.0, 2.0);
    
    
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bezier Curve");
    init();
    glutDisplayFunc(display);
	glutMainLoop();
    return 0;
}