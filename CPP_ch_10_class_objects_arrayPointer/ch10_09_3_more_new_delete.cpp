
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




// --------    rev[17-jun-24: 9:50pm]    --------



/* Example 1: Following program "allocates" MEMORY for an integer and "initializes" that memory */
// An example of initializing a dynamic variable .
# include <iostream >
using namespace std ;
int main ()
{
int *p;
p = new int (9) ; // give initial value of 9
if (!p)
{
cout << " Allocation error \n";
return 1;
}
cout << " Here is integer at p: " << *p << "\n";
delete p; // release memory
return 0;
}
As you should expect, this program displays the value 9, which is the initial value given
to the memory pointed to by p.




/* Example 2: The following program passes "initial values" to a dynamically allocated object */
// Allocating dynamic objects
# include <iostream >
using namespace std ;
class samp
{
int i, j;
public :
samp ( int a, int b) { i=a; j=b; }
int get_product () { return i*j; }
};
int main ()
{
samp *p;
p = new samp (6, 5); // allocate object with
initialization
if (!p)
{
cout << " Allocation error \n";
return 1;
}
cout << " Product is: " << p-> get_product () << "\n";
delete p;
return 0;
}
When the samp object is allocated, its constructor is automatically called and is passed
the values 6 and 5.




/* Example 3: The following program allocates an ARRAY of integers */
// A simple example of new and delete
# include <iostream >
using namespace std ;
int main ()
{
int *p;
p = new int [5]; // allocate room for 5 integers
// always make sure that allocation succeeded
if (!p)
{
cout << " Allocation error \n";
return 1;
}

int i;
for (i =0; i <5; i ++)
p[i] = i;
for (i =0; i <5; i ++)
{
cout << " Here is integer at p[" << i << "]: ";
cout << p[i] << "\n";
}
delete [] p;
return 0;
}




/* Example 4: The following program creates a dynamic array of objects */
// Allocating dynamic objects .
# include <iostream >
using namespace std ;
class samp
{
int i, j;
public :
void set_ij ( int a, int b) { i=a; j=b; }
int get_product () { return i*j; }
};
int main ()
{
samp *p;
int i;
// allocate object array named "samp" 
p = new samp [10]; // allocate object array
if (!p)
{
cout << " Allocation error \n";
return 1;
}
for (i =0; i <10; i ++)
p[i]. set_ij (i, i);
for (i =0; i <10; i ++)
{
cout << " Product [" << i << "] is: ";
cout << p[i]. get_product () << "\n";
}
delete [] p;
return 0;
}




/* Example 5 : (array of object) The following version of the preceding program gives samp a "DESTRUCTOR", 
                and now when p is freed, each element’s destructor is called.
*/

// Allocating dynamic objects
# include <iostream >
using namespace std ;
class samp
{
int i, j;
public :
void set_ij ( int a, int b) { i=a; j=b; }
~ samp () { cout << " Destroying ...\ n"; }
int get_product () { return i*j; }
};
int main ()
{
samp *p;
int i;
p = new samp [10]; // allocate object array
if (!p)
{
cout << " Allocation error \n";
return 1;
}
for (i =0; i <10; i ++)
p[i]. set_ij (i, i);
for (i =0; i <10; i ++)
{
cout << " Product [" << i << "] is: ";
cout << p[i]. get_product () << "\n";
}
delete [] p;
return 0;
}


// As you can see, samp’s destructor is called ten times-once for each element in the array




/* Example 1: Show how to convert the following code into its equivalent that uses "new" */
char *p;
p = ( char *) malloc (100) ;
// ...
strcpy (p, " This is a test ");
Hint: A string is simply an array of characters.




/* Example 2: Using new, show how to allocate a "double" and give it an initial value of "-123.0987" */



