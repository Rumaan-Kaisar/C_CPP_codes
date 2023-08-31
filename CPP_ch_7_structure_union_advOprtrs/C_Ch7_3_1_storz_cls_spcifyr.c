/* 
    ------------    variable storage class specifire    ------------

    variable storage class specifire:
        Variables in C not only have "data types", they also have a "storage class". There are four types of variable storage class :
    
            [1]	Automatic variables,
            [2]	External variables,
            [3]	Register  variables,
            [4]	Static variables.
    
    Four type modifiers/specifiers:
        For the four different 'variable storage class', C defines 'four type modifiers' that affect how a variable is stored. They are
    
            [1]	auto
            [2]	extern
            [3]	register
            [4]	static
    
        These 'specifiers' precede the 'type name'. That is 

                                storage_class  data_type  variable_name;
            Example :   
                                extern int count; 




    auto : 
        The specifier 'auto' is completely UNNECESSARY. 
        Automatic variables are simply 'local variables', which are "auto by Default". 




    extern 
        extern is used for multi file source code to access GLOBAL data.

        As the size of a program grows, it takes 'longer' to COMPILE. 
            For this reason, C allows us to break a program into two or more files. 
        
        We can SEPARATELY COMPILE these files and then link them together  
            (the actual method of separate compilation and linking will be explained in the instructions that accompany your compiler). 

        GLOBAL DATA may need to be accessed by two or more files that form a program. But 'global data' can only be defined 'once'.
            In this case, each source file must 'inform the compiler about the global data' it uses. 
            To accomplish this you will need to use the keyword extern. 
*/




/* Example 1: To understand why we need 'extern', consider the following program, which is split between two files. */

/* FILE #1: ("main.c" file) */
#include <stdio.h>

int count;  // Global Data

void f1(void);  // function prototype

int main(void){ 
    int i;
    f1();       // set count's value
    for(i=0; i<count; i++) printf("%d", i);

    return 0;
}



/* FILE #2 ("fl.c" function definition) */
void f1(void){
    extern int count; // Accessing GLOBAL data count using "extern"
    count = 17;
}


/* 
    By placing 'extern' in front of count's declaration in FILE #2, you are telling the compiler that 'count' is an integer defined ELSEWHERE. 
        In other words, using 'extern' informs the compiler about the existence and the type of the variable it precedes, 
            but it does not cause storage for that variable. 


    If we didn't use 'extern' two errors would occur: 

    Error 1: 
        If we directly use : 

            // FILE #2 
            void f1(void){
                count = 17 ;
            } 
            
            An ERROR will be reported because 'count' is not defined. 


    Error 2:   
        If we even define count as :
            
            // FILE #2 
            void f1(void){ 
                int count; // re-declaring the variable i

                count = 17;
            } 
            
            many linkers will report a DUPLICATE-symbol ERROR, which means that 'count' is defined twice, and the linker doesn't know which to use.

    The solution to these problem is C's 'extern' specifier. 

*/





/* 
    // another use of "extern"
    Use 'extern' in SAME FILE to MENTION the global variable (not to treat as LOCAL variable): 
        We can use  'extern' inside a 'function' to declare a global variable defined ELSEWHERE in the same file 
        (i.e.  to mention that it is GLOBAL variable so that it won't be treated as a LOCAL variable ). 

        But it is rarely used. 
            Because, whenever the compiler encounters a 'variable name' not defined by the function as a LOCAL variable, it assumes that it is GLOBAL. 
            For example, the following is valid:
*/

// Use 'extern' in SAME FILE 
#include <stdio.h>

int count;

int main(void){ 	
    extern int count; // this refers to global count 

    count = 10;
    printf("%d", count);

    return 0;
}





//-------------------------    Linking multiple source files    -------------------------

// How to Link Multiple C++ Files with G++:
    // first install "GCC compiler" or "codeBlocks with GCC"
    // we have installed "codeBlocks with GCC"
    // find the intalled path, then find the "bin" folder where the "compilers" stored
    // copy the path, its usually: 'C:\Program Files\CodeBlocks\MinGW\bin\'
    // add this path to "user variable" and "system variable" to your SYSTEM's "Environment Variables" (place the at the top of the list)
    // alwways run CLI in "C:\Users\name" i.e. in system-user directory

// Use fillowing command to link: "main.c" and "fl.c"
        // if source files are in 'C:\Users\name':
        g++ main.c fl.c -o main

// if the files are in another destination:
        // if source files are in   'H:\shared_docs\codes_C_CPP\raw_runs\multi_file'
        g++ H:\shared_docs\codes_C_CPP\raw_runs\multi_file\main.c H:\shared_docs\codes_C_CPP\raw_runs\multi_file\fl.c -o H:\shared_docs\codes_C_CPP\raw_runs\multi_file\main

