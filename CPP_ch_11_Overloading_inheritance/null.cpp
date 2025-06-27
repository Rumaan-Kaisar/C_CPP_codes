

// --------    rev[09-Jun-25]    --------


// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-







// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-



// basic: tested
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

    std::cout << "\nOffice :\n";
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






/* Example 5: Given this skeleton, fill in the details as indicated in the comments: 


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
*/

#include <iostream>


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
        earth(double d, int r) : planet(d, r) { // pass the distance and days of revolution back to planet.
            // circumference of the orbit.
            circumference = 2* distance *3.1416;
        }
        // show() displays the information
        void show() {
            std::cout << " Distance from sun : " << distance << '\n';
            std::cout << " Days in orbit : " << revolve << '\n';
            std::cout << " Circumference of orbit : ";
            std::cout << circumference << '\n';
        }            
};


int main() {
    earth ob(93000000 , 365) ;
    ob.show();

    return 0;
}




/* Example 6: Fix the following program: A variation on the vehicle hierarchy.
                But this program contains an error, Fix it. 

                Hint: try compiling it as is and observe the error messages.


                Error:
                    sol.cpp: In constructor ‘car::car(steering, motor, int, int, int)’:
                    sol.cpp:73:106: error: type ‘vehicle’ is not a direct base of ‘car’
                        |         car(enum steering s, enum motor m, int w, int r, int p) : road_use(p, w, r), motorized(m, w, r), vehicle(w, r) {
                        |                                                                                                          ^~~~~~~
                    sol.cpp: In member function ‘void car::show()’:
                    sol.cpp:77:13: error: reference to ‘showv’ is ambiguous
                        |             showv();
                        |             ^~~~~
                    sol.cpp:20:10: note: candidates are: ‘void vehicle::showv()’

                


#include <iostream>

// A base class for various types of vehicles .
class vehicle {
        int num_wheels;
        int range;
    public:
        vehicle(int w, int r) {
            num_wheels = w;
            range = r;
        }
    void showv() {
        std::cout << " Wheels : " << num_wheels << '\n';
        std::cout << " Range : " << range << '\n';
    }
};


enum motor { gas , electric , diesel };


class motorized : public vehicle {
        enum motor mtr;
    public:
        motorized(enum motor m, int w, int r) : vehicle (w, r) {
            mtr = m;
        }
        void showm() {
            std::cout << " Motor : ";
            switch(mtr) {
                case gas:
                    std::cout << "Gas \n";
                    break;

                case electric:
                    std::cout << " Electric \n";
                    break;

                case diesel:
                    std::cout << " Diesel \n";
                    break ;
            }
        }
};


class road_use : public vehicle {
        int passengers;
    public:
        road_use(int p, int w, int r) : vehicle (w, r) {
            passengers = p;
        }
    void showr() {
        std::cout << " Passengers : " << passengers << '\n';
    }
};


enum steering { power , rack_pinion , manual };


class car : public motorized , public road_use {
        enum steering strng;
    public:
        car(enum steering s, enum motor m, int w, int r, int p) : road_use(p, w, r), motorized(m, w, r), vehicle(w, r) {
            strng = s;
        }
        void show() {
            showv();
            showr();
            showm();
            std::cout << " Steering : ";
            switch(strng) {
                case power:
                    std::cout << " Power \n";
                    break;
                case rack_pinion:
                    std::cout << " Rack and Pinion \n";
                    break;
                case manual:
                    std::cout << " Manual \n";
                    break;
            }
        }
};


int main() {
    car c(power , gas , 4, 500 , 5);
    c.show();

    return 0;
}



            ans:
                To fix the program, make 'motorized' and 'road_use' inherit 'vehicle' as a "virtual base class".
                
                you might have seen a warning message (or perhaps an error message):
                    Some compilers don't allow a switch statement inside an inline function.
                    If that happens, the compiler automatically treats the function as a regular (non-inline) function.

*/

#include <iostream>

// A base class for various types of vehicles .
class vehicle {
        int num_wheels;
        int range;
    public:
        vehicle(int w, int r) {
            num_wheels = w;
            range = r;
        }
    void showv() {
        std::cout << " Wheels : " << num_wheels << '\n';
        std::cout << " Range : " << range << '\n';
    }
};


enum motor { gas , electric , diesel };


class motorized : virtual public vehicle {
        enum motor mtr;
    public:
        motorized(enum motor m, int w, int r) : vehicle (w, r) {
            mtr = m;
        }
        void showm() {
            std::cout << " Motor : ";
            switch(mtr) {
                case gas:
                    std::cout << "Gas \n";
                    break;

                case electric:
                    std::cout << " Electric \n";
                    break;

                case diesel:
                    std::cout << " Diesel \n";
                    break ;
            }
        }
};


