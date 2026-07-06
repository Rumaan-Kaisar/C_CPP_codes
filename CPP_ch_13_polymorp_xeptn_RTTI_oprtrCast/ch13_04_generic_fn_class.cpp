
/*  ------------------------    Generic-Functions & Generic-Classes (reusable code)    ------------------------

    Core Concepts of GENERICS:
        Generic functions and classes allow for the creation of "reusable code".
        In a generic function or class, the type of data that operated upon is specified as a parameter.

        We create generic functions  & classes using "templates". 
        A GnF is created using the keyword "template".

        Purpose:
            Allows a single function or class to work with "multiple different data types" 
            without writing explicit, repetitive code for each type.

        Data Independence:
            Generics define the nature of an algorithm independently of the data. 
            The compiler automatically generates the correct code for the specific data type during execution.

        Use Case:
            Highly useful when algorithms are logically identical regardless of the data type 
            (e.g., the Quicksort algorithm works the same way for integers and floats; only the data type differs).



    ----------------    Generic functions (GnF)    ----------------

    A Generic Function (GnF) defines a general set of operations applied to "various data types". 
    The "data type" that it will operate upon passed to it as a parameter. 

    By a Gnf the function can automatically overload itself.
    The compiler automatically generates the correct code for the type of data during function execution. 

    Benefits:
        A GnF is the data-independent-code which defines the nature of the algorithm. 
        
        It helps a lot because many algorithms are logically the same 
            no matter what type of data is being operated upon. 
            
        For example: 
            the Quicksort algorithm is applicable for both integers and floats.  
            It is just that the type of the data being sorted is different.


    --------  template  --------

    In C++ the keyword "template"  is used to create a template (or framework) 
        that describes what a function will do, 
        leaving it to the compiler to fill in the details as needed. 

    The general form of a template is:

                template <class Ttype> return_type func_name(parameter list){ 
                    // body of function 
                }

        Ttype:
            A placeholder name for the data type. 
            The compiler replaces this with the actual data type during execution.

        class:
            Used to specify a generic type. 
            The keyword "typename" can also be used interchangeably 
            (e.g.,  template <typename Ttype>).


    --------  Key Terminology  --------

    Template Function:      A generic function (a function definition preceded by a "template" statement).
    Generated Function:     A specific version of the function created by the compiler for a specific data type.

    Instantiating:          The act of generating a specific function. 
                            A generated function is a specific instance of a template function.


    Definition formatting:
        The template portion of a GnF definition does not have to be on the same line as the function's name. 
        For example:

                template <class X>
                    void swapargs(X &a, X &b) { 
                        X temp;
                        temp=a;
                        a=b;
                        b=temp;
                }

        No other statements can occur between the "template statement" and the start of the "GnF definition".
        For example, the following fragment will not compile:

                template <class X>

                int i;  // this line causes error

                void swapargs(X &a, X &b) { 
                    X temp;
                    temp=a;
                    a=b;
                    b=temp;
                }



    ========  Important Rules  ========

    No Intermediate Statements:
        No other statements can occur between the "template" statement and the "start of the function definition".

        Incorrect:  
                    template <class X> int i; 
                    void swapargs(...) { ... } 
                    
                    (Causes a compilation error).


    When you create a GnF, you are, in essence, allowing the compiler to generate 
        as many different versions of that function as necessary 
        to handle the various ways that your program calls that function.

        For example, if the function is called with "int", "double", and "char", 
            the compiler creates appropriate versions for those types.




    ----------------    Generic-Classes (GnC)    ----------------

    A Generic Class defines all algorithms used by the class, 
    But the actual data type being manipulated is specified as a parameter when objects are created.

    GnC are useful when a class contains generalizable logic (i.e when data types varies). 
    For example: 
        By using a GnC, you can create a class that will maintain a queue, a linked list, and so on for any type of data. 

    The compiler will automatically generate the correct type of object based upon the "type" you specify when the object is created.
    Member functions of a GnC are, themselves, automatically GnF. They "need not be explicitly specified" as such using template.


    The general form of a GnC:

                template <class Ttype> class class_name { 
                    // class members
                    . . .
                    . . . 
                };

        "Ttype" is the placeholder type name that will be specified when a class is instantiated.

        Multiple generic types can be defined using a comma-separated list: 

                template <class T1, class T2, . . .>


    Object Instantiation:
        Once a GnC created, we can create a "specific instance" of that class by using the following general form:

                class_name <type> object_name;

        Here "type" is the "type name" of the data that the class will be operating upon.

        Note: 
            Unlike normal classes, you must specify the data type inside angle brackets "< >" when creating the object.
            Note that- we're using "class_name <type> obj_name;" instead of ordinary "class_name obj_name;".


    Member Functions:
        Member functions of a GnC are automatically generic. 
        They do not need to be explicitly defined with a "template" prefix inside the class.


    Access/Define Member Functions Outside the Class:
        We can access/define any function/member of a generic class "outside" of it by using: 

                template <class Ttype> return_type class_name<Ttype> :: member_function(parameters) {
                    // function body
                }

        you must use the "template" prefix and append "<type>" to the class name.
    
    
    The key point is:
        that "class_name <type>" considered the class name instead of ordinary "class_name" 
        to define an object of its type or accessing any member outside of it.


    --------    "typename" vs. "class"    --------

    You can use "typename" instead of "class" to specify a generic type in a template definition.

                template <typename X> void swapargs(X &a, X &b) { 
                    X temp;
                    temp=a;
                    a=b;
                    b=temp;
                }

        In this context, "template <typename X>" and "template <class X>" mean the exact same thing.
        The "typename" keyword is used to specify an "unknown type" within a template.



    --------  STL: Standard Template Library  --------

    C++ provides a library that is built upon template classes. 
    This library is usually referred to as the "Standard Template Library", or STL for short. 
    STL provides generic versions of the most commonly used "algorithms" and "data structures". 
*/




