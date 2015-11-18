#include"sList.h"
#include<iostream>
using namespace std;
int main(){
	List<int> list;
	list.push_front(15);
	list.push_front(2);
	list.push_front(5);
	list.addValueIfNotPresent(3);
	list.addValueIfNotPresent(7);
	list.printList();
	
	cout << "\ndemonstrating the size method: " << list.size() << "\n\n";
	cout << "we also used a method called 'addValueIfNotPresent' to try \nto add 3 again, and we also added a 4 \nso, there should only be one 3 and a 4..." << "\n\n";
	cout << "looking for value 4. \nShould return 0 if not present, 1 if it is present. \nLet's see: " << list.checkVal(4) << "\n\n";
	cout << "now we're checking if a value (4) is there and removing it\n\n";
	list.removeValueIfPresent(4);
	list.printList();
}
