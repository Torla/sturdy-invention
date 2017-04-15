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
    operator int() const {
        return x+y;
    }
    position(int x,int y);
    position();
    void move(int x,int y);
    int get_position_x() {
        return x;
    }
    int get_position_y() {
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


#endif // POSITION_H_INCLUDED
