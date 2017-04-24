#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "screen.h"
#include "obj.h"
#include "mapLayoutLoader.h"
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
    int blocker;
    std::set<int> objectHere;
public:
    mapCell(tile t=STANDARD_FLOOR):floor_tile(t),blocked(false) {};
    bool isBlocked() const {
        return blocked;
    }
    void setBlocked(bool x) {
        blocked=x;
    }
    void setBlocker(int x) {
        blocker=x;
    }
    int getBlocker() const {
        return blocker;
    }
    bool isEmpty() const {
        return objectHere.empty();
    }
    void add(int id){
        objectHere.insert(id);
    }
    void remove(int id) {
        objectHere.erase(id);
    }
    void clear() {
        objectHere.clear();
    }
    std::set<int>::iterator begin() const {
        return objectHere.begin();
    }
    std::set<int>::iterator end() const {
        return objectHere.end();
    }
    void show(int x,int y) const {
        screen.putOnMap(floor_tile,x,y,0);
    }
    operator std::string() const {
        std::stringstream s;
        s << "tile: " << floor_tile << " Blocked:" << blocked << " Blocker:" << blocker <<  " Object here: " << std::endl;
        for(auto id:*this) {
            s  << "    " << id << " " << (std::string)(*(obj::ind[id])) << std::endl;
        }
        return s.str();
    }
};


class mapClass:screnable {
    friend mapLayoutLoader;
    mapCell map[mapPar::MapWidth][mapPar::MapHeight];
public:
    mapClass():screnable(1) {};
    mapCell* operator()(const int x,const int y);
    mapCell* operator()(position pos) {
        return (*this)(pos.get_position_x(),pos.get_position_y());
    }
    static bool inBoundaries(const int x,const int y){
        if(x>=mapPar::MapWidth || x<0) return false;
        if(y>=mapPar::MapHeight || y<0) return false;
        return true;
    }
    bool show() const override;
};

extern mapClass map;
#endif // MAP_H_INCLUDED

