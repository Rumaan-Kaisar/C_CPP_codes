
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
        Unions are very useful when you need to interpret data in two or more different ways.
            a value stored in a memory can be represented differently using different "data-types" of sharing variables

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
        
        For example, following will cause 'erroneous' output (not ERROR)

        code.m = 379; 	        // int type variable m is used
        code.x = 7859.36; 	    // float type variable x is used
        printf("%d", code.m); 	// try to access other variables value cause wrong output

        would produce 'erroneous' output (which is machine dependent).
            Because When a different member is assigned a new value, the new value supersedes the previous member's value. 
            
            NOTE that: 
                There will be no ERROR but the output will be different, because different data-type 
                will represent the the stored data differently
*/




/* Example 1: following will cause 'erroneous' output (not ERROR) */

#include <stdio.h>

int main(void){

    union item {
        int m;
        float x;
        char c;
    } sample;

    sample.m = 379; 	        // int type variable m is used
    printf("\ntry to access using int: %d\n", sample.m); 	// try to access using int
    printf("\ntry to access using float: %f\n", sample.x); 	// try to access using float
    printf("\ntry to access using float but using int format specifier : %d\n", sample.x); 	// try to access using float
    printf("\ntry to access using char: %c\n", sample.c); 	// try to access using char

    sample.x = 7859.36; 	    // float type variable x is used
    printf("\nstoring 7859.36 using the float variable: %f\n", sample.x); 	// store/update using float
    printf("\nShowing 7859.36 using the int variable: %d\n", sample.m); 	// try to access using int
    printf("\nShowing again 7859.36 using the float variable: %f\n", sample.x); 	// try to access using float

    return 0;
}

// output:
//     try to access using int: 379
//     try to access using float: 0.000000
//     try to access using float but using int format specifier : 0
//     try to access using char: {
//     storing 7859.36 using the float variable: 7859.359863
//     Showing 7859.36 using the int variable: 1173723873
//     Showing again 7859.36 using the float variable: 7859.359863





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





/* Example 2: Unions are very useful when you need to interpret data in two or more different ways. For example, 
                The encode() function shown below uses a union to encode an integer by swapping its two low-order bytes. 
                The same function can also be used to
                'decode' an 'encoded integer' by swapping the already exchanged bytes back to their original positions. 

                Same value in a single location is represented using different types.
*/

#include <stdio.h>

int encode(int i);

int main(void){
    int i;
    i = encode (10) ; // encode it 
    printf("10 encoded is %d\n", i);

    i = encode(i); // decode it 
    printf("i decoded is %d", i);

    return 0;
}


// Encode an integer, decode an encoded integer.
int encode(int i){
    union crypt_type{
        int num;
        char c[2];
    } crypt;

    unsigned char ch;

    crypt.num = i;  // union initialized, 'int value' is stored in "num"

    // swap bytes: the stored "int" value accessed using "char" type variable
    ch = crypt.c[0];
    crypt.c[0] = crypt.c[1];
    crypt.c[1] = ch;

    // return encoded integer
    return crypt.num;
}

// note: 
    // the stored value can be accessed using "num" or "c[]" any time
    // the value is represented/interpreted differently due to data-type variation

// The program displays the following:
// 10 encoded is 2560
// i decoded is 10




/* Example 3: The following program uses the union of a structure containing "BIT-FIELDS" and 
                a character to display the 'binary representation of a character' typed at the keyboard: 

                When a key is pressed, its ASCII code is assigned to "key.ch", which is a char. 
                This data is reinterpreted as a series of bit-fields, 8bit = 1byte is represented by 
                    8 variables "a, b, c, d, e, f, g, h"; 
                    since a char is 1 byte = 8 bit long, we used 8 variables
                which allow the binary representation of the key to be displayed
*/

// This program displays the binary code for a character entered at the keyboard
#include <stdio.h>
#include <conio.h>

// following is a bit-fields
struct sample {
    unsigned a: 1;
    unsigned b: 1;
    unsigned c: 1;
    unsigned d: 1;
    unsigned e: 1;
    unsigned f: 1;
    unsigned g: 1;
    unsigned h: 1;
};

// following union uses bit-fields
union key_type {
    char ch;
    struct sample bits;
};

union key_type key;


int main(void){
    printf("Strike a key: ");
    key.ch = getche();
    printf ("\nBinary code is: ");

    // notie the 'bit-fields' accessed in reversed order
    if(key.bits.h) printf("1 ");
        else printf("0 ");
    if(key.bits.g) printf("1 ");
        else printf("0 ");
    if(key.bits.f) printf("1 ");
        else printf("0 ");
    if(key.bits.e) printf("1 ");
        else printf("0 ");
    if(key.bits.d) printf("1 ");
        else printf("0 ");
    if(key.bits.c) printf("1 ");
        else printf("0 ");
    if(key.bits.b) printf("1 ");
        else printf("0 ");
    if(key.bits.a) printf("1 ");
        else printf("0 ");

    return 0;
}


// Sample output is shown here:
// Strike a key: X
// Binary code is: 0 1 0 1 1 0 0 0




/* Example 4: Using a union composed of a double and an 8-byte character array, 
                write a function that writes a double to a disk file, a character at a time. 
                Write another function that reads this value from the file and reconstructs the value using the same union.
                (Note: If the length of a double for your compiler is not 8 bytes, use an appropriately sized character array.) */

#include <stdio.h>
#include <stdlib.h>

union u_type{
    double d;
    unsigned char c[8];
};

double uread(FILE *fp);

void uwrite(double num, FILE *fp);

