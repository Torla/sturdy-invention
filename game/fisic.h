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
        velocityStruct():sud(0),frameCountSud(100),est(0),frameCountEst(100) {};
        operator std::string() const {
            std::stringstream s;
            s << "(" << sud << "," << est << ") ";
            return s.str();
        }
    } velocity;
    float mass;
    float friction;
protected:
    void setFriction(float x) {
        friction=x;
    }
    void setMass(int x) {
        mass=x;
    }
    void fisicsFrame();
public:
    fisics(float mass,float friction):velocity(),mass(mass),friction(friction){};
    virtual ~fisics(){};
    void push(direction dir,float force);
    virtual void move(direction)=0;
    operator std::string() const {
        std::stringstream s;
        s << "Mass: " << mass << " friction: " << friction << " vel: " << (std::string)velocity;
        return s.str();
    }

};


#endif // FISIC_H_INCLUDED
