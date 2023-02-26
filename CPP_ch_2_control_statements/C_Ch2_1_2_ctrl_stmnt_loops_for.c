/* 
    C's Iteration/Loop statement:
        There are three iteration statements in C : 
                                                    while,  
                                                    do-while,   
                                                    for
 */


/* --------------------    FOR loop    --------------------
    General forms:
    Single Line:

        for(initialization; conditional-test , increment) statement ;
        

        Block:

        for(initialization; conditional-test , increment){ 
            statement_1;
            statement_2;
            . . . . . .
            statement_N;
            }


    // A for loop can run negatively. For example,

        for (num=20; num>0; num=num-1)


    the loop-control variable may be incremented or decremented by more than one. 

        for(i = 0; i<101; i = i+5) printf("%d",i);


    Infinite Loop : 
                for(num=1; num>0; num=num+1) printf(" %d ", num); or,  
                for(num=1; num<=11||num>11; num=num+1) printf(" %d ", num);


 */



// Example 1: this program uses a for loop to print the numbers 1 through 10 on the screen.
#include<stdio.h>
int main(void){  
    int num, i;

    for(num = 1; num < 11; num=num+1) printf(" %d ", num);
    printf(" terminating loop-1\n");

    // A for loop can run negatively. For example,
    for (num=20; num > 0; num=num-1)printf(" %d ", num);
    printf(" terminating loop-2\n");

    // the loop-control variable may be incremented or decremented by more than one. 
    for(i = 0; i<101; i = i+5) printf("%d",i);
    printf(" terminating loop-3\n");

    return 0;
}


/* Example 2: This program only displays "terminating" because num is initialized to 11, 
                causing the conditional test to fail. */

#include<stdio.h>
int main(void){
    int num;

    // this loop will not execute
    for(num=11; num<11; num=num+1) printf(" %d ", num);
    
    printf("\n Terminating");
    return 0;
}
/*INFINITE LOOP : for(num=11; num<=11||num>11; num=num+1) printf(" %d ", num);
  INFINITE LOOP : for(num=1; num>0; num=num+1) printf(" %d ", num); */



/*Example 3: Sum and Product from 1 to 6*/
#include<stdio.h>
int main(void){
    int num, sum, prod;

    sum=0;
    prod=1;

    for(num=1; num<=6; num=num+1){
       sum=sum+num;
       prod=prod*num;
    }
    printf("Sum = %d , Product = %d", sum, prod);

    return 0;
}



// Example 4: It ask tor 1 + 1 then 2 + 2 and so all. This program would be useful to a first grade, who is learning to add.
#include<stdio.h>
int main(void){   
    int ans, i;

    for(i=1; i<11; i++){
        printf("\nWhat is %d + %d = ", i, i);
        scanf("%d", &ans);
        if(ans==(i+i)) printf("\nCorrect");
        else printf("Wrong answer. Answer is %d", (i+i));
    }

    return 0;
}


/*Example 5: Double Loop prime check differently*/
#include<stdio.h>
int main(void) {
    int num, is_prime, i;

    printf("Enter a positive integer number : "); 
    scanf("%d", &num);
    
    // now test for factors 
    printf("\nTest--1");
    is_prime = 1; /*Prime indicator , changes if factors are present*/
    for(i=2; i<=(num/2); i++){
        if((num%i)==0) is_prime = 0;
    }

    if(is_prime==1) printf("Number is prime");
    else printf("Number is not a prime");

    printf("\nTest--2");
    for(i=2; i<=(num/2); i++){
        if((num%i)==0) {
            printf("\nNumber is not a prime"); 
            return 0;   //return 0 to END Program HERE
        }
    }
    printf("\nNumber is prime");
    
    return 0;
}


/*Example 6: Numbers Evenly Divisible by 17*/
#include <stdio.h>
int main(void){
    int i;

    printf("Type-1: Multiple Type \n"); /*Multiplication Type Test*/
    for(i=1; (17*i)<=100; i++) printf(" %d ", (17*i));

    printf("\nType-2: DIVISION Type \n"); /*Division Type Test using modulus*/
    for(i=17; i<101; i++) if((i%17)==0)printf("\n %d ", i);

    return 0;
}


/*Example 7: Print the factors of a given Numbers*/
#include<stdio.h>
int main(void){
    int num, i;
    
    printf("Enter a positive integer number : "); 
    scanf("%d", &num);

    printf("\nFactors of the given number : ");
    for(i=2; i<=(num/2); i++) if((num%i)==0) printf(" %d ", i);
    return 0;
}



/*Example 8: 2-D Array type Output*/
#include<stdio.h>
int main(void)
{
    int i, col, num;
    printf("Enter the terminal number :"); scanf("%d", &num);
    printf("Enter the number of columns:"); scanf("%d", &col);
    for(i=1; i<=num; i++) {printf("  %d  ", i);
    if((i%col)==0) printf("\n");}
    return 0;
}


//---------------------    Increment & Decrement    ---------------------
/* 
    To increment/decrement loop control variable, usually we use:
        increment operator "++" and 
        decrement operator  " - - "

Difference between "i++" and "++i" : position of the operator does affect when the operation is performed.

When the increment/decrement follows the variable, the operation is performed after its value has been obtained
If the variable is preceded by the increment/decrement , the operation is performed first, and then the value of the variable is obtained
j = i++;    current value of i is assigned to j. Then i is incremented.
j = ++i;    current value of i is incremented then assigned to j 

    Using the increment operator, you can change this line ofcode:
        i = i + 1;
    into this:
        i++;

    Similarly,
        count = count - 1;
    can be rewritten as
        count--;

*/

#include<stdio.h>
int main(void){ 
    int i, j;
    
    // this will print i=11 and j=10
    i = 10; 
    j = i++;
    printf("i = %d  and  j = %d ", i,j);
    return 0;
}


#include<stdio.h>
int main(void){ 
    int i, j;
    
    // this will print i=11 and j=11
    i = 10; 
    j = ++i;
    printf("i = %d  and  j = %d ", i,j);
    
    return 0;
}


/* 
// May be following happens due to call-stack of printf()
int i; i=0;printf(" %d  %d  %d  %d", --i, --i, --i, --i); // Gives : -4   -4   -4   -4
int i; i=0;printf(" %d  %d  %d  %d", i--, i--, i--, i--); // Gives : -3   -2   -1   0
int i; i=0;printf(" %d  %d  %d  %d", ++i, ++i, ++i, ++i); // Gives : 4   4   4   4
int i; i=0;printf(" %d  %d  %d  %d", i++, i++, i++, i++); // Gives : 3   2   1   0
 */


/* Example 9: this will print i++ and i-- */
#include<stdio.h>
int main(void){ 
    int i; 
    
    i = 0;
    i++ ;
    printf("i++ = %d  ",i); /*prints 1(=0+1)*/
                
    i-- ;
    printf("i-- = %d  ",i); /*prints 0 (= 1-1) , new value was i=1 after i++ */
    
    return 0;
}


/* Example 10: Replace a = a + 1 and b = b -1 */
#include<stdio.h>
int main(void)
{
    int a,b;

    /*
    a=1; 
    a=a+1;
    b=a; 
    b=b-1;
    */

    a=1; 
    a++;
    b=a; 
    b--;

    printf(" %d %d ",a ,b);

    return 0;
}

/* 
Consider below C++ program and predict its output.

printf("%d %d %d", i, ++i, i++);

The above invokes undefined behaviour by referencing both ‘i’ and ‘i++’ in the argument list. 
It is not defined in which order the arguments are evaluated. (consider printf's call stack) 
*/
