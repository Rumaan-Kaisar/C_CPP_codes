
/*  ------------------------    copy constructor    ------------------------
    
    Problem while PASSING / RETURN objects to a function:

        Recall 10.10 PASSING objects to functions and RETURNING objects from function: 
            ch10_10_2_pass_ref_to_obj.cpp
            ch10_10_3_return_ref.cpp



        Problems when "Passing Objects" to a function:
            When an object is passed to a function, an exact copy (bitwise copy) of that object is created
                and given to the function parameter that receives the object

            ----  problems  ----
            If the object contains "pointers" to dynamically allocated memory, 
                both the "original" and the "copy" will point to the same memory. 

            Any changes made to the copy will also affect the original object.

            Additionally, when the function ends, the copy's destructor is called, 
                which "affect the original object" if it deallocates shared resources.



        Problems when "Returning Objects" from a function:
            When an object is returned from a function, a "temporary object" is often created to hold the return value. 

            ----  problems  ----
            This temporary object goes out of scope once the value is returned to the calling routine, 
                causing the temporary object's destructor to be called.

            If the destructor destroys important resources (like dynamically allocated memory), 
                it could "cause issues" in the calling function that needs those resources.




    --------  Creating and using a copy constructor  --------
    The core of the above issues is that a "bitwise (exact) copy of the object" is being made. 
    By defining a "copy constructor", you can "control what happens" when an object is copied.

    Two Types of Object Copying:
        Assignment: 
            When one object is "assigned" to another after both have been created.
        
        Initialization: This occurs in three cases:
            When an object is used to "initialize" another in a declaration.
            When an object is passed to a function as a "parameter".
            When a temporary object is created as a "return value" from a function.


    Copy Constructor vs Assignment
        The copy constructor only applies to initializations, not assignments.



    --------  Declaring, defining & invoking (activating) copy-constructor  --------
    By default, when an initialization occurs, C++ provides a copy constructor that simply duplicates the object. 

    However, you can create a custom copy constructor to specify "how one object initializes another". 
        A typical copy constructor looks like this:

                    class_name(const class_name &obj) {
                        body of constructor
                    }

        "obj" is a reference to an object that is being used to initialize another object
        "const" is an access modifier (recall C_Ch7_3_2_acs_modfyr_constVolatile.c)
            const ensures that obj cannot be modified


    How to declare & define : 
        For a class "myclass" with an object 'y' of type 'myclass', the declaration of the copy constructor is:

                    myclass(const myclass &ob);
                    // const is an access modifier recall C_Ch7_3_2_acs_modfyr_constVolatile.c


            The definition would be:  
                    myclass :: myclass( const myclass &ob) {
                        body of copy-constructor
                    }


            Invoking the Copy Constructor:
                Three types of statements can invoke the  myclass copy constructor:

                1.     myclass x = y;       // y explicitly initializing x 
                2.     fun1 (y);            // y passed as a parameter 
                3.     y = func2 ();        // y receiving a returned object 

                In the first two cases, a "reference to y" would be passed to the copy constructor. 
                In the third, a "reference to the object" returned by func() is passed to the copy constructor.

*/  




/*  Example 1: This program creates a " safe " array class. 
                Since space for the array is dynamically allocated , a copy constructor is provided 
                    to allocate memory when one array object is used to initialize another. 

                That copy constructor ensures that when one array object initializes another, 
                    separate memory is allocated for the copy.
*/
#include <iostream>
#include <cstdlib> 			// to use exit() 


class array {	
        int *p, size;
    public: 
        array (int sz);             // constructor 
        array(const array &a);      // copy constructor 
        ~array() { delete [] p; }   // destructor 
        void put(int i, int j) { if(i>=0 && i<size) p[i] = j; }
        int get(int i) { return p[i]; }	
};


// ----  constructor  ----
array :: array(int sz) {
    p = new int [sz];
    if(!p){
        std::cout<< " Allocation error "; 
        exit(1);
    }
    size = sz;
    std::cout << "Using 'normal' constructor \n";      
}


// ----  Copy constructor  ----
// In the following, memory is allocated specifically for the copy, and the address of this memory is assigned to p. 
// Therefore, p is not pointing to the same dynamically allocated memory as the original object.
array :: array(const array &a) { 
    int i;

    size = a.size ;
    p = new int [a.size]; // allocate memory for copy
    if(!p){
        std::cout<< " Allocation error "; 
        exit(1);
    }

    for(i=0; i < a.size; i++) p[i]=a.p[i]; // copy contents
    std::cout << " Using copy constructor \n"; 
}



