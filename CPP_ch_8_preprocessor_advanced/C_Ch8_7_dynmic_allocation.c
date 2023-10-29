
/* 
    ---------------    Dynamic allocation    ---------------
    Its a process of 'memory allcation' as needed during RUNTIME. 

    This allocated memory can be used for a variety of purposes. 
        Most commonly, memory is allocated by applications that need to take full advantage of 'all the memory (RAM)' in the computer.
        
        Other uses for dynamic allocation include:
            linked lists  
            binary trees.

    Consider the following example: 
        A word processor (say text editor) will want to let the user edit documents that are 'as large as possible'. 
        However, if the word processor uses a 'normal character array', 
            it must fix its size at compile time. 
            So, it the application compiled in computers with the minimum amount memory
                it won't allow other users having pc with more memory to edit larger documents. 

        If memory is ALLOCATED DYNAMICALLY (as needed until memory is exhausted),
            any user may make full use of the memory in the system. 




    ---------------    malloc() and free()    ---------------

    The core of C's dynamic-allocation functions are 
        malloc(), which allocates memory and 
        free(), which releases previously allocated memory. 
        
        Both functions use the header file <STDLIB.H>. Their prototypes are:

                void *malloc(size_t numbytes);
                
                void free(void *ptr);

                numbytes: the number of bytes of memory you wish to allocate.

            malloc() returns a POINTER to the 'start of the allocated piece of memory'. 
                If malloc() cannot fulfill the memory request 
                    (for example, insufficient memory available) it returns a NULL POINTER.

            To free memory, call free() with a POINTER to the 'start the block of memory' (previously allocated using malloc())


    NOTES:
        [1]	HEAP: Memory is allocated from a region, called the heap.
                Although the actual physical layout of memory may differ, conceptually the 'heap' lies between your program and the 'stack'. 
                Since this is a finite area, 'an allocation request can fail' when memory is EXHAUSTED.

        [2]	When a program terminates, all 'allocated memory' is automatically released.

        [3] Overrun: the boundaries of allocated memory can be overrun just like an Array. 



    ---------------    check for a valid malloc-pointer    ---------------
    Be careful not to CRUSH you computer. So check the pointer returned by MALLOC
        You must confirm that a 'call to malloc() is SUCCESSFUL' before you use the pointer it returns.

        If you perform an operation on a 'NULL pointer', 
        You could CRASH your PROGRAM and maybe even the ENTIRE COMPUTER.

        CHECK: The easiest way to check for a valid pointer is shown in this fragment:

                p = malloc(SIZE);
                if(!p) {
                    printf("Allocation Error");
                    exit(1);
                }

*/


/* #############    Finishing Tips    ############# */

//     Go back and skim through each chapter, thinking about how each aspect of C relates to the rest of it. 
//         As you will see, C is a highly integrated language, in which one feature complements another. 
//         The connection between pointers and arrays, for example, is pure elegance.

//     Practice more: C is a language best learned by doing! Continue to write programs in C and to study other programmer's codes. 
    
//     Finally, you now have the necessary foundation in C to allow you to move on to C++, C’s object-oriented extension. 
    



/* ---------------    check for a valid malloc-pointer    --------------- */


// Be careful not to CRUSH you computer.

/* Example 1: You must confirm that a call to malloc() is successful before you use the pointer it returns. 
                If you perform an operation on a null pomter, 
                you could CRASH your PROGRAM and maybe even the ENTIRE COMPUTER.

                The easiest way to check for a valid pointer is shown in this fragment: */

p = malloc(SIZE);
if(!p) {
    printf("Allocation Error");
    exit(1);
}




/* Example 2: The following program allocates '80 bytes' and assigns a 'character pointer' to it. 
                This creates a "DYNAMIC CHARACTER ARRAY".

                It then uses the allocated memory to input a strig using gets().
                Finally, the string is redisplayed and the pointer is freed.

                (actually, all memory is freed when the program ends, there is no ned for free()
                Here we used free() only to demonstrate its use.) */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *p;

    p = malloc(80);
    if(!p) {
        printf("Allocation Failed");
        exit(1);
    }

    // inputting the string
    printf("Enter a string: ");
    gets(p);
    printf(p);

    // freeing allocated memory
    free(p);
    // when program terminated, this memory autometically freed

    return 0;
}




// ##########    check the available memry    ##########

/* Example 3: This program tells you approximately how much free memory is available to your program. 
                The program works by allocating 1000-byte-Long chunks of memory until an allocation request fails. 
                When malloc() returns null, the 'heap' is exhausted. 
                Hence, the value on 'l_g' represents (within 1000 bytes) the amount of free memory available to the program.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *p;
    long l_g;

    l_g = 0;

    // allocate 1000 bytes each-time untill p returns null-pointer
    do {
        p = malloc(1000);
        if(p) l_g += 1000;
    } while(p);

    printf("Approximately %ld bytes of free memory.", l_g);
    
    return 0;
}

// output: Approximately 2017941816 bytes of free memory.




// ----------------    rev    -------------

/* ----------    Buffer and Dynamic allocation    ----------
    dynamic allocation is used to create buffers for file I/O when we are using fread() and, or fwritc(). 
        Often, we only need a buffer for a short period of time, 
        so it makes sense to allocate it when needed and free it when done.  
*/


