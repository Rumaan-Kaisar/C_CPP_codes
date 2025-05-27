
/*  ------------------------    virtual BASE and Multi inheritance   ------------------------

// rev[27-May-2025]

Sure — let’s clarify and simplify this explanation about virtual base classes:

Virtual Base Classes
When a class is inherited multiple times indirectly through different paths in a class hierarchy, it can cause a problem called the "diamond problem" — where a base class ends up with multiple copies in the final derived class.




📌 Example Scenario:
Base is inherited by both Derived1 and Derived2.

Derived3 inherits both Derived1 and Derived2.

Now, Derived3 has two copies of Base — one through Derived1 and one through Derived2.

This creates a conflict (ambiguity) if Derived3 tries to access a member of Base — because it won’t be clear which Base to use.

✅ Solution: Virtual Base Class
To avoid this problem:

Inherit Base as a virtual base class in both Derived1 and Derived2.

This ensures only one shared copy of Base exists in Derived3, no matter how many paths inherit it.

📖 How to declare:
cpp
Copy
Edit
class Derived1 : virtual public Base { };
class Derived2 : virtual public Base { };
The keyword virtual before the access specifier (public) handles this.

📌 Summary:
Problem	Solution
Multiple indirect copies of a base class	Use virtual base classes to share one copy
Ambiguity accessing base members	Virtual inheritance prevents this issue

Would you like a full code example for this too?







Virtual base classes

problems with "one derived" & "multiple direct base"
A potential problem exists when multiple base classes are directly inherited by a derived class. Consider the following class hierarchy:


Derived1 (inherited by Derived 3)

Base (inherited by Derived 1& Derived 2)

  Derived3
	Derived2 (inherited by Derived 3)	
		

Derived1
Base
Derived3
[Base is inherited twice (indirectly) by Derived3]	
	Derived2
Base

( a )	 Here the base class Base is inherited by both Derived1 and Derived2. 
( b )	 Derived3 directly inherits both Derived1 and Derived2. 



	These implies that Base is actually inherited (indirectly) twice by Derived3 -first through Derived1, and then again through Derived2. 
	This causes ambiguity when a " member of Base "  is used by Derived3. Since two copies of Base are included in Derived3, which member should it refer/use. 
	To resolve this ambiguity: in which a derived class indirectly inherits the same base class more than once.  We use the virtual base class.
	If the base class inherited as virtual by any derived classes, it prevents two copies of the base from being present in the derived object.
	The virtual keyword precedes the base class access specifier  when it is inherited by a derived class.


	The only difference between a normal base and a virtual base occurs when an object inherits the base more than once. 





	Example 1:  Here virtual base class prevents two copies of base from being present in derived3.
class base {
   public :
       int i;
};	// Base as virtual.
class derived1 : virtual public base {
		public :  int j;	   };	// base as virtual here , too.
class derived2 : virtual public base {
		public : int k; 
		};
// only one copy of base is present 
class derived3 : public derived1, public derived2
{
public :
	int product() { return i*j*k; }
};	int main() { derived3 ob;
	ob.i=10; // unambiguous : only one copy present
	ob.j=3;
	ob.k=5;
	cout<< "Product is"<< ob.product() <<'\n';
return 0; }



	If derived1 and derived2 had not inherited base as virtual, the statement ob.i = 10; would have been ambiguous and a compile-time error would have resulted.
	It is important to understand that when a base is inherited as virtual by a derived, that base still exists within that derived. For example, this fragment is perfectly valid:
derived1 ob_drv1;  	// we've used derived3 type object in the above
ob_drv1.i = 100;


	The only difference between a normal base and a virtual base occurs when an object inherits the base more than once. 


*/  