class road_use : virtual public vehicle {
        int passengers;
    public:
        road_use(int p, int w, int r) : vehicle (w, r) {
            passengers = p;
        }
    void showr() {
        std::cout << " Passengers : " << passengers << '\n';
    }
};


enum steering { power , rack_pinion , manual };


class car : public motorized , public road_use {
        enum steering strng;
    public:
        car(enum steering s, enum motor m, int w, int r, int p) : road_use(p, w, r), motorized(m, w, r), vehicle(w, r) {
            strng = s;
        }
        void show() {
            showv();
            showr();
            showm();
            std::cout << " Steering : ";
            switch(strng) {
                case power:
                    std::cout << " Power \n";
                    break;
                case rack_pinion:
                    std::cout << " Rack and Pinion \n";
                    break;
                case manual:
                    std::cout << " Manual \n";
                    break;
            }
        }
};


int main() {
    car c(power , gas , 4, 500 , 5);
    c.show();

    return 0;
}




// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

// ----------------    operator overloading and inheritance    ----------------

/* Example 2: from the preceding examples (in C++ operator overloading ch11_05_1 - ch11_05_4), 
                most operators overloaded in a base class are available for use in a derived class. 
                
                Which one or ones are not? 
                Can you offer a reason why this is the case?


            ans:
                The assignment operators "=" is the only operator that is not inherited.
                    In C++, most "Overloaded Operators" in a base class are inherited by the derived class and remain usable.
                    However, the "Assignment" operator (operator=) is not automatically inherited by a derived class.

                Reason:
                    A derived class often has "extra members" not present in the base class. 
                    The base class's overloaded "operator=" doesn't know about these new members, so it can't copy them correctly.

                    That's why a derived class should define its own operator= if needed.

                    Most operators (+, -, *, [], etc.) behaves properly through inheritance
                    operator= needs to handle new members in derived class

                also:
                    Each class needs to handle its own resources and member variables safely during assignment.
                    The compiler-generated or base class operator= would only copy the base class members — 
                        ignoring any new members added in the derived class.
*/


// ----  rev[23-Jun-2025]  ----



/* Example 3: Following is a reworked version of the coord class from the previous 
                operator overloading codes (eg: ch11_06_ovrldOpr_friend.cpp)

                This time it is used as a "base" for another class called "quad", 
                    which also maintains the quadrant the specific point is in. 

                So we Overload the +, -, and = relative to "coord" class.
                    Then use coord as a base for quad.
                    (recall Example 2 of ch11_05_2_ovrldOpr_binary.cpp)

                On your own, run this program and try to understand its output. 

            issues:                
                in coord class, private coordinate variables x, y cause problems.
                If we can make them public, the program compiles properly.
*/


#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord() { x =0; y =0; }
        coord(int i, int j) { x=i; y=j; }
        void get_xy(int &i, int &j) { i=x; j=y; }

        // OPERATOR OVERLOADING: coord type used for overloaded operator
        coord operator+(coord ob2);
        coord operator-(coord ob2);
        coord operator=(coord ob2);
};


