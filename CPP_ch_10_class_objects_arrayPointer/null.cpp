
// --------    rev[2-May-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

// ------------    Cumulative/Masery/Review skill check    ------------




// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
Before proceeding, you should be able to answer the following questions and perform the exercises.


/* Example 5: Using the "stack class" (ch10_06_2_pass_obj_to_func.cpp, Example 5), 
                write a function called "loadstack()" that returns a stack 
                that is already loaded with the letters of the alphabet(a-z). 
                
                Assign this stack to another object in the calling routine and 
                    prove that it contains the alphabet. 

                Be sure to change the stack size so it is large enough to hold the alphabet. 
*/

#include <iostream>

#define SIZE 27

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

stack loadstack();  // Declaring "loadstack()" of class type "stack". It returns a stack.


// -=-=-  main function  -=-=-
// notice the stack loading mechanism moved to loadstack()
int main(){
    stack s1;
    
    // load stack using "loadstack()"
    s1 = loadstack();
    // show the stack using "showstack()"
    showstack(s1);

    return 0;
}


/* 
// -=-=-  main function (old)  -=-=-
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
*/

// Definition of "showstack()" to display the contents of a stack. 
void showstack (stack o){
    char c;
    // when this statement ends, the stack-type object 'o' is empty
    while(c=o.pop()) std::cout << c << '\n';
} 

// Definition of "loadstack()" to Load a stack with the letters of the alphabet .
stack loadstack(){
    stack t;
    char c;

    // load a-z
    for(c = 'a'; c <= 'z'; c++) t.push(c);
    return t;
}






/* Example 6: Explain why you must be careful when passing objects to a function 
                or returning objects from a function. 

                ANS:
                    When passing / returning an object to / from a function 
                    "temporary copies" of the object are created that will be destroyed when the function terminates.

                    When a temporary copy of an object is destroyed, 
                        the destructor function might destroy something that is needed elsewhere in the program.

*/




/* Example 7: What is a friend function 

                ANS:
                    A friend is a non-member function that is granted access 
                        to the "private members" of the class for which it is a friend.
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

// Load a stack with the alphabet .
# include <iostream >
# include <cctype >
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
444ANSWERS
CUMULATIVE SKILLS CHECK: Chapter 3
}
void showstack ( stack o);
stack loadstack ();
stack loadstack ( int upper );
int main ()
{
stack s1 , s2 , s3;
s1 = loadstack ();
showstack (s1);
// get uppercase letters
s2 = loadstack (1) ;
showstack (s2);
// use lowercase letters
s3 = loadstack (0) ;
showstack (s3);
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
/*
Load a stack with the letters of the alphabet . Uppercase
letters if upper if 1; lowercase otherwise .
*/
stack loadstack ( int upper )
{
445TEACH YOURSELF
C++
stack t;
char c;
if( upper )
c = ’A’;
else
c = ’a’;
for (; toupper (c) <= ’Z’; c++)
t. push (c);
return t;
}




