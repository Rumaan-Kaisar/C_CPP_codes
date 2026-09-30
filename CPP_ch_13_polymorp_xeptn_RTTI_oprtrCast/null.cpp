


// ----  rev[25-Aug-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-




// ---- rev[18-Sept-2026] ----







// ----------------    rev[21-Sept-2026]: add below in compact form to the function explanation    ----------------



// ========  GPT compasct  ========





/* Example 5: Show the general forms of try, catch, and throw. In short words, describe their operation. 


                The general forms of try, catch, and throw are shown here:

                try {
                    // try block
                    throw exp;
                }
                catch (type arg) {
                    // ...
                }


                //  ----  GPT  ----

                ### General forms of `try`, `catch`, and `throw` in C++

                ```cpp
                try {
                    // Code that may cause an exception
                }
                catch (type variable) {
                    // Code that handles the exception
                }
                ```

                To generate an exception:

                ```cpp
                throw value;
                ```

                ### How they work, in short:

                try --> Contains code that might cause an exception.
                throw --> Signals that an error/exception has occurred.
                catch --> Catches and handles the exception thrown by `throw`.

                ### Example:

                ```cpp
                try {
                    throw 10;
                }
                catch (int x) {
                    cout << "Exception: " << x;
                }
                ```

                Here, `throw 10` sends the value `10` to the matching `catch` block, which then handles it.


*/






/* Example 6: Again, rework the stack class so that stack over-and underflows are handled as exceptions. */


/*
This function demonstrates a generic stack
that includes exception handling .
*/
#include <iostream>

#define SIZE 10

// Create a generic stack class
template <class StackType > class stack {
        StackType stck[SIZE ];  // holds the stack
        int tos;                // index of top of stack
    public:
        void init(){ 
            tos = 0; 
        }
        void push(StackType ob);
        StackType pop();
};


// Push objects .
template <class StackType> void stack <StackType>:: push(StackType ob) {
try
{
if( tos == SIZE )
throw SIZE ;
}
catch ( int )
{
cout << " Stack is full .\n";
return ;
}
stck [ tos ] = ob;
tos ++;
}


// Pop objects .
template <class StackType >
StackType stack < StackType >:: pop ()
{
try
{
if( tos ==0)
throw 0;
}

catch ( int )
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
char ch;
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
cout << " Pop s1: " << s1.pop () << ’\n’;
for (i =0; i <3; i ++)
cout << " Pop s2: " << s2.pop () << ’\n’;
// demonstrate double stacks
stack < double > ds1 , ds2 ; // create two stacks
double d;
// initialize the stacks
ds1 . init ();
ds2 . init ();
ds1 . push (1.1) ;
ds2 . push (2.2) ;
ds1 . push (3.3) ;
ds2 . push (4.5) ;
ds1 . push (5.5) ;
ds2 . push (6.6) ;
for (i =0; i <3; i ++)
std::cout << " Pop ds1 : " << ds1 .pop () << ’\n’;
for (i =0; i <3; i ++)
std::cout << " Pop ds2 : " << ds2 .pop () << ’\n’;

return 0;
}



// -----------------------    reworked version    ------------------------

#include <iostream>

#define SIZE 10

// --------  Create a generic stack class  --------
template <class StackType> class stack {
        // OLD code: StackType stck[SIZE];
        // NEW code: each stack position now holds 2 values.
        StackType stck[SIZE][2];    // holds the stack (of 2 values)
        int tos;                    // index of top of stack
    public:
        void init() { tos = 0; }    // initialize stack

        // OLD code: void push(StackType ch);
        // NEW code: push() receives TWO objects.
        void push(StackType ob, StackType ob2);     // push objects on stack (notice 2 objects)

        // OLD code: StackType pop();
        // NEW code: second value is returned through reference 'ob2'.
        StackType pop(StackType &ob2);              // pop object from stack (from ob2's location)
};


// --------  Push two objects (GnF)  --------
/*  
    OLD VERSION:

        template <class StackType> void stack<StackType>::push(StackType ob)

    NEW VERSION:

        template <class StackType> void stack<StackType>::push(StackType ob, StackType ob2)
    
    The old push() accepted ONE object. Example:    s1.push('a');
    The new push() accepts TWO objects. Example:    s1.push('a', 'b');

    This means that ONE stack position now contains:    ['a', 'b']

    Notice that both parameters have StackType:

        stack<char>     both objects must be char.
        stack<double>   then both objects must be double.
*/
template <class StackType> void stack <StackType>::push(StackType ob, StackType ob2) {
    if(tos == SIZE) {
        std::cout << " Stack is full .\n";
        return;
    }
    // OLD: stck[tos] = ob;
    // NEW: store the two values in columns 0 and 1.
    stck[tos][0] = ob;  // store the FIRST object of the pair.
    stck[tos][1] = ob2; // store the SECOND object of the pair.
    tos++;
}


