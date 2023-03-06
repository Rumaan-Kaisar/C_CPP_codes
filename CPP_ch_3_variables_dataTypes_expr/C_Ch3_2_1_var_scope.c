/* 
    Global variables:
        maintain their values throughout the lifetime of the program. 
        accessible by all functions in the program.

    Local variables:
        A local variable is known only to the function in which it is declared. 
        it is created when the function is entered and destroyed when the function returns.
*/



 /* 
    Local variables:
    Local variables exist only while the function in which they are declared is executing.
        a local variable is created upon entry into its function and destroyed upon exit.
        local variables in different functions can have the same name.  

        A variable declared within a block is known only to other code within that block. Thus, j may not be used outside of its block.  

            for(i=0; i<10; i++){   
                if(i==5){   
                    int j;  // Declare j within the if block

                    j = i*10;
                    printf("%d", j);
                } 
            }

    Most C programmers declare all variables used by a function at the start of the function's block.

    Local variables do not maintain their values between functions calls. 
        When a function is called, its local variables are created, and upon its return, they are destroyed. 

    function-parameters are local too: The formal parameters to a function are also local variables.
        parameters can be used like any other local variable within that function.



    Global variables :  
        Global variables are known throughout the entire program and may be used by any piece of code in the program. 
        A local variable and a global variable may have the same name. 
            When local and global variables share the same name, the 'compiler' will always use the 'local' variable.

        you should "always use local variable"s where you can because
            global variables use memory the entire time your program is executing
            using a global where a local variable will do a perfect job makes a function less general
*/

/* Example 1: local variables in different functions can have the same name.  */
#include<stdio.h>

void f1(void), f2(void);

int main(void){
    int count;

    for(count=0; count<= 5; count++){
        printf("\n count in main : %d \n",count); 
        f1();
    }
     f1(); 	
    return 0; 
}

void f1(void){ 
    int count;
 	
    for(count=1; count<11; count++) {
        printf("\n count in f1 : %d \n",count); 
        f2();
    }
}

void f2(void){ 	
    char count;
    
    printf("Alphabets :");
    for(count='a'; count<='z'; count++) printf(" %c",count);
    printf("\n");
}


// keyword "auto" can be used to declare local variables. 
// However, since all local variables are, by default, assumed to be auto, it is virtually never used.




/* Example 2: Within a function, local variables can be declared at the "start of any block". 
            For example, the following program is perfectly valid: */
#include<stdio.h>
int main(void){ 
    int i;

    for(i=0; i<10; i++){   
        if(i==5){   
            int j;  // Declare j within the if block

            j = i*10;
            printf("%d", j);
        } 
    }  
    
    return 0;
}


 
/* Example 3: You must declare all local variables (befor using them) prior to any program statements. For example, the following is incorrect: */
#include <stdio.h>
int main(void) { 	
    printf("This program won't compile.");
    
    i = 10; 
    int i; 	// this should come first

    printf("%d", i); 
    
    return 0;
}





/* Eaxmple 4: Global variables are created by declaring them outside any function. For example, consider this program: 
                Here, both main() and f1() use the global variable max. 
                The main( ) function sets the value of max to 10, and f1() uses this value to control its for loop.
                */
#include <stdio.h>

void f1 (void) ;

int max; /* this is a global variable */

int main (void) {
    max = 10; 	
    
    f1() ; 	
    return 0; 
}

void f1 (void) {
    int i; 
    
    for(i=0; i<max; i++) printf("%d",  i); 
}



/* Example 5: When local and global variables share the same name, the compiler will always use the local variable. 
                the compiler will always use the local variable.*/
#include <stdio.h>

void f1 (void) ;

int max; 	/* this is a global variable */

int main (void) {	
    max=10; 
    
    f1();
    printf("max in main : %d\n", max);
    return 0;
}

void f1 (void) {	
    int max;  	/* this is a local variable */
    
    max=300; 
    
    printf("max in f1 : %d\n", max);
}



