
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

 */
