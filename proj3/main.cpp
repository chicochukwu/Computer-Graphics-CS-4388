
/********************************************
 * Assignment_S3_sfg11.cpp
 *
 * Sarah Gibbons
 * April 2, 2017
 * CS 4388.251 - Assignment S3 Computer Graphics
 *
 ********************************************/

#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linix__
#include <GL/glut.h>
#endif
#include <math.h>
#include <stddef.h>

    // define at least 4 light sources
void init() {
        //glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClearColor(1.0, 1.0, 1.0, 0.0); //makes the window background white
    glMatrixMode(GL_PROJECTION); //enables camera changes
    glLoadIdentity();
    glFrustum(-2.0,2.0, -2.0,2.0, 2.0,6.0); //Define 4x4x4 view volume with near edge 2 far edge 6
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0,0.0,2.0, 0.0,0.0,-2.0, 0.0,1.0,0.0); //Place camera on scene egde and invert Z
    
    glEnable(GL_DEPTH_TEST);
    
        //ambient light
    glEnable(GL_LIGHTING);
    GLfloat model_ambient[4] = {0.4f, 0.4f, 0.4f, 1.0f};
    GLfloat local_view[]={0.0};
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, model_ambient);
    glLightModelfv(GL_LIGHT_MODEL_LOCAL_VIEWER, local_view);
    
        //positioned light
    glEnable(GL_LIGHT0);
    GLfloat lightPos0[4] = {-50.0f, 100.0f, 0.0f, 1.0f};
    GLfloat lightDiff0[4] = {1.0f, 1.0f, 1.0f, 1.0f}; //white
    GLfloat lightAmb0[4] = {0.025f, 0.025f, 0.025f, 1.0f}; //grey
    GLfloat lightSpec0[4]= { 1.0f, 1.0f, 1.0f, 1.0f}; //white
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb0);
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiff0);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpec0);
    
        //directed light
    glEnable(GL_LIGHT1);
    GLfloat lightPos1[4] = {120.0f, -130.f, 130.0f, 0.0f};
    GLfloat lightDiff1[4] = {0.25f, 0.25f, 0.25f, 1.0f};
    GLfloat lightAmb1[4] = {0.0125f, 0.0125f, 0.0125f, 1.0f};
    GLfloat lightSpec1[4]= { 0.95f, 0.95f, 0.95f, 1.0f};
    glLightfv(GL_LIGHT1, GL_AMBIENT, lightAmb1);
    glLightfv(GL_LIGHT1, GL_POSITION, lightPos1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, lightDiff1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, lightSpec1);
    
        //spotlight
    glEnable(GL_LIGHT2);
    GLfloat lightSpot[4] = {-1.0f, 1.0f, -8.0f};
    GLfloat lightDiff2[4] = {0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat lightAmb2[4] = {0.05f, 0.05f, 0.05f, 1.0f};
    GLfloat lightSpec2[4]= { 0.8f, 0.8f, 0.8f, 1.0f};
    GLfloat lightPos2[4] = {-120.0f, 130.0f, -130.0f, 0.0f};
    
    glLightfv(GL_LIGHT2, GL_POSITION, lightPos2);
    glLightfv(GL_LIGHT2, GL_AMBIENT, lightAmb2);
    glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, lightSpot);
    glLightfv(GL_LIGHT2, GL_DIFFUSE, lightDiff2);
    glLightfv(GL_LIGHT2, GL_SPECULAR, lightSpec2);
    glLightf(GL_LIGHT2,GL_SPOT_CUTOFF,180.0);
    glLightf(GL_LIGHT2,GL_SPOT_EXPONENT, 2.0);
    glLightf(GL_LIGHT2,GL_CONSTANT_ATTENUATION,1.5);
    glLightf(GL_LIGHT2,GL_LINEAR_ATTENUATION,0.5);
    glLightf(GL_LIGHT2,GL_QUADRATIC_ATTENUATION, 0.2);
    
        //Configure glColor
    glEnable(GL_COLOR_MATERIAL);        //Configure glColor
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    
    glEnable(GL_RESCALE_NORMAL);
    glEnable(GL_CULL_FACE);         //Enable face culling for cube face rendering
    
}


    // ============================================================================
    //  drawPoint
    // ============================================================================
