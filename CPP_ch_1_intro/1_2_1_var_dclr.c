#include<stdio.h>

int main(void)
{
    int num; // declares num to be an integer variable
    char ch;
    float f;
    double d;

    num=100;
    ch='x';  /*Charecter inside the single quote*/
    f=100.123;
    d=123.009;
    
    printf("the value is %d", num);
    printf("ch is %c", ch);
    printf("f is %f", f);
    printf("d is %f", d);

    return 0;
}
