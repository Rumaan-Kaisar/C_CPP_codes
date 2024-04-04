
/* ----------------------     CLASS intro     ---------------------- 
    Class is the core feature of C++ and OOP.
    The class is the mechanism that is used to create 'objects'. 

    A class is declared using the 'class' keyword. 
        The syntax of a class declaration is similar to that of a 'structure' 
        (actually class is a kind of "structure" with more feature). 
*/

// General form:
class class_name {
    // private functions and variables
    public :
        // public functions and variables
} object_list;



/* 
    Ways of class Declaration:
        In a class declaration, the 'object-list' and 'class_name' are optional. (Similar to structure)

        From a practical point of view 'class_name' is virtually always needed. 
            the 'class_nam'e acts like a DATA-TYPE name that is used to declare 'objects of the class'.



    Private and public members : 
        'Functions' and 'variables' declared inside a class declaration are said to be 'members' of that class.

        private by default: 
            By default, all functions and variables declared inside a class are private to that class. 
            they are accessible, only by other 'members of that class'. 

        public: 
            To declare public class members, the 'public' keyword is used, followed by a 'colon : '. 
            All functions and variables declared 'after the public specifier' are accessible both by 
                other members of the class and by any other part of the program that contains the class. 
*/


// Here is a simple class declaration: 
class myclass{
    // (default) private to myclass 
    int a;

    public:
        void set_a(int num );	// prototype 
        int get_a();		// prototype 
};

/* 
    Above class has one private variable, called 'a', and 
        two public functions, set_a() and get_a(). 

        Since 'a' is private, it is not accessible by any code outside "myclass". 
        since 'set_a()' and 'get_a()' are members of myclass, they can directly access  'a'.
        
        Further, 'set_a()' and 'get_a()' are declared as 'public members of myclass' and 
            can be called by any other part of the program that contains myclass.



    member functions:
        Functions that are declared to be part of a class are called "member functions". 
        Notice that set_a(int num ); and int get_a(); are 'function prototype' declaration inside the class.



    Defining the member functions: 
        Although the prototypes of the functions 'set_a()' and 'get_a()' are declared by myclass, they are 'not yet defined'.
        To define a member function, you must "LINK" the 'type_name of the class' with the name of the function. 
        You do this by preceding the function name with the class name followed by two colons '::' . 
            The two colons are called the "SCOPE RESOLUTION OPERATOR". 
*/


// --------    Defining the member functions of a CLASS    --------

ret_type class_name :: func_name(parameter_list) {
    // body of function
}

// class_name: is the name of the class to which the function belongs 
// ret_type: is the return type of the function which must be the 'same return type of the prototype' declared inside the class.




/* Example 1: For example, here member functions set_a() and get_a() are defined: */
void myclass :: set_a(int num) {
    	a = num;	
}

int myclass :: get_a() {
     	return a;	
}




/* --------    object of a class    --------
    Crating object of a class : 
        This is similar to declaring a 'structure variable' in C. 
            Since 'class is similar to structure' and "object is similar to variable". 
        
        The 'declaration of a class' did not define any objects of type of that class 
            - it only defines the type of object that will be created when one is actually declared. 
    
    
        To create an object, use the 'class_name' as a "type specifier" :

                class_name object_name1, object_name2, . . . , object_nameN; 
*/




/* Example 2: For example, this line declares two objects of type myclass: */
myclass ob1 , ob2; 		// these are objects of type myclass 



/* 
    // ----    CLASS & its OBJECT    ----
    A 'class declaration' is a "Logical ABSTRACTION" that defines a NEW TYPE. 
        It determines what an 'object of that type' will look like.

    An 'object declaration' creates a "Physical ENTITY" of that type. 
        i.e. an object occupies "memory space", but a type definition does not.



    // ----    local & global OBJECT    ----
    Like variables, there is 'local objects' and 'global objects'.



    // ----    accessing object members    ----
    Accessing members of an object: 
        your program can reference an objects "public members" by using the dot '.' (period) operator
        its the same way that structure members are accessed.

    'Each object' of a class has its 'own copy of every variable' declared within the class. 
        statements in following example set ob1's copy of 'a' to 10 and ob2's copy to 99. 
        This means that ob1's 'a' is DISTINCT and DIFFERENT from the 'a' linked to ob2.
*/




/* Example 3: Assuming the preceding object declaration, the following statement calls "set_a()" for objects 'ob1' and 'ob2': */

ob1.set_a(10);      // sets ob1's version of 'a' to 10
ob2.set_a(99);      // sets ob2's version of 'a' to 99




/* Example 4: Create a class that holds 'name' and 'address' information. 
                Store all the information in 'character strings' that are "private" members of the class. 

                Include a "public function" that stores the 'name' and 'address'. 
                Also include a "public function" that displays the 'name' and 'address'. 
                (Call these functions store() and display().)
*/
#include <iostream>
#include <cstring>
// using namespace std;


class addr {
    // following are all private
    char name[40];
    char street[40];
    char city[30];
    char state[3];
    char zip[10];

