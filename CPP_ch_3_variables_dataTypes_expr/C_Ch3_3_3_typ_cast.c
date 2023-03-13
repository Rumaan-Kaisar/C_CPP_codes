/* 
    TYPE-CAST
    A type cast temporarily changes the type of a variable. For
    example, here the 'int i' is temporarily changed into a double.

    (double) i;
 */



/* 	------------    The TYPE CASTS    ------------
	Transform the type of a variable temporarily. A type cast takes this general form: 
					(type) value


	You cannot cast a variable that is on the left side of an assignment statement. For example: this is an invalid statement in C:
					int num; 	(float) num = 123.23; 	//this is incorrect

	For example, the "modulus" operator can only be used on integer values, but we have float

		One solution is to create an integer variable for use in the modulus operation and 
		assign the value of the floating-point variable to it.

		But a type cast is a perfect solution, which causes a temporary type change. 

			float f;
			int modulus; 	

			f = 100.2;
			modulus = (int)f%17;

*/



/* Example 1 : The "modulus" operator can only be used on integer values, but we have float */
#include<stdio.h>

int main(){
	float f;
	int modulus; 	

	f = 100.2;
	modulus = (int)f%17;


	// print f as an integer
	printf("%d", (int) f);

	// print the modulus
	printf("Modulus is %d", modulus);

	return 0;
}



/* Example 2: The single argument of sqrt() must be of type double. It also returns a double value. 
				It uses the <MATH.H> header file.
				Following program prints the square roots of the numbers between 1 and 100 using a for loop.
				It also prints the whole number portion and the fractional part of each result separately. 
				To do so, it uses a type cast to convert sqrt()'s return value into an int. */
#include<stdio.h>
#include<math.h>

int main(){
    double i;

    for(i=1.0; i<101.0; i++){
		printf("The square root of %lf is %lf\n", i, sqrt(i));
		printf("Whole number part: %d\t", (int)sqrt(i));
		printf("Fractional part: %lf\n", sqrt(i)-(int)sqrt(i));
		printf("\n");
    }

    return 0;
}



/* Example 3: You cannot cast a variable that is un the lett side of an assigmTIcnt statement. */
int num;
(float) num = 123.23; //this is incorrect



/* Example 4: Write a program that uses for to print the numbers 1 to 10 by tenths.
				Use a floating-point variable to control the loop.
				However, use a type cast so that the "conditional expression" is
				evaluated as an "integer expression" in the interest of speed */
#include<stdio.h>
int main(void){
	float f;

	for(f=1.0; (int)f <= 9; f = f + 0.1) printf("%f ", f);
	// (int)f <= 9  is integer expression
	// loop is controlled by float
	
	return 0;
}



/* Example 5: Since a floating point value cannot be used with the % operator,
				how can you fix this statement?
				x = 123.23 % 3;  //fix this statement */
x = (int)123.23 % 3;  
