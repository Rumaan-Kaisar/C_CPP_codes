

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





// tested: basic of base
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




// tested
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




// tested
/* Example 3: Following is a reworked version of the coord class from the previous 
                operator overloading codes (eg: ch11_06_ovrldOpr_friend.cpp)

                This time it is used as a "base" for another class called "quad", 
                    which also maintains the quadrant the specific point is in. 

                So we Overload the +, -, and = relative to "coord" class.
                    Then use coord as a base for quad.
                    (recall Example 2 of ch11_05_2_ovrldOpr_binary.cpp)

                On your own, run this program and try to understand its output. 

            issue 1:
                in coord class, private coordinate variables x, y cause problems.
                If we can make them public, the program compiles properly.

                What happens if we make 'x' and 'y' public in 'coord'?
                    The program will compile and work fine as written.
                    Because then, both "coord's" member functions and "any derived class (like 'quad')" 
                    can directly access those members without restriction.


            Not a good idea though:
                We're avoiding "data encapsulation" — meaning internal data (like 'x' and 'y') 
                    should be "hidden (private or protected)"

                If you make them 'public':
                    You lose control over how those values are modified.
                    Any code outside the class can freely change 'x' and 'y', 
                    which can lead to bugs or inconsistent object states.


            Best Practice:

                If 'quad' needs to access them-
                    1. Make them 'protected' instead of 'public'.
                    2. Or, use getter and setter functions.
                Eg:
                    class coord {
                        protected:
                            int x, y;
                            ...
                    };

                This way, only derived classes can access them directly — external code cannot.


            issue 2:
                Operator = Should Return a Reference (in declaration inside the classes):
                By convention, operator= should return a reference to the current object (*this), not a copy.
                Correct declaration:
                        coord& operator=(coord ob2);
                        quad& operator=(coord ob2);
*/

#include <iostream>

class coord{
        int x, y; // coordinate values. Change these to "protected"
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

    x = ob2.x;  // change this as below
    y = ob2.y;  // change this as below

    // int xi, yi;
    
    // ob2.get_xy(xi, yi);  // safely get values
    // x = xi;
    // y = yi;

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


/*  ----------------    Notice    ----------------
    In our code get_xy(x, y) writes values into x and y in main via reference.
    No need to initialize x and y before calling get_xy()

    int x, y; // declared, but not initialized
    ...
    ...
    o3.get_xy(x, y); // passing them by reference


    Does get_xy() assign values to them?
    Yes.

    Because in coord class:

            void get_xy(int &i, int &j) { i = x; j = y; }

        i and j are references to x and y in main.
        i = x; assigns the value of coord's x to i (which is actually x in main).
        Similarly for j.

    So — even if x and y in main are uninitialized, 
        calling get_xy() will set them to the current object's x and y values.


--------------------------------
Your OUTPUT:
        Using coord operator +() 
        Using quad operator =() 
        Point in Quadrant : 1
        (o1+o2) X: 25, Y: 13
        Using coord operator -() 
        Using quad operator =() 
        Point in Quadrant : 2
        (o1 -o2) X: -5, Y: 7
        Using coord operator =() 
        Point in Quadrant : 1
        (o3=o1) X: 10, Y: 10
--------------------------------        
*/




// tested
/* Example 4: Convert the previous program so that it uses friend operator functions.



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


            Following is the same program converted to friend operator functions:
                Now the operators are declared as friends inside coord
                Defined outside the class body
                No need for 'this' or indirect access issues, 
                    since friend functions can directly access private members.

                Since a FRIEND function does not have a "this" pointer: 
                    For BINARY operators, a friend operator function is passed both operands explicitly
                    The assignment operator (=) cannot be overloaded using a friend function
*/
// Following will not compile
#include <iostream>

class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }

    // Friend operator functions
    friend coord operator+(coord ob1, coord ob2);
    friend coord operator-(coord ob1, coord ob2);
    friend coord operator=(coord &ob1, coord ob2);
};

// Friend Overload '+'
coord operator+(coord ob1, coord ob2) {
    coord temp;
    std::cout << " Using friend coord operator +() \n";
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
}

