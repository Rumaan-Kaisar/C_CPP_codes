/* 
    C compiler will assign the following types:
            10      int
            10000   int
            123.45  double
            123564  long
            -45099  long
 */

/* Example 1: Write a program that inputs a long, a short, and a double and 
                then writes these values to the screen. */

#include <stdio.h>
int main(void){
    long lg;
    short s;
    double d;

    printf("Enter a long value: ");
    scanf ("%ld", &lg);

    printf("Enter a short value: ");
    scant ("%hd", &s);

    printf("Enter a double value: ");
    scanf("%lf", &d);
    
    printf("%ld\n", lg);
    printf("%hd\n", s);
    printf("%f\n", d);  // notice "%lf" Not Used for output

    return 0;
}