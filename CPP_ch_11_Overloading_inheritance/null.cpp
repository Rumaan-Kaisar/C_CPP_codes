

// --------    rev[09-Jun-25]    --------


// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-







// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-



// basic
/* Example 1: Create a generic "base" class called "building" that stores:
                    the number of floors a building has,
                    the number of rooms, and 
                    its total square footage. 

                Create "derived" class called "house" that:
                    inherits building and also 
                    stores the number of bedrooms and 
                    the number of bathrooms.

                Next, create a "derived" class called "office" that inherits "building" and also stores 
                    the number of fire extinguishers and 
                    the number of telephones.
*/

#include <iostream>

class building {
    protected :
        int floors;
        int rooms;
        double footage;
};


class house : public building {
        int bedrooms;
        int bathrooms;
    public:
        house(int f, int r, double ft, int br, int bth) {
            floors = f;
            rooms = r;
            footage = ft;
            bedrooms = br;
            bathrooms = bth;
        }
        void show() {
            std::cout << " floors : " << floors << '\n';
            std::cout << " rooms : " << rooms << '\n';
            std::cout << " square footage : " << footage << '\n';
            std::cout << " bedrooms : " << bedrooms << '\n';
            std::cout << " bathrooms : " << bathrooms << '\n';
        }
};


class office : public building {
        int phones;
        int extinguishers;
    public :
        office(int f, int r, double ft , int pn, int ext) {
            floors = f;
            rooms = r;
            footage = ft;
            phones = pn;
            extinguishers = ext;
        }
        void show() {
            std::cout << " floors : " << floors << '\n';
            std::cout << " floors : " << floors << '\n';
            std::cout << " rooms : " << rooms << '\n';
            std::cout << " square footage : " << footage << '\n';
            std::cout << " Telephones : " << phones << '\n';
            std::cout << " fore extinguishers : ";
            std::cout << extinguishers << '\n';
        }
};


int main() {
    house h_ob(2, 12, 5000 , 6, 4);
    office o_ob(4, 25, 12000 , 30, 8);

    std::cout << " House :\n";
    h_ob.show();

    std::cout << "\ nOffice :\n";
    o_ob.show();

    return 0;
}



// access specifier

/* Example 2: When a "base" class is inherited as "public" by the derived class, 
                    what happens to its public members? 
                    What happens to its private members? 

                If the base is inherited as private by the derived class, 
                    what happens to its public and private members? 


                Public inheritance:
                    Public members of the base stay public in the derived class.
                    Private members of the base stay private to the base.

                Private inheritance:
                    All members of the base become private in the derived class.

*/



// access specifier

/* Example 3: Explain what "protected" means.
                Explain what it means both when referring to members of a class and 
                when it is used as an inheritance access specifier.


                When declaring members:
                    protected members are like private members — they aren't accessible by outside code,
                    but can be accessed by derived classes.

                When "protected" used as an inheritance access specifier:
                    If a class inherits a base class as protected, then:
                    The base's public and protected members become protected in the derived class.
                    Private members of the base still stay private to the base.
*/



// constructors destructors orders
/* Example 4: When one class inherits another, when are the classe's constructors called? 
                When are their destructors called? 
            ans:
                Constructors are called in "order of derivation". 
                Destructors are called in "reverse order".
*/






/* Example 5: Given this skeleton, fill in the details as indicated in the comments: */

# include <iostream>

class planet {
    protected:
        double distance;    // miles from the sun
        int revolve;        // in days
    public:
        planet(double d, int r) { distance = d; revolve = r; }
};

class earth : public planet {
        double circumference;   // circumference of orbit
    public:

        // Create earth( double d, int r). 
            // Have it pass the distance and days of revolution back to planet.
            // Have it compute the circumference of the orbit.
            // (Hint : circumference = 2r *3.1416.)
            // Create a function called show() that displays the information
};


int main() {
    earth ob(93000000 , 365) ;
    ob.show();

    return 0;
}


5. # include <iostream >
using namespace std ;
class planet
{
protected :
double distance ; // miles from the sun
int revolve ; // in days
public :
planet ( double d, int r) { distance = d; revolve = r; }
};
class earth : public planet
{
double circumference ;
public :
earth ( double d, int r) : planet (d, r)
{
circumference = 2* distance *3.1416;
}
void show ()
{
cout << " Distance from sun : " << distance << ’\n’;
cout << " Days in orbit : " << revolve << ’\n’;
cout << " Circumference of orbit : ";
cout << circumference << ’\n’;
}
};
int main ()
{
earth ob (93000000 , 365) ;
ob. show ();
return 0;
}




