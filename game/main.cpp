#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"
#include "map.h"



using namespace std;



int main() {
    obj* o=new obj(20,10,N,TEST2);
    obj* o2=new obj(11,10,N,TEST2);
    cout << (std::string)*map(20,10);
    screen.show();
    SDL_Delay(1000);
    delete o;
    delete o2;
    return 0;
    SDL_Quit();
    IMG_Quit();
}

