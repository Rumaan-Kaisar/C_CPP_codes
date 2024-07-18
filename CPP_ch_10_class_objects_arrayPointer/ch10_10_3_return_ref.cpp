
/*  ----------------    returning REFERENCES    ----------------
    A function can return a reference

    Returning a reference can be very useful when you are 
        "overloading" certain types of operators. (discussed  in next chapter)

    However, it also can be employed to allow a function 
        to be used on the "left side of an assignment" statement. 

*/


// A simple example of a function returning a reference .


Here function f() is declared as returning a reference to an integer. Inside the body of the
function, the statement
return x;
does not return the value of the global variable x, but rather, it automatically returns x’s
address (int the form of a reference). Thus, inside main(), the statement
f() = 100;
puts the value 100 into x because f() has returned a reference to it.
To review, function f() returns a reference. Thus when f() is used on the left side of the
assignment statement, it is this reference, returned by f(), that is being assigned to. Since
f() returns a reference to x (in this example), it is x that receives the value 100.
2.

/* Example 1 : here is a very simple program that contains a function that "returns a reference" */

#include <iostream >

int &f(); // function that return a reference
int x;  // without global variable  returning reference is meaningless


int main(){ 
    f() = 100; // assign 100 to reference returned by f()

    std::cout << x << "\n";
    
    return 0; 
}


int &f() {		 // Return an int reference
return x; } 	// returns a reference to x


int main ()

{
f() = 100; // assign 100 to reference returned by f()
cout << x << "\n";
return 0;
}
// Return an int reference
int &f()
{
return x; // returns a reference to x
}

	Here function f() returns a reference. So, f() is declared as returning a reference to an integer. 
	Inside the body of the function, the statement "  return x;  "  does not return the value of the global variable x, but rather, it automatically returns x's address (int the form of a reference). 
	When f() is used on the left side of the assignment statement, it is this reference, returned by f(), that is being assigned to.  Thus, inside main(), the statement  "  f() = 100;  " puts the value 100 into x because f() has returned a reference to x. thus x recives the value 100.
	Be careful on not go out of scope. For example, here the reference returned by f() is useless:
int &f() {	int x;  	/* x is now a local variable */ 
return x; }  	/* returns a reference to x */ 
In this case, x is now local to f() and will go out of scope when f() returns. This effectively means that the reference returned by f() is useless.
	Example 2 : One very good use of returning a reference is found when a bounded array type is created. In C++, you can create an array class that performs automatic bounds checking. An array class contains two core functions-one that stores information into the array and one that retrieves information. These functions can check, at run time, that the array boundaries are not overrun. The following program implements a bounds-checking array for characters:
 

// A simple bounded array example .
# include <iostream >
# include <cstdlib >
using namespace std;
class array{	int size ;
char *p;
public:
 	array(int num); /* constructor */
~array(){delete [] p;} /* destructor */
char &put(int i);
char get(int i);	};

array :: array(int num)  /* constructor define */
{p = new char [num];	          /* array declaration */
if(!p){ cout << "Allocation error \n";
exit(1) ; } 		/* allocation check */
size = num ; }	/* array size */

/* Put something into the array .*/ 
char &array :: put(int i)  /* &f() define */
{if(i<0 || i>=size ){
cout << " Bounds error !!!\ n";
exit(1);}
return p[i];} /* return reference to p[i]*/ 




/* Get something from the array.*/ 
char array :: get(int i)
{
if(i <0 || i >= size ){
cout << " Bounds error !!!\ n";
exit(1) ; }
return p[i];
}

int main() {
array a(10) ;
a.put (3) = 'X';
a.put (2) = 'R';
cout << a.get (3) << a.get (2) ;
cout << "\n";

/* now generate run - time boundary error */ 
a.put (11) = '!';
return 0;
} 

	Notice that the put() function returns a reference to the array element specified by parameter i. This reference can then be used on the left side of an assignment statement to store something in the array-if the index specified by i is not out of bounds. 
	The reverse is get(), which returns the value stored at the specified index if that index is within range.
	This approach to maintaining an array is sometimes referred to as a safe array. 
	The array is allocated dynamically by the use of new. This allows arrays of differing length to be declared.
	If you need to have array boundaries verified at run time, this is one way to do it. However, remember that bounds checking slows access to the array. So use it when it really needed.
