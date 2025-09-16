
/*  ------------------------    I/O manipulators    ------------------------

    I/O manipulators:
        Special functions that control I/O formatting directly inside an I/O statement.
        Unlike "ios member functions" (setf(), precision(), etc.), manipulators make code shorter and more readable.
        Can be used directly in I/O statements (e.g., <<, >>), unlike ios member functions which are called separately.

        Example:
                cout << oct << 100 << hex << 100;   // 'hex' and 'oct' are manipulators
                cout << setw(10) << 100;    // 'setw' is a manipulators

            First statement 
                sets output "base" to octal, then prints 100 in octal.
                Then switches to hexadecimal, and prints 100 in hex.
                Format changes (like base) stay active until changed again.

            The second statement:
                Sets the "field width" to 10 for the next output.
                Then prints 100 using the current base (last base setting still active, i.e. hex, from earlier).

        Key Features:
            Compact & readable: Allow formatting within stream expressions.
            Stream-specific:    Only affect the stream they are used with (e.g., cout, cin).
            No global effect:   Changing format in one stream doesn't affect others.

            Easier and more intuitive to use.
            Allow compact, readable code directly in stream statements.
            Preferred over ios member functions for formatting.
            Good for table formatting, base conversions, boolean display, etc.



    Manipulator Arguments:
        Some manipulators take arguments, like setw(10), setfill('*'), setprecision(3)
            Must include <iomanip>

        Some have no arguments, like hex, oct, endl — these are used without parentheses.
            This is because it is the "address of the manipulator" that is passed to the "overloaded << operator".
            This allows the stream to call it internally.
            Only need <iostream>


    Note:
        Many of the "I/O manipulators" parallel "member functions" of the "ios" class. 
    


    --------  boolalpha  --------

    Boolalpha:
        Allows to input and output "Boolean values" using the keywords "true" and "false"
        (normally you must enter 1 for true and 0 for false).

        Must set the boolalpha flags for 'cin' and 'cout' separately. Eg: 
            cin >> boolalpha >> b;  // enter true or false
            cout << boolalpha << true << " " << false; // true false

        As with all format flags, setting boolalpha for one stream does not affect others.
    


    --------  Set/Reset  --------

        Set/Reset:
            setiosflags() / resetiosflags() are high-level equivalents of setf() / unsetf().

        To set specific format flags manually by manipulator, 
            use setiosflags() which is equivalent to setf().

        To turn off flags use the resetiosflags() manipulator which is equivalent to unsetf().



// ----  rev[16-Sep-2025]  ----

	Table of Slandered C++ I/O manipulators:
Manipulator	Purpose	I/O	Manipulator	Purpose	I/O
	 	I/O	  oct	Turns on oct ag	I/O
 		I/O	  right	Turns on right flag	Output
		Output	resetiosflags(fmtflags f)	Turns off the flags specified in f	I/O 
	 	Output	scientific	Turns on scientific flag	Output
		Output	setbase(int base)	Sets the number base to base	I/O 
 		Output	setfill(int ch)	Sets the fill character to ch	I/O
		I/O	  setiosflags(fmtflags f)	Turns on the flags specified in f	Output
		Output	setprecision(int p)	Sets the number of digits of precision	Output
		Output	setw(int w)	Sets the field width to w	Output
		I/O	  showbase	Turns on showbase flag	Output
		Output	showpoint	Turns on showpoint flag	Output
		Output	showpos	Turns on showpos flag	Output
		Output	skipws	Turns on skipws flag	Input
		Input	unitbuf	Turns on unitbuf flag	Output
		Output	uppercase	Turns on uppercase flag	Output
		Output	ws	Skips leading white space	Input


boolalpha       Turns on boolalpha flag
dec             Turns on dec flag
endl            newline and flushes  stream
ends            Outputs a null
fixed           Turns on fixed flag
flush           Flushes a stream
hex             Turns on hex flag
internal        Turns on internal flag
left            Turns on left
noboolalpha     Turns off boolalpha flag
noshowbase      Turns off showbase flag
noshowpoint     Turns off showpoint flag
noshowpos       Turns off showpos flag
noskipws        Turns off skipws flag
nounitbuf       Turns off unitbuf flag
nouppercase     Turns off uppercase flag









--------  GPT  --------
Here’s a balanced (mid-ground) explanation of 12.4 I/O manipulators, simplified pointwise:











Example: cout << setiosflags(ios::showpos);

endl / ends / flush

endl: newline + flush buffer.

ends: insert '\0'.

flush: flush buffer without newline.




Standard Manipulator Table (common ones)

------------------------------------------------
Manipulator         Purpose
------------------------------------------------
dec, oct, hex       Set number base
setw(int)           Set field width (next output)
setfill(ch)         Set fill character
setprecision(p)     Set floating-point precision
fixed               Fixed-point float formatting
scientific          Scientific float formatting
showpos             Show + for positive numbers
showpoint           Always show decimal point
boolalpha           Print true/false instead of 1/0
uppercase           Uppercase hex + scientific E
ws                  Skip whitespace on input
endl                Newline + flush
------------------------------------------------



🔹 Key Takeaways

manipulators = stream shortcuts.

They often parallel ios member functions, but are cleaner inside I/O expressions.

Use <iomanip> for manipulators with parameters.

Formatting changes persist for that stream until reset.

Would you like me to also show a side-by-side comparison of ios functions vs manipulators (e.g., cout.setf(std::ios::hex) vs cout << hex) so it’s crystal clear how they map?




--------  Qwen  --------

Here is a simplified, pointwise summary of Section 12.4: I/O manipulators, with concise yet clear explanations:






✅ Common Examples
cpp


1
2
3
cout << oct << 100;        // Output 100 in octal
cout << hex << 100;        // Then in hexadecimal
cout << setw(10) << 100;   // Set width to 10, then output
setw(n) → sets field width (like width(n)), but resets after one use.
setfill(c) → sets padding character (like fill(c)).
setprecision(n) → sets floating-point precision.
boolalpha → prints true/false instead of 1/0.
✅ boolalpha – Boolean Formatting
By default: true → 1, false → 0.
With boolalpha: outputs as true/false.
Must be set separately for cin and cout:
cpp


1
2
cout << boolalpha << true;  // prints: true
cin >> boolalpha >> b;      // allows input: true/false
✅ Flag Control manipulators
setiosflags(f) → same as setf(f) — turns on format flags.
resetiosflags(f) → same as unsetf(f) — turns off flags.
Used with <iomanip>.
Example:

cpp


1
cout << setiosflags(ios::left) << setw(10) << "Hello";
✅ Important manipulators (Summary Table)
dec
,
hex
,
oct
Number base
I/O
boolalpha
/
noboolalpha
Show true/false
I/O
setw(n)
Set field width
Output
setfill(c)
Set padding char
Output
setprecision(n)
Set decimal precision
Output
setbase(n)
Set number base (limited support)
Output
left
,
right
,
internal
Alignment
Output
fixed
,
scientific
Floating-point format
Output
showpoint
,
showpos
,
showbase
Show extra info
Output
uppercase
Use A-F, E, etc.
Output
endl
Newline + flush
Output
ends
Insert null char
Output
flush
Flush stream
Output
ws
Skip whitespace (input)
Input
skipws
/
noskipws
Enable/disable skip spaces
Input
unitbuf
/
nounitbuf
Flush after each output
Output

✅ Example Code
cpp


1
2
3
4
5
6
7
8
9
10
11
⌄
#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << hex << 100 << endl;                     // 64
    cout << setfill('X') << setw(10) << 100 
         << " hi " << endl;                         // XXXXXXXX64 hi
    cout << boolalpha << true << " " << false;     // true false
    return 0;
}
✅ Key Takeaways
manipulators make formatting cleaner and inline.
Use <iomanip> for parameterized manipulators (setw, setfill, etc.).
Most manipulators affect only the next operation (e.g., setw).
Format changes (like hex, boolalpha) persist until changed.
💡 Prefer manipulators for readable, concise I/O formatting! 




*/  




/* Example 1:  Following includes setfill() and setw() so we have to include <iomanip> */
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::hex << 100 << std::endl ;
    std::cout << std::setfill('X') << std::setw(10) ;
    std::cout << 100 << " hi " << std::endl ;

    return 0;
}

   


/* Example 2: */

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

