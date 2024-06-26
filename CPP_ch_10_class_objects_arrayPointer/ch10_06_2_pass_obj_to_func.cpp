
/*  ----------------------    PASS objects to function    ---------------------- 

    PASSING objects to functions:
        Objects can be passed to functions as arguments similar to other data-types
        Declare the function's PARAMETER as a "class type" and 
            then use an 'object' of that class as an 'argument' when calling the function. 

                type function_name( class_type obj_1, class_type obj_2, . . . . );


        As with other types of data, by default all objects are "passed by value" to a function.
    


    What is "passing by value"?
        The default method of parameter passing in C++, including objects, is 'by value'. 
        This means that a "BITWISE COPY" of the argument is made and it is this copy that is used by the function. 
        Therefore, changes to the object inside the function "DO NOT AFFECT" the calling (original) object.  
        
    Objects , like other parameters , are passed by value . 
        Thus changes to the parameter inside a function have "NO EFFECT" on the object used in the call.



    ------------    How to modify / change the passed object using a function    ------------
    passing the ADRESS of an object:
        The address of an object can be passed to a function so that 
            the argument used in the call can be modified by the function
        i.e. changes to the object inside the function will affect the calling (original) object. 

*/


/* Example 1: In following program we pass object to a function 
                Here sqr_it() takes an argument of type samp and returns the square of that object's i value.
*/

#include <iostream>

class samp{ 
        int i;
    public:
        samp(int n) { i = n; }
        int get_i() { return i;} 
};

// following function uses an object as an argument
    // it returns square of "obj.i". 
int sqr_it(samp obj){
      return obj.get_i() * obj.get_i(); 
}


int main(){	
    samp a(10), b(2);

    // calling sqr_it(), notice the 'object' arguments
    std::cout << sqr_it(a) << "\n";
    std::cout << sqr_it(b) << "\n";

    return 0;
}
 



/* Example 2: Changes to the parameter inside a function have "NO EFFECT" on the object used in the call  */
#include <iostream>

class samp{ 
        int i;
    public:
        samp(int n) { i = n; }
        void set_i(int n) { i=n; }
        int get_i() {return i;} 
};

// Set obj.i to its square. This has no effect on the object used to call sqr_it()  
void sqr_it(samp obj) {
    obj.set_i(obj.get_i() * obj.get_i());   // setting, i.e. updating with squared value
    std::cout << "Square = Copy of a has i value of :";
    std::cout << obj.get_i() << std::endl;   // returns the current, updated value. Printing 
}

int main(){	
    samp a(10);

    sqr_it(a);  // 'a' passed by value
    std::cout << "But , a.i is unchanged in main : ";
    std::cout << a.get_i(); 

    return 0;
}

// output : 	
// Copy of a has i value of 100
// But, a.i is unchanged in main: 10




/* Example 3: Pass the ADDRESS of an object to modify / change the passed object using a function.
                Let's consider the class of the previous example. 
                If we change the DEFINITION of sqr_it() like below: 
                    it will modify the value of the object whose address is used in the call to "sqr_it()".
*/

#include <iostream>

class samp{ 
        int i;
    public:
        samp(int n) { i = n; }
        void set_i(int n) { i=n; }
        int get_i() {return i;} 
};

// Passing object's adress. This affects the original object used to call sqr_it()
// Notice how '->' is used to access the member-function set_i()
void sqr_it(samp *obj) {
    obj->set_i( obj->get_i() * obj->get_i() );
    std::cout << "Square = Copy of a has i value of :" ;
    std::cout << obj->get_i() << std::endl; 
}

int main(){	
    samp a(10); 

    sqr_it(&a);  // pass a's address of sqr_it()
    std::cout <<"Now , a.i is changed in main : ";
    std::cout << a.get_i(); 
    
    return 0;
}

// output : 	
// Copy of a has i value of 100
// Now, a.i is changed in main: 100




