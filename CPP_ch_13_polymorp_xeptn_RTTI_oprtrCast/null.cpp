vir fn EX + abs fn EX:


1. Here is a short example that uses a virtual function:
// A simple example using a virtual function .
# include <iostream >
using namespace std ;
class base
{
public :
int i;
264VIRTUAL FUNCTIONS
10.2. INTRODUCTION TO VIRTUAL FUNCTIONS
base ( int x) { i = x; }
virtual void func ()
{
cout << " Using base version of func (): ";
cout << i << ’\n’;
}
};
class derived1 : public base
{
public :
derived1 ( int x) : base (x) {}
void func ()
{
cout << " Using derived1 ’s version of func (): ";
cout << i*i << ’\n’;
}
};
class derived2 : public base
{
public :
derived2 ( int x) : base (x) {}
void func ()
{
cout << " Using derived2 ’s version of func (): ";
cout << i+i << ’\n’;
}
};
int main ()
{
base *p;
base ob (10) ;
derived1 d_ob1 (10) ;
derived2 d_ob2 (10) ;
p = &ob;
p-> func (); // use base ’s func ()
p = & d_ob1 ;
p-> func (); // use derived1 ’s func ()
p = & d_ob2 ;
p-> func (); // use derived2 ’s func ()
return 0;
}
This program displays the following output:
Using base version of func(): 10
265TEACH YOURSELF
C++
Using derived1’s version of func(): 100
Using derived2’s version of func(): 2


