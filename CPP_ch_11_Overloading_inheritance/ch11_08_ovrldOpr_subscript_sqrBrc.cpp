
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


