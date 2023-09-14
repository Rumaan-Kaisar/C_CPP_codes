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

*/



I. The XOR operation has one interesting property. Given two
values A and B, when the outcome of A XOR B is XORed with B
a second time, A is produced. For example, thi& output
initial value of i: 100
i after first XOR: 21895
i after second XOR: 100
is produced by the following program:
#include <stdio.h>
int main(voidl
(
int i;
i = 101);
printf("initial value of i: %d\n-, il;
i = i ;, 21987;
printf(-i after first XOR: %d\n", i);
i = i A 21987;
printf{"i after second XOR: %d\n", il;
return 0;
)


2. The following program uses a bitwise AND to display, in binary,
the ASCII value of a character typed at the keyboard:
#include <stdio.h>
#include <conio.h>

int main (void)
(
)
char chi
lnt i;
printf(MEnter a character: ");
ch = getche();
printf{"\n") ;
j* display bin~ry representation *;
for(i=128; i>oi .i=i/2)
if(l & chI printf("l ");
else printf("O ");
return 0;
'f.he program works by adjusting the value of i so that only one
bit is set each time a comparison is made. Since the high-order
bit in a byte represents 12B. this value is used as a starting point.
Each time through the loop. i is halved. This causes the next
bit position to be set and all others cleared. Thus. each time
through the loop. a bit in eh is tested. If it is I. the comparison
produces a true result and a I is output. Otherwise a 0 is
displayed. This process continues until all bits have been tested



3. By modifying the program from Example 2. it can be used to
show the effect of the 1's complement operator.
#include <stdio.h>
#include <conio.h>
int main (void)
(
char Chi
int i;
ch = 'a';
/*. ?isplay binary representation ~ I
for!i=128; i>O; i=i/2)
ifli & ch) printfl"l ");
else printf("Q ");
j * reverse bit patt~rn */

ch = -Chi
printf("\n") ;
/ * display binary representation */
for(i=128: i>Oi i=i/2)
if(i & chI printf("l .);
else printf{"O .);
return 0;
, 1.5 USE C'S BITWISE OPERATORS
When you run this program, you will see that the state of bits in
ch are reversed after the N operation has occurred.
4. The following program shows how to use the [5 operator to
determine if a signed integer is positive or negative. (The
program assumes short integers are 16 bits long.) Since negative
numbers are represented with their high-order bit set, the
comparison will be true only if i is negative. (The value 32768 is
the value of an unsigned short integer when only its high-order
bit is set. This value is \000 0000 in binary.)
#include <stdio.h>
iot main (void)
(
short i;
printf("Enter a number: "I;
scanf("%hd", &i);
•
if(i & 32768) printf("Number is negative.\n M ):
return 0;
}
5. The following program makes i into a negative number
by setting its high-order bit. (Again, 16-bit short integers
are assumed.)
#include <stdio.h>
int rnain(void)
(
short i;

i :: 1;
i=iI32768;
printf("%hd", il;
return 0;
It displays - 32 ,767




1. One very easy way to encode a file is to reverse the state of each
bit using the N operator. Write a program that encodes a file
using this method. (To decode the file, simply run the program
a second time.) Have the user specify the name of the file on
_ -the command line.

'includ~ <stdio.h>
'include <stdlib.h>
int mainCint argc, char ·argv[1)
{
FILE *in. ·out;
unsigned char chi
if(argc!=3) (
printf(-Usage: code <in> <out>\p~);
exit (1);
) .'
}
if «in = fopen (argv [1] , "rb")) ==NULL) (
printf{-Cannot open input file.\n-);
exit(l);
}
if«out = fopen(argv[2], "wb"})==NULL) (
printf(·Cannot open output file.\n-);
exit(l);
}
while ( !feof (in)) (
}
ch = fgetc (in) ;
if(!feof(in)) fputc(-ch,
fclose(in) ;
fclose{out) ;
return 0;




2. A better method of coding a file uses the XOR operation
combmed wah a user-defined key. Write a program that
encodes a file using this method. Have the user speCJfy the file
to code as "'ell as a single character key on the command line.
(To decode the me, run the program a second time using the
Silme key.)

'include <stdio. h>
'include <stdlib.h>
}
int main(int argc, char *argv[])
!
FILE *in, "out:
unsigned char Chi
if(argc!=4) !
}
printf(~Usage: code <in> <out> <key>\n-):
eXit(l);
if(! in = fopen(argv[l]. "rb"))==NULL) !
printfC-Cannot open input file.\nW);
exit!l);
}
if«out. fopen (argv[2]. "wb"))==NULLI !
printf(-Cannot open output file.\n-);
exit(l);
}
while! ! feof (in)) !
ch = fgetc (in) ;
}
ch = *argv(3) ~ chi
if(!feof(in) ) fputc(ch. out);
fclose (in) ;
fclose (out) ;
return 0;



3. What is the outcome of these operations?
A 1010 001 J [< OIOJ J JOJ
B OIOJ 1I0J I J Il J lOll
C. OIOJ 01 JO A IOJO 101 J

a. 0000 0001
b. lUI lUI
c. lUI 1101



4. Sometimes, the high-order bit of a byte is used as a panty bIt by
modem programs. It is used to verify the integrity of each byte
transferred. There are two types of parity: even and odd. If even
parity is used, the parity bit is used to ensure that each byte has
an even number of 1 bits. If odd parity is used, the parity bit is
used to ensure that each byte has an odd number of 1 bits. Since
the parity bit is not part of the information being transferred,
show how you can clear the high-order bit of a character value

char chi
.
.
.
/ - To zero high order bit. AND with 127, which
*/
in binary is 0111 1111. This causes the h i ghorder bit to b~ zeroed and all other bits left
untouched.
ch = ch & 127;


