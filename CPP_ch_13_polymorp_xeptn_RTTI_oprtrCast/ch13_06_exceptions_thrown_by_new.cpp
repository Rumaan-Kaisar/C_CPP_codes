
/*  ------------------------    chapter    ------------------------

13.7 Handling exceptions thrown by new
Behavior of new as specified by Standard C++: In early C++, new returned null on failure. In later version new caused an exception on failure.  Finally, it was decided that a new failure will generate an exception by default, but that a null pointer could be returned instead, as an option. 
	Allocation exceptions with new and xalloc or bad_alloc: In Standard C++, when an allocation request cannot be honored, new throws a bad_alloc (xalloc in older versions) exception. If you don't catch this exception, your program will be terminated.
	It is good for short programs but in real applications you must catch this exception and process it in some rational manner. 
	To have access to this exception, you must include the header  <new> in your program.
	Returning old fashioned null In Standard C++:  It is also possible to have new return null instead of throwing an exception when an allocation failure occurs.  This form of new is : 	p_var =new(nothrow) type ;
	Here p_var is a pointer variable of type. 
	The nothrow form of new works like the original version of new from years ago. Since it returns null on failure, it can be "dropped into" older code and avoid exception handling.  Useful when compiling older code with a modern C++ compiler. 
	It is also valuable when you are replacing calls to malloc() with new. 
	Example 1: Here is an example of new that uses a try/catch block to monitor for an allocation failure.
#include <iostream>
#include <new>
using namespace std;
	int main(){ int *p;
	    	         try{ p = new int; }	/* allocate memory for int */      
		         catch (bad_alloc xa){  cout << " Allocation failure .\n";
			      	                return 1;  }	for(*p = 0; *p < 10; (*p)++)      cout << *p << " "  ;
delete p; // free the memory
return 0; }
	Here if an allocation failure occurs, it is caught by the catch statement.
	Example 2: Since the previous program is unlikely to fail under any normal circumstance, the following program demonstrates new's exception-throwing capability by forcing on allocation failure. It does this by allocating memory until it is exhausted.

int main(){ double *p;
do{	try{ p = new double[100000]; }		/* this will eventually run out of memory */ 
catch( bad_alloc xa ){ 	cout << " Allocation failure .\n";
return 1;}
}while (p);
return 0;}
	Example 3: Following shows the use of new(nothrow) alternative. It reworks the Example 2 and forces an allocation failure.
int main(){ double *p;
do{	p = new(nothrow) double[100000];  		/* this will eventually run out of memory */ 
if(p) cout << "Allocation ok \n";
else cout << "Allocation error \n";
}while (p);
return 0;}
	When you use the nothrow approach, you must check the pointer returned by new after each allocation request.



*/  
