#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include "files/character.cpp"

const int sWIDTH = 640;
const int sHEIGHT = 480;

class qBMP {
 public:
  std::string file="";
  SDL_Surface* xSurface;

 qBMP() {
  //load picture
  xSurface = NULL;
  printf("POSSIBLE ISSUE.. NO LOADED PICTURE!");
 }

 qBMP( char *str1) {
  //load picture
  xSurface = NULL;
  file = str1;
  file += "\n";
  xSurface = SDL_LoadBMP( str1 );
  printf("qBMP()\n");
 }

 ~qBMP() {
  //destroy picture
  SDL_FreeSurface( xSurface );
  xSurface = NULL;
  printf("~qBMP() %s", file.c_str());
  //std::cout<< file;
 }
};

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
   this->xWindow = SDL_CreateWindow( "window 1", \
                                      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
                                      this->sW, this->sH, \
                                      SDL_WINDOW_SHOWN );
   /*SDL_GetError()*/
   if(this->xWindow == NULL) {
    this->haswindow = 0;
   } else {
    this->haswindow = 1; }
  }
  void destroywindow()
  {
   if(this->haswindow==1)
    SDL_DestroyWindow( this->xWindow );
   else
    printf( "destroywindow() not needed" );
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


// ========================================================================
// =========================    MAIN    ===================================

int main( int argc, char* args[] )
{
 int appFLAG=0;
/*
*/

 qBMP xxHi("images/hi.bmp");
 qBMP xxAloha("images/aloha.bmp");
 qBMP xxBlack("images/black.bmp");

 SDL_Window* window = NULL;
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
// ===================== INIT =============================================

 //Initialize SDL
 if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
 {
  printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
 }
 else
 {
  //Create window
  window = SDL_CreateWindow( "window 2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, sWIDTH, sHEIGHT, SDL_WINDOW_SHOWN );
  if( window == NULL )
  {
   printf( "window fail");
  }
  else
  {
   //Get window surface
   screenSurface = SDL_GetWindowSurface( window );

   //Fill the surface white
      SDL_Rect r1; r1.x=32; r1.y=32; r1.w=10; r1.h=10;
      const SDL_Rect *r2 = &r1;
   SDL_FillRect( (screenSurface), r2, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
   SDL_UpdateWindowSurface( window );


// ====================== EVENTS =========================================

   SDL_Event e;
   while(appFLAG==0)
   {
    while( SDL_PollEvent( &e ) != 0 )
    {
     //printf("= %i\n", e.type);
     if( e.type == SDL_QUIT )
     {
      appFLAG = 1;
     } else if( e.type == SDL_KEYDOWN ) {
      switch( e.key.keysym.sym )
      {
       //load
       case SDLK_1:
        printf(" key1 - x\n");
        break;

       //display
       case SDLK_2:
        printf(" key2 - display \n");
        SDL_BlitSurface( xxHi.xSurface, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        break;
       case SDLK_3:
        printf(" key3 - display \n");
        SDL_BlitSurface( xxAloha.xSurface, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        break;
       case SDLK_4:
        printf(" key4 - display \n");
        SDL_BlitSurface( xxBlack.xSurface, NULL, screenSurface, NULL );
        SDL_UpdateWindowSurface( window );
        break;

       //free and NULL
       case SDLK_0:
        break;

       //quit
       case SDLK_SLASH:
        appFLAG=1;
        break;

       case SDLK_LEFT:
        break;
       case SDLK_RIGHT:
        break;
       case SDLK_UP:
        break;
       case SDLK_DOWN:
        break;

       default:
        break;
      }
     }
    }
   }
  }
 }



// ===================== DESTROY \/ =========================================
 /* DESTROYYYY  (screensurface destroyed with window) */

 SDL_DestroyWindow( window ); window = NULL;

// ===================== DESTROY /\ =========================================



 //wind.destroywindow();
 SDL_Quit();
 return 0;
}



/*

 // === work on getting this working \/
 //Fill the surface white
 SDL_Rect r1; r1.x=0; r1.y=0; r1.w=32; r1.h=32;
 const SDL_Rect *r2 = &r1;
 SDL_FillRect( wind.xSurface, r2, SDL_MapRGB( (wind.xSurface)->format, 0x99, 0x66, 0x44 ) );
 SDL_Delay( 1000 );


*/