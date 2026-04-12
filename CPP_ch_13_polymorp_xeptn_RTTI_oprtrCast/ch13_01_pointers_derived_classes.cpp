
/*  ------------------------    chapter    ------------------------

13.1 Pointers To Derived Classes
A pointer declared as a pointer to a base class can also be used to point to any class derived from that base. For example, assume two classes called base and derived, where derived inherits base. Then the following statements are correct:

base *p; 			/* base class pointer */ 

base base_ob ; 			/* object of type base */ 
derived derived_ob ; 		/* object of type derived */ 

p = &base_ob ; 		/* p points to base object : Normally p can.*/ 
p = &derived_ob ; 		/* p points to derived object : Advanced pointing by p */ 

	A base pointer can point to an object of any class derived from that base without generating a type mismatch error.
	By a base pointer we can access only those members of the derived object that were inherited from the base. Because the base pointer has knowledge only of the base class, nothing about the members added by the derived class.
	The reverse is not true: A pointer of the derived type cannot be used to access an object of the base class. (A type cast can be used to overcome this restriction, but its use is not recommended practice.)
	Note (Be careful): Pointer arithmetic is relative to the data type the pointer is declared as pointing to. Thus, if you point a base pointer to a derived object and then increment that pointer, it will not be pointing to the next derived object. It will be pointing to (what it thinks is) the next base object. Be careful about this.
	Example 1: Following illustrates how a base class pointer can be used to access a derived class:

class base{ 	int x;
	public: 	void setx(int i){ x=i; }
		int getx(){ return x; }	};

class derived : public base { int y;
	public : 	void sety(int i){ y=i; }
		int gety(){ return y; }	};

int main(){	base *p; 		/* pointer to base type */ 
		base b_ob ; 	/* object of base */ 
		derived d_ob ; 	/* object of derived */ 	
p = &b_ob ; 	          /* p access base  : point to base object */
p-> setx(10) ; 	          /* access base object */ 
cout << " Base object x: " << p-> getx () << '\n';

p = &d_ob ; 	          /* p access derived : point to derived object */ 
p-> setx(99) ; 	          /* access derived object */ 

d_ob.sety(88) ;	           /* can't use p to set y, so do it directly */
cout << " Derived object x: " << p-> getx() << '\n';
cout << " Derived object y: " << d_ob.gety() << '\n';
	return 0; }
	There is no value in using a base class pointer in the way shown in this example.


*/  
