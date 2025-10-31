// ----  rev[31-Oct-2025]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

At this point you should be able to perform the following exercises and answer the questions.
1. Write a program that displays the number 100 in decimal, hexadecimal, and octal. (Use
the ios format flags.)
230INTRODUCING THE C++ I/O SYSTEM
SKILLS CHECK
2. Write a program that displays the value 1000.5364 in a 20-character field, left justified,
with two decimal places, using * as a fill character. (Use the ios format flags.)
3. Rewrite your answer to Exercises 1 and 2 so that they use I/O manipulators.
4. Show how to save the format flags for cout and how to restore them. Use either member
functions or manipulators.
5. Create an inserter and an extractor for this class:
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
6. Create a class called box that stores the dimensions of a square. Create an inserter that
displays a square box on the screen. (Use any method you like to display the box.



// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

1. Using the stack class shown here, create an inserter that displays the contents of the
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
231TEACH YOURSELF
C++
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
}
2. Write a program that contains a class called watch. Using the standard time functions,
have this class’s constructor read the system time and store it. Create an inserter that
displays the time.
3. Using the following class, which converts feet to inches, create an extractor that prompts
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
};




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. Write a program that displays the sentence "C++ is fun" in a 40-character-wide filed
using a colon (:) as the fill character.
2. Write a program that displays the outcome of 10/3 to three decimal places. Use ios
member functions to do this.
3. Redo the preceding program using I/O manipulators.
4. What is an inserter? What is an extractor?
5. Given the following class, create an inserter and an extractor for it.
class date
{
char d [9]; // store date as string : mm/dd/yy
public :
// add inserter and extractor
};
6. What header must be included if your program is to use I/O manipulators that take
parameters?
7. What predefined streams are created when a C++ program begins execution?







// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-
