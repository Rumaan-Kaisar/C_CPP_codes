
// --------    rev[22-Nov-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-



// ----  rev[25-Nov-2024]  ----

/* Example 8: Create a function called reverse() that takes two parameters. 

                The first parameter, called "str", is a pointer to a string 
                    that will be reversed upon return from the function. 

                The second parameter is called "count", and 
                    it specifies how many characters of str to reverse.

                Give count a default value that, when present, tells reverse() to reverse the entire string.
 */

#include <iostream>
#include <cstring>

void reverse(char *str , int count = 0);

int main ()
{
char s1 [] = " This is a test .";
472ANSWERS
CUMULATIVE SKILLS CHECK: Chapter 5
char s2 [] = "I like C++. ";
reverse (s1); // reverses entire string
reverse (s2 , 7); // reverse first 7 chars
cout << s1 << ’\n’;
cout << s2 << ’\n’;
return 0;
}

void reverse ( char *str , int count )
{
int i, j;
char temp ;
if (! count )
count = strlen (str) - 1;
for (i=0, j= count ; i<j; i++, j --)
{
temp = str [i];
str [i] = str [j];
str [j] = temp ;
}
}



/* Example 9: What is wrong with the following prototype?
char * wordwrap ( char *str , int size = 0, char ch); */
9. All parameters receiving default arguments must appear to the right of those that do not.



/* Example 10: Explain some ways that ambiguity can be introduced when you are overloading functions. */
10. Ambiguity can be introduced by default type conversions, reference parameters, and default arguments.



/* Example 11: What is wrong with the following fragment?
void compute ( double *num , int divisor =1) ;
void compute ( double * num );
// ...
compute (&x);
 */
11. It is ambiguous because the compiler cannot know which version of compute() to call.
Is it the first version, with divisor defaulting? Or is it the second version, which takes
only one parameter?



/* Example 12: When you are assigning the address of an overloaded function to a pointer, what is it that
determines which version of the function is used? */
12. When you are obtaining the address of an overloaded function, it is the type specification
of the pointer that determines which function is used.






// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.



/* Example 1: Create a function called order() that takes two integer reference parameters. If the first
argument is greater than the second argument, reverse the two arguments. Otherwise,
take no action. That is order the two arguments used to call order() so that, upon return,
the first argument will be less than the second. For example, given
int x=1, y =0;
order (x, y);
following the call, x will be 0 and y will be 1.
 */


1. # include <iostream >
using namespace std ;
void order ( int &a, int &b)
{
int t;
if(a<b)
return ;
else // swap a and b
{
t = a;
473TEACH YOURSELF
C++
a = b;
b = t;
}
}
int main ()
{
int x=10 , y =5;
cout << "x: " << x << ", y: " << y << ’\n’;
order (x, y);
cout << "x: " << x << ", y: " << y << ’\n’;
return 0;
}



/* Example 2: Why are the following two overloaded functions inherently ambiguous?
int f( int a);
int f( int &a); */
2. The syntax for calling a function that takes a reference parameter is identical to the syntax
for calling a function that takes a value parameter.



/* Example 3: Explain why using a default argument is related to function overloading. */
3. A default argument is essentially a shorthand approach to function overloading because
the net result is the same.
For example,
int f( int a, int b = 0);
is functionally equivalent to these two overloaded functions:
int f( int a);
int f( int a, int b);



/* Example 4: Given the following partial class, add the necessary constructor functions so that both
declarations within main() are valid. (Hint: You need to overload samp() twice.)
class samp
{
int a;
public :
// add constructor functions
int get_a () { return a; }
};
int main ()
{
samp ob (88) ; // init ob ’s a to 88
samp obarray [10]; // non - initialized 10- element array
// ...
}
 */
4. # include <iostream >
using namespace std ;
class samp
{
int a;
public :
samp () { a = 0; }
samp ( int n) { a = n; }
int get_a () { return a; }
};
int main ()
{
samp ob (88) ;
samp obarray [10];
// ...
}
474ANSWERS
REVIEW SKILLS CHECK: Chapter 6



/* Example 5: Briefly explain why copy constructors are needed */
5. Copy constructors are needed when you, the programmer, must control precisely how a
copy of an object is made. This is important only when the default bitwise copy creates
undesired side effects.




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.



/* Example 1: Show how to overload the constructor for the following class so that uninitialized objects
can also be created. (When creating uninitialized objects, give x and y the value 0.)
class myclass
{
int x, y;
public :
myclass ( int i, int j) { x=i; y=j; }
//
};
 */
1. class myclass
{
int x, y;
public :
myclass ( int i, int j) { x=i; y=j; }
myclass () { x =0; y =0; }
};



/* Example 2: Using the class from Question 1, show how you can avoid overloading myclass() by using
default arguments. */
2. class myclass
{
int x, y;
public :
myclass ( int i=0, int j=0) { x=i; y=j; }
};



/* Example 3: What is wrong with these two overloaded functions?
void f( int a);
void f( int &a); */
3. Once default arguments have begun, a non-defaulting parameter cannot occur.



/* Example 4: When is it appropriate to use default arguments? When is it probably a bad idea? */
4. A function cannot be overloaded when the only difference is that one version takes a value
parameter and the other takes a reference parameter. (The compiler cannot tell them
apart.)



/* Example 5: Given the following class definition, is it possible to dynamically allocate an array of these
objects?
class test
{
char *p;
int *q;
int count ;
public :
test ( char *x, int *y, int c)
{
p = x;
q = y;
count = c;
}
// ...
};
 */
5. It is appropriate to use default arguments when there are one or more values that will
occur frequently. Is is inappropriate when there is no value or values that have a greater
likelihood of occurring.



/* Example 6: What is a copy constructor and under what circumstances is it called? */
6. No, because there is no way to initialize a dynamic array. This class has only one constructor, and it requires initializers.
7. A copy constructor is a special constructor that is called when one object initializes another. This circumstance can occur in any of the following three ways: When one object
is explicitly used to initialize another, when an object is passed to a function, or when a
temporary object is created as a function return value.






// ------------    Cumulative/Masery/Review skill check    ------------

