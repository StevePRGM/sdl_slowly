/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>.
#include <iostream>

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
  int hasinitvideo;
  int haswindow;
  int hassurface;

  SDL_interface()
  {
   xWindow = NULL;
   xSurface = NULL;
   sW = 640;
   sH = 480;
   hasinitvideo=0;
   haswindow=0;
   hassurface=0;
  }
  ~SDL_interface()
  {
  }

  void initvideo()
  {
   if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
   {
    //SDL_GetError()
    this->hasinitvideo = 0;
   } else {
    this->hasinitvideo = 1;
   }
  }

  void createwindow()
  {
   this->xWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, this->sW, this->sH, SDL_WINDOW_SHOWN );
   if(this->xWindow == NULL)
   {
    //SDL_GetError()
    this->haswindow = 0;
   } else {
    this->haswindow = 1;
   }
  }
  void destroywindow()
  {
   if(this->haswindow==1)
    SDL_DestroyWindow( this->xWindow );
   else
    printf( "destroywindow not needed" );
  }
  void createsurface()
  {
   this->xSurface = SDL_GetWindowSurface( this->xWindow );
  }
  /*void fillrect()
  {
   SDL_FillRect( this->xSurface, NULL, SDL_MapRGB( this->xSurface->format, 0x34, 0x50, 0xFF ) );
   SDL_Delay(1000);
  }*/
};


int main( int argc, char* args[] )
{
 int appFLAG=0;
	//The window we'll be rendering to
	SDL_Window* window = NULL;
	
	//The surface contained by the window
	SDL_Surface* screenSurface = NULL;

/*
 SDL_interface wind;
 wind.initvideo();
 wind.createwindow();
  wind.createsurface();
  //wind.fillrect();

 //if(wind.hasinitvideo == 0) { return 0; }
*/

// ========================================================================
// ========================================================================

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
      SDL_Rect r1; r1.x=32; r1.y=32; r1.w=10; r1.h=10;
      const SDL_Rect *r2 = &r1;
   SDL_FillRect( (screenSurface), r2, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
   
   //Update the surface
   SDL_UpdateWindowSurface( window );
// ========================================================================
   SDL_Event e;
   while(appFLAG==0)
   {
    while( SDL_PollEvent( &e ) != 0 )
    {
     if( e.type == SDL_QUIT ) // the close button
     {
      appFLAG = 1;
     }
     switch( e.key.keysym.sym ) // which key?
     {
      case SDLK_UP:
       SDL_DestroyWindow( window );
       SDL_Quit();
       return 0;
       break;
      default:
       break;
     }
    }
   }


// ========================================================================

   /*
   //Wait two seconds
   SDL_Delay( 1000 );
   */

  }
 }
 //Destroy window
 SDL_DestroyWindow( window );

// ========================================================================
// ========================================================================


/* work on getting this working \/
 //Fill the surface white
 SDL_Rect r1; r1.x=0; r1.y=0; r1.w=32; r1.h=32;
 const SDL_Rect *r2 = &r1;
 SDL_FillRect( wind.xSurface, r2, SDL_MapRGB( (wind.xSurface)->format, 0x99, 0x66, 0x44 ) );
 SDL_Delay( 1000 );

 wind.destroywindow();
*/

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}