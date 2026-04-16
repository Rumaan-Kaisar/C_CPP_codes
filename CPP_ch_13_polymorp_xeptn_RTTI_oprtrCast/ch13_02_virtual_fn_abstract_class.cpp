
/*  ------------------------    Virtual Functions (VF)    ------------------------


    A virtual function is a "base class member function" and redefined (overridden) by derived classes.
    
    
    
     To create a virtual function, precede the function's declaration with the keyword virtual.  When a VF is redefined by a derived, the keyword virtual is not needed. A class that contains a VF is referred to as a polymorphic class.

	When a class containing a VF is inherited, the derived redefines the VF relative to the derived.  VF implements the "one interface, multiple methods" philosophy that underlies polymorphism. 
	The VF within the base class defines the form of the interface to that function. 
	Each redefinition of the VF by a derived implements its operation as it relates specifically to that derived. I.e. the redefinition creates a specific method. 
	A VF can be called just like any other member function. But interesting thing happens when a virtual function is called through a pointer- creates the run-time polymorphism. 
	When a base pointer points to a derived object that contains a VF and that VF is called through that pointer, it is the type of that pointed object that determines which version of the VF will be executed at the time when the call occurs. And, this determination is made at run time. This process is the way that run-time polymorphism is achieved.
	Therefore, if two or more different classes are derived from a base class that contains a VF, then when different objects are pointed to by a base pointer, different versions of the virtual function are executed.

	Example 1: Following uses a VF. Here the type of the object being pointed to determines which version of an overridden virtual function will be executed when accessed via a base class pointer, and that this decision is made at run time. 
			class base{
			public: int i;
			 base(int x) { i = x; }
			 virtual void func() { cout<< " Using base version of func(): ";
			 cout << i << '\n'; }
			};
class derived1 : public base {
public : derived1(int x) : base(x){} /* passing argument to base constructor and uses same definition. Using base's constructor */
void func(){cout<< " Using derived1's version of func (): ";
	      cout << i*i << '\n'; }
				};	class derived2 : public base {
public : derived2(int x) : base(x){} /* passing argument to base constructor and uses same definition. Using base's constructor */
void func(){cout << " Using derived2 's version of func (): ";
	      cout << i+i << '\n'; }
				};
int main(){	base *p;
		base ob (10) ;
		derived1 d_ob1 (10) ;
		derived2 d_ob2 (10) ;
	p = &ob; 	p -> func();  /* use base 's func() */ 
	p = &d_ob1 ; 	p -> func();  /* use derived1's func() */ 
	p = &d_ob2 ; 	p -> func();  /* use derived2 's func() */ 
return 0; }	This program displays the following output:

Using base version of func( ): 10
Using derived1's version of func( ): 100
Using derived2's version of func( ): 20

	Above program creates three classes. 
	The base class defines the virtual function func(). 
	"base" is then inherited by both derived1 and derived2. Each of these classes overrides func() with its individual implementation. 
	Inside main(), the base pointer p is declared along with objects of type base, derived1, and derived2. 
i.	First, p is assigned the address of ob (base type object). When func() is called by using p, the base version of func() is used. 
ii.	Next, p is assigned the address of d_ob1. In this time derived1 version (the overridden version) of func() is executed when func() is called using p. (the type of the object pointed to determines which VF will be called)
iii.	Finally, p is assigned the address of d_ob2 and func() is called again by using p. This time, it is the overridden version of func() defined inside derived2 is executed.
	Virtual functions are hierarchical in order of inheritance. Further, when a derived class does not override a virtual function, the function defined within its base class is used. For example consider the previous example with the modified "derived2" 
class derived2 : public base
{ public :
	derived2 (int x) : base(x){}
	/* derived2 does not override func( ) */ 
};	int main() {. . . . .
	p = &d_ob2 ;
	p -> func(); 
	/* use base's func( ) */ 
return 0;
}	This program displays the following output:

Using base version of func( ): 10
Using derived1's version of func( ): 100
Using base version of func( ): 10

	In this version, derived2 does not override func(). When p is assigned d_ob2 and func() is called, base's version is used because it is next up in the class hierarchy. In general, when a derived class does not override a VF, the base class's version is used.
	A VF can respond to random events that occur at run time. Consider Example 1, following modified main() selects between d_ob1 and d_ob2 based upon the value returned by the standard random number generator rand(). 
	Remember that the version of func() executed is resolved at run time. (Which is impossible at compile time.)

int main(){	base *p;
derived1 d_ob1 (10);
derived2 d_ob2 (10);
int i,j;

for(i=0; i<10; i++){	 j = rand();

   if((j%2) ) p = &d_ob1 ; 	/* if odd use d_ob1 */ 
   else p = &d_ob2 ; 		/* if even use d_ob2 */ 

p -> func(); 	}		/* call appropriate function */	
return 0; }


Note
[1]	Redefinition of a VF inside a derived class and function overloading are different process (although they look similar). 
	An overloaded function must differ in type and/or number of parameters, while a redefined VF must have precisely the same type and number of parameters and the same return type. (changing either the number or type of parameters of redefined VF destroys its virtual nature and makes it an "overloaded function") 
	Virtual functions must be class members. This is not the case for overloaded functions. 
	Destructor functions can be virtual, constructors cannot.
	Because of the difference between overloaded functions and redefined VF, the term "overriding" is used to describe VF redefinition.








13.3 Abstract class and Pure Virtual function (PVF)
Sometimes when a VF is declared in the base class there is no meaningful operation for it to perform.  Because often a base simply supplies a core set of member functions and variables to which the derived class supplies the remainder.  In this case we use pure virtual functions (PVF).
	A PVF has no definition relative to the base class. Only the function's prototype is included. To make a PVF, use this general form:
virtual type func_name(parameter_list =0;
	The key part of this declaration is the setting of the function equal to 0. This tells the compiler that no body exists for this function relative to the base class. 
	When a virtual function is made pure, it forces any derived class to override it. If a derived class does not, a compile-time error results. 
	Abstract class: When a class contains at least one PVF, it is referred to as an abstract class. It is an incomplete type, and no objects of that class can be created.  Thus, abstract classes exist only to be inherited. They are neither intended nor able to stand alone. 
	You can still create a pointer to an abstract class, since it is through the use of base class pointers that run-time polymorphism is achieved. 
	It is also permissible to have a reference to an abstract class.
	When a VF is inherited, so is its virtual nature. I.e. when a derived inherits a VF from a base and then that derived is used as a base for yet another derived, the VF can be overridden by the final derived class (as well as the first derived). For example, if base B contains a VF called f(), and D1 inherits B and D2 inherits D1, both D1 and D2 can override f() relative to their respective classes.
	Example 1: This program creates a base called area that holds two dimensions of a figure. It also declares a VF called getarea() that, when overridden by derived classes, returns the area of the type of figure defined by the derived. 

	class area{ 	double dim1 , dim2 ; 	/* dimensions of figure */ 
		public : 	void setarea(double d1, double d2){ dim1 = d1; dim2 = d2;}
		void getdim(double &d1 , double &d2) { d1 = dim1 ; d2 = dim2 ; }
			virtual double getarea(){ 	cout << "You must override this function \n";
							return 0.0; }
		};
class rectangle : public area {
	public :
		double getarea(){double d1, d2;
				    getdim(d1, d2);
				    return d1*d2;  }
				};	class triangle : public area {
	public :
		double getarea() { double d1, d2;
				     getdim(d1, d2);
				  return 0.5*d1*d2;}
				};
int main(){ 	area *p;
		rectangle r;
		triangle t;
			r.setarea(3.3, 4.5) ;
			t.setarea(4.0, 5.0) ;
			p = &r; cout << " Rectangle has area : " << p-> getarea() << '\n';
			p = &t; cout << " Triangle has area : " << p-> getarea() << '\n';
		return 0; }
	In this case, the declaration of getarea() inside the base determines the nature of the interface. The actual implementation is left to the classes that inherit it. In this example, the area of a triangle and a rectangle are computed.
	Here the definition of getarea() inside area is just a placeholder and performs no real function. Because area is not linked to any specific type of figure, there is no meaningful definition that can be given to getarea() inside area.  
	getarea() must be overridden by a derived class in order to be useful. 

class area{ . . . . . . same as previous . . . . .
virtual double getarea() = 0; 	/* pure virtual function */ 	};
	Example 2: Following program illustrates how a function's virtual nature is preserved when it is inherited:
class base {
public : virtual void func(){ 
cout << " Base version of func ( )\n"; }	};	class derived1 : public base {
public : void func(){ 
cout <<"derived1's version of func()\n"; }
 };	class derived2 : public derived1{ 	/* derived2 inherits derived1 */  
public : void func(){ 
cout << "derived2's version of func()\n"; } };
int main() { 	base *p;
		base ob;
		derived1 d_ob1 ;
		derived2 d_ob2 ;
			p = &ob; 	p -> func(); 		/* use base's func() */ 
			p = &d_ob1 ; 	p -> func(); 		/* use derived1's func() */ 
			p = &d_ob2 ; 	p -> func(); 		/* use derived2's func() */ 
		return 0; }
	The VF func() is first inherited by derived1, which overrides it relative to itself. Next, derived2 inherits derived1. In derived2, func() is again overridden.
	Since VFs are hierarchical, if derived2 did not override func(), when d_ob2 was accessed, derived1's func() would have been used.
	If neither derived1 nor derived2 had overridden func(), base's func( ) would have been used.









----  QWEN  ----

Here is a clean, simplified, and logically organized pointwise summary of your notes:



📘 13.2 Virtual Functions (VF)


🔹 Core Concepts

Declared using the "virtual" keyword in the base class. 
The keyword is optional in derived classes.


Enables the "one interface, multiple methods" principle → foundation of polymorphism.
Base class defines the interface; derived classes provide specific implementations.


🔹 Run-Time Polymorphism
Achieved when a VF is called through a base class pointer.
The actual object type pointed to determines which function version runs.
Function resolution happens at run-time, not compile-time.
Allows dynamic behavior: the same pointer can trigger different derived methods based on runtime conditions (e.g., user input, random selection).


🔹 Inheritance & Hierarchy Behavior
Virtual nature is preserved through multiple inheritance levels.
If a derived class does not override a VF, the nearest base class version is automatically used.
Example logic: Base → Derived1 → Derived2
If only Derived1 overrides, Derived2 inherits that version.
If neither overrides, Base version runs.



🔹 Virtual Functions vs. Function Overloading
Feature
Virtual Function (Overriding)
Function Overloading

Signature
Must match exactly (same params & return type)
Must differ in parameter type/count

Scope
Must be a class member
Can be standalone or class member

Resolution
Run-time (dynamic binding)
Compile-time (static binding)

Keyword
virtual in base
None required


⚠️ Changing a VF's signature destroys its virtual nature and turns it into an overloaded function.



🔹 Constructor & Destructor Rules
❌ Constructors cannot be virtual.
✅ Destructors can (and often should) be virtual to ensure proper cleanup in polymorphic hierarchies.





📘 13.3 Pure Virtual Functions (PVF) & Abstract Classes


🔹 Pure Virtual Function (PVF)
Declared with = 0 in the base class: virtual return_type func() = 0;
Has no implementation in the base class (acts only as an interface placeholder).
Forces every derived class to override it; otherwise, compilation fails.
Used when the base class has no meaningful default behavior for that function.


🔹 Abstract Class
Any class containing at least one PVF is an abstract class.
❌ Cannot be instantiated (no objects can be created).
✅ Exists only to be inherited and used as a base.
✅ Pointers and references to abstract classes are allowed (essential for run-time polymorphism).


🔹 Key Behavior & Usage
PVFs define a contract: derived classes must provide the actual logic.
Example: class area { virtual double getarea() = 0; };
rectangle and triangle inherit area and must implement getarea().
Virtual hierarchy rules still apply: PVF overrides are inherited and can be further overridden down the chain.


💡 Quick Reference Checklist
✅ Use virtual in base class to enable overriding.
✅ Call through base pointer → run-time polymorphism.
✅ Missing override? → Base/nearest version runs.
✅ = 0 → Pure virtual → Abstract class → Must be overridden.
✅ Abstract classes: no objects, but pointers/references allowed.
✅ Overriding ≠ Overloading (signature must match exactly for VFs).
✅ Destructors: virtual ✅ | Constructors: virtual ❌
Let me know if you'd like this converted into flashcards, a diagram, or a condensed cheat sheet!








Here is a clean, simplified, and logically organized pointwise summary of your notes:

---
### 📘 **13.2 Virtual Functions (VF)**

#### 🔹 **Core Concepts**
- A **virtual function** is a base class member function intended to be redefined (overridden) in derived classes.
- Declared using the `virtual` keyword in the base class. The keyword is **optional** in derived classes.
- Enables the `"one interface, multiple methods"` principle → foundation of **polymorphism**.
- Base class defines the **interface**; derived classes provide **specific implementations**.

#### 🔹 **Run-Time Polymorphism**
- Achieved when a VF is called through a **base class pointer**.
- The **actual object type** pointed to determines which function version runs.
- Function resolution happens at **run-time**, not compile-time.
- Allows dynamic behavior: the same pointer can trigger different derived methods based on runtime conditions (e.g., user input, random selection).

#### 🔹 **Inheritance & Hierarchy Behavior**
- Virtual nature is **preserved** through multiple inheritance levels.
- If a derived class **does not override** a VF, the nearest base class version is automatically used.
- Example logic: `Base → Derived1 → Derived2`
  - If only `Derived1` overrides, `Derived2` inherits that version.
  - If neither overrides, `Base` version runs.

#### 🔹 **Virtual Functions vs. Function Overloading**
| Feature | Virtual Function (Overriding) | Function Overloading |
|--------|-------------------------------|----------------------|
| **Signature** | Must match exactly (same params & return type) | Must differ in parameter type/count |
| **Scope** | Must be a class member | Can be standalone or class member |
| **Resolution** | Run-time (dynamic binding) | Compile-time (static binding) |
| **Keyword** | `virtual` in base | None required |
| ⚠️ Changing a VF's signature destroys its virtual nature and turns it into an overloaded function. |

#### 🔹 **Constructor & Destructor Rules**
- ❌ **Constructors** cannot be virtual.
- ✅ **Destructors** can (and often should) be virtual to ensure proper cleanup in polymorphic hierarchies.

---
### 📘 **13.3 Pure Virtual Functions (PVF) & Abstract Classes**

#### 🔹 **Pure Virtual Function (PVF)**
- Declared with `= 0` in the base class: `virtual return_type func() = 0;`
- Has **no implementation** in the base class (acts only as an interface placeholder).
- **Forces** every derived class to override it; otherwise, compilation fails.
- Used when the base class has no meaningful default behavior for that function.

#### 🔹 **Abstract Class**
- Any class containing **at least one PVF** is an abstract class.
- ❌ **Cannot be instantiated** (no objects can be created).
- ✅ Exists **only to be inherited** and used as a base.
- ✅ Pointers and references to abstract classes **are allowed** (essential for run-time polymorphism).

#### 🔹 **Key Behavior & Usage**
- PVFs define a **contract**: derived classes must provide the actual logic.
- Example: `class area { virtual double getarea() = 0; };`
  - `rectangle` and `triangle` inherit `area` and must implement `getarea()`.
- Virtual hierarchy rules still apply: PVF overrides are inherited and can be further overridden down the chain.

---
### 💡 **Quick Reference Checklist**
- ✅ Use `virtual` in base class to enable overriding.
- ✅ Call through base pointer → run-time polymorphism.
- ✅ Missing override? → Base/nearest version runs.
- ✅ `= 0` → Pure virtual → Abstract class → Must be overridden.
- ✅ Abstract classes: no objects, but pointers/references allowed.
- ✅ Overriding ≠ Overloading (signature must match exactly for VFs).
- ✅ Destructors: virtual ✅ | Constructors: virtual ❌

Let me know if you'd like this converted into flashcards, a diagram, or a condensed cheat sheet!



*/  
