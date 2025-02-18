
/*  ------------------------    overloading "subscript" : []-operator   ------------------------

    Overloading The '[]' SUBSCRIPT Operator:
        The general form of a member "operator[]()" function is (overloading the [] operator as a member function):
        
                return_type class_name::operator[](int index) {
                    // Function implementation
                }

        The parameter is usually an int (but not strictly required)
            since operator[]() functions are mainly used for "array subscripting".

        In C++, [] is treated as a binary operator for overloading purposes.
        The [] can be overloaded only by a member function. 


        How It Works:
            Assume that an object called 'ob' is indexed as: ob[9]; 
            This index will translate into the following call to the "operator[]()"

                ob.operator[](9)

            The value of the expression within [] is passed to operator[]() in its explicit parameter. 
            The "this" pointer will point to "ob", the object that generated the call.
*/




/* Example 1: Following program demonstrates how to overload the [] operator to create a simple array-like class

                "arraytype" declares an array of five integers. 
                    Its constructor initializes each member of the array (with values 0, 1, 2, 3, 4)
                    This specific initialization is just for demonstration purposes
                
                The overloaded operator[]() returns the value of the element specified by its parameter.
                    i.e. it returns the value "int" at the specified index
                    Does not allow modification of array elements (returns by value, not reference)

                Limitations:
                    No bounds checking (accessing ob[5] would cause undefined behavior)
                    Cannot modify elements via ob[i] = new_value

    Note: The initialization of the "array a" by the constructor in this and the following programs 
        is for the sake of illustration only. It is not required. 
*/

#include <iostream>

const int SIZE = 5;

class arraytype{
        int a[SIZE];
    public:
        arraytype(){
            int i;
            for(i=0; i < SIZE; i++) a[i] = i;
        }
        
        // overload []
        int operator[](int i){ return a[i]; }
};


int main(){
    arraytype ob;
    int i;

    for (i=0; i < SIZE; i++) std::cout << ob[i] << " ";
    
    return 0;
}



/*  Limitation 1: No Bounds Checking
        operator[]() does not verify index validity. Accessing out-of-range indices (e.g., ob[5]) causes undefined behavior. 
*/
int main() {
    arraytype ob;

    // Accessing valid indices (0-4)
    for(int i=0; i<SIZE; i++) std::cout << ob[i] << " ";  // Output: 0 1 2 3 4

    // Accessing an invalid index (5)
    std::cout << ob[5];  // Undefined behavior (may crash or return garbage)
    return 0;
}



/*  Limitation 2: Cannot Modify Elements
        The operator[]() function returns the array element by "value", not by "reference". 
        This means you cannot modify the array elements using ob[i] = new_value. 
        
        Solution: 
            to make a referance just use '&' before 'operator[]'  i.e. 
            
            int &operator[](int i){ return a[i]; }

*/
int main() {
    arraytype ob;

    // Attempting to modify an element
    ob[2] = 99;  // This will NOT modify the array

    // Print array to confirm no changes
    for(int i=0; i<SIZE; i++) std::cout << ob[i] << " ";  // Output: 0 1 2 3 4

    return 0;
}



/*  Fixing the Limitations:
        Add bounds checking to prevent invalid index access.
        Return a reference (int&) from operator[] to allow modification of array elements. 
*/
#include <iostream>

const int SIZE = 5;

class arraytype{
        int a[SIZE];
    public:
        arraytype(){ for(int i=0; i<SIZE; i++) a[i] = i; }
        
        // Overloaded [] operator with "bounds checking" and "reference" return
        int &operator[](int i) {
            if((i<0) || (i>=SIZE)) {
                std::cout << "Index " << i << " is out of bounds.\n";
                exit(1);  // Terminate program on error
            }
            return a[i];  // Return reference to element
    }
};


int main() {
    arraytype ob;

    // Attempting to modify an element
    ob[2] = 99;  // This works now

    // Print array to confirm changes
    for(int i = 0; i < SIZE; i++) std::cout << ob[i] << " ";  // Output: 0 1 2 3 4
    
    // Accessing an invalid index
    ob[5] = 10;  // Output: Index 5 is out of bounds.

    return 0;
}




/* ----------------    Why Use References?    ----------------
    Returning a reference allows direct modification of the array elements.
    Without a reference, the [] operator could only be used for reading values, not writing. 
*/




/* Example 2 (modify elements, use referance): It is possible to design the operator[]() function in such a way that 
                the [] can be used on both the left and right sides of an assignment statement.
                ( i.e. a=b[i] and b[i]=a. Assigning values to/form array )
                
                To do this, return a "reference" to the element being indexed. 
                Just as we did to fix the limitations in the previous example.
                
                For example, following program makes this change and illustrates its use 
*/
#include <iostream>

