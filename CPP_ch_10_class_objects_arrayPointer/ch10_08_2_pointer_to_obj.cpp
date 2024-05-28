
/*  ------------    Object Pointers    ------------
    We've already discussed this topic in : ch10_03_obj_pointer.cpp
        However, let's review it again


    We can 'access' a member of an object via "pointer" to that object. 
    
    When a "pointer" is used, the "arrow operator" (->) rather than the dot (.) operator is employed.
        (it is exactly the same way "->" is used when given a "pointer to a structure")

    However using the dot operator "." to access members of an object is the correct method



    object pointer declaration is same as any other variable. 
        Specify its class name, and then precede the variable name with an asterisk "*"

    Note that, creation of an object pointer does not create an object- 
        it creates just a pointer to one. 



    address:
        To obtain the address of an object, precede the object with "&" operator

    pointer arithmetic:    
        like other types, when object pointer incremented, it will point to the next object of its type.

*/




/* Example 1: following use two ways to access a class member of an object of that class
                    use "." operator 
                    use "->" operator (pointer)

                # Notice how following declaration creates a pointer to an object of myclass. 
                            myclass *p; 

                # The address of ob is put into p by using this statement:       
                            p = &ob;

                # Finally, the program shows how the members of an object can be accessed through a Pointer as using :      
                            p->get()
*/

#include <iostream>

class myclass{
        int a;
    public:
        myclass(int x) { a = x; }; // constructor
        int get() { return a; };
};


int main(){
    myclass ob(120); 	// create object
    myclass *ptr;       //  create pointer to object

    ptr = &ob; // put address of 'ob' into 'ptr'
    std::cout << " Access value using object : " << ob.get();  // dot-operator '.' is used
    std::cout << "\n";
    std::cout << " Access value using pointer : " << ptr->get(); // arrow-operator '->' is used

    return 0; 
}




/*  --------    Pointer arithmetic    --------
    Pointer arithmetic using an "object pointer" is the same as it is for any other data type: 
        it is performed relative to the "type" of the object. 
    
    For example, when an object pointer is incremented, 
        it points to the next object. 
    
    When an object pointer is decremented, 
        it points to the previous object. 
*/


/* Example 2: (Pointers increment) Here is an example of object pointer arithmetic 

                Notice the pointer arithmetic:
                    Each time p is incremented, it points to the next object in the array.
*/

#include <iostream>

class samp{
        int a, b;
    public:
        samp(int n, int m){ a = n; b = m; }     // inline function constructor
        int get_a(){ return a; }
        int get_b(){ return b; }
};


int main(){
    // initialization
    samp ob[4] = {
        samp(1, 2),
        samp(3, 4),
        samp(5, 6),
        samp(7, 8)
    };

    int i;
    samp *p;    // object pointer

    p = ob;     // get starting address of array
    for(i =0; i<4; i++){
        std::cout << p -> get_a() << ' ';
        std::cout << p -> get_b() << "\n";
        p++;    // advance to next object
    }

    std::cout << "\n";

    return 0;
}




/* Example 3: Rewrite above "Example 2" so it displays the contents of the ob array in "reverse order". */

// Display in reverse order.
#include <iostream>

class samp{
        int a, b;
    public:
        samp(int n, int m){ a = n; b = m; }     // inline function constructor
        int get_a(){ return a; }
        int get_b(){ return b; }
};


int main(){
    // initialization
    samp ob[4] = {
        samp(1, 2),
        samp(3, 4),
        samp(5, 6),
        samp(7, 8)
    };

    int i;
    samp *p;    // object pointer

    // p = ob;     // get starting address of array
    p = &ob[3];     // get address of last element, notice "&" is used for specific element
    for(i =0; i<4; i++){
        std::cout << p -> get_a() << ' ';
        std::cout << p -> get_b() << "\n";
        // p++;    // advance to next object
        p--;    // advance to previous object
    }

    std::cout << "\n";

    return 0;
}




/* Example 4: Change "ch10_08_1_array_of_obj.cpp", (Example 3) so the two-dimensional array is accessed via a pointer.

                Hint:   In C++, as in C, all arrays are stored contiguously, 
                        left to right, low to high. 

                (Multidimensional arrays of objeects) here is a program
                    that creates a 2D array of objects and initializes them: 

                notice the constructor takes one parameter, hence 'shorthand form' used
*/
// Access via a pointer a 2D-array of objects .
#include <iostream>

class samp{
        int a;
    public:
        samp(int n) { a = n; }
        int get_a() { return a; }
};


