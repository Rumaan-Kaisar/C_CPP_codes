

// ===============    DEBUGED    ===============




/* Example 4: In C, as you know, you cannot pass an ARRAY to a function as a PARAMETER.
                (Only a pointer to an array can be passed.)

                However, there is one way around this restriction.
                    If you enclose the array within a structure,
                    the array is passed using the standard "call-by-value" convention.

                Write a program that demonstrates this by passing a string inside a structure to a function,
                    ALTERING its contents inside the function and
                    demonstrating that the 'original string' is NOT ALTERED after the function returns.
*/


#include <string.h>
#include <stdio.h>

struct s_type {
    char str[80];
} var;

void f(struct s_type arr);

int main(void) {
    strcpy(var.str, "this is original string");
    f(var); // passing array inside a structure
    printf("%s", var.str);  // original array is not changed

    return 0;
}


void f(struct s_type arr){
    strcpy(arr.str, "new string");
    printf("%s\n", arr.str);
}





