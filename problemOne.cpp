#include<list>
#include<iostream>
using namespace std;

//i think this isn't right because I'm creating a new list and the problem asked us not to allocate any additional space
list<int> reverseIt(list<int> * listToReverse){
	list<int> reversedList;
	for(list<int>::iterator itr = listToReverse->begin(); itr!=listToReverse->end(); ++itr){
		reversedList.push_front(*itr);
	}
	return reversedList;
}

// nope. i can't figure it out. moving on while there's still time.
// arrrg
// i tried to add a method to List.h as well, but I doubt it works. 
void reverse(list<int> * theList)
                { 
			list<int>::iterator start = theList->begin();
			list<int>::iterator end =  theList->end();
			int listSize = theList->size();
                        while(*start<=listSize/2+1){ 
				int tmp= *start;
				*start = *end;
				*end = tmp;
				start++;
				end--;
                        }
                }


int main(){
	list<int> reverseThisList;
	for(int i = 0; i < 10; i++){
		reverseThisList.push_back(i);
	}
	cout << "the list: ";
	for(list<int>::iterator itr = reverseThisList.begin(); itr!=reverseThisList.end(); ++itr) cout << *itr;
	cout << endl;

	list<int> reversedList = reverseIt(&reverseThisList);
	cout << "the reversed list (by nonclass function): ";
	for(list<int>::iterator itr2 = reversedList.begin(); itr2!=reversedList.end(); ++itr2) cout << *itr2;
	cout << endl;

	//that works, but I think I did it wrong. so now trying again with a new list.

	list<int> reverseListAgain;
        for(int i = 0; i < 10; i++){
                reverseListAgain.push_back(i);
        }
    
	reverse(&reverseListAgain);
	
	cout << "the reversed list (method from List.h): ";
        for(list<int>::iterator itr = reverseThisList.begin(); itr!=reverseThisList.end(); ++itr) cout << *itr;
        cout << endl;


	return 0;
}