/* Example 2: Using the strtype class shown in Section 3.1, Example 3 [ch10_06_1_assign_obj.cpp: Example 4], 
                add a friend function that takes as an argument "a pointer to an object" of type 'strtype' and 
                returns a pointer to the string pointed to by that object. 

                (That is, have the function return p.) 
                Call this function get_string(). 
*/
# include <iostream >
# include <cstring >
# include <cstdlib >
using namespace std ;
class strtype
{
char *p;
int len ;
public :
strtype ( char * ptr );
~ strtype ();
void show ();
friend char * get_string ( strtype *ob);
};
strtype :: strtype ( char *ptr )
{
len = strlen ( ptr );
p = ( char *) malloc (len +1);
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
strcpy (p, ptr );
}
strtype ::~ strtype ()
{
cout << " Freeing p\n";
free (p);
}
void strtype :: show ()
{
cout << p << " - lengthj : " << len ;
cout << ’\n’;
446ANSWERS
CUMULATIVE SKILLS CHECK: Chapter 3
}
char * get_string ( strtype *ob)
{
return ob ->p;
}
int main ()
{
strtype s1(" This is a test .");
char *s;
s1. show ();
// get pointer to string
s = get_string (& s1);
cout << " Here is string contained in s1: ";
cout << s << "\n";
return 0;
}




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
The outcome of the experiment is as follows: Yes, data from the base class is also copied
when an object of a derived class is assigned to another object of the same derived class.
Here is a program that demonstrates this fact:
# include <iostream >
using namespace std ;
class base
{
int a;
public :
void load_a ( int n) { a = n; }
int get_a () { return a; }
};
class derived : public base
{
int b;
public :
void load_b ( int n) { b = n; }
int get_b () { return b; }
};
int main ()
{
derived ob1 , ob2 ;
ob1 . load_a (5) ;
ob1 . load_b (10) ;
447TEACH YOURSELF
C++
// assign ob1 to ob2
ob2 = ob1 ;
cout << " Here is ob1 ’s a and b: ";
cout << ob1 . get_a () << " " << ob1 . get_b () << "\n";
cout << " Here is ob2 ’s a and b: ";
cout << ob2 . get_a () << " " << ob2 . get_b () << "\n";
/*
As you can probably guess , the output is the same for
each object .
*/
return 0;
}




// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

/* Example 1: When one object is assigned to another, what precisely takes place? 

                ANS:
                    When one object is assigned to another of the "same type", 
                    the current values of all data members of the object on the RIGHT are assigned 
                    to the corresponding data members on the LEFT.
*/




/* Example 2: Can any troubles or side effects occur when one object is assigned to another? 
                (Give an example.) 

                ANS:
                    if that assignment "overwrites important data" already existing in the target object. 
                    eg: a" pointer to dynamic memory" or to an "open file" can be overwritten and, therefore, lost.
*/




/* Example 3: When an object is "passed as an argumen"t to a function, a copy of that object is made. 
                Is the copy's constructor function called? 
                Is its destructor called? 

                ANS:
                    Constructor isn't called
                    The copy’s destructor is called when the object is destroyed 
                        by the termination of the function.
*/




/* Example 4: By default, objects are passed to functions "by value", i.e. what occurs to the 
                    copy inside the function is not supposed to affect the argument used in the call. 
                
                Can there be a violation of this principle? 
                If so, give an example. 


                ANS:
                    The violation of the separation between an argument and its copy when 
                        passed to a parameter can be caused by "several destructor", 
                        that memory will also be lost to the argument. 
                    
                    In general, if the DESTRUCTOR function destroys anything that the "original argument requires", 
                        damage to the argument will occur.
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


5. # include <iostream >
using namespace std ;
class summation
{
int num ;
long sum ; // summation of num
public :
void set_sum ( int n);
void show_sum ()
{
cout << num << " summed is " << sum << "\n";
}
};
void summation :: set_sum (int n)
{
448ANSWERS
REVIEW SKILLS CHECK: Chapter 4
int i;
num = n;
sum = 0;
for (i =1; i <=n; i ++)
sum += i;
}
summation make_sum ()
{
int i;
summation temp ;
cout << " Enter number : ";
cin >> i;
temp . set_sum (i);
return temp ;
}
int main ()
{
summation s;
s = make_sum ();
s. show_sum ();
return 0;
}




/* Example 6: In the preceding question, set_sum() was not defined in-line within the "summation" class declaration.
                Give a reason why this might be necessary for some compilers. 

                ANS:
                    For some compilers, in-line functions cannot contain "LOOPS".
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

7. # include <iostream >
using namespace std ;
class myclass
{
int num ;
public :
myclass ( int x)
{
num = x;
}
friend int isneg ( myclass ob);
};
int isneg ( myclass ob)
{
return (ob. num <0) ? 1 : 0;
}
449TEACH YOURSELF
C++
int main ()
{
myclass a( -1) , b (2) ;
cout << isneg (a) << ’ ’ << isneg (b);
cout << ’\n’;
return 0;
}




/* Example 8: Can a friend function be friends with more than one class? 

                ANS:
                    Yes, a friend function can be friends with more than one class.
*/



