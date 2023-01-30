
// If you want to specify a character value, the format speciffer is %c.
// To specify a floating-point value, use %f. The %f works fpr both float and double

/* 
    Input from Keyboard: call scanf() using the general form
    scanf("%d", &int-var-name); // Integer input

        #   The first argument to scanf( ) is a "string" that determines how the second argument will be treated.
        #   In this case, the "%d" specifies that the second argument will be receivinh an integer
        #   & allows a function to place a value into one of its arguments. Related to pointer.

 */


// Input specifier for float and double
/* 
Float:      scanf('%f', &float-var-name);
Double:     scanf('%lf', &double-var-name); 
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

    printf("Integer number: %d", num);
    printf("Floating point number: %f", f);
    printf("Double number: %f", g);

    // Note: Mixing with float & int type data cause severe problem

    return 0;
    
}
