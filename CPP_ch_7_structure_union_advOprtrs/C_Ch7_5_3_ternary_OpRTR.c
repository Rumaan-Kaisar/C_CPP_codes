
/* 
    --------------    OPERATORs Advanced - 1 : ternary (?)    --------------
    The ternary operator  "?" : 
        A ternary operator requires 'three operands'. 
        C contains one ternary operator: the ? .   
        
        The ? operator is used to REPLACE statements such as :

                        if(condition) var = exp1;
                        else  var = exp2;

        The general form of the ?  operator is

                        var = condition ? exp1 : exp2 ;
    
    Here, 'condition'  is an EXPRESSION that evaluates to TRUE or FALSE. 
        If it is TRUE, 'var' is assigned the value of 'exp1' . 
        If it is FALSE, 'var' is assigned the value of 'exp2'.


    The reason for the '?' operator:
        Compiler can produce more efficient code (instead of the equivalent if/else statement.)
*/



/* Example 1: The following program inputs a number and then 
                converts the number into 1 if the number is positive 
                and -1 if it is negative. */
#include <stdio.h>

int main(void) {
    int i;

    printf("Enter a number: ");  
    scanf("%d", &i) ;

    i = (i>=0) ? 1 : -1;
    printf("Outcome: %d ", i);
    
    return 0;
}



2.(The next program is a computerized coin toss. It waits for you to
press a key and then prints either Heads or Tails.
#include <stdio.h>
#include <stdlib.h>
tiinclude <conio.h>
int main(void)
int i;
while(!kbhit(» rand();
i = rand() %2 ? 1: 0;
it (i) printf{"Heads");
else printf ("Tails");
return 0;
The coin-toss program can be written in a more efficient
way. There is no technical reason that the? operator need
assign its value to any variable. Therefore, the coin toss program
can be written as:
#include <stdio.h>
#include <stdlib.h>
#include'<conio.h>
int main(void)
(
while(!kbhit(» rand();
rand()%2 ? printf(-Heads")
return 0;
)
printf(-Tails") ;
Remember, since a call to a function is a valid C expression, it is
perfectly valid to call printf( ) in the? statement)


1. One particularly good use for the? operator is to provide a
means of preventing a division-by-zero error. Write a program
that inputs two integers from the user and displays the result of
dividing the first by the second. Use? to avoid division by zero.
2. Convert the following statement into its equivalent? statement.
if(a>b) count = laO;
else count = 0;

