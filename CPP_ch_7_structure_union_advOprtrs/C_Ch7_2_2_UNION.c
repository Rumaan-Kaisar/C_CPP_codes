
/* 
    ------------    UNIONS    ------------

    Unions are another user defined data type. 
        It similar to structures and follow the same syntax.  Its general form is

                union tag-name {
                    type member_1;
                    type member_2;
                    type member_3;
                    . . .
                    . . .
                    type member_N;
                } variable-names;

            Like a structure, either the 'tag-name' or the 'variable-names' may be present. 
            Members may be of any valid C data type.



        Variable declaration: 
            we can declare variable using following or 'along with' union-declaration (similar to structure) :

                union tag-name variable_1, variable_2, . . . , variable_n;



    In C, a 'union' is a "single piece of memory" that is shared by two or more variables. 
        The variables that share the memory may be of 'different types'. 
        However, 'only one variable' may be in use at 'any one time'. 

        Thus all the members of union shaere the same memory
            a union may contain many members of different types, it can handle only one member at a time. 



    Why we need unions : 
        In some cases we may need 'more than one variables' but among them, we use only one variable at a time. 
            So in such cases we use unions instead of structures. 



    Difference between structure and union 
        In terms of storage(how they store data):
            In 'structures', each member has its own storage location, 
            All the members of a 'union' use the same location.

        In terms of size:        
            The size of a structure is determined by the sum or total of the sizes of all of its members . 
            The size of an union is the size of its largest ember.

        UNIONS may be used in all places where a STRUCTURE is allowed. 

Nested union inside structure:
    The notation for accessing a 'union member' which is nested inside a structure remains the same as for the 'nested structures'.

*/



// -----------------    Size of UNION vs STRUCTURE    -----------------

// following 'union' and 'structure' contains three members, each with a different data type. 
// since  only one location is allocated for a union variable, irrespective of its size.
    // we can use only one member at a time 

union item {
    int m;      // 2 byte
    float x;    // 4 byte
    char c;     // 1 byte
} ;	
// since float takes the largest space in memory
    // size of this union is 4 bytes


struct item{
    int m;      // 2 byte
    float x;    // 4 byte
    char c;     // 1 byte
} ;
// size of this stucture is 7 byte 
    // since total space (sum) required by the members is 7 byte


/*     Note:
        The size of a union is fixed at compile time and is large enough to accommodate the largest member of the union. 
            Assuming 4-byte flaoat, the union will be 4 bytes long even if it used to hold an 'int' value (though int is only 2 byte long)

        Use the "sizeof" compile-time operator to determine the size of a union.

        It won't be always largest member's size
            In some environments, the compiler may pad the union so that it aligns on a word boundary.

        Unions are very useful when you need to interpret data in two or more different ways. 
*/




// ------------------    Assigning values to union members    ------------------  
// We use ".", "->" the dot and arrow operators just as we dis for structures

union item {
    int m; 
    float x; 
    char c;
} sample;

/* 
    For example, this statement assigns 123.098 to x of sample: 		

            sample.x = 123.098;

    To access a union through a pointer, you must use the 'arrow' operator. 
    For example, assume that" p" points to 'sample'. The following statement assigns m the value 101:		 

            p -> m = 101;

    Restrictions on accessing union members : 
        Since we can use any "one" of its members at a time
            we should make sure that we are accessing the member whose value is currently stored. 
        
        For example, following will cause an ERROR

        code.m = 379; 	        // int type variable m is used
        code.x = 7859.36; 	    // float type variable x is used and value of m is destroyed
        printf("%d", code.m); 	// try to access destroyed variables value cause error

        would produce erroneous output (which is machine dependent).
            Because When a different member is assigned a new value, the new value supersedes the previous member's value. 
*/




/* 
    ------------------    Union variable initialization    ------------------  

    Unions may be 'initialized' when the 'variable is declared'. 
        But, unlike structures, it can be initialized only with a 'value of the same type as the first union member' 

    E.G. cosider following union: 
*/

union item {
    int m; 
    float x; 
    char c;
};

// we cannot initialize a union with its second or third or other member.For example,   	
union item abc = {100};  // is valid 

// but following is invalid	because the type of the first member of "union item" is int
union item abc = {10.75};   // invalid


