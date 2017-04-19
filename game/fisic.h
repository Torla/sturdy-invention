#ifndef FISIC_H_INCLUDED
#define FISIC_H_INCLUDED


#include "position.h"

//delta velocity/frame=force/mass-friction*velocity
class fisics {
    struct velocityStruct {
        int sud; //blocks per 100 frame
        int frameCountSud;
        int est;
        int frameCountEst;
        velocityStruct():sud(0),frameCountSud(0),est(0),frameCountEst(0) {};
    } velocity;
    int mass;
    float friction;
protected:
    void setFriction(float x) {
        friction=x;
    }
    void setMass(int x) {
        mass=x;
    }
    void frame();
public:
    fisics(int mass,float friction):mass(mass),friction(friction) {};
    void push(direction dir,int force);
    virtual void move(direction)=0;

};


#endif // FISIC_H_INCLUDED
