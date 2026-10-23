				
/*  ------------------------    RTTI: Runtime Type Identification    ------------------------

    RTTI Basics:
        RTTI identifies the "actual type" of an object at "run time".
        C++ uses RTTI when an object's exact type is unknown at compile time.

        In C, RTTI is generally not available as a built-in language feature 
            object types are typically determined at "compile time" instead of "run time".


    RTTI and Casting Operators:
        The "casting operators" gives safer, more controlled ways to cast. 

        One of the casting operators, dynamic_cast is directly related to RTTI
            dynamic_cast can perform "run-time type checking" (RTTI) when converting 
            "pointers" or "references" within a "polymorphic class hierarchy".



    ----------------    RTTI (run-time type identification)    ----------------

    RTTI is not found in "non-polymorphic languages" such as C. 
        We dont need RTTI for C, because the type of each object is known at "compile-time"
        (i.e., when the program is written). 


    In "polymorphic languages" such as C++, there can be situations in which-
        the type of an object is "unknown at compile-time" 
        because the precise nature of that object is not determined until the program is executed.
    
    For example:
        In C++, a base-class pointer can point to:
            - A base-class object.
            - An object of any derived class.

        This determination must be made at "run-time", using RRTI.



    --------  C++ Polymorphism  --------

    C++ implements polymorphism through:
        Class hierarchies.
        Virtual functions.
        Base-class pointers.



    --------  typeid: obtain an object's type  --------

    To obtain an object's type, use "typeid" and must include the header <typeinfo>.
    
    Common syntax:

                typeid(obj)

        Here "obj" is the object whose type you will be obtaining. 

        "typeid" returns a reference to an object of type "type_info" that describes 
            the type of object defined by "obj". 
        
        Another form accepts a "type name" as its argument:

                typeid(type_name)

            Used to obtain type information for "type comparisons".
            [returns a "type_info object" that describes the specified type]


    bad_typeid exception: 
        Because typeid is commonly applied to a dereferenced pointer (i.e., one to which the * operator has been applied), 
            a "special exception" has been created to handle the situation in which the pointer being dereferenced is "null". 

        In this case, typeid throws a "bad_typeid exception".



    --------  typeid with non-polymorphic class  --------

    typeid with non-polymorphic class:
        When typeid is applied to a "non-polymorphic class", the base type of the pointer or reference is obtained.

    It means that in C++, when you use "typeid" with a pointer or reference to a non-polymorphic class, 
        C++ determines the type from the "declared type" of the pointer or reference, 
        "not the actual type" of the object it points to or refers to.

    In C++, when you apply the typeid operator to a non-polymorphic class (a class that has no virtual functions), 
        the compiler determines the type at "compile-time" rather than runtime.

        Because the evaluation happens at compile-time, typeid cannot look at the actual object sitting in memory.
        Instead, it strictly looks at the declared (static) type of the pointer or reference you are using.



    --------  Members of the "type_info"  --------

    Members of the "type_info" Class:
    
        bool operator==(const type_info &ob);
        bool operator!=(const type_info &ob);
        bool before(const type_info &ob);
        const char*name();


            Member          Purpose
            
            operator==()    Checks whether two types are the same.
            operator!=()    Checks whether two types are different.
            before()        Checks the relative order of two types.
            name()          Returns a pointer to the type's name.


        The overloaded "==" and "!=" provide for the "comparison of types". 

        before() is used for "type ordering"; 
            its result has no relationship to inheritance or class hierarchies (i.e. internal use only).
            returns "true" if the invoking object is before the object used as a parameter in collation order.

        The name() function returns a pointer to the name of the type.



    --------  RTTI with Base-Class Pointers  --------

    The most important use of typeid is- its application through a pointer of a "polymorphic base".
    "typeid" can identify at "run-time" the actual object type that is being pointed to by a polymorphic base-class pointer.

    If the base class is polymorphic (has at least one virtual function),
        "typeid" will automatically return the type of the actual object being pointed to,
        which can be a "base object" or a "derived object" from that base.
        [Note: A "base pointer" can point to a "base object" or any "derived object" from that base.]

        Example:
            typeid(*ptr)

    

    --------  RTTI with "references"  --------

    The same RTTI rule applies to "references":
        When "typeid" is applied to a "reference" to an object of a "polymorphic class", 
        it will return the type of the object actually being referred to, which can be of a derived type.
*/




