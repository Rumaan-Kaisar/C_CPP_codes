
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
            it has 'no return type'. It is 'illegal' for a constructor to have a 'return type'.

    
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





/* Example 3: You should recall that the stack class created in Chapter 1 required an initialization
function to set the stack index variable. This is precisely the sort of operation that a
constructor function was designed to perform . Here is an improved version of the stack
class that uses a constructor to automatically initialize a stack object when it is created: */

# include <iostream >
using namespace std ;
# define SIZE 10
// Declare a stack class for characters .
class stack
{
char stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
public :
stack (); // constructor
void push ( char ch); // push character on stack
char pop (); // pop character from stack
};
// Initialize the stack .
stack :: stack ()
{
cout << " Constructing a stack \n";
tos = 0;
}
// Push a character
void stack :: push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack is full \n";
return ;
}
stck [ tos ] = ch;
tos ++;
}
// Pop a character
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
As you can see, now the initialization task is performed automatically by the constructor
function rather than by a separate function that must be explicitly called by the program.
This is an important point. When an initialization is performed automatically when an
object is created, it eliminates any prospect that, by error, the initialization will not be
performed. This is another way that objects help reduce program complexity. You, as the
programmer, don’t need to worry about initialization-it is performed automatically when
the object is brought into existence.





/* Example 4: Here is an example that shows the need for both a constructor and a destructor function.
It creates a simple string class, called strtype, that contains a string and its length. When
a strtype object is created, memory is allocated to hold the string and its initial length
is set to 0. When strtype object is destroyed, that memory is released. */

# include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
# define SIZE 25
class strtype
{
char *p;
int len ;
public :
strtype (); // constructor
~ strtype (); // destructor
void set ( char * ptr );
void show ();
};
// Initialize a string object .
strtype :: strtype ()
{
p = ( char *) malloc ( SIZE );
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
} *
p = ’\0 ’;
len = 0;
}
// Free memory when destroying string object .
strtype ::~ strtype ()
{
cout << " Freeing p\n";
free (p);
}
void strtype :: set ( char *ptr )
{
if( strlen (p) >= SIZE )
{
cout << " String too big \n";
return ;
}
strcpy (p, ptr );
len = strlen (p);
}
void strtype :: show ()
{
cout << p << " - length : " << len ;
cout << "\n";
}
int main ()
{
strtype s1 , s2;
s1. set (" This is a test .");
s2. set ("I like C ++. "):
s1. show ();
s2. show ();
return 0;
}
The program uses malloc and free() to allocate and free memory. While this is perfectly
valid, C++ does provide another way to dynamically manage memory, as you will see
later in this book.
Note: The preceding program uses the new-style headers for the C library functions used
by the program. As mentioned in Chapter 1, if your compiler does not support these
headers, simply substitute the standard C header files. This applies to other programs in
this book in which C library functions are used.





/* Example 5: Here is an interesting way to use an object’s constructor and destructor. This program
uses an object of the timer class to time the interval between when an object of type
timer is created and when it is destroyed. When the object’s destructor is called, the
elapsed time is displayed. You could use an object like this to time the duration of a
program or the length of time a function spends within a block. Just make sure that the
object goes out of scope at the point at which you want the timing interval to end. */

# include <iostream >
# include <ctime >
using namespace std ;
class timer
{
clock_t start ;
public :
timer (); // constructor
~ timer (); // destructor
};
timer :: timer ()
{
start = clock ();
}
timer ::~ timer ()
{
clock_t end ;
end = clock ();
cout << " Elapsed time : " << (end - start ) / CLOCKS_PER_SEC
<< "\n";
}
int main ()
{
timer ob;
char c;
// delay ...
cout << " Press a key followed by ENTER : ";
cin >> c;
return 0;
}
This program uses the standard library function clock(), which returns the number of
clock cycles that have taken place since the program started running. Dividing this value
by CLOCKS PER SEC converts the value to seconds.





/* Example 6: Rework the queue class that you developed as an exercise in Chapter 1 by replacing its
initialization function with a constructor. */





/* Example 7: Create a class called stopwatch that emulates a stopwatch that keeps track of elapsed
time. Use a constructor to initially set the elapsed time to 0. Provide two member
functions called start() and stop() that turn on and off the timer, respectively. Include
a member function called show() that displays the elapsed time. Also, have the destructor
function automatically display elapsed time when a stopwatch object is destroyed. (To
simplify, report the time in seconds.) */





/* Example 8: What is wrong with the constructor shown in the following fragment? */
class sample
{
double a, b, c;
public :
double sample (); // error , why ?
};



