
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



    Note:
        There is no way to default 'a' and specify 'b'.

        Default arguments must be "CONSTANTS" or "GLOBAL" variables. They cannot be "local" variables or other parameters.

        Default arguments must be specified only once, either in the:
            function's prototype or 
            function's in its definition (must precedes the function's first use)
            
        The defaults CANNOT be specified in both the "prototype" and the "definition"


        All default parameters must be to the right side of any parameters that don't have defaults

                    void example(int a, int b = 10)     // Correct
                    void example(int a = 5, int b)      // Incorrect


        Also specified parameters can't stay left side of the default parameters
            i.e. Once you begin to define default parameters, you cannot specify any parameters that have no defaults


        Once the "first default argument" is specified, all following arguments must also have default values. 
            You can't skip some arguments. 
            For example, following will cause a compile-time error because "b" doesn't have a default:

                    void f(int a=0, int b)  // wrong! b must have a default too


        You can "omit" only the arguments from the "rightmost side". 
        You cannot skip middle arguments without skipping the ones after them.
            
            For example, in the function:
                            void f(int a = 0, int b = 1, int c = 2);

            You can call:
                            f();          // uses a=0, b=1, c=2
                            f(10);        // uses a=10, b=1, c=2
                            f(10, 20);    // uses a=10, b=20, c=2
                            f(10, 20, 30); // uses a=10, b=20, c=30


        Default arguments should "typically be placed" in the function declaration (prototype) and 
            not in the function definition itself.
            For example: 

                void f(int a = 0, int b = 0);  // Default values in the declaration

                void f(int a, int b) {
                    // function body
                }


        If "no single value" is more likely to be used, providing a default value isn't useful.
        If a specific value is required most of the time (say nine times out of ten), 
            it's a good idea to set it as a default argument for the function.



    DEFAULT arguments instead of OVERLOADING:
        A constructor is often overloaded to allow the creation of both initialized and uninitialized objects. 
        However, you can avoid overloading a constructor by giving it one or more default arguments. For example,

            // using default argument
            class myclass {
                    int x;
                public:
                    myclass(int n = 0) { x = n; }   // Constructor with a default argument
                    void display() {std::cout << "x = " << x << endl;}
            };


            // using constructor-overloading
            class myclass {
                    int x;
                public:
                    // Overloaded constructors
                    myclass(int n) { x = n; }
                    myclass() { x = 0; }
                    void display() {std::cout << "x = " << x << endl;}
            };


        So it is possible to create objects that have "explicit initial values" and those for which the default value is sufficient.



    ------------    Mixing DEFAULT arguments with Function OVERLOADING    ------------
    You can "mix" DEFAULT arguments and function OVERLOADING. 
    Be CAREFUL because they might CONFLICT if multiple overloaded functions match a call due to default arguments.



    ------------    Defaults Across Multiple Files    ------------
    If you declare a function with DEFAULT ARGUMENTS in a "header file" and define it in a "source file", 
        place the DEFAULT VALUES only in the "header file" to avoid redefinition errors



    ------------    Copy-Constructor with DEFAULT arguments    ------------
    We've seen the general form of a copy constructor with only one parameter. 
    However, it is possible to create copy constructors that take additional arguments, 
        as long as the additional arguments have default values. For example, 

            myclass( const myclass &obj , int x = 0){ 
                // body of constructor
            }

    As long as the first argument is a "reference to the object being copied", and all other arguments "default", 
        the function qualifies as a "copy constructor".
*/




/* Example 1: Here is a program that illustrates the default argumnets 

                Remember that once the first default argument is specified, all following parameters must have defaults as well.
                For example, this slightly different version of f() causes a compiletime error:

                    // wrong ! b must have default , too
                    void f(int a=0, int b){
                        std::cout <<"a: "<< a <<", b: "<< b;
                        std::cout <<'\n';
                    }
*/

#include <iostream>

