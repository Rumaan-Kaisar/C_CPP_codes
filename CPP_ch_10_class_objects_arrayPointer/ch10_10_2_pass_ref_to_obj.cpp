
	PASSING REFERENCES TO OBJECTS :  As you learned in 10.10, when an object is passed to a function by use of the default call-by-value parameter-passing mechanism, a copy of that object is made. Although the parameter's constructor function is not called, its destructor function is called when the function returns.
	As you should recall, this can cause serious problems in some instances-when the destructor frees dynamic memory, for example. There is two way to solve this : 
	One solution to this problem is to pass an object by reference.
	The other solution involves the use of copy constructors, which are discussed in Next chapter: Function overloading.
	When you pass the object by reference, no copy is made, and therefore its destructor function is not called when the function returns. Remember, however, that changes made to the object inside the function affect the object used as the argument.
	Note: It is critical to understand that a reference is not a pointer. Therefore, when an object is passed by reference, the member access operator remains the dot (.), not the arrow (->).
	Example:   Lets first define class with constructor and destructor 
#include <iostream >
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

