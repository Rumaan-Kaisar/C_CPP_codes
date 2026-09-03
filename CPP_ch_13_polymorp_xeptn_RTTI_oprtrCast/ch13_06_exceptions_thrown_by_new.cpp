
/*  ------------------------    Exceptions thrown by "new"    ------------------------

    In old C++, "new" returned "null" when memory allocation failed. 
    Modern C++ throws an "exception" by default when allocation fails. 
    However, you can choose to make it "return null" instead (as an option).

    
    --------  Allocation exceptions with "new" and "xalloc" or "bad_alloc"  --------

    When new cannot allocate memory, it throws a "bad_alloc" exception (xalloc in older versions).
    If you do not handle the exception, the program will terminate.

    For small programs, this may be acceptable. 
    In real applications, it is better to catch the exception and handle the error properly.
    
    Handling the exception:
        To use "bad_alloc", you must include the header: #include <new>

        nothrow - Returning old fashioned null In Standard C++:
            You can make "new" return "null" instead of throwing an exception using "nothrow" when an allocation failure occurs
            This form of new is :   
                
                p_var =new(nothrow) type;

            Here "p_var" is a pointer variable of "type". 

        Why use "nothrow"? 
            It behaves like the old version of "new". 
            If memory allocation fails, it returns "null" instead of throwing an "exception".

        This is useful when:
            Working with old C++ code with a modern C++ compiler.
            Replacing malloc() with new.
            You want to avoid exception handling.
*/  




/* Example 1: Following uses "new" with a try/catch block for an allocation failure. */

#include <iostream>
#include <new>

int main() {
    int *p;
    
    // any allocation failure will caught by the catch statement.
    try {
        p = new int;    // allocate memory for int
    }
    catch(std::bad_alloc xa) {
        std::cout << " Allocation failure .\n";
        return 1;
    }

    for(*p = 0; *p < 10; (*p)++) std::cout << *p << " ";
    delete p;   // free the memory

    return 0;
}



        
/* Example 2: Since the previous program normally does not fail, 
                the next program shows how new throws an exception when memory allocation fails.

                Forcing an allocation error:
                It does this by continuously allocating memory until all available memory is used up.
*/

#include <iostream>
#include <new>

int main() {
    double *p;
    // Force an allocation failure:

    do {
        try{
            p = new double [100000];    // this will eventually run out of memory
        }
        catch(std::bad_alloc xa) {
            std::cout << " Allocation failure .\n";
            return 1;
        }
    } while(p);

    return 0;
}




/* Example 3: The following program shows how to use the new(nothrow) alternative. 
                It reworks above program and forces an allocation failure. 

                Remember, when you use the "nothrow" approach, 
                you must "check" the "pointer returned by new" after each allocation request.
*/

#include <iostream>
#include <new>

int main() {
    double *p;
    // Force an allocation failure:
    do {
        // notice the use of "new ( nothrow )"
        p = new (std::nothrow) double [100000];    // this will eventually run out of memory

        if(p) std::cout << " Allocation OK\n";
        else std::cout << " Allocation failure .\n";
    
        // notice, no try-catch is used
    } while(p);

    return 0;
}




/* Example 4:   1. Explain the difference between the behavior of "new" and "new(nothrow)" when an allocation failure occurs.
                2. Given the following fragment, show two ways to convert it into modern C++-style code.

                        p = malloc( sizeof(int) );
                        if(!p){
                            cout << " Allocation error .\n";
                            exit(1);
                        }

            ans:
                By default, new throws an "exception" when an allocation error occurs. 
                The nothrow version of new "returns a null pointer" if memory cannot be allocated.


                way 1:
                    p = new (nothrow) int;
                    if(!p){
                        cout << " Allocation error .\n";
                        // ...
                    }

                way 2:
                    try{
                        p = new int ;
                    }
                    catch(bad_alloc ba) {
                        cout << " Allocation error .\n";
                        // ...
                    }
*/




