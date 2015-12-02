#include"Vector.h"
#include<iostream>
using namespace std;

int main(){

	Vector<int> vec;

	vec.push_back(10);
	vec.push_back(9);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(6);

	Vector<int>::iterator itr = vec.begin();

	cout << "Printing the vector using the iterator class type (with overloaded ++): ";
	for(itr; itr != vec.end(); ++itr){
		cout << *itr << " ";
	}
	cout << endl;
}
