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
with 5 people and 0 passes, the last person standing is person # 5
```
but... it doesn't work yet..
trying different values:
```
with 7 people and 2 passes, the last person standing is person # 4
```
which isn't correct.
will continue to work on this.

##sList.h and testSList.h
These are my answer to 3.11. Creating a simple single linked list. I modified the double linked list provided by the book.

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
