
// --------  cp4 :: 09-May-2026

/*  ------------------------    Polymorphism    ------------------------

    Polymorphism is an OOP concept where: 
        One interface (common interface) can be used for many different actions.
        It follows the idea of "one interface, multiple methods."

        This means the same function or method name can behave differently 
            depending on the object or situation, 
            reducing complexity and improving flexibility.

        In polymorphism a single, "well-defined interface" is used to access 
            a number of different but related actions, and artificial complexity is removed.



    ----------------    Early binding & Late binding    ----------------

    Early binding (build-time):
        Early binding essentially refers to those "events" that can be "known" at COMPILE time.
        Specifically, it refers to those function calls that can be resolved "during compilation".
    
        Early bound entities include:
            [1] "Normal" functions,
            [2] Overloaded functions,
            [3] Non-virtual member
            [4] Friend functions.

        When these types of functions are compiled:
            All address information necessary to call them is "known at compile time". 
            Calls to functions bound at compile time are the fastest types of function calls.

        Features:
            * Function addresses are fixed at "COMPILE time".
            * Faster execution.
            * Less flexible than late binding.

        Advantage:
            High speed and better performance.

        Disadvantage:
            Lack of flexibility.



    Late binding (run-time):
        Late binding refers to events that must occur at run time.
            i.e. the function call is decided during "program EXECUTION" (run time).
        
        The compiler does not know the "exact function to call" until the program "runs".
            the address of the function to be called is not known until the program runs. 

        In C++ a virtual function is a late bound object.  
        When a VF is called through a base class pointer, 
            the program must determine at "runtime" what type of object the pointer actually refers to, 
            and then runs the correct overridden function.

        Features:
            Function selection happens at run time.
            More flexible than early binding.
            Slightly slower.

        Advantage: 
            Flexibility at run time.  

        Disadvantage:
            Slower than early binding.


    ------------------------------------------------------------------------
    | Feature        | Early Binding                   | Late Binding      |
    | -------------- | ------------------------------- | ----------------- |
    | Decision Time  | Compile time                    | Run time          |
    | Functions Used | Normal, overloaded, non-virtual | Virtual functions |
    | Speed          | Faster                          | Slower            |
    | Flexibility    | Less flexible                   | More flexible     |
    | Also Called    | Static binding                  | Dynamic binding   |



    ----------------    Difference Between Polymorphism and Inheritance    ----------------

    These concepts are closely related, but they are "not the same thing".

    Inheritance:
        One class acquires the properties and behaviors of another class.
        It creates an “is-a” relationship.

        Purpose of Inheritance:
            * Code reuse
            * Creating relationships between classes
            * Building class hierarchies

    Polymorphism:
        The same function/interface behaves differently for different objects.

        runtime polymorphism can be achived using "virtual functions".

        Role of Virtual Functions:
            A VF enables "late binding" (runtime polymorphism).
            Without "virtual", the base class function is called.
            With "virtual", C++ decides at runtime which overridden function to execute.

        Pure Virtual Function:
            A pure virtual function is a virtual function with "no implementation" in the base class.

        Abstract Class:
            A class containing at least one pure VF is called an "abstract class".
*/




/*  Example 1: What is the difference between "inheritance" and the concepts of: 
                virtual functions, 
                pure virtual functions, and 
                abstract classes?

            ans:
                Inheritance is the base concept that connects all of them.
                    Virtual functions, pure virtual functions, and abstract classes 
                    are all tools used within inheritance to control how inherited behavior works in polymorphic ways.

                More precisely:
                    Virtual functions, pure virtual functions, and abstract classes 
                    are mechanisms used within inheritance to control and shape how 
                    inherited behavior behaves at runtime through polymorphism.


                Inheritance gives code reuse (child class gets parent class features).
                Polymorphism gives flexibility (same function call behaves differently depending on the object).

                Virtual functions, pure virtual functions, and abstract classes 
                    combine both inheritance and polymorphism together.

                How they connect:
                    Virtual function + inheritance          -->     runtime polymorphism
                    Pure virtual function + inheritance     -->     forced polymorphism
                    Abstract class + inheritance            -->     design structure for polymorphism

                    Inheritance Provides the Relationship

                    While:
                        Virtual Functions provide Polymorphism
                        Pure Virtual Functions Force a Common Interface
                        Abstract Classes Act as Templates
*/