/* Example 6: Fix the following program: */
/*
A variation on the vehicle hierarchy . But
this program contains an error . Fix it. Hind :
try compiling it as is and observe the error
messages .
*/
# include <iostream >
using namespace std ;
// A base class for various types of vehicles .
class vehicle
{
int num_wheels ;
int range ;
public :
vehicle ( int w, int r)
{
num_wheels = w;
range = r;
}
void showv ()
{
cout << " Wheels : " << num_wheels << ’\n’;
cout << " Range : " << range << ’\n’;
199TEACH YOURSELF
C++
}
};
enum motor {gas , electric , diesel };
class motorized : public vehicle
{
enum motor mtr ;
public :
motorized ( enum motor m, int w, int r) : vehicle (w, r)
{
mtr = m;
}
void showm ()
{
cout << " Motor : ";
switch ( mtr )
{
case gas : cout << "Gas \n";
break ;
case electric : cout << " Electric \n";
break ;
case diesel : cout << " Diesel \n";
break ;
}
}
};
class road_use : public vehicle
{
int passengers ;
public :
road_use ( int p, int w, int r) : vehicle (w, r)
{
passengers = p;
}
void showr ()
{
cout << " Passengers : " << passengers << ’\n’;
}
};
enum steering { power , rack_pinion , manual };
class car : public motorized , public road_use
{
enum steering strng ;
public :
car ( enum steering s, enum motor m, int w, int r, int p) :
road_use (p, w, r), motorized (m, w, r), vehicle (w, r)
{
200INHERITANCE
SKILLS CHECK
strng = s;
}
void show ()
{
showv ();
showr ();
showm ();
cout << " Steering : ";
switch ( strng )
{
case power : cout << " Power \n";
break ;
case rack_pinion : cout << " Rack and Pinion \n";
break ;
case manual : cout << " Manual \n";
break ;
}
}
};
int main ()
{
car c(power , gas , 4, 500 , 5);
c. show ();
return 0;
}


6. To fix the program, have motorized and road use inherit vehicle as a virtual base class.
Also, refer to Question 1 in the Cumulative Skills Check in this chapter.





// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

Cumulative Skills Check
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.




/* Example 1: In Exercise 6 from the preceding Mastery Skills Check section, you might have seen a
warning message (or perhaps an error message) concerning the use of the switch statement
within car and motorized. Why? */

1. Some compilers will not allow you to use a switch in an in-line function. If this is the
case with your compiler, the functions were automatically made into "regular" functions.




/* Example 2: As you know from the preceding chapter, most operators overloaded in a base class are
available for use in a derived class. Which one or ones are not? Can you offer a reason
why this is the case? */

2. The assignment operators is the only operator that is not inherited. The reason for this
is easy to understand. Since a derived class will contain members not found in the base
class, the overloaded = relative to the base has no knowledge of the members added by
the derived class and, as such, cannot properly copy those new members.




/* Example 3: Following is a reworked version of the coord class from the previous chapter. This time
it is used as a base for another class called quad, which also maintains the quadrant the
specific point is in. On your own, run this program and try to understand its output. */

/*
Overload the +, -, and = relative to coord class . Then
use coord as a base for quad .
*/
# include <iostream >
using namespace std ;
201TEACH YOURSELF
C++
class coord
{
public :
int x, y; // coordinate values
coord () { x =0; y =0; }
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
coord operator +( coord ob2);
coord operator -( coord ob2);
coord operator =( coord ob2);
};
// Overload + relative to coord class .
coord coord :: operator +( coord ob2)
{
coord temp ;
cout << " Using coord operator +() \n";
temp .x = x + ob2 .x;
temp .y = y + ob2 .y;
return temp ;
}
// Overload - relative to coord class .
coord coord :: operator -( coord ob2)
{
coord temp ;
cout << " Using coord operator -() \n";
temp .x = x - ob2 .x;
temp .y = y - ob2 .y;
return temp ;
}
// Overload = relative to coord .
coord coord :: operator =( coord ob2)
{
cout << " Using coord operator =() \n";
x = ob2 .x;
y = ob2 .y;
return * this ; // return the object that is assigned to
}
class quad : public coord
{
202INHERITANCE
SKILLS CHECK
int quadrant ;
public :
quad ()
{
x = 0;
y = 0;
quadrant = 0;
}
quad ( int x, int y) : coord (x, y)
{
if(x >=0 && y >= 0)
quadrant = 1;
else if(x <0 && y >=0)
quadrant = 2;
else if(x <0 && y <0)
quadrant = 3;
else
quadrant = 4;
}
void showq ()
{
cout << " Point in Quadrant : " << quadrant << ’\n’;
}
quad operator =( coord ob2 );
};
quad quad :: operator =( coord ob2 )
{
cout << " Using quad operator =() \n";
x = ob2 .x;
y = ob2 .y;
if(x >=0 && y >= 0)
quadrant = 1;
else if(x <0 && y >=0)
quadrant = 2;
else if(x <0 && y <0)
quadrant = 3;
else
quadrant = 4;
return * this ;
}
int main ()
{
quad o1 (10 , 10) , o2 (15 , 3) , o3;
int x, y;
o3 = o1 + o2; // add two objects - this calls operator +()
o3. get_xy (x, y);
203TEACH YOURSELF
C++
o3. showq ();
cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";
o3 = o1 - o2; // subtract two objects
o3. get_xy (x, y);
o3. showq ();
cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";
o3 = o1; // assign an object
o3. get_xy (x, y);
o3. showq ();
cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";
return 0;
}



