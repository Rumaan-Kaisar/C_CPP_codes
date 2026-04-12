
/*  ------------------------    chapter    ------------------------

	RTTI allows you to identify the type of an object during the execution of your program.
	The casting operators give you safer, more controlled ways to cast. As you will see, one of the casting operators, dynamic cast, relates directly to RTTI.

13.8 RTTI (run-time type identification)
	RTTI is not found in non-polymorphic languages such as C. In such languages, there is no need for run-time type information because the type of each object is known at compile time (i.e., when the program is written). 
	In polymorphic languages such as C++, there can be situations in which the type of an object is unknown at compile time because the precise nature of that object is not determined until the program is executed.  For example: A base class pointer can be used to point to objects of the base class or to any object derived from that base.  This determination must be made at run-time, using RRTI.
	C++ implements polymorphism through :		The use of class hierarchies, 
	Virtual functions, and 
	Base class pointers. 
	To obtain an object's type, use typeid and must include the header <typeinfo>. The most common form of typeid is:
typeid(object)
	Here object is the object whose type you will be obtaining. 
	typeid returns a reference to an object of type type_info that describes the type of object defined by object. 
	The type_info class defines these public members:		bool operator==( const type_info &ob);
	bool operator!=( const type_info &ob);
	bool before( const type_info &ob);
	const char*name();
	The overloaded "==" and "!=" provide for the comparison of types. 
	The before() function returns true if the invoking object is before the object used as a parameter in collation order. (Internal use only. Its return value has nothing to do with inheritance or class hierarchies.) 
	The name() function returns a pointer to the name of the type.
	The most important use of typeid is: its application through a pointer of a polymorphic base. Using typeid you can determine at run-time the type of the object that is being pointed to by a base pointer. 
	typeid will automatically return the type of the actual object being pointed to, which can be a base object or a derived object from that base.  [Note: A base pointer can point to a base object or any derived object from that base.]
	The same applies to references:		When typeid is applied to a reference to an object of a polymorphic class, it will return the type of the object actually being referred to, which can be of a derived type. 
	When typeid is applied to a non-polymorphic class, the base type of the pointer or reference is obtained.
	Another form of typeid: This form of typeid takes a type name as its argument:   typeid( type_name )
	It is used to obtain a type_info object that describes the specified type so that it can be used in a type comparison statement.
	bad_typeid exception: Because typeid is commonly applied to a dereferenced pointer (i.e., one to which the * operator has been applied), a special exception has been created to handle the situation in which the pointer being dereferenced is null. In this case, typeid throws a bad_typeid exception.

	Example 1: The following program demonstrates typeid. It first obtains type information about one of C++'s built-in types, int. It then displays the types of objects pointed to by p, which is a pointer of type BaseClass.
#include <iostream>
#include <typeinfo>
using namespace std;

class BaseClass { 	
	virtual void f(){  }      /* BaseClass polymorphic */ 
		     /* ... */  };

class Derived1 : public BaseClass{ /* ... */  };
class Derived2 : public BaseClass{ /* ... */  };

int main(){	int i;
BaseClass *p, baseob;
Derived1 ob1;
Derived2 ob2;		
	/* First, display type name of a built -in type. */
cout << " Typeid of i is " <<  typeid (i). name () << endl ;

	/* Demonstrate typeid with polymorphic types. */
p = &baseob ;
  cout << "p is pointing to an object of type" << typeid(*p).name() << endl;
p = &ob1;
  cout <<"p is pointing to an object of type" << typeid(*p).name() << endl ;
p = &ob2;
  cout <<"p is pointing to an object of type" << typeid(*p).name() << endl ;
return 0;}

			
			Output [may vary depending on compiler] :
	
Typeid of i is int
p is pointing to an object of type class BaseClass
p is pointing to an object of type class Derived1
p is pointing to an object of type class Derived2
	when typeid is applied to a base pointer of a polymorphic type, the type of object pointed to will be determined at run time, as the output produced by the program shows.
	Example 2 (When objects are passed to functions by reference): In the following program, the function WhatType() declares a reference parameter to objects of type BaseClass. This means that WhatType() can be passed references to objects of type BaseClass or any class derived from BaseClass. When the typeid operator is applied to this parameter, it returns the actual type of the object being passed.
class BaseClass { 	
	virtual void f(){  }      /* BaseClass polymorphic */ 
		     /* ... */  };

class Derived1 : public BaseClass{ /* ... */  };
class Derived2 : public BaseClass{ /* ... */  };

/* Demonstrate typeid with a reference parameter.*/
void WhatType( BaseClass &ob){
	     cout << "ob is referencing an object of type " << typeid(ob).name() << endl ; }	
