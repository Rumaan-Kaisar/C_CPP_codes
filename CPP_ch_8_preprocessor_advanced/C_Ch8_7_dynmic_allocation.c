
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

*/


/* #############    Finishing Tips    ############# */

//     Go back and skim through each chapter, thinking about how each aspect of C relates to the rest of it. 
//         As you will see, C is a highly integrated language, in which one feature complements another. 
//         The connection between pointers and arrays, for example, is pure elegance.

//     Practice more: C is a language best learned by doing! Continue to write programs in C and to study other programmer's codes. 
    
//     Finally, you now have the necessary foundation in C to allow you to move on to C++, C’s object-oriented extension. 
    

