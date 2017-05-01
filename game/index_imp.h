#ifndef indexof_IMP_H_INCLUDED
#define indexof_IMP_H_INCLUDED

#include "index.h"

#include "iostream"

#include <algorithm>
#include <list>



template <class H,class T> indexof<H,T>::indexof():table(),numElements(0) {

}

template <class H,class T> bool indexof<H,T>::add(T & x) {
    table.insert({(H)x,&x});
    numElements++;
    return false;
}

template <class H,class T> bool indexof<H,T>::remove(T & x) {
    table.erase(x);
    numElements--;
    return false;
}

template <class H,class T> T* indexof<H,T>::find(H id) const {
    return table.at(id);
}

template <class H,class T> indexof<H,T>::~indexof() {
    if(numElements!=0) {
        std::cout << "war: eliminating not empty indexof" << std::endl;
    }
    return;
}

template <class H,class T> bool indexof<H,T>::clear() {
    table.clear();
    return false;
}


template <class H,class T> void indexof<H,T>::forEach(void (*consumer)(T* &)) {
    std::list<std::pair<const H,T*>> l;
    std::for_each(table.begin(),table.end(),[&consumer,&l](std::pair<const H,T*>& x) {
        l.push_front(x);
    });
    std::for_each(l.begin(),l.end(),[&consumer](std::pair<const H,T*>& x) {
        consumer(x.second);
    });
    return;
}
#endif // indexof_H_INCLUDED
