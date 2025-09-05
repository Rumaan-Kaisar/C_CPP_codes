
/*  ------------------------    chapter    ------------------------

// ----  rev[04-Aug-2025]  ----

12.4 I/O MANIPULATORS
I/O manipulators are special I/O format functions that can occur within an I/O statement. (Where ios member functions stay separate from I/O statement).  For example:	cout << oct << 100 << hex << 100;
cout << setw(10) << 100;
	The first statement tells cout to display integers in octal and then outputs 100 in octal. It then tells the stream to display integers in hexadecimal and then outputs 100 in hexadecimal format. 
	The second statement sets the field width to 10 and then displays 100 in hexadecimal format again (last base setting active). 
	Notice that when a manipulator does not take an argument, such as oct in the example, it is not followed by parentheses. This is because it is the address of the manipulator that is passed to the overloaded << operator.
	The main advantages of using manipulatior over the ios member functions is that they are easier to use and allow compact coding.
	Many of the I/O manipulators parallel member functions of the ios class. 
	An I/O manipulator affects only the stream of which the I/O expression is a part and doesn't affect all currently opened streams.
	To access manipulators that take parameters, such as setw(), you must include <iomanip> in you program. This is not necessary when you are using a manipulator that does not require an argument.
	Example 1:  Following includes setfill() and setw() so we have to include <iomanip>
#include <iostream>
#include <iomanip>
using namespace std;
int main() { 	cout << hex << 100 << endl ;
cout << setfill('X') << setw(10) ;
cout << 100 << " hi " << endl ;
return 0;}
	Boolalpha: boolalpha allows you to input and output Boolean values using the keywords true and false (normally you must enter 1 for true and 0 for false).
	Must set the boolalpha flags for cin and cout separately. Eg: cin >> boolalpha >> b;  // enter true or false
	As with all format flags, setting boolalpha for one stream does not imply that it is also set for another. For Example 2:

	int main() { bool b;
	cout << " Before boolalpha:";
	b = true ;
	cout << b <<" ";
	b = false ;
	cout << b << endl;	cout << " After boolalpha:";
b = true ;
cout << boolalpha << b << " ";
b = false ;
cout << b << endl;
return 0;}	OUTPUT:
Before boolalpha: 1  0
After boolalpha: 	true false


	Set/Reset: 		To set specific format flags manually by manipulator, use setiosflags() which is equivalent to setf().
	To turn off flags use the resetiosflags() manipulator which is equivalent to unsetf().
	Table of Slandered C++ I/O Manipulators:
Manipulator	Purpose	I/O	Manipulator	Purpose	I/O
boolalpha	Turns on boolalpha flag	I/O	oct	Turns on oct ag	I/O
dec 	Turns on dec flag	I/O	right	Turns on right flag	Output
endl	newline and flushes  stream	Output	resetiosflags(fmtflags f)	Turns off the flags specified in f	I/O 
ends	Outputs a null 	Output	scientific	Turns on scientific flag	Output
fixed	Turns on fixed flag	Output	setbase(int base)	Sets the number base to base	I/O 
flush 	Flushes a stream	Output	setfill(int ch)	Sets the fill character to ch	I/O
hex	Turns on hex flag	I/O	setiosflags(fmtflags f)	Turns on the flags specified in f	Output
internal	Turns on internal flag	Output	setprecision(int p)	Sets the number of digits of precision	Output
left	Turns on left	Output	setw(int w)	Sets the field width to w	Output
noboolalpha	Turns off boolalpha flag	I/O	showbase	Turns on showbase flag	Output
noshowbase	Turns off showbase flag	Output	showpoint	Turns on showpoint flag	Output
noshowpoint	Turns off showpoint flag	Output	showpos	Turns on showpos flag	Output
noshowpos	Turns off showpos flag	Output	skipws	Turns on skipws flag	Input
noskipws	Turns off skipws flag	Input	unitbuf	Turns on unitbuf flag	Output
nounitbuf	Turns off unitbuf flag	Output	uppercase	Turns on uppercase flag	Output
nouppercase	Turns off uppercase flag	Output	ws	Skips leading white space	Input





--------  GPT  --------
Here’s a balanced (mid-ground) explanation of 12.4 I/O Manipulators, simplified pointwise:

🔹 What are I/O Manipulators?

Manipulators are special functions that change stream formatting directly inside an I/O statement.

Unlike ios member functions (setf(), precision(), etc.), manipulators make code shorter and more readable.

🔹 Examples

Base manipulators

cout << oct << 100 << hex << 100;


oct → prints 100 in octal.

hex → prints 100 in hexadecimal.

The stream "remembers" the last base (here: hex).

Width manipulator

cout << setw(10) << 100;


Sets field width = 10, then prints 100 (padded with spaces or fill char).

👉 Key point: manipulators without arguments (oct, hex, dec) are passed directly; manipulators with arguments (setw(10), setfill('X')) need <iomanip>.

🔹 Advantages

Easier and more compact than calling member functions.

Affect only the stream where used (e.g., cout, not cerr).

Good for table formatting, base conversions, boolean display, etc.

🔹 Special Manipulators

boolalpha / noboolalpha

Makes true/false print as words instead of 1/0.

cout << boolalpha << true << " " << false; // true false


Must be set separately for cin and cout.

setiosflags() / resetiosflags()

High-level equivalents of setf() / unsetf().

Example: cout << setiosflags(ios::showpos);

endl / ends / flush

endl: newline + flush buffer.

ends: insert '\0'.

flush: flush buffer without newline.

🔹 Standard Manipulator Table (common ones)
Manipulator	Purpose
dec, oct, hex	Set number base
setw(int)	Set field width (next output)
setfill(ch)	Set fill character
setprecision(p)	Set floating-point precision
fixed	Fixed-point float formatting
scientific	Scientific float formatting
showpos	Show + for positive numbers
showpoint	Always show decimal point
boolalpha	Print true/false instead of 1/0
uppercase	Uppercase hex + scientific E
ws	Skip whitespace on input
endl	Newline + flush
🔹 Key Takeaways

Manipulators = stream shortcuts.

They often parallel ios member functions, but are cleaner inside I/O expressions.

Use <iomanip> for manipulators with parameters.

Formatting changes persist for that stream until reset.

Would you like me to also show a side-by-side comparison of ios functions vs manipulators (e.g., cout.setf(std::ios::hex) vs cout << hex) so it’s crystal clear how they map?




--------  Qwen  --------





*/  