// for c++ compilation
        g++ main.cpp function_file.cpp -o main
        // -o main : it means we want the output file as one "main.exe"




// To link multiple files in code::block: 
    // use 'project', 
    // create new project (console), 
    // put the source code files in the project name folder. 
    // Compile,  
    // run the whole .cbp file.




/* 
    register (access AS FAST AS POSSIBLE): 
        When you specify a 'register variable' you are telling the compiler that you want ACCESS to that variable to be AS FAST AS POSSIBLE. 
        
        In 'early version of C 'it causes the variables to be held in a register of the CPU. (This is how the name register came about.)
            By using a register of the CPU, "EXTREMELY FAST ACCESS" times are achieved.


        In 'modern versions of C', the requirement that register variables must be held in a CPU register was 'removed'. 
            Now a register variable will be stored in such a way as to minimize access time. This means:

                register variables of type 'int' and 'char' continue to be held in a CPU register.
                
                No matter what storage method is used, only so many variables can be granted the fastest possible access time. 
                    e.g. the CPU has a limited number of registers. When fast-access locations are exhausted, 
                        the compiler is free to make register variables into regular variables.


        You must choose carefully which variables you modify with register.  
            use it for a frequently used variable, such as the variable that CONTROLS a LOOP, into a register variable.  
                The more times a variable is accessed, the greater the increase in performance when its access time is decreased.
                
            Generally, you can assume that 'at least two variables per function' can be truly optimized for access speed.

        pointers vs register:
            Restriction of using pointers: 
            Because a register variable may be stored in a register of the CPU, it may not have a 'memory address'. 
                This means that you cannot use the "&" to find the ADDRESS of a 'register variable' and cannot use POINTERS.




    static : 
        Recall how a local variable act: a local variable is created upon entry into its function and destroyed upon exit. And a global variable is active in whole program.

        -----------------    static LOCAL variable    -----------------

        Use of static modifier on local variables:  
            When you use the static modifier, you cause the contents of a local variable to be preserved between function calls 
                (That is it will not destroy when function exit and it act like a global variable inside its own function). 

        Unlike normal local variables, which are 'initialized each time a function is entered', a static local variable is "INITIALIZED only ONCE". 

        The advantage to using a 'static local variable' over a 'global': 
            The 'static local' variable is still known to and accessible by only the function in which it is declared.
            Global variables active outside any function.


        -----------------    static GLOBAL variable    -----------------

        Use of static modifier on global variables :  
            The 'static' modifier may also be used on 'global variables' (more like a local variable for its own file). 
            It causes the GLOBAL VARIABLE to be known to and accessible by ONLY the functions in the SAME FILE in which it is declared. 
            This static global variable has 'NO EFFECT ON OTHER FILE' (when we work with different files) which use the 'same named global variable'.

*/



/* Example 2: take a look at this program, notice how static is used. */

#include <stdio.h>

void f(void);

int main(void){ 
    int i;
    for(i=0; i<10; i++) f();
    return 0;
}

void f(void){   
    static int count = 0;
    // int count = 0;
    count++;
    printf("count is : %d  ", count);
}


// which displays the following output, . Here count retains its value between function calls. :
count is : 1 count is : 2 . . . .  count is : 10 

// but without static modifier int count = 0; gives the result : 
count is : 1 count is : 1 . . . .  count is : 1. Which is obvious and we explained in 3.2 in chapter 3.





/* Example 3: no name conflicts arise if a static global variable in one file has the same name as another global variable 
                in a different file of the same program. 
                For example, consider these two fragments, which are parts of the same program: */


// FilE #1
int count;  // global variable
. . .
. . .
count = 10;
printf("%d", count);



// FilE #2
static int count;   // static global variable (using same name of File#1's global var)
. . .
. . .
count = 5:
printf("%d", count);
 

// Because count is declared as static in FILE #2, no name conflicts arise. 
    // The printf() statement in FILE #1 displays 10 and the printf() statement in FILE #2 displays 5 
    // because the two counts are different variables.






