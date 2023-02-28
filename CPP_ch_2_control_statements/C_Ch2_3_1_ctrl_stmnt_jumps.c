/* -------------------     jump Statements     -------------------
    C has four types of jump statements. 
1.	goto statement :  the form is   "goto" identifier;
        This statement transfers control flow to the statement labeled with the given identifier. 
        The statement must be within the same function as the goto.
2.	break statement : the form is  "break";
        is used within iteration statements and switch statements 
        to pass control flow to the statement following the current iteration/switch statements.
3.	continue statement :the form is  "continue";
        is used within the sub-statement of iteration statements to transfer control flow 
        to the place just before the end of the sub-statement.
        Basically it skips iterations inside a loop
4.	return statement : the form is  "return expression(opt)";
        This statement returns from the function. If the function return type is void, the function may not return a value; 
        otherwise, the expression represents the value to be returned.
 */


// --------------------------------    break TO EXIT A LOOP    --------------------------------
/* The break statement allows you to exit a loop from any point within its body
the loop is immediately stopped, and program control resumes at the next statement following the loop. 
    You can have as many break statements within a loop as you desire. 
    too many exit points from a loop tend to destructure your code
    try to use normal loop exit.
 */


/* Example 1: For example, this loop prints only the numbers 1 to 10: */
#include <stdio.h>
int main(void){
    int j;
    
    for(j=1; j<100; j++) {
        printf ("%d ", j); 
        if(j==10) break; //exit the loop
    }

    return 0;
}



/* Example 2: The break statement is commonly used in loops in which a
                special condition can cause immediate tennination. Here is an
                example of such a situation. In this case, a keypress can stop the
                execution of the program. */
#include <stdio.h>
// #include <conio.h>
int main(void){
    int i;
    char ch;

    /*display all numbers that are multiples of 6 */
    for(i=1; i < 10000; i++){    
        if(!(i%6)){
            printf("%d , more?(Y/N)", i);
            // ch = getche();
            ch = getchar();
            if(ch=='N') break; /* stop the loop */
            printf("\n");
        }
    }
    return 0;
}



/* Example 3: A break" will cause an exit from only the innermost loop. For
                example, this program prints the numbers 0 to 5 five times: */
#include<stdio.h>
int main(void){
    int i, j;

    for(i=0; i<5; i++) {
        for(j=0; j<100; j++){
            printf ("%d ", j);
            if (j==5) break;
        }
        printf ("\n");
    }

    return 0;
}



/* Example 4: The reason C includes the break statement is to allow your
                programs to be more efficient. For example, examine this fragment: */
#include<stdio.h>
int main(void){
    char ch;

    do { 
        printf("Load, Save, Edit, Quit?\n");
        do {
            printf("Enter your selection:"); 
            ch = getchar();
        } while(ch!='L' && ch!='S' && ch!='E' && ch!='Q');

        if(ch != 'Q') { 
            /*do something */
            printf("Not Quit?\n"); 
            }

        if(ch != 'Q') {
            /*do something else*/
            printf("Not Quit Again? Oh boy ...\n");
            }
        /* etc. */
    } while(ch != 'Q');

    return 0;
}


        /* Better version: in above situation, several additional tests are performed on ch to see if it is equal to 'Q',
        to avoid executing certain sections of code when the Quit option is selected (which makes the program act slow). 
        Most C programmers would write the preceding loop as shown here:

        In following version, ch need only be tested once to see if it contains a 'Q'. 
        This implementation is more efficient because only one if statement is required. */

#include<stdio.h>
int main(void){
    char ch;

    for( ; ; ) { /* infinite for loop */ 
        printf("Load, Save, Edit, Quit?\n"); 
        
        do {
            printf("Enter your selection:"); 
            ch = getchar();
        } while(ch!='L' && ch!='S' && ch!='E' && ch!='Q');

        if (ch == 'Q') break;	 //Quit makes exit the infinite for loop 

        // do something
        printf("Not Quit?\n"); 
        
        // do something else
        {
            printf("Not Quit Again? Oh boy ...\n");
        }

        // etc.
    }
    return 0;
}




/* Example 5: Write a program that prints'a table showing the proper amount of tip to leave. 
            Start the table at $1 and stop at $1OO, using increments of $1. 
            Compute three tip percentages: 10%, 15%, and 20% . 
            After each line, ask the user if he or she wants to continue. If not, use break to stop the loop. */
#include<stdio.h>
// #include<conio.h>
int main(void) {
    float i;
    char ch;

    printf("Compute tip:\n");
    for(i=1.0; i<=100.0; i++){
        printf("%f %f %f %f\n", i, (i + i*0.1), (i + i*0.15), (i + i*0.2));
        printf("More?(Y/N):");
        // ch=getche();
        ch = getchar();
        printf("\n");
        if(ch=='N') break;
    }

    return 0;
}




