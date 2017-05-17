#include"declare.h"
#include"food.h"
#include"loadMedia.h"
#include"sound.h"

void initFood(){
    int count=0;
    do{
        count = 0;
        food.x= rand()%(Map.w- 2*size)+size;
        food.y= rand()%(Map.h- 2*size)+size;
        for(int i=0; i<snakelength; i++){
            if(snake[i].x != food.x && snake[i].y != food.y){
                count += 1;
            }
        }
    }
    while(abs(Map.w/2-food.x)%size != 0 || abs(Map.h/2-food.y)%size != 0 || count < snakelength-1);
}
void drawfood(){
    if(snakelength != SNAKE_LENGTH_MAX){
        LoadMedia("food.png",food.x,food.y,size,size);
    }
}
void snakeEatFood(){
    if((snake[0].x==food.x ||snake[0].x==food.x+size-1) && snake[0].y ==food.y){
        eatSound();
        snakelength++;
        initFood();
        score=(snakelength-snakeLengthStart)*100;
    }
}
