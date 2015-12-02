# thirdAssignment
##listPos.cpp
My answer to question 3.1.
We have two lists, one list represents the positions of the elements from another list that we want to print.
Running ./listPos looks like:
```
1 4 6 8 
It took me 0 clicks to run this. 
but... I guess that is irrelevant. I think the question is about big-oh
I only run through the master list once. And, I only access the first element of position list.
Within each iteration through the master list, I delete the first element of the position list,
so I can get the first element on the next iteration
I think this is O(n) because the most important thing is the size of the master list
```

##swapDList.cpp
My answer to 3.2

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./swapDList, looks like this:
```
our list: 0 1 2 3 4 5 6 7 8 9 
the list after swapping: 0 5 2 3 4 1 6 7 8 9 

```

##findElement.cpp
This is my answer to question 3.3

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./findElement, looks like:
```
3
```
##intersection.cpp
My answer to 3.4

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./intersection
```
The resulting intersection: 1 5 9 
```
The lists were: {0,1,4,5,6,8,9}
and: {1,3,5,7,9}

##union.cpp
My answer to 3.5

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./union
```
The union: 0 1 2 3 4 5 6 7 8 9 19 99 
```
Our lists were: {0,1,2,3,4,5,6,7,8,9,19}
and: {1,3,5,7,9,99}

##josephusGame.cpp
My answer to the josephus problem.

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./josephusGame
```
the list: 12345
potatoe holder: 1
eliminating person 1

group size: 4
number of passes: 0
potatoe holder: 2
eliminating person: 2

group size: 3
number of passes: 0
potatoe holder: 3
eliminating person: 3

group size: 2
number of passes: 0
potatoe holder: 4
eliminating person: 4

with 5 people and 0 passes, the last person standing is person # 5
```

###Vector.h and testVector.cpp
These are my answers to 3.9 and 3.10.

Instead of iterators being simple pointers, I made an iterator class and overloaded ++, --, ==, != and did some simple checking to see if ++ or -- went beyond the boundary of the Vector. If the iterator goes too far I just print "iterated too far".

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./testVector

```
Printing the vector using the iterator class type (with overloaded ++): 10 9 8 7 6 iterated tooo far!
```

##sList.h and testSList.h
These are my answers to 3.11. Creating a simple single linked list. I modified the double linked list provided by the book so that it was a single linked list. Removed the prev pointer from the Node struct, and the operator--, and I also got rid of tail... but I don't think that was really necessary.

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./testSList:
```
our list: 7 3 4 2 15 

demonstrating the size method: 5

we also used a method called 'addValueIfNotPresent' to try 
to add 3 again, and we also added a 4 
so, there should only be one 3 and a 4...

looking for value 4. 
Should return 0 if not present, 1 if it is present. 
Let's see: 1

now we're checking if a value (4) is there and removing it

our list: 7 3 2 15 
```

###postfix.cpp
My answer to 3.22 --> evaluating a postfix expression. I followed the example from the book and wrote code using the english explanation of the algorithm.

Original infix expression = 6523+8*+3+*

It pushes operands to a stack, but when it encounters an operator it evaluates and pushes the result back to the stack

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./postfix
```
found operand, pushing to top = 6
found operand, pushing to top = 5
found operand, pushing to top = 2
found operand, pushing to top = 3
found operator, adding 3 and 2 = 5 and push it to the stack
found operand, pushing to top = 8
found operator, multiplying 8 by 5 = i get 40 and push it to the stack
found operator, adding 40 and 5 = 45 and push it to the stack
found operand, pushing to top = 3
found operator, adding 3 and 45 = 48 and push it to the stack
found operator, multiplying 48 by 6 = i get 288 and push it to the stack
should be 288 (followed explanation of algorithm from book): 288

```

###inToPost.cpp
My answer to 3.23 --> converting an infix expression to a postfix expression.
The original expression is: 3+2+1*1-2/4

Running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./inToPost
```
postfix expression: 3 2 + 1 1 * + 2 4 / - 
```

###sList.h and testReversePrint.cpp
My answer to 3.29 --> printing a list in reverse using constant space and with const member function

The member functions, in sList.h, look like this:
```
  //this just gets the list size and counts down from it, printing each element
	//using printX to print that element
	void printReverse() const{
		for(int i = size(); i > 0; --i){
		cout << printX(i) << " ";
		}
	}

	//this gets a position and prints what is at that position
  Object printX(int x) const{
    	int count = 0; 
    	while(count <= x){
    		if(count == x){
    		return x;
    	  }
    		count++;
    	}
  }
  ```

And, running stefo@ubuntu:~/CppStuff/thirdAssignment$ ./testReversePrint
```
our list: 1 2 3 4 5 
The reversed list: 5 4 3 2 1 
```
