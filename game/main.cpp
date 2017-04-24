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
    obj* o=new blockingObj(20,10,1,0.5,E,PLAYER);
    mapLayoutLoader::load("map/1.txt");
    cout << *map(20,19) << endl;
    for(int i=0; i<300; i++) {
        if(i<=100) o->push(W,1);
        else o->push(E,1);
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

