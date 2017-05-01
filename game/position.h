#ifndef POSITION_H_INCLUDED
#define POSITION_H_INCLUDED

#define ass(x) (((x)>0)?(x):(-x))

#include <iostream>
#include <string>
#include <sstream>

#include "index.h"
#include "index_imp.h"

class position {
    int x;
    int y;
public:
    position(int x,int y);
    void move(int x,int y);
    int get_position_x() const {
        return x;
    }
    int get_position_y() const {
        return y;
    }
    float distance(const position & p);
    float distance(int x,int y);
    int distance_man(const position & p);//da fixare
    int distance_man(int x,int y);
    operator std::string() const {
        std::stringstream s;
        s << '(' << x << ',' << y << ')';
        return s.str();
    }
};


struct direction {
    int angle;
    direction(int x=0):angle(x) {};
    operator int() const {
        return angle%360;
    }
    direction& operator=(int x) {
        angle=x;
        return *this;
    }

};


enum directionCardinal {N=0,
                        NE=45,
                        E=90,
                        SE=135,
                        S=180,
                        SW=225,
                        W=270,
                        NW=315,
                       };
#endif // POSITION_H_INCLUDED
