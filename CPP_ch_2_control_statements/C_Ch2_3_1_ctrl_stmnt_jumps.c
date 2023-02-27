
jump Statements : C has four types of jump statements. 
1.	goto statement :  the form is   goto identifier;
This statement transfers control flow to the statement labeled with the given identifier. The statement must be within the same function as the goto.
2.	break statement : the form is  break;
is used within iteration statements and switch statements to pass control flow to the statement following the while, do-while, for, or switch.
3.	continue statement :the form is  continue;
is used within the sub-statement of iteration statements to transfer control flow to the place just before the end of the sub-statement.
4.	return statement : the form is  return expression(opt);
This statement returns from the function. If the function return type is void, the function may not return a value; otherwise, the expression represents the value to be returned.



// --------------------------------    break TO EXIT A LOOP    --------------------------------
/* The break statement allows you to exit a loop from any point within its body
the loop is immediately stopped, and program control resumes at the next statement following the loop. 

    You can have as many break statements within a loop as you desire. 

    too many exit points from a loop tend to destructure your code

    try to use normal loop exit.
 */


/* Example 1: For example, this loop prints only the numbers 1 to 10: */
#include <stdio.h>
int main(void){
    int j;
    
    for(j=1; j<100; j++) {
        printf ("%d ", j); 
        if(j==10) break; //exit the loop
    }
}



#include <stdio.h>
#include <conio.h>
int main(void){
    int i;
    char ch;
    /*display all numbers that are multiples of 6*/
    for(i=1;i<10000; i++){    
        if(!(i%6)){
            printf("%d , more?(Y/N)", i);
            ch = getche();
            if(ch=='N') break; /* stop the loop */
            printf("\n");
        }
    }
    return 0;
}


#include<stdio.h>
int main(void){
    int i,j;
    for(i=0; i<5; i++) {
        for(j=0; j<100; j++){
        printf ("%d ", j);
        if (j==5) break;
        }
    printf ("\n");
    }
return 0;
}

#include<stdio.h>
#include<conio.h>
int main()
{

    float i;
    char ch;
    printf("Compute tip:");

    for(i=1.0;i<=100.0;i++){
        printf("%f %f %f %f\n",i,i+i*0.1,i+i*0.15,i+i*0.2);
        printf("More?(Y/N):");
        ch=getche();
        printf("\n");
        if(ch=='N') break;
    }

    return 0;
}


#include<stdio.h>

int main()
{
    int i;
    char ch;

    for(i=1;i<1000;i++)
    {
    if(!(i%6)){
        printf("%d,more?(Y/N)",i);
        ch=getchar();
        if(ch=='N')
        break;
        prinitf("\n");
    }
    }


    return 0;
}


#include<stdio.h>

int main()
{
    int n1,n2;
    char ch;

    do{
        printf("love,Save,Edit,Quit?\n");

    do{
    printf("Enter your selection:");
    ch=getchar();

    }
    while(ch!='L' && ch!='s '&& ch!='E' && ch!='Q');

    if(ch!='Q')
    {
    printf("%d+%d=%d",n1,n2,n1+n2);
    }
    if(ch!='Q')
    {
    printf("%d-%d=%d",n1,n2,n1-n2);
    }

    }
    while(ch!='Q');



}


do { printf("Load, Save, Edit, Quit?\n");
do {printf("Enter your selection:"); ch = getchar();
   } while(ch!='L' && ch!=’S’ && ch!='E' && ch!='Q');
if(ch != 'Q') { /*do something */ }
if(ch != 'Q') {/*do something else*/}
/* etc. */
} while(ch != 'Q');

In this situation, several additional tests are performed on ch to see if it is equal to 'Q' to avoid executing certain sections of code when the Quit option is selected (which makes the program act slow). Most C programmers would write the preceding loop as shown here:
for( ; ; ) { /* infinite for loop */ 
printf("Load, Save, Edit, Quit?\n"); 
     do {printf("Enter your selection:"); ch = getchar();
        } while(ch!='L' && ch!=’S’ && ch!='E' && ch!='Q');
if (ch == 'Q') break;	 /*Quit makes exit the infinite for loop */
/* do something */
/*do something else*/
/* etc. */
}
In this version, ch need only be tested once to see if it contains a 'Q'. This implementation is more efficient because only one if statement is required.



