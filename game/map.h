#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED

#include "screen.h"
#include "obj.h"
#include <list>
#include <string>
#include <sstream>

namespace mapPar {
const int MapHeight=41;
const int Mapwidth=20;
}

class mapCell {
    tile floor_tile;
    bool blocked;
public:
    std::list<int> objectHere;
    mapCell(tile t):floor_tile(t),blocked(false) {};
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
    operator std::string() {
        std::stringstream s;
        s << "tile: " << floor_tile << " Blocked:" << blocked << " Object here: " << std::endl;
        for(int id:objectHere) {
            s  << "    " << id << " " << (std::string)(*(obj::ind.find(id))) << std::endl;
        }
        return s.str();
    }
};


#endif // MAP_H_INCLUDED
