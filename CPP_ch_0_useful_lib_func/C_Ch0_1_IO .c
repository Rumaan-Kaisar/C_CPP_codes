
    -------------------    Standard CONSOLE i/o    -------------------
    -------------------    getchar(), putchar() & EOF    -------------------
    EOF: 
        when error occurs while reading/writing an input/output in the case of int returning type function, 
        a negative value is returned (usually -1) it is called macro EOF.

        EOF stands for end-of-file.  
        EOF is an integer value, to allow it to be returne.



    getchar, putchar:
        These two perform "character" INPUT and OUTPUT, respectively;

            int getchar(void);   // Return type is int
            int putchar(int ch); // Return type is int and also parameter type is int

        They both use the header file <STDIO.H>. 

        int getchar(void)
            Returns the next character typed on the keyboard. This character is read as an unsigned char convened to an int.  
            Even though getchar() is declared as returning an int, high-order byte(s) of the integer is discarded when assigned to a char variable
            The reason that getchar() returns an integer is to return the macro EOF, which is a negative integer (usually -1).
            Many compilers implement getchar() in a line-buffered manner, which makes its use limited in an interactive environment.
            
            Line Buffering : getchar() is generally implemented using line buffering. 


        int putchar(int ch) 
            putchar() outputs a "single character" to the screen . 
            Although its parameter is declared to be of type int, this value is converted into an unsigned char by the function. 
                Thus, only the low-order byte of ch is actually displayed. 
            If the output operation is successful, putchar() returns the character written. If an output error occurs, EOF is returned. 
            
            putchar() is faster and more efficient than printf()



/* Example 1: Line Buffering : getchar() is generally implemented using line buffering.
                When input is line buffered, no characters are actually passed back to the calling Program until the user presses ENTER.
                The following program demonstrates this:

                Instead of printing a period between each character,
                what you will see on the screen is all the letters you typed before pressing ENTER, followed by a string of periods.*/
#include <stdio.h>
#include <conio.h>

int main(void){
    char ch, s_ch;

    do {
        ch = getchar() ;
        putchar('.') ;
    } while(ch != '\n');

    
    // do {s_ch = getche() ; printf(".") ;} while(s_ch != '\r');
    
    return 0;
}


/* Example 3: The following program illustrates the fact that you can use C's backslash character constants '\n' with putchar(). 
                This program displays
                A
                B
                on the screen  */
#include <stdio.h>

int main(void){
    putchar('A');
    putchar('\n');
    putchar('B');

    return 0;
}





/*     
    ----------------    NON-STANDARD CONSOLE FUNCTIONS    ----------------
            getche()
            getch()
            kbhit()
            cprintf()
            cscanf()



    getche() and getch():
        int getche(void); 	// Return type is int
        int getch(void); 	// Return type is int

        Both functions use the header file <CONIO.H> and returns int.

        getche() waits until the keystroke. 
        After the keystroke getche() echoes(shows) it to the screen. It immediately returns the character.
            as an unsigned char and elevated to int. However, your routines (functions) can simply assign this value to a char value. 

        The getch() function is the same as getche(), except that the keystroke is not echoed(not showed) to the screen.



    kbhit():
        int kbhit(void); 	// Return type is int

        kbhit()  requires CONIO.H. 
            It is to detect keypress. When a key is pressed, kbhit() returns true (nonzero), but DOES NOT READ the character.
            If no keystroke is pending, khhit( ) returns false (zero).


    Problems of mixing standard I/O and non-standared I/O: 
        non-standard i/O functions such as getche() are not compatible with the standard i/O functions such as printf() or scanf().



    cprintf() and cscanf():
        These are non-standard versions of printf() and scanf(). Both cprintf() and  cscanf() use the CONIO.H.
        The cprintf() function works like printf() except that 
            it does not translate the newline character (\n) into the CARRIAGE RETURN. Use CARRIAGE RETURN (\r) explicitly.

        The cscanf() function works like the scanf() function.

        We can mix cprintf() and cscanf() with other non standared I/O functions like getche() or getch()
*/


/* Example 5: What is the difference between getchar() and getche() */
/* 
    The getchar() function is defined by the "ANSI standard" and is used to input characters from the keyboard. 
        However, in most implementations, it uses 'line-buffered I/O', which makes it impractical for interactive use. 

    The getche() function is "not defined by the ANSI standard", but it is quite common and is
        essentially an interactive version of getchar( ). 
*/






/* Example 1: The getch() function lets you take greater control of the screen because
                you can determine what is displayed each time a key is struck.
                For example, this program reads characters until a 'q' is typed.
                All characters are displayed in uppercase using the cprintf() function. */
#include <stdio.h>
#include <conio.h>
#include <ctype.h>

int main(void) {
    char ch;

    do{
        ch = getch();
        // cprintf("%c", toupper(ch));
        printf("%c", toupper(ch));
        } while(ch != 'q');
    return 0;
}



// strings


/*     
    ---------------    String IO    ---------------
                gets()
                puts()
    Prototypes:
        char *gets(char *str); // "pointer-function" returns char type & char type "pointer-parameter"
        int puts(char *str);   // " function" returns int type & char type "pointer-parameter"

        Both use STDIO.H. 
        Both do not perform bound checking (checking the size) before storing the string into the character array.



    puts():
    outputs the string pointed to by 'str' to the screen. 
    It automatically appends a carriage return. 
        Example : puts("one"); puts("two") ; puts("three"); outputs the words 'one', 'two', and 'three' on three separate lines.
    If successful, puts() returns a "non-negative value". 
    If an error occurs, EOF is returned.

    puts() is much smaller and faster than printf()



    gets():
        gets() reads characters until a CARRIAGE RETURN is read. 
        It stores the 'characters' in the array pointed to by "str". 
        The "CARRIAGE RETURN" is not added to the string. Instead, it is CONVERTED into the "NULL TERMINATOR". 
        If successful,  gets() returns a "pointer" to the "start of str". 
        If an error occurs, a 'null pointer' is returned.

    Even though gets() returns a pointer to the 'start of the string', it still must be called with a "POINTER TO AN ACTUAL ARRAY".

        For example, the following is wrong:
        char *p;
        p = gets(p); 	 // wrong!!!
        Here, "there is no ARRAY defined" into which gets() can put the string. This will result in a program failure. 
*/