/* Eaxmple 6: Local variables are better tahn globl: Here, the function power() is created to compute the value of m raised to the e'th power. 
                Since m and e are global, the function cannot be used to compute the power of other values. 
                It can only operate on those contained within m and e. */

/*Non-general form of a function*/
#include<stdio.h>

int power(void);

int m, e;

int main(void){
    m=2; 
    e=3;
    printf("%d to the power %d is %d^%d = %d", m,e,m,e, power());
    return 0;
}

/*Non-general version of power(): 
    this function can not be used or called for any other values 
    because m,e are global and fixed in main() here power() lost its general purpose */
int power(void) {	
    int temp_1, temp_2;
    			
    temp_1=1;

    //Using e, m which is global and has a fixed value defined in main()
    temp_2=e;   
    for( ; temp_2 > 0; temp_2--) temp_1 = temp_1*m;
    
    return temp_1;
}


/*Better version of above program*/
#include<stdio.h>

int power(int m, int e);

int main(void){   
    int m, e;

    m = 2;
    e = 3;

    printf("\n%d to the power %d is %d^%d = %d", m,e,m,e, power(m,e));
    printf("\n4 to the power 5 is %d", power(4,5));
    printf("\n3 to the power 3 is %d", power(3,3));

    return 0;
}

/*general version of power(): this function is parameterized version, usees local variables */
int power(int m, int e){ 	
    int temp;
    
    temp=1;
    for( ; e > 0; e--) temp=temp*m;
    return temp;
}

// By parameterizing power(), can be used to return the result of any value raised to some power. 
// Here the function is complete within itself-no extra baggage need be carried about when it is used.

/* Using a large number of global variables can lead to program errors because of unknown and unwanted side effects. */



/* Example 7: Rememher. local variables do not maintain their values between functions calls. For example. the following program will not
work correctly: */

#include<stdio.h>

int series(void); 
int main(void){
    int i;

    for(i=0;i<10;i++) printf("%d ",series());

    return 0;
}

// This is incorrect.
int series(void){
    int total;

    total=(total+1423)%1422;

    return total;
}

/* This program attempts to use series() to generate a number series in which each number is based upon the value of the preceding one. 
However, the value total will not be maintained between function calls, and the function fails to carry out its intended task. */



/* Example 8: Write a program that contains a function called soundspeed(), which computes the number of seconds 
                it will take sound to travel a speCified distance. Write the program two ways: 
                first, with soundspeed() as a non-general function and 
                second, with soundspeed() parameterized. 
                (For the speed of sound, use 1129 feet per second). */


// Here is the non-generalized version.
#include<stdio.h>

void soundspeed(void);

double distance;

int main(void){
    printf("Enter distance in feet: ");
    scanf("%lf", &distance);

    soundspeed();

    return 0;
}

void soundspeed(void){
    printf("Travel time: %f", distance / 1129.0);
}



// Here is the parameterized version.
#include<stdio.h>

void soundspeed(double distance);

int main(void){
    double distance;

    printf("Enter distance in feet: ");
    scanf("%lf", &distance); // using %f gives error, since double

    soundspeed(distance);

    return 0;
}

void soundspeed(double distance){
    printf("Travel time: %f", distance / 1129.0);
}




/* Example 9: series() function generate a series of numbers, based upon this formula:
            
            next_number = (previous_number*1468) % 467
    
    Give the number an initial value of 21. 
    Use a global variable to hold the last value between function calls.

    main() demonstrate that the function works by calling it ten times and displaying the result. */

// Note: Being stored in global variable, Values dont get lost during function calls

#include <stdio.h>
int series(void);

int num = 21;

int main(void){
    int i;
    for(i=0; i < 10; i++) printf("%d\n", series());
    return 0;
}

int series(void){ 
    num = (num*1468) % 467;
    return num;
}

