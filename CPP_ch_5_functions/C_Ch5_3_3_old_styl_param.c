


/*  ---------------|    Old-Style Parameter Declarations    |---------------
    The general form of the old-style parameter declaration is shown here:

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
        Within the parentheses, only the 'names of the parameters' are specified. 
        Outside the parentheses, the "types" and "names" are specified.  
*/




/* Example 1: For example, following shows modern declaration and then old-style */
// ---------------|    Modern Style    |---------------
float f(char ch, long size, double max){ . . function code . . }


// ---------------|    OLD-Style    |---------------
    // The equivalent old-style declaration is
        float f(ch, size, max)
        char ch;
        long size;
        double max;
        { 
            . . function code . . 
        }




/* Example 2: One advantage of the old-style declaration is that you can specify more than one parameter after the type name.
                For example, this is perfectly valid: */
myfunc (i, j, k)
int i, j, k;
{ . . function code . . }




/* Example 3: Following uses old style declaration  */
#include<stdio.h>

int area(int l, int w);

int main(void)
{
    printf("Area is %d",area(10,20));
    return 0;
}

int area(int l, int w)
int l, w;
{
    return l*w;
}




/* Example 4: Convert this program so that f_to_m() uses the old-style declaration form. */
#include <stdio.h>

double f_to_m(double f);

int main(void){
    double feet;

    printf ("Enter feet: ");
    scanf("%lf", &feet);

    printf("Meters: %f", f_to_m(feet));

    return 0;
}

double f_to_m(double f){
    return f / 3.28;
}


/* old styled */
#include<stdio.h>
double ftom(double f);

int main (void){
    double feet;

    printf("Enter feet:");
    scanf("%lf", &feet);
    printf("Meters: %lf", ftom(feet));
    
    return 0;
}

// old-style declaration
double ftom(f)
double f;
{
    return f/3.28;
}




/* Example 5: What is the prototype for this function?
                double myfunc(int x, int y, char ch){ } */

// The prototype is shown here.

double myfunc(int x, int y, char ch);




/* Example 6: Show how the function in previous Exercise would be coded using the old-style function declaration. */

// Using the old-style function declaration
double myfunc(x, y, ch)
int x, y;
char ch ;
{

}




/* Example 7: How is this declaration coded using the old-style function
                declaration form?
                void func(int a, char ch, double d) */
func (a, ch, d)
int a;
char Ch;
double d;
{
}

