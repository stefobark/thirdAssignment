#include<iostream>
#include<stack>
#include<ctype.h> //http://www.cplusplus.com/reference/cctype/isdigit/
#include<string>
using namespace std;

int main(){
	string expression ("6523+8*+3+*");
	stack<int> pFStack;
	
	for(char& itr: expression) {
		
		if(isdigit(itr)){
			int pushDigit = itr - '0';
			pFStack.push(pushDigit);
			cout << "found operand, pushing to top = " << pFStack.top() << "\n";
		}
		
		if(itr == '*'){
			
			int first = pFStack.top();
			cout << "found operator, multiplying " << first << " ";
			pFStack.pop();
			int second = pFStack.top();
			cout << "by " << second << " = ";
			pFStack.pop();
			int mPushThis = first * second;
			cout << "i get " << mPushThis << " and push it to the stack" << endl;
			pFStack.push(mPushThis);
		}
		
		if(itr == '+'){
			int addFirst = pFStack.top();
			cout << "found operator, adding " << addFirst << " ";
			pFStack.pop();
			int addSecond = pFStack.top();
			cout << "and " << addSecond << " = ";
			pFStack.pop();
			int aPushThis = addFirst + addSecond;
			cout << aPushThis << " and push it to the stack" << endl;
			pFStack.push(aPushThis);
		}
			//cout << itr << endl;
	}
	cout << "should be 288 (followed explanation of algorithm from book): "<< pFStack.top() << endl; 
}
				
