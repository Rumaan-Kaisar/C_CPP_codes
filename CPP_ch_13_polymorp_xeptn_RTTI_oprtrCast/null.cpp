


// ----  rev[08-May-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-








// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


At this point you should be able to perform the following exercises and answer the questions.


/* Example 1:
            What is a virtual function?
                A VF is a placeholder function declared within a base class.
                It is intended to be redefined by any class derived from that base class.
                This redefinition process is technically known as "OVERRIDING".

            What types of functions "cannot be made virtual"?
                Nonmember functions (functions not part of any class).
                Constructor functions.

            How does a virtual function help achieve run-time polymorphism (dynamic function resolution)?
                A virtual function supports run-time polymorphism through the use of base class pointers.
                (also  referred as "dynamic binding" or "late binding")
                
                When a base class pointer points to a derived class object containing the virtual function, 
                    the program determines which version to call during execution (run-time).
                
                The specific function executed depends on the "actual type" of the object being pointed to, 
                    rather than the "declared type" of the pointer.
*/




/* Example 2:
            What is a pure virtual function?
                It is a virtual function that contains no definition in the base class.
                It is declared using the syntax "= 0" (e.g., "virtual void func() = 0;").
                It serves as a placeholder that "must be overridden" by any concrete derived class.
                Classes containing pure virtual functions cannot be instantiated directly.

            What is an abstract class? What is a polymorphic class?
                Abstract Class:
                    A base class that contains "at least one PURE Virtual Function".
                    Cannot be instantiated; it is designed to be inherited by derived classes.
                    Provides a common interface for derived classes to implement.

                Polymorphic Class:
                    A class that contains "at least one Virtual Function" (regular or pure).
                    Enables run-time polymorphism through base class pointers or references.
                    Allows derived class objects to be treated as base class objects while maintaining correct function behavior.

                Key Relationship:
                    All abstract classes are polymorphic (since pure virtual functions are virtual), 
                    but not all polymorphic classes are abstract (a class with only regular virtual functions can still be instantiated).
*/




/* Example 3: 
            Is the following fragment correct? If not, why explain?

                class base {
                    public :
                        virtual int f(int a) = 0;
                        // ...
                };

                class derived : public base {
                    public :
                        int f(int a, int b) { return a*b; }
                        // ...
                }:

            ans:
                The fragment is "incorrect".
                When overriding a virtual function, the derived class version (redefinition of the VF) must have:
                    same function name
                    same return type
                    same number and types of parameters as the original function (identical signature)

                In this case, the redefinition of f() differs in the number of its parameters.
                    The base class declares f(int), but the derived class defines f(int, int) — the "parameter count" differs.

                Result:
                    So this fragment "does not OVERRIDE" the base function; instead it creates a new "overloaded" function, 
                    --> leaving the "pure virtual function unimplemented"
                    --> compilation error if `derived` is instantiated.
*/
 
 
 
/* Example 4: Is the virtual quality inherited?

            ans:
                Yes. Once a function is declared "virtual" in a base class, 
                    it remains "virtual" in all derived classes.
  
                Derived classes may optionally use the "virtual" keyword again (for clarity), 
                    but it is not required.
  
                This inheritance of the "virtual" property is what enables "consistent run-time polymorphism" 
                    throughout the inheritance hierarchy.
*/




// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

This section checks how well you have integrated material in this chapter with that from the
preceding chapters.






// polymorph
/* Example 1: Enhance the list example from above, Example 2, so that it overloads the + and --
operators. Have the + store an element and the { retrieve an element. */


#include <iostream>
#include <cstdlib>

class list{
    public:
        list *head;         // pointer to start of list  
        list *tail;         // pointer to end of list  
        list *next;         // pointer to next item  

        int num;            // value to be stored  

        list(){ head = tail = next = NULL; }

        // actions for add and get values
        virtual void store(int i) = 0;      // PVF 
        virtual int retrieve() = 0;         // PVF 
};


// Create a derived class "queue" - type "list". Notice the operator overloading
class queue : public list {
    public :
        void store(int i);
        int retrieve();
        
        // operator overloading
        queue operator+(int i) { 
            store(i); 
            return *this; 
        }
        int operator--( int unused ) { return retrieve(); }
};


