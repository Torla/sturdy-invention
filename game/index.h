#ifndef indexof_H_INCLUDED
#define indexof_H_INCLUDED

#include <iostream>

class indexofable {
public:
    virtual operator int() const=0;
};


template <class T> class indexof {
    int indexofDim;
    T **table;
    int numElements;

    int hash(const int x) {
        return x%indexofDim;
    }
public:
    indexof(int size);
    bool add(T & x);
    bool remove(T & x);
    T* find(int id);
    ~indexof();
    bool clear();
    bool freeAll();
    void forEach(void (T::*consumer)());
};



#endif // indexof_H_INCLUDED
