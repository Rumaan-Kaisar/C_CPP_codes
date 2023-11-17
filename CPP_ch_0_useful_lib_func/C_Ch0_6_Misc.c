
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
int rand(void);	rand() generates a sequence of pseudo-random numbers. Each time it is called, an integer between 0 and RAND_MAX is returned. RAND_MAX is defined in STDLIB.H. The ANSI standard stipulates that the macro RAND_MAX will have a value of at least 32,767.	printf("%d", rand());


void srand(unsigned seed);	srand() function is used to set a starting point for the sequence generated by rand(), which returns pseudo random numbers. Generally srand() is used to allow multiple program runs to use different sequences of pseudo-random numbers. Eg: randomly initialize the rand() using srand() 	int i, utm; long ltime;
ltime = time(NULL); 
utm = (unsigned int) ltime/2;  srand(utime);
for(i=0; i<10; i + +) printf("%d ", rand());





// --------    DSA functions    --------
void qsort(void *base, size_t num, size_t size,
        int(*compare)(const void*, const void*));

Function pointed to by compare is used to compare two elements in the array. It must return the values:	qsort() function sorts the array pointed to by base using a Quicksort (developed by C.A.R. Hoare). The Quicksort is generally considered the best general-purpose sorting algorithm. Upon termination, the array will be sorted. The number of elements in the array is specified by num and the size (in bytes) of each element is described by size. (The size_t type is defined in STDLIB.H and is equivalent of unsigned.) . The array is sorted in ascending order, with the lowest address containing the lowest element.	int comp(const void *i, const void *j)
int num[5]= {8, 7, 6, 2, 0};
int main(void){
  int i;
  qsort(num, 5, sizeof(int), comp); 
  printf("Sorted array: ");
  for(i=0; i<10; i++) printf("%d ", num[i]); 
return 0;}
// compare the integers
int comp(const void *i, const void *j){
return *(int *)i – *(int *)j;     }
-ve : arg1 < arg2	0 : arg1= arg2	+ve : arg1 > arg2		
The form of compare must be
int function_name(const void *arg1, const void *argl2)		






void *bsearch(const void *key, const void *base, 
           size_t num, size_t size, 
int(*compare)(const void *, const void *));

Function pointed to by compare is used to compare two elements in the array with the key. It must return values:
	bsearch() performs a binary search on the sorted array pointed to by base and returns a pointer to the first member that matches the key pointed to by key. The number of elements in the array is specified by num and the size (in bytes) of each element is described by size. (size_t type e defined in STDLIB.H and equivalent of unsigned). The array must be sorted in ascending order, with the lowest address containing the lowest element. If the array does not contain the key, then a null pointer is returned.	char *alph = "abcdefghijklmnopqrstuvwxyz";
int comp(const void *ch, const void *s);
int main(void){char ch, *p;
    do { printf("Enter a character: "); 
    scanf("%c%*c",&ch); ch = tolower(ch);
    p = bsearch(&ch, alph, 26, 1, comp) 
if(p) printf("is in alphabet.\n"); 
else printf("is not in alphabet.\n") } while(p);
return 0;} 
int comp(const void *ch, const void *s){
return *(char *)ch – *(char *)s;     }
-ve : arg1 < arg2	0 : arg1= arg2	+ve : arg1 > arg2		
The form of compare must be
int function_name(const void *arg1, const void *argl2)	




// --------    <setjmp.h> : JUMP between FUNCTIONS   --------

#include <setjmp.h>    // must be  included before use	

void longjmp(jmp_buf envbuf, 
		int  val);	longjmp() causes program execution to resume at the point of the last call to setjmp(). These two functions are the way ANSI C provides for a jump between functions. Notice that the header SETJMP.H is required.
               The longjmp() function operates by resetting the stack as described in envbuf, which must have been set by a prior call to setjmp(). This causes program execution to resume at the statement following the setjmp() invocation—the computer is ’tricked’ into thinking that it never left the function that called setjmp(). (As a somewhat graphic explanation, the longjmp() function ’warps’ across time and (memory) space to a previous point in your program, without having to perform the normal function-return process.)
               The buffer envbuf is of type jmp_buf, which is defined in the header SETJMP.H. The buffer must have been set through a call to setjmp() prior to calling longjmp().
               The value of val becomes the return value of setjmp() and may be interrogated to determine where the long jump came from. The only value not allowed is 0.
               It is important to understand that the longjmp() function must be called before the function that called setjmp() returns. If not, the result is technically undefined. In actuality, a crash will almost certainly occur.
               By far the most common use of longjmp() is to return from a deeply nested set of routines when a catastrophic error occurs.	#include <setjmp.h>
#include <stdio.h>

void f2(void);
jmp_buf ebuf;

int main(void){ char first=1; int i;
           printf("1") ; 
           i = setjmp(ebuf) ; 
           if(first) {first = !first; 
	        f2();
	        printf("Not printed"); 
	        }
           printf("%d",i); 
           return 0;}

void f2(void){  printf("2");
	          longjmp(ebuf, 3);   }

#include <setjmp.h> 
int  setjmp(jmp_buf envbuf);	setjmp() saves the contents of the system stack in the buffer envbuf for later use by longjmp(). setjmp() returns 0 upon invocation. However, longjmp() passes an argument to setjmp() when it executes, and it is this value (always nonzero) that will appear to be the value of setjmp() after a call to longjmp().	

