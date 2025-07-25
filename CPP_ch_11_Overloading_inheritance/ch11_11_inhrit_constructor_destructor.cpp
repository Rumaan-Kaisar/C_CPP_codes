
/*  ------------------------    Inherit constructors, destructors    ------------------------
    
    Constructors, Destructors, and INHERITANCE
        The BASE class, the DERIVED class, or both may have constructor and/or destructor functions.
 
    
    --------  When both BASE and DERIVED classes have their own constructors and destructors  --------

    Constructor (Base-class first): 
        Constructors run in "order of inheritance": base class constructor runs first, then derived class.
        Because a base class has no knowledge of any derived class, so it handles its own initialization separately

    Destructor (Derived-class first): 
        Destructors run in "reverse order": DERIVED class's destructor is executed before the BASE class's destructor
        Because the DERIVED depends on the BASE, destroying the base first would break the derived.
    


    --------    parameterized constructors    --------
    Parameterized constructors discussed in ch10_01_3_constructor_param.cpp

    It is possible to pass arguments to either a derived or base class constructor. There are three cases: 

    Only derived class takes arguments: 
        When only the derived class takes an initialization.
        Arguments are passed directly to the derived class constructor in the usual way.


    Both base and derived classes take arguments:
        A chain of argument passing is needed.
        All arguments are "first" passed to the DERIVED class constructor.
        The derived class then forwards the relevant arguments to the base class using an expanded constructor initializer list.

        The syntax for passing along an argument from the derived class to the base class is:

                derived_constructor(arg_list) : base(arg_list) {
                    // body of derived constructor
                }

        Example: 
                class Base {
                        int x;
                    public:
                        Base(int a) { x = a; }
                };

                class Derived : public Base {
                    public:
                        // Pass value to base class constructor using initializer list
                        Derived(int a) : Base(a) {
                            // body of derived class constructor (if needed)
                        }
                };

        Both the derived class and the base class can use the same argument (Example 3).
        It is also possible for the derived class to ignore all arguments and just pass them along to the base (Example 5).
        It's also true for following case.


    If Only the Base Class Takes Arguments:
        The derived class must still pass those arguments to the base class constructor, 
        since the base class constructor needs them for proper initialization.

        The derived class can either:
            Accept the necessary arguments itself and forward them to the base class.
                uses above cases syntax

            Or hard-code the values when calling the base class constructor. Using following syntax:

                derived_constructor() : base(arg_list) {
                    // body of derived constructor
                }

            Notice "Example 7"

*/  




/* Example 1: (Base-Derived Constructor-Destructor execution):  
                Notice the CONSTRUCTORS are executed in "order of derivation" and 
                The DESTRUCTORS are executed in "reverse order".

                The output will be:	
                                    Constructing base 
                                    Constructing derived 
                                    Destructing derived     // Reverse order
                                    Destructing base        // Reverse order
*/

#include <iostream>

class base{
    public:
        base(){ std::cout << " Constructing base class \n"; }
        ~base(){ std::cout << " Destructing base class \n"; }
};

// cannot pass constructor arguments to the base class in following line. 
// Only the inheritance type (public, protected, or private) is specified here.
// arguments passed in derive's constructor declaration
class derived : public base{    // no-arguments allowed in this line
    public:
        derived(){ std::cout << " Constructing derived class \n"; }
        ~derived(){ std::cout << " Destructing derived class \n"; }
};

int main(){
    derived ob; // By declaring object, Constructor-Destructor executes 
    return 0;
}




/* Example 2: (Only pass argument to derive's  constructor – Normal fashion): The BASE is SAME as Example 1
                This program shows how to pass an argument to a derived class's constructor:
                Notice that the argument is passed to the derived class's constructor in the normal fashion
*/

#include <iostream>

class base{
    public:
        base(){ std::cout << " Constructing base class \n"; }
        ~base(){ std::cout << " Destructing base class \n"; }
};

