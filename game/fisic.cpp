#include "fisic.h"

#undef ass
#define ass(x) ((x>=0)?(x):(-x))

void fisics::fisicsFrame() {
    if(velocity.sud!=0  && velocity.frameCountSud--<=0) {
        if(velocity.sud>0) move(S);
        else if(velocity.sud<0) move(N);
        velocity.sud-=(velocity.sud*friction);
        if(velocity.sud!=0) velocity.frameCountSud=100/ass(velocity.sud);
        else velocity.frameCountSud=100;
    }
    if(velocity.est!=0 && velocity.frameCountEst--<=0) {
        if(velocity.est>0) move(E);
        else if(velocity.est<0) move(W);
        velocity.est-=(velocity.est*friction);
        if(velocity.est!=0) velocity.frameCountEst=100/ass(velocity.est);
        else velocity.frameCountEst=100;
    }
}

void fisics::push(direction dir,float force) {
    float sud=0;
    float est=0;
    const float rad2=1.42;
    switch (dir) {
    case N:
        sud=-1;
        est=0;
        break;

    case NE:
        sud=-1;
        est=1;
        break;

    case E:
        sud=0;
        est=1;
        break;

    case SE:
        sud=1;
        est=1;
        break;

    case S:
        sud=1;
        est=0;
        break;

    case SW:
        sud=1;
        est=-1;
        break;

    case W:
        sud=0;
        est=-1;
        break;

    case NW:
        sud=-1;
        est=-1;
        break;
    }
    if((int)sud && (int)est) {
        sud/=rad2;
        est/=rad2;
    }
    if((int)sud) {
        velocity.sud+=(force*sud)/mass;
        if(velocity.sud!=0 && 100/ass(velocity.sud) < velocity.frameCountSud) velocity.frameCountSud=100/ass(velocity.sud);
    }
    if((int)est) {
        velocity.est+=(force*est)/mass;
        if(velocity.est!=0 && 100/ass(velocity.est) < velocity.frameCountEst) velocity.frameCountEst=100/ass(velocity.est);
    }

    return;
}
