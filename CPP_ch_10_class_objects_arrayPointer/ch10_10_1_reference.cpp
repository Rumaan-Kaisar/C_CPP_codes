
/*  ---------------    references    ---------------
    Java, Python, and JavaScript are often described as "not using POINTERS" in the same way as languages like C or C++. 
    They use REFERENCES, which serve a similar purpose to pointers but operate at a higher level of abstraction.


    Key Differences from Pointers:
        No Pointer Arithmetic:
            Unlike C/C++, none of these languages allow pointer arithmetic. 
            You cannot directly manipulate the memory addresses.

        No Explicit Memory Management:
            Memory management is handled "automatically" in these languages, 
            so there is no need to "manually" allocate and deallocate memory.

        Safety:
            References are designed to be safer and less error-prone compared to "raw pointers", 
            reducing the risk of "memory leaks", "segmentation faults", and other pointer-related bugs.


        ----  operation procedure  ----
        referance operation:
            just use &
            
        pointer operation:
            memory address: 
                "&" is used to get the memory address of a variable

            dereferencing: 
                In C++, the "dereferencing symbol" is the asterisk (*). 
                you can use the dereferencing operator to get the value stored at the memory address held by the pointer.



    C++ references:
        C++ has the concept of references, which are a safer and more user-friendly alternative to pointers

        A reference in C++ is an "alias" for another variable. 
        A reference is an "implicit pointer" that 
            for all intents and purposes acts like another name (i.e. alias) for a variable. 

        Once a reference is initialized to a variable, it "cannot be changed" to refer to another variable.
        This provides a way to access the same "memory location" with a different name.

        Syntax:
            To declare a reference, you use the "&" symbol:

                int x = 10;
                int &ref = x;   // "ref" is now a reference to x


        --------    Usage    --------
        There are three ways that a reference can be used.
            First, a reference can be "passed" to a function. 
            Second, a reference can be "returned" by a function. 
            Finally, an "independent reference" can be created. 
 

        --------    Properties    --------
        Initialization: 
            References must be initialized when they are declared. 
            You cannot have an uninitialized reference.
        
        Aliases: 
            A reference acts as an alias to the original variable. 
            Any operation performed on the reference "affects" the original variable.
        
        Non-nullable: 
            Unlike pointers, references cannot be "null". 
            They must "always refer" to a valid object.
        
        Immutability: 
            Once a reference is bound to a variable, it cannot be changed to refer to another variable.



    --------    Benefits of Using References    --------
    Simplicity:
        References are easier to use and understand than pointers 
        because they do not require dereferencing syntax (*) and cannot be null.

    Safety:
        References eliminate many of the common bugs associated with pointers, 
        such as "null pointer dereferencing" and "pointer arithmetic errors".

    Readability: 
        Code that uses references is often more readable and expressive.


    ADVANTAGES over equivalent pointer alternatives: 
        1. No longer need to remember to pass the address of an argument, it's done autometically
        2. reference parameters offer a cleaner, more elegant interface

        3. when an object is passed to a function as a reference, no copy is made.
                avoiding the troubles associated with the copy of an argument damaging
                something needed elsewhere in the program when its DESTRUCTOR function is called.


    Finally, note that:
        reference is NOT a pointer
            Pointers: Indirect access (like a map to a treasure).
            References: Direct access (like a nickname for a friend).

        Use POINTERS for "indirect manipulation", dynamic memory allocation, and null checks

        Use REFERENCES for function arguments where you want to modify the original variable and 
            for clarity when you don't need the extra features of pointers.
*/




/* Example 1: Here is a simple example demonstrating the use of references in C++: */

#include <iostream>

void increment(int &ref) {
    ref++; // increment the value of the referenced variable
}


