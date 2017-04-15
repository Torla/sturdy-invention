#include <iostream>
#include <string>
//#include "position.h"
#include "grafic.h"


using namespace std;


int main() {
    window *win = new window("Test",300,300);
    cout << win->getName() <<  " " << win->getWidth() << " " << win->getHight() << endl;
    texture *tex = new texture("img/test.jpg",win);
    win->clear();
    win->put(tex,10,10,100,100);
    win->show();
    SDL_Delay(1000);
    delete win;
    return 0;
}

