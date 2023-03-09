/* 
    TYPE-CAST
    A type cast temporarily changes the type of a variable. For
    example, here the 'int i' is temporarily changed into a double.

    (double) i;
 */



3.6 The  TYPE CASTS
To transform the type of a variable temporarily. For example, to use a floating-point value for one computation, but wish to apply the modulus operator to it elsewhere. Since the modulus operator can only be used on integer values, we have a problem. One solution is to create an integer variable for use in the modulus operation and assign the value of the floating-point variable to it when the time comes. This is a somewhat inelegant solution, however. The other way around this problem is to use a type cast, which causes a temporary type change. A type cast takes this general form: 
				(type) value	 .
where type is the name of a valid C data type. For example,
float f; 	f = 100.2;
/*print f as an integer */
printf("%d", (int) f);

	The single argument of sqrt( ) must be of type double. It also returns a double value. 
	You cannot cast a variable that is on the left side of an assignment statement. For example: this is an invalid statement in C:
 int num; 	(float) num = 123.23; 	/ * this is incorrect * /



As you learned in Chapter I, sqrt( ) , one of C's library
functions, returns the square root of its argument. It uses the
MATH.H header file. Its single argument must be of type
double. It also returns a double value. The following program
prints the square roots of the numbers between 1 and 100 using
a for loop. It also prints the whole number portion and the
fractional part of each result separately. To do so, it uses a type
cast to convert sqrt( )'s return value into an int
#include<stdio.h>

int main(){

    double i;

    for(i=1.0;i<101.0;i++){

    printf("The square root of %lf is %lf\n",i,sqrt[i]);
    printf("Whole number part:%d", (int)sqrt[i]);
    printf("Fractional part:%lf\n",sqrt(i)-(int)sqrt(i));
    printf("\n");



    }



    return 0;


    }


You cannot cast a variable that is un the lett side of an
assigmTIcnt statement. For example. this is an in\'.Jlid
statement in C:
int num;
(float) num = 123.23; //this is incorrect


Write a program that uses for to print the numbers 1 to 10 b"
tenths. Use a floating-point variable to control the loop.
However, use a type cast so that the conditional expression is
evaluated as an integer expression in the interest of speed
 #include<stdio.h>

int series(int x);
int main()
{
	int a,b;
	
	printf("Enter number:");
	scanf("%d",&a);
	
	b=series(a);
	
	printf("%d",b);
}
	
	int series(int x)
	{
		int a;
		a=(x*1468)%467;
		
		return a;
		
	}



Since a floating point value cannot be used with the % operator,
how can you fix this statement?
x = 123.23 % 3;  //fix this statement
