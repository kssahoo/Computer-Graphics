
#include<stdlib.h>
#include<GLUT/glut.h>
#include<math.h>
#include<stdio.h>
#include<string.h>
#define PI 3.14159265

static int smooth = 0,mode=1;
int buttonPressed;		/* which mouse button was pressed? */
int oldX, oldY;			/* where was our last position? */
int winWidth = 860, winHeight = 640;
float viewWidth = 3;
char *txt;
int noOfEdges,num=0,status,count=0,noOfPoints,count2;
double noOfVertices,noOfFaces,min_x,max_x,min_y,max_y,min_z,max_z,size_x,size_y,size_z;
double vert_a_x,vert_a_y,vert_a_z,vert_b_x,vert_b_y,vert_b_z,vert_c_x,vert_c_y,vert_c_z;
double vect_a_x,vect_a_y,vect_a_z,vect_b_x,vect_b_y,vect_b_z,norm_x,norm_y,norm_z;
int noOfSimpleVertices =0;
int noOfComplexVertices =0;
int noOfBoundaryVertices =0;
int noOfInteriorVertices =0;
int noOfCornerVertices=0;
//int v2tArray[][];
int tempArray[];
void readFile();
void print();
void print2();
void readFaces();
void findBoundingBox();
void getFaceNormal();
void getVertexNormal();
void getVertexTriangleRelation();
void getVertexToEdgesRelation();
void getVertexToConnectedEdgesRelation();
void printVertexTriangleValues();
void printVertexToEdgesValues();
void getSimpleVertices();
void classifyVertices();
void printEdgeToTriangles();
void computeAveragePlane();

struct vertices
{
    double x;
    double y;
    double z;
    int t;
    int a;
    int s;
    int i;
    int c;
    int e;
    int t1;
    int t2;
};

struct faces
{
    int f1;
    int f2;
    int f3;
    
};

struct vertices vertexToTriangle[100000][1000];
struct vertices vertexToEdges[100000][100000];

struct vertices v2tArray[100000][100000];
struct vertices simpleVertices[10000000];
struct vertices interiorVertices[10000000];
struct vertices cornerVertices[10000000];

struct vertices vertex[1000000];
struct vertices edge[1000000];
struct vertices edgeToTriangles[1000000];
struct vertices faceNormals[1000000];
struct vertices vertexNormals[1000000];
struct faces face[1000000];