/* Example 1: This program shows how you can use the return value of gets() to access the string holding the input information.
                Notice that this program also confirms that no error has occurred before attempting to use the string. */
#include <stdio.h>
int main(void){
    char *p, str[80];

    printf("Enter a string: ");

    p = gets(str);  // Notice "POINTER TO AN ACTUAL ARRAY"

    // if not null
    if(p) printf("%s %s", p, str);

    return 0;
}



/* Example 3: Compile the program shown in Example 2, above. Note the size
                of the compiled code. Next, convert it so that it uses puts(), instead of printf( ).
                You will find that the printf() version is several byte, larger. */
#include <stdio.h>

int main(void){
    char str[80];

    puts("Enter a string: ");

    // if not null
    if(gets(str)) puts(str);

    return 0;
}




/* 
    ------------------    printf() : Details    ------------------
    The printf() function has this prototype:

        int printf(char *control-string, ... );

        The periods '...' indicate a VARIABLE-LENGTH ARGUMENT list. 
        printf() returns the number of characters output. 
        If an error occurs, it returns a negative number.



    The 'control string' may contain two types of items: 
        characters, to be output and 
        format specifiers.  



    Format specifiers
        The most used format specifiers are %c, %d, %f, %s, %u  and %p. 
        The printf() format specifires are shown in the following table

        Code	Format	                                        Details
        %c	Character	
        %d	Signed decimal integers	
        %i	Signed decimal integers	                            The %i command is the same as %d and is redundant.
        %e	Scientific notation (lowercase 'e')	                Display float using  scientific notation in  lowercase. Use L  for  long double. 
        %E	Scientific notation (uppercase 'E')	                Display float using  scientific notation in  uppercase. Use L  for  long double. 
        %f	Decimal floating point	
        %g	Uses %e or %f, whichever is shorter (lower case)	Use lowercase scientific/ normal whichever is shorter.  Use L  for  long double.
        %G	Uses %E or %f, whichever is shorter (upper case)	Use uppercase scientific/normal whichever is shorter.  Use L  for  long double.
        %o	Unsigned octal	display an integer in octal format.
        %s	String of characters	
        %u	Unsigned decimal integers	
        %x	Unsigned hexadecimal (lowercase letters)	        display Hexadecimal letters 'a' through 'f' in lowercase.
        %X	Unsigned hexadecimal (uppercase letters)	        display Hexadecimal letters 'a' through 'f' in uppercase.
        %p	Displays a pointer	

        %n	The associated argument is a pointer to an integer into which the number of characters written so far is placed.	
            The argument that matches the %n specifier must be a pointer to an integer. 
            When the %n is encountered, printf() assigns the integer pointed to by the associated argument the number of characters output so far.

        %%	Prints a % sign	Since all format specifires begins with percentage, so use %%




    ------------------    General form     ------------------
    ------------------ format specifiers   ------------------
    ------------------ minimum field width ------------------
    ------------------ precision specefier ------------------

    Format specifiers : 
        Begin with %. 
        A format-specifier/format-code , determines how its matching argument will be displayed. 
        Format specifiers and their arguments are matched from left to right,
        there must be as many ARGUMENTS as there are SPECIFIERS.


    Minimum field-width : 
        All specifiers "excluding %%, %p, %c" may have a MINIMUM FIELD-WIDTH specifier and/or a PRECISION SPECIFIER associated with them. 
        Both of these are integer quantities. 
        
        If the item to output is 'shorter' than the specified minimum field width, the output is 'padded with spaces' 
        If the output is 'longer' than the minimum, output is "not truncated". 
        The minimum-field-width specifier is placed "after the %" sign and "before the format specifier".
        
        Eg : %10f tells printf() to output a double value of width 10.


    Precision specifier : 
        The 'precision specifier' follows the 'minimum-field-width specifier'. 
        The two are separated by a period (i.e. "."). 
        
        The precision specifier affects different types of format specifiers differently. 
            If it is applied to the %d, %i, %o, %u or %x specifiers, it determines how many digits are to be shown. Leading zeros are added if needed. 
            When applied to %f, %e, or %E, it determines how many digits will be displayed after the decimal point. 
            For %g or %G, it determines the number of significant digits. 
            When applied to the %s, it specifies a maximum field width 
                (the maximum field specifire for scanf() and printf() are different . "." is not used for scanf()). 
                If a string is longer than the maximum-field-width specifier, it will be truncated.

        If you don't want to specify a 'minimum field width', you can still 'specify the precision'. Simply put a 'period' in front of the precision value.

    Left/Right justify:
        By default, all numeric output is right justified. 
        To left justify output , put a "MINUS SIGN" directly after the % sign. 




    ------------------    GENERAL FORM OF A FORMAT SPECIFIER    ------------------
    GENERAL FORM OF A FORMAT SPECIFIER is shown here. Optional items are shown between brackets,

            %[-][minimum-field-width][.][precision] format-specifier

            for example , %15.2f  tells printf() to output a double value using a field width of 15, with 2 digits after the decimal point.




    rand():
        uses STDLIB.H
        to generate the random numbers.  
        rand() returns a random integer value each time it is called.

*/

