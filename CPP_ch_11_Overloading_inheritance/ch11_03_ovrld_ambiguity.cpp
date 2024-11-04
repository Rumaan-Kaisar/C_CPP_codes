
/*  ------------------------    Ambiguity caused by Overloading     ------------------------

    Ambiguity Caused By Overloading:
        Overloading-caused ambiguity can be introduced through 
            - type conversions, 
            - reference parameters, and 
            - default arguments. 

        Further, some types of ambiguity are caused by the "overloaded functions" themselves. 
        Other types occur in the manner in which an overloaded function is called. 



    Type Conversion Ambiguity: 

When an argument has a compatible (but not exact) type with the function parameter, C++ automatically converts it to the target type. This automatic type conversion may create ambiguity if there are multiple overloaded functions that can match due to the conversion.

Example: This type conversion allows a function like putchar() to accept a char argument, even though its parameter is specified as int.
Other factors that may cause ambiguity include reference parameters, default arguments, and the way overloaded functions are called.




    [1]	Type conversion ambiguity: when a function is called with an argument that is of a compatible (but not the same) type as the parameter to which it is being passed, the type of the argument is automatically converted to the target type (C++'s automatic type conversion rules).  Sometimes automatic type conversion will cause an ambiguous situation when a function is overloaded.

    	It is this sort of type conversion that allows a function such as putchar() to be called with a character even though its argument is specified as an int. 






float f( float i) { return i/2.0; }
double f( double i) { return i/3.0; }
int mai() { 	float x = 10.09;
		double y = 10.09;
	cout << f(x); /* unambiguous - use f(float) */ 
cout << f(y); /* unambiguous - use f(double) */ 
cout << f (10) ; /* ambiguous , convert 10 to double or 
					       float ??   */ 
return 0; }

The compiler is able to select the correct version of f() when it is called with either a float or a double variable. However, what happens when it is called with an integer? Does the compiler call f(float) or f(double)? (Both are valid conversions!) In either case, it is valid to promote an integer into either a float or a double. Thus, the ambiguous situation is created.
	However, when this function is called with the wrong type of argument, C++'s automatic conversion rules cause an ambiguous situation,

void f( unsigned char c) { cout << c; }
void f( char c) { cout << c; }	int main() { f('c');
	f(86) ;   /* which f() is called ? */ 
	return 0; }

Here, when f() is called with the numeric constant 86, the compiler cannot know whether to call f(unsigned char) or f(char). Either conversion is equally valid, thus leading to ambiguity.


[2]	Ambiguity by Reference: In C++ there is no syntactical difference between calling a function that takes a value parameter and calling a function that takes a reference parameter, hence ambiguity arise. For example :

int f(int a, int b) { return a+b; }
		/* Following is inherently ambiguous */
int f(int a, int &b) { return a-b; }	int main() { int x=1, y=2;
cout << f(x, y);    /* which version of f() is called?*/ 
return 0; }
Here, f(x, y) is ambiguous because it could be calling either version of the function. 
[3]	Ambiguity by default arguments: Another type of ambiguity is caused when you are overloading a function in which one or more overloaded functions use a default argument. Consider following program:

int f(int a) { return a*a; }
int f(int a, int b = 0) { return a*b; }	int main() { cout << f(10 , 2); /* calls f(int , int) */ 
cout << f (10) ;    /* ambiguous: f(int ) or f(int , int )? */ 
return 0; }
Here the call f(10, 2) is perfectly acceptable, and unambiguous. However, the compiler has now way of knowing whether the call f(10) is calling the first version of f() or the second version with b defaulting.


*/  
