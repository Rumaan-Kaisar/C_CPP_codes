
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

   There are two terms that are often linked to OOP in general and to C++ specifically. They are early binding and late binding. 
   Early binding: Early binding essentially refers to those events that can be known at compile time. Specifically, it refers to those function calls that can be resolved during compilation. Early bound entities include:
[1] "Normal" functions,     [2] Overloaded functions,   [3] Non-virtual member  [4] Friend functions.

   When these types of functions are compiled, all address information necessary to call them is known at compile time. 
   Calls to functions bound at compile time are the fastest types of function calls. Main disadvantage is lack of flexibility.
   Late binding: Late binding refers to events that must occur at run time. A late bound function call is one in which the address of the function to be called is not known until the program runs. 
   In C++, a virtual function is a late bound object.  When a VF is accessed via a base class pointer, the program must determine at run time what type of object is being pointed to and then select which version of the overridden function to execute. 
   Advantage: Flexibility at run time.  Disadvantage: is that there Slower than early binding.


## Polymorphism, Early Binding & Late Binding

### Polymorphism

## 1. Early Binding (Compile-Time Binding)

Early binding means the function call is decided **during compilation** (compile time).

The compiler already knows which function will be called.

### Examples of Early Bound Functions

1. Normal functions
2. Overloaded functions
3. Non-virtual member functions
4. Friend functions

### Features

* Function addresses are fixed at compile time.
* Faster execution.
* Less flexible than late binding.

### Advantage

* High speed and better performance.

### Disadvantage

* Less flexibility.

---




## 2. Late Binding (Run-Time Binding)

Late binding means the function call is decided **during program execution** (run time).

The compiler does not know the exact function to call until the program runs.

### In C++

* **Virtual functions** use late binding.
* When a virtual function is called through a base class pointer, C++ checks the actual object type at run time and then calls the correct overridden function.

### Features

* Function selection happens at run time.
* More flexible than early binding.
* Slightly slower.

### Advantage

* Greater flexibility and runtime decision-making.

### Disadvantage

* Slower than early binding.

---

## Short Comparison Table

| Feature        | Early Binding                   | Late Binding      |
| -------------- | ------------------------------- | ----------------- |
| Decision Time  | Compile time                    | Run time          |
| Functions Used | Normal, overloaded, non-virtual | Virtual functions |
| Speed          | Faster                          | Slower            |
| Flexibility    | Less flexible                   | More flexible     |
| Also Called    | Static binding                  | Dynamic binding   |







Polymorphism, Early Binding & Late Binding
Polymorphism

Polymorphism is an OOP concept where one interface can be used for many different actions.
It follows the idea of “one interface, multiple methods.”

This means the same function or method name can behave differently depending on the object or situation, reducing complexity and improving flexibility.

Early Binding and Late Binding
1. Early Binding (Compile-Time Binding)

Early binding means the function call is decided during compilation (compile time).

The compiler already knows which function will be called.

Examples of Early Bound Functions
Normal functions
Overloaded functions
Non-virtual member functions
Friend functions
Features
Function addresses are fixed at compile time.
Faster execution.
Less flexible than late binding.
Advantage
High speed and better performance.
Disadvantage
Less flexibility.
2. Late Binding (Run-Time Binding)

Late binding means the function call is decided during program execution (run time).

The compiler does not know the exact function to call until the program runs.

In C++
Virtual functions use late binding.
When a virtual function is called through a base class pointer, C++ checks the actual object type at run time and then calls the correct overridden function.
Features
Function selection happens at run time.
More flexible than early binding.
Slightly slower.
Advantage
Greater flexibility and runtime decision-making.
Disadvantage
Slower than early binding.
Short Comparison Table
Feature	Early Binding	Late Binding
Decision Time	Compile time	Run time
Functions Used	Normal, overloaded, non-virtual	Virtual functions
Speed	Faster	Slower
Flexibility	Less flexible	More flexible
Also Called	Static binding	Dynamic binding





########################################################

so what is the difference from the "inheritance" using the idea of "Virtual functions", "pure virtual functions" and abstruct classes?

########################################################


## Difference Between Polymorphism and Inheritance

These concepts are closely related, but they are **not the same thing**.

