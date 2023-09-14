
/*
    --------------    OPERATORs Advanced - 2 : assignment    --------------

    Assignment Operator More Uses: 
        You can 'assign several variables' the same value using the general form

                    var_1 = var_2 = var_3 = ... = var_n = value ;


        Professional programmers use such multiple-variable assignments. e.g.   

                    i = j = k = 100; 
        
            assigns i, j, and k the value 100.  
        


    SHORT-HAND operators using "=" :  
        In C, you can transform a statement like 	'a = a + 3;' into a statement like 	'a += 3;'
    
                    var = var op expression;
                            as 	
                    var = op  expression;	
            
            Here, op is one of   +  -  *  /  %  << >>  &  |  ^ .
        Note: There must be no space between the operator and the equal sign. 

*/


1. The following program illustrates the multiple-assignment
statement:
#include <stdio.h>
int main(voidl
(
int i. j, k;
i = j = k = 99;
printf("%d %d %d". i. j. kl;
return 0;
)



2. The next program counts to 98 by twos. Notice that it uses C
shorthand to increment the loop-control variable by two each
iteration.
#include <stdio.h>
int main(void)
(
}
int i:
/* count by 25 */
for(i=O: i<100: i+=2)
printf(-%d -, i);
return 0;



3. The following program uses the left-shift operator in shorthand
form to multiply the value ofi by 2, three times. (The resulting
value is 8.)
#include <stdio.h>
int main(void)
(
int i = 1;
i «= 3; /* multiply by 2, 3 times *j
printf("%d", i);
return 0;
}


1. Compile and run the program in Example 1 to prove to yourself
that the multiple-assignment statement works.

2. How is the following statement written using C shorthand?
x = x & y;

3. Write a program that displays all the even multiples of 17 from
17 to 1000. Use C shorthand.



