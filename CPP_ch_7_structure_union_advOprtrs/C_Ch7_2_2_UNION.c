
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



    In general terms what is a 'STRUCTURE', and what is a 'UNION'? 
            Answer: 
                A 'structure' is a named group of RELATED variables. 
                A 'union' defines a MEMORY-LOCATION shared by two or more variables of DIFFERENT types.



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





/* Example 5: Write a program that uses a 'union' to convert an int into a long. */

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




/* Example 6: What is a bit-field? 
                A "bit field" is a 'structure member' that specifies its length in bits
                It's just a structure element whose size is specified in bits
*/




/* Example 7: What does this fragment display? (Assume 'two-byte ints' and 'eight-byte doubles'.)

                        union {
                            int i;
                            double d;
                        } uvar;

                        printf("%d", sizeof uvar) i

                Answer: The fragment displays 8, the size of the largest element of the union. 
*/




/* Example 8: Write a program that uses a 'union' to display as 'a character the individual bytes'
                that make up a 'short integer' entered by the user.
*/

#include <stdio.h>

union i_to_c {
    char c[2];
    short int i;
} ic;

int main(void){
    printf("Enter an integer: ");
    scanf("%hd", &ic.i);

    printf("Character representation of each byte: %c %c", ic.c[0], ic.c[1]);

    return 0;
}




/* Example 9: Write a program that displays individually the values of the 'HIGH and LOW-order bytes' of a short integer.
                (Hint: Use a 'union' that contains as its two elements a short integer and a 'two-byte character array'.)
*/

#include <stdio.h>

int main(void) {
    union u_type {
        short int i;
        unsigned char c[2];
    } uvar;

    uvar.i = 99;

    printf("High order byte: %u\n", uvar.c[1]);
    printf("Low order byte: %u\n", uvar.c[0]);

    return 0;
}




/* Example 10: As you know from previous chapters, fgetc() returns an 'INTEGER VALUE',
                even though it only reads a character from a file.

                Write a program that copies one file to another.
                Assign the return value of fgetc() to a "UNION" that contains an integer and character member.

                Use the 'integer element' to check for EOF.
                Write the character element to the destination file.
                Have the user specify both the source and destination tile names on the command line (CLI).
*/

// Copy a file.
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {

    FILE *from, *to;

    union u_type {
        int i;
        char ch;
    } uvar;


    // see if correct number of command line arguments
    if(argc!=3) {
        printf("Usage: copy <source> <Destination>\n");
        exit(1);
    }

    // open source file
    if((from = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination flle
    if((to = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open destination file.\n");
        exit(1);
    }

    // copy the file
    for( ; ; ) {
        uvar.i = fgetc(from);
        if(uvar.i==EOF) break;
        fputc(uvar.ch, to);
    }


    fclose(from);
    fclose(to);

    return 0;
}
// save the source code as copy.c
// CLI: > copy file1 file2


