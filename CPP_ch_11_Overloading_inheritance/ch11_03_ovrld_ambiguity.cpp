
/*  ------------------------    Ambiguity caused by Overloading     ------------------------

    Ambiguity Caused By Overloading:
        Overloading-caused ambiguity can be introduced through 
            - type conversions, 
            - reference parameters, and 
            - default arguments. 

        Further, some types of ambiguity are caused by the "overloaded functions" themselves. 
        Other types occur in the manner in which an overloaded function is called. 


    solutions:
        Most often we'll "Explicitly Cast the Argument" to avoid ambiguty.
        Another solution is making the "Function Signatures" more distinct
*/  



/*  ------------    Type Conversion Ambiguity    ------------

    Type Conversion Ambiguity: 
        When an argument has a "compatible (but not exact) type" with the function parameter, C++ automatically converts it to the target type. 
            A "compatible (but not exact) type" refers to a type that can be implicitly converted 
                to another type through C++'s automatic type conversion rules, 
            For example, C++ will automatically convert types like "char to int" or "float to double" 
                when passing them as arguments if needed.

        This automatic type conversion may create ambiguity 
            if there are multiple overloaded functions that can match due to the conversion.

        Example: 
            This type conversion allows a function like putchar() to accept a "char" argument, even though its parameter is specified as "int".
*/




/* Example 1: Consider the following example with "int" and "double" types, also notice:
                    printValue(int) takes an int parameter, and also accept a "char" argument
                    printValue(double) takes a double parameter, and also accept a "float" argument


                ambiguity:
                    When printValue(value) is called with value of type "float", it causes ambiguity because:

                        float can be "implicitly" converted to int for printValue(int).
                        float can also be "implicitly" converted to double for printValue(double).

                Since both conversions are compatible (but not exact matches), the "compiler can't decide" which overload to choose, 
                    resulting in an ambiguous call.


                Solution:
                    Use an "explicit cast" to match the type "exactly", like 
                        printValue(static_cast<int>(value)); 
                                or 
                        printValue(static_cast<double>(value));.

                    Modify the function to take a float if float arguments are common in usage.

    This type of ambiguity arises when the "argument type" is compatible with "multiple overloaded functions" but doesn’t match any of them exactly.
*/
    
#include <iostream>

void printValue(int x) {
    std::cout << "Integer: " << x << std::endl;
}

void printValue(double x) {
    std::cout << "Double: " << x << std::endl;
}


int main() {
    float value = 5.5f;

    printValue(value); // Ambiguous call

    return 0;
}




/* Example 2: Notice the following program:
                    The compiler correctly selects the appropriate version of f() when called with either a "float" or "double".

                    However, when called with an "int", ambiguity arises. 
                        The compiler can't decide whether to promote the "int" to a "float" or "double", 
                        Does the compiler call f(float) or f(double)?
                            as both conversions are valid. This creates an ambiguous situation.


                f(x) calls f(float) because x is of type float.
                f(y) calls f(double) because y is of type double.
                f(10) would be ambiguous because 10 can be implicitly converted to either float or double.

                To resolve this, use an "explicit cast" to specify which function to call:
                    f(static_cast<float>(10)) calls f(float)
                    f(static_cast<double>(10)) calls f(double)
*/

#include <iostream>

float f(float i) { 
    return i/2.0; 
}

double f(double i) { 
    return i/3.0; 
}

int main() {
    float x = 10.09;
    double y = 10.09;

    std::cout << f(x) << std::endl;   // unambiguous - calls f(float)
    std::cout << f(y) << std::endl;   // unambiguous - calls f(double)

    // followig line cause "Ambiguous ERR"
    std::cout << f(10) << std::endl;     // ambiguous - should 10 be converted to float or double?

    // To resolve ambiguity, use an explicit cast:
    std::cout << f(static_cast<float>(10)) << std::endl;   // calls f(float)
    std::cout << f(static_cast<double>(10)) << std::endl;  // calls f(double)

    return 0;
}




/* Example 3: when this function is called with the wrong type of argument, 
                C++'s automatic conversion rules cause an ambiguous situation.

                When f() is called with the numeric constant 86, 
                    the compiler cannot know whether to call f(unsigned char) or f(char). 
                    Either conversion is equally valid, thus leading to ambiguity.
*/
#include <iostream>

