
// --------    rev[15-Aug-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-

// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-

// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-









/* Example 6: Can dynamically allocated arrays be initialized? 
                In C++, why it is not possible to initialize an "array" that is dynamically allocated? 
                Explain it in short way.

            ans: No.
            Reason: 
                Dynamically allocated arrays in C++ are essentially pointers to a "block of memory". 
                Initialization requires "knowing the memory location" and values to store, 
                    which isn't possible at compile time. 
                You must manually assign values to elements after allocation.



----  Gemini  ----
When you dynamically allocate an array in C++ using "new", 
    you're essentially "reserving a block of memory" without specifying its contents. 

This is because:

Memory Location Uncertainty: 
    The exact memory address where the array will be stored is determined at "runtime", not "compile time". 
    This makes it impossible to pre-fill values during the allocation process.

Compiler Limitations: 
    The compiler doesn't have enough information at compile time to know the specific values you want to initialize the array with, especially if those values are determined by user input or calculations.
Efficiency: Initializing every element to a default value (like 0) during allocation might introduce unnecessary overhead, especially for large arrays.
Therefore, to initialize a dynamically allocated array, you must manually assign values to each element after the allocation using a loop or other methods. This gives you flexibility in setting the initial values based on your program's logic.

Example:

C++
int size = 5;
int* arr = new int[size]; // Allocate memory for an array of 5 integers

// Initialize elements manually
for (int i = 0; i < size; ++i) {
    arr[i] = i * 2; // Assign values to elements
}



----  GPT  ----
In C++, when you dynamically allocate an array using new, you can't directly initialize it with a list of values because the memory is allocated at runtime, and there's no syntax for providing an initializer list like with a static array.

For example, this is not allowed:
int* arr = new int[5] {1, 2, 3, 4, 5}; // This won't compile in standard C++


Why?
Static Arrays: When you create a static array (e.g., int arr[5] = {1, 2, 3, 4, 5};), the initializer list is used at compile-time to allocate and initialize the array.

Dynamic Arrays: With dynamic arrays, the memory is allocated at runtime, so there's no mechanism in the language to take an initializer list and apply it to the dynamically allocated memory.



How to Initialize Dynamically Allocated Arrays:
1. Manual Initialization: Use a loop to manually assign values:


int* arr = new int[5];
for (int i = 0; i < 5; i++) {
    arr[i] = i + 1;
}


2. Use std::vector: If you need the convenience of initialization and dynamic sizing, use std::vector, which allows initializing with a list of values.
std::vector<int> arr = {1, 2, 3, 4, 5};

Summary:
Dynamic arrays are allocated at runtime, and C++ doesn't provide a direct way to initialize them with an initializer list at that time. You need to manually initialize each element or use higher-level containers like std::vector.




*/










/* Example 7: Create a function called mag() using the following prototype that raises num to the order
of magnitude specified by order: */
void mag ( long &num , long order );
For example, if num is 4 and order is 2, when mag() returns, num will be 400. Demonstrate in a program that the function works.

7. # include <iostream >
using namespace std ;
void mag ( long &num , long order );
int main ()
{
long n = 4;
long o = 2;
cout << "4 raised to the 2nd order of magnitude is ";
mag (n, o);
cout << n << ’\n’;
return 0;
}
void mag ( long &num , long order )
{
for ( ; order ; order --)
num = num * 10;
}








// ------------    Cumulative/Masery/Review skill check    ------------



