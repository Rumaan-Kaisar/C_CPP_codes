
/*  ------------------------    Exceptions thrown by "new"    ------------------------

    In old C++, "new" returned "null" when memory allocation failed. 
    Modern C++ throws an "exception" by default when allocation fails. 
    However, you can choose to make it "return null" instead (as an option).

    
    --------  Allocation exceptions with "new" and "xalloc" or "bad_alloc"  --------

    When new cannot allocate memory, it throws a "bad_alloc" exception (xalloc in older versions).
    If you do not handle the exception, the program will terminate.

    For small programs, this may be acceptable. 
    In real applications, it is better to catch the exception and handle the error properly.
    
    Handling the exception:
        To use "bad_alloc", you must include the header: #include <new>






   Returning old fashioned null In Standard C++:  It is also possible to have new return null instead of throwing an exception when an allocation failure occurs.  This form of new is :   p_var =new(nothrow) type ;
   Here p_var is a pointer variable of type. 
   The nothrow form of new works like the original version of new from years ago. Since it returns null on failure, it can be "dropped into" older code and avoid exception handling.  Useful when compiling older code with a modern C++ compiler. 
   It is also valuable when you are replacing calls to malloc() with new. 









    





Using nothrow: You can make new return null instead of throwing an exception:
p_var = new(nothrow) type;
Here, p_var is a pointer variable.
Why use nothrow? It behaves like the old version of new. If memory allocation fails, it returns null instead of throwing an exception.
This is useful when:
Working with old C++ code.
Replacing malloc() with new.
You want to avoid exception handling.

*/  

/* Example 1: Here is an example of new that uses a try/catch block to monitor for an allocation
failure. */

#include <iostream>
#include <new>

int main ()
{
int *p;
try
{
p = new int ; // allocate memory for int
}
catch ( bad_alloc xa)
{
cout << " Allocation failure .\n";
return 1;
}
for (*p = 0; *p < 10; (*p)++)
cout << *p << " ";
delete p; // free the memory
return 0;
}
Her if an allocation failure occurs, it is caught by the catch statement.

   Example 1: Here is an example of new that uses a try/catch block to monitor for an allocation failure.
#include <iostream>
#include <new>
using namespace std;
    int main(){ int *p;
                     try{ p = new int; }    // allocate memory for int
                 catch (bad_alloc xa){  cout << " Allocation failure .\n";
                                    return 1;  }    for(*p = 0; *p < 10; (*p)++)      cout << *p << " "  ;
delete p; // free the memory
return 0; }
   Here if an allocation failure occurs, it is caught by the catch statement.



        
/* Example 2: Since the previous program is unlikely to fail under any normal circumstance, the following program demonstrates new’s exception-throwing capability bu forcing on allocation
failure. It does this by allocating memory until it is exhausted. */
// Force an allocation failure .
# include <iostream >
# include <new >
using namespace std ;
int main ()

{
double *p;
// this will eventually run out of memory
do
{
try
{
p = new double [100000];
}
catch ( bad_alloc xa)
{
cout << " Allocation failure .\n";
return 1;
}
}
while (p);
return 0;
}

//    Example 2: Since the previous program is unlikely to fail under any normal circumstance, the following program demonstrates new's exception-throwing capability by forcing on allocation failure. It does this by allocating memory until it is exhausted.

int main(){ double *p;
do{ try{ p = new double[100000]; }      // this will eventually run out of memory
catch( bad_alloc xa ){  cout << " Allocation failure .\n";
return 1;}
}while (p);
return 0;}




/* Example 3: The following program shows how to use the new(nothrow) alternative. It reworks te
preceding program and forces an allocation failure. */
// Demonstrate the new ( nothrow ) alternative .
# include <iostream >
# include <new >
using namespace std ;
int main ()
{
double *p;
// this will eventually run out of memory
do
{
p = new ( nothrow ) double [100000];
if(p)
cout << " Allocation OK\n";
else
cout << " Allocation Error .\n";
}
while (p);
return 0;
}
As this program demonstrates, when you use the nothrow approach, you must check the
pointer returned by new after each allocation request.


   Example 3: Following shows the use of new(nothrow) alternative. It reworks the Example 2 and forces an allocation failure.
int main(){ double *p;
do{ p = new(nothrow) double[100000];        // this will eventually run out of memory
if(p) cout << "Allocation ok \n";
else cout << "Allocation error \n";
}while (p);
return 0;}
   When you use the nothrow approach, you must check the pointer returned by new after each allocation request.




/* Example 4:


1. Explain the difference between the behavior of new and new(nothrow) when an allocation failure occurs.
2. Given the following fragment, show two ways to convert it into modern C++-style code.
p = malloc ( sizeof ( int ));
if (!p)
{
cout << " Allocation error .\n";
exit (1) ;
}
 */




1. By default, new throws an exception when an allocation error occurs. The nothrow
version of new returns a null pointer if memory cannot be allocated.
2. p = new ( nothrow ) int ;
if (!p)
{
cout << " Allocation error .\n";
// ...
}
try
{
p = new int ;
}
catch ( bad_alloc ba)
{
cout << " Allocation error .\n";
// ...
}