/* Example 1: Following program demonstrates type_id. 
                It first obtains type information about "int".
                It then displays the types of objects pointed to by p, which is a pointer of type BaseClass.
*/

#include <iostream>
#include <typeinfo>

class BaseClass {   
    virtual void f(){  }      // make BaseClass polymorphic
    // ...
};

class Derived1 : public BaseClass{
    // ...
};

class Derived2 : public BaseClass{
    // ...  
};


int main(){
    int num;
    BaseClass *p, baseob;
    Derived1 ob1;
    Derived2 ob2;
    
    // First, display type name of a built -in type.
    std::cout << "Typeid of num is " <<  typeid(num).name() << std::endl;

    // Demonstrate typeid with polymorphic types.
    p = &baseob;
    std::cout << "p is pointing to an object of type" << typeid(*p).name() << std::endl;

    p = &ob1;
    std::cout << "p is pointing to an object of type" << typeid(*p).name() << std::endl;

    p = &ob2;
    std::cout << "p is pointing to an object of type" << typeid(*p).name() << std::endl;

    return 0;
}


/*  Output [may vary depending on compiler]:
        
            Typeid of i is int
            p is pointing to an object of type class BaseClass
            p is pointing to an object of type class Derived1
            p is pointing to an object of type class Derived2

        Note: 
            it may shows int as "i", float as "f"

    when "typeid" is applied to a "base pointer" of a polymorphic type, 
        the type of object pointed to will be determined at "run time", 
        as the output produced by the program shows.
    
    Now try to comment out the virtual function f() in BaseClass and observe the results.

    Note on "type abbreviation":
        For an int variable in C++, typeid(num).name() typically returns "i" on 
        common compilers like GCC and Clang (using the Itanium C++ ABI), 
        or "int" on Microsoft Visual C++ (MSVC).
*/




/*  ----------------    abbreviation code for built-in types in C++    ----------------

    There are many more fundamental types in C++.
    Because GCC/Clang "compresses" them using "name mangling", each type gets its own specific abbreviation code, 
        while MSVC spells out the full name.


    GCC / Clang type codes:

    | ------------------------------------ |
    | C++ type             | Mangling code |
    | -------------------- | ------------- |
    | int                  |  i            |
    | float                |  f            |
    | double               |  d            |
    | char                 |  c            |
    | short                |  s            |
    | long                 |  l            |
    | bool                 |  b            |
    | void                 |  v            |
    | unsigned int         |  j            |
    | unsigned long        |  m            |
    | long long            |  x            |
    | unsigned long long   |  y            |
    | signed char          |  a            |
    | unsigned char        |  h            |
    | unsigned short       |  t            |
    | ------------------------------------ |


    --------  Modified Types (Pointers & References)   --------
    
    When you add pointers (*) or arrays, GCC/Clang stacks these abbreviations together:
        - int* becomes "Pi" (Pointer to int)
        - const int becomes "Ki" (constant int)
        - int& becomes "Ri" (Reference to int)

    pointer and reference codes:

    | ---------------------------------- |
    | C++ type           | Mangling code |
    | ------------------ | ------------- |
    | int*               |  Pi           |
    | const int          |  Ki           |
    | const int*         |  PKi          |
    | int&               |  Ri           |
    | int&&              |  Oi           |
    | int const* const   |  KPKi         |
    | ---------------------------------- |


    The prefixes mean:

        `P` — pointer
        `R` — lvalue reference
        `O` — rvalue reference
        `K` — `const`

    Note: MSVC does not use the Itanium ABI's single-letter type encodings. It uses its own decorated-name format, which is different.
*/









