
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

minimum field width and precision specefier :
    %[-sign][minimum-field-width][.][precision] format-specifier

    printf("%10d %10d %10d\n", rand() , rand(), rand());
    printf("%15.2f\n", rand());
    %15.2f  tells printf() to output a double value using a field width of 15, with 2 digits after the decimal point.
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

    /* Mod: % and division: / */
    printf ("%d", 5/2) ;
    printf("%d" , 5%2) ;
    printf("%d" , 4/2) ;
    printf("%d" , 4%2) ;

    
     //  parentheses and spaces can add clarity
    float result = (f * num) + (88 / g) - (19 % num);
    // int result = (f * num) + (88 / g) - (19 % num); /* Datatype error: type conversion needed */
    printf("%f", result);

    // Note: Mixing with float & int type data cause severe problem

    return 0;
    
}

// Write a program that inputs an integer from the kcvboard and displays its square.
#include <stdio.h>
int main(void){
    int i;
    printf("Enter a number: ");
    scanf("%d", &i);
    printf("Square is %d", i*i);
    return 0;
}





