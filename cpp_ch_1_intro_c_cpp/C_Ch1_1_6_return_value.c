/* For your program to obtain the return value, you must put the function on the right side of an assignment statement. 
For example, this program prints the square root of 10: */

#include <stdio.h>
#include <math.h> 		/*Needed by sqrt() library function*/

int main(void){  
    double answer;
    answer = sqrt(10.0);
    printf("Answer = %f", answer);
    return 0;}






/* ----------- The return Sataement ----------- */
/* 
    Return a value to the calling routine using the return statement : When writing our own functions, 
    we can return a value to the calling routine/function using the return statement. 
    The return statement takes the general form:

        return value;

        The 'value' associated with the 'return' statement need not be a constant. It can be any valid C expression
 */
#include <stdio.h>

int func(void); /* prototype */

int main(void){
    int num;
    num = func();
    printf ("%d", num) ;
    return 0;
}

int func(void){
    return 10; 
}
/* 
    we can create functions that return any type of data, 
        functions that return values of type int are quite common.  

    Functions that are declared as void may not return values.
    If a function does not explicitly specify a return type, it is assumed to return an integer by default.

    When the return statement is encountered, the function returns immediately. No statements after it will be executed. 
        Thus, a return statement causes a function to return before its closing curly brace is reached.

    A return statement can also be used by itself, without a return value. This form of return looks like this:   

        return ;

        It is used mostly by void functions (i.e., functions that have a void return type) to cause the function to return immediately
        can also use this form of return in functions that are supposed to return values. However, doing so makes the returned value undefined.
 */
