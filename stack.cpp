#include"stack.h"
using namespace std;

listStack::push(Object a){theList.push_front(a); return theList.front();}
listStack::pop(){theList.pop_front(); return theList.front();}
listStack::top(){return theList.front();}
listStack::isEmpty(){return (theList.size()==0);}

