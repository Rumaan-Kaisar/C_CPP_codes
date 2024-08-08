
// --------    rev[06-Aug-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-



/* Example 1: Given a pointer to an object, what operator is used to access a member of that object? 
                
            ans:
                To access a "member" of an object by using a POINTER, use the arrow "->" operator.
*/




/* Example 2: In "ch10_01_2_constructor_destructor.cpp", in "Example 4" a strtype class 
                was created that dynamically allocated space for a string. 
                Later we improved it using parameterized constructor 

                It creates a simple string class, called 'strtype', that contains a 'string and its length'. 

                When a 'strtype' object is created, 
                    'memory' is allocated to hold the string and its initial length is set to 0. 

                When strtype object is destroyed, that memory is released
                The old program uses malloc() and free() to allocate and free memory.

                Rework the strtype class (shown here for your convenience) so it uses new and delete


#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
        int len;
    public:
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        void show();
};

// constructor:
strtype::strtype(char * ptr){
    len = strlen(ptr);  // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    if(!p){ // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 

    strcpy(p, ptr); // copy string to p
}

// destructor:
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}

void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


// In this version of strtype, a string is given an initial value using the constructor function.
int main(){
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();

    return 0;
}

*/


// using "new" and "delete"


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

