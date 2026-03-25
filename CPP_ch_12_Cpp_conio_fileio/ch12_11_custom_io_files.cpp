
/*  ------------------------    Customized I/O And Files    ------------------------

    General Principle of Stream Operations:
        Overloaded inserters "<<", extractors ">>", and I/O manipulators can be used 
        with "any stream" as long as they are written in a general manner.

        Because all C++ streams share the same underlying structure,
            the same overloaded inserter function can be used to output 
            to the screen "cout" or to a file "ofstream" without requiring any changes.


    Avoid Hard-Coding:
        Do not "hard-code" a specific stream (e.g., "cout") into an I/O function.
        because it will be limited to only that stream. 
        
        "Hard-coding" limits the function's use to only that specific stream.
        Thats why we generalize the I/O functions whenever possible. 
        (Recall "ch12_05_inserter_extractor.cpp" : Make inserter/extractor as general as possible)
*/  




/* Example 1: In the following program, the "coord" class overloads the << and >> operators. 
                The program uses these operator functions to write data to both the "screen" and a "file". 

                Class Setup: The coord class uses friend functions for input and output.

                Saving: An ofstream object (out) uses << to save coordinates to a file.
                Loading: An ifstream object (in) uses >> to read that data into new objects.

                Displaying: 
                    The same << operator works with "cout", 
                    showing the code is reusable for both files and the screen.
*/

#include <iostream>
#include <fstream>

class coord {
        int x, y;
    public:
        coord(int i, int j) { x = i; y = j; }
        
        // Friend functions for overloading operators
        friend std::ostream &operator <<(std::ostream &stream, coord ob);
        friend std::istream &operator >>(std::istream &stream, coord &ob);
};


// Overload << operator
std::ostream &operator <<(std::ostream &stream, coord ob) {
            stream << ob.x << ' ' << ob.y << '\n';
            return stream;
}

// Overload >> operator
std::istream &operator >>(std::istream &stream, coord &ob) {
            stream >> ob.x >> ob.y;
            return stream;
;}


int main() {
    coord o1(1, 2), o2(3, 4);

    // Writing to File
    std::ofstream out("test");
    if(!out) {
        std::cout << "Cannot open output file.\n";
        return 1; 
    }
    out << o1 << o2;    // Uses overloaded << to store values in a file
    out.close();

    // Reading from File
    std::ifstream in("test");
    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }
    coord o3(0, 0) , o4(0, 0);  // Initialize objects where values will be stored.
    in >> o3 >> o4;     // Uses overloaded >> to read from "in"

    // Output the values to Screen
    std::cout << o3 << o4;      // Uses overloaded << to print the values to screen
    in.close ();

    return 0;
}




/* Example 2: All of the I/O manipulators can be used with files. 
                Following progranm is a reworked version of "Example 3" from "ch12_06_custom_manipulators.cpp".
                In this case the same manipulator that writes to the screen will also write to a file. 
*/

// ---- rev[25-Mar-2026] ----


# include <iostream >
# include <fstream >
# include <iomanip >
using namespace std ;
// Attention :
ostream & atn ( ostream & stream )
{
stream << " Attention : ";
return stream ;
}
// Please note :
ostream & note ( ostream & stream )
{
stream << " Please Note : ";
return stream ;
}
int main ()
{
ofstream out (" test ");

if (! out )
{
cout << " Cannot open output file .\n";
return 1;
}
// write to screen
cout << atn << " High voltage circuit \n";
cout << note << " Turn off all lights \n";
// write to file
out << atn << " High voltage circuit \n";
out << note << " Turn off all lights \n";
out . close ();
return 0;
}
