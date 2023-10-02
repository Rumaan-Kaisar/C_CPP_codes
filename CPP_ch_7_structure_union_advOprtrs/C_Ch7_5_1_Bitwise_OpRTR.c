
/* 
    ---------------    Bitwise Operators    ---------------
    Bitwise Operators : 
        c contains four special operators that perform their operations on a bit-by-bit level. these operators are
    
            1.	bitwise AND  :   &
            2.	bitwise OR : 	|
            3.	bitwise XOR (eXclusive OR) :   ^
            4.	1's complement :   ~
    

    These operators work with 'CHARACTER' and 'INTEGER' types; 
        They cannot be used with 'FLOATING-point' types.
        The AND, OR, and XOR operators produce a result based on a comparison of corresponding bits in each operand. 
    
    
    AND:
        The AND operator sets a bit if both bits being compared are set. 
    
          1010  0110
        & 0011  1011

        1	0	1	0	0	1	1	0
        0	0	1	1	1	0	1	1
        0	0	1	0	0	0	1	0

    
    
    OR:
        The OR sets a bit if either of the bits being compared is set. 
    
          1010  0110
        | 0011  1011

    	1	0	1	0	0	1	1	0
        0	0	1	1	1	0	1	1
        1	0	1	1	1	1	1	1

    
    
    XOR:
        The XOR operation sets a bit when "EITHER" of the two bits involved is 1, but not when both are 1 or both are 0. 

          1010  0110
        ^ 0011  1011

    	1	0	1	0	0	1	1	0
        0	0	1	1	1	0	1	1
        1	0	0	1	1	1	0	1

    

    1's complement:
        The 1's complement operator is a unary operator that reverses the state of each bit within an integer or character. 
        Eg:     ~ 10010 = 01101.



    Difference between logical operators and bitwise operators : 

        There are no Logical XOR  and Complement of 1. 
        Also there is no BITWISE  negation (not) operator.

        Logical  operator gives 0 or 1 as output but 
            BITWISE operator gives any integer as output . 
            eg:
                x=1 ⇒   x=   0 0 0 0  0 0 0 1
                y=2 ⇒   y=   0 0 0 0  0 0 1 0

                Bitwise-AND '&' :    0 0 0 0  0 0 0 0 ⇒ 0

                Logical-AND '&&':	 (x && y) = (1 && 2) = (1 && 1) = 1 , since 1 and 2 both positive.


            another example:
                x=3 ⇒   x=   0 0 0 0  0 0 1 1
                y=4 ⇒   y=   0 0 0 0  0 1 0 0

                Bitwise-OR '|' :    0 0 0 0  0 1 1 1 ⇒ 7

                Logical-OR '||':	 (x || y) = (3 || 4) = (1 || 1) = 1 , since 3 and 4 both positive.
	
*/




/* Example 1: The XOR operation has one interesting property. Given two values A and B,
                when the outcome of (A XOR B) is XORed with B a second time, A is produced.

                            i.e.    A = (A XOR B) XOR B
                
                Notice in the follwoing example.

                        initial value of i: 100
                        i after first XOR: 21895
                        i after second XOR: 100

                    is produced by the following program.   */

#include <stdio.h>
int main(void) {
    int i;

    i = 100;
    printf("initial value of i: %d\n", i);

    i = i ^ 21987;
    printf("i after first XOR: %d\n", i);

    i = i ^ 21987;
    printf("i after second XOR: %d\n", i);

    return 0;
}




/* Example 2: The following program uses a 'bitwise AND' to display, in binary,
                the ASCII value of a character typed at the keyboard:                 

                The program works by 'adjusting the value of i' so that only one bit is set each time a comparison is made.
                    Since the high-order bit in a byte represents 128, this value is used as a starting point.
                    Each time through the loop, i is halved.
                    This causes the next bit position to be set and all others cleared.

                128 in Binary is 1000 0000
                    ASCII uses seven-digit binary numbers—i.e., numbers consisting of various sequences of 0's and 1's. 
                    Since there are 128 different possible combinations of seven 0's and 1's, the code can represent 128 different characters

                Thus, each time through the loop, a bit in 'ch' is tested. 
                    If it is 1, the comparison produces a true result and a 1 is output. 
                    Otherwise a 0 is displayed. 

                This process continues until all bits have been tested                */

