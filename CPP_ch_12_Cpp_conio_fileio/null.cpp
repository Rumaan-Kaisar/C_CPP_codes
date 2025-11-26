
// ----  rev[31-Oct-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-




// rev[20-Nov-2025]




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.















// rev[21-Nov-2025]




/* Example 5: Given the following class, create an INSERTER and an EXTRACTOR for it.
                class date {
                        char d[9]; // store date as string : mm/dd/yy
                    public :
                        // add inserter and extractor
                };
*/

#include <iostream>

class date {
        char d[9]; // store date as string : mm/dd/yy
    public :
        friend std::ostream &operator<<( std::ostream &stream , date ob);   // inserter
        friend std::istream &operator>>( std::istream &stream , date &ob);  // extractor
};

// inserter
std::ostream &operator<<(std::ostream &stream, date ob) {
    stream << ob.d << '\n';
    return stream;
}

// extractor
std::istream &operator>>(std::istream &stream, date &ob) {
    std::cout << " Enter date (mm/dd/yy): ";
    stream >> ob.d;
    return stream;
}

int main() {
    date ob;
    std::cin >> ob;
    std::cout << ob;
    return 0;
}




/* Example 6: What header must be included if your program is to use "I/O manipulators" that take parameters? 

            ans:
                To use a parameterized manipulator, we must include <iomanip> in our program.
*/





/* Example 7: What predefined streams are created when a C++ program begins execution? 

            ans:
                The predefined streams are cin, cout, cerr, and clog.
*/