/* Example 1: The following program creates a GnF / Function template 
                that "swaps the values" of the two variables it is called with. 

                (We're using Generics because the way to swap two values does not depend on their type.)
*/

#include <iostream>

// Generic Function Definition
template <class X> void swapargs(X &a, X &b) {       
    X temp;
    temp = a;
    a = b;
    b = temp;  
}

int main() {    
    int i = 10, j = 20;
    float x = 10, y = 23.3;
    
    std::cout << "Original i, j: " << i << ' ' << j << std::endl;
    std::cout << "Original x, y: " << x << ' ' << y << std::endl; 
        
    swapargs(i, j); // Compiler generates int version to swap integers
    swapargs(x, y); // Compiler generates float version to swap floats

    std::cout << "Swapped i, j: " << i << ' ' << j << std::endl;
    std::cout << "Swapped x, y: " << x << ' ' << y << std::endl;
        
    return 0; 
}


/*  
    The keyword "template" is used to define a generic function. 


    The line:
                template <class X> void swapargs(X &a, X &b)
    
        tells the compiler two things that:
            a template is being created and 
            a generic definition is beginning. 

        Here X acts as a placeholder for a data type (instead of a specific type like "int" or "float").

        After the template portion, function swapargs() is declared, 
            using X as the data type of the values that will be swapped. 


    Inside main(), the swapargs() is called using two different types of data: "int" and "float". 
    Because swapargs() is a GnF, the compiler automatically creates two versions of swapargs()
        one that will exchange integer values and 
        one that will exchange floating-point values. 
*/




/* Example 2: To define "more than one" generic data-type with the template statement, 
                use a comma-separated list.

                When creating instances of myfunc(), the compiler replaces 
                the placeholders type1 and type2 with actual data types:
                    First instance:     int and char*
                    Second instance:    double and long
*/

#include <iostream>

template <class type1, class type2> void myfunc(type1 x, type2 y){ 
    std::cout<< x <<' '<< y << std::endl;
}

int main(){
    // Compiler generates a version for (int, const char*)
    myfunc(10 , "hi");

    // Compiler generates a version for (double, long)
    myfunc(0.23 , 10L);
    
    return 0;
}




/*  ----------------    Generics vs. Function Overloading    ----------------

    GnF are similar to overloaded functions except that they are more "RESTRICTIVE".

    Standard Overloaded Functions:
        Can perform completely different actions within the body of each function version.
        Example:
            One version might just print an integer, 
            while another prints a double with specific precision and fill characters.

    Generic Functions:
        "Must" perform the exact same general algorithm/action for all data types. 
        Rule:
            Use regular function overloading, not templates, if different data types 
            require completely different logic.
    
    Example:
        Following overloaded functions cannot be replaced by a Gnf 
        because they do not do the same thing:

                void outdata(int i){ 
                    std::cout << i;
                }
                void outdata(double d){
                    std::cout << setprecision(10) << setfill ('#');
                    std::cout << d;
                    std::cout << setprecision(6) << setfill (' ');
                }


    --------  Explicit Overloading of a Template Function  --------

    You can manually overload a generic function for a specific data type. 
    If you do this, your explicitly overloaded version overrides (hides) the generic version for that specific data type.
*/




