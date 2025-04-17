
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


// ----  rev[15-Apr-2025]  ----




/* 	Example1: This program illustrates how public, private, and protected members of a class can be accessed 
It also shows: what occurs when protected members are inherited as public: 

	Because a and b are protected in base and inherited as public by derived, they are available for use by member functions of derived as we used to showabc(). 
	However, outside of these two classes, a and b are effectively private and inaccessible.
*/

class base { int t;  //  private member
protected : 
   int a, b;   //  private but accessible by derived *
public :
   int s;
   void setab(int n, int m) { a=n; b=m; }
};	class derived : public base { 	     //  new class 
			int c; 	//  private in deived 
	public :
		void setc(int n) {c = n;}
void showbc(){ 	   //  this has access to a and b from base 
		cout<< a <<' '<< b <<' '<< c; }
};
int main(){ base ob_bs; 		//  base type object 
	derived ob_drv; 		//  derived type object 
	ob_bs.t=5; 			//  error: t is private member of base
	ob_bs.a=3; ob_bs.b=4;   	//  error: a,b is protected member of base but accessible inside derived
	ob_bs.s=9 			// ok: s is public member of base
	ob_bs.setab (3, 4); 		// ok: setab() is public member of base
	ob_drv.setab(1, 2);   // ok: setab() is also public to derived because of public specifier in class declaration of derived 
	ob_drv.setc(3) ; 		// ok: c is public member of derived
	ob_drv.a=3; ob_drv.b=4;   	//  error: a,b is protected member of base but accessible inside derived
	ob_drv.showabc(); 	return 0;} 		//  accessing a,b inside of derived class










/* 	Example 2: When a base class is inherited as protected, public and protected members of the base class become protected members of the derived class. 
For example following statement returns error because of inheriting base as protected instead of public in the class declaration of derived in the preceding program,  */

class derived : protected base { . . . . . .  same . . .  . }
int main(){ derived ob_drv; 		// derived type object 
		ob_drv.setab (1, 2);  // ERROR : setab() is now a protected member of base.  setab() is not accessible here . 

Because base is inherited as protected, its public and protected elements become protected members of derived and are therefore inaccessible within main().



1. This program illustrates how public, private, and protected members of a class can be
accessed:
# include <iostream >
using namespace std ;
class samp
{
// private by default
int a;
protected : // still private relative to samp
int b;
public :
int c;
samp ( int n, int m) { a = n; b = m; }
int geta () { return a; }
int getb () { return b; }
};
int main ()
{
samp ob (10 , 10) ;
// ob.b = 99; Error ! b is protected and thus private
ob.c = 30; // OK , c is public
cout << ob. geta () << ’ ’;
cout << ob. getb () << ’ ’ << ob.c << ’\n’;
return 0;
}
As you can see, the commented-out line is not permissible in main() because b is protected
and is thus still private to samp.
2. The following program illustrates what occurs when protected members are inherited as
public:
# include <iostream >
using namespace std ;
181TEACH YOURSELF
C++
class base
{
protected : // private to base
int a, b; // but still accessible by derived
public :
void setab ( int n, int m) { a = n; b = m; }
};
class derived : public base
{
int c;
public :
void setc ( int n) { c = n; }
// this function has access to a and b from base
void showbc ()
{
cout << a << ’ ’ << b << ’ ’ << c << ’\n’;
}
};
int main ()
{
derived ob;
/*
a and b are not accessible here because they are
private to both base and derived .
*/
ob. setab (1, 2);
ob. setc (3) ;
ob. showbc ();
return 0;
}
Because a and b are protected in base and inherited as public by derived, they are
available for use by member functions of derived. However, outside of these two classes,
a and b are effectively private and inaccessible.
3. As mentioned earlier, when a base class is inherited as protected, public and protected
members of the base class become protected members of the derived class. For example,
here the preceding program is changed slightly, inheriting base as protected instead of
public:
// This program will not compile .
# include <iostream >
using namespace std ;
class base
{
182INHERITANCE
7.3. CONSTRUCTORS, DESTRUCTORS, AND INHERITANCE
protected : // private to base
int a, b; // but still accessible by derived
public :
void setab ( int n, int m) { a = n; b = m; }
};
class derived : protected base // inherit as protected
{
int c;
public :
void setc ( int n) { c = n; }
// this function has access to a and b from base
void showabc ()
{
cout << a << ’ ’ << b << ’ ’ << c << ’\n’;
}
};
int main ()
{
derived ob;
// ERROR : setab () is now a protected member of base .
ob. setab (1, 2); // setab () is not accessible here .
ob. setc (3) ;
ob. showabc ();
return 0;
}
As the comments now describe, because base is inherited as protected, its public and
protected elements become protected members of derived and are therefore inaccessible
within main().
EXERCISES
1. What happens when a protected member is inherited as public? What happens when it
is inherited as private? What happens when it is inherited as protected?
2. Explain why the protected category is needed?
3. In Exercise 1 from Section 7.1, if the a and b inside myclass were made into protected
instead of private (by default) members, would any of your answers to that exercise
change? If so, how?
