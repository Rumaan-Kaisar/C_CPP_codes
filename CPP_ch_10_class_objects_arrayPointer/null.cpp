
// SKILLS CHECK



// -=-=-=-=-    Mastery Skills Check    -=-=-=-=-

At this point you should be able to perform the following exercises and answer the questions.
1. What is a constructor? What is a destructor? When are they executed?
2. Create a class called line that draws a line on the screen. Store the line length in a private
integer variable called len. Have line’s constructor take one parameter: the line length.
Have the constructor store the length and actually draw the line. If your system does not
support graphics, display the line by using *.
Optional: Give linea destructor that erases the line.
3. What does the following program display?
# include <iostream >
using namespace std ;
int main ()
{
int i = 10;
long l = 1000000;
double d = -0.0009;
cout << i << ’ ’ << l << ’ ’ << d;
cout << "\n";
return 0;
}
4. Add another derived class that inherits area cl from Section 2.3, Exercise 1. Call this
class cylinder and have it compute the surface area of a cylinder. Hint: The surface area
of a cylinder is: 2 ∗ π ∗ R2 + π ∗ D ∗ height:
5. What is an in-line function? What are its advantages and disadvantages?
6. Modify the following program so that all member functions are automatically in-lined:
# include <iostream >
using namespace std ;
class myclass
{
int i, j;
public :
myclass ( int x, int y);
void show ();
};
myclass :: myclass ( int x, int y)
{
i = x;
j = y;
}
void myclass :: show ()
{
cout << i << " " << j << "\n";
}
int main ()
{
myclass count (2, 3);
count . show ();
return 0;
}
7. What is the difference between a class and a structure?
8. Is the following fragment valid?
union
{
float f;
unsigned int bits ;
};





// -=-=-=-=-    Cumulative Skills Check    -=-=-=-=-

This section checks how well you have integrated material in this chapter with that from the
preceding chapter.
1. Create a class called prompt. Pass its constructor function a prompting string of your
own choosing. Have the constructor display the string and then input an integer. Have
the constructor display the string and then input an integer. Store this value in a private
variable called count. When an object of type prompt is destroyed, ring the bell on the
terminal as many times as the user entered.
2. In Chapter 1 you created a program that converted feet to inches. Now create a class that
does the same thing. Have the class store the number of feet and its equivalent number of
inches. Pass to the class’s constructor the number of feet and have the constructor display
the number of inches.
3. Create a class called dice that contains one private integer variable. Create a function
called roll() that uses the standard random number generator, rand(), to generate a
number between 1 and 6. Then have roll() display that value.





// -=-=-=-=-    Review Skills Check    -=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. Given the following class, what are the names of its constructor and destructor functions?
class widgit
{
int x, y;
public :
// ... fill in constructor and destructor functions
};
2. When is a constructor function called? When is a destructor function called?
3. Given the following base class, show how it can be inherited by a derived class called
Mars.
class planet
{
int moons ;
double dis_from_sun ;
double diameter ;
double mass ;
public :
// ...
};
4. There are two ways to cause a function to be expanded in line. What are they?
5. Give two possible restrictions to in-line functions.
6. Given the following class, show how an object called ob that passes the value 100 to a
and X to c would be declared.
class sample
{
int a;
char c;
public :
sample ( int x, char ch) { a = x; c = ch; }
// ...
};





