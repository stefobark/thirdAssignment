#include<list>
#include"List.h"
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

//after much fiddling, and seeing many strange numbers being output, this works! and I don't create a new list!
//but I'm still not sure if i should be pointing in a pointer to this list...
void myNonClassReverse(list<int> * reverseThisList)
   {
   	list<int>::iterator i = reverseThisList->begin();
		list<int>::iterator j = reverseThisList->end();
		
		// i assume that since we're getting the head and tail and switching them,
		// then moving further inward to switch again, we need the size of the list / 2 as the condition
		// for terminating our for loop
		int timesThrough = reverseThisList->size()/2;
		
		for(int x = 0; x < timesThrough; x++){
			// i think reverseThisList->end() returned something that was out of the list. 
			// so without decrementing it at the top, like I'm doing below, it was spitting out strange
			// numbers. but now it works!
			j--;
			//store the value pointed to by i in tmp
			int tmp = *i;
			//change the value pointed to by i (which initialy means, "one before reverseThisList->end()"
			*i = *j;
			//and now the value of j gets the value that i intitially had
			*j = tmp;
			//YES!! I have to wait to increment i. I almost had it but my i was incrementing i at the top
			//which was making it skip 0! and, without decrementing j at the top, it was spitting out weird numbers.
			//i think it began pointing outside of the list or something. end() must return null or something.
			//just looked it up. i think this is right. it says that end() returns "An iterator to the element
			//past the end of the sequence." http://www.cplusplus.com/reference/list/list/end/
			//and begin() is different.. it returns "An iterator to the beginning of the sequence container." 
			//http://www.cplusplus.com/reference/list/list/begin/
			i++;
		}
    }

int main(){
        //for the nonmember function, i'll use list from std
	list<int> reverseThisList;
         for(int i = 0; i < 10; i++){
                reverseThisList.push_back(i);
        }
        cout << "the list: ";
        for(list<int>::iterator itr = reverseThisList.begin(); itr!=reverseThisList.end(); ++itr) cout << *itr;
        cout << endl;
			
        myNonClassReverse(&reverseThisList);
        cout << "the reversed list (by nonclass function): ";
        for(list<int>::iterator itr2 = reverseThisList.begin(); itr2!=reverseThisList.end(); ++itr2) cout << *itr2;
        cout << endl;

	//for the member function, i wrote a method in List.h called reverse and myReverse. reverse is a solution i found.
	//myReverse is my own thinking but I fixed it up after I saw how the other solution was working
	List<int> reverseListAgain;
        for(int i = 0; i < 10; i++){
            reverseListAgain.push_back(i);
        }
        
        reverseListAgain.reverse();
        cout << "the reversed list (method from List.h that I found on stackoverflow): ";
        for(List<int>::iterator itr = reverseListAgain.begin(); itr!=reverseListAgain.end(); ++itr)
        		{ cout << *itr;}
        cout << endl;
	
	//this is where I demonstrate my method working.
        List<int> reverseListYetAgain;
        for(int i = 0; i < 10; i++){
            reverseListYetAgain.push_back(i);
        }
        
        reverseListYetAgain.myReverse();
        cout << "the reversed list (method from List.h that I wrote): ";
        for(List<int>::iterator itr = reverseListYetAgain.begin(); itr!=reverseListYetAgain.end(); ++itr)
        		{ cout << *itr;}
        cout << endl;

        return 0;
}




