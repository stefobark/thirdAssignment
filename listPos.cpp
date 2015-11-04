#include<iostream>
#include<list>

int main(){
	
	//going to count clicks
	clock_t t;
  	t = clock();

	// I'm not sure if this is the best way to initialize a list, 
	// but I saw it done on the c++ reference site and it made good sense
	int myints[] = {0,1,2,3,4,5,6,7,8,9};
	std::list<int> L (myints, myints + sizeof(myints) / sizeof(int) );	

	// we want the values from these positions of L.. so, because L's values are the same as their position,
	// we should, in the end, see 1,4,6,8 printed to the screen
	int posList[] = {1,4,6,8};
	std::list<int> P (posList, posList + sizeof(posList) / sizeof(int) );

	int countPos = 0; // keep track of where we are in the loop
	
	// looping through L using an iterator
  	for (std::list<int>::iterator it = L.begin(); it != L.end(); it++){

		std::list<int>::iterator itP = P.begin();
  		
		// if the we're at the correct position of the list we're checking, print the value
		if(*itP == countPos){ 
			std::cout << *it << ' ';
			// if we haven't removed all the elements, remove the first element
			// we do this because we're only checking the first element of P to see if it aligns with the position
			// of L.
	                if(itP != P.end()) P.pop_front();

		}

		countPos++;
	}

  	std::cout << '\n';

	t = clock() - t;
	printf ("It took me %d clicks to run this. \n",t);
	std::cout << "but... I guess that is irrelevant. I think the question is about big-oh" << std::endl;
	std::cout << "I only run through the master list once. And, I only access the first element of position list." << std::endl;
	std::cout << "Within each iteration through the master list, I delete the first element of the position list," << std::endl;
	std::cout << "so I can get the first element on the next iteration" << std::endl;
	std::cout << "I think this is O(n) because the most important thing is the size of the master list" << std::endl;
}