    public:
        // fn prototypes
        void store(char *nm, char *stt, char *cty, char *ste, char *zp);
        void display();
};


// fn definitions
void addr::store( char *nm, char *stt, char *cty, char *ste, char *zp){
    strcpy(name, nm);
    strcpy(street, stt);
    strcpy(city, cty);
    strcpy(state, ste);
    strcpy(zip, zp);
}

void addr::display(){
    std::cout << name << "\n";
    std::cout << street << "\n";
    std::cout << city << "\n";
    std::cout << state << "\n";
    std::cout << zip << "\n\n";
}


int main(){
    addr a;     // 'a' is an object of class 'addr'

    a.store("C. B. Turkle ", "11 Pinetree Lane ", " Wausau ", "In", " 46576 ");
    // To avoid warning: ISO C++ forbids converting a string constant to 'char*'
    // a.store((char*)"C. B. Turkle ", (char*)"11 Pinetree Lane ", (char*)" Wausau ", (char*)"In", (char*)" 46576 ");
    a.display();

    return 0;
}


// ISSUE:
// warning: ISO C++ forbids converting a string constant to 'char*' [-Wwrite-strings]

// I solved it with following code using (char*):
/*  
    simply changing:
            sleep("50000"); // as string
        to:
            sleep((char*)"50000"); // as string 
*/




/* Example 5: What is wrong with the following fragment? */
#include <iostream>
using namespace std;

class myclass{
    int i;
    
    public:
        . 
        . 
        .
};

int main(){
    myclass ob;
    ob.i = 10;  // 'i' is 'private' to 'myclass' and cannot be accessed inside main()
    . 
    . 
    . 
}

// Answer: The integer 'i' is 'private' to 'myclass' and cannot be accessed inside main()




/* Example 6: This program demonstrates 'myclass'. It 'sets' the value of 'a' of ob1 and ob2 
                and then displays a's value for each object. */
#include <iostream>
// using namespace std;

class myclass{
    // private to myclass
    int a;

    public:
        void set_a(int num);
        int get_a();
};

// fn definition
void myclass::set_a(int num){
    a = num;
}

int myclass::get_a(){
    return a;
}


int main(){
    myclass ob1 , ob2;

    ob1.set_a(10);
    ob2.set_a(99);
    std::cout << ob1.get_a() << "\n";
    std::cout << ob2.get_a() << "\n";

    return 0;
}




/* Example 7: In 'myclass' from the preceding example, 'a' is private. 
                only 'member functions' of myclass can access it directly. 
                (This is one reason why the 'public function' get_a() is required.) 

                If you try to access a private member of a class from some part of your program that 
                    is not a member of that class, a COMPILE-TIME-ERROR will result. 

                For example, assuming that myclass is defined as shown in the preceding example, 
                    the following main() function will cause an error: 
*/

// This fragment contains an error
#include <iostream>
// using namespace std;

int main(){
    myclass ob1 , ob2;

    ob1.a = 10; // ERROR ! cannot access private member
    ob2.a = 99; // by non-member functions.
    std::cout << ob1.get_a() << "\n";
    std::cout << ob2.get_a() << "\n";

    return 0;
}


/* 
    error: ‘int myclass::a’ is private within this context
    
    now, move 'a' into public, the ERR resolvs, as below:

    class myclass{
        public:
            int a;
            void set_a(int num);
            int get_a();
    };
*/




/* Example 8: Just as there can be 'public member functions', there can be 'public member variables' as well. 
                For example, if a were declared in the public section of 'myclass', 
                'a' could be referenced by any part of the program, as shown here. 
                
                In this example, since 'a' is declared as a public member of 'myclass', it is directly accessible from main(). 

                Notice how the dot operator '.' is used to access 'a'. 
                    In general, when you are calling a 'member function' or accessing a 'member variable' from outside its class, the
                    object's name followed by the dot operator '.' followed by the" member's name" 
                    is required to fully specify which object's member you are referring to.
                
*/

// This fragment contains an error

#include <iostream>
// using namespace std;

class myclass{
    public:
        // now a is public
        int a;
        // and there is no need for set_a() or get_a()
};

int main(){
    myclass ob1, ob2;

    // here a is accessed directly
    ob1.a = 10;
    ob2.a = 99;
    std::cout << ob1.a << "\n";
    std::cout << ob2.a << "\n";

    return 0;
}




/* Example 9: To get a taste of the power of objects, let’s look at a more practical example. 
                This program creates a class called 'stack' that implements 
                a stack that can be used to store characters: */
#include <iostream>
// using namespace std;

#define SIZE 10

// Declare a stack class for characters
class stack{
    char stck[SIZE];     // holds the stack
    int tos;   // index of top of stack
    
    public :
        void init();    // initialize stack
        void push(char ch);     // push character on stack
        char pop();     // pop character from stack
};


// Initialize the stack
void stack::init(){
    tos = 0;
}


// Push a character
void stack::push(char ch){
    if(tos==SIZE){
        std::cout << " stack is full ";
        return;
    }

    stck[tos] = ch;
    tos++;
}


