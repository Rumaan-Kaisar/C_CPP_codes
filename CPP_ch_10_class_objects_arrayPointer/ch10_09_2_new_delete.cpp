
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




    --------  type cast during memory allocation  --------

    Remember in "ch10_01_2_constructor_destructor.cpp" in Example 4, 
        we first encountered a type cast for memory allocation.

            p = (char *)malloc(SIZE);    // malloc() returns a POINTER
            // Why type cast : To make conversion from ‘void *’ to ‘char *’

            type cast! why? : 
                    Notice 'type cast' in malloc(): To avoid ERR- invalid conversion from ‘void*’ to ‘char*’
                    
                    In C, you don't need to cast the return value of malloc(). 
                        [Recall 'C_Ch8_7_dynmic_allocation.c', "Example 2"]
                        The "pointer to void" i.e 'void *' returned by malloc() is automagically converted to the correct type.

                        i.e. the (void *) returned by malloc() is automatically "converted into a pointer" 
                            compatible with the "type of pointer" on the left side of the assignment. 

                        In C, no "type cast" is required when you are assigning the return value of malloc() to a pointer 
    
                    
                    However, in C++ compiler, 'a cast is NEEDED'.
                        C++ is not C. Their type systems are totally different. 
                        Observations about C++'s type system do not necessarily apply to C. In fact, they rarely do.

                        C++, requires an "explicit type cast" when you use malloc(). 
                        Because it allows C++ to enforce more rigorous type checking.


    --------    Advantages of "new" and "delete"    --------

        Although "new" and "delete" perform functions similar to malloc() and free(), they have several advantages. 

        1.  "new" automatically ALLOCATES enough "memory" to hold an object of the specified type.
                No to use "sizeof" to compute the number of bytes required.
                
        2.  "new" automatically RETURNS a "pointer" of the specified type

        3.  You do not need to use an "explicit type cast" the way you did 
                when you allocated memory by using malloc()

        4.  Both new and delete can be overloaded,
                enabling you to easily implement your own custom allocation system. 

        5.  It is possible to initialize a "dynamically allocated object". 

        6.  You no longer need to include <cstdlib> with your programs.


    From now we'll use "new" and "delete" instead of malloc() and free()
*/




/* Example 1: A simple example of new and delete. 
                this program allocates memory to hold an integer
        
                Notice the "Allocation error" check:
                    However, thuis check is meaningful only if your compiler implements new is such a way 
                    that it returns "null" on failure.
*/
#include <iostream>

int main() {
    int *p;

    p = new int; // allocate room for an integer
    if(!p){
        std::cout << "Allocation error \n";
        return 1;
    }

    *p = 100;
    std::cout << "Here is integer at p:" << *p << "\n";

    delete p; // release memory

    return 0;
}



/*  ------------    initializing dynamic dynamically allocated object    ------------
    We can give a dynamically allocated object an initial value 
        by using this form of the new statement:

        p_var = new type( initial_value );
*/




/*  Example 2: We can give a dynamically allocated object an initial value.	 
                Here is an example that allocates an object dynamically
*/
#include <iostream>

class samp { 
        int i, j;
    public:
        samp(int a, int b) { i=a; j=b; }
        int get_product() { return i*j; } 
};


int main() {
    samp *p;

    p = new samp(6, 5); 	// allocate object with initialization
    if(!p){ 
        std::cout << " Allocation error \n"; 
        return 1;
    }
    std::cout << "Product: " << p->get_product() << std::endl;

    delete p;	 // release memory
    
    return 0; 
}


/*  -=-=-=-=-=-    NOTE on Allocation check    -=-=-=-=-=-
    In modern C++, "new" will throw a "std::bad_alloc" exception if the allocation fails, 

        So the check if(!p) is not necessary. 


    However, if you prefer to "check for allocation errors" without using exceptions, 
        you can use the "nothrow" version of "new":

    NOTHROW version of "new":

        p = new (std::nothrow) samp(6, 5);
        if(!p) {
            std::cout << "Allocation error\n";
            return 1;
        }
*/



