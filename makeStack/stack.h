#include<list>
using namespace std;
template <typename Object>
class listStack
{
	//the stack has a list of Objects as its data member
	list<Object> theList;
	public:
	//construct it. which i think just means there will be an empty list available
        listStack(){};
	//push an object to the front
	Object push(Object a){theList.push_front(a);}
	//pop the object from the front
	Object pop(){theList.pop_front();}
	//return the object from the front of the list
	Object top(){return theList.front();}
	//return true if the list has a size less than or equal to zero;
	bool isEmpty(){return (theList.size()<=0);}
};
