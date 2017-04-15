#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <array>

#include "grafic.h"

enum tile {
    EMPTY,
    TEST,
    TEST2,
    TEST3,
    TILENUM,
};


extern std::array<texture*,TILENUM> tileset;

class screen_class {
    window* win;
public:
    screen_class() {
        win=new window("Test",1000,400);
        clear();
        show();
    }
    ~screen_class() {
        delete win;
    }
    window* getWindow() {
        return win;
    }
    void clear() {
        win->clear();
    }
    void show() {
        win->show();
    }
    void put(tile t,int x,int y,int w,int h,int angle=0) {
        win->put(tileset[t],x,y,w,h,angle);
    }
};

extern screen_class screen;

class screnable{
public:
    virtual bool show()=0;
};

#endif // SCREEN_H_INCLUDED
