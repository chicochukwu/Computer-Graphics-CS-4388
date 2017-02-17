
/********************************************
 * openGl_prj1_sfg11.c
 *
 * Sarah Gibbons
 * Febuary 7, 2017
 * CS 4388.251 - Project #2 Computer Graphics
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



GLfloat xRotated, yRotated, zRotated;

// ============================================================================
// initializeGL:
// ============================================================================

void initializeGL() {
    glClearColor(1.0, 1.0, 1.0, 0.0); //makes the window background white
    glEnable(GL_DEPTH_TEST);
    glColor3f(0.0f, 0.0f, 0.0f); //makes the generated color black
    glPointSize(10.0); //point size is 10x10 px
    glLineWidth(4.0); //line width is 4px
    glMatrixMode(GL_PROJECTION); //enables camera changes
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); //sets the camera
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0, 0, 0, 0, 0, -1, 0, 1, 0);

}

// ============================================================================
//  drawPoint
// ============================================================================
void drawPoint() {
    glClear(GL_COLOR_BUFFER_BIT); //Clears the window
    glBegin(GL_POINTS);
        glVertex2f(0,0);
    glEnd();
    glFlush();
}
// ============================================================================
//  drawLine
// ============================================================================
void drawLine()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2f(-.5,0);
        glVertex2f(.5, 0);
    glEnd();
    glFlush();
}
// ============================================================================
//  drawTriangle:
// ============================================================================
void drawTriangle(){
    glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
        glVertex2f(-.25, 0);
        glVertex2f(.25, 0);
        glVertex2f(0, .5);
    glEnd();
    glFlush();
}
// ============================================================================
//  drawSquare:
// ============================================================================
void drawSquare() {
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_QUADS);
        glVertex2f(-.25, .25);  // define vertices starting with lower-left v
        glVertex2f(.25, .25);   // upper right v
        glVertex2f(.25, -.25);
        glVertex2f(-.25, -.25);
    glEnd(); // end of rectangle quad
    glFlush();

}
// ============================================================================
//  drawHexagon:
// ============================================================================
void drawHexagon(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POLYGON);
        glVertex2f(.25, -.25);
        glVertex2f(.5, -.5);
        glVertex2f(.25, -.75);
        glVertex2f(-.25, -.75);
        glVertex2f(-.5, -.5);
        glVertex2f(-.25, -.25);
    glEnd();
    glFlush();
}
// ============================================================================
//  drawCircle:
// ============================================================================
void drawCircle() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    const static int n = 50;
    const static GLfloat R = 0.5f;
    const static GLfloat Pi = 3.14159;
    
    glBegin(GL_POLYGON);
        for(int i = 0; i < n; i++)
            glVertex2f(R*cos(2*Pi/n*i), R*sin(2*Pi/n*i));
    
    glEnd();
    glFlush();
}
// ============================================================================
//  drawCube:
// ============================================================================
void drawCube() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0f, 1, 1, 20);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(5, 5, 10, 0, 0, 0, 0, 1, 0);

    glBegin(GL_QUADS);        // Draw The Cube Using quads
        glColor3f(0.0f,1.0f,0.0f);    // Color Blue
        glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Top)
        glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Top)
        glVertex3f(-1.0f, 1.0f, 1.0f);    // Bottom Left Of The Quad (Top)
        glVertex3f( 1.0f, 1.0f, 1.0f);    // Bottom Right Of The Quad (Top)
        glColor3f(1.0f,0.5f,0.0f);    // Color Orange
        glVertex3f( 1.0f,-1.0f, 1.0f);    // Top Right Of The Quad (Bottom)
        glVertex3f(-1.0f,-1.0f, 1.0f);    // Top Left Of The Quad (Bottom)
        glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Bottom)
        glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Bottom)
        glColor3f(1.0f,0.0f,0.0f);    // Color Red
        glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Front)
        glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Front)
        glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Front)
        glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Front)
        glColor3f(1.0f,1.0f,0.0f);    // Color Yellow
        glVertex3f( 1.0f,-1.0f,-1.0f);    // Top Right Of The Quad (Back)
        glVertex3f(-1.0f,-1.0f,-1.0f);    // Top Left Of The Quad (Back)
        glVertex3f(-1.0f, 1.0f,-1.0f);    // Bottom Left Of The Quad (Back)
        glVertex3f( 1.0f, 1.0f,-1.0f);    // Bottom Right Of The Quad (Back)
        glColor3f(0.0f,0.0f,1.0f);    // Color Blue
        glVertex3f(-1.0f, 1.0f, 1.0f);    // Top Right Of The Quad (Left)
        glVertex3f(-1.0f, 1.0f,-1.0f);    // Top Left Of The Quad (Left)
        glVertex3f(-1.0f,-1.0f,-1.0f);    // Bottom Left Of The Quad (Left)
        glVertex3f(-1.0f,-1.0f, 1.0f);    // Bottom Right Of The Quad (Left)
        glColor3f(1.0f,0.0f,1.0f);    // Color Violet
        glVertex3f( 1.0f, 1.0f,-1.0f);    // Top Right Of The Quad (Right)
        glVertex3f( 1.0f, 1.0f, 1.0f);    // Top Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f, 1.0f);    // Bottom Left Of The Quad (Right)
        glVertex3f( 1.0f,-1.0f,-1.0f);    // Bottom Right Of The Quad (Right)
    glEnd();            // End Drawing The Cube
    glFlush();
    
    
 
}
// ============================================================================
// display: a rectangle, triangle and hexagon using glBegin and glEnd to specify
//          the quadrant that way there is no overlap
// ============================================================================
void display() {
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    glFlush();  // Render now
}

// ============================================================================
// animation :
// ============================================================================


void reshape(GLsizei x, GLsizei y) {  // GLsizei for non-negative integer
    if (y == 0 || x == 0) return;  //Nothing is visible then, so return
                                   //Set a new projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    gluPerspective(40.0,(GLdouble)x/(GLdouble)y,0.5,20.0);
    glMatrixMode(GL_MODELVIEW);
    glViewport(0,0,x,y);  //Use the whole window for rendering - Sdpuf

}


// ============================================================================
// menu:
// ============================================================================

void menu (unsigned char key, int mouseX, int mouseY)
{
    switch(key)
    {
        case 'p':
        case 'P':
            drawPoint();
            break;
        case 'l':
        case 'L':
            drawLine();
            break;
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
        {
            drawCube();
            initializeGL();
        }
            break;
        case 'q':
        case 'Q':
            break;
        default:
            break;
    }
}
// ============================================================================
// main: Creates a window, sets the size to 640x480 and initializes position
//       to be in the upper left quadrent then calls glutDisplayFunc
// returns 0 for success
// ============================================================================

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                  // initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //sets parameters
    glutInitWindowSize(640, 480); //sets window size
    glutCreateWindow(" Sarah Gibbons - OpenGL Project 2 ");   // create window with a title
    glutInitWindowSize(640, 480);           // define a window 640x480
    glutInitWindowPosition(100,50);          // initializing left corner so no-overlap
    initializeGL();
    glutDisplayFunc(display);
    glutKeyboardFunc(menu);
    initializeGL();
    glutMainLoop();
    
    return 0;
}
