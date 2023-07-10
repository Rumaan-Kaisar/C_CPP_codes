
Shift Operators : C includes two operators not commonly found in other computer languages: the left and right bit-shift operators. These operators may be applied only to character or integer operands. They take these general forms:

value << number-of-bits
Value >> number-of-bits

The integer expression specified by "number-of-bits" determines how many places to the left or right the bits within value are shifted. When bits are shifted off an end they are lost.
	The left shift operator is <<  . Each left-shift causes all bits within the specified value to be shifted left one position and a zero is brought in on the right. a left shift is the same as multiplying the number by 2. 
	The right shift operator is >> .  A right-shift shifts all bits to the right one position and brings a zero in on the left. (Unless the number is negative, in which case a one is brought in).  A right shift is equivalent to dividing a number by 2. 

Because of the internal operation of virtually all CPUs, shift operations are usually faster than their equivalent arithmetic operations.

For example :
Value	Bitwise Presentation	result	effect
a = 14	0	0	0	0	1	1	1	0	14	no
a << 1	0	0	0	1	1	1	0	0	28	One bit left
a >> 1	0	0	0	0	0	1	1	1	7	One bit right



Note 
	The XOR operation has one interesting property. Given two values A and B, when the outcome of A XOR B is XORed with B a second time (i.e. (A ^ B) ^ B = A), A is produced. For example, this output
initial value of i: 100
i after first XOR with 21987: 21895
i after second XOR with 21987: 100
is produced by the following program:
#include<stdio.h>
int main(void)
    {int i;
     i = 100; printf("initial value of i: %d\n", i);
     i = i ^ 21987; printf("i after first XOR with 21987: %d\n", i);
     i = i ^ 21987; printf("i after second XOR with 21987: %d\n", i);
return 0;}
	Difference between logical operators and bitwise operators : 
Logical  operator gives 0 or 1 as output but bitwise operator gives any integer as output . For example consider following  two  examples ,
 Say x=1, y=2. Then x&&y=1 and x&y=0.
Logical  "AND" && :	 x&&y = 1&&2 = 1&&1 = 1 , since 1 and 2 both positive.
Bitwise  " AND " & : 	x=1⇒x=0 0 0 0  0 0 0 1
					y=2⇒x=0 0 0 0  0 0 1 0
								
					                          0 0 0 0  0 0 0 0 ⇒0

Say x=3, y=4. Then x||y=1 and x|y=0.
Logical  "OR"   || :	 x&&y = 3||4 = 1||1 = 1 , since 3 and 4 both positive.
Bitwise  "OR"   | : 	x=3⇒x=0 0 0 0  0 0 1 1
				y=4⇒x=0 0 0 0  0 1 0 0
							
				                          0 0 0 0  0 1 1 1 ⇒7
	There are no Logical XOR  and Complement of 1. Also there is no BITWISE  negation (not) operator.
	One use of Bitwise XOR is encrypting password.

