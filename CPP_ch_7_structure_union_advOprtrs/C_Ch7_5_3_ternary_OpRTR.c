
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



/* Example 2: This program is a computerized coin toss.
                It waits for you to press a key and then prints either Heads or Tails. */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
    int i;

    while(!kbhit()) rand();
    // because rand() gives 41, 18467, 6334 for 1st, 2nd, 3rd calls
    // and this series is fixed
    // hence rand() is called repeatedly inside this WHILE-LOOP untill a key is pressed
        // so that each time we get a different random number

    i = rand()%2 ? 1 : 0;   // here rand() gives the next random-number after the last call inside the While-loop

    if(i) printf("Heads");
    else printf ("Tails");

    getche();
    return 0;
}



// The coin-toss program can be written in a more efficient way. There is no technical reason that the ? operator need assign its value to any variable. 
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main(void){
    int i;

    while(!kbhit()) rand(); // rand() is called repeatedly untill a key is pressed

    // rand() gives the next random-number after the last call inside the While-loop
    rand()%2 ? printf("Heads") : printf("Tails"); 

    getche();
    return 0;
}
// Remember, since a call to a function is a valid C expression, it is perfectly valid to call printf( ) in the? statement




/* Example 3: One particularly good use for the '?' operator is to provide a means of preventing a division-by-zero error.
                Write a program that inputs two integers from the user and
                displays the result of dividing the first by the second. Use? to avoid division by zero. */
#include <stdio.h>
int main(void) {
    int i, j, answer;

    printf("Enter two integers: ");
    scanf("%d %d", &i, &j);

    answer = j ? i/j : 0;   // avoid MathErr
    printf("%d", answer);

    return 0;
}




/* Example 4: Convert the following statement into its equivalent '?' statement. 

                if(a>b) count = 100;
                else count = 0;
*/
count = (a>b) ? 100 : 0;




/* Example 5: Rewrite this statement using the ? operator. 
                    if(!done) count = 100;
                    else count = 0;
*/

count = done ? 0 : 100;

// value = condition ? true : false;




// NOOTE: C++ program to demonstrate use of kbhit()
#include <stdio.h>
#include <conio.h>
 
int main() {
    while(!kbhit()) printf("Press a key\n");
 
    return 0;
}

// "Press a key" will keep printing on the  console until the user presses a key on the keyboard.


