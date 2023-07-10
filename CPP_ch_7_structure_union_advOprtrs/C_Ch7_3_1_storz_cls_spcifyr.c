
5.6 variable storage class specifire (Advanced topic)
Variables in C not only have data types, they also have a storage class. There are four types of variable storage class :
 
[1]	Automatic variables,
[2]	External variables,
[3]	Register  variables,
[4]	Static variables.
 

For the four different variable storage class, C defines four type modifiers that affect how a variable is stored. They are
 
[1]	auto
[2]	extern
[3]	register
[4]	static
 
These specifiers precede the type name. That is 
storage_class  data_type  variable_name ;	Example :   extern int count; 

[1]	auto  : The specifier auto is completely unnecessary. Automatic variables are simply local variables, which are auto by default. 

[2]	extern :  As the size of a program grows, it takes longer to compile. For this reason, C allows us to break a program into two or more files. We can separately compile these files and then link them together  ( the actual method of separate compilation and linking will be explained in the instructions that accompany your compiler). 
	Global data may need to be accessed by two or more files that form a program. But global data can only be defined once.
	In this case, each source file must inform the compiler about the global data it uses. To accomplish this you will need to use the keyword extern. 
To understand why, consider the following program, which is split between two files:

 
/* FILE #1 */
#include <stdio.h>
int count;
void f1 (void) ;
int main(void){ 
    int i;
    f1(); /* set count's value */
    for(i=0; i<count; i++) printf("%d", i);
return 0;}
/* FILE #2 */
void f1(void){
    	extern int count; /* Global count */
count = 17 ;}



 
	By placing extern in front of count's declaration in FILE #2, you are telling the compiler that count is an integer defined elsewhere. In other words, using extern informs the compiler about the existence and the type of the variable it precedes, but it does not cause storage for that variable.

	To link multiple files in code::block, use project, create new project (console), put the source code files in the project name folder. Compile,  run the whole .cbp file.

If we didn’t use extern two errors would occur : 
Error 1 : If we directly use : /* FILE #2 */ void f1(void){count = 17 ;} an error will be reported because count is not defined. 
Error 2  :   If we even define count as /* FILE #2 */ void f1(void){ int count; count = 17 ;} many linkers will report a duplicate-symbol error, which means that count is defined twice, and the linker doesn't know which to use.

The solution to these problem is C's extern specifier. 
	Use extern in same file to mention the global variable : We can use  extern inside a function to declare a global variable defined elsewhere in the same file (i.e.  to mention that it is global variable so that it won't be treated as a local variable ). But it is rarely used. Because, whenever the compiler encounters a variable name not defined by the function as a local variable, it assumes that it is global. For example, the following is valid:

#include <stdio.h>
int count;
int main(void){ 	extern int count; /* this refers to global count *1
count = 10;
printf("%d", count);
return 0;}
[3]	register : When you specify a register variable you are telling the compiler that you want access to that variable to be as fast as possible. In early version of C it causes the variables to be held in a register of the CPU. (This is how the name register came about.) By using a register of the CPU, extremely fast access times are achieved.
	In modern versions of C, the requirement that register variables must be held in a CPU register was removed. Instead, the ANSI C standard stipulates that a register variable will be stored in such a way as to minimize access time. This means that,
	 register variables of type int and char continue to be held in a CPU register.
	No matter what storage method is used, only so many variables can be granted the fastest possible access time. 

For example, the CPU has a limited number of registers. When fast-access locations are exhausted, the compiler is free to make register variables into regular variables. 
You must choose carefully which variables you modify with register.  One good choice is to make a frequently used variable, such as the variable that controls a loop, into a register variable.  The more times a variable is accessed, the greater the increase in performance when its access time is decreased. Generally, you can assume that at least two variables per function can be truly optimized for access speed.
	Restriction of using pointes : Because a register variable may be stored in a register of the CPU, it may not have a memory address. This means that you cannot use the & to find the address of a register variable and cannot use pointers.

[4]	static : Recall 3.2 how a local variable act : a local variable is created upon entry into its function and destroyed upon exit. And a global variable is active in whole program.

	Use of static modifier on local variables :  When you use the static modifier, you cause the contents of a local variable to be preserved between function calls (That is it will not destroy when function exit and it act like a global variable inside its own function). 

Unlike normal local variables, which are initialized each time a function is entered, a static local variable is initialized only once. 
For example, take a look at this program,

#include <stdio.h>
void f(void);
int main(void){ int i;
                for(i=0; i<10; i++) f();
                return 0;}

void f(void){   static int count = 0;
                count++;
                printf("count is : %d  ", count);}
which displays the following output:
count is : 1 count is : 2 . . . .  count is : 10 . Here count retains its value between function calls. 
but without static modifier int count = 0; gives the result : count is : 1 count is : 1 . . . .  count is : 1. Which is obvious and we explained in 3.2 in chapter 3.

So why didn’t we use a global variable in the previous example? The answer is : The advantage to using a static local variable over a global one is that the static local variable is still known to and accessible by only the function (global variables active outside any function) in which it is declared.

	Use of static modifier on global variables :  The static modifier may also be used on global variables ( more like a local variable for its own file). It causes the global variable to be known to and accessible by only the functions in the same file in which it is declared. This static global variable has no effect on other file (when we work with different files) which use the same named global variable.
This means that there are no name conflicts if a static global variable in one file has the same name as another global variable in a different file of the same program. 
For example, consider these two fragments, which are parts of the same program:

 
FilE #1
int count;
. . .
. . .
count = 10;
printf("%d", count);
FilE #2
static int count;
. . .
. . .
count = 5:
printf("%d", count);
 

Because count is declared as static in FILE #2, no name conflicts arise. The printf() statement in FILE #1 displays 10 and the printf() statement in FILE #2 displays 5 because the two counts are different variables.

