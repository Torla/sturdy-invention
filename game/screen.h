#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED

#include <array>
#include <set>
#include <algorithm>

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
    PLAYER,
    WALL,
    LIFEBAR,
    LIFEBARFRAME,
    TILENUM,
};


extern std::array<texture*,TILENUM> tileset;

class screnable {
    int layer;
public:
    screnable(int layer);
    virtual ~screnable();
    virtual bool show() const=0;
    struct compare {
        bool operator()(screnable* const& a,screnable* const& b) const {
            if(a->layer!=b->layer)return a->layer<b->layer;
            else return a<b;
        }
    };
};


class screen_class {
    window* win;
    std::set<screnable*,screnable::compare> toShowList;
    screen_class(const screen_class&)=delete;
    screen_class& operator=(const screen_class&)=delete;
public:
    screen_class():win(new window("Test",screenPar::WinWidth,screenPar::WinHeight)),toShowList(){
        win->clear();
        win->show();
    }
    ~screen_class() {
        delete win;
    }
    window* getWindow() const {
        return win;
    }
    void addToShow(screnable* inst) {
        toShowList.insert(inst);
    }
    void removeToShow(screnable* inst) {
        toShowList.erase(inst);
    }
    void show() const {
        win->clear();
        for(screnable* i:toShowList) {
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
