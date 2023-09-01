/* FILE #1 (main file) */
#include <stdio.h>

int count;  // Global Data

void f1(void);  // function prototype

int main(void){
    int i;
    f1();       // set count's value
    for(i=0; i<count; i++) printf("%d", i);

    return 0;
}