---

# 1. Inheritance

Inheritance means **one class acquires the properties and behaviors of another class**.

It creates an **“is-a” relationship**.

### Example

```cpp
class Animal {
public:
    void eat() {
        cout << "Eating";
    }
};

class Dog : public Animal {
};
```

Here:

* `Dog` inherits from `Animal`
* Dog gets the `eat()` function automatically.

### Purpose of Inheritance

* Code reuse
* Creating relationships between classes
* Building class hierarchies

---

# 2. Polymorphism

Polymorphism means **the same function/interface behaves differently for different objects**.

### Example

```cpp
class Animal {
public:
    virtual void sound() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow";
    }
};
```

Now:

```cpp
Animal* a;

Dog d;
Cat c;

a = &d;
a->sound();   // Bark

a = &c;
a->sound();   // Meow
```

Same function:

```cpp
sound()
```

Different behavior:

* Dog → Bark
* Cat → Meow

This is **runtime polymorphism** using **virtual functions**.

---

# Role of Virtual Functions

A **virtual function** enables **late binding** (runtime polymorphism).

Without `virtual`, the base class function is called.

With `virtual`, C++ decides at runtime which overridden function to execute.

---

# Pure Virtual Function

A pure virtual function is a virtual function with **no implementation** in the base class.

Syntax:

```cpp
virtual void sound() = 0;
```

It means:

> “Every derived class MUST define this function.”

---

# Abstract Class

A class containing at least one pure virtual function is called an **abstract class**.

### Example

```cpp
class Animal {
public:
    virtual void sound() = 0;
};
```

You cannot create objects of abstract classes:

```cpp
Animal a; // ERROR
```

But derived classes can implement the function:

```cpp
class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};
```

---

# Relationship Between Them

| Concept               | Purpose                                        |
| --------------------- | ---------------------------------------------- |
| Inheritance           | Reuse and relationship between classes         |
| Virtual Function      | Enables runtime polymorphism                   |
| Pure Virtual Function | Forces derived classes to implement a function |
| Abstract Class        | Provides a common template/interface           |
| Polymorphism          | Same interface, different behaviors            |

---

# Main Idea

## Inheritance

Creates the relationship:

```text
Dog IS-A Animal
```

## Virtual Function

Allows:

```text
Animal pointer can call Dog behavior
```

## Pure Virtual Function + Abstract Class

Forces all derived classes to follow a common interface.

---

# Simple Analogy

Think of:

## Abstract Class = Blueprint

```text
Vehicle must have start()
```

## Pure Virtual Function

```text
start() has no fixed implementation
```

## Inheritance

```text
Car and Bike inherit Vehicle
```

## Polymorphism

```text
Calling start() behaves differently for Car and Bike
```


---------------------------------------


Difference Between Polymorphism and Inheritance

These concepts are closely related, but they are not the same thing.

1. Inheritance

Inheritance means one class acquires the properties and behaviors of another class.

It creates an “is-a” relationship.

Example
class Animal {
public:
    void eat() {
        cout << "Eating";
    }
};

class Dog : public Animal {
};

Here:

Dog inherits from Animal
Dog gets the eat() function automatically.
Purpose of Inheritance
Code reuse
Creating relationships between classes
Building class hierarchies
2. Polymorphism

Polymorphism means the same function/interface behaves differently for different objects.

Example
class Animal {
public:
    virtual void sound() {
        cout << "Animal sound";
    }
};

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};

class Cat : public Animal {
public:
    void sound() override {
        cout << "Meow";
    }
};

Now:

Animal* a;

Dog d;
Cat c;

a = &d;
a->sound();   // Bark

a = &c;
a->sound();   // Meow

Same function:

sound()

Different behavior:

Dog → Bark
Cat → Meow

This is runtime polymorphism using virtual functions.

Role of Virtual Functions

A virtual function enables late binding (runtime polymorphism).

Without virtual, the base class function is called.

With virtual, C++ decides at runtime which overridden function to execute.

Pure Virtual Function

A pure virtual function is a virtual function with no implementation in the base class.

Syntax:

virtual void sound() = 0;

It means:

“Every derived class MUST define this function.”

Abstract Class

