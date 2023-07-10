7.8 OPERATORs Advanced - 1
7.8.1 The ternary operator  " ? : "  A ternary operator requires three operands. C contains one ternary operator: the ? .   The ? operator is used to replace statements such as :
if(condition) var = exp1;
else  var = exp2;
The general form of the ?  operator is
var = condition ? exp1 : exp2 ;
Here, condition  is an expression that evaluates to true or false. If it is true, var is assigned the value of exp1 . If it is false , ,var is assigned the value of exp2.

The following program inputs a number and then converts the number into 1 if the number is positive and -1 if it is negative.
#include <stdio.h>
int main(void) { 	int i;
printf("Enter a number: ");  scanf("%d", &i) ;
i=i>=0?1:-1;
printf("Outcome: %d ", , i);
   return 0;}
Note: the reason for the? operator is that a C compiler can produce more efficient code using it instead of the equivalent if/else statement.

