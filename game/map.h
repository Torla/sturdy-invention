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

class mapCell {
    tile floor_tile;
    bool blocked;
public:
    std::list<int> objectHere;
    mapCell(tile t=EMPTY):floor_tile(t),blocked(false) {};
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
    operator std::string() {
        std::stringstream s;
        s << "tile: " << floor_tile << " Blocked:" << blocked << " Object here: " << std::endl;
        for(int id:objectHere) {
            s  << "    " << id << " " << (std::string)(*(obj::ind[id])) << std::endl;
        }
        return s.str();
    }
};


class mapClass{

mapCell map[mapPar::MapWidth][mapPar::MapHeight];

public:
    mapClass(){};
    mapCell* operator()(int x,int y){return &map[x][y];}
    mapCell* operator()(position pos){return &map[pos.get_position_x()][pos.get_position_y()];}

};

extern mapClass map;
#endif // MAP_H_INCLUDED
