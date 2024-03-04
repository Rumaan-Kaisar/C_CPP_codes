
/*  ----------------    AUTOMATIC IN-LINING    ----------------

    If a member function's definition is 'short enough', 
        the DEFINITION can be included inside the "class declaration". 
        Then the function autometically become an "in-line function", if possible. 

    When a function is defined "within a class declaration", the 'inline' keyword is no longer necessary. 
        if any 'in-line restriction' is violated, the compiler is free to generate a normal function.
    
    For example, the  divisible()  is automatically in-lined as shown here:


            class samp {	
                    int i, j;
                public:
                    samp(int a, int b);
                    int divisible(){ return !(i%j); }   // divisible() is defined inside class-declaration and automatically 'in-lined'.
            };

            samp::samp(int a, int b) {
                i = a;
                j = b; 
            }


        Notice, the code associated with divisible() occurs inside the declaration for the class 'samp'. 
            Further notice that no other definition of divisible() is 'needed-or permitted'.

        Notice how divisible()  occurs all on one line. 
            This format is very common in C++ programs when a function is declared within a class declaration. 
            It allows the declaration to be more compact. 

*/




/* Example 1: The divisible() "Member-functions" of classes from the preceding section "ch10_05_1_inLine_func.cpp" Example 2, 
                can be AUTOMATICALLY in-lined as shown here: */

#include <iostream>

class samp{
        int i, j;
    public:
        samp(int a, int b); // defined outside, couled be in-lined, if defined here. It's common for constuctors
        // divisible() is defined here instead of declaring and it'll automatically in-lined.
        int divisible(){ return !(i%j);}
};

samp::samp(int a, int b){
    i = a;
    j = b;
}


int main(){
    samp ob1(10 , 2), ob2(10, 3);

    // this is true
    if(ob1.divisible()) std::cout << "10 divisible by 2\n";
    // this is false
    if(ob2.divisible()) std::cout << "10 divisible by 3\n";
    return 0;
}

/*  Notice the code associated with divisible() occurs inside the declaration for the class 'samp'. 
        Further notice that no other definition of divisible() is "needed-or permitted". 
        DEFINING divisible() inside 'samp' made it in-line function automatically.

        When a function defined inside a class declaration cannot be made 
            into an in-line function (because a restriction has been violated), 
            it is automatically made into a 'regular function'.
        
        The same restrictions that apply to "normal in-line functions" apply to 
            'automatic in-line functions' within a class declaration

    Notice how divisible() is defined within samp, all on one line. 
        This format is very common in C++ programs when a function is declared within a class declaration. 
        It allows the declaration to be more compact. 
        
        However, the samp class could have been written like this:

                class samp{
                        int i, j;
                    public:
                        samp(int a, int b);
                        int divisible(){
                            return !(i%j);
                        }
                };

    In this version, the layout of divisible() uses the more-or-less standard indentation style. 
    for the compiler, there is no difference with compact style.

    between the compact style is commonly found
    in C++ programs when short functions are defined inside a class definition.
*/




/* Example 2: Most common use of in-line functions defined within a class is to define:
                        Constructor and 
                        Destructor functions. 

                For example the 'sampclass' can more efficiently be defined like below: 
*/
# include <iostream>

class samp{
        int i, j;
    public:
        // inline constructor
        samp(int a, int b) { i = a; j = b; }
        int divisible(){ return !(i%j); }
};

// The definition of samp() within the CLASS 'samp' is sufficient, and no other definition of samp() is needed.




/* Example 3: Sometimes a short function will be included in a class declaration 
                even though the automatic in-lining feature is of "little or no value". 
                Consider following class declaration: */
class myclass{
        int i;
    public:
        myclass(int n){ i = n; }
        void show(){ std::cout << i; }
};

/*  Here the function show() is made into an in-line function automatically. 
    However, as you should know, I/O operations are (generally) so slow relative to CPU/memory operations 
        that any effect of eliminating the 'function call overhead' is essentially lost. 
        
    Even so, in C++ programs, it is still common to see small functions of this type 
        declared within a class simply for the sake of convenience, and because no harm is caused.
*/




/* Example 4: Convert the stack class from "ch10_01_2_constructor_destructor.cpp", Example 3, 
                so that it uses 'automatic in-line' functions where appropriate. 
                It uses 'non-parameterized constructor'.
*/


/* OLD Example 3: Recall the "stack class" we created in previous section required an initialization function to set the stack index variable.
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


1. # include <iostream >
using namespace std ;
# define SIZE 10
// Declare a stack class for characters
class stack
{
char stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
public :
stack ()
{
tos = 0;
}
void push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack is full \n";
return ;
}
stck [ tos ] = ch;
tos ++;
}
char pop ()
{
if( tos ==0)
{
cout << " Stack is empty \n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
};
int main ()
{
// Create two stacks that are automatically initialized .
430ANSWERS
2.7 EXERCISES
stack s1 , s2;
int i;
s1. push (’a’);
s2. push (’x’);
s1. push (’b’);
s2. push (’y’);
s1. push (’c’);
s2. push (’z’);
for (i =0; i <3; i ++)
cout << " Pop s1: " << s1.pop () << "\n";
for (i =0; i <3; i ++)
cout << " Pop s2: " << s2.pop () << "\n";
return 0;
}



/* Example 5: Convert the "strtype" class from "ch10_01_3_constructor_param.cpp", Example 4, 
                so that it uses automatic in-line functions.
                It uses parameterized cinstructor. 
*/

/* OLD Example 4: Here is a different way to implement the 'strtype class' (developed earlier) 
                that now uses a parameterized constructor function. 
                
                'strtype class'creates a simple string class, called 'strtype', that contains a 'string and its length'. 

                When a 'strtype' object is created, 
                    'memory' is allocated to hold the string and its initial length is set to 0. 

                When strtype object is destroyed, that memory is released. 
                
                The program uses malloc and free() to allocate and free memory. While this is perfectly valid, 
                    C++ does provide another way to dynamically manage memory, which we will see later.
*/

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


2. # include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
int len ;
public :
strtype ( char * ptr )
{
len = strlen ( ptr );
p = ( char *) malloc (len +1);
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
} ~
strtype ()
{
cout << " Freeing p\n";
free (p);
}
void show ()
{
cout << p << " - lengthj : " << len ;
cout << ’\n’;
}
};
431TEACH YOURSELF
C++
int main ()
{
strtype s1(" This is a test ."), s2("I like C++. ");
s1. show ();
s2. show ();
return 0;
}

