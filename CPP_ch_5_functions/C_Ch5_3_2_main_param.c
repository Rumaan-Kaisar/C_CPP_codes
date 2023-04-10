5.4 Pass Arguments  To Main()
Command-line argument : Many programs allow command-line arguments to be specified when they are run. A command-line argument is the information that follows the program's name on the command line of the operating system. Command-line arguments are used to pass information into a program.
For example, when you use a text editor, you probably specify the name of the file you want to edit after the name of the text editor. Assuming you use a text editor called EDTEXT, then this line causes the file TEST to be edited.
EDTEXT TEST
Here, TEST is a command-line argument.
C command-line arguments are passed to a C program through two arguments (or parameters) to the main() function. The parameters are called argc and argv. 
argc : The argc parameter holds the number of arguments on the command-line and is an integer. It will always be at least 1 because the name of the program qualifies as the first argument.
argv : The argv parameter is an array of string pointers. The most common method for declaring argv is shown here:
char *argv [] ;
	The empty brackets indicate that it is an array of undetermined length. 
	All command-line arguments are passed to main() as strings . To access an individual string, index argv. For example, argv[0] points to the program's name and argv[1] points to the first argument.

This program displays all the command-line arguments that are present when it is executed.
#include <stdio.h>
int main(int argc, char *argv[]){	int i;
for(i=1; i<argc; i++) printf("%s", argv[i]);
return 0;}
Note
[1]	You can use windows powershell instead of windows command line.
[2]	C does not specify what constitutes a command-line argument, because operating systems vary considerably on this point. However, the most common convention is as follows: Each command-line argument must be separated by a space or a tab character. "Commas", "semicolons", and the like are not considered separators. For example,
This is a test 	is made up of four strings, but	 this,that,and,another 	is one string.
[3]	If you need to pass a command-line argument that does contain spaces, you must place it between quotes, as shown in this example: 	"This is a test"
[4]	The names of argv and argc are arbitrary-you can use any names you like. It is a good idea to use these names so that anyone reading your program can quickly identify them as the command-line parameters. 
[5]	The ANSI C standard only defines the argc and argv parameters. However, your compiler may allow additional parameters to main(). 
[6]	New functions : When you pass numeric data to a program, that data will be received in its string form. Your program will need to convert it into the proper internal format using one or another of C's standard library functions. The most common conversion functions are shown here, using their prototypes:
int atoi(char *str);
double atof(char *str);
long atol(char *str);
These functions use the STDLIB.H header file. 
	The atoi() function returns the int equivalent of its string argument. 
	The atof() returns the double equivalent of its string argument,
	The atol() returns the long equivalent of its string argument.
If you call one of these functions with a string that is not a valid number, zero will be returned. 

The following program demonstrates these functions. To use it, enter an integer, a long integer and a floating-point number on the command line It will then redisplay them on the screen.

#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){   int i; double d; long l;
                                    i = atoi(argv[1]);
                                    l = atol(argv[2]);
                                    d = atof(argv[3]);
                                    printf("%d   %ld   %f", i, l, d);
                            return 0;}

New function : When some condition necessary for a program's execution has not been met, most C programmers call the standard library function exit() to terminate the program. The exit()  function has following prototype and uses the STDLIB.H header file.:

void exit(int return-code);

When exit() terminates the program, it returns the value of return-code to the operating system .  By convention, most operating systems use a return code of zero to mean that a program has terminated normally. Nonzero values indicate abnormal termination.





#include<stdio.h>
#include<stdlib.h>

int main (int argc,char *argv[])
{
    int i;
    double d;
    long l;
    i=atoi(argv[1]);
    l=atol(argv[2]);
    d=atof(argv[3]);

    printf("%d %ld %f",i,l,d);
    return 0;

}





#include<stdio.h>
#include<stdlib.h>
int main (int argc, char *argv[])
{
    double pounds;
    pounds=atof(argv[1])/16.0;
    printf("%f pounds",pounds);
    return 0;
}





#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    double pounds;
    if(argc!=2)
    {
        printf("Usage: Convert <ounces>\n");
        printf("Try again");
        exit(1);
    }

        pounds=atof(argv[1])/16.0;
        printf("%f pounds", pounds);

    return 0;
}




#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (int argc,char *argv[])
{
    int i;
    if(argc!=3)
    {
        printf("You must specify two arguments");
        exit(1);
    }
    i=strcmp(argv[1],argv[2]);
    if(i<0) printf("%s > %s ",argv[1],argv[2]);
    else if(i>0) printf("%s < %s ",argv[1],argv[2]);
    else printf("They are the same");
    
    return 0;
}




#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
    if(argc!=3)
    {
        printf("You must specify two numbers");
        exit(1);
    }
    printf("%f",atof(argv[1])+atof(argv[2]));
    
    return 0;
}




#include <stdio.h>
#include<string.h>
#include<stdlib.h>

int main (int argc, char *argv[])
{
    if(argc!=4)
    {
        printf("You must specify the operation");
        printf("Followed by two numbers");
        exit(1);
    }
    if(!strcmp("add",argv[1]))
    printf("%f",atof(argv[2])+atof(argv[3]));
    else if(!strcmp("subtract",argv[1]))
    printf("%f",atof(argv[2])-atof(argv[3]));
    if(!strcmp("multiply",argv[1]))
    printf("%f",atof(argv[2])*atof(argv[3]));
    if(!strcmp("divide",argv[1]))
    printf("%f",atof(argv[2])/atof(argv[3]));
    return 0;
}


