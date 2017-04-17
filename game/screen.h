#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <array>
#include <set>

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
    STANDARD_FLOOR,
    TEST,
    TEST2,
    TEST3,
    TILENUM,
};


extern std::array<texture*,TILENUM> tileset;

class screnable {
    int layer;
public:
    screnable(int layer);
    virtual ~screnable();
    virtual bool show()=0;
    struct compareClass{
    bool operator()(screnable* const& a,screnable* const& b) const {return a->layer<b->layer;}
    };
};

class screen_class {
    window* win;
    std::set<screnable*,screnable::compareClass> toShowList;
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
        toShowList.insert(inst);
    }
    void removeToShow(screnable* inst){
        toShowList.erase(inst);
    }
    void show() {
        win->clear();
        for(screnable* i:toShowList){
            i->show();
        }
        win->show();
    }
    void put(tile t,int x,int y,int w,int h,int angle=0) {
        if(t==EMPTY) return;
        win->put(tileset[t],x,y,w,h,angle);
    }
    void putOnMap(tile,int,int,int);
};

extern screen_class screen;



#endif // SCREEN_H_INCLUDED
