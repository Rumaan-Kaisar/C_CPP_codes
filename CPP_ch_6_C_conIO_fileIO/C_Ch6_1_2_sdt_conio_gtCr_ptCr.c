6.3 Standard CONSOLE i/o : getchar(), putchar() & EOF
EOF: when error occurs while reading/writing an input/output in the case of int returning type function , a negative value is returned (usually -1) it is called macro EOF. The EOF macro, defined in STDIO.H, stands for end-of-file. Since EOF is an integer value, to allow it to be returned, the responsible/corresponding function must return an integer.

The ANSI C standard defines these two functions prototype that perform character input and output, respectively;
int getchar(void);   /*Return type is int*/
int putchar(int ch); /*Return type is int and also parameter type is int*/
They both use the header file STDIO.H. 

int getchar(void); : Here getchar( ) is declared as returning an int. The getchar( ) function returns the next character typed on the keyboard. This character is read as an unsigned char convened to an int.  Even though getchar( ) is declared as returning an int, but when program will assign this value to a char variable the high-order byte(s) of the integer is simply discarded. The reason that getchar( ) returns an integer is that when an error occurs while reading input, getchar( ) returns the macro EOF, which is a negative integer (usually -1). Since EOF is an integer value, to allow it to be returned, getchar( ) must return an integer. 
	Many compilers implement getchar( ) in a line-buffered manner, which makes its use limited in an interactive environment.

int putchar(int ch); : Here putchar( ) is declared as returning an int , its parameter is declared to be of type int. The putchar( ) function outputs a single character to the screen . Although its parameter is declared to be of type int, this value is converted into an unsigned char by the function. Thus, only the low-order byte of ch is actually displayed. If the output operation is successful, putchar() returns the character written. If an output error occurs, EOF is returned. 

Note
[1]	In the vast majority of circumstances, if an error occurs when reading from the keyboard, it means that the computer has ceased to function. Therefore, most programmers don't usually bother checking for EOF when using getchar( ). They just assume a valid character has been returned. Of course, there are circumstances in which this is not appropriate-for example, when I/O is redirected  (as explained in Next Chapter). 

[2]	If an output error occurs executing putchar( ), EOF is returned. For reasons similar to getchar( ), if output to the screen fails, the computer has probably crashed anyway, so most programmers don't bother checking the return value of putchar( ) for errors.

[3]	The reason to use putchar( ) rather than printf( ) with the %c specifier to output a character is that putchar( ) is faster and more efficient. 

[4]	Line Buffering : getchar( ) is generally implemented using line buffering. When input is line buffered, no characters are actually passed back to the calling Program until the user presses ENTER. The following program demonstrates this:
#include <stdio.h>
#include <conio.h>
int main(void){	char ch;
do {ch = getchar( ) ; putchar('.') ;} while(ch != '\n');
return 0;}
Instead of printing a period between each character, what you will see on the screen is all the letters you typed before pressing ENTER, followed by a string of periods.
do {s_ch = getche( ) ; printf(".") ;} while(s_ch != '\r'); printing a period between each character.

[5]	/n and /r corresponds to std-char-functions and nonstd-char-functions : When entering characters using getchar( ), pressing ENTER will cause the newline character (\n) to be returned. However, when using one of the alternative non-standard functions, pressing ENTER will cause the carriage return character (\r) to be returned. Keep this difference in mind.
This program illustrates how getchar(), getche(), putchar(), printf() works: getchar() and  getche(), uses different header files. In putchar() we used single quote ' and in printf() we used double quote ".
#include <stdio.h>
#include <conio.h>
int main(void){  char ch, s_ch;
    do {ch = getchar( ) ; putchar('.') ;} while(ch != '\n');
    printf("\n\nHowever getche & printf works differently \n");
    do {s_ch = getche( ) ; printf(".") ;} while(s_ch != '\r');
    return 0;}

