6.2 Macro substitution : #define
The #define directive tells the preprocessor to perform a text substitution throughout your entire program. That is, it causes one sequence of characters to be replaced by another. This process is generally referred to as macro substitution. The general form of the #define statement is shown here:
#define macro-name character-sequence
Notice that this line does not end in a semicolon. Each time the macro-name is encountered in the program, the associated character-sequence is substituted for it. For example, consider this program:
#include<stdio.h>
#define MAX 100
int main(void){	int i;
for(i=O; i<MAX; i++) printf("%d", i);
return 0;}
When the identifier MAX is encountered by the preprocessor, 100 is automatically substituted. Actually the for loop to the compiler;
for(i=O; i<100; i++) printf("%d", i);
Keep in mind: At the time of the substitution, 100 is simply a string of characters composed of a 1 and two 0's. The preprocessor does not convert a numeric string into its internal binary format. This is left to the compiler.

[1]	The macro name can be any valid C identifier. But most programmers have adopted the convention of using uppercase for macro names. This makes it easy for identifying macro names in programs.

[2]	Preprocessor directives in general and #define in particular are not affected by C's code blocks. It can be defined outside of all functions or within a function, once it is defined, all code after that point may have access to it. For example, 
int main(void){ 	#define MAX 100
			int i;
for(i=O; i<MAX; i++) printf("%d", i);
return 0;}

[3]	Each preprocessor directive must appear on its own line. i.e.     #define BIG 100  #define SMALL 0   is not acceptable.

[4]	Macro substitutions are useful for two main reasons. 
( a )	First, to maintain a specific value : C library function's certain predefined values may vary between programming environments. Macro substitutions solve this problem.

( b )	Second , to maintain programs – Easy to change values :  For example, if you know that a value, such as an array size, is going to be used several places in your program, it is better to create a macro for this value. Then if you ever need to change this value, you simply change the macro definition. All references to it will be changed automatically when the program is recompiled.

[5]	Since a macro substitution is simply a text replacement, you can use a macro name in place of a quoted string. For example, the

#define FUN "Macro Substitutions are Fun"
int main(void){ printf(FUN); return 0; }
