
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

        It is left to the compiler to choose the appropriate specific version of the function (that is, the method) to call

        One of the main uses for function overloading is to achieve "COMPILE-TIME POLYMORPHISM",
            which embodies the philosophy of "one interface, many method"s. 

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
                        a single name can be used to describe a general class of action, the artificial
                        complexity cause by three slightly different names is eliminated
                    
                However, abs() is already defined in C++, that's why abs(-10) will invoke the library abs() function, not ours, 
                    and won't print "Absolute of -10 : In integer abs() = 10"
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




/* Example 2: Here is another example of function overloading. In this case, the function date() is
                overloaded to accept the date either as a 'string' or as "three integers". 
                In both cases, the function displays the data passed to it. */
#include <iostream >
// using namespace std;

void date(char *date);  // date as a string
void date(int month, int day, int year ); // date as numbers

int main() {
    date(" 8/23/99 ");
    date(8, 23, 99);

    return 0;
}

// Date as string .
void date(char *date){
    std::cout << " Date : " << date << "\n";
}

// Date as integers.
void date(int month, int day, int year){
    std::cout << " Date : " << month << "/";
    std::cout << day << "/" << year << "\n";
}





// -------------   rev   -------------

/* Example 3: So far, you have seen overloaded functions that differ in the data types of their arguments.
                However, overloaded functions can also differ in the number of arguments, as this example illustrates */

# include <iostream >
using namespace std ;
void f1( int a);
void f1( int a, int b);
int main ()
{
f1 (10) ;
f1 (10 , 20) ;
return 0;
}
void f1( int a)
{
cout << "In f1( int a)\n";
}
void f1( int a, int b)
{
cout << "In f1( int a, int b)\n";
}


/* Example 4: It is important to understand that the return type alone is not a sufficient difference to
                allow function overloading. If two functions differ only in the type of data they return,
                the compiler will not always be able to select the proper one to call. For example, this
                fragment is incorrect because it is inherently ambiguous. */

// This is incorrect and will not compile .
int f1( int a);
double f1( int a);
. . .
f1 (10) ; // which function does the compiler call ???
As the comment indicates, the compiler has o way of knowing which version of f1() to
call.



EXERCISES
/* Example 1: Create a function called sroot() that returns the square root of its argument. Overload
                sroot() three ways: have it return the square root of an integer, a long integer, and a
                double. (To actually compute the square root, you can use the standard library function
                sqrt().) */


/* Example 2: The C++ standard library contains these three functions: 
                double atof ( const char *s);
                int atoi ( const char *s);
                long atol ( const char *s);
                These functions return the numeric value contained in the string pointed to by s. Specifically, atof() returns a double, atoi() returns an integer, and atol() returns a long.
                Why is it not possible to overload these functions? */


/* Example 3: Create a function called min() that returns the smaller of the two numeric arguments
                used to call the function. Overload min() so it accepts characters, integers, and doubles
                as arguments. */


/* Example 4: Create a function called sleep() that pauses the computer for the number of seconds
                specified by its single argument. Overload sleep() so it can be called with either an
                integer or a string representation of an integer. For example, both of these calls to sleep()
                will cause the computer to pause for 10 seconds:
                sleep (10) ;
                sleep ("10");
                Demonstrate that your functions work by including them in a short program. (Feel free
                to use a delay loop to pause the computer. */
