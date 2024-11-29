
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

        Like function overloading, knowing when to use a default argument and 
            when not to is essential for writing clear, effective C++ programs



    Note:
        There is no way to default 'a' and specify 'b'.

        Default arguments must be "CONSTANTS" or "GLOBAL" variables. They cannot be "local" variables or other parameters.

        Default arguments must be specified only once, either in the:
            function's prototype or 
            function's definition (must precedes the function's first use)
            
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



    ------------    Definition  or Declaration(prototype)?    ------------
    
    You do not need to specify the default argument again in the function "definition" 
        if you have already specified it in the "declaration"
    
    Default arguments in C++ are specified only in the function declaration (prototype).
    
    The compiler uses the default arguments defined in the prototype 
        when the function is called without explicitly providing the argument.
    
    Including the default argument in the definition is unnecessary and can lead to a compile-time error 
        in some cases because the compiler expects the default value to be specified only once.



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




/* Example 4: A default argument can be useful for selecting an OPTION in a function.
                A parameter can be given a "default value" to act as a flag to indicate using the previously selected option.

                For example the function print() displays text.
                    If "how" is set to "ignore", the text is displayed as is.
                    If "how" is "upper", it is displayed in uppercase.
                    If "how" is "lower", it is shown in lowercase.
                    When "how" is not specified, it defaults to -1, meaning the function reuses the previous how value.


                Here is a C++ prototype for the print() function described:

                        void print(char *s, int how = -1);

                    char *s: The string to be printed.
                    int how = -1: The how parameter is used to control how the string is displayed 
                                    (with -1 as the default flag to reuse the previous value).


                NOTE: 
                    We're not overloading any original or built-in "print()" function in C++.
                    C++ does not have a predefined "print()" function (like C). 
                    Instead, C++ typically uses "std::cout" for printing to the console. 

                    So, when you define your own print() function like this:

                        void print(char *s, int how = -1);

                    You are not overriding or overloading any existing function in the standard library.
*/


#include <iostream>
#include <cctype>

const int ignore = 0;
const int upper = 1;
const int lower = 2;

void print(char *s, int how =-1);      // prototype with default value

int main(){
    print(" Hello There \n", ignore);
    print(" Hello There \n", upper);
    print(" Hello There \n");   // continue in upper
    print(" Hello There \n", lower);
    print(" That ’s all \n");   // continue in lower

    return 0;
}


/*  function definition: 
        Print a string in the specified case. 
        Use last case specified if none is given
*/
void print(char *s, int how){   // default value of "how" given in prototype
    static int oldcase = ignore;

    // reuse old case if none specified
    if(how<0) how = oldcase;
    while(*s){
        switch(how){
            case upper: 
                std::cout << (char)toupper(*s);
                break;
            case lower:
                std::cout << (char)tolower(*s);
                break;
            default:
                std::cout << *s;
        }
        s++;
    }
    oldcase = how;
}


/*  Above program demonstrates how to use "default arguments" and a STATIC variable 
        to "remember" the last "how" parameter in the print() function.

    Explanation:
        In C++, remembering a previous state or value (like the "old case" for "how" in the print() function example) 
            can be done by using "static variables". 
            These variables retain their value between function calls.


        A static variable inside a function maintains its value even after the function returns.
            We declare "oldcase" as static and it stores "how" values, 
                and it will preserve its value across multiple calls.

            The static variable "oldcase" is used to remember the last case (ignore, upper, lower) across multiple function calls. 
                This way, if "how" is not specified, it reuses the previous setting.


        The "how" parameter is given a default value of -1. 
            If the user doesn't specify "how", it uses the last case stored in "oldcase"
*/




/* ------------    lifetime of a static variable    ------------ 

    Is a static variable destroyed after a function call, even if it's defined inside the function?

        No, static variables are not destroyed after a function call, even if they are defined inside the function.
        Static variables have a lifetime that lasts for the entire duration of the program. 
        Once initialized, they retain their value between multiple calls to the function.


        * Static local variables are not destroyed when the function ends.
        * They stay in memory for the entire duration of the program.
        * Even though they are defined inside a function, they retain their value between function calls.
        * Their scope is limited to the function, but their lifetime lasts as long as the program runs.
*/




