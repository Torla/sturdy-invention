#include "obj.h"
#include "index.h"
#include "index_imp.h"

const int indexDim=1000;

int obj::id_counter=0;
indexof<obj> obj::ind(indexDim);

obj::obj(int x,int y,direction dir,tile t):pos(x,y){
    id=id_counter++;
    this->dir=dir;
    this->t=t;
    if(ind.add(*this)){
        std::cout << "Err: inpossible adding obj in index (obj id " << id << ")" << std::endl;
    }
}

obj::~obj(){
ind.remove(*this);
}
