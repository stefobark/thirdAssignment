#include<iostream>
#include"dList.h"
using namespace std;

int main(){

	int listContents[] = {0,1,2,3,4,5,6,7,8,9};
	List<int> swapList (listContents, listContents + sizeof(listContents) / sizeof(int) );

	std::cout << "The contents of this list: ";
  	for (List<int>::iterator it = swapList.begin(); it != swapList.end(); it++)
    		cout << *it << ' ';

  	cout << '\n';

	

}

