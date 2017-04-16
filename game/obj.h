#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

#include <string>
#include <sstream>

#include "index.h"
#include "screen.h"
#include "position.h"



class obj:public indexable,public screnable {
    static int id_counter;
    int id;
protected:
    tile t;
public:
    position pos;
    direction dir;
    static indexof<obj> ind;
    obj(int x,int y,direction dir=N,tile t=EMPTY);
    virtual ~obj();
    direction getDirection() {
        return dir;
    }
    void setDirection(direction dir) {
        this->dir=dir;
    }
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
