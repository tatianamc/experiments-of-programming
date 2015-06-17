/*
 * main.c
 *
 *  Created on: 31.12.2012
 *      Author: Igor
 */
//gcc -Wall -o "%e" "%f" -opengl32 -glut32 -glu32
#include <GL\gl.h>
#include <GL\glu.h>
#include <GL\glut.h>

void RenderScene(void)
{
	//Очищаем окно
	glClear(GL_COLOR_BUFFER_BIT);
	//Выбор текущего цвета
	glColor3f(1.0f,0.0f,0.0f);
	//Рисует прямоугольник закрашенный текущим цветом
	glRectf(-25.0f,25.0f,25.0f,-25.0f);
	//Очищает очередь текущих команда
	glFlush();
}

//Вызывется GLUT при изменении размеров окна
void ChangeSize(GLsizei w, GLsizei h)
{
	GLfloat aspectRatio;
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
	aspectRatio = (GLfloat)w/(GLfloat)h;
	if(w<=h)
		glOrtho(-100.0, 100.0,-100.0/aspectRatio,100.0/aspectRatio,
				1.0, -1.0);
	else
		glOrtho(-100.0 * aspectRatio, 100.0 * aspectRatio,
				-100.0,100.0,1.0,-1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}

void SetupRC(void)
{
	glClearColor(0.0f,0.0f,1.0f,1.0f);
}

int main(void)
{
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutCreateWindow("GLRect");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();



	return 0;
}

