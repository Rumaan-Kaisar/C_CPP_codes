
/*  ------------------------    Formatted I/O    ------------------------

    It is possible to output information in a wide variety of forms using C++'s I/O system 
        as we did before with  C's printf() function


        Format flags control things like:
            How numbers are displayed (decimal, hexadecimal, scientific notation, etc.)
            Text alignment (left or right)
            Whether to show signs (+ or -) for positive numbers
            Precision, filling characters, uppercase/lowercase, etc.


    C++ Format Flags (like printf in C):
        C++ streams (like 'cout') have "format flags" that control how output looks.
        You can think of them as switches that you can turn 'on' or 'off' to change the output format.
        These flags are part of the "ios" class and are grouped under a bitmask enumeration called "fmtflags".


    These values are used to set or clear the format flags and are defined within ios.
    Note: "ios" is in the "std" namespace, so you have to use std::ios to acces these

        adjustfield
        basefield
        boolalpha
        dec
        fixed
        floatfield
        hex
        internal
        left
        oct
        right
        scientific
        showbase
        showpoint
        showpos
        skipws
        unitbuf
        uppercase



    Whitespace handling:
        skipws:         When the skipws flag is set, whitespace characters 
                        (spaces, tabs, and newlines) will be cleared for new input. 
                        (default ON)
                        When skipws is cleared, whitespace characters are not discarded.	


    Justification (Alignment): 
        Default is "right".
        left, right:    flags make- left and right justified output (e.g., "    10" or "10    ").
        internal:       Pads the inside of a number, between the sign and the value (e.g., "+   10").


    Number Base
        dec (Default):  Displays numbers in base 10 (e.g., 255).
        oct, hex:       produce octal and hexadecimal output respectively. 
        
        To return output to decimal, set the dec flag.

        showbase: Shows the base prefix (e.g., 0xff for hex, 0377 for oct).


    Boolean Values
        boolalpha:      Displays true and false as words instead of 1 and 0.
        
        Booleans can be input or output using the keywords true and false, when boolalpha is set.


    Floating-Point Numbers:
        scientific:     Uses scientific notation (e.g., 1.5e+10).
        fixed:          Uses standard decimal notation (e.g., 15000000000.000000).
        showpoint:      Always shows the decimal point ".000000", even for whole numbers (e.g., 10.0 instead of 10).
        uppercase:      Uses uppercase letters (E, not e) in scientific/hex notation (e.g., 1.5E+10, 0XFF).

        By default, the scientific notation "e" and hexadecimal notation "x" is displayed in lowercase, 
        setting uppercase flag displays these characters in uppercase.
        When neither flag is set, the compiler chooses an appropriate method.


    Number Sign
        showpos:        Displays a + sign for positive numbers (e.g., +10 instead of 10).


    Buffer Control
        unitbuf:        Flushes the output buffer after each insertion operation.
                        Ensures data is written immediately.



    --------  Format Flag Groups  --------
    Some flags work together as groups. When you set a group, you clear all other flags in that same group.

        basefield:      The group for number base (dec, hex, oct).
        adjustfield:    The group for justification (left, right, internal).
        floatfield:     The group for floating-point notation (scientific, fixed).


        Group           Flags
        --------------------------------------
        basefield       dec, oct, hex
        adjustfield     left, right, internal
        floatfield      fixed, scientific


    Notes:
        Flags can be combined, set, or cleared using stream member functions like 
        setf(), unsetf(), or manipulators like std::hex.

        These flags affect how data is displayed or input through streams like cin, cout, etc.



    ----------------    set a format flag : setf()    ----------------
    setf():
        To set a format flag, use the setf() function which is a member of ios.

        Its form is:
                        fmtflags setf( fmtflags flags );

            Sets one or more format flags for a specific stream
            This function returns the previous settings of the format flags and 
            turns "on" those flags specified by "flags". 
            (All other flags are unaffected. Does not affect flags that are not mentioned)  


            For example, to turn on the showpos flag:

                        stream.setf( ios :: showpos );  // turns on showpos for the stream

                Here "stream" is the stream that you wish to affect. 

                Notice the use of the scope resolution operator (::). 
                    Because the format flags are defined within the "ios" class, 
                    you must access their values by using "ios" and the scope resolution operator. 


        Notes:
            setf() must be called on a specific stream like cout, cin, etc.
            Flags like showpos, showbase, hex are part of the "ios" class, so you must use ios::flagname
                Otherwise showpos/showbase/hex will not be recognized. 
                We must specify  ios::showpos or ios::showbase or ios::hex.
            
            There is no concept in C++ of global format status. 
            Each stream maintains its own format status information individually.



    Setting Multiple Flags Together:
        in a single call to setf() use "OR" together the values of the flags. 
        For example, this call sets the showbase and hex flags for cout:
        
                    cout.setf(  ios::showbase | ios::hex );




    ----------------    clearing format flags : unsetf()    ----------------
    unsetf():
        The complement of setf() is unsetf().
        This member function of ios clears one or more format flags. Its prototype form is:

                        void unsetf( fmtflags flags );

            The flags specified by "flags" are cleared. (All other flags are unaffected.)

        Example:
            cout.unsetf(ios::hex);      // turns off hex format




    --------  current format settings & set/reset  --------
    flags():
        use flags() to know the current format settings without altering
        Its a special member function of ios, its prototype is:   

                        fmtflags flags();

        set/reset ability:
            The flags() also allows to set/reset all format flags associated with 
                a stream to those specified in the argument to flags(). 
            The prototype for this version of flags() is:

                        fmtflags flags( fmtflags f);

                For this version, the bit pattern found in "f" is copied to the variable used to hold the format flags 
                    associated with the stream, and overwrites all previous flag settings. 
                The function returns the previous settings.


        To Read Current Settings:
                        fmtflags current = stream.flags();

        To Set All Flags at Once:
                        stream.flags(ios::dec | ios::showpos);  // replaces all existing flags

        Returns: the old settings before the change
*/  




