


// ----  rev[25-Aug-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



/* Example 4: Rework the stack class so that it can store pairs of different-type objects on the stack.
                (rework version of Example 10 of 'ch13_04_generic_fn_class.cpp', introduced in "ch10_01_1_class_intro.cpp") 
                
                Following template class demonstrates a generic stack that holds two values.
                Then a character stack and a floating-point stack are created.

                OLD code (ONE object):  one stack position stored one value (Example 10).
                NEW code (TWO objects): one stack position stores two values.

            Note: 
                both values are still of the SAME type:
                stack<char>   -> char + char
                stack<double> -> double + double
*/

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
    stck[tos][0] = ob;
    stck[tos][1] = ob2;
    tos++;
}


// --------  Pop objects (GnF).  --------
/*  
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
    ob2 = stck[tos][1];
    return stck[tos][0];
}


int main(){
    // Demonstrate character stacks.
    stack <char> s1, s2;    // create two stacks
    int i;
    char ch;

    // initialize the stacks
    s1.init();
    s2.init();

    s1.push('a', 'b');
    s2.push('x', 'z');

    s1.push('b', 'd');
    s2.push('y', 'e');

    s1.push('c', 'a');
    s2.push('z', 'x');

    for(i=0; i<3; i++) std::cout << " Pop s1: " << s1.pop(ch) << ' ' << ch << '\n';
    for(i=0; i<3; i++) std::cout << " Pop s2: " << s2.pop(ch) << ' ' << ch << '\n';


    // demonstrate double stacks
    stack <double> ds1, ds2;    // create two stacks
    double d;

    // initialize the stacks
    ds1.init();
    ds2.init();

    ds1.push(1.1, 2.0);
    ds2.push(2.2, 3.0);

    ds1.push(3.3, 4.0);
    ds2.push(4.5, 5.0);

    ds1.push(5.5, 6.0);
    ds2.push(6.6, 7.0);

    for(i=0; i<3; i++) std::cout << " Pop ds1: " << ds1.pop(d) << ' ' << d << '\n';
    for(i=0; i<3; i++) std::cout << " Pop ds2: " << ds2.pop(d) << ' ' << d << '\n';

    return 0;
}

/*
    OLD VERSION:
    --------------------------------------------------------

        StackType stck[SIZE];

    This creates a one-dimensional array.

    For example, stack<char> becomes:

        char stck[10];

    So each stack position contains only ONE value:

        stck[0] -> one char
        stck[1] -> one char
        stck[2] -> one char
        ...


    NEW VERSION:
    --------------------------------------------------------

        StackType stck[SIZE][2];

    The array is now TWO-dimensional.

    For example, stack<char> becomes:

        char stck[10][2];

    Each stack position can now contain TWO values:

        stck[0][0] -> first value
        stck[0][1] -> second value

        stck[1][0] -> first value
        stck[1][1] -> second value

        stck[2][0] -> first value
        stck[2][1] -> second value

    So visually:

            Stack position

                0       1
            +-------+-------+
        0 |   a   |   b   |
            +-------+-------+
        1 |   c   |   d   |
            +-------+-------+
        2 |   e   |   f   |
            +-------+-------+

    The FIRST index selects the stack position.

    The SECOND index selects which value of the pair.
*/


// ---- rev[18-Sept-2026] ----






// --------  GPT  --------