int main(){
    // following initalize 8 objects
    samp ob[4][2] = { 
        1, 2,
        3, 4,
        5, 6,
        7, 8,
    };

    int i;
    samp *p;    // pointer

    p = (samp *)ob;

    for (i =0; i<4; i ++){
        std::cout << p-> get_a () << " ";
        p++;
        std::cout << p-> get_a () << "\n";
        p++;
    }
    std::cout << "\n";

    return 0;
}


/* Cosider all 3 previous examples: Example 2, Example 3, Example 4,

        --------    Use ChatGPT to explain:    --------

        1. why cast/conversion needed in "p = (samp *)ob;"

        2. Explain:"error: cannot convert ‘samp [4][2]’ to ‘samp*’ in assignment"

        3. use samp ob[8] instead of samp ob[4][2], can you use "p =ob;" similar to "Example 2"

        4. whats the difference between:
                        Example 2 :     "p = ob;"
                        Example 3 :     "p = &ob[3];"
                        Example 4 :     "p = (samp *)ob;"
*/




/* Example 5: Consider: "Example 2" and "Example 4".
                Why "p = (samp *)ob;" used instead of "p = ob;" in the "Example 4"? 


answer:


In C++, when dealing with multidimensional arrays and pointers, the type of the pointer must match the type of the array elements. Let's dissect the reason behind using p = (samp *)ob; instead of p = ob; in the context of your examples.


Understanding Array Types and Pointers:

Consider the following declaration:

    cpp
    Copy code
    samp ob[4][2];
    This creates a two-dimensional array of samp objects. Here's how the types break down:

    ob is an array of 4 elements, where each element is an array of 2 samp objects.
    The type of ob is samp[4][2].
    The type of ob[0] is samp[2] (an array of 2 samp objects).
    The type of &ob[0][0] is samp* (a pointer to a samp object).


Pointer Arithmetic:
    When you assign a pointer to the array ob, you need to consider what exactly the pointer is pointing to:

    p = ob; would attempt to assign p a type of samp (*)[2], which is a pointer to an array of 2 samp objects.
    p = (samp *)ob; explicitly casts ob to a pointer to samp, effectively treating the entire 2D array as a contiguous block of samp objects.
    By using the cast p = (samp *)ob;, you are telling the compiler to treat the 2D array ob as if it were a single-dimensional array of samp objects. This is valid because, in memory, a 2D array is stored contiguously in row-major order (left to right, top to bottom).


Why Casting is Necessary?
    Without the cast, if you tried to directly assign p = ob;, the types wouldn't match:

    ob is of type samp[4][2].
    p is of type samp*.
    The cast p = (samp *)ob; ensures that the type of p is compatible with the type of &ob[0][0], effectively treating the 2D array as a contiguous block of memory.

    Summary
    In summary, p = (samp *)ob; is used to treat the 2D array as a contiguous block of memory. This allows you to increment the pointer p and access each samp object in sequence. Without the cast, the types would not be compatible, and you would not be able to perform pointer arithmetic correctly to traverse the entire 2D array as if it were a 1D array.


*/





/* Example 6: Why '&' is used in "p = &ob[3];"? Why not just "p=ob[3]" in "Example 3" ? */

In C++, the & operator is used to get the address of a variable. When working with pointers and arrays, it's crucial to understand the distinction between an object and the address of an object.

Understanding the Difference
p = ob[3]; assigns the value of the fourth element of the array ob (since array indexing is zero-based) to p. This is incorrect because p is a pointer to samp, not a samp object.
p = &ob[3]; assigns the address of the fourth element of the array ob to p. This is correct because p is supposed to point to a samp object.
Explanation
Here’s a detailed explanation of why & is used in p = &ob[3];:

Type Compatibility:

ob is an array of samp objects.
ob[3] is a samp object.
p is a pointer to a samp object (samp*).
To make p point to the fourth element of ob, you need to assign it the address of that element. The address of ob[3] is obtained using the address-of operator &.

Pointer Assignment:

p = &ob[3]; means that p now points to the memory location of the fourth element of ob.

Summary
p = ob[3]; tries to assign a samp object to a samp* pointer, which is incorrect.
p = &ob[3]; correctly assigns the address of the fourth samp object in the array ob to the pointer p.
Using &ob[3] ensures that p points to the correct memory location, allowing for proper pointer arithmetic and accessing the object's members correctly.





/* Example 7: Then why there is no '&' with "p = ob;" in the first example? */
Great question! The reason for the difference in the use of & in p = ob; and p = &ob[3]; is due to the way arrays and pointers interact in C++.

Arrays and Pointers in C++
In C++, arrays and pointers are closely related. When you use the name of an array by itself, it "decays" into a pointer to the first element of the array. This is a special behavior of arrays in C++.

Explanation
Case 1: p = ob;
When p = ob; is used, the array name ob decays into a pointer to its first element:

ob is of type samp[4], but when used in expressions, it decays to samp*, a pointer to the first element of the array.
Thus, p = ob; assigns the address of ob[0] to p.
This is why you don't need the & operator in this case. The array name itself acts as a pointer to the first element.

Case 2: p = &ob[3];
When you want p to point to a specific element of the array (in this case, the fourth element), you need to use the address-of operator &:

ob[3] is the fourth element of the array, which is of type samp.
&ob[3] is the address of the fourth element, which is of type samp*.
To make p point to the fourth element, you need to assign it the address of ob[3], hence p = &ob[3];.

Summary
p = ob;: Here, ob decays to a pointer to the first element of the array, so no & is needed.
p = &ob[3];: Here, ob[3] is an element of the array, so you need & to get the address of this specific element.


In summary:

p = ob; works because ob decays to &ob[0].
p = &ob[3]; works because you need the address of a specific element in the array.
This distinction ensures that p correctly points to the starting address of the array or a specific element within the array, respectively.





/* Example 8: use samp ob[8] instead of samp ob[4][2] in "Example 4", can you use "p =ob;" similar to "Example 2"? 

Answer: Yes you can. 
Also we can use the casting for 1D array
*/

// Access via a pointer a 2D-array of objects .
#include <iostream>

class samp{
        int a;
    public:
        samp(int n) { a = n; }
        int get_a() { return a; }
};


int main(){
    // following initalize 8 objects
    samp ob[8] = { 
        1, 2,
        3, 4,
        5, 6,
        7, 8,
    };

    int i;
    samp *p;    // pointer

    p = ob;
    // p = (samp *)ob;     // also works

    for (i =0; i<4; i ++){
        std::cout << p-> get_a () << " ";
        p++;
        std::cout << p-> get_a () << "\n";
        p++;
    }
    std::cout << "\n";

    return 0;
}



Example 9: I understand why i need casting "p = (samp *)ob;" for 2D array of objects. However can i still use the casting for 1D array? Or we have to use "p = ob"?

You don't have to use casting for a 1D array of objects because, in C++, the array name automatically decays to a pointer to its first element. However, you can use casting if you want, although it's redundant and not idiomatic.

Using Casting for 1D Array
While it is not necessary, you can still use casting for a 1D array, but it's typically avoided because it's not needed and reduces code readability.

Examples
Let's illustrate this with examples:

Without Casting (Recommended Way)

With Casting (Not Recommended but Possible)

#include <iostream>

class samp {
    int a, b;
public:
    samp(int n, int m) { a = n; b = m; } // inline function constructor
    int get_a() { return a; }
    int get_b() { return b; }
};

int main() {
    // initialization
    samp ob[4] = {
        samp(1, 2),
        samp(3, 4),
        samp(5, 6),
        samp(7, 8)
    };

    int i;
    samp *p;    // object pointer

    p = (samp *)ob; // get starting address of array (cast not necessary)
    for (i = 0; i < 4; i++) {
        std::cout << p->get_a() << ' ';
        std::cout << p->get_b() << "\n";
        p++;    // advance to next object
    }

    std::cout << "\n";

    return 0;
}


Why Casting is Not Necessary for 1D Arrays
Type Decay: When you use the name of a 1D array (ob), it decays to a pointer to its first element. This means p = ob; is already effectively p = &ob[0];.
Readability: Adding an unnecessary cast makes the code less readable and more complicated without any benefit.
Summary
While you can use casting for a 1D array of objects, it is redundant and not recommended. The preferred way is to use p = ob; for a 1D array, which automatically decays to the pointer to the first element. This keeps the code clean and idiomatic.



Example 10: But does using casting with 1D array of objects has side effects?

Using a cast with a 1D array of objects in C++ generally does not have adverse side effects, but it is redundant and can reduce code readability. Here are a few points to consider:

No Functional Side Effects
Type Compatibility: When you cast a 1D array of objects to a pointer to the first element ((samp *)ob), you are effectively telling the compiler to treat the array as a pointer to the first element, which is what happens implicitly anyway. Therefore, there are no functional side effects or changes in behavior.
Code Readability and Maintainability
Redundancy: Adding a cast where it is not needed makes the code less clean and can confuse readers who might wonder why the cast was necessary.
Maintainability: Overuse of casting can make the code harder to maintain and understand. Future developers (or even you) might spend extra time figuring out why a cast was used when it wasn't needed.

Conclusion
Using a cast with a 1D array of objects to a pointer does not have adverse side effects in terms of functionality. The cast is redundant because the array name already decays to a pointer to its first element. The main issues with using unnecessary casts are reduced code readability and maintainability. It is best practice to avoid unnecessary casting to keep the code clean and easy to understand.



