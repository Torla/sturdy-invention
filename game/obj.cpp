#include "obj.h"
#include "index.h"
#include "index_imp.h"
#include "map.h"

const int indexDim=1000;

int obj::id_counter=0;
indexof<obj> obj::ind(indexDim);

obj::obj(int x,int y,direction dir,tile t):screnable(),pos(x,y),dir(dir) {
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


bool obj::show() {
    screen.put(t,pos.get_position_x()*20+screenPar::MapPosx,pos.get_position_y()*20+screenPar::MapPosy,20,20,dir);
    return false;
}
