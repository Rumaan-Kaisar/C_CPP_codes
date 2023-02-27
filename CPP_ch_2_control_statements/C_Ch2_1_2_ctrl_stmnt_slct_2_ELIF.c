/* 
------------------ Simple if-else ------------------ 
    if(expression) statementOrBlock;
    else statementOrBlock;      // Notice no condition with else
*/



/* 
------------------  if-else-if ladder & filtering  ------------------
if-else-if ladder is another form of nested if: 

FORM 1 :

        if(expression) statement;
        else
        if(expression) statement;
        else
            if(expression) statement;
            .
            .
            .
            else statement;



FORM 2 :

        if(expression) statement;
        else {  if(expression) statement;
                else {  if(expression) statement;
                        else {  if(expression) statement;
                                else {  if(expression) statement;
                                        else statement;
                                }
                        }
                }
        }

Both "FORM 1" and  "FORM 2" act in the same way. 
The expressions are calculated from the top - downward. 
As soon as a true condition is found. the statement associated with it is executed, 
and the rest of the ladder is bypassed.


General form of If-Else-If ladder:

        if(expression) statement;
        else if(expression) statementOrBlock;
        else if(expression) statementOrBlock;
        .
        .
        .
        else statementOrBlock;
 */



/* 
------------------  Nested IFs   ------------------
if(count > max)    // outer if 
    if (error) printf ("Error, try again. ");     // Inner-nested if
*/


/* 
------------------ Types of nested IF-ELSEs ----------------

Type 1:   General Nested if

    if(condition 1){
        if(condition 2)
        else
    }
    else { 
        if(condition 1)
        else
    }



Type 2 (Filter type):   General Nested if 

    if(cond. 1){
        if(cond. 2){ 
            if(cond. 3){
                if(cond. 4) //4th
                else    
                }   //3rd
            else   
            }    //2nd
        else    
        }       //1st
    else

It is a filter type of nested if. If cond. 4 is true then all four conditions are true . 
If cond. 4 is false then associated else will be executed.



Type 3 - If-else-if ladder: Described already

    if(cond. 1) statement;
    else if(cond. 2) statement;
    else if(cond. 3) statement;
    .
    .
    .
    else statement;

Control statement can be passed through a series of  conditional statement using if-else-if ladder (Type-3) or
can be choose to flow through different series of  conditional statement (Type-1) or 
the control can be filtered (Type-2).
 */



/* Example 1: In this example the else related to the first if  */
#include<stdio.h>
int main(void){
    char ch;
    int y;

    if(ch=='S') { /* first if */
        printf("Enter a number: "); 
        scanf("%d", &y);
    if(y) pintf("Its square is %d.", y*y); /* second if */
    }
    else printf("Make next selection.");    // related to 1st if

    return 0;
}



/* Example 2: An else always associates with the nearest if in the same block that does not already have an else 
                associated with it. In this example, the else is associated with the second if. */
#include<stdio.h>
int main(void){
    int p, q;
    
    p = 1;
    q = 0;

    if(p)
        if (q) printf("a and b are true"); /*Everything changes if {} appears*/
    else printf ("To which statement does this else apply?");  // related to 2nd if

    return 0;
}



/* Example 3: the arithmetic program using "else-if ladder". */
#include<stdio.h>
// #include<conio.h>
int main(void){
    int a,b;
    char ch;

    printf("Do you want to:\n");
    printf("Add, Subtract, Multiply, or Divide?\n");
    printf("Enter first letter:");
    ch=getchar();
    printf("\n");

    printf ("Enter first number: ");
    scanf ("%d",&a);
    printf("Enter second number: ");
    scanf("%d",&b);

    if(ch=='A') printf("%d", a+b) ;
    else if(ch=='S') printf("%d", a-b) ;
    else if(ch=='M') printf("%d", a*b) ;
    else if(ch=='D' && b!=0) printf("%d", a/b);

    return 0;
}



/* Example 4: improvement to the addition drill program developed previously. It lets the user have a
                second try at getting the right answer. */
#include<stdio.h>
int main(){
    int answer,count;
    int again;

    for(count=1; count<11; count++) {
        printf("What is %d + %d? ", count, count);
        scanf("%d", &answer);

        if(answer == count+count) printf("Right!\n");
        else {
            printf("Sorry, you're wrong\n");
            printf("Try again.\n");

            printf ("\nWhat is %d + %d?",count,count);
            scanf ( "%d", &answer);
    
            //nested if-else
            if (answer==count+count) printf("Right!\n");
            else printf("Wrong, the answer is %d\n" ,count+count);
        }
    }

    return 0;
}



/* Example 5:  a program that computes the area of either a circle,
                rectangle, or triangle. Used an if-else-ifladder */
#include<stdio.h>
// #include<conio.h>
int main(){
    char Selection;
    float radius;
    int length, width, base,height;

    printf("a.Area of a circle \nb.Area of the square \nc.Area of the triangle\n");
    printf("Make a selection:");
    Selection=getchar();

    if(Selection=='a'){
        printf("\nEnter a radius:");
        scanf("%f",&radius);

        printf("Area:%.2f",3.1416*radius*radius);
    }
    
    else if(Selection=='b'){
        printf("\nEnter a length & width:");
        scanf("%d, %d",&length, &width);

        printf("Area:%d",length*width);
    }

    else if (Selection=='c'){
        printf("\nEnter a length of base:");
        scanf("%d", &base);

        printf("\nEnter a length of hight:");
        scanf("%d", &height);

        printf("Area: %d", (base*height)/2);
    }
    
    return 0;
}
