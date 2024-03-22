
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





// ------------------    make sure you are "not destroying information" that may be needed LATER    ------------------

/* Example 4: You must exercise some CARE when assigning one object to another. 
                For example, here is the "strtype class" developed in 
                "ch10_01_3_constructor_param.cpp, [Example 4]" parameterized constructor, along with a short main(). 

                See if you can find an error in this program.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

// class definition
class strtype{
        char *p;
        int len;
    public:
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        void show();
};

// constructor: Initialize a string object with parameter.
strtype::strtype(char * ptr){
    len = strlen(ptr);      // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    if(!p){     // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 
    strcpy(p, ptr);     // copy string to p
}

// destructor: Free memory when destroying string object .
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}

void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


int main(){
    // initialize with string, as parameters
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();
    // assign s1 to s2 -- this generates an ERROR
    s2 = s1;
    s1.show();
    s2.show();

    return 0;
}

/*  When s1 and s2 are created, both allocate memory to hold their respective strings. 

    A pointer to each object's allocated memory is stored in p.
        When a strtype object is destroyed, this memory is released.

    However, when s1 is assigned to s2, s2's p now points to the "same memory" as s1's p.

    Thus, when these objects are destroyed, the memory pointed to by s2's p is freed TWICE
        and the memory originally pointed to by s2's p is not freed at all.

    This sort of problem occurring in a real program will cause
        the "DYNAMIC ALLOCATION system" to fail, 
        and possibly even cause a program crash. 


    NOTE:
        When assigning one object to another, 
        you must make sure you are "not destroying information" that may be needed LATER.
*/


// ChatGPT's solution:
/*  The problem with the given code is that it doesn't implement a proper assignment operator ("operator=") for the 'strtype' class. 

    When you assign one 'strtype' object to another ('s2 = s1'), 
        the default ASSIGNMENT operator provided by the COMPILER is used, which performs a shallow copy. 
        
    This means that it copies the pointer 'p' from 's1' to 's2', 
        resulting in both 's1' and 's2' pointing to the "same dynamically allocated memory". 
        
    When the destructor of "s2" is called at the end of 'main()', it frees the memory pointed to by 'p'. 
        Then, when the destructor of 's1' is called, it attempts to free the "same memory" again, resulting in a "double-free error".

    To fix this issue, you need to implement a proper assignment operator for the 'strtype' class that performs a "deep copy", 
        copying the contents of the dynamically allocated memory pointed to by 'p' from the SOURCE object to the DESTINATION object. 
        Here's how you can do it:
 */

// Operator overloading 
// Definition of Assignment operator: Performs a "DEEP COPY" of the source object to the destination object.
strtype& strtype::operator=(const strtype& other) {
    if (this != &other) { // Check for self-assignment
        // Free the existing memory
        free(p);
        // Allocate new memory for the destination object
        len = other.len;
        p = (char *)malloc(len + 1);
        if (!p) {
            std::cout << "Allocation error\n";
            exit(1);
        }
        // Copy the contents from the source object to the destination object
        strcpy(p, other.p);
    }
    return *this;
}

/* 
    With this assignment operator implemented, when you assign one `strtype` object to another (`s2 = s1`), 
        a deep copy is performed, and each object has its 'own dynamically allocated memory'. 

    Therefore, when the destructors of `s1` and `s2` are called at the end of `main()`, 
        each destructor frees its own memory without causing a double-free error.
*/

// ------------    Corrected code    ------------
#include <iostream>
#include <cstring>
#include <cstdlib>

// class definition
class strtype{
    char *p;
    int len;
public:
    strtype(char *ptr);  // constructor
    ~strtype(); // destructor
    void show();
    strtype& operator=(const strtype& other); // assignment operator
};

// constructor: Initialize a string object with parameter.
strtype::strtype(char * ptr){
    len = strlen(ptr);      // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    if(!p){     // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 
    strcpy(p, ptr);     // copy string to p
}

