#include <iostream>
#include <string>
#include "position.h"
#include "screen.h"
#include "obj.h"


using namespace std;



int main() {
    position p;
    obj* o=new obj(0,0);
    cout << (string)(*o) << endl;
    SDL_Delay(1000);
    delete o;
    return 0;
}

