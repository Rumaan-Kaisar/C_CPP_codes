/*     
    ----------------    NON-STANDARD CONSOLE FUNCTIONS    ----------------
            getche()
            getch()
            kbhit()
            cprintf()
            cscanf()



    getche() and getch():
        int getche(void); 	// Return type is int
        int getch(void); 	// Return type is int

        Both functions use the header file <CONIO.H> and returns int.

        getche() waits until the keystroke. 
        After the keystroke getche() echoes(shows) it to the screen. It immediately returns the character.
            as an unsigned char and elevated to int. However, your routines (functions) can simply assign this value to a char value. 

        The getch() function is the same as getche(), except that the keystroke is not echoed(not showed) to the screen.



    kbhit():
        int kbhit(void); 	// Return type is int

        kbhit()  requires CONIO.H. 
            It is to detect keypress. When a key is pressed, kbhit() returns true (nonzero), but DOES NOT READ the character.
            If no keystroke is pending, khhit( ) returns false (zero).


    Problems of mixing standard I/O and non-standared I/O: 
        non-standard i/O functions such as getche() are not compatible with the standard i/O functions such as printf() or scanf().



    cprintf() and cscanf():
        These are non-standard versions of printf() and scanf(). Both cprintf() and  cscanf() use the CONIO.H.
        The cprintf() function works like printf() except that 
            it does not translate the newline character (\n) into the CARRIAGE RETURN. Use CARRIAGE RETURN (\r) explicitly.

        The cscanf() function works like the scanf() function.

        We can mix cprintf() and cscanf() with other non standared I/O functions like getche() or getch()
*/




/* Example 1: The getch() function lets you take greater control of the screen because
                you can determine what is displayed each time a key is struck.
                For example, this program reads characters until a 'q' is typed.
                All characters are displayed in uppercase using the cprintf() function. */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main(void) {
    char ch;

    do{
        ch = getch();
        // cprintf("%c", toupper(ch));
        printf("%c", toupper(ch));
        } while(ch != 'q');
    return 0;
}





/* Example 2: The kbbit( ) function is very useful when you want to let a user interrupt a routine
                without actually forcing the user to continually respond to a prompt like 'Continue?'.
                For example, this program prints a 5-percent sales-tax table in increments of 20 cents.
                The program continues to print the table until either the user strikes a key or the maximum value is printed. */
#include<stdio.h>
#include<conio.h>

int main(void) {
    double amount;

    amount = 0.20;

    // notice how CARRIAGE RETURN "\r" is used with "\n"
    // cprintf( "Printing 5-percent tax table \n\r");
    // cprintf("Press a key to stop.\n\n\r");
    printf( "Printing 5-percent tax table \n\r");
    printf("Press a key to stop.\n\n\r");

    do{
        // cprintf("amount: %f tax: %f \n\r", amount, amount*0.05);
        printf("amount: %f tax: %f \n\r", amount, amount*0.05);
        if(kbhit()) break;
        amount = amount + 0.20;
    } while(amount < 100.0);

    return 0;
}


// In the calls to cprintf(), notice how both the carriage return (\r) and the newline (\n) must be output. 
// As explained, cprintf() does not automatically convert newlines into carriage return.





/* Example 3: Write a program that displays the ASCII code of each character typed. 
                Do not display the actual character, however. */
#include <stdio.h>
#include <conio.h>

int main(void){
    char ch;

    ch = getch();
    printf("%d", ch);

    return 0;
}




/* Example 4: Write a program that prints periods on the screen until you press a key. */
#include <stdio.h>
#include <conio.h>

int main(void){
    do{
        printf("%c", '.');
    } while(!kbhit());

    return 0;
}




/* Example 5: What is the difference between getchar() and getche() */
/* 
    The getchar() function is defined by the "ANSI standard" and is used to input characters from the keyboard. 
        However, in most implementations, it uses 'line-buffered I/O', which makes it impractical for interactive use. 

    The getche() function is "not defined by the ANSI standard", but it is quite common and is
        essentially an interactive version of getchar( ). 
*/


