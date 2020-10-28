#include <GL/glut.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <math.h>
#include <stdio.h>

using namespace std;

// keycodes W and S
#define VK_W 0x57
#define VK_S 0x53

// proportions of the screen
int width = 1000;
int height = 500;
int interval = 1000 / 60;

// score
int score_1 = 0;
int score_2 = 0;

// variables for the rectangles
int rectangle_width = 20;
int rectangle_height = 80;
int rectangle_velocity = 5;

// position of rectangle 1
float rectangle1_x = 10.0;
float rectangle1_y = 50.0;

// position of rectangle 2
float rectangle2_x = width - rectangle_width - 10;
float rectangle2_y = 50;

// variables of the ball
float ball_pos_x = width / 2;
float ball_pos_y = height / 2;
float ball_dir_x = -1.0;
float ball_dir_y = 0.0;
int ball_size = 15;
int ball_velocity = 5;

void drawText(float x, float y, const char *string) {
	int j = strlen(string);
	glColor3f(1.0, 1.0, 1.0);
	glRasterPos2f(x, y);

	for(int i = 0; i < j; i++) {
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, string[i]);
	}
}

void drawRectangle(float x, float y, float width, float height) {
    glBegin(GL_QUADS);
        glVertex2f(x, y);
        glVertex2f(x + width, y);
        glVertex2f(x + width, y + height);
        glVertex2f(x, y + height);
    glEnd();
}

// cast int to string
string int2str(int x) {
    stringstream ss;
    ss << x;
    return ss.str( );
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // display the score
    string pontuacao = int2str(score_1) + " - " + int2str(score_2);
    const char * texto = pontuacao.c_str();
    drawText(width / 2 - 10, height - 20, texto);

    // red rectangle
    glColor3f(1.0, 0.0, 0.0);
    drawRectangle(rectangle1_x, rectangle1_y, rectangle_width, rectangle_height);

    // blue rectangle
    glColor3f(0.0, 0.0, 1.0);
    drawRectangle(rectangle2_x, rectangle2_y, rectangle_width, rectangle_height);

    // ball
    glColor3f(1.0, 1.0, 1.0);
    drawRectangle(ball_pos_x, ball_pos_y, ball_size, ball_size);

    glutSwapBuffers();
}

void keyboard() {
    // movemente of the rectangle 1 (red)
    if (GetAsyncKeyState(VK_W) && rectangle1_y < height-75) {
        rectangle1_y += rectangle_velocity;
    }
    if (GetAsyncKeyState(VK_S) && rectangle1_y > 0) {
        rectangle1_y -= rectangle_velocity;
    }

    // movemente of the rectangle 2 (blue)
    if (GetAsyncKeyState(VK_UP) && rectangle2_y < height-75) {
        rectangle2_y += rectangle_velocity;
    }
    if (GetAsyncKeyState(VK_DOWN) && rectangle2_y > 0) {
        rectangle2_y -= rectangle_velocity;
    }
}

void atualizaBola() {
    // move the ball
    ball_pos_x += ball_dir_x * ball_velocity;
    ball_pos_y += ball_dir_y * ball_velocity;

    /*  game logic */
    if (ball_pos_x < rectangle1_x + rectangle_width &&
        ball_pos_x > rectangle1_x &&
        ball_pos_y < rectangle1_y + rectangle_height &&
        ball_pos_y > rectangle1_y) {

        float direcao_vertical = ((ball_pos_y - rectangle1_y) / rectangle_height) - 0.5;
        printf("%.1f = ((%.1f - %.1f) / %d) - 0.5\n", direcao_vertical, ball_pos_y, rectangle1_y, rectangle_height);
        ball_dir_x = fabs(ball_dir_x); // positive direction (right side)
        ball_dir_y = direcao_vertical;
    }

    if (ball_pos_x > rectangle2_x &&
        ball_pos_x < rectangle2_x + rectangle_width &&
        ball_pos_y < rectangle2_y + rectangle_height &&
        ball_pos_y > rectangle2_y) {

        float direcao_vertical = ((ball_pos_y - rectangle2_y) / rectangle_height) - 0.5;
        ball_dir_x = -fabs(ball_dir_x); // negative direction (left side)
        ball_dir_y = direcao_vertical;
    }

    // player 2 scored
    if (ball_pos_x < 0) {
        ++score_2;
        // reset the ball
        ball_pos_x = width / 2;
        ball_pos_y = height / 2;
        ball_dir_x = fabs(ball_dir_x);
        ball_dir_y = 0; // reset vertical
    }

    // player 1 scored
    if (ball_pos_x > width) {
        ++score_1;
        // reseta ball
        ball_pos_x = width / 2;
        ball_pos_y = height / 2;
        ball_dir_x = -fabs(ball_dir_x);
        ball_dir_y = 0; // reseta vertical
    }

    // hit the top of screen
    if (ball_pos_y > height) {
        ball_dir_y = -fabs(ball_dir_y);
    }

    // hit the bottom of screen
    if (ball_pos_y < 1) {
        ball_dir_y = fabs(ball_dir_y);
    }
}

void update(int value) {
    // key mappings
    keyboard();

    // refresh the ball
    atualizaBola();

    // screen update
    glutTimerFunc(interval, update, 0);

    // recall the display func
    glutPostRedisplay();
}

void enable2D(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, 0.0, height, 0.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(width, height);
    glutCreateWindow("Pong");
    glutDisplayFunc(display);
    glutTimerFunc(interval, update, 0);

    enable2D(width, height);
    glColor3f(1.0, 1.0, 1.0);
    glutMainLoop();

    return 0;
}
