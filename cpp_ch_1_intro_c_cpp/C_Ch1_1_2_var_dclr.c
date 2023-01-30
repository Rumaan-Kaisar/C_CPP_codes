/* 
general format:

    type variable_name   
 */

/* 
Variable Types in C

        Type	                                        Keyword

        character data	                                    char
        signed whole numbers	                            int
        floating-point numbers	                            float
        double-precision floating-point numbers	            double
        valueless	                                        void

 */


// Variables of types float and double hold signed floating-point values
// double provides about twice the precision (number of significant digits) as does float.
// double is capable of storing values with absolute magnitudes larger than those stored by variables of type float.

#include<stdio.h>

int main(void)
{
    int num; // declares num to be an integer variable
    char ch;
    float f;
    double d;
    
    // multiple variable declaration
    float x, y, z;

    num=100;    /* Assigning a vlue to a variale */
    ch='x';     /* Charecter inside the single quote */
    f=100.123;
    d=123.009;
    
    printf("the value is %d", num);
    printf("ch is %c", ch);
    printf("f is %f", f);
    printf("d is %f", d);

    return 0;
}