void drawPoint() {
    glPushMatrix();
    glPointSize(4.0);
    glTranslatef(0,1,0);
    glScalef(2,2,2);
    
    glShadeModel(GL_FLAT);
        //point material
        //point materials
    GLfloat AmP[4] = { 0.45f, 0.45f, 0.45f, 1.0f};
    GLfloat DmP[4] = { 0.45f, 0.54f, 0.45f, 1.0f};
    GLfloat SmP[4] = { 0.54f, 0.45f, 0.54f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmP);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmP);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmP);
    glBegin(GL_POINTS);
    glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing black
    glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    glPopMatrix();
    
    
}
    // ============================================================================
    //  drawLine
    // ============================================================================
void drawLine()
{
    
    glPushMatrix();
    glLineWidth(4.0);
    glTranslatef(0,-1,0);
    glScalef(1.5,1.5,1.5);
    glRotatef(90, 0, 0, 1);
    
    glShadeModel(GL_FLAT);
        //line materials
    GLfloat AmL[4] = { 0.55f, 0.55f, 0.55f, 1.0f};
    GLfloat DmL[4] = { 1.0f, 0.0f, 1.0f, 1.0f};
    GLfloat SmL[4] = { 0.65f, 0.65f, 0.65f, 1.0f};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmL);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmL);
    
    glTranslatef(0,-1,0);
    glScalef(1.5,1.5,1.5);
    glRotatef(90, 0, 0, 1);
    
    glColor3f(0.0f, 255.0f, 0.0f); // set the drawing color
    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 1.0f);          // set the drawing color green
    glNormal3f(0.0,0.0,0.0);
    glVertex3f(-0.5, 0.0, 0.0);
    glVertex3f(0.5, 0.0, 0.0);
    glEnd();
    glPopMatrix();
    
}
    // ============================================================================
    //  drawTriangle:
    // ============================================================================
void drawTriangle(){
    glPushMatrix();
    glTranslatef(-1,-1.5,-1);
    glScalef(1,1,1);
    glRotatef(45, 0, 0, 1);
    
    glShadeModel(GL_FLAT);
        //triangle materials
    GLfloat AmT[4] = { 0.0f, 0.0f, 0.5f, 1.0f};
    GLfloat DmT[4] = { 0.0f, 0.0f, 1.0f, 1.0f};
    GLfloat SmT[4] = { 0.90f, 0.90f, 0.90f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmT);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmT);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmT);
    glMaterialf(GL_FRONT, GL_SHININESS, 10.0f); //shine
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f, 0.0f, 1.0f);          // set the drawing color blue
    glNormal3f(0.0f, 0.0f, -1.0f);
    glVertex3f(-0.5, -0.5, 0.0);        // testing nonesense
    glVertex3f(0.5, -0.5, 0.0);        // testing nonesense
    glVertex3f(0.0, 0.5, 0.0);        // testing nonesense
    glEnd();
    glPopMatrix();
}
    // ============================================================================
    //  drawSquare:
    // ============================================================================
void drawSquare() {
    glPushMatrix();
    glTranslatef(-1,1,0);
    glScalef(.75,.75,.75);
    glRotatef(270, 0, 0, 1);
    
    
    glShadeModel(GL_FLAT);
        //square material
        //square materials
    GLfloat AmS[4] = { 0.2f, 0.2f, 0.2f, 1.0f};
    GLfloat DmS[4] = { 0.0f, 1.0f, 1.0f, 1.0f};
    GLfloat SmS[4] = { 0.6f, 0.6f, 0.6f, 1.0f};
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmS);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmS);
    glMaterialf(GL_FRONT, GL_SHININESS, 30.0f); //shine
    
    
    glBegin(GL_POLYGON);
    glNormal3f(0.0f, 0.0f, 1.0f);
    glColor3f(0.0f, 0.0f, 255.0f); // set the drawing color
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(-0.5, 0.5, 0.0);
    glVertex3f(0.5, 0.5, 0.0);
    glVertex3f(0.5, -0.5, 0.0);
    glEnd();
    glPopMatrix();
    
    /*
     glBegin(GL_QUADS);
     glVertex2f(-.25, .25);  // define vertices starting with lower-left v
     glVertex2f(.25, .25);   // upper right v
     glVertex2f(.25, -.25);
     glVertex2f(-.25, -.25);
     */
        //glFlush();
    
}
    // ============================================================================
    //  drawHexagon:
    // ============================================================================