void f(int a=0, int b=0){
    std::cout <<"a: "<< a <<", b: "<< b;
    std::cout <<'\n';
}	

int main(){	
    f();
    f(10) ;
    f(10 , 99);

    return 0;
}




/* Example 2: To understand how "default arguments" are related to function OVERLOADING, 
                consider the following program that overloads the function rect_area().
                This function calculates the area of a rectangle.


                The function is OVERLOADED in two ways:
                    non-square: with both "length" and "width" of the rectangle are passed, the first version is used.
                    square: When only one argument (length) is passed, the second version is called.

                However we can use "default arguments" instead:
                    Instead of creating two separate functions, the second parameter can be given a default value
                    If the default value is passed, the function assumes it’s a square and uses the same value for both dimensions.
*/

// Compute area of a rectangle using OVERLOADED functions
#include <iostream>

// Return area of a non - square rectangle
double rect_area(double length , double width){
    return length * width;
}

// Return area of a square
double rect_area(double length){
    return length * length;
}


int main(){
    std::cout << "10 x 5.8 rectangle has area : ";
    std::cout << rect_area(10.0, 5.8) << '\n';
    std::cout << "10 x 10 square has area : ";
    std::cout << rect_area(10.0) << '\n';

    return 0;
}



/*  Version 2: using default argument

    The default value for "width" is set to 0 because no rectangle can have a width of 0.
    If rect_area() sees the default value (0), it automatically assumes the shape is a square and 
        uses the "length" value for both length and width.

    Default arguments can simplify code and reduce the need for function overloading.
    However, there are still cases where function overloading is necessary.
*/

// Compute area of a rectangle using default arguments
#include <iostream>

// Return area of a rectangle .
double rect_area(double length , double width = 0){
    if(!width) width = length;  // checking the 2nd argument
    return length*width;
}

int main(){
    std::cout << "10 x 5.8 rectangle has area : ";
    std::cout << rect_area(10.0, 5.8) << '\n';
    std::cout << "10 x 10 square has area : ";
    std::cout << rect_area(10.0) << '\n';

    return 0;
}




// --------    constructors with default argumnets    --------

/* Example 3: It is not only legal but also common to use "default arguments in constructors".
                Instead of OVERLOADING a constructor for both initialized and uninitialized objects, 
                    you can often use DEFAULT arguments.
                This simplifies the code by eliminating the need for multiple constructor definitions.

                This program shows that by giving n a default value of 0, 
                    objects can be created with either explicit or default values.
*/
#include <iostream>

class myclass{
        int x;
    public:
        // Use DEFAULT argument instead of OVERLOADING myclass's constructor
        myclass(int n = 0){ x = n; }
        int getx(){ return x; }
};

int main(){
    myclass o1(10) ; // declare with initial value
    myclass o2; // declare without initializer

    std::cout << "o1: " << o1.getx() << '\n';
    std::cout << "o2: " << o2.getx() << '\n';
    
    return 0;
}







// --------  rev[22-Oct-2024]  --------

/* Example 4: Another good application for a default argument is found when a parameter is used to select an option. 
It is possible to give that parameter a default value that is used as a flag
that tells the function to continue to use the previously selected option. For example, in
the following program, the function print() displays a string on the screen. If its how
parameter is set to ignore, the text is displayed as is. If how is upper, the text is
displayed in uppercase. If how is lower, the text is displayed in lowercase. When how
is not specified, it defaults to -1, which tells the function to reuse the last how value. 



// ----  GPT  ----
A default argument can be useful for selecting an option in a function.
A parameter can be given a default value to act as a flag to indicate using the previously selected option.
Example: The function print() displays text.
If how is set to ignore, the text is displayed as is.
If how is upper, it is displayed in uppercase.
If how is lower, it is shown in lowercase.
When how is not specified, it defaults to -1, meaning the function reuses the previous how value.


Here is a C++ prototype for the print() function described:

cpp
Copy code
void print(const char* str, int how = -1);
Explanation:

const char* str: The string to be printed.
int how = -1: The how parameter is used to control how the string is displayed (with -1 as the default flag to reuse the previous value).



NOTE: it is not overloading any original or built-in print() function in C++.

C++ does not have a predefined print() function. Instead, C++ typically uses std::cout for printing to the console. So, when you define your own print() function like this:

cpp
Copy code
void print(const char* str, int how = -1);
You are not overriding or overloading any existing function in the standard library. This is simply defining your own function with the name print().

*/


