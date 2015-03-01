
#include<stdlib.h>
#include<GLUT/glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>

static int smooth = 0,mode=1;
int buttonPressed;		/* which mouse button was pressed? */
int oldX, oldY;			/* where was our last position? */
int winWidth = 680, winHeight = 460;
float viewWidth = 3;
char *txt;
int noOfEdges,num=0,status,count=0,noOfPoints,count2;
double noOfVertices,noOfFaces,min_x,max_x,min_y,max_y,min_z,max_z,size_x,size_y,size_z;
double vert_a_x,vert_a_y,vert_a_z,vert_b_x,vert_b_y,vert_b_z,vert_c_x,vert_c_y,vert_c_z;
double vect_a_x,vect_a_y,vect_a_z,vect_b_x,vect_b_y,vect_b_z,norm_x,norm_y,norm_z;
void readFile();
void print();
void print2();
void readFaces();
void findBoundingBox();
void getFaceNormal();
void getVertexNormal();


struct vertices
{
    double x;
    double y;
    double z;
};

struct faces
{
    int f1;
    int f2;
    int f3;
    int f4;
    int f5;
};

struct vertices vertex[1000000];
struct vertices faceNormals[1000000];
struct vertices vertexNormals[1000000];
struct faces face[1000000];

void readFile()
{
    FILE *fp;
    
    //fp = fopen("/Users/keertisekharsahoo/Desktop/OFF folder/dragon.txt", "r");
    fp= fopen(txt,"r");
    if (fp == NULL)
        exit(EXIT_FAILURE);
    char line[10];
    fscanf(fp, "%s", line);
    fscanf(fp,"%lf %lf %d",&noOfVertices,&noOfFaces,&noOfEdges);
    for(int i = 0; i < noOfVertices; i++)
    {
        fscanf(fp, "%lf %lf %lf",&vertex[i].x,&vertex[i].y,&vertex[i].z);
    }
    for(int f=0;f<noOfFaces;f++)
    {
        fscanf(fp, "%d %d %d %d",&noOfPoints,&face[f].f1,&face[f].f2,&face[f].f3);
    }
    fclose(fp);
    if(mode ==1 )
    {
        mode++;
    }
}




