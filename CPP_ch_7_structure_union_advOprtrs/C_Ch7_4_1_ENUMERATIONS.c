/* 
    -------------    ENUMERATIONS (named integer constants)    -------------
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




/* Example 1: Following creates an enumeration consisting of the parts of a computer. 
                It assigns 'comp' the value CPU and then displays its value (which is 1). 

                Notice how the 'enumeration tag-name' is used to declare 'comp' as an 
                enumeration variable separately from the actual declaration of computer.
*/

#include <stdio.h>

enum computer {
    keyboard , 
    CPU, 
    screen, 
    printer
};

int main(void) {
    enum computer comp;

    comp = CPU; // acessing 2nd member

    printf("%d", comp);
    return 0;
}




/* Example 2: It takes a little work to display the string equivalent of an enumerated constant.
                Remember, enumerated constants are not strings; they are named integer constants.
                The following program uses a switch statement to output the 'string equivalent' of an ENUMERATED VALUE.

                The program uses C's random-number generator to choose a means of transportation.
                It then displays the means on the screen. (This program is for people who can't make up their minds!) */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum transport {
    car, train, airplane, bus
} tp;

int main(void) {
    printf("Press a key to select transport: ");

    // generate a new random number each time the program is run
    while (!kbhit()) rand();

    getch(); // read and discard character */

    tp = rand()%4;

    switch(tp) {
        case car: printf("car");
                    break;
        case train: printf("train");
                    break;
        case airplane: printf("airplane");
                    break;
        case bus: printf("bus");
    }

    return 0;
}




/* Example 3: In some cases, there is an easier way to obtain a string equivalent of an enumerated value.
                As long as you do not initialize any of the constants,
                    you can create a two-dimensional string array that contains the string equivalents
                    of the enumerated values in the same order that the constants appear in the enumeration.
                    You can then index the array using an enumeration value to obtain its corresponding string.

                The following version of the transportation choosing program, for example, uses this approach:
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

enum transport {
    car, train, airplane, bus
} tp;

// Following is a two-dimensional string array that contains the string equivalents of "enum transport"
char trans[][20] = {
    "car", "train", "airplane", "bus"
};

int main(void) {
    printf("Press a key to select transport: ");

    // generate a new random number each time the program is run
    while (!kbhit()) rand();

    getch(); // read and discard character */

    tp = rand()%4;
    printf("%s", trans[tp]);

    return 0;
}




/* Example 4: Remember, the names of enumerated constants are known only to the program, 
                not to any library functions. For example, given the fragment 
*/

enum numbers {zero, one, two, three} num;

printf("Enter a number: ");
scanf("%d", &num);

// you cannot respond to scanf() by entering 'one'.
// scanf() is a library function and doesn't know about "enum numbers"




/* Example 5:  Create an enumeration of the coins of the U.S. from penny to dollar. */
enum money {penny, nickel. quarter, half_dollar. dollar}:




/* Example 6:  Is this fragment correct? If not, why not? */

enum cars {Ford, Chrysler, GM} make;
make = GM;
printf("car is %s", make);  // wrong! its not a "string", enum's are named int