#include <iostream>
#include <cctype>

const int ignore = 0;
const int upper = 1;
const int lower = 2;


void print(char *s, int how = -1);
int main ()
{
print (" Hello There \n", ignore );
print (" Hello There \n", upper );
print (" Hello There \n"); // continue in upper
print (" Hello There \n", lower );
print (" That ’s all \n"); // continue in lower
return 0;
}
/*
Print a string in the specified case . Use
last case specified if none is given .
*/
void print ( char *s, int how )
{
static int oldcase = ignore ;
// reuse old case if none specified
if(how <0)
how = oldcase ;
while (*s)
{
switch ( how )
{
case upper : cout << ( char ) toupper (*s);
break ;
case lower : cout << ( char ) tolower (*s);
break ;
default : cout << *s;
} s
++;
}
oldcase = how ;
}
This function displays the following output:
Hello There
HELLO THERE
HELLO THERE
hello there
that’s all




/* Example 5: Earlier in this chapter, you saw the general form of a copy constructor. This general form
was shown with only one parameter. However, it is possible to create copy constructors
that take additional arguments, as long as the additional arguments have default values.
For example, the following is also an acceptable form of a copy constructor: */



myclass ( const myclass &obj , int x = 0)
{
// body of constructor
}
As long as the first argument is a reference to the object being copied, and all other
arguments default, the function qualifies as a copy constructor. This flexibility allows you
to create copy constructors that have other uses.




/* Example 6: Although default arguments are powerful and convenient, when used correctly, default
arguments allow a function to perform its job in an efficient and easy-to-use manner.
However, this is only the case when the default value given to a parameter makes sense.
For example, if the argument is the value wanted nine times out of ten, giving a function
a default argument to this effect is obviously a good idea. However, in cases in which no
one value is more likely to be used than another, or when there is no benefit to using a
default argument as a flag value, it makes little sense to provide a default value. Actually,
providing a default argument when one is not called for destructures your program and
tends to mislead anyone else who has to use that function.
As with function overloading, part of becoming an excellent C++ programmer is knowing
when to use a default argument and when not to.

 */







/* Example 1: In the C++ standard library is the function strtoi(), which has this prototype:
long strtoi ( const char *start , const ** end , int base );
The function converts the numeric string pointed to by start into a long integer. The
number base of the numeric string is specified by base. Upon return, end points to the
character in the string immediately following the end of the number. The long integer
equivalent of the numeric string is returned. base must be in the range 2 to 38. However,
most commonly, base 10 is used.
Create a function called mystrtoi() that works the same as strtoi() except that ( base)
is given the default argument of 10. (Feel free to use strtoi() to actually perform the
conversion. It requires the header <cstdlib>.) Demonstrate that your version works
correctly. */




/* Example 2: What is wrong with the following function prototype? */
char *f( char *p, int x = 0, char *q);




/* Example 3: Most C++ compilers supply nonstandard functions that allow cursor positioning and the
like. If your compiler supplies such functions, create a function called myclreol() that
clears the line from the current cursor position to the end of the line. However, give
this function a parameter that specifies the number of character positions to clear. If the
parameter is not specified, automatically clear the entire line. Otherwise, clear only the
number of character positions specified by the parameter. */




/* Example 4: What is wrong with the following prototype, which uses a default argument? */
int f( int count , int max = count );



