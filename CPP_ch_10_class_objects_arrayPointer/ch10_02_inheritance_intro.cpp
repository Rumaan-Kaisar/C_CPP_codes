
11.1 Introduction to INHERITANCE
In C++, inheritance is the mechanism by which one class can inherit the properties of another. Inheritance allows a hierarchy of classes to be built, moving from the most general to the most specific.
	Base class and derived class: When one class is inherited by another, the class that is inherited is called the base class. The inheriting class is called the derived class. In general, the process of inheritance begins with the definition of a base class. The base class defines all qualities that will be common to any derived classes.
	The base class represents the most general description of a set of traits. A derived class inherits those general traits and adds properties that are specific to that class.

Example of base class and derived class
The declaration for the base class	Using base class, here is a derived class that inherits it:
	/* Define base class. */
class Bs {	int i;
		public : void set_i(int n);
		int get_i();  };		/* Define derived class . */
class Drv : public Bs { int j;
			public : void set_k(int n);
				  int mul();   };
	Notice that after the class name Drv there is a colon followed by the keyword public and the class name Bs. This tells the compiler that class Drv will inherit all components of class Bs. 
	They keyword public tells the compiler that Bs will be inherited such that all public elements of the base class will also be public elements of the derived class. However, all private elements of the base class remain private to it and are not directly accessible by the derived class.
	Derived class can call base class public member functions directly. For example consider the following function. 
int :: mul(){	return j*get_i(); }
Notice that it calls get_i(), which is a member of the base class Bs, not of Drv, without linking it to any specific object (without base class it won't be possible). 
However, the reason that mul() must call get_i() instead of accessing i directly is that the private members of a base class (in this case,i) remain private (due to encapsulation) to it and not accessible by any derived class. 
	The general form used to inherit a base class is shown here:
class derived_class_name : access_specifier base_class_name {
. . . . . . . };
Here access-specifier is one of these three keywords: public, private, or protected. 

