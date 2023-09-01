
/* Example 5: Here is another example of using extern to allow global data to be accessed by two files: */

// FILE #1:
#include <stdio.h>

char str[80];
void getname(void);

int main(void){
    getname();
    printf("Hello %s", str);
    
    getchar();  // to prevent exit immediately

    return 0;
}


// g++ H:\shared_docs\codes_C_CPP\raw_runs\multi_file\main_xtrn.c H:\shared_docs\codes_C_CPP\raw_runs\multi_file\getname.c -o H:\shared_docs\codes_C_CPP\raw_runs\multi_file\getname2