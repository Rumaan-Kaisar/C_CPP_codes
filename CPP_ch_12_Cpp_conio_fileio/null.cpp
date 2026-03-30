


// ----  rev[27-Nov-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

At this point you should be able to perform the following exercises and answer the questions.


// custom manipulator (rev done)

/* Example 1: Following program uses an "output manipulator" that outputs "three tabs" 
                and then sets the field width to 20. 
                
                Demonstrate that the manipulator works.
*/

#include <iostream>

std::ostream & tabs( std::ostream &stream ) {
    stream << '\t' << '\t' << '\t';
    stream.width(20);
    return stream;
}

int main(){
    std::cout << tabs << " Testing \n";
    return 0;
}



// ----  rev[27-Mar-2026] ----


// custom manipulator (rev done)

/* Example 2: Following program uses an "input manipulator" 
                that reads and discards all non-alphabetical characters.

                When the first alphabetical character is read, 
                    have the manipulator return it to the "input stream" and return. 
                    
                Call this manipulator findalpha. 
*/

#include <iostream>
#include <cctype>

std::istream &findalpha( std::istream &stream ) {
    char ch;

    do {
        stream.get(ch);
    } while( !isalpha(ch) );

    return stream ;
}


int main() {
    char str[80];

    std::cin >> findalpha >> str;
    std::cout << str << '\n';

    return 0;
}




// 3, 4, 5 goes to "ch12_10_io_status_check.cpp"

/* Example 3: Following program copies a text file and reverse case of letters. */

#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[]) {
    char ch;

    if(argc!=3) {
        std::cout << " Usage : COPYREV <source > <target >\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in){
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    std::ofstream out(argv[2]);

    if(!out) {
        std::cout << " Cannot open output file .\n";
        return 1;
    }

    while(!in.eof()) {
        ch = in.get();

        if(!in.eof()) {
            if(islower(ch)) ch = toupper(ch);
            else ch = tolower(ch);
            out.put(ch);
        }
    }

    in.close();
    out.close();

    return 0;
}




/* Example 4: Following program reads a text file and then 
                counts how many times each letter appears in that file.
*/

#include <iostream>
#include <fstream>
#include <cctype>

int alpha[26];

int main(int argc, char *argv[]) {
    char ch;

    if(argc!=2) {
        std::cout << " Usage : COUNT <source>\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in) {
        std::cout << " Cannot open input file.\n";
        return 1;
    }

    // init alpha []
    int i;

    for(i=0; i<26; i++) alpha[i] = 0;

    while(!in.eof()) {
        ch = in.get();

        // if letter found , count it
        if(isalpha(ch)) {
            ch = toupper (ch); // normalize
            alpha [ch -'A']++; // 'A'-'A' == 0, 'B'-'A' == 1, etc.
        }
    }

    // display count
    for (i =0; i <26; i ++) std::cout << (char)('A'+i) << ": " << alpha[i] << '\n';
    
    in.close();

    return 0;
}




/* Example 5: Following are rewarked versions of 'Example 3' and 'Example 4' above.
                That does a complete error checking. 
*/

// Rewarked 1: Copy a file and reverse case of letters

#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[]) {
    char ch;

    if(argc!=3) {
        std::cout << " Usage : COPYREV <source> <target>\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in){
        std::cout << " Cannot open input file.\n";
        return 1;
    }

    std::ofstream out(argv[2]);

    if(!out) {
        std::cout << " Cannot open output file.\n";
        return 1;
    }

    while(!in.eof()) {
        ch = in.get();
        if(!in.good() && !in.eof()) return 1;   // Error checking

        if(!in.eof()) {
            if(islower(ch)) ch = toupper(ch);
            else ch = tolower(ch);
            out.put(ch);
            if(!out.good()) return 1;   // Error checking
        }
    }

    in.close();
    out.close();
    if (!in.good() && !out.good()) return 1;    // Error checking

    return 0;
}



// Rewarked 2: Count letters with error checking .

#include <iostream>
#include <fstream>
#include <cctype>

