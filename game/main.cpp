#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"
#include "fisic.h"
#include "wall.h"



using namespace std;



int main() {
    obj* o=new blockingObj(2,0,1,0.4,E,PLAYER);
    obj* o2=new wall(5,0);
    new wall(5,1);
    new wall(5,2);
    new wall(5,3);
    cout << (std::string)*map(5,0);
    o->push(SE,10);
    for(int i=0; i<100; ++i) {
        obj::ind.forEach([](obj* &x){x->frame();});
        screen.show();
        SDL_Delay(10);
    }
    SDL_Delay(500);
    obj::ind.forEach([](obj* & x) {
        delete x;
    });
    SDL_Quit();
    IMG_Quit();
    return 0;
}