// --------  Pop objects (GnF).  --------
/*  
    OLD VERSION:

        template <class StackType> StackType stack<StackType>::pop()

    NEW VERSION:

        template <class StackType> StackType stack<StackType>::pop(StackType &ob2)

    The old version returned ONE object.
    This new version has TWO ways of returning the pair:

        1. The FIRST object is returned normally.
        2. The SECOND object is returned through 'ob2'.
*/
template <class StackType> StackType stack <StackType>::pop(StackType &ob2) {
    if(tos == 0) {
        std::cout << " Stack is empty .\n";
        return 0;   // return null on empty stack
    }
    tos--;
    // We first retrieve the SECOND object. Because ob2 is a REFERENCE, this changes the variable supplied by the caller.
    ob2 = stck[tos][1];     // put the SECOND value into ob2. '&' means the caller's variable is changed directly.
    return stck[tos][0];    // return the FIRST value from column 0.
}


int main(){
    // --------  Demonstrate character stacks.  --------
    stack <char> s1, s2;    // create two stacks
    int i;
    char ch;    // it is needed because pop() now returns the second value through a reference parameter "s1.pop(ch);".
    // The first value comes back through the return statement.
    // The second value comes back through ch.

    // initialize the stacks
    s1.init();
    s2.init();

    // TWO values are pushed as ONE stack entry. But in OLD version One value was pushed like "s1.push('a');"
    s1.push('a', 'b');  // one stack entry now contains ('a', 'b').
    s2.push('x', 'z');

    s1.push('b', 'd');
    s2.push('y', 'e');

    s1.push('c', 'a');
    s2.push('z', 'x');

    /*
        s1 now contains:

            ['a', 'b']
            ['b', 'd']
            ['c', 'a']

        s2 now contains:

            ['x', 'z']
            ['y', 'e']
            ['z', 'x']
    */

    for(i=0; i<3; i++) std::cout << " Pop s1: " << s1.pop(ch) << ' ' << ch << '\n';
    for(i=0; i<3; i++) std::cout << " Pop s2: " << s2.pop(ch) << ' ' << ch << '\n';

    /*  --------------------------------------------------------
        OLD VERSION:

            s1.pop()    // returned one value.

        NEW VERSION:

            s1.pop(ch)  // returns TWO values.


        since s1 contains:

                ['a', 'b']
                ['b', 'd']
                ['c', 'a']

            Because a stack is LIFO (Last In, First Out), then top entry is:    ['c', 'a']
                Then:

                    s1.pop(ch)

                does:

                    return 'c'
                    ch = 'a'

                Therefore:

                    std::cout << s1.pop(ch) << ' ' << ch;

                prints:

                    c a

                so the pairs come out in reverse order:

                ['c', 'a']
                ['b', 'd']
                ['a', 'b']


        And s2 contains:

                ['x', 'z']
                ['y', 'e']
                ['z', 'x']
                
            Then the pairs also come out in reverse order:

                ['z', 'x']
                ['y', 'e']
                ['x', 'z']
    */

    // --------  demonstrate double stacks  --------
    stack <double> ds1, ds2;    // create two stacks
    double d;                   // NEW: receives the second double from pop().

    // initialize the stacks
    ds1.init();
    ds2.init();

    // TWO values are pushed as ONE stack entry.
    // Each push now stores TWO doubles as one stack entry.
    ds1.push(1.1, 2.0);
    ds2.push(2.2, 3.0);

    ds1.push(3.3, 4.0);
    ds2.push(4.5, 5.0);

    ds1.push(5.5, 6.0);
    ds2.push(6.6, 7.0);

    /*  ds1 contains:

                [1.1, 2.0]
                [3.3, 4.0]
                [5.5, 6.0]

            Since this is a stack, the last pair is removed first (LIFO):

                [5.5, 6.0]

            So:

                ds1.pop(d)

            gives:

                return value = 5.5
                d            = 6.0

            Output order:

                [5.5, 6.0]
                [3.3, 4.0]
                [1.1, 2.0]


        Similarly ds2 contains:

                [2.2, 3.0]
                [4.5, 5.0]
                [6.6, 7.0]

            Pop order:

                [6.6, 7.0]
                [4.5, 5.0]
                [2.2, 3.0]
    */

    for(i=0; i<3; i++) 
        std::cout   << " Pop ds1: " 
                    << ds1.pop(d) 
                    << ' ' 
                    << d 
                    << '\n';
                    
    for(i=0; i<3; i++) 
        std::cout   << " Pop ds2: " 
                    << ds2.pop(d) 
                    << ' ' 
                    << d 
                    << '\n';

    return 0;
}









/* Example 7: Check your compiler’s documentation. 
See whether it supports the terminate() and unexpected() functions. 
Generally, these functions can be configured to call any function you choose. 
If this is the case with your compiler, try creating your own set of customized
termination functions that handle otherwise unhandled exceptions. */




/* Example 8: Thought question: Give a reason why having new generate an exception is a better
approach than having new return null on failure. */




Cumulative Skills Check



