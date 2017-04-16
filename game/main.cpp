#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"



using namespace std;



int main() {
    new obj(20,10,N,TEST2);
    new obj(11,10,N,TEST2);
    new obj(11,10,N,TEST);
    new obj(9,10,N,TEST2);
    screen.show();
    SDL_Delay(1000);
    obj::ind.freeAll();
    screen.show();
    SDL_Delay(1000);
    SDL_Quit();
    IMG_Quit();
    return 0;
}

