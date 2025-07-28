
/*  ------------------------    chapter    ------------------------

    ----  rev[28-Jul-2025]  ----

12.2 Formatted I/O
It is possible to output information in a wide variety of forms using C++'s I/O system as we did before with  C's printf() function
	Each stream has associated with it a set of format flags that control the way information is formatted. The ios class declares a bitmask enumeration called fmtflags, in which the values are defined:
adjustfield	dec	hex	oct	showbase	skipws
basefield	fixed	internal	right	showpoint	unitbuf
boolalpha	floatfield	left	scientific	showpos	uppercase


	These values are used to set or clear the format flags and are defined within ios. 


	skipws: When the skipws flag is set, whitespace characters (spaces, tabs, and newlines) will be cleared for new input. When skipws is cleared, whitespace characters are not discarded.	


	left, right, internal (for justified output): Default is right.
	left and right flags make, left and right justified output.
	internal flag makes a numeric value is padded to fill a field by inserting spaces between sign/base character. 


	Dec, oct, hex : Decimal output is default
	oct and hex flags produce octal and hexadecimal output respectively. 
	To return output to decimal, set the dec flag.	

	showbase displays the base of numeric values. Eg. for hexadecimal conversion, 1F will be displayed as 0x1F.
	By default, the scientific notation "e" and hexadecimal notation "x" is displayed in lowercase, setting uppercase flag displays these characters in uppercase.
	scientific, fixed: If the scientific flag produce floating-point values using scientific notation. And fixed flag makes scientific-notation disabled, and normal notation returned.	

	showpos flag displays "+" before positive values.
	showpoint flag display ".000000" for all floating-point output-whether needed or not.
	When neither flag is set, the compiler chooses an appropriate method.


	Booleans can be input or output using the keywords true and false, when boolalpha is set.

	unitbuf flushes the buffer after each insertion operation.	
	basefield: the oct, dec, and hex fields can be collectively referred as basefield. 
	adjustfield: the left, right, and internal fields collectively referred as adjustfield.
	floatfield: the scientific and fixed fields collectively referenced as floatfield.




	To set a format flag, use the setf() function which is a member of ios. Its form is:       fmtflags setf (fmtflags flags);
	This function returns the previous settings of the format flags and turns on those flags specified by flags. (All other flags are unaffected.)  For example, to turn on the showpos flag:
stream.setf ( ios :: showpos );
	Here stream is the stream that you wish to affect. 
	Notice the use of the scope resolution operator (::). Because the format flags are defined within the ios class, you must access their values by using ios and the scope resolution operator. 
	setf() is a member function of the ios class and affects streams created by that class. 
	Therefore, any call to setf() is done relative to a specific stream.
	setf() cannot be called by itself 
	There is no concept in C++ of global format status. Each stream maintains its own format status information individually.
	To set more than one flag in a single call to setf(): use "OR" together the values of the flags. For example, this call sets the showbase and hex flags for cout:
cout.setf( ios :: showbase | ios :: hex );
	Note: showpos, showbase, hex all are enumerated constants within the ios class. Therefore, it is necessary to tell the compiler this fact by preceding showpos/showbase/hex with the class name "ios" and the scope resolution operator "::". Otherwise showpos/showbase/hex will not be recognized. We must specify  ios::showpos or ios::showbase or ios::hex.
	The complement of setf() is unsetf().This member function of ios clears one or more format flags. Its prototype form is:
void unsetf ( fmtflags flags );
	The flags specified by flags are cleared. (All other flags are unaffected.)
	To know the current format settings without altering: Use the special member function of ios, flags(), which simply returns the current setting for each format flag. Its prototype is:   fmtflags flags();
	The flags() also allows to set/reset all format flags associated with a stream to those specified in the argument to flags(). The prototype for this version of flags() is:
fmtflags flags ( fmtflags f);
	For this version, the bit pattern found in f is copied to the variable used to hold the format flags associated with the stream, and overwrites all previous flag settings. The function returns the previous settings.






*/  





/* Example 1:    following program shows how to set several flags. 


	This program displays: 	1.232300e+02 hello  64 	    a  fffffff6 	+100.000000
	Here showpos flag affects only decimal output (i.e. a  fffffff6 is unaffected). It does not affect the value 10 when output in hexadecimal. 
	Also notice the unsetf() call that turns off the dec flag (which is on by default). It is necessary to turn it off when turning on either hex or oct. In general, it is better to set only the number base that you want to use and clear the others.


*/
int main(){
	cout.unsetf(ios::dec); // not required by all compilers 
	cout.setf (ios::hex | ios::scientific);
	cout<< 123.23 << "hello" << 100 <<'\n';	
cout.setf(ios::showpos );
cout<< 10 <<' '<< -10 <<'\n';
cout.setf(ios::showpoint | ios::fixed );
cout<< 100.0;
return 0; }



/* Example 2: The following program illustrates the effect of the uppercase flag. It first enable uppercase, showbase, and hex flags to output: 99 in hexadecimal. Then disables the uppercase.
int main() { cout.unsetf(ios :: dec );
	cout.setf(ios::uppercase | ios::showbase | ios::hex);
	cout << 88 << '\n';	cout.unsetf(ios::uppercase );
cout << 88 << '\n';
return 0; }
 */




/* Example3: The following illustrates the showflags() function. Displays which flag is on and which is off. */


void showflags(); 								// Declaration of the function
int main(){	showflags(); 							// first shows default flag settings
		cout.setf(ios::oct | ios::showbase | ios::fixed ); 	// Changing flags
		showflags();		// shows changed flag settings
        			return 0;}
void showflags(){
ios::fmtflags f;
f = cout.flags(); // get flag settings
if(f & ios :: skipws ) cout <<"skipws on \n";
else cout << " skipws off \n";

if(f & ios :: left ) cout << " left on\n";
else cout << " left off \n";

if(f & ios :: right ) cout << " right on\n";
else cout << " right off \n";

if(f& ios :: internal) cout<<"internal on\n";
else cout << " internal off \n";

if(f & ios :: dec ) cout << "dec on\n";
else cout << "dec off \n";	if(f & ios :: oct ) cout << "oct on\n";
else cout << "oct off \n";

if(f & ios :: hex ) cout << "hex on\n";
else cout << "hex off \n";

if(f&ios:: showbase ) cout<<"showbase on\n";
else cout << " showbase off \n";

if(f&ios::showpoint) cout<<"showpoint on\n";
else cout << " showpoint off \n";

if(f& ios :: showpos ) cout << " showpos on\n";
else cout << " showpos off \n";

if(f&ios::uppercase) cout<<"uppercase on\n";
else cout << " uppercase off \n";	if(f&ios::scientific) cout << " scientific on\n";
else cout << " scientific off \n";

if(f & ios :: fixed ) cout << " fixed on\n";
else cout << " fixed off \n";

if(f & ios :: unitbuf ) cout << " unitbuf on\n";
else cout << " unitbuf off \n";

if(f & ios :: boolalpha ) cout << " boolalpha on\n";
else cout << " boolalpha off \n";

cout << "\n"; }


// 	Inside showags(), the local variable f is declared to be of type fmtflags. If your compiler does not define fmtflags, declare this variable as long instead. 


