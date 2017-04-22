#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"
#include "mapLayoutLoader.h"
#include "fisic.h"
#include "wall.h"



using namespace std;



int main() {
    obj* o=new blockingObj(2,0,1,0.1,E,PLAYER);
    mapLayoutLoader::load("map/1.txt");
    screen.show();
    SDL_Delay(500);
    obj::ind.forEach([](obj* & x) {
        delete x;
    });
    SDL_Quit();
    IMG_Quit();
    return 0;
}

