
/*  ------------    More new, delete :    dynamically allocate array    ------------ 
    
    Dynamically allocate a 1D array : 
        
                p_var = new type[ size ];

        After this statement has executed, "p_var" will point 
            to the start of an array of "size" elements of the type specified. 



    initialization:
        You can give a dynamically allocated object an "initial value" by using this form:
                    p_var = new type ( initial_value );

        It is not possible to initialize an "array" that is dynamically allocated.



    delete:
                delete [] p_var;

        This syntax causes the "compiler" to call the DESTRUCTOR function for "each element" in the array. 
        It does not cause "p_var" to be freed MULTIPLE times. 
        "p_var" is still freed only once.



    --------    Notes    --------
    new automatically allocates enough memory to hold an object of the specified type. 
        You do not need to use sizeof, for example, to compute the number of bytes required.

    new automatically returns a pointer of the specified type. 
        You do not need to use an "explicit type cast".  

        In C, "no type cast is required" when you are assigning the return value of malloc() to a pointer 
            because the "void *" returned by malloc() is automatically converted into a pointer 
            compatible with the type of pointer on the left side of the assignment. 

        However, this is not the case in C++, which requires an "explicit type cast" when you use malloc(). 
        
    
    Both new and delete can be overloaded, 
        enabling you to easily implement your own "custom allocation system". 
    
    It is possible to initialize a dynamically allocated object. 

    You no longer need to include <cstdlib> with your programs.

*/




/* Example 1: Following program "allocates" MEMORY for an integer and "initializes" that memory */

#include <iostream>

int main() {
    int *p;

    // initializing a dynamic variable
    p = new (std::nothrow) int(9);     // give initial value of 9, using "nothrow" version of "new"
    if (!p){
        std::cout << " Allocation error \n";
        return 1;
    }

    std::cout << " Here is integer at p: " << *p << "\n";
    delete p; // release memory

    return 0;
}

// above program displays the value 9, 
// which is the initial value given to the memory pointed to by p.




/* Example 2: The following program passes "initial values" to a dynamically allocated object 
                When the samp object is allocated, 
                    its constructor is automatically called and is passed the values 6 and 5.
*/

#include <iostream>

class samp{
        int i, j;
    public:
        samp(int a, int b) { i=a; j=b; }
        int get_product() { return i*j; }
};


int main(){
    samp *p;

    p = new (std::nothrow) samp(6, 5);     // allocate object with initialization
    if(!p){
        std::cout << " Allocation error \n";
        return 1;
    }
    std::cout << " Product is: " << p->get_product() << "\n";

    delete p;

    return 0;
}




/* Example 3: The following program allocates an ARRAY of integers */
#include <iostream>

int main(){
    int *p;

    p = new (std::nothrow) int[5];     // allocate room for 5 integers
    // always make sure that allocation succeeded
    if (!p){
        std::cout << " Allocation error \n";
        return 1;
    }

    int i;
    for (i =0; i <5; i ++) p[i] = i;
    for (i =0; i <5; i ++){
        std::cout << " Here is integer at p[" << i << "]: ";
        std::cout << p[i] << "\n";
    }

    delete [] p;    // freeing "each element" in the array 

    return 0;
}




/* Example 4: The following program creates a dynamic array of "objects" */
// Allocating dynamic objects.
#include <iostream>

class samp{
        int i, j;
    public:
        void set_ij(int a, int b) { i=a; j=b; }
        int get_product() { return i*j; }
};


int main(){
    samp *p;
    int i;

    // allocate object array named "samp" 
    p = new samp[10];  // allocate object array
    if(!p){
        std::cout << " Allocation error \n";
        return 1;
    }

    // "->" is not used since we're dealing with array
    for(i =0; i <10; i ++) p[i].set_ij(i, i);  
    for(i =0; i <10; i ++){
        std::cout << " Product [" << i << "] is: ";
        std::cout << p[i].get_product() << "\n";
    }
    
    delete [] p;
    
    return 0;
}




