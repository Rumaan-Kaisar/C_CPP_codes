
/* --------    mastery    -------- */


/* Example 1: What is the difference between using quotes and angle brackets with the #include directive?

                When you specif'y the file name within angle brackets <>, 
                    the compiler searches for the file in an implementation-defined manner. 

                When you enclose the file name within double quotes "",
                    the compiler first tries some other implementation-defined manner to find the file. 
                    If that fails, it restarts the search as if you had enclosed the file name wIthin angle brackets.
*/




/* Example 2: Using an #ifdef, show how to conditionally compile this
                fragment of code based upon whether DEBUG is defined or not. 

                        if(!(j%2)) {
                            printf("j = %d\n", j);
                            j = 0;
                        }
*/
#if DEBUG
if(!(j%2)) {
    printf("j = %d\n", j);
    j = 0;
}
#endif




/* Example 3: Using the fragment from previous Exercise, show how you can
                conditionallv compile the code when DEBUG is defined as 1.
                (Hint: Use #if).
*/

#define DEBUG 1

#if DEBUG == 1
if(!(j%2)) {
    printf("j = %d\n", j);
    j = 0;
}
#endif




/* Example 4: How do you undefine a macro? */
// To undefine a macro name use #undef




/* Example 5: What is __FILE__ and what does it represent? 
                __FILE__ is a 'predefined macro' that contains the name of the
                'source file' currently being compiled.
*/




/* Example 6: What do the # and ## preprocessor operators do? 

                # operator makes the argument it precedes into a "QUOTED STRING". 
                ## operator CONCATENATES two arguments
*/




/* Example 7: Write a program that sorts the string "this is a test of qsort".
                Display the sorted output. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comp(const void *i, const void *j);

int main(void) {
    char str[] = "this is a test of qsort";
    qsort(str, strlen(str), 1, comp);
    printf (str);

    return 0;
}

int comp(const void *i , const void *j) {
    return *(char*)i - *(char*)j;
}

// output: aefhiiooqrsssstttt




/* Example 8: Write a program that 'dynamically allocates' memory for one DOUBLE.
                Have the program assign that location the value 99.01,
                display the value, and then free the memory. */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double *p;

    p = malloc(sizeof(double));
    if(!p) {
        printf ("Allocation Error");
        exit(1);
    }

    *p = 99.01;
    printf("%f", *p);
    free(p);

    return 0;
}







// -------  rev  ----------
/* --------    cumul    -------- */

This section checks how well you have integrated the material in
this ch<lptcr with that from "<lrlier ch<lpters.

Example 1: Section 10.1, Example 3, presents .1 computerized card-catalog
program tllat liSt'S an array \)f structures to hold infornlation on
books. Change this program so that only an array of structure

pointers is created, and use dynamically allocated memory to
actually hold the information for each book as it is entered. This
way, less memory is used when information on only a few
books is stored.



Example 2: Show the macro eqUivalent of this function;
char code_it(char c)
(
return -Ci
)
Demonstrate that your macro version works in a program.
,



Example 3: On your own, look over the programs that you have written in
the course of working through this book. Try to find places
where you can;
.. Use conditional compilation.
• Replace a short function with a f~tion.like macro.
.. Replace statically allocated arrays with dynamic arrays.
... Use function pointers.



Example 4: On your own, study the user's manual or online documentation
for your C compiler, paying special attention to the description
of its standard library functions. The C standard library contains
several hundred library functions that can make your
programming tasks easier. Also, Appendix A in this book
discusses some of the most common library functions.



Example 5: Now that you have finished this book, go back and skim through
each chapter, thinking about how each aspect of C relates to the
rest of it. As you will see, C is a highly integrated language, in
which one feature complements another. The connection
between pointers ahd arrays, for example, is pure elegance.



Example 6: C is a language best learned by doing! Continue to write
programs in C and to study other programmers' programs. You
will be surprised at how quickly C will become second nature!



7. Finally, you now have the necessary foundation in C to a1\ow
you to move on to C++;C'sobject-orientedextension. If C++ .
programming is in your future, proceed to Teach Yoursel{C++,
(Berkeley, CA, Osborne/McGraw-Hill). It picks up where this
book leaves off.
