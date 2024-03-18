
/*  ------------    Assigning Objects    ------------
    One object can be 'assigned to another object':
        both objects need to be the same type (similar to structure). 
 
    When one object is assigned to another, a "BITWISE COPY" of all the data members is made.

    Important fact:
        C++ is different in this case from Java, JavaScript & Python

        In C++, when you assign one object to another, a 'MEMBERWISE COPY' is made by default. 
            i.e. each data member of the SOURCE OBJECT is copied to the corresponding data member of the destination object. 
                For 'built-in' types, this copy operation is essentially a "bitwise copy". 
                For 'user-defined' types, the copy operation may involve calling the 'copy constructor' or "assignment operator", 
                    depending on how they are implemented.
            
            All data members of one object are copied to another "including compound data" such as ARRAYS.                    


        In Java / JavaScript / Python, on the other hand, when you assign one object reference to another, 
            you are "copying the REFERENCE", not the object itself. 
            Both the 'original' and the 'copied reference' point to the "same object" in MEMORY. 
            i.e. modifications made to the properties of one object will affect the other object 
                if they are referring to the same underlying data.

            To create a copy of an object with its 'own separate memory space' in Java/JavaScript/Python, 
                you typically need to perform a deep copy manually.

        Java:
            To create a deep copy of an object in Java, implement the 'Cloneable' interface and overriding the clone() method,
                This involves creating a new instance of the object and copying the state of all its fields to the new instance.  
            Alternatively use serialization/deserialization techniques.

        JavaScript:
            iterate through its properties and creating 'new copies of nested objects' recursively. 
            Alternatively, use built-in methods such as: 
                spread syntax ({...obj}) or Object.assign() to create shallow copies, 
            or you can use external libraries like lodash for deep copying.

        Python:
            Use the copy() method or the 'copy module' for shallow copies, 
            Or the deepcopy() function from the 'copy module' for deep copies. 
            These functions create new objects with their own memory space, recursively copying all nested objects.
*/




/* Example 1: The contents of object called 'obj_1' is assigned to another object called 'obj_2', 
                the contents of all of obj_1's data are copied into the equivalent members of obj_2.
*/

#include <iostream>

class myclass {
        int a, b;
    public:
        void set(int i, int j) {a = i; b = j; }
        void show() {std::cout << a << ' ' << b << "\n";}
};


int main(){	
    myclass obj_1 , obj_2;

    obj_1.set(10 , 4);
    
    // assign obj_1 to obj_2 
    obj_2 = obj_1;
    obj_1.show();
    obj_2.show();   // obj_2 has copied members from obj_1
    return 0;
}




/*  obj_1's member variables a and b set to the values 10 and 4, respectively. 
    Next, obj_1 is assigned to obj_2. 
        This causes the current value of obj_1.a to be assigned to obj_2.a and  obj_1.b to be assigned to obj_2.b. 

    An assignment between two objects simply makes the data in those objects identical. 
        The two objects are still completely separate, 
        For example, after the assignment, calling obj_1.set() to set the value of obj_1.a has no effect on obj_2 or its a value.

    Remember: 
        For Java / JavaScript / Python this is not true.

    Restrictions: 
        same type: Only objects of the 'same type' can be used in an assignment statement. 
            If the objects are not of the same type, a "COMPILE-TIME ERROR" is reported. 
            It is not sufficient that the types just be physically similar-their type names must be the same. 
*/




/* Example 2: It is not sufficient that the types of the objects just be physically similar - their 'type names' must be the same.

                In following example, the class 'yourclass' is similar to 'myclass' 
                    but uses a different class name: 'yourclass' and thus appears as a different type to the compiler
                Hence a "COMPILE-TIME ERROR" is reported
*/

// This program has an error: object's "type name" must be the same
#include <iostream>

class myclass{
        int a, b;
    public:
        void set(int i, int j) {a = i; b = j; }
        void show() {std::cout << a << ' ' << b << "\n";}
};

// 2nd class, similar to 'myclass', but different type name 'yourclass'
class yourclass {
        int a, b;
    public:
        void set(int i, int j) {a = i; b = j; }
        void show() {std::cout << a << ' ' << b << "\n";}
}; 


int main(){	
    myclass obj_1; 
    yourclass obj_2;

    obj_1.set(10 , 4);  // assigning values to obj_1

    // assign obj_1 to obj_2 
    obj_2 = obj_1; 	// compile-time error will occur: not same type
    obj_1.show();	 
    obj_2.show();

    return 0;
}


/*  In this case, even though 'myclass' and 'yourclass' are physically the same, 
        because they have different type names, they are treated as differing types by the compiler. 
*/




/* Example 3: All data including COMPOUND DATA such as arrays are copied to another object.
                In the following version of the 'STACK example', only s1 has any characters actually pushed onto it.
                However, because of the assignment, s2's "stck" array will also contain the characters a, b, and c.
*/
#include <iostream>