/*  Example 3: If your functions need to do different things based on the data type, you "must" use function overloading. 
                In the following "outdata" program, the "int" version simply prints the number, 
                while the "double" version adds special formatting (like '#' fills and specific decimal precision). 
                Because the internal actions are completely different, a single generic function cannot replace them.
*/


#include <iostream>
#include <iomanip>      // Required for setprecision and setfill

// Overloaded function 1: Just prints the integer
void outdata(int i) { 
    std::cout << "Int: " << i << std::endl; 
}

// Overloaded function 2: Prints the double with special formatting
void outdata(double d) {     
    std::cout << "Double: ";
    std::cout << std::setprecision(10) << std::setfill('#');
    std::cout << d << std::endl;
    
    // Reset formatting back to normal
    std::cout << std::setprecision(6) << std::setfill(' '); 
}

int main() {
    outdata(42);          // Calls the int version
    outdata(3.14159265);  // Calls the double version
    return 0; 
}




/*  Example 4: We can EXPLICITLY overload a GnF too. 
                In this case, that overloaded function (our version) 
                overrides (or "hides") the GnF relative to that specific version. 

                For example, consider following version of Example 1.

                When swapargs(i, j) is called, the program uses the explicitly overloaded swapargs() function 
                    because the arguments are of type int. 
                    
                Therefore, the compiler does not create the generic swapargs() function for "int" values, 
                    since the explicit version overrides it.
*/

#include <iostream>

template <class X> void swapargs(X &a, X &b) { 
    X temp; 
    temp = a; 
    a = b; 
    b = temp; 
}

// Explicitly overloaded version for integers (Overrides the GnF for ints)
void swapargs(int a, int b) { 
    std::cout << "This is inside swapargs(int, int)\n"; 
}   

int main() {    
    int i = 10, j = 20;
    float x = 10.0, y = 23.3;
    
    std::cout << " Original i, j: " << i << ' ' << j << std::endl;
    std::cout << " Original x, y: " << x << ' ' << y << std::endl;

    swapargs(i, j); // Calls the explicit overloaded version (int)
    swapargs(x, y); // Calls the generic version (float)
    
    std::cout << " Swapped i, j: " << i << ' '<< j << std::endl;
    std::cout << " Swapped x, y: " << x << ' ' << y << std::endl;

    return 0; 
}




/*  Example 5: Manual Overloading of a template, 
                as shown in this example, it allows you to tailor a version of a GnF to accommodate a special situation. 

                In general, if you need to have different versions of a function for different data types, 
                    you should use overloaded functions rather than templates.

                Following program creates a very simple generic "Singly Linked List" class. 
                It then demonstrates the class by creating a linked list that stores characters.
*/

#include <iostream>
 
template <class data_t> class list {
        data_t data;
        list *next;
    public:
        list(data_t d);     // constructor declaration
        void add(list *node){
            node->next = this; 
            next = 0;
        }
    list* getnext(){ return next; }
    data_t getdata(){ return data; }
};


// definition of member function (constructor) 'list'
template <class data_t> list <data_t>::list(data_t d) {
    data = d;
    next = 0;
}


int main(){
    // Specifying the data type (char) inside < >
    list <char>  start('a');
    list <char>  *p, *last;
    int i;

    // build a list
    last = &start ;
    for(i=1; i<26; i++){
        p = new list <char> ('a' + i);
        p->add(last);
        last = p;
    }

    // follow the list and print
    p = &start;
    while(p) {
        std::cout << p->getdata();
        p = p->getnext();
    }
    
    return 0;
}


/* In the above program-
    The "actual data-type" stored by the "list" is generic in the "class declaration". 
    Here objects and pointers are created inside main() that specify that the data-type of the list will be "char".

    Setting "data type" in "object declaration" of a generic class-type: 
        The desired data type is passed inside the angle brackets in the following declaration:

                list <char> start('a');

    By simply changing the data-type specified "inside < >" when list objects are created, 
        you can change the "type of data" stored by the list. 
        For example, 
            You could create "another object" that stores "integers" by using:

                list <int> int_start(1);


    ----------------    Custom Types    ----------------
    
    You can use generic classes to store custom structures. 
    For example, if you have a "struct addr", you can create a list of addresses using: 

                list<addr> obj(structvar);

        Use "list" to store user defined data types "struct":
        For example, if you want to store address information, use following structure:

                struct addr {
                    char name[40];
                    char street[40];
                    char city[30];
                    char state[3];
                    char zip[12];
                }
    
        Then, to use list to generate objects that will store objects of type "addr", use:
        
                list <addr> obj(struct_var);
            
            (assuming that struct_var contains a valid "addr" structure)
*/




