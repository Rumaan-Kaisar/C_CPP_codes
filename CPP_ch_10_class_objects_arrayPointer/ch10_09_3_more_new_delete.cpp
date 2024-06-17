
/*  ------------    More new, delete :    dynamically allocate array    ------------ 
    
    Dynamically allocate a 1D array : 
        
                p_var = new type[ size ];

        After this statement has executed, "p_var" will point 
            to the start of an array of "size" elements of the type specified. 



    initialization:
        You can give a dynamically allocated object an "initial value" by using this form:
                    p_var = new type ( initial_value );

        It is not possible to initialize an "array" that is dynamically allocated.



    delete:
                delete [] p_var;

        This syntax causes the "compiler" to call the DESTRUCTOR function for "each element" in the array. 
        It does not cause "p_var" to be freed MULTIPLE times. 
        "p_var" is still freed only once.



    --------    Notes    --------
    new automatically allocates enough memory to hold an object of the specified type. 
        You do not need to use sizeof, for example, to compute the number of bytes required.

    new automatically returns a pointer of the specified type. 
        You do not need to use an "explicit type cast".  

        In C, "no type cast is required" when you are assigning the return value of malloc() to a pointer 
            because the "void *" returned by malloc() is automatically converted into a pointer 
            compatible with the type of pointer on the left side of the assignment. 

        However, this is not the case in C++, which requires an "explicit type cast" when you use malloc(). 
        
    
    Both new and delete can be overloaded, 
        enabling you to easily implement your own "custom allocation system". 
    
    It is possible to initialize a dynamically allocated object. 

    You no longer need to include <cstdlib> with your programs.

*/




// ----  rev[14-jun-2024]  ----

/* Example 3 : to allocate an array of integers  */
int *p;
p = new int[5]; 	// allocate room for 5 integers
if(!p) { cout << " Allocation error \n"; return 1; } 	// allocation check
. . . . . . STATEMENTS. . . . . .
delete [] p;




/* Example 4 : to allocate object array named "samp", */
samp *p;
p = new samp[5]; 	// allocate object array named "samp" 
if(!p) { cout << " Allocation error \n"; return 1; } 	// allocation check
. . . . . . STATEMENTS. . . . . .
delete [] p;




