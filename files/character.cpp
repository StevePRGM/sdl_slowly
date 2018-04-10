/* todo stuff
 character.location
 character.draw
 character.x+=character.speed


*/

class character {
public:
 int x;
 int y;
 unsigned int speed;
 SDL_Surface *img;

 character()
 {
  x=0;
  y=0;
 }
 ~character()
 {
 }

 loadBMP(std::string file1)
 {
  printf("file1 = %s", file1.c_str());
 }
};

class zombie {
public:
 int x;
 int y;
 qBMP *pic;
};






/**/