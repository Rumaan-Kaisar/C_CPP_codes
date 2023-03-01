
/* General form of while:         
    
    while(expression) statement;

    the target of while may also be a block of code. 
    The while loop works by repeating its target as long as the expression is true.
    
     When it becomes false, the loop stops. 
    if the expression is false to begin with, the loop will not execute even once. */

/* EXAMPLE 1 : A better way to wait for the letter q to be typed is shown here using while. */
#include<stdio.h>
// #include<conio.h>
int main(void){
    char ch;

    ch=getchar();
    
    while(ch!='q') ch=getchar();
    
    printf("\nFound the q");	  
    
    return 0;
}



/* EXAMPLE 2 :The following program is a simple code machine. 
                It translates the characters you type into a coded form by adding 1 to each letter. 
                That is, 'A' becomes 'B': and so forth. 
                The program stops when you press ENTER. (The getche() function returns \r when ENTER is pressed.) */

#include<stdio.h>
#include<conio.h>
int main(void){ 
    char ch;

    printf("Enter your massage :"); 
    ch=getche();

    while(ch!='\r'){
        printf("%c", ch+1); 
        ch=getche(); 
    } 

    return 0;
}



/* Example 3: compute driving time, given distance and average speed. */
#include<stdio.h>
int main(void){
    float avg_speed, distance;
    int num;

    printf("Total number of test:");
    scanf("%d",&num);

    while(num){
        printf("Test %d\n", num);

        printf("Enter average speed:");
        scanf("%f",&avg_speed);

        printf("\nEnter distance:");
        scanf("%f",&distance);
        
        printf("Driving time:%f\n",distance/avg_speed);
        num--;
    }
   
    return 0;
}



/* Example 4: following program that will decode message, that have been
                encoded using the 'code machine  in the second Example 2: in this section. */

#include<stdio.h>
#include<conio.h>
int main(void){
    char ch;

    printf("Enter your message:");
    ch=getche();
    
    while(ch !='\r'){
        printf("%c ",ch-1);
        ch=getche();
    }

    return 0;
}


/* do (or do-whle) Loop general form:

        do {
        statements
        } while(expression);

The do loop is unique because-it will always execute the code within the loop at least once,
since the expression controlling the loop is tested at the bottom of the loop. */

/* EXAMPLE 5 : The fact that do will always execute the body of its loop at least once makes it 
                perfect for checking menu input. For example,
                this version of the arithmetic program reprompts the user until a valid response is entered. */
#include<stdio.h>
/*If we dont use <conio.h> and getche(), 'Enter the first letter'
in the 'do' loop appears twice if wrong entry is entered*/
int main(void){
    int a,b; 
    char ch;
   	
    printf("Do you want to :\n ");
    printf("Add, Substruct, Multply, or Devide?\n ");

    /*Force user to enter a valid response */
    do{
        printf("Enter the first letter : "); 
        ch=getchar();
    } while(ch!='A' && ch!='S' && ch!='M' && ch!='D');

    printf("\nEnter the first number :\n "); 
    scanf("%d", &a);
    printf("Enter the second number :\n "); 
    scanf("%d", &b);

    if(ch=='A')  printf("Addition of the numbers : %d \n ", a+b);
    else if(ch=='S') printf("Subtraction of the numbers : %d \n ", a-b);
    else if(ch=='M') printf("Multiplication of the numbers : %d \n ", a*b);
    else if((ch=='D') && (b!=0)) printf("Division of the numbers : %d \n ", a/b);

    return 0;
}



/* EXAMPLE 6 : The do loop is especially useful when your program is waiting for some event to occur. 
                For example, this program waits for the user to type a q . Notice that it contains one less call to getche() 
                than the equivalent previous program. */
#include<stdio.h>
#include<conio.h>
int main(void){
    char ch;
   	
    do {
        ch=getche();
    } while(ch!='q');

    printf("\nFound the q");
    return 0;
}


/* Example 7: Write a program that conVerts gallons to liters. Using a do loop,
                allow the user to repeat the conversion */

#include<stdio.h>

int main(){
    float gallons;

    printf("\nEnter gallons:");
    scanf("%f",&gallons);

    do{
        printf("Liters: %f\n", gallons*3.7854);

        printf("Enter gallons or 0 to finish:");
        scanf("%f",&gallons);

    }while(gallons!=0);

    return 0;
}


/* Example 8: Write a program that displays the menu below and uses a do
                loop to check for valid responses. (Your program does not need
                to implement the actual functions shown in the menu.)
                Mailing list menu:
                1. Enter addresses
                2. Delete address
                3. Search the list
                4. Print the list
                5. Quit
                Enter the number of your choice (1-5) */
#include<stdio.h>
int main(){
    int choice;

    printf("Mailing list menu:\n\n");
    printf("1.Enter addresses\n");
    printf("2.Delete addresses\n");
    printf("3.Search the list\n");
    printf("4.Print the list\n");
    printf("5.Quit\n");

    do{
        printf("Enter the number of your choice(1-5):");
        scanf("%d",&choice);
    }while(choice<1 || choice>5);

    return 0;
}



/* Example 9: Using the three loop statements, show three different ways to count from 1 to 10. */
#include <stdio.h>
int main(void){
    int i, j, k;
    
    // for
    for(i=1; i<11; i++) printf("%d ", i);

    //do
    printf("\n");
    j = 1;
    do {
        printf ("%d ", j);
        j++;
    } while(j < 11);

    /* while */
    printf("\n");
    k=1;
    while (k<11) {
        printf("%d ", k);
        k++;
    }

    return 0;
}



/* Example 10: Write a program that inputs characters until the user strikes the
ENTER key. */
#include <stdio.h>
#include <conio.h>

int main(void){
    char ch;

    do{
        ch = getche();
    }while(ch!='\r');

    return 0;
}
