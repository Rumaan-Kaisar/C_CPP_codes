/* 
    ----------    Type conversion in "Expression"    ----------
        Type conversion in "Expression" :

    
            char ch;
            int i;
            float f;
            double outcome;

            ch = '0';
            i = 10;
            f = 10.2;
            outcome = ch * (i / f);     // i is elevated to float and ch is elevated to float
    


    Integral promotion : 
        One portion of C's conversion rules is called integral promotion. 
        Integral promotion is only in effect during the evaluation of an expression. 
            Whenever a "char" or a "short int" is used in an expression, its value is automatically elevated to "int" during the evaluation of that expression. 



    Type-conversion algorithm : 
        After the automatic integral promotions have been applied, the C compiler will convert all operands "up" to the type of the largest operand. 
        This is called type promotion and is done on an operation-by-operation basis, as described in the following type-conversion algorithm.

        ----------    conversion rules that dictate how type differences are resolved.     ----------

            IF an operand is a "long double" → THEN the second is converted to "long double"
            ELSE IF an operand is a "double" → THEN the second is converted to "double"
            ELSE IF an operand is a "float" → THEN the second is converted to "float"
            ELSE IF an operand is an "unsigned long" → THEN the second is converted to "unsigned long"
            ELSE IF an operand is "long" → THEN the second is converted to "long"
            ELSE IF an operand is "unsigned" → THEN the second is converted to "unsigned"

        There is one additional special case: 
            If one operand is "long" and the other is "unsigned int", and if the value of the "unsigned int" cannot be represented by a "long", 
            both operands are converted to "unsigned long". 



    Once these conversion rules have been applied, each pair of operands will be of the same type and
    the result of each operation will be the same as the type of both operands. For example :

        For 
            int i; 
            float f;  

            i is elevated to a "float" during the evaluation of the "i*f".

    Even though the final outcome of an expression will be of the largest type, the type conversion rules are applied on an operation-by-operation basis. 
        For example., in  100.0/(10/3) the division of '10/3' produces an "integer" result, since both are integers. 
        Then this value is elevated to 3.0 to divide 100.0. 
*/



/* Example 1: In this program, i is elevated to a float during the evaluation of
                the expression i+f. Thus, the program prints 33.25. */
#include<stdio.h>

int main(void){
    int i;
    float f;

    i=10;
    f=23.25;

    printf("%f ", i+f);

    return 0;
}



/* Example 2: This program illustrates how short ints are automatically
                promoted to ints. The printf( ) statement works correctly even
                though the %d modifier is used because i is automatically
                elevated to int when printf( ) is called. */
#include<stdio.h>

int main(void){
    short int i;

    i= -10;
    printf("%d ", i);

    return 0;
}



/* Example 3: Even though the final outcome of an expression will be of the
                largest type, the type conversion rules are applied on an
                operation-by-operation basis. For example., in folowing expression
                100.0/(10/3) */
The division (10/3) produces an integer result, since both are
integers. Then this value is elevated to 3.0 to divide 100.0.



/* Examople 4: Given these variables,
                char ch;
                short i;
                unsigned long ul;
                float f;

                what is the overall type of this expression:
                f/ch - (i*ul)
*/
i elevated to unsigned long, ch elevated to float, lastly result (i*ul) is elevated to float
Hence entire expression is float.



/* Examople 5: What is the type of the sub-expression (i*ul), above */
Subexpression is unsigned long