```cpp
/*
    Example 4: Rework the stack class so that it can store
    pairs of objects on the stack.

*/


// --------  rev[21-Sept-2026]  --------

// ============================================================
// push()
// ============================================================

/*
    OLD VERSION:

        template <class StackType>
        void stack<StackType>::push(StackType ob)

    NEW VERSION:

        template <class StackType>
        void stack<StackType>::push(StackType ob, StackType ob2)

    The only conceptual change here is that push() now receives
    TWO objects instead of ONE.
*/

template <class StackType>
void stack<StackType>::push(StackType ob, StackType ob2)
{
    /*
        This part is unchanged.

        If tos reaches SIZE, the stack has no more positions.
    */

    if (tos == SIZE)
    {
        std::cout << " Stack is full.\n";
        return;
    }


    /*
        --------------------------------------------------------
        OLD VERSION
        --------------------------------------------------------

            stck[tos] = ob;

        There was only one value in each stack position.

        Example:

            push('a')

        resulted in:

            stck[0] = 'a'


        NEW VERSION
        --------------------------------------------------------

            stck[tos][0] = ob;

        We now have TWO positions inside each stack entry.

        [0] means:

            "store the FIRST object of the pair."

        Example:

            push('a', 'b')

        gives:

            stck[0][0] = 'a'
    */

    stck[tos][0] = ob;


    /*
        This is the NEW line.

            stck[tos][1] = ob2;

        [1] means:

            "store the SECOND object of the pair."

        Therefore:

            push('a', 'b')

        produces:

            stck[0][0] = 'a'
            stck[0][1] = 'b'

        So one stack entry now contains:

            ['a', 'b']
    */

    stck[tos][1] = ob2;


    /*
        This part is also unchanged.

        After storing the pair, move tos to the next
        available stack position.

        Before push:

            tos = 0

        After push:

            tos = 1
    */

    tos++;
}


// ============================================================
// pop()
// ============================================================

/*
    OLD VERSION:

        template <class StackType>
        StackType stack<StackType>::pop()

    NEW VERSION:

        template <class StackType>
        StackType stack<StackType>::pop(StackType &ob2)

    The function now needs a reference parameter because
    there are TWO values to get out of the stack.
*/

template <class StackType>
StackType stack<StackType>::pop(StackType &ob2)
{
    /*
        This part is unchanged.

        If tos == 0, there is nothing to remove.
    */

    if (tos == 0)
    {
        std::cout << " Stack is empty.\n";

        /*
            Same basic idea as the old version:

                return 0;

            However, this is only suitable for types where
            0 can be used as a meaningful "empty" indication.
        */

        return 0;
    }


    /*
        This part is unchanged.

        Move tos backward before accessing the top entry.

        Suppose:

            tos = 3

        The actual top entry is at:

            index 2

        Therefore:

            tos--;

        changes:

            tos = 3

        into:

            tos = 2
    */

    tos--;


    /*
        --------------------------------------------------------
        OLD VERSION
        --------------------------------------------------------

            return stck[tos];

        There was only ONE object to return.


        NEW VERSION
        --------------------------------------------------------

            ob2 = stck[tos][1];

        We first retrieve the SECOND object.

        Because ob2 is a REFERENCE, this changes the variable
        supplied by the caller.

        Example:

            char ch;

            s1.pop(ch);

        If the top pair is:

            ['c', 'a']

        then:

            ob2 = 'a'

        and therefore:

            ch == 'a'
    */

    ob2 = stck[tos][1];


    /*
        Now return the FIRST object.

        OLD:

            return stck[tos];

        NEW:

            return stck[tos][0];

        [0] means the FIRST value of the pair.

        Therefore, if:

            stck[tos][0] = 'c'
            stck[tos][1] = 'a'

        then:

            return stck[tos][0];

        returns:

            'c'

        while the previous statement already placed:

            'a'

        into ob2.
    */

    return stck[tos][0];
}


// ============================================================
// main()
// ============================================================

int main()
{
    // --------------------------------------------------------
    // Character stacks
    // --------------------------------------------------------

    /*
        OLD:

            stack<char> s1, s2;

        This line is actually UNCHANGED.

        But what the stack contains has changed.

        OLD stack:

            stack<char>
                |
                +-- one char per position

        NEW stack:

            stack<char>
                |
                +-- two chars per position
    */

    stack<char> s1, s2;


    int i;


    /*
        NEW:

            char ch;

        This variable is needed because pop() now returns
        the second value through a reference parameter.

        OLD pop():

            s1.pop();

        NEW pop():

            s1.pop(ch);

        The first value comes back through the return statement.

        The second value comes back through ch.
    */

    char ch;


    // Initialize the stacks.
    // This is unchanged from the old version.

    s1.init();
    s2.init();


    /*
        --------------------------------------------------------
        OLD:

            s1.push('a');

        One value was pushed.


        NEW:

            s1.push('a', 'b');

        TWO values are pushed as ONE stack entry.

        The stack now contains:

            ['a', 'b']
    */

    s1.push('a', 'b');


    /*
        OLD:

            s2.push('x');

        NEW:

            s2.push('x', 'z');

        Stack entry:

            ['x', 'z']
    */

    s2.push('x', 'z');


    /*
        OLD:

            s1.push('b');

        NEW:

            s1.push('b', 'd');

        s1 now contains:

            ['a', 'b']
            ['b', 'd']
    */

    s1.push('b', 'd');


    /*
        s2 now contains:

            ['x', 'z']
            ['y', 'e']
    */

    s2.push('y', 'e');


    /*
        s1 now contains:

            ['a', 'b']
            ['b', 'd']
            ['c', 'a']
    */

    s1.push('c', 'a');


    /*
        s2 now contains:

            ['x', 'z']
            ['y', 'e']
            ['z', 'x']
    */

    s2.push('z', 'x');


    /*
        --------------------------------------------------------
        OLD VERSION:

            s1.pop()

        returned one value.


        NEW VERSION:

            s1.pop(ch)

        returns TWO values.

        Example top entry:

            ['c', 'a']

        Then:

            s1.pop(ch)

        does:

            return 'c'
            ch = 'a'

        Therefore:

            std::cout << s1.pop(ch) << ' ' << ch;

        prints:

            c a
    */

    for (i = 0; i < 3; i++)
        std::cout << "Pop s1: "
                  << s1.pop(ch)
                  << ' '
                  << ch
                  << '\n';


    /*
        s2 contains:

            ['x', 'z']
            ['y', 'e']
            ['z', 'x']

        Because a stack is LIFO (Last In, First Out),
        the pairs come out in reverse order:

            ['z', 'x']
            ['y', 'e']
            ['x', 'z']
    */

    for (i = 0; i < 3; i++)
        std::cout << "Pop s2: "
                  << s2.pop(ch)
                  << ' '
                  << ch
                  << '\n';



    // ========================================================
    // Demonstrate double stacks
    // ========================================================

    /*
        OLD:

            stack<double> ds1, ds2;

        NEW:

            stack<double> ds1, ds2;

        Again, the declaration itself is unchanged.

        But each stack entry can now hold TWO doubles.

        Example:

            [1.1, 2.0]
            [3.3, 4.0]
            [5.5, 6.0]
    */

    stack<double> ds1, ds2;


    /*
        NEW variable.

        It receives the SECOND double from pop().

        The first double is returned normally.
    */

    double d;


    // Initialize the stacks.
    // Unchanged from the old version.

    ds1.init();
    ds2.init();


    /*
        OLD:

            ds1.push(1.1);

        NEW:

            ds1.push(1.1, 2.0);

        One stack entry now contains:

            [1.1, 2.0]
    */

    ds1.push(1.1, 2.0);


    /*
        ds2:

            [2.2, 3.0]
    */

    ds2.push(2.2, 3.0);


    /*
        ds1:

            [1.1, 2.0]
            [3.3, 4.0]
    */

    ds1.push(3.3, 4.0);


    /*
        ds2:

            [2.2, 3.0]
            [4.5, 5.0]
    */

    ds2.push(4.5, 5.0);


    /*
        ds1:

            [1.1, 2.0]
            [3.3, 4.0]
            [5.5, 6.0]
    */

    ds1.push(5.5, 6.0);


    /*
        ds2:

            [2.2, 3.0]
            [4.5, 5.0]
            [6.6, 7.0]
    */

    ds2.push(6.6, 7.0);


    /*
        --------------------------------------------------------
        NEW POP BEHAVIOR
        --------------------------------------------------------

        ds1 contains:

            [1.1, 2.0]
            [3.3, 4.0]
            [5.5, 6.0]

        Since this is a stack, the last pair is removed first:

            [5.5, 6.0]

        pop(d):

            returns 5.5
            puts 6.0 into d

        So:

            ds1.pop(d)

        gives:

            return value = 5.5
            d            = 6.0

        Output:

            Pop ds1: 5.5 6
    */

    for (i = 0; i < 3; i++)
        std::cout << "Pop ds1: "
                  << ds1.pop(d)
                  << ' '
                  << d
                  << '\n';


    /*
        ds2:

            [2.2, 3.0]
            [4.5, 5.0]
            [6.6, 7.0]

        Pop order:

            [6.6, 7.0]
            [4.5, 5.0]
            [2.2, 3.0]

        Again:

            pop(d)

        returns the FIRST value and places the SECOND
        value into d.
    */

    for (i = 0; i < 3; i++)
        std::cout << "Pop ds2: "
                  << ds2.pop(d)
                  << ' '
                  << d
                  << '\n';


    return 0;
}
```

