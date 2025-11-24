
// ----  rev[31-Oct-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-




// rev[20-Nov-2025]




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.


/* Example 1: Write a program that displays the sentence "C++ is fun" 
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




/* Example 2: Write a program that displays the outcome of 10/3 to "three decimal places". 
                Use "ios member functions" to do this. 
*/

#include <iostream>

int main() {
    std::cout . precision (4) ;
    std::cout << 10.0/3.0 << '\n';
    return 0;
}




/* Example 3: Redo the preceding program using I/O manipulators. */

#include <iostream>
#include <iomanip>

int main() {
    std::cout << setprecision(4) << 10.0/3.0 << '\n';
    return 0;
}




/* Example 4: What are INSERTER and EXTRACTOR ? 
                
            inserter:
                an overloaded operator<<() function that OUTPUTS a class's data to an output stream. 
            
            extractor:
                an overloaded operator>>() function that INPUTS a class's data from an input stream
*/



// rev[21-Nov-2025]




/* Example 5: Given the following class, create an INSERTER and an EXTRACTOR for it.
                class date {
                        char d[9]; // store date as string : mm/dd/yy
                    public :
                        // add inserter and extractor
                };
*/

5. # include <iostream >
using namespace std ;
class date
{
char d [9]; // store date as string : mm/dd/yy
public :
friend ostream & operator <<( ostream &stream , date ob);
friend istream & operator >>( istream &stream , date &ob);
};
ostream & operator <<( ostream &stream , date ob)
{
stream << ob.d << ’\n’;
return stream ;
}
istream & operator >>( istream &stream , date &ob)
{
cout << " Enter date (mm/dd/yy): ";
stream >> ob.d;
return stream ;
}
int main ()
{
date ob;
cin >> ob;
cout << ob;
return 0;
}




/* Example 6: What header must be included if your program is to use I/O manipulators that take
parameters? */

6. To use a parameterized manipulator, you must include <iomanip> in your program.



/* Example 7: What predefined streams are created when a C++ program begins execution? */

7. The predefined streams are cin, cout, cerr, and clog.



