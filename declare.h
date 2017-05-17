#ifndef DECRALE_H_INCLUDED
#define DECRALE_H_INCLUDED

#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<SDL.h>
#include<math.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<cstring>
#include<sstream>
#include<SDL_mixer.h>

using namespace std;

struct point{
	int x, y;
};
const int SNAKE_LENGTH_MAX=55, MIN_SPEED_GAME=100, MAX_SPEED_GAME=30, WIDTH_WINDOW= 645, HEIGHT_WINDOW= 480, snakeLengthStart=5;
extern point snake[SNAKE_LENGTH_MAX], snake1[SNAKE_LENGTH_MAX], dir, food;
extern int snakelength, size, MinSpeedGameCoppy, score;
extern SDL_Rect Map ;
extern SDL_Window * window;
extern SDL_Texture* texture;
extern SDL_Renderer* renderer;
extern TTF_Font* font;
extern SDL_Event e;

#endif // DECRALE_H_INCLUDED
