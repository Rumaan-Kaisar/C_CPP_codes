 abs fn EX:





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




