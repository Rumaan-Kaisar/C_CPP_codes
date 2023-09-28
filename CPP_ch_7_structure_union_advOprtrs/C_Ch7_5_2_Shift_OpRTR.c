
/* 
    ---------------    Shift Operators    ---------------

    Shift Operators :
        The left and right bit-shift operators applied only to 'character' or 'integer' operands. They take these general forms:

                value << number-of-bits
                value >> number-of-bits

            The integer expression specified by "number-of-bits" determines how many places to the left or right the bits within value are shifted.
            When bits are shifted off an end they are lost.

    The left shift operator is << : 
        Each left-shift causes all bits within the specified value to be shifted left one position and a zero is brought in on the right. 
            Note: a left shift is the same as MULTIPLYING the number by 2. 

    The right shift operator is >>:  
        A right-shift shifts all bits to the right one position and brings a zero in on the left. 
            (Unless the number is negative, in which case a one is brought in).  
            Note: A right shift is equivalent to DIVIDING a number by 2. 

    Shift operations are USUALLY FASTER than their equivalent ARITHMETIC operations.


    For example :
        Value	Bitwise Presentation	      result	effect
        a = 14	0	0	0	0	1	1	1	0	14	no
        a << 1	0	0	0	1	1	1	0	0	28	One bit left
        a >> 1	0	0	0	0	0	1	1	1	7	One bit right

*/



/* Example 1: This program demonstrates the right anq left shift operators: */

#include <stdio.h>

void show_binary(unsigned u);

int main(void) {
    unsigned short u;

    u = 45678;

    show_binary(u);
    u = u << 1;
    show_binary(u);
    u = u >> 1;
    show_binary(u);

    return 0;
}

void show_binary(unsigned u) {
    unsigned n;

    for(n=32768; n>0; n=n/2){
        if(u & n) printf("1 ");
        else printf("0 ");
    }
    printf("\n");
}


/*
    The output from this program is
    1011 0010 0110 1110
    0110 0100 1101 1100
    0011 0010 0110 1110 
*/

// Notice that after the left shift '<<', a bit of information has been lost.
    // When the right shift occurs, a zero is brought in & the lost bit never returns




/* Example 2: Since a 'right shift' is the same as a Division by TWO, but faster,
                the show_binary() function in previous example can be made more efficient as shown here: 

                Notice the LOOP-condition: 'n>>1' is used because it's faster than 'n/2'
                    'n' is used instead of 'n>0'
*/

void show_binary(unsigned u) {
    unsigned n;

    for(n=32768; n; n=n>>1){
        if(u & n) printf("1 ");
        else printf("0 ");
    }
    printf("\n");
}




/* Example 3: Write a program that uses the 'shift operators' to MULTIPLY and
                DIVIDE an integer. Have the user enter the initial value. 
                Display the result of each operation. 
*/

#include <stdio.h>

int main(void) {
    int i, j, k;

    printf("Enter a number: ");
    scanf("%d", &i) ;

    j = i << 1; // multiply by 2
    k = i >> 1; // divide by 2

    printf("%d doubled, %d\n", i, j);
    printf("%d halved, %d\n", i, k);

    return 0;
}



/* Example 4: What do the << and >> operators do?
                The <<  and >> are the left and right shift operators, respectively. 
                They shift the bits. */




// ----------------    ROTATE operator    ----------------

/* Example 5: C does not have a ROTATE operator.
                A ROTATE is similar to a shift, except that the 'bit shifted off one end' is inserted onto the other.

                For example, 1010 0000 'rotated left' one place is 0100 0001.

                Write a function called rotate() that rotates a byte left one position each time it is called.
                (Hint, you will need to use a union so that you can have access to the bit shifted off the end of the byte.)
                Demonstrate the function in a program.
*/

#include <stdio.h>

void rotate(unsigned char *c);

int main(void) {
    unsigned char ch;
    int i;

    ch = 1;

    for(i=0; i<16; i++) {
        rotate(&ch);
        printf("%u\n", ch);
    }

    return 0;
}


void rotate(unsigned char *c){
    union {
        unsigned char ch[2];
        unsigned u;
    } rot;

    rot.u = 0; // clear 16 bits
    rot.ch[0] = *c;

    // shift integer left
    rot.u = rot.u << 1;

    // See if a bit got shifted into ch[1], If so, 'bitwise-OR' it back onto the other end.
    if(rot.ch[1]) rot.ch[0] = rot.ch[0] | 1;

    *c = rot.ch[0];
}



