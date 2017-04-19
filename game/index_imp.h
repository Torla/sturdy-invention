#ifndef indexof_IMP_H_INCLUDED
#define indexof_IMP_H_INCLUDED

#include "index.h"

#include "iostream"

#include <algorithm>
#include <list>



template <class T> indexof<T>::indexof() {
    numElements=0;
}
template <class T> bool indexof<T>::add(T & x) {
    table.insert({(int)x,&x});
    numElements++;
    return false;
}

template <class T> bool indexof<T>::remove(T & x) {
    table.erase(x);
    numElements--;
    return false;
}

template <class T> T* indexof<T>::find(int id) {
    return table.at(id);
}

template <class T> indexof<T>::~indexof() {
    if(numElements!=0) {
        std::cout << "war: eliminating not empty indexof" << std::endl;
    }
    return;
}

template <class T> bool indexof<T>::clear() {
    table.clear();
    return false;
}


template <class T> void indexof<T>::forEach(void (*consumer)(T* &)) {
    std::list<std::pair<const int,T*>> l;
    std::for_each(table.begin(),table.end(),[&consumer,&l](std::pair<const int,T*>& x) {
        l.push_front(x);
    });
    std::for_each(l.begin(),l.end(),[&consumer](std::pair<const int,T*>& x) {
        consumer(x.second);
    });
    return;
}
#endif // indexof_H_INCLUDED