I. To get an idea about how much faster access to a register
variable is, try the foHowing program. It makes use of another of
C's standard library functions caHed c1ock( ), which returns the
",number of system clock ticks since the program began
execution. It has this prototype:
clock_t clock(void);
It uses the TIME.H header. TIME.H also defines the c1ock_t
type, which is more or less the same as long. To time an event
using c1ock{ ), call it immediately before the event you wish to
time and save its return value. Next, call it a second time after
the event finishes and subtract the starting value from the
ending value. This is the approach used by the program to time
how long it takes two loops to execute. One set of loops is
controlled by a register variable, 'the other is controlled by a
non-register variable.
'include <stdio.h>
.include <time.h>
int i; /* This will not be transformed into a
register variable because it is global.* /
int main(void)
(
~ register int j:
I
int k;
clock_t start, finish;
start '= clock();
for(k=Oi k<100; k++)
for(i~O; i<32000; i+.)
finish = clock();
pr~ntf( · Non-register loop: tId ticKs \ n- , finish - start);
start = clock();
for l k=O; k<lOO; k++l
for(j=O; j<32000 ; j++l;
finish = clock() ;
printf (-Register 'loop: tId ticKs \ n-, finish - start);
return 0;ADVANCW DATA TYPES AND OPERATDRS 345
For most compilers, the register-controlled loop will execute
about twice as fast as the non-register controlled loop.
The non-register variable is global because, when feasible,
virtually all compilers will automatically convert local variables
not specified as register types into register types as an
automatic optimization. If you do not see the predicted results,
it may mean that the compiler has automatically optimized i
into a register variable, too. Although you can't declare global
variables as register, there is notbing that prevents a compiler
from optimizing your program to this effeet. If you don't see
much difference between the two loops, try creating extra global
variables prior to i so that it will not be automatically optimized.
2. As you know, the compiler can optimize access speed for
only a limited number of register variables in anyone function
(perhaps as few as two). However, this does not mean that your
program can only have a few register variables. Because of the
way a C program executes, each function may utilize the
maximum number of register variables. For example, for the
average compiler, all the variables shown in the next program
will be optimized for speed:
#include <stdio.h>
void f2 (void) :
void f (void) ;
int main (void)
(
register int a , b;
)
void f (void)
(
register int i, j;c
void f2(voidl
(
register int j. k;
)
3. Local static variables have several uses. One is to al1o-;'" a
function to perform various ininalizations only once, when it is
first called. For example, consider this function :
void myfunc(void)
(
}
static inc first = 1;
if{f~rst) { j* initialize the system */
rewH~d (fp) ;
)
a = 0;
lee = 0,
fprintf(~System IniLialized~);
first = 0;
Because first is static, it will hold its value between calls. Thus,
the initialization code will be executed only the first time the
function is called.
4. Another interesting use for a local static variable is to control a
recursive function. For example. this program prints the
numbers 1 through 9 on the screen:
#include <stdio.h>
void f (void) ;
int main (void)
(
t();
return 0;
}ADVANCUI DATA TYPES AND OPERATORS 347
void f (void)
(
)
static int stop=O:
stop++;
if(stop==10) return;
printf("%d ", stop);
f(); /* recursive call *1
11.' USE THE STORAGE ClASS SPEC/FifRS
Notice how stop is used to prevent a recursive call to C( ) when
it equals 10.
5. Here is another example of using extern to allow global data to
be accessed by two files:
FILE #1:
fiinclude <stdio.h>
char str[80];
void getname(void);
int main (void)
(
getname () ;
printf"{ -Hello %s·. str);
return 0;
)
FILE #Z,
'include <stdio.h>
extern char str[BO]:
void getname(void)
(
)
printf("Enter your first name: .. ,; .
gets (str);
~TEACH YOURSElF
C
EXERCISES



------------   exs   -------------



1. Assume that your compiler will actually optimize access time of
only two register variables per function. In this program, which
two variables are the best ones to be made into register variables?
#include <stdio.h>
#include <conio.h>
int main (void)
{
)
int i. j, k, m;
do ("
printf t -Enter a value: .);
scanf ("M', &i);
m = 0;
for(j=O; j<i; j++)
for (k=Oi k<100i k++ )
m = k + mi
while t i>O) ;
return 0;

1. The best variables to make into resIatm" types are k and m,
because they are accessed most frequently



linclude <stdio.h>
,
void .~it(int value),
int ....in(void)
(
}
sWlLit(lO) ,
sum_it (20) ,
sWILit(30) ,
sWILit(40);
return OJ
void s~it{int value)
(
static int sum=O;
sum = sum + value;
printf(-CUrrent value: 'd\n·, sum);
}




2. Write a program that contains a function called sum_it( ) that
has this .prototype:
void sum_it (int value);
Have this function use a local static integer variable to maintain
and display a running total of the values of the parameters iUs
called with. for example, if sum_it( ) is called three times with
the values 3,6, 4, then sum_it( ) will display 3, 9, and 13.




3. Try the program descnbed in Example :.. Be sure to actually use
two files. If you are unsure how to compile and link a program
consisting of two files, check your compiler's user manual.




What is wrong with this fragment?
register int i;
int .p;
p = &i;

4. You cannot obtain the address of a register variabl