/*  ----------------    Multiple generic types    ----------------

    A template class can have more than one generic data type. 

    Simply declare all the data types required by the class 
        in a comma-separated list within the template specification.

                template <class type1, class type2, ... >

        When you call the function, the compiler looks at the arguments you pass and 
            automatically replaces the placeholders ("type1", "type2") 
            with the actual data types (like "int", "double", "char*") to generate the specific function.

*/




/* Example 6:  The following program creates a class that uses two generic data types. 

                The program declares two types of objects. 
                    ob1 uses integer and double data. 
                    ob2 uses a character and a character pointer.

                For both cases, the compiler automatically generates the appropriate data and functions for each object.
*/

#include <iostream>

template <class Type1 , class Type2> class myclass{
        Type1 i;
        Type2 j;
    public:
        myclass(Type1 a, Type2 b) {
            i = a;
            j = b;
        }
        void show(){
            std::cout << i << ' ' << j << '\n'; 
        }
};

int main(){
    myclass <int, double> ob1(10 ,0.23);
    myclass <char, char*> ob2('X', " This is a test ");
    
    ob1.show();     // show int , double  i.e. Outputs: 10 0.23
    ob2.show();     // show char , char * i.e. Outputs: X This is a test

    return 0;
}






// ----  rev[04-Jun-2026]  ----



// --------  Generic-Functions  --------



/* 
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
differently, a generated function is a specific instance of a template function. */




/* Example 2: The template portion of a generic function definition does not have to be on the same
line as the function’s name. For example, the following is also a common way to format
the swapargs() function: */
template <class X>
void swapargs (X &a, X &b)
{
X temp ;
temp = a;
a = b;
b= temp ;
}

/* If you use this form, it is important to understand that no other statements can occur
between the template statement and the start of the generic function definition. For
example, the following fragment will not compile: */

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
/* As the comments imply, the template specification must directly precede the rest of the
function definition. */




/* Example 3: As mentioned, instead of using the keyword class, you can use the keyword typename
to specify a generic type in a template definition. For example, here is another way to
declare the swapargs() function. */
// Use typename
template <typename X> void swapargs (X &a, X &b)

{
X temp ;
temp = a;
a = b;
b= temp ;
}
The typename keyword can also be used to specify an unknown type within a template,
but this use is beyond the scope of this book.




/* Example 4: You can define more than one generic data type with the template statement, using a
comma-separated list. For example, this program creates a generic function that has two
generic types: */
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
/* In this example, the placeholder types type1 and type2 are replaced by the compiler with
the data types int and char * and double and long, respectively, when the compiler
generates the specific instances of myfunc().
Remember: When you create a generic function, you are, in essence, allowing the
compiler to generate as many different versions of that function as necessary to handle
the various ways that your program calls that function. */




/* Example 5: Generic functions are similar to overloaded functions except that they are more restrictive.
When functions are overloaded, you can have different actions performed within the body
of each function. But a generic function must perform the same general action for all
versions. For example, the following overloaded functions cannot be replaced by a generic
function because they do not do the same thing: */
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




/* Example 6: Even though a template function overloads itself as needed, you can explicitly overload
one, too. If you overload a generic function, that overloaded function overrides (or *hides*)
the generic function relative to that specific version. For example, consider this version of
Example 1: */
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
/* generate this version of the generic swapargs() function because the generic function is
overridden by the explicit overloading.
Manual overloading of a template, as shown in this example, allows you to tailor a version
of a generic function to accommodate a special situation. However, in general, if you need

to have different versions of a function for different data types, you should use overloaded
functions rather than templates. */






1. If you have not done so, try each of the preceding examples.

/* 2. Write a generic function, called min(), that returns the lesser of its two arguments. For
example, min(3, 4) will return 3 and min(’c’, ’a’ will return a. Demonstrate your
function in a program. */


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


/* 
3. A good candidate for a template function is called find(). This function searches an array
for an object. It returns either the index of the matching object (if one is found) or -1 if no
match is found. Here is the prototype for a specific version of find(). Convert find() into
a generic function and demonstrate your solution within a program. (The size parameter
specifies the number of elements in the array.)
int find ( int object , int *list , int size )
{
// ...
}
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




/* 4. In your own words, explain why generic functions are valuable and may help simplify the
source code to program that you create. */


4. Generic functions are valuable because they allow you to define a general algorithm that
can be applied to various types of data. (That is, specific versions of the algorithm need
not be explicitly created by you.) Generic functions further help implement the concept
of "one interface, multiple methods," which is a common theme in C++ programming.



*/  
