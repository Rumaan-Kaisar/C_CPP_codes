
/* 
    ----------------    #define & #include : advanced    ----------------

    macro name:
        #define is used to define a 'macro name' which will be substituted by the 'character sequence associated with that macro'.



    ------------------    #define, function-like macro    ------------------

    function-like macro
        We can use #define to create function like macros.
            in a function-like macro, 'arguments' can be passed to the macro when it is expanded by the preprocessor. 

        The advantage to using function-like macros instead of functions is that 'in-line code' is generated by the macro, 
            thus 'avoiding' the 'time' it takes to call and return from a function. 

        Only relatively simple operations can be made into 'function-like macros'. 

        Also, because code is duplicated, the resulting program might be longer than it would be if a function were used.

    
    NOTICE we didn't use ';' for any of those following examples for '#define or #include'
*/            




/* Example 1: Function-like macro. Consider this program:
                when SUM(i, j) appears in program it wll replaced by the operation "i+j". 

                    Here the line 

                        sum = SUM(10, 20); 

                    is transformed into 

                        sum = 10+20; 

                    by the preprocessor.

                As you can see, the values 10 and 20 are automatically substituted for the parameters i and j.
*/

#include <stdio.h>

#define SUM(i, j) i+j  // when SUM(i, j) appears anywhere it wll replaced by the operation "i+j" 

int main(void){
    int sum;
    
    sum = SUM(10, 20);
    printf("%d", sum);

    return 0;
}




/* Example 2: In following code a "function-like macro : RANGE" performing several range check as well as controls the Do-While loop.

                    #define RANGE(i, min, max) (i<min) || (i>max) ?  1 : 0
                        // TRUE when i not in range : To continue the loop
                        // FALSE when i in range : To break the loop & print the number
                    . . . . .
                    . . . . .
                    // Forced to find a random number between 1 & 100
                    do {
                        r = rand();	
                    } while(RANGE(r, 1, 100));  
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define RANGE(i, min, max) (i<min) || (i>max) ? 1 : 0

int main(void) {
    int r;

    // print random numbers between 1 and 100 
    do {
        do {
            r = rand();
        } while(RANGE(r, 1, 100));  // if r falls in the range this loop breaks
        printf ("%d ", r);
    } while(!kbhit());  // continue untill keypress

    return 0;
}

// 2 98 63 35 19 64 80 3 86 81 40 37 29 7 19 42 56 
// 65 66 47 73 38 4 96 45 2 68 69 83 18 41 26 66 . . . .


/* 
    -------------    parenthesization    -------------
    The RANGE() macro discussed will need parenthesization as well if it is to work in all possible situations.
        #define RANGE(i, min, max) (((i)<(min)) || ((i)>(max))) ? 1 : 0
    
    another example:
        #define MAX(i, j) ((i) > (j)) ? (i) : (j) 
*/




/* Example 3: Here is a program that uses the function-like macro MAX( ) to compute which argument is larger. 
                Pay close attention to the last printf() statement. */
#include <stdio.h>

#define MAX(i, j) i>j ? i : j

int main(void) {
    printf("%d\n", MAX(1, 2));
    printf("%d\n", MAX(1, -1));

    // this statement does not work correctly
    printf("%d\n", MAX(100 && -1, 0));  // 0

    return 0;
}


// --------------    fully parenthesize all parameters to a function-like macro    --------------
// MAX(100 && -1, 0)
// When the preprocessor expands the final printf() statement, the MAX() macro is transformed into this expression:
100 && -1 > 0 ? 100 && -1 : 0

// precedence rules: Because of C's precedence rules, however, this expression is executed as if parentheses had been added like this:
100 && (-1 > 0) ? 100 && -1 , 0

As you can see, this causes the wrong answer to be computed.
// To fix this problem, the MACRO needs to be rewritten as:
#define MAX(i, j) ((i)>(j)) ? (i) : (j)
// Now the macro works in all possible situations. 

// In general, you will need to "FULLY PARENTHESIZE" all parameters to a 'function-like macro'.
// version 2: 
#include <stdio.h>

#define MAX(i, j) ((i)>(j)) ? (i) : (j)

int main(void) {
    printf("%d\n", MAX(1, 2));
    printf("%d\n", MAX(1, -1));

    // this statement now work correctly
    printf("%d\n", MAX(100 && -1, 0));  // 1

    return 0;
}





/* 
    --------------    #include    --------------

    Usage of #include : 
        The #include directive has these two general forms:
    
                #include <filename>
                
                #include "filename"


    #include <filename> 
        used for 'search standered Header file' comes with compiler

        If you specify the file name between ANGLE BRACKETS, 
            you are instructing the COMPILER to search for the file in some implementation defined manner. 
        
        For most compilers, this means searching a SPECIAL DIRECTORY devoted to the 'standard header files'. 
        This is why the sample programs have been using this form to include the header files required by the STANDARD LIBRARY FUNCTIONS. 


    #include "filename" 
        used for search user-defined HEADER file
    
        If you enclose the file name between QUOTATION MARKS, 
            the compiler searches for the file in another implementation-defined manner. 
        
        If that search 'fails', the search is restarted as if you had specified the file name between "angle brackets". 
    
        For the 'majority of compilers', enclosing the name between 'quotation marks' causes the "CURRENT WORKING DIRECTORY" to be searched first. 
            Typically, you will use 'quotation marks' to include "header" files that "you/user create".


    Note:
        #include "stdio.h" uses quotes in the #include directive. While not as efficient as using the angle brackets, 
        the #include statement will still find and include the STDIO.H header file.

        It is permissible to use 'both forms' of the #include directive in the same program. For example,
            #include <stdio.h>
            #include "stdlib.h"
*/





/* Example 4: The next program uses 'quotes' in the #include directive. 
                While NOT AS EFFICIENT as using the angle brackets, the #include 
                statement will still find and include the STDlO.H header fIle.

                If your compiler does not find STOIO.H.
                recheck the installation instructions that came with your compiler.
*/
#include "stdio.h"

int main(void) {
    printf("This is a test");

    return 0;
}




/* Example 5: It is permissible to use both forms of the #include directive in the same program. For example, */
#include <stdio.h>
#include "stdlib.h"

int main(void) {
    printf("This is a random number: %d", rand());

    return 0;
}




/* Example 6: Correct the RANGE( ) macro by adding parentheses in the proper locations. */
#define RANGE(i, min, max) ((i)<(min)) || ((i)>(max)) ? 1 : 0




/* Example 7: Write a program that uses a parameterized macro to compute
                the ABSOLUTE VALUE of an integer and demonstrate its use in a program. */
#include <stdio.h>

#define ABS(i) (i)<0 ? -(i) : i

int main(void) {
    printf("%d %d", ABS(-1), ABS(2));

    return 0;
}




/* Example 8: What is the difference between using quotes and angle brackets with the #include directive?

                When you specif'y the file name within angle brackets <>, 
                    the compiler searches for the file in an implementation-defined manner. 

                When you enclose the file name within double quotes "",
                    the compiler first tries some other implementation-defined manner to find the file. 
                    If that fails, it restarts the search as if you had enclosed the file name wIthin angle brackets.
*/