int main(){
    array num(10);  // calls "normal" constructor 
    int i;

    // put some values into the array
    for(i=0; i<10; i++) num.put(i, i); // array value 
    for(i=9; i>=0; i--) std::cout<<num.get(i); // display num
    std::cout << "\n";

    // create another array and initialize with num 
    array x = num;  // this invokes copy constructor 
    for(i=0; i<10; i++) std::cout<< x.get(i); // display x 
    
    return 0; 
}


/*  When "num" is used to initialize "x", the Copy Constructor is called. 
    It allocates new memory for "x.p" and copies the contents from "num" into "x", i.e. x's array. 

    This ensures that "x" and "num" have identical but separate arrays 
        (i.e., num.p and x.p point to different memory locations).


    If no copy constructor existed, the bitwise initialization "array x = num;" would have 
        resulted in both arrays sharing the same memory, causing both to reference the same data.
        (i.e. num.p and x.p would have pointed to the same location.)

    The copy constructor is called only used for "initialization", not for assignment.
        For example, the following sequence "does not call the copy constructor" defined in the preceding program:

                array a(10);
                array b(10);
                b = a;  // This performs an assignment, not a copy constructor call.

*/




/* 


// --------    rev[23-Sep-2024]    --------

	Here in the copy constructor, memory is allocated specifically for the copy , and the address of this memory is assigned to p. Therefore , p is not pointing to the same dynamically allocated memory as the original object .
	When copy-constructor is called: When num is used to initialize x (i.e., array x = num; ) the copy constructor is called, memory for the new array is allocated and stored in x.p, and the contents of num are copied to x's array.  In this way, x and num have arrays that have the same values, but each array is separate and distinct. (That is, num.p and x.p do not point to the same piece of memory.) 
	If the copy constructor had not been created, the bitwise initialization array x = num; would have resulted in x and num sharing the same memory for their arrays! (That is, num.p and x.p would have pointed to the same location.)
	When copy-constructor is not called: The copy constructor is called only for initializations. Copy constructors do not affect assignment operations. For example, the following sequence does not call the copy constructor defined in this program: 
array a(10) ; array b(10) ; b = a;       ( b = a performs the assignment operation. Rather calling copy-constructor) 
Note: Old Overload keyword : For old C++ compiler the keyword overload was required to create an overloaded function. It is now 
obsolete and no longer supported by modern C++ compilers. The general form:
overload func_name ; 	(It must precede the overloaded function declarations)
where func_name is the name of the function to be overloaded..  
*/


#include <cstdlib> // for exit()

class array {
    int *p, size;
public:
    array(int sz);               // normal constructor
    array(const array &a);       // copy constructor
    ~array() { delete[] p; }     // destructor
    
    void put(int i, int j) { 
        if (i >= 0 && i < size) 
            p[i] = j; 
    }
    
    int get(int i) { return p[i]; }
};

// Copy constructor
array::array(const array &a) {
    size = a.size;
    p = new int[a.size]; // allocate memory for the copy
    if (!p) { 
        std::cout << "Allocation error"; 
        exit(1); 
    }
    
    for (int i = 0; i < a.size; i++) 
        p[i] = a.p[i]; // copy contents
    std::cout << "Using copy constructor\n";
}

// Normal constructor
array::array(int sz) {
    p = new int[sz];
    if (!p) { 
        std::cout << "Allocation error"; 
        exit(1); 
    }
    
    size = sz;
    std::cout << "Using 'normal' constructor\n";
}

int main() {
    array num(10); // calls normal constructor
    for (int i = 0; i < 10; i++) 
        num.put(i, i); // populate array values
    
    for (int i = 9; i >= 0; i--) 
        std::cout << num.get(i) << " "; // display array
    
    std::cout << "\n";
    
    // Create another array and initialize with num
    array x = num; // calls copy constructor
    for (int i = 0; i < 10; i++) 
        std::cout << x.get(i) << " "; // display x
    
    return 0;
}


