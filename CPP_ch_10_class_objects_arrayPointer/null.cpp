
// --------    rev[28-Apr-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

// ------------    Cumulative/Masery/Review skill check    ------------




// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
Before proceeding, you should be able to answer the following questions and perform the exercises.



/* Example 1: What single prerequisite must be met in order for one object to be assigned to another? 
                ANS: 
                    Same class type.
                    For one object to be ASSIGNED to another, both must be of the "same class type".
*/



/* Example 2: Given this class fragment (uses memory allocation), 

                        class samp{
                                double *p;
                            public:
                                samp(double d){
                                    p = (double *)malloc(sizeof ( double ));
                                    if(!p) exit(1) ; // allocation error
                                    *p = d;
                                } 
                                ~samp(){free (p);}
                                // ..
                        };

                        // ...
                        samp ob1(123.09), ob2(0.0);
                        // ...
                        ob2 = ob1;


                what problem is caused by the assignment of 'ob1' to 'ob2'?


                ANS:
                    The trouble with the assignment of ob1 to ob2 is that:
                        The MEMORY pointed to by ob2's initial value of p is now LOST 
                            because this value is "overwritten by the assignment".         
                        This memory thus becomes "impossible to free", 
                        
                        And the memory pointed to by ob1's p is freed twice when it is destroyed
                            possibly causing DAMAGE to the "dynamic allocation system".
*/




/* Example 3: Given this class,

                        class planet{
                                int moons;
                                double dist_from_sun;   // in miles
                                double diameter;
                                double mass;
                            public:
                                // ....
                                double get_miles(){ return dist_from_sun; }
                        };

                create a function called light() that takes as an argument an object of type planet and 
                    returns the number of seconds that it takes "light from the sun to reach" the planet.

                Assume that light travels at 186,000 miles per second and 
                    that dist from sun is specified in miles.


                ans:
                    int light(planet p){
                        return p.get_miles() / 186000;
                    }
*/




/* Example 4: Can the "address of an object" be passed to a function as an argument? 
                ANS: Yes.
*/




/* Example 5: Using the "stack class" (ch10_06_2_pass_obj_to_func.cpp, Example 5), 
                write a function called "loadstack()" that returns a stack 
                that is already loaded with the letters of the alphabet(a-z). 
                
                Assign this stack to another object in the calling routine and 
                    prove that it contains the alphabet. 

                Be sure to change the stack size so it is large enough to hold the alphabet. 
*/

#include <iostream>

#define SIZE 10

// Declare a stack class for characters .
class stack {
        char stck[SIZE];   // holds the stack
        int tos;            // index of top of stack
    public:
        stack();            // constructor. Notice no 'void init();' required
        void push(char ch); // push character on stack
        char pop();         // pop character from stack
};


// -=-=-=-=-=-    implementing member function    -=-=-=-=-=-

// stack(): Initialize the stack the constructor function
stack::stack(){
    std::cout << " Constructing a stack \n";
    tos = 0;
}

// push(): Push a character
void stack::push(char ch){
    if(tos == SIZE){
        std::cout << " Stack is full \n";
        return;
    }
    stck[tos] = ch;
    tos++;
}

// pop(): Pop or remove a character
char stack::pop(){
    if(tos == 0){
        std::cout << " Stack is empty \n";
        return 0; // return null on empty stack
    }
    tos--;
    return stck[tos];
}


void showstack (stack o);   // Declaring "showstack()". It display the contents of a stack. 

