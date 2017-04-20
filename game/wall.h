#ifndef WALL_H_INCLUDED
#define WALL_H_INCLUDED

#include "obj.h"
namespace wallPar{
const int wallMass=1000000;
const int wallFriction=1;
};

class wall:public blockingObj{
public:
wall(int x,int y):blockingObj(x,y,wallPar::wallMass,wallPar::wallFriction,N,WALL,2){};
    virtual operator std::string() const {
        std::stringstream s;
        s << "wall " << blockingObj::operator std::string();
        return s.str();
    }
};


#endif // WALL_H_INCLUDED
