/* 
    C - OPERATORS
        C divides the operators into the following groups:

        Arithmetic operators: 
            +	Addition:       x + y	
            -	Subtraction     x - y	
            *	Multiplication  x * y	
            /	Division        x / y	
            %	Modulus         x % y	(returns division remainder)
            ++	Increment	    ++x	
            --	Decrement	    --x


        Assignment operators:
            // shortcut assignment with arithmetic operators
                    =	  x = 5	x = 5	
                    +=	  x += 3	x = x + 3	
                    -=	  x -= 3	x = x - 3	
                    *=	  x *= 3	x = x * 3	
                    /=	  x /= 3	x = x / 3	
                    %=	  x %= 3	x = x % 3
            
            // shortcut assignment with logical operators
                    &=	  x &= 3	x = x & 3	
                    |=	  x |= 3	x = x | 3	
                    ^=	  x ^= 3	x = x ^ 3

            // shortcut assignment with bitwise operators	
                    >>=	  x >>= 3	x = x >> 3	
                    <<=	  x <<= 3	x = x << 3
        
        
        Comparison operators:
            ==	    Equal to	        x == y	
            !=	    Not equal	        x != y	
            >	    Greater than	    x > y	
            <	    Less than	        x < y	
            >=	    Greater or equal 	x >= y	
            <=	    Less  or equal 	    x <= y


        Logical operators:
            && 	Logical and		x < 5 &&  x < 10	
            || 	Logical or	    x < 5 || x < 4	
            !	Logical not     !(x < 5 && x < 10)


        Bitwise operators:
            &   (bitwise AND)   in C or C++ takes two numbers as operands and does AND on every bit of two numbers. The result of AND is 1 only if both bits are 1.  
            |   (bitwise OR)    in C or C++ takes two numbers as operands and does OR on every bit of two numbers. The result of OR is 1 if any of the two bits is 1. 
            ^   (bitwise XOR)   in C or C++ takes two numbers as operands and does XOR on every bit of two numbers. The result of XOR is 1 if the two bits are different. 
            <<  (left shift)    in C or C++ takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift. 
            >>  (right shift)   in C or C++ takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift. 
            ~   (bitwise NOT)   in C or C++ takes one number and inverts all bits of it. 

        Sizeof Operator:
            The memory size (in bytes) of a data type or a variable can be found with the sizeof operator.
                int myInt;
                float myFloat;
                double myDouble;
                char myChar;

                printf("%lu\n", sizeof(myInt));
                printf("%lu\n", sizeof(myFloat));
                printf("%lu\n", sizeof(myDouble));
                printf("%lu\n", sizeof(myChar));

*/



/* 
    professionally written C code:
                if(count != 0) 
            written as
                if(count)

        in C, true is any nonzero value and false is zero. 

                if(count == 0)
            generally written as: 
                if(!count)
*/



/* 
    relational-logical operators combination:
            var > max || !(max==100) && 0 <= item

    Though C defines true as any nonzero value, the relational and logical operators always produce the value 1 for true. 
    remember that the outcome of a relational or logical operation is 0 when false and 1 when true.


    C does not define an exclusive-OR (XOR) logical operator, need to create as follows:
    
    int xor(int a, int b) { return (a || b) && !(a && b) ; }

    0&&1||1 and 0&&(1||1) do not evaluate to the same outcome according to precedence of the logical operators.

    If a program runs for  (a==x)||(b==y)||(c==z)||(d==t) then it not runs for  (a!=x)&&(b!=y)&&(c!=z)&&(d!=t)
 */



3. Do these two expressions evaluate to the same outcome?

#include <stdio.h>

int main(void){
    int i;
    
    i = !(10==9); // !(10==9)  expression true
    printf("%d\n", i);
    
    // "0 && 1 || 1" and "0 && (1 || 1)"are not the same 
    printf("%d\n", 0 && 1 || 1);
    printf("%d\n", 0 && (1 || 1));
    
    return 0;
}
