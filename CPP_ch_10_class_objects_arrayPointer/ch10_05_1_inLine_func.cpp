
/*  ------------------------    In-Line Functions    ------------------------
    IN-LINE FUNCTIONS: 
        In C++, IN-LINE FUNCTIONS are not actually called but, rather, are expanded in line, at the point of each call. 
        This is much the same way that a C-like parameterized macro works 
        (recall 8.1, C_Ch8_1_adv_define_include.c function-like macro). 

        The advantage is, no overhead associated with the 'function call and return mechanism
            makes an in-line functions executed much faster than normal functions. 
        
        The disadvantages of in-line functions is that if they are too large and called too often, your program grows larger. 
            In general only 'short functions' are declared as in-line functions.


    Declaration:
        simply precede the function's "definition" with the "inline" specifier. For Example :

                inline int even(int x) { return !(x%2); }

        The function even(), which returns true if its argument is even, is declared as being-in-line. 
        It means that,   
                                            if(even(x)) cout << "Even";    
            is functionally equivalent to:   
                                            if(!(x%2)) cout << " Even ";


    Restrictions:
        An in-line function must be defined before it is first called.  
            That's why even() must defined before main().

            inline int even(int x) { return !(x%2); }
            int main(){
                . . . . . . . . . 
            }

        Some compilers will not in-line a function if it contains 
            a 'static' variable, 
            a loop statement, 
            a switch or a goto, or 
            if the function is RECURSIVE.


    Remember, the inline specifier is a "REQUEST", not a "command", to the compiler. 
    If any in-line restriction is 'violated', the compiler is free to generate a 'normal function' 
        (i.e. the function is compiled as a normal function and the inline request is ignored.). 


    Any type of function can be in-lined, including: 
        Member-functions of classes.
        Overloaded function
*/




/*  ------------    inline vs macro    ------------
    using inline provides a more structured way to 'expand short functions in line'. 
        For example, when you are creating a parameterized macro, it is easy to forget the extra parentheses.


    an in-line function might be able to be 'optimized more thoroughly' by the compiler than a MACRO expansion. 

    C++ PROGRAMMERS virtually never use 'parameterized macros', instead relying on inline 
        to avoid the overhead of a function call associated with a short function.
*/




/*  ------------    Inline vs normal functions    ------------
    C++ provides inline functions to reduce the 'function call overhead'. 
        An inline function is a function that is expanded in line when it is called. 

    When the inline function is called whole code of the inline function gets 
        "inserted or substituted" at the point of the inline function call. 

    This substitution is performed by the C++ COMPILER at "compile time". 

    An inline function 'may increase efficiency' if it is SMALL.



    Syntax:

        inline return-type function-name(parameters) {
            // function code
        }  



    Normal function:
        in this case fn() stays outside main()

        start: main() -> flow ctrl transfer -> fn() -> stop
                or -> stop


    In-line function:
        in this case fn() goes inside main(), there is no 'flow ctrl transfer' outside main()

        start: main() ->  fn() -> stop
*/






