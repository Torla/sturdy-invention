#include "screen.h"
#include "map.h"

using namespace screenPar;

screen_class screen;

std::array<texture*,TILENUM> tileset = {
    NULL,
    new texture("img/standard_floor.jpg",screen.getWindow()),
    new texture("img/test.bmp",screen.getWindow()),
    new texture("img/test2.bmp",screen.getWindow(),true),
};


screnable::screnable(int layer):layer(layer){
screen.addToShow(this);
}

screnable::~screnable(){
screen.removeToShow(this);
}

void screen_class::putOnMap(tile t,int x,int y, int angle){
    if(t==EMPTY) return;
    int tileDimH=MapHeight/mapPar::MapHeight;
    int tileDimW=MapWidth/mapPar::MapWidth;
    win->put(tileset[t],x*tileDimW+MapPosx,y*tileDimH+MapPosy,tileDimW,tileDimH,angle);
}