int main() {
    int a = 5;
    int &rf = a; // rf is a reference to a

    std::cout << "a: " << a << std::endl; // Output: 5
    std::cout << "ref: " << rf << std::endl; // Output: 5

    rf = 10; // modifying "rf" modifies the original variable "a"
    std::cout << "a after modifying ref: " << a << std::endl; // Output: 10

    increment(a); // pass a by reference to the function
    std::cout << "a after increment: " << a << std::endl; // Output: 11

    return 0;
}




/* Example 2: Using references to Function Parameters and Return Values 
                This example demonstrates how references can be used to manipulate data efficiently and safely in C++.

                The "swap" function uses references to swap the values of two variables directly. 

                The "getLarger" function "returns a reference" to the larger of two values, 
                    allowing direct modification of the original variable. 
*/

#include <iostream>

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int& getLarger(int &x, int &y) {
    return (x > y) ? x : y;
}

int main() {
    int a = 5, b = 10;

    swap(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl; // Output: a: 10, b: 5

    int &larger = getLarger(a, b);
    std::cout << "Larger: " << larger << std::endl; // Output: Larger: 10

    larger = 20; // modifying "larger" modifies "a"
    std::cout << "a after modifying larger: " << a << std::endl; // Output: a: 20

    return 0;
}




/*  ------------    Reference as parameter    ------------
    The most important use of a reference is as a parameter to a function.
    To demonstrate, we first use a pointer parameter, then we use a reference parameter.
*/



/* Example 3: Following program uses a "pointer" (not a reference) as a parameter 
                This program demonstrates how a POINTER is used as a parameter to 
                    manually create a "call-by-reference parameter-passing" mechanism. 

                In a "C" program, this is the only way to achieve a "call-by-reference".
*/
// using POINTER parameter
#include <iostream>

void f(int *n);     // use a POINTER parameter


int main(){
    int i = 0;

    f(&i);  // using POINTER, (not a reference)
    std::cout << " Here is i's new value : " << i << "\n";
    return 0;
}

void f( int *n){
    *n = 100; // put 100 into the argument pointed to by n
}


/*  Here f() loads the value 100 into the integer pointed to by n. 
    f(&i) means f() is called with the address of i in main(). 
    Thus, i contains the value 100 after f() returns, 
*/




/* Example 4: in C++ reference parameter completely automate above process.
                When you use a reference parameter, 
                    the compiler automatically passes the address of the variable used as the argument. 
                Thus, a reference parameter fully automates the "call-by-reference parameter-passing" mechanism.

                Following is a rework of the previous program.
                Following uses a REFERENCE parameter.
*/

#include <iostream>

void f(int &n);     // declare a "reference parameter", instead of "pointer parameter"


int main(){
    int i = 0;

    f(i);   // notice no use of '&'
    std::cout << " Here is i's new value : " << i << "\n";

    return 0;
}

void f(int &n){
    // reference parameter: notice that no * is needed in the following statement
    n = 100;    // put 100 into the argument used to call f()
}


/* 
    To declare a reference variable or parameter, you precede the variable's name with the "&". 
        Eg: This is how n is declared as a parameter to f(). 
                
                void f(int &n)

        Now that n is a reference, using * isn't allowed any more
            each time n is used within f(), it is automatically treated as a pointer to the argument used to call f()

        Within the function, the compiler automatically uses the "variable pointed to by the reference parameter"
        i.e. the statement "n = 100;" actually puts the value 100 into the variable used to call f(), which in this case, is "i"


        when f() is called, it's also not allowed to precede the argument with the &
            because f() is declared as taking a reference parameter, 
            the "address to the argument" is automatically passed to f()
*/




/*  ------------    Pointer arithmetic is not allowed for references    ------------

    You cannot change what a reference is pointing to. 
        If the statement   " n++ ; "   were put inside f() in the preceding program, 
        "n" would still be pointing to i in main() instead of incrementing n. 
        This statement actually "increments the value" of the variable being referenced  (in this case, i).
    
    If you need to perform "pointer arithmetic", you should use pointers instead of references.


    You cannot use pointer arithmetic with references in C++. 
        References and pointers are fundamentally different in how they are used and managed.

    ----  Differences Between References and Pointers  ----
    References:
        A reference is an alias for another variable.
        Once a reference is initialized to a variable, it cannot be changed to refer to another variable.
        References are typically implemented as "pointers under the hood", but "they are not pointers" in terms of syntax and usage.
        You cannot perform arithmetic operations (like INCREMENTING or DECREMENTING) on references.

    Pointers:
        A pointer is a variable that holds the memory address of another variable.
        Pointers can be reassigned to point to different variables.
        Pointer arithmetic is possible, 
        You can increment or decrement pointers to "TRAVERSE" arrays or other data structures.


    However, attempting pointer arithmetic with a reference will not produce a compilation error
        Operations on references directly affect the referred variable

        Therefore, the line ++ref; in "Example 6" is valid and increments the value of a, 
            which is why it does not produce a compilation error. 

*/



/* Example 5: Pointer Arithmetic. */
#include <iostream>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *p = arr;

    for (int i = 0; i < 5; ++i) {
        std::cout << *p << " "; // Output: 10 20 30 40 50
        ++p; // Move to the next element in the array
    }

    return 0;
}




