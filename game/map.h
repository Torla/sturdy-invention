#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "screen.h"
#include "obj.h"
#include <list>
#include <string>
#include <sstream>

namespace mapPar {
const int MapHeight=20;
const int MapWidth=41;
}

class mapCell{
    tile floor_tile;
    bool blocked;
public:
    std::list<int> objectHere;
    mapCell(tile t=STANDARD_FLOOR):floor_tile(t),blocked(false) {};
    bool isBlocked() {
        return blocked;
    }
    void setBlocked(bool x) {
        blocked=x;
    }
    bool isEmpty() {
        return objectHere.empty();
    }
    void add(int id) {
        objectHere.push_front(id);
    }
    void remove(int id) {
        objectHere.remove(id);
    }
    void clear(){
        objectHere.clear();
    }
    void show(int x,int y){
        screen.putOnMap(floor_tile,x,y,0);
    }
    operator std::string() {
        std::stringstream s;
        s << "tile: " << floor_tile << " Blocked:" << blocked << " Object here: " << std::endl;
        for(int id:objectHere) {
            s  << "    " << id << " " << (std::string)(*(obj::ind[id])) << std::endl;
        }
        return s.str();
    }
};


class mapClass:screnable{

mapCell map[mapPar::MapWidth][mapPar::MapHeight];

public:
    mapClass():screnable(){};
    mapCell* operator()(int x,int y);
    mapCell* operator()(position pos){return (*this)(pos.get_position_x(),pos.get_position_y());}
    bool show();
};

extern mapClass map;
#endif // MAP_H_INCLUDED
