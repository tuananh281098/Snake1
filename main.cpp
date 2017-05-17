
#include"declare.h"
#include"sound.h"
#include"loadMedia.h"
#include"food.h"
#include"Snake.h"
#include"drawTextOnScreen.h"

using namespace std;

bool init();
void startGame();
void mainLoop();
bool endGame();
void close();
void waitUntilKeyPressed();

int main(int argc, char * argv[]){
    if(!init()){
        cout << "don't init";
    }
    else{
        startGame();
        srand(time(NULL));
        initFood();
        mainLoop();
        waitUntilKeyPressed();
        close();
    }
	return 0;
}
bool init(){
    for(int i=0; i<snakelength; i++){
        snake[i].x = Map.w/2-(i*size);
        snake[i].y = Map.h/2;
    }
	dir.x=size;
	dir.y=0;
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        cout << "error";
        return -1;
    }
    else{
        window=SDL_CreateWindow("snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED , WIDTH_WINDOW, HEIGHT_WINDOW, SDL_WINDOW_SHOWN);
        if(window==NULL){
            cout << "error1";
            return -1;
        }
        else{
            if (TTF_Init() < 0){
                SDL_Log("%s", TTF_GetError());
                return -1;
            }
            if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
                return -1;
            renderer= SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(renderer == NULL){
                cout << SDL_GetError();
                return -1;
            }
        }

    }
    return 1;
}
void startGame(){
    LoadMedia( "startGame/begin1.png", 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW );
    SDL_RenderPresent(renderer);
    startGameSound();
    while(true){
        SDL_Rect a = {248, 254, 128, 64};
        SDL_Rect b = {248, 353, 128, 64};
        while(SDL_PollEvent(&e)){
            switch(e.type){
                case SDL_QUIT:
                {
                    SDL_Quit();
                    break;
                }
                case SDL_MOUSEMOTION:
                {
                   // cout<< e.motion.x << " " << e.motion.y << endl;
                    if(a.x < e.motion.x && e.motion.x < a.w + a.x && a.y < e.motion.y && e.motion.y < a.h + a.y){
                        LoadMedia( "startGame/start.png", 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW );
                        SDL_RenderPresent(renderer);
                    }
                    else if(b.x < e.motion.x && e.motion.x < b.w + b.x && b.y < e.motion.y && e.motion.y < b.h + b.y){
                        LoadMedia( "startGame/howtoplay.png", 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW );
                        SDL_RenderPresent(renderer);
                    }
                    else{
                        LoadMedia( "startGame/begin1.png", 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW );
                        SDL_RenderPresent(renderer);
                    }
                    break;
                }
                case SDL_MOUSEBUTTONDOWN:
                {
                    if(a.x < e.motion.x && e.motion.x < a.w + a.x && a.y < e.motion.y && e.motion.y < a.h + a.y){
                        selectSound();
                        return;
                    }
                    else if(b.x < e.motion.x && e.motion.x < b.w + b.x && b.y < e.motion.y && e.motion.y < b.h + b.y){
                        selectSound();
                        LoadMedia( "startGame/howtoplay1.png", 0, 0, WIDTH_WINDOW, HEIGHT_WINDOW );
                        SDL_RenderPresent(renderer);
                    }
                }
            }
        }
    }
}
void mainLoop(){
    while(!endGame()){
        LoadMedia("map/map1.png", 0, 0, Map.w, HEIGHT_WINDOW);
        checkmove();
        drawsnake();
        snakeEatFood();
        drawfood();
        Score();
        foodToWin();
        SDL_RenderPresent(renderer);
        if(MinSpeedGameCoppy > MAX_SPEED_GAME){
            MinSpeedGameCoppy = MIN_SPEED_GAME - 2*(snakelength-snakeLengthStart);
        }
        if(e.type == SDL_QUIT){
            SDL_Quit();
            return;
        }
        SDL_Delay(MinSpeedGameCoppy);
    }
}
bool endGame(){
    bool s=false;
    for(int i=1;i<snakelength;i++){
       if(snake[0].x==snake[i].x && snake[0].y==snake[i].y){
            s=true;
            SDL_Delay(300);
            LoadMedia("endGame/gameover.png", 0, 0, Map.w, Map.h);
            SDL_RenderPresent(renderer);
            Mix_PauseMusic();
            gameoverSound();
            return s;
       }
    }
    if(snakelength == SNAKE_LENGTH_MAX){
        s=true;
        SDL_Delay(300);
        LoadMedia("endGame/winGame.png", 0, 0, Map.w, Map.h);
        SDL_RenderPresent(renderer);
        Mix_PauseMusic();
    }
    if(snake[0].x <=0 || snake[0].y <=0 || snake[0].y > Map.h-25|| snake[0].x > Map.w-25){
        s=true;
        SDL_Delay(300);
        LoadMedia("endGame/gameover.png", 0, 0, Map.w, Map.h);
        SDL_RenderPresent(renderer);
        Mix_PauseMusic();
        gameoverSound();
        return s;
    }
    return s;
}
void close(){
    SDL_DestroyWindow(window);
    window=NULL;
    SDL_DestroyTexture(texture);
    texture = NULL;
    SDL_DestroyRenderer(renderer);
    renderer = NULL;
	TTF_Quit();
	SDL_Quit();
}
void waitUntilKeyPressed(){
    while(true) {
        if(SDL_WaitEvent(&e) != 0 && e.type == SDL_QUIT)
            return ;
    }
}

