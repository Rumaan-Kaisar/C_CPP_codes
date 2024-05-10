
/*  ----------------    AUTOMATIC IN-LINING    ----------------

    If a member function's definition is 'short enough', 
        the DEFINITION can be included inside the "class declaration". 
        Then the function autometically become an "in-line function", if possible. 

    When a function is defined "within a class declaration", the 'inline' keyword is no longer necessary. 
        if any 'in-line restriction' is violated, the compiler is free to generate a normal function.
    
    For example, the  divisible()  is automatically in-lined as shown here:


            class samp {	
                    int i, j;
                public:
                    samp(int a, int b);
                    int divisible(){ return !(i%j); }   // divisible() is defined inside class-declaration and automatically 'in-lined'.
            };

            samp::samp(int a, int b) {
                i = a;
                j = b; 
            }


        Notice, the code associated with divisible() occurs inside the declaration for the class 'samp'. 
            Further notice that no other definition of divisible() is 'needed-or permitted'.

        Notice how divisible()  occurs all on one line. 
            This format is very common in C++ programs when a function is declared within a class declaration. 
            It allows the declaration to be more compact. 

*/




/* Example 1: The divisible() "Member-functions" of classes from the preceding section "ch10_05_1_inLine_func.cpp" Example 2, 
                can be AUTOMATICALLY in-lined as shown here: */

#include <iostream>

class samp{
        int i, j;
    public:
        samp(int a, int b); // defined outside, couled be in-lined, if defined here. It's common for constuctors
        // divisible() is defined here instead of declaring and it'll automatically in-lined.
        int divisible(){ return !(i%j);}
};

samp::samp(int a, int b){
    i = a;
    j = b;
}


int main(){
    samp ob1(10 , 2), ob2(10, 3);

    // this is true
    if(ob1.divisible()) std::cout << "10 divisible by 2\n";
    // this is false
    if(ob2.divisible()) std::cout << "10 divisible by 3\n";
    return 0;
}

/*  Notice the code associated with divisible() occurs inside the declaration for the class 'samp'. 
        Further notice that no other definition of divisible() is "needed-or permitted". 
        DEFINING divisible() inside 'samp' made it in-line function automatically.

        When a function defined inside a class declaration cannot be made 
            into an in-line function (because a restriction has been violated), 
            it is automatically made into a 'regular function'.
        
        The same restrictions that apply to "normal in-line functions" apply to 
            'automatic in-line functions' within a class declaration

    Notice how divisible() is defined within samp, all on one line. 
        This format is very common in C++ programs when a function is declared within a class declaration. 
        It allows the declaration to be more compact. 
        
        However, the samp class could have been written like this:

                class samp{
                        int i, j;
                    public:
                        samp(int a, int b);
                        int divisible(){
                            return !(i%j);
                        }
                };

    In this version, the layout of divisible() uses the more-or-less standard indentation style. 
    for the compiler, there is no difference with compact style.

    between the compact style is commonly found
    in C++ programs when short functions are defined inside a class definition.
*/




/* Example 2: Most common use of in-line functions defined within a class is to define:
                        Constructor and 
                        Destructor functions. 

                For example the 'sampclass' can more efficiently be defined like below: 
*/
# include <iostream>

class samp{
        int i, j;
    public:
        // inline constructor
        samp(int a, int b) { i = a; j = b; }
        int divisible(){ return !(i%j); }
};

// The definition of samp() within the CLASS 'samp' is sufficient, and no other definition of samp() is needed.




/* Example 3: Sometimes a short function will be included in a class declaration 
                even though the automatic in-lining feature is of "little or no value". 
                Consider following class declaration: */
class myclass{
        int i;
    public:
        myclass(int n){ i = n; }
        void show(){ std::cout << i; }
};

/*  Here the function show() is made into an in-line function automatically. 
    However, as you should know, I/O operations are (generally) so slow relative to CPU/memory operations 
        that any effect of eliminating the 'function call overhead' is essentially lost. 
        
    Even so, in C++ programs, it is still common to see small functions of this type 
        declared within a class simply for the sake of convenience, and because no harm is caused.
*/




/* Example 4: Convert the stack class from "ch10_01_2_constructor_destructor.cpp", Example 3, 
                so that it uses 'automatic in-line' functions where appropriate. 

                It uses 'non-parameterized constructor'.

                'stack class' is used to store characters.
*/

