/* 	
	---------------    Macro substitution : #define    ---------------
	The #define directive tells the preprocessor to perform a "text substitution" throughout your entire program.

		That is, it causes "one sequence of characters" to be replaced by "another".
		The general form of the #define statement is:

			#define macro_name character_sequence

			Notice that this line does not end in a semicolon.
			There must be one or more SPACES between the "macro_name" and the "character_sequence"

	The macro name can be any valid C identifier. There is a convention of using UPPERCASE for MACRO names.  


	Preprocessor directives in general and #define in particular are not affected by C's code blocks. 
	It can be defined outside of all functions or within a function, 
		once it is defined, all code after that point may have access to it.
	
	Each preprocessor directive must appear on its own line. i.e.     #define BIG 100  #define SMALL 0   is not acceptable


	Macro substitutions are useful for two main reasons. 
		To maintain a specific value
		To maintain programs – Easy to change values

	Since a 'macro substitution' is simply a text replacement, you can use a macro name in place of a "quoted string".

*/




/* Example 1: When the identifier MAX is encountered by the preprocessor, 100 is automatically substituted.
				Keep in mind: At the time of the substitution, 100 is simply a string of characters composed of a 1 and two 0's. 
				The preprocessor DOES NOT CONVERT a numeric string into its internal binary format. This is left to the COMPILER. */
#include<stdio.h>

#define MAX 100

int main(void){	
	int i;

	for(i=0; i<MAX; i++) printf("%d ", i);
	
	return 0;
}




/* Example 2: Preprocessor directives in general and #define in particular are not affected by C's code blocks. 
	It can be defined outside of all functions or within a function, 
		once it is defined, all code after that point may have access to it. */
#include <stdio.h>

void f(void);

int main(void){
	#define LIGHTSPEED 186000

	f();

	return 0;
}

void f(void){
	printf("%ld", LIGHTSPEED);
}



/* Example 3: Since a macro substitution is simply a text replacement, you can use a macro name in place of a quoted string. */
#include <stdio.h>

#define FUN "Macro Substitutions are Fun"

int main(void){ 
	printf(FUN); 

	return 0; 
}