class derived : public base{
        int j;
    public:
        derived(int n){     // pass argument to derive's  constructor – Normal fashion
            std::cout << " Constructing derived class \n";
            j = n;
        } 
        ~derived(){ std::cout << " Destructing derived class \n"; }
        void showj(){ std::cout << j << '\n'; }
};


int main(){
    derived o(10);
    o.showj();

    return 0;
}




/* Example 3: (Base and derived uses same arguments)
                Notice, both the derived class and the base class constructors take arguments. 
                    In this specific case, both use the "same argument", the parameter n 
                    and the derived class simply passes along the argument to the base


                Note that:
                    n is the same variable name in 'base' and 'derived'
                    even though same value passed, they have same name — but different variables.

                    Inside base's constructor, the parameter n is local to base.
                    Inside derived's constructor, the parameter n is local to derived.


                What's happenning is-
                    Even though they both receive the same value (10 in this case), 
                        they are separate local parameters in their respective constructors.
                        i.e. two different variables, holding the same value temporarily passed at construction time.

                    Only the data members i in base and j in derived remain in the object after construction.
                    The n parameters themselves are temporary variables local to the constructors and 
                        cease to exist once their respective constructors complete.
*/

#include <iostream>

class base{
        int i;
    public:
        base(int n){
            std::cout << " Constructing base class \n";
            i = n;
        } 
        ~base(){ std::cout << " Destructing base class \n"; }
        void showi(){ std::cout << i << '\n';}
};

class derived : public base{
        int j;
    public:
        derived(int n) : base(n){  // pass arg to base class.
            std::cout << " Constructing derived class \n";
            j = n;
        }
        ~derived(){ std::cout << " Destructing derived class \n";}
        void showj(){ std::cout << j << '\n'; }
};


int main(){
    derived o(10);
    
    o.showi();
    o.showj();
    
    return 0;
}




/* Example 4: (Base and derived uses different arguments)

                Mostly, the constructors for the base and derived classes won't use the same arguments.
                When this is the case and you need to pass one or more arguments to each:

                Pass all required arguments to the derived class’s constructor- 
                    both those needed by the "derived class" itself and those meant for the "base class"

                Then the derived class simply passes along to the base those arguments required by it.

*/

#include <iostream>

class base{
        int i;
    public:
        base(int n){
            std::cout << " Constructing base class \n";
            i = n;
        } 
        ~base(){ std::cout << " Destructing base class \n"; }
        void showi(){ std::cout << i << '\n';}
};


class derived : public base{
        int j;
    public:
        derived(int n, int m) : base(m){  // pass arg to base class.
            std::cout << " Constructing derived class \n";
            j = n;
        }
        ~derived(){ std::cout << " Destructing derived class \n";}
        void showj(){ std::cout << j << '\n'; }
};


int main(){
    derived o(10, 20);

    o.showi();
    o.showj();

    return 0;
}




/* Example 5: (Base uses the arguments and derived just pass these to base without using):   
                If the derived class does not need an argument, it ignores the argument and simply passes it along.
                
                For example, in this fragment, parameter n is not used by derived(). Instead, it is simply passed to base().
*/
#include <iostream>

class base{
        int i;
    public:
        base(int n){
            std::cout << " Constructing base class \n";
            i = n;
        } 
        ~base(){ std::cout << " Destructing base class \n"; }
        void showi(){ std::cout << i << '\n';}
};


class derived : public base{
        int j;
    public:
        derived(int n) : base(n){  // pass arg to base class.
            std::cout << " Constructing derived class \n";
            j = 0;  // no use of n
        }
        ~derived(){ std::cout << " Destructing derived class \n";}
        void showj(){ std::cout << j << '\n'; }
};


int main(){
    derived o(10);
    
    o.showi();
    o.showj();
    
    return 0;
}




