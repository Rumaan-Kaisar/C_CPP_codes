
// --------    rev[13-Aug-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



/* Example 5: Give one advantage of reference parameters. Give one disadvantage. 

Advantages: 
    A reference parameter does not cause a copy of the object used in the call
to be made. A reference is often faster to pass than a value. The reference parameter
streamlines the call-by-reference syntax and procedure, reducing the chance for errors.

Disadvantages: 
    Changes to a reference parameter open the possibility of side effects in
the calling routine.
*/









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



