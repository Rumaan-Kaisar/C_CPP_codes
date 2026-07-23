


// ----  rev[09-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-











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



