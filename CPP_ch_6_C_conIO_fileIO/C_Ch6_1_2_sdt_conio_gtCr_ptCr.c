/* 
    -------------------    Standard CONSOLE i/o    -------------------
    -------------------    getchar(), putchar() & EOF    -------------------
    EOF: 
        when error occurs while reading/writing an input/output in the case of int returning type function, 
        a negative value is returned (usually -1) it is called macro EOF.

        EOF stands for end-of-file.  
        EOF is an integer value, to allow it to be returne.



    getchar, putchar:
        These two perform "character" INPUT and OUTPUT, respectively;

            int getchar(void);   // Return type is int
            int putchar(int ch); // Return type is int and also parameter type is int

        They both use the header file <STDIO.H>. 

        int getchar(void)
            Returns the next character typed on the keyboard. This character is read as an unsigned char convened to an int.  
            Even though getchar() is declared as returning an int, high-order byte(s) of the integer is discarded when assigned to a char variable
            The reason that getchar() returns an integer is to return the macro EOF, which is a negative integer (usually -1).
            Many compilers implement getchar() in a line-buffered manner, which makes its use limited in an interactive environment.
            
            Line Buffering : getchar() is generally implemented using line buffering. 


        int putchar(int ch) 
            putchar() outputs a "single character" to the screen . 
            Although its parameter is declared to be of type int, this value is converted into an unsigned char by the function. 
                Thus, only the low-order byte of ch is actually displayed. 
            If the output operation is successful, putchar() returns the character written. If an output error occurs, EOF is returned. 
            
            putchar() is faster and more efficient than printf()
*/


 

/* Example 1: Line Buffering : getchar() is generally implemented using line buffering.
                When input is line buffered, no characters are actually passed back to the calling Program until the user presses ENTER.
                The following program demonstrates this:

                Instead of printing a period between each character,
                what you will see on the screen is all the letters you typed before pressing ENTER, followed by a string of periods.*/
#include <stdio.h>
#include <conio.h>

int main(void){
    char ch, s_ch;

    do {
        ch = getchar() ;
        putchar('.') ;
    } while(ch != '\n');

    
    // do {s_ch = getche() ; printf(".") ;} while(s_ch != '\r');
    
    return 0;
}

// Following prints a period between each character. Since getche() is not line buffered
//do {s_ch = getche() ; printf(".") ;} while(s_ch != '\r');






/* ------------    Newline and Carriage Return    ------------
    '/n' and '/r' corresponds to "std-char-functions" and "nonstd-char-functions" : 
        When entering characters using getchar(), pressing ENTER will cause the NEWLINE CHARACTER (\n) to be returned. 
        when using alternative non-standard functions (eh: getche), pressing ENTER will cause the CARRIAGE RETURN character (\r) to be returned.
*/    




/* Example 2: This program illustrates how getchar(), getche(), putchar(), printf() works: 
                getchar() and  getche(), uses different header files. 
                In putchar() we used single quote ' and in printf() we used double quote ". */
#include <stdio.h>
#include <conio.h>

int main(void){  
    char ch, s_ch;

    do {
        ch = getchar() ; 
        putchar('.') ;
    } while(ch != '\n');

    printf("\n\nHowever getche & printf works differently \n");

    do {
        s_ch = getche() ; 
        printf(".") ;
    } while(s_ch != '\r');

    return 0;
}




/* Example 3: The following program illustrates the fact that you can use C's backslash character constants '\n' with putchar(). 
                This program displays
                A
                B
                on the screen  */
#include <stdio.h>

int main(void){
    putchar('A');
    putchar('\n');
    putchar('B');

    return 0;
}




/* Check the EOF */

/* Example 4: Rewrite the program shown in the first example so that it
                checks for errors on both input and output operations. */

#include <stdio.h>

int main(void){
    int i;

    do {
        i = getchar();
        if(i==EOF){
            printf("Error on input.");
            break;
        }

        if(putchar('.')==EOF){
            printf("Error on Output.");
            break;
        }
    } while ( (char) i != '\n');

return 0;
}




/* Example 5: Following fragment is wrong. 
                The 'putcbar()' function outputs a character. It cannot output a "STRING". */
char str[80] = "this is a test";
.
.
putchar(str) :




/* Example 6: What is the difference between getchar(), getche(), and getch()? */
All these functions input a character from the keyboard. 
getchar() often implemented using line-buffered I/O which makes its use in interactive environments undesirable.
    It is a Standared Input function.

getche() is an interactive equivalent to getchar().
    It is a NON-STANDARD CONSOLE FUNCTION

getch() is the same as getche() except that it does not echo the character typed.
    It is a NON-STANDARD CONSOLE FUNCTION
    
    
    
