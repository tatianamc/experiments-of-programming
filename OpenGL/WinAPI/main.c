// команда сборки проекта для geany
// компилятор mingw
// gcc -Wall -o "%e" "%f" -lopengl32 -lglu32 -I"%d/include" -L"%d/lib" -lglut32

#include <GL/gl.h>
#include <GL/glu.h>
#include "glut.h"

typedef struct {
	float x;
	float y;
} Delta;

Delta delta;

float step = 0.05f;

float angle = 0.0f;

void keyPressed (unsigned char key, int x, int y) {

	switch(key) {
		case 'w':
			delta.y +=step;
			break;
		case 's':
			delta.y -=step;
			break;
		case 'a':
			delta.x -=step;
			break;
		case 'd':
			delta.x +=step;
			break;

        case '[':
			angle -=10;
			break;
		case ']':
			angle +=10;
			break;
	}

}

// Для обраотки клавишь стрелок
void arrow_keys ( int key, int x, int y )
{
  switch(key) {
		case GLUT_KEY_UP:
			delta.y +=step;
			break;
		case GLUT_KEY_DOWN:
			delta.y -=step;
			break;
		case GLUT_KEY_LEFT:
			delta.x -=step;
			break;
		case GLUT_KEY_RIGHT:
			delta.x +=step;
			break;
	}
}



void reshape(int w, int h)
{
	/*glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();*/

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливаем фоновый цвет на черный
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST); // включаем тест глубины
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) w / (float) h, 0.1f, 100.0f); // настраиваем трехмерную перспективу
    glMatrixMode(GL_MODELVIEW); // переходим в трехмерный режим

     /*
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable (GL_BLEND);*/

}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


	glTranslatef(0.0f, 0.0f, -7.0f);
	// ВАШ КОД ЗДЕСЬ
	//
    glColor3f(0.0, 1.0, 0.0);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glRotatef(angle,0,1,0);

    glBegin(GL_TRIANGLES);

	glVertex3f(1.0f + delta.x, 1.0f + delta.y, 0);
	glVertex3f(-1.0f + delta.x, 1.0f + delta.y, 0);
	glVertex3f(0.0f + delta.x, -1.0f + delta.y, 0);

	glVertex3f(1.0f + delta.x, 1.0f + delta.y, 0);
	glVertex3f(-1.0f + delta.x, 1.0f + delta.y, 0);
	glVertex3f(0.0f + delta.x, 0.0f + delta.y, 1.0f);


	glVertex3f(1.0f + delta.x, 1.0f + delta.y, 0);
	glVertex3f(0.0f + delta.x, 0.0f + delta.y, 1.0f);
	glVertex3f(0.0f + delta.x, -1.0f + delta.y, 0);


	glVertex3f(0.0f + delta.x, 0.0f + delta.y, 1.0f);
	glVertex3f(-1.0f + delta.x, 1.0f + delta.y, 0);
	glVertex3f(0.0f + delta.x, -1.0f + delta.y, 0);

    glEnd();

/*
	glBegin(GL_LINES);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(1.0f + delta.x, 1.0f + delta.y, 2);
	glVertex3f(-1.0f + delta.x, 1.0f + delta.y, 2);

	glVertex3f(1.0f + delta.x, 1.0f + delta.y, 2);
	glVertex3f(1.0f + delta.x, -1.0f + delta.y, 2);

	glVertex3f(-1.0f + delta.x, -1.0f + delta.y, 2);
	glVertex3f(1.0f + delta.x, -1.0f + delta.y, 2);

	glVertex3f(-1.0f + delta.x, 1.0f + delta.y, 2);
	glVertex3f(-1.0f + delta.x, -1.0f + delta.y, 2);
	glEnd();
*/
	//
	// КОНЕЦ
	//
	glutSwapBuffers();
}


int main (int argc, char * argv[])
{
	delta.x = 0;
	delta.y = 0;

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);

	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL my first program");

	glutReshapeFunc(reshape);
	glutDisplayFunc(display);

	// Для работы анимации
	glutIdleFunc( display );
	// Обработчик нажатия клавишь
	glutKeyboardFunc(keyPressed);

	// Включить возможность ловить клавиши
	glutSpecialFunc( arrow_keys );

	glutMainLoop();

	return 0;
}