#include <iostream>

#define SIZE 10

// Declare a stack class for characters. 
// Instead of just DECLARING, all member functions are DEFINED inside the class to make them in-line
class stack {
        char stck[ SIZE];   // holds the stack
        int tos;            // index of top of stack
    
    // Notice all following functions are now DEFINED inside the class
    public:
        stack(){ tos = 0; } // Initialize the stack.

        void push(char ch) {    // push character on stack
            if(tos == SIZE) {   
                std::cout << " Stack is full \n";
                return;
            }
            stck[tos] = ch;
            tos++;
        }

        char pop(){     // pop character from stack
            if(tos == 0){
                std::cout << " Stack is empty \n";
                return 0; // return null on empty stack
            }
            tos--;
            return stck[tos];
        };
};


// -=-=-  main function  -=-=-
int main(){
    stack s1, s2; // create two stacks that are automatically initialized.
    int i;

    s1.push('a');
    s2.push('x');
    s1.push('b');
    s2.push('y');
    s1.push('c');
    s2.push('z');

    for(i =0; i<3; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i =0; i<3; i ++) std::cout << " Pop s2: " << s2.pop() << "\n";

    return 0;
}


/* 
    Notice, 'the initialization task is performed automatically' by the constructor function 
        rather than by a separate function that must be explicitly called by the program.

    Constructor function makes sure that the inilialization is performed.
    The programmer, don’t need to worry about initialization-it is performed automatically when the object is brought into existence.
*/




/* Example 5: Convert the "strtype" class from "ch10_01_3_constructor_param.cpp", Example 4, 
                so that it uses automatic in-line functions.

                It uses "parameterized constructor". 

                'strtype class'creates a simple string class, called 'strtype', that contains a 'string and its length'. 

                When a 'strtype' object is created, 
                    'memory' is allocated to hold the string and its initial length is set to 0. 

                When strtype object is destroyed, that memory is released. 
                
                The program uses malloc and free() to allocate and free memory. While this is perfectly valid.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
        int len;
    public:
        // constructor: Initialize a string object with parameter.
        strtype(char * ptr){
            len = strlen(ptr);  // get len of the string
            // allocate using string's length 'len' instead of fixed 'SIZE'
            p = (char *)malloc(len +1);    // malloc() returns a POINTER. Extra 1 is for 'end-of-line' character
            // Why type cast : To make conversion from ‘void *’ to ‘char *’, C++ data type differs from C
            if(!p){ // Error massage
                std::cout << " Allocation error \n";
                exit(1) ;
            }
            strcpy(p, ptr); // copy string to p
        }

        // destructor: Free memory when destroying string object .
        ~strtype(){
            std::cout << " Freeing p\n";
            free(p);
        }

        void show(){
            std::cout << p << " - length : " << len ;
            std::cout << "\n";
        }
};

// In this version of strtype, a string is given an initial value using the constructor function.
int main(){
    // initialize with string, as parameters
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();

    return 0;
}




// --------    Auto in-line for "DERIVED class"    --------

/* Example 6: Given the following base class,

                    class area_cl{
                        public:
                            double height;
                            double width;
                    };

                Create two derived classes called 'rectangle' and 'isosceles' that inherit "area_cl". 
                Have each class include a function called area() 
                    that returns the area of a rectangle or isosceles triangle, as appropriate. 
                
                Add another derived class that inherits 'area_cl' from 'ch10_02_inheritance_intro.cpp', Example 4. 
                    Call this class 'cylinder' and have it compute the surface area of a cylinder. 
                    Hint: The surface area of a cylinder is: (2∗π∗R**2 + π∗D∗height).

                Use parameterized constructors to initialize height and width
                Use 'in-line functions' to implement member functions and constructors
*/

#include <iostream>

class area_c1{
    public:
        double height;
        double width;
};

// derived classes. Notice the in-line functions 
class rectangle:public area_c1{
    public:
        rectangle(double h, double w){height = h; width = w;}
        double area() { return width*height; }
};

class isosceles:public area_c1{
    public:
        isosceles(double h, double w){height = h; width = w;}
        double area(){ return 0.5*width*height; }
};

