//текст линковщика 
// g++ -Wall -o "%e" "%f" -mwindows -lopengl32 -lglu32
#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <stdio.h>

#define GLvoid void
//#define CDS_FULLSCREEN 4

HGLRC hRC = NULL; //постоянный контекст рендеринга
HDC hDC = NULL; //приватный контекст устройства GDi
HWND hWnd = NULL; //Здесь будет хранится дескриптор окна
HINSTANCE hInstance; //Дискриптор приложения

bool keys[256]; //для операций с клавиатурой
bool active = TRUE; //флаг активности окна
bool fullscreen = TRUE; //флаг полноэкранного режима

LRESULT CALLBACK WndProc(HWND, UINT,WPARAM, LPARAM);//прототип функции WndProc
//изменение размера и инициализация окна GL
GLvoid resizeGLScene(GLsizei width, GLsizei height)
{
	if(height ==0) //предотвращение деления на ноль
	{
		height = 1;
	}
	/*сброс текущей области вывода*/
	glViewport(0,0,width,height);
	//выбор матрицы проекций
	glMatrixMode(GL_PROJECTION);
	//сброс матрицы проекции
	glLoadIdentity();
	//вычисление соотношения геометрических размеров для окна
	gluPerspective(45.0f, (GLfloat)width/(GLfloat)height,0.1f, 100.0f);
	//выбор матрицы вида модели
	glMatrixMode(GL_MODELVIEW);
	//сброс матрицы вида модели
	glLoadIdentity();
}

//все установки OpenGL происходят здесь
int InitGL(GLvoid) 
{
	//разрешить цветовое сглаживание
	glShadeModel(GL_SMOOTH);
	//Очистка в установленный цвет RGB alpha(прозрачность)
	glClearColor(0.0f,0.0f,0.0f,0.5f);
	
	//установка буфера глубины
	//разрешает очистку буфера глубины
	glClearDepth(1.0f);
	//разрешает тест глубины
	glEnable(GL_DEPTH_TEST);
	//тип теста глубины
	glDepthFunc(GL_LEQUAL); 
	//улучшение в вычислении перспективы
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	return TRUE; //иничиализация прошла успешно
}
//функция отрисовки
int DrawGLScene(GLvoid)
{
	//Очистить экран и буфер глубины
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	//сбрисить текущею матрицу
	glLoadIdentity(); //Сбрасить текущую матрицу
	
	//сдвинуть влево на 1,5 единиц
	glTranslatef(-1.5f,0.0f,-6.0f);
	//бывают 
	//GL_TRIGLE
	//GL_QUADS
	//GL_POLYGONS
	
	glBegin(GL_TRIANGLES);                      // Drawing Using Triangles
    glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
    glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
    glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
	glEnd();                            // Finished Drawing The Triangle
	
	glTranslatef(3.0f,0.0f,0.0f);
	glBegin(GL_QUADS);                      // Draw A Quad
        glVertex3f(-1.0f, 1.0f, 0.0f);              // Top Left
        glVertex3f( 1.0f, 1.0f, 0.0f);              // Top Right
        glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
        glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
    glEnd();                            // Done Drawing The Quad
    return TRUE;        
	
	
}
//корректное разрушение окна
GLvoid KillGLWindow(GLvoid)
{
	if(fullscreen)
	{
		//возврат окна в начальный режим
		ChangeDisplaySettings(NULL,0);
		//показать курсор мыши
		ShowCursor(TRUE); //Показать курсор мыши
	}
	//существует ли контекст рендеринга
	if(hRC)
	{
		//можно ли освободиь RC DC
		if(!wglMakeCurrent(NULL,NULL))
		{
			MessageBox(NULL,"Ошибка освобождения DC и RC","Ошибка", MB_OK|MB_ICONINFORMATION);
		}
		//можно ли освободить контекст рендеринга
		if( !wglDeleteContext( hRC ) )
		{
			MessageBox(NULL,"Ошибка освобождения контекста рендеринга","Ошибка", MB_OK|MB_ICONINFORMATION);		
		}
		hRC = NULL; 
	}
	//возможно ли уничтожить DC
	if(hDC && !ReleaseDC(hWnd, hDC))
	{
		MessageBox(NULL,"Ошибка освобождения контекста устройства","Ошибка", MB_OK|MB_ICONINFORMATION);
		hDC = NULL;
	}
	//возможно ли уничтожить окно
	if(hWnd && !DestroyWindow(hWnd))
	{
		MessageBox(NULL,"Не освобождено hWnd","Ошибка", MB_OK|MB_ICONINFORMATION);
		hWnd = NULL;
	}
	//возможно ли разрегистрировать класс
	if(!UnregisterClass("OpenGL",hInstance))
	{
		MessageBox(NULL,"Нельза разрегистрировать класс","Ошибка", MB_OK|MB_ICONINFORMATION);
		hInstance = NULL;
	}
}

