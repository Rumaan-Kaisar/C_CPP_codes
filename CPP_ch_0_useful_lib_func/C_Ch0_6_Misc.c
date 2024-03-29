
// -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-         Miscellaneous Functions        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

#include <stdlib.h>    // must be  included before use	Example

#include <stdlib.h>


// --------    TERMINATOR functions    --------

void abort(void);
/* abort() causes 'immediate termination of a program'. 
    Whether it closes any open files is defined by the implementation, but generally it won’t.	

    Example: In this program, if the user enters 'A', the program will terminate.

    #include <stdlib.h>
    #include <conio.h>

    int main(void) {
            for(;;) if(getche()=='A') abort(); 

        return 0;
    }
*/


void exit(int status);
/* exit() causes "immediate normal termination" of a program. 

    The value of 'status' is passed to the calling process, (usually the operating system, if the environment supports). 
        By convention, if  the value of "status = 0", NORMAL program TERMINATION is assumed. 
        A 'NONZERO' value may be used to indicate an ERROR. 
        
        You may also use the "predefined macros": EXIT_SUCCESS and EXIT_FAILURE as arguments to exit().	

    eg:
        if(ch=='Q') exit(0);
*/




// --------    Absolute value functions    --------
int abs(int num);
/* abs()  returns the absolute value of the integer num.	

    Eg: 
        gets(num);
        return abs(atoi(num)); 
*/


long labs(long num);
/* labs() returns the absolute value of the long int num.	g

    Eg: 
        ets(num); 
        eturn labs(atol(num)); 
*/




// --------    convertion functions    --------
double atof(const char *str);
/* atof() converts the STRING pointed to by 'str' into a DOUBLE value. 
    "str" must contain a 'valid float number'. Otherwise 0 is returned.

    The number may be 'terminated by any character' that cannot be part of a valid floating-point number. 
        This includes 'whitespace' characters, 'punctuation' (other than periods), and characters other than 'E' or 'e'. 
    
    Eg:        
        Thus, atof(100.00HELLO) returns  100.00.
        printf("%f", atof(num));
*/


int atoi(const char *str);
/* atoi() converts the STRING pointed to by 'str' into an INT value. 
    "str" must contain a valid integer number. Otherwise 0 is returned.
    
    The number may be terminated by any character that cannot be part of a integer number. 
        This includes 'whitespace' characters, 'punctuation', and other characters. 
    
    Eg: 
        Thus, atoi(123.23) returns 123 and 0.23 ignored.	
        printf("%d", atoi(num));
*/


long atol(const char *str);
/* atol() converts the STRING pointed to by 'str' into an LONG INT value. 
    "str" must contain a valid long integer number. Otherwise 0 is returned.
    
    The number may be terminated by any character that cannot be part of an integer number.
        This includes 'whitespace' characters, 'punctuation', and other characters. 
    
    Eg: 
        Thus, atol(123.23) returns 123 and 0.23 ignored.	
        printf("%ld", atol(num));
*/




// --------    Random numbers    --------
int rand(void);
/* rand() generates a 'sequence' of pseudo-random numbers. 
    Each time it is called, an "integer" between '0 and RAND_MAX' is returned. 
        RAND_MAX is defined in STDLIB.H. 
        The ANSI standard stipulates that the macro RAND_MAX will have a value of at least 32,767.

    Eg: This program displays ten pseudo-random numbers.

        #include <stdlib.h>
        #include <stdio.h>

        int main(void) {
            int i;
            for(i=0; i<10; i++) printf("%d ", rand());
        }
*/


void srand(unsigned seed);
/* srand() function is used to set a 'starting point' for 
    the 'sequence generated by rand()', which returns pseudo-random-numbers. 

    Generally srand() is used to allow multiple program runs to use 'different sequences of pseudo-random numbers'.

    Eg: This program uses the SYSTEM TIME to randomly initialize the rand() function using srand():

        #include <stdio.h>
        #include <stdlib.h>
        #include <time.h>

        // Seed rand() with the system time and display the first 100 numbers.
        int main(void) {
            int i, utime;
            long Ltime;

            // get the current calendar time
            Ltime = time(NULL);
            utime = (unsigned int) Ltime/2;
            srand(utime);

            for(i=0; i<10; i++) printf("%d\n", rand());

            return 0;
        }
*/




// --------    DSA functions    --------
// qsort() : QuickSort
void qsort(
            void *base, 
            size_t num, 
            size_t size, 
            int(*compare)(const void*, const void*)
);

