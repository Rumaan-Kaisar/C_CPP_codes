
/*  ----------------    pass the object by reference    ----------------

    We know when an object is passed to a function by 
        use of the default "call-by-value parameter-passing" mechanism, a copy of that object is made.

    Although the parameter's constructor function is not called, 
        its destructor function is called when the function returns

        this can cause serious problems in some instances-
            For example: when the destructor frees dynamic memory.

        There is two way to solve this: 
            1. pass an object by reference
            2. use of copy constructors (discussed in Next chapter: Function overloading)



    Resolving problem of execution of "copy's destructor function" during function return
            Recall "ch10_06_2_pass_obj_to_func.cpp" and "ch10_06_3_return_obj_from_func.cpp"

        When you pass the object by REFERENCE, "no copy is made",
            so its destructor isn't called during function returns. 
        
        Remember: 
            that changes made to the object inside the function "affect the object" used as the argument.


        Note: 
            It is crucial to understand that a reference is not a pointer. 
            
            Therefore, when an object is passed by reference, 
                the member access operator remains the dot (.), not the arrow (->).

            Both pointers and references allow changes made inside a function 
                to affect the original object used as the argument.

            When using a POINTER, you must DEREFERENCE it to access or modify the object.
            When using a REFERENCE, you can access or modify the object DIRECTLY.

*/

// --------    Passing by Pointer vs. Reference    --------




	Example:   Lets first define class with constructor and destructor 
#include <iostream>
using namespace std;
class myclass {	int who ;
public : myclass (int n) { who = n;
cout << " Constructing " << who << "\n";}
~ myclass () { cout << " Destructing " << who << "\n"; }
int id() { return who; }	};

default call-by-value parameter-passing mechanism	call-by-reference parameter-passing mechanism
void f(myclass t){  /* t is passed by value .*/ 
cout << "Received" << t.id() << "\n"; }
int main(){	myclass x(1) ;
f(x);
return 0;}	void f(myclass &t){  /* Now t is passed by reference .*/ 
cout << "Received" << t.id() << "\n"; } /*still "." used*/
int main(){	myclass x(1) ;
f(x);
		return 0;}
Output : 	Constructing 1
		Received 1
		Destructing 1
		Destructing 1 	/*Two time appears */	Output : 	Constructing 1
		Received 1
		Destructing 1
Now we notice that the only difference between the two mechanism is "&" before t inside the function parameter .

