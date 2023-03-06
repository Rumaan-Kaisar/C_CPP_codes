


/* ----------  DATA - TYPE MODIFIERS   -----------------
    C has five basic data types: 
        void, 
        char, 
        int, 
        float, and 
        double. 
These basic types, except type void, can be modified using C's type modifiers
                long	
                short	
                signed	
                unsigned
The type modifier precedes the type name. For example, this declares a long integer: 	

            long int i;

long and short modifiers : applied to int.
    in most 16-bit environments, an int is 16 bits long and a 
    long int is 32 bits in length.
 
signed modifier : to specify a signed integer value. (A signed number means that it can be positive or negative.) 
    Default integer declaration automatically creates a signed variable so there is no need of signed modifier. 
    
    The main use of the signed modifier is with char. 
    To ensure a signed character variable in all environments, we must declare it as  signed char. 

unsigned modifier : The unsigned modifier can be applied to char and int. 
    It may also be used in combination with long or short. 
    It is used to create an unsigned integer.

in signed and unsigned integers the high-order bit is interpreted differently. 
Signed integers are important for a great many algorithms, 
but they only have half the absolute magnitude of their unsigned relatives . 

For example, here is 32,767 shown in binary:
    0 111111111111111 (= +32767)
unsigned and signed difference:
so unsigned 1 111111111111111 (= 65535)
sand signed 1 111111111111111 (= -32767)
If this is a signed value and the high-order bit is set to 1, the number would then be interpreted as -1 (assuming two's complement format). 
However, if this is an unsigned value, then when the high-order bit is set to 1, the number becomes 65,535.


Type	                Typical size in bits	        Minimal range
char	                8 or 1 byte	                    -127 to 127 (related to  2^8)/2
unsigned char	        8 or 1 byte	                    0 to 255 (related to  2^8)
signed char	            8 or 1 byte	                    -127 to 127 (related to  2^8)/2
int	                    16 or 32 (2 byte or 4 byte)	    -32,767 to 32,767 (related to  2^16)/2
unsigned int	        16 or 32 (2 byte or 4 byte)	    0 to 65,535 (related to  2^16)
signed int	            16 or 32 (2 byte or 4 byte)	        Same as int
short int	            6 (2 byte)	                        Same as int
unsigned short int	    16 (2 byte)	                    0 to 65,535 (related to  2^16)
signed short int	    16 (2 byte)	                    Same as short int i.e. int
long int	            32 (4 byte)	                    -2,147,483,647   to   2,147,483,647    (2^32)/2
signed long int	        32 (4 byte)	                        Same as long int
Unsigned long int	    32 (4 byte)	                    0 to 4,294,967,295     (2^32)
float	                32 (4 byte)	                    Six digit of precision
double 	                64 (8 byte)	                    Ten  digit of precision
long double	            80 (10 byte)	                Ten  digit of precision

bit  and byte:  
    1 and 0 are bit's . And 1 byte = 8 bit. 
    In 1 byte or 8 bit we can have 00000000 or 11111111 or any combination of 1's and 0's out of total  256 (=2^8) combinations.  
    In the case of signed data type 1 bit is used for signing.



Notes :
1.	C allows a shorthand notation for declaring unsigned, short, or long integers. 
    We can simply use the word unsigned, short, or long without the int. The int is implied autometically. 
    For example, both declare unsigned int variables.
        unsigned count;
        unsigned int num;

2.	A signed char variable can also be used as a 'small' integer when the situation does not require larger numbers.\

3.	When outputting integers modified by short, long, or unsigned using printf( ), you cannot simply use the %d specifier. 
        to output a short, use      %hd
        To output a long, use       %ld
        an unsigned value, use      %u
        an unsigned long int, use   %lu
        a long double use           %Lf (upper case L ?).

4.	scanf( ) 
        When reading a short int use    %hd
        When reading a long int, use    %ld
        an unsigned long int, use       %lu
        a double, use                   %lf
        a long double, use              %Lf

 */



/* Example 1: This program shows how to input and output short, long, and
unsigned values. */
#include<stdio.h>
int main(void){
    unsigned u;
    long l;
    short s;

    printf("Enter an unsigned: ");
    scanf("%u",&u);
    printf("Enter a long: ");
    scanf("%ld",&l);
    printf("Enter a short: ");
    scanf("%hd",&s);

    printf("%u %ld %hd\n", u, l, s);
    
    return 0;
}



/* Example 2: Difference bttween the way that signed and unsigned integers are interpreted by C, 
This program assumes that short integers are 16 bits wide. 
the output is -32536 & 33000.*/
#include<stdio.h>
int main(void){
    short int i;    // signed short integer
    unsigned short int u;   // unsigned short integer

    u=33000;
    i=u;
    printf("%hd %hu",i,u);

    return 0;
}



/* Example 3: use a char variable any place you would use an
int variable. the following program uses a char variable
to control the loop that is summing the numbers between 1 and
100.
the computer takes less time to access a single byte (one character) than it doe, to access two bytes. */

#include<stdio.h>
int main(void){
    int i;
    char j;

    i=0;
    for(j=1;j<101;j++) i=i+j;

    printf("Total is: %d",i);

    return 0;
}



/* Examp00le 4: Write a program that prompts the user for a distance and
computes how long it takes light to travel that distance" Use an
unsigned long int to hold the distance. (Light travels at
approximately 186,000 miles per second.) */
#include<stdio.h>
int main(void){
    unsigned long int distance;

    printf("Enter distance:");
    scanf("%lu", &distance);

    printf("Time taken: %lu seconds", distance/186000);

    return 0;
}

/* declare an unsigned short int called "loc_counter"
    short loc_counter 
Write this statement another way:
short int i;    // general
short i;    // shorthand
*/



/* 
    C compiler will assign the following types:
            10      int
            10000   int
            123.45  double
            123564  long
            -45099  long
 */

/* Example 5: Write a program that inputs a long, a short, and a double and 
                then writes these values to the screen. */

#include <stdio.h>
int main(void){
    long lg;
    short s;
    double d;

    printf("Enter a long value: ");
    scanf ("%ld", &lg);

    printf("Enter a short value: ");
    scant ("%hd", &s);

    printf("Enter a double value: ");
    scanf("%lf", &d);
    
    printf("%ld\n", lg);
    printf("%hd\n", s);
    printf("%f\n", d);  // notice "%lf" Not Used for output

    return 0;
}
