#include <GL/glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct tm *newtime;
time_t ltime;

static int projectionType = 1; /// Ortho = 1, Perspective = 0

GLfloat distance = 5;
GLfloat azimuth = 0;
GLfloat incidence = 0;
GLfloat twist = 0;

void polarView () {
    glTranslatef(0.0, 0.0, -distance);
    glRotatef(-twist, 0.0, 0.0, 1.0);
    glRotatef(-incidence, 1.0, 0.0, 0.0);
    glRotatef(-azimuth, 0.0, 0.0, 1.0);
}

void insertText (float x, float y, char *text) {
    int tam;

    tam = strlen(text);
    glRasterPos3f( x, y, -1);

    for(int i = 0; i < tam; i++) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, text[i]);
    }
}

void display () {
    int hour_ticks , sec_ticks;

    time(&ltime); /// Get the time
    newtime = localtime(&ltime); /// Convert to local time

    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /// Orthogonal perspective
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.5, 1.5, -1.5, 1.5, 1.0, 30.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    /// Put the text on screen
    glColor3f( 1.0, 1.0, 1.0);
    if (projectionType == 0) {
        insertText(-0.5, -1.4, "Perspective");
    } else {
        insertText(-0.5, -1.4, "Orthogonal");
    }

    /// Change the perspective
    if (projectionType == 0) {
        glMatrixMode (GL_PROJECTION);
        glLoadIdentity();

        gluPerspective(60.0, 1, 1.0, 30.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
    }

    glPushMatrix();

    /// Activate the controls of rotation, etc
    polarView();

    glTranslatef(0,0,-0);
    glRotatef( 180, 1.0, 0.0, 0.0);

    const unsigned int tamGrade = 50;
    glBegin(GL_LINES);

    for(unsigned int j = 0; j <= tamGrade; ++j) {
        glColor3d(0, 1, 0);
        const float i = -1.0f + (j * 2.0f / (tamGrade));
        glVertex2f(i, 1.0f);
        glVertex2f(i, -1.0f);
        glVertex2f(-1.0f, i);
        glVertex2f(1.0f, i);
    }
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void keyboard (unsigned char key, int x, int y) {
    switch (key) {
        case 'v':
            projectionType = abs(projectionType - 1);

            /// Change the distance of the projection
            if (projectionType == 0) {
                distance -= 2;
            } else {
                distance += 2;
            }
            break;
        case 27:
            exit(0);
            break;
        case 'w':
            incidence += 2;
            break;
        case 's':
            incidence -= 2;
            break;
        case 'z':
            distance++;
            break;
        case 'x':
            distance--;
            break;
        case 'd':
            azimuth += 5;
            break;
        case 'a':
            azimuth -= 5;
            break;
        case 'e':
            twist += 5;
            break;
        case 'q':
            twist -=5;
            break;
        default:
        break;
    }
}

static void time (int te) {
    int timent;
    int i;

    glutPostRedisplay();
    glutTimerFunc(100, time, 1);
}

void reshape (int w, int h) {
    glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity ();
}

void init () {
    glClearColor (0.0, 0.0, 0.0, 0.0);
    glShadeModel (GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
}

int main (int argc, char** argv) {
    puts("Change visualization: V");
    puts("Rotatition in X the grid: W / S");
    puts("Turn the grid: A / D");
    puts("Inclinate the grid: Z / X");
    puts("Zoom in/out: Z / X");
    puts("Exit: ESC");

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (450, 100);
    glutCreateWindow (argv[0]);

    init ();

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutTimerFunc( 10, time, 1);

    glutMainLoop();

    return 0;
}
