
/* 
    -----------------    predefined MACROS    -----------------

    ANSI C standard has at least FIVE 'predefined macro names'. They are
 
                __LINE __
                __FILE __
                __ DATE __
                __ TIME __
                __ STDC __
 
    __LINE__
        defines an 'integer value' that is equivalent to the LINE NUMBER of the 'source line' currently being compiled.
        
    __FILE__ 
        defines a 'string' that is the NAME OF THE FILE currently being compiled,

    __DATE__
        defines a string that holds the 'current system date', 
        The string has this general form:

                month/day/year

    __TIME__
        defines a string that contains the TIME the 'compilation' of a program BEGAN. 
        The string has this general form: 

                hours:minutes:seconds

    __ STDC__
        defined as the value 1 if the compiler conforms to the ANSI standard.

*/


/* Example 1: This program demonstrates the macros __LINE__, __FILE__, __DATE__, and __TIME__. */

#include <stdio.h>

int main(void) {

}

printf("Compil i ng %5, line: %d, on %5, at ~s·,
__FILE__ • __LINE__ • __DATE__ •
__TIME__};

return 0;

It is important to understand that the values of the macros are
fixed at compile time. For example. if the above program is
called T.C. and it is compiled on March 18. 1997. at 10 A.M..
it will always display this output no matter when the
program 1S run,
Compiling T.C, line: 6. on Mar ~8 1997. at 10:00:00

The main use of these macros is to create a time and date stamp,
which shows when the program was compiled.




/* Example 2: From the previous section, we can use the #line directive to 
                change the number of the current line of source code and the name of the file. 
                When you do this, you are actually changing the values of __LlNE__ and __FILE__. 
            
                This program sets __LlNE__ to 100 and __FILE__ to 'myprog.c' */
#include <st~io_h>
int main/void)
(
#line 100 ~myprog.c~
)
printf(-Compiling %s, line, %d, on %5, at %5",
__FILE__ • __LINE__ . __DATE__ •
___
TIME__I:
return 0;
The program displays the following output, assuming it was
compiled on March 18, 1997, at 10 AM.
Compiling myprog.c. line: 101. on Mar 18 199i at 10:00:00





