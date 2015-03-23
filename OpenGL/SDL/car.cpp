// g++ main.cpp -o cube -lSDL2 -lGL -lGLU
#include <SDL2/SDL.h> 
#include <GL/gl.h> 
#include <GL/glu.h> 
#include <math.h>

#include <iostream> 

using namespace std;
GLuint texture[6];

class Car {
	public:
		float x;
		float y;
		float speed;
		float direction;
		
		void addSpeed() {
			speed+=0.005f;
		}
		
		void slowSpeed() {
			speed-=0.005f;
		}
		
		void keyLeftDown(bool isPressed) {
			isKeydown[0] = isPressed;
		}
		
		void keyRightDown(bool isPressed) {
			isKeydown[1] = isPressed;
		}
		
		
		void draw() {
			
			glPushMatrix();
			
			glTranslatef(0.3f-posX, 1.0f-posY, -7.0f);
			glRotatef(direction,0.0f,0.0f,1.0f);
			
			glBindTexture(GL_TEXTURE_2D, texture[1]);			
			glBegin(GL_QUADS);
			glColor4f(1.0f,1.0f,1.0f,1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.25f,  0.15f, 3.0f);    
			glTexCoord2f(0.0f, 0.0f); glVertex3f( -0.25f,  0.15f, 3.0f);    
			glTexCoord2f(0.0f, 1.0f); glVertex3f( -0.25f,  -0.15f, 3.0f);   
			glTexCoord2f(1.0f, 1.0f); glVertex3f( 0.25f,  -0.15f, 3.0f);		
			glEnd();
			
			glTranslatef(-(0.3f-posX), -(1.0f-posY), +7.0f);
			
			glPopMatrix();
			
			updatePosition();
		}
		
		Car() {
			x = 0;
			y = 0;
			speed = 0.0f;
			posX = 0;
			posY = 0;
			direction = 0;
			
		}
		
		private:
			float posX;
			float posY;
			
			bool isKeydown[2];
			
			float toRad(float gradus) {
				return (gradus*M_PI)/180.0;
			}
			
			void turnLeft() {
				direction+=180*speed;
			}
			
			void turnRight() {
				direction-=180*speed;
			}
			
			void updatePosition() {
				
				if(isKeydown[0]){
					turnLeft();
				}
				if(isKeydown[1]){
					turnRight();
				}
				
				cout<<direction;
				cout<<" ";
				cout<<toRad(direction) ;
				cout<<"\n";
				posX += speed*cos(toRad(direction));
				posY += speed*sin(toRad(direction));
			}
			
};

// задаем окно для SDL
SDL_Window *window; 
 
const int width = 640; 
const int height = 480;
 
void drawBackground();
void LoadGLTextures();

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
     
    glEnable(GL_ALPHA_TEST);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable (GL_BLEND);
}

int main(int argc, char *argv[]){
	 
	init();
 
    bool running = true;

    while(running) { 
       
        // события SDL
        SDL_Event event;     
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
                        case SDLK_LEFT:
							car.keyLeftDown(true);
							break;
						case SDLK_RIGHT:
							car.keyRightDown(true);
							break;
						case SDLK_UP:
							car.addSpeed();
							break;
						case SDLK_DOWN:
							car.slowSpeed();
							break;
                    }
                break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym){  
                        
                        case SDLK_LEFT:
							car.keyLeftDown(false);
							break;
						case SDLK_RIGHT:
							car.keyRightDown(false);
							break;
                    }
                break;
            } 
        }
 
		// Rendering
        drawBackground(); 
        // Рисуем машину
        car.draw();
        // обновляем экран
        glFlush();
        SDL_GL_SwapWindow(window);
    }
 
	// завершаем работу SDL и выходим
    SDL_Quit(); 
    return 0;
}

void drawBackground(){
	
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    
    glTranslatef(0.0f, 0.0f, -7.0f);    
    glBindTexture(GL_TEXTURE_2D, texture[0]);
    glBegin(GL_QUADS);
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 2.84f,  2.2f, 2.0f);   
	glTexCoord2f(0.0f, 0.0f); glVertex3f( -2.84f,  2.2f, 2.0f);   
	glTexCoord2f(0.0f, 1.0f); glVertex3f( -2.84f,  -2.2f, 2.0f);
	glTexCoord2f(1.0f, 1.0f); glVertex3f( 2.84f,  -2.2f, 2.0f);  
    glEnd();
    glLoadIdentity();
}

void LoadGLTextures( ) {
	//создать указатель для текстуры
    SDL_Surface *TextureImage; 

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
