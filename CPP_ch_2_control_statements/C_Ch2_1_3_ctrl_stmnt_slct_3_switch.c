/* The switch statement is C's multiple selection statement. 
It is used to select one of several alternative paths in program execution and works as follows :
A value is successively tested against a list of integer or character constants. 
When a match is found, the statement sequence associated with that match is executed.  */

// --------------------    SWITCH   --------------------
/* The general form of the switch statement:

        switch(value) {
            case constant_1:statement sequence or BLOCK; break;
            case constant_2: statement sequence or BLOCK; break;
            case constant_3: statement sequence or BLOCK; break;
                    . . . 
                    . . .
            default : statement sequence or BLOCK; break;
        }


    The 'default' statement sequence is performed if no matches are found. 
    The 'default' is optional. If all matches fail and 'default' is absent, no action takes place.

    When a match is found, the statements associated with that 'case' are executed until break is encountered or, in the case of 'default' or the last 'case', the end of the switch is reached.

    switch will work with only int or char types

    no two 'case' constants in the same switch can have identical values.

    Technically, the break statement is optional. when break encountered within a switch, flow exit from
    the entire switch statement and continue on to the next statement outside the switch.
    break works similar to breaking out of a loop. 

    When a break statement is missing, execution "falls through" into the next 'case' and stops only when a break statement or the end of the switch or 'default' is encountered. 

    Cases share a common statement: The statement sequence associated with a 'case' may be empty, allows two or more cases to share a common statement sequence without duplication of code. 

    switch can only test for equality, whereas the if conditional expression can be of any type.
*/



/* no two cases with the same switch may use the same value. 
Therefore if we use 'A' as a value in one case and 65 in other case, it will give error.
Since the ASCII code for 'A' is 65. 
Hence to C, both 'A' and 65 are the same thing, and no two case constants can be'the same.
*/

// invalid
    switch(x) {
        case 'A' : printf("is an A"); break;
        case 65 : printf("is the number 65"); break;
    }



/* Notice the fall through:
When i=1, a = 2. When i=4, a i = 5. */
switch(i){
case 1: a = 1; // no break, hence fall through
case 2: a = 2; 
        break;
case 3: a = 3;
        break;
case 4:
case 5: a = 5;
}

// Example Fall-Through demo:
#include <stdio.h>

int main(void) {
    int a, i =1;
    
    switch(i){
    case 1: a = 1;
            printf("inside case 1 \n");   // no break, hence fall through
    case 2: a = 2;
            printf("inside case 2 \n");
            break;
    case 3: a = 3;
            break;
    case 4:
    case 5: a = 5;
    }

    return 0;
}


// ----------------------------------------------------------------------------------------


#include<stdio.h>
int main(void){
    int x;

    printf("Enter a number between 1 and 4 :"); 
    scanf("%d", &x);

    switch(x){ 	
        case 1 : {
            printf("One");
            printf("\nInside block");         
                    }
            break;
        case 2 : printf("Two"); break;
        case 3 : printf("three"); break;
        case 4 : printf("four"); break;
        case 5 : printf("five"); /*In absence of 'break' control jumps to Next case (case 6)*/
        case 6 : printf(" fuck !! You inputted 5!"); break;
        default : printf("Not acceptable 5 and more");break;
        }
    
        return 0;
}



// --------------------    Nested switch   --------------------
/* If the case constants of the inner and outer switch contain common values, no conflicts will arise. 
For example, the following code fragment is petfectly acceptable: */

#include<stdio.h>
int main(void){
    int a, b;

    printf("Enter a number between 1 and 4 :"); 
    scanf("%d", &a);

    switch(a) { 
        case 1: 
            b = a;
            switch(b) {  
                    case 0: printf("b is false"); break;
                    case 1: printf("b is true"); break; /*'break' may be absent*/
            }
            break ;
        case 2: {
                printf("Hold on!");
                printf("\nInside block!");         
                        }
                // break;
        default : printf("\nWhat the? you didn't put brak in previous case!!");
                break;
    }
    
    return 0;
}




/* Example 1: The switch statement is often used to process menu commands. 
                For example, the arithmetic program can be recoded as shown here. 
                This version reflects the way professional C code is written. */