/* Example 5: Earlier in "ch11_01_2_copy_constructor.cpp" we saw the general form of a copy constructor. 
                This general form was shown with only one parameter.

                However, it is possible to create copy constructors that take additional arguments, 
                    as long as the additional arguments have "DEFAULT values".
*/

myclass (const myclass &obj, int x = 0){
    // body of constructor
}

/*  As long as the first argument is a "reference to the object being copied", and all other arguments default, 
        the function qualifies as a copy constructor.  
*/




/* Example 1: In the C++ standard library is the function strtol(), which has this prototype:

                        long strtol(const char *start, const **end, int base);

                The function converts the "numeric string" pointed to by "start" into a long integer. 
                The number base of the numeric string is specified by base. 
                Upon return, "end" points to the character in the string immediately following the end of the number.

                The long integer equivalent of the numeric string is returned. base must be in the range 2 to 36. 
                    However, most commonly, base 10 is used.

                
                Create a function called mystrtoi() that works the same as strtoi() or strtol()
                    except that (Base) is given the default argument of 10. 
                    (Feel free to use strtoi() to actually perform the conversion. It requires the header <cstdlib>.) 
*/

#include <iostream>
#include <cstdlib>

long mystrtol(const char *s, char ** end, int base = 10){
    return strtol(s, end , base );
}


int main(){
    long x;
    char *s1 = " 100234 ";
    char *p;

    x = mystrtol (s1 , &p, 16);
    std::cout << " Base 16: " << x << '\n';
    x = mystrtol (s1 , &p, 10);
    std::cout << " Base 10: " << x << '\n';
    x = mystrtol (s1 , &p); // use default base of 10
    std::cout << " Base 10: " << x << '\n';

    return 0;
}




/* Example 2: What is wrong with the following function prototype? 

                        char *f(char *p, int x = 0, char *q);
            ans:
                All parameters taking default arguments must appear to the "right" of those that do not.

                That is, once you begin giving parameters defaults, 
                    all subsequent parameters must also have defaults.
                    In the above code, q is not given a default.

*/




/* Example 3: Many C++ compilers provide "nonstandard functions" for cursor positioning.

                If such functions are available, create a function named myclreol() 
                    to clear the line from the current cursor position to the end of the line.
                    
                Add an optional parameter to myclreol() that specifies the "number of characters" to clear.
                    If the parameter is not provided, the function should clear the entire line.
                    If the parameter is provided, the function should clear only 
                        the specified number of characters from the current cursor position.
*/

// Since cursor positioning functions differ from compiler to compiler and environment to environment, only one possible solution is shown.

// The following program works for Borland C++ under a command-prompt environment.
// Note : This program is Borland C++- specific

#include <iostream>
#include <conio.h>

void myclreol(int len = -1);


int main(){
    int i;

    gotoxy(1, 1);
    for(i=0; i<24; i++) std::cout << " abcdefghijklmnopqrstyvwxyz1234567890 \n";
    
    gotoxy(1, 2);
    myclreol();
    
    gotoxy(1, 4);
    myclreol(20) ;

    return 0;
}


// Clear to end of line unless len parameter is specified .
void myclreol(int len){
    int x, y;

    x = wherex();   // get x position
    y = wherey();   // get y position
    
    if(len == -1) len = 80-x;
    int i = x;
    for( ; i <= len ; i ++) std::cout << ' ';
    gotoxy (x, y); // reset the cursor
}




// --------    ChatGPT: above code converted for GCC    --------
/*  The original code relies on Borland-specific functions like gotoxy(), wherex(), and wherey() for cursor manipulation. 
    Unfortunately, these functions aren't part of the C++ standard library and are not available in GCC.

    To make it compatible with GCC and standard C++, we need to use ANSI escape codes for cursor control instead, 
    which work in most Unix-like environments, including Linux terminals.

    Here's the equivalent code that should work in a typical GCC setup with a terminal that supports ANSI escape codes: 
*/

