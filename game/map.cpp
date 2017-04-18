#include "map.h"

mapClass map;

using namespace mapPar;

mapCell* mapClass::operator()(int x,int y) {
    if(x>MapWidth || y>MapHeight || x<0 || y<0) {
        std::cout << "Err: access on mapclass over boundaries " << x << " " << y << std::endl;
        return NULL;
    }
    return &map[x][y];
}

bool mapClass::show() {
    for(int i=0; i<MapWidth; i++) {
        for(int j=0; j<MapHeight; j++) {
            map[i][j].show(i,j);
        }
    }
    return false;
}