// ----  rev[22-Oct-2026]  ----


/*  

   Example 2 (When objects are passed to functions by reference): In the following program, the function WhatType() declares a reference parameter to objects of type BaseClass. This means that WhatType() can be passed references to objects of type BaseClass or any class derived from BaseClass. When the typeid operator is applied to this parameter, it returns the actual type of the object being passed.

class BaseClass {
    virtual void f(){  }      // BaseClass polymorphic
    // ...
};

class Derived1 : public BaseClass{
    // ...
};
class Derived2 : public BaseClass{
    // ...
};


// Demonstrate typeid with a reference parameter.

void WhatType( BaseClass &ob){
         cout << "ob is referencing an object of type " << typeid(ob).name() << endl ; }    
int main(){ BaseClass baseob ;
          Derived1 ob1;
          Derived2 ob2;

        WhatType( baseob );
        WhatType(ob1);
        WhatType(ob2);
    return 0;}

Output:     ob is pointing to an object of type class BaseClass
        ob is pointing to an object of type class Derived1
        ob is pointing to an object of type class Derived2




   Example 3: Since the type_info object returned by typeid overloads the  ==  and !=  operators, this too is easy to know whether the type of one object matches that of another. The following program demonstrates the use of these operators.
class X {   virtual void f(){}  };
class Y {   virtual void f(){}  };

    int main(){     X x1, x2;
Y y1;

if(typeid(x1) == typeid(x2)) cout << "x1 and x2 are same types \n";
else cout << "x1 and x2 are different types \n";

if( typeid (x1) != typeid (y1)) cout << "x1 and y1 are different types \n";
else cout << "x1 and y1 are same types \n";

return 0;}


    output

   x1 and x2 are same types
   x1 and y1 are different types    




   Example 4: The typeid operator can be applied to template classes. For example, consider the following program. It creates a hierarchy of template classes that store a value. 
   The VF   get_val() returns a value that is defined by each class. 
   Num  for value of the number itself
   Square  for square of the number
   Sqr_root  for square root of the number. 
   Objects derived from Num are generated by generator() function. The typeid determines the type of the generated object .

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
};  template <class T> class Square : public Num <T> { 
public : 
Square(T i) : Num <T>(i){ }
T get_val(){ return (this -> x)*(this ->x);  

// Edited: main book 'return x*x;'
}
};
    template <class T> class Sqr_root : public Num <T> { 
public : 
Sqr_root(T i) : Num <T>(i){ }
T get_val(){ return sqrt((double) this -> x); 

// Edited: main book sqrt( (double) x);'
}
};

// A Random selection factory for objects derived from Num : for run-time selection.

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
p1 = generator();       // get next object
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

   The example shown in main book will not compile . Reason: Consider a template class Derived with a template base class:

template <typename T> class Base { public: int d; };

template <typename T> class Derived : public Base<T>{  void f(){this->d = 0;}   };

   this has type Derived<T>, a type which depends on T. So this has a dependent type. So this->d makes d a dependent name. Dependent names are looked-up in the context of the template definition as non-dependent names and in the context of instantiation.
   Without this->, the name d would only be looked-up as a non-dependent name, and not be found.
   Another solution is to declare d in the template definition itself:

template <typename T> class Derived : public Base<T> {  using Base::d; 
void f(){ d = 0; }  };

Note:   RTTI is not common in every program. However, when you are working with polymorphic types, it allows you to know what type of object is being operated upon in any given situation.

*/






/* 2. As explained, when typeid is applied to a reference to a polymorphic base class, the
type returned is that of the actual object being referred to. The circumstances in which
you will most often make use of this feature is when objects are passed to functions by
reference. For example, in the following program, the function WhatType() declares a
reference parameter to objects of type BaseClass. This means that parameter to objects
of type BaseClass. This means that WhatType() can be passed references to objects

of type BaseClass or any class derived from BaseClass. When the typeid operator is
applied to this parameter, it returns the actual type of the object being passed.
 */