/* 
	---------------    scanf() Details    ---------------

	The prototype for scanf() is:

		int scanf(char *control-string, ... );
		
		Eg:
		scanf("%d.%d", &i, &j);
		Here "%d.%d" is the "CONTROL STRING" and '&i, &j'  are the varargs
  
		scanf() returns the number of fields assigned values. 
			If an error occurs before any assignments are made, "EOF" is returned.


	The "CONTROL-STRING" consists mostly of FORMAT SPECIFIERS. However, it can contain other characters. 
		The format specifiers determine how scanf() reads information into the 'variables pointed to by the arguments' that follow the 'control string'. 
			The specifiers are matched in order, from left to right, with the arguments. 
			There must be as many arguments as there are specifiers. 

		The control string defines the expected input format and helps `scanf` parse the input correctly.
			Here are some commonly used control characters in the `scanf` control string:

			- Space character `' '`: Skips over any whitespace characters (spaces, tabs, newlines) in the input stream.
			- Asterisk character `'*'`: Suppresses assignment. The corresponding input value is read but not stored in a variable.
			- Ampersand character `'&'`: Used to pass the address of a variable to `scanf` for assignment.
			- Square brackets `'[]'`: Specifies a set of characters that are valid for input matching. For example, `[abc]` matches 'a', 'b', or 'c' in the input.
			- Dash character `'-'` (within square brackets): Indicates a range of characters in the set. For example, `[a-z]` matches any lowercase letter.
			- Caret character `'^'` (as the first character within square brackets): Inverts the character set. For example, `[^0-9]` matches any character that is not a digit.
			- Percent character `'%'`: Matches a literal percent character in the input.

		Here's an example that demonstrates the usage of control characters within the `scanf` control string:
		
				int num1, num2;
				char name[20];
				
				scanf("%d %*f", &num1);           // Reads an integer and discards a floating-point number
				scanf(" %d", &num2);              // Reads an integer, skips leading whitespace
				scanf("%20[a-zA-Z ]", name);      // Reads up to 20 characters (including letters and spaces)


			In the example above, the control string `"%d %*f"` reads an integer and discards a floating-point number. 
				The space character before `%d` consumes any whitespace left in the input buffer. 
				The `*` before `%f` suppresses assignment, so the value is read but not stored in a variable.
			
			The control string `" %d"` reads an integer and skips leading whitespace using the space character before `%d`.
			
			The control string `"%20[a-zA-Z ]"` reads up to 20 characters, including letters (both uppercase and lowercase) and spaces. 
				The square brackets specify the valid character set for input matching.
			
			These are just a few examples of control characters used in the `scanf` control string. 
				You can combine them and use them according to your specific input requirements.




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



	------------------    Space usage    ------------------
	Use white space between "format-specifier" as '%lf %c' to consume any whitespace or newline character left in the input buffer.
	
			float num;
			char ch;
			scanf("%f", &num);
			scanf(" %c", &ch);    // Notice the space before %c to consume any whitespace or newline character left in the input buffer.
*/




// ------------------    scanf with special character    ------------------
// notice the use of ':' after %d and space ' '  before %c
	// if ':' is not used a space need to add before all format-specifier as below
		// printf("Enter an integer: ");
		// scanf("%d", &s.i);		// notice ':'  after %d
	
		// printf("Enter a character: ");
		// scanf(" %c", &s.ch);	// notice ' ' space
	
		// printf("Enter a floating point number: ");
		// scanf(" %lf", &s.d);	// notice ' ' space
	
		// printf("Enter a string: ");
		// scanf(" %s", s.str); 	// notice ' ' space

// in following example stucture is used





// ----------    file IO    ----------