/* 

Key Points:
Memory Allocation in Copy Constructor:
The copy constructor allocates separate memory for the new object and copies the contents from the original object. This prevents the two objects from sharing the same memory.

When Copy Constructor is Called:
The copy constructor is invoked when an object is used to initialize another, such as array x = num;. This ensures that num and x have separate arrays with identical values.

If No Copy Constructor:
Without the copy constructor, x = num; would result in both x and num pointing to the same memory location, leading to unintended modifications.

Copy Constructor vs. Assignment:
The copy constructor only applies during initialization, not during assignment. For example, b = a; performs an assignment and does not invoke the copy constructor.


Note:
Old Overload Keyword:
In older C++ compilers, the overload keyword was required to define overloaded functions. This is now obsolete and no longer supported by modern compilers.


*/



2. To see how the copy constructor helps prevent some of the problems associated with
passing certain types of objects to functions, consider this (incorrect) program:
// This program has an error .
# include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
public :
strtype ( char *s);
~ strtype () { delete [] p; }
char * get () { return p; }
};
strtype :: strtype ( char *s)
{
int l;
l = strlen (s) +1;
p = new char [l];


if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, s);
}
void show ( strtype x)
{
char *s;
s = x. get ();
cout << s << "\n";
}
int main ()
{
strtype a(" Hello "), b(" There ");
show (a);
show (b);
return 0;
}
/* In this program, when a strtype object is passed to show(), a bitwise copy is made (since
no copy constructor has been defined) and put into parameter x. Thus, when the function
returns, x goes out of scope and is destroyed. This, of course, causes x’s destructor to
be called, which frees x.p. However, the memory being freed is the same memory that is
still being used by the object used to call the function. This results in an error.
The solution to the preceding problem is to define a copy constructor for the strtype
class that allocates memory for the copy when the copy is created. This approach is used
by the following, corrected, program: */


/*
This program uses a copy constructor to allow strtype
objects
to be passed to functions .
*/
# include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
public :
strtype ( char *s); // constructor
strtype ( const strtype &o); // copy constructor

~ strtype () { delete [] p; } // destructor
char * get () { return p; }
};
// " Normal " constructor
strtype :: strtype ( char *s)
{
int l;
l = strlen (s) +1;
p = new char [l];
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, s);
}
// Copy constructor
strtype :: strtype ( const strtype &o)
{
int l;
l = strlen (o.p) +1;
p = new char [l]; // allocate memory for new copy
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, o.p); // copy string into copy
}
void show ( strtype x)
{
char *s;
s = x. get ();
cout << s << "\n";
}
int main ()
{
strtype a(" Hello "), b(" There ");
show (a);
130FUNCTION OVERLOADING
5.2. CREATING AND USING A COPY CONSTRUCTOR
show (b);
return 0;
}
Now when show() terminates and x goes out of scope, the memory pointed to by x.p
(which will be freed) is not the same as the memory still in use by the object passed to
the function



// EXERCISES
1. The copy constructor is also invoked when a function generates the temporary object that
is used as the function’s return value (for those functions that return objects). With this
in mind, consider the following output:
Constructing normally
Constructing normally
Constructing copy
This output was created by the following program. Explain why, and describe precisely
what is occurring.
# include <iostream >
using namespace std ;
class myclass
{
public :
myclass ();
myclass ( const myclass &o);
myclass f();
};
// Normal constructor
myclass :: myclass ()
{
cout << " Constructing normally \n";
}
// Copy constructor
myclass :: myclass ( const myclass &o)
{
cout << " Constructing copy \n";
}
// Return an object .
myclass myclass ::f()
{
myclass temp ;
return temp ;
}
131TEACH YOURSELF
C++
int main ()
{
myclass obj ;
obj = obj .f();
return 0;
}



2. Explain what is wrong with the following program and then fix it.
// This program contains an error .
# include <iostream >
# include <cstdlib >
using namespace std ;
class myclass
{
int *p;
public :
myclass ( int i);
~ myclass () { delete p; }
friend int getval ( myclass o);
};
myclass :: myclass ( int i)
{
p = new int ;
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
} *
p = i;
}
int getval ( myclass o)
{
return *o.p; // get value
}
int main ()
{
myclass a (1) , b (2) ;
cout << getval (a) << " " << getval (b);
cout << "\n";
cout << getval (a) << " " << getval (b);
return 0;
}
132FUNCTION OVERLOADING
5.3. THE OVERLOAD ANACHRONISM



3. In your own words, explain the purpose of a copy constructor and how it differs from a
normal constructor.


