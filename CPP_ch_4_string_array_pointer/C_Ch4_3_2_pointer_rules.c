
/* 
    --------------|    Restriction to Pointer Expression    |--------------
    In general, pointers may be used like other variables. However, there are few rules and restrictions.
    There are four operators that may be applied to pointer variables: The arithmetic operators +, ++, -, and --. 

    We cannot add a floating-point number to a pointer.


    --------------|    Pointer Increment/Decrement    |--------------
    Pointer arithmetic performed relative to the "base type" of the pointer. 
    Base-Type-Size increment: Each time a pointer is "incremented", it will point to the "next item", as defined by its "base type",
        For example, 
            an integer pointer called p contains the address 200. After the statement    p++;
                p will have the value 202, assuming integers are two bytes long. 
            
            if p had been a float pointer (assuming 4-byte floats), then the resultant value contained in p would have been 204 .

            The only pointer arithmetic that appears as "normal" occurs when char pointers are used. 
                Because characters are one byte long, an increment increases the pointer's value by one, and a decrement decreases its value by one.


        Increment and decrement to either the "pointer itself "or the "object" to which it points.
            For example, assume that p points to an integer that contains the value 1. 
            Increment pointer itself:
                *p++ ;
                This statement first increments p and then "obtains the value" at the "new location" (incremented the pointer location). 
            Increment the pointed object: To increment what is pointed to by a pointer, you must use a form like this:
                (*p) ++;
                The parentheses cause the value pointed to by p (i.e. the pointed variable) to be incremented. 


    --------------|    Addition, Multiplication, subtraction, Devision, comparison    |--------------
    Only add or subtract integer values
        You may add or subtract any integer quantity to or from a pointer. For example, the following is a valid fragment:
            int *p;  . . . . . . . .   p = p + 200;
            This statement causes p to point to the 200th integer past the one to which p was previously pointing.

    you may subtract one pointer from another in order to find the "number of elements" separating them.

    Do not multiply, divide, or take the modulus of a pointer. 

    You may compare two pointers using the relational operators. 
        However, pointer comparisons make sense only if the pointers relate to each other-if they both point to the same object, for example.
        You may also compare a pointer to zero to see if it is a null pointer.
*/




/* Example 1: You can use printf() to display the memory address contained in a pointer by using the %p format specifier. 
                The following program, shows how all pointer arithmetic is relative to the base type of the pointer.

                Although the values contained in the pointer variables in this
                program will vary widely between compilers and even between versions of the same compiler, you will see that the address
                pointed to by ch will be incremented by one byte. The others will be incremented by the number of bytes in their base types.
                For example, in a 16-bit environment this will typically be 2 for ints, 4 for floats, and 8 for doubles. */
#include <stdio.h>
int main (void){
    char *cp, ch;
    int *ip, i;
    float *fp, f;
    double *dp, d;
    
    cp = &ch;
    ip = &i;
    fp = &f;
    dp = &d;

    //print the current values
    printf("%p %p %p %p\n", cp, ip, fp, dp);

    // now increment them by on e
    cp++;
    ip++;
    fp++;
    dp++;

    //print their new values
    printf("%p %p %p %p", cp, ip, fp, dp);

    return 0;
}




/* Example 2: The following program illustrates the need for parentheses
                when you want to increment the object pointed to by a pointer instead of the pointer itself. */

// After this program has executed, q still has the value 1, but p has been incremented.
#include <stdio.h>
int main (void){
    int *p, q;
    p = &q;
    q = 1;
    printf("%p  ",p);
    
    *p++; // this will not increment q
    printf(" %d %p",q, p);
    
    return 0;
}


// However, if the above program is written like this, q will change
#include <stdio.h>
int main (void){
    int *p,q;

    p = &q;
    q = 1;
    printf("%p  ",p);
    
    (*p)++; // now q is incremented and p is unchanged
    printf(" %d %p",q, p);
    
    return 0;
}




/* Example 3: You cannot multiply a pointer */
int *p, i;
p = &i;
p = P*8;    //wrong




/* Example 4: Assume that p is a float pointer that currently points to location 100 
                and that floats are 4 bytes long. What is the value of p after this fragment has executed?
                p = p + 2; 
                */
p = p + 2;  //108. Because 4bytr + 4byte = 8