// Friend Overload '-'
coord operator-(coord ob1, coord ob2) {
    coord temp;
    std::cout << " Using friend coord operator -() \n";
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
    return temp;
}

// Friend Overload '='
coord operator=(coord &ob1, coord ob2) {
    std::cout << " Using friend coord operator =() \n";
    ob1.x = ob2.x;
    ob1.y = ob2.y;
    return ob1;
}

// 'quad' class inheriting 'coord'
class quad : public coord {
    int quadrant;
public:
    quad() {
        x = 0;
        y = 0;
        quadrant = 0;
    }
    quad(int x, int y) : coord(x, y) {
        if (x >= 0 && y >= 0)
            quadrant = 1;
        else if (x < 0 && y >= 0)
            quadrant = 2;
        else if (x < 0 && y < 0)
            quadrant = 3;
        else
            quadrant = 4;
    }
    void showq() {
        std::cout << " Point in Quadrant : " << quadrant << '\n';
    }
};

int main() {
    quad o1(10, 10), o2(15, 3), o3;
    int x, y;

    o3 = o1 + o2;
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 - o2;
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1-o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1;
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}


/* Note: 
        In abvoe code using '=' as friend is not the proper way.
        And raise error

    
    Can you declare?
                friend coord operator=(coord &ob1, coord ob2);
        in C++ Technically you can declare it — but it will not behave as a proper assignment operator should.
        Because, Assignment needs to modify the left-hand object (caller)

        In a normal assignment:
                a = b;
            the left-hand side 'a' is modified by copying data from 'b'.
            A member function "operator=()" has access to "this", so it knows which object to modify.

        A friend function version like:
                friend coord operator=(coord &ob1, coord ob2);

            Can technically modify 'ob1' since it's passed by reference.
            But it won't integrate cleanly with C++'s built-in assignment syntax expectations.

        Since, C++ requires 'operator=()' to be a non-static member function
            The compiler expects to call a "member function for assignment".
            It will not look for a friend non-member "operator=" during an assignment.


    The correct way is always:
            
            coord& operator=(const coord &ob2); // as a member function
*/

// ----------------------------------------------------------------
// FIXED code: 
// Notice, no 'protected' is used also in quad's '=' get_xy() used to get (x, y) values insted of direct access
#include <iostream>

class coord {
        int x, y;
    public:
        coord() { x = 0; y = 0; }
        coord(int i, int j) { x = i; y = j; }
        void get_xy(int &i, int &j) { i = x; j = y; }

        // Friend operator functions
        friend coord operator+(coord ob1, coord ob2);
        friend coord operator-(coord ob1, coord ob2);

        // '=' as member
        coord operator=(coord ob2);
};

// Friend Overload '+'
coord operator+(coord ob1, coord ob2) {
    coord temp;
    std::cout << " Using friend coord operator +() \n";
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
}

