#include"declare.h"
#include"sound.h"

Mix_Music *startSound = NULL;
Mix_Chunk *eat = NULL;
Mix_Chunk *select = NULL;
Mix_Chunk *gameover = NULL;
Mix_Chunk *win = NULL;

void startGameSound(){
    startSound = Mix_LoadMUS("sound/jump_and_run_-_tropics.wav");
    if(Mix_PlayingMusic() == 0){
       Mix_PlayMusic(startSound, -1);
    }
}

void eatSound(){
    eat = Mix_LoadWAV("sound/eat.wav");
    if(!Mix_Playing(-1)){
        Mix_PlayChannel(-1, eat, 0);
    }
}

void selectSound(){
    select = Mix_LoadWAV("sound/select1.wav");
    if(!Mix_Playing(-1)){
        Mix_PlayChannel(-1, select, 0);
    }
}

void gameoverSound(){
    gameover = Mix_LoadWAV("sound/game over.wav");
    if(!Mix_Playing(-1)){
        Mix_PlayChannel(-1, gameover, 0);
    }
}

void winGameSound(){
    win = Mix_LoadWAV("sound/eat.wav");
    if(!Mix_Playing(-1)){
        Mix_PlayChannel(-1, win, 0);
    }
}
