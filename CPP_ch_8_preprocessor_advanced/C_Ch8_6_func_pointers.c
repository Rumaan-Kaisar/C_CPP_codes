
/*
    --------------    Function Pointers    --------------
    A FUNCTION POINTER is a 'variable' that contains the 'address of the entry point' to a function.


    how "Function Pointers" works: 

        COMPILER creates an 'entry point' for each function in the program during COMPILATION 
            The "ENTRY POINT" is the ADDRESS to which 'execution transfers' when a function is called. 
            Since the ENTRY POINT has an ADDRESS, it is possible to have a pointer variable point to it. 
        
        Once you have a "POINTER TO A FUNCTION", it is possible to actually CALL that FUNCTION using the POINTER. 


    To create a variable that can point to a function, 
        declare the pointer as having the 'same type' as the 'return type of the function', followed by any parameters. 

            For example, the following declares 'p' as a pointer to a function that 'returns an integer' and has two integer PARAMETERS, x and y;

                int (*p) (int x, int y);

    NOTE:
        The PARENTHESES surrounding *p are NECESSARY because of C's precedence rules. 




    ASSIGN the ADDRESS of a function to a function pointer:
        Simply use its 'NAME without any parentheses'.  For example, assuming that sum() has the prototype

                int sum(int a, int b);

        the following assignment statement is correct:

                p = sum;

            Once this has been done, you can call sum() 'indirectly through p' using a statement like:

                result = (*p) (10, 20);

            Again because of C's precedence rules the Parentheses are necessary around p.


        Actually, you can also just use p directly, like this:

                result = p(10, 20);
            
        NOTE:
            (*p) form inform anyone that reading your codes that a function pointer is being used 
                to call a function indirectly, instead of calling a function named p. 
*/



/* Example 1: This program fills in the details and demonstrates the function pointer. 
                The program calls sum() indirectly using "p", and displays the result.
*/
#include <stdio.h>

int sum(int a, int b);

int main(void) {
    int (*p) (int x, int y);    // function pointer
    int result;

    p = sum; // get address of sun()
    result = (*p) (10, 20);

    printf("%d", result);

    return 0;
}

int sum(int a, int b){
    return a+b;
}




/* --------------    function pointer array    -------------- 
    Using a "function-pointer array" to call the appropriate function 
        is more efficient than using a switch() statement.
*/

/* Example 2: The following program will give you a taste of full power of "function pointer"
                One important uses of function pointers occurs when a "FUNCTION-POINTER ARRAY" is created.
                    Each element in the array can point to a different function.
                    To call any specific function, the array is simply indexed.

                'Function-pointer arrays' are typically used when writing systems software, such as
                        a.  compilers,
                        b.  assemblers, and
                        c.  interpreters.

                Like the program in Example 1, this program prompts the user for two numbers.
                    Next, it asks the user to enter the 'number of the operation to perform'.
                    This number is then used to index the function-pointer array to execute the proper function.
                    Finally, the result is displayed.
*/

#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int (*p[4]) (int x, int y);     // function-pointer array

int main (void) {
    int result;
    int i, j, op;

    p[0] = sum;        // get address of sum()
    p[1] = subtract;   // get address of subtract()
    p[2] = mul;        // get address of mul()
    p[3] = div;        // get address of div()

    printf("Enter two numbers: ");
    scanf("%d%d", &i, &j);

    printf("O: Add, 1: Subtract, 2: Multiply, 3: Oivide\n");

    do {
        printf("Enter number of operation: ");
        scanf("%d", &op);
    } while(op<0 || op>3);

    result = (*p[op]) (i, j);
    printf("%d", result);

    return 0;
}


int sum(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int div(int a, int b) {
    if(b) return a/b;
    else return 0;
}




/* Example 3: function-pointer arrays can be initialized, just like any other array. 
                The following version of above program shows this. */

#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);

// Initialized function-pointer array. 
// Get address of all: sum(), subtract(), mul(), div()
int (*p[4]) (int x, int y) = { sum, subtract, mul, div };

int main (void) {
    int result;
    int i, j, op;

    printf("Enter two numbers: ");
    scanf("%d%d", &i, &j);

    printf("O: Add, 1: Subtract, 2: Multiply, 3: Divide\n");

    do {
        printf("Enter number of operation: ");
        scanf("%d", &op);
    } while(op<0 || op>3);

    result = (*p[op]) (i, j);
    printf("%d", result);

    return 0;
}


int sum(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int div(int a, int b) {
    if(b) return a/b;
    else return 0;
}




/*  ------------    qsort() : QuickSort    ------------ 
    qsort() function uses a FUNCTION POINTER during its utilaztion.

    The qsort() function is a generic sort routine that can sort any type of 
    'singly dimensioned array', using the "Quicksort algorithm".
    Its prototype is: 
*/

void qsort(void *array, size_t number, size_t size, int (*comp)(const void *a, const void *b));

/* 
    array:  is a pointer to the first element in the 'array to be sorted'. 
    number: number of elements in the array
    size:   size of each element of the array
    (Remember, size _t is a data-type defined by the C compiler and is loosely the same as unsigned.)  

    Notice the final parameter is a "function-pointer": 
        
                int (*comp)(const void *a, const void *b)

        This pointer to a function (which you create) compares two elements of the array 
            and returns the following results:

    *a < *b returns a negative value
    *a == *b returns a zero
    *a > *b returns a positive value

    The qsort() function has no return value. 
    It uses the <STDLIB.H> header file.
*/




/* Example 4: Load a 100-element integer array with random numbers, sorts it, and displays the sorted form.
                Notice the necessary type casts within the comp() function, */
#include <stdio.h>
#include <stdlib.h>

int comp(const void *i, const void *j);

int main(void) {
    int sort[100], i;

    // load 100 random numbers from the 'random number list' to sort[100]
    for(i=0; i<100; i++) sort[i] = rand();

    qsort(sort, 100, sizeof(int), comp);

    // print the result
    for(i=0; i<100; i++) printf("%d\n",sort[i]);

    return 0;
}

// comparison function
int comp(const void *i, const void *j) {
    return *(int*)i - *(int*)j;
}





/*  ------------    bscarch() : BinarySearch    ------------ 
    Another of C's standard library functions is called bscarch().
    
    This function searches a SORTED ARRAY, given a 'KEY'. 

    It returns a pointer to the 'first entry' in the array that matches the KEY,
        if no match is found, a null pointer is returned, its prototype is:
*/
    void *bsearch(const void *key, const void *array, size_t number, size_t size, int(*comp)(const void *a, const void *b));
/*
    All the parameters to bsearcb() are the same as for qsort() except the first, 
        which is a 'pointer to key', the object being sought. 
    
    The comp() function operates the same for bscarch() as it does for qsort().
*/




/* Example 5: Modify the program in 'Example 4' (Quick-sort) so that after the array is sorted, 
                the user is prompted to enter a number. 
                Next, USili bsearch() search the sorted array and report if a match is found.
*/



/* Example 6: Add a fume ion called modulus() to the second version of the previous arithmetic program (Example 3). 
                Have the function return the result of 'a%b'.
                Add this option to the menu and fully integrate it into the program. */



