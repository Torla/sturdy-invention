#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"
#include "mapLayoutLoader.h"
#include "fisic.h"
#include "wall.h"
#include "player.h"

using namespace std;

int main() {
    mapLayoutLoader::load("map/1.txt");
    objHandler(0)->push(E,100);
    for(int i=0; i<300; i++) {
        cout << *player->getHandler() << endl;
        if(i<=100) player->push(E,1);
        else player->push(S,2);
        obj::ind.forEach([](obj* & x) {
            x->frame();
        });
        SDL_Delay(10);
        if(!(i%3)) screen.show();
    }
    SDL_Delay(500);
    obj::ind.forEach([](obj* & x) {
        delete x;
    });
    IMG_Quit();
    SDL_Quit();
    return 0;
}

