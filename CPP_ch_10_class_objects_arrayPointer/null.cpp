


// SKILLS CHECK



// -=-=-=-=-    Mastery Skills Check    -=-=-=-=-

/* Example 1: What is a constructor? What is a destructor? When are they executed? 
                
                Ans:
                    A "constructor" is the function that is called when an object is created. 
                    A "destructor" is the function that is called when an object is destroyed.
*/




/* Example 2: Create a class called "line" that draws a line on the screen. 
                Store the line length in a 'private' integer variable called len. 
                Have line's constructor take one parameter: the line length.
                Have the constructor store the length and actually draw the line. 
                If your system does not support graphics, display the line by using *.

                Optional: Give line a destructor that erases the line. 
*/
#include <iostream>

class line{
        int len;
    public:
        line(int l);
};

line::line(int l){
    int i;
    len = l;
    // draw the line
    for (i =0; i<len; i++) std::cout << '*';
}

int main(){
    line l(10);
    return 0;
}




/* Example 3: What does the following program display? */
#include <iostream>

int main(){
    int i = 10;
    long l = 1000000;
    double d = -0.0009;

    std::cout << i << ' ' << l << ' ' << d;
    std::cout << "\n";

    return 0;
}

// 10 1000000 -0.0009




/* OLD Example 4: Given the following base class,

                    class area_cl{
                        public:
                            double height;
                            double width;
                    };

                Create two derived classes called 'rectangle' and 'isosceles' that inherit "area_cl". 
                Have each class include a function called area() 
                    that returns the area of a rectangle or isosceles triangle, as appropriate. 
                
                Add another derived class that inherits 'area_cl' from 'ch10_02_inheritance_intro.cpp', Example 4. 
                    Call this class 'cylinder' and have it compute the surface area of a cylinder. 
                    Hint: The surface area of a cylinder is: (2∗π∗R**2 + π∗D∗height).

                Use parameterized constructors to initialize height and width
                Use 'in-line functions' to implement member functions and constructors
*/

#include <iostream>

class area_c1{
    public:
        double height;
        double width;
};

// derived classes. Notice the in-line functions 
class rectangle:public area_c1{
    public:
        rectangle(double h, double w){height = h; width = w;}
        double area() { return width*height; }
};

class isosceles:public area_c1{
    public:
        isosceles(double h, double w){height = h; width = w;}
        double area(){ return 0.5*width*height; }
};

class cylinder:public area_c1{
    public:
        cylinder(double h, double w){height = h; width = w;}
        double area(){ return (2*3.1416*(width/2)*( width /2)) + (3.1416*width*height); }
};

// no implementation of member functions, we've already have in-lined functions


int main() {
    rectangle b(10.0, 5.0);
    isosceles i(4.0, 6.0);
    cylinder c(3.0, 4.0);

    std::cout << " Rectangle : " << b.area() << "\n";
    std::cout << " Triangle : " << i.area() << "\n";
    std::cout << " Cylinder : " << c.area() << "\n";

    return 0;
}







/* Example 5: What is an in-line function? What are its advantages and disadvantages? 

                An in-line function's code is expanded in line. 
                    This means that the function is not actually called, 
                        it's implemented by the compiler at the calling-pointg
                    
                    This avoids the overhead associated with the function 'call and return' mechanism.

                Advamtage: It increases the execution speed. 
                Disadvantage: It can increase the size of the program.
*/







/* Example 6: Modify the following program so that all member functions are automatically in-lined: */
#include <iostream>

using namespace std;

class myclass{
        int i, j;
    public:
        myclass(int x, int y);
        void show();
};

myclass::myclass(int x, int y){
    i = x;
    j = y;
}

void myclass::show(){
    cout << i << " " << j << "\n";
}

int main(){
    myclass count(2, 3);
    count.show();
    return 0;
}


// Modified  program using in-lined functions
#include <iostream>

class myclass{
        int i, j;
    public:
        myclass(int x, int y){ i = x; j = y; }
        void show(){ std::cout << i << " " << j; }
};

int main(){
    myclass count(2, 3);
    count.show();
    return 0;
}




