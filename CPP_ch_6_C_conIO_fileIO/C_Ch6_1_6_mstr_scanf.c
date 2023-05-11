/* 
	---------------    scanf() Details    ---------------
	The prototype for scanf() is:

		int scanf(char *control-string, ... );


	The "CONTROL-STRING" consists mostly of FORMAT SPECIFIERS. However, it can contain other characters. 
		The format specifiers determine how scanf() reads information into the 'variables pointed to by the arguments' that follow the 'control string'. 
			The specifiers are matched in order, from left to right, with the arguments. 
			There must be as many arguments as there are specifiers. 

		scanf() returns the number of fields assigned values. 
			If an error occurs before any assignments are made, "EOF" is returned.


	Code	Meaning						Details
	%c	Read a single character	
	%d	Read a decimal integer	
	%i	Read a decimal integer	
	%e	Read a floating-point number	
	%f	Read a floating-point number	
	%g	Read a floating-point number	
	%o	Read an octal number			used to read an unsigned integer using octal  bases
	%s	Read a string	
	%x	Read a hexadecimal number		used to read an unsigned integer using hexadecimal  bases
	%p	Read a pointer	inputs a memory address using the format determined by the host environment
	%n	Receives an integer value equal to the number of characters read so far	
		assigns the number of characters input up to the point the %n is encountered to 
		the integer variable pointed to by its matching argument,  l or h applied for long or short .

	%u	Read an unsigned integer	
	%[]	Scan for a set of characters	




	Use of   %* (no associated argument): 
		you can suppress(neglect) the assignment of a field by putting an asterisk "*" immediately after the % sign. 
			This can be very useful when inputting information that contains needless characters. 
			(eg : input password containing "-" : abc-3nh-th7). 
			
			For example, following scanf() used to assign 555 to first, discard the -, and assign 2345 to second. 
			Since the hyphen is not needed, there is no reason to assign it to anything. Hence, NO ASSOCIATED ARGUMENT is supplied.

				int first , second;
				scanf( "%d%*c%d", &first. &second);

			inputting : 555-2345, then scanf() will read as first=555 and second=2345, the "-" will be skipped.




	scanset  %[] : 
		A "SCANSET SPECIFIER" is created by putting a 'list of characters' inside square brackets, 
			for example, here is a 'scanset specifier' containing the letters 'ABC' :   %[ABC]	 //reads A,B,C from input

		When scanf() encounters a scanset, it begins reading input into the "character array" pointed to by the scanset's matching argument.  
			It will only continue reading characters as long as the 'next character is part of the scanset'. 

		As soon as a character that is not part of the scanset is found, scanf() stops reading input for this specifier and 
			moves on to any others in the control string.

		You can specify a range in a scanset using the - (hyphen), for example, this scanset specifies the characters 'A' through 'Z',
					%[A-Z]

			Technically, the use of the hyphen to specify a range is not specified by the ANSI C standard, but it is nearly universally accepted.

		Exclusion: When the scanset is very large, sometimes it is easier to specify what is "not part of a scanset", 
			To do this, precede the set with a ^ , for example, 	
			
			%[^0123456789] 		// When scanf() encounters this scanset, it will read any characters 'except' the digits 0 through 9.
*/


	Here’s an example of a scanset that accepts both the upper- and lowercase characters (but no spaces). 

char str[80];
printf("Enter letters, anything else to stop\n");
scanf("%[a-zA-Z]", str); printf(str);
Following code is slightly changed with a whitespace " " inside [] , it allows white space between characters to be read by scanf().
char edstr[80];
/*Admits space*/
printf("Enter letters with space, anything else to stop\n");
scanf("%[a-zA-Z ]", edstr); printf(edstr); //added white space inside []


	You could also specify punctuation symbols and digits inside scanf("%[a-zA-Z ]", edstr);, so that you can read virtually any type of string. 






Notes
[1]	The specifiers %d, %i, %u, %x, and %o (integer type specifiers) may be modified by the h when inputting into a short variable and by l when inputting into a long variable.

[2]	The specifiers %e. %f, and %g are equivalent. They all read floating-point numbers represented in either scientific notation or standard decimal notation .  To read a double, modify them with l. To read a long double, modify them with L.

[3]	Limitation of scanf()to read strings : You can use scanf() to read a string using the %s specifier, but when scanf() inputs a string, it stops reading that string when the first whitespace character is encountered (i.e. scanf() can read a word, not whole sentence). A whitespace character is either a space, a tab, or a newline, This means that you cannot easily use scanf() to read input like this into a string:
this is one string
Because there is a space after "this," scanf() will ,stop inputting the string at that point. This is why gets() is generally used to input strings.
[4]	Line-Buffering : As scanf() is generally implemented, it line-buffers input in the same way that getehar() often does. While. this makes little difference when inputting numbers, its lack of interactivity tends to make scanf() of limited value for other types of input.
[5]	You can specify a maximum field width for all specifiers except %c (for which a field is always one character)  and %n (to which the concept does not apply). The maximum field width is specified as an unsigned integer, and it immediately precedes the format specifier character. For example, this limits the maximum length of a string assigned to str to 3 characters:  scanf("%3s", str);
int i, j; 
printf("Enter an integer: "); scanf("%3d%d", &i, &j);
printf("%d %d", i, j);
This illustrates the maximum-field-width specifier: If 12345 is entered, i will be assigned 123, and j will have the value 45. The reason for this is that scanf() is told that i's field is only three characters long. The remainder of the input is then sent to j.

[6]	If a space appears in the control string, then scanf() will begin reading and discarding whitespace characters until the first non-whitespace character is encountered.  For example: This program lets the user enter a number followed by an operator followed by a second number, such as 12 + 4. It then performs the specified operation on the two numbers

#include<stdio.h>
int main(void){ int i, j; char op;
                printf("Enter operation: "); scanf("%d %c %d", &i, &op, &j);
                switch(op){ 	case '+': printf("%d", i+j); break;
                        	case '-': printf("%d", i-j); break;
                        	case '/': if(j) printf("%d",i/j); break;
                        	case '*': printf("%d", i*j);}
  return 0;}

Notice that the format for entering the information scanf("%d %c %d", &i, &op, &j); contains whitespace between two format specifires, this tricks admits whitespace between numbers and operation (here the white space is skipped by scanf())

[7]	If any other character appears in the control string, scanf() reads and discards all matching characters until it reads the first character that does not match that character .
#include<stdio.h>
int main(void){	int i, j;
printf("Enter a decimal number: "); scanf("%d.%d", &i, &j);
printf("left part: %d, right part: %d", i, j);
return 0;}

This program illustrates the effect of having non-whitespace characters in the control string. It allows you to enter a decimal value, but it assigns the digits to the left of the decimal point to one integer and those to the right of the decimal to another. The decimal point "." between the two %d specifiers causes the decimal point in the number to be matched and discarded.
