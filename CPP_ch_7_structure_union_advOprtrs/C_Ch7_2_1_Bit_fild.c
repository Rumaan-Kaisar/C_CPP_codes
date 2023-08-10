
/* 
    ------------    BIT FIELDS    ------------

    Previously we've used 'integer fields' of size '16 bits' to store data. 
    In some occation data items require much less than 16 bits space. In such cases, we waste memory space. 

        The internal representation of bit fields is machine dependent.
                it depends on the 'size of int' and the "ORDERING" of bits. 
                Some machines store bits from left to right and others from right to left.
            
            The compiler will automatically store bit-fields in the 'smallest unit of memory' that will hold them. 
                Whether the bit-fields are stored high-order to low-order (left to right) or the other way around is implementation dependent.
                (However, many compilers use high-order to low-order.)


    bit field;
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





