
/*  ------------------------    inserter and extractor    ------------------------

    ----------------    inserter    ----------------

    Insertion Operator '<<' (Output):
        Output in C++ is called insertion, using the '<<' operator.
        Eg: It "inserts" data into an output stream (like cout).


        OVERLOADING '<<' creates an INSERTER function (or inserter for short).

            General form:

                    ostream &operator<<(ostream &stream, class_name obj) {
                        // body of inserter
                        return stream;
                    }

                Returns a reference to 'stream', which is of type 'ostream'. so we can chain: 
                    cout << ob1 << ob2 << ob3;.

                First parameter: 
                    'ostream&' reference to an object of type ostream (output stream).
                    So 'stream' must be an output stream (e.g., cout, file streams).
                    ('ostream' is derived form the ios class.) 

                Second parameter: 
                    receives the object that will be output or printed
                    (This can also be a reference parameter, i.e. can be passed by value or const reference for efficiency).

            Inserter Cannot be a member function because 
                the left operand (cout) is not of the class type.



    ----------------    extractor    ----------------

    Extraction operator '>>' (Input):
        Input in C++ is called "extraction", and the >> is referred to as the extraction operator. 
        Eg: It "extracts" data from an input stream (like cin).

        The reason for this term is that the act of "inputting information from a stream" 
            removes (i.e. extracts) data from it.


        OVERLOADING '>>' creates an EXTRACTOR function.

            General form:

                    istream &operator>>(istream &stream, class_name &ob) {
                        // body of extractor
                        return stream;
                    }

                Return a reference to 'stream' , which is of type 'istream' an input stream. So chaining works: 
                    cin >> ob1 >> ob2;.

                First parameter: 
                    reference to an 'istream' (input stream).
                    So "istream&" must be an input stream (e.g., cin).

                Second parameter: 
                    reference to the object that receives input.


            Like inserter, an extractor cannot be a member function because
                left operand is a stream, not a class object.



    ---- '<<' and '>>' as Class Members ----

    Inserter and extractor cannot be a member of a class:
        If << or >> were class member functions, the left operand would have to be a class object.
        But in I/O, When you create an inserter/extractor, the left operand is a stream (cout, cin).
            and the right operand is the object that you want to output/input.
        So inserters/extractors cannot be a member function of a class.

    Recall: 
        If an overloaded operator function is a member of a class, 
        the left operand (which implicitly passed through 'this' and also generates the call to the operator) must be an object of that class. 

        But in "cout << obj", the left operand is "cout" (a stream), not obj.
        Hence, these operators must be non-member functions.



    ---- '<<' and '>>' as friend ----

    Inserter and extractor as friend of a class:  
        Inserters/extractors are often made friends of the class.
        An overloaded inserter will be a friend of the class for which it was created.
        This gives them access to private members (like x, y in coord).

        Example:
                class coord {
                        int x, y;
                    public:
                        coord(int i=0, int j=0): x(i), y(j) {}
                        friend ostream &operator<<(ostream &, coord);
                        friend istream &operator>>(istream &, coord &);
                };



    ---- Making Inserters/Extractors General ----

    Make inserter/extractor as general as possible:
        Always use the passed 'stream' parameter (e.g., stream << ...), not hard-coded 'cout' or 'cin' 
            (so that the code works for any stream.)

        In this case, the I/O statement inside the inserter/extractor outputs/inputs the values of x and y to "stream", 
            which is whatever stream is passed to the function 
            ( "stream" is general for cin, cout and both "<<" & ">>" can be used with it). 

        In the following chapter we'll see, when written correctly 
            the same inserter that outputs to the 'screen' can be used to output to 'any stream'. 

        This ensures the same function works with:
            cout, cerr as output
            File streams (ofstream, ifstream)
            String streams (stringstream)

        Avoid this mistake:
                cout << ob.x << ob.y;    // Bad: tied only to console

        Do this instead:
                stream << ob.x << ob.y;  // Good: works with any output stream


    However the following is not for general streaming:
        In this case, the output statement is "hard-coded" to display information on the standard output device linked to "cout". 
        This prevents the inserter from being used by 'other streams'. 

        Bad practice: 
                
                // hard-coding with 'cout' ties the inserter only to 'console output'.

                ostream &operator<<(ostream &stream, coord ob){
                    cout << ob.x << ", " << ob.y << '\n'; 	// using "cout" instead of  "stream"
                    return stream;
                }

        Good practice: 

                // use the passed stream (cout, file, etc.) 

                ostream &operator<<(ostream &stream, coord ob) {
                    stream << ob.x << ", " << ob.y;
                    return stream;
                }



    ----  Non-Friend Inserters/Extractors  ----

    If inserter/extractor are not friends to any class, they cannot use the "private members" of any class. 
    However all public members are accessible.

*/  



/* Example 1: This program contains an inserter and an extractor for the coord class. 
                
                Defines a class coord representing a 2D coordinate with x and y.
                
                Uses "operator overloading" to make input/output intuitive:
                    "operator<<" allows printing coordinates like "cout << a;"
                    "operator>>" allows reading coordinates like "cin >> a;"
                
                Demonstrates both reading and writing "object data" using normal I/O syntax.

                What’s Special About It:
                    Makes user-defined objects behave like built-in data types in I/O.
                    The stream (cout, cin, file) is passed as an argument, so the same function works universally.
                    Enables polymorphic stream behavior — you can output to: 
                            console, 
                            file, or even a 
                            network stream 
                        without changing the function.
*/

#include <iostream>
using namespace std;

class coord {
        int x, y;
    public:
        coord() { x = 0; y = 0; }
        coord(int i, int j) { x = i; y = j; }
        friend ostream &operator<<( ostream &stream, coord ob);      // inserter 
        friend istream &operator>>( istream &stream, coord &ob);     // extractor
};

