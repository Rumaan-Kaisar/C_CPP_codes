


// ----  rev[08-May-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-








// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


At this point you should be able to perform the following exercises and answer the questions.
1. What is a virtual function?
2. What types of functions cannot be made virtual?
3. How does a virtual function help achieve run-time polymorphism? Be specific.
4. What is a pure virtual function?
5. What is an abstract class? What is a polymorphic class?
6. Is the following fragment correct? If not, why not?

        class base {
            public :
                virtual int (int a) = 0;
                // ...
        };

        class derived : public base {
            public :
                int f(int a, int b) { return a*b; }
                // ...
        }:

7. Is the virtual quality inherited?
8. On your own, experiment with virtual functions at this time. This is an important concept
and you should master the technique.




1. A virtual function is essentially a placeholder function that is declared in a base class and
that is redefined by a class derived from that base. The process of redefinition is called
overriding.
2. Nonmember functions and constructor functions cannot be made virtual.
3. A virtual function supports run-time polymorphism through the use of base class pointers.
When a base class pointer points to an object of a derived class containing a virtual
function, the specific function called is determined by the type of object being pointed to.
4. A pure virtual function is one that contains no definition relative to the base class.
5. An abstract class is a base class that contains at least one pure virtual function. A
polymorphic class is one that contains at least one virtual function.
6. The fragment is incorrect because the redefinition of a virtual function must have the
same return type and type and number of parameters as the original function. In this
case, the redefinition of f() differs in the number of its parameters.
7. Yes.



// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

This section checks how well you have integrated material in this chapter with that from the
preceding chapters.
1. Enhance the list example from Section 10.4, Example 1, so that it overloads the + and {
operators. Have the + store an element and the { retrieve an element.
2. How do virtual functions differ from overloaded functions?
3. On your own, reexamine some of the function overloading examples presented earlier in
this book. Determine which can be converted to virtual functions. Also, think about ways
in which a virtual function can solve some of your own programming problems



1. // Demonstrate virtual functions .
# include <iostream >
# include <cstdlib >

class list
{
public :
list * head ; // pointer to start of list
list * tail ; // pointer to end of list
list * next ; // pointer to next item
int num ; // value to be stored

list () { head = tail = next = NULL ; }
virtual void store (int i) = 0;
virtual int retrieve () = 0;
};


// Create a queue - type list .
class queue : public list
{
public :
void store ( int i);
int retrieve ();
queue operator +( int i) { store (i); return * this ; }
int operator --( int unused ) { return retrieve (); }
};


void queue :: store ( int i)
{
list * item ;
item = new queue ;
if (! item )
{
cout << " Allocation error .\n";
exit (1) ;
}
item ->num = i;
// put on end of list
if( tail )
tail -> next = item ;
tail = item ;
item -> next = NULL ;
if (! head )
head = tail ;
}


int queue :: retrieve ()
{
int i;
list *p;
if (! head )
{
cout << " List empty .\n";
return 0;
}
// remove from start of list
i = head -> num ;
p = head ;
head = head -> next ;

delete p;
return i;
}


// Create a stack - type list .
class stack : public list
{
public :
void store ( int i);
int retrieve ();
stack operator +( int i) { store (i); return * this ; }
int operator --( int unused ) { return retrieve (); }
};


void stack :: store ( int i)
{
list * item ;
item = new stack ;
if (! item )
{
cout << " Allocation error .\n";
exit (1) ;
}
item ->num = i;
// put on front of list for stack - like operation
if( head )
item -> next = head ;
head = item ;
if (! tail )
tail = head ;
}
int stack :: retrieve ()
{
int i;
list *p;
if (! head )
{
cout << " List empty .\n";
return 0;
}

// remove from start of list
i = head -> num ;
p = head ;
head = head -> next ;
delete p;

return i;
}



int main ()
{
// demonstrate queue
queue q_ob ;
q_ob + 1;
q_ob + 2;
q_ob + 3;
cout << " Queue : ";
cout << q_ob --;
cout << q_ob --;
cout << q_ob --;
cout << '\n';
// demonstrate stack
stack s_ob ;
s_ob + 1;
s_ob + 2;
s_ob + 3;
cout << " Stack : ";
cout << s_ob --;
cout << s_ob --;
cout << s_ob --;
cout << '\n';
return 0;
}



2. Virtual functions differ from overloaded functions in that overloaded functions must differ
from the number of parameters or the type of parameters. An overridden virtual function
must have exactly the same prototype (that is, the same return type and the same type
and number of parameters) as the original function.



// ----  rev[31-Mar-2026] ----

// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
1. What is a virtual function?
2. What is a pure virtual function? If a class declaration contains a pure virtual function,
what is that class called, and what restrictions apply to its usage?
3. Run-time polymorphism is achieved through the use of functions and
class pointers. (Fill in the missing words.)
4. If, in a class hierarchy, a derived class neglects to override a (non-pure) virtual function,
what happens when an object of that derived class calls that function?
5. What is the main advantage of run-time polymorphism? What is its potential disadvantage?



1. A virtual function is a function that is declared as virtual by the base class and then
overridden by a derived class. A base class that contains at least one pure virtual function
is called an abstract class.
2. The missing words are "virtual" and "base".
3. If a derived class does not override a non-pure virtual function, the derived class will use
the base class’s version of the virtual function.

4. The main advantage of run-time polymorphism is flexibility. The main disadvantage is
loss of execution speed.




