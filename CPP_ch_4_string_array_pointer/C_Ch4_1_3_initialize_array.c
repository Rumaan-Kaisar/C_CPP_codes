

4.4 Initialize Arrays
Initialization of an array can be done by specifying a list of values the array elements will have. The general form of array initialization for one-dimensional arrays is:
type array_name[size] = { value-list }
The value-list is a comma-separated list of constants that are type compatible with the base type of the array. Moving from left to right, the first constant will be placed in the first position of the array, the second constant in the second position, and so on.  In the following example, a five-element integer array is initialized with the squares of the numbers 1 through 5.

int i[5] = {1, 4, 9, 16, 25};  /*This means i[0]=1 and  i[4]= 25*/

Initialize character arrays : There are two ways. First, if the array is not holding a null-terminated string, we simply specify each character using a comma-separated list. For example, this initializes a with the letters 'A', 'B', and 'C'.

char a[3] = {'A', 'B', 'C'};

Second, If the character array is going to hold a string, you can initialize the array using a quoted string, as shown here:

char name[S] = "Herb";

Notice that no curly braces surround the string. Braces are not used in this form of initialization : when a string constant is used, the compiler automatically supplies the null terminator. Because strings in C must end with a null, you must make sure that the array you declare is long enough to include the null. This is why name is 5 characters long, even though 'Herb' is only 4.

Initialization of Multidimensional arrays : Multidimensional arrays are initialized in the same way as one-dimensional arrays. For example, here the array sqr is initialized with the values 1 through 9, using row order:
int sqr[3] [3] = {	1, 2, 3,
4, 5, 6,
7, 8, 9  } ;
This initialization causes sqr[0][0]=1, sqr[0][1]=2,  sqr[0][2]= 3 and so forth.

Unsized arrays – Implicit way of initialization of arrays :  To not specify the size of the array simply put nothing inside the square brackets. If you don't specify the size, the compiler counts the number of initializers and uses that value as the size of the array. For example, int pwr[]causes the compiler to create an initialized array eight elements long.
int pwr[] = {1, 2, 4, 8, 16, 32, 64, 128};
Arrays that don't have their dimensions explicitly specified are called  unsized arrays. It helps avoid counting errors on long lists, which is especially important when initializing strings. For example, here an unsized array is used to hold a prompting message.

char prompt[]="Enter your name : ";

"Enter your name : " can be changed any time in future , no need to count the characters. The size of prompt will automatically adjust.

Multidimensional unsized array initializations : For multidimensional arrays you must specify all but the leftmost dimension to allow C to index the array properly (useful only for listed tables). In this way you may build tables of varying lengths with the compiler allocating enough storage for them automatically. For example, the declaration of sqr as an unsized array is shown here:

int sqr[] [3] = {	1, 2, 3,
4, 5, 6,
7, 8, 9  } ;

The advantage to this declaration over the sized version is that we can add more row into these tables. 


in this program a 5x2 two-dimensional array·is
initialized so that the first element in each row is the number of
a file server in a network and the second element contains the
number of users connected to that server. The program allows a
user to enter the number of a server. It then looks up the server
in the table and reports the number of users
#include <stdio.h>

int main()
{
    int ServerUsers[5][2]={
       1,14,
       2,28,
       3,19,
       4,8,
       5,15
   };
    
    int server,i;
    printf("Enter the server number:");
    scanf("%d",&server);
    
    //look it up in the server
    for(i=0;i<5;i++)
    {
        if(server==ServerUsers[i][0])
        {
            printf("There are %d user on server %d.\n",ServerUsers[i][1],server);
            break;
        }
    }
    
    //report error if not found
    if(i==5) printf("Server not listed.\n");

    return 0;
}



Even though an array has been given an initial value, its
contents "may be changed. For example, this program prints
hello on the screen.
#include <stdio.h>
#include <string.h>

int main()
{
    char str[80]="I like C";
    
    strcpy(str,"hello");
    printf(str);

    return 0;
}





 #include <stdio.h>

int main()
{
    int a[10][3];
    int i,j,x;
    
    for(i=0;i<10;i++)
    {
        x=i+1;
        for(j=0;j<3;j++)
        {
            a[i][j]=x;
            x=(i+1)*x;
        }
    }
    
    for(i=0;i<10;i++)
    for(j=0;j<3;j++)
    printf("%5d",a[i][j]);

    return 0;
}


Is this fragment correct?
int balancer] = 10.0, 122.23, 100.0;
2. Is this fragment correct?
#include <stdio.h>
#include <5tring.h>
int ma~n(void)
char name[] = -Tom";
strcpy{name, ftTom Brazwell-) i
3. Write a program that initializes a IOx3 array so that the fIrst
element of each row contains a number, the second element
contains its square, and the third element contams its cube.
Stan with 1 and stop at 10. For example, the fIrst few rows will
look like this:
1, 1, 1,
2,4,8,
3,9,27,
4,16,64,
Next, prompt the user for a cube, look up this value in the table,
and report the cube's root and the root's square. Use an unsized
array so that the table size may be easily changed

#include<stdio.h>

int main() {
    int cube[10][3] = {1,1,1,2,4,8,3,9,27,4,16,64,5,25,125,6,36,216,7,49,343,8,64,512,9,81,729,10,100,1000};
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
#include <stdio. h>
int main(vcid)
(
)
int cube[) [3) = (
1, 1. 1,
2, 4, 8,
3, 9, 27,
4, 16, 64,
5, 25, 125,
6, 36, 216,
7, 49, 343,
8, 64, 512,
9, 81, 729,
10, 100, 1000
) ;
int num, i;
printfC-Enter cube: .);
scanfC-%d-, &num);
for(i=O; i<10; i++)
if{cube[i) [2)==nurn) (
)
printf{ORoot; %d\n°, cube[i) [0));
printf{OSquare; %dO, cube[i) [1));
break;
if(i==10) printf(~Cube not found.\n");
return 0;
