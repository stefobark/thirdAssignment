
#include<iostream>
#include<string>
#include<stack>
using namespace std;

//check if x has higher precedence than y
bool checkPrecedence(char x, char y) {
	int xScore;
	int yScore;
	
	if(x == '*' || x == '/') xScore = 1;
	else if(x == '+' || x == '-') xScore = 0;

	
	if(y == '*' || y == '/') yScore = 1;
	else if(y == '+' || y == '-') yScore = 0;

	
	if(xScore > yScore ) return 1;
	else if (yScore > xScore || xScore == yScore) return 0;
}
	
//the conversion function
string convertInToPost(string infix){
		  string postfix;
		  stack<char> operators;
		  
        for(string::iterator itr = infix.begin(); itr!=infix.end(); itr++){
        	//if it is a digit push it the output string
                 if(isdigit(*itr)) postfix.push_back(*itr);
                 
                 //else, if the operators stack is empty, just push this operand
                 else if(operators.empty()) operators.push(*itr);
                 
                 //else if this operand is of higher precendence than the last put on the stack
		 //push it to the operator stack
                 else if(checkPrecedence(*itr, operators.top())){
                 	 	operators.push(*itr);
                 }
                 
                 //else, if it is of lower or equal precedence start popping
		 //until the stack is empty
                 else if(checkPrecedence(*itr, operators.top()) == 0){
                 		//while there are still operators in the operator stack, push
				//them to the output string and pop them from the stack
				while(operators.size() != 0){
                 			postfix.push_back(operators.top());
                 			operators.pop();
                 			}
				//then, push the current operand to the stack
                 		operators.push(*itr);
        			  }
			
        }
	//when, we're done looking through the expression string, push rest of the operators
	//to the output string
        while(operators.size() != 0){
            postfix.push_back(operators.top());
            operators.pop();
        }
        return postfix;
}

int main(){

        string infix = "3+2+1*1-2/4";
        string postfix = convertInToPost(infix);

        cout << "postfix expression: ";
        //show me that it works.
	for(string::iterator finalItr = postfix.begin(); finalItr != postfix.end(); ++finalItr){
                cout << *finalItr << " ";
        }
        cout << endl;
}

