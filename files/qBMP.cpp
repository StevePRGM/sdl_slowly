class qBMP {
 public:
  std::string file="";
  SDL_Surface *xSurface;

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