#define SIZE 10

// Declare a stack class for characters .
class stack {
        char stck[ SIZE];   // holds the stack
        int tos;            // index of top of stack
    
    public:
        stack();            // constructor. Notice no 'void init();' required
        void push(char ch); // push character on stack
        char pop();         // pop character from stack
};


// -=-=-=-=-=-    implementing member function    -=-=-=-=-=-

// stack(): Initialize the stack. No 'void init();' required
    // implementing constructor function
stack::stack(){
    std::cout << " Constructing a stack \n";
    tos = 0;
}

// push(): Push a character
void stack::push(char ch){
    if(tos == SIZE){
        std::cout << " Stack is full \n";
        return;
    }
    stck[tos] = ch;
    tos++;
}

// pop(): Pop or remove a character
char stack::pop(){
    if(tos == 0){
        std::cout << " Stack is empty \n";
        return 0; // return null on empty stack
    }
    tos--;
    return stck[tos];
}


// -=-=-  main function  -=-=-
int main(){
    stack s1, s2; // create two stacks that are automatically initialized.
    int i;

    s1.push('a');
    s1.push('b');
    s1.push('c');

    // clone s1
    s2 = s1; // now s1 and s2 are identical

    for(i =0; i<3; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i =0; i<3; i ++) std::cout << " Pop s2: " << s2.pop() << "\n";

    return 0;
}









// ------------    rev[18-mar-24]    ------------
/* 3. You must exercise some care when assigning one object to another. 
For example, here is the "strtype class" developed in "ch10_01_3_constructor_param.cpp, [Example 4]", along with a short main(). 
See if you can find an error in this program. */


#include <iostream>
#include <cstring>
#include <cstdlib>

// #define SIZE 25      'no need'

// class definition
class strtype{
        char *p;
        int len;
    public:
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        // void set(char *ptr);     'no need'
        void show();
};

// constructor: Initialize a string object with parameter.
strtype::strtype(char * ptr){
    len = strlen(ptr);  // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    if(!p){ // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 

    strcpy(p, ptr); // copy string to p

    // -- old code --
    // *p = '\0';
    // len = 0;
}

// destructor: Free memory when destroying string object .
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}


/* -- old code --   'no need'
void strtype::set(char *ptr){
    if(strlen(p) >= SIZE){
        std::cout << " String too big \n";
        return;
    }
    strcpy(p, ptr);
    len = strlen(p);
} 
*/


void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


// In this version of strtype, a string is given an initial value using the constructor function.
int main(){
    // strtype s1 , s2;
    // initialize with string, as parameters
    strtype s1(" This is a test ."), s2("I like C++. ");

    // s1.set("This is a test.");   'no need'
    // s2.set("I like C ++.");      'no need'
    s1.show();
    s2.show();

    return 0;
}





# include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
int len ;
public :
strtype ( char * ptr );
~ strtype ();
void show ();
};
strtype :: strtype ( char *ptr )
{
len = strlen ( ptr );
p = ( char *) malloc (len +1);
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
}
strtype ::~ strtype ()
{
cout << " Freeing p\n";
free (p);
}
void strtype :: show ()
{
cout << p << " - length : " << len ;
cout << "\n";
}
int main ()
{
strtype s1(" This is a test ."), s2("I like C++. ");
68A CLOSER LOOK AT CLASSES
3.1. ASSIGNING OBJECTS
s1. show ();
s2. show ();
// assign s1 to s2 - - this generates an error
s2 = s1;
s1. show ();
s2. show ();
return 0;
}
The trouble with this program is quite insidious. When s1 and s2 are created, both
allocate memory to hold their respective strings. A pointer to each object’s allocated
memory is stored in p. When a strtype object is destroyed, this memory is released.
However, when s1 is assigned to s2, s2’s p now points to the same memory as s1’s p.
Thus, when these objects are destroyed, the memory pointed to by s2’s p is freed twice
and the memory originally pointed to by s2’s p is not freed at all.
While benign in this context, this sort of problem occurring in a real program will cause
the dynamic allocation system to fail, and possibly even cause a program crash. As you
can see from the preceding example, when assigning one object to another, you must make
sure you are not destroying information that may be needed later.
EXERCISES
1. What is wrong with the following program?
// This program has an error .
# include <iostream >
using namespace std ;
class cl1
{
int i, j;
public :
cl1 ( int a, int b) { i = a; j = b; }
// ...
};
class cl2
{
int i, j;
public :
cl2 ( int a, int b) { i = a; j = b; }
// ...
};
int main ()
{
cl1 x(10 , 20) ;
cl2 y(0, 0);
x = y;
69TEACH YOURSELF
C++
// ...
}
2. Using the queue class that you created for Chapter 2, Section 2.1, Exercise 1, show how
one queue can be assigned to another.
3. If the queue class from the preceding question dynamically allocates memory to hold the
queue, why, in this situation, can one queue not be assigned to another?
