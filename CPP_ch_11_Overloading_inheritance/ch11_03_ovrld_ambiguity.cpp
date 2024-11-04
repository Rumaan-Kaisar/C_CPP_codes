
/*  ------------------------    Ambiguity caused by Overloading     ------------------------

    Ambiguity Caused By Overloading:
        Overloading-caused ambiguity can be introduced through 
            - type conversions, 
            - reference parameters, and 
            - default arguments. 

        Further, some types of ambiguity are caused by the "overloaded functions" themselves. 
        Other types occur in the manner in which an overloaded function is called. 
*/  



/*  --------    Type Conversion Ambiguity    --------

    Type Conversion Ambiguity: 
        When an argument has a "compatible (but not exact) type" with the function parameter, C++ automatically converts it to the target type. 
            A "compatible (but not exact) type" refers to a type that can be implicitly converted 
                to another type through C++'s automatic type conversion rules, 
            For example, C++ will automatically convert types like "char to int" or "float to double" 
                when passing them as arguments if needed.

        This automatic type conversion may create ambiguity 
            if there are multiple overloaded functions that can match due to the conversion.

        Example: This type conversion allows a function like putchar() to accept a "char" argument, even though its parameter is specified as "int".
*/


/* Example 1: Consider the following example with "int" and "double" types, also notice:
                    printValue(int) takes an int parameter, and also accept a "char" argument
                    printValue(double) takes a double parameter, and also accept a "float" argument


                ambiguity:
                    When printValue(value) is called with value of type "float", it causes ambiguity because:

                        float can be "implicitly" converted to int for printValue(int).
                        float can also be "implicitly" converted to double for printValue(double).

                Since both conversions are compatible (but not exact matches), the "compiler can't decide" which overload to choose, 
                    resulting in an ambiguous call.


                Solution:
                    Use an "explicit cast" to match the type "exactly", like 
                        printValue(static_cast<int>(value)); 
                                or 
                        printValue(static_cast<double>(value));.

                    Modify the function to take a float if float arguments are common in usage.

    This type of ambiguity arises when the "argument type" is compatible with "multiple overloaded functions" but doesn’t match any of them exactly.
*/
    
#include <iostream>

void printValue(int x) {
    std::cout << "Integer: " << x << std::endl;
}

void printValue(double x) {
    std::cout << "Double: " << x << std::endl;
}


int main() {
    float value = 5.5f;

    printValue(value); // Ambiguous call

    return 0;
}


// ----  rev[04-Nov-2024]  ----


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



