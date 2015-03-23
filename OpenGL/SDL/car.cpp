// g++ main.cpp -o cube -lSDL2 -lGL -lGLU

#include <SDL2/SDL.h> // Библиотека SDL 2
#include <GL/gl.h> // Библиотека OpenGL
#include <GL/glu.h> // Библиотека GLU
#include <SDL2/SDL_image.h> 

#include <iostream> // стандартная библиотека ввода-вывода в C++

using namespace std;

class Car {
	public:
		float x;
		float y;
		
		void draw() {
						
			glBegin(GL_QUADS);
			glColor4f(1.0f,1.0f,1.0f,1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5f,  0.3f, 3.0f);   //левый нижний 
			glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.0f,  0.3f, 3.0f);    //левый верхний
			glTexCoord2f(0.0f, 1.0f); glVertex3f( 0.0f,  0.0f, 3.0f);  //правый верхинй 
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.5f,  0.0f, 3.0f);		
			glEnd();
		}
		
		Car() {
			x = 0;
			y = 0;
		}
};

 
SDL_Window *window; // задаем окно для SDL
 
const int width = 640; // ширина окна
const int height = 480; // высота окна
 
void drawBackground();
void LoadGLTextures();
GLuint texture[6]; /* массив текстур */

Car car;



void init(){
    // Инициализация SDL
    if ( SDL_Init(SDL_INIT_VIDEO) < 0 ){ 
        cout << "Unable to init SDL, error: " << SDL_GetError() << endl;
        exit(1);
    } 
    // Включаем двойной буфер, настраиваем цвета
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 6);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
 
    // Создаем окно с заголовком "Cube", размером 640х480 и расположенным по центру экрана.
    window = SDL_CreateWindow("Cars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
    SDL_GL_CreateContext(window);
    //SDL_GLContext glcontext = SDL_GL_CreateContext(window); // создаем контекст OpenGL
    if(window == NULL){ // если не получилось создать окно, то выходим 
        exit(1);
    }
    // Инициализация OpenGL
 
	LoadGLTextures();
	glEnable( GL_TEXTURE_2D ); //включить карту текстур
	
	
	
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // устанавливаем фоновый цвет на черный
    glClearDepth(1.0);
    glDepthFunc(GL_LESS);
    glEnable(GL_DEPTH_TEST); // включаем тест глубины
    glShadeModel(GL_SMOOTH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float) width / (float) height, 0.1f, 100.0f); // настраиваем трехмерную перспективу
    glMatrixMode(GL_MODELVIEW); // переходим в трехмерный режим
    
    
    
    
   // glEnable(GL_BLEND_SRC);      
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_ONE, GL_ONE_MINUS_SRC_ALPHA); 
    glEnable (GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

int main(int argc, char *argv[]){
	 
	init(); // инициализация
 
    bool running = true;

    while(running) { 
       
        SDL_Event event; // события SDL
       
        while ( SDL_PollEvent(&event) ){ // начинаем обработку событий
            switch(event.type){ // смотрим:
                case SDL_QUIT: // если произошло событие закрытия окна, то завершаем работу программы
                    running = false;
                break;
 
                case SDL_KEYDOWN: // если нажата клавиша
                    switch(event.key.keysym.sym){ // смотрим какая
                        case SDLK_ESCAPE: // клавиша ESC
                            running = false; // завершаем работу программы
                        break;
                    }
                break;
            } 
        }
 
        // пока программа запущена изменяем углы поворота, тем самым вращая куб
        drawBackground(); // рисуем сам куб с текущими углами поворота
        
        // обновляем экран
        glFlush();
        SDL_GL_SwapWindow(window);
    }
 
    SDL_Quit(); // завершаем работу SDL и выходим
    return 0;
}
//textures/track.bmp
void drawBackground(){
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -7.0f);    // Сдвинуть вглубь экрана
    
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    
    glBegin(GL_QUADS);
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 2.84f,  2.2f, 2.0f);   //левый нижний 
	glTexCoord2f(0.0f, 0.0f); glVertex3f( -2.84f,  2.2f, 2.0f);    //левый верхний
	glTexCoord2f(0.0f, 1.0f); glVertex3f( -2.84f,  -2.2f, 2.0f);  //правый верхинй 
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 2.84f,  -2.2f, 2.0f);
        
    glEnd();
    
 
 
    glBindTexture(GL_TEXTURE_2D, texture[1]);
    car.draw();
    
 
    glLoadIdentity();
    // Draw car 
    
  
/*
    glBegin(GL_QUADS);                  // Рисуем куб
    
    glColor3f(1.0f, 0.0f, 0.0f);        // Красная сторона (Передняя)
    glVertex3f( 1.0f,  1.0f, 1.0f);     // Верхний правый угол квадрата
    glVertex3f(-1.0f,  1.0f, 1.0f);     // Верхний левый
    glVertex3f(-1.0f, -1.0f, 1.0f);     // Нижний левый
    glVertex3f( 1.0f, -1.0f, 1.0f);     // Нижний правый
 
    glEnd();                            // Закончили квадраты    
 */
}

void LoadGLTextures( ) {
    SDL_Surface *TextureImage; //создать указатель для текстуры

    /* Загрузка bmp изображения и выход в случае ошибки*/
    if (( TextureImage = SDL_LoadBMP( "textures/track.bmp" ))) {
	    glGenTextures( 1, &texture[0] ); //создать текстуру
	    glBindTexture( GL_TEXTURE_2D, texture[0] ); //генирация типа и данных для текстуры
	    /* сгенерировать текстуры */
	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage->w,TextureImage->h, 0, GL_BGR,GL_UNSIGNED_BYTE, TextureImage->pixels );
	    /* линейный фильтор */
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
     }
    // исвободить память 
    if ( TextureImage )
	    SDL_FreeSurface( TextureImage );  
	    
	 SDL_Surface *TextureImage1;   
	 /* Загрузка bmp изображения и выход в случае ошибки*/
    if (( TextureImage1 = SDL_LoadBMP( "textures/car.bmp" ))) {
		
		

		glGenTextures( 1, &texture[1] ); //создать текстуру
	    glBindTexture( GL_TEXTURE_2D, texture[1] ); //генирация типа и данных для текстуры
	    /* сгенерировать текстуры */
	    glTexImage2D( GL_TEXTURE_2D, 0,4, TextureImage1->w,TextureImage->h, 0, GL_RGBA,GL_UNSIGNED_INT_8_8_8_8, TextureImage1->pixels );
	    /* линейный фильтор */
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
     }
    // исвободить память 
    if ( TextureImage1 )
	    SDL_FreeSurface( TextureImage1 );  
}
