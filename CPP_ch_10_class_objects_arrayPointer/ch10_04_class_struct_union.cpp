
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



/* Example 1: Here is a short program that uses struct to create a class */
# include <iostream >
# include <cstring >

// use struct to define a class type
struct st_type
{
st_type ( double b, char *n);
void show ();
private :
double balance ;
char name [40];
};
st_type :: st_type ( double b, char *n)
{
balance = b;
strcpy (name , n);
}
void st_type :: show ()
{
cout << " Name : " << name ;
cout << ": $" << balance ;
if( balance <0.0)
cout << "**";
cout << "\n";
}
int main ()
{
st_type acc1 (100.12 , " Johnson ");
st_type acc2 ( -12.34 , " Hedricks ");
acc1 . show ();
acc2 . show ();
return 0;
}
Notice that, as stated, the members of a structure are public by default. The private
keyword must be used to declare private members.
Also, notice one difference between C-like structures and C++-like structures. In C++,
the structure tag-name also becomes a complete type name that can be used to declare
objects. In C, the tag-name requires that the keyword struct precede it before it becomes
a complete type.




/* Example 2: Here is the above program, rewritten using a class */

# include <cstring >

class cl_type
{
double balance ;
char name [40];
public :
cl_type ( double b, char *n);
void show ();
};
cl_type :: cl_type ( double b, char *n)
{
balance = b;
strcpy (name , n);
}
void cl_type :: show ()
{
cout << " Name : " << name ;
cout << ": $" << balance ;
if( balance <0.0)
cout << "**";
cout << "\n";
}
int main ()
{
cl_type acc1 (100.12 , " Johnson ");
cl_type acc2 ( -12.34 , " Hedricks ");
acc1 . show ();
acc2 . show ();
return 0;
}



/* Example 3: Following program uses a UNION to display the 'binary bit pattern', 
                byte by byte, contained within a double value. */
# include <iostream >

union bits
{
bits ( double n);
void show_bits ();
double d;
unsigned char c[ sizeof ( double )];
};
52INTRODUCING CLASSES
2.5. CLASSES, STRUCTURES, AND UNIONS ARE RELATED
bits :: bits ( double n)
{
d = n;
}
void bits :: show_bits ()
{
int i, j;
for (j = sizeof ( double ) -1; j >=0; j --)
{
cout << " Bit pattern in byte " << j << ": ";
for (i = 128; i; i >>= 1)
if(i & c[j])
cout << "1";
else
cout << "0";
cout << "\n";
}
}
int main ()
{
bits ob (1991.829) ;
ob. show_bits ();
return 0;
}



/* Example 4: Both STRUCTURES and UNIONS can have 'constructors' and 'destructors'. 
                The following example shows the 'strtype class' reworked as a STRUCTURE. 
                It contains both a constructor and a destructor function. */

# include <iostream >
# include <cstring >
# include <cstdlib >


struct strtype
{
strtype ( char * ptr );
~ strtype ();
void show ();
private :
char *p;
int len ;
};
strype :: strype ( char * ptr )
{
len = strlen ( ptr );
p = ( char *) malloc (len +1);
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
}
strtype ::~ strtype ()
{
cout << " Freeing p\n";
free (p);
}
void strtype :: show ()
{
cout << p << " - length : " << len ;
cout << "\n";
}
int main ()
{
strtype s1(" This is a test ."), s2("I like C++");
s1. show ();
s2. show ();
return 0;
}




/* Example 5: Following program uses an 'anonymous union' to display the individual bytes that comprise a double. 
                (This program assumes that doubles are 8 bytes long.) */
// Using an anonymous union .
# include <iostream >


int main ()
{
union
{
unsigned char bytes [8];
double value ;
};
int i;
value = 859345.324;
// display the bytes within a double
for (i =0; i <8; i ++)
cout << ( int ) bytes [i] << " ";
return 0;
}
As you can see, both value and bytes are accessed as if they were normal variables and
not part of a union. Even though they are declared as being part of an anonymous union,
their names are at the same scope level as any other local variable declared at the same
point. This is why a member of an anonymous union cannot have the same name as any
other variable known to its scope.




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