/*  ------------    CONSTRUCTOR & DESTRUCTOR for object passed as function parameters    ------------

    Above two example reflects the same thing that we've discussed in 
        C's passing argument's address in function parameters ( recall  C_Ch5_3_1_func_param.c ).



    CONSTRUCTOR function is NOT called:
        When a "copy of an object" is created because it is used as an argument to a function, 
            the constructor function is not called. 

        Because the constructor is generally used to initialize the object, 
        It must not be called when making a "copy of an already existing object" passed to a function. 
        Doing so would "alter the contents" of the object. 

        When passing an object to a function, 
            you want the current state of the object, not its initial state.



    DESTRUCTOR function is CALLED:
        However, when the copy is destroyed (by going out of scope when the function returns), 
        Destructor is called because the object might perform some 
            operation that must be undone when it goes out of scope.

        One important point :  
            when an object is passed to a function, a "copy of that object" is made. 
            Further, when that function returns, the "copy's destructor function" is called. 
*/




/* Example 4: Destructor function is called because the object might perform 
                some operation that must be undone when it goes out of scope.  
                Notice following Example
*/

#include <iostream>

class samp { 
        int i;
    public:
        samp(int n){      // constructor
            i=n;   
            std::cout << " Constructing \n"; 
        }
        ~samp(){          // destructor
            std::cout << " Destructing \n"; 
        }
   		int get_i(){ return i; }
};


// Return square of obj.i.
int sqr_it(samp obj){ 
    return obj.get_i() * obj.get_i(); 
}
    

int main(){
    samp a(10);

    std::cout << sqr_it(a) << "\n";

    return 0; 
}
 
/* Output : 	
        Constructing
        100
        Destructing
        Destructing 


    Notice only one call to the constructor function is made. 
        This occurs when a is created. 

    However, two calls to the destructor are made. 
        One is for the "copy" created when "object a" is passed to sqr_it(). 
        The other is for "object a itself".
*/




/*  ----------------    problem of execution of "copy's destructor function"    ----------------
    When an object is passed to a function, a "copy of that object" is made. 
        Further, when that function returns, the "copy's destructor function" is called. 

    However the execution of "copy's destructor function" can creates some sort-of problems. 
        For example, if the object used as the argument 
            "allocates dynamic memory when created" and 
            "frees that memory when destroyed", 
        its copy will free the same memory when its destructor is called. 
        This will leave the original object DAMAGED and effectively USELESS. 


    Resolve it 2 ways:
            1. using REFERENCE. 
            2. using copy-constructor
        This problem can be resolved in two ways : one, using reference. Two, using copy-constructor.

        One way around the problem of a - "parameter’s destructor function destroying data needed by the calling argument" is 
            to pass the address of the object and not the object itself (making REFERENCE). 
            When an 'ADDRESS' is passed, no new object is created, 
            and therefore, no destructor is called when the function returns

        Another way is to use a COPY-CONSTRUCTOR
            It's a special type of constructor that lets you define precisely how copies of objects are made.
*/




/* Example 5: Using the stack example from previous Section "ch10_06_1_assign_obj.cpp", Example 3, 
                add a function called "showstack()" that is passed an object of type 'stack'.
                Have this function display the contents of a stack.
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




/* Example 6: As you know, when an object is passed to a function, a copy of that object is made.
                Further, when that function returns, the copy's destructor function is called. 
                Keeping this in mind, what is wrong with the following program? 
                Does it generates double free ERR? What is the consequences?
*/

// This program contains an error. Double-Free ERR
#include <iostream>
#include <cstdlib>

class dyna{
        int *p;
    public:
        dyna(int i);
        ~dyna(){ 
            free(p); 
            std::cout << " freeing \n"; 
        }
        int get(){ return *p; }
};

// constructor
dyna::dyna(int i){
    p = (int *)malloc(sizeof(int));
    if(!p){
        std::cout << " Allocation failure \n";
        exit(1);
    }
    *p = i;
}

// Return negative value of *ob.p
int neg(dyna ob){
    return -ob.get();
}

int main(){
    dyna o(-10);
    std::cout << o.get() << "\n";
    std::cout << neg(o) << "\n";

    dyna o2(20);
    std::cout << o2.get() << "\n";
    std::cout << neg(o2) << "\n";

    std::cout << o.get() << "\n";
    std::cout << neg(o) << "\n";

    return 0;
}

