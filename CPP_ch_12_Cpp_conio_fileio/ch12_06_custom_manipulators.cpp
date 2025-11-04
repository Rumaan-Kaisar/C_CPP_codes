
/*  ------------------------    Custom manipulators    ------------------------
    
    Manipulators are special functions used with input/output streams (cin, cout).
    They help format data or perform repeated stream operations easily.


    Custom manipulators are important for two main reasons. 

    Combine repeated I/O steps:
        A custom manipulator can group several separate I/O operations that occur often in a program, 
        so we can perform them with a single command.

    Handle special devices:
        A custom manipulator allows us to perform I/O with "nonstandard devices" -
        for example, sending control codes to special hardware like printers or optical recognition systems.


    --------  Types of Manipulators  --------
    There are two basic types of manipulators: 
        Input stream manipulators (work with cin)
        Output stream manipulators (work with cout)

    There is a secondary division: 
        Parameterized manipulators
            Example: setw(10)
            
            Creating Parameterized manipulators is different across compilers, and 
            the steps are not consistent.
            So, for now, we will not cover how to create parameterized manipulators.

        Parameterless manipulators:
            Example: endl, flush
            (Easy and consistent across compilers.)



    --------  parameterless manipulators  --------
    
    The creation of parameterless manipulators is straightforward and the same for all compilers. 
    These follow a standard function format and always:
        Take a reference to the stream they operate on
        Return that same stream reference, allows chaining like:

                cout << manip1 << manip2;


    OUTPUT Manipulator Skeleton:
        All parameterless Output Manipulator Functions (used with 'cout') have this skeleton:

                ostream &manip_name( ostream &stream ) {
                    // your code here
                    return stream;
                }

            Here manip_name is the name of the manipulator and stream "&stream" is a reference to 
                the "invoking stream" which must be returned by the manipulator "return stream;".  
                This is necessary if a manipulator is used as part of a larger I/O expression. 

            Here the manipulator has a single argument "a reference to the stream upon which it is operating", 
                but no argument will be used when the manipulator is called in an output operation.


    INPUT Manipulator Skeleton:
        All parameterless Input Manipulator Functions (used with 'cin') have this skeleton:

                istream &manip_name( istream &stream ) {
                    // your code here
                    return stream;
                }

            An input manipulator receives a reference to the stream on which it was invoked. 
            This stream must be returned by the manipulator.


    The key point:
        The stream must be returned so it can continue to be used in a longer input/output expression.
*/  




/* Example 1: Following creates a manipulator called setup() that sets 
                    field width to 10, 
                    precision to 4, and 
                    fill character to *. 
*/

#include <iostream>

std::ostream &setup(std::ostream & stream) {
    stream.width(10);
    stream.precision(4);
    stream.fill('*');
    return stream;
}

int main() {
    std::cout << setup << 123.123456;
    return 0;
}




/* Example 2: Following creates the getpass() input manipulator, 
                which rings the 'bell' and then prompts for a 'password'. 

                It Won't run on online compilers like: codechef, GeeksforGeeks, HackerRank
                install: GCC
                    https://winlibs.com/ 
                    downloads: 
                        UCRT runtime, 
                        GCC 15.2.0 (with POSIX threads) + MinGW-w64 13.0.0 (UCRT) - release 2

                Or, install "Code::Blocks" with integrated GCC compiler
*/

#include <iostream>
#include <cstring>

// A simple input manipulator
std::istream &getpass(std::istream & stream) {
    std::cout << '\a'; // sound bell
    std::cout << " Enter password : ";
    return stream;
}

int main() {
    char pw[80];

    do {
        std::cin >> getpass >> pw;
    } while(strcmp (pw , "password"));

    std::cout << " Logon complete \n";

    return 0;
}




/* Example 3: Custom manipulators don't have to be complicated to be useful. 
                For instance, the simple manipulators atn() and note() shown here 
                give a quick way to print commonly used words or phrases.

                These simple manipulators can save you from some tedious typing, if those words are frequently used!!
*/

#include <iostream>

// Attention :
std::ostream &atn(std::ostream & stream) {
    stream << " Attention : ";
    return stream ;
}

// Please note :
std::ostream &note(std::ostream & stream) {
    stream << " Please Note : ";
    return stream ;
}

int main() {
    std::cout << atn << " High voltage circuit \n";
    std::cout << note << " Turn off all lights \n";
    return 0;
}




/* Example 4: Create an "OUTPUT manipulator" that displays the current "system time and date". 
                Call this manipulator td(). 
*/

#include <iostream>
#include <ctime>

// A time and date output manipulator
std::ostream &td(std::ostream & stream) {
    struct tm *localt;
    time_t t;

    t = time(NULL);
    localt = localtime(&t);

    stream << asctime(localt) << std::endl;
    return stream;
}


int main() {
    std::cout << td << '\n';
    return 0;
}




/* Example 5: Create an "OUTPUT manipulator" called sethex() that sets output to "hexadecimal" 
                and turns on the "uppercase" and "showbase" flags. 
                
                Also, create an "OUTPUT manipulator" called reset() that UNDOES the changes made by sethex(). 
*/

#include <iostream>

// Turn on hex output with uppercase 'X'
std::ostream &sethex(std::ostream & stream) {
    stream.unsetf(std::ios::dec | std::ios::oct);
    stream.setf(std::ios::hex | std::ios::uppercase | std::ios::showbase);
    return stream;
}

// Reset flags
std::ostream &reset(std::ostream & stream) {
    stream.unsetf(std::ios::hex | std::ios::uppercase | std::ios::showbase);
    stream.setf(std::ios::dec);
    return stream;
}


int main() {
    std::cout << sethex << 100 << '\n';
    std::cout << reset << 100 << '\n';

    return 0;
}




/* Example 6: Create an input manipulator called skipchar() that 
                reads and ignores the next ten characters from the input stream. 
*/

#include <iostream>

// Skip 10 characters .
std::istream &skipchar(std::istream & stream) {
    int i;
    char c;

    for(i =0; i <10; i ++) stream >> c;
    return stream;
}


int main() {
    char str [80];

    std::cout << " Enter some characters : ";
    std::cin >> skipchar >> str;
    std::cout << str << '\n';

    return 0;
}


