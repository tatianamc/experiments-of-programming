/*
 * laba01(3dgr).c
 *
 *  Created on: 14.02.2013
 *      Author: Igor
 */

#define GL_PI 3.1415f

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
#include <math.h>
#include <stdio.h>

//исходное положение и размер прямоугольника
GLfloat x1 = 0.0f;
GLfloat y11 = 0.0f;
GLfloat rsize = 25;
//величини шага в направлениях x и y
//число пикселей на которые на каждом шаге перемещается прямоугольник
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
//Отслеживание изменений ширины и высоты окна
GLfloat windowWidth;
GLfloat windowHeight;


GLfloat xRot;
GLfloat yRot;

int nodeCnt = 12;

double kNode[2][12] = {
		             {0.0,4.0,3.0,4.0,0.0,1.0, 1.0,3.0,2.0,3.0,1.0,2.0},
		             {0.0,0.0,3.0,6.0,6.0,3.0, 1.0,1.0,3.0,5.0,5.0,3.0}
};


void RenderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	//Записываем соотояние матрицы и выполняем поворот
	glTranslatef(0,0, -1);

	int i = 0;
	 glColor3f(1.0f,0.0f,0.0f);

				           glBegin(GL_LINES);
				               glVertex2f(-100,0);
				               glVertex2f(100,0);

				               glVertex2f(0,100);
				               glVertex2f(0,-100);

				               glColor3f(1.0f,1.0f,0.0f);
				               glVertex2f(50,50);
				               glVertex2f(20,-50);
				           glEnd();

	glColor3f(0.0f,1.0f,0.0f);

	glBegin(GL_LINE_LOOP);

					for (i = 0; i < nodeCnt - 6 ; i++) {
						glVertex2d(kNode[0][i],kNode[1][i]);
					}
			    glEnd();

			    glBegin(GL_LINE_LOOP);

			       		for (i = 6; i < nodeCnt ; i++) {
			       			glVertex2d(kNode[0][i],kNode[1][i]);
			       		}
			           glEnd();



	//xRot +=0.2f;
	//yRot +=0.2f;
	glutSwapBuffers();
	//glFlush();

}

void TimerFunction(int value)
{
	glutPostRedisplay();
	glutTimerFunc(33, TimerFunction, 1);
}
//Вызывется GLUT при изменении размеров окна
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 100.0f;
	//Предотвращаем деление на нуль
	if(h == 0)
		h=1;

	//Устанавливает поле просмотра с размерами окна
	glViewport(0,0,w,h);
	//Обновляет систему координат
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//С помощю плоскостей отчечения (левая, правая, нижняя, верхняя, ближняя, дальнаяя)
	//устанавливает объем отчения

	if(w<=h)
	{
		glOrtho(-nRange, nRange,
				-nRange*h/w,nRange*h/w,
				-nRange, nRange);
	}
	else
	{
		glOrtho(-nRange*w/h, nRange*w/h,
				-nRange,nRange,
				-nRange,nRange);
	}
    //обновляется стек матриц проекции модели
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void SetupRC(void)
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glColor3f(0.0f,1.0f,0.0f);
}

void move(float dx, float dy)
{
	int i;
	for(i=0;i<nodeCnt;i++)
		{
			kNode[0][i]+=dx;
			kNode[1][i]+=dy;
		}
}

void zoom(float z)
{
	int i;
		for(i=0;i<nodeCnt;i++)
			{
				kNode[0][i]*=z;
				kNode[1][i]*=z;
			}
}

void semetry(int sx, int sy)
{
	int i;
		for(i=0;i<nodeCnt;i++)
			{
				kNode[0][i]*=sx;
				kNode[1][i]*=sy;
			}
}

void semetryHHH()
{
	int i;
	float angle = atan(50.0/(50.0-20.0));

	for(i=0;i<nodeCnt;i++)
    {
	   kNode[0][i] = kNode[0][i]*cos(angle)-kNode[1][i]*sin(angle);
	   kNode[1][i] = kNode[0][i]*sin(angle)+kNode[1][i]*cos(angle);
    }
	/*for(i=0;i<nodeCnt;i++)
	{
	   kNode[0][i]*=1.0;
	   kNode[1][i]*=-1.0;
    }

	angle = atan(50.0/(50.0-30.0));

	for(i=0;i<nodeCnt;i++)
	{
		kNode[0][i] = kNode[0][i]*cos(angle)-kNode[1][i]*sin(angle);
		kNode[1][i] = kNode[0][i]*sin(angle)+kNode[1][i]*cos(angle);
	}*/
}

void rotate(double angle)
{
	int i;
	for(i=0;i<nodeCnt;i++)
	{
		kNode[0][i] = kNode[0][i]*cos(angle)-kNode[1][i]*sin(angle);
		kNode[1][i] = kNode[0][i]*sin(angle)+kNode[1][i]*cos(angle);
	}
}



void SpecialKeys(int key, int x, int y)
{

	if(key == GLUT_KEY_UP)
		move(0.0f,1.0f);

	if(key == GLUT_KEY_DOWN)
		move(0.0f,-1.0f);

	if(key == GLUT_KEY_LEFT)
		move(-1.0f,0.0f);

	if(key == GLUT_KEY_RIGHT)
		move(1.0f,0.0f);

	if(key == GLUT_KEY_F1)
		zoom(0.5f);

	if(key == GLUT_KEY_F2)
		zoom(2.0f);

	if(key == GLUT_KEY_F3)
			rotate(M_PI/6.0);

	if(key == GLUT_KEY_F4)
       rotate(-M_PI/6.0);

	if(key == GLUT_KEY_F5)
		semetry(-1,1);

	if(key == GLUT_KEY_F6)
		semetry(1,-1);

	if(key == GLUT_KEY_F7)
			semetryHHH();


	glutPostRedisplay();
}



int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutCreateWindow("Laba 01");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	//glutTimerFunc(33,TimerFunction,1);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();

	return 0;
}
