#include"declare.h"
#include"loadMedia.h"

void LoadMedia(string path, int x, int y, int w, int h){
    SDL_Surface* load = NULL;
    load=IMG_Load(path.c_str());
    if(load==NULL)
        cout<< "not found image in "<< path.c_str() << endl;
    else{
        texture = SDL_CreateTextureFromSurface(renderer, load);
        SDL_FreeSurface(load);
        SDL_Rect filled;
        filled.x = x;
        filled.y = y;
        filled.w =w;
        filled.h =h;
        SDL_RenderCopy(renderer, texture, NULL, &filled);
        SDL_DestroyTexture(texture);
    }
}
