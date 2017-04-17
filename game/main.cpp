#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"



using namespace std;



int main() {
    new obj(20,19,S,TEST2);
    new obj(20,19,S,TEST2);
    new obj(20,19,S,TEST2);
    cout << (std::string)*map(20,19);
    screen.show();
    SDL_Delay(1000);
    obj::ind.freeAll();
    screen.show();
    SDL_Delay(1000);
    SDL_Quit();
    IMG_Quit();
    return 0;
}

