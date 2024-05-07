
// --------    rev[2-May-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

// ------------    Cumulative/Masery/Review skill check    ------------




// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
This section checks how well you have integrated material in this chapter with that from the
preceding chapters.





// --------    rev[07-may-2024]    --------

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


                ANS:
                    The outcome of the experiment is as follows: 
                    Yes, data from the base class is also copied when an object of 
                        a derived class is assigned to another object of the same derived class.
    
                    Here is a program that demonstrates this fact:
*/


#include <iostream>

class base{
        int a;
    public:
        void load_a(int n) { a = n; }
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