/*  ------------    Advantage and Dsiadvantage of in-line functions (ChatGPT)    ------------
    An inline function in C++ is 'expanded in place' at the point of call, rather than being called like a regular function. 

    inline expansion:
        When a function is declared as inline, the compiler "replaces" each call to that function "with the corresponding function body". 
        This process is done during compile time


    ----  Advantage  ----
    Performance Improvement: 
        By eliminating the overhead of function calls, such as: 
            pushing arguments onto the stack, 
            jumping to the function, and 
            returning), 

        inline functions can improve performance if:
            the funcion is small and
            frequently-called


    Reduced Function Call Overhead: 
        Since the function body is inserted directly at the call site, 
            there's no need to save and restore the program state, 
            leading to reduced overhead associated with function calls.


    Optimization Opportunities: 
        The compiler has more visibility into the function body, which may enable additional optimizations, such as 
            constant propagation, 
            dead code elimination, and 
            loop unrolling.


    Avoidance of "Linker Errors": 
        In C++, functions defined in header files that are included in multiple source files can lead to 'linker error's due to 'multiple definitions'.
        Declaring such functions as inline can help avoid such errors by allowing multiple definitions of the same function across translation units, as long as they are identical.




    ----  Disadvantages  ----
    Note that the 'inline' keyword is just a suggestion to the compiler, and the compiler 'may choose to ignore' it. 
        Whether a function is actually inlined or not depends on various factors, including: 
            the size of the function, 
            optimization settings, and the 
            compiler's heuristics.

    It's typically best to use inline functions for small, frequently-called functions


    Code Bloat: 
        Inlining a function involves copying its code to every call site. 
        If the function is large or called from many places, this can lead to increased code size, 
        affectiing 'memory usage' and 'cache' performance.

    Compiler Heuristics: 
        the compiler 'may choose to ignore' inline keyword depending on optimization settings, function size, and other factors.

    Debugging Complexity: 
        Inlined functions can complicate debugging, as the function call stack may not accurately reflect the "program's execution flow".
        
    Increased Compilation Time: 
        for large projects with many inline function calls cause more compile time
        compiler needs to "process and GENERATE code" for each inline function at every call site.

    Binary Size Increase: 
        Inlined functions can increase the size of the binary executable, 
        which may be undesirable where minimizing file size is a priority.

    Potential for Duplicated Code: 
        Inlining functions can lead to code duplication if the same function is inlined in multiple places. 
        This can increase maintenance overhead and make it harder to ensure consistency across the codebase.

    Limited Optimization Opportunities: 
        Inlining functions may limit certain optimization opportunities, such as 
            function-level optimizations and interprocedural optimizations, which rely on separate function bodies.

*/




/* Example 1: To declare an in-line function, simply precede the function’s definition with the inline specifier.
                For example, this short program shows how to declare an in-line function: */

#include <iostream>

inline int even(int x){
    return !(x %2);
}

int main(){
    if(even(10)) std::cout << "10 is even \n";
    if(even(11)) std::cout << "11 is even \n";
    return 0;
}


/*  The function even(), which returns true if its argument is even, 
    even() being in-line means that the line:

                                    if(even(10)) cout << "10 is even \n";

    is functionally equivalent to:      
                                    if (!(10%2)) cout << "10 is even \n";

    'even(10)' replaced with '!(10%2)' at compile time.


    An in-line function must be "DEFINED" (just declaration won't work) before it is first called. 
        otherwise the compiler has no way to know that it is supposed to be "EXPANDED in-line". 
*/




/* Example 2: Any type of function can be in-lined, including Member-functions of classes.
                Here the member function divisible() is in-lined for 'fast execution'.
                    The function returns true if its first argument can be evenly divided by its second. 
*/

// in-lining a member function
# include <iostream >
using namespace std ;
class samp
{
int i, j;
public :
samp ( int a, int b);
int divisible (); // in - lined in its definition
};
samp :: samp ( int a, int b)
{
i = a;
j = b;
}
/*
Return 1 if i is evenly divisible by j.
This member function is expanded in line .
*/
inline int samp :: divisible ()
{
return !(i%j);
}
int main ()
{
samp ob1 (10 , 2) , ob2 (10 , 3);
// this is true
if( ob1 . divisible ())
cout << "10 divisible by 2\n";
// this is false
if( ob2 . divisible ())
cout << "10 divisible by 3\n";
return 0;
}




/* Example 3: It is perfectly permissible to in-line an overloaded function.
                This program overloads min() three ways. Each way is also declared as inline. */
# include <iostream >
using namespace std ;
// Overload min () three ways .
// integers
inline int min ( int a, int b)

{
return a<b ? a : b;
}
// longs
inline long min ( long a, long b)
{
return a<b ? a : b;
}
// doubles
inline double min ( double a, double b)
{
return a<b ? a : b;
}
int main ()
{
cout << min (-10, 10) << "\n";
cout << min ( -10.0 , 100.002) << "\n";
cout << min ( -10L, 12L) << "\n";
return 0;
}




/* Example 4: In "cpp_ch9_3_func_ovrld.cpp" you overloaded the abs() function 
                so that it could find the absolute value of integers, long integers, and doubles. 
                Modify that program so that those functions are "Expanded in-line". 
*/



/* Example 5: Why might the following function not be in-lined by your compiler? Loop, & no inline keyword? */
void f1 ()
{
int i;
for (i =0; i <10; i ++)
cout << i;
}



