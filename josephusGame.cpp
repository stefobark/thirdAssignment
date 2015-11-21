#include<list>
#include<iostream>
using namespace std;
//josephus game. but.. i think the story on this is a bit more sad than a hot potatoe type game.

	// the function to run the 'game'. we give it a list, 
	
	int josephusGame(list<int> * group, int M){
		list<int>::iterator potatoeHolder = group->begin();
		
		int countPasses = 0;
		//while there is more than one person left in the group, run this little algorithm 
		while(group->size() > 0){
			if(potatoeHolder == group->end()) potatoeHolder = group->begin();
			cout << "group size: " << group->size() << endl;
			cout << "number of passes: " << countPasses << endl;
			cout << "potatoe holder: " << *potatoeHolder << endl;
			//if we've reached the number of passes, eliminate the person and start the count of passes over again
			if (countPasses == M){
				cout << "eliminating person: " << *potatoeHolder << endl;
				potatoeHolder = group->erase(potatoeHolder);
				countPasses = 0;
				if(group->size() == 1) break;
			} else {
				potatoeHolder++;
				countPasses++;
			}
			cout << "\n";
		}
	return group->front();
	
}

int main(){
	list<int> group;
	int M = 0;
	int N = 5;	
	// so, there will be N people.
	// and there will be M passes.
	// starting the count at one and going until its equal to N
	for(int i = 1; i <= N; i++){
		group.push_back(i);
	}
	
	cout << "the list: ";

	for(list<int>::iterator itr = group.begin(); itr != group.end(); itr++){
		cout << *itr;
	}
	cout << endl;	
	int winner = josephusGame(&group, M);
	cout << "with " << N << " people" << " and " << M << " passes, the last person standing is person # " << winner << endl;
}
	
	
	
	
	