/* Example 1: Following program shows how to set several flags. 

                This program displays: 
                    1.232300e+02    hello   64      a  fffffff6     +100.000000

                Here showpos flag affects only decimal output (i.e. a  fffffff6 is unaffected). 
                    It does not affect the value 10 when output in Hexadecimal or Octal. 

                Also notice the unsetf() call that turns off the "dec" flag (which is on by default). 
                    It is necessary to turn it off when turning on either hex or oct. 

                In general, it is better to set only the number base that you want to use and clear the others.


                In some compilers, dec can override hex or oct.
                For portability, clear the unwanted base flag before setting a new one.

                Good practice:
                    Always set the base you want (dec, hex, oct)
                    Always unset the others to avoid conflicts.
*/

#include <iostream>

int main(){
    // display using default settings
    std::cout << 123.23 << " hello " << 100 << '\n';
    std::cout << 10 << ' ' << -10 << '\n';
    std::cout << 100.0 << "\n\n";

    // now , change formats
    std::cout.unsetf( std::ios::dec ); // not required by all compilers

    std::cout.setf( std::ios::hex | std::ios::scientific );
    std::cout << 123.23 << " hello " << 100 << '\n';

    std::cout.setf ( std::ios::showpos );
    std::cout << 10 << ' ' << -10 << '\n';

    // --- Reset both basefield + floatfield before applying new style ---
    // std::cout.setf(static_cast<std::ios_base::fmtflags>(0), std::ios::basefield);
    // std::cout.setf(static_cast<std::ios_base::fmtflags>(0), std::ios::floatfield);

    std::cout.setf ( std::ios::showpoint | std::ios::fixed );
    std::cout << 100.0;

    return 0;
}


/*  This program displays the following output:

        123.23 hello 100
        10 -10
        100

        1.232300e+02 hello 64
        a fffffff6
        +0x1.9p+6


    In the last output, why its not showing "+100.000000 "  instead it shwowing "+0x1.9p+6"?

    GPT explanation:
        In our code, we call:

                std::cout.setf(std::ios::hex | std::ios::scientific);

            This sets hexadecimal integer output (std::ios::hex) and scientific notation for floating-point numbers.

        Later we do:

                std::cout.setf(std::ios::showpoint | std::ios::fixed);

            But we never cleared the "std::ios::hex" flag for floating-point output.
            In C++, std::ios::hex affects both integer and floating-point formatting 
            (in the latter case, it triggers C++11 s hexfloat style).


        What +0x1.9p+6 means:
            This is the hexadecimal floating-point representation of 100.0:


        How to fix it:
            To properly restore decimal floating-point output, you must reset the floatfield and the basefield before applying new flags.

                // --- Reset both basefield + floatfield before applying new style ---
                // Following won't work actually
                std::cout.setf(0, std::ios::basefield);   // clear dec/hex/oct
                std::cout.setf(0, std::ios::floatfield);  // clear fixed/scientific/hexfloat

            Note: 
                std::ios_base::setf() expects an argument of type std::ios_base::fmtflags, not a raw int.
                Use "static_cast" to tell the compiler we mean a “no flags” value of type fmtflags
                so instead of '0' we'll use 'static_cast<std::ios_base::fmtflags>(0)'

                // --- Reset both basefield + floatfield before applying new style ---
                std::cout.setf(static_cast<std::ios_base::fmtflags>(0), std::ios::basefield);
                std::cout.setf(static_cast<std::ios_base::fmtflags>(0), std::ios::floatfield);
*/




/* Example 2: The following program illustrates the effect of the "uppercase flag". 
                It first enable uppercase, showbase, and hex flags to output: "99" in hexadecimal
                Then disables the uppercase.

                In this case, the 'X' used in the hexadecimal notation is uppercase. 
                Next, it clears the uppercase flag by using unsetf() 
                and again outputs 99 in hexadecimal. This time, the 'x' is lowercase.

            output:
                0X63
                0x63
*/

#include <iostream>

int main(){
    std::cout.unsetf( std::ios::dec );

    std::cout.setf( std::ios::uppercase | std::ios::showbase | std::ios::hex );
    std::cout << 99 << '\n';

    std::cout.unsetf( std::ios::uppercase );
    std::cout << 99 << '\n';

    return 0;
}