/* Example 6: Attempting Pointer Arithmetic with References: */
#include <iostream>

int main() {
    int a = 10;
    int &ref = a;

    // This increments the value of 'a' through the reference 'ref' but not the reference itself
    ++ref; // 'a' is now 11

    std::cout << ref << std::endl; // Output: 11
    std::cout << a << std::endl;   // Output: 11

    return 0;
}





// --------    Swap using pointer & and referance    --------


/* Example 7: This example demonstrates how references can be used to manipulate data efficiently and returned in C++

                Following swap() function swaps the values of two integer variables using REFERENCES 
                and retrun the larger value using getLarger()


                Notice, the function-definition,  "void swap(int &x, int &y)" takes two parameters: int &x and int &y
                    These are "references to integers", meaning 
                    any changes made to x and y within the function will directly affect the variables passed as arguments.


                Inside the main() function, "a" and "b" are declared and initialized with values 5 and 10
                    The swap() function is called with 'a' and 'b' as arguments "swap(a, b);"
                    Since swap uses REFERENCES, the values of 'a' and 'b' are swapped (affecting 'a', 'b' directly)
                    After swapping, 'a' becomes 10 and 'b' becomes 5.



                Also notice getLarger() function, it returns a reference

                    it takes two integer references as parameters and returns a reference to the larger of the two.
                        which in this case is 'a', The reference is stored in "larger".

                    Now, since "larger" is connected to 'a', modifying "larger" wil affect 'a'
                        The value of "larger" is changed to 20. Since "larger" is a reference to "a", "a" is also modified

*/

#include <iostream>

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int& getLarger(int &x, int &y) {
    return (x > y) ? x : y;
}

int main() {
    int a = 5, b = 10;

    swap(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl; // Output: a: 10, b: 5

    int &larger = getLarger(a, b);
    std::cout << "Larger: " << larger << std::endl; // Output: Larger: 10

    larger = 20; // modifying larger modifies a
    std::cout << "a after modifying larger: " << a << std::endl; // Output: a: 20

    return 0;
}




/*  --------  swapping using REFERENCES  -------- 

                    void swap(int &x, int &y) {
                        int temp = x;
                        x = y;
                        y = temp;
                    }

        Direct Manipulation: 
            Changes made to x and y within the function directly affect the variables passed as arguments

        Cleaner Syntax: 
            Using references results in cleaner syntax since there's no need to use the dereference operator (*)

        usage:
            swap(a, b);


    --------  swapping using POINTERS  --------

                    void swap(int *x, int *y) {
                        int temp = *x;
                        *x = *y;
                        *y = temp;
                    }

        Indirect Manipulation:
            Changes made to *x and *y within the function indirectly affect the variables passed as arguments

        Syntax Complexity:
            Using pointers requires dereferencing (*x, *y), which can make the code slightly more complex

        usage:
            swap(&a, &b);
*/




/* Example 8: What is the difference between referance swap and pointer swap? 

                syntax
                    References is Simpler and cleaner, no need to worrying about "dereferencing"
                    Pointers requires explicit passing of the "ADDRESS" using the address-of operator (&) 
                        and dereferencing within the function using "*".

                Safety:
                    References generally safer as they are less prone to errors such as "null pointer dereferencing".
                    Pointers more flexible but can lead to runtime errors 
                        if not managed carefully (e.g., dereferencing a null pointer).


                Function Calls:
                    References function call looks identical to passing by value, "swap(a, b);"
                    Pointers function call requires explicitly passing addresses, "swap(&a, &b);"
                        making it clear that the function may modify the original variables.

*/

// Swap Using REFERENCES:
#include <iostream>

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    swap(a, b); // Swaps the values of a and b
    std::cout << "a: " << a << ", b: " << b << std::endl; // Output: a: 10, b: 5
    return 0;
}



