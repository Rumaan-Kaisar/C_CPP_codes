
/*  ----------------    returning REFERENCES    ----------------
    A function can return a reference

    Returning a reference can be very useful when you are 
        "overloading" certain types of operators. (discussed  in next chapter)

    However, it also can be employed to allow a function 
        to be used on the "left side of an assignment" statement. 

    A "reference returned by a function" cannot be assigned to a POINTER.
*/



/* Example 1 : here is a very simple program that contains a function that "returns a reference" */

#include <iostream>

int &f(); // function that return a reference
int x;  // without global variable  returning reference is meaningless


int main(){ 
    f() = 100; // assign 100 to reference returned by f()

    std::cout << x << "\n";
    
    return 0; 
}

// Return an int reference
int &f() { return x; } 	// returns a reference to x


/*  --------    f() returns a reference:    -------- 
    So, f() is declared as returning a reference to an integer. 

    inside f() the statement "return x;"  does not return the "value of the global variable x", 
        but rather, it automatically returns "x's address" (int the form of a reference). 

    When f() is used on the "left" side of the assignment statement, 
        it is this reference, returned by f(), that is being assigned to.  
        
        Thus, inside main(), the statement  " f() = 100; " puts the value 100 into x 
        because f() has returned a reference to x. 
        thus x recives the value 100.



    ----   don't lose the SCOPE   ----
    Be careful on not go "out of scope", that's why we used "global x"
    For example, here the reference returned by f() is useless:

            int &f() {	
                int x;      // x is now a local variable
                return x;   // returns a reference to x
            }  	

    In this case, "x is now local to f()" and will go out of scope when f() returns. 
    This effectively means that the reference returned by f() is useless.

*/




// ------------    bounded array    ------------

/* Example 2 : One very good use of returning a reference is found when a "BOUNDED array type" is created. 

                In C++, you can create an array class that performs "automatic bounds checking". 

                An array class contains two core functions
                    - one that stores information into the array and 
                    - one that retrieves information. 

                These functions can check, at "run-time", that the array boundaries are NOT OVERRUN. 

                The following program implements a bounds-checking array for characters.
*/

#include <iostream>
#include <cstdlib>

class array{
        int size;
        char *p;
    public:
 	    array(int num);     // constructor
        ~array(){ delete [] p; }      // destructor, frees allocated memory
        char &put(int i);
        char get(int i);	
};

// constructor definition
array :: array(int num){
    p = new char[num];      // array declaration. Dynamically allocate a 1D array
    
    // allocation check
    if(!p){ 
        std::cout << "Allocation error \n";
        exit(1);
    } 		
    size = num;     // array size
}


// Put something into the array
// &f()-like referance returning
char &array :: put(int i) {
    if(i<0 || i>=size ){
        std::cout << " Bounds error !!!\ n";
        exit(1);
    }
    return p[i];    // return reference to p[i]
}



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