### In short, there are really only 4 major changes

You can use this as your quick mental map while looking at the two programs:

```text
OLD VERSION                         NEW VERSION
─────────────────────────────────────────────────────────────

StackType stck[SIZE];        →      StackType stck[SIZE][2];

push(StackType ob);         →      push(StackType ob,
                                         StackType ob2);

stck[tos] = ob;             →      stck[tos][0] = ob;
                                    stck[tos][1] = ob2;

StackType pop();            →      StackType pop(StackType &ob2);

return stck[tos];           →      ob2 = stck[tos][1];
                                    return stck[tos][0];

s1.push('a');               →      s1.push('a', 'b');

s1.pop();                   →      s1.pop(ch);
```

The **conceptual transformation** is simply:

```text
OLD

push(one object)
       ↓
   ┌───────┐
   │   A   │
   └───────┘


NEW

push(two objects)
       ↓
   ┌───────┬───────┐
   │   A   │   B   │
   └───────┴───────┘
```

And `pop()` has to change accordingly: **one value comes back through `return`, while the second comes back through the reference parameter `&ob2`.**





// ========  GPT compasct  ========




/*    Example 4: Rework the stack class so that each stack entry
    can store TWO values.
*/





// Push two objects
template <class StackType>
void stack<StackType>::push(StackType ob, StackType ob2) {

    if(tos == SIZE) {
        std::cout << " Stack is full .\n";
        return;
    }

    // OLD: stck[tos] = ob;
    // NEW: store the two values in columns 0 and 1.
    stck[tos][0] = ob;
    stck[tos][1] = ob2;

    tos++;
}