void f(unsigned char c){std::cout << c;}

void f(char c){std::cout << c;}	

int main(){
    f('c');
    f(86);   // which f() is called ?
    // f(static_cast<unsigned char>(86));

	return 0; 
}




/* ------------    Ambiguity by Reference    ------------
    Ambiguity by Reference:
        In C++ there is no syntactical difference between 
            -   calling a function that takes a "value parameter" and 
            -   calling a function that takes a "reference parameter"
    
        This can lead to ambiguity, especially if two overloaded functions exist, 
            one taking a value and the other a reference :
*/
#include <iostream>

int f(int a, int b){ 
    std::cout << "value" << std::endl;
    return a+b;     // function with both parameters by value
}    

int f(int a, int &b){ 
    std::cout << "reference" << std::endl;
    return a-b;     // function with second parameter by reference
}    


int main(){
    int x=1, y=2;

    std::cout << f(x, y);    // ambiguous: which version of f() is called?
    // Explicitly pass y as a reference or a value
    std::cout << f(x, static_cast<int>(y));    // ambiguous: calles by value i.e. f(int a, int b)
    std::cout << f(x, std::ref(y)) << std::endl;  // wont work either: Calls the reference version f(int, int&)

    return 0;
}

// Here, f(x, y) is ambiguous because it could be calling either version of the function

/*  Solutions: Explicitly cast the argument
        std::cout << f(x, static_cast<int>(y));     // Calls "f(int, int)"
        std::cout << f(x, y);   // This will call "f(int, int&)" because 'y' is passed as a reference
*/




/* ------------    Ambiguity by default arguments    ------------
    Ambiguity by default arguments
        Ambiguity occurs if one or more overloaded functions use a default argument
        because default arguments can make it unclear which version of an overloaded function should be called

    Here the call f(10, 2) is perfectly acceptable, and unambiguous.
    f(10) is ambiguous because:
        It could match the first version f(int) directly.
        It could also match the second version f(int, int), with the default value for b (i.e., b = 0).
        Since both versions are valid candidates for f(10), the compiler does not know which function to choose.
*/

#include <iostream>

int f(int a){        // First version: takes a single int parameter
    return a*a;
}

int f(int a, int b = 0){  // Second version: takes two int parameters, with b defaulting to 0
    return a*b;
}

int main(){
    std::cout << f(10, 2) << std::endl;  // Calls f(int, int) - unambiguous
    std::cout << f(10) << std::endl;     // Ambiguous: could be calling either f(int) or f(int, int)

    return 0;
}


/* Solution to Resolve Ambiguity:
    To avoid this ambiguity, remove the default argument in the second version of the function. 
    By making f(int, int) require two parameters explicitly, f(10) will unambiguously match f(int). 
    
    int f(int a, int b) {    // Second version: takes two int parameters, no default value for b
        return a * b;
    }
*/




/* Example 4: Explain some ways that ambiguity can be introduced when you are overloading functions. 

                Ways Ambiguity Can Occur in Function Overloading:

                    Default Type Conversions: 
                        When arguments are automatically converted to match parameter types

                    Reference Parameters: 
                        Functions with reference parameters can clash with those using value parameters
                        
                    Default Arguments: 
                        Functions with default values can conflict with other overloaded versions if the arguments overlap.
*/




/* Example 5: What is wrong with the following fragment?

                    void compute(double *num, int divisor =1);
                    void compute(double * num);
                    // ...
                    compute (&x);

                ans:
                    It is ambiguous because the compiler cannot know which version of compute() to call.
                    Is it the first version, with divisor defaulting? 
                    Or is it the second version, which takes only one parameter?
*/




/* Example 6: Why are the following two overloaded functions inherently ambiguous?

                        int f( int a);
                        int f( int &a); 

            ans:
                The syntax for calling a function that takes a "reference parameter"
                is identical to the syntax for calling a function that takes a "value parameter".
*/




/* Example 7: What is wrong with these two overloaded functions?
                    void f(int a);
                    void f(int &a); 

                A function cannot be overloaded when the only difference is that: 
                    one version takes a value parameter and 
                    the other takes a reference parameter. 

                    (The compiler cannot tell them apart.)
*/