// Swap Using POINTERS:
#include <iostream>

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a = 5, b = 10;
    swap(&a, &b); // Swaps the values of a and b
    std::cout << "a: " << a << ", b: " << b << std::endl; // Output: a: 10, b: 5
    return 0;
}




/* Example 9: Can a swap be done simply without using references or pointers? 

                Ans:    SCOPE matters!!!
                        Yes, you can implement a swap function without using references or pointers, 
                            but it won't affect the original variables outside the function SCOPE. 
                            It doesn't modify the "actual variables" passed to the function
                        
                        Without references or pointers, the swap function cannot modify the actual variables passed to it, 
                            making the swap only local to the function.
*/
#include <iostream>

// Swap Without References or Pointers
void swap(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "Inside function - x: " << x << ", y: " << y << std::endl;
}

int main() {
    int a = 5, b = 10;
    swap(a, b);
    std::cout << "Outside function - a: " << a << ", b: " << b << std::endl; // Output: a: 5, b: 10
    return 0;
}

/*  In this case the swap function takes x and y as parameters "by value" 
        that means the function receives "copies of a and b"

    Inside the function, x and y are swapped 
        However, since x and y are "local" to the function, 
        the "original" values of a and b in the main function are "not affected"
*/



// Practical Swap Function:
// To actually swap the values of variables in the main function, you need to use either references or pointers

#include <iostream>

// using reference
void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
    std::cout << "Inside function - x: " << x << ", y: " << y << std::endl;
}

int main() {
    int a = 5, b = 10;
    swap(a, b); // Swaps the values of a and b. modifies 'a and b' directly
    std::cout << "Outside function - a: " << a << ", b: " << b << std::endl; // Output: a: 10, b: 5
    return 0;
}

// Using references (or pointers) allows the function to modify the original variables




/* Example 10 (another swap function):  The classic example of "passing arguments by reference" is 
                a function that "exchanges the values of the two arguments" with which it is called. 

                Folowing swap_args() uses references to swap its two integer arguments:
*/
// using references	
#include <iostream>

void swapargs (int &x, int &y);


int main(){
    int i, j;

    i = 10;
    j = 19;
    std::cout << "i: " << i << ", ";
    std::cout << "j: " << j << "\n";

    swapargs (i, j);
    std::cout << " After swapping : " << "i: " << i << ", " << "j: " << j << std::endl;

    return 0;
}


void swapargs(int &x, int &y){
    int t;

    t = x;
    x = y;
    y = t;
}



// using pointers
#include <iostream>

void swapargs(int *x, int *y);
// Notice in the reference version of swapargs(), there is no need for the * operator


int main(){
    int i, j;

    i = 10;
    j = 19;
    std::cout << "i: " << i << ", ";
    std::cout << "j: " << j << "\n";

    swapargs (&i, &j);  // change
    std::cout << " After swapping : " << "i: " << i << ", " << "j: " << j << std::endl;

    return 0;
}


