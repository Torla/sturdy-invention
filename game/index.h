#ifndef indexof_H_INCLUDED
#define indexof_H_INCLUDED

#include <iostream>
#include <array>
#include <unordered_map>

class indexable {
public:
    virtual operator int() const=0;
};


template <class T> class indexof {
    std::unordered_map<int,T*> table;
    int numElements;

public:
    indexof();
    bool add(T & x);
    bool remove(T & x);
    T* find(int id);
    ~indexof();
    bool clear();
    bool freeAll();
    void forEach(void (*consumer)(T* &));
    T* operator[](int id) {
        return find(id);
    }
};



#endif // indexof_H_INCLUDED
