6.4 NON-STANDARD CONSOLE FUNCTIONS : getche(), getch(), kbhit(), cprintf(), cscanf()
Both getche() and getch()  are non-standard functions of C. Prototypes of  getche() and getch()  are :
int getche(void); 	/*Return type is int*/
int getch(void); 	/*Return type is int*/
Both functions use the header file CONIO.H and returns int. . 

	The getche() function waits until the next keystroke is entered at the keyboard. When a key is pressed, getche() echoes(shows) it to the screen and then immediately returns the character. The character is read as an unsigned char and elevated to int. However, your routines (functions) can simply assign this value to a char value. 

	The getch() function is the same as getche(), except that the keystroke is not echoed(not showed) to the screen.

	Another very useful non-ANSI-standard function commonly supplied with a C compiler is kbhit(). It has this prototype:
int kbhit(void); 	/*Return type is int*/
The kbhit() function also requires the header file CONIO.H. This function is used to determine whether a key has been pressed or not. When a key is pressed, kbhit() returns true (nonzero), but does not read the character (can be read it with getche() or getch() ). If no keystroke is pending, khhit( ) returns false (zero).

Problems of mixing standard I/O and non-standared I/O : For some compilers. the non-standard i/O functions such as getche() are not compatible with the standard i/O functions such as printf() or scanf(). When this is the case, mixing the two can cause unusual program behavior. If mixing standard I/O and non-standared I/O is not compatible in your compiler, you may need to use non-standard versions of scanf() and/or printf(), too. These are called cprintf() and cscanf() . Both cprintf() and  cscanf() use the CONIO.H header file.
	The cprintf() function works like printf() except that it does not translate the newline character (\n) into the carriage return, linefeed pair as does the printf() function. Therefore, It is necessary to explicitly output the carriage return (\r) where desired. 
	The cscanf() function works like the scanf() function. 
