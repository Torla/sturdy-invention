#include <iostream>
#include <string>
#include "position.h"

using namespace std;

int main() {
    index<position>* ind = new index<position>(10);
    position *p,*q;
    q = new position(2,2);
    p = new position(1,1);
    ind->add(*p);
    ind->add(*q);
    ind->forEach(&position::test);
    ind->freeAll();
    delete ind;
    return 0;
}

