

// ===============    DEBUGED    ===============

/* Example 1: Write a program that contains two structure variables defined as:

                    struct s_type {
                        int i;
                        char ch;
                        double d;
                    } var1, var2;

                Have the program give each member of both structures initial values,
                but make sure that the values differ between the two structures.

                Using a function called struct_swap(), have the program swap the contents of var1 and var2.
*/

#include <stdio.h>

struct s_type {
    int i;
    char ch;
    double d;
} var1, var2;

void struct_swap(struct s_type *i, struct s_type *j);

int main(void) {
    var1.i = 100;
    var2.i = 99;

    var1.ch = 'a';
    var2.ch = 'b';

    var1.d = 1.0;
    var2.d = 2.0;

    printf("var1: %d %c %f \n", var1.i, var1.ch, var1.d);
    printf("var2: %d %c %f \n", var2.i, var2.ch, var2.d);

    struct_swap(&var1, &var2);

    printf("After swap: \n");
    printf("var1: %d %c %f \n", var1.i, var1.ch, var1.d);
    printf("var2: %d %c %f \n", var2.i, var2.ch, var2.d);

    return 0;
}


void struct_swap(struct s_type *i, struct s_type *j){
    struct s_type temp;
    temp = *i;
    *i = *j;
    *j = temp;
}







/* Example 2: As you know from previous chapters, fgetc() returns an 'INTEGER VALUE',
                even though it only reads a character from a file.

                Write a program that copies one file to another.
                Assign the return value of fgetc() to a "UNION" that contains an integer and character member.

                Use the 'integer element' to check for EOF.
                Write the character element to the destination file.
                Have the user specify both the source and destination tile names on the command line (CLI).
*/

// Copy a file.
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    FILE *from, *to;

    union u_type {
        int i;
        char ch;
    } uvar;


    // see if correct number of command line arguments
    if(argc!=3) {
        printf("Usage: copy <source> <Destination>\n");
        exit(1);
    }

    // open source file
    if((from = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination flle
    if((to = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open destination file.\n");
        exit(1);
    }

    // copy the file
    for( ; ; ) {
        uvar.i = fgetc(from);
        if(uvar.i==EOF) break;
        fputc(uvar.ch, to);
    }


    fclose(from);
    fclose(to);

    return 0;
}
// save the source code as copy.c
// CLI: > copy file1 file2




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





