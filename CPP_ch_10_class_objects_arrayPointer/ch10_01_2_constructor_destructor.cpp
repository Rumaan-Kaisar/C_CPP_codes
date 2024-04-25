
// ----------------------     CONSTRUCTOR & DESTRUCTOR     ----------------------  

// General form   of     CONSTRUCTOR	

class class_name{	
        // private functions and variables
    public :
        // public functions and variables	
        class_name();	// constructor
} object_list ;	




// General form   of     DESTRUCTOR

class class_name{	
        // private functions and variables
    public :
        // public functions and variables 	
        ~class_name();	// destructor 
} object_list ;


/* ------------    INITIALIZATION using "constructor"    ------------

    Object INITIALIZATION using "constructor": 
        When applied to real problems, virtually every object you create will require some sort of initialization. 
            To address this situation, C++ allows a constructor function to be included in a class declaration. 
            
        A class’s constructor is 'called each time an object of that class is created'. 
            Any initialization that needs to be 'performed on an object' can be done automatically by the constructor function.

        A constructor function has the 'same name as the class' of which it is a part 
        
        Return type of constructor:
            it has 'no return type'. It is 'illegal' for a constructor to have a 'return type'.
            Observe following examples ()

    
    The constructor is called when the object is created. 
        An object is 'created' when that object's declaration statement is EXECUTED. 


    For "GLOBAL objects", an object's constructor is 'called ONCE', when the program first begins execution. 
    For "LOCAL objects", the constructor is 'called EACH TIME' the declaration statement is executed.
 
*/



/* Example 1: construuctor in actioin for Local & Global object 
                
                'myclass ob;' line cause "Object Initialization" and prints 'In constructor'
*/

#include <iostream>
// using namespace std;

class myclass{
        int a;
    public :
        myclass(); // constructor
        void show();    
};


int main(){
    myclass ob; // object declaration

    ob.show();  // calling function
            
    return 0;
}


// member function definition
myclass :: myclass(){ 
    std::cout << "In constructor \n"; 
    a = 10; 
}

void myclass :: show(){
    std::cout << a;
}




/*  ------------    Destroy objects using "destructor"    ------------
    
    Destroy objects using "destructor":  
        The 'complement of a constructor' is the DESTRUCTOR. 
        This function is called when an object is destroyed. 
        
        For example, an object that allocates memory when it is created will 'want to free that memory' when it is destroyed. 
        
        The 'name' of destructor-function is the "name of its class", preceded by a "tilde" "~" . 

    It is not possible to take the ADDRESS of either a 'constructor' or a 'destructor'.

    A class's DESTRUCTOR is called when 'an object is destroyed'. 
        'Local' objects are destroyed when they go out of scope. 
        'Global' objects are destroyed when the program ends. Example: 	 

*/




/* Example 2: destructor & construuctor in actioin for Local & Global object 

                'myclass ob;' line cause "Object Initialization" and prints 'In constructor'
                    exiting the main() function destroys object and prints 'Destructing. . ..'

                also notice when extra_fn() called, new object 'ob2' is initialized and prints 'In constructor'
                    "Inside extra_fn" is printed by extra_fn() 
                    after exitig extra_fn() the 'scope' is lost and 'ob2' is destroyes and prints 'Destructing. . ..'
*/

#include <iostream>
// using namespace std;

class myclass{  
        int a;
    public : 
        myclass(); 	// constructor 
        ~myclass(); // destructor               
        void show();    
};

void extra_fn(){
    myclass ob2;
    std::cout << "Inside extra_fn\n";
}

int main(){
    myclass ob; // object declaration

    std::cout << std::endl;
    extra_fn();
    std::cout << std::endl;

    ob.show();  // calling the member function of 'ob'
    std::cout << "Inside main\n";

    return 0;
}


// member function definition
myclass :: myclass(){ 
    std::cout << "In constructor \n"; 
    a = 10; 
}

myclass :: ~myclass(){
    std::cout << "Destructing. . .. \n";
}

void myclass :: show(){
    std::cout << a <<"\n";
}