int alpha[26];

int main(int argc, char *argv[]) {
    char ch;

    if(argc!=2) {
        std::cout << " Usage : COUNT <source>\n";
        return 1;
    }

    std::ifstream in(argv[1]);

    if(!in) {
        std::cout << " Cannot open input file.\n";
        return 1;
    }

    // init alpha []
    int i;

    for(i=0; i<26; i++) alpha[i] = 0;

    while(!in.eof()) {
        ch = in.get();
        if(!in.good() && !in.eof()) return 1;   // Error checking

        // if letter found , count it
        if(isalpha(ch)) {
            ch = toupper (ch); // normalize
            alpha [ch -'A']++; // 'A'-'A' == 0, 'B'-'A' == 1, etc.
        }
    }

    // display count
    for(i =0; i <26; i ++) std::cout << (char)('A'+i) << ": " << alpha[i] << '\n';
    
    in.close();
    if (!in.good()) return 1;    // Error checking

    return 0;
}





/* Example 6: What function positions the get pointer? 
              What function positions the put pointer?

            ans:
                To set the get pointer, use seekg(). 
                To set the put pointer, use seekp().
*/











// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-




// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.

/* Example 1: Following is a reworked version of the inventory class 
                (Example 8 of "ch12_05_inserter_extractor.cpp").

                Write a program that fills in the functions store() and retrieve().                
                Next, create a small inventory file on disk containing a few entries. 
                
                Then, using random I/O, allow the user to display the information about any item 
                    by specifying its record number.


                Following is an inventory class is created that stores 
                    the name of an item, 
                    the number on hand and 
                    its cost. 
                The program includes both an "inserter" and an "extractor" for this class.


                #include <iostream>
                #include <fstream>
                #include <cstring>

                #define SIZE 40

                // inventory class
                class inventory {
                        char item[SIZE];    // name of item
                        int onhand;     // number on hand
                        double cost;    // cost of item

                    public:
                        inventory(char *i, int o, double c) {
                            strcpy(item, i);
                            onhand = o;
                            cost = c;
                        }

                        // fill these functions
                        void store( fstream & stream );
                        void retrieve( fstream & stream );

                        friend std::ostream &operator<<(std::ostream &stream, inventory ob);    // inserter
                        friend std::istream &operator>>(std::istream &stream, inventory &ob);   // extractor
                };


                // inserter
                std::ostream &operator<<( std::ostream &stream, inventory ob ) {
                    stream << ob.item << ": " << ob.onhand;
                    stream << " on hand at $" << ob.cost << '\n';
                    return stream;
                }

                // extractor
                std::istream &operator>>( std::istream &stream, inventory &ob ) {
                    std::cout << " Enter item name : ";
                    stream >> ob.item;

                    std::cout << " Enter number on hand : ";
                    stream >> ob.onhand;
                    
                    std::cout << " Enter cost : ";
                    stream >> ob.cost;
                    
                    return stream;
                }


                int main() {
                    inventory ob(" hammer ", 4, 12.55);

                    std::cout << ob;
                    std::cin >> ob;
                    std::cout << ob;

                    return 0;
                }


*/






1. # include <iostream >
# include <fstream >
# include <cstring >
using namespace std ;
# define SIZE 40
class inventory
{
char item [ SIZE ]; // name of item
int onhand ; // number on hand
double cost ; // cost of item
public :
inventory ( char *i, int o, double c)
{
strcpy (item , i);
onhand = o;
cost = c;
}
void store ( fstream & stream );
void retrieve ( fstream & stream );
friend ostream & operator <<( ostream &stream , inventory ob)
;
friend istream & operator >>( istream &stream , inventory &ob
);
};
ostream & operator <<( ostream &stream , inventory ob)
{
stream << ob. item << ": " << ob. onhand ;
stream << " on hand at $" << ob. cost << ’\n’;
return stream ;
}