const int SIZE = 5;

class arraytype{
        int a[SIZE];
    public:
        arraytype(){
            int i;
            for(i=0; i<SIZE; i++) a[i] = i;
        }
        // overload [], with referance
        int &operator[]( int i){ return a[i]; }
};


int main(){
    arraytype ob;
    int i;

    // Print array
    for(i=0; i<SIZE; i++) std::cout << ob[i] << " ";
    std::cout << "\n";

    // add 10 to each element in the array
    for(i=0; i<SIZE; i++) ob[i] = ob[i]+10;     // [] on the left of '=', i.e., modifying elements

    // Print array to confirm changes
    for(i=0; i<SIZE; i++) std::cout << ob[i] << " ";

    return 0;
}


/*  This program outputs:
            0 1 2 3 4
            10 11 12 13 14

        Since the operator[]() now returns a "reference" to the array element, 
            it allows modification of the array elements, just like normal arrays. 
            (i.e. it can be used on the left side of '=' to modify an element)
        It can still be used on the right side of an assignment as well.
*/




/* Example 3 (Safe array, bound checking): Recall that a safe array is an array that is 
                encapsulated within a class that performs bounds checking. 

                prevents overrun: This approach prevents the array boundaries from being overrun.

                Overloading the [] operator provides a "better way" to implement safe array indexing. 
                    Earlier methods used functions like get() and put() to access elements 
                    (ch10_10_3_return_ref.cpp: Example 2 and Example 3), 
                    but overloading [] allows the array to be accessed like a regular array while maintaining safety.

                To create a safe array with overloaded [] operator, 
                    simply add "bounds checking" to the operator[]() function.
                    Following program proves that it works by generating a boundary error
                
                The operator[]() must also return a reference to the element being indexed.


                When 
                        ob[SIZE + 100] = 99; 
                
                    executes, the boundary error is intercepted by operator[]() and stops the program, preventing errors. 
                    
                Overloading [] allows safe arrays to function like regular arrays, making them easy to use.    
                However, this safety comes with added overhead, which may not be suitable for all cases. 
                Despite this, safe arrays are valuable in applications where preventing boundary errors is critical.
*/
// --------  A safe array  --------
#include <iostream>
#include <cstdlib>

const int SIZE = 5;

class arraytype{
        int a[SIZE];
    public:
        arraytype(){
            int i;
            for(i=0; i<SIZE; i++) a[i] = i;
        }
        
        // using referance for overloaded []
        int &operator[](int i);
};


// In overloaded [] bound checking for arrayType. Also notice the referance
int &arraytype::operator[](int i){
    if((i<0) || (i>(SIZE-1))){
        std::cout << "\nIndex value of " << i << " is out of bounds.\n";
        exit(1);
    }
    return a[i];
}


int main(){
    arraytype ob;
    int i;

    // this is OK
    for(i=0; i<SIZE; i++) std::cout << ob[i] << " ";

    // following generates a run-time error because SIZE+100 is out of range
    ob[SIZE+100] = 99; // error

    return 0;
}



/* Example 4: Modify Example 1 (strtype class) in "ch11_07_ovrldOpr_assignment.cpp" 
   so that strtype overloads the [] operator. 
   Have this operator return the character at the specified index. 
   Also, allow [] to be used on the left side of the assignment statement 
   (i.e., modification of the object). Demonstrate its use. */








/* Example 5: Modify Example 2 (dynarray) from "ch11_07_ovrldOpr_assignment.cpp" 
   so that it uses [] to index the dynamic array. 
   That is, replace the get() and put() functions with the [] operator. */









