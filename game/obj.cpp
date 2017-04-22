#include "obj.h"
#include "index.h"
#include "index_imp.h"
#include "map.h"

using namespace objPar;

int obj::id_counter=0;
indexof<obj> obj::ind;

obj::obj(int x,int y,float mass,float friction,direction dir,tile t,int layer):screnable(layer),fisics(mass,friction),pos(x,y),dir(dir) {
    id=id_counter++;
    this->t=t;
    if(ind.add(*this)) {
        std::cout << "Err: inpossible adding obj in index (obj id " << id << ")" << std::endl;
    }
    map(pos)->add(*this);
}

obj::~obj() {
    map(pos)->remove(*this);
    ind.remove(*this);
}

void obj::move(int x,int y) {
    if(!mapClass::inBoundaries(x,y)) return;
    map(pos)->remove(*this);
    pos.move(x,y);
    map(pos)->add(*this);
}

void obj::move(direction dir) {
    int x=0,y=0;
    switch (dir) {
    case N:
        x=-1;
        y=0;
        break;

    case NE:
        x=-1;
        y=1;
        break;

    case E:
        x=0;
        y=1;
        break;

    case SE:
        x=1;
        y=1;
        break;

    case S:
        x=1;
        y=0;
        break;

    case SW:
        x=1;
        y=-1;
        break;

    case W:
        x=0;
        y=-1;
        break;

    case NW:
        x=-1;
        y=-1;
        break;
    }
    move(pos.get_position_x()+y,pos.get_position_y()+x);
}

bool obj::show() {
    screen.putOnMap(t,pos.get_position_x(),pos.get_position_y(),dir);
    return false;
}


blockingObj::blockingObj(int x,int y,float mass,float friction,direction dir,tile t,int layer):obj(x,y,mass,friction,dir,t,layer) {
    map(x,y)->setBlocked(true);
}

blockingObj::~blockingObj() {
    map(pos)->setBlocked(false);
}
void blockingObj::move(int x,int y) {
    if(!mapClass::inBoundaries(x,y)) return;
    if(map(x,y)->isBlocked()) return;
    map(pos)->setBlocked(false);
    obj::move(x,y);
    map(pos)->setBlocked(true);
    return;
}