/* 
    ----------------------    File Access & Modify    ----------------------

                File access: 
                    using fopen(), fclose() and 

                File read/write:
                    using fgetc(), fputc() 



    ----------------------    OPEN a File    ----------------------
    fopen():
        Opening a file: To open a file and associate it with a stream, use fopen() it uses  <STDIO.H>. Its prototype:

                FILE *fopen(char *fname, char *mode); 

                    Here "FILE" is a Structure (data-type). It is defined in STDIO.H
                        It holds various information about the file, such as size, current location, access modes. 
                        It essentially identifies the file. (A structure is a group of variables accessed under one name.)

        Generally we use the following form 

                FILE *file_pointer;
                file_pointer = fopen("file_name", "mode");

        IN the prototype, the name of the file to open is pointed to by "fname". It must be a valid file name, as defined by the operating system. 
        The string pointed to by "mode" determines how the file may be accessed. 


        If the open operation is successful, fopen() returns a valid file pointer.
            fopen() returns a pointer to the structure associated with the file by the open process. 
            This pointer will be used with all other functions that operate on the file. 

        If the fopen() function fails, it returns a null pointer.



    ----------------------    Always check the NULL pointer    ----------------------
        It is very important to ensure that a valid file pointer has been returned. 
        Use a condition to make sure that it is not NULL. 
        
    The proper way to open a file called "myfile" for text input :

            FILE *fp;
            if( (fp = fopen("myfile", "r") ) == NULL){ 
                printf("Error opening file.\n");
                exit(1); // or substitute your own error handler 
            }

    Here not only the "file error checking " happening inside the condition of "if" statement but also file is opened (if it exists) simultaneously. 
    It is actually equivalent to

            FILE *fp;
            fp=fopen("myfile", "r"); // file opening
            if(fp===NULL){      // file error checkin
                printf("file error\n");
                exit(1);        //  less effect of exit() : file error occurs before the conditional statement
            }

            There is no point of using exit(), after the file error occurred.
            There is no need for a separate comparison step because the assignment and the comparison can be performed at the same time within the if .




    ----------------------    Why use fopen() inside an if    ----------------------
        In the later case there is no point of using exit(), after the file error occurred.
        
        To prevent error of file opening if the file doesn't exist, the fopen() should occur inside the  "if" statement. 
            The program will stop if the file doesn't exist using exit(1) against the "NULL" condition. 
            And no error occurs during file closing (fclose()) or any crash. 

    Once the file is opened it never close until "fclose()" appeared to corresponding 'file pointer'.

    The point of using exit() is that: fclose() creates system error if its pointer argument is invalid on a null-pointer.




    ----------------------    CLOSING a File    ----------------------

    Closing a file : 
        To close a file and disassociate it with a stream, use fclose() it uses  STDIO.H. Its prototype is shown here:

                int fclose(FILE *fp);

        The fclose() function closes the file associated with "fp", which 
            must be a "valid file pointer" previously obtained using fopen(), and disassociates the stream from the file. 
            
        The fclose() function returns zero if successful. If an error occurs, EOF is returned.


        Be carefull with using fclose() : 
            NEVER call fclose() with an invalid argument. Doing so will "DAMAGE THE FILE SYSTEM" and possibly cause irretrievable "DATA LOSS".
            Invalid arguments means : you cannot use fclose() with "NULL OR EMPTY FILE POINTER" or invalid-error causing file pointer 
            NEVER use fclose before fopen with corresponding file.





    ----------------------    ANSI C standard values for mode are shown in Table.    ----------------------

                "r"     Open a text file for 'reading'	
                "r+"    Open a text file for 'read/write'
                "w"     Create a text file for 'writing'	
                "w+"	Create a text file for 'read/write'
                "a"     Append(means : edit/add) to a text file	
                "a+"	Append /create a text file for 'read/write'

                "rb"	Open a binary file for reading	
                "r+b" or "rb+"	Open a binary file for read/write. Also can use "rb+"

                "wb"	Create a binary file for writing	
                "w+b" or "wb+"	Create a binary file for read/write. Also can use "wb+"

                "ab"	Append to a binary file	
                "a+b" or "ab+"	Append/create a binary file for read/write. Also can use "ab+"


    Although most of the file modes are self-explanatory, a few comments are in order :
    [1]	"r": when opening a file for 'read-only' operations, the FILE DOES NOT EXIST, fopen() will "fail" and NULL-pointer will return.

    [2]	"a": When opening a file using append mode, if the FILE DOES NOT EXIST, it will be "created". 
                Further, append all new data written to the file, and will be written to the EOF. 
                The original contents will remain unchanged. 
            SAFE to use.

    [3]	"w": If, when a file is opened for writing, the FILE DOES NOT EXIST, it will be created. 
                If it does exist, the contents of the ORIGINAL FILE WILL BE DESTROYED and a new file created.
            Unsafe.

    [4]	"r+": It is similar to "r", "r+" will not create a file if it does not exist. 
                It can both read-write.

    [5]	"a+": It is similar to "a", moreover we can read with this mode. 
                IT can both read-append. 

    [6]	"w+": similar to "w". It can both read-write. Seems like "r+" & "w+" are same , but there are few differences. 
                Difference between "r+" & "w+": "r+" will not create a file if it does not exist; however, "w+" will. 
                Further, if the file already exists, opening it with "w+" destroys its contents (unsafe); opening it with "r+" does not (safe).


    Note: 
        For GENERAL PURPOSE use only "r+" and "a+" for 'read/write/append' but be careful using "w"/"w+".




    ----------------------    Flushing the buffer    ----------------------

        In order to improve efficiency, most file system implementations write data to disk one sector at a time.
            Therefore, data is buffered until it is physically written to disk. 
            When you call fclose(), it automatically writes any information remaining in a "partially full buffer" to disk. 




    ----------------------    fgetc, fputc : file Read/Write    ----------------------

    Reading and Writing from/to a files : 
    Once a file has been "opened", depending upon its "mode", you may read and/or write bytes (or characters) using these two functions:

                int fgetc(FILE *fp);
                int fputc(int ch, FILE *fp);


    fgetc() : 
        The fgetc() function "reads the NEXT byte" from the file described by "fp" as an "unsigned char" and returns it as an "integer". 
                (The character is returned in the low-order byte.) 
        If an error occurs, fgetc() returns EOF (int type EOF=-1).  
        fgetc() also returns EOF (i.e -1) when the "END OF THE FILE" is reached. 
        
        Although fgetc() returns 'integer', your can assign it to a "char" since the 'low-order byte' contains the character read from the file.



    fputc() : 
        The fputc() function 'writes' the byte contained in the "low-order byte" of 'ch' to the file associated with 'fp' as an "unsigned char". 
            Although ch is defined as an int, you may cal1 it using a char, which is the common procedure. 
        
        The fputc() returns the character written if successful or EOF if an error occurs.



    Historical note:
        The traditional names for fgetc() and fputc() are getc() and putc(). 
        The ANSI C standard still defines these names, and they are essential1y interchangeable with fgetc() and fputc().
        All other ANSI 'file system function names' begin with "f": so "f" was added to getc() and putc().         
*/


