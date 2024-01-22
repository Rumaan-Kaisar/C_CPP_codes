
/* ----------------------     Constructors with Parameters     ----------------------
    Constructors with Parameters:
        simply add the appropriate parameters to the 'declaration' and 'definition'. 
        when you declare an object, specify the arguments. 
        
    By 'Constructors with Parameters' we can initialize different objects with different values as we want.
*/


class class_name{	
    // private functions and variables
    public :          	
        // public functions and variables
        class_name(type p1, type p2, . . . type pN);		// constructor with parameter
}; 	// no object list. Objects declared separately

    . . .
    . . .
    . . .

class_name object1(p1, p2, . . . , pN); // passing arguments to constructor

/*  Actually, the syntax for passing an argument to a parameterized constructor is 'SHORTHAND' for this longer form (which use constructor function):
    
                class_name object1 = class_name(p1, p2, . . . , pN);
        
        Eg: "myclass ob(4);" is shortheand form of  "myclass ob = myclass(4);"
        
        However the short-hand form is  often used :  
                class_name object1(p1, p2, . . . , pN);
            Actually, there is a slight technical difference between the two forms that relates to "copy constructors". We'll discuss it later.

    You can pass an object's constructor 'any valid expression, including variables'. 
        Actually objects can be constructed as needed to "fit" the 'exact situation' at the time of their creation. 
*/




/*  Destructors with Parameters:
        Destructor functions "CANNOT have parameters". 
        The reason is there exists no mechanism by which to pass arguments to an object that is being destroyed. 
*/




/* Example 1: Here the constructor for 'myclass' takes one parameter.
                The value passed to myclass() is used to initialize a. 

                Pay special attention to how 'ob' is declared in main(), with arguments ob(4). 
                    The value 4, specified in the parentheses following ob, 
                    it is the argument that is passed to myclass()'s parameter x, which is used to initialize a.
*/

#include <iostream>

class myclass{
        int a;
    public:
        myclass(int x);     // constructor with parameter
        void show();
};

myclass::myclass(int x){
    std::cout << "In constructor \n";
    a = x;  // parameter x is used to initiLalize private var 'a'
}

void myclass::show(){
    std::cout << a << "\n";
}


int main(){
    myclass ob(4);  // object with arguments to constructor
    ob. show();     // calling member function
    return 0;
} 


// Actually, the syntax for passing an argument to a parameterized constructor is shorthand for this longer form:
myclass ob = myclass(4);
// however, most C++ programmers use the short form.




/* Example 2: (multi-argument constructor) It is quite common-to pass a constructor more than one argument. 
                Here  myclass() is passed two arguments. 
                Here 4 is passed to x and 7 is passed to y.  
                
                You can pass any number of arguments as you like (up to the limit set by the compiler, of course).
*/
#include <iostream>

class myclass{
        int a, b;
    public:
        myclass(int x, int y); // constructor
        void show();
};

myclass::myclass(int x, int y){
    std::cout << "In constructor \n";
    a = x;
    b = y;
}

void myclass::show(){
    // dispaly both a, b
    std::cout << a << ' ' << b << "\n";
}


int main(){
    myclass ob(4, 7);
    ob. show();
    
    return 0;
}




/* Example 3: Here is another version of the 'stack class' that uses a parameterized constructor to pass a "name" to a stack. 
                This single-character name is used to 'identify the stack' that is being referred to when an error occurs. 

                Tips for DEBUGGING: Giving objects a "name," as shown in this example, is especially useful during DEBUGGING,
                    when it is important to know which object generates an error.                
*/
#include <iostream>

#define SIZE 10

// Declare a stack class for characters .
class stack {
        char stck[SIZE];    // holds the stack
        int tos;            // index of top of stack
        char who;           // identifies stack
    
    public:
        stack(char c);       // constructor. Notice the parameter
        void push(char ch); // push character on stack
        char pop();         // pop character from stack
};


// Initialize the stack. Use of parameter
stack::stack(char c){
    tos = 0;
    who = c;    // Use of parameter
    std::cout << " Constructing stack " << who << "\n";
}

// push(): Push a character
void stack::push(char ch){
    if(tos == SIZE){
        // Error massage
        std::cout << " Stack " << who << " is full \n";
        return;
    }
    stck[tos] = ch;
    tos++;
}

