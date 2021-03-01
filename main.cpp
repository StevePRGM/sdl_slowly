#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
//#include <utility> // for const_cast<int>()
#include "files/qBMP.cpp"
#include "files/character.cpp"
#include "files/SDLinterface.cpp"

const int sWIDTH = 640;
const int sHEIGHT = 480;
const int sByron = 123;

#define xyy_debug1 //SDL_GetMouseState( &mx, &my ); std::cout << "(" << mx << "," << my << ") ";
#define xyy_debug2 //std::cout << (short)(e.button.button) << "_d(" << mx << "," << my << ") \n";
#define xyy_debug3 //std::cout << (short)(e.button.button) << "_u(" << mx << "," << my << ") \n";
#define xyy_debug4 //std::cout << "key: " << e.key.keysym.sym << "\n";
#define xyy_debugX //some other debug code (currently commented out)
#define xyy_debugX //some other debug code (currently commented out)
#define xyy_debugX //some other debug code (currently commented out)
#define xyy_debugX //some other debug code (currently commented out)

/*
draw(SDL_BlitSurface h1, SDL_Rect rs, SDL_BlitSurface h2, const SDL_Rect rd)
{
 //SDL_Rect r1 = {0,0,32,32};
 //SDL_Rect r2 = {0,0,32,32};
 //const SDL_Rect *rs = &r1;
 //SDL_Rect *rd = &r2;

 SDL_BlitSurface( h2, rs, h1, rd );
}
*/

// ========================================================================
// =========================    MAIN    ===================================

int main( int argc, char* args[] )
{
 if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) { return 0; }

 int appFLAG=0;
 SDL_interface wind;

 qBMP xHi("images/hi.bmp");
 qBMP xAloha("images/aloha.bmp");
 qBMP xBlack("images/black.bmp");

 clsMover man1;
 man1.img = xHi.xSurface;
 man1.imgbg = xBlack.xSurface;
 man1.winSurface = wind.xSurface;

 unsigned int i=0;

// ====================== EVENTS ====================

 SDL_Event e;
 while(appFLAG==0)
 {
  int mx; int my;
  while( SDL_PollEvent( &e ) != 0 )
  {
   //printf("= %i\n", e.type);
   if( e.type == SDL_QUIT )
   {
    appFLAG = 1;
   } else if( e.type == SDL_MOUSEBUTTONDOWN ) {
    xyy_debug2
   } else if( e.type == SDL_MOUSEBUTTONUP ) {
    xyy_debug3
   } else if( e.type == SDL_MOUSEMOTION ) {
    xyy_debug1
   } else if( e.type == SDL_KEYDOWN ) {
    xyy_debug4
    switch( e.key.keysym.sym )
    {
     case SDLK_ESCAPE:
      appFLAG=1;
      break;
     case SDLK_0:
      break;
     case SDLK_1:
      printf(" key1 - x\n");
      break;
     case SDLK_2:
      printf(" key2 - display \n");
      break;
     case SDLK_3:
      printf(" key3 - display \n");
      break;
     case SDLK_4:
      printf(" key4 - display \n");
      break;

     case SDLK_LEFT:
       std::cout << "man1@(" << man1.x << "," << man1.y << ")\n";
       man1.tele(-5,0);
       SDL_UpdateWindowSurface( wind.xWindow );
      break;
     case SDLK_RIGHT:
       std::cout << "man1@(" << man1.x << "," << man1.y << ")\n";
       man1.tele(+5,0);
       SDL_UpdateWindowSurface( wind.xWindow );
      break;
     case SDLK_UP:
       std::cout << "man1@(" << man1.x << "," << man1.y << ")\n";
       man1.tele(0,-5);
       SDL_UpdateWindowSurface( wind.xWindow );
      break;
     case SDLK_DOWN:
       std::cout << "man1@(" << man1.x << "," << man1.y << ")\n";
       man1.tele(0,+5);
       SDL_UpdateWindowSurface( wind.xWindow );
      break;

     default:
      break;
    }
   }
  }
 }
 SDL_Quit();
 return 0;
}




// should use a union...
void fDEBUG(int i, int a1=0, int a2=0, int a3=0, int a4=0)
{
 if(i==1) {
  std::cout << "(" << a1 << "," << a2 << ") ";
 } else {
 }
}

/*

 // === work on getting this working \/
 //Fill the surface white
 SDL_Rect r1; r1.x=0; r1.y=0; r1.w=32; r1.h=32;
 const SDL_Rect *r2 = &r1;
 SDL_FillRect( wind.xSurface, r2, SDL_MapRGB( (wind.xSurface)->format, 0x99, 0x66, 0x44 ) );
 SDL_Delay( 1000 );


 SDL_FillRect( this->xSurface, NULL, SDL_MapRGB( this->xSurface->format, 0x34, 0x50, 0xFF ) );
 SDL_Delay(1000);


 //fill rect
 SDL_FillRect( wind.xSurface, rs, SDL_MapRGB( wind.xSurface->format, 0xFF, 0xFF, 0xFF ) );
 SDL_UpdateWindowSurface( wind.xWindow );


*/