/* Example 4: Again on your own, convert the program shown in Exercise 3 so that it uses friend operator
functions. */












// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.




/* Example 1: Create a class hierarchy that stores information about airships. Start with a general
base class called airship that stores the number of passengers and the amount of cargo
(in pounds) that can be carried. Then create two derived classes called airplane and
balloon from airship. Have airplane store the type of engine used (propeller or jet)
and range, in miles. Have balloon store information about the type of gas used to lift
the balloon (hydrogen or helium) and its maximum altitude (in feet). Create a short
program that demonstrates this class hierarchy. (Your solution will, no doubt, differ from
the answer shown in the back of this book. If it is functionally similar, count it as correct.) */


1. # include <iostream >
using namespace std ;
class airship
{
protected :
int passengers ;
double cargo ;
};
class airplane : public airship
{
char engine ; // p for propeller , j for jet
double range ;
public :
airplane ( int p, double c, char e, double r)
{
passengers = p;
cargo = c;
engine = e;
range = r;
}
void show ();
};
class balloon : public airship
{
char gas ; // h for hydrogen , e for helium
double altitude ;
public :
balloon ( int p, double c, char g, double a)
{
passengers = p;
cargo = c;
gas = g;
altitude = a;
}
void show ();
};
void airplane :: show ()
{
cout << " Passengers : " << passengers << ’\n’;
cout << " Cargo capacity : " << cargo << ’\n’;
508ANSWERS
REVIEW SKILLS CHECK: Chapter 8
cout << " Engine : ";
if( engine == ’p’)
cout << " Propeller \n";
else
cout << " Jet \n";
cout << " Range : " << range << ’\n’;
}
void balloon :: show ()
{
cout << " Passengers : " << passengers << ’\n’;
cout << " Cargo capacity : " << cargo << ’\n’;
cout << " Gas : ";
if( gas == ’h’)
cout << " Hydrogen \n";
else
cout << " Helium \n";
cout << " Altitude : " << altitude << ’\n’;
}
int main ()
{
balloon b(2, 500.0 , ’h’, 12000.0) ;
airplane b727 (100 , 40000.0 , ’j’, 40000.0) ;
b. show ();
cout << ’\n’;
b727 . show ();
return 0;
}




/* Example 2: What is protected used for? */

2. The protected access specifier causes a class member to be private to its class but still
accessible by any derived class.




/* Example 3: Given the following class hierarchy, in what order are the constructor functions called? In
what order are the destructor functions called? */
# include <iostream >
using namespace std ;
class A
{
public :
A() { cout << " Constructing A\n"; }
206INTRODUCING THE C++ I/O SYSTEM
~A() { cout << " Destructing A\n"; }
};
class B : public A
{
public :
B() { cout << " Constructing B\n"; }
~B() { cout << " Destructing B\n"; }
};
class C : public B
{
public :
C() { cout << " Constructing C\n"; }
~C() { cout << " Destructing C\n"; }
};
int main ()
{
C ob;
return 0;
}

3. The program displays the following output, which indicates when the constructors and
destructors are called.
Constructing A
Constructing B
Constructing C
Destructing C
Destructing B
Destructing A


/* Example 4: Given the following fragment, in what order are the constructor functions called?
class myclass : public A, public B, public C
{
// ...
};
*/
4. Constructors are called in the order ABC, destructors in the order CBA.




/* Example 5: Fill in the missing constructor functions in this program: */
# include <iostream >
using namespace std ;
class base
{
int i, j;
public :
// need constructor
void showij () { cout << i << ’ ’ << j << ’\n’; }
};
class derived : public base
{
int k;
public :
// need constructor
void show () { cout << k << ’ ’; showij (); }
};
int main ()
207TEACH YOURSELF
C++
{
derived ob (1, 2, 3);
ob. show ();
return 0;
}



5. # include <iostream >
using namespace std ;
509TEACH YOURSELF
C++
class base
{
int i, j;
public :
base ( int x, int y) { i = x; j = y; }
void showij () { cout << i << ’ ’ << j << ’\n’; }
};
class derived : public base
{
int k;
public :
derived ( int a, int b, int c) : base (b, c)
{
k = a;
}
void show () { cout << k << ’ ’; showij (); }
};
int main ()
{
derived ob (1, 2, 3);
ob. show ();
return 0;
}




/* Example 6: In general, when you define a class hierarchy, you begin with the most
class and move to the most class. (Fill in the missing words.) */


6. The missing words are "general" and "specific".






