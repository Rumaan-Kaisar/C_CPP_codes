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


// Following is wrong: void functiions doesn't return values
void func(void){
    int i;
    printf("Enter a number: ");
    scanf ("%d",. &i);
    return i;
}


/*  Notice auto type conversion. 
    Not wrong though, however misleading and code readibility harmed 
*/
#include <stdio.h>
int f1(void) ;

int main(void) {
    double answer;
    answer = f1();  /*  using double data-type to store int type */
    printf("%f", answer);
    return 0;
}

int f1(void){
    return 100;
}



/* Practicce Square the number */
#include <stdio.h>

int get_sqr(void);

int main(void){
    int sqr;
    sqr = get_sqr();
    printf("Square: %d " , sqr);
    return 0;
}

int get_sqr(void){
    int num;
    printf("Enter a number: ");
    scanf ("%d", &num);
    return num*num; /* square the number */
}


/* 
use return without specitying a value. 
This allows a function to return before its closing curly brace is reached 
*/
#include <stdio.h>
void func1(void);

int main(void) {
    func1();
    return 0;
}

void func1(void){
    printf("This is printed. ");
    return; /* return with no value */
    printf("This is never printed.");
}



/* Write a program that uses a function called convert(), which
prompts she user for an amount in dollars and returns this value
converted into pounds. (Use an exchange rate of $2.00 per
pound.) Display the conversion. */

#include <stdio.h>

int convert(void);
int main(void){
    printf("%d", convert());
    return 0;
}

int convert(void){
    int dollar;
    printf("Enter number of dollars: ");
    scanf("%d", &dollar);
    return dollar/2;
}
