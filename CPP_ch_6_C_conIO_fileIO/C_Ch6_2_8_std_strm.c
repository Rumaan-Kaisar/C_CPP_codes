
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
        You don't actually need the 'console functions' to access the "console". Any 'file -system function' can access it. 
        (non-standard I/O functions like getche() are differentiated from the 'standard file-system functions' and operate "only on the console".) 




Redirection of std streams : In environments that allow redirection of I/O, stdin and stdout could refer to devices other than the keyboard and screen. Since the console functions operate on stdin and stdout. if these streams are redirected, the "console" functions can be made to operate on other devices. For example, by redirecting the stdout to a disk file. you can use a "console" I/O function to write to a disk file.

Note
	stdin, stdout, and stderr are not variables. They may not be assigned a value using fopen() , nor should you attempt to close them using fclose() . These streams are maintained internally by the compiler. You are free to use them, but not to change them.
