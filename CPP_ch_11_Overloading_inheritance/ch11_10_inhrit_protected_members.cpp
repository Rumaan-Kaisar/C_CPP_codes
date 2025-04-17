
/*  ------------------------    inheritance and "protected"    ------------------------

    Protected:
        Sometimes we want to keep a member of a BASE class "private" but still allow a DERIVED class access to it.
        To do this, use the "protected" access specifier.


    Accessing PROTECTED members:
        Protected members of a base class can be accessed by any class derived from that base.
        Outside the base or derived classes, protected members are not accessible.
        The protected access specifier can occur anywhere in the class declaration
        They're usually placed after private (default) members and before public ones in a class.


// ----  rev[15-Apr-2025]  ----

General form of a class declaration:




class class_name { 		//  private members *
protected: 	//  protected members (optional)*
public: 	//  public members *
};
	When a protected member of a base class is inherited: 
	as public by the derived class, it becomes a protected member of the derived class. 
	as private by the derived class, it becomes a private member of the derived class.
	When a base inherited as protected: public and protected members of the base class become protected members of the derived class. (Of course, private members of the base class remain private to it and not acessable.)
	The protected access specifier can also be used with structures.
	Example1: This program illustrates how public, private, and protected members of a class can be accessed also what occurs when protected members are inherited as public:
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
	Because a and b are protected in base and inherited as public by derived, they are available for use by member functions of derived as we used to showabc(). 
	However, outside of these two classes, a and b are effectively private and inaccessible.

	Example 2: When a base class is inherited as protected, public and protected members of the base class become protected members of the derived class. For example following statement returns error because of inheriting base as protected instead of public in the class declaration of derived in the preceding program, 

class derived : protected base { . . . . . .  same . . .  . }
int main(){ derived ob_drv; 		// derived type object 
		ob_drv.setab (1, 2);  // ERROR : setab() is now a protected member of base.  setab() is not accessible here . 

Because base is inherited as protected, its public and protected elements become protected members of derived and are therefore inaccessible within main().


*/  
