
/*  ------------------------    Multi inheritance    ------------------------

------------    rev[13-May-2025]    ------------

Multiple inheritance

There are two ways that a derived class can inherit more than one base class. 
	A derived class can be used as a base class for another derived class, creating a multilevel class hierarchy. In this case, 
	The original base class is said to be an indirect base class of the second derived class. 
	Note: Any class-no matter how it is created-can be used as a base class.
	When a base B1 is used for a derive D1 and this derived is used as a base for another derived D2. (i.e. "B1 inherited by D1" & "D1 inherited by D2").	 base_1 B1→derived_1 base_2  D1→derived_2  D2 .  The general case of 11.17 appears.
	Constructors called in the order of derivation. That is B1 first, D1 second and D2 third.   
	Destructors called in the reverse order of derivation. That is D2 first, D1 second and B1 third.   
	Argument passing:  When a derived class inherits a hierarchy of classes, each derived class in the chain must pass back to its preceding base any arguments it needs.
	A derived class can directly inherit more than one base class. In this situation, 
	Two or more base classes are combined to help create the derived class. 
	One derived with multiple base: When a derived class directly inherits multiple base classes, it uses this expanded form:


class derived_class_name : access base_1 , access base_2 , ... , access base_N { // body }
	Here base_1 through base_N are the base class names and 
	access is the access specifier (private/public/protected), which can be different for each base class.
	Execution of constructors & destructors: When multiple base classes are inherited, constructors are executed in the order, left to right, that the base classes are specified. Destructors are executed in the opposite order.
	Argument passing: The derived passes the necessary arguments to the multiple base  by using this expanded form of the derived class's constructor function:

derived_constructor(arg-list) : base_1(arg-list), base_2(arg-list),... , base_N(arg-list) { // body }
	Here base_1 through base_N are the base class names and 

    
    


Multilevel Inheritance
In multilevel inheritance, a derived class becomes a base for another derived class, creating a chain (hierarchy).

Example:
Base1 → Derived1 → Derived2

In this case:

Base1 is an indirect base for Derived2.

Any class can be used as a base class, no matter how it was created.

✅ Constructor & Destructor Call Order
Constructors are called in the order of inheritance, from base to derived:

Base1

Derived1

Derived2

Destructors are called in reverse order:

Derived2

Derived1

Base1

✅ Argument Passing
In a class chain, each derived class must pass required arguments to its immediate base class during construction.

Example:

cpp
Copy
Edit
Derived2(int x, int y, int z) : Derived1(x, y), ownValue(z) { }
✅ Multiple Inheritance
In multiple inheritance, a derived class inherits directly from two or more base classes.

Syntax:

cpp
Copy
Edit
class Derived : access Base1, access Base2, ..., access BaseN {
    // body
};
Each base can have its own access specifier: public, protected, or private.

✅ Constructor & Destructor Order
Constructors are called left to right in the order of base classes listed in the derived class declaration.

Destructors are called right to left, the reverse of constructors.

✅ Argument Passing in Multiple Inheritance
The derived class passes arguments to multiple base classes via an expanded constructor initializer list:

cpp
Copy
Edit
Derived(int a, int b) : Base1(a), Base2(b) {
    // derived constructor body
}
📌 Summary:
Type	Constructor Order	Destructor Order
Multilevel Inheritance	Base → Derived1 → Derived2	Derived2 → Derived1 → Base
Multiple Inheritance	Left to Right (Base1 → Base2)	Right to Left (Base2 → Base1)


    Example 1:  A derived class that inherits a class derived from another class.
class B1 { int a;
public :
B1(int x) { a = x; }
int geta() {return a;}
};	

// Inherit direct base class.
class D1 : public B1 { int b;
	public :
// Notice how pass y to B1
D1(int x, int y) : B1(y) {b = x;}
int getb() {return b;}
};


// Inherit a derived and an indirect base .
class D2 : public D1 { int c;
	public :
// Notice how pass args to D1
D2(int x, int y, int z) : D1(y, z){
				 c = x; }
void show(){	cout << geta() <<' ';
		cout << getb() <<' ';
		cout << c << '\n';} };
int main() { 	D2 ob_d2(1, 2, 3);
		ob_d2.show();
				// geta() and getb() are still public here, because both are public elements of B1 and D1 
		cout << ob_d2.geta() << ' ' << ob_d2.getb() << '\n';	return 0;}
	The call to ob_d2.show() displays 3 2 1. In this example, B1 is an indirect base class of D2.
	Notice that D2 has access to public elements/members of both B1 and D1, because all access specifire is public .
	Notice how arguments are passed along the chain from D2 to B1. Each class in a class hierarchy must pass all arguments required by each preceding base class.  D1(int x, int y) : B1(y)  and D2(int x, int y, int z) : D1(y, z) Otherwise  compile-time error occurs.
	How to draw C++-style inheritance graphs: Traditionally, C++ programmers usually draw inheritance charts as directed graphs in which the arrow points from the derived class to the base class.  For example the class hierarchy created in preceding program is :
D2
D1
B1





	Example 2: Here a derived class directly inherits two base classes. And illustrates how the destructor and constructors are called.
class B1 { 	int a; 	// first base class
	public : B1(int x) { a = x; }
		  int geta() { return a; } 
};	class B2 { 	int b; 	// second base class
	public : B2(int x) { b = x; }
		  int getb() { return b; }	
};
// Directly inherit two base classes 
class D : public B1, public B2{ int c;
	public :
// here z and y are passed directly to B1 and B2
D(int x, int y, int z) : B1(z), B2(y) {c=x;}
void show() {	cout<< geta() <<' '<< getb()<<' ';
		cout << c << '\n';}	};	int main(){	D ob_d(1, 2, 3);
		ob_d.show();
		return 0;	}


	The call to ob_d2.show() displays 3 2 1.
	Because bases inherited as public , D has access to public elements of both B1 and B2.
	The arguments to B1 and B2 are passed individually to these classes by D. This program creates a class that looks like this:


B1
D

	B2





	Example 3: The following program illustrates the order in which constructor and destructor functions are called when a derived directly inherits multiple base:
class B1 { 		
public : 
 B1(){cout< " Constructing B1\n";}
~B1(){cout<<" Destructing B1\n";}};	class B2 { 		
public : 
 B2(){cout< " Constructing B2\n";}
~B2(){cout<<" Destructing B2\n";}};	class D : public B1, public B2{
public :
D(){cout< " Constructing D\n";}
~D(){cout<<" Destructing D\n";}  };
		int main() { D ob_d; 	return 0; }

	This program displays :	Constructing B1
Constructing B2
Constructing D
Destructing D
Destructing B2
Destructing B1	when multiple direct base classes are inherited, constructors are called in order, left to right, as specified in the inheritance list. Destructors are called in reverse order.




*/  