/* Example 1.1:  writing and reading a file. 
                This program demonstrates the four file-system functions.
                    First, it opens a file called MYFILE for output. 
                    Next, it writes the string "OMG!! Whatz goin on?" to the file. 
                    Then, it closes the file and 
                    reopens it for read operations. 
                    Finally, it displays the contents of the file on the screen and 
                    closes the file.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char str[80]="OMG!! Whatz goin on?";

    FILE *f_point;
    char *p;
    int i;

    // open the file for output, w - creartes a file
    if((f_point=fopen("myfile", "w"))==NULL){
        printf("File-Error\n"); 
        exit(1);
    }

    // write str into the file/disc
    p = str;
    while(*p){
        if((fputc(*p, f_point)==EOF)){
            printf("Write-Error\n"); 
            exit(1);
        }
    	p++; 
    }

    // closing the file after writing
    fclose(f_point);


    // Open the file for the input
    if((f_point=fopen("myfile", "r"))==NULL){
        printf("Opening-Error"); 
        exit(1);
    }

    // read back the file
    for(;;){
        i=fgetc(f_point);
        if(i==EOF) break;
        putchar(i);
        }
    fclose(f_point); // close the file aftre done reading

    return 0;
}

/* 
    Notes:
        while(*p){if((fputc(*p, f_point)==EOF)){printf("Write-Error\n"); exit(1);} p++; } 
        
        can be written as follows: using "p++" inside fputc()
            while(*p) if((fputc(*p++, f_point)==EOF)){printf("Write-Error\n"); exit(1);} 



    In this version, when reading from the file, the return value of fgetc() is assigned to an 'integer' variable called 'i'
        for(;;){i=fgetc(f_point); if(i==EOF) break; putchar(i);}



    For most compilers, you can simply assign the value returned by fgetc() to a char and still check for EOF: as following
        Char ch;
        for(;;){ch=fgetc(f_point); if(ch==EOF) break; putchar(i);}

        when a char is being compared to an int (the EOF , which is -1), the "char" is automatically ELEVATED to  "int"



    There is no need for a separate comparison step because the "assignment" and the "comparison" can be performed at the same time within the "if"
        for(;;) { if((ch = fgetc(f_point)) == EOF) break; putchar(ch); }

    Don't let the statement if((ch = fgetc(f_point)) == EOF) fool you.
        First, inside the if, the return value of 'fgetc()' is assigned to "ch". As you may recall, the assignment operation in C is an expression. 
        The entire value of (ch = fgetc(fp)) is equal to the return value of fgetc(). Therefore, it is this integer value that is tested against EOF.

        The fragment 

            for(;;) { if((ch = fgetc(f_point)) == EOF) break; putchar(ch); } 

            written by a "PROFESSIONAL C PROGRAMMER" as follows:

                while((ch = fgetc(f_point)) != EOF) putchar(ch);

        each character is read, assigned to ch, and tested against EOF, all within the expression of the "while" loop. 
*/







/* 
    ---------------    End of file [EOF]    ---------------
    End of file [EOF] feof() And file error checking ferror()


    fgetc() returns EOF either
    [1]	 an error has occurred 
    [2]	or the end of the file has been reached

    How do you know which event has taken place? 
        Further if you are operating on a binary file, all values are valid. It is possible that a byte will have the same value (when elevated to an int) as EOF.
            So how do you know if valid data has been returned or EOF reached?


    feof() and ferror(), are the solution:

            int feof(FILE *fp);
            int ferror(FILE *fp);



    feof(): 
        feof() returns 'nonzero' if the file associated with fp has reached the "EOF [literally End-Of-File]". 
        Otherwise it returns zero. (i.e 0 for error EOF)
        This function works for both binary files and text files. 


    ferror(): 
        ferror() returns 'nonzero' if the file associated with fp has an "ERROR". 
        Otherwise, it returns zero (for no ERR).

        Keep in mind that ferror() only reports the status of the file system relative to the "last file access". 
            Therefore, you must call it "after each file" operation.
*/





/* 
    --------------------    String/TEXT I/O in a File    --------------------

        String I/O in a File with fputs() & fgets(). 

        Text I/O with fprintf() & fscanf()




    --------------------    String I/O using fputs() and fgets()    --------------------

    fputs() and fgets()
        Writes a string to and read a string from a file, respectively. Their prototypes are

            int fputs(char *str, FILE *fp);     // writes
            char *fgets(char *str, int num, FILE *fp);      // reads


        fputs() 
            'fputs()' writes the string pointed to by "str"  to the file associated with "fp". 
                EOF returned if an error occurs and a 
                non-negative value returned if successful

            The 'null' that terminates 'str' is not written. 
            unlike its related function puts() it does not automatically append a carriage return, linefeed pair. 
                Example : 
                    fputs(str_1, f_point);


        fgets()
            'fgets()' reads characters from the file associated with "fp" into the string pointed to by "str"
                    until "num-1" (one less than the string length number) characters have been read, 
                    or a newline character is encountered, 
                    or the end of the file (EOF) is reached. 
                In any case, the string is null-terminated. 
            
            Unlike its related function gets(), the newline character is retained. 
            
            "str" is returned if successful 
            'null pointer' returned if an error occurs. 
                Example : 
                    fgets(str_1, 79, f_point); // 0 to 79 = 80




    --------------------    TEXT I/O using fputs() and fgets()    --------------------

    fprintf() & fscanf()
        fprintf() and fscanf() similar to printf() and scanf() except that they work with files. 
        Their prototypes are:

            int fprintf(FILE *fp, char *control-string, … );
            int fscanf(FILE *fp, char * control-string, … );

        These functions operate on the file specified by "fp".
        their operations are the same as printf() and scanf().
        
        fprintf() and fscanf() make it very easy to write a wide variety of data to a file using a text format.
*/




/* Example 1: This program demonstrates fputs() and fgets(). It reads lines entered by the user
                and writes them to the file specified on the command line.
                When the user enters a blank line, the input phase terminates, and the file is closed.
                Next, the file is reopened for input, and the program uses fgets() to display the contents of the file. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char str[80];

    //check for command line argument
    if(argc != 2){
        printf("Sepcify file name.\n");
        exit(1);
    }

    // open file for output/write
    if((fp=fopen(argv[1],"w"))==NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    printf("Enter a blank line to stop.\n");
    do{
        printf(": ");
        gets(str);  // input from user
        strcat(str,"\n");   // add new line
        if(*str != '\n') fputs(str,fp); // writing to file
    } while(*str != '\n');
    fclose(fp);

    //open file for input/read
    if((fp=fopen(argv[1], "r"))==NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    //read back the file, display to the console
    do{
        fgets(str, 79, fp); // reads from file
        if(!feof(fp)) printf(str);  // writes to the console
    } while(!feof(fp));
    fclose(fp);

    return 0;
}

// name the above file "FL_IO_str_1"
/*  Following CREATES & WRITES to "myfile"
    ...\C_Cpp_codes\raw_test>  FL_IO_str_1 myfile
    Enter a blank line to stop.
    : my name is MYFILE i am a text file,
    : I live inside a PC
    : I wanna go to the internet, to see the world
    :
    my name is MYFILE i am a text file,
    I live inside a PC
    I wanna go to the internet, to see the world 
*/