/* Example 4: The following program shows how dynamic allocation can be used to create a buffer. 
                The program allocates enough space to hold 'ten FLOATING-POINT values'. 

                It then assigns ten random numbers to the allocated memory, 'indexing the pointer as an array'. 
                Next, it 'writes' the values to disk and 'frees the memory'. 
                Finally, it re-allocates memory, reads the file and displays the random numbers. 

                Although there is no need to free and then reallocate 
                    the memory that serves as a file buffer in this short example, 
                    it illustrates the basic idea. 
*/


#include <stdio.h>
#include <stdlib.h >
i nt main(vo id )
{
int i;
double *p;
FILE '"fp;
/ '" get memory * /
p = malloctlO * sizeof(double));
iEl:p) {
printf("Allocation Error");
exit(l) ;
}
/* generate 10 random numbers */
for(i=O; i<10; i++)
p[i] = (double) rand();
if«fp = fopen("myfile", "wb"))==NULL)
printf(MCannot open file.\n")i
exit(l);
}
/* write the entire array in one step */
if(fwrite(p, lO*sizeof(double) , I, fp) != 1) (
printf("Write Error.\n");
exit(l) ;
}
fclose (fp) i
free(p); /'" memory not needed now " I
I '
imagine something transpires here
'f
I~ get memory again */
p = malloc(lO .. sizeof(double»
if(!p) {
print f (M Allocat ion Error");
exit(1) ;
if«fp = fopen("myfile", "rb"))==NULL) (
printf("Cannot open file. \n");
exit(l) ;
}
/* read the entire array in one step */
if{fread(p, lO*sizeof(double) , 1,' fp) != 1)
printf("Read Error.\n");
exit (1);
fclose (fp) ;
THE C PREPROCESSOR AND SOME ADVANCED TOPICS
127 MASTER DYNAMIC ALLOCAnON
/* display the array */
for(i=O; i<10; i++) printf{ft%f" p[ii);
free (p) ;
return 0;
"



// ----------    memory overflow/overrun    ----------
Example 5: Just as array boundaries can be overrun, so can the boundaries of allocated memory. For example, this fragment is syntactically
valid, but wrong.
p = malloc(lO);
for(i=O; i<100; i) plil = i;



Example 1: Compile and run the example programs.



Example 2: Vlritc a program that creates a tenRelernent dynamic integer
array. Next, using pointer arithmetIc or array indexing, c1ssign
the values I through 10 to the integers that wmprisc the arra\'.
Finally, display the values and free the memory.



Example 3: What's wrong \·"ith this fragment?
char "p;
'p = mallocllO);
gets (p) ;




"
/* --------    mastery    -------- */

At this point yoti should be able to answer these qttestions and
perform these exercises:


Example 1: What is the difference between using quotes and angle brackets
\vith the #include directive?


Example 2: Using an #ifdef, show how to conditionally compile this
fragment of code hased upon whether DEBUG is defined or not.
if l ! (j %2)) {
)
print.f("J = %d\n", J);
J = 0;


Example 3:L'smg the tragmcm from ExerCIse 2, show how you can
conditionallv compile the cncie when DEBUG is defined as 1.
(Hint: Use #if).
-I. Hov,' do VOll undefine a macro?


Example 5: \"lhat is __FILE__ and what does it repre!:.f'nt:'


6. What do the # and ## preprocessor operators do:'


Example 7: Write a prugr<lm that sorts the string "this is a test ofqsort".
Display the sorted output.


Example 8: Write a program that dynamically allocates mem(lfY for one
double. Have the program assign that locanon the value ~9.01,
display the value, and then free the memory





"
/* --------    cumul    -------- */

This section checks how well you have integrated the material in
this ch<lptcr with that from "<lrlier ch<lpters.

Example 1: Section 10.1, Example 3, presents .1 computerized card-catalog
program tllat liSt'S an array \)f structures to hold infornlation on
books. Change this program so that only an array of structure

pointers is created, and use dynamically allocated memory to
actually hold the information for each book as it is entered. This
way, less memory is used when information on only a few
books is stored.



Example 2: Show the macro eqUivalent of this function;
char code_it(char c)
(
return -Ci
)
Demonstrate that your macro version works in a program.
,



Example 3: On your own, look over the programs that you have written in
the course of working through this book. Try to find places
where you can;
.. Use conditional compilation.
• Replace a short function with a f~tion.like macro.
.. Replace statically allocated arrays with dynamic arrays.
... Use function pointers.



Example 4: On your own, study the user's manual or online documentation
for your C compiler, paying special attention to the description
of its standard library functions. The C standard library contains
several hundred library functions that can make your
programming tasks easier. Also, Appendix A in this book
discusses some of the most common library functions.



Example 5: Now that you have finished this book, go back and skim through
each chapter, thinking about how each aspect of C relates to the
rest of it. As you will see, C is a highly integrated language, in
which one feature complements another. The connection
between pointers ahd arrays, for example, is pure elegance.



Example 6: C is a language best learned by doing! Continue to write
programs in C and to study other programmers' programs. You
will be surprised at how quickly C will become second nature!



7. Finally, you now have the necessary foundation in C to a1\ow
you to move on to C++;C'sobject-orientedextension. If C++ .
programming is in your future, proceed to Teach Yoursel{C++,
(Berkeley, CA, Osborne/McGraw-Hill). It picks up where this
book leaves off.
