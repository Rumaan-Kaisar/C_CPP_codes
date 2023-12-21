// ----  SKILLS CHECK  ----

/* Example 1: Give brief descriptions of polymorphism, encapsulation, and inheritance. 

                "Polymorphism" is the mechanism by which one general interface can be used 
                    to access many specific implementations. 

                "Encapsulation" provides a 'protected linkage' between code and its related data. 
                    Access to encapsulated routines can be tightly controlled, 
                    thus preventing unwanted tampering. 

                "Inheritance" is the process by which one object can acquire the traits (properties) of another. 
                    Inheritance is used to support a system of hierarchical classification.
*/




/* Example 3: Write a program that uses 'C++ style I/O' to input two integers from the keyboard and
                then displays the result of raising the first to the power of the second. 
                (For example, if the user enters 2 and 4, the result is (2^4), or 16.) */

#include <iostream>
// using namespace std;

int main(){
    int b, e, result;

    std::cout << " Enter base : ";
    std::cin >> b;
    std::cout << " Enter exponent : ";
    std::cin >> e;

    r = 1;
    for( ; e; e --) result = result * b;

    cout << " Result : " << result;

    return 0;
}




/* Example 4: Create a function called rev_str() that reverses a string. 
                Overload rev_str() so it can be called with either one character array or two. 
                    When it is called with 'one string', have that one string contain the reversal. 
                    When it is called with 'two strings', return the reversed string in the second argument. 

                For example:

                    char s1[80], s2[80];
                    strcpy(s1 , " hello ");
                    rev_str(s1 , s2);   // reversed string goes in s2 , s1 untouched
                    rev_str(s1);    // reversed string is returned in s1
*/
#include <iostream>
#include <cstring>
// using namespace std;

// Overload string reversal function .
void rev_str(char *s); // reverse string in place
void rev_str(char *in , char *out ); // put reversal into out


int main(){
    char s1[80] , s2[80];

    strcpy(s1 , " This is a test ");    
    rev_str(s1 , s2);
    std::cout << s2 << "\n";

    rev_str(s1);
    std::cout << s1 << "\n";
    
    return 0;
}


// Reverse string , put result in s.
void rev_str(char *s){
    char temp[80];
    int i, j;

    // reversing
    for(i= strlen(s)-1, j=0;    i>=0;   i--, j++) temp[j] = s[i];
    temp[j] = '\0'; // null - terminate result

    strcpy(s, temp);
}


// Reverse string, put result into out .
void rev_str(char *in, char *out){
    inti, j;
    
    for(i=strlen(in)-1, j=0;    i>=0;   i--,j++) out[j] = in[i];
    out[j] = '\0' ; // null - terminate result
}





/* Example 5: Given the following new-style C++ program, show how to change it into its old-style form. */
#include <iostream>
// using namespace std;

int f(int r);

int main(){
    std::cout << f(10);

    return 0;
}

int f(int r){
    return 2*3.1416*r;
}



// old style
#include <iostream.h>

int f(int a);

int main(){
    std::cout << f (10) ;

    return 0;
}

int f(int a){
    return a*3.1416;
}




/* Example 6: What is the bool data type? 
                The bool data type stores Boolean values. 
                The only values an object of type bool can have are true and false.
*/




/* Example 1: Write a program that uses C++ style I/O to prompt the user 
                for a string and then display its length. 
*/
#include <iostream>
#include <cstring>
// sing namespace std;

int main(){
    char s[80];

    std::cout << " Enter a string : ";
    std::cin >> s;
    std::cout << " Length : " << strlen (s) << "\n";

    return 0;
}




/* Example 3: Create an overloaded rotate() function that 'left-rotates the bits' in its argument and returns the result. 
                Overload it so it accepts 'ints' and 'longs'. 
                (A rotate is similar to a 'shift' except that the bit shifted off one end is shifted onto the other end.)

                In C "OCTAL" is started with '0', '0123' is equivalent to "83"
                Hexadecimal is started with '0x', '0x123' is equivalent to "291"
*/
#include <iostream >
// using namespace std;

int rotate(int i);
long rotate(long i);

int main(){
    int a;
    long b;

    a = 0123
    std::cout << a;

    a = 0x123
    std::cout << a;

    a = 0x8000 ;
    b = 8;
    std::cout << rotate (a);
    std::cout << "\n";
    std::cout << rotate (b);

    return 0;
}


int rotate (int i){
    int x;

    if(i & 0x8000) x = 1;   // bitwise AND
    else x = 0;

    i = i << 1; // using bitwise-shift operator
    i += x;
    return i;
}


long rotate(long i){
    int x;

    if(i & 0x80000000) x = 1;// bitwise AND
    i = i << 1; // using bitwise-shift operator
    i += x;
    return 0;
}




