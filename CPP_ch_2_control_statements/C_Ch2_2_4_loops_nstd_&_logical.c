
/* -------------------------     Relational & Logical operators with ctrl-statement     --------------------------
    The relational and logical operators are both lower in precedence than the arithmetic operators. 
    This means that an expression like

        10 + count > a + 12

    is evaluated as if it were written
        (10 + count) > (a + 12)

*/



/* Example 1: In professionally written C code, it is uncommon to find a statement like 
            if (count == 0) //written as if(!count)
            or
            if (count != 0) //written as if(count)
                */
#include <stdio.h>
int main(){
    int ran_num;
    int count = 0;

    printf("Enter a random number:");
    scanf("%d", &ran_num);

    if (ran_num >= 0) count = 1;

    if (!count) printf("The number is negative!");
    else printf("The number is non-negative!");

    return 0;
}



/* Example 2: the outcome of a relational or logical operation is 0 when false and 1 when true. 
                For example, the following program requests two integers, then displays the outcome of each relational and logical operation when applied to them. 
                In all cases, the result will be a 0 or a 1 */
#include <stdio.h>
int main(){
    int i, j;

    printf("Enter first number:");
    scanf("%d", &i);
    printf("Enter second number:");
    scanf("%d", &j);


    // Results of operations are 0 or 1!

    // Relational operations
    printf("i <j %d\n", i < j);
    printf("i<=j %d\n", i <= j);
    printf("i==j %d\n", i == j);
    printf("i >j %d\n", i > j);
    printf("i>=j %d\n", i >= j);

    // Logical Operations
    printf("i && j %d\n", i && j);
    printf("i || j %d\n", i || j);
    printf("!i !j %d %d\n", !i, !j);

    return 0;
}



/* Example 3: C does not define an exclusive-OR (XOR) logical operator.
                However, it is easy to create a function that performs the operation.  */
#include <stdio.h>

int XOR(int a, int b);

int main(){
    int p, q;

    printf("Enter P(0 or 1):");
    scanf("%d", &p);
    printf("Enter Q(0 or 1):");
    scanf("%d", &q);

    printf("P AND  Q: %d\n", p && q);
    printf("P  OR  Q: %d\n", p || q);
    printf("P XOR  Q: %d\n", XOR(p, q));
    
    return 0;
}

int XOR(int a, int b){
    return (a || b) && !(a && b); // XOR= a&&!b || !a&&b)
}


// Example 4: The loop prints the numbers 0 through 99
            // used minimum field width of 5
#include <stdio.h>
int main()
{
    int x;
    for (x = 1; x < 100; x++){ 
        printf("%5d ", x);
        if(x%5 ==0) printf("\n");
	}

    return 0;
}


/* Example 5: Guess the magic number' game. It works like this: 
                    The player has ten ties to guess the magic Number. 

                    For correct gussing, prints 'RIGHT!' and then terminate.
                    Otherhand the program report whether the guess was high or low and then let the player enter another number.

                    process goes on until the player guesses the number or the ten tries have been used up.

                    For fun, you might want to report the number of tries it takes to guess the number */
#include <stdio.h>
int main(void){
    int magic; // magic number
    int guess; // user's guess
    int i, try_count;

    magic = 1325;
    guess = 0;
    try_count = 0;

    for(i=0; (i < 10) && (guess!=magic); i++){

        printf("Enter your guess: ");
        scanf ("%d", &guess);

        if(guess == magic){
            printf("RIGHT!");
            printf("%d is the magic number.\n", magic);
        }
        else {
            printf("Sorry, you're wrong ");
            if(guess > magic) printf("Your guess is too high. \n");
            else printf("Your guess is too low. \n");
            try_count++;
        }
    }
    
    printf("\nYou've tried %d times.", try_count);
    return 0;
}



/* Example 6:  Write a program that computes the square footage of a house
                given the dimensions of each room. 
                ask user, 
                    how many rooms
                    request the dimensions of each room. 
                Display the resulting total square footage */
#include <stdio.h>
int main (void){
    int rooms, len, width, total;
    int i;

    printf("Number of rooms? ");
    scanf ("%d", &rooms);

    total = 0;
    for(i=rooms; i>0; i--) {
        printf("Enter length: ");
        scanf("%d", &len);

        printf("Enter width: ");
        scanf("%d", &width);

        total = total + (len*width);
    }

    printf("Total square footage: %d", total);
    return 0;
}


/* Example 7: Create an improved addition-drill program that keeps track of
                the number of right and wrong answers and displays them when
                the program end */
#include <stdio.h>
int main(void){
    int answer, count;
    int right, wrong;

    right = 0;
    wrong = 0;

    for(count=1; count < 11; count++){
        printf("\nWhat is %d + %d? ", count, count);
        scanf("%d", &answer);

        if(answer == count+count){
            printf( "Right!" );
            right++;
        }
        else{
            printf("Sorry, you're wrong." );
            printf("The answer is %d", count+count);
            wrong++;
        }
    }

    printf("\nyou got %d right and %d wrong.", right, wrong);
    return 0;
}



/* Example 8: Write a program that prints the numbers 1 to 100 using 5
columns. Have each number separated from the next by a tab */
#include <stdio.h>
int main(void){
    int i;

    for(i=1; i<=100; i++) {
        printf("%d\t", i);
        if((i%5)==0) printf("\n");
    }

    return 0;
}



/* Example 9: Write a program that prints the numbers -100 to 100 */
#include <stdio.h>
int main(void){
    int i;

    for(i=-100; i<101; i++) {
        printf("%d\t", i);
        if(((i%10)==0) && (i != -100)) printf("\n");
    }

    return 0;
}


