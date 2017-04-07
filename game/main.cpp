#include <iostream>
#include <string>
#include "position.h"

using namespace std;

int main()
{
index<indexable> ind(10);
position p(1,1),*q;
ind.add(p);
q=(position*)ind.find(p);

cout << *q << p;
return 0;
}