#include<stdio.h>

int main()
{
    int i,j;

    for(i=1;i<5;i++){
        for(j=0;j<100;j++)
        {
        printf("%d",j);
        if(j==5)
        break;
        }

        printf("\n");
    }


    return 0;

}


#include<stdio.h>
int main()
{
    float i;
    char ch;

    printf("Tip computer\n");


    for(i=1.0;i<101.0;i=i+i){
    printf("%f %f %f %f\n",i,i+i*.1,i+i*.15,i+i*.2);
    printf("More?(Y/N)");
    ch=getchar();

    printf("\n");
    if(ch=='N')
    break;
    }


}




2.16 Use continue for skipping any code
The continue statement is somewhat the opposite of the break statement. It forces the next iteration of the loop to take place, skipping any code in between itself and the test condition of the loop.  For example, this program never displays any output:

  #include<stdio.h>
  int main(void){ int x;
    for(x=0; x<100; x++){continue;
        printf("this never show up"); /* this is never executed */ }
    return 0;}

Each time the continue statement is reached, it causes the loop to repeat, skipping the printf( ) statement.

Note:
1.	In while and do-while loops, a continue statement will cause control to go directly to the test condition and then continue the looping process. 

2.	In the case of for, the increment part of the loop is performed, the conditional test is executed, and the loop continues.


#include <stdio.h>
int main(void){
int total, i, j;
total = 0;
do{
    printf ("Enter next number (0 to stop):");
    scanf("%d", &i);
    printf("Enter number again:");
    scanf ("%d", &j);
    if(i != j){
        printf("Mismatch\n") ;
        continue;
    }
    total = total + i;
}while(i);

printf("Total is %d\n", total);
return 0;
}


#include <stdio.h>
int main (void){
    int x;
    for(x=0; x<100; x++) {
    continue;
    printf("%d ",x); /* this is never executed */
    }
return 0;
}



#include<stdio.h>
int main()
{
    int total,i,j;

    total=0;
    do{
    printf("Enter next number (0 to stop):");
    scanf("%d",&i);
    printf("Enter number again:");
    scanf("%d",&j);

    if(i!=j){
        printf("Mismatch\n");
        continue;


    }
    total+=1;
    }
    while(i);

    printf("Total is %d\n",total);


    return 0;



}


#include<stdio.h>
int main()
{
    int i;

    for(i=1;i<101;i++)

    {
        if(!(i%2))
        continue;
        printf("%d",i);



    }

    return 0;


}


2.18 The goto STATEMENT
C supports a non-conditional jump statement, called the goto. Because C is a replacement for assembly code, the inclusion of goto is necessary because it can be used to create very fast routines. However, most programmers do not use goto because it destructures a program and, if frequently used, can render the program virtually impossible to understand later. Also, there is no routine that requires a goto. 
The goto statement can perform a jump within a function. It cannot jump between functions. It works with a label. In C, a label is a valid identifier name followed by a colon. For example, the following goto jumps around the printf( ) statement:
goto mylabel;
printf("This will not print ");
mylabel: printf ("This will print. ") ;
About the only good use for goto is to jump out of a deeply nested routine when a catastrophic error occurs.

Labeled Statements :  A statement can be preceded by a label. Three types of labels exist in C. A simple identifier followed by a colon (:) is a label. Usually, this label is the target of a goto statement. Within switch statements, case and default labeled statements exist. 
1) label : statement ; ...  goto label; 2) case int/char-const : statement; 3) default : statement;


#include<stdio.h>
#include<conio.h>
int main(){
    int i;

    i=1;
    again:
        printf("%d ",i);
        i++;
        if(i<10) goto again;

    return 0;
}

