
/* 
    ---------------    typedef    ---------------

    In C you can create a 'new name' for an EXISTING TYPE (i.e. we can rename char, int, float etc) using typedef.

    The general form of typedef is
                                        typedef old_name new_name;
        This 'new_name' can be used to declare variables. 


        a 'typedef' does not cause the original name to be deactivated. 
            For example, in "Example 1", 'signed char' is still a valid type. 
        
        you can use 'several typedef statements' to create 'many' different, 'new names' for the 'same type'.



    ------------    Use of typedef    ------------
    create portable programs: 
        typedef creates opportunity to modify the variables before compile using just one statement.
            For example, compile the program on computers using 16-bit integers as well as on computers using 32-bit integers, 
            Wwe can use a 'typedef' when compiling the program for the 16-bit machines as follows:
        
                    typedef int myint;
        
                Assuming that you used myint to declare all integer values that you wanted to be 16 bits long (which can be changed later). 
                Then, before compiling the code for a 32-bit computer, you can change  the typedef statement like this:
        
                    typedef short int myint; 	// changing 32 bit to 16 bit

        This works because on computers using 32-bit integers. a short int will be 16 bits long. 
    

    self-documenting code (more meaningful):
        You can use typedef to create a self-documenting code (you can also do meaningful or semantic programming). 
        For example, if you are writing an inventory program, you might use this typedef statement.
        
            typedef double subtotal;

        Now, when anyone reading your program sees a variable declared as subtotal, he or she will know that it is used to hold a subtotal.
*/




/* Example 1: For example., in the following program, 'smallint' is a 'new_name' for a "signed char" and is used to declare i. */
#include <stdio.h>

typedef signed char smallint; 	// renaming the data-type signed char

int main(void) {	
    smallint i; 	// Renamed data-type

    for(i=0; i<10; i++) printf("%d", i);
    
    return 0;
}






/* Example 2: The new name created by one typedef can be used in a subsequent typedef to create another name. */
typedef int height;
typedef height length;  // using one defined-name to define another
typedef length depth;

depth d;

// Here, d is still an integer



