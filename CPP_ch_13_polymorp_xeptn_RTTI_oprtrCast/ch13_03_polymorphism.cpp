
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


// Create a derived class "queue" - type "list".
class queue : public list {
    public :
        void store(int i);
        int retrieve();
};


// Create a derived class "stack" - type "list" .
class stack : public list {
    public :
        void store(int i);
        int retrieve();
};


// -------- queue's versions of "store" and "retrieve"  --------

void queue :: store(int i){ 
    // It adds a new item to the end of the queue (FIFO: First In, First Out).
    
    list *item;         // A pointer item is created. It will point to a new node in the list.
    item = new queue;   // Memory is allocated for a new object. This new object acts as a node in the "queue"

    // Checks if memory allocation fails
    if(!item ){
        std::cout << " Allocation error .\n";
        exit(1);
    }
    
    // Note: item, head, tail, next are "pointers" of type "list"

    item->num = i;      // Stores the given value i inside the new node.
    
    // put on end of list 
    if(tail) tail->next = item;     // If the queue already has elements: The current last node (tail) is linked to the new node.
    tail = item;    // Updates tail to point to the new node. Now this new node is the last element of the queue.
    item -> next = NULL;    // Since it's the last node, it doesn’t point to anything after it.

    // initializes the queue properly.
    if(!head) head = tail;  // If the queue was empty before: Both head and tail will point to this new node.
}


int queue :: retrieve(){
    // Opposite of store(). It defines how a queue removes and returns a value—always from the front (FIFO behavior).
    // Takes the first element from the queue
    // Removes it from the list
    // Returns its value

    int i;      // i will store the value being removed
    list *p;    // p is a temporary pointer used to safely delete a node

    // Checks if the queue is empty (head == NULL)
    if(!head){
        std::cout << " List empty.\n ";
        return 0; 
    }

    // remove from start of list 
    i = head -> num;    // Gets the value from the first node. This is the value that will be returned
    p = head;   // Saves the current first node in p (because we’re about to move head)
    head = head -> next;    // Moves "head" to the next node
    delete p;   // Frees the memory of the old first node
    return i;   // Returns the value that was stored in the removed node
}


// -------- stack's own versions of "store" and "retrieve"  --------

void stack :: store(int i){ 
    // It adds a new item to the top of the stack (LIFO: Last In, First Out).

    list *item;     // A pointer 'item' is created. It will point to a new node.
    item = new stack;   // Memory is allocated for a new object (node in the stack).

    // Checks if memory allocation fails
    if(!item){  
        std::cout << " Allocation error.\n";
        exit(1); 
    }

    // Note: item, head, tail, next are pointers of type "list"

    item->num = i;  // Stores the given value i inside the new node.

    // put on front of list for stack-like operation
    if(head) item->next = head;  
    // If stack already has elements:
    // The new node points to the current top (head)

    head = item;    
    // Updates head to point to the new node.
    // Now this new node becomes the top of the stack.

    // initializes the stack properly
    if(!tail) tail = head;  
    // If the stack was empty before:
    // Both head and tail point to this new node.
}


int stack :: retrieve(){    
    // Opposite of store(). Defines how a stack removes and returns a value.
    // Always removes from the top (LIFO behavior).
    // Takes the top element
    // Removes it from the list
    // Returns its value

    int i;      // i will store the value being removed
    list *p;    // p is a temporary pointer used to safely delete a node

    // Checks if the stack is empty (head == NULL)
    if(!head){  
        std::cout << " List empty .\n";
        return 0; 
    }

    // remove from start of list (top of stack)
    i = head->num;    // Gets the value from the top node
    p = head;         // Saves the current top node
    head = head->next;    // Moves head to the next node (new top)
    delete p;         // Frees memory of the old top node

    return i;         // Returns the value that was removed
}

/*  If you compare this with above queue version, the key difference is just 
        where insertion happens:

            Queue --> insert at end, remove from front
            Stack --> insert at front, remove from front

        That single change is what flips FIFO into LIFO. 
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

/* main():
    The important idea here isn’t just stack vs queue — it’s "runtime polymorphism":

    list *p;    is a base class pointer

    It points to:

        a "queue" object --> behaves like FIFO
        a "stack" object --> behaves like LIFO

    Calls like "p->store()" and "p->retrieve()" are resolved "at runtime" via "virtual" functions

    So the same code:
                        p->store(...);
                        p->retrieve();

        produces "different behavior depending on the object type"

    Output:

        Queue: 123
        Stack: 321
*/


// --------  rev[25-May-2026]  --------



