/* 
    Type conversion in  "Assignment" : 
        the type of right side is converted into type of  left. 

        left side type is larger than right, no problems. 
        But if left is smaller than right, data loss may occur. 

                Following displays -24: 	

                    char ch; 
                    int i; 
                    
                    i = 1000; 
                    ch = i;

        reason is, only the 'low-order eight bits' of i are copied into ch . 
        Since this kind of assignment type conversion is not an error in C, no error message will be received. 

    When there is an 'integer-to-character' or a 'longer-integer to shorter-integer' type conversion across an assignment, 
    the basic rule is that the appropriate number of "high-order bits" will be removed. 

        In many environments, 8 bits will be lost when going from an int to a char, and 16 bits will be lost when going from a long to an int.
        When converting from a "long double" to a "double" or from a 'double to a float', "precision" is lost. 
        When converting from a 'float to an int', the "fractional" part is lost, and if the number is too large to fit in the target type, a garbage value will result.

        The conversion of an 'int to a float' or a 'float to double', and so on, will 'not add any precision or accuracy'. 
            These kinds of conversions will only change the form in which the value is represented. 
        
        Some C compilers will always treat a 'char' variable as an 'unsigned' value. Others will treat it as a 'signed' value. Thus, what will happen when a character variable holds a value greater than 127 is implementation-dependent.
        
        It is best to declare the variable explicitly as either signed or unsigned.
*/



/* Eaxmple 1: when the type of the left side is smaller than the type of the right, data loss may
                occur. For example, this program displays -24: */
#include<stdio.h>

int main(void){
	char ch;
	int i;

	i = 1000;
	ch = i;

	printf ("%d", ch);

	return 0;
}



/* Example 2: converting from a floating-point value to an integer value, the fractional portion of the number is lost. 
                The follOWing program illustrates this fact. It prints 1234. */
#include<stdio.h>

int main(void){
    int i;
    float f;

    f= 1234.0098;
    i= f;   // convert to int

    printf("%f %d ", f, i);

    return 0;
}



/* Example 3: When converting from a larger integer type to a smaller one, it is possible to generate a garbage value, as this program illustrates. 
                (This program assumes that short integers are 16 bits long and that long integers are 32 bits long.) */
#include<stdio.h>

int main(void){
    short int si;
    long int li;

    li= 100000;
    si= li;     //convert to short int

    printf("%hd ", si);

    return 0;
}



/* Example 4: this program displays 10. */
#include<stdio.h>

int main(void){
    int i;
    long double ld;

    ld=10.00;
    i=ld;
    printf("%d",i);

    return 0;
}



/* Example 5: this program displays 3.0. */
#include<stdio.h>

int main(void){
    float f;
    f=10/3;
    printf("%f",f);

    return 0;
}

