/* 
    ---------------    Access modifiers : const and volatile    ---------------
    Modifiers const and volatile affect the way variables are accessed by both your 'program' and the 'compiler'

    const : 
        precede a variable's type with 'const', you PREVENT that variable from 'being modified by your program'.
        It can be given an initial value when it is declared.
        The compiler is free to locate const variables in ROM (read-only memory) in environments that support it.
        

    volatile : 
        When you precede a variable's type with volatile, 
            you are telling the COMPILER that the 'value' may be changed in ways not 'explicitly defined' in the program. 
        
        For example, a variable's ADDRESS might be given to an 'interrupt service routine', and 
            its value changed each time an interrupt occurs.
*/




/* Example 1: The following short program shows how a 'const' variable can be given an 'INITIAL VALUE' 
                and be used in the program, as long as it is not on the left side of an assignment statement . 
*/
 
#include <stdio.h>

int main(void) {	
    const int i = 10;   // initialized const local variable
    
    printf( "%d", i); 	// this is OK
    
    return 0; 
}



// The following program tries to assign i another value. This program will 'not compile'. 

#include <stdio.h>

int main(void) {	
    const int i = 10;   // initialized a const local variable
    
    i=20; 	// this is wrong
    printf( "%d", i); 

    return 0; 
}

// error: assignment of read-only variable 'i'



/*
    -----------    const pointer parameters    -----------

    The const modifier can 'prevent' a function from modifying the 'object' that a 'parameter points to'. 
    i.e. when a 'pointer parameter' is preceded by const, 
        'no statement in the function' can modify the variable pointed to by that parameter.

    The most important feature of 'const pointer parameters' is that 
        they guarantee that many Standared Library functions will not modify the variables pointed to by their parameters.

    For example, here is the actual prototype to strlen() specified by the ANSI standard:
                    size_t sll1en(const char *str);
        Since 'str' is specified as conat, 'the string it points to' cannot be changed.
*/



/* Example 2: The following program shows how a 'pointer parameter' can be declared as 'const' 
                to prevent the object it points to from being modified. 
*/

#include<stdio.h>

void pr_str(const char *p);     // const pointer  parameter


int main(void){	
    char str[80];

    printf("Enter a string: "); 
    gets(str);      // inputs a sting to str[80]*/
    pr_str(str) ; 	// function call

    return 0;
}


void pr_str(const char *p){
    while(*p) putchar(*p++); 	// this is ok
}



// Above program is ok and compile with no error, but following will not compile. 
// Because this version attempts to alter (change to upper-case) the 'string' pointed to by 'p'.

#include<stdio.h>
#include<ctype.h>

void pr_str(const char *p);     // const pointer  parameter


int main(void){	
    char str[80];

    printf("Enter a string: "); 
    gets(str);      // inputs a sting to str[80]*/
    pr_str(str) ; 	// function call

    return 0;
}


void pr_str(const char *p){
    while(*p){ 
        *p=toupper(*p);	// this cause compile ERR
        putchar(*p++); 
    }
}




/* Example 3: When you precede a variable's type with volatile, you are telling the COMPILER 
                that the 'value' may be changed in ways not 'explicitly defined' in the program.

                For example, a variable's ADDRESS might be given to an 'interrupt service routine', and 
                    its value changed each time an interrupt occurs. 
*/ 

volatile unsigned u;

give_address_to_some_interrupt(&u);

for(;;) { 		
    // watch value of u 
    printf ("%d", u);
    . . . . . . . 
    . . . . . . . 

/* In this example, if u had not been declared as volatile, 
        the compiler could have optimized the repeated calls to printf() in such a way that 'u was not re-examined each time'. 
        The use of volatile forces the compiler to actually obtain the value of u whenever it is used. 
*/



/* Example 4: One good time to use const is when you want to embed a 'version control number' into a program. 
                By using a const variable to hold the version, you prevent it from accidentally being changed. 

                Write a short program that illustrates how this can be done. 
                    Use 6.01 as the version number. 
*/

#include <stdio.h>

const double version = 6.01;

int main(void)
(
printf(-Version '.2f-, version):
return 0;
}



/* Example 5: Write your own version of 'strcpy()' called 'mystrcpy()', which has the prototype
                                char *mystrcpy (char *to, canst char *from);
                The function returns a pointer to "to". Demonstrate your version of mystrcpy() in a program. 
*/

'include <stdio.h>
char *mystrcpy(char *to, const char *from);
int main(void)
{
    chlr 'p, str(80],

    P = mystrcpy(STR, *TESTING);
printfC-'. 'S·, P. str};
return 0:
)
char *mystrcpy(char *to. const char *from)
{
char -temp ;
temp == to;
while (*from) *to++ == -from++;
*to = '\0' ; /* null termdnator */
return temp:
)

