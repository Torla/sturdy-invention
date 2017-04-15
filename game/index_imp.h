#ifndef INDEX_IMP_H_INCLUDED
#define INDEX_IMP_H_INCLUDED

#include "index.h"

#include "iostream"



template <class T> index<T>::index(int size) {
    table=new T*[size];
    for(int i=0; i<size; i++) {
        table[i]=NULL;
    }
    indexDim=size;
    numElements=0;
}
template <class T> bool index<T>::add(T & x) {
    int i;
    if(indexDim==numElements) {
        std::cout << "err: Index is full" << std::endl;
        return true;
    }
    for(i=hash((int)x); table[i]!=NULL; i=(i+1)%indexDim) {}
    table[i]=&x;
    numElements++;
    return false;
}

template <class T> bool index<T>::remove(T & x) {
    int i,count;
    for(i=hash((int)x),count=0; table[i]!=&x && count!=indexDim; i=(i+1)%indexDim,count++) {};
    if(count==indexDim) {
        std::cout << "err: Miss in remove from index" << std::endl;
        return true;
    }
    table[i]=NULL;
    numElements--;
    return false;
}

template <class T> T* index<T>::find(int id) {
    int i,count;
    for(i=hash(id),count=0; (int)(*table[i])!=id && count!=indexDim; i=(i+1)%indexDim,count++) {};
    if(count==indexDim) {
        std::cout << "err: index find miss" << std::endl;
        return NULL;
    }
    return table[i];
}

template <class T> index<T>::~index() {
    if(numElements!=0) {
        std::cout << "war: eliminating not empty index" << std::endl;
    }
    delete table;
    return;
}

template <class T> bool index<T>::clear() {
    int i;
    for(i=0; i<indexDim && numElements!=0; i++) {
        if (table[i]!=NULL) {
            delete table[i]=NULL;
            numElements--;
        }
    }
    return false;
}

template <class T> bool index<T>::freeAll() {
    int i;
    for(i=0; i<indexDim && numElements!=0; i++) {
        if (table[i]!=NULL) {
            delete table[i];
            numElements--;
        }
    }
    return false;
}

template <class T> void index<T>::forEach(void (T::*consumer)()) {
    int i;
    for(i=0; i<indexDim && numElements; i++) {
        if (table[i]!=NULL) {
            (table[i]->*consumer)();
        }
    }
    return;
}
#endif // INDEX_H_INCLUDED
