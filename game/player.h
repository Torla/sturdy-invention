#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "obj.h"
#include "position.h"
#include "health.h"
#include "screen.h"

namespace playerPar {
const float playerFriction=0.5;
const int playerMass=1;
const int playerScreenLayer=10;
const int startingMaxHp=100;
const int hpPositionX=10;
const int hpPositionY=10;
const int hpWidth=1000;
const int hpHeight=30;
}


class playerClass:public blockingObj {
    static bool exist;
    health hp;

public:
    playerClass(int x,int y);
    ~playerClass() {
        exist=false;
    }
    virtual bool show() const override{
        blockingObj::show();
        screen.put(LIFEBAR,playerPar::hpPositionX,playerPar::hpPositionY,(float)((float)hp.getPoint()/hp.getMax())*playerPar::hpWidth,playerPar::hpHeight);
        screen.put(LIFEBARFRAME,playerPar::hpPositionX,playerPar::hpPositionY,playerPar::hpWidth,playerPar::hpHeight);
        return false;
    }
    virtual void hit(int x) override{hp.damage(x);}
    virtual void heal(int x) {hp.heal(x);}
    virtual operator std::string() const {
        std::stringstream s;
        s << "player " << "hp:" << (std::string)hp << ' ' << blockingObj::operator std::string();
        return s.str();
    }
};

extern playerClass *player;

#endif // PLAYER_H_INCLUDED
