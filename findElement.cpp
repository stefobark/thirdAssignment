#include<iostream>
#include<list>
using namespace std;

// here is the nonclass function described in question 3
// it takes two iterators that represent the start and end of a listInts
// while the start iterator doesn't equal the end (when there are more elements to check)
// it checks to see if our iterator points to the element we want to find
// if it finds the element it returns the iterator to that position in the list
// if not, it increments our beginning iterator
// it if finds nothing, it returns the end iterator.

template <typename Iterator, typename Object>
Iterator find( Iterator start, Iterator end, const Object & x){
	while (start!=end) {
    if (*start==x) return start;
    ++start;
  }
  return end;
}

int main(){
 	int listInts[] = {0,1,2,3,4,5,6,7,8,9};
 	list<int> theList (listInts, listInts + sizeof(listInts) / sizeof(int));
	list<int>::iterator start = theList.begin();
	list<int>::iterator end = theList.end();
	list<int>::iterator found = find(start, end, 3);
	cout << *found << endl;
}
