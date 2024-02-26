
SKILLS CHECK
Mastery Skills Check
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



