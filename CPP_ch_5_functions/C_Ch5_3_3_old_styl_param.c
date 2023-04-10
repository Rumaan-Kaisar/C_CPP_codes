5.5 Old-Style Parameter Declarations
The original parameter declaration method is now called the old-style or classic form. The general form of the old-style parameter declaration is shown here:
type function-name(parameter_1, parameter_2,. . . . . ., parameter_N)
type parameter_1;
type parameter_2;
. . . .
. . . .
type parameter_N;
{
FUNCTION-CODE
}
Notice that the declaration is divided into two parts: 
	Within the parentheses, only the names of the parameters are specified. 
	Outside the parentheses, the types and names are specified. 

For example, given the following modern declaration and then old-style
float f(char ch, long size, double max){ . . function code . . }
the equivalent old-style declaration is
float f(ch, size, max)
char ch;
long size;
double max;
{ . . function code . . }
Note
	One advantage of the old-style declaration is that you can specify more than one parameter after the type name (sometimes you find it quite useful). For example, this is perfectly valid:
myfunc (i. j. k)
int i, j, k;
{ . . function code . . }
	The ANSI C standard specifies that either the old-style or the modern declaration form may be used. The reason for this is to maintain compatibility with older C programs. 




#include<stdio.h>

int area(int l, int w)
{
    return l*w;
}

int main ()
{
    printf("Area is %d",area(10,20));
    return 0;
}




#include<stdio.h>
double ftom(double f);

int main ()
{
    double feet;
    printf("Enter feet:");
    scanf("%lf",&feet);
    printf("Meters: %lf",ftom(feet));
    
    return 0;
}

double ftom(f)
double f;
{
    return f/3.28;
}




