/* 
    --------------    # & ## operators    --------------

    The C preprocessor contains two 'little-used' but "potentially valuable" operators: # and ##.

    #
        The # operator turns the 'argument of a function-like macro' (recall C_Ch8_1_adv_define_include) into a QUOTED STRING. 
    
    ##
        The ## operator concatenates two identifiers
    
*/



/* Example 1: This program demonstrates the # operator 
                The program displays: 'value is 10'. 
                This output occurs because MKSTRING() causes the identifier "value" to be made into a quoted string.
*/
#include <stdio.h>

#define MKSTRING(str) # str

int main(void){
    int value;

    value = 10;
    printf("%s is %d", MKSTRING(value), value);

    return 0;
}




/* Example 2: The following program demonstrates the ## operator.
                It creates the output() macro, which translates into a call to printf(). 
                The value of two variables, which end in 1 or 2, is displayed.

                The program displays 10 20 99 -10. 

                In the calls to output(), 'count' and 'i' are concatenated with 1 and 2 
                    to form the variable names count1, count2, i1 and i2 in the printf() statements.
*/
#include<stdio.h>

// two variables, which have last character 1 or 2 in their identifier-name, e.g. a1, a2
#define output(i) printf("%d %d\n", i ## 1, i ## 2) 

int main(void) {
    int count1, count2;
    int i1, i2;

    count1= 10;	
    count2 = 20;

    i1 = 99;	
    i2 = -10;

    output(count);
    output(i);

    return 0;
}




/* Example 3: Following program displays: 'OneTwo' */
#include <stdio.h>

#define MKSTRING(str) #str
#define JOIN(a, b) MKSTRING(a##b)

int main(void) {

    printf(JOIN(One, Two));

    return 0;
}



// following doesn't work
#include <stdio.h>

#define JOIN(a, b) a ## b

int main(void) {

    printf(JOIN("one ", "two"));

    return 0;
}





// Example 4: Another C program to illustrate (##) operator 
#include <stdio.h>
  
// Macro definition using the Token-pasting operator 
#define concat(a, b) a##b

int main(void) {
    int xy = 30;
  
    // Printing the concatenated value of x and y
    printf("%d", concat(x, y));

    return 0;
}





/* Example 5: followwing C program illustrates (#) operator  */
#include <stdio.h>
  
// Macro definition using the stringizing operator
#define mkstr(s) #s

int main(void) {
    
    // Printing the stringized value of "geeksforgeeks"
    printf(mkstr(geeksforgeeks));

    return 0;
}


