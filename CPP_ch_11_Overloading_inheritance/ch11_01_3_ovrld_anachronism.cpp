
/*  ------------------------    overload anachronism    ------------------------
    When C++ was first invented, the keyword "overload" was required to create an overloaded function.

        In the early versions of C++, the keyword "overload" was required to "EXPLICITLY indicate" 
            that a function would have multiple versions (overloaded functions)
            
        The keyword was used to "notify the compiler" that a function, 
            with the same name but different parameters, would be declared multiple times within the program.

        For example, if you were going to create several versions of a function named "timer()", you would first write:

                        overload timer;

            This would tell the compiler that timer() is going to be overloaded, 
                and different versions of timer() would follow. 
            Each version of timer() would have different parameter lists.



    --------    Modern C++ compilers "no longer require or support"    --------
    Modern C++ compilers "no longer require or support" the overload keyword. 
    Function overloading is now "AUTOMATICALLY recognized" by the compiler as long as each function has a "unique signature" 
        (i.e., a different combination of parameter types or numbers).

    Although the keyword "overload" is now obsolete and no longer supported by modern C++ compilers, 
        you may still see overload used in old programs.
    
    


The general form of overload is shown here,
overload func_name ;
where func-name is the name of the function to be overloaded. This statement must precede
the overloaded function declarations. For example, this tells the compiler that you will be
overloading a function called time():
overload timer ;
Remember: overload is obsolete and no longer supported by modern C++ compilers.








Though this keyword is no longer needed, it might still be seen in very old programs, so understanding it helps when reviewing legacy C++ code. Today, when you overload a function, you simply declare it multiple times with different parameters, without needing the overload keyword.

Key points:

overload was a way to mark functions for overloading in early C++.
It's now obsolete and not supported by modern compilers.
Modern C++ automatically handles function overloading based on the function's signature.

*/  
