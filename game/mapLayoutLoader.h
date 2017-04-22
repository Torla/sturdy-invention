#ifndef MAPLAYOUTLOADER_H_INCLUDED
#define MAPLAYOUTLOADER_H_INCLUDED


#include "obj.h"
#include "string"

class mapLayoutLoader {
    static void placeObject(char sym,int x,int y);
public:
    static void load(std::string path);
};

#endif // MAPLAYOUTLOADER_H_INCLUDED
