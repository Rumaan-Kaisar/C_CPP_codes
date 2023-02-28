/* --------------------------    Advanced for Loop   --------------------------

1.	We do not have to initialize a loop-control variable.
2.	does not need any loop-control variable because the conditional expression may use some other means of stopping the loop. 
3.	increment is technically an expression that is evaluated each time the loop iterates. It does not have to increment or decrement a variable.
4.	one or more of the expressions inside for may be empty. 
For example, loop-control variable has already been initialized outside the for, there is no need for an initialization expression. 


    following for loop is valid. C allows any of its expressions to be empty

            char ch;
            ch = 'x' ;
            for ( ; ch ! = ' '; ) ch = getche ();

    traditional way to create an infinite loop in C.
            for ( ; ; )
        
*/



/* EXAMPLE 1 : This program continues to loop until a q is entered at the keyboard. 
                Instead of testing a loop-control variable, the conditional test in this for checks the value of a character entered by the user. 
                Here, the condition that controls the loop has nothing to do with the loop-control variable. 
                The reason ch is given an initial value is to prevent it from accidentally containing a q when the program begins.*/
#include<stdio.h>
// #include<conio.h>
int main(void){ 
    int i; 
    char ch; 
    
    ch='a'; /*Give ch an initial value*/

    for(i=0; ch!='q'; i++){ 
        printf("pass : %d\n", i); 
        ch=getchar(); 
        } 
        
    return 0;
}



/* EXAMPLE 2 :  This program asks the user for a value and then counts down to zero from this number. 
                Here, the loop-control variable is initialized by the user outside the loop, 
                so the initialization portion of the loop is empty. */
#include<stdio.h>
int main(void){
    int i;
   	
    printf("Enter an integer for initialization : "); 
    scanf("%d", &i);    // loop-control variable i is initialized by the user
    
    for( ; i; i--) printf(" %d ", i);

    return 0;
    }



/* EXAMPLE 3: It is perfectly valid for the loop-control variable to be altered outside the increment section. 
                For example, the following program manually increments i at the bottom of the loop. */
#include<stdio.h>
int main(void){
    int i;

    for(i=0; i<10;){
        printf(" %d ", i);
        i++;
        }

    return 0;
}



// Infinite Loop
/* EXAMPLE 4:  Using the for, it is possible to create an  infinite loop. 
                The form of this kind of loop is 
                
                    for(  ;  ;  ){. . . . .}
                */

#include<stdio.h>
int main(void){
    int i;

    i = 0;

    for(  ;  ;  ){
        printf(" %d ", i);
        i++;
        // if(i == 123) break;
        }

    return 0;
}



/* EXAMPLE 5:  Empty target (execution block) for loop. Following program simply keeps inputting characters until the user types q. */
#include<stdio.h>
// #include<conio.h>
int main(void){ 
    char ch;

    for(ch=getchar(); ch!='q'; ch=getchar()); //Loop without target

    printf("Yo !! Found the Q !!");	
    
    return 0;
}
/* when the loop starts, getche( ) is called. Then, the value of ch is tested against q . 
Next, conceptually, the nonexistent target of the for is executed, and the call to getche( ) in the increment portion of the loop is executed. 
This process repeats until the user enters a q. 
The reason the target of the for can be empty is because C allows null statements. */



/* Example 6: Write a program that computes driving time when given the
            distance and the average speed. Let the user specifY the
            number of drive time computations he or she wants to perform. */
#include<stdio.h>
int main(){
    float dist,speed;
    int num;

    printf("Enter number of drive time computation");
    scanf("%d",&num);

    for( ; num; num--){
        printf("\nEnter distence:");
        scanf("%f",&dist);

        printf("Enter average speed");
        scanf("%f",&speed);

        printf("Drive time is=%f\n",dist/speed);
    }

    return 0;
}



/* Examle 7: To create time-delay loops, for loops with empty targets are often used. 
            Create a program that asks the user for a numher and then iterates until zero is reached .
            Once the countdown is done, sound the bell, but don't display anything on the screen. */
#include<stdio.h>
int main(){
    int i;

    printf("Enter a number");
    scanf("%d",&i);

    for( ; i; i--);

    printf("\a");

    return 0;
}



/* Example 8: Even if a for loop uses a loop control variable , it need not be incremented or decremented by a fixed amount. 
            Instead, the amount added or subtracted may vary. 
            Following program begins at 1 and runs to 1000. the loop-control variable adds it to itself inside the increment expression.
            This is an easy way to produce the arithmetic progression 1 2 4 8 16, and so on. */
#include<stdio.h>
int main(){
    int i;

    for(i=1;i<1001;i=i+i)
    printf("%d ",i);

    return 0;
}