/* -----------------   continue for skipping any code  -----------------   
The "continue" statement is somewhat the opposite of the "break"
It forces the next iteration of the loop to take place, 
skipping any code in between itself and the test condition of the loop.

Note:
while, do-while: a "continue" will cause control to go directly to the "test condition" and then continue the looping process. 
for: the increment part of the loop is performed, the 'conditional test' is executed, and the loop continues. */


/* Example 6: For example, this program never displays any output: */
#include<stdio.h>
int main(void){ 
    int x;

    for(x=0; x<100; x++){
        continue;
        printf("this never show up"); // this is never executed
    }
    return 0;
}

Each time the continue statement is reached, it causes the loop to repeat, skipping the printf() statement.


/* Example 7: One good use for "continue" is to restart a statement sequence when an error occurs. 
                Following program computes a running total of numbers entered by the user. Before adding a value to the running total, 
                it verifies that the number was correctly entered by having the user enter it a second time.
                If the two numbers don't match, the program uses continue to restart the loop. */
#include <stdio.h>
int main(void){
    int total, i, j;

    total = 0;
    do{
        printf ("Enter next number (0 to stop):");
        scanf("%d", &i);
        printf("Enter number again:");
        scanf ("%d", &j);
    
        if(i != j){
            printf("Mismatch\n") ;
            continue;
        }

        total = total + i;
    }while(i);

    printf("Total is %d\n", total);
    return 0;
}



/* Example 8: Write a program that prints only the odd numbers between 1
                and 100. Use a for loop that looks like this:
                for(i=l; i<101; i++) ... 
                Use a continue statement to avoid printing even numbers.                
                */

#include<stdio.h>
int main(void) {
    int i;

    for(i=1;i<101;i++){
        // Notice how ! is used to catch an even number
        if(!(i%2)) continue; // iteration skips if i%2 = 0, i.e. !(i%2) == true
        printf("%d ",i);
    }
    return 0;
}




/* -----------------   The goto STATEMENT  -----------------
goto is a non-conditional jump statement.
Because C is a replacement for assembly code, the inclusion of goto is necessary 
because it can be used to create very fast routines.

    *   do not use goto because it destructures a program 
        and, if frequently used, can render the program virtually impossible to understand later.

    *   The only good use for goto is to jump out of a deeply nested routine when a catastrophic error occurs.
    *   goto can perform a jump within a function. 
    *   It cannot jump between functions. 
    *   It works with a label. In C, a label is a valid identifier name followed by a colon : . 

    For example, the following goto jumps around the printf() statement

        goto mylabel;
        printf("This will not print");
        mylabel: printf ("This will print. ") ;

    ------------    Labeled Statements    ------------
    A statement can be preceded by a label. Three types of labels exist in C. 

    1)  label : statement ; 
            ...  
        goto label; 
        
    2)  case int/char-const : statement; 

    3)  default : statement;
*/


/* Example 9: This program uses goto to create the equivalent of a for loop
                running from 1 to 10. (This is just an example "goto". In actual */
#include<stdio.h>
int main(void){
    int i;

    // following is equivalent to : for(i=1, i<10, i++), condition checked after increment
    i = 1;
    again:
        printf("%d ",i);
        i++;
        if(i<10) goto again;
    return 0;
}



/* Example 10: Write a program that uses goto to emulate a while loop that counts 1 to 10. 
                condition checked first */
#include <stdio.h>
int main(void){
    int i;

    i = 1;

    jump_label:
        if(i >= 11) goto done_label;
        printf("%d ", i);
        i++;
        goto jump_label;

    done_label: printf("\nDone-");
    return 0;
}

/* Alternative version */
#include <stdio.h>
int main(void){
    int i;

    i = 1;
    jump_label:
        if(i < 11) {
            printf("%d ", i);
            i++;
            goto jump_label;
        }

    printf("\nDone-");
    return 0;
}



/* Example 11: The ASCII codes for the lowercase letters are separated from the uppercase letters
                by a difference of 32. Therefore, to convert a lowercase letter to  an uppercase one, simply subtract 32 from it. 
                Write a program that reads characters from the keyboard and displays lowercase letters as uppercase ones. 
                Stop when ENTERis pressed. */

#include <stdio.h>
// #include <conio.h>
int main(void){
    char ch;

    printf("Enter lowercase letters .");
    printf(" (Press '.' to Quit.)\n");
    do{
        ch = getchar();
        if(ch!='.') printf("%c", ch-32);
    } while(ch!='.'):

    return 0;
}



