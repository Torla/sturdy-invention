#include <iostream>
#include <string>
//#include "position.h"
#include "screen.h"


using namespace std;


int main() {
int i;
for(i=0;i<100;i++){
    screen.clear();
    screen.put(TEST,(i*25)%1000,(i*25)%1000,25,25);
    screen.show();
    SDL_Delay(33);
}
    SDL_Delay(1000);
    return 0;
}

