#include "position.h"

#include <math.h>



position::position(int x,int y){
this->x=x;
this->y=y;
return;

}position::position(){
this->x=0;
this->y=0;
return;
}

void position::move(int x,int y){
this->x=x;
this->y=y;
return;
}

float position::distance(int x,int y){
return sqrt(pow(this->x-x,2)+pow(this->y-y,2));
}

float position::distance(const position & p){
return distance(p.x,p.y);
}

int position::distance_man(int x,int y){
return ass(((this->x)-(x))+((this->y)-(y)));
}

int position::distance_man(const position & p){
return this->distance_man(p.x,p.y);
}
