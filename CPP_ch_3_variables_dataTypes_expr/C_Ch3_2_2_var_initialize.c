/* 
----------  Variable initialization  ----------  
A variable may be given an initial value when it is declared.
        type var-name = constant;
The compiler may be able to produce faster code using initialized variable.

For example, 
        int count = 100; 


	You may initialize one or more of them.
        int min=0, count, max=100;

	A local variable can be "initialized by any expression" valid at the time the variable is declared. For example, 
        initializ-e a local variable y using a global variable x, 	
            int y = x; 
        and initialize a local variable z using another local variable y and a function myfunc()  
            int z = myfunc(y);

	You cannot initialize a global variable using another variable.    
        int a=1, b=2, c=a; //is wrong in this case.  

    A local variable can be initialized using any expression valid at the time of the initialization.
        int a=1, b=2, c=a; //is correct in this case


 1.	Global variables are initialized only once, at the start of program execution.
        Global variables that are not explicitly initialized are automatically set to zero.

 2.	Local variables are initialized each time a function is entered.
        Local variables that are not initialized should be assumed to contain unknown values. 
        Although some C compilers automatically initialize un-initialized local variables to 0.
*/



/* Example 1: This program gives i the initial value of -1 and then displays its value */
#include<stdio.h>

int main(void){
    int i= -1;

    printf("i is initialized to %d", i);

    return 0;
}



/* Example 2: When you declare a list of variables, you may initialize one or
                more of them. For example, this fragment initializes min to 0
                and max to 100. It does not initialize count. */

#include<stdio.h>

int main(void){
    int min=0, count, max=100;

    count = min*max;
    printf("min %d, max %d and count %d", min, max, count);

    return 0;
}



/* Example 3: local variables are initialized each time the function is entered. 
                For this reason, this program prints 10 three times. */
#include<stdio.h>

void f(void);
int main(void){
    f();
    f();
    f();

    return 0;
}

void f(void){
    int i=10;
    printf("%d",i);
}



/* Example 4: A local variable can be initialized by any expression valid
                at the time the variable is declared. For example, consider this program: */

#include<stdio.h>

int x= 10;  //initialize global variable

int myfunc(int i);

int main(void){
    int y= x;   //initialize a local variable using a global variable

    int z= myfunc(y);   //initialize a local variable using another local variable and a function call 

    printf("y = %d, \t z = %d", y, z);
    
    return 0;
}

int myfunc(int i){
    return i/2;
}



/* Example 5: Write a program that gives an integer variable called i an initial 
                value of 100 and then uses i to control a for loop that displays the numbers 100 down to 1. */
#include<stdio.h>

int main(void){
    int i= 100;

    for ( ; i>0; i--) printf("%d ", i);
    return 0;
}

// initialize inside FOR-loop
#include<stdio.h>
int main(void){
    for ( int i= 100; i>0; i--) printf("%d ", i);
    return 0;
}


// Wrong for Global var diclaration, ok for Local var
int a=1, b=2, c=a;
