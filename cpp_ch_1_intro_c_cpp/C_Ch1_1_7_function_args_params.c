/* Parameterized functions :
    Functions that take arguments are called parameterized functions.
    arguments are always separated by commas. 
    You must specify the type and name of each parameter and, for  more than one parameter
    Functions that do not have parameters should use the keyword void in their parameter list.
    Argument refers to the value that is passed to a function. 
 
    The variable that receives the value of the argument inside the function is the 'formal parameter' of the function. 

    If a variable is used as an argument to a function, it has nothing to do with the 'formal parameter' that receives its value. 
    i.e. sum(u,v) do nothing to  void sum(int x, int y). */
 
/* 
    Argument : 
        A function's argument is a value that is passed to the function when the function is called. 

    Parameters : 
        For a function to be able to take arguments, special variables to receive argument values must be declared. 
        These are called the formal parameters of the function. 
    

    General form of declaring functions with multiple arguments

    ret-type func_name(type ver1, type ver2, . . . , type ver31);

    For example, the function listed below prints the sum of the two integer arguments used to call it.

    void sum(int x, int y){	
        printf("%d ", x + y);	
    }

    Each time sum() is called, it will sum the value passed to x with the value passed to y.  
*/

#include<stdio.h>
/*----------------- Function prototype with arguments & parameters------------------- */
void sum(int x, int y);

int main(void) {
    sum(1,20);
    sum(9,6);
    sum(81,9);

    return 0;
}

void sum(int x, int y) {
    printf(" sum = %d ", x+y);
} 


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
    answer = fl();  /*  using double data-type to store int type */
    printf("%f", answer);
    return 0;
}

int fl(void){
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
