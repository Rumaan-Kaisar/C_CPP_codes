/* 
    Global variables:
        maintain their values throughout the lifetime of the program. 
        accessible by all functions in the program.

    Local variables:
        A local variable is known only to the function in which it is declared. 
        it is created when the function is entered and destroyed when the function returns.
*/


/* Example 1: series() function generate a series of numbers, based upon this formula:
            
            next_number = (previous_number*1468) % 467
    
    Give the number an initial value of 21. 
    Use a global variable to hold the last value between function calls.

    main() demonstrate that the function works by calling it ten times and displaying the result. */

// Note: Being stored in global variable, Values dont get lost during function calls

#include <stdio.h>
int series(void);

int num = 21;

int main(void){
    int i;
    for(i=0; i < 10; i++) printf("%d\n", series());
    return 0;
}

int series(void){ 
    num = (num*1468) % 467;
    return num;
}

