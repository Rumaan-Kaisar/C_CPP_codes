
/* 
    ---------------|     Pass Arguments  To Main()    |---------------
    Command-line argument : Many programs allow command-line arguments to be specified when they are run.
        Command-line arguments are used to pass information into a program.
            For example: you use a text editor called "EDTEXT", then this line causes the file "TEST" to be edited.
                EDTEXT TEST
                Here, TEST is a command-line argument.



    C command-line arguments are passed to a C program through "two arguments" (or parameters) to the main() function. 
    The parameters are called 'argc' and 'argv'. 

    argc : The 'argc' parameter holds the 'number of arguments' on the command-line and is an "INTEGER". 
        It will always be at least 1 because the name of the program qualifies as the first argument.

    argv : The 'argv' parameter is an "array of string pointers". The most common method for declaring argv is shown here:
        char *argv [] ;
        The empty brackets indicate that it is an array of "undetermined length". 

    The names of 'argv' and 'argc' are arbitrary-you can use any names you like.



    All command-line arguments are passed to main() as "strings" . To access an individual string, index argv. 
        For example, argv[0] points to the "program's name" and argv[1] points to the first argument. 


    
    
    ---------------|    seperators for Command line args    |---------------
    You can use windows powershell instead of windows command line.
    The most common convention is as follows: 
        Each command-line argument must be separated by a "space" or a "tab" character. 
        "Commas", "semicolons", and the like are 'not considered separators'.
        If you need to pass a "command-line argument" that does contain "spaces", you must place it between quotes, as : 	"This is a test"




    ---------------|    String Conversion Functions    |---------------
        When you pass numeric data to a program, that data will be received in its "string" form. 
            Your program will need to convert it into the proper internal format using one or another of C's standard library functions. 
            The most common conversion functions are shown here, using their prototypes:

                int atoi(char *str);
                    // atoi() returns the int equivalent of its string argument

                double atof(char *str);
                    // atof() returns the double equivalent of its string argument,

                long atol(char *str);
                    // atol() returns the long equivalent of its string argument.
        
        These functions use the <STDLIB.H> header file. 
            If you call one of these functions with a string that is not a valid number, zero will be returned. 




    exit():
    When some condition necessary for a program's execution has not been met, 
        most C programmers call the standard library function exit() to terminate the program. 
        The exit()  function has following prototype and uses the STDLIB.H header file.:

            void exit(int return-code);

    Return codes:
        When exit() terminates the program, it returns the value of return-code to the operating system .  
            return code of "zero" to mean that a program has terminated "normally". 
            "Nonzero" values indicate "abnormal" termination.
*/





/* Example 1: This program displays all the command-line arguments that are present when it is executed. */
#include <stdio.h>

int main(int argc, char *argv[]){
    int i;

    for(i=1; i<argc; i++) printf("%s", argv[i]);

    return 0;
}
// save the program as "func_mn_prm_1.c" after compile, in CLI execute following
// func_mn_prm_1 Hoolo meaw




/* Example 2: The following program demonstrates atoi(), atol(), atof() functions. 
                To use it, enter an integer, a long integer and a floating-point number on the command-line 
                It will then redisplay them on the screen. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){   
    int i; 
    double d; 
    long l;

    i = atoi(argv[1]);
    l = atol(argv[2]);
    d = atof(argv[3]);

    printf("%d   %ld   %f", i, l, d);

    return 0;
}
// save the program as "func_mn_prm_2.c" after compile, in CLI execute following
// func_mn_prm_2 23 334567 4656.678




/* Example 3: This program coverts ounces to pounds. To use it, specity the
                number of ounces on the command line */
#include<stdio.h>
#include<stdlib.h>

int main (int argc, char *argv[]){
    double pounds;

    pounds = atof(argv[1])/16.0;
    printf("%f pounds",pounds);

    return 0;
}




/* Example 4: Although the examples up to this point haven't done so,
                you should verity in real programs, that the right number of
                command-line arguments have been supplied by the user. The
                way to do this is to test the value of argc. For example, the
                ounces-to-pounds program can be improved as shown here:| */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    double pounds;

    if(argc!=2){
        printf("Usage: Convert <ounces>\n");
        printf("Try again");
    }
    else{
        pounds=atof(argv[1])/16.0;
        printf("%f pounds", pounds);
    }
    
    return 0;
}
/* This way the program will perform a conversion only if a
command-line argument is present.  */
// func_mn_prm_3    shows the message
// func_mn_prm_3 23     converts the value to pound