/* Example 7: What is the difference between a class and a structure? 

                In a class, members are private by default. 
                In a structure, members are public by default.
*/






/* Example 8: Is the following fragment valid? */
union{
    float f;
    unsigned int bits;
};

// Ans: Yes. It defines an anonymous union.
















// ----  REV [8-mar-24]  ----


// -=-=-=-=-    Cumulative Skills Check    -=-=-=-=-

This section checks how well you have integrated material in this chapter with that from the
preceding chapter.


/* Example 1: Create a class called 'prompt'. Pass its constructor function a prompting string of your own choosing. 
                Have the constructor display the string and then input an integer. 
                Store this value in a private variable called 'count'. 

                When an object of type prompt is destroyed, 
                    ring the bell on the terminal as many times as the user entered. 
*/

1. # include <iostream >
using namespace std ;
class prompt
{
int count ;
public :
prompt ( char *s) { cout << s; cin >> count ; }
~ prompt ();
};
prompt ::~ prompt ()
{
int i, j;
for (i =0; i< count ; i ++)
{
cout << ’\a’;
for (j =0; j <32000; j++) ; // delay
}
}
int main ()
{
prompt ob(" Enter a number : ");
return 0;
}




/* Example 2: Previously we created a program that converted feet to inches. 
                Now create a class that does the same thing. 
                Have the class store the number of feet and its equivalent number of inches. 
                Pass to the class's constructor the number of feet and 
                    have the constructor display the number of inches.
*/

2. # include <iostream >
using namespace std ;
class ftoi
{
double feet ;
double inches ;
public :
ftoi ( double f);
};
ftoi :: ftoi ( double f)
{
feet = f;
inches = feet * 12;
cout << feet << " is " << inches << " inches .\n";
}
int main ()
{
ftoi a (12.0) , b (99.0) ;
return 0;
}




/* Example 3: Create a class called dice that contains one private integer variable. 
                Create a function called roll() that uses the standard random number generator, rand(), 
                    to generate a number between 1 and 6. Then have roll() display that value. 
*/

3. # include <iostream >
# include <cstdlib >
using namespace std ;
class dice
{
int val ;
public :
void roll ();
};
void dice :: roll ()
{
val = ( rand () % 6) + 1; // generate 1 through 6
cout << val << "\n";
}
int main ()
{
dice one, two;
one.roll();
two.roll();
one.roll();
two.roll();
one.roll();
two.roll();

return 0;
}










// -=-=-=-=-    Review Skills Check    -=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.




/* Example 1: Given the following class, what are the names of its 'constructor' and 'destructor' functions? */

class widgit{
        int x, y;
    public:
        // ... fill in constructor and destructor functions
};

// Constructor is called widgit() and 
// Destructor is called ~widgit().






/* Example 2: When is a constructor function called? When is a destructor function called? 

                Constructor function is called when an object is created 
                    (i.e., when an object comes into existence). 

                Destructor is called when an object is destroyed.
*/






/* Example 3: Given the following base class, 
                show how it can be inherited by a derived class called 'Mars'. 
*/

class planet{
        int moons;
        double dis_from_sun;
        double diameter;
        double mass;
    public:
        // ...
};

// Ans:  derived class called 'Mars'
class Mars:public planet{
    // ...
};




/* Example 4: There are two ways to cause a function to be expanded 'in-line'. What are they? */
1. use 'inline' keyword:
2. define a function inside a class declaration:

You can expand a function in line either by preceding its definition with the inline specifier
or by including its definition within a class declaration.




/* Example 5: Give two possible restrictions to 'in-line' functions. */
5. An in-line function must be defined before it is first used. Other common restrictions
include the following: It cannot contain any loops. It must not be recursive. It cannot
contain a goto or a switch statement. It cannot contain any static variables.




/* Example 6: Given the following class, show how an object called 'ob' that passes the value 
                '100 to a'and 'X to c' would be declared. 
*/
class sample
{
int a;
char c;
public :
sample ( int x, char ch) { a = x; c = ch; }
// ...
};

6. sample ob (100 , ’X’);



