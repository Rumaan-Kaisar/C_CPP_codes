// The moon's gravity about 17% of Earth's. Enter your weight and get Effective moon weight on the moon

#include <stdio.h>

int main(void){
    float weight;
    printf("Enter your weight: ");
    scanf("%f" , &weight);
    printf("Effective moon weight: %f", weight*0.17);
    return 0;
}