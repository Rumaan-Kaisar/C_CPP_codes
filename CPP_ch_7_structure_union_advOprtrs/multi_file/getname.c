
// FILE #2:
#include <stdio.h>

extern char str[80];

void getname(void){
    printf("Enter your first name: ");
    gets(str);
}