// Pop two objects
template <class StackType>
StackType stack<StackType>::pop(StackType &ob2) {

    if(tos == 0) {
        std::cout << " Stack is empty .\n";
        return 0;
    }

    tos--;

    // NEW: put the SECOND value into ob2.
    // '&' means the caller's variable is changed directly.
    ob2 = stck[tos][1];

    // OLD: return stck[tos];
    // NEW: return the FIRST value from column 0.
    return stck[tos][0];
}


int main() {

    // Demonstrate character stacks.
    stack<char> s1, s2;

    int i;

    // NEW: variable used to receive the second value from pop().
    char ch;

    // initialize the stacks
    s1.init();
    s2.init();

    // OLD: s1.push('a');
    // NEW: one stack entry now contains ('a', 'b').
    s1.push('a', 'b');

    s2.push('x', 'z');
    s1.push('b', 'd');
    s2.push('y', 'e');
    s1.push('c', 'a');
    s2.push('z', 'x');

    // OLD: s1.pop()
    // NEW: pop(ch) returns first value and puts second value in ch.
    for(i=0; i<3; i++)
        std::cout << "Pop s1: " << s1.pop(ch) << ' ' << ch << '\n';

    for(i=0; i<3; i++)
        std::cout << "Pop s2: " << s2.pop(ch) << ' ' << ch << '\n';


    // demonstrate double stacks
    stack<double> ds1, ds2;

    // NEW: receives the second double from pop().
    double d;

    // initialize the stacks
    ds1.init();
    ds2.init();

    // Each push now stores TWO doubles as one stack entry.
    ds1.push(1.1, 2.0);
    ds2.push(2.2, 3.0);
    ds1.push(3.3, 4.0);
    ds2.push(4.5, 5.0);
    ds1.push(5.5, 6.0);
    ds2.push(6.6, 7.0);

    // First value is returned; second value goes into d.
    for(i=0; i<3; i++)
        std::cout << "Pop ds1: " << ds1.pop(d) << ' ' << d << '\n';

    for(i=0; i<3; i++)
        std::cout << "Pop ds2: " << ds2.pop(d) << ' ' << d << '\n';

    return 0;
}
```

The **essential changes** are therefore just:

```cpp
StackType stck[SIZE][2];       // instead of [SIZE]