/* Example 6: Here is an example demonstrating the case where only the base class takes arguments, 
                and the derived class does not need any additional arguments: 

                Base class constructor takes an integer argument int x.
                Derived class constructor does not require any arguments, 
                    just pass an argument (10) to the base class constructor.


                Case 1: You can leave the Derived() constructor's argument list empty, 
                    and directly pass the constant in the "initializer list":
                    No need for a parameter in Derived() because there's nothing dynamic to receive

                                Derived() : Base(10) {
                                    // Derived constructor body
                                }

                Case 2: You must declare a parameter in the Derived constructor, 
                    because now it needs to accept a value at runtime to pass along to Base

                                Derived(int m) : Base(m) {
                                    // Derived constructor body
                                }

*/
// case 1:

#include <iostream>

class Base {
public:
    Base(int x) {
        std::cout << "Base class constructor called with value: " << x << std::endl;
    }
};

class Derived : public Base {
public:
    Derived() : Base(10) {  // Passing argument to the base class constructor
        std::cout << "Derived class constructor called." << std::endl;
    }
};

int main() {
    Derived obj;  // Creating an object of the derived class
    return 0;
}



// case 2 (similar to Example 5):
#include <iostream>

class Base {
    int x;
public:
    Base(int n) {
        x = n;
        std::cout << "Base class constructor called with value: " << x << std::endl;
    }
    void show() {
        std::cout << "Value in Base: " << x << std::endl;
    }
};

class Derived : public Base {
    int y;
public:
    Derived(int m) : Base(m) {  // Passing variable 'm' to Base constructor
        y = m;
        std::cout << "Derived class constructor called with value: " << y << std::endl;
    }

    void showDerived() {
        std::cout << "Value in Derived: " << y << std::endl;
    }
};

int main() {
    int value = 25;
    Derived obj(value);   // Passing variable to derived class constructor

    obj.show();
    obj.showDerived();

    return 0;
}



// Keeping both (OVERLOAD): both options — a Derived(int m) constructor and a Derived() with a default value
class Derived : public Base {
    public:
        Derived() : Base(10) {  // default value passed to Base
            std::cout << "Derived() called\n";
        }

        Derived(int m) : Base(m) {  // pass variable to Base
            std::cout << "Derived(int) called with " << m << '\n';
        }
};




/* Example 7: If Only the Base Class Takes Arguments:
                The derived class must still pass those arguments to the base class constructor, 
                since the base class constructor needs them for proper initialization.

                Case 1:
                    Derived Class Accepts the Necessary Arguments and Forwards Them to the Base Class
                    In this case, the derived class accepts arguments and then forwards them to the base class constructor. 

                Case 2:
                    The Derived class constructor does not take any arguments.
                    Instead, derived Class Hard-Codes the Values When Calling the Base Class Constructor (not dynamic)
*/

// Case 1: 
#include <iostream>

class Base {
    public:
        Base(int x, int y) {
            std::cout << "Base class constructor called with values: " << x << " and " << y << std::endl;
        }
};

class Derived : public Base {
    public:
        Derived(int a, int b) : Base(a, b) {  // Forwarding arguments to the Base class constructor
            std::cout << "Derived class constructor called with values: " << a << " and " << b << std::endl;
        }
};

int main() {
    Derived obj(10, 20);  // Creating an object of the Derived class
    return 0;
}



// Case 2: 
#include <iostream>

class Base {
    public:
        Base(int x, int y) {
            std::cout << "Base class constructor called with values: " << x << " and " << y << std::endl;
        }
};

class Derived : public Base {
    public:
        Derived() : Base(100, 200) {  // Hard-coding values when calling Base class constructor
            std::cout << "Derived class constructor called with hard-coded values." << std::endl;
        }
};

int main() {
    Derived obj;  // Creating an object of the Derived class
    return 0;
}




