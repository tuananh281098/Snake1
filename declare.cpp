#include"declare.h"

int snakelength=5, size=25, MinSpeedGameCoppy=150, score=0;
point snake[SNAKE_LENGTH_MAX], snake1[SNAKE_LENGTH_MAX], dir, food;
SDL_Rect Map = {0, 0, 645, 431};
SDL_Window * window= NULL;
SDL_Texture* texture=NULL;
SDL_Renderer* renderer= NULL;
TTF_Font* font = NULL;
SDL_Event e;
