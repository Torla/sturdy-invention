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
    obj* o=new blockingObj(1,10,1,0.5,E,PLAYER);
    mapLayoutLoader::load("map/1.txt");
    cout << (string)*map(0,0);
    for(int i=0; i<500; i++) {
        if(i<=200) o->push(E,1);
        obj::ind.forEach([](obj* & x) {
            x->frame();
        });
        SDL_Delay(10);
        screen.show();
    }
    SDL_Delay(500);
    obj::ind.forEach([](obj* & x) {
        delete x;
    });
    IMG_Quit();
    SDL_Quit();
    return 0;
}

