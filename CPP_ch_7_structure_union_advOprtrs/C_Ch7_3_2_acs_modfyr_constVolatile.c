
5.7 Access modifiers : const and volatile (Advanced topic)
C includes two type modifiers that affect the way variables are accessed by both your program and the compiler. These modifiers are const and volatile. 

	const : If you precede a variable's type with const, you prevent that variable from being modified by your program. The variable may be given an initial value, however, through the use of an initialization when it is declared. The compiler is free to locate const variables in ROM (read-only memory) in environments that support it. (A const variable may also have its value changed by hardware dependent means.)

Example : The following short program shows how a const variable can be given an initial value and be used in the program, as long as it is not on the left side of an assignment statement .

#include <stdio.h>
int main(void) {	const int i = 10;
printf ( "%d", i); 	/* this is OK */
   return 0; }
The following program tries to assign i another value. This program will not compile. 

#include <stdio.h>
int main(void) {	const int i = 10; 
i=20; 			/* this is wrong */
printf ( "%d", i); 
   return 0; }
	The const modifier can prevent a function from modifying the object that a parameter points to. That is, when a pointer parameter is preceded by const, no statement in the function can modify the variable pointed to by that parameter.
	The most important feature of const pointer parameters is that they guarantee that many standard library functions will not modify the variables pointed to by their parameters.

Example : The following program shows how a pointer parameter can be declared as const to prevent the object it points to from being modified.

#include<stdio.h>

void pr_str(const char *p);

int main(void){	char str[80];
printf("Enter a string: "); gets(str); /*inputs a sting to str[80]*/
pr_str(str) ; 		/*function call*/
return 0;}

void pr_str(const char *p){
while(*p) putchar(*p++); 	/* this is ok */
}
This program is ok and compile with no error, but following will not compile. Because this version attempts to alter (change to upper-case) the string pointed to by p.

#include<stdio.h>
#include<ctype.h>

void pr_str(const char *p);

int main(void){	char str[80];
printf("Enter a string: "); gets(str); /*inputs a sting to str[80]*/
pr_str(str) ; 		/*function call*/
return 0;}

void pr_str(const char *p){
while(*p){ *p=toupper(*p)	/* this wil not compile */
 	     putchar(*p++); }
}

	volatile : When you precede a variable's type with volatile, you are telling the compiler that the value of the variable may be changed in ways not explicitly defined in the program. For example, a variable's address might be given to an interrupt service routine, and its value changed each time an interrupt occurs. 
volatile unsigned u;
give_address_to_some_interrupt(&u);
for(;;) { 		/* watch value of u */
printf ("%d", u);. . . . . . . 
In this example, if u had not been declared as volatile, the compiler could have optimized the repeated calls to printf() in such a way that u was not reexamined each time. The use of volatile forces the compiler to actually obtain the value of u whenever it is used.
 
