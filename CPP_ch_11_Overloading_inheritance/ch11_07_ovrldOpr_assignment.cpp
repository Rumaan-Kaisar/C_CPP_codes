
/*  ------------------------    overloading ASSIGNMENT operator : '='    ------------------------
    By default (without overloading), when the assignment operator is applied to an object, 
        a bitwise copy (also called a "shallow copy") of the object on the right is put into the object on the left. 
    
    This means that the contents of the memory of the object on the right-hand side 
        are copied directly into the memory of the object on the left-hand side.

    If this is what you want, 
        there is no reason to provide your own operator=() function (i.e. overloading has no reason). 

    However, there are cases in which a strict bitwise copy is not desirable 
        and we need to provide a special assignment operation.
*/  




/*  Example 1: Following is another version of the strtype class (from previous chapters)
                This version overloads the '=' operator to ensure 
                the pointer 'p' is not overwritten during assignment.
*/

#include <iostream>
#include <cstring>
#include <cstdlib>

class strtype{
        char *p;
        int len;
    public:
        strtype(char *s);   // constructor
        ~strtype(){         // destructor
            // std::cout << " Freeing " << (unsigned)p << '\n';     // ERR: cast from ‘char*’ to ‘unsigned int’ loses precision
            std::cout << " Freeing " << (void*)p << '\n';
            delete [] p;    // delete dynamically allocate a 1D array. "delete [] p_var;"
            // recall "ch10_09_3_more_new_delete.cpp"
        }
        char *get(){ return p; }
        
        // Overload '=': It is an operator function that returns a reference to the object
        strtype &operator=(strtype &ob);    // reference operator function
};


strtype::strtype(char *s){
    int l;

    l = strlen(s) + 1;
    p = new char [l];
    if(!p){
        std::cout << " Allocation error \n";
        exit(1);
    }

    len = l;
    strcpy(p, s);
}


// overload '=': Assign an object
strtype &strtype::operator=(strtype &ob){
    
    // see if more memory is needed
    if(len < ob.len){ 
        // allocate more memory
        delete [] p;
        p = new char[ob.len];

        if(!p){
        std::cout << " Allocation error \n";
        exit(1);
        }
    }

    len = ob.len;
    strcpy(p, ob.p);
    return *this;
}


int main(){
    strtype a(" Hello "), b(" There ");

    std::cout << a.get() << '\n';
    std::cout << b.get() << '\n';

    a = b; // now p is not overwritten

    std::cout << a. get () << '\n';
    std::cout << b. get () << '\n';

    return 0;
}

/*  The error occurs because we're trying to cast a char* pointer to an "unsigned int", 
        which might lead to a loss of precision, especially on 64-bit systems 
        where pointers are 64 bits but unsigned int is typically 32 bits.
        Casting to unsigned can truncate the pointer value, leading to potential data loss

    Solution:
        cast the pointer p to an uintptr_t or void* instead, 
        as these types are specifically designed to safely store pointer values.

                #include <cstdint> // Include this for uintptr_t

        change:
                std::cout << " Freeing " << (uintptr_t)p << '\n';   // Use uintptr_t for pointer-to-integer cast

    uintptr_t
        The uintptr_t type is an unsigned integer type guaranteed to be large enough to hold a pointer. 
        Casting a pointer to uintptr_t ensures compatibility and avoids precision loss.

                #include <cstdint> is needed for uintptr_t.

Alternative:
If you don't need to perform arithmetic or formatting operations on the pointer, you can also directly cast p to void* for printing.
std::cout << " Freeing " << (void*)p << '\n';

*/


// ----  rev[27-Jan-2025]  ----


/* ------------    Note: using space wit &    ------------
    Common Styles (without space):      strtype &operator=(strtype &ob);
     
    Both
            strtype &operator=(strtype &ob);
    and 
            strtype & operator=(strtype &ob); 
    
    are syntactically correct in C++. 
    
    The placement of the space between & and operator is purely 
        a matter of style preference and does not affect functionality.
*/


As you can see, the overloaded assignment operator prevents p from being overwritten.
It first checks to see if the object on the left has allocated enough memory to hold the
string that is being assigned to it. If it hasn’t, that memory is freed and another portion
is allocated. Then the string is copied to that memory and the length is copied into len.
Notice two other important features about the operator=() function. First, it takes a
reference parameter. This prevents a copy of the object on the right side of the assignment
from being made. As you know from previous chapters, when a copy of an object is made
when passed to a function, that copy is destroyed when the function terminates. In
this case, destroying the copy would call the destructor function, which would free p.
However, this is the same p still needed by the object used as an argument. Using a
reference parameter prevents this problem.
The second important feature of the operator=() function is that it returns a reference,
not an object. The reason for this is the same as the reason it uses a reference parameter.
When a function returns an object, a temporary object is created that is destroyed after
the return is complete. However, this means that the temporary object’s destructor will
be called, causing p to be freed, but p (and the memory it points to) is still needed by
the object being assigned a value. Therefore, by returning a reference, you prevent a
temporary object from being created.
Note: As you learned in Chapter 5, creating a coy constructor is another way to prevent
both of the problems described in the preceding two paragraphs. But the copy constructor
might not be as efficient a solution as using a reference parameter and a return reference

