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

##
