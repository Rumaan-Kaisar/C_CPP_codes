
/* 
    ------------    BIT FIELDS    ------------

    BIT FIELDS (plural, its a structure where its members uses "bit-field"):
        BIT FIELDS is a structure and its each member is a bit-field

    Previously we've used 'integer fields' of size '16 bits' to store data. 
    In some occation data items require much less than 16 bits space. In such cases, we waste memory space. 

        The internal representation of bit fields is machine dependent.
                it depends on the 'size of int' and the "ORDERING" of bits. 
                Some machines store bits from left to right and others from right to left.
            
            The compiler will automatically store bit-fields in the 'smallest unit of memory' that will hold them. 
                Whether the bit-fields are stored high-order to low-order (left to right) or the other way around is implementation dependent.
                (However, many compilers use high-order to low-order.)


    bit field:
        To reduce memory loss we use bit field.
            Bit-fields are useful when you want to pack information into the SMALLEST POSSIBLE SPACE.

        A bit field is a "SET OF ADJACENT BITS" whose size can be from 1 to 16 bits in length. 
            A word can therefore be divided into a number of bit fields. 

        The 'name' and 'size' of BIT FIELDS are defined using a STRUCTURE.
        

    BIT FIELDS & structure:
        bit-fields are variation of structure member
        A bit-fields is composed of one or more bits.

        Using a bit-field, you can access by name 'one or more bits' within a "byte" or "word". 

        syntax:
                type name : size;
        
        type: type is either 'int' or 'unsigned'. 
                If you specify a signed bit-field, then the high-order bit is treated as a sign bit, if possible. 
                
        size: The number of bits in the field is specified by size. 
                Notice that a colon ':' separates the 'name of the bit-field' from its 'size in bits'.



    GENERAL FORM of bit-field structure:

            struct tag-name {	
                data-type name1 : bit-length; 
                data-type name2 : bit-length;
                    . . . .
                    . . . .
                data-type nameN : bit-length;
            };


    Length of bit-field structure:
        It is not necessary to define all bits within a byte or word. 
            For example, this is perfectly valid even its less than a "Byte":

                struct b_type { 
                    int a : 2;	 
                    int b : 3 ;
                };


    BOOLEAN & bit-field;
        Bit-fields are often used to store Boolean (true/false) data 
            You can pack 'eight Boolean values' into a "single byte".



    NOTES/RULES:
        There are several specific points to observe:
            [1]	The first field always starts with the first bit of the word.

            [2]	A bit-field cannot overlap integer boundaries. i.e. cannot exceed "1 Byte", (a 'bit-field-structure' has no such bounderies)
                    a).	That is, the 'sum of lengths of all the fields in a structure' should not be more than the size of a word. 
                    b).	In case, it is more, the overlapping field is automatically forced to the beginning of the next word.

            [3]	There can be unnamed fields declared with size. Such fields provide padding within the word. Example:   unsigned : bit-length ;

            [4]	There can be unused bits in a word.

            [5]	We cannot take the ADDRESS of a bit field variable. This means no "ADDRESS related things like Array/Pointer/Scanf-read"
                    a).	we cannot use scanf to read values into bit fields. 
                    b).	We cannot use POINTER to ACCESS the bit fields.
                    c).	Bit fields cannot be ARRAYED.

            [6]	Bit fields should be assigned values that are within the range of their size. 
                    If we try to assign larger values, behavior would be unpredicted.


*/




/* Example 1: Here is a structure that uses bit-fields to hold inventory information. 
                This whole bit-field structure is 1-byte long i.e. half of size of int type field.
                normally it would have taken four bytes without the use of bit-fields.
                    i.e. memory is reduced 4 times.
*/

struct b_type{ 
    unsigned department: 3;     // up to 7 departments 
    unsigned instock: 1; 	    // 1 if in stock, 0 if out 
    unsigned backordered: 1;    // 1 if backordered, 0 if not 
    unsigned lead_time: 3; 	    // order lead time in months 
} inv[MAX_ITEM];




/*
    It is possible to 'combine-normal structure elements' with bit field elements. 
        Also we can mix bit-fields with other types of members in a structure's definition. for example : 
*/


// Example 2: Mixing bit-field  with other structure element
struct b_type{ 
    unsigned department: 3; 	    // bit-field variable  
    unsigned instock: 1; 	        // bit-field variable  
    unsigned backordered: 1;        // bit-field variable  
    unsigned lead_time: 3; 	        // bit-field variable  
    char name[20];		            // normal variable 
    struct addr address;	        // structure variable 
} inv[MAX_ITEM];




