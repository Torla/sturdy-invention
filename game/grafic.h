#ifndef GRAFIC_H_INCLUDED
#define GRAFIC_H_INCLUDED

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>

class texture;

class window {
    static bool isinit;
    SDL_Window* win;
    SDL_Renderer* renderer;
public:
    window(const char* nome,int w,int h);
    ~window();
    std::string getName() {
        std::string str(SDL_GetWindowTitle(win));
        return str;
    }
    int getWidth() {
        int w;
        SDL_GetWindowSize(win,&w,NULL);
        return w;
    }
    int getHight() {
        int h;
        SDL_GetWindowSize(win,NULL,&h);
        return h;
    }
    void setSize(int w,int h){SDL_SetWindowSize(win,w,h);}
    SDL_Renderer *getRenderer(){return renderer;}
    void clear(){SDL_RenderClear(renderer);}
    void show(){SDL_RenderPresent(renderer);}
    void put(texture* tex,int x,int y,int w,int h);
};

class texture{
    static bool isinit;
    SDL_Texture* tex;
public:
    texture(const char *path,window *win);
    ~texture();
    SDL_Texture* getTexture(){return tex;}
};

#endif // GRAFIC_H_INCLUDED