/* Example 1: This program shows the idea of “one interface, multiple methods.” 
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

#include<iostream>
#include<cstdlib>

class list{
    public:
        list *head;         // pointer to start of list  
        list *tail;         // pointer to end of list  
        list *next;         // pointer to next item  

        int num;            // value to be stored  

        list(){ head = tail = next = NULL ; }

        // actions for add and get values
        virtual void store(int i) = 0;      // PVF 
        virtual int retrieve() = 0;         // PVF 
};


// Create a queue - type list.
class queue : public list {
            public : void store(int i);
                   int retrieve();
                };

void queue :: store(int i){ list *item;
    item = new queue ;
    if(!item ){     cout << " Allocation error .\n";
            exit(1); }
    item -> num = i;

// put on end of list 
    if(tail) tail -> next = item ;
    tail = item ;
    item -> next = NULL ;
    if(!head) head = tail ;  }

int queue :: retrieve(){    int i;
                list *p;
    if(!head){  cout << " List empty.\n ";
            return 0; }

// remove from start of list 
    i = head -> num;
    p = head ;
    head = head -> next ;
    delete p;
    return i; } 
// Create a stack - type list.

class stack : public list {
            public : void store(int i);
                   int retrieve();
                };

void stack :: store(int i){ list *item ;
    item = new stack ;
    if(!item){  cout << " Allocation error.\n";
            exit(1); }
    item -> num = i;

// put on front of list for stack - like operation 
    if(head) item -> next = head ;
    head = item ;
    if(!tail) tail = head ; }

int stack :: retrieve(){    int i;
                list *p;
    if(!head){  cout << " List empty .\n";
            return 0; }

// remove from start of list 
    i = head -> num;
    p = head ;
    head = head -> next ;
    delete p;
    return i; }

int main() {    list *p;
// demonstrate queue 
        queue q_ob ;
        p = &q_ob;      // point to queue  
            p-> store(1);
            p-> store(2);
            p-> store(3);
        cout << " Queue : ";
            cout << p-> retrieve();
            cout << p-> retrieve();
            cout << p-> retrieve();
            cout << '\n';   // demonstrate stack 
        stack s_ob;
        p = &s_ob;  // point to stack  
            p-> store(1);
            p-> store(2);
            p-> store(3);
        cout << " Stack : ";
            cout << p-> retrieve();
            cout << p-> retrieve();
            cout << p-> retrieve();
            cout << '\n';
        return 0;}


// --------  rev[17-May-2026]  --------

/* Example 2: The Power of Run-Time Polymorphism

                Following updated main() function shows how random events that occur at run time 
                    can be easily handled by using "Virtual Functions" and run-time polymorphism.

                Storing values:
                    A FOR-loop runs from 0 to 9. For each number, you choose whether to add it to a stack or a queue. 
                    Your choice updates a base pointer (p) to point to the correct object, which then stores the value i.

                Removing values:
                    After storing, a second loop asks which list you want to remove values from. 
                    Again, your choice dynamically selects the correct object.
*/


int main(){
    list *p;
    queue q_ob;
    stack s_ob;
    char ch;
    int i;

    for(i=0; i<10; i++) {
        std::cout << " Stack or Queue ? (S/Q): ";
        std::cin >> ch;
        ch = tolower(ch);
        if(ch == 'q') p = &q_ob ;
        else p = &s_ob ;
        p -> store(i);  
    }

    std::cout << " Enter T to terminate \n";
    // infinite loop
    for(;;){
        std::cout << " Remove from Stack or Queue ? (S/Q): ";
        std::cin >> ch;
        ch = tolower(ch);
        if(ch == 't') break;
        if(ch == 'q') p = &q_ob;
        else p = &s_ob ;
        std::cout << p-> retrieve() << '\n';
    }
    std::cout << '\n';

    return 0;
}



Difference between Stack and Queue Data Structures :

Stack: A stack is a linear data structure in which elements can be inserted and deleted only from one side of the list, called the top. 
   A stack follows the LIFO (Last In First Out) principle, i.e., the element inserted at the last is the first element to come out. 
   The insertion of an element into stack is called push operation, and deletion of an element from the stack is called pop operation. 
   In stack we always keep track of the last element present in the list with a pointer called top.    Queue: A queue is a linear data structure in which elements can be inserted only from one side of the list called rear, and the elements can be deleted only from the other side called the front.

   The queue follows the FIFO (First In First Out) principle, i.e. the element inserted at first in the list, is the first element to be removed from the list. 
   The insertion of an element in a queue is called an enqueue operation and the deletion of an element is called a dequeue operation. 
   In queue we always maintain two pointers, one pointing to the element which was inserted at the first and still present in the list with the front pointer and the second pointer pointing to the element inserted at the last with the rear pointer.