type. This is because using a reference prevents the overhead associated with copying an
object in either circumstances. As you can see, there are often several ways to accomplish
the same end in C++. Learning to choose between them is part of becoming an excellent
C++ programmer.






/* 
	The overloaded assignment operator prevents p from being overwritten.
	It first checks to see if the object on the left has allocated enough memory to hold the string that is being assigned to it. If it hasn't, that memory is freed and another portion is allocated. 
	Then the string is copied to that memory and the length is copied into len.
	Notice two other important features about the operator=() function. 
	First, it takes a reference parameter. This prevents a copy of the object on the right side of the assignment from being made. 

[Recall ch10_06_1 - ch10_06_3 and ch10_10_1 - ch10_10_4 : when a copy of an object is made when passed to a function, that copy is destroyed when the function terminates. In this case, destroying the copy would call the destructor function, which would free p. However, this is the same p still needed by the object used as an argument. Using a reference parameter prevents this problem.]
	The second important feature of the operator=() function is that it returns a reference, not an object. The reason for this is the same as the reason it uses a reference parameter.

[Recall ch10_06_1 - ch10_06_3 and ch10_10_1 - ch10_10_4 : When a function returns an object, a temporary object is created that is destroyed after the return is complete. However, this means that the temporary object's destructor will be called, causing p to be freed, but p (and the memory it points to) is still needed by the object being assigned a value. Therefore, by returning a reference, you prevent a temporary object from being created.]

Note: We know creating a copy constructor is another way to prevent both of the problems described in the preceding two paragraphs. But the copy constructor might not be as efficient a solution as using a reference parameter and a return reference type. This is because using a reference prevents the overhead associated with copying an object in either circumstances. 

There are often several ways to accomplish the same end in C++. Learning to choose between them is part of becoming an excellent C++ programmer.


*/






/* Example 2: Given the following class declaration, fill in all the details that will create a dynamic
array type. That is, allocate memory for the array, storing a pointer to this memory in
p. Store the size of the array, in bytes, in size. Have put() return a reference to the
specified element, and have get() return the value of a specified element. Don’t allow the
boundaries of the array to be overrun. Also, overload the assignment operator so that the
allocated memory of each array is not accidentally destroyed when one array is assigned to
another. (In the next section you will see a way to improve your solution to this exercise.)
class dynarray
{
int *p;
int size ;
public :
dynarray ( int s); // pass size of array in s
int & put ( int i); // return reference to element i
int get ( int i); // return value of element i
// create operator =() function
};
 */
6.6 EXERCISE
1. # include <iostream >
# include <cstdlib >
482ANSWERS
6.6 EXERCISE
using namespace std ;
class dynarray
{
int *p;
int size ;
public :
dynarray ( int s);
int & put ( int i);
int get ( int i);
dynarray & operator =( dynarray &ob);
};
// Constructor
dynarray :: dynarray ( int s)
{
p = new int [s];
if (!p)
{
cout << " Allocation error \n";
exit (1) ;
}
size = s;
}
// Store an element .
int & dynarray :: put ( int i)
{
if(i <0 || i >= size )
{
cout << " Bounds error !\n";
exit (1) ;
}
return p[i];
}
// Get an element
int dynarray :: get ( int i)
{
if(i <0 || i >= size )
{
cout << " Bounds error !\n";
exit (1) ;
}
return p[i];
}
// Overload = for dynarray
483TEACH YOURSELF
C++
dynarray & dynarray :: operator =( dynarray &ob)
{
int i;
if( size != ob. size )
{
cout << " Cannot copy arrays of differing size !\n";
exit (1) ;
}
for (i = 0; i< size ; i++)
p[i] = ob.p[i];
return * this ;
}
int main ()
{
int i;
dynarray ob1 (10) , ob2 (10) , ob3 (100) ;
ob1 . put (3) = 10;
i = ob1 . get (3) ;
cout << i << ’\n’;
ob2 = ob1 ;
i = ob2 . get (3) ;
cout << i << ’\n’;
// generates an error
ob1 = ob3 ; // !!!
return 0;
}




