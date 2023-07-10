OPERATORs Advanced - 3

7.8.2 The Comma Operator : The comma operator has a very unique function: it tells the compiler to "do this and this and this". That is, the comma is used to string together several operations. 
	The most common use of the comma is in the for loop. In the following loop, the comma is used in the initialization portion to initialize two loop-control variables, and in the increment portion to increment i and j.
for(i=0, j=0 ; i+j<count ; i++, j++) ...
	The value of a comma-separated list of expressions is the rightmost expression. For example, the following statement assigns 100 to value:
value = (count, 99, 33, 100);
The parentheses are necessary because the comma operator is lower in precedence than the assignment operator.

