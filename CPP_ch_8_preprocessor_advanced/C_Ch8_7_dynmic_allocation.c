
---------------    Dynamic allocation    ---------------

Dynamic allocation is the process by which memory is allocated as needed during runtime. This allocated memory can be used for a variety of purposes. Most commonly, memory is allocated by applications that need to take full advantage of all the memory in the computer. 
For example, a word processor will want to let the user edit documents that are as large as possible. However, if the word processor uses a normal character array, it must fix its size at compile time. Thus, it would have to be compiled to run in computers with the minimum amount memory not allowing users with more memory to edit larger documents. 
If memory is allocated dynamically (as needed until memory is exhausted), however, any user may make full use of the memory in the system. Other uses for dynamic allocation include linked lists and binary trees.

The core of C’s dynamic-allocation functions are malloc(), which allocates memory. And free(), which releases previously allocated memory. Both functions use the header file STDLIB.H. Their prototypes are
void *malloc(size_t numbytes);
void free(void *ptr);
Here, numbytes is the number of bytes of memory you wish to allocate.
	The malloc() function returns a pointer to the start of the allocated piece of memory. If malloc() cannot fulfill the memory request—for example, there may be insufficient memory available—it returns a null pointer.
	To free memory, call free() with a pointer to the start the block of memory (previously allocated using malloc( )) you wish to free. 
Note
[1]	Memory is allocated from a region called the heap. Although the actual physical layout of memory may differ, conceptually the heap lies between your program and the stack. Since this is a finite area, an allocation request c an fail when memory is exhausted.
[2]	When a program terminates, all allocated memory is automatically released.


Finishing Tips
	Now that you have finished this book, go back and skim through each chapter, thinking about how each aspect of C relates to the rest of it. As you will see, C is a highly integrated language, in which one feature complements another. The connection between pointers and arrays, for example, is pure elegance.
	C is a language best learned by doing! Continue to write programs in C and to study other programmer's programs. You will be surprised at how quickly C will become second nature!
	Finally, you now have the necessary foundation in C to allow you to move on to C++, C’s object-oriented extension. If C++ programming is in your future, proceed to Teach Yourself C++, It picks up where this book leaves off.

