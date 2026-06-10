


// ----  rev[09-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-






// --------  Generic-Functions  --------

1. The following program creates a generic function that swaps the values of the two variables
it is called with. Because the general process of exchanging two values is independent of
the type of the variables, this process is a good choice to be made into a generic function.
// Function template example .
# include <iostream >
using namespace std ;
// This is a function template .
template <class X> void swapargs (X &a, X &b)
{
X temp ;
temp = a;
a = b;
b= temp ;
}
int main ()
{
int i=10 , j =20;
float x=10 , y =23.3;
cout << " Original i, j: " << i << ’ ’ << j << endl ;
cout << " Original x, y: " << x << ’ ’ << y << endl ;
swapargs (i, j); // swap integers
swapargs (x, y); // swap floats
cout << " Swapped i, j: " << i << ’ ’ << j << endl ;
cout << " Swapped x, y: " << x << ’ ’ << y << endl ;
return 0;
}
The keyword template is used to define a generic function. The line:
template <class X> void swapargs (X &a, X &b)

tells the compiler two things: that a template is being created and that a generic definition
is beginning. Here X is a generic type that is used as a placeholder. After the template
portion, the function swapargs() is declared, using X as the data type of the values that
will be swapped. In main(), the swapargs() function is called using two different types
of data: integers and floats. Because swapargs() is a generic function, the compiler
automatically creates two versions of swapargs()-one that will exchange integer values
and one that will exchange floating-point values. You should compile and try this program
now.
Here are some other terms that are sometimes used when templates are discussed and
that you might encounter in other C++ literature. First, a generic function (that is, a
function definition preceded by a template statement) is also called a template function.
When the compiler creates a specific version of this function, it is said to have created a
generated function. The act of generating a function is referred to as instantiating it. Put
differently, a generated function is a specific instance of a template function.
2. The template portion of a generic function definition does not have to be on the same
line as the function’s name. For example, the following is also a common way to format
the swapargs() function:
template <class X>
void swapargs (X &a, X &b)
{
X temp ;
temp = a;
a = b;
b= temp ;
}
If you use this form, it is important to understand that no other statements can occur
between the template statement and the start of the generic function definition. For
example, the following fragment will not compile:
// This will not compile .
template <class X>
int i; // this is an error
void swapargs (X &a, X &b)
{
X temp ;
temp = a;
a = b;
b= temp ;
}
As the comments imply, the template specification must directly precede the rest of the
function definition.
3. As mentioned, instead of using the keyword class, you can use the keyword typename
to specify a generic type in a template definition. For example, here is another way to
declare the swapargs() function.
// Use typename
template <typename X> void swapargs (X &a, X &b)
284TEMPLATES AND EXCEPTION HANDLING
11.1. GENERIC FUNCTIONS
{
X temp ;
temp = a;
a = b;
b= temp ;
}
The typename keyword can also be used to specify an unknown type within a template,
but this use is beyond the scope of this book.
4. You can define more than one generic data type with the template statement, using a
comma-separated list. For example, this program creates a generic function that has two
generic types:
# include <iostream >
using namespace std ;
template <class type1 , class type2 >
void myfunc ( type1 x, type2 y)
{
cout << x << ’ ’ << y << endl ;
}
int main ()
{
myfunc (10 , "hi");
myfunc (0.23 , 10L);
return 0;
}
In this example, the placeholder types type1 and type2 are replaced by the compiler with
the data types int and char * and double and long, respectively, when the compiler
generates the specific instances of myfunc().
Remember: When you create a generic function, you are, in essence, allowing the
compiler to generate as many different versions of that function as necessary to handle
the various ways that your program calls that function.
5. Generic functions are similar to overloaded functions except that they are more restrictive.
When functions are overloaded, you can have different actions performed within the body
of each function. But a generic function must perform the same general action for all
versions. For example, the following overloaded functions cannot be replaced by a generic
function because they do not do the same thing:
void outdata ( int i)
{
cout << i;
}
void outdata ( double d)
{
cout << setprecision (10) << setfill (’#’);

cout << d;
cout << setprecision (6) << setfill (’ ’);
}
6. Even though a template function overloads itself as needed, you can explicitly overload
one, too. If you overload a generic function, that overloaded function overrides (or *hides*)
the generic function relative to that specific version. For example, consider this version of
Example 1:
// Overriding a template function .
# include <iostream >
using namespace std ;
// This is a function template .
template <class X> void swapargs (X &a, X &b)
{
X temp ;
temp = a;
a = b;
b= temp ;
}
// This overrides the generic version of swapargs ().
void swapargs ( int a, int b)
{
cout << " this is inside swapargs (int ,int )\n";
}
int main ()
{
int i=10 , j =20;
float x=10 , y =23.3;
cout << " Original i, j: " << i << ’ ’ << j << endl ;
cout << " Original x, y: " << x << ’ ’ << y << endl ;
swapargs (i, j); // calls overloaded swapargs ()
swapargs (x, y); // swap floats
cout << " Swapped i, j: " << i << ’ ’ << j << endl ;
cout << " Swapped x, y: " << x << ’ ’ << y << endl ;
return 0;
}
As the comments indicate, when swapargs(i,j) is called, it invokes the explicitly overloaded version of swapargs() defined in the program. Thus, the compiler does not
generate this version of the generic swapargs() function because the generic function is
overridden by the explicit overloading.
Manual overloading of a template, as shown in this example, allows you to tailor a version
of a generic function to accommodate a special situation. However, in general, if you need

to have different versions of a function for different data types, you should use overloaded
functions rather than templates.






1. If you have not done so, try each of the preceding examples.
2. Write a generic function, called min(), that returns the lesser of its two arguments. For
example, min(3, 4) will return 3 and min(’c’, ’a’ will return a. Demonstrate your
function in a program.
3. A good candidate for a template function is called find(). This function searches an array
for an object. It returns either the index of the matching object (if one is found) or -1 if no
match is found. Here is the prototype for a specific version of find(). Convert find() into
a generic function and demonstrate your solution within a program. (The size parameter
specifies the number of elements in the array.)
int find ( int object , int *list , int size )
{
// ...
}
4. In your own words, explain why generic functions are valuable and may help simplify the
source code to program that you create.


2. # include <iostream >
using namespace std ;
template <class X> X min (X a, X b)
{
if(a <=b)
return a;
else
return b;
}
int main ()
{
cout << min (12.2 , 2.0) ;
cout << endl ;
cout << min (3, 4);
cout << endl ;
cout << min (’c’, ’a’);
return 0;
}
/*
This min (X, X) function might cause ambiguity
because of STL function min ( const _Tp &, const _Tp &).
Try a different name .
*/
3. # include <iostream >
# include <cstring >
using namespace std ;
template <class X> int find (X object , X *list , int size )
{
int i;
for (i =0; i< size ; i ++)
if( object == list [i])
return i;
return -1;
}
int main ()
{
int a[] = {1, 2, 3, 4};
char *c = " this is a test ";

double d[] = {1.1 , 2.2 , 3.3};
cout << find (3, a, 4);
cout << endl ;
cout << find (’a’, c, (int ) strlen (c));
cout << endl ;
cout << find (0.0 , d, 3);
return 0;
}
4. Generic functions are valuable because they allow you to define a general algorithm that
can be applied to various types of data. (That is, specific versions of the algorithm need
not be explicitly created by you.) Generic functions further help implement the concept
of "one interface, multiple methods," which is a common theme in C++ programming.












// --------  Generic-Classes  --------

1. This program creates a very simple generic singly linked list class. It then demonstrates
the class by creating a linked list that stores characters.
// A simple generic linked list .
# include <iostream >
using namespace std ;
template <class data_t > class list
{
data_t data ;
list * next ;
public :
list ( data_t d);
void add ( list * node ) { node -> next = this ; next = 0; }
list * getnext () { return next ; }
data_t getdata () { return data ; }
};
template <class data_t > list <data_t >:: list ( data_t d)
{
data = d;
next = 0;
}
int main ()
{
list <char > start (’a’);
list <char > *p, * last ;
int i;
// build a list
last = & start ;
for (i =1; i <26; i ++)
{
p = new list <char >( ’a’ + i);
p->add ( last );
last = p;
}
// follow the list
p = & start ;
while (p)
{
cout << p-> getdata ();
p = p-> getnext ();

}
return 0;
}
As you can see, the declaration of a generic class is similar to that of a generic function.
The actual type of data stored by the list is generic in the class declaration. It is not until
an object of the list is declared that the actual data type is determined. In this example,
objects and pointers are created inside main() that specify that the data type of the list
will be char. Pay special attention to this declaration:
list <char > start (’a’);
Notice how the desired data type is passed inside the angle brackets.
You should enter and execute this program. It builds a linked list that contains the
characters of the alphabet and then displays them. However, by simply changing the type
of data specified when list objects are created, you can change the type of data stored by
the list. For example, you could create another object that stores integers by using this
declaration:
list <int > int_start (1) ;
You can also use list to store data types that you create. For example, if you want to
store address information, use this structure:
struct addr
{
char name [40];
char street [40];
char city [30];
char state [3];
char zip [12];
}
Then, to use list to generate objects that will store objects of type addr, use a declaration
like this (assuming that structvar contains a valid addr structure):
list <addr > obj ( structvar );
2. Here is another example of a generic class. It is a reworking of the stack class first
introduced in Chapter 1. However, in this case, stack has been made into a template
class. Thus, it can be used to store any type of object. In the example, shown here, a
character stack and a floating-point stack are created:
// This function demonstrates a generic stack ,
# include <iostream >
using namespace std ;
# define SIZE 10
// Create a generic stack class
template <class StackType > class stack
{
StackType stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack

public :
void init () { tos = 0; } // initialize stack
void push ( StackType ch); // push object on stack
StackType pop (); // pop object from stack
};
// Push an object .
template <class StackType >
void stack < StackType >:: push ( StackType ob)
{
if( tos == SIZE )
{
cout << " Stack is full .\n";
return ;
}
stck [ tos ] = ob;
tos ++;
}
// Pop an object
template <class StackType >
StackType stack < StackType >:: pop ()
{
if( tos ==0)
{
cout << " Stack is empty .\n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
int main ()
{
// Demonstrate character stacks .
stack <char > s1 , s2; // create two stacks
int i;
// initialize the stacks
s1. init ();
s2. init ();
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
// demonstrate double stacks
stack < double > ds1 , ds2 ; // create two stacks
// initialize the stacks
ds1 . init ();
ds2 . init ();
ds1 . push (1.1) ;
ds2 . push (2.2) ;
ds1 . push (3.3) ;
ds2 . push (4.4) ;
ds1 . push (5.5) ;
ds2 . push (6.6) ;
for (i =0; i <3; i ++)
cout << " Pop ds1 : " << ds1 .pop () << "\n";
for (i =0; i <3; i ++)
cout << " Pop ds2 : " << ds2 .pop () << "\n";
return 0;
}
As the stacl class (and the preceding list class) illustrates, generic function and classes
provide a powerful tool that you can use to maximize your programming time because
they allow you to define the general form of an algorithm that can be used with any type
of data. You are saved from the tedium of creating separate implementations for each
data type that you want the algorithm to work with.
3. A template class can have more than one generic data type. Simply declare all the data
types required by the class in a comma-separated list within the template specification.
For example, the following short example creates a class that uses two generic data types:
/*
This example uses two generic data types in a
class definition
*/
# include <iostream >
using namespace std ;
template <class Type1 , class Type2 > class myclass
{
Type1 i;
Type2 j;
public :
myclass ( Type1 a, Type2 b) { i = a; j = b; }
void show () { cout << i << ’ ’ << j << ’\n’; }
};
int main ()
{
291TEACH YOURSELF
C++
myclass <int , double > ob1 (10 , 0.23) ;
myclass <char , char *> ob2(’X’, " This is a test ");
ob1 . show (); // show int , double
ob2 . show (); // show char , char *
return 0;
}
This program produces the following output:
10 0.23
X This is a test
The program declares two types of objects. ob1 uses integer and double data. ob2 uses
a character and a character pointer. For both cases, the compiler automatically generates
the appropriate data and functions to accommodate the way the objects are created.





1. If you have not yet done so, compile and run the two generic class examples. Try declaring
lists and/or stacks of different data types.
2. Create and demonstrate a generic queue class.
3. Create a generic class, called input, that does the following when its constructor is called:
➤ prompts the user for input,
➤ inputs the data entered by the user, and
➤ reprompts if the data is not within a predetermined range.
Objects of type input should be declared like this:
input ob(" prompt message ", min_value , max_value )
Here prompt message is the message that prompt for input. The minimum and maximum
acceptable values are specified by min-value and max-value, respectively. (Note: the type
of data entered by the user will be the same as the type of min-valueand max-value.)

2. // Create a generic queue .
# include <iostream >
using namespace std ;
# define SIZE 100
template <class Qtype > class q_type
{
Qtype queue [ SIZE ]; // holds the queue
int head , tail ; // indices of head and tail
public :
q_type () { head = tail = 0; }
void q( Qtype num ); // store
Qtype deq (); // retrieve
};
// Put value on queue .
template <class Qtype > void q_type <Qtype >::q( Qtype num)
{
if( tail +1== head || ( tail +1== SIZE && ! head ))
{
cout << " Queue is full .\n";
return ;
}
tail ++;
if( tail == SIZE )
tail = 0; // cycle around
queue [ tail ] = num ;
}
// Remove value from queue .
template <class Qtype > Qtype q_type <Qtype >:: deq ()
{

if( head == tail )
{
cout << " Queue is empty .\n";
return 0; // or some other error indicator
}
head ++;
if( head == SIZE )
head = 0; // cycle around
return queue [ head ];
}
int main ()
{
q_type <int > q1;
q_type <char > q2;
int i;
for (i =1; i <=10; i ++)
{
q1.q(i);
q2.q(i -1+ ’A’);
}
for (i =1; i <=10; i ++)
{
cout << " Dequeue 1: " << q1.deq () << ’\n’;
cout << " Dequeue 2: " << q2.deq () << ’\n’;
}
return 0;
}


3. # include <iostream >
using namespace std ;
template <class X> class input
{
X data ;
public :
input ( char *s, X min , X max);
// ...
};
template <class X>
input <X >:: input ( char *s, X min , X max )
{
do
{
cout << s << ": ";
cin >> data ;
}

while ( data < min || data > max);
}
int main ()
{
input <int > i(" enter int ", 0, 10) ;
input <char > c(" enter char ", ’A’, ’Z’);
return 0;
}