void drawHexagon(){
    
    glPushMatrix();
    glTranslatef(-1, 0, 0);
    glScalef(1,.5,1);
    glRotatef(30, 0, 0, 1);
    
    
    glShadeModel(GL_FLAT);
        //hexagon material
        //hex materials
    GLfloat AmH[4] = { 0.0f, 0.0f, 0.0f, 1.0f};
    GLfloat DmH[4] = { 1.0f, 1.0f, 1.0f, 1.0f};
    GLfloat SmH[4] = { 0.5f, 0.5f, 0.5f, 1.0f};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmH);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmH);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmH);
    glMaterialf(GL_FRONT, GL_SHININESS, 60.0f); //shine
    glColor3f(0.0f, 0.0f, 0.0f);          // set the drawing color
    
        // glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    glBegin(GL_POLYGON);
        //using angles to derive point vertex position
    for(int i = 0; i <= 360; i+=60){
        double x = cos(i* (M_PI/180))/2;
        double y = sin(i* (M_PI/180))/2;
        glNormal3f(0,0,1);
        glVertex3d(x,y,0.0);
    }
    glEnd();
    glPopMatrix();
}
    // ============================================================================
    //  drawCircle:
    // ============================================================================
void drawCircle() {
    
    glPushMatrix();
    
    glTranslatef(1,-1,-0.5);
    glScalef(.75,1.25,1);
    glRotatef(225, 0, 0, 1);
    
    glShadeModel(GL_FLAT);
    
        //circle materials
    GLfloat AmC[4] = { 0.8f, 0.8f, 0.0f, 1.0f};
    GLfloat DmC[4] = { 1.0f, 1.0f, 0.3f, 1.0f};
    GLfloat SmC[4] = { 0.8f, 0.7f, 0.8f, 1.0f};
    
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmC);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmC);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmC);
    glMaterialf(GL_FRONT, GL_SHININESS, 60.0f); //shine
    
        //       glClear(GL_COLOR_BUFFER_BIT);     // clear the screen
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 0.0f);          // set the drawing color
                                          //using angles to find radius to derive point vertex position
    for(int i =0; i <= 360; i++){
        double x = cos(i*(M_PI/180))/2;
        double y = sin(i*(M_PI/180))/2;
        glNormal3f(0,0,1);
        glVertex3d(x,y,0.0);
    }
    glEnd();
    glPopMatrix();
}
    // ============================================================================
    //  drawCube:
    // ============================================================================
void drawCube() {
        //glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        // glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
    glShadeModel(GL_SMOOTH);
        //glLoadIdentity();
        //gluLookAt(5, 5, 10, 0, 0, 0, 0, 1, 0);
    
        //glTranslatef(1.5f, 0.0f, -7.0f);  // Move right and into the screen
        //glScalef(1.0,1.0,1.9);
    /*
     GLfloat AmU[4] = { 0.5f, 0.2f, 0.2f, 1.0f};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, AmU);
     GLfloat DmU[4] = { 1.0f, 0.0f, 0.0f, 1.0f};
     glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, DmU);
     GLfloat SmU[4] = { 0.95f, 0.95f, 0.95f, 1.0f};
     glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, SmU);
     glMaterialf(GL_FRONT, GL_SHININESS, 50.0f); //shine
     
     */
    
    glColor3f(0.0f,1.0f,0.0f);    // Color Blue
    glBegin(GL_POLYGON);        // Draw The Cube Using polygon
    glNormal3f(0.0f, 1.0f, 0.0f);
    glVertex3f(0.5, 0.5, -0.5); //top right front
    glVertex3f(0.5, 0.5, 0.5); //top right back
    glVertex3f(-0.5, 0.5, 0.5); //top left back
    glVertex3f(-0.5, 0.5, -0.5); //top left front
    glEnd();
    
    glBegin(GL_POLYGON);        // Draw The Cube Using polygon
    glColor3f(1.0f,0.5f,0.0f);    // Color Orange
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,0.0f);    // Color Red
    glNormal3f(0.0f, -1.0f, 0.0f);
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
    glEnd();
    
    glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(0.0f,0.0f,1.0f);    // Color Blue
    glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right
    glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left
    glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left
    glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right
    glEnd();
    
    glBegin(GL_POLYGON);
    glColor3f(1.0f,0.0f,1.0f);    // Color Violet
    glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right
    glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left
    glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left
    glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right
    
    glEnd();            // End Drawing The Cube
    glPopMatrix();
    glFlush();
    
    
    
}


