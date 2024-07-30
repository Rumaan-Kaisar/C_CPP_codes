
// --------    rev[09-May-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

Example 1: Given the following class, create a two-by-five two-dimensional array and give each object
in the array an initial value of your own choosing. Then display the contents of the array.
116ARRAYS, POINTERS, AND REFERENCES
SKILLS CHECK
class a_type
{
double a, b;
public :
a_type ( double x, double y)
{
a = x;
b = y;
}
void show () { cout << a << ’ ’ << b << "\n"; }
};




Example 2: Modify your solution to the preceding problem so it accesses the array by using a pointer.




Example 3: What is the this pointer?




Example 4: Show the general forms for new and delete. What are some advantages of using them
instead of malloc() and free()?




Example 5: What is a reference? What is one advantage of using a reference parameter?




Example 6: Create a function called recip() that takes one double reference parameter. Have the
function change the value of that parameter into its reciprocal. Write a program to
demonstrate that it works.







// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-



Example 1: Given a pointer to an object, what operator is used to access a member of that object?




Example 2: In Chapter 2, a strtype class was created that dynamically allocated space for a string.
Rework the strtype class (shown here for your convenience) so it uses new and delete.
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
~ strtype ();
void show ();
};
strtype :: strtype ( char *ptr )
{
len = strlen ( ptr );
p = ( char *) malloc (len +1);
117TEACH YOURSELF
C++
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
}
strtype ::~ strtype ()
{
cout << " Freeing p\n";
free (p);
}
void strtype :: show ()
{
cout << p << " - length : " << len ;
cout << "\n";
}
int main ()
{
strtype s1(" This is a test ."), s2("I like C++. ");
s1. show ();
s2. show ();
return 0;
}




Example 3: On your own, rework any program from the preceding chapter so that it uses a reference.






// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-


Example 1: What is a reference? Give two important uses.




Example 2: Show how to allocate a float and an int by using new. Also, show how to free them by
using delete.




Example 3: What is the general form of new that is used to initialize a dynamic variable? Give a
concrete example.




Example 4: Given the following class, show how to initialize a ten-element array so that x has the
value 1 through 10.
class samp
{
int x;
public :
samp ( int n) { x = n; }
int getx () { return x; }
};




Example 5: Give one advantage of reference parameters. Give one disadvantage.




Example 6: Can dynamically allocated arrays be initialized?




Example 7: Create a function called mag() using the following prototype that raises num to the order
of magnitude specified by order:
void mag ( long &num , long order );
For example, if num is 4 and order is 2, when mag() returns, num will be 400. Demonstrate in a program that the function works.





