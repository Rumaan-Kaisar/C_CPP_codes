
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




Example 2: The following segment uses the C++ I/O format functions to create an aligned table of numbers:


int main(){ double x;
   cout.precision(4) ;
   cout<< ;	 {	cout.width(7); cout<<x<<" ";
				cout.width(7); cout<<sqrt(x)<<" ";
				cout.width(7); cout<<x*x<< '\n';}
return 0; }





----  Qwen  ----

Here is the simplified pointwise summary of the given content on width(), precision(), and fill():



🔹 Example 2: Creating a Neat Table
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
⌄
cout.precision(4);  // Set floating-point precision to 4 digits

cout << "x    sqrt(x)    x^2\n\n";

for(double x = 2.0; x <= 20.0; x++) {
    cout.width(7); cout << x << " ";
    cout.width(7); cout << sqrt(x) << " ";
    cout.width(7); cout << x*x << "\n";
}
Produces neatly aligned columns.
Each number takes up at least 7 characters, padded with spaces.




This program creates the following table:
x sqrt(x) x^2
2 1.414 4
3 1.732 9
4 2 16
5 2.236 25
6 2.449 36
7 2.646 49
8 2.828 64
9 3 81
10 3.162 100
11 3.317 121
12 3.464 144
13 3.606 169
14 3.742 196
15 3.873 225
16 4 256
17 4.123 289
18 4.243 324
19 4.359 361
20 4.472 400
EXERCISES



/* Example 3: Create a program that prints the "natural log" and "base 10 log" of the numbers from 2 to 100.
                Format the table so that:
                    the numbers are "right justified" 
                    within a field width of 10,
                    using a precision of five decimal places. 
*/

// Create a table of log10 and log from 2 through 100.
# include <iostream >
# include <cmath >

int main ()
{
double x;
cout . precision (5) ;
cout << " x log x ln e\n\n";
for (x = 2.0; x <= 100.0; x++)
{
cout . width (10) ;
cout << x << ' ';
cout . width (10) ;
cout << log10 (10) << ' ';
cout . width (10) ;
cout << log (x) << '\n';
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

# include <iostream >
# include <cstring >

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
cout . width ( len );
cout << s << '\n';
}




