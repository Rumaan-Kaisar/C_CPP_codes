
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



For example, the divisible()
function from the preceding section can be automatically in-lined as shown here:
# include <iostream >
using namespace std ;
58INTRODUCING CLASSES
2.7. AUTOMATIC IN-LINING
class samp
{
int i, j;
public :
samp ( int a, int b);
/*
divisible () is defined here and automatically
in - lined .
*/
int divisible () { return !(i%j);}
};
samp :: samp ( int a, int b)
{
i = a;
j = b;
}
int main ()
{
samp ob1 (10 , 2) , ob2 (10 , 3);
// this is true
if( ob1. divisible ())
cout << "10 divisible by 2\n";
// this is false
if( ob2. divisible ())
cout << "10 divisible by 3\n";
return 0;
}
As you can see, the code associated with divisible() occurs inside the declaration for the class
samp. Further notice that no other definition of divisible() is needed-or permitted. Defining
divisible() inside samp causes it to be made into an in-line function automatically.
When a function defined inside a class declaration cannot be made into an in-line function
(because a restriction has been violated), it is automatically made into a regular function.
Notice how divisible() is defined within samp, paying particular attention to the body. It
occurs all on one line. This format is very common in C++ programs when a function is
declared within a class declaration. It allows the declaration to be more compact. However, the
samp class could have been written like this:
class samp
{
int i, j;
public :
samp ( int a, int b);
/*
divisible () is defined here and automatically in - lined .
*/
59TEACH YOURSELF
C++
int divisible ()
{
return !(i%j);
}
};
In this version, the layout of divisible() uses the more-or-less standard indentation style. From
the compiler’s point of view, there is no difference between the compact style is commonly found
in C++ programs when short functions are defined inside a class definition.
The same restrictions that apply to "normal" in-line functions apply to automatic in-line functions within a class declaration



