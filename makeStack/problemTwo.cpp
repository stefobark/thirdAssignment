#include"stack.h"
#include<iostream>
using namespace std;

int main(){
	//there shall be a stack called theStack
 	listStack<int> theStack;
 	
	//then we'll push ints up 9 into it
	for(int i = 0; i < 10; i++){
		theStack.push(i);
	}
	
	//then we check if top() works
	cout << "theStack.top(): " << theStack.top() << endl;
	
	//now we check if pop() works
	theStack.pop();
	
	cout << "theStack.top() after theStack.pop(): " << theStack.top() << endl;
	
	//and we check to see if isEmpty() works
	cout << "theStack.isEmpty() 0 means its not empty. 1 means it is empty: " << theStack.isEmpty() << endl;
 	
	return 0;
}	
