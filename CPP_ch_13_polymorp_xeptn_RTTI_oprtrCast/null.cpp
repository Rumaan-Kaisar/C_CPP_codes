


// ----  rev[25-Aug-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-




// ---- rev[01-Oct-2026] ----







// ----------------    rev[21-Sept-2026]: add below in compact form to the function explanation    ----------------


// Exception Handling: goes to "ch13_05_exception_handling.cpp"

/* Example 6: Rework the stack class so that stack "over-and underflows" are handled as "exceptions". 
                (rework version of Example 10 of 'ch13_04_generic_fn_class.cpp', introduced in "ch10_01_1_class_intro.cpp") 
*/

#include <iostream>

#define SIZE 10

// Create a generic stack class
template <class StackType> class stack {
        StackType stck[SIZE];       // holds the stack
        int tos;                    // index of top of stack
    public:
        void init() { tos = 0; }    // initialize stack
        void push(StackType ch);    // push object on stack
        StackType pop();            // pop object from stack
};


// Push an object (GnF)
template <class StackType> void stack <StackType>::push(StackType ob) {
    
    /* OLD:
    if(tos == SIZE) {
        std::cout << " Stack is full .\n";
        return;
    }
    */
    // changed to 
     
    stck [tos] = ob;
    tos++;
}

// Push objects .

    // include exception handling
    try {
        if(tos == SIZE) throw SIZE;
    }
catch ( int )
{
cout << " Stack is full .\n";
return ;
}

}


// Pop objects .
template <class StackType >
StackType stack < StackType >:: pop ()
{
    // include exception handling
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



// --------    reworked    --------

/* Example 10: Following is a rewoked version of the "stack" class introduced in "ch10_01_1_class_intro.cpp".  
                However, in this case, stack has been made into a template class (i.e a generic stack). 
                Thus, it can be used to store any type of object. 
                In this example, a character stack and a floating-point stack are created.
*/

#include <iostream>

#define SIZE 10






// Pop an object (GnF)
template <class StackType> StackType stack <StackType>::pop() {
    if(tos==0) {
        std::cout << " Stack is empty .\n";
        return 0;   // return null on empty stack
    }
    tos--;
    return stck[tos];
}


int main() {
    // Demonstrate character stacks .
    stack <char> s1, s2;    // create two stacks
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

    for(i=0; i<3; i++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i=0; i<3; i++) std::cout << " Pop s2: " << s2.pop() << "\n";

    // demonstrate double stacks
    stack <double> ds1, ds2;    // create two stacks

    // initialize the stacks
    ds1.init();
    ds2.init();

    ds1.push(1.1);
    ds2.push(2.2);
    ds1.push(3.3);
    ds2.push(4.4);
    ds1.push(5.5);
    ds2.push(6.6);

    for (i=0; i<3; i++) std::cout << " Pop ds1 : " << ds1.pop() << "\n";
    for (i=0; i<3; i++) std::cout << " Pop ds2 : " << ds2.pop() << "\n";

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
