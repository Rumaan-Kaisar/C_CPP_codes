// Ounce to cup conversion: There are 8 ounces in a cup
#include <stdio.h>

int ounce_to_cup(int ounce);

int main(void){
    int ounces;
    int cups;
    printf("Enter ounces: ");
    scanf ("%d", &ounces);
    cups =  ounce_to_cup(ounces);
    printf("%d cups", cups);
    return 0;
}

int ounce_to_cup(int ounce){
    return ounce/8;
}