// version 2
#include <iostream>
#include <string>

void gotoxy(int x, int y) {
    // Move cursor to (x, y) using ANSI escape codes
    std::cout << "\033[" << y << ";" << x << "H";
}

void myclreol(int len = -1) {
    int x, y;
    
    // Get current cursor position in a terminal-independent way is challenging in standard C++. 
    // However, for demonstration, we assume the cursor is at (1, 1) when the program starts.
    
    // Clear till end of line or till specified length
    if(len == -1){
        // Clear till the end of the line (from current position to 80 columns)
        std::cout << "\033[K";
    } 
    else{
        // Clear specified length by printing spaces
        for(int i = 0; i < len; i++) {
            std::cout << ' ';
        }
        // Move the cursor back to the start position after clearing
        std::cout << "\033[" << len << "D";
    }
}

int main(){
    int i;

    gotoxy(1, 1);
    for(i=0; i<24; i++) std::cout << "abcdefghijklmnopqrstuvwxyz1234567890\n";
    
    gotoxy(1, 2);
    myclreol();         // Clear from the current position till the end of the line

    gotoxy(1, 4);
    myclreol(20);       // Clear only 20 characters from the current position

    return 0;
}


/*     --------    Explanation    --------
    gotoxy(int x, int y): 
        This function uses ANSI escape codes to move the cursor to the specified coordinates (x, y). 
        The format "\033[<y>;<x>H" is an ANSI escape code that positions the cursor.

    myclreol(int len = -1):
        When "len" is -1, it clears from the current cursor position to the end of the line using "\033[K".
        When "len" is specified, it clears only "len" characters by printing spaces. 
            After printing spaces, it moves the cursor back to the original position using "\033[<len>D" to reset the position.
*/




/* Example 4: What is wrong with the following prototype, which uses a default argument? 

                    int f(int count, int max = count);
                
                ans:
                    A default argument cannot be another parameter or a local variable.
*/




/* Example 5: Briefly describe a default argument. 

                ans:
                    A default argument is a value that is given to a function parameter 
                    when no corresponding argument appears when the function is called.
*/




/* Example 6: What is wrong with the following prototype?

                    char * wordwrap( char *str , int size = 0, char ch); 

                All parameters receiving default arguments must appear to the right of those that do not.

                NOTE: 
                    Both "char *wordwrap" and "char * wordwrap" are syntactically correct in C++ and mean the same thing.
                    The most common style is "char *wordwrap", where the * is grouped with the variable name or function name
*/




/* Example 7: Create a function called reverse() that takes two parameters. 

                The first parameter, called "str", is a pointer to a string 
                    that will be reversed upon return from the function. 

                The second parameter is called "count", and 
                    it specifies how many characters of str to reverse.

                Give count a default value that, when present, tells reverse() to reverse the entire string.
 */

#include <iostream>
#include <cstring>

void reverse(char *str , int count = 0);    // declaration with "default value"


int main(){
    char s1[] = " This is a test. ";
    char s2[] = " I like C++. ";

    reverse(s1); // reverses entire string
    reverse(s2 , 7); // reverse first 7 chars
    std::cout << s1 << '\n';
    std::cout << s2 << '\n';

    return 0;
}


// function definition
void reverse(char *str , int count){
    int i, j;
    char temp;

if(!count) count = strlen(str) - 1;

    for(i=0, j= count; i<j; i++, j--){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}




/* Example 8: Explain why using a default argument is related to function overloading. 

                A "default argument" is essentially a 'shorthand' approach to function overloading 
                    because the net result is the same. For example:

                        int f(int a, int b = 0);

                is functionally equivalent to these two overloaded functions:

                        int f(int a);
                        int f(int a, int b);
*/


