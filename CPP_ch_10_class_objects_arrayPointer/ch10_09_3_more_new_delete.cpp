
	Dynamically allocate a one-dimensional array : To dynamically allocate a one-dimensional array, use this form of new:
p_var = new type[ size ];
After this statement has executed, p_var will point to the start of an array of size elements of the type specified. 
	For various technical reasons, it is not possible to initialize an array that is dynamically allocated.
	To delete a dynamically allocated array, use this form of delete:
delete [] p_var ;
This syntax causes the compiler to call the destructor function for each element in the array. It does not cause p_var to be freed multiple times. p_var is still freed only once.

Example 3 : to allocate an array of integers 
int *p;
p = new int[5]; 	/* allocate room for 5 integers */ 
if(!p) { cout << " Allocation error \n"; return 1; } 	/*allocation check*/
. . . . . . STATEMENTS. . . . . .
delete [] p;

Example 4 : to allocate object array named "samp",
samp *p;
p = new samp[5]; 	/* allocate object array named "samp" */ 
if(!p) { cout << " Allocation error \n"; return 1; } 	/*allocation check*/
. . . . . . STATEMENTS. . . . . .
delete [] p;

Note
[1]	new automatically allocates enough memory to hold an object of the specified type. You do not need to use sizeof, for example, to compute the number of bytes required. This reduces the possibility for error. 
[2]	new automatically returns a pointer of the specified type. You do not need to use an explicit type cast.  
	In C, no type cast is required when you are assigning the return value of malloc() to a pointer because the void * returned by malloc() is automatically converted into a pointer compatible with the type of pointer on the left side of the assignment. 
	However, this is not the case in C++, which requires an explicit type cast when you use malloc(). The reason for this difference is that it allows C++ to enforce more rigorous type checking.
[3]	Both new and delete can be overloaded, enabling you to easily implement your own custom allocation system. 
[4]	It is possible to initialize a dynamically allocated object. 
[5]	You no longer need to include <cstdlib> with your programs.


