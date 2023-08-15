
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





// -----------    EXS    ----------------

Example 1: Unions are very useful when you need to interpret data in two
or more different ways. For example, the encode( ) function
shown below uses a union to encode an integer by swapping its
two low-order bytes. The same function can also be used to
decode an encoded integer by swapping the already exchanged
bytes back to their original positions.

#include <stdio.h>
int encode(int i);
int main(void)
(
int i;
i = encode (10) ; f* encode it */)
printf("lO encoded is %d\n", il;
i = encode(i); /* decode it *1
printf("i decoded is %d-, i);
return 0;
STRUCTURES AND UNIONS 331
10.5 CREATE UNIONS
/* Encode an integer, decode an encoded integer. *1
int encode{int i)
{
)
union crypt_type {
int num;
char c (2];
} crypt j
unsigned char Chi
crypt.num = i;
j * swap bytes */
ch = crypt.e(O];
crypt.e[O] = crypt.e[l];
crypt.e(l] = chi
/ * return encoded integer *1
return crypt.num;
The program displays the following:
10 encoded is 2560
i decoded is 10




Example 2: The following program uses the union of a structure containing
bit-fields and a character to display the binary representation of
a character typed at the keyboard:

/ * This program displays the binary code for a
character entered at the keyboard .
' /
#include <stdio.h>
#include <conio . h>
struct sample (
unsigned a: 1;
unsigned b: 1;

unsigned c, 1 ;
unsigned d, 1;
unsigned e, 1 ;
unsigned f' 1 ;
unsigned g' 1 ;
unsigned h, 1 ;
) ;
union key_type {
char chi
struct sample bits;
key; ,
int main(void~
(
printf("Strike a key: ~);
key.ch = getche();
printf (~\nBinary code is: "l;
if(key.bits.h) printf("l H);
else printf("O "};
if(key.bits.g) printf("l ~);
else printf("O to);
if(key.bits.f) printf("! ");
else printf ("0 ");
if(key.bits.e) printf("l ");
else printf ("0 .. );
if{key.bits.d) printf{"l ");
else printf{"O ");
if(key.bits.c) printf("l "J;
else printf ("0 .. );
if{key.bits.b) printf("l n);
else printf("O M);
if(key.bits.a) printf(~l ");
else printf{"O ");
return 0;
When a key is pressed, its ASCII code is assigneq to !<ey.ch,
which is a char. This data is reinterpreted as a serjf's ofbit-fields,
which allow the binary representation of the key to be
displayed. Sample output is shown here:Strike a key: X
Binary code is: 0 1 0 1 1 0 0 0





Example 3: Using a union composed of a double and an 8-byte character
array, write a function that writes a double to a disk file, a
character at a time. Write another function that reads this value
from the file and reconstructs the value using the same union.
(Note: If the length of a double for your compiler is not 8 bytes,
use an appropriately sized character array.)

1. tinclude <stdio. h>
'include <stdlib.h>
union u_type (
'double d;
unsigned char c [8) ;
) ;
double ureadCFILE 'fp);
void uwrite(double num, FILE -fp):
int main (void)
C
)
FILE "fp;
double d;
if CCfp = fopenC "myfile", "wb+")) ==NULL) C
printf(-Cannot open file.\n-}:
exitCl);
)
uwriteClOO.23, fp);
d = ureadCfp);
printfC"'lf", d);
return 0;
void uwrite {double num, FILE -fp}
(-
int i;
union u_type var;
var.d = num;
forli=O; i<8; i++) fputc(var.c{i], fp);
)
double ureadCFILE "fp)
{
int i;
union u_type var;
...
'0.5 EXEIfCIS£S ...800 1EACM YOURSElF
c
rewind (fp) ;
for(i=O; i<8; i++) var.c[iJ = fgetc(fp);
return var.d:
)




Example 4: Write a program that uses a union to convert an int into a long.
Demonstrate that it works.

2. *include <stdio.h>
int rnain(void)
{
j
union t_type {
long 1:
lnt i:
} uvar;
,
uvar.l = OL; /* clear 1 */
uvar.i = 100;
printf(~%ld", uvar.l ) ;
return 0:





// ===============    MASTERY SKILLS CHECK    ===============
At this point you should be able to answer these questions and
perform these exercises:

Example 1: In general terms what is a structure, and what is a union?
A structure is a named group of related variables. A union
.defines a memorylocation snared by two or more vanables of
different types.




Example 2: Show how to create a structure type called s_type that contains
these five members:
char chi
float d:
int i;
char str[80];
double balance:
Also, define one variable called s_var using this structure.

struct s_type {
char chi
float d ;
int i;
char str[80};
double balance;
} s_var:




Example 3: What is wrong with this fragment>
struct s_type {
int a;

char b;
float bali
} myvar, .p;
p = &myvar;
p.a = 10;

Because p is a pointer to a structure, you must use the aITOW
operator to reference an element, not the dot operator.




Example 4: Write a program that uses an array of structures to store
employee names, telephone numbers, hours worked, and
hourly wages. Allow for 10 employees. Have the program input
the information and save it to a disk file. Call the file EMP.

#include <stdio.h>
#include <stdl ib.h>
struct s_type {
char name [40 J ;
char phone [14] ;
int hours:
double walle;
} emp[lO];
int main (void)
(
FILE *fp;
int i;
char temp[eO];
,
if((fp = fopen('emp', 'wb'l)==NULL) {
printf (·cannot open EMP file. \n-);
exit(l);
}
)
for(i=Oi i<10; i+.) (
print£(-Enter name: .);
gets (emp[i] . name) ;
}
printf(-Enter telephone number: .);
gets (emp Ii] .pl)one) ;
printf(-Enter hours worked: .);
gets (te.'!Ip);
emp[i] .hours = atoi(temp);
printf(MEnter hourly wage: .);
gets (temp) ;
ernp [i 1.wage = atof (temp) ;
fwrite(emp, sizeof emp, 1, fp);
fclose (fp) ;
return 0;




Example 5: Write a program that reads the EMP file created in Exercise 4
and displays the information on the screen.

S. 'include <stdio. h>
tinclude <stdlib.h>
struct s_type {
char name[40l;
char phone[14l;
int hours,
double wage;
) emp[l.O];
int rnain(void)
(
FILE ·fp;
int ii
if«fp = fopen("emp·, "rb"))==NULL) {
printf ("Cannot open EMP file. In") ;
exit(l) ;
J
fread(emp. sizeof amp, 1, fp);
for(i=O; 1<10; i+.} (
}
printf(",s 'sIn", emp[iJ .name , emp[i).phone);
printf("'d 'flnln", emp[iJ .hours , emp[iJ .wage);
fclose (fp) ,
return 0;}




Example 6: What is a bit-field?
A bit"field is a structure member that specifies its length in bits




Example 7: Write a program that displays individually the values of the
high- and low-order bytes of a short integer. (Hint: Use a union
that contains as its two elements a short integer and a two-byte
character array.)
This section checks how well you have integrated the material 

'include <stdio.h>
}
int main (void)
{
union u_type (
short int ii
unsigned char c{2] ;
) uvar:
uvar.i :: 99;
printf("High order byte, 'uln", uvar.c[l));
printf("Low order byte, 'uln", uvar.c[OJ );
return 0;
}







// ===============    CUMULATIVE SKILLS CHECK    ===============


This section checks how well you have integrated the material in
this chapter with that from earlier chapters.

Example 1: Write a program that contains two structure variables defined as:
struct s_type {
int i;
char chi
double d;
} varl, var2;
Have the program give each member of both structures initial
values, but make sure that the values differ between the two
structures. Using a function called struct_swap( ), have the
program swap the contents ofvarl and var2.

'include <stdio.h>
struct B_type {
int i;
char chi
double d;
} var1, var2;
int main (void)
(
varl.i = 100;
var2.i = 99;
var1.ch =- 'a';
var2.ch='b';
var1.d = 1. 0;
var2.d = 2.0;
NJ.aa 80S
CUMUVoTM SK1U.S a£CK ~
printf(-varl: %d %c %f\n-, var1.i. varl.ch, varl.d):
printf(-var2: %d %c %f\n-, var2.i. var2.ch. var2.d):
}
struct_swap(&varl, &var2);
printf« -After swap: \n-):
printf (·varl: %d %c %f\n -. var1. i, varl. ch, varl. d) ;
printf(-var2: %d %c %f-, var2.i. var2.ch. var2.d};
return 0;
void struct_swap(struct s_type *i. struct s_type *j)
(
)
struct s..:,type temp;
temp = *i:
*i = *j;
*j =- temp;




Example 2: As you know from Chapter 9, fgetc( ) returns an integer value,
even though it only reads a character from a file. Write aSTRUCTURES AND UNIONS 335
10.5 CREATE UNIONS
program that copies one file to another. Assign the return value
of fgetc( ) to a union that contains an integer and character
member. Use the integer element to check for EOF. Write the
character element to the destination file. Have the user specify
both the source and destination tile names on the command line.

j* Copy a file. *j
'include <stdio.h>

linallJl;le <stdlib.b>
- - .... 1
,
.--
"
int main(int argc, char '*argvIl:)
{
FILE "'from. ·to;
union u_type {
int i;
char chi
} uvar;
, •
/* see if correct number of command line arguments *j
if(argc!=31 {
printf("Usage: copy <source> <qestination>\n");
exit(ll;
)
'* open source file */
if«from = fopen(argv(l}. "rb" "==NULL) {
printf("Cannot open source f~le.\n·);
exit(l);
)
••
'" /* open des.tl.llt\tlOll flle *1
.' if «to = fop;'n(argv[2}. "..b" "==NULL) {
printf ("Cannot opell d.e,stin.ation {ile. \n") ;
exit (11;
) .,
,* forcopy ( ; i.) (the , file *' t
uvar. i = £getc (from) ;
if (uvar.i==EOF) break;
fputc (uvar. ch, to);
,
"
• ,
-
~ j:;') <> Co
fclose (from) ;
fclose(tol; ,
return 0; •
) •





Example 3: What is wrong with this fragment?
Sl:.ruct s_type {
int a;
int b: 2;
int c: 6;
} vari
scanf ("%d", &var);

You cannot use a structure as an argument to·acanf( ).
However, you can use a structure element as an argument, as
shown here. c
scanf("'d·, &var.a):




Example 4: In C, as you know, you cannot pass an array to a function as a
parameter. (Only a pointer to an array can be passed.) However,
there is one way around this restriction. If you enclose the array
,
within a structure, the array is passed using the standard
call-by-value convention. Write a program that demonstrates
this by passing a string inside a structure to a function, altering
its contents inside the function and demonstrating that the
original string is not altered after the function returns.

'include <string.h»
'include <&tdio.h>
"
s~ruct B_type (
char str(80);
} var;
11
void f(struct
int main (..void)
(
1 •
"_type
• U , •
• , ,
• L
i J ; f • , ,
(
strcpy(var.str, "this is original string");
f '( var} ;
.- ~
printf("'s". var.strl: -
.
return 0;
}
void f(struct s_type i)
(
}
strcpy(i.str, "new string") ;
printf(·'s\n·, i.str)·
6 '




// ===============    REVIEW SKILLS CHECK    ===============

Before proceeding, you should be able to answer these questions
and perform these exercises.


Example 1: Write a program that uses an array of structures (0 hold the
squares and cubes of the numbers I through 10. Display the
contents of the array.

Unclude <stdio : h>
,.
• ,
!
S.eruct. nWlLt.ype
i~t ~i .~
int sqr;
,
int cu.be:
} ·.nums (1'01.
int main (void)
(
int i;
'1:
" ,
j
,
o 1
" !) , t I
foX"(i=l; i<1,1[ i++) { J , 1 ...' 3
nums[i-l].i = i;

nu..(i-l).~ - i·i,
nuaa(i-l).CUbe - i·i·i,
for(i-O, i<10: i++) (
printf("\d ", nu..(i).i):
printf("td ", nuaa(i).~):
printf("td\n", nu..li) .CUbe) :
}
return 0,




Example 2: Write a program that uses a union to display as a character the
individual bytes that make up a short integer entered by the
user.

'include <stdio.b>
union i_to_c (
char c(2):
ahort int i:
} ic:
int main (void)
I
)
printf(-Enter an integer .,:
scanf(-'bd-, ~ic . i) :
printf("Cbaracter representation of each ~e: tc tc",
ic .cIO), ic .cll)) :
return 0;




Example 3: What does this fragment display? (Assume two-byte ints and
eight-byte doubles.)
union {
int i;
double d;
} uvar;
printf("%d", sizeof uvar) i

The fragment displays 8, the size of the largest element of
the union.




Example 4: What IS wrong with this fragment?
struct {
int i;
char str[80J;
double balance;
} svar;
svar->i = 100;

To access a structure member when actually uaing a etructure
variable, you must use the dot operator. The arrow operator iI
used when accesaing a member using a pointer to a structure.




5. What is a bit-field?

Abit-field iI a structure element whole IIize II specified Inbits




