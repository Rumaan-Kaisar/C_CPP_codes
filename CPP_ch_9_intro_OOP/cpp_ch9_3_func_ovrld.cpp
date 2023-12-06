
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

int main(){
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




/* Example 3: So far, you have seen overloaded functions that differ in the "DATA TYPES" of their arguments.
                However, overloaded functions can also differ in the "NUMBER OF ARGUMENTS" */

#include <iostream>
// using namespace std;

void f1(int a);
void f1(int a, int b);

int main(){
    f1(10);
    f1(10 , 20);

    return 0;
}

// notice the number of arguments
void f1(int a){
    std::cout << "In f1( int a)\n";
}

void f1(int a, int b){
    std::cout << "In f1( int a, int b)\n";
}




/* Example 4: It is important to understand that the return type alone is not a sufficient difference to allow function overloading. 
                If two functions differ only in the type of data they return,   the compiler will not always be able to select the proper one to call. 
                For example, this fragment is incorrect because it is inherently ambiguous. */

// This is incorrect and will not compile .
int f1( int a);
double f1( int a);
. . .
f1 (10) ; // which function does the compiler call ???
// As the comment indicates, the compiler has no way of knowing which version of f1() to call.




/* Example 5: Create a function called sroot() that returns the square root of its argument. 
                Overload sroot() three ways: 
                    have it return the square root of 
                        an integer, 
                        a long integer, and 
                        a double. 
                
                To actually compute the square root, you can use the standard library function sqrt()
*/
#include <iostream>
#include <cmath>

// using namespace std ;

// Overload sroot() for integers , longs , and doubles
    // NOTICE: return-type and argument-type both differs
int sroot(int i);
long sroot(long i);
double sroot(double i);

int main(){
    std::cout << " Square root of 90.34 is : " << sroot(90.34);
    std::cout << "\n";
    std::cout << " Square root of 90L is : " << sroot(90L);
    std::cout << "\n";
    std::cout << " Square root of 90 is : " << sroot(90);
    std::cout << "\n";

    return 0;
}


// Return square root of integer.
int sroot(int i){
    std::cout << " computing integer root \n";
    return (int) sqrt((double)i);
}

// Return square root of long.
long sroot(long i){
    std::cout << " computing long root \n";
    return (long) sqrt((double)i);
}

// Return square root of double.
double sroot(double i){
    std::cout << " computing double root \n";
    return sqrt(i);
}
// Notice sqrt() always use 'double' type hence we used type-cast




/* Example 6: The C++ standard library contains these three functions: 
 
                        double atof ( const char *s);   // atof() returns a double, 
                        int atoi ( const char *s);      // atoi() returns an integer, and 
                        long atol ( const char *s);     // atol() returns a long.
                
                These functions return the numeric value contained in the string pointed to by 's'. 
                
                Why is it NOT POSSIBLE to "overload" these functions? 
*/
The functions atof(), atoi(), atol() cannot be overloaded because 
    they differ only in the "type of data they return". 
    Function overloading requires that either the type or the number of arguments differs.




/* Example 3: Create a function called min() that returns the smaller of the two numeric arguments used to call the function. 
                Overload min() so it accepts char, int, and double as arguments.
*/

// Overload the min () function.
#include <iostream>
#include <cctype>

// using namespace std;

char min(char a, char b);
int min(int a, int b);
double min(double a, double b);

int main(){
    std::cout << " Min is: " << min('x', 'a') << "\n";
    std::cout << " Min is: " << min(10 , 20) << "\n";
    std::cout << " Min is: " << min(0.2234 , 99.2) << "\n";

    return 0;
}

// min () for chars
char min(char a, char b){
    return tolower(a)<tolower(b) ? a : b;
}

// min () for ints
int min(int a, int b){
    return a<b ? a : b;
}

// min () for doubles
double min(double a, double b){
    return a<b ? a : b;
}




/* Example 4: Create a function called sleep() that "PAUSES THE COMPUTER" for the number of seconds specified by its single argument.
                Overload sleep() so it can be called with either an int or a 'string representation of an integer'. 
                
                For example, both of these calls to sleep() will cause the computer to pause for 10 seconds:

                        sleep (10) ;
                        sleep ("10");
                
                Demonstrate that your functions work by including them in a short program. 
                (Feel free to use a DELAY LOOP to pause the computer. 
*/

#include <iostream>
#include <cstdlib>

// using namespace std;

// Overload sleep to accept integer or char * argument
void sleep(int n);
void sleep(char *n);    // uses string 

// Change this value to fit your processor speed .
#define DELAY 100000

int main(){
    std::cout << ".";
    sleep(30000);   // as int
    std::cout << ".";
    sleep("50000"); // as string
    std::cout << ".";

    return 0;
}


// sleep() with integer argument .
void sleep(int n){
    long i;

    for( ; n; n--){
        for(i=0; i<DELAY; i++);
    }
    std::cout << "\ndone! int.";
}


// sleep() with char * argument .
void sleep(char *n){
    long i;
    int j;

    j = atoi(n); // char or str to int
    for ( ; j; j--){
        for(i=0; i<DELAY; i++);
    }
    std::cout << "\nChar done!.";
}



