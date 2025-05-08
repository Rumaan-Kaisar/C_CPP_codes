
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




// --------rev[06-May-2025]--------

/* Example 6: Here is an example demonstrating the case where only the base class takes arguments, 
                and the derived class does not need any additional arguments: 

                Base class constructor takes an integer argument int x.
                Derived class constructor does not require any arguments, 
                    just pass an argument (10) to the base class constructor.

Notice we left arhument empty "Derived() : Base(10)" in case we're just passing a constant (fixed default value).
bot to pass a varible we must argument in Derived: "Derived(int m) : Base(m)"


You can leave the Derived() constructor's argument list empty, and directly pass the constant in the initializer list:
*/


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





/* 
Example 7: If Only the Base Class Takes Arguments:
        The derived class must still pass those arguments to the base class constructor, 
        since the base class constructor needs them for proper initialization.

        The derived class can either:
            Accept the necessary arguments itself and forward them to the base class.
                uses above cases syntax

            Or hard-code the values when calling the base class constructor. Using following syntax:

                derived_constructor() : base(arg_list) {
                    // body of derived constructor
                }

    


Summary:
Case 1 demonstrates the derived class accepting arguments and forwarding them to the base class constructor.

Case 2 demonstrates the derived class hard-coding values when calling the base class constructor.

 */
/* Case 1: Derived Class Accepts the Necessary Arguments and Forwards Them to the Base Class
In this case, the derived class accepts arguments and then forwards them to the base class constructor. 
Explanation:
The Derived class constructor takes two arguments a and b.

It forwards these arguments to the Base class constructor using the initializer list: Base(a, b).

When the Derived class object is created, it calls both the Base class constructor and the Derived class constructor with the given arguments.

Output:
pgsql
Copy
Edit
Base class constructor called with values: 10 and 20
Derived class constructor called with values: 10 and 20
*/

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




/* Case 2: Derived Class Hard-Codes the Values When Calling the Base Class Constructor
In this case, the derived class hard-codes the values when calling the base class constructor. 
Explanation:
The Derived class constructor does not take any arguments.

Instead, it hard-codes the values 100 and 200 when calling the Base class constructor via the initializer list: Base(100, 200).

When the Derived class object is created, it calls the Base class constructor with the hard-coded values.

Output:
Base class constructor called with values: 100 and 200
Derived class constructor called with hard-coded values.
*/


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





