#include"declare.h"
#include"drawTextOnScreen.h"

void drawText(string text, int x, int y){
    font = TTF_OpenFont("font/COLLEGIA.ttf", 20);
    SDL_Color fg = { 220, 220, 220};
    SDL_Surface* loadedText=NULL;
	loadedText = TTF_RenderText_Solid(font, text.c_str(), fg);
	texture= SDL_CreateTextureFromSurface(renderer, loadedText);
	SDL_Rect srcRest;
	SDL_Rect desRect;
	TTF_SizeText(font, text.c_str(), &srcRest.w, &srcRest.h);

	srcRest.x = 0;
	srcRest.y = 0;

	desRect.x = x;
	desRect.y = y;
	desRect.w = srcRest.w;
	desRect.h = srcRest.h;

	SDL_RenderCopy(renderer, texture, &srcRest, &desRect);
	SDL_DestroyTexture(texture);
}
void Score(){
    stringstream text;
    text<< score;
    drawText(text.str().c_str(), 270, 447);
}
void foodToWin(){
    stringstream text;
    text << SNAKE_LENGTH_MAX-snakelength;
    drawText(text.str().c_str(), 35, 447);
}

