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
  qBMP *pic;

  character() {
   x=0;
   y=0;
   pic=NULL;
  }
};
class zombie {
 public:
  int x;
  int y;
  qBMP *pic;
};






/**/