void push(StackType ob,
          StackType ob2);      // instead of one parameter

stck[tos][0] = ob;
stck[tos][1] = ob2;             // store the pair

StackType pop(StackType &ob2); // second value via reference

ob2 = stck[tos][1];             // get second value
return stck[tos][0];            // get first value
```

That's really the whole modification. The rest of the program is mostly just changing calls from `push(x)` to `push(x, y)` and from `pop()` to `pop(variable)`.





/* Example 10: 

                
*/








int main() {





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











/* Example 5: Show the general forms of try, catch, and throw. In short words, describe their operation. */


5. The general forms of try, catch, and throw are shown here:

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
cout << " Pop ds1 : " << ds1 .pop () << ’\n’;
for (i =0; i <3; i ++)
cout << " Pop ds2 : " << ds2 .pop () << ’\n’;

return 0;
}




/* Example 7: Check your compiler’s documentation. See whether it supports the terminate() and
unexpected() functions. Generally, these functions can be configured to call any function
you choose. If this is the case with your compiler, try creating your own set of customized
termination functions that handle otherwise unhandled exceptions. */




/* Example 8: Thought question: Give a reason why having new generate an exception is a better
approach than having new return null on failure. */




Cumulative Skills Check


/* 1. In Chapter 6, Section 6.7, Example 3, a safe array class was shown. On your own, convert
it into a generic safe array. */

/* 2. In Chapter 1, overloaded versions of the abs() function were created. As a better solution,
create a generic abs() function on your own that will return the absolute value of any
numeric object. */




Review Skills Check
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.
/* 1. What is a generic function and what is its general form?
2. What is a generic class and what is its general form?

3. Write a generic function called gexp() that returns the value of one of its arguments
raised to the power of the other. */


/* 4. In Chapter 9, Section 9.7, Example 1, a coord class that holds integer coordinates was
created and demonstrated in a program. Create a generic version of the coord class that
can hold coordinates of any type. Demonstrate your solution in a program. */


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



3. 

#include <iostream>

// Return a to the b.
template <class X> X gexp (X a, X b){
    X i, result =1;
    for (i =0; i<b; i++) result *= a;
    return result;
}

int main() {
cout << gexp(2, 3) << endl;
cout << gexp(10.0, 2.0);
return 0;
}

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


/* 5. try, catch, and throw work together like this: Put all statements that you wish to
monitor for exceptions within a try block, if an exception occurs, throw that exception
using throw and handle it with a corresponding catch statement. */


6. No.


/* 7. terminate() is called when an exception is thrown for which there is no corresponding
catch statement. unexpected() is called when an attempt is made to throw an exception
out of a function that is not specified in the function’s throw clause. */


8. catch(...).

