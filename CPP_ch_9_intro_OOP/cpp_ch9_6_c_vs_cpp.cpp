
/* 
    ----------------------     C vs C++     ----------------------
    Foollowing are some difference between C and C++:
	
    'Void' is not essential for empty parameter: 
        In C, when a function takes 'no parameters', its prototype has the word 'void' inside its function parameter list. 
            e.g., in C, if a function called f1() takes no parameters (and returns a char), its prototype will look like: 	
                char f1(void);

        However, in C++, the void is 'optional'. Therefore, in C++, the prototype for f1() is usually written like:
                char f1();
	
        In a C program, it is common practice to declare main() as shown here if it takes no command-line arguments:
                int main(void)
          
        However, in C++, the use of void is redundant and unnecessary and we'll use :    
                int main()
	



    empty-param-list vs void in C & C++:
        In a C program, 'char f1();' simply mean that 'nothing is said about the parameters' to the function and
            'char f1(void);' means that the function takes "no parameters".
	
        In C++, 'char f1(void);' means that the function has "no parameters".  In C++, these two declarations are EQUIVALENT: 
                char f1();  EQIVALENT   char f1(void);
	
    
    

    Prototype is essential: 
        In a C++ program, all functions 'must be prototyped'. C++ programs will not compile if the function is not prototyped. 
        [Remember, in C, prototypes are recommended but technically optional.]
	
        A member function's prototype contained in a 'class' (discussed in next chapter) 
            that prototype also serves as its 'general prototype', and no other separate prototype is required.




	returning values are essential :  
        In C++, if a function is 'DECLARED as returning a value', it must return a value. 
            We must explicitly declare the return type of all functions.
	
        In C, a 'non-void function' is not required to actually return a value. If it doesn't, a garbage value is "returned". 
            In C, if you don't EXPLICITLY specify the 'return type' of a function, an integer return type is assumed. 




	Local variable anywhere: 
        In C++, 'local variables' can be declared 'ANYWHERE'. 
            so local variables can be declared 'close' to where they are 'first used', 
            thus helping to prevent unwanted side effects.
	
        In C, local variables can declared only 'at the start of a BLOCK', prior to any "action" statements.
	



    New "bool" data-type: 
        C++ defines the bool data type, which is used to store Boolean (i.e., true/false) values. 
            Hence C++ also defines the keywords 'true' and 'false', which are the only values that a value of 'type bool' can have. 
	
        In C++, the outcome of the 'RELATIONAL' and 'LOGICAL' operators is a value of "type bool", 
            and all 'CONDITIONAL statements' must evaluate to a "bool" value. 
	
        In C, 'true' is any 'nonzero value' and 'false' is 0. 
            This still holds in C++ because 'any nonzero value' is automatically converted into "false" when used in a BOOLEAN EXPRESSION. 
            The reverse also occurs: 'true' is converted to "1" and 'false' is converted to "0" when a 'bool value' is used in an INTEGER EXPRESSION. 



    ------------    A Few More Differences Between C and C++    ------------

    char to int elivation:
        In C, a char constant is automatically elevated to an int, whereas in C++, it is not.

    upgrade on register variable:
        In C, you cannot take the address of a register variable. In C++, you can.

    In C, it is not an error to declare a 'global variable' several times. In C++, this is an error.

    In C, an identifier will have at least '31 significant characters'. In C++, all characters are considered significant. 
        However,extremely long identifiers are unwieldy and are seldom needed.

    In C, you can call main() from within a program, although this would be unusual. In C++, this is not allowed.

    In C, the type wchar_t is defined with a typedef. In C++, wchar_t is a keyword.

*/




/* Example 1: In a C program, it is common practice to declare main() as shown here if it takes no command-line arguments:
                                int main(void)
                However, in C++, the use of void is redundant and unnecessary. We normally use 'int main()' 
*/




/* Example 2: Following short C++ program will not compile because the function sum() is not PROTOTYPED.
                also notice no 'return type' is declared 
*/
// This program will not compile
#include <iostream>
// using namespace std;
// int sum(int a, int b);

int main(){
    int a, b, c;
    
    std::cout << " Enter two numbers : ";
    std::cin >> a >> b;
    
    c = sum (a, b);
    std::cout << " Sum is: " << c;
    
    return 0;
}

// This function needs a prototype
sum (int a, int b){
    return a+b;
}


// ----  Correct version  ----
#include <iostream>
// using namespace std;
int sum(int a, int b);

int main(){
    int a, b, c;
    
    std::cout << " Enter two numbers : ";
    std::cin >> a >> b;
    
    c = sum (a, b);
    std::cout << " Sum is: " << c;
    
    return 0;
}

// This function needs a prototype
int sum (int a, int b){
    return a+b;
}




/* Example 3: Here is a short program that illustrates how local variables can be declared anywhere within a block. 

                The declaration of 'j' and 'fact' near the point of first use is of little value in this short example; 
                    however, in large functions, the ability to declare variables close to the point of 
                    their first use can help 'clarify your code' and prevent unintentional side effects.
*/
#include <iostream>
// using namespace std;

int main(){
    int i; // local var declared at start of block

    std::cout << " Enter number : ";
    std::cin >> i;

    // compute factorial
    int j, fact =1;     // vars declared after action statement
    for(j=i; j >=1; j--) fact = fact * j;
    std::cout << " Factorial is " << fact;

    return 0;
}




/* Example 4: The following program creates a Boolean variable called 'outcome' and 
                assigns it the value 'false'. It then uses this variable in an if statement. 

                The program displays 'false'.
*/
#include <iostream>
// using namespace std;

int main(){
    bool outcome;

    outcome = false;
    if(outcome) 
        std::cout << " true ";
    else 
        std::cout << " false ";

    return 0;
}




/* Example 5: The following program will not compile as a C++ program. Why not? 
                Because the function 'f()' is not prototyped */

// This program has an error .
#include <iostream>
// using namespace std ;
// void f();    // prtotype

int main(){
    f();

    return 0;
}

void f(){
    std::cout << " this won ’t work ";
}




/* Example 6: What is the bool data type? 
                The bool data type stores Boolean values. 
                The only values an object of type bool can have are true and false.
*/


