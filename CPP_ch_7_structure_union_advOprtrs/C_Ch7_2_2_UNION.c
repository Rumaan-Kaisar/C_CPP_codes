
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

*/

	In C, a union is a single piece of memory that is shared by two or more variables. 
	The variables that share the memory may be of different types. 
	However, only one variable may be in use at any one time. 
	A union is defined much like a structure. 
	Like a structure, either the tag-name or the variable-names may be present. 
	Members may be of any valid C data type.

Note
Why we need unions : In some cases we may need more than one variables but among them, we use only one variable at a time. So in such cases we use unions instead of structures. 

 7.4.1 Difference between structure and union 
Though structure and unions are similar but there is major distinction between them in terms of storage(how they store data). 
	In structures, each member has its own storage location, whereas all the members of a union use the same location. This implies that, although a union may contain many members of different types, it can handle only one member at a time. 
	The size of a structure is determined by the sum or total of the sizes of all of its members . The size of an union is the size of its largest ember.

union item {int m; float x; char c;} code;	struct item{int m; float x; char c;} code;
Storage of 4 bytes	Storage of seven bytes
1001	1002	1003	1004	Here x is the largest member having size 4 byte, hence size of the union is 4 byte.	3001	3002	3003	3004	3005	3006	3007
c=1byte			c=1byte	m=2byte	x=4byte
m=2byte	m=2byte			Here size of the structure = size of c + size of m + size of x
Hence, size of the structure is 7 byte. 
x=4byte	x=4byte	x=4byte	x=4byte		

Above declares a variable code of type union item. The union contains three members, each with a different data type. However, we can use only one of them at a time. This is due to the fact that only one location is allocated for a union variable, irrespective of its size.

	The compiler allocates a piece of storage that is large enough to hold the largest vari¬able type in the union. In the declaration above, the member x requires 4 bytes which is the largest among the members. 


Note
[1]	It is important to understand that the size of a union is fixed at compile time and is large enough to accommodate the largest member of the union. Assuming 4-byte flaoat, this means that code will be 4 bytes long. Even if code is currently used to hold an int value, it will still occupy 4 bytes of memory (though int is only 2 byte long). 
[2]	As is the case with structures, you should use the "sizeof" compile-time operator to determine the size of a union. You should not simply assume that it will be the size of the largest element, because in some environments, the compiler may pad the union so that it aligns on a word boundary.
[3]	Unions are very useful when you need to interpret data in two or more different ways.

7.4.2 Assigning values to union members  
To access a union member, we can use the same syntax that we use for structure members. That is,  code.m; code.x; code.c; are all valid member variables. Where : 		union item {int m; float x; char c;} sample;
	To access a member of a union, use the dot and arrow operators just as you do for structures. For example, this statement assigns 123.098 to x of sample: 		sample.x = 123.098;
	If you are accessing a union through a pointer, you must use the arrow operator. For example, assume that p points to sample. The following statement assigns m the value 101:		 p -> m = 101;

	Restrictions on accessing union members : 
	During accessing, we should make sure that we are accessing the member whose value is currently stored. For example, the statements such as

code.m = 379; 	/* int type variable m is used*/
code.x = 7859.36; 	/* float type variable x is used and value of m is destroyed*/
printf("%d", code.m); 	/* try to access destroyed variables value cause error*/

would produce erroneous output (which is machine dependent).

	In effect, a union creates a storage location that can be used by any one of its members at a time. When a different member is assigned a new value, the new value supersedes the previous member’s value.

	Unions may be used in all places where a structure is allowed. The notation for access¬ing a union member which is nested inside a structure remains the same as for the nested structures.

Union variable initialization : Unions may be initialized when the variable is declared. But, unlike structures, it can be initialized only with a value of the same type as the first union member (we cannot initialize a union with its second or third or other member).For example,   	union item abc = {100};  is valid but the declaration 	union item abc = {10.75}; is invalid. This is because the type of the first member is int. 
