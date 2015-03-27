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
		
		void addSpeed() {
			speed+=speedStep;
		}
		
		
		void slowSpeed() {
			speed-=speedStep;
		}
		
		
		void keyLeftDown(bool isPressed) {
			isKeydown[0] = isPressed;
		}
		
		
		void keyRightDown(bool isPressed) {
			isKeydown[1] = isPressed;
		}
		
		void draw() {
			
			glPushMatrix();
			
			glTranslatef(posX, posY, -defoultZ);
			glRotatef(direction,0.0f,0.0f,1.0f);
			glBindTexture(GL_TEXTURE_2D, texture[1]);			
			
			glBegin(GL_QUADS);
			glColor4f(1.0f,1.0f,1.0f,1.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f( carHalfWidth,  carHalfHeigh, z);    
			glTexCoord2f(0.0f, 0.0f); glVertex3f( -carHalfWidth,  carHalfHeigh, z);    
			glTexCoord2f(0.0f, 1.0f); glVertex3f( -carHalfWidth,  -carHalfHeigh, z);   
			glTexCoord2f(1.0f, 1.0f); glVertex3f( carHalfWidth,  -carHalfHeigh, z);		
			glEnd();
			
			glTranslatef(-posX, -posY, defoultZ);
			
			glPopMatrix();
			updatePosition();
		}
		
		Car() {
			x = 0;
			y = 0;
			z = 2.001f;
			speed = 0.0f;
			posX = 0.3f;
			posY = 1.0f;
			direction = 0;
			
			speedStep = 0.005f;
			defoultZ = 7;
			
			carHalfWidth = 0.25f;
			carHalfHeigh = 0.15f;
		} 
		
		private:
			float x;
			float y;
			float z;
			float speed;
			float direction;
		
			float speedStep;
			float carHalfWidth;
			float carHalfHeigh;
			float defoultZ;
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
				
				posX -= speed*cos(toRad(direction));
				posY -= speed*sin(toRad(direction));
				setH();
			}
			
			// Update position car by Z
			void setH() {

				// Square right entrence		
				bool rt = (-1.5<posX&&posX<-0.775)&&(1.1<posY&&posY<1.8);
				// Square left entrence	
				bool rd = (-2.43<posX&&posX<-1.59)&&(-1.59<posY&&posY<0.62);
				// Check, if car on bridge
				bool md = (-2.43<posX&&posX<-0.775)&&(0.35<posY&&posY<1.2);
				
				if((rt||rd)&&(!md)) {
					z = 2.003;
				} else {
					if(!md) {
						z = 2.001;
					}
				}
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
    
    glTranslatef(-1.62f, 0.95f, -7.0f);    
    glBindTexture(GL_TEXTURE_2D, texture[2]);
    glBegin(GL_POLYGON);
    
    glColor4f(1.0f,1.0f,1.0f,1.0f);
    
    
    // Draw Bridgge
    // Точки вычисляются исходя из пропорций экрана, и размеров объекта
    // на экране
    
    glTexCoord2f(1.0f, 0.0f); 
    glVertex3f(0.568f,  0.582f, 2.002f);
    
    glTexCoord2f(0.8f, 0.0f); 
    glVertex3f(0.3f,  0.582f, 2.002f);
    
    glTexCoord2f(0.0f, 1.0f); 
    glVertex3f(-0.568f,  -0.582f, 2.002f);
    
    glTexCoord2f(0.5f, 1.0f); 
    glVertex3f(0.0f,  -0.582f, 2.002f);
    
    glTexCoord2f(0.5f, 1.0f); 
    glVertex3f(0.568f,  0.1f, 2.002f);
    
    glEnd();
    
    glLoadIdentity();
}

GLuint loadTextureFromBMP24(std::string path) {
	GLuint tex;
	
	//создать указатель для текстуры
    SDL_Surface *TextureImage; 

    if (( TextureImage = SDL_LoadBMP( path.c_str() ))) {
	    glGenTextures( 1, &tex ); //создать текстуру
	    glBindTexture( GL_TEXTURE_2D, tex ); //генирация типа и данных для текстуры
	    /* сгенерировать текстуры */
	    glTexImage2D( GL_TEXTURE_2D, 0, 3, TextureImage->w,TextureImage->h, 0, GL_BGR,GL_UNSIGNED_BYTE, TextureImage->pixels );
	    /* линейный фильтор */
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
     } 
     
    // исвободить память 
    if ( TextureImage )
	    SDL_FreeSurface( TextureImage );  
	    
	return tex;
}

GLuint loadTextureFromBMP32(std::string path) {
	GLuint tex;
	
	SDL_Surface *TextureImage;   
    if (( TextureImage = SDL_LoadBMP( path.c_str() ))) {
		glGenTextures( 1, &tex ); //создать текстуру
	    glBindTexture( GL_TEXTURE_2D, tex ); //генирация типа и данных для текстуры
	    // сгенерировать текстуры 
	    glTexImage2D( GL_TEXTURE_2D, 0,4, TextureImage->w,TextureImage->h, 0, GL_RGBA,GL_UNSIGNED_INT_8_8_8_8, TextureImage->pixels );
		// линейный фильтор 
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
	    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
     }
    // исвободить память 
    if ( TextureImage )
	    SDL_FreeSurface( TextureImage );
	    
	return tex;
}

void LoadGLTextures( ) {
	texture[0] = loadTextureFromBMP24("textures/track.bmp");
	texture[1] = loadTextureFromBMP32("textures/car.bmp");
	texture[2] = loadTextureFromBMP32("textures/most.bmp");
}
