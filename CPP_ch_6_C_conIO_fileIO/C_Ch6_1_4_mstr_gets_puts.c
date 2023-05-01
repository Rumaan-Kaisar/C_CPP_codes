6.5 Details on gets() and puts( )
Their function prototypes of gets() and puts() are

char *gets(char *str); /*"pointer-function" returns char type & char type "pointer-parameter"*/
int puts(char *str);  /*" function" returns int type & char type "pointer-parameter"*/

These functions use the header file STDIO.H. Both do not perform bound checking (checking the size) before storing the string into the character array.
	The gets() function reads characters entered at the keyboard until a carriage return is read (i.e., until the user presses ENTER). It stores the characters in the array pointed to by str. The carriage return is not added to the string. Instead, it is converted into the null terminator. If successful,  gets() returns a pointer to the start of str. If an error occurs, a null pointer is returned. 
	The puts() function outputs the string pointed to by str to the screen. It automatically appends a carriage return, line-feed sequence (i.e. there is no need to use new-line format : each puts() output the corresponding string in different line). Example : puts("one"); puts("two") ; puts("three"); outputs the words one, two, and three on three separate lines. If successful, puts() returns a non-negative value. If an error occurs, EOF is returned.
	The main reason to use puts() instead of printf(), to output a string is that puts() is much smaller and faster. 

Note
	even though gets( ) returns a pointer to the start of the string, it still must be called with a pointer to an actual array. For example, the following is wrong:
char *p;
p = gets(p); 	 /* wrong!!! */
Here, there is no array defined into which gets() can put the string. This will result in a program failure.