/* 2. In Chapter 1, overloaded versions of the abs() function were created. As a better solution,
create a generic abs() function on your own that will return the absolute value of any
numeric object. */




Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
/* 1. What is a generic function and what is its general form?
2. What is a generic class and what is its general form?
*/








/* Example 4: In "ch12_11_custom_io_files.cpp", Example 1, a coord class that holds integer coordinates was
created and demonstrated in a program. 

Create a generic version of the coord class that
can hold coordinates of any type. Demonstrate your solution in a program. */


#include <iostream>
#include <fstream>

template < class CoordType > class coord
{
CoordType x, y;
public :
coord ( CoordType i, CoordType j) { x = i; y = j; }
void show () { cout << x << ", " << y << endl ; }
};

int main ()
{
coord <int >o1 (1, 2) , o2 (3, 4);
o1. show ();
o2. show ();
coord < double > o3 (0.0 , 0.23) , o4 (10.19 , 3.098) ;
o3. show ();
o4. show ();
return 0;
}





/* "ch12_11_custom_io_files.cpp" Example 1: In the following program, the "coord" class overloads the << and >> operators. 
                The program uses these operator functions to write data to both the "screen" and a "file". 

                Class Setup: The coord class uses friend functions for input and output.

                Saving: An ofstream object (out) uses << to save coordinates to a file.
                Loading: An ifstream object (in) uses >> to read that data into new objects.

                Displaying: 
                    The same << operator works with "cout", 
                    showing the code is reusable for both files and the screen.
*/

#include <iostream>
#include <fstream>

class coord {
        int x, y;
    public:
        coord(int i, int j) { x = i; y = j; }
        
        // Friend functions for overloading operators
        friend std::ostream &operator <<(std::ostream &stream, coord ob);
        friend std::istream &operator >>(std::istream &stream, coord &ob);
};


// Overload << operator
std::ostream &operator <<(std::ostream &stream, coord ob) {
            stream << ob.x << ' ' << ob.y << '\n';
            return stream;
}

// Overload >> operator
std::istream &operator >>(std::istream &stream, coord &ob) {
            stream >> ob.x >> ob.y;
            return stream;
;}


int main() {
    coord o1(1, 2), o2(3, 4);

    // Writing to File
    std::ofstream out("test");
    if(!out) {
        std::cout << "Cannot open output file.\n";
        return 1; 
    }
    out << o1 << o2;    // Uses overloaded << to store values in a file
    out.close();

    // Reading from File
    std::ifstream in("test");
    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }
    coord o3(0, 0), o4(0, 0);  // Initialize objects where values will be stored.
    in >> o3 >> o4;     // Uses overloaded >> to read from "in"

    // Output the values to Screen
    std::cout << o3 << o4;      // Uses overloaded << to print the values to screen
    in.close ();

    return 0;
}







5. Briefly explain how try, catch, and throw work together to provide C++ exception
handling.


6. Can throw be used if execution has not passed through a try block?

7. What purpose do terminate() and unexpected() serve?

8. What form of catch will handle all types of exceptions?












MASTERY SKILLS CHECK:










/* 7. If new throws an exception when an allocation error occurs, you can be sure that the
error will be handled one way or another-even if only by abnormal program termination.
In contrast, an allocation failure that is reported by new, a return of a null pointer
can be overlooked if you forget to check for this possibility. The trouble is that when
your program attempts to use the null pointer, it might work for a while, then behave
erratically, and finally crash in unpredictable (and unduplicatable ) ways. This is very
difficult type of bug to diagnose. 


Here’s a simpler version:

> If `new` throws an exception when memory allocation fails, you can be sure the error will be handled somehow—even if the program simply terminates.
>
> On the other hand, if `new` reports an allocation failure by returning a **null pointer**, you might forget to check it. If your program then uses that null pointer, it may behave strangely, work for a while, and eventually crash in unpredictable ways.
>
> **Such bugs are very difficult to find and diagnose.**

### In very simple terms:

* **`new` throws an exception:** The error is hard to ignore because the program must deal with the exception.
* **`new` returns `nullptr`:** You might forget to check it, causing strange behavior or crashes later.
* Therefore, **exceptions make memory-allocation errors easier to detect and handle.**


*/

1. In C++, a generic function defines a general set of operations that will be applied to
various types of data. It is implemented with the keyword template. Its general form is
shown here:

template <class Ttype> ret_type func_name(para_list) {
    // ...
}


2. In C++, a generic class defines all operations that relate to that class, but the actual
data is specified as a parameter when an object of that class is created. Its general form
is shown here:
template <class Ttype> class class_name {
    // ...
};




/* 5. try, catch, and throw work together like this: Put all statements that you wish to
monitor for exceptions within a try block, if an exception occurs, throw that exception
using throw and handle it with a corresponding catch statement. */


6. No.


/* 7. terminate() is called when an exception is thrown for which there is no corresponding
catch statement. unexpected() is called when an attempt is made to throw an exception
out of a function that is not specified in the function’s throw clause. */


8. catch(...).