A class containing at least one pure virtual function is called an abstract class.

Example
class Animal {
public:
    virtual void sound() = 0;
};

You cannot create objects of abstract classes:

Animal a; // ERROR

But derived classes can implement the function:

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};
Relationship Between Them
Concept	Purpose
Inheritance	Reuse and relationship between classes
Virtual Function	Enables runtime polymorphism
Pure Virtual Function	Forces derived classes to implement a function
Abstract Class	Provides a common template/interface
Polymorphism	Same interface, different behaviors
Main Idea
Inheritance

Creates the relationship:

Dog IS-A Animal
Virtual Function

Allows:

Animal pointer can call Dog behavior
Pure Virtual Function + Abstract Class

Forces all derived classes to follow a common interface.



Simple Analogy

Think of:

Abstract Class = Blueprint
Vehicle must have start()

Pure Virtual Function
start() has no fixed implementation

Inheritance
Car and Bike inherit Vehicle

Polymorphism
Calling start() behaves differently for Car and Bike




########################################################

So "Virtual functions", "pure virtual functions" and abstruct classes uses inheritance and polymorphisms togather?

########################################################


Yes — exactly.
**Virtual functions, pure virtual functions, and abstract classes combine both inheritance and polymorphism together.**

Here is the connection clearly:

---

# 1. Inheritance Provides the Relationship

A derived class inherits from a base class.

Example:

```cpp id="b8m3ru"
class Animal { };

class Dog : public Animal { };
```

This creates:

```text id="bbn9zk"
Dog IS-A Animal
```

So inheritance builds the class hierarchy.

---

# 2. Virtual Functions Provide Polymorphism

When a function is marked `virtual`, C++ allows different derived classes to provide different implementations.

Example:

```cpp id="8t84af"
class Animal {
public:
    virtual void sound() {
        cout << "Animal sound";
    }
};
```

Derived class:

```cpp id="ysl0c7"
class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};
```

Now:

```cpp id="wb4v5n"
Animal* a = new Dog();
a->sound();
```

Output:

```text id="7qyjz3"
Bark
```

This is runtime polymorphism.

---

# 3. Pure Virtual Functions Force a Common Interface

Example:

```cpp id="0s9hfh"
class Animal {
public:
    virtual void sound() = 0;
};
```

This means:

```text id="i7m4b5"
Every derived class MUST define sound()
```

So pure virtual functions enforce rules for derived classes.

---

# 4. Abstract Classes Act as Templates

A class with a pure virtual function becomes an abstract class.

You cannot create its object:

```cpp id="0l8av4"
Animal a; // ERROR
```

But you can use pointers/references:

```cpp id="jlwm1n"
Animal* a;
```

This allows a common interface for many derived classes.

---

# Final Big Picture

| Concept               | Role                              |
| --------------------- | --------------------------------- |
| Inheritance           | Creates parent-child relationship |
| Virtual Function      | Enables runtime polymorphism      |
| Pure Virtual Function | Forces overriding                 |
| Abstract Class        | Defines a common interface        |
| Polymorphism          | Same call, different behavior     |

---

# Short Summary

## Inheritance

Creates:

```text id="j4r4ew"
Dog IS-A Animal
```

## Virtual Function

Allows:

```text id="ekngpr"
Animal pointer → Dog behavior
```

## Pure Virtual Function

Forces:

```text id="z5k1qx"
Every animal must define sound()
```

## Abstract Class

Provides:

```text id="h9i3cn"
A common blueprint/interface
```

So yes:

```text id="4bq8zf"
Inheritance + Virtual Functions = Runtime Polymorphism
```

And:

```text id="47d1yw"
Pure Virtual Functions + Abstract Classes strengthen and organize that polymorphism.
```



---------------------------------------------------------

Yes — exactly.
Virtual functions, pure virtual functions, and abstract classes combine both inheritance and polymorphism together.

Here is the connection clearly:

1. Inheritance Provides the Relationship

A derived class inherits from a base class.

Example:

class Animal { };

class Dog : public Animal { };

This creates:

Dog IS-A Animal

So inheritance builds the class hierarchy.

2. Virtual Functions Provide Polymorphism