int main(){ BaseClass baseob ;
	      Derived1 ob1;
	      Derived2 ob2;

		WhatType( baseob );
		WhatType(ob1);
		WhatType(ob2);
	return 0;}

Output: 	ob is pointing to an object of type class BaseClass
		ob is pointing to an object of type class Derived1
		ob is pointing to an object of type class Derived2

	Example 3: Since the type_info object returned by typeid overloads the  ==  and !=  operators, this too is easy to know whether the type of one object matches that of another. The following program demonstrates the use of these operators.
class X { 	virtual void f(){}	};
class Y {	virtual void f(){}	};

	int main(){ 	X x1, x2;
Y y1;

if(typeid(x1) == typeid(x2)) cout << "x1 and x2 are same types \n";
else cout << "x1 and x2 are different types \n";

if( typeid (x1) != typeid (y1)) cout << "x1 and y1 are different types \n";
else cout << "x1 and y1 are same types \n";

return 0;}


	output

   x1 and x2 are same types
   x1 and y1 are different types	

	Example 4: The typeid operator can be applied to template classes. For example, consider the following program. It creates a hierarchy of template classes that store a value. 
	The VF   get_val() returns a value that is defined by each class. 
	Num  for value of the number itself		Square  for square of the number		Sqr_root  for square root of the number. 
	Objects derived from Num are generated by generator() function. The typeid determines the type of the generated object .
#include <iostream>
#include <typeinfo>
#include <cmath>
#include <cstdlib>
using namespace std;

template <class T> class Num{ 
public : 
T x;
Num (T i) { x = i; }
virtual T get_val () { return x; } 
};	template <class T> class Square : public Num <T> { 
public : 
Square(T i) : Num <T>(i){ }
T get_val(){ return (this -> x)*(this ->x);  
/* Edited: main book 'return x*x;' */ 	}
};
	template <class T> class Sqr_root : public Num <T> { 
public : 
Sqr_root(T i) : Num <T>(i){ }
T get_val(){ return sqrt((double) this -> x); 
/* Edited: main book sqrt( (double) x);' */ 	}  
};
/* A Random selection factory for objects derived from Num : for run-time selection.*/ 
Num <double> *generator(){ 
switch( rand() % 2){ 	
case 0: return new Square <double> ( rand() % 100) ;
case 1: return new Sqr_root <double> ( rand() % 100) ; }
return NULL ;  }
int main(){ 	
Num <double> ob1(10), *p1;
Square <double> ob2(100.0) ;
Sqr_root <double> ob3(999.2) ;
int i;

cout << typeid(ob1).name() << endl ;
cout << typeid(ob2).name() << endl ;
cout << typeid(ob3).name() << endl ;

if( typeid(ob2) == typeid(Square <double>)) cout << "is Square <double>\n";

p1 = &ob2 ;
if( typeid(*p1) != typeid(ob1)) cout << " Value is: " << p1 -> get_val();
cout << "\n\n";

cout << "Now , generate some Objects .\n";
for (i=0; i <10; i++){
p1 = generator(); 		/* get next object */ 
if(typeid(*p1) == typeid(Square <double>)) cout << "Square object :";
if(typeid (*p1) == typeid(Sqr_root <double>)) cout << "Sqr_root object:";
cout << "Value is:" << p1 -> get_val();
cout << endl ;
}
return 0;}	

output :
class Num<double>
class Square<double>
class Sqr root<double>
is Square<double>
Value is: 10000
Now, generate some Objects.
Sqr root object: Value is: 8.18535
Square object: Value is: 0
Sqr root object: Value is: 4.89898
Square object: Value is: 3364
Square object: Value is: 4096
Sqr root object: Value is: 6.7082
Sqr root object: Value is: 5.19615
Sqr root object: Value is: 9.53939
Sqr root object: Value is: 6.48074
Sqr root object: Value is: 6

	The example shown in main book will not compile . Reason: Consider a template class Derived with a template base class:

template <typename T> class Base { public: int d; };

template <typename T> class Derived : public Base<T>{  void f(){this->d = 0;}	};

	this has type Derived<T>, a type which depends on T. So this has a dependent type. So this->d makes d a dependent name. Dependent names are looked-up in the context of the template definition as non-dependent names and in the context of instantiation.
	Without this->, the name d would only be looked-up as a non-dependent name, and not be found.
	Another solution is to declare d in the template definition itself:

template <typename T> class Derived : public Base<T> { 	using Base::d; 
void f(){ d = 0; }	};

Note: 	RTTI is not common in every program. However, when you are working with polymorphic types, it allows you to know what type of object is being operated upon in any given situation.



*/  
