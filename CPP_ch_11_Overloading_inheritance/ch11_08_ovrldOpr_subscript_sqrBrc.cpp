
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
    for(int i = 0; i < SIZE; i++) std:: cout << ob[i] << " ";  // Output: 0 1 2 3 4

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
    for(int i = 0; i < SIZE; i++) std::cout << ob[i] << " ";  // Output: 0 1 2 3 4

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



/*  

============================  DS  =========================================




	Example 2 -Assigning values to & form using reference and []: It is possible to design the operator[]() function in such a way that the [] can be used on both the left and right sides of an assignment statement (i.e. a=b[i] and b[i]=a. Assigning values to & form array ). To do this, return a reference to the element being indexed. 

class arraytype
{. . . . 
public: 
// as same as Example 1 of 11.14
int &operator[](int i){return a[i]; }    //reference
};	int main(){ arraytype ob;  int i;
      for(i=0; i<SIZE; i++) cout<<ob[i]<<" ";
cout << "\n";
// add 10 to each element in the array
for(i=0; i< SIZE ; i++){
		ob[i] = ob[i ]+10;}  // [] on left of =
      for(i=0; i<SIZE; i++) cout<<ob[i]<<" ";
return 0;}

	Because the operator[]() function now returns a reference to the array element indexed by i, it can be used on the left side of an assignment to modify an element of the array (just like normal arrays).

============================  DS  =========================================

Example 2: Using Reference with [] for Assignment
This program demonstrates how to overload the [] operator to allow it to be used on both sides of an assignment (e.g., a = b[i] and b[i] = a). This is achieved by returning a reference to the array element.

cpp
Copy
#include <iostream>
using namespace std;

const int SIZE = 5;

class arraytype {
    int a[SIZE];  // Private array of 5 integers
    
public:
    // Constructor initializes array with index values (0-4)
    arraytype() {
        for(int i = 0; i < SIZE; i++) {
            a[i] = i;  // Sets a[0] = 0, a[1] = 1, etc.
        }
    }
    
    // Overloaded subscript operator returning a reference
    int& operator[](int i) {
        return a[i];  // Returns a reference to the element at index i
    }
};

int main() {
    arraytype ob;  // Create object

    // Print initial array values
    for(int i = 0; i < SIZE; i++) {
        cout << ob[i] << " ";  // Uses overloaded [] operator
    }
    cout << "\n";

    // Add 10 to each element in the array
    for(int i = 0; i < SIZE; i++) {
        ob[i] = ob[i] + 10;  // [] on the left side of assignment
    }

    // Print modified array values
    for(int i = 0; i < SIZE; i++) {
        cout << ob[i] << " ";  // Uses overloaded [] operator
    }

    return 0;
}


Key Points:


1. Reference Return Type (int&):

The operator[] function now returns a reference to the array element (int&).

This allows the [] operator to be used on both sides of an assignment:

Right side: a = ob[i] (reads the value at index i)

Left side: ob[i] = a (modifies the value at index i)


2. Behavior in main():

Initial array values: 0 1 2 3 4

After adding 10 to each element: 10 11 12 13 14


3. Why Use References?

Returning a reference allows direct modification of the array elements.

Without a reference, the [] operator could only be used for reading values, not writing.



4. Limitations:

Still no bounds checking (accessing ob[5] would cause undefined behavior).



	Example 3 (Safe array): Recall that a safe array is an array that is encapsulated within a class that performs bounds checking. This approach prevents the array boundaries from being overrun. 
	To create a safe array with overloaded [] operator, simply add bounds checking to the operator[]() function. The operator[]() must also return a reference to the element being indexed.  Following program proves that it works by generating a boundary error:

{ public:. . . . 
// as same as Example 1 of 11.14
int &operator[](int i) }; 			//reference
// only declaration given inside class	
// Bound checks inside the if statement
int &arraytype :: operator[](int i){
if(i<0 || i>(SIZE-1)){
   cout<<i<< "is out of bounds.\n"; exit(1);}
return a[i]; }
	int main() { 	arraytype ob;  int i;
			for(i=0; i<SIZE; i++) cout<< ob[i] << " "; // this is OK
			ob[SIZE +100] = 99;  // generates a run - time error because SIZE +100 is out of range
		return 0;}

	In this program, when the statement ob[ SIZE +100] = 99; executes, the boundary error is intercepted by operator[]() and the program is terminated before any damage can be done.
	Remark 1: Because the overloading of the [] operator allows you to create safe arrays that look and act just like regular arrays.
	Remark 2: Be careful. A safe array adds overhead that might not be acceptable in all situations.  However, in applications in which you want to be sure that a boundary error does not take place, a safe array will be worth the effort.

=========================================  GPT  ============================
Safe Array Using Overloaded [] Operator
A safe array is an array encapsulated within a class that includes bounds checking to prevent out-of-bounds access. This approach ensures that the array boundaries are not overrun, preventing potential runtime errors.

Implementation Details
The operator[]() function is overloaded to check bounds before accessing an element.
It returns a reference to allow direct modification of elements.
If an invalid index is used, the program terminates with an error message.
Example Code
cpp
Copy
Edit
class arraytype {
    int a[SIZE]; // Array with fixed size
public:
    int &operator[](int i); // Overloaded operator declaration
};

// Operator[] definition with bounds checking
int &arraytype::operator[](int i) {
    if (i < 0 || i >= SIZE) {
        std::cout << i << " is out of bounds.\n";
        exit(1); // Terminate program on invalid access
    }
    return a[i];
}

int main() {
    arraytype ob;
    
    // Access within valid range
    for (int i = 0; i < SIZE; i++)
        std::cout << ob[i] << " ";

    ob[SIZE + 100] = 99; // Triggers runtime error due to out-of-bounds access

    return 0;
}
Key Takeaways
Safety: The program detects invalid access before any memory corruption occurs.
Ease of Use: The overloaded [] operator makes the safe array behave like a regular array.
Performance Consideration: Bounds checking adds overhead, so it may not be suitable for performance-critical applications.
Reliability: Useful for applications where data integrity is more important than execution speed.

===============================  DS  ============================
Here's a clarified explanation of the safe array example with bounds checking:

Example 3: Safe Array with Bounds Checking
This program demonstrates how to create a "safe array" that prevents boundary overflows using the overloaded [] operator.

cpp
Copy
#include <iostream>
#include <cstdlib>  // For exit()
using namespace std;

const int SIZE = 5;

class arraytype {
    int a[SIZE];  // Private array
    
public:
    // Constructor initializes array (0-4)
    arraytype() {
        for(int i = 0; i < SIZE; i++) {
            a[i] = i;
        }
    }

    // Overloaded [] operator declaration (returns a reference)
    int& operator[](int i); 
};

// Definition of operator[] with bounds checking
int& arraytype::operator[](int i) {
    if(i < 0 || i >= SIZE) {  // Check if index is invalid
        cout << "Index " << i << " is out of bounds.\n";
        exit(1);  // Terminate program on error
    }
    return a[i];  // Return reference to valid element
}

int main() {
    arraytype ob;

    // Valid access: prints 0 1 2 3 4
    for(int i = 0; i < SIZE; i++) {
        cout << ob[i] << " ";
    }

    // Invalid access: triggers boundary error
    ob[SIZE + 100] = 99;  // Program terminates here

    return 0;
}


Key Points:
1. Bounds Checking:

The operator[] checks if the index i is within [0, SIZE-1].

If invalid, it prints an error and terminates the program (exit(1)).



2. Reference Return (int&):

Allows [] to be used on both sides of an assignment (e.g., ob[i] = 5 or x = ob[i]).



3. Runtime Error Prevention:

The line ob[SIZE + 100] = 99 triggers the bounds check, prints Index 105 is out of bounds., and exits the program.

Important Remarks:
Safety vs. Overhead:

Safe arrays prevent boundary errors but add slight runtime overhead due to the index check.

Use this approach when safety is critical (e.g., user input handling).

Real-World Improvements:

In practice, consider throwing an exception (e.g., throw std::out_of_range("...")) instead of using exit(1) for better error handling.

Output:
Copy
0 1 2 3 4  
Index 105 is out of bounds.  

*/  
