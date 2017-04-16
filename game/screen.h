#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <array>

#include "grafic.h"


namespace screenPar {
const int WinHeight=600;
const int WinWidth=1025;
const int MapHeight=500;
const int MapWidth=1025;
const int MapPosx=0;
const int MapPosy=100;
const int HudPosx=0;
const int HudPosy=0;
const int HudHeight=100;
const int HudWidth=1025;
}

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
        win=new window("Test",screenPar::WinWidth,screenPar::WinHeight);
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

class screnable {
public:
    virtual bool show()=0;
};

#endif // SCREEN_H_INCLUDED
