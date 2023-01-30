
#include<iostream>
using namespace std;

int main()
{
    int num; // declares num to be an integer variable
    char ch;
    float f;
    double d;

    num=100;
    ch='x';  /*Charecter inside the single quote*/
    f=100.123;
    d=123.009;
    
    cout<<"the value is "<< num;
    cout<<"ch is "<< ch;
    cout<<"f is "<< f;
    cout<<"d is "<< d;

/* Note: The overall syntax of the two languages is very similar. 
    The operators and keywords used in C are also used in C++ to achieve the same things. 
    But C++ has more keywords than C, and it has an extended grammar. */

    printf("\n the value is %d", num);
    printf("ch is %c", ch);
    printf("f is %f", f);
    printf("d is %f", d);
    return 0;

    /*  
        https://www.geeksforgeeks.org/cpp-printf-function/   
        C++ printf() Function
        "printf()" function is originally declared under the "<cstdio>" header file. It prints the "formatted string" to the standard output "stdout".

        Syntax: 
        int printf(const char*word, .......)
     */
}