/* 
    --------------    BINARY I/O    --------------
    fprintf() and fscanf() are not efficient way to read and write numeric data. 
    data conversions occurs

    using fprintf() the number is converted from its binary format into ASCII text. 
    Conversely using fscanf() , it must be converted back into its binary representation. 


    moreover a file created by fprintf() will also be LARGER.



    --------------    any data read/write    --------------

    fread() & fwrite()
        These functions can read and write any type of data, using its "BINARY REPRESENTATION". 
            Prototypes are (with four parameters)

                size_t fread(void *buffer, size_t size, size_t num, FILE *fp);
                size_t fwrite(void *buffer, size_t size, size_t num, FILE *fp);


    fread():
        'fread()' function reads from the file associated with 'fp', 
        'num' is number of objects, 
        each object 'size' bytes long, 
        into the buffer pointed to by 'buffer'. 

        It returns the number of objects actually read. 
        If this value is less than num, either the EOF encountered or an error has occurred. 
            You can use feof() or ferror() to find out which.


    fwrite():
        'fwrite()' writes to the file associated with 'fp', 
        "num" number of objects, 
        each object "size" bytes long, 
        from the buffer pointed to by "buffer".

        It returns the number of objects written. 
        This value will be less than num only if an output error has occurred.



    void pointer/generic pointer: 
        It can point to "any type of data" without the use of a "TYPE CAST". 
        This is generally referred to as a generic pointer. 

        In C, void pointers are used for two primary purposes. 
            [1]	First, as illustrated by fread() and fwrite(), they are a way for a function to receive 
                a pointer to any type of data without causing a type mismatch error. 
                Therefore, the functions must be capable of receiving any sort of data pointed to by "buffer". 

            [2]	A second purpose they serve is to allow a function to return a generic pointer. 



    type size_t: 
        size_t is a type which is defined in the STDIO.H header file.
        A variable of this type is able to hold a value equal to the "size of the largest object" supported by the COMPILER. 
        
        you can think of size_t as being the same as unsigned or unsigned long. 
        But unsigned or unsigned long can change in different environment,  size_t is ENVIRONMENT INDEPENDENT.


    Note:
    When using fread() or fwrite() to input or output binary data, the file must be opened for binary operations. 
        Forgetting this can cause hard-to-find problems.        
 */




/* Example 1: The following program writes an integer to a file called "MYFILE_BI"
                using its internal, binary representation and then reads it back.
                (The program assumes that integers are 2 bytes long.) */

#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *f_point;
    int i, k;

    printf("size of int in this system: %d\n", sizeof(int));

    // open the file for output
    if((f_point = fopen("myfile_bi", "wb")) == NULL){
        printf("File-Error\n");
        exit(1);
    }

    i = 100; 	// value written through i


    // write into the file and using "!=1" instead of "==EOF" for error checking
    /* if((fwrite(&i, 2, 1, f_point)!=1)){  // gives different result */
    if((fwrite(&i, 4, 1, f_point)!=1)){
        printf("Write-Error\n");
        exit(1);
    }
    fclose(f_point);


    // Open the file for the input/read
    if((f_point = fopen("myfile_bi", "rb")) == NULL){
        printf("Opening-Error");
        exit(1);
    }

    // read from file and output
    /* if((fread(&k, 2, 1, f_point)!=1)){  // gives different result */
    if((fread(&k, 4, 1, f_point)!=1)){
        printf("Read-Error\n");
        exit(1);
    }

    printf(" i is %d ", k); 	// value read through k
    fclose(f_point);

    return 0;
}

// Notice the error checking performed by comparing the number of items written or read with that requested
//     In some cases you will still need to use feof() or ferror() to determine if the EOF or an ERROR has occurred.





/* 
    ----------------    sizeof() & its use    ----------------

    One thing WRONG with the PRECEDING EXAMPLE is that an "assumption about the size of an integer" has been made 
        and this size is HARDCODED into the program. 

    The program will not work properly with compilers that use 4-byte integers.
    [More generally, the size of many types of data changes between systems or is difficult to determine manually] . 

    In this situation use the keyword sizeof, which is a "COMPILE-TIME OPERATOR" that returns the 'size in bytes', of a data type or variable.
    Using "sizeof" also ensure the portability of your code to new environments.  
        It takes the general forms :
            
            sizeof(type) 		or 	
            sizeof var_name

    For example, if 'floats' are four bytes long and "f" is a float variable, both of the following expressions evaluate to 4:
            sizeof f 	or 	
            sizeof(float)

        When using sizeof with a "TYPE", the TYPE must be enclosed between parentheses. 
        No parentheses are needed when using a "variable name", although the use of parentheses in this context is not an error.

*/




/* Example 2: An improved version of the preceding program (Example 1: program writes an integer to a file called "MYFILE_BI_2") 
                is shown here, using sizeof. */

#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *f_point;
    int i, k;

    // open the file for output / append
    if((f_point=fopen("MYFILE_BI_2", "ab+"))==NULL){
        printf("File-Error\n"); 
        exit(1);
    }

    i=400; 		// value written through i

    // write into the file and using "!=1" instead of "==EOF" for error checking
    // notice the use of "sizeof"
    if((fwrite(&i, sizeof(int), 1, f_point)!=1)){
        printf("Write-Error\n"); 
        exit(1);
    }
    fclose(f_point);

    
    // Open the file for the input/read
    if((f_point=fopen("MYFILE_BI_2", "rb"))==NULL){
        printf("Opening-Error"); 
        exit(1);
    }
    
    // read from file and output
    // notice the use of "sizeof"
    if((fread(&k, sizeof k, 1, f_point)!=1)){
        printf("Read-Error\n"); 
        exit(1);
    }

    printf(" i is %d ", k); 	// value read through k
    fclose(f_point);
    
    return 0;
}




