
/*  ----------------    INDEPENDENT REFERENCES    ----------------
    It's not commonly used
    Independent reference is a reference variable that in all effects 
        is simply "another name for another variable". 

    Because references cannot be assigned "new values", 
        an independent reference must be initialized when it is declared.

    There is "little benefit" in this type of reference, 
        but you may see it from time too time in other programs

    An independent reference can refer to a "constant". For example, following is valid.

            const int &ref = 10; 



    ----------------    RULES    ----------------
    RESTRICTIONS on using Reference : There are a number of restrictions that apply to all types of references. 

        [1]	You cannot reference another reference. 
        [2]	You cannot obtain the "ADDRESS" of a reference. 
        [3]	You cannot create "ARRAYS" of references.
        [4]	You cannot reference a "bit-field". 
        [5]	References must be "INITIALIZED" unless they are members of a class, are return values, or are function parameters.
        [6]	Remember, references are similar to pointers, but they are not pointers.
 

    Note:
        Reference PARAMETERS offer several advantages over equivalent pointer

            a.  No longer need to remember to pass the address of an argument. 
                    the address is automatically passed. 

            b.  Reference parameters offer a cleaner, more elegant interface
            
            c.  When an "object" is passed to a function as a reference, "no copy is made". 
                    It eliminate the troubles associated with the "copy of an argument" damaging 
                    something needed elsewhere in the program when its destructor function is called
                (recall change : destructor problem while passing object to a function) .

*/




/* Example 1: Following program contains an independent reference 
                The independent reference "ref" serves as a different name for "x"
                From a practical point of view, "x" and "ref" are equivalent
*/
#include <iostream>

int main(){
    int x;
    int &ref = x;  // create an independent reference

    x = 10;     // these two statements
    ref = 10;   // are functionally equivalent
    ref = 100;

    // this prints the number 100 twice
    std::cout << x << ' ' << ref << "\n";

    return 0;
}




/* Example 2: An independent reference can refer to a constant. */
const int & ref = 10;