/* qsort() function uses a FUNCTION POINTER during its utilaztion.

    The qsort() function is a 'generic sort routine' that can sort any type of 
        'singly dimensioned array', using the "Quicksort algorithm (developed by C.A.R. Hoare)".
        Upon termination, the array will be sorted.
        The array is sorted in ASCENDING ORDER, with the 'lowest address' containing the lowest element.

    base:  is a pointer to the first element in the 'array to be sorted'. 
    number: number of elements in the array
    size:   size of each element of the array (in bytes)
    (Remember, size _t is a data-type defined by the C compiler in STDLIB.Hand is loosely the same as 'unsigned'.)  

    Notice the final parameter is a "function-pointer": 
        
                int (*compare)(const void *a, const void *b)

        This pointer to a function (which you create) compares two elements of the array 
            and returns the following results:

                *a < *b returns a negative value
                *a == *b returns a zero
                *a > *b returns a positive value

    The qsort() function has no return value. 
    It uses the <STDLIB.H> header file.


    Eg: This program sorts a list of integers and displays the result

        #include <stdio.h>
        #include <stdlib.h>

        int comp(const void *i, const void *j);

        int num[10] = {1, 3, 6, 5, 8, 7, 9, 6, 2, 0};

        int main(void) {
            int i;

            // load 100 random numbers from the 'random number list' to sort[100]
            printf("Original array: \n");
            for(i=0; i<10; i++) printf("%d ", num[i]);
            printf ("\n");

            // sorting
            qsort(num, 10, sizeof(int), comp);

            // print the result
            printf("Sorted array: ");
            for(i=0; i<10; i++) printf("%d ", num[i]);

            return 0;
        }

        // comparison function: compare the integers
        int comp(const void *i, const void *j) {
            return *(int *)i - *(int *)j;
        }	 
*/	




// bscarch() : BinarySearch
void *bsearch(
    const void *key, 
    const void *array, 
    size_t number, 
    size_t size, 
    int(*comp)(const void *a, const void *b)
);

/* Another of C's standard library functions is called bscarch().
    
    This function searches a SORTED ARRAY, given a 'KEY'. 

    It returns a pointer to the 'first entry' in the "array" that matches the KEY,
        if no match is found, a null pointer is returned

    All the parameters to bsearcb() are the same as for qsort() except the first, 
        which is a 'pointer to key', the object being sought. 
    
    The comp() function operates the same for bscarch() as it does for qsort().


    Eg: This program reads characters entered at the keyboard and
        determines whether they belong to the alphabet.

        #include <stdlib.h>
        #include <ctype.h>
        #include <stdio.h>

        char *alphabets = "abcdefghijklmnopqrstuvwxyz";
        int comp (const void *ch, const void *s);

        int main(void) {
            char ch;
            char *p;

            do {
                printf("Enter a character: ");
                scanf("%c%*c", &ch);    // '%*c' is used for loop & carrige return
                ch = tolower(ch);

                p = bsearch(&ch, alphabets, 26, 1, comp);
                if(p) printf("is in alphabet.\n");
                else printf("is not in alphabet.\n");
            } while (p) ;

            return 0;
        }


        // compare two characters
        int comp(const void *ch, const void *s) {
            return *(char *)ch - *(char *)s;
        }
*/





// --------    <setjmp.h> : JUMP between FUNCTIONS   --------

#include <setjmp.h>    // must be  included before use	

void longjmp(jmp_buf envbuf, int  val);
int  setjmp(jmp_buf envbuf);

/* 
    longjmp() causes program execution to resume at the point of the last call to setjmp(). 
        These two functions are the way ANSI C provides for a "JUMP BETWEEN FUNCTIONS". 
        Notice that the header <setjmp.h> is required.

        The longjmp() function operates by resetting the 'STACK' as described in 'envbuf', 
            which must have been set by a prior call to setjmp(). 
            This causes 'program execution 'to RESUME at the 'statement following the setjmp() invocation'
                — the computer is "tricked" into thinking that it never left the function that called setjmp(). 
                    (the longjmp() function "WARPS" across time and (memory) space to a previous point in your program, 
                        without having to perform the normal function-return process.)

        The buffer "envbuf" is of type "jmp_buf", which is defined in the header <SETJMP.H>. 
            The buffer must have been set through a call to setjmp() prior to calling longjmp().

        The value of "val" becomes the 'return value' of setjmp() and may be interrogated to determine where the long jump came from. 
            The only value not allowed is 0.

        It is important to understand that the longjmp() function "must be called before the function that called setjmp() returns". 
            If not, the result is technically UNDEFINED. In actuality, a CRASH will almost certainly occur.

        By far the most common use of longjmp() is to "return from a deeply nested set of routines" when a catastrophic error occurs.



    setjmp() saves the 'contents' of the 'system stack' in the buffer 'envbuf' for later use by longjmp(). 
        setjmp() returns 0 upon invocation. 
        The buffer "envbuf" is of type 'jmp_buf', which is defined in the header <setjmp.h>.
        However, longjmp() passes an argument to setjmp() when it executes, 
            and it is this value (always nonzero) that will appear to be the value of setjmp() after a call to longjmp(). 


    Eg: This program prints '1 2 3':

        #include <setjmp.h>
        #include <stdio.h>

        void f2(void);

        jmp_buf ebuf;

        int main(void) {
            char first=1;
            int i;

            printf("1 ");
            i = setjmp(ebuf);
            if(first) {
                first = !first;
                f2( );
                printf("this will not be printed");
            }

            printf("%d", i);

            return 0;
        }


        void f2(void) {
            printf("2 ");
            longjmp(ebuf, 3);
        }

*/