#include <stdio.h>
#include <conio.h>

int main(void) {
    char ch;
    int i;

    printf("Enter a character: ");
    ch = getche();

    printf("\n");

    // display binary representation
    for(i=128; i>0; i=i/2){
        if(i & ch) printf("1 ");    // using Bitwise AND
        else printf("O ");
    }

    return 0;
}




/* Example 3: By modifying the program from Example 2. it can be used to show the effect of the 1's complement operator. 
                When you run this program, you will see that the state of bits in
                ch are reversed after the '~' (1's compliment) operation has occurred.*/

#include <stdio.h>
#include <conio.h>

int main(void){
    char ch, rvch;
    int i;

    ch = 'a';

    // display binary representation
    for(i=128; i>0; i=i/2){
        if(i & ch) printf("1 ");    // using Bitwise AND
        else printf("O ");
    }

    // reverse bit pattern: use of '~'
    rvch = ~ch;
    printf("\n");

    // display binary representation of reverse bits
    for(i=128; i>0; i=i/2){
        if(i & rvch) printf("1 ");    // using Bitwise AND
        else printf("O ");
    }

    return 0;
}




/* Example 4: The following program shows how to use the '&' operator to determine if a signed integer is positive or negative. 
                (The program assumes short integers are 16 bits long.) 
                
                Since negative numbers are represented with their high-order bit set, the comparison will be true only if 'i' is negative. 
                    (The value 32768 is the value of an 'unsigned short integer' when only its high-order bit is set. 
                        This value is 1000 0000 0000 0000 in binary.) */

#include <stdio.h>

int main(void){
    short i;
    printf("Enter a number: ");
    scanf("%hd", &i);

    if(i & 32768) printf("Number is negative.\n " );

    return 0;
}




/* Example 5: The following program makes i into a negative number by setting its high-order bit.
                (Again, 16-bit short integers are assumed.) */

#include <stdio.h>
int main(void){
    short i;

    i = 1;
    i = 1 | 32768;  // applying 'OR'

    printf("%hd", i);

    return 0;
}
// It displays '-32767'




/* Example 6: One very easy way to encode a file is to reverse the state of each bit using the '~' operator.
                Write a program that encodes a file using this method.
                (To decode the file, simply run the program a second time.)
                Have the user specify the name of the file on the command line. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *in, *out;
    unsigned char ch;

    if(argc!=3) {
        printf("Usage: code <in> <out>\n");
        exit(1);
    }

    // read
    if((in = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open input file.\n");
        exit(1);
    }

    // write
    if((out = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open output file.\n");
        exit(1);
    }

    // putting the encoded characters into 'out' file
    while(!feof(in)) {
        ch = fgetc(in);
        if(!feof(in)) fputc(~ch, out);
    }

    // closing the files
    fclose(in);
    fclose(out);

    return 0;
}

// save-compile the code as : 'opr_adv_4_btw6.c'
// CLI:      opr_adv_4_btw6 neg_encd neg_encoded
// CLI:      opr_adv_4_btw6 neg_encoded neg_decoded




/* Example 7: Earlier we wrote a program that encoded files using the 1's complement operator.
                Write a program that reads a text file encoded using this method
                    and displays its decoded contents.
                Leave the actual file encoded, however. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in;
    unsigned char ch;

    if(argc!=2) {
        printf("Usage: code <in>\n");
        exit(1);
    }

    if((in = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open input file.\n");
        exit(1);
    }


    while (!feof(in)) {
        ch = fgetc(in);
        if(!feof(in)) putchar(~ch);
    }

    fclose(in);

    return 0;
}

// adv_cumul_4_1sc neg_encoded




/* Example 8: A better method of coding a file uses the 'XOR' operation combined wah a user-defined key. 
                Write a program that encodes a file using this method. Have the user specify the file
                to code as well as a single character key on the command line.
                (To decode the file, run the program a second time using the same key.) */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in, *out;
    unsigned char ch;

    if(argc!=4){
        printf("Usage: code <in> <out> <key>\n");
        exit(1);
    }

    // read
    if((in = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open input file.\n");
        exit(1);
    }

    // write
    if((out = fopen(argv[2], "wb")) == NULL) {
        printf("Cannot open output file.\n");
        exit(1);
    }

    // putting the encoded characters into 'out' file
    while(!feof(in)) {
        ch = fgetc(in);
        ch = *argv[3] ^ ch; // applying 'XOR'
        if(!feof(in)) fputc(ch, out);
    }

    // closing the files
    fclose(in) ;
    fclose (out);

    return 0;
}

