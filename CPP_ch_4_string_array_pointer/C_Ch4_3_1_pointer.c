
/* 
    ---------|    pointer    |---------
    C's most important and sometimes most troublesome features
        A pointer is basically the address of an object.
        We will learn about the special 
        pointer operators, 
        pointer arithmetic,
        relation between arrays and pointers
        pointers as parameters to functions


    ---------|    Summery    |---------

        pointer:
            A 'pointer' is a "variable" that contains the "address" of another variable.

        pointer operators:
            '*' operator returns the "value of the object" pointed to by the 'pointer' it precedes.  
            '&' operator returns the 'address of the variable' it precedes.

        base type of a pointer:
            The base type of a pointer is important because all pointer arithmetic is done relative to it.

    -----------------------------------


    pointer : 
        Pointer is a kind of variable by which we can work with other variables data using the location of the pointed variable. 
        It’s a kind of indirect use of a variables data using its memory location.

        A pointer is a variable that holds the memory address of another Object. 
        For example, if a variable called "p" contains the 'address' of another variable called "q", then "p points to q" . 
            Therefore if q is at location 100 in memory, then p would have the value 100 . 
        
        General form:
            type *var_name;

        Here, "type" is the "base type" of the pointer. The 'base type' specifies the 'type of the object' that the pointer can point to. 
        Notice that the variable name is preceded by an "asterisk" (also asterisk can be preceded by type : type* 
            There is no space between "type & * " or  " * & var_name "). This tells the computer that a pointer variable is being created. 
            For example :  	
                int *p;  
                creates a pointer to an integer:.

        A pointer type declaration "type *Pointer_ver_name" has two pats
            Part-1	        Part-2
            type*	        Pointer_ver_name
            int*	        s_time 
                    or
            type	        *Pointer_ver_name
            int             *s_time 



    point and return address:
        The * and & operators for point and return address.

        & operator returns the address of the variable it precedes. 
        * operator returns the value stored at the address that it precedes.

        we can verbalize the "&" operator as "address of" and "*" operator as "at address". 




    ---------|    Assigning values to a variables indirectly using pointer    |---------

        This fragment assigns 'q' a value indirectly using the pointer 'p' :
            int *p, q;
            p = &q: 	//get q's address
            *p = 199; 	// assign q a value using a pointer



    Indirection: When a variable's value is referenced through a pointer, the process is called indirection.
        Pointers are used to  support "linked lists" and "binary trees" implementing data-structutrs.




    ---------|    BASE TYPE of a pointer    |---------
        The base type of a pointer is very important. 
        Although C allows any type of pointer to point anywhere in memory, it is the base type that determines how the object pointed to will be treated.

        Consider the following fragment:

            int q;	
            double *fp;     // floating type
            fp = &q;
            *fp = 100.23;   // Assigning 'double type value' to a 'int type variable' using pointer

        Here fp assigns the location(address) of an int type variable q
        but *fp's base type is duoble.  *fp assigns double type data (floating-point value) to the int type veriable q. 

        Although not syntactically incorrect, but this fragment is wrong.
        Since 'int's are usually shorter than 'double's, and above assignment statement causes memory adjacent to q to be overwritten. 
        Thus causing an error.

        Except in special cases, never use a pointer of one type to point to an object of a different type.




    ---------|    In most case both * and & operators appear    |---------

    Crashing a program!!
        If you attempt to use a pointer before it has been assigned the address of a variable, your program will probably crash.

        In most case both * and & operators appear in programs, they don't appear alone.
 
        Remember, declaring a pointer variable simply creates a variable capable of holding a memory address. It does not give it any meaningful initial Value.

        Following fragment is incorrect.
            int *p;
            *p=10;  // incorrect - p is not pointing to anything "There is no location to assign 10"



    Null pointer: pointer that contains a null value (zero) is assumed to be unused and pointing at nothing.  
        Although compiler admits a null pointer, usually with disastrous results.

        
*/




/* Example 1: Pointer demo */
#include <stdio.h>
int main(void){	
    int *p, q;
    
    q = 199;	 // assign q 199 
    p = &q; 	// assign p the address of q

    printf("%d\n", *p);	 // display q's value using pointer 
    printf("q = %d, location = %x, *p = %d", q, p, *p);     // Displays all. Using %x  specifier for address
    printf("\nAddress of q: %p", p);  // Using %p  specifier for address

    return 0;
}

// 'p = &q;'   can be read as "assign p the address of q ". Finally, 
// 'printf("%d\n", *p);'   the value of q is displayed using the * operator applied to p. This statement can be read as "print the value at address q".

/*
---------|    specifires %p and %x    |---------
    The specifires %p and %x:  Functions belonging to the printf function family have the type specifiers "%p" and "%x".
        "x" and "X" serve to output a hexadecimal number, "x" stands for lower case letters (abcdef) while "X" for capital letters (ABCDEF).
        "p" serves to output a pointer. It may differ depending upon the compiler and platform (32bit or 64bit).


    One specifier is often used instead of another on 32-bit systems, but it is a mistake. Here is an example:

    int a = 10;
    int *b = &a; 

    printf("%p\n",b); 
    printf("%X\n",b);

        On a Win32 system, the following result will be printed:
            0018FF20
            18FF20

    As you may see, the output results for "%p" and "%X" are rather similar. 
    This similarity leads to inaccuracy in the code and this, in turn, results in errors occurring 
        when you port a program to a 64-bit platform (in 64 bit may get : 000018FF20 for X). 
        Normally %x is used, but it is better to use " %p " to display the memory address. 
*/


