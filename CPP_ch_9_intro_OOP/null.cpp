SKILLS CHECK
Mastery Skills Check
At this point you should be able to perform the following exercises and answer the questions.



Example 1: Give brief descriptions of polymorphism, encapsulation, and inheritance.



Example 2: How can comments be included in a C++ program?



Example 3: Write a program that uses C++-style I/O to input two integers from the keyboard and
then displays the result of raising the first to the power of the second. (For example, if
the user enters 2 and 4, the result is 24, or 16.)



Example 4: Create a function called rev str() that reverses a string. Overload rev str() so it can be
called with either one character array or two. When it is called with one string, have that
one string contain the reversal. When it is called with two strings, return the reversed
string in the second argument. For example:
char s1 [80] , s2 [80];
strcpy (s1 , " hello ");
rev_str (s1 , s2); // reversed string goes in s2 , s1 untouched
rev_str (s1); // reversed string is returned in s1



Example 5: Given the following new-style C++ program, show how to change it into its old-style form.
# include <iostream >
using namespace std ;
int f( int a);
int main ()
{
cout << f (10) ;
return 0;
}
int f( int a)
{
return a * 3.1416;
}



Example 6: What is the bool data type?







Example 1: Write a program that uses C++-style I/O to prompt the user for a string and then display
its length.



Example 2: Create a class that holds name and address information. Store all the information in
character strings that are private members of the class. Include a public function that
stores the name and address. Also include a public function that displays the name and
address. (Call these functions store() and display().)



Example 3: Create an overloaded rotate() function that left-rotates the bits in its argument and
returns the result. Overload it so it accepts ints and longs. (A rotate is similar to a shift
except that the bit shifted off one end is shifted onto the other end.)



Example 4: What is wrong with the following fragment?
# include <iostream >
using namespace std ;
class myclass
{
int i;
public :
. . .
};
int main ()
{
myclass ob;
ob.i = 10;
. . . }

