
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


--------rev[29-Apr-2025]--------

-------------------------------------------







	Example 1 (Base-Derived Constructor-Destructor execution): 


class base {
public :
  base(){ cout<< "Constructing base \n"; }
  ~base(){ cout<< "Destructing base \n"; } 
};	class derived : public base{ // no-arguments allowed 
public :
   derived(){ cout<< "Constructing derived \n"; }
   ~derived(){ cout<< "Destructing derived \n"; }
};
		int main() { 	derived obj; 		// By declaring object Constructor-Destructor executes 
				return 0; }
This program displays the following output:	Constructing base 
Constructing derived 
Destructing derived  	// Reverse order
Destructing base  	// Reverse order

	As you can see :		the constructors are executed in order of derivation and 
	The destructors are executed in reverse order.



	Example 2 (Only pass argument to derived class constructor – Normal fashion): The BASE is SAME as Example 1
class derived : public base { int j;
			public :
		derived(int n) { cout<< "Constructing derived \n";
				    j = n; }
		~derived() { cout<< "Destructing derived \n"; }
		void showj() { cout << j << '\n'; } 	};	int main() { 	derived obj(10);
obj.showj();
return 0; }
	Notice that the argument is passed to the derived class's constructor in the normal fashion.




	Example 3 ( Base and derived uses same arguments ): 
class base { 
	int i;
public :
	base(int n) {	cout<< "Constructing base \n";
			i = n;}
	~base() { cout<< "Destructing base \n"; }
	void showi() { cout << i << '\n';}   };	class derived : public base {
	int j;
public :
derived(int n) : base(n) {  // pass arg to base 
		    cout<< "Constructing derived \n";
		    j = n;}
~derived() { cout<< "Destructing derived \n"; }
void showj() { cout << j << '\n'; }	};
int main() { 	derived obj(10) ; 	obj.showi(); 	   obj.showj(); 	return 0; }
	In the declaration of derived's constructor, the parameter n (which receives the initialization argument) is both used by derived() and passed to base().In this specific case, both use the same argument, and the derived class simply passes along the argument to the base.



	Example 4 ( Base and derived uses different arguments ):  Mostly the constructors for the base & derived won't use same argument. 
	When this is the case and you need to pass one or more arguments to each : 
	To the derived class's constructor, we must pass those arguments: which are needed by both derived and base.
	Then the derived class simply passes along to the base those arguments required by it. 
class derived : public base { int j;
   public :
derived(int n, int m) : base(m) {cout<< "Constructing derived \n"; j=n;}  // pass arg to base 
~derived() { cout<< "Destructing derived \n"; }
void showj() { cout<< j << '\n'; }  };
int main() { derived ob(10 , 20);    ob.showi ();    ob.showj ();     return 0; }



	Example 5 ( Base uses the arguments and derived just pass these to base without using  ):  
class base { int i;
public :
base(int n){ cout<< "Constructing base \n"; i=n;}
~base() { cout<< "Destructing base \n"; }
void showi() { cout<< i << '\n'; } 
};	class derived : public base { int j;
	public :
derived(int n) : base(n) 	   // pass arg to base 
 	{cout<< "Constructing derived \n"; j=0; }
~derived() { cout<< "Destructing derived \n"; }
void showj() { cout << j << '\n'; } 	};
	If the derived class does not need an argument, it ignores the argument and simply passes it along. For example, in this fragment, parameter n is not used by derived(). Instead, it is simply passed to base().






Example 6: Here is an example demonstrating the case where only the base class takes arguments, and the derived class does not need any additional arguments:

Example:
cpp
Copy
Edit
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
Explanation:
Base class constructor takes an integer argument int x.

Derived class constructor does not require any arguments, but it needs to pass an argument (10) to the base class constructor.

When you create an object of the Derived class, the Base class constructor is called first with the argument 10, followed by the body of the derived class constructor.





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

            Notice Example 7


Case 1: Derived Class Accepts the Necessary Arguments and Forwards Them to the Base Class
In this case, the derived class accepts arguments and then forwards them to the base class constructor.

cpp
Copy
Edit
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
Case 2: Derived Class Hard-Codes the Values When Calling the Base Class Constructor
In this case, the derived class hard-codes the values when calling the base class constructor.

cpp
Copy
Edit
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

Explanation:
The Derived class constructor does not take any arguments.

Instead, it hard-codes the values 100 and 200 when calling the Base class constructor via the initializer list: Base(100, 200).

When the Derived class object is created, it calls the Base class constructor with the hard-coded values.

Output:
pgsql
Copy
Edit
Base class constructor called with values: 100 and 200
Derived class constructor called with hard-coded values.
Summary:
Case 1 demonstrates the derived class accepting arguments and forwarding them to the base class constructor.

Case 2 demonstrates the derived class hard-coding values when calling the base class constructor.

