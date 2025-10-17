
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

    // notice "object" is used just like "built-in data types"
    std::cout << a << b;
    std::cin >> a;
    std::cout << a;
    
    return 0; 
}




/* Example 2: Following is the preceding program reworked with using a non-friend inserter.
                Since the "inserter" is not a "friend" of the coord class, 
                it does not have access to the private parts of coord, 
                so the variables x and y have to be made "public". 
*/

# include <iostream>

class coord {
    public:
        int x, y;   // must be public. Inserter needs access
        coord() { x = 0; y = 0; }
        coord(int i, int j) { x = i; y = j; }
};

// An inserter for the coord class .
std::ostream &operator<<(std::ostream &stream , coord ob) {
    stream << ob.x << ", " << ob.y << '\n';
    return stream;
}

int main() {
    coord a(1, 1), b(10, 23);
    std::cout << a << b;    // notice object is used
    return 0;
}




/* Example 3: An inserter is not limited to showing text output.
                It can perform any operation or conversion needed to output data 
                    in a form suitable for a particular device or situation.

                For example, an inserter can be written to send plotting commands to a plotter 
                    instead of displaying plain text.

                To illustrate this, following is a program that defines a "triangle" class
                    which stores the "width" and "height" of a right triangle.

                The inserter for this class "displays the triangle "on the screen.

                This program illustrates how a properly designed inserter
                    can be fully integrated into a "normal" I/O expression. 
*/

#include <iostream>

class triangle {
        int height, base;
    public:
        triangle(int h, int b) { height = h; base = b; }
        friend std::ostream &operator<<(std::ostream &stream , triangle ob);
};


// Draw a triangle
std::ostream &operator<<(std::ostream &stream , triangle ob) {
    int i, j, h, k;

    i = j = ob.base -1;

    for(h=ob. height -1; h; h--) {
        for(k=i; k; k--) stream << ' ';
        stream << '*';
        if(j!=i) {
            for(k=j-i -1; k; k--) stream << ' ';
            stream << '*';
        } 
        i--;
        stream << '\n';
    }

    for(k =0; k<ob. base ; k++) stream << '*';
    stream << '\n';

    return stream;
}


int main() {
    triangle t1(5, 5), t2(10, 10), t3(12, 12);

    std::cout << t1;
    std::cout << std::endl << t2 << std::endl << t3;

    return 0;
}




/* Example 4: Given the following "strtype class" and partial program, create an inserter that displays a string. 

                #include <iostream>
                #include <cstring>
                #include <cstdlib>

                class strtype {
                        char *p;
                        int len ;
                    public:
                        strtype( char *ptr );
                        ~strtype() { delete [] p; }
                        friend std::ostream &operator<<( std::ostream &stream, strtype &ob);
                };

                strtype :: strtype( char *ptr ) {
                    len = strlen(ptr) +1;
                    p = new char(len);
                    if(!p) {
                        std::cout << " Allocation error \n";
                        exit(1);
                    }
                    strcpy(p, ptr);
                }


                // ----  Create operator << inserter function here.  ----


                int main() {
                    strtype s1(" This is a test ."), s2("I like C++. ");
                    std::cout << s1 << '\n' << s2;
                    return 0;
                }
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype {
        char *p;
        int len ;
    public:
        strtype( char *ptr );
        ~strtype() { delete [] p; }
        friend std::ostream &operator<<( std::ostream &stream, strtype &ob);
};

strtype :: strtype( char *ptr ) {
    len = strlen(ptr) +1;
    p = new char(len);
    if(!p) {
        std::cout << " Allocation error \n";
        exit(1);
    }
    strcpy(p, ptr);
}

// operator << inserter function here.
std::ostream &operator<<( std::ostream &stream , strtype &ob) {
    stream << ob.p;
    return stream;
}

int main() {
    strtype s1(" This is a test ."), s2("I like C++. ");
    std::cout << s1 << '\n' << s2 << '\n' << std::endl;
    return 0;
}




/* Example 5: Replace the show() function in the following program with an "inserter function". 

                #include <iostream>

                class planet {
                    protected :
                        double distance ;   // miles from the sun
                        int revolve ;       // in days
                    public :
                        planet(double d, int r) {
                            distance = d;
                            revolve = r;
                        }
                };

                class earth : public planet {
                        double circumference ; // circumference of orbit
                    public :
                        earth(double d, int r) : planet(d, r) {
                            circumference = 2* distance *3.1416;
                        }
                        
                        // Rewrite this so that it displays the information using an inserter
                        void show() {
                            std::cout << " Distance from sum : " << distance << '\n';
                            std::cout << " Days in orbit : " << revolve << '\n';
                            std::cout << " Circumference of orbit : " << circumference
                            << '\n';
                        }
                };

                int main() {
                    earth ob(93000000, 365);
                    
                    ob.show();

                    // rewrite the show() so that following line works
                    std::cout << ob;

                    return 0;
                }
*/

#include <iostream>

class planet {
    protected :
        double distance ;   // miles from the sun
        int revolve ;       // in days
    public :
        planet(double d, int r) {
            distance = d;
            revolve = r;
        }
};

class earth : public planet {
        double circumference ; // circumference of orbit
    public :
        earth(double d, int r) : planet(d, r) {
            circumference = 2*distance*3.1416;
        }
        
