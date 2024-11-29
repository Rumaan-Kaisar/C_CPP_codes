
// --------    rev[29-Nov-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



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

