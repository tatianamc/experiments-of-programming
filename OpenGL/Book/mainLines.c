/*
 * mainLines.c
 *
 *  Created on: 02.01.2013
 *      Author: Igor
 */

//gcc -Wall -o "%e" "%f" -opengl32 -glut32 -glu32
#define GL_PI 3.1415f

#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>
#include <math.h>
#include <stdio.h>

//величини шага в направлени€х x и y
//число пикселей на которые на каждом шаге перемещаетс€ пр€моугольник
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
//ќтслеживание изменений ширины и высоты окна
GLfloat windowWidth;
GLfloat windowHeight;


GLfloat xRot;
GLfloat yRot;

void RenderScene(void)
{
	GLfloat y;
	GLint factor = 1;
	GLushort pattern = 0x5555;

	glClear(GL_COLOR_BUFFER_BIT);
		//«аписываем соото€ние матрицы и выполн€ем поворот
	glPushMatrix();
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot, 0.0f,1.0f,0.0f);

	glEnable(GL_LINE_STIPPLE);

	for(y = -90.0f; y<90.0f; y+=20.0f)
	{
		glLineStipple(factor, pattern);

		glBegin(GL_LINES);
			glVertex2f(-80.0f,y);
			glVertex2f(80.0f,y);
		glEnd();

		factor++;
	}

	glDisable(GL_LINE_STIPPLE);
	glutSwapBuffers();
}

void RenderScene2(void)
{
	GLfloat y;
	GLfloat fSizes[2];
	GLfloat fCurrSize;

	glClear(GL_COLOR_BUFFER_BIT);
		//«аписываем соото€ние матрицы и выполн€ем поворот
	glPushMatrix();
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot, 0.0f,1.0f,0.0f);

	glGetFloatv(GL_LINE_WIDTH_RANGE,fSizes);
	fCurrSize = fSizes[0];

	for(y = -90.0f; y<90.0f; y+=20.0f)
	{
		glLineWidth(fCurrSize);
		glBegin(GL_LINES);
			glVertex2f(-80.0f,y);
			glVertex2f(80.0f,y);
		glEnd();

		fCurrSize +=1.0f;
	}

	glutSwapBuffers();
}

void RenderScene1(void)
{
	GLfloat x,y,z, angle;
	//«апомним диапазон размеров поддерживаемых точек
	//GLfloat sizes[2];
	//«апоминаем поддерживаемый инкреент размеров точек
	//GLfloat step;
	//«аписываем размер текущих точек
	//GLfloat curSize;

	glClear(GL_COLOR_BUFFER_BIT);
	//«аписываем соото€ние матрицы и выполн€ем поворот
	glPushMatrix();
	glRotatef(xRot,1.0f,0.0f,0.0f);
	glRotatef(yRot, 0.0f,1.0f,0.0f);

	//ѕолучаем диапазон размеров поддерживаемых точек и размер шага
	//glGetFloatv(GL_POINT_SIZE_RANGE,sizes);
	//glGetFloatv(GL_POINT_SIZE_GRANULARITY,&step);
	//задаем исходный размер точки
	//curSize = sizes[0];
	z = 0.0f;

	glBegin(GL_LINES);
		for (angle = 0.0f; angle <= GL_PI*3.0f ; angle +=(GL_PI/20.0f)) {
			//верхни€ половина окружности
			x = 50.0f*sin(angle);
			y = 50.0f*cos(angle);
			glVertex3f(x,y,z);

			//Ќижна€ половина окружности
			x = 50.0f*sin(angle+GL_PI);
			y = 50.0f*cos(angle+GL_PI);
			glVertex3f(x,y,z);

			//«адаем размер точки перед указанием примитива
			//glPointSize(curSize);
			//рисуем точку
			//glBegin(GL_POINTS);

			//glEnd();
			z +=0.5f;
			//curSize +=step;
		}

    glEnd();
	//¬останавливаем преобразовани€
    glPopMatrix();

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
//¬ызыветс€ GLUT при изменении размеров окна
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat nRange = 100.0f;
	//ѕредотвращаем деление на нуль
	if(h == 0)
		h=1;

	//”станавливает поле просмотра с размерами окна
	glViewport(0,0,w,h);
	//ќбновл€ет систему координат
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//— помощю плоскостей отчечени€ (лева€, права€, нижн€€, верхн€€, ближн€€, дальна€€)
	//устанавливает объем отчени€

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
    //обновл€етс€ стек матриц проекции модели
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void SetupRC(void)
{
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	glColor3f(0.0f,1.0f,0.0f);
}

void SpecialKeys(int key, int x, int y)
    {
	GLfloat stepSize = 0.5f;



	if(key == GLUT_KEY_UP)
		yRot += stepSize;

	if(key == GLUT_KEY_DOWN)
		yRot -= stepSize;

	if(key == GLUT_KEY_LEFT)
		xRot -= stepSize;

	if(key == GLUT_KEY_RIGHT)
		xRot += stepSize;


	glutPostRedisplay();
	}

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutCreateWindow("GL 3.1");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	//glutTimerFunc(33,TimerFunction,1);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();

	return 0;
}




