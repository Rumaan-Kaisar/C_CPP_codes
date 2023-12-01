
// ----     rev    ----

/* ----------------------     Function overloading (intro)     ----------------------


Function overloading:
    In C++ function overloading is one type of POLYMORPHISM (compile-time polymorphism). 
        When two or more functions share the same name, they are said to be overloaded.

    In C++, two or more functions can share the 'same name' as long as either:
        the "TYPE of their arguments" differs or 
        the "number of their arguments" differs
        or both
    
    

    
	Overloaded functions can help reduce the complexity of a program by allowing related operations to be referred to by the same name.
	It is very easy to overload a function: simply declare and define all required versions. The compiler will automatically select the correct version based upon the number and/or type of the arguments used to call the function.
	It is also possible in C++ to overload operators. 
	The return type alone is not a sufficient difference to allow function overloading. If two functions differ only in the type of data they return, the compiler will not always be able to select the proper one to call. For example, this fragment is incorrect because it is inherently ambiguous. 		int f1(int a);
double f1( int a);
. . . . . 
f1(10) ; 	/* which function does the compiler call ???*/ 
As the comment indicates, the compiler has no way of knowing which version of f1() to call.
*/


/* Example 1: Example of 'Function overloading'.
                The C standard library contains the functions abs(), labs(), and fabs(), 
                    which return the absolute value of an integer, a long integer, and a floating-point value, respectively. 
                    
                    In C++, you can 'overload one name' for the three types of data, as this example illustrates: 
*/

#include <iostream>
// using namespace std;

// Overloading three abs() functions with different types 
int abs(int n);
long abs(long n);
double abs(double n);

int main(){ 
    std::cout<<"Absolute of -10 : "<<abs(-10)<<"\n";
    std::cout<<"Absolute of -10L : "<<abs(-10L)<<"\n";
    std::cout<<"Absolute of -10.01 : "<<abs(-10.01)<<"\n";
}

// abs() for ints
int abs(int n){ 
    cout<< "\n In integer abs() = ";
    return n<0 ? -n : n;
}

// abs() for longs
long abs(long n){
    cout<< "\n In long abs() = ";
    return n<0 ? -n : n;
}

// abs() for doubles
double abs(double n){
    cout<< "\n In double abs() = ";
    return n<0 ? -n : n;
}

