#include<iostream>
// using namespace std; /* without namespace */

int main(){
    std::cout << "Hello World!" << std::endl;
    /*  'std::cout' is the standard output stream object, defined in "iostream", and it prints to the standard output (stdout).
        '<<' is, in this context, the "stream insertion operator", so called because it inserts an object into the stream object.
        The standard library defines the << operator to perform data insertion for certain data types into output streams. "stream << content" inserts "content" into the "stream" and returns the same, but updated stream
    */
   /* 
        std::endl is a special I/O "stream manipulator object", also defined in file "iostream". 
        Inserting a manipulator into a stream changes the state of the stream.
        
        The stream manipulator "std::endl" does two things: 
            first it inserts the end-of-line character and then 
            it flushes the stream buffer to force the text to show up on the console.     
        This ensures that the data inserted into the stream actually appear on your console.
    */
}

// #include <iostream> is a preprocessor directive

// "iostream" is a standard library header file that contains definitions of the standard input and output streams.

// "int main()" main function is called upon execution of the program. 
    // There must be only one main function in a C++ program, and it must always return a number of the int type.
    // The int is what is called the function's return type. The value returned by the main function is an exit code.
    // By convention, a program exit code of "0" or "EXIT_SUCCESS" is interpreted as success by a system that executes the program. Any other return code is associated with an error

/* 
    If no return statement is present, the main function (and thus, the program itself) returns 0 by default. 

    In this example, we don't need to explicitly write return 0;.
    
    All other functions, except those that return the void type, must explicitly return a value according to their return type, or else must not return at all.
 */