The redefinition of a virtual function inside a derived class might, at first, seem somewhat
similar to function overloading. However, the two processes are distinctly different. First,
an overloaded function must differ in type and/or number of parameters, while a redefined
virtual function must have precisely the same type and number of parameters and the
same return type. (In fact, if you change either the number or type of parameters when
redefining a virtual function, it simply becomes an overloaded function and its virtual
nature is lost.) Further, virtual functions must be class members. This is not the case for
overloaded functions. Also, while destructor functions can be virtual, constructors cannot.
Because of the difference between overloaded functions and redefined virtual functions,
the term overriding is used to describe virtual function redefinition.
As you can see, the example program creates three classes. The base class defines the
virtual function func(). This class is then inherited by both derived1 and derived2.
Each of these classes overrides func() with its individual implementation. Inside main(),
the base class pointer p is declared along with objects of type base, derived1, and
derived2. First, p is assigned the address ob ob (an object of type base). When func()
is called by using [, it is the version in base that is used. Next, p is assigned the address
of d ob1 and func() is called again. Because it is the type of the object pointed to that
determines which virtual function will be called, this time it is the overridden version
in derived1 that is executed. Finally, p is assigned the address of d ob2 and func()
is called again, This time, it is the version of func() defined inside derived2 that is
executed.
The key points to understand from the preceding example are that the type of the object being pointed to determines which version of an overridden virtual function will be
executed when accessed via a base class pointer, and that this decision is made at run
time.
2. Virtual functions are hierarchical in order of inheritance. Further, when a derived class
does not override a virtual function, the function defined within its base class is used. For
example, here is a slightly different version of the preceding program:
// Virtual functions are hierarchical .
# include <iostream >
using namespace std ;
class base
{
public :
int i;
base ( int x) { i = x; }
virtual void func ()
{
cout << " Using base version of func (): ";
cout << i << ’\n’;
}
};
class derived1 : public base
{
public :
266VIRTUAL FUNCTIONS
10.2. INTRODUCTION TO VIRTUAL FUNCTIONS
derived1 ( int x) : base (x) {}
void func ()
{
cout << " Using derived1 ’s version of func (): ";
cout << i*i << ’\n’;
}
};
class derived2 : public base
{
public :
derived2 ( int x) : base (x) {}
// derived2 does not override func ()
};
int main ()
{
base *p;
base ob (10) ;
derived1 d_ob1 (10) ;
derived2 d_ob2 (10) ;
p = &ob;
p-> func (); // use base ’s func ()
p = & d_ob1 ;
p-> func (); // use derived1 ’s func ()
p = & d_ob2 ;
p-> func (); // use base ’s func ()
return 0;
}
This program displays the following output:
Using base version of func(): 10
Using derived1’s version of func(): 100
Using base version of func(): 10
In this version, derived2 does not override func(). When p is assigned d ob2 and func()
is called, base’s version is used because it is next up in the class hierarchy. In general,
when a derived class does not override a virtual function, the base class’s version is use


3. The next example shows how a virtual function can respond to random events that occur at
run time. This program selects between d ob1 and d ob2 based upon the value returned
by the standard random number generator rand(). Keep in mind that the version of
func() executed is resolved at run time. (Indeed, it is impossible to resolve the calls to
func() at compile time.)
/*
This example illustrates how a virtual function
can be used to respond to random events occurring
267TEACH YOURSELF
C++
at run time .
*/
# include <iostream >
# include <cstdlib >
using namespace std ;
class base
{
public :
int i;
base ( int x) { i = x; }
virtual void func ()
{
cout << " Using base version of func (): ";
cout << i << ’\n’;
}
};
class derived1 : public base
{
public :
derived1 ( int x) : base (x) {}
void func ()
{
cout << " Using derived1 ’s version of func (): ";
cout << i*i << ’\n’;
}
};
class derived2 : public base
{
public :
derived2 ( int x) : base (x) {}
void func ()
{
cout << " Using derived2 ’s version of func (): ";
cout << i+i << ’\n’;
}
};
int main ()
{
base *p;
derived1 d_ob1 (10) ;
derived2 d_ob2 (10) ;
int i, j;
for (i =0; i <10; i ++)
{
j = rand ();
if ((j %2) )
268VIRTUAL FUNCTIONS
10.2. INTRODUCTION TO VIRTUAL FUNCTIONS
p = & d_ob1 ; // if odd use d_ob1
else
p = & d_ob2 ; // if even use d_ob2
p-> func (); // call appropriate function
}
return 0;
}
4. Here is a more practical example of how a virtual function can be used. This program
creates a generic base class called area that holds two dimensions of a figure. It also
declares a virtual function called getarea() that, when overridden by derived classes,
returns the area of the type of figure defined by the derived class. In this case, the
declaration of getarea() inside the base class determines the nature of the interface. The
actual implementation is left to the classes that inherit it. In this example, the area of a
triangle and a rectangle are computed.
// Use virtual function to define interface .
# include <iostream >
using namespace std ;
class area
{
double dim1 , dim2 ; // dimensions of figure
public :
void setarea ( double d1 , double d2)
{
dim1 = d1;
dim2 = d2;
}
void getdim ( double &d1 , double &d2)
{
d1 = dim1 ;
d2 = dim2 ;
}
virtual double getarea ()
{
cout << " You must override this function \n";
return 0.0;
}
};
class rectangle : public area
{
public :
double getarea ()
{
double d1 , d2;
getdim (d1 , d2);
return d1 * d2;
}
};
269TEACH YOURSELF
C++
class triangle : public area
{
public :
double getarea ()
{
double d1 , d2;
getdim (d1 , d2);
return 0.5 * d1 * d2;
}
};
int main ()
{
area *p;
rectangle r;
triangle t;
r. setarea (3.3 , 4.5) ;
t. setarea (4.0 , 5.0) ;
p = &r;
cout << " Rectangle has area : " << p-> getarea () << ’\n’;
p = &t;
cout << " Triangle has area : " << p-> getarea () << ’\n’;
return 0;
}
Notice that the definition of getarea() inside area is just a placeholder and performs
no real function. Because area is not linked to any specific type of figure, there is no
meaningful definition that can be given to getarea() inside area. In fact, getarea()
must be overridden by a derived class in order to be useful. In the next section, you will
see a way to enforce this


1. Write a program that creates a base class called num. Have this class hold an integer
value and contain a virtual function called shownum(). Create two derived classes called
outhex and outoct that inherit num. Have the derived classs override shownum() so
that it displays the value in hexadecimal and octal, respectively.


2. Write a program that creates a base class called dist that stores the distance between two
points in a double variable. In dist, create a virtual function called trav time() that
outputs the time it takes to travel that distance, assuming that the distance is in miles and
the speed is 60 miles per hour. In a derived class called metric, override trav time() so
that it outputs the travel time assuming that the distance is in kilometers and the speed
is 100 kilometers per hour.

1. # include <iostream >
using namespace std ;
class num
{
public :
int i;
547TEACH YOURSELF
C++
num ( int x) { i = x; }
virtual void shownum () { cout << i << ’\n’; }
};
class outhex : public num
{
public :
outhex ( int n) : num(n) {}
void shownum () { cout << hex << i << ’\n’; }
};
class outoct : public num
{
public :
outoct ( int n) : num(n) {}
void shownum () { cout << oct << i << ’\n’; }
};
int main ()
{
outoct o (10) ;
outhex h (20) ;
o. shownum ();
h. shownum ();
return 0;
}
2. # include <iostream >
using namespace std ;
class dist
{
public :
double d;
dist ( double f) { d = f; }
virtual void trav_time ()
{
cout << " Travel time at 60 mph : ";
cout << d / 60 << ’\n’;
}
};
class metric : public dist
{
public :
metric ( double f) : dist (f) {}
void trav_time ()
{
cout << " Travel time at 100 kph : ";
548ANSWERS
10.3 EXERCISES
cout << d / 100 << ’\n’;
}
};
int main ()
{
dist *p, mph (88.0) ;
metric kph (88) ;
p = & mph ;
p-> trav_time ();
p = & kph ;
p-> trav_time ();
return 0;
}




// ABS:

1. Here is an improved version of the program shown in Example 4 in the predeing section.
In this version, the function getarea() is declared as pure in the base class area.
// Create an abstract class
# include <iostream >
using namespace std ;
class area
{
double dim1 , dim2 ; // dimensions of figure
public :
void setarea ( double d1 , double d2)
{
dim1 = d1;
dim2 = d2;
}
void getdim ( double &d1 , double &d2)
{
d1 = dim1 ;
271TEACH YOURSELF
C++
d2 = dim2 ;
}
virtual double getarea () = 0; // pure virtual function
};
class rectangle : public area
{
public :
double getarea ()
{
double d1 , d2;
getdim (d1 , d2);
return d1 * d2;
}
};
class triangle : public area
{
public :
double getarea ()
{
double d1 , d2;
getdim (d1 , d2);
return 0.5 * d1 * d2;
}
};
int main ()
{
area *p;
rectangle r;
triangle t;
r. setarea (3.3 , 4.5) ;
t. setarea (4.0 , 5.0) ;
p = &r;
cout << " Rectangle has area : " << p-> getarea () << ’\n’;
p = &t;
cout << " Triangle has area : " << p-> getarea () << ’\n’;
return 0;
}
Now that getarea() is pure, it ensures that each derived class will override it.
2. The following program illustrates how a function’s virtual nature is preserved when it is
inherited:
// Virtual functions retain their virtual nature when
inherited ,
272VIRTUAL FUNCTIONS
10.3. MORE ABOUT VIRTUAL FUNCTIONS
# include <iostream >
using namespace std ;
class base
{
public :
virtual void func ()
{
cout << " Using base version of func ()\n";
}
};
class derived1 : public base
{
public :
void func ()
{
cout << " Using derived1 ’s version of func ()\n";
}
};
// derived2 inherits derived1 .
class derived2 : public derived1
{
public :
void func ()
{
cout << " Using derived2 ’s version of func ()\n";
}
};
int main ()
{
base *p;
base ob;
derived1 d_ob1 ;
derived2 d_ob2 ;
p = &ob;
p-> func (); // use base ’s func ()
p = & d_ob1 ;
p-> func (); // use derived1 ’s func ()
p = & d_ob2 ;
p-> func (); // use derived2 ’s func ()
return 0;
}
In this program, the virtual function func() is first inherited by derived1, which overrides
it relative to itself. Next, derived2 inherits derived1. In derived2, func() is again
273TEACH YOURSELF
C++
overridden.
Because virtual functions are hierarchical, if derived2 did not override func(), when
d ob2 was accessed, derived1’s func() would have been used. If neither derived1 nor
derived2 had overridden func(), all references to it would have been routed to the one
defined in base


1. On your own, experiment with the two example programs. Specifically, try creating an
object by using area from Example 1 and observe the error message. In Example 2, try
removing the redefinition of func() within derived2. Confirm that, indeed, the version
inside derived1 is used.

2. Why can’t an object be created by using an abstract class?


3. In Example 2, what happens if you remove only the redefinition of func() inside derived1? Does the program still compile and run? If so, why?


2. By definition, an abstract class contains at least one pure virtual function. This means
that no body for that function exists relative to that class. Thus, there is no way that an
object can be created because the class definition is not complete.
3. When func() is called relative to derived1, it is the func() inside base that is used.
The reason this works is that virtual functions are hierarchical.