/* 
    // --------------    Accessig BIT-FIELDS    --------------
    Accessing members of bit-field-structure (bit-fields) : 
        refer to a bit-field (memebr of BIT-FIELDS) just like any other member of a structure. 
            e.g. following assigns the value 3 to the 'department' field of item 10 (10th element of inv[n] array):

                inv[9].department = 3;

    Restrictions:  
        No use of ADDRESS: Because the smallest addressable-unit of memory is a "BYTE", 
            But BIT-FIELDS uses "BITS" you cannot obtain the address of a bit-field variable. 
            i.e. we cannot use 
                scanf() to read values into a bit-field. 
            
                    We may have to read into a 'temporary variable' and then assign its value to the bit-field. e.g. 

                            scanf("%d %d", &dpt); 	// assigning to other variable 
                            inv[9].department = dpt; 	// assigning other variable  to a bit-fild

                    We cannot use 'pointer' to access a bit-field.
                    We cannot use 'array' to a bit-field. 
*/





/* Example 3: It is not necessary to 'name every bit' when using bit-fields.
                Following structure uses BIT-FIELDS to access the 'first' and 'last' bit in a "BYTE".
                The use of unnamed bit-fields makes it easy to reach the bits you are interested in. */

struct b_type {
    unsigned first : 1;
    int : 6;
    unsigned last : 1;
};




/* Example 4: To see how useful bit-fields can be when working with Boolean data,
                Following is a crude simulation of a spaceship flight recorder.
                By packing all the relevant information into one byte,
                comparatively little disk space is used to record a flight. */

// ---------    Simulation of a 100 minute spaceship flight recorder    ---------

#include <stdlib.h>
#include <stdio.h>


// all fields indicate:
    // OK if 1,
    // malfunctioning or low if 0

struct telemetry {
    unsigned fuel : 1;
    unsigned radio : 1;
    unsigned tv : 1;
    unsigned water : 1;
    unsigned food : 1;
    unsigned waste : 1;
};

struct telemetry flt_recd;

// function with STRUCT parameter
void display(struct telemetry i);


int main(void){
    FILE *fp;
    int i;

    if((fp = fopen("flight" , "wb")) == NULL) {
        printf("Cannot open file. \n");
        exit(1);
    }

    // Imagine that each minute a status report of the spaceship is recorded on disk.
    for(i=0; i<100; i++) {
        flt_recd.fuel = rand()%2;
        flt_recd.radio = rand()%2;
        flt_recd.tv = rand()%2;
        flt_recd.water = rand()%2;
        flt_recd.food = rand()%2;
        flt_recd.waste = rand()%2;

        display(flt_recd);
        fwrite(&flt_recd, sizeof flt_recd, 1, fp);
    }

    fclose(fp);

    return 0;
}


void display(struct telemetry i){
    if(i.fuel) printf("Fuel OK\n");
    else printf("Fuel low\n");

    if(i.radio) printf("Radio OK\n");
    else printf("Radio failure\n");

    if(i.tv) printf("TV system OK\n");
    else printf("TV malfunction\n");

    if(i.water) printf("Water supply OK\n");
    else printf("Water supply low\n");

    if(i.food) printf("Food supply OK\n");
    else printf("Food supply low\n");

    if(i.waste) printf("Waste containment OK\n");
    else printf("Waste containment failure\n");

    printf("\n");
}



// Depending on how your compiler packs the bit-fields, after you run this program, the file on disk may be as short as 100 bytes long. 
// Now try the program after modifying the telemetry structure as shown here:

// No bit-field versioon
struct telemetry {
    char fuel;
    char radio;
    char tv;
    char water;
    char food;
    char waste;
} flt_recd;

// In this version, no bit-fields are used and the resulting file is at least 600 bytes long.




/* Example 5: Write a program that creates a structure that contains three bit-fields 
                called a, b, and c. Make a and b 'three bits long' and
                make c two bits long. 
                Next, assign each a value and display the values. 
*/

#include <stdio.h>

int main(void){
    // defining a BIT-FIELDS
    struct b_type {
        int a: 3;
        int b: 3;
        int c: 2;
    } bvar;

    // accessing members of the BIT-FIELDS "bvar"
    bvar.a = -1;
    bvar.b = 3;
    bvar.c = 1;

    printf("%d %d %d", bvar.a, bvar.b, bvar.c);

    return 0;
}




/* Example 6: Many compilers supply library functions that return the status of various hardware devices, 
                such as a serial port or the keyboard, by encoding information in a bit-by-bit fashion. 
                
                On your own, consult the user's manual for your compiler to see if it supports such functions. 
                If it does, write some programs that read and decode the status of one or more devices. 
*/





