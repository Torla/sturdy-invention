#ifndef indexof_H_INCLUDED
#define indexof_H_INCLUDED

#include <iostream>
#include <array>
#include <unordered_map>


class indexable {
public:
    virtual operator int() const=0;
};


template <class H,class T> class indexof {
    std::unordered_map<H,T*,typename H::hash> table;
    int numElements;

public:
    indexof();
    bool add(T & x);
    bool remove(T & x);
    T* find(H id) const;
    ~indexof();
    bool clear();
    bool freeAll();
    void forEach(void (*consumer)(T* &));
    T* operator[](H id) const {
        return find(id);
    }
};



#endif // indexof_H_INCLUDED
