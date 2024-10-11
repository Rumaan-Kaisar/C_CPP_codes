
/*  ------------------------    Default Arguments    ------------------------

    Default Arguments in Functions:
        Default arguments allow you to assign a default value to a function parameter, 
            so if a function is called "without specifying arguments" for those parameters, the default values are used. 

        Using default arguments is essentially a "shorthand form" of function overloading.


    Assign a default argument:
        To assign a default argument, follow the parameter with an equal sign (=) and specify the default value. 
        For example, the function below provides default values of 0 for both of its parameters:

                void f(int a = 0, int b = 0);

        If the function f() is called without arguments, it will use the default values a = 0 and b = 0.


    Similar to variable initialization:
        Notice that this syntax is similar to variable initialization. 
        This function can now be called three different ways. 

            it can be called with both arguments specified. Example: 
                    f(10, 99);      // a is 10, b is 99 

            it can be called with only the first argument specified. In this case, b will default to 0. Example: 
                    f(10);          // a is 10, b defaults to 0 

            Finally, f() can be called with no arguments, causing both a and b to default to 0. Example: 
                    f();            // a and b default to 0



	Notice that this syntax is similar to variable initialization. This function can now be called three different ways. 
[1]	First, it can be called with both arguments specified. Example: f(10, 99); 		/* a is 10, b is 99*/ 
[2]	Second, it can be called with only the first argument specified. In this case, b will default to 0. Example: 
f(10); 	/* a is 10, b defaults to 0 */
[3]	Finally, f() can be called with no arguments, causing both a and b to default to 0. Example: 
f(); 		/* a and b default to 0*/




----  GPT more  ----
here are a few important points to know about default arguments in C++:

Order of Default Arguments: When using default arguments, any parameter with a default value must be to the right of those without. For example, this is correct:

cpp
Copy code
void f(int a, int b = 0);
But this is incorrect:

cpp
Copy code
void f(int a = 0, int b);
Omission of Arguments: When calling a function with default arguments, you can omit only the arguments from the rightmost side. For example, in the function:

cpp
Copy code
void f(int a = 0, int b = 1, int c = 2);
You can call:

cpp
Copy code
f();          // uses a=0, b=1, c=2
f(10);        // uses a=10, b=1, c=2
f(10, 20);    // uses a=10, b=20, c=2
f(10, 20, 30); // uses a=10, b=20, c=30
But you cannot skip middle arguments without skipping the ones after them.

Declaration in Function Prototype: Default arguments should typically be placed in the function declaration (prototype) and not in the function definition itself. For instance:

cpp
Copy code
void f(int a = 0, int b = 0);  // Default values in the declaration
void f(int a, int b) {
    // function body
}
Mixing with Function Overloading: You can mix default arguments and function overloading. However, care should be taken because they might conflict if multiple overloaded functions match a call due to default arguments.

Defaults Across Multiple Files: If you declare a function with default arguments in a header file and define it in a source file, place the default values only in the header file to avoid redefinition errors.




// --------    rev point 2: [10-Oct-2024]    --------


	It is clear that there is no way to default a and specify b.
	There are several rules to specify default arguments :
	Default arguments must be specified only once: either in the function's prototype or in its definition if the definition precedes the function's first use. The defaults cannot be specified in both the prototype and the definition. 
	All default parameters must be to the right side of any parameters that don't have defaults.  Once you begin to define default parameters, you cannot specify any parameters that have no defaults (i.e. specified parameters can't stay left side of the default parameters).
	Default arguments must be constants or global variables. They cannot be local variables or other parameters.
Here is a program that illustrates the example described in the preceding discussion:

void f(int a=0, int b=0){
cout <<"a: "<< a <<", b: "<< b;
cout <<'\n';}	int main(){	f();
		f(10) ;
		f(10 , 99);
		return 0;}	output:
	a: 0, b: 0
	a: 10, b: 0
	a: 10, b: 99
	All arguments must specified as default:  We can't make any specific argument to default. Once the first default argument is specified, all following parameters must have defaults as well. For example, this slightly different version of f() causes a compile- time error:
void f(int a=0, int b) 		/* wrong! b must have default , too */ 
Many times a constructor is overloaded simply to allow both initialized and uninitialized objects to be created. In many cases, you can avoid overloading a constructor by giving it one or more default arguments. For example,

myclass(int n = 0) { x = n; } 	/* default argument instead of overloading constructor */
. . . . . . 
. . . . . . 
myclass o1(10) ;  			/* declare with initial value */ 
myclass o2;  				/* declare without initializer */ 

So it is possible to create objects that have explicit initial values and those for which the default value is sufficient.
	Cpy-Constructor with default arguments: We've seen the general form of a copy constructor with only one parameter. However, it is possible to create copy constructors that take additional arguments, as long as the additional arguments have default values. For example, 

myclass( const myclass &obj , int x = 0){ /* body of constructor */ }

As long as the first argument is a reference to the object being copied, and all other arguments default, the function qualifies as a copy constructor. This flexibility allows you to create copy constructors that have other uses.

Note
[1]	Another good application for a default argument is found when a parameter is used to select an option.
[2]	Although default arguments are powerful and convenient, they can be misused. For example, 
	If the argument is the value wanted nine times out of ten, giving a function a default argument to this effect is obviously a good idea. 
	In cases in which no one value is more likely to be used than another, or when there is no benefit to using a default argument as a flag value, it makes little sense to provide a default value.



*/  
