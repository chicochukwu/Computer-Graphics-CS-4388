
/********************************************
 * main.c
 *
 * Sarah Gibbons
 * Febuary 7, 2017
 * CS 4388.251 - Project #1 Computer Graphics
 * The purpose of this program is to provide 
 * familiarity with the VM and the openGL
 * environment.
 ********************************************/

#ifdef _WIN32
#include <GL/glut.h>
#elif __APPLE__
#include <GLUT/glut.h>
#elif __linix__
#include <GL/glut.h>
#endif

// ============================================================================
// initializeGL: inilializes background color to back and white
// ============================================================================

void initializeGL() {
    
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and white
}

// ============================================================================
// display: a rectangle, triangle and hexagon using glBegin and glEnd to specify
//          the quadrant that way there is no overlap
// ============================================================================

void display() {
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
  
    glBegin(GL_QUADS);              // form a rectangle
    glVertex2f(-0.9f, 0.1f);        // define vertices starting with lower-left v
    glVertex2f(0.0f, 0.1f);         // lower right v
    glVertex2f(0.0f, 0.7f);         // upper right v
    glVertex2f(-0.9f, 0.7f);        // upper left v
    glEnd();                        // end of rectangle quad
    
    glBegin(GL_TRIANGLES);          // Each set of 3 vertices form a triangle
    
    glVertex2f(-0.7f, -0.6f);
    glVertex2f(-0.1f, -0.6f);
    glVertex2f(-0.4f, -0.1f);
    glEnd();
    
    glBegin(GL_POLYGON); // These vertices form a closed polygon
    
    glVertex2f(0.4f, 0.2f);
    glVertex2f(0.6f, 0.2f);
    glVertex2f(0.7f, 0.4f);
    glVertex2f(0.6f, 0.6f);
    glVertex2f(0.4f, 0.6f);
    glVertex2f(0.3f, 0.4f);
    glEnd();
    
    glFlush();  // Render now
}

// ============================================================================
// main: Creates a window, sets the size to 640x480 and initializes position
//       to be in the upper left quadrent then calls glutDisplayFunc
// returns 0 for success
// ============================================================================

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                  // initialize GLUT
    glutCreateWindow("OpenGL Project 1");   // create window with a title
    glutInitWindowSize(640, 480);           // define a window 640x480
                                            //glutInitWindowPosition(50,50);          // initializing left corner so no-overlap
                                            //glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
    glutDisplayFunc(display);
    initializeGL();
    glutMainLoop();
    
    return 0;
}