int main(void){
    FILE *fp;
    double d;

    if ((fp = fopen("myfile_union", "wb+")) == NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    uwrite(100.23, fp);
    d = uread(fp);
    printf("%lf", d);

    return 0;
}


void uwrite(double num, FILE *fp){
    int i;
    union u_type var;

    var.d = num;    // using 'double' to store value
    for(i=0; i<8; i++) fputc(var.c[i], fp);     // using 'char' to write in the file
}


double uread(FILE *fp){
    int i;
    union u_type var;

    rewind(fp);     // resstting file position
    
    // using 'char' to read from the file
    for(i=0; i<8; i++) var.c[i] = fgetc(fp);

    return var.d;   // returning the falue using "double"
}

/* 
        ----------    C library function - rewind()    ----------

        The C library function 
            
                void rewind(FILE *stream) 

            sets the file position to the beginning of the file of the given stream.
*/




// -----------    EXS    ----------------

/* Example 5: Write a program that uses a union to convert an int into a long. */

#include <stdio.h>

int main(void){
    union t_type {
        long lg;
        int i;
    } uvar;

    uvar.lg = 0L;   // clear lg
    uvar.i = 100;

    printf("%ld", uvar.lg);

    return 0;
}








// ===============    MASTERY SKILLS CHECK    ===============


/* Example 1: In general terms what is a 'structure', and what is a 'union'? 
            Answer: 
                A 'structure' is a named group of RELATED variables. 
                A 'union' defines a MEMORY-LOCATION shared by two or more variables of DIFFERENT types.
*/




/* Example 2: Show how to create a structure type called "s_type" that contains these five members:
                char ch;
                float d;
                int i;
                char str[80];
                double balance;

            Also, define one variable called "s_var" using this structure.
*/

struct s_type {
    char ch;
    float d;
    int i;
    char str[80];
    double balance;
} s_var;




/* Example 3: What is wrong with this fragment?

                struct s_type {
                    int a;
                    char b;
                    float bal;
                } myvar, *p;
                // notice the pointer

                p = &myvar;
                p.a = 10;   // wrong, use '->' 


            Because p is a pointer to a structure, 
            you must use the ARROW OPERATOR '->' to reference an element, not the dot operator.
*/






/* Example 4: Write a program that uses an 'array of structures' to store

                    employee names, 
                    telephone numbers, 
                    hours worked, and
                    hourly wages. 

                Allow for 10 employees. Have the program input the information and 
                save it to a disk file. Call the file 'EMP'. 
*/

#include <stdio.h>
#include <stdlib.h>

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




/* Example 5: Write a program that reads the "EMP" file created in previous Exercise
                and displays the information on the screen. */

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




/* Example 6: What is a bit-field? 
                A "bit field" is a 'structure member' that specifies its length in bits
*/





/* Example 7: Write a program that displays individually the values of the 'HIGH and LOW-order bytes' of a short integer. 
                (Hint: Use a 'union' that contains as its two elements a short integer and a 'two-byte character array'.) 
*/


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

/* Example 1: Write a program that contains two structure variables defined as:

                    struct s_type {
                        int i;
                        char ch;
                        double d;
                    } var1, var2;

                Have the program give each member of both structures initial values, 
                but make sure that the values differ between the two structures. 

                Using a function called struct_swap(), have the program swap the contents of var1 and var2. 
*/

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




/* Example 2: As you know from previous chapters, fgetc() returns an 'INTEGER VALUE', 
                even though it only reads a character from a file. 

                Write a program that copies one file to another. 
                Assign the return value of fgetc() to a "UNION" that contains an integer and character member. 

                Use the 'integer element' to check for EOF. 
                Write the character element to the destination file. 
                Have the user specify both the source and destination tile names on the command line (CLI). 
*/

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





/* Example 3: What is wrong with this fragment?

                    struct s_type {
                        int a;
                        int b: 2;
                        int c: 6;
                    } var;

                    scanf("%d", &var);

                You cannot use a structure as an argument to scanf().
                However, you can use a structure element as an argument, as shown here:

                                scanf("%d", &var.a);
 */




/* Example 4: In C, as you know, you cannot pass an ARRAY to a function as a PARAMETER. 
                (Only a pointer to an array can be passed.)

                However, there is one way around this restriction. 
                    If you enclose the array within a structure, 
                    the array is passed using the standard "call-by-value" convention.

                Write a program that demonstrates this by passing a string inside a structure to a function, 
                    ALTERING its contents inside the function and 
                    demonstrating that the 'original string' is NOT ALTERED after the function returns. 
*/

"
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



"
// ===============    REVIEW SKILLS CHECK    ===============


/* Example 1: Write a program that uses an array of structures to hold the 
                squares and cubes of the numbers 1 through 10. 
                Display the contents of the array. 
*/

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




/* Example 2: Write a program that uses a 'union' to display as 'a character the individual bytes' 
                that make up a 'short integer' entered by the user. 
*/

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




/* Example 3: What does this fragment display? (Assume 'two-byte ints' and 'eight-byte doubles'.)

                        union {
                            int i;
                            double d;
                        } uvar;

                        printf("%d", sizeof uvar) i

                Answer: The fragment displays 8, the size of the largest element of the union. 
*/



// copy it to "STRUCTURE" part
/* Example 4: What IS wrong with this fragment?

                        struct {
                            int i;
                            char str[80];
                            double balance;
                        } svar;

                        svar->i = 100; 
                        
                To access a structure member when actually uaing a 'structure variable', you must use the dot '.' operator. 
                The arrow operator is used when 'accesaing a member' using a 'pointer' to a 'structure'.
*/

// UPDATE notes: copy it to "STRUCTURE" part 'NOTES'
To access a structure member when actually uaing a 'structure variable', you must use the dot '.' operator. 
The arrow operator is used when 'accesaing a member' using a 'pointer' to a 'structure'.




/* Example 5: What is a bit-field? */

A 'bit-field' is a structure element whose size is specified in bits