void swapargs(int *x, int *y){
    int t;
    
    t = *x;
    *x = *y;
    *y = t;
}




/* Example 11: Here is a program that uses the rounder() function to "round a double value". 
                The value to be rounded is passed by reference. 

                Notice, rounder() uses a relatively obscure standard library function called modf() 
                    to decompose a number into its whole number and fractional parts.

                    The "fractional part" is returned; 
                    The "whole number" is put into the variable pointed to by modf()'s second parameter.
*/
#include <iostream>
#include <cmath>

void rounder(double &num);

int main(){
    double i = 100.4;

    std::cout << i << " rounded is ";
    rounder(i);
    std::cout << i << "\n";

    i = 10.9;
    std::cout << i << " rounded is ";
    rounder(i);
    std::cout << i << "\n";

    return 0;
}


void rounder(double &num){
    double frac;
    double val;

    // decompose "num" into "whole" and "fractional" parts
    frac = modf(num , &val);
    std::cout << "(Itegral part: " << val << " fractional part: " << frac << ")" << std::endl;
    // rounding
    if(frac < 0.5) num = val;
    else num = val +1.0;
}


/* Note:    ambiguity error

            It arises if we define and name our own "round" function within the code, 
                which conflicts with the standard "round" function from the <cmath> header std::round
                So we set a different name: "rounder"
*/
// demo of std::round
#include <iostream>
#include <cmath>

int main(){
    double i = 100.4;

    std::cout << i << " rounded is ";
    std::cout << std::round(i) << "\n";

    i = 10.9;
    std::cout << i << " rounded is ";
    std::cout << std::round(i) << "\n";

    return 0;
}




/*  --------    modf() Function in C++    --------
    The modf() function is used to "decompose" a floating-point number (num) 
        into its integral and fractional parts. It takes two arguments:

            num: The floating-point number to be decomposed.
            &val: A pointer to a "double-precision floating-point variable" where the integral part will be stored.

        modf() calculates the integral part of num.
            It stores the integral part in the memory location pointed to by &val.
            The function then "returns the fractional part" of num.
*/

#include <iostream>
#include <cmath>

int main() {
    double num = 3.14159;
    double integralPart;

    double fractionalPart = modf(num, &integralPart);

    std::cout << "Original number: " << num << std::endl;
    std::cout << "Integral part: " << integralPart << std::endl;
    std::cout << "Fractional part: " << fractionalPart << std::endl;

    return 0;
}




// ----  rev[08-7-2024]  ----

/* Example 12: Write a function called neg() that "reverses the sign" of its integer parameter.
                Write the function two ways-
                    first by using a pointer parameter and 
                    then by using a reference parameter. 

                Include a short program to demonstrate their operation. 
*/
#include <iostream>

void rneg(int &i);  // reference version
void pneg(int *i);  // pointer version

int main ()
{
int i = 10;
int j = 20;
rneg (i);
pneg (&j);
cout << i << ’ ’ << j << ’\n’;
return 0;
}
// using a reference parameter
void rneg ( int &i)
{
i = -i;
}
// using a pointer parameter
void pneg ( int *i)
456ANSWERS
4.7 EXERCISE
{
*i = -*i;
}



/* Example 13: What is wrong with the following program? */
// This program has an error .
# include <iostream >
using namespace std ;
void triple ( double & num );
int main ()
{
double d = 7.0;
triple (&d);
cout << d;
return 0;
}
// Triple num ’s value .
void triple ( double & num )
{
num = 3 * num ;
}

When triple() is called, the address of d is explicitly obtained with the & operator. This
is neither necessary nor legal. When a reference parameter is used, the argument is not
preceded by the &.




/* Example 14: Give some advantages of reference parameters. */
The address of a reference parameter is automatically passed to the function. You need
not obtain the address manually. Passing by reference is often faster than passing by
value. No copy of argument is generated. Therefor, there is no chance of a side effect
occurring because the copy’s destructor is called.

