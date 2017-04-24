#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED

#include <string>
#include <sstream>
#include <hashtable.h>

#include "index.h"
#include "screen.h"
#include "position.h"
#include "fisic.h"

namespace objPar {

}

class obj;

class objHandler{
static std::hash<int> h;
int id;
public:
    objHandler(int x=0):id(x){}
    void operator=(int &x){id=x;}
    friend bool operator==(const objHandler & a,const objHandler & b){return a.id==b.id;}
    obj* operator->();
    obj& operator*();
    operator int() const {return id;}
    struct hash{
    size_t operator()(const objHandler & x) const {
            return h(x);
        }
    };
};

class obj:public screnable,public fisics {
    static int id_counter;
    objHandler id;
protected:
    position pos;
    tile t;
public:
    direction dir;
    static indexof<objHandler,obj> ind;
    obj(int x,int y,float mass,float friction,direction dir=N,tile t=EMPTY,int layer=2);
    virtual ~obj();
    position getPosition() const {
        return pos;
    }
    direction getDirection() const {
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
    operator objHandler() const{
        return id;
    };
    virtual bool show() const override;
    virtual void frame() {
        fisics::fisicsFrame();
    }
    virtual operator std::string() const{
        std::stringstream s;
        s <<"id: "<<id << " tile:" << t << " pos:" << (std::string)pos << " dir:" << dir << " " << fisics::operator std::string();
        return s.str();
    }
    friend std::ostream& operator<< (std::ostream& out , obj & o){
        out << (std::string)o;
        return out;
    }
};

class blockingObj:public obj {
public:
    blockingObj(int x,int y,float mass,float friction,direction dir=N,tile t=EMPTY,int layer=2);
    ~blockingObj();
    virtual void move(int x,int y) override;
    virtual void hit(int) {};
    virtual operator std::string() const override{
        std::stringstream s;
        s << "blocking " << obj::operator std::string();
        return s.str();
    }
};

inline obj* objHandler::operator->(){return obj::ind.find(id);}
inline obj& objHandler::operator*(){return *(obj::ind.find(id));}

#endif // OBJ_H_INCLUDED
