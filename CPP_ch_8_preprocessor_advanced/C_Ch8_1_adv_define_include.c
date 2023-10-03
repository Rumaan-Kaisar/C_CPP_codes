
----------------    #define & #include : advanced    ----------------

We use #define to define a macro name which will be substituted by the character sequence associated with that macro.

Create function like macros using #define : We can use #define to create function like macros. In a function-like macro, arguments can be passed to the macro when it is expanded by the preprocessor. For example, consider this program:

#include<stdio.h>
#define SUM(i, j) i+j  /* when sum(i, j) appears in program it wll replaced by the operation "i+j" */  
int main(void){ 	int sum;
sum = SUM(10, 20);
printf("%d", sum);
return 0; }

Here the line sum = SUM(10, 20); is transformed into sum = 10+20; by the preprocessor. As you can see, the values 10 and 20 are automatically substituted for the parameters i and j.

Again observe how a "function-like macro : RANGE" performing several range check a well as controls the Do-While loop as follows:

#define RANGE(i, min, max) (i<min)||(i>max) ?  1:0
. . . . .
. . . . .
/* Forced to find a random number between 1 & 100 */
do {	r = rand();	} while(RANGE(r, 1, 100));  
	The advantage to using function-like macros instead of functions is that in-line code is generated by the macro, thus avoiding the time it takes to call and return from a function. 
	Only relatively simple operations can be made into function-like macros. 
	Also, because code is duplicated, the resulting program might be longer than it would be if a function were used.

Usage of #include : The #include directive has these two general forms:
#include <filename>
#include "filename"
	#include <filename> (used for search standered Header file comes with compiler) : If you specify the file name between angle brackets, you are instructing the compiler to search for the file in some implementation defined manner. For most compilers, this means searching a special directory devoted to the standard header files. This is why the sample programs have been using this form to include the header files required by the standard library functions. 
	#include "filename" (used for search user-defined HEADER file ) : If you enclose the file name between quotation marks, the compiler searches for the file in another implementation-defined manner. If that search fails, the search is restarted as if you had specified the file name between angle brackets. For the majority of compilers, enclosing the name between quotation marks causes the current working directory to be searched first. Typically, you will use quotation marks to include header files that you create.

Note
[1]	#include "stdio.h" uses quotes in the #include directive. While not as efficient as using the angle brackets, the #include statement will still find and include the STDIO.H header file.
[2]	It is permissible to use both forms of the #include directive in the same program. For example,
#include <stdio.h>
#include "stdlib.h"

