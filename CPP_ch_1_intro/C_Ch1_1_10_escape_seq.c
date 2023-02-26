// C's escape sequences:asm

These characters can not be entered from keyboard
    
    \b	    Backspace
    \f	    From feed
    \n	    Newline
    \r	    Carriage return (related to ENTER key)
    \t	    horizontal tab
    \"	    single quote
    \'	    double quote
    \0	    null
    \\	    backslash
    \v	    vertical tab
    \a	    alert
    \?	    Question  mark
    \N	    Octal constant (N is octal value)
    \xN	    hexdecimal constant (N is hexadecimal value) 

    
    
// Example 0: Newline and tab    
#include <stdio.h>
int main(void){
  printf("\n\tThis is a test.");
  printf("\n\tThis is a test.");
  return 0;
}



/* Example 1: This program sounds the bell: */

#include <stdio.h>

int main(void){
    printf("\a");
    return 0;
}



/* Example 2: You can enter any special character by specifYing it as an octal
                or hexadecimal value following the backslash. 
                Following displays The ASCII character set  */
#include <stdio.h>
int main(void){
    printf("\xA0 \xA1 \xA2 \xA3");
return 0;
}

/* Example 3: The \n newline character does not have to go at the end of the
                string that is being output by printf();  */
#include <stdio.h>
int main(void){
    printf("one\ntwo\nthree\nfour") ;
    return 0;
}



/* Example 3: Write a program that outputs a table of numbers. 
                Each line in the table contains three entries; the number, its square, and its cube. 
                Begin with 1 and end with 10. Also, use a for loop to generate the numbers. */
#include <stdio.h>

int main(void){
    int i;

    for(i=1; i<11; i++)
        printf("%d \t%d \t%d\n", i, i*i, i*i*i);

    return 0;
}



/* Example 4: Write a program that prompts the user for an integer value. 
                Next, using a for loop, make it count down from this value to 0,
                displaying each number on its own line. When it reaches 0; have it sound the bell. */
#include <stdio.h>

int main(void){
    int i, j;

    printf("Enter a number: ");
    scanf("%d", &i);

    for(j=i; j>0; j--) printf("%d\n",j);
    printf("\a");

    return 0;
}
