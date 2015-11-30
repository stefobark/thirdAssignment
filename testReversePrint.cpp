#include"sList.h"
#include<iostream>
using namespace std;
int main(){
	List<int> list;
	list.push_front(5);
	list.push_front(4);
	list.push_front(3);
	list.addValueIfNotPresent(2);
	list.addValueIfNotPresent(1);
	list.printList();
	
	cout << "The reversed list: ";
	list.printReverse();
	
	cout << endl;
	return 0;
}