// pop(): Pop or remove a character
char stack::pop(){
    if(tos == 0){
        // Error massage
        std::cout << " Stack " << who << " is empty \n";
        return 0; // return null on empty stack
    }
    tos--;
    return stck[tos];
}


// -=-=-  main function  -=-=-
int main(){
    stack s1('A'), s2('B'); // create two stacks that are automatically initialized. Notice parameters
    int i;

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    // This will generate some error messages. Used 'i=5' instead of 'i=3'
    for(i =0; i<5; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i =0; i<5; i ++) std::cout << " Pop s2: " << s2.pop() << "\n";

    return 0;
}





/* Example 4: Here is a different way to implement the 'strtype class' (developed earlier) 
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





/* Example 5: You can pass an object’s constructor any valid expression, including variables. 
                For example, this program uses 'user input' to construct an object: */
#include <iostream>

class myclass{
        int i, j;
    public:
        myclass(int a, int b);  // variable parameters
        void show();
};

myclass::myclass(int a, int b){
    std::cout << "In constructor \n";
    i = a;
    j = b;
}

void myclass::show(){
    std::cout << i << ' ' << j << "\n";
}


int main(){
    int x, y;

    std::cout << " Enter two integers : ";
    std::cin >> x >> y;
    
    // use variables to construct 'ob'
    myclass ob(x, y);
    ob.show();

    return 0;
}


/* important point about objects: 
    They can be constructed as needed to fit the exact situation at the time of their creation. 
    As you learn more about C++, you will see how useful constructing objects "on the fly" is. 
*/





Example 6: Change the stack class so it dynamically allocates memory for the stack. Have the size
of the stack specified by a parameter to the constructor function. (Don’t forget to free
this memory with a destructor function.)

1. // Dynamically allocated stack .
# include <iostream >
# include <cstdlib >
using namespace std ;
// Declare a stack class for characters
class stack
{
char * stck ; // holds the stack
int tos ; // index of top of stack
int size ; // size of stack
public :
stack ( int s); // constructor
~ stack (); // destructor
void push ( char ch); // push character on stack
char pop (); // pop character from stack
};
// Initialize the stack
stack :: stack ( int s)
{
cout << " Constructing a stack \n";
tos = 0;
stck = ( char *) malloc (s);
if (! stck )
{
cout << " Allocation error \n";
exit (1) ;
}
size = s;
}
stack ::~ stack ()
{
free ( stck );
}
// Push a character .
void stack :: push ( char ch)
{
if( tos == size )
{
cout << " Stack is full \n";
return ;
}
stck [ tos ] = ch;
tos ++;
}
423TEACH YOURSELF
C++
// Pop a character .
char stack :: pop ()
{
if( tos ==0)
{
cout << " Stack is empty \n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
int main ()
{
// Create two stacks that are automatically initialized .
stack s1 (10) , s2 (10) ;
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






Example 7: Create a class called t and d that is passed the current system time and date as a
parameter to its constructor when it is created. Have the class include a member function
that displays this time and date on the screen. (Hint: Use the standard time and date
functions found in the standard library to find and display the time and date.)

2. # include <iostream >
# include <ctime >
using namespace std ;
class t_and_d
{
time_t systime ;
public :
t_and_d ( time_t t); // constructor
void show ();
};
t_and_d :: t_and_d ( time_t t)
{
systime = t;
}
void t_and_d :: show ()

{
cout << ctime (& systime );
}
int main ()
{
time_t x;
x = time ( NULL );
t_and_d ob(x);
ob. show ();
return 0;
}








Example 8: Create a class called box whose constructor function is passed three double values, each
of which represents the length of one side of a box. Have the box class compute the
volume of the box and store the result in a double variable. Include a member function
called vol() that displays the volume of each box object.

3. # include <iostream >
using namespace std ;
class box
{
double l, w, h;
double volume ;
public :
box ( double a, double b, double c);
void vol ();
};
box :: box ( double a, double b, double c)
{
l = a;
w = b;
h = c;
volume = l * w * h;
}
void box :: vol ()
{
cout << " Volume is: " << volume << "\n";
}
int main ()
{
box x(2.2 , 3.97 , 8.09) , y(1.0 , 2.0 , 3.0) ;
x. vol ();
y. vol ();
return 0;

C++
}