/*  Answer: The memory used to hold the integer pointed to by 'p' in object 'o' 
            that is used to call neg() is "freed" when the "copy of o" is destroyed when neg() terminates, 
            even though this memory is still needed by "o inside main()".
*/




/* Example 7: Given this class,

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


                ANS:
                    int light(planet p){
                        return p.get_miles() / 186000;
                    }
*/




/* Example 8: Can the "address of an object" be passed to a function as an argument? 

                ANS: Yes.
*/




/* Example 9: Using the "stack class" (ch10_06_2_pass_obj_to_func.cpp, Example 5), 
                write a function called "loadstack()" that returns a stack 
                that is already loaded with the letters of the alphabet(a-z). 
                
                Assign this stack to another object in the calling routine and 
                    prove that it contains the alphabet. 

                Be sure to change the stack size so it is large enough to hold the alphabet. 
*/

#include <iostream>

#define SIZE 27     // change the stack size

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


void showstack(stack o);   // Declaring "showstack()". It display the contents of a stack. 

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




/* Example 10: Explain why you must be careful when passing objects to a function 
                or returning objects from a function. 

                ANS:
                    When passing / returning an object to / from a function 
                    "temporary copies" of the object are created that will be destroyed when the function terminates.

                    When a temporary copy of an object is destroyed, 
                        the destructor function might destroy something that is needed elsewhere in the program.

*/




/* Example 11: Functions can be OVERLOADED as long as the "number or type of their parameters" differs.
                Overload loadstack() from "Example 9" such that it takes an integer, called "upper", as a parameter. 
                In the overloaded version, if "upper" is 1, load the stack with the uppercase alphabet. 
                Otherwise, load it with the lowercase alphabet. 
*/
#include <iostream>
#include <cctype>

#define SIZE 27     // change the stack size

// Declare a stack class for characters.
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


void showstack(stack o);    // Declaring "showstack()". It display the contents of a stack. 
stack loadstack();          // Declaring "loadstack()" of class type "stack". It returns a stack.
stack loadstack(int upper);     // overloading loadstack() to return uppercase alphabet


// -=-=-  main function  -=-=-
// notice the stack loading mechanism moved to loadstack() and loadstack(int upper)
int main(){
    stack s1 , s2 , s3;

    // load stack using "loadstack()" with lowercase alphabet
    s1 = loadstack();
    // show the stack s1 using "showstack()"
    showstack(s1);

    // get uppercase letters
    s2 = loadstack(1);
    showstack(s2);  // show stack s2

    // use lowercase letters
    s3 = loadstack(0);
    showstack(s3);

    return 0;
}



// Definition of "showstack()" to display the contents of a stack. 
void showstack (stack o){
    char c;
    // when this statement ends, the stack-type object 'o' is empty
    while(c=o.pop()) std::cout << c << '\n';
} 


// Definition of "loadstack()" to Load a stack with the letters of the alphabet.
stack loadstack(){
    stack t;
    char c;

    // load a-z
    for(c = 'a'; c <= 'z'; c++) t.push(c);
    return t;
}


/*  overloaded version of loadstack() so that it returns uppercase alphabet 
        Load a stack with the letters of the alphabet.
        Uppercase letters if upper is 1; 
        lowercase otherwise.
*/
stack loadstack(int upper){
    stack t;
    char c;

    // set starting point
    if(upper) c = 'A';
    else c = 'a';

    /*  load A-Z. Uppercase Z is used in loop condition
        notice loop control variable initilaized outside of FOR
        also notice in loop condition, toupper(c) is used for the case, c = 'a'
            in this case loop condition is checked with uppercased c 
            but lowercase c is pushed to t
            resulting a stack of lowercase alphabet 
    */
    for(; toupper(c) <= 'Z'; c++) t.push(c);
    return t;
}




/* Example 12: When an object is "passed as an argumen"t to a function, a copy of that object is made. 
                Is the copy's constructor function called? 
                Is its destructor called? 

                ANS:
                    Constructor isn't called
                    The copy’s destructor is called when the object is destroyed 
                        by the termination of the function.
*/




/* Example 13: By default, objects are passed to functions "by value", i.e. what occurs to the 
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