#include <stdio.h>
int main(void){
    int a, b;
    char ch;

    printf("Do you want to: \n");
    printf("Add, Subtract, Multiply, or Divide?\n");
    /* force user to enter a valid response */
    do{
        printf("Enter first letter: ");
        ch = getchar();
    } while(ch!='A' && ch!='S' && ch!='M' && ch!='D');
    printf("\n");

    printf("Enter first number: ");
    scanf("%d", &a);
    printf("Enter second number: ");
    scanf("%d", &b);

    switch(ch){
        case 'A': printf("%d", a+b); break;
        case 'S': printf("%d", a-b); break;
        case 'M': printf("%d", a*b); break;
        case 'D': if(b!=0) printf("%d", a/b);
    }

    return 0;
}


/* Example 2: when a break statement is missing, execution "falls through' into the next case and stops only 
                when a break statement or the end of the switch is encountered. */
// don’t use <conio.h> as it is not supported on online judges. So remove it and the getch()
#include <stdio.h>
// #include <conio.h>
int main(void){
    char ch;

    do{
        printf("\nEnter a character. q to quit: ");
        // ch = getche() ;
        ch = getchar() ;

        printf("\n");

        switch(ch){
        case 'a': printf ("Now is " );
        case 'b': printf("the time" );
        case 'c': printf("for all good men");
                break;
        case 'd': printf("The summer ");
        case 'e': printf("soldier ");
        }
    }while(ch != 'q');

    return 0;
}



/* Example 3: The statement sequence associated with a case may be empty.
                This allows two or more cases to share a common statenlent. */

#include <stdio.h>
// #include <conio.h>
int main(void){
    char ch;

    printf("Enter the letter: ");
    ch = getchar() ;

    switch(ch){
        case 'a' :
        case 'e' :
        case 'i' :
        case 'o' :
        case 'u' :
        case 'y' :  printf(" is a vowel\n");
                    break;
        default :   printf(" is a consonant");
    }

    return 0;
}


/* Example 4: a program that counts the numbers of letters, digits,
and common punctuation symhols entered hy the user. Stop
inputting when the user presses '/'. 
Use a switch statement to categorize the characters into punctuation, digits, and letters.
When the program ends, report the number of characters in each category.  */

#include <stdio.h>
// #include <conio.h>
int main(void){
    char ch;
    int digit, punc, letter;

    printf("Enter characters, '/' to stop.\n");
    digit = 0;
    punc = 0;
    letter = 0;

    do{
        ch = getchar() ;
        switch(ch){
            case '1' :
            case '2' :
            case '3' :
            case '4' :
            case '5' :
            case '6' :
            case '7' :
            case '8' :
            case '9' :
            case '0' : digit++; break;
            case '.' :
            case ',' :
            case '?' :
            case '!' :
            case ':' :
            case ';' : punc++; break;
            default : letter++;
        }
    }while(ch!='/') ;
    printf("\nDigits: %d\n", digit);
    printf("Punctuation: %d\n", punc);
    printf("Letters: %d\n", letter);
    
    return 0;
}



/* Example 5: Using a switch statement, write a program that reads characters
                from the keyboard and watches for tabs, newlines, and
                backspaces. When one ia received, diaplay what it is in words.
                For example, wilen the uaer preues the TAB key, print tab. */

#include <stdio.h>
#include <conio.h>
int main(){
    char ch;

    printf("Enter characters (q to quit): \n");
    do {
        ch = getche();
        // ch = getchar();
        switch(ch) {
            case '\t':  printf("tab\n");
                        break;

            case '\b':  printf("backspace\n");
                        break;

            case '\r':  printf("Enter\n");
        }
    } while(ch!='q');

    return 0;
}




/* Example 6: Convert this series of ifs into an equivalent switch. 

        if(ch=='L') load();
        else if(ch=='S') save();
        else if(ch=='E') enter();
        else if(ch=='O') display();
        else if(ch=='Q') quit();
*/

char ch;
switch(ch){
    case 'L': load();
              break;

    case 'S': save();
              break;

    case 'E': enter();
              break;

    case 'D': display();
              break;

    case 'Q': quit();
              break;
}