void display(void)
{
    /* clear old screen contents */
    glClearColor(.5,.7,.9,1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //readFile();
    glColor3f(197/255.00,179/255.00,88/255.00);
    /* draw something*/
    glBegin(GL_TRIANGLES);
    
    for(int c=0; c<noOfFaces;c++)
    {
        //glNormal3d(faceNormals[c].x, faceNormals[c].y, faceNormals[c].z);
        
        glNormal3d(vertexNormals[face[c].f1].x, vertexNormals[face[c].f1].y, vertexNormals[face[c].f1].z);
        glVertex3d(vertex[face[c].f1].x,vertex[face[c].f1].y,vertex[face[c].f1].z);
        
        glNormal3d(vertexNormals[face[c].f2].x, vertexNormals[face[c].f2].y, vertexNormals[face[c].f2].z);
        glVertex3d(vertex[face[c].f2].x,vertex[face[c].f2].y,vertex[face[c].f2].z);
        
        glNormal3d(vertexNormals[face[c].f3].x, vertexNormals[face[c].f3].y, vertexNormals[face[c].f3].z);
        glVertex3d(vertex[face[c].f3].x,vertex[face[c].f3].y,vertex[face[c].f3].z);
        
    }
    glEnd();
    if(status ==1)
    {
        findBoundingBox();
    }
    
    glutSwapBuffers();
}

void findBoundingBox()
{
    min_x = max_x = vertex[0].x;
    min_y = max_y = vertex[0].y;
    min_z = max_z = vertex[0].z;
    
    for (int b=0;b<noOfVertices ;b++)
    {
        if(vertex[b].x < min_x)
            min_x = vertex[b].x;
        if(vertex[b].x > max_x)
            max_x = vertex[b].x;
        if(vertex[b].y < min_y)
            min_y = vertex[b].y;
        if(vertex[b].y > max_y)
            max_y = vertex[b].y;
        if(vertex[b].z < min_z)
            min_z = vertex[b].z;
        if(vertex[b].z > max_z)
            max_z = vertex[b].z;
        
        size_x = max_x - min_x;
        size_y = max_y - min_y;
        size_z = max_z - min_z;
        
    }
    
    
    
    glColor3f(0.50, 0.90, 0.50);
    glLineWidth(2.0);
    glBegin(GL_LINE_LOOP);
    glVertex3d(min_x, min_y,min_z);
    glVertex3d(min_x, max_y,min_z);
    glVertex3d(min_x, max_y,max_z);
    glVertex3d(min_x, min_y,max_z);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(max_x, max_y,min_z);
    glVertex3d(max_x, min_y,min_z);//left
    glVertex3d(max_x, min_y,max_z);
    glVertex3d(max_x, max_y,max_z);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(min_x, min_y,min_z);
    glVertex3d(min_x, max_y,min_z);
    glVertex3d(max_x, max_y,min_z);
    glVertex3d(max_x, min_y,min_z);
    
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(min_x, min_y,max_z);
    glVertex3d(min_x, max_y,max_z);
    glVertex3d(max_x, max_y,max_z);
    glVertex3d(max_x, min_y,max_z);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(min_x, min_y,min_z);
    glVertex3d(max_x, min_y,min_z);
    glVertex3d(max_x, min_y,max_z);
    glVertex3d(min_x, min_y,max_z);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex3d(min_x, max_y,min_z);
    glVertex3d(max_x, max_y,min_z);
    glVertex3d(max_x, max_y,max_z);
    glVertex3d(min_x, max_y,max_z);
    glEnd();
}

void getFaceNormal()
{
    for(int f=0;f<noOfFaces;f++)
    {
        vert_a_x = vertex[face[f].f1].x;
        vert_a_y = vertex[face[f].f1].y;
        vert_a_z = vertex[face[f].f1].z;
        
        vert_b_x = vertex[face[f].f2].x;
        vert_b_y = vertex[face[f].f2].y;
        vert_b_z = vertex[face[f].f2].z;
        
        vert_c_x = vertex[face[f].f3].x;
        vert_c_y = vertex[face[f].f3].y;
        vert_c_z = vertex[face[f].f3].z;
        
        vect_a_x = vert_b_x - vert_a_x;
        vect_a_y = vert_b_y - vert_a_y;
        vect_a_z = vert_b_z - vert_a_z;
        
        vect_b_x = vert_c_x - vert_a_x;
        vect_b_y = vert_c_y - vert_a_y;
        vect_b_z = vert_c_z - vert_a_z;
        
        norm_x = (vect_a_y * vect_b_z) - (vect_a_z * vect_b_y);
        norm_y = (vect_a_z * vect_b_x) - (vect_a_x * vect_b_z);
        norm_z = (vect_a_x * vect_b_y) - (vect_a_y * vect_b_x);
        
        faceNormals[f].x = norm_x;
        faceNormals[f].y = norm_y;
        faceNormals[f].z = norm_z;
        count2++;
    }
}

void getVertexNormal()
{
    for(int v=0;v<noOfVertices;v++)// let v=5
    {
        double sum_x=0,sum_y=0,sum_z=0;
        int count =0;
        
        for( int j=0; j<noOfFaces;j++)
        {
            if(face[j].f1 == v || face[j].f2 ==v || face[j].f3 == v)
            {
                sum_x  = sum_x + faceNormals[j].x; //sum_x static
                sum_y  = sum_y + faceNormals[j].y;
                sum_z  = sum_z + faceNormals[j].z;
                count ++;
            }
        }
        
        vertexNormals[v].x = (sum_x)/count;
        vertexNormals[v].y = (sum_y)/count;
        vertexNormals[v].z = (sum_z)/count;
    }
    
}


/* called on any keypress
 *
 * We don't use x and y, but they're the mouse location when the key
 * was pressed.
 */
void
key(unsigned char k, int x, int y)
{
    switch (k) {
        case 27:			/* Escape: exit */
            exit(0);
        case 's': case 'S':	     /* 's' or 'S': toggle smooth & faceted */
            smooth = !smooth;
            glutPostRedisplay();	/* tell GLUT to redraw after this change */
            break;
        case 'b':
            status =1;
            glutPostRedisplay();
            //findBoundingBox();
            break;
        case 'c':
            status =0;
            glutPostRedisplay();
            //glClear(GL_COLOR_BUFFER_BIT);
            //glFlush();
            break;
    }
}
void
mousePress(int b, int state, int x, int y)
{
    buttonPressed = b;
    oldX = x;
    oldY = y;
}

/*
 * called when the mouse moves
 *
 * use difference between oldX,oldY and x,y to define a rotation
 */
void
mouseDrag(int x, int y)
{
    float dx = x - oldX;		/* record differences from last position */
    float dy = y - oldY;
    
    oldX = x;			/* update stored position */
    oldY = y;
    
    if (buttonPressed == GLUT_LEFT_BUTTON) {
        /* rotation angle, scaled so 1/2 window width = about 90 degrees */
        float angle = 180 * sqrt(dx*dx + dy*dy) / winWidth;
        
        /* save current rotation state */
        float matrix[16];
        glGetFloatv(GL_MODELVIEW_MATRIX, matrix);
        
        
        /*
         From the starting state, rotate around axis perpendicular to
         mouse motion, where the window x axis is aligned with the 3D
         view x axis, while the window y axis is aligned with the 3D
         view z axis. Find perpendicular using rule that (y,-x) is
         perpendicular to (x,y)
         */
        glLoadIdentity();
        glRotatef(angle, dy,dx,0);
        
        /* reapply other rotations so far */
        glMultMatrixf(matrix);
        
        /* tell GLUT that something has changed and we must redraw */
        glutPostRedisplay();
    }
}
/* smooth fade from 1 to 0 as t goes from 0 to 1 */
static double fade(double t) { return t * t * t * (t * (t * 6 - 15) + 10); }

/* linear interpolation between a and b */
static double lerp(double t, double a, double b) { return a + t * (b - a); }

/* convert low four bits of hash code into 12 gradient directions:
 h     x y z |  h     x y z |  h     x y z |  h     x y z
 0000   + +   | 0100   +   + | 1000     + + | 1100   + +
 0001   - +   | 0101   -   + | 1001     - + | 1101   - +
 0010   + -   | 0110   +   - | 1010     + - | 1110     + -
 0011   - -   | 0111   -   - | 1011     - - | 1111     - -
 the last four (11??) are repeats of earlier gradients
 */
static double grad(int hash, double x, double y, double z) {
    int h = hash & 15;
    double u = h<8||h==12||h==13 ? x : y;
    double v = h<4||h==12||h==13 ? y : z;
    return ((h&1) == 0 ? u : -u) + ((h&2) == 0 ? v : -v);
}

/********** exported noise function */

double noise3(double x, double y, double z) {
    /* permutation table for hashing -- 256 elements, repeated so we can compute
     permutations like p[p[x]+y+1] without masking max index: p[255+255+1] */
    static int p[] = {
        151,160,137,91,90,15,
        131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
        190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
        88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
        77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
        102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
        135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
        5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
        223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
        129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
        251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
        49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
        138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180,
        
        /* second copy */
        151,160,137,91,90,15,
        131,13,201,95,96,53,194,233,7,225,140,36,103,30,69,142,8,99,37,240,21,10,23,
        190, 6,148,247,120,234,75,0,26,197,62,94,252,219,203,117,35,11,32,57,177,33,
        88,237,149,56,87,174,20,125,136,171,168, 68,175,74,165,71,134,139,48,27,166,
        77,146,158,231,83,111,229,122,60,211,133,230,220,105,92,41,55,46,245,40,244,
        102,143,54, 65,25,63,161, 1,216,80,73,209,76,132,187,208, 89,18,169,200,196,
        135,130,116,188,159,86,164,100,109,198,173,186, 3,64,52,217,226,250,124,123,
        5,202,38,147,118,126,255,82,85,212,207,206,59,227,47,16,58,17,182,189,28,42,
        223,183,170,213,119,248,152, 2,44,154,163, 70,221,153,101,155,167, 43,172,9,
        129,22,39,253, 19,98,108,110,79,113,224,232,178,185, 112,104,218,246,97,228,
        251,34,242,193,238,210,144,12,191,179,162,241, 81,51,145,235,249,14,239,107,
        49,192,214, 31,181,199,106,157,184, 84,204,176,115,121,50,45,127, 4,150,254,
        138,236,205,93,222,114,67,29,24,72,243,141,128,195,78,66,215,61,156,180
    };
    
    int X, Y, Z,  AAA, AAB, ABA, ABB, BAA, BAB, BBA, BBB;
    double u, v, w;
    
    /* find unit cube that contains point (mod 256) */
    X = (int)floor(x) & 255,
    Y = (int)floor(y) & 255,
    Z = (int)floor(z) & 255;
    
    /* find relative position in cube and fade curves */
    x -= floor(x);  u = fade(x);
    y -= floor(y);  v = fade(y);
    z -= floor(z);  w = fade(z);
    
    /* hash eight cube corners */
    AAA = p[p[p[X  ]+Y  ]+Z  ]; AAB = p[p[p[X  ]+Y  ]+Z+1];
    ABA = p[p[p[X  ]+Y+1]+Z  ]; ABB = p[p[p[X  ]+Y+1]+Z+1];
    BAA = p[p[p[X+1]+Y  ]+Z  ]; BAB = p[p[p[X+1]+Y  ]+Z+1];
    BBA = p[p[p[X+1]+Y+1]+Z  ]; BBB = p[p[p[X+1]+Y+1]+Z+1];
    
    /* add blended results from eight corners of cube */
    return lerp(w, lerp(v, lerp(u, grad(AAA, x  , y  , z   ),
                                grad(BAA, x-1, y  , z   )),
                        lerp(u, grad(ABA, x  , y-1, z   ),
                             grad(BBA, x-1, y-1, z   ))),
                lerp(v, lerp(u, grad(AAB, x  , y  , z-1 ),
                             grad(BAB, x-1, y  , z-1 )),
                     lerp(u, grad(ABB, x  , y-1, z-1 ),
                          grad(BBB, x-1, y-1, z-1 ))));
}
void
reshape(int width, int height)
{
    /* distance in grid coordinates from edge to the center of the window */
    float xMax = viewWidth/2;
    float yMax = xMax * height / width;
    
    /* copy width and height into global variables so other callback
     functions can access them */
    winWidth = width;
    winHeight = height;
    
    /* this viewport makes a 1 to 1 mapping of physical pixels to GL
     "logical" pixels */
    glViewport(0, 0, (GLint) width, (GLint) height);
    
    /* adjust region of 3D space projected into this window */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-xMax, xMax,		/* x extents */
            -yMax, yMax,		/* y extents */
            -xMax, xMax);		/* z extents */
    
    /* switch back to "normal" transformation mode */
    glMatrixMode(GL_MODELVIEW);
}

