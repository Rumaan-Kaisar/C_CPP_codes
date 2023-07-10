
7.6 typedef
In C you can create a new name for an existing type (i.e. we can rename char, int, float etc) using typedef. The general form of typedef is
typedef old-name new-name;
This new name can be used to declare variables. For example., in the following program, smallint is a new name for a signed char and is used to declare i.
#include <stdio.h>
typedef signed char smallint; 	/* renaming the data-type signed char */
int main(void){	smallint i; 	/*Renamed data-type*/
for(i=0; i<10; i++)
printf("%d", i);
return 0;}
	a typedef does not cause the original name to be deactivated. For example, in the program, signed char is still a valid type. 
	you can use several typedef statements to create many different, new names for the same type.

Use of typedef
1.	The first is to create portable programs. Using a changed data-type-name instead of pre-defined data-type-name enables the opportunity to modify the variables before compile using just one statement. For example, if you know that you will be writing a program that will be executed on computers using 16-bit integers as well as on computers using 32-bit integers, and you want to ensure that certain variables are 16 bits long in both environments, you might want to use a typedef when compiling the program for the 16-bit machines as follows:
typedef int myint;
Assuming that you used myint to declare all integer values that you wanted to be 16 bits long (which can be changed later). 

Then, before compiling the code for a 32-bit computer, you can change  the typedef statement like this:
typedef short int myint; 	/* changing 32 bit to 16 bit */
This works because on computers using 32-bit integers. a short int will be 16 bits long. 
2.	The second reason you might want to use typedef is to help provide self-documenting code (meaningful or semantic programming). For example, if you are writing an inventory program, you might use this typedef statement.
typedef double subtotal;
Now, when anyone reading your program sees a variable declared as subtotal, he or she will know that it is used to hold a subtotal.