/* 
    ----------------    Random access    ----------------

    write/read a file sequentially from its beginning to its end using:
            fgetc(), 
            fputc(), 
            fputs(), 
            fgets(), 
            fprintf(), 
            fscanf(), 
            fread() and 
            fwrite().




    fseek():
        Used to access a file randomly (i.e. any where/any point of a file ).
        The prototype of fseek() is

            int fseek(FILE *fp, long offset, int origin);

        returns 'zero' when 'successful'
        nonzero if a failure occurs.

        In most implementations, you may seek past the end of the file, 
            but you may never seek to a point before the start of the file.


        fp: 
            fp is associated with the file being accessed. 
        offset: 
            The value of "offset" determines the "number of bytes" from 'origin' to make the 'new current position'. 
        origin: 
            origin must be one of these "macros", shown here with their meanings:

                Origin	    Meaning

                SEEK_SET	Seek from start of file
                SEEK_CUR	Seek from current location
                SEEK_END	Seek from end of file

        These macros are defined in STDIO.H. 

        For example, if you wanted to set the 'current location' 100 bytes from the 'start of the file',  then 
            'origin' will be SEEK_SET and 
            'offset' will be 100.

    0L:
        Sometimes 0L is used
        0L is a long integer value with all the bits set to ZERO - that's generally the definition of 0.

        Note:   (~0L) is a long integer value with all the bits set to ONE according to TWO's complement.
                The "~" means to 'invert all the bits', which leaves you with a 'long integer' with all the bits set to one.

                The reason for using (~0L) instead of '-1L' is to be clearer about the intent - 
                    - it's not meant to be used as a number at all, but rather as a collection of bits

 


    ftell():
        You can "determine" the CURRENT LOCATION of a file using ftell(). Its prototype:

            long ftell(FILE *fp);

        returns the "location" of the "current position" of the file associated with fp. 
        If a failure occurs, it returns -1.



    How you can "RANDOMLY ACCESS DATA OF ANY TYPE": 
        You simply need to "multiply" the "size of the base data type" by its 'index' in the file.



    NOTES:
        In general, use 'random access' only on 'binary files'. 
            Because text files may have character translations performed on them.
                there may not be a direct correspondence between file-content and the byte.

        The only time you should use fseek() with a "text file" is when seeking to a 
            position previously determined by ftell(), USing "SEEK_SET" as the "origin".

        text-file - can be opened as a binary file. 
            There is no inherent restriction about random access on files containing text. 
            The restriction applies only to files "opened as text files".
            
*/




/* Example 1: The following program uses fseek() to report the value of any
                byte within the file specified on the command line. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long loc;
    FILE *fp;

    // see if file name is specified
    if(argc!=2){
        printf("File name missing.\n");
        exit(1);
    }

    // open for reading the file
    if((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open file. \n");
        exit(1);
    }

    printf("Enter byte to seek to: ");
    scanf("%ld", &loc);
    if(fseek(fp, loc, SEEK_SET)){
        printf("Seek error. \n");
        exit(1);
    }

    printf("Value at loc %ld is %d", loc, getc(fp));
    fclose(fp);

    return 0;
}

// make the file name rand_io_1.c
// myFile_2 is a pre-existed file (there's text inside it)
// CLI commnads:
    // rand_io_1 myFile_2
    // Enter byte to seek to: 2
        // Value at loc 2 is 71




/* Example 2: Following uses ftell() and fseek() to copy the contents of one file into another in reverse order.
                Pay special attention to how the END of the "input/read file" is found.
                Since the program has sought to the EOF, the program "backs up one byte" so that
                    the 'current location' of the file associated with in is at the 'last actual character' in the file. */

// Copy a file in reverse order
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long loc;
    FILE *in, *out;
    char ch;

    // see if correct number of command line arguments
    if(argc != 3){
        printf("Usage: revcopy <source> <destination>.\n");
        exit(1);
    }

    // open the first file for reding
    if((in = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open input file. \n");
        exit(1);
    }

    // open the second file for writing
    if((out = fopen(argv[2], "wb")) == NULL){
        printf("Cannot open input file. \n");
        exit(1);
    }


    // find end of source file
        // '0L' setes all bits to 0, its a long int, its besically defining the 0
    fseek(in, 0L, SEEK_END);
    loc = ftell(in);


    // copy file in reverse order
    loc = loc-1;    // back up past end-af-file EOF mark
    while(loc >= 0L) {
        fseek(in, loc, SEEK_SET);
        ch = fgetc(in);
        fputc(ch, out);
        loc--;
    }


    fclose(in) ;
    fclose(out) ;

    return 0;
}

// CLI commands
// rand_io_2 myFile_2 myfile





/* 
    ----------------    Other important File-System functions    ----------------

    rename() - Rename a file : 
        To rename a file use rename() :

            int rename(char *oldname, char *newname);

            "oldname" points to the original name of the file and 
            "newname" points to its new name. 
            The function returns 'ZERO' if 'SUCCESSFUL' and 
            'NONZERO' if an 'ERROR' occurs.



    remove() - Erase a file : 
        To erase a file use remove() : 

            int remove(char *file-name);

        will erase the file whose name matches that pointed to by 'file-name'. 
        It returns 'ZERO' if 'SUCCESSFUL' and 
        'NONZERO' if an 'ERROR' occurs.



    rewind() - Position change : 
        To position a file's current location to the "start of the file" use rewind().
        
            void rewind(FILE *fp);

            It rewinds the file associated with fp. 
            It has no return value, because any file that has been successfully opened can be rewind.



    fflush() - Flush disk buffer : 
        To cause a file's disk buffer to be flushed use fflush().
        
            int fflush(FILE *fp);

            It flushes the buffer of the file associated with 'fp'. 
            Returns "ZERO" if "SUCCESSFUL", 
            "EOF" if a "FAILURE" occurs. 
            
            If you call fflush() using a NULL for fp, all 'existing disk buffers' are "flushed".
*/

