#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"



using namespace std;



int main() {
    obj* o=new obj(5,5,NW,TEST2);
    new obj(0,0,S,TEST2);
    new obj(10,15,N,TEST2);
    new obj(6,7,SW,TEST2);
    cout << (std::string)*map(5,5);
    o->move(0,0);
    cout << (std::string)*map(0,0);
    screen.show();
    SDL_Delay(1000);
    obj::ind.freeAll();
    screen.show();
    SDL_Delay(1000);
    SDL_Quit();
    IMG_Quit();
    return 0;
}

