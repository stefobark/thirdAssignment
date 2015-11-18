#include<list>
#include<vector>
#include<iostream>
using namespace std;
//josephus game. but.. i think the back story on this is a bit more sad than a hot potatoe type game.

	// the function to run the 'game'. we give it a pointer to a group, 
	// it returns an iterator to the last standing person
	// M is the number of passes. N is the number of people in the group.
	// to check if it is working, I took what the book said: "if M = 0 and N = 5, 5 will be the last person standing"
	
	
	list<int>::iterator josephusGame(list<int> * group, int M){
		list<int>::iterator potatoeHolder = group->begin();
		
		int countPasses = 0;
		
		
		//while there is more than one person left in the group, run this little algorithm 
		while(group->size() > 1){
			//if we've reached the number of passes, eliminate the person and start the count of passes over again
			if(countPasses == M){
				potatoeHolder = group->erase(potatoeHolder);
				countPasses = 0;
			//or else, keep counting and moving the potatoe down the line
			} else {
				countPasses++;
				potatoeHolder++;
			}
			
			// but, if we've reached the end of the list (and, remember that end() of the 
			// list is not actually an element of the list. it will return a pointer to
			// an element outside of the list.. an "iterator to the element past the end of the sequence ")
			// give the potatoe to the first person.
			
			if(potatoeHolder == group->end()) potatoeHolder = group->begin();
		}
return potatoeHolder;
	
}

int main(){
	list<int> group;
	
	// so, there will be N people.
	// and there will be M passes.
	// starting the count at one and going until its equal to N
	int M = 0;
	int N = 5;
	for(int i = 1; i <= N; i++){
		group.push_back(i);
	}
	
	list<int>::iterator winner = josephusGame(&group, M);
	cout << "with " << N << " people" << " and " << M << " passes, the last person standing is person # " << *winner << endl;
}
	
	
	
	
	