istream & operator >>( istream &stream , inventory &ob)
{
cout << " Enter item name : ";
stream >> ob. item ;
cout << " Enter number on hand : ";
stream >> ob. onhand ;
cout << " Enter cost : ";
stream >> ob. cost ;
return stream ;
}
void inventory :: store ( fstream & stream )
{
stream . write (item , SIZE );
stream . write (( char *) & onhand , sizeof (int ));
stream . write (( char *) &cost , sizeof ( double ));
}
void inventory :: retrieve ( fstream & stream )
{
stream . read (item , SIZE );
stream . read (( char *) &onhand , sizeof (int ));
stream . read (( char *) &cost , sizeof ( double ));
}
int main ()
{
fstream inv (" inv ", ios :: out | ios :: binary );
int i;
inventory pliers (" pliers ", 12, 4.95) ;
inventory hammers (" hammers ", 5, 9.45) ;
inventory wrenches (" wrenches ", 22, 13.90) ;
inventory temp ("", 0, 0.0) ;
if (! inv )
{
cout << " Cannot open file for output .\n";
return 1;
}
// write to file
pliers . store ( inv );
hammers . store ( inv );
wrenches . store ( inv );
inv . close ();
// open for input

inv . open (" inv ", ios :: in | ios :: binary );
if (! inv )
{
cout << " Cannot open file for input .\n";
return 1;
}
do
{
cout << " Record # (-1 to quit ): ";
cin >> i;
if(i == -1)
break ;
inv . seekg (i*( SIZE + sizeof (int)+ sizeof ( double )), ios ::
beg );
temp . retrieve ( inv );
cout << temp ;
}
while ( inv . good ());
inv . close ();
return 0;
}


// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.

/* Example 1: Create a manipulator that causes numbers to be displayed in scientific notation, using a
capital E. */


1. # include <iostream >
using namespace std ;
ostream & setsci ( ostream & stream )
{
stream . setf ( ios :: scientific | ios :: uppercase );
return stream ;
}
int main ()
{
double f = 123.23;
cout << setsci << f;
cout << ’\n’;
return 0;
}




/* Example 2: Write a program that copies a text file. During the copy process, convert all tabs into the
correct number of spaces. */


2. // Copy and convert tabs to spaces .
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
if( argc !=3)
{
cout << " Usage : CPY <int > <out >\n";
return 1;
}
ifstream in( argv [1]) ;
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
ofstream out ( argv [2]) ;
if (! out )
{
cout << " Cannot open output file .\n";
return 1;
}
char ch;
int i = 8;
while (! in. eof ())
{
in. get (ch);
if(ch == ’\t’)
for ( ; i >0; i --)
out . put (’ ’);
else
out . put (ch);
if(i == -1 || ch == ’\n’)
i = 8;
i --;
}
in. close ();
out . close ();
return 0;
}




/* Example 3: Write a program that searches a text file for a word specified on the command line. Have
the program display how many times the specified word is found. For simplicity, assume
that anything surrounded by whitespace is a word. */


3. // Search file .
# include <iostream >
# include <fstream >
# include <cstring >
546ANSWERS
10.2 EXERCISES
using namespace std ;
int main ( int argc , char * argv [])
{
if( argc !=3)
{
cout << " Usage : SEARCH <file > <word >\n";
return 1;
}
ifstream in( argv [1]) ;
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
char str [255];
int count =0;
while (! in. eof ())
{
in >> str ;
if (! strcmp (str , argv [2]) )
count ++;
}
cout << argv [2] << " found " << count ;
cout << " number of times .\n";
in. close ();
return 0;
}




/* Example 4: Show the statement that sets the put pointer to the 234th byte in a file linked to a stream
called out. */

4. The statement is
out . seekp (234 , ios :: beg );




/* Example 5: What functions report status information about the C++ I/O system? */

5. The functions are rdstate(), good(), eof(), fail(), and bad().




/* Example 6: Give one advantage of using the C++ I/O functions instead of the C-like I/O system. */

6. The C++ I/O system can be customized to operate on classes that you create.

// -=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=--=-=-=-=-=-=-
