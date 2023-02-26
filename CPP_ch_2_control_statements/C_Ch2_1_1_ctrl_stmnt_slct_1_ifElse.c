/* There are three selection statements in C : if, else-if and switch. */

/* 
Note on TRUE/FALSE:
    in C, 'true' is any 'nonzero' value-and 'false' is 'zero'. 
    Therefore, following is perfectly valid:

        if(count+1) printf("Not Zero");
 */


/* 
General form: IF
    if(expression) statement;
    or
    if(expression) {
        statement block
        }
 */


// --------------------------------    IF  ---------------------------------
// Example 1: General form. Shows a number is Negative or Positive.
 #include <stdio.h>
int main(void){
    int num;
    printf("Enter an integer: ");
    scanf("%d", &num);
    if(num < 0) printf("Number is negative." ) ;
    if(num > -1) printf("Number is non-negative.");

    if(10 > 9) printf("true");
    if(5 > 9) printf("this will not print");
    return 0;
}


// Example 2: It displays two numbers and asks the user what the answer is.
#include <stdio.h>
int main(void){
    int answer;
    printf("What is 10 + 14? ");
    scanf("%d", &answer);
    if(answer == 10+14) printf("Right!");
    return 0;
}


// Example 3: This program converts either 'feet to meters' or 'meters to feet', depending upon what the user requests.
#include <stdio.h>

int main(void){

    float num;
    int choice;

    printf("Enter value: ");
    scanf("%f", &num);
    printf (" 1: Feet to Meter5,\n 2: Meters to Feet. ");
    printf ("Enter your choice: ");
    scanf ("%d", &choice);

    if(choice == 1) printf("%f", num / 3.28);
    if(choice == 2) printf("%f", num * 3.28);

    return 0;
}


// Example 4:  asks the user for an integer and then tells the user if that number is even or odd. 
// Modulo operator = %
#include <stdio.h>
int main(void){
    int i;

    printf("Enter a number: ");
    scanf ("%d", &i);

    if((i%2)==0) printf("Even");
    if((i%2)==1) printf("Odd");

    return 0;
}



/* Using Block  of codes */
// Example 1.1b: Ask for a number and print
#include <stdio.h>
int main(void){
    int num;

    printf("Enter a number: ");
    scanf ("%d", &num);

    if(num > 0) {
    printf("This is ");
    printf("an example of ");
    printf("a code block.");
    }

    return 0;
}



/* Example 1.2b: Write a program that prints 5 different proverbs. The program
                    prompts the user for the number of the proverb to print and
                    then displays it. (Use any proverbs you like.) */
#include <stdio.h>
int main(void){
    int i;
    
    printf("Enter proverb number: ");
    scanf ( "%d", &i);

    if(i==1) printf("A bird in the hand ...");
    if(i==2) printf("A rolling stone ...");
    if(i==3) printf("Once burned, twice shy.");
    if(i==4) printf("Early to bed, early to rise ... ");
    if(i==5) printf("A penny saved is a penny earned.");

    return 0;
}




// --------------------------------    IF-ELSE  ---------------------------------

/* General form of the if-else  is shown here:

        if(expression) statement_1;
        else statement_2; 
    
    Using blocks:

        if(expression) { statement_1;
        Statement_2;
        . . . . . .
        Statement_N;}
        else(expression) { statement_1;
            Statement_2;
            . . . . . .
            Statement_N;} 
    
    */


/* Incorrect indentation: The else is associated with the if(j) statement, 
    However, the indentation is incorrect 

    if(i)
        if(j) printf("i and j are true");
    else printf("i is false");    
*/


//Example 5: here the else is used in place of a second if (Example 1), determines
             // whether a number is negative or non·negative.
#include <stdio.h>
int main(void){
    int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if(num < 0) printf("Number is negative." );
    else printf("Number is non-negative.");

    return 0;
}

/* Example 6: This program prompts the user for two numhers. 
divides the first by the second and dispbys the result 
However. division by zero is undefined, so the program uses an if and an else to prevent error.
 */
#include <stdio.h>
int main(void){
    int num1, num2;

    printf("Enter first number: ");
    scanf("%d", &num1);
    
    printf("Enter second number: ");
    scanf("%d", &num2);

    if(num2 == 0) printf("Cannot divide by zero.");
    else printf("Answer is: %d.", num1 / num2); // "else" takes no condition

    return 0;
}

