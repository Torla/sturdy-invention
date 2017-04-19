#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

#include <string>
#include <sstream>

#include "index.h"
#include "screen.h"
#include "position.h"
#include "fisic.h"

namespace objPar {
const int indexDim=1000;
}

class obj:public indexable,public screnable,public fisics {
    static int id_counter;
    int id;
    position pos;
protected:
    tile t;
public:
    direction dir;
    static indexof<obj> ind;
    obj(int x,int y,int mass,float friction,direction dir=N,tile t=EMPTY,int layer=2);
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
    void move(position pos) {
        move(pos.get_position_x(),pos.get_position_y());
    }
    void move(direction dir);
    operator int() const {
        return id;
    }
    virtual bool show();
    virtual void frame() {
        fisics::frame();
    }
    virtual operator std::string() const {
        std::stringstream s;
        s << " " <<"id: "<<id << " tile:" << t << " pos:" << (std::string)pos << " dir:" << dir << " ";
        return s.str();
    }
};


#endif // OBJ_H_INCLUDED