// destructor: Free memory when destroying string object .
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}

// Assignment operator: Performs a deep copy of the source object to the destination object.
strtype& strtype::operator=(const strtype& other) {
    if (this != &other) { // Check for self-assignment
        // Free the existing memory
        free(p);
        // Allocate new memory for the destination object
        len = other.len;
        p = (char *)malloc(len + 1);
        if (!p) {
            std::cout << "Allocation error\n";
            exit(1);
        }
        // Copy the contents from the source object to the destination object
        strcpy(p, other.p);
    }
    return *this;
}

void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}

int main(){
    // initialize with string, as parameters
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();
    // assign s1 to s2 -- this generates an ERROR
    s2 = s1;
    s1.show();
    s2.show();

    return 0;
}


/* Notice how Declaration & Definition done:
        strtype& operator=(const strtype& other)       // used for Declaration
        strtype& strtype::operator=(const strtype& other) {}    // used for Definition
*/




// ------------    rev[21-mar-24]    ------------
/* Example 5: What is wrong with the following program? */
// This program has an error.

#include <iostream>

class cl1{
        int i, j;
    public:
        cl1(int a, int b) {i = a; j = b;}
        // ...
};

class cl2{
        int i, j;
    public:
        cl2(int a, int b) {i = a; j = b;}
        // ...
};

int main(){
    cl1 x(10, 20);
    cl2 y(0, 0);

    // being physically similar won't work - their 'type names' must be the same.
    x = y;  // ERR: 

    // ...
}

/*  Ans:
    The assignment statement x = y is wrong because cl1 and cl2 are two different types of classes, 
        and objects of differing class types cannot be assigned
*/




/* Example 6: Using the queue class that you created for "ch10_01_2_constructor_destructor.cpp"
                (constructor with no parameters), show how one queue can be assigned to another. 
*/
#include <iostream>

#define SIZE 100

class q_type{
    int queue[SIZE];    // holds the queue
    int head, tail ;    // indices of head and tail

    public:
        // void init();    // initialize. 'OLD code'
        q_type();      // constructor: auto initialization
        void q(int num);    // store
        int deq();          // retrieve
};

// Constructor
q_type::q_type(){
        head = tail = 0;
} 

// Put value on the queue .
void q_type::q(int num){
    if((tail+1 == head )|| ( (tail+1== SIZE) && (!head) )){
        // no dequeue case: "((tail+1== SIZE) && (!head))" checks 'head = 0' and 'tail = SIZE-1'
        // dequeue case: because of "cycle around"  'tail' is one-less than 'head'
            // thats why we used '(tail+1 == head )'
        std::cout << " Queue is full \n";
        return;
    }

    tail++;

    if(tail == SIZE) tail = 0; // cycle around
    queue[tail] = num ;
}

// Remove a value from a queue.
int q_type::deq(){
    if(head == tail){
        std::cout << " Queue is empty \n";
        return 0; // or some other error indicator
    }

    head++;

    if(head == SIZE) head = 0; // cycle around
    return queue[head];
}


// New code / Test
int main(){
    q_type q1, q2;
    int i;

    for(i=1; i<=10; i++) q1.q(i);

    // assign one queue to another
    q2 = q1;

    // show that both have the same contents
    for(i =1; i<=10; i++) std::cout << " Dequeue 1: " << q1.deq() << "\n";
    for(i =1; i<=10; i++) std::cout << " Dequeue 2: " << q2.deq() << "\n";

    return 0;
}




/* Example 7: If the queue class from the preceding question dynamically allocates memory to hold the
                queue, why, in this situation, can one queue not be assigned to another? 

                If memory to hold a queue is 'dynamically allocated', assigning one queue to another causes
                    the dynamic memory allocated to the queue on the "left side" of the assignment statement to be LOST and
                    the memory allocated to the queue on the "right side" to be FREED TWICE when the objects are destroyed. 

                Either of these two conditions is an unacceptable ERROR.
*/


