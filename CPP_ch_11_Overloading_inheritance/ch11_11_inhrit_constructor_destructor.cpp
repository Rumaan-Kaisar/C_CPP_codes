
/*  ------------------------    Inherit constructors, destructors    ------------------------
    
    Constructors, Destructors, and INHERITANCE
        The BASE class, the DERIVED class, or both may have constructor and/or destructor functions.
 
    When both BASE and DERIVED classes have their own constructors and destructors:

Constructor (Base-class first): 
    The constructor functions are executed in order of derivation. That is, the base class constructor is executed before the constructor in the derived class. Because a base class has no knowledge of any derived class, any initialization it performs is separate from.

Destructor (Derived-class first): 
    The destructor functions are executed in reverse order.  That is, the derived class's destructor is executed before the base class's destructor because the base class underlies the derived class. If the base class's destructor were executed first, it would imply the destruction of the derived class. 



	Passing arguments: It is possible to passed arguments to either a derived or base class constructor. There are two cases: 
	Only derived class takes arguments: When only the derived class takes an initialization, arguments are passed to the derived class's constructor in the normal fashion (as we did before).
	Base class takes arguments along with derived class: to pass an argument to the constructor of the base class, a chain of argument passing is established. 
	First, all necessary arguments to both the base class and the derived class are passed to the derived class's constructor. 
	Then using an expanded form of the derived class's constructor declaration, pass the appropriate arguments along to the base class. 
	The syntax for passing along an argument from the derived class to the base class is:
derived_constructor( arg_list ): base( arg_list ){
`				/* body of derived class constructor */ 
}
	Here base is the name of the base class. 
	Both the derived class and the base class can use the same argument (example 3).
	It is also possible for the derived class to ignore all arguments and just pass them along to the base (example 5).
	Example 1 (Base-Derived Constructor-Destructor execution): 

class base {
public :
  base(){ cout<< "Constructing base \n"; }
  ~base(){ cout<< "Destructing base \n"; } 
};	class derived : public base{ /* no-arguments allowed */
public :
   derived(){ cout<< "Constructing derived \n"; }
   ~derived(){ cout<< "Destructing derived \n"; }
};
		int main() { 	derived obj; 		/* By declaring object Constructor-Destructor executes */
				return 0; }
This program displays the following output:	Constructing base 
Constructing derived 
Destructing derived  	/* Reverse order*/
Destructing base  	/* Reverse order*/

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
derived(int n) : base(n) {  /* pass arg to base */
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
derived(int n, int m) : base(m) {cout<< "Constructing derived \n"; j=n;}  /* pass arg to base */ 
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
derived(int n) : base(n) 	   /* pass arg to base */ 
 	{cout<< "Constructing derived \n"; j=0; }
~derived() { cout<< "Destructing derived \n"; }
void showj() { cout << j << '\n'; } 	};
	If the derived class does not need an argument, it ignores the argument and simply passes it along. For example, in this fragment, parameter n is not used by derived(). Instead, it is simply passed to base().


*/  