/*  Example 1: Following is another version of the strtype class (from previous chapters)
                This version overloads the '=' operator to ensure 
                the pointer 'p' is not overwritten during assignment.

                The overloaded assignment operator prevents p from being overwritten.
                        It checks if the object on the left has enough allocated memory to hold the assigned string.
                        If not, it frees the old memory and allocates new memory. 
                        Then, it copies the string and updates the length (len).
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
        int len;
    public:
        strtype(char *s);   // constructor
        ~strtype(){         // destructor
            // std::cout << " Freeing " << (unsigned)p << '\n';     // ERR: cast from ‘char*’ to ‘unsigned int’ loses precision
            std::cout << " Freeing " << (void*)p << '\n';
            delete [] p;    // delete dynamically allocate a 1D array. "delete [] p_var;"
            // recall "ch10_09_3_more_new_delete.cpp"
        }
        char *get(){ return p; }
        
        // Overload '=': It is an operator function that returns a reference to the object
        strtype &operator=(strtype &ob);    // reference operator function
};


strtype::strtype(char *s){
    int l;

    l = strlen(s) + 1;
    p = new char [l];
    if(!p){
        std::cout << " Allocation error \n";
        exit(1);
    }

    len = l;
    strcpy(p, s);
}


// overload '=': Assign an object
strtype &strtype::operator=(strtype &ob){
    
    // see if more memory is needed
    if(len < ob.len){ 
        // allocate more memory
        delete [] p;
        p = new char[ob.len];

        if(!p){
        std::cout << " Allocation error \n";
        exit(1);
        }
    }

    len = ob.len;
    strcpy(p, ob.p);
    return *this;
}


int main(){
    strtype a(" Hello "), b(" There ");

    std::cout << a.get() << '\n';
    std::cout << b.get() << '\n';

    a = b; // now p is not overwritten

    std::cout << a. get () << '\n';
    std::cout << b. get () << '\n';

    return 0;
}

/*  The error occurs because we're trying to cast a char* pointer to an "unsigned int", 
        which might lead to a loss of precision, especially on 64-bit systems 
        where pointers are 64 bits but unsigned int is typically 32 bits.
        Casting to unsigned can truncate the pointer value, leading to potential data loss

    Solution:
        cast the pointer p to an uintptr_t or void* instead, 
        as these types are specifically designed to safely store pointer values.

                #include <cstdint> // Include this for uintptr_t

        change:
                std::cout << " Freeing " << (uintptr_t)p << '\n';   // Use uintptr_t for pointer-to-integer cast

    uintptr_t
        The uintptr_t type is an unsigned integer type guaranteed to be large enough to hold a pointer. 
        Casting a pointer to uintptr_t ensures compatibility and avoids precision loss.

                #include <cstdint> is needed for uintptr_t.

    Alternative (void*):
        If you don't need to perform arithmetic or formatting operations on the pointer, 
            you can also directly cast p to void* for printing.

                std::cout << " Freeing " << (void*)p << '\n';



    ------------    Note: using space with &    ------------
    Common Styles (without space):      strtype &operator=(strtype &ob);
     
    Both
            strtype &operator=(strtype &ob);
    and 
            strtype & operator=(strtype &ob); 
    
    are syntactically correct in C++. 
    
    The placement of the space between & and operator is purely 
        a matter of style preference and does not affect functionality.
*/




/* Example 2: Given the following class declaration, your task is to complete it to create a "dynamic array". 
                Fill in all the details that will create a dynamic array type

                Here's what you need to do:
                    Allocate memory for the array and store a pointer to this memory in p.
                    Store the size of the array (in bytes) in size.

                Implement
                    put() that returns a reference to a specified element
                    get() that returns the value of a specified element

                Ensure that the array boundaries are not overrun.

                Also, overload the assignment operator(=):
                    To ensure that the memory allocated for one array 
                        is not accidentally destroyed during assignment.

                    (Note: In the next section, you’ll learn how to improve this solution further.)



                        class dynarray{
                                int *p;
                                int size;
                            public:
                                dynarray(int s);    // pass size of array in s
                                int &put(int i);    // return reference to element i
                                int get(int i);     // return value of element i

                                // create operator=() function
                        };
*/

#include <iostream>
#include <cstdlib>

class dynarray{
        int *p;
        int size;
    public:
        dynarray(int s);    // pass size of array in s
        int &put(int i);    // return reference to element i
        int get(int i);     // return value of element i

        // overload "=", i.e. create operator=() function
        dynarray &operator=(dynarray &ob);
};

// Constructor
dynarray::dynarray(int s){
    p = new int [s];
    if(!p){
        std::cout << " Allocation error \n";
        exit(1);
    }
    size = s;
}

// Store an element
int &dynarray::put(int i){
    if((i<0) || (i >= size)){
        std::cout << " Bounds error !\n";
        exit(1);
    }
    return p[i];
}

// Get an element
int dynarray::get(int i){
    if((i<0) || (i >= size)){
        std::cout << " Bounds error !\n";
        exit(1);
    }
    return p[i];
}


// Overload = for dynarray
dynarray &dynarray::operator=(dynarray &ob){
    int i;
    if(size != ob.size){
        std::cout << " Cannot copy arrays of differing size !\n";
        exit(1);
    }
    // assigning
    for(i=0; i<size; i++) p[i] = ob.p[i];
    return *this;
}


int main(){
    int i;
    dynarray ob1(10), ob2(10), ob3(100);

    ob1.put(3) = 10;
    i = ob1.get(3);
    std::cout << i << '\n';

    ob2 = ob1;
    i = ob2.get(3);
    std::cout << i << '\n';

    // generates an error, for arrays of differing size
    ob1 = ob3; // arrays of differing size

    return 0;
}

