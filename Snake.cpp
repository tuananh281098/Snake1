#include"declare.h"
#include"Snake.h"
#include"loadMedia.h"

void drawsnake(){
	for(int i=0; i<snakelength;i++){
		snake1[i].x=snake[i].x;
        snake1[i].y=snake[i].y;
		if(i==0){
			snake[i].x+=dir.x;
			snake[i].y+=dir.y;
			if(dir.x==-size)  LoadMedia("headSnake/headLeft.png",snake[i].x,snake[i].y,size,size);
			if(dir.x==size)   LoadMedia("headSnake/headRight.png",snake[i].x,snake[i].y,size,size);
            if(dir.y==size)   LoadMedia("headSnake/headDown.png",snake[i].x,snake[i].y,size,size);
            if(dir.y==-size)  LoadMedia("headSnake/headSnakeUp.png",snake[i].x,snake[i].y,size,size);
		}
		else{
			snake[i].x=snake1[i-1].x;
			snake[i].y=snake1[i-1].y;
			if(i!=snakelength-1 && snake[i].y==snake[i-1].y){
                if(snake[i].x==snake[i-1].x+size && snake[i].y==snake[i-1].y && snake[i].x==snake1[i].x && snake[i].y==snake1[i].y+size)
                    LoadMedia("snake's body/snakeDownLeft.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i].x==snake[i-1].x-size && snake[i].y==snake[i-1].y && snake[i].x==snake1[i].x && snake[i].y==snake1[i].y-size)
                    LoadMedia("snake's body/snakeUpRightOrLeftDown.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i].x==snake[i-1].x+size && snake[i].y==snake[i-1].y && snake[i].x==snake1[i].x && snake[i].y==snake1[i].y-size)
                    LoadMedia("snake's body/snakeUpLeftOrRightDown.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i].x==snake[i-1].x-size && snake[i].y==snake[i-1].y && snake[i].x==snake1[i].x && snake[i].y==snake1[i].y+size)
                    LoadMedia("snake's body/snakeDownRightOrLeftUp.png",snake[i].x,snake[i].y,size,size);

                else
                    LoadMedia("snake's body/snakeLeftRight.png",snake[i].x,snake[i].y,size,size);

            }
            if(i!=snakelength-1 && snake[i].x==snake[i-1].x){
                if(snake[i].x==snake[i-1].x && snake[i].y==snake[i-1].y+size && snake[i].y==snake1[i].y && snake[i].x==snake1[i].x+size)
                    LoadMedia("snake's body/snakeDownLeft.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i].x==snake[i-1].x && snake[i].y==snake[i-1].y-size && snake[i].y==snake1[i].y && snake[i].x==snake1[i].x-size)
                    LoadMedia("snake's body/snakeUpRightOrLeftDown.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i].x==snake[i-1].x && snake[i].y==snake[i-1].y-size && snake[i].y==snake1[i].y && snake[i].x==snake1[i].x+size)
                    LoadMedia("snake's body/snakeUpLeftOrRightDown.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i].x==snake[i-1].x && snake[i].y==snake[i-1].y+size && snake[i].y==snake1[i].y && snake[i].x==snake1[i].x-size)
                    LoadMedia("snake's body/snakeDownRightOrLeftUp.png",snake[i].x,snake[i].y,size,size);

                else
                    LoadMedia("snake's body/snakeUpDown.png",snake[i].x,snake[i].y,size,size);

            }
            if(i==snakelength-1){
                if(snake[i-1].y==snake[i].y && snake[i-1].x+size==snake[i].x)
                    LoadMedia("snake's body/snakeEndRight.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i-1].y==snake[i].y && snake[i-1].x-size==snake[i].x)
                    LoadMedia("snake's body/snakeEndLeft.png",snake[i].x,snake[i].y,size,size);

                else if(snake[i-1].x==snake[i].x && snake[i-1].y+size==snake[i].y)
                    LoadMedia("snake's body/snakeEndDown.png",snake[i].x,snake[i].y,size,size);

                else
                    LoadMedia("snake's body/snakeEndUp.png",snake[i].x,snake[i].y,size,size);
            }
		}
    }
}
void checkmove(){
    while(SDL_PollEvent(&e)!=0){
        if(e.type == SDL_KEYDOWN ){
            switch(e.key.keysym.sym){
                case SDLK_LEFT:{
                    if(dir.x!=size && snake[0].y!=snake[1].y){
                    dir.x = -size; dir.y = 0;
                    }
                    break;
                }
                case SDLK_RIGHT:{
                    if(dir.x!=(-size) && snake[0].y!=snake[1].y){
                    dir.x = size; dir.y = 0;
                    }
                    break;
                }
                case SDLK_UP:{
                    if(dir.y!=size && snake[0].x!=snake[1].x){
                    dir.y = -size; dir.x = 0;
                    }
                    break;
                }
                case SDLK_DOWN:{
                    if(dir.y!=(-size)&& snake[0].x!=snake[1].x){
                    dir.y = size; dir.x = 0;
                    }
                    break;
                }
                default: break;
            }
        }
    }
}
