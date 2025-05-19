
/*  ------------------------    Multi inheritance    ------------------------
    There are two ways that a DERIVED class can inherit more than one BASE class.

        1. Multi-level inheritance
        2. Multiple inheritance


    Multi-level Inheritance
        Constructor Order:      Base > Derived1 > Derived2
        Destructor Order:       Derived2 > Derived1 > Base

    Multiple Inheritance
        Constructor Order:      Left to Right (Base1 > Base2)
        Destructor Order:       Right to Left (Base2 > Base1)




    --------  Multi-level Inheritance  --------

    A derived class can act as a base for another derived class, forming a chain.

            Base > Derived1 > Derived2

        Here, original "Base" becomes an "indirect base" of Derived2.
        Creating a multilevel class hierarchy.

    Constructor & Destructor Order:
        Constructors run in order of inheritance:       Base > Derived1 > Derived2.
        Destructors run in reverse order:     Derived2 > Derived1 > Base.

    Argument Passing:
        Each derived class must pass required arguments to its "immediate base class" during construction.

                    Derived2(int x, int y, int z) : Derived1(x, y), ownValue(z) { }




    --------  Multiple Inheritance  --------

    One derived with multiple base: 
        A derived class can inherit from "more than one base class" directly.
        In this case, a derived class is created by combining two or more base classes.
        When a derived class directly inherits multiple base classes, it uses this expanded form:

                    class Derived : access Base1, access Base2, ..., access BaseN {
                        // body
                    };

            Each base can have its own "access" specifier: public, protected, or private.

    Constructor & Destructor Order:
        Constructors run left to right, in the "order of base class listing".
        Destructors run right to left (reverse order).

    Argument Passing:
        The derived class passes necessary arguments to the multiple base  by using this expanded form:
        
                    Derived(args) : Base1(arg1), Base2(arg2), ..., BaseN(argN) {
                        // derived constructor body
                    }





// ----  rev[16-May-2025]  ----




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



/* Example 1 (Multi-level Inheritance):  
                A derived class that inherits a class derived from another class. 
                Notice how arguments are passed along the chain from D2 to B1.

The call to ob.show() displays 3 2 1. Here, B1 is an indirect base of D2. Public members stay public when inherited publicly, so D2 can access members of both D1 and B1. Each class must pass the required arguments to its base classes, or a compile-time error occurs. Inheritance diagrams in C++ traditionally point arrows from derived classes to base classes, though it might feel unintuitive at first.
*/




// 
# include <iostream >
using namespace std ;
class B1
{
int a;
public :
B1( int x) { a = x; }
int geta () { return a; }
};
// Inherit direct base class .
class D1 : public B1
{
int b;
public :
D1( int x, int y) : B1(y) // pass y to B1
{
b = x;
}
int getb () { return b; }
};
// Inherit a derived class and an indirect base .
class D2 : public D1
{
int c;
public :
D2( int x, int y, int z) : D1(y, z) // pass args to D1
{
c = x;
}
/*
Because bases inherited as public , D2 has access
to public elements of both B1 and D1.
*/
void show ()
{
191TEACH YOURSELF
C++
cout << geta () << ’ ’ << getb () << ’ ’;
cout << c << ’\n’;
}
};
int main ()
{
D2 ob (1, 2, 3);
ob. show ();
// geta () and getb () are still public here
cout << ob. geta () << ’ ’ << ob. getb () << ’\n’;
return 0;
}


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

