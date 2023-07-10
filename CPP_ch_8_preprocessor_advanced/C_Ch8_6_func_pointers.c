5.8 Function Pointers (Advanced topic)
A function pointer is a variable that contains the address of the entry point to a function. 
	When the compiler compiles your program, it creates an entry point for each function in the program. 
	The entry point is the address to which execution transfers when a function is called. 
	Since the entry point has an address, it is possible to have a pointer variable point to it. 
	Once you have a pointer to a function, it is possible to actually call that function using the pointer. 

To create a variable that can point to a function, declare the pointer as having the same type as the return type of the function, followed by any parameters. For example, the following declares p as a pointer to a function that returns an integer and has two integer parameters, x and y;
int (*p) (int x, int y);

The parentheses surrounding *p are necessary because of C’s precedence rules.
	To assign the address of a function to a function pointer, simply use its name without any parentheses.  For example, assuming that sum() has the prototype
int sum(int a, int b);

the assignment statement   p = sum;   is correct. Once this has been done, you can call sum() indirectly through p using a statement like
result = (*p) (10, 20);
[Again because of C’s precedence rules the Parentheses are necessary around p. ]

Actually, you can also just use p directly, like this:
result = p(10, 20);
Note
(*p) form inform anyone that reading your codes that a function pointer is being used to call a function indirectly, instead of calling a function named p. 