class cylinder:public area_c1{
    public:
        cylinder(double h, double w){height = h; width = w;}
        double area(){ return (2*3.1416*(width/2)*( width /2)) + (3.1416*width*height); }
};

// no implementation of member functions, we've already have in-lined functions


int main() {
    rectangle b(10.0, 5.0);
    isosceles i(4.0, 6.0);
    cylinder c(3.0, 4.0);

    std::cout << " Rectangle : " << b.area() << "\n";
    std::cout << " Triangle : " << i.area() << "\n";
    std::cout << " Cylinder : " << c.area() << "\n";

    return 0;
}




/* Example 7: Modify the following program so that all member functions are automatically in-lined: */
#include <iostream>

using namespace std;

class myclass{
        int i, j;
    public:
        myclass(int x, int y);
        void show();
};

myclass::myclass(int x, int y){
    i = x;
    j = y;
}

void myclass::show(){
    cout << i << " " << j << "\n";
}

int main(){
    myclass count(2, 3);
    count.show();
    return 0;
}


// Modified  program using in-lined functions
#include <iostream>

class myclass{
        int i, j;
    public:
        myclass(int x, int y){ i = x; j = y; }
        void show(){ std::cout << i << " " << j; }
};

int main(){
    myclass count(2, 3);
    count.show();
    return 0;
}




/* Example 8: Create a class called 'prompt'. Pass its constructor function a prompting string of your own choosing. 
                Have the constructor display the string and then input an integer. 
                Store this value in a private variable called 'count'. 

                When an object of type prompt is destroyed, 
                    ring the bell on the terminal as many times as the user entered. 
*/

#include <iostream>

class prompt{
        int count;
    public:
        prompt (char *s) { std::cout << s; std::cin >> count; }
        ~prompt();
};

prompt::~prompt(){
    int i, j;
    for(i =0; i<count; i ++){
        std::cout << '\a';
        for(j =0; j<32000; j++); // delay
    }
}

int main(){
    prompt ob(" Enter a number : ");
    return 0;
}




/* Example 9: There are two ways to cause a function to be expanded 'in-line'. What are they? 
                1. use 'inline' keyword: 
                    You can expand a function in line either by preceding its definition with the 'inline' specifier

                2. define a function inside a class declaration:
                    Include the functions definition within a class declaration.
*/




/* Example 10: Give two possible restrictions to 'in-line' functions. 

                An in-line function must be defined before it is first used. 
                Other common restrictions:
                    no 'loops'
                    must not be 'recursive'
                    no 'goto' or a 'switch'
                    no 'static' variables
*/




/* Example 11: Given the following class, show how an object called 'ob' that passes the value 
                '100 to a'and 'X to c' would be declared. 
*/
class sample {
        int a;
        char c;
    public:
        sample(int x, char ch) { a = x; c = ch; }
    // ...
};

sample ob (100 , 'X');




/* Example 12: using following class, create a function called make_sum() 
                that returns an object of type summation. 

                Have this function prompt the user for a number and then 
                    construct an object having this value and return it to the calling procedure. 

                Demonstrate that the function works.


                        class summation {
                                int num;
                                long sum ; // summation of num
                            public:
                                void set_sum(int n);
                                void show_sum(){ std::cout << num << " summed is " << sum << "\n"; }
                        };

                        void summation :: set_sum (int n) {
                            int i;
                            num = n;
                            sum = 0;
                            for (i =1; i <=n; i ++) sum += i;
                        }
*/

#include <iostream>

class summation{
        int num;
        long sum;   // summation of num
    public:
        void set_sum(int n);
        void show_sum(){ std::cout << num << " summed is " << sum << "\n"; }
};

// notice we didn't define set_sum() as in-line because it contains loop
void summation :: set_sum(int n){
    int i;
    num = n;
    sum = 0;
    for(i =1; i<=n; i ++) sum += i;
}

summation make_sum(){
    int i;
    summation temp;
    std::cout << " Enter number : ";
    std::cin >> i;
    temp.set_sum (i);
    return temp;
}


int main(){
    summation s;

    s = make_sum();
    s.show_sum();
    
    return 0;
}




/* Example 13: In the preceding question, set_sum() was not defined in-line within the "summation" class declaration.
                Give a reason why this might be necessary for some compilers. 

                ANS:
                    For some compilers, in-line functions cannot contain "LOOPS".
*/

