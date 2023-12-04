
/* ----------------------     Function overloading (intro)     ----------------------

    Function overloading:
        In C++ function overloading is one type of POLYMORPHISM (compile-time polymorphism). 
            When two or more functions share the same name, they are said to be overloaded.

        In C++, two or more functions can share the 'same name' as long as either:
            the "TYPE of their arguments" differs or 
            the "number of their arguments" differs
            or both
    
        Overloaded functions can help reduce the complexity of a program by 
            allowing 'related operations' to be referred to by the same name.



    How to overload a function: 
        simply DECLARE and DEFINE all required versions. 
        the 'compiler' will 'automatically select' the correct version based 
            upon the 'NUMBER' and/or 'TYPE' of the arguments used to call the function.
        
        it's the ARGUMENTs that make the difference. 

    It is also possible in C++ to overload OPERATORS. 

    return type not used to overload: The 'return type of a function'  alone is not a sufficient difference to allow function overloading. 
        If two functions differ only in the "type of data they return", the compiler will not always be able to select the proper one to call. 
        For example, this fragment is incorrect because it is inherently ambiguous. 		
        
            int f1(int a);
            double f1( int a);
            . . . 
            . . .
            f1(10) ; 	// which function does the compiler call ??? 

        As the comment indicates, the compiler has no way of knowing which version of f1() to call.
*/




/* Example 1: Example of 'Function overloading'.
                The C standard library contains the functions abs(), labs(), and fabs(),
                    which return the absolute value of an integer, a long integer, and a floating-point value, respectively.

                    In C++, you can 'overload one name' for the three types of data, as this example illustrates:
                
                However, abs() is already defined in C++, that's why abs(-10) will invoke the library abs()
                    function, not ours, and won't print "Absolute of -10 : In integer abs() = 10"
                That's why we'll change our function name abs() to abs_val()
*/

#include <iostream>
// using namespace std;

// Overloading three abs() functions with different types
int abs_valu(int n);
long abs_valu(long n);
double abs_valu(double n);

int main(){
    std::cout<<"Absolute of -10 : "<<abs_valu(-10)<<"\n";
    std::cout<<"Absolute of -10L : "<<abs_valu(-10L)<<"\n";
    std::cout<<"Absolute of -10.01 : "<<abs_valu(-10.01)<<"\n";

    return 0;
}

// abs() for ints
int abs_valu(int n){
    std::cout<< "\n In integer abs() = ";
    return n<0 ? -n : n;
}

// abs() for longs
long abs_valu(long n){
    std::cout<< "\n In long abs() = ";
    return n<0 ? -n : n;
}

// abs() for doubles
double abs_valu(double n){
    std::cout<< "\n In double abs() = ";
    return n<0 ? -n : n;
}


// As you can see, this program defines three functions called abs()-one for each data type.
// Inside main(), abs() is called using 'three different types of arguments'. 
// The compiler automatically calls the correct version of abs() based upon the type of data used as an argument.

