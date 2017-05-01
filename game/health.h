#ifndef HEALTH_H_INCLUDED
#define HEALTH_H_INCLUDED

#include <iostream>
#include <string>
#include <sstream>

class health {
    int max;
    int point;
public:
    health(int max,int point=-1):max(max),point(point) {
        if(point>max) point=max;
        if(point==-1) point=max;
    }
    int getMax() const {
        return max;
    }
    void setMax(int max) {
        this->max=max;
    }
    int getPoint() const  {
        return point;
    }
    void setPoint(int point) {
        this->point=point;
    }
    void setToMax() {
        point=max;
    }
    void damage(int x) {
        point-=x;
        if(point<0) point=0;
    }
    void heal(int x) {
        point+=x;
        if(point>max) point=max;
    }
    operator std::string() const {
        std::stringstream s;
        s << point << '/' << max;
        return s.str();
    }
    friend std::ostream& operator << (std::ostream& out, health & o){
        out << (std::string)o;
        return out;
    }
};


#endif // HEALTH_H_INCLUDED
