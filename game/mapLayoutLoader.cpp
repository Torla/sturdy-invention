#include "mapLayoutLoader.h"

#include <string>
#include <sstream>
#include <fstream>
#include "map.h"
#include "wall.h"

using namespace mapPar;

void mapLayoutLoader::placeObject(char sym,int x,int y) {
    switch (sym) {
    case '.':
        break;
    case 'W':
        new wall(x,y);
        break;
    }
}

void mapLayoutLoader::load(std::string path) {
    int x,y;
    std::ifstream file(path.c_str());
    std::string row;
    for(y=0; y<MapHeight; y++) {
        file >> row;
        for(x=0; x<MapWidth; x++) {
            map(x,y)->clear();
            map.map[x][y].setBlocked(false);
            placeObject(row[x],x,y);
        }
    }
}
