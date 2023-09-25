
/* 
    --------------    OPERATORs Advanced - 2 : comma    --------------

    The Comma Operator : 
        Comma Operator tells the compiler to "do this and this and this". 
            i.e. the comma is used to STRING TOGETHER several OPERATIONS.

        The most common use of the comma is in the for loop. 
            In the following loop, the comma is used in the 'initialization portion' to initialize 'two loop-control variables', 
            and in the 'increment portio'n to increment i and j.

                    for(i=0, j=0 ; i+j<count ; i++, j++) { }


    value of a comma-separated list:
        The value of a comma-separated list of expressions is the rightmost expression. 
            E.G. the following statement assigns 100 to value:
    
                    value = (count, 99, 33, 100);

        The parentheses are necessary because the 'comma operator' is LOWER in precedence than the assignment operator.
*/




/* Example 1: This program displays the numbers 0 through 49. 
                It uses the comma operator to maintain two loop-control variables. */
#include <stdio.h>

int main(void) {
    int i, j;

    // count to 49
    for(i=0, j=100; i<j; i++, j--) printf("%d %d\n", i, j);

    return 0;
}




/* Example 2: In many places in C, it is actually syntactically correct 
                to use the COMMA in place of the SEMICOLON. */

#include <stdio.h>

int main(void) {
    char ch;

    ch = getchar(), // notice the comma here
    putchar(ch+1);

    return 0;
}

/* 
    Because the comma tells the compiler to "do this and this" 
        the program runs the same with the comma after getchar() as it would had a semicolon been used. 

    Using a comma in this way is considered extremely bad form, however. 
        It is possible that an unwanted side effect could occur. 

    (This use of the comma operator does make interesting coffee-break conversation,
        however! Many C programmers are not aware of this interesting twist in the C syntax.)
*/




/* Example 3 : Write a program that uses the comma operator to maintain three for loop-control variables. 
                        Have one variable run from 0 to 99, 
                        the second run from -50 to 49, and 
                        the third set to the sum of the first two, both initially and each time the loop iterates. 

                Have the loop stop when the first variable reaches 100.
                Have the program display the value of the third variable each time the loop repeats. */

#include <stdio.h>

int main(void) {
    int i, j, k;

    for(i=0, j=-50, k=i+j; i<100; i++, j++, k=i+j) printf("k = %d\n", k);

    return 0;
}




/* Example 4: What is the value of i after the following statement executes
                i=(1,2,3);
                it will be 3. 
*/