// 'std::endl' and '\n' both seem to do the same thing but there is a subtle difference between them. 
    // "std::cout << std::endl" inserts a 'new line and flushes the stream(output buffer)', 
    // whereas std::cout <<"\n "just inserts a new line.

// Therefore, "std::cout << std::endl;" can be said equivalent to- std::cout << "\n" << flush;




/* 
    ------------    'variable declaration' VS 'object declaration'    ------------
    In C++, a variable declaration statement is an "action statement".
    
    In 'C', it is easy to think of 'declaration statements' as simply 'establishing' variables. 
        
    However, in C++, because an 'object' might have a CONSTRUCTOR, 
        a "variable (i.e. object ) declaration" statement may, in fact, cause a considerable 'number of actions' to occur.



    Other usage Restriction: 
        Don't use a constructor or destructor to perform actions "not directly related to the INITIALIZATION or orderly DESTRUCTION of an object" 
        
        Technically, a constructor or a destructor can perform any type of operation. 
            The code within these functions does not have to 'initialize' or 'reset anything' related to the class for which they are defined. 
            For example, a constructor for the preceding examples could have computed 'pi' to 100 places. 

*/




/* Example 3: Recall the "stack class" we created in previous section required an initialization function to set the stack index variable.
                Constructor function was designed to perform this sort of operation. 

                Following is an improved version of the 'stack class' that can be used to store characters
                    that uses a constructor to 'automatically initialize' a stack object when it is created 
*/

#include <iostream>
// using namespace std;

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

    // No need to initialize the stacks
    // s1.init();  // no need 
    // s2.init();  // no need

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


/* 
    Notice, 'the initialization task is performed automatically' by the constructor function 
        rather than by a separate function that must be explicitly called by the program.

    Constructor function makes sure that the inilialization is performed.
    The programmer, don’t need to worry about initialization-it is performed automatically when the object is brought into existence.
*/




/* Example 4: Following program need both "constructor" and "destructor" function.
                It creates a simple string class, called 'strtype', that contains a 'string and its length'. 

                When a 'strtype' object is created, 
                    'memory' is allocated to hold the string and its initial length is set to 0. 

                When strtype object is destroyed, that memory is released. 
                
                The program uses malloc and free() to allocate and free memory. While this is perfectly valid, 
                    C++ does provide another way to dynamically manage memory, which we will see later.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

#define SIZE 25

// class definition
class strtype{
        char *p;
        int len;

    public:
        strtype();  // constructor
        ~strtype(); // destructor
        void set(char *ptr);
        void show();
};


// -=-=-    implementing member function    -=-=-

// constructor: Initialize a string object .
strtype::strtype(){
    p = (char *)malloc(SIZE);    // malloc() returns a POINTER
    // Why type cast : To make conversion from ‘void *’ to ‘char *’
    if(!p){
        std::cout << " Allocation error \n";
        exit(1) ;
    } 

    *p = '\0';
    len = 0;
}

// destructor: Free memory when destroying string object .
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}


void strtype::set(char *ptr){
    if(strlen(p) >= SIZE){
        std::cout << " String too big \n";
        return;
    }
    strcpy(p, ptr);
    len = strlen(p);
}


void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


int main(){
    strtype s1 , s2;

    s1.set("This is a test.");
    s2.set("I like C ++.");
    s1.show();
    s2.show();

    return 0;
}


/* Note: The preceding program uses the new-style headers for the C library functions used by the program.
            If your compiler does not support these headers, simply substitute the standard C header files. 

            type cast! why? : 
                Notice 'type cast' in malloc(): To avoid ERR- invalid conversion from ‘void*’ to ‘char*’
                
                In C, you don't need to cast the return value of malloc(). 
                    [Recall 'C_Ch8_7_dynmic_allocation.c', "Example 2"]
                    The "pointer to void" i.e 'void *' returned by malloc() is automagically converted to the correct type. 
                
                However, in C++ compiler, 'a cast is NEEDED'.
                    C++ is not C. Their type systems are totally different. 
                    Observations about C++'s type system do not necessarily apply to C. In fact, they rarely do.
*/




