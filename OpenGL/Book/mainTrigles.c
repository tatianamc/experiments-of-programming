/*
 * mainTrigles.c
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
#include <windows.h>

//величини шага в направлениях x и y
//число пикселей на которые на каждом шаге перемещается прямоугольник
GLfloat xstep = 3.0f;
GLfloat ystep = 3.0f;
//Отслеживание изменений ширины и высоты окна
GLfloat windowWidth;
GLfloat windowHeight;

GLfloat xRot;
GLfloat yRot;
BOOL bCull= FALSE;
BOOL bDepth = FALSE;
BOOL bOutLine = FALSE;

void RenderScene(void)
{
	GLfloat x, y , angle; //хранятся координаты и углы
	int iPivot = 1; 	  //Используется, чтобы отмечать
						  //чередующиеся цвета
	//Очищаем окно и буфер глубины
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Включаем отбор, если установлена метка
	if(bCull)
		glEnable(GL_CULL_FACE);
	else
		glDisable(GL_CULL_FACE);

	//Если установлена метка, активируем проверку глубины
	if(bDepth)
		glEnable(GL_DEPTH_TEST);
	else
		glDisable(GL_DEPTH_TEST);

	//Если установлена метка ресуем заднюю сторону
	//в форме каркаса
	if(bOutLine)
		glPolygonMode(GL_BACK,GL_LINE);
	else
		glPolygonMode(GL_BACK,GL_FILL);

	//Записываем состояние матрицы и выполняем поворот
	glPushMatrix();
	glRotatef(xRot, 1.0, 0.0f, 0.0f);
	glRotatef(yRot, 0.0f, 1.0f, 0.0f);

	// Начинаем веер треугольников
	glBegin(GL_TRIANGLE_FAN);
	//Вершина конуса является общей вершиной веера. Перемещаясь
	// вверх по оси z, в вместо окружности получаем конус
	glVertex3f(0.0f, 0.0f, 75.0f);
	//По циклу проходим окружность и задаем четные точки вдоль
	// окружности кк вершины веера треугольников
	for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
	{
		// Расчитываем положения x и y следующей вершины
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);
		//Чередуем красный и зеленый цвет
		if((iPivot%2)==0)
		{
			glColor3f(0.0f,1.0f,0.0f);
		}
		else
		{
			glColor3f(1.0f, 0.0f, 0.0f);
		}

		// Увеличиваем pivot на 1, чтобы в следующий раз
		// Изменить цвет
		iPivot++;
		// Задаем следующую вершину веера треугольникав
		glVertex2f(x,y);
	}
	//Рисуем веер, имитирующий конус
	glEnd();

	//Начинаем новый веер треугольников, имитирующий основание
	//конуса
	glBegin(GL_TRIANGLE_FAN);
	// Центром веера является начало координат
	glVertex2f(0.0f, 0.0f);
	for(angle = 0.0f; angle < (2.0f*GL_PI); angle += (GL_PI/8.0f))
	{
		//Рассчитываем координаты x и y следующей вершины
		x = 50.0f * sin(angle);
		y = 50.0f * cos(angle);
		//Чередуем красный и зеленый цвета
		if((iPivot%2)==0)
			glColor3f(0.0f, 0.0f, 1.0f);
		else
			glColor3f(1.0f,1.0f,0.0f);

		//увеличиваем pivot на единицу чтобы в следующий разм
		// поменять цвета
		iPivot++;
		// Задаем следующую вершину веера треугольников
		glVertex2f(x,y);
	}
	//Рисуем веер, имитирующий основание конуса
	glEnd();
	// Востанавливаем преобразованя
	glPopMatrix();
	//Oчищаем стек команд рисования
	glFlush();

	glutSwapBuffers();
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
	//учтанавливаем черный фор
	glClearColor(0.0f,0.0f,0.0f,1.0f);
	//цвет рисования
	glColor3f(0.0f,1.0f,0.0f);
	//Цвет модели затенения выбирается неструктурированным
	glShadeModel(GL_FLAT);
	//Многоугольники с обходом по часовой стрелке считаются
	//направленными вперед; поведение изменено на обратное,
	//поскольку мы используем вееры треугольников
	glFrontFace(GL_CW);
}

void SpecialKeys(int key, int x, int y)
    {
	GLfloat stepSize = 0.9f;


	switch(key)
	{
		case GLUT_KEY_UP:
			yRot += stepSize;
			break;
		case GLUT_KEY_DOWN:
			yRot -= stepSize;
			break;
		case GLUT_KEY_LEFT:
			xRot -= stepSize;
			break;
		case  GLUT_KEY_RIGHT:
			xRot += stepSize;
			break;
		case GLUT_KEY_F1:
			bCull= !bCull;
			break;
		case GLUT_KEY_F2:
			bDepth=!bDepth;
			break;
		case GLUT_KEY_F3:
			bOutLine = !bOutLine;
			break;
	}

	glutPostRedisplay();
	}

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutCreateWindow("GL TRIGLES");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	//glutTimerFunc(33,TimerFunction,1);
	glutSpecialFunc(SpecialKeys);
	glutMainLoop();

	return 0;
}

