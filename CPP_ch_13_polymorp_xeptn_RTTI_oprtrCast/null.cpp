


// ----  rev[25-Aug-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-


Mastery Skills Check
At this point you should be able to perform the following exercises and answer the questions.
1. Create a generic function that returns the mode of an array of values. (The mode of a set
is the value that occurs most often.)
2. Create a generic function that returns the summation of an array of values.
3. Create a generic bubble sort(or use nay other sorting algorithm you like).
4. Rework the stack class so that it can store pairs of different-type objects on the stack.
Demonstrate your solution.
5. Show the general forms of try, catch, and throw. In your own words, describe their
operation.
6. Again, rework the stack class so that stack over-and underflows are handled as exceptions.
7. Check your compiler’s documentation. See whether it supports the terminate() and
unexpected() functions. Generally, these functions can be configured to call any function
you choose. If this is the case with your compiler, try creating your own set of customized
termination functions that handle otherwise unhandled exceptions.
8. Thought question: Give a reason why having new generate an exception is a better
approach than having new return null on failure.




Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapter.
1. In Chapter 6, Section 6.7, Example 3, a safe array class was shown. On your own, convert
it into a generic safe array.
2. In Chapter 1, overloaded versions of the abs() function were created. As a better solution,
create a generic abs() function on your own that will return the absolute value of any
numeric object.




Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. What is a generic function and what is its general form?
2. What is a generic class and what is its general form?
3. Write a generic function called gexp() that returns the value of one of its arguments
raised to the power of the other.
4. In Chapter 9, Section 9.7, Example 1, a coord class that holds integer coordinates was
created and demonstrated in a program. Create a generic version of the coord class that
can hold coordinates of any type. Demonstrate your solution in a program.
5. Briefly explain how try, catch, and throw work together to provide C++ exception
handling.
6. Can throw be used if execution has not passed through a try block?
7. What purpose do terminate() and unexpected() serve?
8. What form of catch will handle all types of exceptions?












MASTERY SKILLS CHECK: Chapter 11
1. # include <iostream >
# include <cstring >

// A generic mode - fining function .
template <class X> X mode (X *data , int size )
{
register int t, w;
X md , oldmd ;
int count , oldcount ;
oldmd = 0;
oldcount = 0;
for (t =0; t< size ; t ++)
{
md = data [t];
count = 1;
for (w = t +1; w< size ; w++)
{

if(md == data [w])
count ++;
if( count > oldcount )
{
oldmd = md;
oldcount = count ;
}
}
}
return oldmd ;
}
int main ()
{
int i[] = {1, 2, 3, 4, 2, 3, 2, 2, 1, 5};
char *p = " this is a test ";
cout << " mode of i: " << mode (i, 10) << endl ;
cout << " mode of p: " << mode (p, (int ) strlen (p)) << endl ;
return 0;
}



2. # include <iostream >

template <class X> X sum (X *data , int size )
{
int i;
X result = 0;
for (i =0; i< size ; i ++)
result += data [i];
return result ;
}
int main ()
{
int i[] = {1, 2, 3, 4};
double d[] = {1.1 , 2.2 , 3.3 , 4.4};
cout << sum (i, 4) << endl ;
cout << sum (d, 4) << endl ;
return 0;
}


3. # include <iostream >

// A generic bubble sort .
template <class X> void bubble (X *data , int size )
{
register int a, b;
X t;
for (a =1; a< size ; a ++)
{
for (b=size -1; b >=a; b --)
{
if( data [b -1] > data [b])
{
t = data [b -1];
data [b -1] = data [b];
data [b] = t;
}
}
}
}
int main ()
{
int i[] = {3, 2, 5, 6, 1, 8, 9, 3, 6, 9};
double d[] = {1.2 , 5.5 , 2.2 , 3.3};
int j;
bubble (i, 10) ; // sort ints
bubble (d, 4); // sort doubles
for (j =0; j <10; j ++)
cout << i[j] << ’ ’;
cout << endl ;
for (j =0; j <4; j ++)
cout << d[j] << ’ ’;
cout << endl ;
return 0;
}



4. /*
This function demonstrates a generic stack that
holds two values .
*/
# include <iostream >
using namespace std ;
# define SIZE 10
// Create a generic stack class
template <class StackType > class stack

