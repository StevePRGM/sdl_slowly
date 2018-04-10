/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class SDL_interface {
 public:
  static int   installState;
  SDL_Window*  xWindow;
  SDL_Surface* xSurface;
  int sW;
  int sH;

  SDL_interface()
  {
   xWindow = NULL;
   xSurface = NULL;
   sW = 640;
   sH = 480;
  }
  ~SDL_interface()
  {
  }

  bool initvideo()
  {
   if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
   {
    printf("sdl fail -- error: %s\n", SDL_GetError());
    return 0;
   } else {
    return 1;
   }
  }

  bool createwindow()
  {
   this->xWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->sW, this->sH, SDL_WINDOW_SHOWN );
  }
  void destroywindow()
  {
   SDL_DestroyWindow( this->xWindow );
  }
};


int main( int argc, char* args[] )
{
 SDL_interface wind;
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

 //if( wind.initvideo() == 1 )
 //{
 //}
	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0x00, 0xFF, 0xFF ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			//Wait two seconds
			SDL_Delay( 2000 );
		}
	}

	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}