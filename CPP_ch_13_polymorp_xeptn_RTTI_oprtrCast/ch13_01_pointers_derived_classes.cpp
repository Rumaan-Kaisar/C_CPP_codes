
/*  ------------------------    Pointers To Derived Classes    ------------------------

    Pointers To Derived Classes
        A pointer declared as a "pointer to a base class" can also be 
            used to point to any class (child) derived from that base. 

        Example:
            Assume two classes called "base" and "derived", 
            where "derived" inherits "base". Then the following statements are correct:

                base *p;                // base class pointer 
                base base_ob;           // object of type base 
                derived derived_ob;     // object of type derived 

                p = &base_ob ;          // p points to base object : Normally p can.
                p = &derived_ob ;       // p points to derived object : Advanced pointing by p 



    A "pointer to a base class" can point to:
        - An object of the base class, or
        - An object of any class "derived from that base" without generating a type mismatch error

        "Base pointer" can access "derived object":
            But you can "only access members inherited from the base class"
                Cannot access members "added in the derived class".
                because base pointer has knowledge only of the base class

        The reverse is not true:
            "Derived pointer" cannot access "base object"
            (Can be forced with casting, but "not recommended".)

 

    --------  NOTE (Pointer arithmetic)  --------

    Pointer arithmetic is relative to the "data type" the pointer is declared as pointing to. 

    If you point a "base pointer" to a "derived object" then 
        Incrementing a base pointer "p++" moves it by "sizeof(base)", not "sizeof(derived)".
        It will not be pointing to the next derived object. 
        It will be pointing to (what it thinks is) the next base object.

    So, if pointing to a derived object, "p++" may misalign and cause errors.


----  rev[14-Apr-2026]  ----





class base{
    int x;
    public:     void setx(int i){ x=i; }
        int getx(){ return x; } };

class derived : public base { int y;
    public :    void sety(int i){ y=i; }
        int gety(){ return y; } };

int main(){ base *p;        // pointer to base type 
        base b_ob ;     // object of base 
        derived d_ob ;  // object of derived
p = &b_ob ;               // p access base  : point to base object
p-> setx(10) ;            // access base object 
cout << " Base object x: " << p-> getx () << '\n';

p = &d_ob ;               // p access derived : point to derived object 
p-> setx(99) ;            // access derived object 

d_ob.sety(88) ;            // can't use p to set y, so do it directly
cout << " Derived object x: " << p-> getx() << '\n';
cout << " Derived object y: " << d_ob.gety() << '\n';
    return 0; }
   There is no value in using a base class pointer in the way shown in this example.



*/  


/* Example 1: Following illustrates how a "base class pointer" can be used to access a derived clas.s:
                Enabling "polymorphism" and writing generic code using base pointers. */

// Demonstrate pointer to derived class .
# include <iostream >
using namespace std ;
class base
{
int x;
public :
void setx ( int i) { x = i; }
int getx () { return x; }
};
class derived : public base
{
int y;
public :
void sety ( int i) { y = i; }
int gety () { return y; }
};
int main ()
{
base *p; // pointer to base type
base b_ob ; // object of base
derived d_ob ; // object of derived
// use p to access base object
p = & b_ob ;
p-> setx (10) ; // access base object
cout << " Base object x: " << p-> getx () << ’\n’;
// use p to access derived object
p = & d_ob ; // point to derived object
p-> setx (99) ; // access derived object
// can ’t use p to set y, so do it directly
d_ob . sety (88) ;
263TEACH YOURSELF
C++
cout << " Derived object x: " << p-> getx () << ’\n’;
cout << " Derived object y: " << d_ob . gety () << ’\n’;
return 0;
}
Aside from illustrating pointers to derived classes, there is no value in using a base class
pointer in the way shown in this example. However, in the next section you will see why
base class pointers to derived objects are so important.
