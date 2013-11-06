#ifndef variables
int playerNormal[3][4] = {
	{4, 1,30,38},
	{35,1,30,38},
        {64,1,29,38}
	}; 
int playerCorrer[9][4] = {
  	{107,1,30,40},
  	{139,1,28,41},
    {168,1,31,39},
  	{201,1,32,41},
  	{235,1,27,40},
  	{266,1,29,40},
    {298,1,32,41},
  	{332,1,36,37},
    {366,1,31,40}
  }
;
typedef struct {
  int width;
  int height;
  int x;
  int y;
}sprite;
typedef struct {
  int tipo;
  sprite img[10];
}personaje;
#endif 