When a function is marked virtual, C++ allows different derived classes to provide different implementations.

Example:

class Animal {
public:
    virtual void sound() {
        cout << "Animal sound";
    }
};

Derived class:

class Dog : public Animal {
public:
    void sound() override {
        cout << "Bark";
    }
};

Now:

Animal* a = new Dog();
a->sound();

Output:

Bark

This is runtime polymorphism.

3. Pure Virtual Functions Force a Common Interface

Example:

class Animal {
public:
    virtual void sound() = 0;
};

This means:

Every derived class MUST define sound()

So pure virtual functions enforce rules for derived classes.

4. Abstract Classes Act as Templates

A class with a pure virtual function becomes an abstract class.

You cannot create its object:

Animal a; // ERROR

But you can use pointers/references:

Animal* a;

This allows a common interface for many derived classes.

Final Big Picture
Concept	Role
Inheritance	Creates parent-child relationship
Virtual Function	Enables runtime polymorphism
Pure Virtual Function	Forces overriding
Abstract Class	Defines a common interface
Polymorphism	Same call, different behavior
Short Summary
Inheritance

Creates:

Dog IS-A Animal
Virtual Function

Allows:

Animal pointer → Dog behavior
Pure Virtual Function

Forces:

Every animal must define sound()
Abstract Class

Provides:

A common blueprint/interface

So yes:

Inheritance + Virtual Functions = Runtime Polymorphism

And:

Pure Virtual Functions + Abstract Classes strengthen and organize that polymorphism.

*/







   Example 1: Here is a program that illustrates "one interface, multiple methods." It defines an abstract list class for integer values. 
   The interface to the list is defined by the PVFs store() and retrieve(). To store a value, call store(). To retrieve a value, call retrieve(). 
   The base list does not define any default methods for these actions. Instead, each derived defines exactly what type of list will be maintained.
   In the program, two types of lists are implemented: a queue and a stack. Although the two lists operate completely differently, each is accessed using the same interface. 


#include<iostream >
#include<cstdlib >
using namespace std;

class list{     public:     list *head ;        // pointer to start of list  
                list *tail ;        // pointer to end of list  
                list *next ;        // pointer to next item  

                int num ;           // value to be stored  

                list(){ head = tail = next = NULL ; }
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




   Example 2:  To see why run-time polymorphism is so powerful, try using this main() instead of previous example:
   This main() illustrates how random events that occur at run time can be easily handled by using VFs and run-time polymorphism. 
   The program executes a for loop running from 0 to 9. Each iteration through the loop, you are asked to choose into which type of list- stack or the queue-you want to put a value. According to your answer, the base pointer p is set to point to the correct object and the current value of i is stored.
   Once the loop is finished, another loop begins that prompts you to indicate you to indicate from which list to remove a value. Once again, it is your response that determines which list is selected.

int main(){     list *p;
        queue q_ob ;
        stack s_ob ;
        char ch;
        int i;

    for(i=0; i <10; i++) {
        cout << " Stack or Queue ? (S/Q): ";
        cin >> ch;
        ch = tolower(ch);
        if(ch == 'q') p = &q_ob ;
        else p = &s_ob ;
        p -> store(i);  }   cout << " Enter T to terminate \n";

for(;;){  cout << " Remove from Stack or Queue ? (S/Q): ";
        cin >> ch;
        ch = tolower(ch);
        if(ch == 't') break ;
        if(ch == 'q') p = &q_ob ;
        else p = &s_ob ;
        cout << p-> retrieve() << '\n';   }
        cout << '\n';
return 0;}



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
list *p;
queue q_ob ;
stack s_ob ;
char ch;
int i;
for (i =0; i <10; i ++)
{
cout << " Stack or Queue ? (S/Q): ";
cin >> ch;
ch = tolower (ch);
if(ch == ’q’)
p = & q_ob ;
else
p = & s_ob ;
p-> store (i);
}
cout << " Enter T to terminate \n";
for (;;)
{
cout << " Remove from Stack or Queue ? (S/Q): ";
cin >> ch;
ch = tolower (ch);
if(ch == ’t’)
break ;
if(ch == ’q’)
p = & q_ob ;
else
p = & s_ob ;
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

