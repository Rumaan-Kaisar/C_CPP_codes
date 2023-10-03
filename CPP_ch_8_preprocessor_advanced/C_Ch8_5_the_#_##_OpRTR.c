
--------------    # & ## operators    --------------

The C preprocessor contains two little-used but potentially valuable operators: # and ##. 
	The # operator turns the argument of a function-like macro (recall 8.1) into a quoted string. 
#include <stdio.h>
#define MKSTRING(str) # str
int main(void){ 	int value;
value = 10;
printf("%s is %d", MKSTRING(value), value);
return 0;}
The program displays value is 10. This output occurs because MKSTRING() causes the identifier "value" to be made into a quoted string.

	The ## operator concatenates two identifiers.
It creates the output() macro, which translates into a call to printf(). The value of two variables, which end in 1 or 2, is displayed.
#include<stdio.h>
#define output(i) printf("%d %d\n", i##1, i##2) 						/* two variables, which end in 1 or 2, eg. a1, a2 */
int main (void) {	int count1, count2;
int i1, i2;
count1= 10;	count2 = 20;
i1 = 99;	i2 = -10;
output(count);
output (i) ;
return 0;}
The program displays 10 20 99 -10. In the calls to output(), count and i are concatenated with 1 and 2 to form the variable names count1, count2, i1 and i2 in the printf() statements.

