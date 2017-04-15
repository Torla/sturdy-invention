#include "grafic.h"

#include "iostream"

bool window::isinit=false;
bool texture::isinit=false;

window::window(const char* nome,int w,int h) {
    if(!isinit) {
        if(SDL_Init(SDL_INIT_VIDEO)<0) {
            std::cout << "SDL_Init error" << SDL_GetError() << std::endl;
        }
        isinit=true;
    }
    win=SDL_CreateWindow(nome,SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,w,h,SDL_WINDOW_SHOWN);
    if (win==NULL) {
        std::cout << "SDL_window create error " << SDL_GetError() << std::endl;
        return;
    }
    renderer=SDL_CreateRenderer(win,-1,SDL_RENDERER_ACCELERATED);
    if (renderer==NULL) {
        std::cout << "SDL_window create error " << SDL_GetError() << std::endl;
        return;
    }
    SDL_SetRenderDrawColor(renderer,0xFF,0xFF,0xFF,0xFF);
    return;
}

window::~window() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(win);
}

void window::put(texture *tex,int x,int y,int w,int h,int angle) {
    SDL_Rect sc;
    sc.x=x;
    sc.y=y;
    sc.w=w;
    sc.h=h;
    SDL_RenderCopyEx(renderer,tex->getTexture(),NULL,&sc,angle,NULL,SDL_FLIP_NONE);
}



texture::texture(const char* path,window *win,bool colorKey,int r,int g,int b) {
    SDL_Surface *surf;
    if(!isinit) {
        if(IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG)<0) {
            std::cout << "IMG init error" << IMG_GetError() << std::endl;
            return;
        }
    }
    surf=IMG_Load(path);
    if(surf==NULL) {
        std::cout << " Error loading:" << path << IMG_GetError()  << std::endl;
        return;
    }
    if(colorKey) {
        SDL_SetColorKey(surf,SDL_TRUE, SDL_MapRGB(surf->format,r,g,b));
    }
    tex=SDL_CreateTextureFromSurface(win->getRenderer(),surf);
    SDL_FreeSurface(surf);
    if(tex==NULL) {
        std::cout << " Error crating surface" << IMG_GetError() << std::endl;
        return;
    }
    return;
}

texture::~texture() {
    SDL_DestroyTexture(tex);
}
