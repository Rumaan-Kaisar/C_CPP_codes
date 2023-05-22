/* 
	---------------    scanf() Details    ---------------

	The prototype for scanf() is:

		int scanf(char *control-string, ... );
		
		Eg:
		scanf("%d.%d", &i, &j);
		Here "%d.%d" is the "CONTROL STRING" and '&i, &j'  are the varargs


	The "CONTROL-STRING" consists mostly of FORMAT SPECIFIERS. However, it can contain other characters. 
		The format specifiers determine how scanf() reads information into the 'variables pointed to by the arguments' that follow the 'control string'. 
			The specifiers are matched in order, from left to right, with the arguments. 
			There must be as many arguments as there are specifiers. 

		scanf() returns the number of fields assigned values. 
			If an error occurs before any assignments are made, "EOF" is returned.


	You can specify a "MAXIMUM FIELD WIDTH" for all specifiers except %c (one character field)  and %n (to which the concept does not apply). 
		The MAXIMUM FIELD WIDTH is specified as an "unsigned" integer, and it immediately precedes the 'format specifier character'.
		For example, this limits the maximum length of a 'STRING' assigned to str to 3 characters:  
				scanf("%3s", str);


	Limitation of scanf() to read 'strings': 
		You can use scanf() to read a string using the %s specifier, but when scanf() inputs a string, 
		It stops reading that string when the first whitespace character is encountered (i.e. scanf() can read a word, not whole sentence). 
		A whitespace character is either a 'space', a 'tab', or a 'newline'

		This is why gets() is generally used to input strings.

	If a space appears in the control string, then scanf() will begin reading and 
		discarding whitespace characters until the first non-whitespace character is encountered
			following used to read operators for arithmetic operations:
			printf("Enter operation: "); 
					scanf("%d %c %d", &i, &op, &j);


	If any other character appears in the control string, scanf() reads and discards 
		all matching characters until it reads the first character that does not match that character .
	

	Line-Buffering: 
		As scanf() is generally implemented, it line-buffers input in the same way that getehar() often does. 


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


	The specifiers %d, %i, %u, %x, and %o (integer type specifiers) may be modified by 
		the 'h' when inputting into a short variable and by 'l' when inputting into a long variable.

	The specifiers %e, %f, and %g are equivalent. They all read floating-point numbers 
		represented in either scientific notation or standard decimal notation .  
		To read a double, modify them with 'l'. To read a long double, modify them with 'L'.




	Use of   %* (no associated argument): 
		you can suppress(neglect) the assignment of a field by putting an asterisk "*" immediately after the % sign. 
			This can be very useful when inputting information that contains needless characters. 
			(eg : input password containing "-" : abc-3nh-th7). 
			
			For example, following scanf() used to assign 555 to first, discard the -, and assign 2345 to second. 
			Since the hyphen is not needed, there is no reason to assign it to anything. Hence, NO ASSOCIATED ARGUMENT is supplied.

				int first , second;
				scanf( "%d%*c%d", &first. &second);

			inputting : 555-2345, then scanf() will read as first=555 and second=2345, the "-" will be skipped.
			%*c to skip single character




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




/* Example 1: To see the effect of the %s specifier, try this program. 
				When prompted, type "this is a test" and press ENTER. You will see only "this" redisplayed on the screen. 
				This is because, when reading strings, scanf() stops when it encounters the 'first whitespace character'. */

#include <stdio.h>

int main(void){
	char str[80];

	//Enter "this is a test"
	printf("Enter a string: ");
	scanf ("%s", str);

	printf(str);

	return 0;
}




/* Example 2: Here’s an example of a "scanset" that accepts both the Uppercase and Lowercase characters (but no spaces). 
				Try entering fiew words. After you press ENTER, only the letters that you entered before 
				pressing the non-letter key (spaces and othr char) will be contained in str. */
#include <stdio.h>

int main(void){
	char str[80];

	printf("Enter letters, anything else to stop\n");
	scanf("%[a-zA-Z]", str);
	
	printf(str);

	return 0;
}




/* Example 3: Following code is slightly changed previous example with a whitespace " " inside [] , 
				it allows "WHITE SPACE" between characters to be read by scanf(). */
#include <stdio.h>

int main(void){
	char str[80];

	/*Admits space*/
	printf("Enter letters with space, anything else to stop\n");
	scanf("%[a-zA-Z ]", str);	//added WHITE SPACE inside [] 
	printf(str); 

	return 0;
}

// You could also specify punctuation symbols and digits inside scanf("%[a-zA-Z ]", edstr);, 
// so that you can read virtually any type of string. 




/* Example 4: If a space appears in the control string, then scanf() will begin reading and 
				discarding whitespace characters until the first non-whitespace character is encountered.  
				This program lets the user enter a number 'followed by an operator' followed by a second number, such as 12 + 4. 
				It then performs the specified operation on the two numbers 
				
				Notice that the format for entering the information scanf("%d %c %d", &i, &op, &j); 
					contains whitespace between two format specifires, 
					this tricks ADMITS WHITESPACE between numbers and operation 
					(here the white space is skipped by scanf()). */
#include<stdio.h>

int main(void){ 
	int i, j; 
	char op;

	printf("Enter operation: "); 
	scanf("%d %c %d", &i, &op, &j);

	switch(op){ 	
		case '+': printf("%d", i+j); break;
		case '-': printf("%d", i-j); break;
		case '/': if(j) printf("%d",i/j); break;
		case '*': printf("%d", i*j);
		}

	return 0;
}

	


