#ifndef indexof_H_INCLUDED
#define indexof_H_INCLUDED

#include <iostream>
#include <array>

class indexable {
public:
    virtual operator int() const=0;
};


template <class T,int size> class indexof {
    int indexofDim;
    std::array<T*,size> table;
    int numElements;

    int hash(const int x) {
        return x%indexofDim;
    }
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
