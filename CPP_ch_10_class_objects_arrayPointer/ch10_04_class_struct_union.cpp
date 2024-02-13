
/*  ----------------    structures-unions and classes    ----------------
    
    -=-=-=-    structures    -=-=-=-
    
    Structures:
        General form of a structure in C++ :

            struct type_name {
                    // PUBLIC function and data members
                private :
                    // PRIVATE function and data members
            } object_list;


    Note:
        by default members of a STRUCTURE are "public"
        by default members of a CLASS are "private"


    Relation between STRUCTURES and CLASSES:
        The 'class' and the 'structure' have virtually IDENTICAL capabilities.  
        In C++ structures include 'member functions', including constructor and destructor functions. 

        Only difference between a 'structure' and a 'class' is: 
            by default, the members of a CLASS are 'private' but 
            the members of a STRUCTURE are 'public'. Because in C all structure members are public by default. 

        In C++  both 'struct' and 'class' create new class types.


    private:
        it tells the compiler that the members that follow are 'private to that class'  (applicable for both class and structure).




    -=-=-=-    unions    -=-=-=-

    Unions: 
        In C++, a union defines a class type that can contain both "functions and data" as members. 
            All members are 'public' by default until the 'private' specifier is used. 
            All data members share the 'same memory location' (just as in C). 
            Unions can contain 'constructor' and 'destructor'

        Why it's unique?
            Union links code and data 
            It allows you to create "class types" in which all data uses a "SHARED LOCATION".
            you cannot do this kind of "shared location" using a CLASS.


        restrictions to apply UNIONS
            no inheritance:
                UNIONS cannot inherit any other class and they cannot be used as a base class for any other type. 

            object constructor/destructor not allowed:
                UNIONs 'must not contain' any OBJECT that has a constructor or destructor. 
                The union, itself, 'can have' a constructor and destructor though. 

            no static members:
                Unions must not have any static members.

            no virtual fn:
                UNIONs 'cannot have' virtual member functions. (Virtual functions are described later.)



    -=-=-=-    anonymous union    -=-=-=-

    Anonymous union: 
        An anonymous union special type of union that "does not have a TYPE name", and 
        No 'variables' can be declared for this sort of union. 
        Instead, it tells the compiler that its 'members' will share the "same memory location".
        
        However, in all other, respects, the 'members' act and are treated like "normal variables". 
        i.e. the members are "accessed DIRECTLY," without the dot '.' operator syntax.  
        
        Anonymous union tells the compiler that you want 'two or more variables' to share the "same memory" location.

        For example, examine this fragment:

                union {    // an anonymous union
                    int i; 
                    char ch[4]; 
                }; 	

                // access i and ch directly
                i = 10; 
                ch[0] = 'X'; 		

            Here 'i' and 'ch' are accessed directly because they are 'not part of any object'. 
                They share the same memory space.


    restrictions:
        Anonymous unions have all of the restrictions that apply to normal unions, plus these additions.
        A 'global anonymous union' must be declared "static". 
        An anonymous union CANNOT contain 'PRIVATE' members. 
        The NAMES of the members of an anonymous union 'must not conflict' with other identifiers within the same scope.


    Note
        [1]	Although structures have the same capabilities as classes, 
                most programmers restrict their use of 'structures' to "adhere to their C-like form" and do not use them to include function members.

        [2]	We reserve the use of struct for objects that have 'no function members'.

*/



/* Example 1: Here is a short program that uses 'struct' to create a class */
#include <iostream>
#include <cstring>

// making a CLASS using STRUCTURE: use struct to define a class type
struct st_type {
        // following members are "public" by default
        st_type(double b, char *n); // constructor
        void show();
    private:    // following members are "private"
        double balance;
        char name[40];
};

st_type::st_type(double b, char *n){
    balance = b;
    strcpy(name, n);
}

void st_type::show(){
    std::cout << " Name : " << name;
    std::cout << ": $" << balance;
    if(balance < 0.0) std::cout << "**";
    std::cout << "\n";
}


int main(){
    st_type acc1(100.12 , " Johnson ");
    st_type acc2( -12.34 , " Hedricks ");
    acc1.show();
    acc2.show();

    return 0;
}

// Notice,
// the members of a structure are public by default. 
// The private keyword must be used to declare private members.





/*  ------------    Differences Between the C and C++ Structures    ------------
    C Structures:
        Only 'data members' are allowed, it cannot have 'member functions'.
        Cannot have 'static' members.
        Cannot have a 'constructor' inside a structure.
        'Direct Initialization' of data members is not possible.
        Writing the ‘struct’ keyword is necessary to declare structure-type variables (objects).
        Do not have access modifiers (public, private).
        Only 'pointers to structs' are allowed.
        'Sizeof' operator will generate 0  for an empty structure.
        Data Hiding is not possible.


    C++ Structures:
        Can hold both: member functions and data members.
        Can have 'static' members.
        'Constructor' creation is allowed.
        'Direct Initialization' of data members is possible.
        Writing the ‘struct’ keyword is not necessary to declare structure-type variables (objects).
        Supports access modifiers (public, private).
        Can have both 'pointers' and 'references' to the struct.
        'Sizeof' operator will generate 1 for an empty structure.
        Data Hiding is possible.


    Difference between 'C-like structures' and "C++-like structures" object declaration:
    object declaration:
        C:      struc tag_name obj_name;
                In C, the tag-name 'st_type' requires the keyword "struct" precede it before it becomes a complete type.
        
        C++:    tag_name obj_name;
                The structure tag-name 'st_type' also becomes a complete type name that can be used to declare objects. 

*/




