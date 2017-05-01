#include "player.h"

using namespace playerPar;

bool playerClass::exist=false;
playerClass *player;

playerClass::playerClass(int x,int y):blockingObj(x,y,playerPar::playerMass,playerPar::playerMass,N,PLAYER,playerPar::playerScreenLayer),hp(startingMaxHp,startingMaxHp) {
    if(exist) {
        std::cout << "Err: instance of player yet exist" << std::endl;
        return;
    }
    exist=true;
    player=this;
}