void readFile()
{
    FILE *fp;
    
    fp = fopen("/Users/keertisekharsahoo/Desktop/OFFfolder/cow.txt", "r");
    //fp= fopen(txt,"r");
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
    //getVertexTriangleRelation();
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
    
    
    glutSwapBuffers();
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

void getVertexTriangleRelation()
{
    printf("======================Inside vertexTriangle relation method====================== \n");
    for(int v=0;v<noOfVertices;v++)
    {
        int i=0;
        int noOfTriangles=0;
        for(int j=0;j<noOfFaces;j++)
        {
            if(face[j].f1 ==v || face[j].f2 ==v || face[j].f3 ==v)
            {
                vertexToTriangle[v][i].t= j;//not using it though
                printf("v2t[%d][%d] is :%d \n",v,i,j);
                v2tArray[v][noOfTriangles].a = j;
                noOfTriangles++;
                i++;
            }
        }
        printf("The no of triangles neighbouring vertex[%d] is : %d and the those are :\n",v,noOfTriangles);
        for(int k=0;k<noOfTriangles;k++)
        {
        printf("%d \n",v2tArray[v][k].a);
        }
    }
    printVertexTriangleValues();
    
}



/* This method is for getting all the edges connected to each vertex.Going over each neighbouring triangle and finding out the edges  */
void getVertexToEdgesRelation()
{
    printf("======================Inside vertexToEdgesRelation method====================== \n");
    for(int v=0;v<noOfVertices;v++)
    {
        int index=0;
        for(int f=0;f<noOfFaces;f++)
        {
            if(face[f].f1 ==v || face[f].f2 ==v || face[f].f3 ==v)
            {
                int vertex_1 = face[f].f1;
                //printf("\nvertex_1 :%d",vertex_1);
                int vertex_2 = face[f].f2;
                //printf("\nvertex_2 :%d",vertex_2);
                
                int vertex_3 = face[f].f3;
                //printf("\nvertex_3 :%d",vertex_3);
                
                
                if(face[f].f1 == v)
                {
                    unsigned int src =0;
                    unsigned int dst =0;
                    unsigned int edge =0;
                    char ch[10] = "";
                    char ch1[10] = "";
                    
                    src = vertex_1;
                    dst = vertex_2;
                    sprintf(ch, "%u",src);
                    sprintf(ch1,"%u",dst);
                    strcat(ch,ch1);
                    
                    sscanf(ch, "%u",&edge);
                    vertexToEdges[v][index++].e = edge;
                    
                    //edgeToTriangles[final].t1 = f;
                    if(edgeToTriangles[edge].t1 != NULL)
                    {
                        edgeToTriangles[edge].t2 = f;
                    }
                    else
                    {
                        edgeToTriangles[edge].t1 = f;
                    }
                    src = vertex_1;
                    dst = vertex_3;
                    sprintf(ch, "%u",src);
                    sprintf(ch1,"%u",dst);
                    strcat(ch,ch1);
                    sscanf(ch, "%u",&edge);
                    vertexToEdges[v][index++].e = edge;
                    if(edgeToTriangles[edge].t1 != NULL)
                    {
                        edgeToTriangles[edge].t2 = f;
                    }
                    else
                    {
                        edgeToTriangles[edge].t1 = f;
                    }
                }
                
                
                if(face[f].f2 == v)
                {
                    unsigned int src =0;
                    unsigned int dst =0;
                    unsigned int edge =0;
                    char ch[10] = "";
                    char ch1[10] = "";
                    
                    src = vertex_2;
                    dst = vertex_1;
                    sprintf(ch, "%u",src);
                    sprintf(ch1,"%u",dst);
                    strcat(ch,ch1);
                    
                    sscanf(ch, "%u",&edge);
                    vertexToEdges[v][index++].e = edge;
                    if(edgeToTriangles[edge].t1 != NULL)
                    {
                        edgeToTriangles[edge].t2 = f;
                    }
                    else
                    {
                        edgeToTriangles[edge].t1 = f;
                    }
                    
                    src = vertex_2;
                    dst = vertex_3;
                    sprintf(ch, "%u",src);
                    sprintf(ch1,"%u",dst);
                    strcat(ch,ch1);
                    sscanf(ch, "%u",&edge);
                    vertexToEdges[v][index++].e = edge;
                    if(edgeToTriangles[edge].t1 != NULL)
                    {
                        edgeToTriangles[edge].t2 = f;
                    }
                    else
                    {
                        edgeToTriangles[edge].t1 = f;
                    }
                }
                
                if(face[f].f3 == v)
                {
                    unsigned int src =0;
                    unsigned int dst =0;
                    unsigned int edge =0;
                    char ch[10] = "";
                    char ch1[10] = "";
                    
                    src = vertex_3;
                    dst = vertex_1;
                    sprintf(ch, "%u",src);
                    sprintf(ch1,"%u",dst);
                    strcat(ch,ch1);
                    
                    sscanf(ch, "%u",&edge);
                    vertexToEdges[v][index++].e = edge;
                    if(edgeToTriangles[edge].t1 != NULL)
                    {
                        edgeToTriangles[edge].t2 = f;
                    }
                    else
                    {
                        edgeToTriangles[edge].t1 = f;
                    }
                    
                    src = vertex_3;
                    dst = vertex_2;
                    sprintf(ch, "%u",src);
                    sprintf(ch1,"%u",dst);
                    strcat(ch,ch1);
                    sscanf(ch, "%u",&edge);
                    vertexToEdges[v][index++].e = edge;
                    if(edgeToTriangles[edge].t1 != NULL)
                    {
                        edgeToTriangles[edge].t2 = f;
                    }
                    else
                    {
                        edgeToTriangles[edge].t1 = f;
                    }
                }
                
            }
        }
    }
    printVertexToEdgesValues();
    printEdgeToTriangles();
}


void classifyVertices()
{
    printf("$================inside get ClassifyVertices====================$");
    
    for(int v=0;v<noOfVertices;v++)
    {
       // printf("\nThe vertex is v[%d]\n",v);
        int index =0;
        for(int i=0;i<noOfFaces;i++)
        {
            int value = v2tArray[v][i].a; //triangle from the vertex to triangles array for the vertex v

            if(face[value].f1 != v)
            {
                tempArray[index] = face[value].f1;
                //printf("index is %d and 1st :%d\n",index,tempArray[index]);
                index ++;
            }
            if(face[value].f2 != v)
            {
                tempArray[index] = face[value].f2;
                //printf("index is %d and 2nd :%d\n",index,tempArray[index]);
                index ++;
            }
            if(face[value].f3 != v)
            {
                tempArray[index] = face[value].f3;
                //printf("index is %d and 3rd :%d\n",index,tempArray[index]);
                index ++;
            }
            if(v2tArray[v][i+1].a == NULL)
            {
                
                break;
            }
        }
        //Checking whether the vertices occur twice or not bcz for a complete cycle of traingles the vertices at the circumference should occur twice in a loop kind.
       // printf("\nindex value for vertex[%d]is %d",v,index);
        int status =0;
        
        for(int k=0;k<index;k++)
        {
            int counter=0;
            for(int j=0;j<index;j++)
            {
                if(tempArray[k] == tempArray[j])
                {
                    counter ++;
                    
                }
                
//                if( counter == 2)
//                {
//                    //continue;
//                    break;
//                }

                if(j == index-1 && counter != 2)
                {
                    printf("\nThe value doesn't occur twice. No further check needed");
                    status = 7;
                }
            }
            if( status ==7)
            {
                //printf("\n 1st test The vertex[%d] is not a simple vertex\n",v);
                
                //printf("\n The vertex[%d] is a Boundary vertex\n",v);
                break;
            }
        }
        if(status == 0)
        {
            /* From here we need to cehck wehther the particular vertex is simple by checking all the connected edges containig the vertex share exactly two triangles */
            int index =0;
            for(int f=0;f<noOfFaces;f++)
            {
                if(face[f].f1 ==v || face[f].f2 ==v || face[f].f3 ==v)
                {
                    int vertex_1 = face[f].f1;
                    printf("\nvertex_1 :%d",vertex_1);
                    int vertex_2 = face[f].f2;
                    printf("\nvertex_2 :%d",vertex_2);

                    int vertex_3 = face[f].f3;
                    printf("\nvertex_3 :%d",vertex_3);

                    
                    if(face[f].f1 == v)
                    {
                        unsigned int src =0;
                        unsigned int dst =0;
                        unsigned int final =0;
                        char ch[10] = "";
                        char ch1[10] = "";
                        
                        src = vertex_1;
                        dst = vertex_2;
                        sprintf(ch, "%u",src);
                        sprintf(ch1,"%u",dst);
                        strcat(ch,ch1);
                        
                        sscanf(ch, "%u",&final);
                        vertexToEdges[v][index++].e = final;
                        
                        src = vertex_1;
                        dst = vertex_3;
                        sprintf(ch, "%u",src);
                        sprintf(ch1,"%u",dst);
                        strcat(ch,ch1);
                        sscanf(ch, "%u",&final);
                        vertexToEdges[v][index++].e = final;
                    }
                    
                    
                    if(face[f].f2 == v)
                    {
                        unsigned int src =0;
                        unsigned int dst =0;
                        unsigned int final =0;
                        char ch[10] = "";
                        char ch1[10] = "";
                        
                        src = vertex_2;
                        dst = vertex_1;
                        sprintf(ch, "%u",src);
                        sprintf(ch1,"%u",dst);
                        strcat(ch,ch1);
                        
                        sscanf(ch, "%u",&final);
                        vertexToEdges[v][index++].e = final;
                        
                        src = vertex_2;
                        dst = vertex_3;
                        sprintf(ch, "%u",src);
                        sprintf(ch1,"%u",dst);
                        strcat(ch,ch1);
                        sscanf(ch, "%u",&final);
                        vertexToEdges[v][index++].e = final;
                    }
                    
                    if(face[f].f3 == v)
                    {
                        unsigned int src =0;
                        unsigned int dst =0;
                        unsigned int final =0;
                        char ch[10] = "";
                        char ch1[10] = "";
                        
                        src = vertex_3;
                        dst = vertex_1;
                        sprintf(ch, "%u",src);
                        sprintf(ch1,"%u",dst);
                        strcat(ch,ch1);
                        
                        sscanf(ch, "%u",&final);
                        vertexToEdges[v][index++].e = final;
                        
                        src = vertex_3;
                        dst = vertex_2;
                        sprintf(ch, "%u",src);
                        sprintf(ch1,"%u",dst);
                        strcat(ch,ch1);
                        sscanf(ch, "%u",&final);
                        vertexToEdges[v][index++].e = final;
                    }
                    
                }
        
            }
            printf("index value is %d",index);
            
            int status =0;
            int count=0;
            for(int i=0;i<index;i++)
            {
                int counter=0;
                for(int j=0;j<index;j++)
                {
                    count ++;
                    //int value = vertexToEdges[v][j].e;
                    //printf("\nvertexToEdges[%d][%d].e:%d",v,i,vertexToEdges[v][i].e);
                    //printf("\nvalue(vertexToEdges[%d][%d].e):%d",v,j,value);
                    
                    if(vertexToEdges[v][i].e == vertexToEdges[v][j].e)
                    {
                        counter++;
                        printf("\nincrementing counter and the value is %d",counter);
                        
                    }
                    if(j== index-1 && counter != 2)
                    {
                        printf("counter is %d",counter);
                        status = 8;
                        break;
                    }
                    printf("counter isssssss %d",counter);
                }
                if(status ==8)
                {
                    noOfComplexVertices++;
                    printf("\n$$$$%%^^#@&*@^^@^&The vertex[%d] is a COMPLEX vertex#$@@**&@%&^#*&#*&*#*",v);
                    break;
                }
            }
            printf("loop is for %d times",count);
            if(status ==0) // here we need to classify the simple vertex further to discover interior edge or corner vertex.
            {
                printf("\n--------------------The veretx[%d] is a SIMPLE vertex---------------------",v);
                simpleVertices[noOfSimpleVertices++].s = v;
                //code for calculation of dihedral angles and finding interior edges and corner edges
                int featureEdgeCount = 0;
                int i=0;
                while(1)
                    
                {
                    
                    float featureAngle = 90.0;
                    int edge = vertexToEdges[v][i].e;
                    int triangle1 =  edgeToTriangles[edge].t1;
                    int triangle2 = edgeToTriangles[edge].t2;
                    int dotProd=0;
                    float theta =0.0;
                    dotProd = (((faceNormals[triangle1].x)*(faceNormals[triangle2].x)) + ((faceNormals[triangle1].y)*(faceNormals[triangle2].y))+((faceNormals[triangle1].z)*(faceNormals[triangle2].z)));
                    theta = acos(dotProd) *180.0 / PI;
                    if(theta > featureAngle)
                    {
                        featureEdgeCount++;
                    }
                    
                    if(vertexToEdges[v][i+1].e == NULL)
                    {
                        break;
                    }
                    i++;
                }
                if(featureEdgeCount == 4) // 4 instead of 2 bcz the edges 12 and 21 are same.
                {
                    
                    interiorVertices[noOfInteriorVertices++].i = v;
                }
                if(featureEdgeCount == 1 || featureEdgeCount >= 3)
                {
                    cornerVertices[noOfCornerVertices++].c = v;
                }
            }
            
        }//end of checking each vertex for edges.
        else
        {
            noOfBoundaryVertices++;
            printf("=============The vertex[%d] is a BOUNDARY vertex=================",v);
        }
            
    }
    printf("\nTotal no of vertices of the mesh is: %lf",noOfVertices);
    printf("\nTotal no of Simple Vetices of the mesh is: %d",noOfSimpleVertices);
    printf("\nTotal no of Complex Vetices of the mesh is: %d",noOfComplexVertices);
    printf("\nTotal no of Boundary Vertices of the mesh is: %d",noOfBoundaryVertices);
    printf("\nTotal no of Interior vertices of mesh is: %d",noOfInteriorVertices);
    printf("\nTotal no of Corner vertices of mesh is: %d",noOfCornerVertices);
    
}

//This method is for calculating avarage plane from a candidate vertex and decide the decimation criteria
void computeAveragePlane()
{
    int i=0;
    double num_x =0,num_y =0,num_z =0;
    double basePoint_x , basePoint_y, basePoint_z;
    double den = 0;
    int v = simpleVertices[i].s;
    //Get the triangles surrounding the vertex
    while(1)
    {
    
        int triangle = vertexToTriangle[v][i].t;
       
        double vertex1_x = vertex[face[triangle].f1].x;
        double vertex1_y = vertex[face[triangle].f2].x;
        double vertex1_z = vertex[face[triangle].f3].x;
        
        double vertex2_x = vertex[face[triangle].f1].y;
        double vertex2_y = vertex[face[triangle].f2].y;
        double vertex2_z = vertex[face[triangle].f3].y;
        
        double vertex3_x = vertex[face[triangle].f1].z;
        double vertex3_y = vertex[face[triangle].f2].z;
        double vertex3_z = vertex[face[triangle].f3].z;
        //Calculate the center of the triangle
        double center_x = (vertex1_x + vertex2_x +vertex3_x)/3;
        double center_y = (vertex1_y + vertex2_y + vertex3_y)/3;
        double center_z = (vertex1_z + vertex2_z + vertex3_z)/3;
        
        double area = (((vertex1_x)*(vertex2_y - vertex3_y)) + ((vertex2_x)*(vertex3_y - vertex1_y)) + ((vertex3_x)*(vertex1_y - vertex2_y)))/2;
        
        if(vertexToTriangle[v][i+1].t == NULL)
        {
            break;
        }
        num_x = num_x + (area * center_x);
        num_y = num_y + (area * center_y);
        num_z = num_z + (area * center_z);
        den = den + area;
        
        i++;
    }
    basePoint_x = num_x / den;
    basePoint_y = num_y / den;
    basePoint_z = num_z / den;
    
    //Calculate distance from the Base point to the plane.i.e. (Vertex - Base Point) . normal
    double dist = sqrt(pow((basePoint_x - vertex[v].x),2) + pow((basePoint_y - vertex[v].y),2) + pow((basePoint_z - vertex[v].z),2));
    
}


unsigned int concatenateFunc(unsigned int vertex1,unsigned int vertex2)
{
    unsigned int src =0;
    unsigned int dst =0;
    unsigned int final =0;
    char ch[10] = "";
    char ch1[10] = "";
    
    src = vertex1;
    dst = vertex2;
    sprintf(ch, "%u",src);
    sprintf(ch1,"%u",dst);
    strcat(ch,ch1);
    
    sscanf(ch, "%u",&final);

    return final;
}

int getValue()
{
    printf("inside get value method ");
    for(int i=0;i<noOfFaces;i++)
    {
        printf("%d",v2tArray[2][i].a);
        if(v2tArray[2][i+1].a == NULL)
        {
            break;
        }
    }
    return 0;
}


void printVertexToEdgesValues()
{
    for(int i=0;i<noOfVertices;i++)
    {
        int j=0;
        while(1)
        {
        
        printf("vertexToEdges[%d][%d]: %d\n",i,j,vertexToEdges[i][j].e);
        if(vertexToEdges[i][j+1].e == NULL)
        {
            break;
        }
        j++;
        }
    }
}

void printEdgeToTriangles()
{
    printf("=============Inside printEdgeToTriangles method=================");
//    while (1)
//    {
        printf("\n edgeToTriangles for vertex %d is :%d",10,edgeToTriangles[11801181].t1);
        printf("\n edgeToTriangles for vertex %d is :%d",10,edgeToTriangles[11801181].t2);
        
    //}
}




void printVertexTriangleValues()
{
    printf("======================Inside printVertexTriangleValues method======================== \n");
    for(int i=0;i<noOfVertices;i++)
    {
        for(int j=0;j<noOfFaces;j++)
        {
            
            printf("v2t[%d][%d] is %d \n",i,j,vertexToTriangle[i][j].t);
            if(vertexToTriangle[i][j+1].t == NULL)
            {
                break;
            }
        }
    }
}

void printSimpleVertices()
{
    int countt =0;
    for(int i=0;i<noOfSimpleVertices;i++)
    {
        printf("simpleVertices[%d]:%d\n",i,simpleVertices[i].s);
        countt ++;
        if(simpleVertices[i+1].s == NULL)
        {
            break;
        }
    }
    printf("/////////////////////////////////////// the simple vertices count is %d////////////////////////////////////////////////",countt);
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
    getVertexTriangleRelation();
    getVertexToEdgesRelation();
    //getSimpleVertices();
    classifyVertices();
    //func();
    //printVertexTriangleValues();
    computeAveragePlane();
    //printSimpleVertices();
    
    glutMainLoop();
    return 0;             /* ANSI C requires main to return int. */
}