/* Example 5: following illustrates the maximum-field-width specifier: 
				If 12345 is entered, i will be assigned 123, and j will have the value 45. 
				The reason for this is that scanf() is told that i's field is only three characters long. 
				The remainder of the input is then sent to j. */
#include <stdio.h>

int main(void){
	int i, j; 

	printf("Enter an integer: ");
	scanf("%3d%d", &i, &j);
	printf("%d %d", i, j);

	return 0;
}




/* Examlpe 6: If any other character appears in the control string, scanf() reads and discards 
				all matching characters until it reads the first character that does not match that character . */

#include<stdio.h>

int main(void){	
	int i, j;

	printf("Enter a decimal number: "); 
	scanf("%d.%d", &i, &j);
	printf("left part: %d, right part: %d", i, j);

	return 0;
}

/* This program illustrates the effect of having non-whitespace characters in the control string. 

It allows you to enter a decimal value, but it assigns the digits to the left of the decimal point to one integer and 
	those to the right of the decimal to another. 

The decimal point "." between the two %d specifiers causes the decimal point in the number to be matched and discarded. */




/* Example 7: Write a program that prompts for your name and then inputs your first, middle, and last names. 
				Have the program read  no more than 20 characters for each part of your name. 
				Finally, have the program redisplay your name. */
#include <stdio.h>

int main(void){
	char first[21], middle[21], last[21];

	printf("Enter your entire name: ");
	scanf("%20s%20s%20s", first, middle, last);
	printf("%s %s %s", first, middle, last);

	return 0;
}





/* Example 8: Write a program that reads a floating-point number as a string using a 'scanset'. */
#include <stdio.h>
int main(void){
	char num[80];

	printf("Enter a floating point number: ");
	scanf("%[0-9.]", num);
	printf(num);

	return 0;
}




/* Example 9: Is this fragment correct? If not why not? */
char ch;
scanf("%2c", &ch);
// No, a character can only have a maximum field length of 1.




/* Example 10: Write a program that inputs 
					a string, 
					a double, and 
					an integer.
				After these items have been read, have the program display how many characters were input. 
				(Hint: use the %n specifier.) */
#include <stdio.h>

int main(void){
	char str[80];
	double d;
	int i, num;

	printf("Enter a string, a double, and an integer: ");
	scanf("%s%lf%d%n", str, &d, &i, &num);
	printf("Number of characters read: %d", num);

	return 0;
}




/* Example 11: Write a program that converts a "hexadecimal" number entered
				by the user into its corresponding "decimal" and octal equivalents. */
#include <stdio.h>

int main(void){
	unsigned u;

	printf("Enter hexadecimal number: ");
	scanf("%x", &u);
	printf("Decimal equivalent: %u", u);

	return 0;
}




/* Example 12: What is a scanset? */
A scanset is a set of characters that scanf() matches with input. As long as the characters being read are part of the scanset, 
scanf() continues to input them into the array pointed to by the scansets corresponding argument.


	

/* Example 13: Write a program, using scanf(), that inputs your first name, birth date (using the format mm/dd/yy), 
                and telephone number. Redisplay the information on the screen to verify that it was input correctly. */
#include <stdio.h>
int main(void){
    char name[80], date[80], phone[80];

    printf("Enter first name, birthdate ");
    printf("and phone number:\n");

    scanf("%s%8s%8s", name, date, phone);
    printf("%s %s %s", name, date, phone);

    return 0;
}




/* Example 14: Write a program that allows you to enter the batting averages for the players on a little league team. 
                    (Assume there are exactly 9 players.) 
                Have the user enter the 'first name' and 'batting average' of each player. 
                Use a two-dimensional character array to hold the names and a one-dimensional double array to hold the batting averages. 
                Once all the names are entered, have the program report the name and average of the players with the highest and lowest averages. 
                Also, have the program display the team average. 
*/
#include <stdio.h>

int main(void){
    char name[9][80];
    double b_avg[9];
    int i, h, l;
    double high, low, team_avg;

    for(i=0; i<9; i++) {
        printf("Entar name %d: ", i+1);
        scanf("%s", name[i]);

        printf("Enter batting average: ");
        scanf("%lf", &b_avg[i]);

        printf ("\n");
    }

    high = 0.0,
    low = 1000.0,
    team_avg = 0.0;

    for(i=0; i<9; i++){
        if(b_avg[i]>high){
            h = i;
            high = b_avg[i];
        }
        if(b_avg[i]<low){
            l = i;
            low = b_avg[i];
        }
        team_avg = team_avg + b_avg[i];
    }

    printf("The high is %s %f\n", name[h], b_avg[h]);
    printf("The low is %s %f\n", name[l], b_avg[l]);
    printf("The team average is %f", team_avg/9.0);

    return 0;
}




/* Example 15: Write a program that inputs a double, a character, and a string not longer than 20 characters. 
                Redisplay the values to confirm that they were input correctly. */

#include <stdio.h>

int main(void){
    double d;
    char ch;
    char str[80];

    printf("Enter a double, a character, and a string\n");
    scanf("%lf%c%20s", &d, &ch, str);
    printf("%f %c %s", d, ch, str);

    return 0;
}




/* Example 16: Write a program that reads and discards leading digits and then reads a string. 
                (Hint: Use a scanset to read past any leading digits.) */

#include <stdio.h>

int main(void){
    char str[80];

    printf("Enter leading digits followed by a string\n");
    scanf("%*[0-9]%s", str);
    printf("%s", str);

    return 0;
}
// input: 908tuhkfugh90-97rve
// output: tuhkfugh90-97rve




