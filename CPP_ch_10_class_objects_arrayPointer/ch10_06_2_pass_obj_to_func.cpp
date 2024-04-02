
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




// --------    rev[2-apr-24]    --------

/* Example 5: Using the stack example from previous Section "ch10_06_1_assign_obj.cpp", Example 3, 
                add a function called "showstack()" that is passed an object of type 'stack'.
                Have this function display the contents of a stack. 

                In the following version of the 'STACK example', only s1 has any characters actually pushed onto it.
                However, because of the assignment, s2's "stck" array will also contain the characters a, b, and c.
*/
#include <iostream>

#define SIZE 10

// Declare a stack class for characters .
class stack {
        char stck[ SIZE];   // holds the stack
        int tos;            // index of top of stack    
    public:
        stack();            // constructor. Notice no 'void init();' required
        void push(char ch); // push character on stack
        char pop();         // pop character from stack
};


// -=-=-=-=-=-    implementing member function    -=-=-=-=-=-

// stack(): Initialize the stack. No 'void init();' required
    // implementing constructor function
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


// -=-=-  main function  -=-=-
int main(){
    stack s1, s2; // create two stacks that are automatically initialized.
    int i;

    s1.push('a');
    s1.push('b');
    s1.push('c');

    // clone s1
    s2 = s1; // now s1 and s2 are identical

    for(i =0; i<3; i ++) std::cout << " Pop s1: " << s1.pop() << "\n";
    for(i =0; i<3; i ++) std::cout << " Pop s2: " << s2.pop() << "\n";

    return 0;
}





/* Example 6: As you know, when an object is passed to a function, a copy of that object is made.
                Further, when that function returns, the copy's destructor function is called. 
                Keeping this in mind, what is wrong with the following program? 
                Is it calling destructormultiple times?
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