// Use a reference with typeid
# include <iostream>
# include <typeinfo>

class BaseClass
{
virtual void f() {} // make BaseClass polymorphic
// ...
};
class Derived1 : public BaseClass
{
// ...
};
class Derived2 : public BaseClass
{
// ...
};
// Demonstrate typeid with a reference parameter .
void WhatType ( BaseClass &ob)
{
cout << "ob is referencing an object of type ";
cout << typeid (ob). name () << endl ;
}
int main ()
{
BaseClass baseob ;
Derived1 ob1 ;
Derived2 ob2 ;
WhatType ( baseob );
WhatType ( ob1 );
WhatType ( ob2 );
return 0;
}
The output produced by this program is shown here.
ob is pointing to an object of type class BaseClass
ob is pointing to an object of type class Derived1
ob is pointing to an object of type class Derived2



/* 3. Although obtaining the type name of an object is useful in some circumstances often all
you need to know is whether the type of one object matches that of another. Since the
type info object returned by typeid overloads the == and ! = operators, this too is
easy to accomplish. The following program demonstrates the use of these operators.
 */
// Demonstrate == and != relative to typeid .
# include <iostream >
# include <typeinfo >

class X
{
virtual void f() {}
};
class Y
{
virtual void f() {}
};
int main ()
{
X x1 , x2;
Y y1;
if( typeid (x1) == typeid (x2))
cout << "x1 and x2 are same types \n";
else
cout << "x1 and x2 are different types \n";
if( typeid (x1) != typeid (y1))
cout << "x1 and y1 are different types \n";
else
cout << "x1 and y1 are same types \n";
return 0;
}
The program displays the following output.
x1 and x2 are same types
x1 and y1 are different types


/* 4. Although the preceding examples demonstrate the mechanics of using typeid, they don’t
show its full potential because the types in the preceding programs are knowable at compile
time. In the following program this is not the case. The program defines a simple class
hierarchy that draws shapes on the screen. At the top of the hierarchy is the abstract
class Shape. Four concrete subclasses are created: Line, Square, Rectangle, and
NullShape. The function generator() generates an object and returns a pointer to
it. The actual object created is determined randomly based upon the outcome of the
random number generator rand(). (A function that produces objects is sometimes called
an object factory.) Inside main(), the shape of each object is displayed for all objects but
NullShape objects, which have no shape. Since objects are generated randomly, there
is no way to know in advance what type of object will be created next. Thus, the use of
RTTI is required. 
*/

# include <iostream >
# include <cstdlib >
# include <typeinfo >

class Shape
{
public :
virtual void example () = 0;
};
class Rectangle : public Shape
{
public :
void example ()
{
cout << " *****\ n* *\n* *\n *****\ n";
}
};
class Triangle : public Shape
{
public :
void example ()
{
cout << "*\n* *\n* *\n *****\ n";
}
};
class Line : public Shape
{
public :
void example ()
{
cout << " *****\ n";
}
};
class NullShape : public Shape
{
public :
void example ()
{ }
};
// A factory for objects derived from Shape .
Shape * generator ()
{
switch ( rand () % 4)
{
case 0:
return new Line ;
case 1:
return new Rectangle ;
case 2:
return new Triangle ;
case 3:
return new NullShape ;
}
return NULL ;
}
int main ()
{
int i;
Shape *p;
for (i =0; i <10; i ++)
{
p = generator (); // get next object
cout << " class " << typeid (*p). name () << endl ;
// draw object only if it is not a NullShape
if( typeid (*p) != typeid ( NullShape ))
p-> example ();
}
return 0;
}


Sample output from the program is shown here


class Rectangle
*****
* *
* *
*****
class NullShape
class Triangle
*
* *
* *
*****
class Line
*****
class Rectangle
316RUN-TIME TYPE IDENTIFICATION AND THE CASTING OPERATORS
12.1. UNDERSTANDING RUN-TIME TYPE IDENTIFICATION (RTTI)
*****
* *
* *
*****
class Line
*****
class Triangle
*
* *
* *
*****
class Triangle
*
* *
* *
*****
class Triangle
*
* *
* *
*****
class Line
*****


