


// ----  rev[07-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-








// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


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




// polymorph: compiled
/* Example 1: Enhance the list example from above, Example 2, 
                so that it overloads the + and -- operators. 

                Have the + store an element and the -- retrieve an element. 
*/

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




/* Example 1:

            What is a virtual function? How do virtual functions differ from overloaded functions?

                A virtual function is a function declared as "virtual" in a "base" class 
                    and intended to be "overridden" by a derived class.
                    A base class that contains at least one pure virtual function is called an "abstract class".

                Difference from overloaded functions:
                    "Overloaded" functions must differ in the "number of parameters" or the "type of parameters".
                    An overridden virtual function "must have exactly the same prototype" as the original function.
                    (i.e. same return type, and same type and number of parameters) 



            What is a pure virtual function? 
            If a class declaration contains a pure virtual function, what is that class called? And
            What restrictions apply to its usage?

                A pure virtual function is a virtual function declared with "= 0" (e.g., virtual void func() = 0;) 
                    and typically has no implementation in the base class.

                A class containing at least one pure virtual function is called an "abstract class".

                Restrictions: 
                    You cannot instantiate (create objects of) an abstract class directly. 
                    It can only be used as a base class, and any derived class must override all pure virtual functions 
                    to become a concrete (instantiable) class.



            If, in a class hierarchy, a derived class neglects to override a (non-pure) virtual function, 
                what happens when an object of that derived class calls that function?
            
                If a derived class does not override a "non-pure virtual function", 
                the derived class will automatically inherit and use the "base class’s version" of that virtual function.



            What is the main advantage of "run-time polymorphism"? 
            What is its potential disadvantage?
            
                Main advantage: 
                    Flexibility.
                    It allows writing generic code that can work with objects of 
                    different derived classes through a common base class interface).
            
                Potential disadvantage: 
                    Loss of execution speed. 
                    Due to the slight overhead of "dynamic binding" and virtual table lookups at run-time.
*/

