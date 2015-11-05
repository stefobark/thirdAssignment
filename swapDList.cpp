//using the list provided by the book
#include"List.h"
#include<iostream>
using namespace std;

int main(){
	// there shall be a list of ints
	List<int> theList;
	
	// we will fill this list with ints 0-9
	for(int i = 0; i < 10; i++){
		theList.push_back(i);
	}
	
	// and we'll need an iterator to run through this list
	List<int>::iterator itr = theList.begin();
	
	//print the list
	cout << "our list: ";
	while(itr != theList.end()){
		cout << *itr << ' ';
		++itr;
	}
	cout << endl;
	
	// return the iterator to the beginning of the list
	itr = theList.begin();
	
	// and there shall be two more iterators to point to the element we want to swap
	List<int>::iterator itrA;
	List<int>::iterator itrB;
	
	// in this while loop, we'll say, assign itrA to the element of our master list with a value of 1
	// and itrB will be assigned to the element with the value of 5
	// i guess we could also assign by position if we created some counter variables to increment while we looped through theList.
	while(itr != theList.end()){
		if(*itr == 1) itrA = itr;
		if(*itr == 5) itrB = itr;
		++itr;
	}
	
	// send those two iterators to the swap method i added to the book's list.h
	theList.swap(itrA, itrB);
	
	// gotta return the iterator to the beginning again, so we can print out the list after swapping
	itr = theList.begin();
	cout << "the list after swapping: ";
	while(itr != theList.end()){
		cout << *itr << ' ';
		++itr;
	}
	
	cout << endl;
	
	return 0;
}
