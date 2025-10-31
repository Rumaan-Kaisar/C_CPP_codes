
// ----  rev[31-Oct-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

At this point you should be able to perform the following exercises and answer the questions.
/* Example 1: Write a program that displays the number 100 in decimal, hexadecimal, and octal. (Use
the ios format flags.) */

1. # include <iostream >
using namespace std ;
int main ()
{
cout << 100 << ’ ’;
cout . unsetf ( ios :: dec ); // clear dec flag
cout . setf ( ios :: hex );
cout << 100 << ’ ’;
cout . unsetf ( ios :: hex ); // clear hex flag
cout . setf ( ios :: oct );
cout << 100 << ’\n’;
return 0;
}




/* Example 2: Write a program that displays the value 1000.5364 in a 20-character field, left justified,
with two decimal places, using * as a fill character. (Use the ios format flags.) */

2. # include <iostream >
using namespace std ;
int main ()
{
cout . setf ( ios :: left );
cout . precision (2) ;
cout . fill (’*’);
cout . width (20) ;
cout << 1000.5364 << ’\n’;
return 0;
}



/* Example 3: Rewrite your answer to Exercises 1 and 2 so that they use I/O manipulators. */

3a. # include <iostream >
using namespace std ;
int main ()
{
cout << 100 << ’ ’;
cout << hex << 100 << ’ ’;
cout << oct << 100 << ’\n’;
return 0;
}


3b. # include <iostream >
# include <iomanip >
using namespace std ;
518ANSWERS
MASTERY SKILLS CHECK: Chapter 8
int main ()
{
cout << setiosflags (ios :: left );
cout << setprecision (2) ;
cout << setfill (’*’);
cout << setw (20) ;
cout << 1000.5364 << ’\n’;
return 0;
}




/* Example 4: Show how to save the format flags for cout and how to restore them. Use either member
functions or manipulators. */

4. ios :: fmtflags f;
f = cout . flag (); // save
// ...
cout . flags (f); // restore




/* Example 5: Create an inserter and an extractor for this class:
class pwr
{
int base ;
int exponent ;
double result ; // base to the exponent power
public :
pwr ( int b, int e);
};
pwr :: pwr ( int b, int e)
{
base = b;
exponent = e;
result = 1;
for ( ; e; e --)
result = result * base ;
} 
*/


5. # include <iostream >
using namespace std ;
class pwr
{
int base ;
int exponent ;
double result ; // base to the exponent power
public :
pwr ( int b, int e);
friend ostream & operator <<( ostream &stream , pwr ob);
friend istream & operator >>( istream &stream , pwr &ob);
};
pwr :: pwr ( int b, int e)
{
base = b;
exponent = e;
result = 1;
for ( ; e; e --)
result = result * base ;
}
ostream & operator <<( ostream &stream , pwr ob)
{
stream << ob. base << "^" << ob. exponent ;
stream << " is " << ob. result << ’\n’;
}
istream & operator >>( istream &stream , pwr &ob)
{
519TEACH YOURSELF
C++
int b, e;
cout << " Enter base and exponent : ";
stream >> b >> e;
pwr temp (b, e); // create temporary
ob = temp ;
return stream ;
}
int main ()
{
pwr ob (10 , 2);
cout << ob;
cin >> ob;
cout << ob;
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
520ANSWERS
CUMULATIVE SKILLS CHECK: Chapter 8
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




/* Example 2: Write a program that contains a class called watch. Using the standard time functions,
have this class’s constructor read the system time and store it. Create an inserter that
displays the time. */



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
}; */




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.


/* Example 1: Write a program that displays the sentence "C++ is fun" in a 40-character-wide filed
using a colon (:) as the fill character. */


/* Example 2: Write a program that displays the outcome of 10/3 to three decimal places. Use ios
member functions to do this. */


/* Example 3: Redo the preceding program using I/O manipulators. */


/* Example 4: What is an inserter? What is an extractor? */


/* Example 5: Given the following class, create an inserter and an extractor for it.
class date
{
char d [9]; // store date as string : mm/dd/yy
public :
// add inserter and extractor
};

 */


/* Example 6: What header must be included if your program is to use I/O manipulators that take
parameters? */


/* Example 7: What predefined streams are created when a C++ program begins execution? */