// Create a derived class "stack" - type "list". Notice the operator overloading
class stack : public list {
    public :
        void store(int i);
        int retrieve();

        // operator overloading
        stack operator +(int i) { 
            store(i);
            return *this;
        }
        int operator --(int unused) { return retrieve(); }
};


// -------- queue's versions of "store" and "retrieve"  --------

void queue :: store(int i) {
    list *item;
    item = new queue;

    if(!item){
        std::cout << " Allocation error .\n";
        exit(1);
    }

    item -> num = i;

    // put on end of list
    if(tail) tail -> next = item;

    tail = item;
    item -> next = NULL;

    if(!head) head = tail;
}


int queue :: retrieve() {
    int i;
    list *p;

    if(!head) {
        std::cout << " List empty .\n";
        return 0;
    }

    // remove from start of list
    i = head -> num ;
    p = head;
    head = head -> next;

    delete p;
    return i;
}


// -------- stack's own versions of "store" and "retrieve"  --------

void stack :: store(int i) {
    list *item;
    item = new stack;

    if(!item) {
        std::cout << " Allocation error .\n";
        exit(1);
    }

    item -> num = i;

    // put on front of list for stack - like operation
    if(head) item -> next = head;
    head = item;
    if(!tail) tail = head;
}


int stack :: retrieve() {
    int i;
    list *p;

    if (!head){
        std::cout << " List empty .\n";
        return 0;
    }

    // remove from start of list
    i = head -> num;
    p = head;
    head = head -> next;
    delete p;

    return i;
}


int main() {
    // demonstrate queue
    queue q_ob;

    q_ob+1;
    q_ob+2;
    q_ob+3;

    std::cout << " Queue : ";
    std::cout << q_ob--;
    std::cout << q_ob--;
    std::cout << q_ob--;
    std::cout << '\n';

    // demonstrate stack
    stack s_ob ;

    s_ob+1;
    s_ob+2;
    s_ob+3;

    std::cout << " Stack : ";
    std::cout << s_ob--;
    std::cout << s_ob--;
    std::cout << s_ob--;
    std::cout << '\n';

    return 0;
}

/* Example 2: This program shows the idea of “one interface, multiple methods.” 
                It creates an abstract "list" class for storing integers.

                The "list" uses two functions: 
                    store() to add a value and 
                    retrieve() to get a value.

                    They both are Pure Virtual Functions (PVFs)
                    So the interface to the "list" is defined by the PVFs store() and retrieve().

                The base (abstract) class "list" does not define any default methods for these functions.
                    Instead, each derived class decides how to store and retrieve data.

                In this program, two types of lists are implemented: a queue and a stack. 
                    Even though they work differently, both use the same interface (store and retrieve).
*/









int main(){
    list *p;    // Base class pointer.
                // This will be used to demonstrate runtime polymorphism:
                // the same pointer will behave differently for queue and stack.

    // -------- Demonstrate Queue (FIFO) --------
    queue q_ob; // Create a queue object

    p = &q_ob;  // Point base class pointer to queue object

    // Insert elements into queue
    p->store(1);     
    p->store(2);
    p->store(3);
    // Order inserted: 1 --> 2 --> 3

    std::cout << "Queue: ";

    // Retrieve elements from queue
        // Since queue is FIFO:
        // Output will be: 1 2 3
    std::cout << p->retrieve();  
    std::cout << p->retrieve();
    std::cout << p->retrieve();


    std::cout << '\n';


    // -------- Demonstrate Stack (LIFO) --------
    stack s_ob; // Create a stack object

    p = &s_ob;  // Point same base class pointer to stack object

    // Insert elements into stack
        // Order pushed: 1 --> 2 --> 3
        // Top of stack is now 3
    p->store(1);
    p->store(2);
    p->store(3);


    std::cout << "Stack: ";

    // Retrieve elements from stack
        // Since stack is LIFO:
        // Output will be: 3 2 1
    std::cout << p->retrieve();
    std::cout << p->retrieve();
    std::cout << p->retrieve();
    

    std::cout << '\n';

    return 0;
}




/* Example 2: How do virtual functions differ from overloaded functions? */

Virtual functions differ from overloaded functions in that overloaded functions must differ
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
