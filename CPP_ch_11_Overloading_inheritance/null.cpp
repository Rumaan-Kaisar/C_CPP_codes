
// --------    rev[19-Nov-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

Mastery Skills Check
At this point you should be able to perform the following exercises and answer the questions.

1. Overload the date() constructor from Section 5.1, Example 3, so that it accepts a parameter of type time t. (Remember, time t is a type defined by the standard time and
date functions found in your C++ compiler’s library.)
2. What is wrong with the following fragment?
class samp
{
int a;
public :
samp ( int i) { a = i; }
// ...
};
// ...
int main ()
{
samp x, y (10) ;
// ...
}


3. Give two reasons why you might want (or need) to overload a class’s constructor.
4. What is the most common general form of a copy constructor?
5. What type of operations will cause the copy constructor to be invoked?
6. Briefly explain what the overload keyword does and why it is no longer needed.
7. Briefly describe a default argument.
8. Create a function called reverse() that takes two parameters. The first parameter, called
str, is a pointer to a string that will be reversed upon return from the function. The
second parameter is called count, and it specifies how many characters of str to reverse.
Give count a default value that, when present, tells reverse() to reverse the entire string.
9. What is wrong with the following prototype?
char * wordwrap ( char *str , int size = 0, char ch);
10. Explain some ways that ambiguity can be introduced when you are overloading functions.

11. What is wrong with the following fragment?
void compute ( double *num , int divisor =1) ;
void compute ( double * num );
// ...
compute (&x);
12. When you are assigning the address of an overloaded function to a pointer, what is it that
determines which version of the function is used?





// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.
1. Create a function called order() that takes two integer reference parameters. If the first
argument is greater than the second argument, reverse the two arguments. Otherwise,
take no action. That is order the two arguments used to call order() so that, upon return,
the first argument will be less than the second. For example, given
int x=1, y =0;
order (x, y);
following the call, x will be 0 and y will be 1.
2. Why are the following two overloaded functions inherently ambiguous?
int f( int a);
int f( int &a);
3. Explain why using a default argument is related to function overloading.
4. Given the following partial class, add the necessary constructor functions so that both
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
5. Briefly explain why copy constructors are needed




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. Show how to overload the constructor for the following class so that uninitialized objects
can also be created. (When creating uninitialized objects, give x and y the value 0.)
class myclass
{
int x, y;
public :
myclass ( int i, int j) { x=i; y=j; }
//
};
2. Using the class from Question 1, show how you can avoid overloading myclass() by using
default arguments.
3. What is wrong with these two overloaded functions?
void f( int a);
void f( int &a);
4. When is it appropriate to use default arguments? When is it probably a bad idea?
5. Given the following class definition, is it possible to dynamically allocate an array of these
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
6. What is a copy constructor and under what circumstances is it called?







// ------------    Cumulative/Masery/Review skill check    ------------



