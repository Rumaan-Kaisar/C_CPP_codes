
/* ------------    new, delete :    ALLOCATION / RELEASE of Memory    ------------
    Previously, to ALLOCATE memory and to FREE the allocated memory we use the C's dynamic allocation FUNCTIONS 
            malloc()
            free() 
    These are the "standard"
        However, C++ provides safer and more convenient "OPERATORS" (not FUNCTIONS): 



    Memory allocation/release operators :  new, delete

                new :  to allocate memory
                delete :  to free memory

        These operators take these general forms:

                p_var = new type;
                delete p_var;

            "type" is the "type/class specifier" of the object for which you want to allocate memory and 
            "p_var" is a POINTER to that type


    new :
        "new" is an OPERATOR that returns a POINTER to "dynamically allocated memory" 
            that is large enough to hold an object of type type.

        If "new" cannot satisfy an allocation request, it generates an EXCEPTION
        If this EXCEPTION is not handled by your program, 
            your program will be TERMINATED (abruptly). 

            (   Exceptions and exception handling are described later; 
                loosely, an exception is a run-time error that can be managed in a structured fashion.  
            )


    delete :
        "delete" RELEASES that memory when it is no longer needed. 
        "delete" can be called only with a VALID pointer, 
        Calling with an invalid pointer, the allocation system will be destroyed, possibly CRASHING your program.


    Insufficient available memory:
        If there is insufficient available memory to fill an allocation request, one of two actions will occur. 
            1.  "new" will return a NULL pointer or
            2.  "new" will generate an EXCEPTION.




        ----  rev[06-jun-2024]  ----


Although new and delete perform functions similar to malloc() and free(), they have several
advantages. 

First, new automatically allocates enough memory to hold an object of the specified
type. 
You do not need to use sizeof to compute the number of bytes required. 

This reduces the possibility for error. 


Second, new automatically returns a pointer of the specified
type. 


Remember in "ch10_01_2_constructor_destructor.cpp" in Example 4, we first encountered a type cast for memory allocation.

p = (char *)malloc(SIZE);    // malloc() returns a POINTER
// Why type cast : To make conversion from ‘void *’ to ‘char *’

type cast! why? : 
                Notice 'type cast' in malloc(): To avoid ERR- invalid conversion from ‘void*’ to ‘char*’
                
                In C, you don't need to cast the return value of malloc(). 
                    [Recall 'C_Ch8_7_dynmic_allocation.c', "Example 2"]
                    The "pointer to void" i.e 'void *' returned by malloc() is automagically converted to the correct type. 
                
                However, in C++ compiler, 'a cast is NEEDED'.
                    C++ is not C. Their type systems are totally different. 
                    Observations about C++'s type system do not necessarily apply to C. In fact, they rarely do.



    

You do not need to use an "explicit type cast" the way you did when you allocated memory
by using malloc() (see the following note). Third, both new and delete can be overloaded,
enabling you to easily implement your own custom allocation system. Fourth, it is possible to
initialize a dynamically allocated object. Finally, you no longer need to include <cstdlib>
with your programs.


Note: In C, no type cast is required when you are assigning the return value of malloc() to
a pointer because the void * returned by malloc() is automatically converted into a pointer
compatible with the type of pointer on the left side of the assignment. However, this is not the
case in C++, which requires an explicit type cast when you use malloc(). The reason for this
difference is that it allows C++ to enforce more rigorous type checking.
Now that new and delete have been introduced, they will be used instead of malloc() and
free()

*/







/* Example 1: A simple example of new and delete . */
# include <iostream >
using namespace std;
int main() {int *p;
p = new int; /* allocate room for an integer */ 
if(!p) {cout << "Allocation error \n";
return 1;}

*p = 100;
cout << "Here is integer at p:" << *p << "\n";
delete p; /* release memory */ 
return 0;}

 
	Initializing dynamic variable : Dynamically allocated objects can be given initial values. We can give a dynamically allocated object an initial value by using this form of the new statement:
p_var = new type( initial_value );

/* Example 2: 	 */
class samp { int i, j;
public :
samp(int a, int b) { i=a; j=b; }
int get_product() { return i*j; } };
int main() { samp *p;
p = new samp(6, 5); 	/* allocate object with initialization */ 
if(!p) { cout << " Allocation error \n"; return 1; } 	/*allocation check*/
delete p;	 /* release memory */
return 0; }

Example 2: To initialize an integer variable,
p = new int(9); 	/* give initial value of 9*/ 
if(!p) { cout << " Allocation error \n"; return 1; }	/*always check if allocation is successful*/
. . . . . . STATEMENTS. . . . . .
delete p; 		/* release memory */ 

