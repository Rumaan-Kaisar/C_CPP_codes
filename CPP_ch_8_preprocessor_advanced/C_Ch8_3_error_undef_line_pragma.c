
/* 
    ----------------    directives #error #undef #line  #pragma    ----------------

    C's preprocessor supports four special-use directives: 

            #error
            #undef
            #line 
            #pragma
    

    #error: 
        General form
                        #error error-message
    
        It causes the compiler to STOP COMPILATION and issue the ERROR-MESSAGE along with other implementation-specific information, 
            which will generally include the' number of the line the #error directive' is in and the 'name of the file'. 
    
            Note that the error-message is 'not enclosed between QUOTES'. 
            The principal use of the #error directive is in 'debugging'.


    #undef: 
        The #undef directive undefines a macro name. Its general form is
    
                        #undef macro-name

            If the macro-name is currently undefined, #undef has 'no effect'. 
            The principal use for #undef is to "LOCALIZE macro names".


    #line: 
        When a C compiler compiles a source file, it maintains two pieces of information: 
            the number of the line currently being compiled and 
            the name of the source file currently being compiled. 
            
            The #line directive is used to change these values. Its general form is
    
                        #line line_num "filename"

                Here, 'line_num' becomes the "number of the next line of source code", and 
                'filename' becomes the name the compiler will associate with the source file.

        The value of 'line_num' must be between 1 and 32,767. 
        The filename may be a string consisting of any valid file name. 
        
        The principal use for #line is for "DEBUGGING" and for 'managing large projects'.


    #pragma: 
        allows a compiler's implementor to define 'other preprocessing instructions' to be given to the compiler. 
        It has this general form:
    
                        #pragma instructions

        If a compiler encounters a #pragma statement that it does not recognize, it ignores it. 
        Whether your compiler supports any #pragmas depends on how your compiler was implemented.
*/


/* Example 1: This program demonstrates the #error directive. 
                As soon as the #error directive is encountered, compilation stops.*/
#include <stdio.h>

int main(void) {
    int i;

    i = 10;

// notice no quotation mark "" used
#error This is an error message.
    printf("%d", i); // this line will not be compiled 
    
    return 0;
}




/* Example 2: The next program demonstrates the #undef directive. 
                As the program states, only the first printf() statement is compiled. */
#include <stdio.h>

#define DOG

int main(void) {
#ifdef DOG
    printf("DOG is defined . \n");
#endif

#undef DOG

#ifdef DOG
    printf("This line won't compile. \n");
#endif

    return 0;
}




/* Example 3: The following program demonstrates the #line directive. 
                Since virtually all implementations of #error display the line number and name of the file, 
                it is used here to verify that #line did, in fact, perform its function correctly. 
                (In the next section, you will see how a C program can directly access the line number and file name). */
#include <stdio.h>

int main(void) {
    int i;

// reset line number to 1000 and file name to myprog.c
#line 1000 "myprog.c"
#error Check the line number and file name.
    return 0;
}


/* Example 4: Although the ANSI C standard does not specify any #pragma directives, 
                on your own check your compiler's user manual and learn about any supported by your system. */

