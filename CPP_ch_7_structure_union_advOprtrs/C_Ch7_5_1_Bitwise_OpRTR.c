
Bitwise
Bitwise Operators : c contains four special operators that perform their operations on a bit-by-bit level. these operators are
 
1.	bitwise AND  :   &
2.	bitwise OR : 	|
3.	bitwise XOR (eXclusive OR) :   ^
4.	1's complement :   ~
 

	These operators work with character and integer types; they cannot be used with floating-point types.
	The AND, OR, and XOR operators produce a result based on a comparison of corresponding bits in each operand. 

	The AND operator sets a bit if both bits being compared are set. 
  1010  0110
& 0011  1011	1	0	1	0	0	1	1	0
	0	0	1	1	1	0	1	1
	0	0	1	0	0	0	1	0

	The OR sets a bit if either of the bits being compared is set. 
  1010  0110
| 0011  1011	1	0	1	0	0	1	1	0
	0	0	1	1	1	0	1	1
	1	0	1	1	1	1	1	1

	The XOR operation sets a bit when either of the two bits involved is 1, but not when both are 1 or both are 0. 
  1010  0110
^ 0011  1011	1	0	1	0	0	1	1	0
	0	0	1	1	1	0	1	1
	1	0	0	1	1	1	0	1

Notice how the resulting bit is set, based on the outcome of the operation being applied to the corresponding bits in each operand.

	The 1's complement operator is a unary operator that reverses the state of each bit within an integer or character. 
Eg:     ~ 10010 = 01101.

	
