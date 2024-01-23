

	AUTOMATIC IN-LINING: If a member function's definition is short enough, the definition can be included inside the class declaration. Doing so causes the function to automatically become an in-line function, if possible. 
	When a function is defined within a class declaration, the inline keyword is no longer necessary. 
	Of course if any in-line restriction is violated, the compiler is free to generate a normal function.
	For example, the  divisible()  is automatically in-lined as shown here:
class samp {	int i, j;
public:
samp (int a, int b);
/* divisible() is defined here and automatically in - lined . */
int divisible() { return !(i%j);}
};
samp :: samp(int a, int b) { i = a;  j = b; }
	As you can see, the code associated with divisible() occurs inside the declaration for the class samp. Further notice that no other definition of divisible() is needed-or permitted.
	Notice how divisible()  occurs all on one line. This format is very common in C++ programs when a function is declared within a class declaration. It allows the declaration to be more compact. 

