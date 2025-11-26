
/*  ------------------------    width, precision, fill    ------------------------

    width(), precision(), and fill() – Stream Formatting Functions
        These are member functions of "std::ios" (used with streams like cout, cin) 
        to control how data is formatted during input/output.

    To set these format parameters: 
        the field width, 
        the precision, and 
        the fill character, 
        
        thse are three member functions defined by "std::ios":

        width():
            specify a minimum field width (padding spaces or fill chars).

        precision():
            number of digits for floating-point output.

        fill():
            padding character when width is not filled.

    Together, these are part of the C++ stream formatting system, "defined" inside the
    std::ios_base / std::ios hierarchy



    --------  Stream Formatting Functions  --------

    width(): 
        Purpose: Sets the minimum field width for the next output/input operation.
        
        Prototype:
                streamsize width(streamsize w);

        What it does:
            "w" becomes the new minimum "field width".
            Returns the previous width.
            "streamsize" is a type defined in <iostream> as a some kind of integer type.
        
        Important points:
            Must be set before each output/input — it is reset after each operation.
            If output is shorter than width, it's padded with the fill character (space by default).
            If the size of the output value exceeds the minimum field width, the field will be overrun.
                No truncation, the entire value is printed 
        


    precision():
        Purpose: Sets the number of digits after the decimal point for floating-point numbers.

        Prototype:
                streamsize precision(streamsize p);

        What it does:
            Sets precision to p (e.g., 4 means 4 digits after decimal).
            Returns the previous precision.
            Default: 6 digits.

        Note:
            Precision setting persists until changed again.



    fill()
        Purpose: Sets the "character" used to "pad fields" when width is larger than value.

        Prototype:
                char fill(char ch);

        What it does:
            "ch" becomes the new "fill character".
            Returns the previous fill character.
            Default: space ' '.


    NOTE: 
        These differ from MANIPULATORS (like std::setw, std::setprecision, std::setfill), 
        They do the same job but are used differently.
        We'll discuss manipulators in the next section

        Use these functions to:
            Align output (e.g., tables, reports)
            Control decimal places
            Customize padding and appearance

        Always set width() just before the value you want to format! 

*/  




/* Example 1: Following is a program that illustrates the format functions.
                
                Output should be:
                    hello
                    %%%%%hello
                    hello%%%%%
                    123.234567
                    123.235%%%

                Notice that the field width is set before each output statement.
*/

#include <iostream>

int main() {
    std::cout.width(10) ;        // set minimum filed width
    std::cout << "hello" << '\n';     // right - justify by default

    std::cout.fill('%');    // set fill character
    std::cout.width(10);    // set width
    std::cout << "hello" << '\n';     // right - justify default

    std::cout.setf( std::ios::left ); // left - justify
    std::cout.width(10) ; // set width
    std::cout << "hello" << '\n'; // output left justified

    std::cout . width (10) ; // set width
    std::cout . precision (10) ; // set 10 digits of precision
    std::cout << 123.234567 << '\n';

    std::cout . width (10) ; // set width
    std::cout . precision (6) ; // set 6 digits of precision
    std::cout << 123.234567 << '\n';

    return 0;
}




/* Example 2: The following program shows how to use the C++ I/O format functions 
                to create an aligned table of numbers.
*/

// Create a table of square roots and squares .
#include <iostream>
#include <cmath>

int main() {
    double x;

    std::cout.precision(4);
    std::cout << "      x  sqrt(x)    x^2\n\n";

    for(x=2.0; x<=20.0; x++) {
        std::cout.width(7);
        std::cout << x << " ";

        std::cout.width(7);
        std::cout << sqrt (x) << " ";

        std::cout.width(7);
        std::cout << x*x << '\n';
    }

    return 0;
}




/* Example 3: Create a program that prints the "natural log" and "base 10 log" of the numbers from 2 to 100.
                Format the table so that:
                    the numbers are "right justified" 
                    within a field width of 10,
                    using a precision of five decimal places. 
*/

// Create a table of 'log10' and 'log' from 2 through 100.
#include <iostream>
#include <cmath>


int main(){
    double x;

    std::cout.precision(5);
    std::cout << " x log x ln e\n\n";

    for(x = 2.0; x <= 100.0; x++) {
        std::cout.width(10);
        std::cout << x << ' ';

        std::cout.width(10);
        std::cout << log10(x) << ' ';

        std::cout.width(10);
        std::cout << log(x) << '\n';
    }

    return 0;
}




/* Example 4: Create a function called center() that has this prototype:
                    void center(char *s);
                Have this function center the specified string on the screen. 

                To accomplish this, use the width() function. 
                Assume that the screen is 80 characters wide. 
                (For simplicity, you may assume that no string exceeds 80 characters.) 

                Write a program that demonstrates that your function works. 
*/

#include <iostream>
#include <cstring>

void center(char *s);

int main() {
    center("Hi there !");
    center("I like C ++.");

    return 0;
}


void center(char *s) {
    int len;

    len = 40 + (strlen(s)/2);
    std::cout.width(len);
    std::cout << s << '\n';
}




/* Example 5: Write a program that displays the value 1000.5364 in a 
                    20-character field, 
                    left justified,
                    with two decimal places, 
                using * as a fill character. (Use the ios format flags.) 
*/

#include <iostream>

int main() {
    std::cout.setf( std::ios::left);
    std::cout.precision(2);
    std::cout.fill('*');
    std::cout.width(20);
    std::cout << 1000.5364 << '\n';

    return 0;
}




/* Example 6: Write a program that displays the sentence "C++ is fun" 
                in a 40-character-wide filed
                using a colon (:) as the "fill character". 
*/

#include <iostream>

int main() {
    std::cout.width (40) ;
    std::cout.fill (':');
    std::cout << "C++ is fun " << '\n';
    
    return 0;
}




/* Example 7: Write a program that displays the outcome of 10/3 to "three decimal places". 
                Use "ios member functions" to do this. 
*/

#include <iostream>

int main() {
    std::cout.precision(4);
    std::cout << 10.0/3.0 << '\n';
    return 0;
}




/* Example 8: Redo the preceding program using I/O manipulators (discussed next section). */

#include <iostream>
#include <iomanip>

int main() {
    std::cout << std::setprecision(4) << 10.0/3.0 << '\n';
    return 0;
}

