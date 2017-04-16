#ifndef indexof_IMP_H_INCLUDED
#define indexof_IMP_H_INCLUDED

#include "index.h"

#include "iostream"



template <class T> indexof<T>::indexof(int size) {
    table=new T*[size];
    for(int i=0; i<size; i++) {
        table[i]=NULL;
    }
    indexofDim=size;
    numElements=0;
}
template <class T> bool indexof<T>::add(T & x) {
    int i;
    if(indexofDim==numElements) {
        std::cout << "err: indexof is full" << std::endl;
        return true;
    }
    for(i=hash((int)x); table[i]!=NULL; i=(i+1)%indexofDim) {}
    table[i]=&x;
    numElements++;
    return false;
}

template <class T> bool indexof<T>::remove(T & x) {
    int i,count;
    for(i=hash((int)x),count=0; table[i]!=&x && count!=indexofDim; i=(i+1)%indexofDim,count++) {};
    if(count==indexofDim) {
        std::cout << "err: Miss in remove from indexof" << std::endl;
        return true;
    }
    table[i]=NULL;
    numElements--;
    return false;
}

template <class T> T* indexof<T>::find(int id) {
    int i,count;
    for(i=hash(id),count=0; (int)(*table[i])!=id && count!=indexofDim; i=(i+1)%indexofDim,count++) {};
    if(count==indexofDim) {
        std::cout << "err: indexof find miss" << std::endl;
        return NULL;
    }
    return table[i];
}

template <class T> indexof<T>::~indexof() {
    if(numElements!=0) {
        std::cout << "war: eliminating not empty indexof" << std::endl;
    }
    delete[] table;
    return;
}

template <class T> bool indexof<T>::clear() {
    int i;
    for(i=0; i<indexofDim && numElements!=0; i++) {
        if (table[i]!=NULL) {
            delete table[i]=NULL;
            numElements--;
        }
    }
    return false;
}

template <class T> bool indexof<T>::freeAll() {
    int i;
    for(i=0; i<indexofDim && numElements!=0; i++) {
        if (table[i]!=NULL) {
            delete table[i];
        }
    }
    return false;
}

template <class T> void indexof<T>::forEach(void (T::*consumer)()) {
    int i;
    for(i=0; i<indexofDim && numElements; i++) {
        if (table[i]!=NULL) {
            (table[i]->*consumer)();
        }
    }
    return;
}
#endif // indexof_H_INCLUDED
