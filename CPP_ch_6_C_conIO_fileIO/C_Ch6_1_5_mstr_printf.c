6.6 printf( ) : Details
The printf() function has this prototype:
int printf(char *control-string, ... );
	The periods indicate a variable-length argument list. The printf() function returns the number of characters output. If an error occurs, it returns a negative number. But if the console is not working, the computer is probably not functional anyway.

	The control string may contain two types of items: characters, to be output and format specifiers.  The most used format specifiers are %c, %d, %f, %s, %u  and %p. The printf() format specifires are shown in the following table
Code	Format	Details
%c	Character	
%d	Signed decimal integers	
%i	Signed decimal integers	The %i command is the same as %d and is redundant.
%e	Scientific notation (lowercase 'e')	Display float using  scientific notation in  lowercase. Use L  for  long double. 
%E	Scientific notation (uppercase 'E')	Display float using  scientific notation in  uppercase. Use L  for  long double. 
%f	Decimal floating point	
%g	Uses %e or %f, whichever is shorter (lower case)	Use lowercase scientific/ normal whichever is shorter.  Use L  for  long double.
%G	Uses %E or %f, whichever is shorter (upper case)	Use uppercase scientific/normal whichever is shorter.  Use L  for  long double.
%o	Unsigned octal	display an integer in octal format.
%s	String of characters	
%u	Unsigned decimal integers	
%x	Unsigned hexadecimal (lowercase letters)	display Hexadecimal letters 'a' through 'f' in lowercase.
%X	Unsigned hexadecimal (uppercase letters)	display Hexadecimal letters 'a' through 'f' in uppercase.
%p	Displays a pointer	
%n	The associated argument is a pointer to an integer into which the number of characters written so far is placed.	The argument that matches the %n specifier must be a pointer to an integer. When the %n is encountered, printf() assigns the integer pointed to by the associated argument the number of characters output so far.
%%	Prints a % sign	Since all format specifires begins with percentage, so use %%

Example 1 : This program prints the value 90 four different way: decimal, octal, lowercase hexadecimal, and uppercase hexadecimal. It also prints a floating-point number using scientific notation with a lowercase 'e' and an uppercase 'E' .
#include<stdio.h>
int main(void){
printf ("Decimal = %d, Octal = %o, Low-Hex = %x, Up-Hex = %X\n" , 90, 90, 90, 90);
printf("Low-sci = %e, Up-sci = %E\n", 99.231, 99.231); return 0;}
The output from this program is shown here:
90 132 5a 5A
9.92310e+01 9.92310E+01

6.6.1 General form of format specifiers , minimum field width and precision specefier : 
Format specifiers : All format specifiers begin with %. A format specifier, also referred to as a format code , determines how its matching argument will be displayed. Format specifiers and their arguments are matched from left to right, and there must be as many arguments as there are specifiers.

	Minimum field-width : All specifiers "excluding %%, %p, %c" may have a minimum field-width specifier and/or a precision specifier associated with them. Both of these are integer quantities. If the item to output is shorter than the specified minimum field width, the output is padded with spaces, so that it equals the minimum width. However, if the output is longer than the minimum, output is nor truncated. The minimum-field-width specifier is placed after the % sign and before the format specifier. Eg : %10f tells printf() to output a double value of width 10.

The minimum-field-width specifier is especially useful for creating tables that contain columns of numbers that must line up. For example, this program prints 1000 random numbers in three columns. 
#include<stdio.h>
#include<stdlib.h>
int main(void){int i;
for(i=0; i<100; i++)
printf("%10d %10d %10d\n", rand() , rand(), rand());
return 0;}

	Precision specifier : The precision specifier follows the minimum-field-width specifier. The two are separated by a period (i.e. "."). The precision specifier affects different types of format specifiers differently. If it is applied to the %d, %i, %o, %u or %x specifiers, it determines how many digits are to be shown. Leading zeros are added if needed. When applied to %f, %e, or %E, it determines how many digits will be displayed after the decimal point. For %g or %G, it determines the number of significant digits. When applied to the %s, it specifies a maximum field width (the maximum field specifire for scanf() and printf() are different . "." is not used for scanf()). If a string is longer than the maximum-field-width specifier, it will be truncated.

By default, all numeric output is right justified. To left justify output , put a minus sign directly after the % sign. The general form of a format specifier is shown here. Optional items are shown between brackets,

%[-][minimum-field-width][.][precision] format-specifier

for example , %15.2f  tells printf() to output a double value using a field width of 15, with 2 digits after the decimal point.

Note
[1]	If you don't want to specify a minimum field width, you can still specify the precision. Simply put a period in front of the precision value.
[2]	The rand() function with STDLIB.H : Use C's standard library functions, rand(), to generate the random numbers. The rand() function returns a random integer value each time it is called. It uses the header STDLIB.H.
