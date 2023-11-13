
/* -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-         DYNAMIC ALLOCATION        -=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-

DYNAMIC ALLOCATION
*/
Two primary ways a C program can store information in the main memory of the computer. The first uses global and local variables—including arrays and structures. The second way information can be stored is with C’s dynamic allocation system. In this method, storage for information is allocated from the free memory area (called the heap) as it is needed. Dynamic allocation system is in stdlib.h, here the type size_t is defined. This type is used extensively by the allocation functions and is essentially the equivalent of unsigned.
Header Function	Description       #include <stdlib.h>    must be  included before use	Example
#include <stdlib.h>
void *calloc(size_t num, size_t size);	calloc() returns a pointer to the allocated memory. Allocated memory is equal to num *size. i.e, calloc() allocates sufficient memory for an array of num objects of size size and returns a pointer to the first byte of the allocated region. A null pointer is returned for not enough memory.	
p = calloc(1OO, sizeof(float));

void free( void *ptr)	free() de-allocates the memory pointed to by ptr. It is called only with a pointer that was previously allocated using malloc() or calloc() etc. Invalid pointer destroy the memory management mechanism and cause a system crash.	for(i=0; i<100; i++) 
free(str[i]);
void *malloc(size_t size);	malloc() returns a pointer to the first byte of a region of memory of size size that has been allocated from the heap. (Remember, the heap is a region of free memory managed by C‘s dynamic allocation subsystem.) A null pointer is returned if there is insufficient memory in the heap.  Always verify that the return value is not a null pointer before attempting to use it. null pointer will usually result in a system crash.	if((p = malloc(sizeof(struct addr)))==NULL)
    {
          printf("Allocation error - aborting.\n");
          exit(0); 
     }
void *realloc(void *ptrt size_t size);	realloc() changes the size of the allocated memory pointed to by ptr to that specified by size. size may greater or less than the original. A pointer to the memory block is returned since it may be necessary for realloc() to move the block to increase its size. Contents of the old block are copied into the new block—no information is lost. A null pointer is returned if there is not enough free memory in the heap. Verify the success of real1oc().	char *p;     p = malloc(17);
if(!p) {   printf("Alloc error");   exit(1);
            }
strcpy(p, "this is 16 chars');
p = realloc(p,18);

