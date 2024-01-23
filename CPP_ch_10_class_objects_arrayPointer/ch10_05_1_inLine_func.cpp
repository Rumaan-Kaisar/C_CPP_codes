
10.5 In-Line Functions
	IN-LINE FUNCTIONS: In C++, it is possible to define functions that are not actually called but, rather, are expanded in line, at the point of each call. This is much the same way that a C-like parameterized macro works (re call 8.1). 
	The advantage is, no overhead associated with the function call and return mechanism. This means that in-line functions can be executed much faster than normal functions. (Normal function call and return take time each time a function is called. If there are parameters, even more time overhead is generated.)
	The disadvantages of in-line functions is that if they are too large and called too often, your program grows larger. For this reason, in general only short functions are declared as in-line functions.
	To declare an in-line function, simply precede the function's "definition" with the "inline" specifier. For Example :

inline int even(int x) { return !(x%2); }

The function even(), which returns true if its argument is even, is declared as being-in-line. 
It means that,   if(even(x)) cout << "Even";    is functionally equivalent to:   if(!(x%2)) cout << " Even ";
	An in-line function must be defined before it is first called. If it isn't, the compiler has no way to know that it is supposed to be expanded in-line. This is why even() was defined before main().

inline int even(int x) { return !(x%2); }
int main(){ . . . . . . . . . }
	It is important to understand that the inline specifier is a request, not a command, to the compiler. 
	If any in-line restriction is violated, the compiler is free to generate a normal function (i.e. the function is compiled as a normal function and the inline request is ignored.). Some compilers will not in-line a function if it contains a static variable, a loop statement, a switch or a goto, or if the function is recursive.
