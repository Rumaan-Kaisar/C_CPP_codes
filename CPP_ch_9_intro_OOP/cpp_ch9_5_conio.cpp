
/* ----------------------     conIO in C++     ----------------------
    
    I/O functions:
        We may still use functions such as 
                printf() and 
                scanf() 
            these are I/O functions. 



    I/O operators:
        In C++, I/O is performed using I/O operators instead of I/O functions. 
        In order to use the C++ I/O operators, you must include the header <iostream> in your program.



    Output:
        The output operator is << .  It is possible to output "more than one value" in a single I/O expression
        In general, to output to the console, use this form of the << operator:

                cout << expression ;

            'expression' can be any valid C++ expression-including 'another output expression'. 
            'cout' is a PREDEFINED STREAM that is automatically linked to the 'console' when a C++ program begins execution. 
                It is similar to C's stdout. 

            By using the << output operator, it is possible to output any of C++'s basic types. 
            
            For example, following statement outputs the value 100.99:			
                
                cout << 100.99;
                cout << " This string is output to the screen .\n";



    Input:
        To input a value from the keyboard, use the >> input operator. 
        In general, to input values from the keyboard, use following form of >> :

                cin >> variable ;

            For example,       
                
                int num; 
                cin >> num;    // inputs an integer value into num.  
                
            Notice that num is not preceded by an '&'. 
                When you use C's scanf() function to input values, variables must have their ADDRESSES passed to the function 
                    so they can receive the values entered by the user. 
                    This is not the case when you are using 'C++'s INPUT OPERATOR'.
        
        You can input as many items as you like in one input statement.
            As in C, individual data items must be separated by WHITESPACE CHARACTERS (spaces, tabls, or newlines).
            When a string is read, input will stop when the first whitespace character is encountered.


    Note:
        [1]	As you know, in C, these are the left and right shift operators, respectively. 
            In C++, they still retain their original meanings (left shift and right shift) 
            but they also take on the 'expanded role' of performing INPUT and OUTPUT.

        [2]	As in C, C++ console I/O may be redirected, but for the rest of this discussion, it is assumed that the console is being used.



    using std:: instead of 'using namespace std'
        it makes more readable code, it's more specific about which function is coming from which header/module
*/




/* Example 1: This program outputs 
                a string, 
                two integer values, and 
                a double floating-point value. */
#include <iostream>
// using namespace std;

int main(){
    int i, j;
    double d;

    i = 10;
    j = 20;
    d = 99.101;

    std::cout << " Here are some values : ";
    std::cout << i;  // int
    std::cout << ' ';
    std::cout << j;  // int
    std::cout << ' ';
    std::cout << d;  // float

    return 0;
}




/* Example 2: It is possible to output "more than one value" in a single I/O expression. 
                For example, this version of the program described in Example 1 shows 
                a more efficient way to code the I/O statements: 
                
                    std::cout << i << ' ' << j <<  ' ' << d; 
    
                outputs several items in one expression. 

                In general, you can use a single statement to output "AS MANY ITEMS AS YOU LIKE". 
                Simply remember that the '>>' output operator behaves like 'any other C++ OPERATOR' and 
                    can be part of an arbitrarily long expression.

                Notice, you must 'explicitly include spaces' between items when needed. 
                    otherwise, the data will run together when displayed on the screen. 
*/
#include <iostream>
// using namespace std ;

int main(){
    int i, j;
    double d;

    i = 10;
    j = 20;
    d = 99.101;

    std::cout << " Here are some values : ";
    std::cout << i << ' ' << j <<  ' ' << d;

    return 0;
}




/* Example 3: This program prompts the user for an integer value: 
                As you can see, the value entered by the user is put into i, no '&' location needed. */
#include <iostream>
// using namespace std;

int main(){
    int i;

    std::cout << " Enter a value : ";
    std::cin >> i;

    std::cout << " Here is your number : " << i << "\n";
    
    return 0;
}




/* Example 4: Multiple inputs in one input statement. This program prompts the user for 
                    an integer value, 
                    a floating-point value, and 
                    a string. 
                
                It then uses 'one input statement' to read all three. 

    Note: individual data items must be separated by whitespace characters (spaces, tabls, or newlines)
*/
#include <iostream>
// using namespace std ;

int main(){
    int i;
    float f;
    char s[80];

    std::cout << " Enter an integer , float , and string : ";
    std::cin >> i >> f >> s;

    std::cout << " Here's your data : ";
    std::cout << i << ' ' << f << ' ' << s;

    return 0;
}

/* You can input as many items as you like in one input statement.

    As in C, individual data items must be separated by whitespace characters (spaces, tabls, or newlines).
        When a string is read, input will stop when the first whitespace character is encountered.

        For example, if you enter the following into the preceding program
            
                10 100.12 This is a test

        the program will display this:
            
                10 100.12 This

        The string is incomplete because the reading of the string stopped with the 'space' after   'This'. 
            The remainder of the string is left in the "INPUT BUFFER", awaiting a subsequent input operation. 
            (This is similar to inputting a string by using scanf() with the '%s' format.) 
*/




// --------    rev    --------

// Buffering

/* Example 5: By default, when you use >>, all input is line buffered. This means that no information
                is passed to your C++ program until you press ENTER. (In C, the scanf() function is line
                buffered, so this style of input should not be new to you.) To see the effect of line-buffered
                input, try this program: */

#include <iostream>
// using namespace std;

int main(){
    char ch;

    cout << "Enter keys , x to stop .\n";
do
{
cout << ": ";
cin >> ch;
}
while (ch != ’x’);
return 0;
}




When you test this program, you will have to press ENTER after each key you type in order
for the corresponding character to be sent to the program.




Example 6. Write a program that inputs the number of hours that an employee works and the employee’s wage. Then display the employee’s gross pay. (Be sure to prompt for input.)


Example 7. Write a program that converts feet to inches. Prompt the user for feet and display the
equivalent number of inches. Have your program repeat this process until the user enters
0 for the number of feet.


Example 8. Here is a C program. Rewrite it so it uses C++-style I/O statements.
# include <stdio .h>
int main ( void )
{
int a, b, d, min ;
printf (" Enter two numbers : ");
scanf ("%d%d", &a, &b);
min = a > b ? b : a;
for (d = 2; d< min ; d++)
if ((( a%d) ==0) && ((b%d) ==0) )
break ;
if(d== min )
{
printf ("No common denominators \n");
return 0;
}
printf (" The lowest common denominator is %d\n", d);
return 0;
}