/* Example 5 : (array of object) The following version of the preceding program gives samp a "DESTRUCTOR", 
                and now when p is freed, each element’s destructor is called.
*/

// Allocating dynamic objects
#include <iostream>

class samp{
        int i, j;
    public:
        void set_ij(int a, int b) { i=a; j=b; }
        ~samp() { std::cout << " Destroying ...\ n"; }
        int get_product() { return i*j; }
};


int main(){
    samp *p;
    int i;

    p = new (std::nothrow) samp[10]; // allocate object array
    if(!p){
        std::cout << " Allocation error \n";
        return 1;
    }

    // "->" is not used since we're dealing with array
    for(i =0; i <10; i ++) p[i].set_ij(i, i);
    for(i =0; i <10; i ++){
        std::cout << " Product [" << i << "] is: ";
        std::cout << p[i]. get_product () << "\n";
    }

    delete [] p;

    return 0;
}

// As you can see, samp’s "destructor" is called ten times-once for each element in the array




/* Example 6: Show how to convert the following code into its equivalent that uses "new" 

                        char *p;
                        
                        // allocate 100 bytes
                        p = (char *) malloc(100);
                        // ...
                        strcpy(p, " This is a test ");

                Hint: A string is simply an array of characters.
*/

char *p;

// allocate 100 bytes: by creating array of 100 "char", assuming each "char" is 1 byte
p = new char[100];
// ...
strcpy (p, " This is a test ");




/* Example 7: Using new, show how to allocate a "double" and give it an initial value of "-123.0987" */
# include <iostream>

int main(){
    double *p;

    // allocate a "double" with initial value of "-123.0987"
    p = new double(-123.0987);
    std::cout << *p << '\n';

    return 0;
}




/* Example 8: In "ch10_01_2_constructor_destructor.cpp", in "Example 4" a strtype class 
                was created that dynamically allocated space for a string. 
                Later we improved it using parameterized constructor 

                It creates a simple string class, called 'strtype', that contains a 'string and its length'. 

                When a 'strtype' object is created, 
                    'memory' is allocated to hold the string and its initial length is set to 0. 

                When strtype object is destroyed, that memory is released
                The old program uses malloc() and free() to allocate and free memory.

                Rework the strtype class (shown here for your convenience) so it uses new and delete


#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
        int len;
    public:
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        void show();
};

// constructor:
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

// destructor:
strtype::~strtype(){
    std::cout << " Freeing p\n";
    free(p);
}

void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


// In this version of strtype, a string is given an initial value using the constructor function.
int main(){
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();

    return 0;
}

*/

// above program using "new" and "delete"

#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
        int len;
    public:
        strtype(char *ptr);  // constructor
        ~strtype(); // destructor
        void show();
};


// constructor: using "new"
strtype::strtype(char * ptr){
    len = strlen(ptr);  // get len of the string
    // allocate using string's length 'len' instead of fixed 'SIZE'
    // p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
    // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
    
    p = new char[len +1];   // using "new" instead of "malloc()"
    
    if(!p){ // Error massage
        std::cout << " Allocation error \n";
        exit(1) ;
    } 

    strcpy(p, ptr); // copy string to p
}


// destructor: using "delete"
strtype::~strtype(){
    std::cout << " Freeing p\n";
    // free(p);
    delete [] p;    // using "delete" instead of "free"

}


void strtype::show(){
    std::cout << p << " - length : " << len ;
    std::cout << "\n";
}


// In this version of strtype, a string is given an initial value using the constructor function.
int main(){
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();

    return 0;
}




/* Example 9: What is the general form of "new" that is used to "initialize" a dynamic variable? 
                Give a concrete example. 

            ans:
                The general form of "new" that includes an initializer is shown here:

                        p_var = new type (initializer);

                For example, this allocates an integer and gives it the value 10:
                        int *p;
                        p = new int (10)
*/

