#include "screen.h"

screen_class screen;

std::array<texture*,TILENUM> tileset ={
NULL,
new texture("img/test.jpg",screen.getWindow())
};
