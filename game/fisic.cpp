#include "fisic.h"


void fisics::frame() {
    if(velocity.frameCountSud--<=0 && velocity.sud!=0) {
        if(velocity.sud>0) move(S);
        else if(velocity.sud<0) move(N);
        velocity.sud-=(velocity.sud*friction);
        if(velocity.sud!=0) velocity.frameCountSud=100/velocity.sud;
    }
    if(velocity.frameCountEst--<=0 && velocity.est!=0) {
        if(velocity.est>0) move(E);
        else if(velocity.est<0) move(W);
        velocity.est-=(velocity.est*friction);
        if(velocity.est!=0) velocity.frameCountEst=100/velocity.est;
    }
}

void fisics::push(direction dir,int force) {
int sud=0;
int est=0;
const int rad2=1.42;
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
if(sud && est){
    sud*=rad2;
    est*=rad2;
}
if(sud){
    if(((velocity.sud+(force*sud)/mass)*velocity.sud)<0) velocity.frameCountSud=0;
    velocity.sud+=(force*sud)/mass;
}

if(est){
    if(((velocity.est+(force*est)/mass)*velocity.est)<0)velocity.frameCountEst=0;
    velocity.est+=(force*est)/mass;
}
return;
}
