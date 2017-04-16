#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <array>
#include <list>

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

class screnable {
public:
    screnable();
    virtual bool show()=0;
};

class screen_class {
    window* win;
    std::list<screnable*> toShowList;
public:
    screen_class() {
        win=new window("Test",screenPar::WinWidth,screenPar::WinHeight);
        win->clear();
        win->show();
    }
    ~screen_class() {
        delete win;
    }
    window* getWindow() {
        return win;
    }
    void addToShow(screnable* inst){
        toShowList.push_back(inst);
    }
    void removeToShow(screnable* inst){
        toShowList.remove(inst);
    }
    void show() {
        win->clear();
        for(screnable* i:toShowList){
            i->show();
        }
        win->show();
    }
    void put(tile t,int x,int y,int w,int h,int angle=0) {
        win->put(tileset[t],x,y,w,h,angle);
    }
};

extern screen_class screen;



#endif // SCREEN_H_INCLUDED