        // Rewrite this so that it displays the information using an inserter
        // void show() {
        //     std::cout << " Distance from sum : " << distance << '\n';
        //     std::cout << " Days in orbit : " << revolve << '\n';
        //     std::cout << " Circumference of orbit : " << circumference
        //     << '\n';
        // }

        friend std::ostream &operator<<(std::ostream &stream , earth ob);
};


std::ostream &operator<<(std::ostream &stream, earth ob) {
    stream << " Distance from sun : " << ob.distance << '\n';
    stream << " Days in orbit : " << ob.revolve << '\n';
    stream << " Circumference of orbit : " << ob.circumference << '\n';
    return stream;
}

int main() {
    earth ob(93000000, 365);
    
    // ob.show();

    // rewrite the show() so that following line works
    std::cout << ob;

    return 0;
}




/* Example 6: Explain why an inserter cannot be a member function. 

            ans:
                An inserter cannot be a" member function" because the OBJECT that generates a call 
                to the inserter is not an object of a USER-defined class.
*/




/* Example 7: This program adds an extractor to the coord class.
                It uses a friend extractor for objects of type coord.

                Notice how the extractor also prompts the user for input. 
                Although such prompting is not required (or even desired) for most situations, 
                This function shows how a customized extractor can simplify coding when a prompting message is needed.
*/

#include <iostream>

class coord {
        int x, y;
    public :
        coord() { x = 0; y = 0; }
        coord(int i, int j) { x = i; y = j; }

        friend std::ostream &operator<<( std::ostream &stream , coord ob);    // inserter
        friend std::istream &operator>>( std::istream &stream , coord &ob);   // extractor
};

// inserter
std::ostream & operator <<( std::ostream &stream , coord ob) {
    stream << ob.x << ", " << ob.y << '\n';
    return stream;
}

// extractor
std::istream & operator >>( std::istream &stream , coord &ob) {
    std::cout << " Enter coordinates : ";
    stream >> ob.x >> ob.y;
    return stream;
}

int main() {
    coord a(1, 1), b(10 , 23);

    std::cout << a << b;
    std::cin >> a;
    std::cout << a;

    return 0;
}



// ---- rev[16-Oct-2025] ----

/* Example 8: Following is an inventory class is created that stores 
                    the name of an item, 
                    the number on hand and 
                    its cost. 
                The program includes both an "inserter" and an "extractor" for this class.
*/

#include <iostream>
#include <cstring>

// inventory class
class inventory {
        char item[40];  // name of item
        int onhand;     // number on hand
        double cost;    // cost of item
    public:
        inventory(char *i, int o, double c) {
            strcpy(item , i);
            onhand = o;
            cost = c;
        }

friend ostream & operator <<( ostream &stream , inventory ob)
;
friend istream & operator >>( istream &stream , inventory &ob
);
};
ostream & operator <<( ostream &stream , inventory ob)
{
stream << ob. item << ": " << ob. onhand ;
stream << " on hand at $" << ob. cost << ’\n’;
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
int main ()
{
inventory ob(" hammer ", 4, 12.55) ;
cout << ob;
cin >> ob;
cout << ob;
return 0;
}




/* Example 9: Add an extractor to the strtype class from "Example 4" above */
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
friend ostream & operator <<( ostream &stream , strtype &ob)
;
friend istream & operator >>( istream &stream , strtype &ob)
;
};
strtype :: strtype ( char *ptr )
{
len = strlen ( ptr ) +1;
p = new char ( len );
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
}
ostream & operator <<( ostream &stream , strtype &ob)
{
stream << ob.p;
return stream ;
}
istream & operator >>( istream &stream , strtype &ob)
{
char temp [255];
stream >> temp ;
if( strlen ( temp ) >= ob.len )
{
delete [] ob.p;
ob. len = strlen ( temp )+1;
ob.p = new char (ob.len );
if (! ob.p)
{
cout << " Allocation error \n";
exit (1) ;
}
}
strcpy (ob.p, temp );
return stream ;
}
int main ()
{
strtype s1(" This is a test ."), s2("I like C++. ");
cout << s1 << ’\n’ << s2 << ’\n’;
cout << "\ nEnter a string : ";
cin >> s1;
cout << s1;
return 0;
}




/* Example 10: Create a class that stores an "integer" value and its "lowest factor". 
                Create both an inserter and an extractor for this class 
*/

#include <iostream>

class factor {
        int num; // number
        int lfact; // lowest factor
    public :
        factor( int i);
        friend ostream &operator<<( ostream &stream , factor ob);
        friend istream &operator>>( istream &stream , factor &ob);
};

factor :: factor(int i){
    int n;

num = i;
for (n =2; n <(i /2) ; n ++)
if (!( i%n))
break ;
if(n <(i /2) )
lfact = n;
else
lfact = 1;
}

istream & operator >>( istream &stream , factor &ob)
{
stream >> ob. num ;
int n;
for (n =2; n <( ob. num /2); n++)
if (!( ob. num %n))
break ;
if(n <( ob. num /2) )
ob. lfact = n;
else
ob. lfact = 1;
return stream ;
}
ostream & operator <<( ostream &stream , factor ob)
{
stream << ob. lfact << " is lowest factor of ";
stream << ob. num << ’\n’;
return stream ;
}
int main ()
{
factor o (32) ;
cout << o;
cin >> o;
cout << o;
return 0;
}


