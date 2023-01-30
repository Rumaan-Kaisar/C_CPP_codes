
/* 
    https://en.wikibooks.org/wiki/C%2B%2B_Programming/Code/Standard_C_Library/Functions/scanf
    C++ Programming/Code/Standard C Library/Functions/scanf

    syntax:
        #include <cstdio>
        int scanf( const char *format, ... );

    The 'scanf()' function reads input from 'stdin', according to the given format, and stores the data in the other arguments. 
    It works a lot like 'printf()'. The format string consists of 'control characters', 'whitespace characters', and 'non-whitespace characters'. 
    The control characters are preceded by a % sign, and are as follows:


            Control Character	    Explanation
            %c	                    a single character
            %d	                    a decimal integer
            %i	                    an integer
            %e, %f, %g	            a floating-point number
            %lf	                    a double
            %o	                    an octal number
            %s	                    a string
            %x	                    a hexadecimal number
            %p	                    a pointer
            %n	                    an integer equal to the number of characters read so far
            %u	                    an unsigned integer
            %[]	                    a set of characters
            %%	                    a percent sign

*/

/*  
    https://www.geeksforgeeks.org/cpp-printf-function/   
    C++ printf() Function
    "printf()" function is originally declared under the "<cstdio>" header file. It prints the "formatted string" to the standard output "stdout".

    Syntax: 
    int printf(const char*word, .......)
*/

#include <cstdio>
int main() {
    int num;
    float f;
    double g;
    
    // Input specifier for Integers
    printf("Enter an integer:");
    scanf("%d", &num);

    // Input specifier for float
    printf("Enter a floating point number: ");
    scanf ("%f", &f);

    // Input specifier for double
    printf("Enter another floating point number: ");
    scanf ("%lf", &g);

    printf("Integer number: %d", num);
    printf("Floating point number: %f", f);
    printf("Double number: %f", g);

    // Note: Mixing with float & int type data cause severe problem

    return 0;
    
}