*/  






/* Example 1: Here is a program that illustrates "one interface, multiple methods." It defines an abstract
list class for integer values. The interface to the list is defined by the pure virtual functions
store() and retrieve(). To store a value, call retrieve(. The base class list does not
define any default methods for these actions. Instead, each derived class defines exactly
what type of list will be maintained. In the program, two types of lists are implemented: a
queue and a stack. Although the two lists operate completely differently, each is accessed
using the same interface. You should study this program carefully.
*/

// Demonstrate virtual functions .
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
list *p;
// demonstrate queue
queue q_ob ;
p = & q_ob ; // point to queue
p-> store (1) ;
p-> store (2) ;
p-> store (3) ;
cout << " Queue : ";
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << ’\n’;
// demonstrate stack
stack s_ob ;
p = & s_ob ; // point to stack
p-> store (1) ;
p-> store (2) ;
p-> store (3) ;
cout << " Stack : ";
cout << p-> retrieve ();
cout << p-> retrieve ();

cout << p-> retrieve ();
cout << ’\n’;
return 0;
}



/* Example 2: The main() function in the list program just shown simply illustrates that the list classes
do, indeed, work. However, to begin to see why run-time polymorphism is so powerful,
try using this main() instead: */


int main ()
{






cout << p-> retrieve () << ’\n’;
}
cout << ’\n’;
return 0;
}
This main() illustrates how random events that occur at run time can be easily handled
by using virtual functions and run-time polymorphism. The program executes a for loop

running from 0 to 9. Each iteration through the loop, you are asked to choose into which
type of list-stack or the queue-you want to put a value. According to your answer, the
base pointer p is set to point to the correct object and the current value of i is stored.
Once the loop is finished, another loop begins that prompts you to indicate you to indicate
from which list to remove a value. Once again, it is your response that determines which
list is selected.
While this example is trivial, you should be able to see how run-time to polymorphism
can simplify a program that must respond to random events. For instance, the Windows
operating system interfaces to a program by sending it messages. As far as the program
is concerned, these messages are generated at random, and you r program must respond
to each one as it is received. One way to respond to these messages is through the use of
virtual functions.


EXERCISES
1. Add another type of list to the program in Example 1. Have this version maintain a sorted
list (in ascending order). Call this list sorted.
2. On you r own, think about ways in which you can apply run-time polymorphism to simplify
the solutions to certain types of problems.

1. // Demonstrate virtual functions .
# include <iostream >
# include <cstdlib >

using namespace std ;


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


// Create a sorted list .
class sorted : public list
{
public :
void store ( int i);
int retrieve ();
};


void sorted :: store ( int i)
{
list * item ;
list *p, *p2;
item = new sorted ;
if (! item )
{
cout << " Allocation error .\n";
exit (1) ;
}
item ->num = i;
// find where to put next item
p = head ;
p2 = NULL ;
while (p) // goes in middle
{
if(p->num > i)
{
item -> next = p;
if(p2)
p2 -> next = item ; // not 1st element
if(p== head )
head = item ; // new first element
break ;
}
p2 = p;
p = p-> next ;
}
if (!p) // goes on end
{
if( tail )
tail -> next = item ;
tail = item ;
item -> next = NULL ;
}
if (! head ) // is first element
head = item ;
}


int sorted :: retrieve ()
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
list *p;
// demonstrate queue
queue q_ob ;
p = & q_ob ; // point to queue
p-> store (1) ;
p-> store (2) ;
p-> store (3) ;
cout << " Queue : ";
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << ’\n’;
// demonstrate stack
stack s_ob ;
p = & s_ob ; // point to stack
p-> store (1) ;
p-> store (2) ;
p-> store (3) ;
cout << " Stack : ";
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << ’\n’;
// demonstrate sorted list
sorted sorted_ob ;
p = & sorted_ob ;
p-> store (4) ;
p-> store (1) ;
p-> store (3) ;
p-> store (9) ;

p-> store (5) ;
cout << " Sorted : ";
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << p-> retrieve ();
cout << ’\n’;
return 0;
}
