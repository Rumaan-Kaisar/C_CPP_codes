
// --------    rev[25-Apr-24]    --------

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-
// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-

// ------------    Cumulative/Masery/Review skill check    ------------



// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-
Before proceeding, you should be able to answer the following questions and perform the exercises.



/* Example 1: What single prerequisite must be met in order for one object to be assigned to another? */



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
*/



/* Example 4: Can the address of an object be passed to a function as an argument? */




/* Example 5: Using the "stack class", write a function called "loadstack()" that 
                returns a stack that is already loaded with the letters of the alphabet(a-z). 
                
                Assign this stack to another object in the calling routine and 
                    prove that it contains the alphabet. 

                Be sure to change the stack size so it is large enough to hold the alphabet. 
*/




/* Example 6: Explain why you must be careful when passing objects to a function 
                or returning objects from a function. 
*/




/* Example 7: What is a friend function */





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



Example 1: When one object is assigned to another, what precisely takes place?



Example 2: Can any troubles or side effects occur when one object is assigned to another? (Give an
example.)



Example 3: When an object is passed as an argument to a function, a copy of that object is made. Is
the copy’s constructor function called? Is its destructor called?



Example 4: By default, objects are passed to functions by value, which means that what occurs to
the copy inside the function is not supposed to affect the argument used in the call. Can
there be a violation of this principle? If so, give an example.



Example 5: Given the following class, create a function called make sum() their returns an object of
type summation. Have this function prompt the user for a number and then construct
an object having this value and return it to the calling procedure. Demonstrate that the
function works.
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
int i;
num = n;
sum = 0;
for (i =1; i <=n; i ++)
sum += i;
}



Example 6: In the preceding question, the function set sum() was not defined in line within the summation class declaration. Give a reason why this might be necessary for some compilers.



Example 7: Given the following class, show how to add a friend function called isneg() that takes one
parameter of type myclass and returns true if num is negative and false otherwise.
88ARRAYS, POINTERS, AND REFERENCES
4.1. ARRAYS OF OBJECTS
class myclass
{
int num ;
public :
myclass ( int x) { num = x; }
};



Example 8: Can a friend function be friends with more than one class?

