
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

    It is possible to pass arguments to either a derived or base class constructor. 
    There are three cases: 

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

            Both the derived class and the base class can use the same argument (Example 3).
            It is also possible for the derived class to ignore all arguments and just pass them along to the base (Example 5).
            It's also true for following case




    


--------rev[28-Apr-2025]--------

-------------------------------------------

If Only the Base Class Takes Arguments:
    The derived class must still pass those arguments to the base class constructor, 
    since the base class constructor needs them for proper initialization.

The derived class can either:

Accept the necessary arguments itself and forward them to the base class.

Or hard-code the values when calling the base class constructor.



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



Key Point:
If a base class has no default constructor (a constructor with no parameters), the derived class must explicitly call one of the base class’s constructors through its own initializer list.






--------rev[25-apr-2025]--------


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


*/  
