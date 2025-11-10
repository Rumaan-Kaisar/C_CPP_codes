
// ----  rev[31-Oct-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// rev[07-Nov-2025]



/* Example 5: Create an inserter and an extractor for this class:
                class pwr {
                        int base;
                        int exponent;
                        double result;  // base to the exponent power
                    public:
                        pwr(int b, int e);
                };

                pwr::pwr(int b, int e) {
                    base = b;
                    exponent = e;
                    result = 1;
                    for( ; e; e--) result = result*base;
                } 
*/

#include <iostream>

class pwr {
        int base;
        int exponent;
        double result;  // base to the exponent power
    public:
        pwr(int b, int e);
        friend ostream &operator<<(ostream &stream, pwr ob);    // inserter
        friend istream &operator>>(istream &stream, pwr &ob);   // extractor
};

pwr::pwr(int b, int e) {
    base = b;
    exponent = e;
    result = 1;
    for( ; e; e--) result = result*base;
} 

// inserter
std::ostream &operator<<(std::ostream &stream , pwr ob) {
    stream << ob.base << "^" << ob.exponent;
    stream << " is " << ob.result << '\n';
    return stream;
}

// extractor
istream &operator>>(istream &stream , pwr &ob) {
    int b, e;
    std::cout << " Enter base and exponent : ";
    stream >> b >> e;
    pwr temp(b, e); // create temporary
    ob = temp;
    return stream;
}


int main(){
    pwr ob(10, 2);

    std::cout << ob;
    std::cin >> ob;
    std::cout << ob;
    
    return 0;
}



/* Example 6: Create a class called box that stores the dimensions of a square. Create an inserter that
displays a square box on the screen. (Use any method you like to display the box. */

6. // This program draws boxes .
# include <iostream >
using namespace std ;
class box
{
int len ;
public :
box ( int l) { len = l; }
friend ostream & operator <<( ostream &stream , box ob);
};
// Draw a box .
ostream & operator <<( ostream &stream , box ob)
{
int i, j;
for (i =0; i<ob. len ; i++)
stream << ’*’;
stream << ’\n’;
for (i =0; i<ob.len -2;i++)
{
stream << ’*’;
for (j =0; j<ob.len -2;j++)
stream << ’ ’;
stream << "*\n";

}
for (i =0; i<ob. len ; i++)
stream << ’*’;
stream << ’\n’;
return stream ;
}
int main ()
{
box b1 (4) , b2 (7) ;
cout << b1 << endl << b2;
return 0;
}



// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

/* Example 1: Using the stack class shown here, create an inserter that displays the contents of the
stack. Demonstrate that your inserter works.
# include <iostream >
using namespace std ;
# define SIZE 10
// Declare a stack class for characters
class stack
{
char stck [ SIZE ]; // holds the stack
int tos ; // index of top -of - stack
public :
stack ();
void push ( char ch); // push character on stack
char pop (); // pop character from stack


};
// Initialize the stack
stack :: stack ()
{
tos = 0;
}
// Push a character
void stack :: push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack is full \n";
return 0;
}
stck [ tos ] = ch;
tos ++;
}
// Pop a character .
char stack :: pop ()
{
if( tos ==0)
{
cout << " Stack is empty \n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
} */


1. # include <iostream >
using namespace std ;
# define SIZE 10
// Declare a stack class for characters
class stack
{
char stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
public :
stack ();
void push ( char ch); // push character on stack
char pop (); // pop character from stack
friend ostream & operator <<( ostream &stream , stack ob);
};
// Initialize the stack
stack :: stack ()
{
tos = 0;
}
// Push a character .
void stack :: push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack is full \n";
return ;
}
stck [ tos ] = ch;

tos ++;
}
// Pop a character .
char stack :: pop ()
{
if( tos ==0)
{
cout << " Stack is empty \n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
ostream & operator <<( ostream &stream , stack ob)
{
char ch;
while (ch=ob. pop ())
stream << ch;
stream << endl ;
return stream ;
}
int main ()
{
stack s;
s. push (’a’);
s. push (’b’);
s. push (’c’);
cout << s;
cout << s;
return 0;
}






/* Example 2: Write a program that contains a class called watch. Using the standard time functions,
have this class’s constructor read the system time and store it. Create an inserter that
displays the time. */


2. # include <iostream >
# include <ctime >
using namespace std ;
class watch
{
time_t t;
public :
watch () { t = time ( NULL ); }
friend ostream & operator <<( ostream &stream , watch ob);
};

ostream & operator <<( ostream &stream , watch ob)
{
struct tm * localt ;
localt = localtime (& ob.t);
stream << asctime ( localt ) << endl ;
return stream ;
}
int main ()
{
watch w;
cout << w;
return 0;
}




/* Example 3: Using the following class, which converts feet to inches, create an extractor that prompts
the user for feet. Also, create an inserter that displays the number of feet and inches.
Include a program that demonstrates that your inserter and extractor work.
class ft_to_inches
{
double feet ;
double inches ;
public :
void set ( double f)
{
feet = f;
inches = f * 12;
}
}; 

*/


3. # include <iostream >
using namespace std ;
class ft_to_inches
{
double feet ;
double inches ;
public :
void set ( double f)
{
feet = f;
inches = f * 12;
}
friend istream & operator >>( istream &stream ,
ft_to_inches &ob);
friend ostream & operator <<( ostream &stream ,
ft_to_inches ob);
};
istream & operator >>( istream &stream , ft_to_inches &ob)
{
double f;
cout << " Enter feet : ";
stream >> f;
ob. set (f);
return stream ;
}
ostream & operator <<( ostream &stream , ft_to_inches ob)

{
stream << ob. feet << " feet is " << ob. inches ;
stream << " inches \n";
return stream ;
}
int main ()
{
ft_to_inches x;
cin >> x;
cout << x;
return 0;
}




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.


/* Example 1: Write a program that displays the sentence "C++ is fun" in a 40-character-wide filed
using a colon (:) as the fill character. */

1. # include <iostream >
using namespace std ;
int main ()
{
cout . width (40) ;
cout . fill (’:’);
cout << "C++ is fun " << ’\n’;
return 0;
}



/* Example 2: Write a program that displays the outcome of 10/3 to three decimal places. Use ios
member functions to do this. */

2. # include <iostream >
using namespace std ;
int main ()
{
cout . precision (4) ;
cout << 10.0/3.0 << ’\n’;
return 0;
}




/* Example 3: Redo the preceding program using I/O manipulators. */

3. # include <iostream >
# include <iomanip >
using namespace std ;
int main ()
{
cout << setprecision (4) << 10.0/3.0 << ’\n’;

return 0;
}


/* Example 4: What is an inserter? What is an extractor? */

4. An inserter is an overloaded operator<<() function that outputs a class’s data to an
output stream. An extractor is an overloaded operator>>() function that inputs a
class’s data from an input stream



/* Example 5: Given the following class, create an inserter and an extractor for it.
class date
{
char d [9]; // store date as string : mm/dd/yy
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