/* SAFER-way: Generally, the preceding program will be wrinen by a
professional C programmer like this: */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    double pounds;

    if(argc!=2){
        printf("Usage: Convert <ounces>\n");
        printf("Try again");
        exit(1);    // stop the program
    }

    pounds=atof(argv[1])/16.0;
    printf("%f pounds", pounds);
    
    return 0;
}
// func_mn_prm_3v2    shows the message
// func_mn_prm_3v2 54     converts the value to pound
// When some condition necessary for a program's execution has not been met, 
// most C programmers call the standard library function exit() to terminate the program. 




/* Example 5: Write a program that accepts two command-line arguments.
                Have the program compare them and report which is
                lexicographically greater than the other. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc, char *argv[]){
    int i;

    if(argc!=3){
        printf("You must specify two arguments");
        exit(1);
    }

    i = strcmp(argv[1], argv[2]);
    if(i<0) printf("%s > %s ",argv[1], argv[2]);
    else if(i>0) printf("%s < %s ", argv[1],argv[2]);
    else printf("They are the same");
    
    return 0;
}
// func_mn_prm_5 lobo nobo
// func_mn_prm_5 lobo lobo




/* Example 6: Write a program that takes two numeric arguments and display their sum. */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[]){
    if(argc!=3){
        printf("You must specify two numbers");
        exit(1);
    }

    printf("%f", atof(argv[1]) + atof(argv[2]));
    
    return 0;
}
// func_mn_prm_6 -7 9



/* Example 7: Expand the program in Exercise 2 so that it takes three
                arguments. The first argument must be one of these words: 
                add
                subtract, 
                multiply, or 
                divide. 
                Based on the value of the first
                argument, perform the requested operation on.the remaining
                two numeric arguments. */
#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[]){
    
    if(argc!=4)
    {
        printf("You must specify the operation");
        printf("Followed by two numbers");
        exit(1);
    }
    if(!strcmp("add", argv[1]))
        printf("%f", atof(argv[2])+atof(argv[3]));

    else if(!strcmp("subtract", argv[1]))
        printf("%f", atof(argv[2])-atof(argv[3]));

    else if(!strcmp("multiply", argv[1]))
        printf("%f", atof(argv[2])*atof(argv[3]));

    else if(!strcmp("divide", argv[1]))
       if(atof(argv[3])) printf("%f", atof(argv[2])/atof(argv[3]));
       else printf("Math ERR");

    return 0;
}
// func_mn_prm_7 add -7 9
// func_mn_prm_7 subtract -7 9
// func_mn_prm_7 multiply -7 9
// func_mn_prm_7 divide -7 9
// func_mn_prm_7 divide 0 9
// func_mn_prm_7 divide 9 0




/* Example 8: How do command-line arguments get passed to a C program? */
Command-line arguments are passed to a C program through the "argc" and "argv" parameters to main().


   

/* Example 9: Write a program that takes a string as a command-line
                argument. Have it output the string in coded form. To code the
                string, add 1 to each character. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    char *p;

    if(argc!=2) {
        printf("You need to specify a string");
        exit(1);
    }

    p = argv[1];

    while(*p) {
        printf("%c", (*p)+1);
        p++;
    }

    return 0;
}
// name source file as func_CLiArg_1.c
// func_CLiArg_1 panthop




/* Example 10: Write a program that allows access only if the user enters the
                correct password as a command-line parameter. If the user
                enters the right word, print "Access Permitted"; otherwise print "Access Denied". */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    if(argc!=2){
        printf("Specify a password");
        exit(1);
    }

    if(!strcmp(argv[1], "password")) printf("Access Permitted");
    else printf("Access Denied");

    return 0;
}
// name source file as func_CLiArg_2.c
// func_CLiArg_2 panthop
// func_CLiArg_2 password




/* Example 10: What does the exit() function do? */
The exit() function causes immediate program termination. 
It also returns a value to the operating system




/* Example 11: What does the atoi() function do? */
The atoi() function converts its "STRING ARGUMENT" into its equivalent "INTEGER" form. 
The string must represent (in string form) a valid integer.


