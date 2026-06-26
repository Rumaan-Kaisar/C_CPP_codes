
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



// --------  rev[26-Jun-2026]  --------



/*  Example 4: We can EXPLICITLY overload a GnF too. 
                In this case, that overloaded function (our version) 
                overrides (or "hides") the GnF relative to that specific version. 

                For example, consider following version of Example 1.
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



```

### Example 3: Generic Class (Singly Linked List)
```cpp
#include <iostream>
using namespace std;

template <class data_t> 
class list {    
    data_t data;
    list *next;
public:
    list(data_t d);               // Constructor declaration
    void add(list *node) {
        node->next = this; 
        next = 0; 
    }
    list* getnext() { return next; }
    data_t getdata() { return data; }
};

// Defining member function outside the class
template <class data_t> 
list<data_t>::list(data_t d) {  
    data = d;
    next = 0;
}   

int main() {    
    // Specifying the data type (char) inside < >
    list<char> start('a');
    list<char> *p, *last;
    
    // Build a list
    last = &start;
    for(int i = 1; i < 26; i++) {  
        p = new list<char>('a' + i);
        p->add(last);
        last = p;   
    }
    
    // Follow and print the list 
    p = &start;
    while(p) {  
        cout << p->getdata();
        p = p->getnext();
    }
    return 0;
}
```
*Note on Custom Types:* You can use generic classes to store custom structures. For example, if you have a `struct addr`, you can create a list of addresses using: `list<addr> obj(structvar);`





/*  











 






}

   When swapargs(i,j) is called, it invokes the explicitly overloaded version of swapargs() defined in the program (because of int values). 
Thus, the compiler does not generate this version of the generic swapargs() function because the GnF is overridden by the explicit overloading.
   Manual overloading of a template, as shown in this example, allows you to tailor a version of a GnF to accommodate a special situation. 
   In general, if you need to have different versions of a function for different data types, you should use overloaded functions rather than templates.





   Example 3: This program creates a very simple generic singly linked list class. 
It then demonstrates the class by creating a linked list that stores characters.

template <class data_t > class list {   data_t data ;
list *next ;
public :
list ( data_t d);
void add(list *node){
node -> next = this; 
next = 0; }
list *getnext(){ return next ; }
data_t getdata(){ return data ; }
};

// definition of member function 'list'

template <class data_t > list <data_t >:: list ( data_t d) {    data = d;
                        next = 0;}  int main(){ list<char>  start ('a');
        list<char>  *p, * last ;
        int i;
// build a list
    last = &start ;
    for (i=1; i <26; i++){  p = new list <char >( 'a' + i);
                 p->add ( last );
                 last = p;  }
// follow the list 
    p = &start ;
    while(p) {  cout << p-> getdata();
            p = p-> getnext();}
    return 0;}

   The actual data-type stored by the list is generic in the class declaration. Here objects and pointers are created inside main() that specify that the data-type of the list will be char.
   Setting data type in object declaration of a generic class-type: The desired data type is passed inside the angle brackets in the following declaration:
list< char > start('a') ;
   By simply changing the data-type specified "inside < >" when list objects are created, you can change the type of data stored by the list. For example, you could create another object that stores integers by using:
list< int > int_start(1) ;
   Use list to store data types that you create: For example, if you want to store address information, use following structure:
struct addr {   char name[40];
        char street[40];
        char city[30];
        char state[3];
        char zip[12]; }
    Then, to use list to generate objects that will store objects of type addr, use:              list< addr > obj( structvar );
 (assuming that structvar contains a valid addr structure)
   A template class can have more than one generic data type. Simply declare all the data types required by the class in a comma-separated list within the template specification.






**1. Using Multiple Generic Types**
* You are not limited to just one placeholder. You can define multiple generic data types by separating them with commas (e.g., `template<class type1, class type2>`).
* When you call the function, the compiler looks at the arguments you pass and automatically replaces the placeholders (`type1`, `type2`) with the actual data types (like `int`, `double`, `char*`) to generate the specific function.


   Example 4:  the following short example creates a class that uses two generic data types:
template <class Type_1 , class Type_2> class myclass{   Type1 i;
                        Type2 j;
             public : myclass( Type1 a, Type2 b) {  i = a;   j = b; }
             void show() { cout << i << ' ' << j << '\n'; }      
             }; int main(){         myclass< int, double > ob1 (10 , 0.23) ;
                  myclass<char , char *> ob2('X', " This is a test ");
        ob1.show();     // show int , double 
        ob2.show();     // show char , char *
       return 0; }
        This program produces the following output:      10     0.23
                                 X This is a test
   The program declares two types of objects. ob1 uses integer and double data. ob2 uses a character and a character pointer. 
   For both cases, the compiler automatically generates the appropriate data and functions for each object.

Note
[1] C++ provides a library that is built upon template classes. This library is usually referred to as the Standard Template Library, or STL for short. 
[2] STL provides generic versions of the most commonly used algorithms and data structures. 




--------    Qwen    --------

Here is the organized, clean, and pointwise version of your notes on Generic Functions and Generic Classes in C++. The formatting has been improved for readability, with code blocks properly indented and symbols replaced with standard bullet points.















---

## 5. Code Examples
`

### Example 2: 






### Example 4: Multiple Generic Data Types in a Class
```cpp
#include <iostream>
using namespace std;

template <class Type1, class Type2> 
class myclass {  
    Type1 i;
    Type2 j;
public: 
    myclass(Type1 a, Type2 b) {  i = a; j = b; }
    void show() { cout << i << ' ' << j << '\n'; }       
};  

int main() {         
    myclass<int, double> ob1(10, 0.23);
    myclass<char, char*> ob2('X', "This is a test");
    
    ob1.show(); // Outputs: 10 0.23
    ob2.show(); // Outputs: X This is a test
    
    return 0; 
}
```

---

## 6. Additional Notes
1.  **Standard Template Library (STL):** C++ provides a massive built-in library constructed entirely upon template classes, known as the STL.
2.  **STL Purpose:** It provides highly optimized, generic versions of the most commonly used algorithms (like sorting and searching) and data structures (like vectors, lists, and queues).


*/  