/* Example 2: Here is the above program, rewritten using a class 
                The only change is: re-arranging the 'public' and 'private' members
*/
#include <iostream>
#include <cstring>

// making a CLASS using STRUCTURE: use struct to define a class type
struct cl_type {
        double balance;
        char name[40];
    public:
        cl_type(double b, char *n); // constructor
        void show();
};

cl_type::cl_type(double b, char *n){
    balance = b;
    strcpy(name, n);
}

void cl_type::show(){
    std::cout << " Name : " << name;
    std::cout << ": $" << balance;
    if(balance < 0.0) std::cout << "**";
    std::cout << "\n";
}


int main(){
    cl_type acc1(100.12 , " Johnson ");
    cl_type acc2( -12.34 , " Hedricks ");
    acc1.show();
    acc2.show();

    return 0;
}




/* Example 3: Following program uses a UNION to display the 'binary bit pattern', 
                byte by byte, contained within a double value. */
#include <iostream>

union bits{
    bits(double n);
    void show_bits();
    double d;
    unsigned char c[sizeof(double)];
};

bits::bits(double n){
    d = n;
}


// print the bit-pattern
void bits::show_bits(){
    int i, j;
    for(j = sizeof(double)-1; j >=0; j --){
        std::cout << " Bit pattern in byte " << j << ": ";
        for (i = 128; i; i >>= 1){   // bitwise right shift
            if(i & c[j]) std::cout << "1";  // checking the bits using 'bitwise AND'
            else std::cout << "0";
        }
        std::cout << "\n";
    }
}


int main(){
    bits ob(1991.829);
    ob.show_bits();
    
    return 0;
}

// The output of this program is:
Bit pattern in byte 7: 01000000
Bit pattern in byte 6: 10011111
Bit pattern in byte 5: 00011111
Bit pattern in byte 4: 01010000
Bit pattern in byte 3: 11100101
Bit pattern in byte 2: 01100000
Bit pattern in byte 1: 01000001
Bit pattern in byte 0: 10001001

/*  ------------    ChatGPT's explantion    ------------
    This program demonstrates how to find the bit-pattern of a double value by using a union to access its memory representation.

    Let's break down the program step by step:

    1. Union Declaration:
            union bits {
                bits(double n);
                void show_bits();
                double d;
                unsigned char c[sizeof(double)];
            };

        This declares a union named bits which contains:
            A constructor 'bits(double n)' that initializes the 'double member d' with the given value 'n'.
            A member function show_bits() which prints the bit pattern of the stored double.
            A double member d to hold the value.
            An array of unsigned char named 'c' with size equal to the 'size of double'. 
                note: This array is used to access the individual bytes of the double value.



    2. Constructor Implementation:    
            bits::bits(double n){
                d = n;
            }

        This constructor initializes the 'double member d' with the value passed to the constructor.   




    3. show_bits() Function:

            void bits::show_bits(){
                int i, j;
                for(j = sizeof(double)-1; j >=0; j --){
                    std::cout << " Bit pattern in byte " << j << ": ";
                    for (i = 128; i; i >>= 1){   // bitwise right shift
                        if(i & c[j]) std::cout << "1";
                        else std::cout << "0";
                    }
                    std::cout << "\n";
                }
            }

        This function prints the bit pattern of the stored double.

        It iterates through each byte of the double 
            (from most significant 'byte' to least significant 'byte') using the loop variable j.

        Inside the loop, it iterates through each 'bit' of the "byte" 
            (from most significant 'bit' to least significant 'bit') using the loop variable i.

        It checks whether the 'bit is set or not' by performing a bitwise AND operation (i & c[j]) with the byte c[j]. 
            If the result is non-zero, the bit is set, and it prints 1; otherwise, it prints 0.



    4. Main function

            int main(){
                bits ob(1991.829);
                ob.show_bits();
                return 0;
            }

        In the main() function, an object 'ob' of type bits is created and initialized with the value '1991.829' using the constructor.
        The show_bits() function is called on this object to print the bit pattern of the stored double value.


    So, overall, this program uses a 'union' to access the memory representation of a double value and prints its "bit pattern byte by byte". 
    It demonstrates how the 'internal representation' of a double value can be accessed and manipulated at the 'byte level'.

*/




