/* 
    -------------    ENUMERATIONS    -------------
    A list of 'named integer constants' called an enumeration. 
        These constants can then be used 'any place' an 'integer' can.

    To define an enumeration, use this general form:

        enum tag-name { enumeration list } variable-list;

    Either the tag-name or the variable-list is optional. 
        The tag-name is essentially the type name of the enumeration 
        (all type & variable declaration are same as structure). 


    An enumeration is essentially an 'integer type' and an enumeration variable can hold 
        any integer value-not just those defined by the enumeration. 

    For clarity and structure, you should use enumeration variables to hold only values that are defined by their enumeration type. 
        i.e. use 1, 2, 3, 4, 5, 6,  etc.

    Two of the main uses of an enumeration are:
        To help provide 'self-documenting code' and 
        To clarify the 'structure' of your program.
*/




/* Example 1: Following is an example of enumaration */

enum color_type {
    red, 
    green, 
    yellow
} color ;



/* In the previous example an enumeration consisting of the constants red, green, and yellow is created. 
    The enumeration 'tag' is 'color_type' and one 'variable', called 'color', has been created.

By default, the compiler assigns integer values to enumeration constants, 
    beginning with 0 at the far left side of the list. 
    Each constant to the right is one greater than the constant that precedes it. 
    
    e.g. in the color enumeration, red is 0, green is 1, and yellow  is 2. 

Override enumaration value:
    You can override the compiler's default values by explicitly giving a constant a value new count begin from that value. 
*/




/* Exxample 2: Override enumaration value, consider following statement: 
                red is still 0, but green is 9, and yellow is 10 ( new counts begin from 9 )
*/

enum color_type {
    red, 
    green=9, 
    yellow
} color ;




/* Split variable declaration  of an enumeration : 
    Once you have defined an enumeration, you can use its tag name to declare enumeration variables 
        at other points in the program (similar to structure variable declaration) . For example   
*/

enum color_type mycolor; declares mycolor as a color_type variable.