// save-compile the code as : 'opr_adv_btw7.c'
// CLI:      opr_adv_btw7 XOR_encd XOR_encoded 7
// CLI:      opr_adv_btw7 XOR_encoded XOR_decoded 7




/* Example 9: What is the outcome of these operations? 
                A. 1010 0011 & 0101 1101
                B. 0101 1101 | 1111 1011
                C. 0101 0110 ^ 1010 1011
*/

a. 0000 0001
b. 1111 1111
c. 1111 1101




/* Example 10: Sometimes, the high-order bit of a byte is used as a 'parity bit' by 'modem programs'. 
                It is used to 'verify' the 'integrity' of each byte transferred. 

                There are two types of 'parity': 'even' and 'odd'. 
                    If even parity is used, the parity bit is used to ensure that each byte has an even number of 1 bits.
                    If odd parity is used, the parity bit is used to ensure that each byte has an odd number of 1 bits. 

                Since the parity bit is not part of the information being transferred, 
                    show how you can clear the high-order bit of a character value. */

char ch;
.
.
.

/* 
    To zero high order bit, 'AND' with '127', which in binary is 0111 1111. 
    This causes the high order bit to be 'zeroed' and all other bits left untouched. 
*/

ch = ch & 127;




/* Example 11: What is the outcome of these operations? 

                a. 1101 1101 & 1110 0110
                b. 1101 1101 | 1110 0110
                c. 1101 1101 ^ 1110 0110
Ans: 
    a. 1100 0100
    b. 1111 1111
    c. 0011 1011
*/




/* 
    Letter	ASCII Code	Binary

    a	    097	        0110 0001
    b	    098	        0110 0010
    c	    099	        0110 0011
    d	    100	        0110 0100
    e	    101	        0110 0101
    f	    102	        0110 0110
    g	    103	        0110 0111
    h	    104	        0110 1000
    i	    105	        0110 1001
    j	    106	        0110 1010
    k	    107	        0110 1011
    l	    108	        0110 1100
    m	    109	        0110 1101
    n	    110	        0110 1110
    o	    111	        0110 1111
    p	    112	        0111 0000
    q	    113	        0111 0001
    r	    114	        0111 0010
    s	    115	        0111 0011
    t	    116	        0111 0100
    u	    117	        0111 0101
    v	    118	        0111 0110
    w	    119	        0111 0111
    x	    120	        0111 1000
    y	    121	        0111 1001
    z	    122	        0111 1010

    A	    065	        0100 0001
    B	    066	        0100 0010
    C	    067	        0100 0011
    D	    068	        0100 0100
    E	    069	        0100 0101
    F	    070	        0100 0110
    G	    071	        0100 0111
    H	    072	        0100 1000
    I	    073	        0100 1001
    J	    074	        0100 1010
    K	    075	        0100 1011
    L	    076	        0100 1100
    M	    077	        0100 1101
    N	    078	        0100 1110
    O	    079	        0100 1111
    P	    080	        0101 0000
    Q	    081	        0101 0001
    R	    082	        0101 0010
    S	    083	        0101 0011
    T	    084	        0101 0100
    U	    085	        0101 0101
    V	    086	        0101 0110
    W	    087	        0101 0111
    X	    088	        0101 1000
    Y	    089	        0101 1001
    Z	    090	        0101 1010
*/


