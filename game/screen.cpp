#include "screen.h"

screen_class screen;

std::array<texture*,TILENUM> tileset = {
    NULL,
    new texture("img/test.bmp",screen.getWindow()),
    new texture("img/test2.bmp",screen.getWindow(),true),
};


screnable::screnable(){
screen.addToShow(this);
}