void drawSphere(double r, int lats, int longs) {
    glPushMatrix();
    glTranslatef(-0.5, 1, -0.75);
    glScalef(.25,.25,.25);
    glColor3f(0.0f, 1.0f, 0.0f);
    
        //sphere material
        //sphere materials, is green
    GLfloat AmZ[4] = { 0.05f, 0.05f, 0.05f, 1.0f};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, AmZ);
    GLfloat DmZ[4] = { 0.0f, 0.1f, 0.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_DIFFUSE, DmZ);
    GLfloat SmZ[4] = { 1.0f, 1.0f, 1.0f, 1.0f};
    glMaterialfv(GL_FRONT, GL_SPECULAR, SmZ);
    
    glMaterialf(GL_FRONT, GL_SHININESS, 8.0f); //shine
    
    glShadeModel(GL_SMOOTH);
    glPushMatrix();
    int i, j;
    for(i = 0; i <= lats; i++) {
        double lat0 = M_PI * (-0.5 + (double) (i - 1) / lats);
        double z0  = sin(lat0);
        double zr0 =  cos(lat0);
        
        double lat1 = M_PI * (-0.5 + (double) i / lats);
        double z1 = sin(lat1);
        double zr1 = cos(lat1);
        
        glBegin(GL_QUAD_STRIP);
        for(j = 0; j <= longs; j++) {
            double lng = 2 * M_PI * (double) (j - 1) / longs;
            double x = cos(lng);
            double y = sin(lng);
            
            glNormal3f(x * zr0, y * zr0, z0);
            glVertex3f(x * zr0, y * zr0, z0);
            glNormal3f(x * zr1, y * zr1, z1);
            glVertex3f(x * zr1, y * zr1, z1);
        }
        glEnd();
        
    }
    glPopMatrix();
    
    
}
void draw() {
}

    // ============================================================================
    // display: a rectangle, triangle and hexagon using glBegin and glEnd to specify
    //          the quadrant that way there is no overlap
    // ============================================================================
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //clear window
}





    // ============================================================================
    // menu:
    // ============================================================================

void menu (unsigned char key, int mouseX, int mouseY)
{
    switch(key)
    {
        case 'd':
            glClear(GL_COLOR_BUFFER_BIT);
        case 'p':
        case 'P':
            drawPoint();
                //break;
        case 'l':
        case 'L':
            drawLine();
                //break;
        case 't':
        case 'T':
            drawTriangle();
            break;
        case 's':
        case 'S':
            drawSquare();
            break;
        case 'h':
        case 'H':
            drawHexagon();
            break;
        case 'c':
        case 'C':
            drawCircle();
            break;
        case 'u':
        case 'U':
            drawCube();
            break;
            
        case 'f':
            drawSphere(1.0, 10, 10);
                //glutSwapBuffers();
                //glutPostRedisplay();
            break;
        default:
            break;
    }
}
    // ============================================================================
    // mySpecial:
    // ============================================================================
void mySpecial( int special, int mouseX, int mouseY)
{
    if (special == GLUT_KEY_LEFT){
        glRotatef( 45, 0.0, 0.0, 1.0 );
        glLoadIdentity();
        gluLookAt(-2.0,0.0,2.0, 0.0,0.0,-2.0, 0.0,1.0,0.0);
    }
    else if (special == GLUT_KEY_RIGHT){
        glRotatef( -45, 0.0, 0.0, 1.0 );
        glLoadIdentity();
        gluLookAt(2.0,0.0,2.0, 0.0,0.0,-2.0, 0.0,1.0,0.0);
    }
    else if (special == GLUT_KEY_UP){
        glLoadIdentity();
        gluLookAt(0.0,-2.0,2.0, 0.0,0.0,-2.0, 0.0,1.0,0.0);
    }
    else if (special == GLUT_KEY_DOWN){
        glLoadIdentity();
        gluLookAt(0.0,2.0,2.0, 0.0,0.0,-2.0, 0.0,1.0,0.0);
        glDisable(GL_LIGHT2);
        glDisable(GL_LIGHT1);
        
        
    }
    menu('d',0,0); // redraw everything with new perspective
}


    // ============================================================================
    // main: Creates a window, sets the size to 640x480 and initializes position
    //       to be in the upper left quadrent then calls glutDisplayFunc
    // returns 0 for success
    // ============================================================================

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                  // initialize GLUT
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE| GLUT_RGB); //sets parameters
    
    glutInitWindowSize(800, 600);           // define a window 640x480
    
    glutInitWindowPosition(100,150);          // initializing left corner so no-overlap
    glutVideoPan(50, 50, 500, 500);
    glutCreateWindow(" Sarah Gibbons - OpenGL Project s3 ");   // create window with a title
    init();
    
    glutDisplayFunc(display);
    
    
    glutKeyboardFunc(menu);
    
    glutSpecialFunc(mySpecial);
    
    glutMainLoop();
    
    return 0;
}