//создает окно
bool CreateGLWindow(/*LPCWSTR*/const char *title, int width, int height, int bits, bool fullscreenflag)
{
	//хранит резултта после поиска
	GLuint PixelFormat; 
	//Структура класса окна
	WNDCLASS wc;
	DWORD dwExStyle; //Рассширенный стиль окна
	DWORD dwStyle; //Обычный стиль окна
	// квадрат для рисования вержиний и нижний точка
	RECT WindowRect; 
	WindowRect.left = (long)0; //установить левую состовляющую в 0
	WindowRect.right = (long)width; //установить правую соостовляющую
	WindowRect.top = (long)0; //установить верхнюю составлюящую
	WindowRect.bottom = (long)height; //установить нижнюю составляющую
	//устанавливаем значение глобальной переменной fullscreen
	fullscreen = fullscreenflag;
	
	//устанавливаем значения окна
	// Считаем дескриптор нашего приложения
	hInstance = GetModuleHandle(NULL);        
	// Перерисуем при перемещении и создаём скрытый DC
	wc.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC; 
	// Процедура обработки сообщений
	wc.lpfnWndProc = (WNDPROC) WndProc;          
	// Нет дополнительной информации для окна
	wc.cbClsExtra = 0;              
	// Нет дополнительной информации для окна
	wc.cbWndExtra = 0;              
	// Устанавливаем дескриптор
	wc.hInstance = hInstance;            
	// Загружаем иконку по умолчанию
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);        
	// Загружаем указатель мышки
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);        
	// Фон не требуется для GL
	wc.hbrBackground = NULL;              
	// Меню в окне не будет
	wc.lpszMenuName = NULL;              
	// Устанавливаем имя классу
	wc.lpszClassName = "OpenGL";            

	//регистрируем класс окна
	if(!RegisterClass(&wc))
	{
		MessageBox(NULL, "Ошибка регистрации класа окна","Ошибка",MB_OK|MB_ICONEXCLAMATION);
		return FALSE;
	}
	
	//проверка полноэкранного режима
	if(fullscreen)
	{
		//режим устройства
		DEVMODE dmScreenSettings;
		//Очистка для хранения установок
		memset(&dmScreenSettings,0,sizeof(dmScreenSettings));
		//размер структуры Devmode
		dmScreenSettings.dmSize=sizeof(dmScreenSettings);
		//ширина экрана
		dmScreenSettings.dmPelsWidth = width;
		//высота экрана 
		dmScreenSettings.dmPelsHeight = height; 
		//глубина цвета
		dmScreenSettings.dmBitsPerPel = bits;
		//режим пикселя
		dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		//пытаемся установить выбранный режим и получить результат.
		if(ChangeDisplaySettings(&dmScreenSettings, CDS_FULLSCREEN)!=DISP_CHANGE_SUCCESSFUL)
		{
			//если переключение в полноэкранный режим невозможно
			//будет предложено оконный режим или выход
			if(MessageBox(NULL,"Перейти в полноэкранный режим невозможно\n Использовать обычный режим","Сообщение программы",MB_YESNO|MB_ICONEXCLAMATION)==IDYES)
			{
				//установка оконного режима
				fullscreen=FALSE;
			}
			else
			{
				//вывод сообщения о закарытии окна 
				MessageBox(NULL,"Программа будет закрыта", "Ошибка", MB_OK|MB_ICONSTOP);
				return FALSE;
			}
		}
	}
	//мы в полноэкранном режиме
	if(fullscreen)
	{
		//скрыть верхнюю часть окна вместе с заголовком
		dwExStyle = WS_EX_APPWINDOW;
		//обычный стиль окна
		dwStyle = WS_POPUP;
		//скрыть указатель мыши
		ShowCursor(FALSE);
	}
	else
	{
		//придать окну более объёмный вид
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;
		//границы и кнопки изменения размера
		dwStyle = WS_OVERLAPPEDWINDOW;
	}
	// Подбирает окну подходящие размеры
	AdjustWindowRectEx( &WindowRect, dwStyle, FALSE, dwExStyle );  
	
	/*
	       определённый ранее расширенный стиль; 
	       имя класса (которое должно быть тем самым, что Вы использовали, когда регистрировали класс окна); 
	       заголовок окна; 
	       обычный стиль окна; 
	       X левого угла окна; 
	       Y левого угла окна; 
	       ширина окна; 
	       высота окна; 
	       родительское окно (у нас его нет); 
	       дескриптор меню (и меню у нас тоже нет); 
	       дескриптор приложения; 
	       дополнительные данные. 
	  */
	
	if( !( hWnd = CreateWindowEx(
								dwExStyle,// Расширенный стиль для окна
								"OpenGL", // Имя класса
								title,    // Заголовок окна
								dwStyle |
								WS_CLIPSIBLINGS |	 // Выбираемые стили для окна
								WS_CLIPCHILDREN ,       // запрещают другим окнам рисовать поверх нашего окна
								0, 0,     // Позиция окна
								WindowRect.right-WindowRect.left,    // Вычисление подходящей ширины
								WindowRect.bottom-WindowRect.top,    // Вычисление подходящей высоты
								NULL,     // Нет родительского
								NULL,     // Нет меню
								hInstance, // Дескриптор приложения
								NULL ) ) ) // Не передаём ничего до WM_CREATE


			{//в случае ошибки
		     KillGLWindow(); // Восстановить экран
		     MessageBox( NULL, "Ошибка создания окна", "Ошибка", MB_OK | MB_ICONEXCLAMATION );
			 return FALSE;                // Вернуть FALSE
			}
			
			//устанавливает формат отображения пикселей
			static PIXELFORMATDESCRIPTOR pfd =
			{
				sizeof(PIXELFORMATDESCRIPTOR), //размер дескриптора данного формата пикселей
				1, 				//номер версии
				PFD_DRAW_TO_WINDOW | //Формат для Окна
				PFD_SUPPORT_OPENGL | //формат для OpenGL
				PFD_DOUBLEBUFFER, //формат для двойного буфера
				PFD_TYPE_RGBA, //требуется rgba формат
				bits, //вибирается бит глубины цвета
				0, 0, 0, 0, 0, 0, //игнорирование цветовых битов
				0, //нет буфера прозрачности
				0, //сдвиговый бит
				0, //нет буфера накопления
				0, 0, 0, 0, //Биты  накопленя игнорируются
				32, //32 битный z-буфер глубины
				0, //нет буфера трафарета
				0, //нет вспомогательных буферов
				PFD_MAIN_PLANE, //главный слой рисования
				0, //зарезервировано
				0,0,0 //маски слоя игнорируются
			};
			
			//можем ли мы получить контекст устройства
			if(!(hDC = GetDC(hWnd))) 	
			{
				KillGLWindow(); //востановить экран
				MessageBox(NULL, "Не получен контекст устройства","Ошибка",MB_OK|MB_ICONINFORMATION);
				return FALSE;
			}
				
			//найден ли подходляфий формат пикселя
			if(!(PixelFormat = ChoosePixelFormat(hDC, &pfd)))
			{
				KillGLWindow(); //востановить экран
				MessageBox(NULL, "Не найден формат пикселя", "Ошибка", MB_OK|MB_ICONEXCLAMATION);
				return FALSE;
			}
			
			//возможно ли установить формат пикселя
			if(!SetPixelFormat(hDC, PixelFormat, &pfd))
			{
				KillGLWindow();
				MessageBox(NULL,"Не установлен формат пикселя","Ошибка",MB_OK|MB_ICONEXCLAMATION);
				return FALSE;
			}
				//возможно ли установить контекст рендеринго
			if(!(hRC = wglCreateContext(hDC)))
			{
				KillGLWindow();
				MessageBox(NULL, "Не установлен контекст рендеринга","Ошибка", MB_OK|MB_ICONEXCLAMATION);
				return FALSE;
			}
				
			//попробовать активировать конекст рендеринга 
			if(!wglMakeCurrent(hDC, hRC))
			{
				KillGLWindow();
				MessageBox(NULL, "Не активирован контекст рендеринга","Ошибка", MB_OK|MB_ICONEXCLAMATION);
				return FALSE;
			}
			
			ShowWindow(hWnd, SW_SHOW); //показать окно
			SetForegroundWindow(hWnd); //слегка повысим приоритет
			SetFocus(hWnd); //установить фокуст клавиатуры на наше окна
			resizeGLScene(width, height); //настроим персективу для нашего окна
			
			//инициализация созданного окна
			if(!InitGL())
			{
				KillGLWindow();
				MessageBox(NULL, "Ошибка инициализации","Ошибка", MB_OK|MB_ICONEXCLAMATION);
				return FALSE;
			}
			
			return TRUE;	
			}

	//регистрируем класс окна и запускаем обработку сообщений
	LRESULT CALLBACK WndProc(HWND hWnd, //дескриптор нужного окна
							UINT uMsg, //сообщение для этого окна
							WPARAM wParam, //дополнительная информация
							LPARAM lParam) //дополнительная информация
	{
		switch(uMsg) //проверка сообщения для окна
		{
			case WM_ACTIVATE: //проверка сообщения активности окна
			{
				if(!HIWORD(wParam)) //проверить состояние минимизации
				{
					active = TRUE; //программа активана
				}
				else
				{
					active = FALSE; //програмаа не активна
				}
				return 0; //вернутся в цикл обработки сообщений
			}
			//перехватываем системную команду
			case WM_SYSCOMMAND:
			{
				switch(wParam) //останавливаем системный вызов
				{
					case SC_SCREENSAVE: // Пытается ли запустится скринвейвер
					case SC_MONITORPOWER:  //пытается монитор перейти в спящий пежим 
					return 0; //предотвратит
				}
				break;
			}
			
			case WM_CLOSE: //получили сообщение на закрытие 
			{
				PostQuitMessage(0); //отправить сообщение о выходе
				return 0;
			}
			//была нажата кнопка
			case WM_KEYDOWN: 
			{
				keys[wParam]=TRUE; //если так присваеваем соответствующей ячейке TRUE
				return 0;
			}
			case WM_KEYUP: // Была ли отпущена клавиша?
			{
				keys[wParam] = FALSE;          //  Если так, мы присваиваем этой ячейке FALSE
				return 0;            // Возвращаемся
			}
			//изменение размеров OpenGL окна
			case WM_SIZE:
			{
				//младшее слово ширина / старшее слово высота
				resizeGLScene(LOWORD(lParam),HIWORD(lParam));
				return 0;
			}
		}
			// пересылаем все необработанные сообщения DefWindowProc
			return DefWindowProc( hWnd, uMsg, wParam, lParam );
		}
		//Точка входа в программу
	int WINAPI WinMain( HINSTANCE hInstance,        // Дескриптор приложения
						HINSTANCE hPrevInstance,        // Дескриптор родительского приложения
						LPSTR lpCmdLine,        // Параметры командной строки
						int nCmdShow )        // Состояние отображения окна
		{
			MSG msg;  // Структура для хранения сообщения Windows
		    bool done = FALSE;            // Логическая переменная для выхода из цикла

			// Спрашивает пользователя, какой режим экрана он предпочитает
			if( MessageBox( NULL, "Хотите ли Вы запустить приложение в полноэкранном режиме?",  "Запустить в полноэкранном режиме?", MB_YESNO | MB_ICONQUESTION) == IDNO )
			{
				fullscreen = FALSE;          // Оконный режим
			}
			
			// Создать наше OpenGL окно
			if( !CreateGLWindow( "GL programm", 1024, 768, 32, fullscreen ) )
			{
				return 0; // Выйти, если окно не может быть создано
			}

			while(!done)
			{
				if(PeekMessage(&msg,NULL,0,0, PM_REMOVE)) //есть ли в очереди сообщение
				{
					if( msg.message == WM_QUIT )        // Мы поучили сообщение о выходе?
					{
						done = TRUE;          // Если так, done=TRUE
					}
					else              // Если нет, обрабатывает сообщения
					{
						TranslateMessage( &msg );        // Переводим сообщение
						DispatchMessage( &msg );        // Отсылаем сообщение
					}
				}
				else
				{
					// Прорисовываем сцену.
					if( active )          // Активна ли программа?
					{
						if(keys[VK_ESCAPE])        // Было ли нажата клавиша ESC?
						{
							done = TRUE;      // ESC говорит об останове выполнения программы
						}
						else            // Не время для выхода, обновим экран.
						{
							DrawGLScene();        // Рисуем сцену
							SwapBuffers( hDC );    // Меняем буфер (двойная буферизация)
						}
					}
					
					if( keys[VK_F1] )          // Была ли нажата F1?
					{
						keys[VK_F1] = FALSE;        // Если так, меняем значение ячейки массива на FALSE
						KillGLWindow();          // Разрушаем текущее окно
						fullscreen = !fullscreen;      // Переключаем режим
						// Пересоздаём наше OpenGL окно
						if( !CreateGLWindow("Наше окно", 1024, 768, 32, fullscreen ))
						{
							return 0;        // Выходим, если это невозможно
						}
					}
				}
			}
		
		// Shutdown
		KillGLWindow();                // Разрушаем окно
		return ( msg.wParam );              // Выходим из программы
}






	
	