/* initialize GLUT - windows and interaction */
void initGLUT(int *argcp, char *argv[])
{
    /* ask for a window at 0,0 with dimensions winWidth, winHeight */
    /* need color, depth (for 3D drawing) and double buffer (smooth display) */
    glutInit(argcp, argv);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(winWidth, winHeight);
    glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
    glutCreateWindow("Modeled Scene: Assignment 2");
    
    /* set callback functions to be called by GLUT for drawing, window
     resize, keypress, mouse button press, and mouse movement */
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(key);
    glutMouseFunc(mousePress);
    glutMotionFunc(mouseDrag);
}

/* initialize OpenGL - rendering state */
void initGL()
{
    float lightdir[4] = {1,1,2,0};	/* homogeneous light position: directional if w=0 */
    float white[4] = {1,1,1,1}; 		/* color for light: glLightfv needs 4 components!*/
    float dim[4] = {.2,.2,.2,1};
    
    /* enable some GL features */
    glEnable(GL_DEPTH_TEST);		/* tell OpenGL to handle overlapping surfaces */
    glEnable(GL_COLOR_MATERIAL);		/* map glColor to surface colors used by lighting */
    glEnable(GL_NORMALIZE);		/* tell GL to normalize normals so we don't have to */
    
    /* set up one light for both directional and ambient */
    glLightfv(GL_LIGHT0, GL_AMBIENT, dim);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, white);
    glLightfv(GL_LIGHT0, GL_POSITION, lightdir);
    glEnable(GL_LIGHT0);			/* turn on this light */
    glEnable(GL_LIGHTING);		/* turn on use of lighting in general */
    
    glEnable(GL_SMOOTH);
    glShadeModel(GL_SMOOTH);
    
}

int main(int argc, char *argv[])
{
    /* set up GLUT and OpenGL */
    initGLUT(&argc, argv);
    initGL();
    txt = argv[1];
    //printf(" i am in main %s \n",txt);
    /* let glut take over, it goes into a loop, checking for input and
     calling the input callbacks, then seeing if we need to draw and
     calling the draw callback, ad infinitum */
    readFile();
    getFaceNormal();
    getVertexNormal();
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}