// Pop a character
char stack::pop(){
    if(tos ==0){
        std::cout << " Stack is empty ";
        return 0; // return null on empty stack
    }
    
    tos--;
    return stck[tos];
}


int main(){
    stack s1, s2; // create two stacks
    int i;

    // initialize the stacks
    s1.init();
    s2.init();
    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    for(i =0; i<3; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i =0; i<3; i ++) std::cout << " Pop s2: " << s2.pop() << "\n";

    return 0;
}

// This program displays the following output:
// Pop s1: c
// Pop s1: b
// Pop s1: a
// Pop s2: z
// Pop s2: y
// Pop s2: x

/* 
    The class 'stack' contains two private variables: 'stck' and 'tos'. 
        The array 'stck' actually holds the characters pushed onto the stack, 
        'tos' contains the index to the top of the stack. 
        
        The public 'stack' functions are init(), push(), and pop(), which initialize the stack, push a value, and pop a value, respectively.
    
        Inside main(), two stacks, 's1' and 's2', are created, and three characters are pushed onto each stack. 
        
        It is important to understand that 'each stack object' is "SEPARATE" from the other. 
            i.e. the characters pushed onto 's1' in no way affect the characters pushed onto s2. 
        Each object contains its own copy of 'stck' and 'tos'. 
        
        This concept is fundamental to understanding objects. 
            Although 'all objects of a class' share their member functions, each object creates and maintains its own data.
 */





/* Example 10: Create a class called 'card' that maintains a library card catalog entry. 

                Have the class store a 
                    book’s title, 
                    author, and 
                    number of copies on hand. 
                    
                    Store the 'title' and 'author' as strings and 
                    the 'number on hand' as an integer. 
                    
                    Use a public member functions called 
                        store() to store a book’s information and  
                        show() to display the information. 
                        
                    Include a short main() function to demonstrate the class. 
*/

#include <iostream>
#include <cstring>
// using namespace std;

class card{
    char title[80];  // book title
    char author[40]; // author
    int number;      // number in library

    public:
        void store(char *t, char *name, int num);
        void show();
};

void card::store(char *t, char *name, int num){
    strcpy(title, t);
    strcpy(author , name);
    number = num ;
}

void card::show(){
    std::cout << " Title : " << title << "\n";
    std::cout << " Author : " << author << "\n";
    std::cout << " Number on hand : " << number << "\n";
}


int main(){
    card book1, book2, book3;

    book1.store(" Dune ", " Frank Herbert ", 2);
    book2.store(" The Foundation Trilogy ", " Isaac Asimov ", 2);
    book3.store(" The Rainbow ", "D. H. Lawerence ", 1);
    book1.show();
    book2.show();
    book3.show();

    return 0;
}




/* Example 11: Create a 'queue class' that maintains a circular queue of integers. 
                Make the queue size 100 integers long. 
                Include a short main() function that demonstrates its operation. 
*/
#include <iostream>
// using namespace std;

#define SIZE 100

class q_type{
    int queue[SIZE];    // holds the queue
    int head, tail ;    // indices of head and tail

    public:
        void init();    // initialize
        void q(int num);    // store
        int deq();      // retrieve
};

// Initialize
void q_type::init(){
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


int main(){
    q_type q1, q2;
    int i;

    q1.init();
    q2.init();

    for(i =1; i<=10; i++){
        q1.q(i);
        q2.q(i*i);
    }

    for(i =1; i<=10; i++){
        std::cout << " Dequeue 1: " << q1.deq() << "\n";
        std::cout << " Dequeue 2: " << q2.deq() << "\n";
    }

    return 0;
}





/* Example 12: What does the following program display? */
#include <iostream>

int main(){
    int i = 10;
    long l = 1000000;
    double d = -0.0009;

    std::cout << i << ' ' << l << ' ' << d;
    std::cout << "\n";

    return 0;
}

// 10 1000000 -0.0009




/* Example 13: Create a class called "dice" that contains one private integer variable. 
                Create a function called "roll()" that uses the standard random number generator, rand(), 
                    to generate a number between 1 and 6. Then have roll() display that value. 
*/

#include <iostream>
#include <cstdlib>

class dice {
        int val;
    public:
        void roll();
};

void dice::roll(){
    val = (rand() % 6) + 1;     // generate 1 through 6
    std::cout << val << "\n";
}

int main(){
    dice one, two;

    one.roll();
    two.roll();
    one.roll();
    two.roll();
    one.roll();
    two.roll();

    return 0;
}




// ----  understand qeue  ----
// A 'Queue' has two pointers to track:
    // Head : tracks 'Dequeue'
    // Tail : tracks 'Queue'

/*  
    Algorithm
        1. START
        2. Check if the queue is full.
        3. If the queue is full, produce overflow error and exit.
        4. If the queue is not full, increment rear pointer to point 
        the next empty space.
        5. Add data element to the queue location, where the rear 
        is pointing.
        6. return success.
        7. END 
*/