// ----  rev[21-Aug-2025]  ----

/*  Example 3: Following uses flags() to display the settings of the format flags relative to "cout". 
                Pay special attention to the showflags() function. 
                    It displays which flag is on and which is off.
                    You might find it useful in programs you write.
            
            output:
                skipws on
                left off 
                right off 
                internal off 
                dec on
                oct off 
                hex off 
                showbase off 
                showpoint off 
                showpos off 
                uppercase off 
                scientific off 
                fixed off 
                unitbuf off 
                boolalpha off 

                skipws on
                left off 
                right off 
                internal off 
                dec on
                oct on
                hex off 
                showbase on
                showpoint off 
                showpos off 
                uppercase off 
                scientific off 
                fixed on
                unitbuf off 
                boolalpha off 
*/





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


// Inside showags(), the local variable f is declared to be of type fmtflags. If your compiler does not define fmtflags, declare this variable as long instead. 





#include <iostream>
using namespace std ;
void showflags ();
int main ()
{
// show default condition of format flags
showflags ();
cout . setf ( ios :: oct | ios :: showbase | ios :: fixed );
showflags ();
return 0;
}
// This function displays the status of the format flags .
void showflags ()
{
ios :: fmtflags f;
f = cout . flags (); // get flag settings
if(f & ios :: skipws )
cout << " skipws on\n";
else
cout << " skipws off \n";
if(f & ios :: left )
cout << " left on\n";
else
cout << " left off \n";
if(f & ios :: right )
cout << " right on\n";
else
cout << " right off \n";
if(f & ios :: internal )
cout << " internal on\n";
else
cout << " internal off \n";
if(f & ios :: dec )
cout << " dec on\n";
else
cout << " dec off \n";
if(f & ios :: oct )
cout << " oct on\n";
else
cout << " oct off \n";
if(f & ios :: hex )
cout << " hex on\n";
else
cout << " hex off \n";
if(f & ios :: showbase )
cout << " showbase on\n";
else
cout << " showbase off \n";
if(f & ios :: showpoint )
cout << " showpoint on\n";
else
cout << " showpoint off \n";
if(f & ios :: showpos )
cout << " showpos on\n";
else
cout << " showpos off \n";
if(f & ios :: uppercase )
cout << " uppercase on\n";
else
cout << " uppercase off \n";
if(f & ios :: scientific )
cout << " scientific on\n";
else
cout << " scientific off \n";
if(f & ios :: fixed )
cout << " fixed on\n";
else
cout << " fixed off \n";
if(f & ios :: unitbuf )
cout << " unitbuf on\n";
else
cout << " unitbuf off \n";
if(f & ios :: boolalpha )
cout << " boolalpha on\n";
else
cout << " boolalpha off \n";
cout << "\n";
}




Inside showflags(), the local variable f is declared to be of type fmtflags. If your
compiler does not define fmtflags, declare this variable as long instead. 

The output from the program is shown here:
skipws on
left off
right off
internal off
dec on
oct off
hex off
showbase off
showpoint off
showpos off
uppercase off
scientific off
214INTRODUCING THE C++ I/O SYSTEM
8.2. FORMATTED I/O
fixed off
unitbuf off
boolalpha off
skipws on
left off
right off
internal off
dec on
oct on
hex off
showbase on
showpoint off
showpos off
uppercase off
scientific off
fixed on
unitbuf off
boolalpha off




/* Example 4: The next program illustrates the second version of flags(). It first constructs a flag mask
that turns on showpos, showbase, oct, and right. It then uses flags() to set the flag
variable associated with cout to these settings. The function showflags() verifies that
the flags are set as indicated. (This is the same function used in the previous program.) */
# include <iostream >
using namespace std ;
void showflags ();
int main ()
{
// show default condition of format flags
showflags ();
// showpos , showbase , oct , right are on , others off
ios :: fmtflags f = ios :: showpos | ios :: showbase | ios :: oct
| ios :: right ;
cout . flags (f); // set flags
showflags ();
return 0;
}





/* Example 5: Write a program that sets cout's flags so that integers display a + sign when positive
values are displayed. Demonstrate that you have set the format flags correctly. */

# include <iostream >
using namespace std ;
int main ()
{
cout . setf ( ios :: showpos );
cout << -10 << ’ ’ << 10 << ’\n’;
return 0;
}




/* Example 6: Write a program that sets cout's flags so that the decimal point is always shown when
floating-point values are displayed. Also, display all floating-point values in scientific */
notation with an uppercase E.

# include <iostream >
using namespace std ;
int main ()
{
cout . setf ( ios :: showpoint | ios :: uppercase |
ios :: scientific );
cout << 100.0;
return 0;
}



/* Example 7: Write a program that saves the current state of the format flags, sets showbase and hex,
and displays the value 100. Then reset the flags to their previous values */

# include <iostream >
using namespace std ;
int main ()
{
ios :: fmtflags f;
f = cout . flags (); // store flags
cout . unsetf ( ios :: dec );
cout . setf ( ios :: showbase | ios :: hex );
cout << 100 << ’\n’;
cout . flags (f); // reset flags
return 0;
}