// alternative form: without auto-inlined-function as a constructor
    // notice "set_i" used instead of "samp"
#include <iostream>

class samp { 
        int i, j;
    public:
        void set_i(int a, int b) { i=a; j=b; }
        int get_product() { return i*j; } 
};


int main() {
    samp *p;

    p = new (std::nothrow) samp; 	// allocate object with NOTHROW version of "new"
    if(!p){ 
        std::cout << " Allocation error \n"; 
        return 1;
    }
    p -> set_i(4, 5);   // setting the values
    std::cout << "Product: " << p->get_product() << std::endl;

    delete p;	 // release memory
    
    return 0; 
}




/* Example 3: Following dynamically allocate, initialize and deallocate an integer variable 

                int *p = new int(9); dynamically allocates memory for an integer 
                    and initializes it with the value 9.

                if(!p) checks if the allocation failed. 
                    In modern C++, new throws a "std::bad_alloc" exception on failure, 
                    so this check is technically redundant,
*/

#include <iostream>

int main() {
    int *p = new int(9);    // Allocate an int variable with an initial value of 9
    // Check if allocation was successful
    if (!p) {
        std::cout << "Allocation error\n";
        return 1; // Exit the program with an error code
    }

    // Use the allocated integer variable in some statements
    std::cout << "The value of the dynamically allocated integer is: " << *p << std::endl;

    // Perform some operations
    *p += 1; // Increment the value by 1
    std::cout << "The value after incrementing is: " << *p << std::endl;
    *p *= 2; // Multiply the value by 2
    std::cout << "The value after multiplying by 2 is: " << *p << std::endl;

    // Release the allocated memory
    delete p;

    return 0;
}




/* Example 4: Write a program that uses "new" to dynamically allocate a float, a long, and a char.
                Give these dynamic variables values and display their values. 
                Finally, "release" all dynamically allocated memory by using delete. 
*/
#include <iostream>

int main(){
    float *f;
    long *l;
    char *c;

    f = new float;
    l = new long;
    c = new char;

    if(!f || !l || !c) {
        std::cout << " Allocation error .";
        return 1;
    }
    *f = 10.102;
    *l = 100000;
    *c = 'A';
    std::cout << *f << ' ' << *l << ' ' << *c;
    std::cout << '\n';

    delete f;
    delete l;
    delete c;

    return 0;
}




/* Example 5: Create a class that contains a person's name and telephone number. 
                Using "new", dynamically allocate an object of this class and 
                put your name and phone number into these fields within this object. 
*/
#include <iostream>
#include <cstring>

class phone {
        char name[40];
        char number[14];
    public:
        void store(char *n, char *num);
        void show();
};

void phone :: store( char *n, char *num) {
    strcpy(name , n);
    strcpy(number , num);
}

void phone :: show() {
    std::cout << name << ": " << number ;
    std::cout << "\n";
}


int main() {
    phone *p;

    p = new phone;  // dynamic allocation
    if(!p){
        std::cout << " Allocation error .";
        return 1;
    } 
    p -> store(" Isaac Newton ", " 111 555 -2323 ");
    p -> show();

    delete p;

    return 0;
}




/* Example 6: What are the two ways that new might indicate an allocation failure? 

                ans:
                    On failure, "new" will either return a "null pointer" or generate an EXCEPTION.
                    You must check your compiler’s documentation to determine which approach is used.
                    
                    In Standard C++, "new" generates an "exception" by default.
*/




/* Example 7: Show the general forms for "new" and "delete". 
                What are some ADVANTAGES of using them instead of malloc() and free()? 

            ans:
                The general forms of new and delete are:
                    p_var = new type;
                    delete p_var;


                Advantages when using "new":
                    You don't need to use a "TYPE CAST".
                        The size of the object is automatically determined; 

                    You don’t need to use "sizeof" also, 

                    You don’t need to include <cstdlib> in your program.
*/


