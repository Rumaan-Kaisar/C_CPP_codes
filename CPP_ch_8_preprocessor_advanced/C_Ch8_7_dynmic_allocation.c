
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
#include <stdlib.h>

int main(void) {
    int i;
    double *p;
    FILE *fp;

    // get memory
    p = malloc(10 * sizeof(double));
    if(!p) {
        printf("Allocation Error");
        exit(1);
    }

    // generate 10 random numbers
    for(i=0; i<10; i++) p[i] = (double)rand();

    // open file to write
    if((fp = fopen("arry_file", "wb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    // write the entire array in one step
    if(fwrite(p, 10*sizeof(double) , 1, fp) != 1) {
        printf("Write Error.\n");
        exit(1);
    }

    // close the file and free memory
    fclose(fp);
    free(p); // memory not needed now

    /*
        imagine something transpires here
        .
        .
        .
    */

    // get memory again
    p = malloc(10 * sizeof(double));
    if(!p) {
        printf("Allocation Error");
        exit(1);
    }

    // open for reading
    if((fp = fopen("arry_file", "rb")) == NULL) {
        printf("Cannot open file. \n");
        exit(1);
    }

    // read the entire array in one step, store it again in p
    if(fread(p, 10*sizeof(double), 1, fp) != 1) {
        printf("Read Error.\n");
        exit(1);
    }

    // close the file
    fclose(fp);

    // display the array
    for(i=0; i<10; i++) printf("%f", p[i]);

    free(p); // relese memory

    return 0;
}




// ----------    memory overflow/overrun    ----------
/* Example 5: Just as array boundaries can be overrun, so can the boundaries of allocated memory. 
                For example, this fragment is syntactically valid, but wrong. */
p = malloc(10);
for(i=0; i<100; i) p[i] = i;




/* Example 6: Write a program that creates a ten-element 'DYNAMIC integer array'. 
                Next, using pointer arithmetic or array indexing, assign
                    the values 1 through 10 to the integers that comprise the array.
                
                Finally, display the values and free the memory.
*/
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int *p, i;

    p = malloc(10*sizeof(int));
    if(!p) {
        printf("Allocation Error");
        exit(1);
    }

    for(i=0; i<10; i++) p[i] = i+1;
    for(i=0; i<10; i++) printf("%d", *(p+i));

    free(p);

    return 0;
}




/* Example 7: What's wrong with this fragment? */
char *p;
*p = malloc(10);
gets(p) ;

/* 
    The statement

        *p = malloc(10);

    should be

        p = malloc(10);

    Also, the value returned by malloc( ) is 'not verified' as a VALID POINTER. 
*/




/* Example 8: Write a program that 'dynamically allocates' memory for one DOUBLE.
                Have the program assign that location the value 99.01,
                display the value, and then free the memory. */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double *p;

    p = malloc(sizeof(double));
    if(!p) {
        printf ("Allocation Error");
        exit(1);
    }

    *p = 99.01;
    printf("%f", *p);
    free(p);

    return 0;
}




/* Example 9: Update the "COMPUTERIZED CARD-CATALOG" program that uses an array of structures 
                to hold infornlation on books. Change this program so that 
                only an array of structure pointers is created, and use dynamically allocated memory 
                to actually hold the information for  each book as it is entered.

                This way, less memory is used when information on only a few books is stored. 


   Following is an improved version of the card-catalog program developed previously,
				it stores its information in a disk file called "CATALOG".

				Notice how using a 'structure' makes it easier to organize the information about each book.
				Also notice how the 'entire structure array' is written and read from disk in a 'single operation'.

                When the program begins, have it read the catalog into memory.
                Also, add an option to save the information to disk.

                Card Catalog:
                            1. Enter Books
                            2. Search by author
                            3. Search by Title
                            4. Save catalog
                            5. Quit


                If you choose Enter, have the program repeatedly input the name, author, and publisher of a book.
                    Have this process continue until the user enters a blank line for the name of the book.

                For searches, prompt the user for the specified author or title and
                then, if a match is found, display the rest of the information.

                The program should be capable of storing 100 book info.
*/

/* =-=-=-=-=-=-=-=-=-=-=            An electronic card catalog             =-=-=-=-=-=-=-=-=-=-= */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int menu(void);
void enter(void);
void load(void);
void save(void);

void display(int i);
void author_search(void);
void title_search(void);


struct catalog{
	char name[80]; 		// author name
	char title[80];		// title
	char pub[80];  		// publisher
	unsigned date; 		// copyright date
	unsigned char ed; 	// edition
} *cat[MAX];
// notice how the array of "catalog structure" is created
// NEW: Also notice that this declares a "POINTER ARRAY" 



int top = 0;    // last location used


int main(void){
    int choice;

    load();  // open to read in catalog

    do{
        choice = menu();
        switch(choice){
            case 1: enter(); // enter books
                break;
            case 2: author_search(); // search by author
                break;
            case 3: title_search(); // search by, title
                break;
            case 4: save();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice, select a choice
int menu(void){
    int i;
    char str[80];

    printf("Card Catalog:\n");
    printf("1. Enter Books\n");
    printf("2. Search by author\n");
    printf("3. Search by Title\n");
    printf("4. Save catalog\n");
    printf("5. Quit\n");

    do{
        printf("Choose your selection:\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


// Following codes are modified to access structure members
    // Enter books into Database (modified code 1 )
    // Memory allocation applied
void enter(void){
    int i;
	char temp[80];

    for(i=top; i<MAX; i++) {
        // allocate memory for book info
        cat[i] = malloc(sizeof(struct catalog));
        if(!cat[i]) {
            printf("Out of memory.\n");
            return; // notice "return" is used instead of exit(1), to avoid sudden termination
        }

        // notice how structre members are accessed
            // since pointer-array is used, -> applied instead of '.'
        printf("Enter author name (ENTER to quit): ");
        gets(cat[i]->name);
        if(!*cat[i]->name) break;

        printf("Enter title: ");
        gets(cat[i]->title);

        printf("Enter publisher: ");
        gets(cat[i]->pub);

		printf("Enter copyright date: ");
		gets(temp);
		cat[i]->date = (unsigned) atoi(temp);

		printf("Enter edition: ");
		gets(temp);
		cat[i]->ed = (unsigned char) atoi(temp);
    }

    top = i;
}



// Search by author (modified code 2 )
void author_search(void){
    char name[80];
    int i, found;

    printf("Name: ");
    gets(name);

    found= 0;

    // -> applied instead of '.' due to pointer-array
    for(i=0; i<top; i++){
        if(!strcmp(name, cat[i]->name)){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Search by TITLE	(modified code 3 )
void title_search(void){
    char title[80];
    int i, found;

    printf("Title: ");
    gets(title);

    found= 0;

    // -> applied instead of '.' due to pointer-array
    for(i=0; i<top; i++){
        if(!strcmp(title, cat[i]->title)){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Display catalog entry. (modified code 4 )
// -> applied instead of '.' due to pointer-array
void display(int i){
    printf("%s\n", cat[i]->title);
    printf("By %s\n", cat[i]->name);
    printf("Published by %s \n", cat[i]->pub);
	printf("Copyright: %u, %u edition\n", cat[i]->date, cat[i]->ed);
}


// Load the catalog file (modified code 5 )
void load(void){
    FILE *fp;
    int i;

    if((fp = fopen("catalog2","rb"))==NULL){
        printf("Catalog file not on disk\n");
        // exit(1); we don't use it because we won't terminate the program
        return; // we use "return" to continue the "main" function
    }

    // read count: with ERR cheking
	if(fread(&top, sizeof top, 1, fp) != 1){
		printf("Error reading count.\n");
		exit(1);
	}

    // Memory allocation applied for each
    for(i=0; i<top; i++) {
        cat[i] = malloc(sizeof(struct catalog));
        if(!cat[i]) {
            printf("Out of memory.\n");
            top = i-1;
            break;
        }
        // READ DATA: i.e array of catalog-structures,
            // "struct" keyward not necessary for "array of stucture", 
                // but needed for each element of pointer-array
        if(fread(cat[i], sizeof(struct catalog), 1, fp) != 1){
            printf("Error reading catalog DATA.\n");
            exit(1);
        }
    }


    fclose(fp);
}


// save the catalog file
void save(void){
    FILE *fp;
    int i;

    // open for writing
    if((fp = fopen("catalog2","wb"))==NULL){
        printf("Cannot open catalog file\n");
        exit(1);
    }

    // write count: with ERR cheking
	if(fwrite(&top, sizeof top, 1, fp) != 1){
		printf("Error writing count.\n");
		exit(1);
	}

	// WRITE DATA: i.e array of catalog-structures,
		// "struct" keyward not necessary for "array of stucture"
    for(i=0; i<top; i++) {
        if(fwrite(cat[i], sizeof(struct catalog), 1, fp) != 1){
            printf("Error writing catalog DATA.\n");
            exit(1);
        }    
    }


    fclose(fp);
}




/* #############    Finishing Tips    ############# */

//     Go back and skim through each chapter, thinking about how each aspect of C relates to the rest of it. 
//         As you will see, C is a highly integrated language, in which one feature complements another. 
//         The connection between pointers and arrays, for example, is pure elegance.


//     Practice more: C is a language best learned by doing! Continue to write programs in C and to study other programmer's codes.


// The previous programs that we worked:
        // we can use "conditionmal compilation"
        // Replace a short function with a "function-like macro"
        // Replace 'statically allocated' arrays with "dynamic arrays"
        // Use "function pointers".
    

// Learn STL (standard library functions):
        // study the user's manual or online documentation for your C/C++ compiler, Learn of its standard library functions. 
        // The C standard library contains several hundred library functions that can make your programming tasks easier.
        // Also you can list the most common library functions.


//     Finally, you now have the necessary foundation in C to allow you to move on to C++, C’s object-oriented extension. 