/* Example 8: Given the following skeleton, fill in the "constructor" function for myderived. 
                Have it pass along a pointer to an "initialization string" to mybase. 
                Also, have myderived() initialize len to the length of the string. 

                    #include <iostream>
                    #include <cstring>

                    class mybase{
                            char str[80];
                        public:
                            mybase(char *s){ strcpy(str, s); }
                            char *get() { return str; }
                    };

                    class myderived : public mybase{
                            int len;
                        public:
                            // add myderived() here

                            int getlen(){ return len; }
                            void show(){ std::cout << get() << '\n'; }
                    };


                    int main(){
                        myderived ob(" hello ");

                        ob.show();
                        std::cout << ob.getlen() << '\n';

                        return 0;
                    }
*/

#include <iostream>
#include <cstring>

class mybase{
        char str[80];
    public:
        mybase(char *s){ strcpy(str, s); }
        char *get() { return str; }
};

class myderived : public mybase{
        int len;
    public:
        myderived(char *s) : mybase(s){     // add myderived()
            len = strlen(s);
        }
        int getlen(){ return len; }
        void show(){ std::cout << get() << '\n'; }
};


int main(){
    myderived ob(" hello ");

    ob.show();
    std::cout << ob.getlen() << '\n';

    return 0;
}




/* Example 9: Using the following skeleton, create appropriate car() and truck() constructor functions.
                Have each pass along appropriate arguments to vehicle. 
                In addition, have car() initialize passengers as specified when object is created. 
                Have truck() initialize loadlimit as specified when an object is created. 


                    #include <iostream>

                    // A base class for various types of vehicle .
                    class vehicle{
                            int num_wheels;
                            int range;
                        public:
                            vehicle(int w, int r){
                                num_wheels = w;
                                range = r;
                            }
                            void showv(){
                                std::cout << "Wheels : " << num_wheels << '\n';
                                std::cout << "Range : " << range << '\n';
                            }
                    };


                    class car : public vehicle{
                            int passengers;
                        public:
                            // insert car () constructor here
                            void show(){
                                showv();
                                std::cout << "Passengers : " << passengers << '\n';
                            }
                    };


                    class truck : public vehicle{
                            int loadlimit;
                        public:
                            // insert truck () constructor here
                            void show(){
                                showv();
                                std::cout << "Loadlimit : " << loadlimit << '\n';
                            }
                    };


                    int main(){
                        car c(5,4,500) ;
                        truck t(3000,12,1200) ;

                        std::cout << " Car : \n";
                        c.show();

                        std::cout << "\n Truck :\n";
                        t.show();

                        return 0;
                    }



                Have car() and truck() declare objects like this:
                    car ob(passengers , wheels , range);
                    truck ob(loadlimit , wheels , range);
*/

#include <iostream>

// A base class for various types of vehicle .
class vehicle{
        int num_wheels;
        int range;
    public:
        vehicle(int w, int r){
            num_wheels = w;
            range = r;
        }
        void showv(){
            std::cout << "Wheels : " << num_wheels << '\n';
            std::cout << "Range : " << range << '\n';
        }
};


class car : public vehicle{
        int passengers;
    public:
        car(int p, int w, int r) : vehicle(w, r){ passengers = p; }     // car() constructor
        void show(){
            showv();
            std::cout << "Passengers : " << passengers << '\n';
        }
};


class truck : public vehicle{
        int loadlimit;
    public:
        truck(int lod, int w, int r) : vehicle(w, r){ loadlimit = lod; }     // truck() constructor here
        void show(){
            showv();
            std::cout << "Loadlimit : " << loadlimit << '\n';
        }
};


int main(){
    car c(5,4,500) ;
    truck t(3000,12,1200) ;

    std::cout << " Car : \n";
    c.show();

    std::cout << "\nTruck :\n";
    t.show();

    return 0;
}




/* Example 10: When one class inherits another, when are the classe's constructors called? 
                When are their destructors called? 
            ans:
                Constructors are called in "order of derivation". 
                Destructors are called in "reverse order".
*/

