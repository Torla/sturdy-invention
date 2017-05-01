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
    window(const window&)=delete;
    window& operator=(const window&)=delete;
    std::string getName() const {
        std::string str(SDL_GetWindowTitle(win));
        return str;
    }
    int getWidth() const {
        int w;
        SDL_GetWindowSize(win,&w,nullptr);
        return w;
    }
    int getHight() const {
        int h;
        SDL_GetWindowSize(win,nullptr,&h);
        return h;
    }
    void setSize(int w,int h) {
        SDL_SetWindowSize(win,w,h);
    }
    SDL_Renderer *getRenderer() {
        return renderer;
    }
    void clear() {
        SDL_RenderClear(renderer);
    }
    void show() {
        SDL_RenderPresent(renderer);
    }
    void put(texture* tex,int x,int y,int w,int h,int angle=0);
};

class texture {
    static bool isinit;
    SDL_Texture* tex;
public:
    texture(const char *path,window *win,bool colorKey=false,int r=0x0,int g=0x0,int b=0x0);
    ~texture();
    texture(const texture&)=delete;
    texture& operator=(const texture&)=delete;
    SDL_Texture* getTexture() {
        return tex;
    }
};

#endif // GRAFIC_H_INCLUDED