// Overload '+' relative to coord class.
coord coord::operator+(coord ob2) {
    coord temp;
    std::cout << " Using coord operator +() \n";
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

// Overload '-' relative to coord class.
coord coord::operator-(coord ob2) {
    coord temp;
    std::cout << " Using coord operator -() \n";
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    return temp;
}

// Overload '=' relative to coord class.
coord coord::operator=(coord ob2) {
    std::cout << " Using coord operator =() \n";
    x = ob2.x;
    y = ob2.y;
    return *this;
    // return the object that is assigned. Noticem, no "temp" is used
}

// "quad" class inheriting "coord"
class quad : public coord {
        int quadrant;
    public:
        quad() {
            x = 0;
            y = 0;
            quadrant = 0;
        }
        quad(int x, int y) : coord (x, y) {
            if(x >=0 && y >= 0) 
                quadrant = 1;
            else if(x <0 && y >=0) 
                quadrant = 2;
            else if(x <0 && y <0) 
                quadrant = 3;
            else 
                quadrant = 4;
        }
        void showq() {
            std::cout << " Point in Quadrant : " << quadrant << '\n';
        }
        // quad's own overladed '=' operator
        quad operator=( coord ob2 );
};


// Overload '=' relative to 'quad' class again
quad quad :: operator=( coord ob2 ) {
    std::cout << " Using quad operator =() \n";

    x = ob2.x;
    y = ob2.y;

    if(x >=0 && y >= 0)
        quadrant = 1;
    else if(x <0 && y >=0)
        quadrant = 2;
    else if(x <0 && y <0)
        quadrant = 3;
    else
        quadrant = 4;

    return * this;
}


int main() {
    quad o1(10, 10), o2(15, 3), o3;
    int x, y;

    o3 = o1 + o2; // add two objects - this calls operator +()
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 - o2; // subtract two objects
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1; // assign an object
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}

/* 
Excellent — let’s carefully analyze and clarify what’s happening in this code.
I’ll explain it pointwise and highlight key points, corrections, and observations:

📌 Key Purpose
coord is a base class for 2D points.

quad is a derived class adding quadrant information to those points.

+, -, and = operators are overloaded in coord.

quad also overloads = because assigning a coord to a quad should recalculate its quadrant.

📌 Issues / Points You Should Note
✅ 1️⃣ Private Members Issue
In coord, x and y are private — so quad cannot access them directly like this:

cpp
Copy
Edit
x = ob2.x;
y = ob2.y;
Fix:
Make x and y either protected or provide getter/setter functions in coord.

✅ 2️⃣ Operator = Should Return a Reference
By convention, operator= should return a reference to the current object (*this), not a copy.

Correct declaration:

cpp
Copy
Edit
coord& operator=(coord ob2);
quad& operator=(coord ob2);
📌 Simplified Execution Flow:
Addition (o1 + o2)

Calls coord::operator+()

Adds x and y

Returns a coord object (but assigned to o3, a quad → calls quad::operator=())

Subtraction (o1 - o2)

Similar to above, using operator-()

Assignment (o3 = o1)

Calls quad::operator=()

Assigns values, recalculates quadrant.

📌 Quadrant Logic
Quadrant is decided based on signs of x and y

Values:

(+,+) → 1

(-,+) → 2

(-,-) → 3

Else → 4

📌 Final Clean Suggestion
Use protected for x and y:

cpp
Copy
Edit
class coord {
protected:
    int x, y;
    ...
};
And update both operator= return types to reference:

cpp
Copy
Edit
coord& coord::operator=(coord ob2)
quad& quad::operator=(coord ob2)
✅ Summary
This program demonstrates:

Inheritance with operator overloading

How base operators can be reused by derived classes

Why sometimes derived classes need their own overloads (like = here for quadrant recalculation)

Would you like me to post a clean, fixed version of this code as well? ⚙️
*/




/* Example 4: Convert the previous program so that it uses friend operator functions. */
#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord() { x =0; y =0; }
        coord(int i, int j) { x=i; y=j; }
        void get_xy(int &i, int &j) { i=x; j=y; }

        // OPERATOR OVERLOADING: coord type used for overloaded operator
        coord operator+(coord ob2);
        coord operator-(coord ob2);
        coord operator=(coord ob2);
};


// Overload '+' relative to coord class.
coord coord::operator+(coord ob2) {
    coord temp;
    std::cout << " Using coord operator +() \n";
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}

// Overload '-' relative to coord class.
coord coord::operator-(coord ob2) {
    coord temp;
    std::cout << " Using coord operator -() \n";
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    return temp;
}

// Overload '=' relative to coord class.
coord coord::operator=(coord ob2) {
    std::cout << " Using coord operator =() \n";
    x = ob2.x;
    y = ob2.y;
    return *this;
    // return the object that is assigned. Noticem, no "temp" is used
}

// "quad" class inheriting "coord"
class quad : public coord {
        int quadrant;
    public:
        quad() {
            x = 0;
            y = 0;
            quadrant = 0;
        }
        quad(int x, int y) : coord (x, y) {
            if(x >=0 && y >= 0) 
                quadrant = 1;
            else if(x <0 && y >=0) 
                quadrant = 2;
            else if(x <0 && y <0) 
                quadrant = 3;
            else 
                quadrant = 4;
        }
        void showq() {
            std::cout << " Point in Quadrant : " << quadrant << '\n';
        }
        // quad's own overladed '=' operator
        quad operator=( coord ob2 );
};


// Overload '=' relative to 'quad' class again
quad quad :: operator=( coord ob2 ) {
    std::cout << " Using quad operator =() \n";

    x = ob2.x;
    y = ob2.y;

    if(x >=0 && y >= 0)
        quadrant = 1;
    else if(x <0 && y >=0)
        quadrant = 2;
    else if(x <0 && y <0)
        quadrant = 3;
    else
        quadrant = 4;

    return * this;
}


int main() {
    quad o1(10, 10), o2(15, 3), o3;
    int x, y;

    o3 = o1 + o2; // add two objects - this calls operator +()
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 - o2; // subtract two objects
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1; // assign an object
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}











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






