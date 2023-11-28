
----------------------     C vs C++     ----------------------

9.6 Difference between C and C++
	Void is not essential for empty parameter : In C, when a function takes no parameters, its prototype has the word void inside its function parameter list. For example, in C, if a function called f1() takes no parameters (and returns a char), its prototype will look like this: 	char f1(void);
However, in C++, the void is optional. Therefore, in C++, the prototype for f1() is usually written like this:      char f1();
	In a C program, it is common practice to declare main() as shown here if it takes no command-line arguments:
int main(void)
          However, in C++, the use of void is redundant and unnecessary and we'll use :    int main()
	in a C program, char f1(); simply mean that nothing is said about the parameters to the function and
char f1(void); means that the function takes no parameters.
	In C++, it means that the function has no parameters.  In C++, these two declarations are equivalent: 
char f1();  ⟺   char f1(void);
	Prototype is essential : In a C++ program, all functions must be prototyped. C++ programs will not compile if the function is not prototyped. [Remember, in C, prototypes are recommended but technically optional.]
	A member function's prototype contained in a class (we'll discuss about class in next chapter) also serves as its general prototype, and no other separate prototype is required.
	returning values are essential :  In C++, if a function is declared as returning a value, it must return a value. We must explicitly declare the return type of all functions.
	In C, a non-void function is not required to actually return a value. If it doesn't, a garbage value is "returned". In C, if you don't explicitly specify the return type of a function, an integer return type is assumed. 
	Local variable anywhere : In C++, local variables can be declared anywhere. One advantage of this approach is that local variables can be declared close to where they are first used, thus helping to prevent unwanted side effects.
	In C, local variables can declared only at the start of a block, prior to any "action" statements.
	New "bool" data-type : C++ defines the bool data type, which is used to store Boolean (i.e., true/false) values. C++ also defines the keywords true and false, which are the only values that a value of type bool can have. 
	In C++, the outcome of the relational and logical operators is a value of type bool, and all conditional statements must evaluate to a bool value. 
	In C, true is any nonzero value and false is 0. This still holds in C++ because any nonzero value is automatically converted into false when used in a Boolean expression. The reverse also occurs: true is converted to 1 and false is converted to 0 when a bool value is used in an integer expression. 