// Example 7: Write a program that requests two numhers and thell displays either their sum or product.
#include <stdio.h>
int main(void){
    int a, b, op;

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf ("%d", &b);

    printf("Enter 0 to 'ADD', 1 to 'MULTIPLY': ");
    scanf("%d", &op);

    if(op==0) printf("%d", a+b);
    else printf ("%d", a*b);
    return 0;
}

// Example 8: even or odd. Recall 'Example 4'.
#include <stdio.h>
int main (void){
    int i;

    printf("Enter a number: ");
    scanf ("%d", &i);

    if((i%2)==0) printf("Even");
    else printf("Odd");

    return 0;
}


/* Example 9:   Improved version of the feet-to-meters, meters-to-feet conversion program (Example 3). 
                Notice the use of code blocks allows the program to prompt specifically for each unit. */
#include <stdio.h>
int main(void){
    float num;
    int choice;

    printf (" 1: Feet to Meter5,\n 2: Meters to Feet. ");
    printf ("Enter your choice: ");
    scanf ("%d", &choice);

    if(choice == 1) {
        printf("Entetr number of feet: ");
        scanf("%f", &num);
        printf("Meters: %f", num / 3.28);
    }
    else {
        printf("Entetr number of meters: ");
        scanf("%f", &num);
        printf("Feet: %f", num * 3.28);
    }

    return 0;
}


/* Example 10:  Using code blocks, we can improve the addition drill program (Example 2).
                prints the correct answer when the user makes a mistake. */
#include <stdio.h>
int main(void){
    int answer;
    printf("What is 10 + 14? ");
    scanf("%d", &answer);

    if (answer == 10+14) printf ("Right!") ;
    else {
        printf("Sorry you're wrong.\n");
        printf("The answer is 24.");
    }

    return 0;
}


/* Example 11: a program that either adds or subtracts two integers. First,
                prompt the user to choose an operation; then prompt for the two numbers and display the result
                First use of C-ARRAY: function promt_user() returns an array.
                 */

/* 
C programming does not allow to return an entire array as an argument to a function. 
However, you can return a pointer to an array by specifying the array's name without an index.

If you want to return a single-dimension array from a function, 
you would have to declare a function returning a 'pointer' as in the following example −

int * myFunction() {
   .
   .
   .
}
// Returning array by passing an array which is to be returned as a parameter to the function.

    #include <stdio.h>  
    int *getarray(int *a);

    int main(){  
    int *n;  
    int a[5];  
    n=getarray(a);

    printf("\nElements of array are :");  
    for(int i=0;i<5;i++) printf("%d", n[i]);

        return 0;  
    }

    int *getarray(int *a) {  
        printf("Enter the elements in an array : ");  
        for(int i=0;i<5;i++)  scanf("%d", &a[i]);
        return a;  
    }  
 */


#include <stdio.h>

int *promt_user(int *arr); //inputs from user, pointers for array return

int main(void){
    int op;
    int *num;       // pointer for C-array of 2 elements
    int numsArry[2];    // array of 2 elements

    printf("Ertter 0 to add, 1 to subtract: ");
    scanf("%d", &op);

    if(op==0){
        // ADD
        num = promt_user(numsArry);
        printf("Addition: %d", num[0] + num[1]);
    }
    else {
        // subtract
        num = promt_user(numsArry);
        printf("Subtraction: %d", num[0] - num[1]);
    }

    return 0;
}

int *promt_user(int *arr){
    printf("Enter first number: ");
    scanf("%d", &arr[0]);
    printf("Enter second number: ");
    scanf("%d", &arr[1]);

    return arr;
}


/* Using Simple if-else */
#include <stdio.h>

int main(void){
    int a,b, op;

    printf("Ertter 0 to add, 1 to subtract: ");
    scanf("%d", &op);

    if(op==0){
        // ADD
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("Addition: %d", a + b);
    }
    else {
        // SUBTRACT
        printf("Enter first number: ");
        scanf("%d", &a);
        printf("Enter second number: ");
        scanf("%d", &b);
        printf("Subtraction: %d", a - b);
    }

    return 0;
}



