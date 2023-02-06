/* 
    autometic type-conversion:
        bool -> char -> short int -> int -> 
        unsigned int -> long -> unsigned -> 
        long long -> float -> double -> long double

    Explicit Type conversion: When we ned to convert higertype to lower type, such as "float" to "int"
        (lower_type) expressiion
 */


#include <stdio.h>
int main(void) {
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

    //  parentheses and spaces can add clarity
    float result = (f * num) + (88 / g) - (19 % num);
    // int result = (f * num) + (88 / g) - (19 % num); /* Datatype error: type conversion needed */
    int result_2 = (int)((f * num) + (88 / g) - (19 % num));    /* Explicit Type conversion */

    
    printf("%f\n", result);
    printf("%d", result_2);

    return 0;
    
}