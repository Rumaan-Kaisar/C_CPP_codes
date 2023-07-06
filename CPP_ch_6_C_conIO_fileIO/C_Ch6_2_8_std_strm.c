/* 
    ---------------    THE STANDARD STREAMS    ---------------
    Standard  streams: 
        When a C program 'BEGINS EXECUTION', three streams are automatically opened and available for use.

                1. standard input (stdin), 
                2. standard output (stdout), and 
                3. standard error (stderr). 

        "stdin" inputs from the KEYBOARD;  
        "stdout" and "stderr" write to the SCREEN.

        By default, they refer to the "CONSOLE", 
            but in environments that Support redirectable I/O, they can be redirected by the OS to some other device.



    These 'standard streams' are "FILE pointers" and may be used with any function that requires a variable of type "FILE *". 

    ConIO using FileIO:
        You can use fprintf() to print "formatted output" to the screen by specifying "stdout" as its output stream. 
            The following two statements are functionally the same:
        
                // using FileIO function
                fprintf(stdout, "%d %c %s", 100, 'c', "this is a string");

                // usning ConIO function
                printf("%d %c %s", 100, 'c', "this is a string");


        In actuality, C makes little distinction between 'console-I/O' and 'file-I/O'. 
            As just shown, it is possible to perform "console I/O" using several of the 'file-system functions'. 



    Disk FileIO using ConIO:
        It is also possible to perform "DISK FILE I/O" using 'CONSOLE I/O' functions, such as printf().
            Because all "console I/O functions" are actually 'special-case file-system functions' that automatically operate on "stdin" and "stdout". 

        The console is simply another hardware device. 
            You don't actually need the 'console functions' to access the "console". Any 'file-system function' can access it. 
            (non-standard I/O functions like getche() are differentiated from the 'standard file-system functions' and operate "only on the console".) 



    Redirection of std streams: 
        In environments that allow "REDIRECTION OF I/O", 'stdin' and 'stdout' could refer to devices "other than the KEYBOARD and SCREEN". 
        
        Since the "console functions" operate on STDIN and STDOUT, if these streams are REDIRECTED, 
            the "console functions" can be made to operate on other devices. 
                For example, by redirecting the "STDOUT" to a "DISK FILE". you can use a "console I/O function" to write to a DISK FILE.



    Note that:
        stdin, stdout, and stderr are not variables. They may not be assigned a value using fopen() , 
            nor should you attempt to close them using fclose() . 
            These streams are "maintained internally" by the COMPILER. 
            You are free to use them, but 'not to change them'.
*/




/* Example 1: Assume that this program is called "TEST". If you execute TEST normally, it displays the string on the screen. 
                However, if an environment supports redirection of I/O, stdout can be redirected to a file. */
#include <stdio.h>

int main(void){
    printf("This is an example of redirection.\n");
    return 0;
}

// For example, in a DOS, OS/2, Windows, or UNIX environment, executing TEST like this
TEST > OUTPUT
// causes the output of TEST to be written to a file called OUTPUT. You might want to try this now for yourself.

// we named our source file "FL_IO_strm_1" and stored the output a file called "output_test"
FL_IO_strm_1 > output_test




/* Example 2: Input can also be redirected. For example, consider the following program.
                causes "STDIN" to be directed to the file called INPUT. 
                Assuming that INPUT contained the ASCII representation for an integer,
                the value of this integer will be read from the file and printed on the screen. */
#include <stdio.h>

int main (void){
    int i;

    scanf ("%d", &i);
    printf ("%d", i);
    return 0;
}

// Assuming it is called TEST, executing it as
TEST < INPUT

// we named our source file "FL_IO_strm_2" and stored the output a file called "input_test"
FL_IO_strm_2 < input_test



// Note: from above 2 Examples notice usage of ">" for "output" and "<" for "input"




/* Example 3: When using gets() it is possible to overrun the array that is being used to receive 
                the characters entered by the user because gets() provides "no bounds checking". 

                One way around this problem is to use
                    fgets(), specifying 'stdin' for the "input stream". 
                    Since fgets() requires you to specify a maximum length, it is possible to prevent an array overrun. 
                    The only trouble is that fgets() does not remove the newline character and gets() does. 
                    This means that you will have to manually remove it, as shown in the following program:     */
#include <stdio.h>
#include <string.h>

int main(void){
    char str[10];
    int i;

    printf("Enter a string: ");
    fgets(str, 10, stdin);

    // remove newline, if present
    i = strlen(str)-1;
    if(str[i]=='\n') str[i] = '\0';

    printf ("This is your string: %s", str);

    return 0;
}

// FL_IO_strm_3 < myFile_2ol




/* Example 4: Write a program that copies the contents of one text file to another. 
                However, use only "console IO functions" and redirection to accomplish the file copy. */

/* 
    Copy using- redirection.
    Execute like this: 
        C > NAME < in > out 
*/

#include <stdio.h>

int main(void) {
    char ch;
    
    while(!feof(stdin)) {
        scanf("%c", &ch);
        if(!feof(stdin)) printf("%c", ch);
    }

    return 0;
}
// FL_IO_strm_4 < fl_1 > fl_2




/* Example 5: On your own, experiment using fgets() to read strings entered from the keyboard. */




/* Example 6: How do the "console' I/O functions relate to the file system?
                The 'console' I/O functions are simply special cases of the general file system  */




/* Example 7: How do functions like printf() and scanf() relate to the C file system?

                These are special functions that automatically use the std streams: "stdin" and "stdout"
                    The printf() and scanf() functions are part of the C file system. 
                    They are simply special case functions that automatically use "stdin" and "stdout". 
*/




/* Example 8: What are stdin, stdout, and stderr?

                These are standared streams. 
                    'stdin', 'stdout', and 'stderr' are three streams that are opened automatically when your C program begins executing. 

                    By default they refer to the 'console', but in operating systems that support IO redirection, they can be redirected to other devices.
*/

