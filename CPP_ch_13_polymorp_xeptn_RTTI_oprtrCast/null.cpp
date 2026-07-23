


// ----  rev[09-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-







// --------  Generic-Classes  --------

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