// Think of ways that rewind() and fflush() could be useful in real applications.




/* Example 1: This program demonstrates remove(). It prompts the user for
                the file to erase and also provides a safety check in case the user
                entered the wrong name. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(void){
    char fname[80];

    printf("Enter name of file to erase: ");
    gets(fname);
    printf("Are you sure? (YIN) ");

    if(toupper(getchar())=='Y') remove(fname);

    return 0;
}




/* Example 2: The following program demonstrates rewind() by displaying
                the contents of the file specified on the command line twice. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;

    // see if file name is specified
    if(argc!=2) {
        printf("File name missing. \n");
        exit(1);
    }

    // open file for reading
    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file. \n");
        exit(1);
    }

    // show it once
    while(!feof(fp)) putchar(getc(fp));

    rewind(fp);

    // show it twice.
    // since in previus statement rewind() is used, location is now set to 'start'
    while(!feof(fp)) putchar(getc(fp));

    fclose(fp);

    return 0;
}



/* 
    ---------------    THE STANDARD STREAMS    ---------------
    Standard  streams: 
        When a C program 'BEGINS EXECUTION', three streams are automatically opened and available for use.

                1. standard input (stdin), 
                2. standard output (stdout), and 
                3. standard error (stderr). 

        "stdin" inputs from the KEYBOARD;  
        "stdout" and "stderr" write to the SCREEN.

        By default, they refer to the "CONSOLE", 
            but in environments that Support redirectable I/O, they can be redirected by the OS to some other device.



    These 'standard streams' are "FILE pointers" and may be used with any function that requires a variable of type "FILE *". 

    ConIO using FileIO:
        You can use fprintf() to print "formatted output" to the screen by specifying "stdout" as its output stream. 
            The following two statements are functionally the same:
        
                // using FileIO function
                fprintf(stdout, "%d %c %s", 100, 'c', "this is a string");

                // usning ConIO function
                printf("%d %c %s", 100, 'c', "this is a string");


        In actuality, C makes little distinction between 'console-I/O' and 'file-I/O'. 
            As just shown, it is possible to perform "console I/O" using several of the 'file-system functions'. 



    Disk FileIO using ConIO:
        It is also possible to perform "DISK FILE I/O" using 'CONSOLE I/O' functions, such as printf().
            Because all "console I/O functions" are actually 'special-case file-system functions' that automatically operate on "stdin" and "stdout". 

        The console is simply another hardware device. 
            You don't actually need the 'console functions' to access the "console". Any 'file-system function' can access it. 
            (non-standard I/O functions like getche() are differentiated from the 'standard file-system functions' and operate "only on the console".) 



    Redirection of std streams: 
        In environments that allow "REDIRECTION OF I/O", 'stdin' and 'stdout' could refer to devices "other than the KEYBOARD and SCREEN". 
        
        Since the "console functions" operate on STDIN and STDOUT, if these streams are REDIRECTED, 
            the "console functions" can be made to operate on other devices. 
                For example, by redirecting the "STDOUT" to a "DISK FILE". you can use a "console I/O function" to write to a DISK FILE.



    Note that:
        stdin, stdout, and stderr are not variables. They may not be assigned a value using fopen() , 
            nor should you attempt to close them using fclose() . 
            These streams are "maintained internally" by the COMPILER. 
            You are free to use them, but 'not to change them'.
*/




/* Example 1: Assume that this program is called "TEST". If you execute TEST normally, it displays the string on the screen. 
                However, if an environment supports redirection of I/O, stdout can be redirected to a file. */
#include <stdio.h>

int main(void){
    printf("This is an example of redirection.\n");
    return 0;
}

// For example, in a DOS, OS/2, Windows, or UNIX environment, executing TEST like this
TEST > OUTPUT
// causes the output of TEST to be written to a file called OUTPUT. You might want to try this now for yourself.

// we named our source file "FL_IO_strm_1" and stored the output a file called "output_test"
FL_IO_strm_1 > output_test




/* Example 2: Input can also be redirected. For example, consider the following program.
                causes "STDIN" to be directed to the file called INPUT. 
                Assuming that INPUT contained the ASCII representation for an integer,
                the value of this integer will be read from the file and printed on the screen. */
#include <stdio.h>

int main (void){
    int i;

    scanf ("%d", &i);
    printf ("%d", i);
    return 0;
}

// Assuming it is called TEST, executing it as
TEST < INPUT

// we named our source file "FL_IO_strm_2" and stored the output a file called "input_test"
FL_IO_strm_2 < input_test



// Note: from above 2 Examples notice usage of ">" for "output" and "<" for "input"




/* Example 3: When using gets() it is possible to overrun the array that is being used to receive 
                the characters entered by the user because gets() provides "no bounds checking". 

                One way around this problem is to use
                    fgets(), specifying 'stdin' for the "input stream". 
                    Since fgets() requires you to specify a maximum length, it is possible to prevent an array overrun. 
                    The only trouble is that fgets() does not remove the newline character and gets() does. 
                    This means that you will have to manually remove it, as shown in the following program:     */
#include <stdio.h>
#include <string.h>

int main(void){
    char str[10];
    int i;

    printf("Enter a string: ");
    fgets(str, 10, stdin);

    // remove newline, if present
    i = strlen(str)-1;
    if(str[i]=='\n') str[i] = '\0';

    printf ("This is your string: %s", str);

    return 0;
}

// FL_IO_strm_3 < myFile_2ol



