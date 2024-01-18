
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







// ----  rev  ----



Example 1: It is possible-in fact, quite common-to pass a constructor more than one argument. Here
myclass() is passed two arguments:
# include <iostream >
using namespace std ;
class myclass
{
int a, b;
public :
myclass ( int x, int y); // constructor
void show ();
};
myclass :: myclass ( int x, int y)
{
cout << "In constructor \n";
a = x;
b = y;
}
void myclass :: show ()
{
cout << a << ’ ’ << b << "\n";
}
int main ()
{
myclass ob (4, 7);
ob. show ();
return 0;
}




Here 4 is passed to x and 7 is passed to y. This same general approach is used to pass
any number of arguments you like (up to the limit set by the compiler, of course).





Example 2: Here is another version of the stack class that uses a parameterized constructor to pass a
"name" to a stack. This single-character name is used to identify the stack that is being
referred to when an error occurs.
# include <iostream >
using namespace std ;
# define SIZE 10
// Declare a stack class for characters .
class stack
{
char stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
char who ; // identifies stack
public :
stack ( char c); // constructor
void push ( char ch); // push character on stack
char pop (); // pop character from stack
};
// Initialize the stack .
stack :: stack ( char c)
{
tos = 0;
who = c;
cout << " Constructing stack " << who << "\n";
}
// Push a character .
void stack :: push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack " << who << " is full \n";
return ;
}
stck [ tos ] = ch;
tos ++;
}
// Pop a character .
char stack :: pop ()
{
if( tos ==0)
{
cout << " Stack " << who << " is empty \n";
return 0; // return null on empty stack
}
39TEACH YOURSELF
C++
tos --;
return stck [ tos ];
}
int main ()
{
// Create two stacks that are automatically initialized .
stack s1(’A’), s2(’B’);
int i;
s1. push (’a’);
s2. push (’x’);
s1. push (’b’);
s2. push (’y’);
s1. push (’c’);
s2. push (’z’);
// This will generate some error messages .
for (i =0; i <5; i ++)
cout << " Pop s1: " << s1.pop () << "\n";
for (i =0; i <5; i ++)
cout << " Pop s2: " << s2.pop () << "\n";
return 0;
}
Giving objects a "name," as shown in this example, is especially useful during debugging,
when it is important to know which object generates an error.





Example 3: Here is a different way to implement the strtype class (developed earlier) that uses a
parameterized constructor function:
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
s1. show ();
s2. show ();
return 0;
}
In this version of strtype, a string is given an initial value using the constructor function.





Example 4: Although the previous examples have used constants, you can pass an object’s constructor
any valid expression, including variables. For example, this program uses user input to
construct an object:
# include <iostream >
using namespace std ;
class myclass
{
int i, j;
public :
myclass ( int a, int b);
void show ();
};
myclass :: myclass ( int a, int b)
{
cout << "In constructor \n";
i = a;
j = b;
}
41TEACH YOURSELF
C++
void myclass :: show ()
{
cout << i << ’ ’ << j << "\n";
}
int main ()
{
int x, y;
cout << " Enter two integers : ";
cin >> x >> y;
// use variables to construct ob
myclass ob(x, y);
ob. show ();
return 0;
}
This program illustrates an important point about objects. They can be constructed as
needed to fit the exact situation at the time of their creation. As you learn more about
C++, you will see how useful constructing objects "on the fly" is.



EXERCISES





Example 5: Change the stack class so it dynamically allocates memory for the stack. Have the size
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






Example 6: Create a class called t and d that is passed the current system time and date as a
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








Example 7: Create a class called box whose constructor function is passed three double values, each
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


