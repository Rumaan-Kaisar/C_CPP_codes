
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




/* Example 3: Pass the ADRESS of an object to modify / change the passed object using a function.
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



// ----    rev[28-mar-24]    ----

	These two example reflects the same thing that we've discussed in C's passing argument's address in function parameters ( recall  5.3 ).
	When a copy of an object is created because it is used as an argument to a function, the constructor function is not called. However, when the copy is destroyed (by going out of scope when the function returns), the destructor function is called.
	The reason for not calling the constructor function is that, the constructor function is generally used to initialize some aspect of an object, it must not be called when making a copy of an already existing object passed to a function. Doing so would alter the contents of the object. When passing an object to a function, you want the current state of the object, not its initial state.
	Destructor function is called because the object might perform some operation that must be undone when it goes out of scope.  For Example :
 
class samp { int i;
public :
   		  samp(int n) { i=n;   /* constructor */
      cout << " Constructing \n"; }
  		  ~samp() {           /* destructor */
      cout << " Destructing \n"; }
   		  int get_i() { return i; }   };
/* Return square of obj.i.*/ 
int sqr_it( samp obj){ 
    return obj.get_i() * obj.get_i(); }
int main() { 	samp a (10) ;
cout << sqr_it (a) << "\n";
return 0; }
 
           Outout : 	Constructing
Destructing
100
Destructing
As you can see, only one call to the constructor function is made. This occurs when a is created. However, two calls to the destructor are made. One is for the copy created when a is passed to sqr_it(). The other is for a itself.
	One important point :  when an object is passed to a function, a copy of that object is made. Further, when that function returns, the copy's destructor function is called. The fact that the destructor for the object that is the copy of the argument is executed when the function terminates can be a source of problems. For example, if the object used as the argument allocates dynamic memory and frees that memory when destroyed, its copy will free the same memory when its destructor is called. This will leave the original object damaged and effectively useless. This problem can be resolved in two ways : one, using reference. Two, using copy-constructor.