/* Example 3: The Power of Run-Time Polymorphism

                Following updated main() function shows how random events that occur at run time 
                    can be easily handled by using "Virtual Functions" and run-time polymorphism.

                Storing values:
                    A FOR-loop runs from 0 to 9. For each number, you choose whether to add it to a stack or a queue. 
                    Your choice updates a base pointer "p" to point to the correct object, which then stores the value i.

                Removing values:
                    After storing, a second loop asks which list you want to remove values from. 
                    Again, your choice dynamically selects the correct object.
*/

int main(){
    list *p;    // Base class pointer.
                // Will point either to a queue object or a stack object,
                // demonstrating runtime polymorphism.

    queue q_ob; // Queue object (FIFO behavior)
    stack s_ob; // Stack object (LIFO behavior)
    char ch;    // Stores user's choice: 's' for stack, 'q' for queue, 't' to terminate
    int i;

    // -------- Store values --------
    for(i = 0; i < 10; i++) {

        std::cout << "Stack or Queue ? (S/Q): ";
        std::cin >> ch;

        // Convert input to lowercase so that both uppercase and lowercase letters work.
        ch = tolower(ch);

        // If user chooses queue, base pointer points to queue object.
            // Otherwise use stack object.
        if(ch == 'q') p = &q_ob;
        else p = &s_ob;
        
        // Store current value of i.
        p->store(i);
        // Because store() is virtual:
            // queue::store() is called for queues
            // stack::store() is called for stacks
    }

    std::cout << "Enter T to terminate\n";

    // -------- Retrieve values --------
    // Infinite loop; exits only when user enters 't'
    for(;;){

        std::cout << "Remove from Stack or Queue ? (S/Q): ";
        std::cin >> ch;

        ch = tolower(ch);
        // Make input case-insensitive.

        if(ch == 't') break;        // Terminate retrieval loop.
        if(ch == 'q') p = &q_ob;    // Retrieve from queue.
        else p = &s_ob;             // Retrieve from stack.

        // Calls either:
            // queue::retrieve()  --> FIFO removal
            // stack::retrieve()  --> LIFO removal
        std::cout << p->retrieve() << '\n';     // The returned value is displayed.
    }

    std::cout << '\n';

    return 0;
}

/*  This main() demonstrates how runtime polymorphism allows one pointer (p) 
        to work with different objects and automatically invoke the appropriate function, 
        making programs more flexible and easier to manage.


    The example is simple, but it shows the idea of runtime polymorphism.
        The program uses one base-class pointer (p) to work with both a queue and a stack.

    The user's choices are not known in advance.
        During execution, the user can choose whether to store or retrieve data from a stack or a queue.
        These choices occur at runtime, similar to random events in real programs.

    The same base-class pointer p can refer to different objects.
        If the user enters 'q', p points to the queue object (q_ob).
        Otherwise, p points to the stack object (s_ob).

    Virtual functions select the correct function automatically.
        p->store(i) calls either queue::store() or stack::store().
        p->retrieve() calls either queue::retrieve() or stack::retrieve().
        Because store() and retrieve() are VFs,
            The correct version (queue or stack) is chosen while the program is running.
            (making runtime polymorphism).

    This reduces the need for separate code.
        The program does not need different function calls for stacks and queues.
        The same interface (store() and retrieve()) works for both.

    The same concept is used in larger applications.
        Operating systems such as Windows send different messages or events to programs.
        Since these events can occur unpredictably, the program must respond at runtime.
        Virtual functions provide a convenient way to handle different actions through a common interface.
*/




/*  ----------------    Stack and Queue Data Structures    ----------------
    Stack: 
        A stack is a linear data structure in which 
        elements can be inserted and deleted only from one side of the list, called the top. 

        A stack follows the LIFO (Last In First Out) principle, 
            i.e., the element inserted at the last is the first element to come out. 

        The insertion of an element into stack is called "push" operation, and 
            deletion of an element from the stack is called "pop" operation. 

        In stack we always "keep track of the last element" present in the list with a pointer called top.
        

    Queue:
        A queue is a linear data structure in which 
            elements can be inserted only from one side of the list called "rear", and 
            the elements can be deleted only from the other side called the "front".

        The queue follows the FIFO (First In First Out) principle, 
            i.e. the element inserted at first in the list, is the first element to be removed from the list. 

        The "insertion" of an element in a queue is called an "enqueue" operation and 
            the "deletion" of an element is called a "dequeue" operation. 

        In queue we always maintain "two pointers", 
            one pointing to the element which was inserted at the first 
                and still present in the list with the front pointer and 
            the second pointer pointing to the element inserted at the last with the rear pointer.
*/




/* Example 4: Add another type of list to the program in Example 2. 
                Have this version maintain a sorted list (in ascending order). 
                Call this list "sorted".
*/

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

