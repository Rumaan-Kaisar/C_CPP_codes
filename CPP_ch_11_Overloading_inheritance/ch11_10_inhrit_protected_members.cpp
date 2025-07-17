
/*  ------------------------    inheritance and "protected"    ------------------------

    Protected:
        Sometimes we want to keep a member of a BASE class "private" but still allow a DERIVED class access to it.
        To do this, use the "protected" access specifier.


    Accessing PROTECTED members:
        Protected members of a base class can be accessed by any class derived from that base.
        Outside the base or derived classes, protected members are not accessible.
        The protected access specifier can occur anywhere in the class declaration
        They're usually placed after private (default) members and before public ones in a class.


    General form of a CLASS declaration with all ACCESS specifiers:

                class ClassName {  
                        // private members (default)

                    protected:  
                        // protected members (optional)

                    public:  
                        // public members
                };


        A "protected member" in a BASE class:
            Becomes protected in the derived class if "inherited as public".
            Becomes private in the derived class if "inherited as private".

        If a base class is "inherited as protected":
            Its public and protected members become protected in the derived class.

        Private members of the base class always stay private and are not accessible in the derived class.

        protected can also be used in "structs".

*/  




/* Example1: This program illustrates how public, private, and protected members of a class can be accessed 
                It also shows: what occurs when protected members are inherited as public: 

                Because a and b are PROTECTED in base and inherited as PUBLIC by derived, 
                they are available for use by member functions of derived as we used to showabc().

                However, outside of these two classes, a and b are effectively private and inaccessible.
*/

#include <iostream>

class base { 
        int t;      //  private member
    protected:
        int a, b;   //  private but accessible by derived *
    public:
        int s;
        void setab(int n, int m){ a=n; b=m; }
};


//  new class 
class derived : public base {   
        int c;  //  private in deived 
    public:
        void setc(int n){c = n;}
        // this has access to a and b from base 
        void showbc(){ std::cout<< a <<' '<< b <<' '<< c; }
};


int main(){ 
    base ob_bs; //  base type object 
    derived ob_drv; //  derived type object 

    // ob_bs.t=5;  //  error: t is private member of base
    // ob_bs.a=3;  //  error: 
    // ob_bs.b=4;  //  error: a,b is protected member of base but accessible inside derived
    ob_bs.s=9;   //  ok: s is public member of base

    ob_bs.setab (3, 4);     // ok: setab() is public member of base
    ob_drv.setab(1, 2);     // ok: setab() is also public to derived because it derived publicly
    ob_drv.setc(3);         // ok: c is public member of derived

    // ob_drv.a=3; //  error:
    // ob_drv.b=4; //  error: a,b is protected member of base but accessible inside derived
    ob_drv.showbc(); 	//  accessing a,b inside of derived class
    
    return 0;
}  



// following is more simplified version of previous program
// The commented line in main() is invalid because b is protected, so it's still hidden from outside the class.
# include <iostream>

class samp{
        // private by default
        int a;
    protected:
        // still private relative to samp
        int b;
    public:
        int c;
        samp(int n, int m){ a = n; b = m; }
        int geta(){ return a; }
        int getb(){ return b; }
};


int main(){
    samp ob(10 , 10);

    // ob.b = 99; Error ! b is protected and thus private
    ob.c = 30; // OK , c is public
    std::cout << ob.geta() << ' ';
    std::cout << ob.getb() << ' ' << ob.c << '\n';
    
    return 0;
}




/* Example 2: The following program illustrates what occurs when protected members are inherited as public.

                Because a and b are protected in base and inherited as public by derived, 
                    they are available for use by member functions of derived. 

                However, outside of these two classes, a and b are effectively private and inaccessible.
*/

#include <iostream>

class base{
    // private by default
    protected: 
        int a, b; // private to base, but still accessible by derived
    public:
        void setab(int n, int m){ a = n; b = m; }
};


class derived : public base{
        int c;
    public:
        void setc(int n){ c = n; }
        // this function has access to a and b from base
        void showabc(){ std::cout << a << ' ' << b << ' ' << c << '\n'; }
};


int main(){
    derived ob;

    // a and b are not accessible here because they are private to both "base" and "derived".
    ob.setab(1, 2);
    ob.setc(3);
    ob.showabc();

    return 0;
}




