
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
    


    --------  boolalpha : Flag Control manipulators  --------

    Boolalpha:
        Allows to input and output "Boolean values" using the keywords "true" and "false"
        (normally you must enter 1 for true and 0 for false). 
        Used with <iomanip>.

        Must set the boolalpha flags for 'cin' and 'cout' separately. Eg: 
            cin >> boolalpha >> b;  // enter true or false
            cout << boolalpha << true << " " << false; // true false

        As with all format flags, setting boolalpha for one stream does not affect others.
    


    --------  Set/Reset  --------

        Set/Reset:
            setiosflags() / resetiosflags() are high-level equivalents of setf() / unsetf().

        To set specific format flags manually by manipulator, 
            use setiosflags() which is equivalent to setf().
            Example:
                        cout << setiosflags(ios::showpos);
        
        To turn off flags use the resetiosflags() manipulator which is equivalent to unsetf().



    --------  endl / ends / flush  --------

    endl:   newline + flush buffer.
    ends:   insert '\0'.
    flush:  flush buffer without newline.



    ----  Table of Slandered C++ I/O manipulators  ----

    -----------------------------------------------
    Manipulator     I/O       Purpose
    ------------------------------------------------
    boolalpha       I/O	      Turns on boolalpha flag
    dec             I/O	      Turns on dec flag
    endl            Output    newline and flushes  stream
    ends            Output    Outputs a null
    fixed           Output    Turns on fixed flag
    flush           Output    Flushes a stream
    hex             I/O	      Turns on hex flag
    internal        Output    Turns on internal flag
    left            Output    Turns on left
    noboolalpha     I/O	      Turns off boolalpha flag
    noshowbase      Output    Turns off showbase flag
    noshowpoint     Output    Turns off showpoint flag
    noshowpos       Output    Turns off showpos flag
    noskipws        Input     Turns off skipws flag
    nounitbuf       Output    Turns off unitbuf flag
    nouppercase     Output    Turns off uppercase flag

    oct             I/O       Turns on oct ag
    right           Output    Turns on right flag
    scientific      Output    Turns on scientific flag
    showbase        Output    Turns on showbase flag
    showpoint       Output    Turns on showpoint flag
    showpos         Output    Turns on showpos flag
    skipws          Input     Turns on skipws flag
    unitbuf         Output    Turns on unitbuf flag
    uppercase       Output    Turns on uppercase flag
    ws              Input     Skips leading white space

    resetiosflags(fmtflags f)   I/O       Turns off the flags specified in f
    setw(int w)                 Output    Sets the field width to w
    setbase(int base)           I/O       Sets the number base to base
    setfill(int ch)             I/O       Sets the fill character to ch
    setiosflags(fmtflags f)     Output    Turns on the flags specified in f
    setprecision(int p)         Output    Sets the number of digits of precision



    ----  Standard Manipulator Table (common ones)  ----

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


    Key Takeaways:
        manipulators = stream shortcuts.
        They often parallel ios member functions, but are cleaner inside I/O expressions.
            i.e. manipulators make formatting cleaner and inline.
        Use <iomanip> for manipulators with parameters.
        Formatting changes persist for that stream until reset.
            Most manipulators affect only the next operation (e.g., setw).
            Format changes (like hex, boolalpha) persist until changed.

*/  




/* Example 1:  Following includes setfill() and setw() so we have to include <iomanip> */
#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::hex << 100 << std::endl ;         // 64
    std::cout << std::oct << 10 << std::endl ;          // 12
    std::cout << std::setfill('X') << std::setw(10) ;
    std::cout << 100 << " hi " << std::endl ;           // XXXXXXXX64 hi

    std::cout << std::boolalpha << true << " " << false;     // true false

    return 0;
}




/* Example 2: Following demonstrates boolalpha. 

            OUTPUT should be:
                Before boolalpha:   1  0
                After boolalpha:    true false
*/

#include <iostream>
#include <iomanip>

int main() {
    bool b;

    std::cout << " Before boolalpha:\t";
    b = true ;
    std::cout << b <<" ";
    b = false ;
    std::cout << b << std::endl;

    std::cout << " After boolalpha:\t";
    b = true ;
    std::cout << std::boolalpha << b << " ";
    b = false ;
    std::cout << b << std::endl;
    
    return 0;
}




// ----  rev[22-Sep-2025]  ----


/* Example 3: Following program displays a table of the squares and square roots of the numbers 2 through 20.
                (recall Example 3 ch12_03_width_precision_fill.cpp)
                This version uses "I/O manipulators" instead of member functions and format flags. 
*/

#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double x;

    std::cout << setprecision (4) ;
    std::cout << " x sqrt (x) x^2\ n\n";

    for(x = 2.0; x <= 20.0; x++) {
        std::cout << std::setw(7) << x << " ";
        std::cout << std::setw(7) << sqrt(x) << " ";
        std::cout << std::setw(7) << x*x << '\n';
    }
}




/* Example 4: One of the most "interesting format flags" added by the new I/O library is "boolalpha".
                This flag can be set either directly or by using the new manipulators boolalpha or noboolalpha.

                What makes boolalpha so interesting is that setting it allows you to
                    input and output "Boolean values" using the keywords "true" and "false".

                Normally you must enter 1 for true and 0 for false.
*/

// Demonstrate boolalpha format flag .
# include <iostream >
using namespace std ;
int main ()
{
bool b;
cout << " Before setting boolalpha flag : ";
b = true ;
cout << b << " ";
b = false ;
cout << b << endl ;
cout << " After setting boolalpha flag : ";
b = true ;
cout << boolalpha << b << " ";
b = false ;
cout << b << endl ;
cout << " Enter a Boolean value : ";
cin >> boolalpha >> b; // you can enter true or false
cout << " You entered " << b;
return 0;
}


// Here is a sample run:
// Before setting boolalpha flag: 1 0



/* 
After setting boolalpha flag: true false
Enter a Boolean value: true
You entered true
As you can see, once the boolalpha flag has been set, Boolean values are input and
output using the words true or false. Notice that you must set the boolalpha flags for
cin and cout separately. As with all format flags, setting boolalpha for one stream does
not imply that it is also set for another. 
*/



/* Example 5: Redo Exercises 1 and 2 from Section 8.3, this time using I/O manipulators instead of
member functions and format flags. 
*/

1a. // Create a table of log10 and log from 2 through 100.
# include <iostream >
# include <iomanip >
# include <cmath >
using namespace std ;
int main ()
{
double x;
cout . precision (5) ;
cout << " x log x ln e\n\n";
for (x = 2.0; x <= 100.0; x++)
{
cout << setw (10) << x << ’ ’;
cout << setw (10) << log10 (10) << ’ ’;
cout << setw (10) << log (x) << ’\n’;
}
return 0;
}


1b. # include <iostream >
# include <iomanip >
# include <cstring >
using namespace std ;
void center ( char *s);
int main ()
{
center ("Hi there !");
center ("I like C ++.");
return 0;
}
void center ( char *s)
{
int len ;
len = 40+( strlen (s)/2);
cout << setw ( len ) << s << ’\n’;
}




/* Example 6: Show the I/O statement that outputs the value 100 in hexadecimal with the base indicator
(the 0x) shown. Use the setiosflags() manipulator to accomplish this. 
*/
2. cout << setiosflags ( ios :: showbase | ios :: hex ) << 100;


/* Example 7: Explain the effect of setting the boolalpha flag. */

3. Setting the boolalpha flag on an output stream causes Boolean values to be displayed
using the words true and false. Setting boolalpha on an input stream allows you to enter
Boolean values using the words true and false.


