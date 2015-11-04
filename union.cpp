#include<iostream>
#include<list>
using namespace std;

list<int> getUnion( list<int>::iterator itOne, list<int>::iterator itTwo, list<int>::iterator itOneEnd, list<int>::iterator itTwoEnd){

	list<int> theResultList;
	int rBack = theResultList.back();
	int tmp;
	
	// while we haven't reached the end of either list
	while(*itOne != *itOneEnd && *itTwo != *itTwoEnd){
		// check if the value of itTwo is smaller than the value of itOne, 
		// if so, push it to the end of the result list and then increment
		// itTwo to check again if it is still smaller.
		if(*itTwo < *itOne) {
			theResultList.push_back(*itTwo);
			++itTwo;
		} 
		// but, if itTwo *IS* smaller, then let's make sure that it 
		// isn't equal to the value pointed to by itOne. if it is not equal,
		// then we can push the value of itOne to the end of the result list
		// and move on to the next value of itOne
		else if(*itOne != *itTwo) {
			theResultList.push_back(*itOne);
			++itOne;
		} 
		// finally, if they were equal, let's increment itOne and start over, 
		// checking to see if the value of itTwo is less than the value of itOne.
		else {
			++itOne;
		}
  }
  
  // the condition of the while loop seems to have made it so that the very last element wasn't pushed to the back 
  // of the result list (it was outputting strange numbers). this doesn't seem ideal, but here I 'fix' it by checking
  // to see if the iterators have exceeded the bounds of the list (which is possible because I
  // keep incrementing itOne)... if they haven't (which would mean they're pointing to some weird location in memory), and if they aren't equal
  // to each other, then I just push it to the back of the result list. seems like I need a better way to traverse the list with the while loop!
  // i've tried all sorts of different sizes of lists to see if i could break this, but it seems to be working!
  if(*itOne < *itOneEnd && *itOne != *itTwo) theResultList.push_back(*itOne);
  if(*itTwo < *itTwoEnd) theResultList.push_back(*itTwo);
  
  return theResultList;
}


int main(){
	
	int listInts[] = {0,1,2,3,4,5,6,7,8,9,19};
 	list<int> listOne (listInts, listInts + sizeof(listInts) / sizeof(int));
 	
 	int listIntsTwo[] = {1,3,5,7,9,99};
 	list<int> listTwo (listIntsTwo, listIntsTwo + sizeof(listIntsTwo) / sizeof(int));
	list<int>::iterator itOne = listOne.begin();
	list<int>::iterator itTwo = listTwo.begin();
	list<int>::iterator itOneEnd = listOne.end();
	list<int>::iterator itTwoEnd = listTwo.end();
 	list<int> result = getUnion(itOne, itTwo, itOneEnd, itTwoEnd);
 	
 	std::cout << "The union: ";
  	for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
    	std::cout << *it << ' ';

  	std::cout << '\n';
  
 }
