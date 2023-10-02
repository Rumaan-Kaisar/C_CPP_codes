
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



/* Example 3 (small): Write a program that uses the 'left and right shift' operators
                to double and halve a number entered by the user. */
#include <stdio.h>

int main(void) {
    int i;

    printf("Enter a number: ");
    scanf ("%d", &i);
    printf("Doubled: %d\n", i << 1);
    printf("Halved: %d\n", i >> 1);

    return 0;
}




/* Example 4: What do the << and >> operators do?
                The <<  and >> are the left and right shift operators, respectively. 
                They shift the bits. */




/* Example 5: Write a program that inputs two characters and compares corresponding 'bits'.
                Have the program display the 'number of each bit' in which a match occurs.
                    For example, if the two integers are
                            1001 0110
                            1110 1010
                the program will report that bits 7, 1, and 0 match. From Right to left index
                (Use the bitwise operators to solve this problem.)
*/

#include <stdio.h>
#include <conio.h>

int main(void) {
    char ch1, ch2;
    char mask, i;

    printf("Enter two characters: ");
    ch1 = getche();
    ch2 = getche();
    printf("\n");

    mask = 1;
    for(i=0; i<8; i++) {
        // find matching 1 in bits
        // notice the use of 'Logical-and' & 'bitwise-and'
        if((mask & ch1) && (mask & ch2)) printf("bits %d has the same 1's \n", i);
        // to find all matching 0's and 1's use following with '==' instead
        if((mask & ch1) == (mask & ch2)) printf("bits %d the same\n", i);
        mask <<= 1; // making left-shift
        printf("\n");
    }

    return 0;
}




// ----------------    ROTATE operator    ----------------

/* Example 6: C does not have a ROTATE operator.
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




/* Example 7: Write a program that swaps the 'low-order four bits of a byte' with the 'high-order four bits'.
                Demonstrate that your routine works by displaying the contents of the byte before and after,
                    using the show_binary() function developed earlier.
                (Change show_hinary() so that it works on an eight-bit quantity, however.) */

#include <stdio.h>

void show_binary(unsigned u);

int main(void){
    unsigned char ch, t1, t2;

    ch = 100;
    printf("%d\n", ch);
    show_binary(ch);

    t1 = ch;
    t2 = ch;

    t1 <<= 4;   // left shifing 4 bits
    t2 >>= 4;   // right shifing 4 bits

    ch = t1 | t2;   // unify sifted bits to make the 'swapped bits'

    show_binary(ch);
    printf("%d", ch);

    return 0;
}


void show_binary (unsigned u){
    unsigned n;

    for(n=128; n>0; n /= 2) {
        if(u & n) printf("l ");     // applying bitwise &
        else printf("0 ");
    }
    printf("\n");
}


