
/* 
    --------    Multidimensional Arrays    --------
    To add a dimension, we simply specify its size inside square brackets. 
        For example, to create a 10x12 two-dimensional integer array called count :
                    int count[10] [12];

    A two-dimensional array is essentially an array of one-dimensional arrays (yep!! Array of arrays) and is 
    most easily thought of in a row-column format.
        For example, given a 4x5 integer array called two_d, looking like 

                    0	1	2	3	4
                0					
                1		1	2	3	4
                2		2	4	6	8
                3		3	6	9	12

    A two-dimensional array is accessed one row at a time, from left to right.


    Three dimensions or greater:
        TO create arrays of three dimensions or greater, simply add the size of the additional dimension. 
        For example, 
            float values[10][12][8];


    More dim more memory:
        100-character one-dimensional array requires 100 bytes of memory. 
        100x100 character array requires 10,000 bytes, and 
        100x100x100 array requires 1,000,000 bytes.  

*/




/* Example 1: This program loads a 4x5 array with the products of the
                indices, then displays the array in row, column formal. */
#include <stdio.h>
int main(void){
    int two_d[4][5];
    int i, j;

    for(i=0; i<4; i++){
        for(j=0; j<5; j++) {
            two_d[i][j] = i*j; 
            //printf(" %d", two_d[i][j]);
        }
        //printf("\n");
    }

    /*or print saperately */
    for(i=0; i<4; i++){	
        for(j=0; j<5; j++) printf("%d ", two_d[i][j]);
        printf("\n");
    }

    return 0;
}




/* Example 2: following program can be used to keep track of the number of points scored per quarter by each
                member of a basketball team. */
#include <stdio.h>

int main(void){
    int bball[4][5];
    int i,j;
    
    for(i=0; i<4; i++)
        for(j=0; j<5; j++) {
            printf("Quarter %d, player %d, ", i+1, j+1);
            printf("Enter number of points: ");
            scanf("%d",&bball[i][j]);
        }
    
    //display results
    for(i=0; i<4; i++)
        for(j=0; j<5; j++){
            printf("Quarter %d, player %d, ", i+1, j+1);
            printf("%d\n", bball[i][j]);
        }

    return 0;
}




/* Example 3: Write a program that defines a 3x3x3 three-dimensional array,
                and load it with the numbers 1 to 27. */
#include <stdio.h>

int main(void) {
   int three_d[3][3][3];
   int i, j, k, x;
   
   x =1;
   for(i=0; i<3; i++)
        for(j=0; j<3; j++)
            for(k=0; k<3; k++){
                three_d[i][j][k] = x;
                x++;
                printf("%5d",three_d[i][j][k]);
            }

    return 0;
}




/* Example 4:  Following program loads a 3D array of products and display the sum of its elements */
#include <stdio.h>

int main(void){
   int a[3][3][3];
   int i, j, k, sum;
   
   sum=0;
   for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            for(k=0; k<3; k++){
                a[i][j][k]= (i+1)*(j+1)*(k+1);
                printf("%5d",a[i][j][k]);
            }
        printf("\n");
        }
    printf("\n");
   }
   
    //    sum all elements
    sum = 0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            for(k=0;k<3;k++) sum = sum + a[i][j][k];
   
    printf("\n%d",sum);

    return 0;
}

