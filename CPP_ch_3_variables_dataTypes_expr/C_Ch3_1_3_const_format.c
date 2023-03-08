/* 
    Constants Advanced 
    scientific notation for floating-point numbers. General form:

    number E sign exponent

    The sign is optional
    there may be no spaces between the parts in an actual number. Following defines the value 1234.56 
            123.456E1

    These two assignment statements are equivalent.	
            char ch ;	
            ch = 'A ' ;	
            ch = 65 ;


    using a suffix. 
        For floating-point types, if you follow the number with an 'F', the number is treated as a float. 
        If you follow it with an 'L', the number becomes a long double. 
        For integer types, the 'U' suffix stands for unsigned and the 'L' stands for long.

    A hexadecimal constant must begin with '0x' (a zero followed by an x).
        For example, 0xAB is a hexadecimal constant, and 024 is an octal constant. You may use either upper- or lowercase.
        

    If we use short int (%hd) data type to printing the number 42340, it displays -23196, 
    because it thinks that it is receiving a signed short integer. 
    The problem is that 42,340 is outside the range of a short int. To make it work properly, we must use the %hu specifier .



    Printing The string : 
    A string is a set of characters enclosed by double quotes. We used string in printf( ) and scanf( ) functions.
    C does not formally have a string data type. Strings are supported in C as character arrays. 
    To display a string using printf( ) you can either make it part of the control string or 
    pass it as a separate argument and display it using the %s format code. For example,

        printf("%s %s %s", "Once", "upon", "a time");
        Here, each string is passed to printf( ) as an argument and displayed using the %s specifier.
*/



/* Example 1: To display a string using printf() you can pass it as a separate argument and display it using the %s format code. 
                For example, this program prints Once upon a time on the screen */
#include<stdio.h>

int main(void){
    printf("%s %s %s", "Once", "upon", "a time");
    return 0;
}



/* Example 2: If we use short int (%hd) data type to printing the number 42340, it displays -23196, 
    because it thinks that it is receiving a signed short integer. 
    The problem is that 42,340 is outside the range of a short int. To make it work properly, we must use the %hu specifier . */

#include<stdio.h>
int main(void){
    // printf("%hd", 42340); //This won't work right
    printf("%hu", 42340); 
    return 0;
}



/* Example 3: explicitly tell the compiler what type of constant you are using,
                the compiler assumes that 2309 is simply an int, Hence, it does not output the correct value. 
                To fix it, you must specify 2309 as 2309.0.  */
#include<stdio.h>
int main(void){
    // printf("%f", 2309); 
    printf("%f", 2309.0);   //explicitly specifyig float
    return 0;
}



/* Example 4: Write a program that reads anq writes a long int value */
#include<stdio.h>
int main(void){
    long int i;
    printf("Enter the value: ");
    scanf("%ld", &i);
    printf("%ld", i);
    return 0;
}



/* Example 5: Write a program that outputs 
                'I like C' using three separate strings*/

#include<stdio.h>
int main(void){
    printf("%s %s %s","I", "like", "C");
    return 0;
}