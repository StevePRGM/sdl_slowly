#include <SDL2/SDL.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>
#include "files/mySDL.cpp"
#include "files/character.cpp"
#include "files/SDLinterface.cpp"

const int sWIDTH = 640;
const int sHEIGHT = 480;


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

 SDL_Rect r1 = {0,0,32,32};
 SDL_Rect r2 = {0,0,32,32};
 const SDL_Rect *rs = &r1;
 SDL_Rect *rd = &r2;


 character man1;

 unsigned int i=0;

// ====================== EVENTS ====================

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
      SDL_BlitSurface( xHi.xSurface, NULL, wind.xSurface, NULL );
      rd->x = (unsigned int)man1.x;
      rd->y = 32;
      SDL_BlitSurface( xHi.xSurface, rs, wind.xSurface, rd );
      SDL_UpdateWindowSurface( wind.xWindow );
      break;
     case SDLK_3:
      printf(" key3 - display \n");
      SDL_BlitSurface( xAloha.xSurface, NULL, wind.xSurface, NULL );
      SDL_UpdateWindowSurface( wind.xWindow );
      break;
     case SDLK_4:
      printf(" key4 - display \n");
      SDL_BlitSurface( xBlack.xSurface, NULL, wind.xSurface, NULL );
      SDL_UpdateWindowSurface( wind.xWindow );
      break;

     //free and NULL
     case SDLK_0:
      break;

     //quit
     case SDLK_SLASH:
      appFLAG=1;
      break;

     case SDLK_LEFT:
       SDL_BlitSurface( xBlack.xSurface, NULL, wind.xSurface, rd );
      man1.x-=5;
       std::cout << "man1.x = " << man1.x << "\n";
       rd->x = (unsigned int)man1.x;
       rd->y = 32;
       SDL_BlitSurface( xHi.xSurface, rs, wind.xSurface, rd );
       SDL_UpdateWindowSurface( wind.xWindow );
      break;
     case SDLK_RIGHT:
       SDL_BlitSurface( xBlack.xSurface, NULL, wind.xSurface, rd );
      man1.x+=5;
       std::cout << "man1.x = " << man1.x << "\n";
       rd->x = (unsigned int)man1.x;
       rd->y = 32;
       SDL_BlitSurface( xHi.xSurface, rs, wind.xSurface, rd );
       SDL_UpdateWindowSurface( wind.xWindow );
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


 SDL_FillRect( this->xSurface, NULL, SDL_MapRGB( this->xSurface->format, 0x34, 0x50, 0xFF ) );
 SDL_Delay(1000);


 //fill rect
 SDL_FillRect( wind.xSurface, rs, SDL_MapRGB( wind.xSurface->format, 0xFF, 0xFF, 0xFF ) );
 SDL_UpdateWindowSurface( wind.xWindow );


*/