// Inserter
ostream &operator<<(ostream &stream, coord ob) {
    stream << ob.x << ", " << ob.y << '\n';
    return stream ; 
}

// Extractor
istream &operator>>(istream &stream, coord &ob) {
    std::cout << " Enter coordinates : ";
    stream >> ob.x >> ob.y;
    return stream;
}

int main() { 
    coord a(1, 1), b(10, 23);

    std::cout << a << b;
    std::cin >> a;
    std::cout << a;
    
    return 0; 
}


// VERSION 2: ostream and istream from std, notice following version
#include <iostream>

class coord {
        int x, y;
    public:
        coord() { x = 0; y = 0; }
        coord(int i, int j) { x = i; y = j; }
        friend std::ostream &operator<<( std::ostream &stream, coord ob);      // inserter 
        friend std::istream &operator>>( std::istream &stream, coord &ob);     // extractor
};

// Inserter
std::ostream &operator<<(std::ostream &stream, coord ob) {
    stream << ob.x << ", " << ob.y << '\n';
    return stream ; 
}

// Extractor
std::istream &operator>>(std::istream &stream, coord &ob) {
    std::cout << " Enter coordinates : ";
    stream >> ob.x >> ob.y;
    return stream;
}

int main() { 
    coord a(1, 1), b(10, 23);

    std::cout << a << b;
    std::cin >> a;
    std::cout << a;
    
    return 0; 
}



// ----  rev[06-Oct-2025]  ----

For the sake of illustration, here is the preceding program revised so that the inserter is
not a friend of the coord class. Because the inserter does not have access to the private
parts of coord, the variables x and y have to be made public.
/*
Create an inserter for objects of type coord , using
a non - friend inserter
*/
# include <iostream >
using namespace std ;
class coord
{
public :
int x, y; // must be public
coord () { x = 0; y = 0; }
coord ( int i, int j) { x = i; y = j; }
};
// An inserter for the coord class .
ostream & operator <<( ostream &stream , coord ob)
{
stream << ob.x << ", " << ob.y << ’\n’;
return stream ;
}
int main ()
{
coord a(1, 1) , b(10 , 23);
cout << a << b;
return 0;
}




3. An inserter is not limited to displaying only textual information. An inserter can perform any operation or conversion necessary to output information in a form needed by a
particular device or situation. For example, it is perfectly valid to create an inserter that
sends information to a plotter. In this case, the inserted will need to send appropriate
224INTRODUCING THE C++ I/O SYSTEM
8.5. CREATING YOUR OWN INSERTERS
plotter codes in addition to the information. To allow you to taste the flavor of this type of
inserter, the following program creates a class called triangle, which stores the width and
height of a right triangle. The inserter for this class displays the triangle on the screen.
// This program draws right triangles
# include <iostream >
using namespace std ;
class triangle
{
int height , base ;
public :
triangle ( int h, int b) { height = h; base = b; }
friend ostream & operator <<( ostream &stream , triangle ob);
};
// Draw a triangle
ostream & operator <<( ostream &stream , triangle ob)
{
int i, j, h, k;
i = j = ob.base -1;
for (h=ob. height -1; h; h --)
{
for (k=i; k; k --)
stream << ’ ’;
stream << ’*’;
if(j!=i)
{
for (k=j-i -1; k; k --)
stream << ’ ’;
stream << ’*’;
} i
--;
stream << ’\n’;
}
for (k =0; k<ob. base ; k++)
stream << ’*’;
stream << ’\n’;
return stream ;
}
int main ()
{
triangle t1 (5, 5) , t2 (10 , 10) , t3 (12 , 12);
cout << t1;
cout << endl << t2 << endl << t3;
225TEACH YOURSELF
C++
return 0;
}
Notice that this program illustrates how a properly designed inserter can be fully integrated into a "normal" I/O expression. This program displays the following:
*
**
* *
* *
*****
a
*
**
* *
* *
* *
* *
* *
* *
* *
**********
a
*
**
* *
* *
* *
* *
* *
* *
* *
* *
* *
************



EXERCISES



1. Given the following strtype class and partial program, create an inserter that displays a
string:
# include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
int len ;
public :
strtype ( char * ptr );
~ strtype () { delete [] p; }
friend ostream & operator <<( ostream &stream , strtype &ob);
};
strtype :: strtype ( char *ptr )
{
226INTRODUCING THE C++ I/O SYSTEM
8.5. CREATING YOUR OWN INSERTERS
len = strlen ( ptr ) +1;
p = new char ( len );
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
}
// Create operator << inserter function here .
int main ()
{
strtype s1(" This is a test ."), s2("I like C++. ");
cout << s1 << ’\n’ << s2;
return 0;
}



2. Replace the show() function in the following program with an inserter function:
# include <iostream >
using namespace std ;
class planet
{
protected :
double distance ; // miles from the sun
int revolve ; // in days
public :
planet ( double d, int r)
{
distance = d;
revolve = r;
}
};
class earth : public planet
{
double circumference ; // circumference of orbit
public :
earth ( double d, int r) : planet (d, r)
{
circumference = 2* distance *3.1416;
}
/*
Rewrite this so that it displays the information using
an inserter function .
*/
void show ()
227TEACH YOURSELF
C++
{
cout << " Distance from sum : " << distance << ’\n’;
cout << " Days in orbit : " << revolve << ’\n’;
cout << " Circumference of orbit : " << circumference
<< ’\n’;
}
};
int main ()
{
earth ob (93000000 , 365) ;
cout << ob;
return 0;
}



3. Explain why an inserter cannot be a member function


