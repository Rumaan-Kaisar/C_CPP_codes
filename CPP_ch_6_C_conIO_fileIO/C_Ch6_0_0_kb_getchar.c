
/*     Notes : 
    getchar():
    C function called getchar(),  returns a single character typed on the keyboard. 
        When called, the function waits for a key to be pressed. 
        Then getchar() echoes the keystroke to the screen and returns the value of the key to the caller. 

    In many C compilers, getchar() buffers input
    it will read and return only one character, until you enter a carriage return.
    it' will return the first character, any other characters that you entered, including the carriage return, will still be in the input buffer.

    getche():
    getche() is not defined by the ANSI C standard, it can be used like getchar(), except that it will return its value immediately after a key is pressed;
    it does not line-buffer input. for most compilers, this function requires a header file called <conio.h>.

    characters returned by either getchar() or getche() will be represented by their ASCII codes
    ASCII character codes are an ordered sequence; each letter's code is one greater than the previous letter,
    This means that 'a' is less than 'b', '2' is less than '3', and so on. 
    You may compare characters just like you compare numbers. Example:
 */

// Example 1: Reading a char from KB, and printing to console.
#include <stdio.h>
int main(void){ 
    char ch;
    ch = getchar(); // read a char :: Similar to scanf()

    // printing the char
    printf(" you typed: %c", ch);

    return 0;
}

// Char to- ASCII code
/* Example 2: Reading a char from KB, and printing its ASCII code to console.
                This program reads a character and displays its ASCII code. 
                You can use a character as if it were a "little integer." */
#include <stdio.h>
int main(void){ 
    char ch;
    int i;

    printf ("Enter a character: ");
    ch = getchar(); // read a char :: Similar to scanf
    if(ch < 'f') printf("character is less than f");
    printf("\nits ASCII code is %d", ch);
    
    // printing the char
    printf(" you typed: %c", ch);
    printf("\nits ASCII code is %d", ch);

    printf("\nNow Enter that ASCII code");
    scanf("%d", &i)
    printf("\nits ASCII code eqal char is %c", i);
    
    return 0;
}



/* Example 3: Find smallest letter of entered characters */
#include<stdio.h>
// #include<conio.h>
int main(void){
    int i;
    char ch, smallest;

    printf("Enter 10 letters : \n");

    smallest='z'; /*make largest to begin with*/

    for(i=1; i<11; i++){
        ch=getchar();
        // ch=getche();
        if(ch < smallest) smallest=ch;
    }
    printf("\nThe smallest character is : %d", smallest); 
    return 0;
}



/* Example 4: this program allows the user to add, subtract, multiply, or divide two numbers */
#include <stdio.h>
int main(void) {
    int a, b;
    char ch;

    printf("Do you want to:\n");
    printf("Add, Subtract, Multiply, or Divide?\n");

    printf ( "\nEnter first letter: ");
    ch = getchar();

    printf("\nEnter the first number :\n "); 
    scanf("%d", &a);
    printf("Enter the second number :\n "); 
    scanf("%d", &b);

    if(ch=='A') printf("%d", a+b);
    if(ch=='S') printf("%d", a-b);
    if(ch=='M') printf("%d", a*b);
    if(ch=='D' && b!=0) printf("%d", a/b);

    return 0;
}





/* Example 5: Followiing displays the ASCII codes for the characters
                A through Z and a through z. */

#include <stdio.h>
int main(void)
{   char t, s;
printf("\nCapital Letters");
    for(t='A'; t<='Z'; t++ ){
        printf("\n ASCII code for %c is %d",t,t);
    }

printf("\n\nSmall Letters");
        for(s='a'; s<='z'; s++ ){
        printf("\n ASCII code for %c is %d",s,s);
    }
    return 0;
}

