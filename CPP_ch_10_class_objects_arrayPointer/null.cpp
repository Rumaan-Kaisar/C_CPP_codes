
// --------    rev[01-Aug-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-







/* Example 5: What is a reference? What is one advantage of using a reference parameter? 

                A reference is essentially an "implicit pointer constant" that is 
                    effectively a "different name" for another variable or argument. 

                One advantage of using a "reference parameter" is that 
                    no "copy of the argument" is made.

*/




/* Example 6: Create a function called recip() that takes one double reference parameter. Have the
function change the value of that parameter into its reciprocal. Write a program to
demonstrate that it works. */

# include <iostream >
using namespace std ;
void recip ( double &d);
int main ()
{
double x = 100.0;
cout << "x is " << x << ’\n’;
recip (x);
cout << " Reciprocal is " << x << ’\n’;
return 0;
}
void recip ( double &d){
d = 1/d;
}







// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-



/* Example 1: Given a pointer to an object, what operator is used to access a member of that object? */
1. To access a member of an object by using a pointer, use the arrow (-> operator.





/* Example 2: In Chapter 2, a strtype class was created that dynamically allocated space for a string. */
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


2. # include <iostream >
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
p = new char [ len +1];
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
delete [] p;
}
void strtype :: show ()
{
cout << p << " - length : " << len ;
cout << ’\n’;
}
int main ()
{
462ANSWERS
REVIEW SKILLS CHECK: Chapter 5
strtype s1(" This is a test ."), s2("I like C++");
s1. show ();
s2. show ();
return 0;}





/* Example 3: On your own, rework any program from the preceding chapter so that it uses a reference. */






// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-


/* Example 1: What is a reference? Give two important uses. */

1. A reference is a special type of pointer that is automatically dereferenced and that can be
used interchangeably with the object it is pointing to. There are three types of references:
parameter references, independent reference, and references that are returned by functions.





/* Example 2: Show how to allocate a float and an int by using new. Also, show how to free them by
using delete. */

2. # include <iostream >
using namespace std ;
int main ()
{
float *f;
int *i;
f = new float ;
i = new int ;
if (!f || !i)
{
cout << " Allocation error \n";
return 1;
} *
f = 10.101;
*i = 100;
cout << *f << ’ ’ << *i << ’\n’;
delete f;
delete i;
return 0;
}





/* Example 3: What is the general form of new that is used to initialize a dynamic variable? Give a
concrete example. */

3. The general form of new that includes an initializer is shown here:
p_var = new type ( initializer );
For example, this allocates an integer and gives it the value 10:
int *p;
p = new int (10) }





/* Example 4: Given the following class, show how to initialize a ten-element array so that x has the
value 1 through 10. */
class samp
{
int x;
public :
samp ( int n) { x = n; }
int getx () { return x; }
};

4. # include <iostream >
using namespace std ;
class samp
{
int x;
public :
samp ( int n) { x = n; }
int getx () { return x; }
};
int main ()
{
samp A [10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
int i;
for (i =0; i <10; i ++)
cout << A[i]. getx () << ’ ’;
cout << ’\n’;
return 0;
}





/* Example 5: Give one advantage of reference parameters. Give one disadvantage. */

5. Advantages: A reference parameter does not cause a copy of the object used in the call
to be made. A reference is often faster to pass than a value. The reference parameter
streamlines the call-by-reference syntax and procedure, reducing the chance for errors.
Disadvantages: Changes to a reference parameter open the possibility of side effects in
the calling routine.





/* Example 6: Can dynamically allocated arrays be initialized? */

6. No.



/* Example 7: Create a function called mag() using the following prototype that raises num to the order
of magnitude specified by order: */
void mag ( long &num , long order );
For example, if num is 4 and order is 2, when mag() returns, num will be 400. Demonstrate in a program that the function works.

7. # include <iostream >
using namespace std ;
void mag ( long &num , long order );
int main ()
{
long n = 4;
long o = 2;
cout << "4 raised to the 2nd order of magnitude is ";
mag (n, o);
cout << n << ’\n’;
return 0;
}
void mag ( long &num , long order )
{
for ( ; order ; order --)
num = num * 10;
}








// ------------    Cumulative/Masery/Review skill check    ------------