{
StackType stck [ SIZE ][2]; // holds the stack
int tos ; // index of top of stack
public :
void init () { tos = 0; }
void push ( StackType ob , StackType ob2 );
StackType pop ( StackType &ob2);
};
// Push objects .
template <class StackType >
void stack < StackType >:: push ( StackType ob , StackType ob2 )
{
if( tos == SIZE )
{
cout << " Stack is full .\n";
return ;
}
stck [ tos ][0] = ob;
stck [ tos ][1] = ob2 ;
tos ++;
}
// Pop objects .
template <class StackType >
StackType stack < StackType >:: pop( StackType &ob2)
{
if( tos ==0)
{
cout << " Stack is empty .\n";
return 0; // return null on empty stack
}
tos --;
ob2 = stck [ tos ][1];
return stck [ tos ][0];
}
int main ()
{
// Demonstrate character stacks .
stack <char > s1 , s2; // create two stacks
int i;
char ch;
// initialize the stacks
s1. init ();
s2. init ();
s1. push (’a’, ’b’);
s2. push (’x’, ’z’);
s1. push (’b’, ’d’);
565TEACH YOURSELF
C++
s2. push (’y’, ’e’);
s1. push (’c’, ’a’);
s2. push (’z’, ’x’);
for (i =0; i <3; i ++)
{
cout << " Pop s1: " << s1.pop (ch);
cout << ’ ’ << ch << ’\n’;
}
for (i =0; i <3; i ++)
{
cout << " Pop s2: " << s2.pop (ch);
cout << ’ ’ << ch << ’\n’;
}
// demonstrate double stacks
stack < double > ds1 , ds2 ; // create two stacks
double d;
// initialize the stacks
ds1 . init ();
ds2 . init ();
ds1 . push (1.1 , 2.0) ;
ds2 . push (2.2 , 3.0) ;
ds1 . push (3.3 , 4.0) ;
ds2 . push (4.5 , 5.0) ;
ds1 . push (5.5 , 6.0) ;
ds2 . push (6.6 , 7.0) ;
for (i =0; i <3; i ++)
{
cout << " Pop ds1 : " << ds1 .pop (d);
cout << ’ ’ << d << ’\n’;
}
for (i =0; i <3; i ++)
{
cout << " Pop ds2 : " << ds2 .pop (d);
cout << ’ ’ << d << ’\n’;
}
return 0;
}
5. The general forms of try, catch, and throw are shown here:
try
{
// try block
throw exp ;
}
catch ( type arg )

{
// ...
}
6. /*
This function demonstrates a generic stack
that includes exception handling .
*/
# include <iostream >
using namespace std ;
# define SIZE 10
// Create a generic stack class
template <class StackType > class stack
{
StackType stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
public :
void init () { tos = 0; }
void push ( StackType ob);
StackType pop ();
};
// Push objects .
template <class StackType >
void stack < StackType >:: push ( StackType ob)
{
try
{
if( tos == SIZE )
throw SIZE ;
}
catch ( int )
{
cout << " Stack is full .\n";
return ;
}
stck [ tos ] = ob;
tos ++;
}
// Pop objects .
template <class StackType >
StackType stack < StackType >:: pop ()
{
try
{
if( tos ==0)
throw 0;
}

catch ( int )
{
cout << " Stack is empty .\n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
int main ()
{
// Demonstrate character stacks .
stack <char > s1 , s2; // create two stacks
int i;
char ch;
// initialize the stacks
s1. init ();
s2. init ();
s1. push (’a’);
s2. push (’x’);
s1. push (’b’);
s2. push (’y’);
s1. push (’c’);
s2. push (’z’);
for (i =0; i <3; i ++)
cout << " Pop s1: " << s1.pop () << ’\n’;
for (i =0; i <3; i ++)
cout << " Pop s2: " << s2.pop () << ’\n’;
// demonstrate double stacks
stack < double > ds1 , ds2 ; // create two stacks
double d;
// initialize the stacks
ds1 . init ();
ds2 . init ();
ds1 . push (1.1) ;
ds2 . push (2.2) ;
ds1 . push (3.3) ;
ds2 . push (4.5) ;
ds1 . push (5.5) ;
ds2 . push (6.6) ;
for (i =0; i <3; i ++)
cout << " Pop ds1 : " << ds1 .pop () << ’\n’;
for (i =0; i <3; i ++)
cout << " Pop ds2 : " << ds2 .pop () << ’\n’;
568ANSWERS
REVIEW SKILLS CHECK: Chapter 12
return 0;
}
7. If new throws an exception when an allocation error occurs, you can be sure that the
error will be handled one way or another-even if only by abnormal program termination.
In contrast, an allocation failure that is reported by new, a return of a null pointer
can be overlooked if you forget to check for this possibility. The trouble is that when
your program attempts to use the null pointer, it might work for a while, then behave
erratically, and finally crash in unpredictable (and unduplicatable ) ways. This is very
difficult type of bug to diagnose.
REVIEW SKILLS CHECK: Chapter 12
1. In C++, a generic function defines a general set of operations that will be applied to
various types of data. It is implemented with the keyword template. Its general form is
shown here:
template <class Ttype > ret_type func_name ( para_list )
{
// ...
}
2. In C++, a generic class defines all operations that relate to that class, but the actual
data is specified as a parameter when an object of that class is created. Its general form
is shown here:
template < class Ttype > class class_name
{
// ...
};
3. # include <iostream >
using namespace std ;
// Return a to the b.
template <class X> X gexp (X a, X b)
{
X i, result =1;
for (i =0; i<b; i ++)
result *= a;
return result ;
}
int main ()
{
cout << gexp (2, 3) << endl ;
cout << gexp (10.0 , 2.0) ;
return 0;
}

#include <iostream>
# include <fstream>
using namespace std ;
template < class CoordType > class coord
{
CoordType x, y;
public :
coord ( CoordType i, CoordType j) { x = i; y = j; }
void show () { cout << x << ", " << y << endl ; }
};
int main ()
{
coord <int >o1 (1, 2) , o2 (3, 4);
o1. show ();
o2. show ();
coord < double > o3 (0.0 , 0.23) , o4 (10.19 , 3.098) ;
o3. show ();
o4. show ();
return 0;
}
5. try, catch, and throw work together like this: Put all statements that you wish to
monitor for exceptions within a try block, if an exception occurs, throw that exception
using throw and handle it with a corresponding catch statement.
6. No.
7. terminate() is called when an exception is thrown for which there is no corresponding
catch statement. unexpected() is called when an attempt is made to throw an exception
out of a function that is not specified in the function’s throw clause.
8. catch(...).
