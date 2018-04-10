
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
   SDL_interface::createwindow();
  }
  ~SDL_interface()
  {
   SDL_interface::destroywindow();
  }

  void createwindow()
  {
   if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
   {
    //SDL_GetError()
    this->hasinitvideo = 0;
   } else {
    this->hasinitvideo = 1;
   }

   this->xWindow = SDL_CreateWindow( "window 1", \
                                      SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, \
                                      this->sW, this->sH, \
                                      SDL_WINDOW_SHOWN );
   /*SDL_GetError()*/
   if(this->xWindow == NULL) {
    this->haswindow = 0;
   } else {
    this->haswindow = 1;
    this->xSurface = SDL_GetWindowSurface( this->xWindow );
   }
  }

  void destroywindow()
  {
   if(this->haswindow==1) {
    SDL_DestroyWindow( this->xWindow );
    this->xWindow = NULL;
    this->xSurface = NULL;
    printf( "destroywindow() HAPPENED\n" );
   } else {
    printf( "@wind.destroywindow(), haswindow was 0.\n" );
   }
  }
};