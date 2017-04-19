#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"
#include "fisic.h"



using namespace std;



int main() {
    obj* o=new obj(0,0,1,0.2,N,TEST2);
    o->push(SE,100);
    for(int i=0; i<1000; ++i) {
        o->push(N,1);
        o->frame();
        screen.show();
        SDL_Delay(10);
    }
    SDL_Delay(1000);
    obj::ind.forEach([](obj* & x) {
        delete x;
    });
    SDL_Quit();
    IMG_Quit();
    return 0;
}

