
/*  ------------------------    address of an overloaded function    ------------------------
    Finding the address of an overloaded function

        recall function pointers: "C_Ch8_6_func_pointers.c"

    Address of an OVERLOADED function :
        In C, you can assign the address of a function (that is, its entry point) to a pointer 
            and access that function via that pointer. 
        A function's address is obtained by putting its name 
            on the right side of an assignment statement without any parentheses or arguments. 
    
    For example, if zap() is a function, then we assign p the address of zap():

            p = zap;
    

    --------    C vs C++    --------
    In C, "any type of pointer" can be used to "point to a function" 
        because there is only one function that it can point to. 
    
    In C++ the situation is a bit more complex because a function can be "overloaded".
    When we assign the address of an "overloaded function" to a function pointer, 
        it is the declaration of the pointer that determines which function's address is assigned. 
    Further, the declaration of the function pointer must "exactly match one and only one" of the overloaded functions. 
    If it does not, ambiguity will be introduced, causing a compile-time error.


    Example:
                    int add(int a, int b) { return a + b; }
                    double add(double a, double b) { return a + b; }

                    int (*intAddPtr)(int, int) = add;    // Points to add(int, int)
                    double (*doubleAddPtr)(double, double) = add; // Points to add(double, double)


        In this example:
            "intAddPtr" matches add(int, int) exactly, so it points to that version.
            "doubleAddPtr" matches add(double, double) exactly, so it points to that version.
            If intAddPtr or doubleAddPtr had an "incompatible signature", it would cause an error.


    Note:
        When assigning the "address of an overloaded function" to a function pointer:
            The pointer's declaration determines which version of the function is assigned.
            The pointer's type must exactly match one specific version of the overloaded functions.
        
        If the declaration doesn't match any version or matches more than one, 
            it causes ambiguity and results in a compile-time error.

*/  



/* Example 1: Following program contains two versions of a function called space().

                Two Versions of space() Function:
                    The first version of space() outputs a specified number (count) of "spaces" on the screen.
                    The second version of space() outputs a specified number (count) of a given "character" (ch).

                In main(), two function pointers are declared:
                    fp1: A pointer to a function that takes a single integer parameter.
                    fp2: A pointer to a function that takes two parameters — an integer and a character.

                The compiler determines which version of the space() function to assign to each pointer (fp1 and fp2) 
                    based on the parameters specified in their declarations.
*/

#include <iostream>

void space(int n){      // Type-1: Output n number of spaces
    for( ; n; n--) std::cout << ' '; 
}

void space(int n, char ch){        // Type-2: Output n chs
    for( ; n; n--) std::cout << ch; 
}


int main() {
    // pointer to void function with one int parameter
    void ( *fp1 )(int );    // matches to Type-1 

    // pointer to void function with int and character parameter.
    void ( *fp2 )(int, char);   // matches to Type-2 

    fp1 = space;   // gets address of space(int)
    fp2 = space;   // gets address of space(int , char)

    fp1(22) ;   // output 22 spaces 
    std::cout << "|\n";

    fp2(30 , 'x'); // output 30 x's 
    std::cout << "|\n";

    return 0;
}




/* Example 2: Following are two overloaded functions. Show how to obtain the address of each. 

                    int dif(int a, int b){
                        return a-b;
                    }

                    float dif(float a, float b){
                        return a-b;
                    }

                ans:
                    // pointer to void function with one int parameter
                    void ( *p1 )(int, int);    // matches to Type-1 

                    // pointer to void function with int and character parameter.
                    void ( *p2 )(float, float);   // matches to Type-2 

                    p1 = dif;   // gets address of space(int)
                    p2 = dif;   // gets address of space(int , char)
*/