/* 5. The typeid operator can be applied to template classes. For example, consider the
following program. It creates a hierarchy of template classes that store a value. The
virtual function get val() returns a value that is defined by each class. For class Num,
this is the value of the number itself. For Square, it is the square of the number, and for
Sqr root, it is the square root of the number. Objects derived from Num are generated
by the generator() function. The typeid operator is used to determine what type of
object has been generated.
*/
// typeid can be used with templates .
# include <iostream >
# include <typeinfo >
# include <cmath >
# include <cstdlib >

template <class T> class Num
{
public :
T x;
Num (T i) { x = i; }
virtual T get_val () { return x; }

};
template <class T>
class Square : public Num <T>
{
public :
Square (T i) : Num <T >(i) {}
T get_val () { return this ->x*this ->x; }
};
template <class T>
class Sqr_root : public Num <T>
{
public :
Sqr_root (T i) : Num <T >(i) {}
T get_val () { return sqrt (( double ) this ->x); }
};
// A factory for objects derived from Num .
Num < double > * generator ()
{
switch ( rand () % 2)
{
case 0:
return new Square <double > ( rand () % 100) ;
case 1:
return new Sqr_root <double > ( rand () % 100) ;
}
return NULL ;
}
int main ()
{
Num < double > ob1 (10) , *p1;
Square < double > ob2 (100.0) ;
Sqr_root < double > ob3 (999.2) ;
int i;
cout << typeid ( ob1 ). name () << endl ;
cout << typeid ( ob2 ). name () << endl ;
cout << typeid ( ob3 ). name () << endl ;
if( typeid ( ob2 ) == typeid (Square <double >))
cout << "is Square <double >\n";
p1 = & ob2 ;
if( typeid (* p1) != typeid (ob1 ))
cout << " Value is: " << p1 -> get_val ();
cout << "\n\n";

cout << "Now , generate some Objects .\n";
for (i =0; i <10; i ++)
{
p1 = generator (); // get next object
if( typeid (* p1) == typeid (Square <double >))
cout << " Square object : ";
if( typeid (* p1) == typeid ( Sqr_root <double >))
cout << " Sqr_root object : ";
cout << " Value is: " << p1 -> get_val ();
cout << endl ;
}
return 0;
}

/*
The example shown in main book will not compile .
Reason : https :// goo .gl/ s0cazE
Remedy : https :// goo .gl /6 lw2sJ
*/
The output from the program is shown here.
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
319






EXERCISES

1. Why is RTTI a necessary feature of C++?

2. Try the experiment described in Example 1. What output do you see?


3. Is the following fragment correct?
cout << typeid ( float ). name ();


4. Given this fragment, show how to determine whether p is pointing to a D2 object.
class B
{
virtual void f() {}
};
class D1 : public B
{
void f() {}
};
class D2 : public B
{
void f() {}
};
int main ()
{
B *p;

5. Assuming the Num class from Example 5, is the following expression true or false?
typeid (Num <int <) == typeid (Num <double >)

6. On your own, experiment with RTTI. Although its use might seem a bit esoteric in the
context of simple, sample programs, it is a powerful construct that allows you to manage
objects at run time.



----  EXERCISES  ----
1. RTTI is necessary to C++ because it is not always possible to know at compile time what
type of object is being pointed to by a base class pointer of referenced by a base class
reference.

2. Here is the output produced when BaseClass is no longer a polymorphic class.
Typeid of i is int
p is pointing to an object of type class BaseClass
p is pointing to an object of type class BaseClass
p is pointing to an object of type class BaseClass

3. Yes.

4. if( typeid (*p) == typeid (D2)) ...

5. False. Although the same template class is used, the type of data used by each version is
different.