// Friend Overload '-'
coord operator-(coord ob1, coord ob2) {
    coord temp;
    std::cout << " Using friend coord operator -() \n";
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
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

// 'quad' class inheriting 'coord'
class quad : public coord {
        int quadrant;
    public:
        /*
        quad() {
            x = 0;
            y = 0;
            quadrant = 0;
        }

        is invalid because quad is trying to access the private members x and y 
            of its base class coord directly — which isn’t allowed in C++.
        */

        // Instead, you should call the "coord base class constructor" to initialize those members properly.
        quad() : coord() {
            quadrant = 0;
        }

        quad(int x, int y) : coord(x, y) {
            int xi, yi;
            get_xy(xi, yi);
            if (xi >= 0 && yi >= 0)
                quadrant = 1;
            else if (xi < 0 && yi >= 0)
                quadrant = 2;
            else if (xi < 0 && yi < 0)
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

    int xi, yi;
    
    /* 
    x and y are private to 'quad' and isn't allowed to write directly
    so following assignments are illigal 

    x = xi;
    y = yi;

    calling coord::operator=(ob2) is the cleanest, correct, and 
    necessary way to assign the base part.
    */

    coord::operator=(ob2);   // call base class assignment
    
    ob2.get_xy(xi, yi);  // safely get values

    if(xi >=0 && yi >= 0)
        quadrant = 1;
    else if(xi <0 && yi >=0)
        quadrant = 2;
    else if(xi <0 && yi <0)
        quadrant = 3;
    else
        quadrant = 4;

    return * this;
}


int main() {
    quad o1(10, 10), o2(15, 3), o3;
    int x, y;

    o3 = o1 + o2;   // add
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 - o2;   // subtract
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o1-o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1;    // assignment
    o3.get_xy(x, y);
    o3.showq();
    std::cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}



// ----------------------------------------------------------------
// refactored code-part for 'quad' class inheriting 'coord'
class quad : public coord {
        int quadrant;
    public:
        quad() : coord() {
            quadrant = 0;
        }

        quad(int x, int y) : coord(x, y) {
            set_quadrant();
        }

        void showq() {
            std::cout << " Point in Quadrant : " << quadrant << '\n';
        }

        // quad's own overloaded '=' operator
        quad operator=(coord ob2);

    private:
        void set_quadrant() {
            int xi, yi;
            get_xy(xi, yi);
            if (xi >= 0 && yi >= 0)
                quadrant = 1;
            else if (xi < 0 && yi >= 0)
                quadrant = 2;
            else if (xi < 0 && yi < 0)
                quadrant = 3;
            else
                quadrant = 4;
        }
};

// Overload '=' relative to 'quad' class
quad quad::operator=(coord ob2) {
    std::cout << " Using quad operator =() \n";

    coord::operator=(ob2);   // call base class assignment

    set_quadrant();          // update quadrant based on new x,y

    return *this;
}

// ----------------------------------------------------------------



// ----  rev[04-Jul-2025]  ----



// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-


/* Example 1: Create a class hierarchy that stores information about "airships". 

                Start with a general BASE class called "airship" that stores: 
                    the number of passengers and 
                    the amount of cargo (in pounds) that can be carried. 

                Then create two derived classes called "airplane" and "balloon" from "airship". 

                Have "airplane" store 
                    the type of engine used (propeller or jet) and 
                    range, in miles.

                Have "balloon" store information about 
                    the type of gas used to lift
                    the balloon (hydrogen or helium) and 
                    its maximum altitude (in feet). 

        Create a short program that demonstrates this class hierarchy.
*/

#include <iostream>

class airship {
    protected:
        int passengers;
        double cargo;
};

class airplane : public airship {
        char engine;    // p for propeller , j for jet
        double range;
    public:
        airplane(int p, double c, char e, double r) {
            passengers = p;
            cargo = c;
            engine = e;
            range = r;
        }
        void show();
};

class balloon : public airship {
        char gas;   // h for hydrogen , e for helium
        double altitude;
    public:
        balloon(int p, double c, char g, double a) {
            passengers = p;
            cargo = c;
            gas = g;
            altitude = a;
        }
        void show();
};


// rev 139843: 1,39,000

void airplane :: show() {
    std::cout << " Passengers : " << passengers << '\n';
    std::cout << " Cargo capacity : " << cargo << '\n';
    std::cout << " Engine : ";

    if( engine == 'p')
        std::cout << " Propeller \n";
    else
        std::cout << " Jet \n";

    std::cout << " Range : " << range << '\n';
}


void balloon :: show() {
    std::cout << " Passengers : " << passengers << '\n';
    std::cout << " Cargo capacity : " << cargo << '\n';
    std::cout << " Gas : ";

    if( gas == 'h')
        std::cout << " Hydrogen \n";
    else
        std::cout << " Helium \n";

    std::cout << " Altitude : " << altitude << '\n';
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



5. 

#include <iostream>

class base {
        int i, j;
    public:
        base(int x, int y) { i = x; j = y; }
        void showij() { std::cout << i << ' ' << j << '\n'; }
};

class derived : public base {
        int k;
    public:
        derived(int a, int b, int c) : base(b, c) { k = a; }
        void show() { std::cout << k << ' '; showij(); }
};

int main() {
    derived ob(1, 2, 3);
    ob. show();
    
    return 0;
}




/* Example 6: In general, when you define a class hierarchy, you begin with the most
class and move to the most class. (Fill in the missing words.) */


6. The missing words are "general" and "specific".






