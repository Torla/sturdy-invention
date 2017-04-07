#ifndef INDEX_H_INCLUDED
#define INDEX_H_INCLUDED

#include <iostream>

class indexable{
public:
     virtual operator int() const=0;
};


template <class T> class index{
    int indexDim;
    T **table;
    int numElements;

    int hash(const int x){return x%indexDim;}
public:
    index(int size);
    bool add(T & x);
    bool remove(T & x);
    T* find(int id);
};



#endif // INDEX_H_INCLUDED