/* Example 3: When a base class is "inherited as protected", PUBLIC and PROTECTED members of the base class 
                become "protected" members of the DERIVED class. 

                For example following statement returns error because of inheriting base as protected instead of public 
                in the class declaration of derived in the preceding program


                        class derived : protected base {
                            //  same as before
                        }

                        int main(){ 
                            derived ob_drv;         // derived type object 
                            ob_drv.setab(1, 2);     // ERROR : setab() is now a protected member of base. setab() is not accessible here . 
                            // ...
                        }

                Because BASE is inherited as "protected", its "public" and "protected" elements become protected members of 
                DERIVED and are therefore inaccessible within main().
*/

// This program will not compile. To compile it- inherit "base" publicly
#include <iostream>

class base{
    // private by default
    protected: 
        int a, b; // private to base, but still accessible by derived
    public:
        void setab(int n, int m){ a = n; b = m; }
};

// inherit as protected
class derived : protected base{
        int c;
    public:
        void setc(int n){ c = n; }
        // this function has access to a and b from base
        void showabc(){ std::cout << a << ' ' << b << ' ' << c << '\n'; }
};


int main(){
    derived ob;
    
    // ERROR : setab() is now a protected member of base.
    ob.setab(1, 2); // setab() is not accessible here.
    ob.setc(3);
    ob.showabc();

    return 0;
}




/* Example 4: What is the resulting access level of a "protected member" 
                when inherited as public, private, or protected?

            ans:
                When a protected member of a base class is inherited as public, 
                    it becomes a protected member of the derived class. 
                If it is inherited as private, it becomes a private member of the derived class. 
                If it is inherited as protected, it becomes a protected member of the derived class.


                Inheritance Mode        Protected Member in Derived Class
                ---------------------------------------------------------
                Public                  Protected
                Private                 Private
                Protected               Protected
*/




/* Example 5: Explain why the protected category is needed? 

            ans:
                The protected category is needed to allow a BASE class to keep certain members "private" 
                while still allowing a DERIVED class to have access to them.
*/




/* Example 6: In "Example 5 (skeleton-code)" from previous section (ch11_09_inhrit_BaseClass_access.cpp), 
                if the 'a' and 'b' inside 'myclass' were made into 'protected' instead of 'private' (by default) members,

                    Would any of that Example code would change? 
                    If so, how? 

                So which of the following statements are legal? (previously A and C weare valid for private 'a', 'b')

                Now say:
                class mybase{
                        // no private by default int a, b;
                    protected:
                        int a, b;
                    public:
                        int c;
                        void setab(int i, int j){ a = i; b = j; }
                        void getab(int &i, int &j){ i = a; j = b; }
                };

                    A. o1.getab(i, j);
                    B. o2.getab(i, j);
                    C. o1.c = 10;
                    D. o2.c = 10; 

            ans:
                A and C are valid in this case too. So no changes to the previous ans.
*/

#include <iostream>

class mybase{
        int a, b;
    public:
        int c;
        void setab(int i, int j){ a = i; b = j; }
        void getab(int &i, int &j){ i = a; j = b; }
};

class derived1 : public mybase{
    // ...
};

class derived2 : private mybase{
    // ...
};


int main(){
    derived1 o1;
    derived2 o2;
    int i, j;
    // ...
}




/* Example 7: When a "base" class is inherited as "public" by the derived class, 
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




/* Example 8: Explain what "protected" means.
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




/* Example 9: What is protected used for? 

            ans:
                The "protected" access specifier controls how "class members" are accessed:
                    Accessible within the same class.
                    Accessible in derived classes (via public or protected inheritance).
                    Not accessible from outside the class hierarchy.

                Why use 'protected'?
                    It lets derived classes access base class members "while keeping them hidden from external code" 
                    offering controlled inheritance and better encapsulation.


                In short:
                    'protected' = private to the world, but visible to derived classes.
                    protected = "Private, but shared with child classes."
*/




// ----------------    operator overloading and inheritance    ----------------

/* Example 10 (pre): from the preceding examples (in C++ operator overloading ch11_05_1 - ch11_05_4), 
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




/* Example 10: Following is a reworked version of the coord class from the previous 
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




/* Example 11: Convert the previous program so that it uses friend operator functions.


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
// ERR: Following will not compile (try FIXED version)
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