/* Example 4: Both STRUCTURES and UNIONS can have 'constructors' and 'destructors'. 
                The following example shows the 'strtype class' reworked as a STRUCTURE (ch10_01_3_constructor_param.cpp). 
                It contains both a constructor (with params) and a destructor function. 
                
                It creates a simple string class, called 'strtype', that contains a 'string and its length'. 
                The program uses malloc and free() to allocate and free memory.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

// structure definition, notice 'public' and 'private' locations swap
struct strtype{
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        void show();
    private:
        char *p;
        int len;
};

// constructor: Initialize a string object with parameter.
strtype::strtype(char * ptr){
    len = strlen(ptr);  // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    if(!p){ // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 
    strcpy(p, ptr); // copy string to p
}

// destructor: Free memory when destroying string object .
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}

void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


int main(){
    strtype s1("This is a test ."), s2("I like C++. ");
    s1.show();
    s2.show();
    return 0;
}




/* Example 5: Following program uses an 'anonymous union' to display the individual bytes that comprise a double. 
                (This program assumes that doubles are 8 bytes long.) 
                
                Notice, both 'value' and 'bytes' are accessed as if they were 'normal variables' and not part of a UNION. 
                Even though they are declared as being part of an "anonymous union",
                their names are at the "same scope level" as any other local variable declared at the same point. 
                    This is why a 'member' of an anonymous union 'cannot have the same name' as any other variable known to its scope.
*/
// Using an anonymous union .
#include <iostream>

int main(){
    union {
        unsigned char bytes[8];
        double value;
    };

    int i;
    
    value = 859345.324;
    // display the bytes within a double, using char array 'bytes[8]' of the 'anonymous union'
    for (i=0; i<8; i++) std::cout << (int)bytes[i] << " ";

    return 0;
}




// ----  rev[13-feb-24]  ----

/* Example 6: Rewrite the 'stack class' presented in "ch10_01_2" so it uses a STRUCTURE rather than a CLASS.


Recall the "stack class" we created in previous section required an initialization function to set the stack index variable.
                Constructor function was designed to perform this sort of operation. 

                Following is an improved version of the 'stack class' that can be used to store characters
                    that uses a constructor to 'automatically initialize' a stack object when it is created 
*/

#include <iostream>


#define SIZE 10


// Declare a stack class for characters .
class stack {
        char stck[ SIZE];   // holds the stack
        int tos;            // index of top of stack
    
    public:
        stack();            // constructor. Notice no 'void init();' required
        void push(char ch); // push character on stack
        char pop();         // pop character from stack
};


// -=-=-=-=-=-    implementing member function    -=-=-=-=-=-

// stack(): Initialize the stack. No 'void init();' required
    // implementing constructor function
stack::stack(){
    std::cout << " Constructing a stack \n";
    tos = 0;
}

// push(): Push a character
void stack::push(char ch){
    if(tos == SIZE){
        std::cout << " Stack is full \n";
        return;
    }
    stck[tos] = ch;
    tos++;
}

// pop(): Pop or remove a character
char stack::pop(){
    if(tos == 0){
        std::cout << " Stack is empty \n";
        return 0; // return null on empty stack
    }
    tos--;
    return stck[tos];
}


// -=-=-  main function  -=-=-
int main(){
    stack s1, s2; // create two stacks that are automatically initialized.
    int i;

    // No need to initialize the stacks
    // s1.init();  // no need 
    // s2.init();  // no need

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    for(i =0; i<3; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i =0; i<3; i ++) std::cout << " Pop s2: " << s2.pop() << "\n";

    return 0;
}


/* 
    Notice, 'the initialization task is performed automatically' by the constructor function 
        rather than by a separate function that must be explicitly called by the program.

    Constructor function makes sure that the inilialization is performed.
    The programmer, don’t need to worry about initialization-it is performed automatically when the object is brought into existence.
 */


1. // Stack class using a structure .
# include <iostream >

# define SIZE 10
// Declare a stack class for characters using a structure .
struct stack
{
stack (); // constructor
void push ( char ch); // push character on stack
char pop (); // pop character from stack
private :
char stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
};
// Initialize the stack
stack :: stack ()
{
cout << " Constructing a stack \n";
tos = 0;
}
// Push a character .
void stack :: push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack is full \n";
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
cout << " Stack is empty \n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
int main ()
{
// Create two stacks that are automatically initialized .
stack s1 , s2;
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




/* Example 7: Use a union class to swap the 'low' and 'high-order' bytes of an 'integer' (assuming 16-bit integers); 
                if your computer uses 32-bit integers, swap the bytes of a 'short int'. */
# include <iostream >

union swapbytes
{
unsigned char c [2];
unsigned i;
swapbytes ( unsigned x);
void swp ();
};
swapbytes :: swapbytes ( unsigned x)
{
i = x;
}
void swapbytes :: swp ()
{
unsigned char temp ;
temp = c [0];
428ANSWERS
2.6 EXERCISES
c [0] = c [1];
c [1] = temp ;
}
int main ()
{
swapbytes ob (1) ;
ob. swp ();
cout << ob.i;
return 0;
}



/* Example 8: Explain what an anonymous union is and how it differs from a normal 'union'. 

                An anonymous union is the 'syntactic mechanism' that allows 
                    two variables to share the same memory space. 

                The members of an anonymous union are accessed directly, without reference to an object. 
                    members are at the same scope level as the union itself.
*/


