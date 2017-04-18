#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

#include <string>
#include <sstream>

#include "index.h"
#include "screen.h"
#include "position.h"

namespace objPar{
    const int indexDim=1000;
}

class obj:public indexable,public screnable {
    static int id_counter;
    int id;
    position pos;
protected:
    tile t;
public:
    direction dir;
    static indexof<obj,objPar::indexDim> ind;
    obj(int x,int y,direction dir=N,tile t=EMPTY,int layer=2);
    virtual ~obj();
    position getPosition() {
        return pos;
    }
    direction getDirection() {
        return dir;
    }
    void setDirection(direction dir) {
        this->dir=dir;
    }
    void move(int x,int y);
    operator int() const {
        return id;
    }
    virtual bool show();
    virtual operator std::string() const {
        std::stringstream s;
        s << " " <<"id: "<<id << " tile:" << t << " pos:" << (std::string)pos << " dir:" << dir << " ";
        return s.str();
    }
};


#endif // OBJ_H_INCLUDED
