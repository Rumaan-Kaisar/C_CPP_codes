
10.11 Memory allocation/release operators :  new, delete
To allocate memory and to free the allocated memory we use the C's dynamic allocation functions malloc() and free() respectively (applicable in C++ also). These are the standard. 
Memory allocation/release operators :  C++ provides safer and more convenient operators (not functions): new and release to allocate and free (delete) memory respectively. These operators take these general forms:
p_var = new type ;
delete p_var ;
Here type is the type specifier of the object for which you want to allocate memory and p_var is a pointer to that type. 
	new is an operator that returns a pointer to dynamically allocated memory that is large enough to hold an object of type type. 
	In Standard C++, the default behavior of new is to generate an exception when it cannot satisfy an allocation request. If this exception is not handled by your program, your program will be terminated. (Exceptions and exception handling are described later; loosely, an exception is a run-time error that can be managed in a structured fashion.)
	delete releases that memory when it is no longer needed. delete can be called only with an invalid pointer, the allocation system will be destroyed, possibly crashing your program.
	If there is insufficient available memory to fill an allocation request, one of two actions will occur. Either new will return a null pointer or it will generate an exception. 

 
Example: // A simple example of new and delete .
# include <iostream >
using namespace std;
int main() {int *p;
p = new int; /* allocate room for an integer */ 
if(!p) {cout << "Allocation error \n";
return 1;}

*p = 100;
cout << "Here is integer at p:" << *p << "\n";
delete p; /* release memory */ 
return 0;}

 
	Initializing dynamic variable : Dynamically allocated objects can be given initial values. We can give a dynamically allocated object an initial value by using this form of the new statement:
p_var = new type( initial_value );

Example 1: 	class samp { int i, j;
public :
samp(int a, int b) { i=a; j=b; }
int get_product() { return i*j; } };
int main() { samp *p;
p = new samp(6, 5); 	/* allocate object with initialization */ 
if(!p) { cout << " Allocation error \n"; return 1; } 	/*allocation check*/
delete p;	 /* release memory */
return 0; }

Example 2: To initialize an integer variable,
p = new int(9); 	/* give initial value of 9*/ 
if(!p) { cout << " Allocation error \n"; return 1; }	/*always check if allocation is successful*/
. . . . . . STATEMENTS. . . . . .
delete p; 		/* release memory */ 

