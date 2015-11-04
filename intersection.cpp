#include<iostream>
#include<list>
using namespace std;


// so, this will have to iterate through both lists, so big oh would be 
// something like O(l1 * l2) (and I'm not sure if this is how we express that)
// I don't think this is ideal, but I have to think more about how to check all 
// elements of both lists to find the intersection. I guess I could pop_front on one of 
// the lists and only check the first element, but I don't think this is ideal either.
// What if we need to keep the list intact...
// ARggghH
list<int> checkIntersection( list<int> * listOne, list<int> * listTwo){
	
	list<int> theResultList;
	list<int>::iterator itOne = listOne->begin();
	list<int>::iterator itTwo = listTwo->begin();
	
	while (itOne!=listOne->end()) {
		itTwo = listTwo->begin();
		while (itTwo!=listTwo->end()){
    		if (*itOne==*itTwo) theResultList.push_back(*itOne);
    		++itTwo;
    	}
    	++itOne;
  }
  
  return theResultList;
}

int main(){
	
	int listInts[] = {0,1,4,5,6,8,9};
 	list<int> theList (listInts, listInts + sizeof(listInts) / sizeof(int));
 	
 	int listIntsTwo[] = {1,3,5,7,9};
 	list<int> theSecondList (listIntsTwo, listIntsTwo + sizeof(listIntsTwo) / sizeof(int));
 	
 	
 	list<int> result = checkIntersection(&theList, &theSecondList);
 	
 	std::cout << "The resulting intersection: ";
  	for (std::list<int>::iterator it = result.begin(); it != result.end(); it++)
    	std::cout << *it << ' ';

  	std::cout << '\n';
  
 }
 	