// -=-=-  main function  -=-=-
int main(){
    stack s1;
    int i;

    s1.push('a');
    s1.push('b');
    s1.push('c');

    // show the stack using "showstack()"
    showstack(s1);

    // s1 in main is still existent
    std::cout << "s1 stack still contains this : \n";
    for(i =0; i<3; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";

    return 0;
}


// Definition of "showstack()" to display the contents of a stack. 
void showstack (stack o){
    char c;
    // when this statement ends, the stack-type object 'o' is empty
    while (c=o. pop ()) std::cout << c << '\n';
} 





// Load a stack with the alphabet .
# include <iostream >
using namespace std ;
# define SIZE 27
// Declare a stack class for characters
class stack
{
char stck [ SIZE ]; // holds the stack
int tos ; // index of top of stack
public :
stack (); // constructor
void push ( char ch); // push character on stack
char pop (); // pop character from stack
};
// Initialize the stack
stack :: stack ()
{
cout << " Constructing a stack \n";
tos = 0;
}
// Push a character .
void stack :: push ( char ch)
{
if( tos == SIZE )
{
cout << " Stack is full \n";
return ;
}
stck [ tos ] = ch;
tos ++;
}
442ANSWERS
MASTERY SKILLS CHECK: Chapter 3
// Pop a character .
char stack :: pop ()
{
if( tos ==0)
{
cout << " Stack is empty \n";
return 0; // return null on empty stack
}
tos --;
return stck [ tos ];
}
void showstack ( stack o);
stack loadstack ();
int main ()
{
stack s1;
s1 = loadstack ();
showstack (s1);
return 0;
}
// Display the contents of a stack .
void showstack ( stack o)
{
char c;
// when this statement ends , the o stack is empty
while (c=o. pop ())
cout << c << ’\n’;
}
// Load a stack with the letters of the alphabet .
stack loadstack ()
{
stack t;
char c;
for (c = ’a’; c <= ’z’; c++)
t. push (c);
return t;
}






/* Example 6: Explain why you must be careful when passing objects to a function 
                or returning objects from a function. 


When passing an object to a function or returning an object from a function, temporary
copies of the object are created that will be destroyed when the function terminates.
When a temporary copy of an object is destroyed, the destructor function might destroy
something that is needed elsewhere in the program.

*/




/* Example 7: What is a friend function 

A friend is a nonmember function that is granted access to the private members of the class for which it is a friend.

*/





// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.



/* Example 1: Functions can be OVERLOADED as long as the "number or type of their parameters" differs.
                Overload loadstack() from Exercise 5 of the Mastery Skills Check so that 
                it takes an integer, called upper, as a parameter. 
                In the overloaded version, if upper is 1, load the stack with the uppercase alphabet. 
                Otherwise, load it with the lowercase alphabet. 
*/



/* Example 2: Using the strtype class shown in Section 3.1, Example 3 [ch10_06_1_assign_obj.cpp: Example 4], 
                add a friend function that takes as an argument "a pointer to an object" of type 'strtype' and 
                returns a pointer to the string pointed to by that object. 

                (That is, have the function return p.) 
                Call this function get_string(). 
*/


/* Example 3: When an object of a "derived class" is assigned to another object of the same derived class, 
                is the data associated with the base class also copied? 

                To find out, use the following two classes and 
                    write a program that demonstrates what happens.

                        class base {
                                int a;
                            public:
                                void load_a(int n) { a = n; }
                                int get_a() { return a; }
                        };

                        class derived : public base {
                                int b;
                            public:
                                void load_b(int n) { b = n; }
                                int get_b() { return b; }
                        };
*/



// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-
Before proceeding, you should be able to correctly answer the following questions and do the
exercises.



/* Example 1: When one object is assigned to another, what precisely takes place? */




/* Example 2: Can any troubles or side effects occur when one object is assigned to another? 
                (Give an example.) 
*/




/* Example 3: When an object is "passed as an argumen"t to a function, a copy of that object is made. 
                Is the copy's constructor function called? 
                Is its destructor called? 
*/




/* Example 4: By default, objects are passed to functions "by value", i.e. what occurs to the 
                    copy inside the function is not supposed to affect the argument used in the call. 
                
                Can there be a violation of this principle? 
                If so, give an example. 
*/




/* Example 5: using following class, create a function called make_sum() 
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




/* Example 6: In the preceding question, set_sum() was not defined in-line within the "summation" class declaration.
                Give a reason why this might be necessary for some compilers. 
*/




/* Example 7: Given the following class, show how to add a friend function called isneg() that 
                takes one parameter of type myclass and 
                returns TRUE if num is negative and FALSE otherwise. 

                        class myclass{
                                int num;
                            public:
                                myclass(int x) { num = x; }
                        };
*/




/* Example 8: Can a friend function be friends with more than one class? */