/* Example 5: Here is an interesting way to use an object’s constructor and destructor. 

                This program uses an object of the 'timer class' to time the interval between: 
                    when an object of type 'timer' is 'created' and when it is 'destroyed'. 

                When the object’s destructor is called, the 'elapsed time is displayed'. 

                You could use an object like this to:
                    # time the 'duration of a program' or 
                    # the length of time a function spends 'within a block'. 

                Just make sure that the object 'goes out of scope' 
                    at the point at which you want the timing interval to end. 
*/

#include <iostream>
#include <ctime>

class timer{
        clock_t start;  // 'clock_t' type time varibale 

    public:
        timer();    // constructor
        ~timer();   // destructor
};

// constructor & destructor def
timer::timer(){
    start = clock();    // Recall 'CPP_ch_0_useful_lib_func, C_Ch0_4_Time .c'
}

timer::~timer(){
    clock_t end;

    end = clock();
    std::cout << " Elapsed time : " << (end - start) << std::endl;
    std::cout << " Elapsed time in second: " << (end - start) / CLOCKS_PER_SEC << std::endl;
    // Convert to seconds: divide value by the CLOCKS_PER_SEC macro
}


int main(){
    timer ob;   // object of timer class
    char c;

    // delay ...
    std::cout << " Press a key followed by ENTER : ";
    std::cin >> c;

    return 0;
}

/* 
    Note: clock() returns the 'number of system clock cycles' that have occurred since the PROGRAM began EXECUTION. 
        Convert to seconds: To compute the number of seconds, divide this value by the CLOCKS_PER_SEC macro. 
*/




/* Example 6: Following is the Rework of the 'queue class' that we developed in previous section 
                by replacing its initialization function with a constructor. 
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

/*  // OLD code: Initialize

    void q_type::init(){
        head = tail = 0;
    } 
*/

// Constructor: Auto initialization
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


int main(){
    q_type q1, q2;
    int i;

    // old code: no need initialization anymoore. Done by the 'constructor' autometically
    // q1.init();
    // q2.init();

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




/* Example 7: Create a class called 'stopwatch' that emulates a stopwatch that keeps track of elapsed time. 
                
                Use a CONSTRUCTOR to initially set the elapsed time to 0. 
                
                Provide two member functions called start() and stop() that turn on and off the timer, respectively. 
                Include a member function called show() that displays the elapsed time. 
                
                Also, have the DESTRUCTOR function automatically display elapsed time when a stopwatch object is destroyed. 
                (To simplify, report the time in seconds.) 
*/

// Stopwatch emulator
#include <iostream>
#include <ctime>


class stopwatch {
        double begin, end;

    public:
        stopwatch();
        ~stopwatch();
        void start();
        void stop();
        void show();
};




stopwatch :: stopwatch(){
    begin = end = 0.0;
}


stopwatch ::~ stopwatch(){
    std::cout << " Stopwatch object being destroyed ... ";
    show();
}


void stopwatch::start(){
    begin = (double)clock() / CLOCKS_PER_SEC;
}


void stopwatch::stop(){
    end = (double)clock() / CLOCKS_PER_SEC;
}


void stopwatch::show(){
    std::cout << " Elapsed time : " << end - begin;
    std::cout << "\n";
}


int main(){
    stopwatch watch ;
    long i;

    watch.start();
    for(i =0; i<320000; i++); // time a for loop
    watch.stop();
    watch.show();

    return 0;
}

/* 
    // another for loop to test
        for(i =0; i<3200000000; i++){
            if(!(i%60000)) {
                watch.stop();
                watch.show();
            }
        }
*/




/* Example 8: What is wrong with the 'constructor' shown in the following fragment? */
class sample{
        double a, b, c;
    public:
        double sample(); // error , why ?
};

// ans: A constructor cannot have a return type.





/* Example 9: What is a constructor? What is a destructor? When are they executed? 
                
                Ans:
                    A "constructor" is the function that is called when an object is created. 
                    A "destructor" is the function that is called when an object is destroyed.
*/




/* Example 10: Given the following class, what are the names of its 'constructor' and 'destructor' functions? */

class widgit{
        int x, y;
    public:
        // ... fill in constructor and destructor functions
};

// Constructor is called widgit() and 
// Destructor is called ~widgit().


