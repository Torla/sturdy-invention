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
protected:
    position pos;
    tile t;
public:
    direction dir;
    static indexof<obj> ind;
    obj(int x,int y,float mass,float friction,direction dir=N,tile t=EMPTY,int layer=2);
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
    virtual void move(int x,int y);
    virtual void move(position pos) {
        move(pos.get_position_x(),pos.get_position_y());
    }
    virtual void move(direction dir);
    operator int() const {
        return id;
    }
    virtual bool show();
    virtual void frame() {
        fisics::frame();
    }
    virtual operator std::string() const {
        std::stringstream s;
        s <<"id: "<<id << " tile:" << t << " pos:" << (std::string)pos << " dir:" << dir << " " << fisics::operator std::string();
        return s.str();
    }
};

class blockingObj:public obj {
public:
    blockingObj(int x,int y,float mass,float friction,direction dir=N,tile t=EMPTY,int layer=2);
    ~blockingObj();
    virtual void move(int x,int y);
    virtual operator std::string() const {
        std::stringstream s;
        s << "blocking " << obj::operator std::string();
        return s.str();
    }
};

#endif // OBJ_H_INCLUDED
