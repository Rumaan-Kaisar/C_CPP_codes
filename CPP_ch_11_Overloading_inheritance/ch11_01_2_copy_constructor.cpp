
/*  ------------------------    copy constructor    ------------------------
    
    Problem while PASSING / RETURN objects to a function:

        Recall 10.10 PASSING objects to functions and RETURNING objects from function: 
            ch10_10_2_pass_ref_to_obj.cpp
            ch10_10_3_return_ref.cpp



        Problems when "Passing Objects" to a function:
            When an object is passed to a function, an exact copy (bitwise copy) of that object is created
                and given to the function parameter that receives the object

            ----  problems  ----
            If the object contains "pointers" to dynamically allocated memory, 
                both the "original" and the "copy" will point to the same memory. 

            Any changes made to the copy will also affect the original object.

            Additionally, when the function ends, the copy's destructor is called, 
                which "affect the original object" if it deallocates shared resources.



        Problems when "Returning Objects" from a function:
            When an object is returned from a function, a "temporary object" is often created to hold the return value. 

            ----  problems  ----
            This temporary object goes out of scope once the value is returned to the calling routine, 
                causing the temporary object's destructor to be called.

            If the destructor destroys important resources (like dynamically allocated memory), 
                it could "cause issues" in the calling function that needs those resources.




----  rev[17-Sep-2024]  ----



By defining a copy constructor, you can fully specify exactly what occurs when a copy of an object is made.
	C++ defines two distinct types of situations in which the value of one object is given to another. 

[1]	The first situation is assignment. 
[2]	The second situation is initialization which can occur three ways:
[a]	when an object is used to initialize another object in a declaration statement.
[b]	when an object is passed as a parameter to a function, and
[c]	when a temporary object is created for use as a return value of a function.
	The copy constructor only applies to initializations. It does not apply to assignments.
	Declaring, defining & invoking (activating) copy-constructor: By default, when an initialization occurs, the compiler will automatically provides a default copy constructor that simply duplicates the object. However, it is possible to specify precisely how one object will initialize another by defining a copy constructor. Once defined, the copy constructor is called whenever an object is used to initialize another. The most common form of copy constructor is 

class_name( const class_name &obj) {	body of constructor 	}


Here obj is a reference to an object that is being used to initialize another object. const is an access modifier recall 5.7.




--------  Creating and using a copy constructor  --------
The core of the above issues is that a "bitwise (exact) copy of the object" is being made. 
By defining a "copy constructor", you can control what happens when an object is copied.

Two Types of Object Copying:
Assignment: When one object is assigned to another after both have been created.
Initialization: This occurs in three cases:
When an object is used to initialize another in a declaration.
When an object is passed to a function as a parameter.
When a temporary object is created as a return value from a function.
Copy Constructor vs Assignment
The copy constructor only applies to initializations, not assignments.
Default and Custom Copy Constructor
By default, C++ provides a copy constructor that simply duplicates the object. However, you can create a custom copy constructor to specify how one object initializes another. A typical copy constructor looks like this:

cpp
Copy code
class_name(const class_name &obj) {
   // body of the constructor
}
In this, obj is a reference to the object used for initialization, and const ensures that obj cannot be modified.





	To declare & define : For example,  a class called myclass, and that y is an object of type myclass, the declaration is 
myclass( const myclass &ob ); 	// const is an access modifier recall C_Ch7_3_2_acs_modfyr_constVolatile.c

The definition will be,  myclass :: myclass( const myclass &ob) {   body of copy-constructor    }

	To invoke: Three types of statements can invoke the  myclass copy constructor:
[1]	myclass x = y; 	// y explicitly initializing x 
[2]	fun1 (y); 		// y passed as a parameter 
[3]	y = func2 (); 	// y receiving a returned object 
In the first two cases, a reference to y would be passed to the copy constructor. In the third, a reference to the object returned by func() is passed to the copy constructor.

	Example: This program creates a " safe " array class. 
Since space for the array is dynamically allocated , a copy constructor is provided to allocate memory when one array object is used to initialize another.

	#include<cstdlib> 			// for using exit() 
		class array {	int *p, size ;
				public: array (int sz); 			// constructor 
					array(const array &a); 		// copy constructor 
					~ array() { delete [] p; } 	// destructor 
					void put(int i, int j) { if(i >=0 && i< size ) p[i] = j; }
					int get(int i) { return p[i]; }	};
Copy constructor	Normal constructor
array :: array( const array &a) { int i;
       size = a.size ;
       p = new int [a.size]; // allocate memory for copy *
       if(!p){cout<< " Allocation error "; exit(1);}
       for(i=0; i<a.size; i++) p[i]=a.p[i]; //copy
       cout << " Using copy constructor \n"; }	array :: array( int sz) {
     p = new int [sz ];
     if(!p){cout<< " Allocation error "; exit(1);}
     size = sz;
     cout << "Using 'normal' constructor \n";      
	}
int main(){array num(10);  // calls "normal" cnstrct 
	    int i;
for(i=0; i<10; i++) num.put(i,i); // array value 
for(i=9; i>=0; i--) cout<<num.get(i); // display 
cout << "\n";		
	// create another array and initialize with num 

     array x = num; // this invokes copy constructor 
    for(i=0; i<10; i++) cout<< x.get(i); // display x 
     return 0; }
	Here in the copy constructor, memory is allocated specifically for the copy , and the address of this memory is assigned to p. Therefore , p is not pointing to the same dynamically allocated memory as the original object .
	When copy-constructor is called: When num is used to initialize x (i.e., array x = num; ) the copy constructor is called, memory for the new array is allocated and stored in x.p, and the contents of num are copied to x's array.  In this way, x and num have arrays that have the same values, but each array is separate and distinct. (That is, num.p and x.p do not point to the same piece of memory.) 
	If the copy constructor had not been created, the bitwise initialization array x = num; would have resulted in x and num sharing the same memory for their arrays! (That is, num.p and x.p would have pointed to the same location.)
	When copy-constructor is not called: The copy constructor is called only for initializations. Copy constructors do not affect assignment operations. For example, the following sequence does not call the copy constructor defined in this program: 
array a(10) ; array b(10) ; b = a;       ( b = a performs the assignment operation. Rather calling copy-constructor) 
Note: Old Overload keyword : For old C++ compiler the keyword overload was required to create an overloaded function. It is now 
obsolete and no longer supported by modern C++ compilers. The general form:
overload func_name ; 	(It must precede the overloaded function declarations)
where func_name is the name of the function to be overloaded.. 


*/  

