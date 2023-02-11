
/* 
    Operator        Meaning

    +               addition
    -               subtraction
    *               multiplication
    /               division
    %               modulus
 */

/* 

#include <cstdio>
int main() {
    int num;
    float f, k, sum;
    double g;
    
    // Input specifier for Integers
    // printf("Enter an integer:");
    // scanf("%d", &num);

    // Input specifier for float
    printf("Enter two floating point numbers: ");
    scanf ("%f", &f);
    scanf ("%f", &k);

    sum = f+k;
    printf("sum: %f\n", sum);

    printf ("Devision 5/2: %d\n", 5/2);
    printf("Multiplication 5*2: %d\n" , 5*2);
    printf("subtraction 4-2: %d\n" , 4-2);
    printf("Modulo 4%2: %d\n" , 4%2);

    // Note: Mixing with float & int type data cause severe problem

    return 0;    
}
 */


#include<iostream>

// using namespace std;

int main()
{
    int a=10, b=5;

    std::cout << a + b <<std::endl; //Addition
    std::cout << a - b <<std::endl; //Subtraction
    std::cout << a / b <<std::endl; //Division
    std::cout << a * b <<std::endl; //Multiplication

    std::cout << a % b <<std::endl; //Modulo -> Remainder

    std::cout << ++a <<std::endl; //Pre-Increment
    std::cout << --a <<std::endl; //Pre-decrement
    std::cout << a++ <<std::endl; //Post-Increment
    std::cout << a-- <<std::endl; //Post-decrement

}
