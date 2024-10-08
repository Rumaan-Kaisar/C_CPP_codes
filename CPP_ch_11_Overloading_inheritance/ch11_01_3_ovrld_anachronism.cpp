
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
        you may still see overload used in very old C++ programs.
    
    The general form of using keyword "overload" is:

                        overload func_name ;

        where func_name is the name of the function to be overloaded.
        This statement must "precede" the "overloaded function DECLARATIONS". 
        Also notice: the parentheses "()" were not included after the function name. For example:

                        overload timer;  // No parentheses after "timer"

            The reason for this is that the keyword "overload" was not defining or declaring the function itself.
            Instead, it just informing the compiler that the function "timer" would have multiple overloaded versions, 
                the actual function declarations and definitions would come later, which do use (), with their respective parameter lists.
            It's just a directive or a marker for the compiler, not a function declaration or definition.

*/  

// ----  Old version of function oveloading  ----
overload timer;  // Tells the compiler that `timer` will be overloaded

int timer(int hours) {
    // Function body for one version of timer()
}

double timer(double seconds) {
    // Function body for another version of timer()
}




// ----  Modern C++ function overloading  ----
// In modern C++, you would simply define multiple versions of the function without any special keyword

int timer(int hours) {
    // Function body for one version of timer()
}

double timer(double seconds) {
    // Function body for another version of timer()
}

