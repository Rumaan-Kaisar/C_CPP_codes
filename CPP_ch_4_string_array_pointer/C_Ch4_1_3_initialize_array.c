

/* 
    --------|  Initialize Arrays  |--------
    The general form of array initialization for one-dimensional arrays is:

            type array_name[size] = { value-list }

        Comma-separated list of constants that are type compatible with the base type of the array.
        Enclosed by curley Braces {}

    A five-element integer array is initialized a folows
            int i[5] = {1, 4, 9, 16, 25};  //This means i[0]=1 and  i[4]= 25


    Initialize character arrays: 
    There are two ways. 
        First, if the array is not holding a null-terminated string, we simply specify each character using a comma-separated list.

            char a[3] = {'A', 'B', 'C'};


        Second, If the character array is going to hold a string, you can initialize the array using a quoted string, as shown here:

            char name[8] = "Binding";   // Note: one room for null terminator

            When a string constant is used, the compiler automatically supplies the null terminator.
            You must make sure that the array you declare is long enough to include the null. 
            This is why name is 8 characters long, even though 'Binding' is only 7.


    Initialization of Multidimensional arrays : We can use one line, or use a row-order (for readability)
    Following initialization causes sqr[0][0]=1, sqr[0][1]=2,  sqr[0][2]= 3 and so forth.

            int sqr[3] [3] = {	1, 2, 3,
                                4, 5, 6,
                                7, 8, 9  } ;



    --------|  Unsized arrays  |--------
    Implicit way of initialization of arrays :  
    simply put nothing inside the square brackets.
        For example, "int pwr[]" causes the compiler to create an initialized array eight elements long.
            
            int pwr[] = {1, 2, 4, 8, 16, 32, 64, 128};

        It helps avoid counting errors on long lists, which is especially important when initializing strings. 
        For example, here an unsized array is used to hold a prompting message.

            char prompt[] = "Enter your name : ";

            "Enter your name : " can be changed any time in future , no need to count the characters. The size of prompt will automatically adjust.


    --------|  Multidimensional unsized array  |--------
    For multidimensional arrays you must specify all but the "leftmost dimension" to allow C to index the array properly.
    The advantage to this declaration over the sized version is that we can "add more row into these tables". 
    For example,

            int sqr[] [3] = {	1, 2, 3,
                                4, 5, 6,
                                7, 8, 9  } ;

*/




/* Example 1: In this program a 5x2 two-dimensional array is
                initialized so that the first element in each row is the number of
                a file server in a network and the second element contains the
                number of users connected to that server. The program allows a
                user to enter the number of a server. It then looks up the server
                in the table and reports the number of users */
#include <stdio.h>

int main(void){
    int ServerUsers[5][2]={
                            1, 14,
                            2, 28,
                            3, 19,
                            4, 8,
                            5, 15
                        };
    
    int server, i;

    printf("Enter the server number:");
    scanf("%d", &server);
    
    //look it up in the server table
    for(i=0; i<5; i++){
        if(server == ServerUsers[i][0]){
            printf("There are %d user on server %d.\n",
                    ServerUsers[i][1], server);
            break;
        }
    }
    
    //report error if not found
    if(i==5) printf("Server not listed.\n");

    return 0;
}




/* Example 2: Even though an array has been given an initial value, its
                contents "may be changed. For example, this program prints hello on the screen. */
#include <stdio.h>
#include <string.h>

int main(void){
    char str[80]="I like C";
    
    strcpy(str, "hello");
    printf(str);

    return 0;
}




/* Example 3: Folowing will give err,  The array name is only 4 characters long. 
                After initialijing the unsized array with "Tom", makes thrray of size 4 (with null terminator)
                The attempted call to strcpy( ) will cause the array to be overrun*/
#include <stdio.h>
#include <string.h>
int main(void){
    char name[] = "Tom";
    strcpy(name, "Tom Brazwell");




/* Example 4: Write a program that initializes a 10x3 array so that the first
                element of each row contains a number, the second element
                contains its square, and the third element contams its cube.
                Start with 1 and stop at 10. For example, the fIrst few rows will
                look like this:
                1, 1, 1,
                2, 4, 8,
                3, 9, 27,
                4, 16, 64,
                Next, prompt the user for a cube, look up this value in the table,
                and report the cube's root and the root's square. Use an unsized
                array so that the table size may be easily changed */

#include<stdio.h>

int main(void) {
    int cube[][3] = {
        1,  1,   1,
        2,  4,   8,
        3,  9,   27,
        4,  16,  64,
        5,  25,  125,
        6,  36,  216,
        7,  49,  343,
        8,  64,  512,
        9,  81,  729,
        10, 100, 1000
        };
    
    int num,i;

    printf("Enter cube: ");
    scanf("%d", &num);

    for(i=0; i<10; i++){
        if(num == cube[i][2]) {
            printf("Root: %d\n", cube[i][0]);
            printf("Square: %d\n", cube[i][1]);
            break;
        }
    }

    if(i == 10) printf("Cube not found.\n");

    return 0;

}


// Not using unsized array:
#include <stdio.h>
int main(void){
    int a[10][3];
    int i,j,x;
    
    for(i=0; i<10; i++){
        x=i+1;
        for(j=0; j<3; j++){
            a[i][j] = x;
            x = (i+1)*x;
        }
    }
    
    for(i=0;i<10;i++){
        for(j=0;j<3;j++)printf("%5d",a[i][j]);
        printf("\n");
    }
    
    return 0;
}

