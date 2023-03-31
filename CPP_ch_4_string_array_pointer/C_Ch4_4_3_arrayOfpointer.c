

4.10 Arrays of Pointers
Pointers may be arrayed like any other data type. For example, the following statement declares an integer pointer army that has 20 elements:
int *pa[20];

	The address of an integer variable called myvar is assigned to the ninth element of the array as follows:

pa[8] = &myvar:; /*Assigning the address*/
Because pa is an array of pointers, the only values that the array elements may hold are the addresses of integer variables.

	To assign the integer pointed to by the third element of pa the value 100, use the statement:
*pa[2] = 100; /*Assigning values by pointer*/
Note
Common use of arrays of pointers is to create string tables in much the same wav that unsized arrays were used in the previous section. 



#include<stdio.h>
#include <string.h>

char *p[][2]={
        "Red delicious", "red",
        "Golden delicious", "golden",
        "Winesap", "red",
        "Gala","reddish orange",
        "Lodi","green",
        "Mutsu", "yellow",
        "Cortland", "red",
        "Jonathan", "red",
        " ", " ",
    };
    
int main ()
{
    int i;
    char apple[80];
    printf("Enter name of apple");
    gets(apple);
    for(i=0; *p[i][0];i++)
    {
        if (!strcmp(apple,p[i][0]))
            printf("%s er color hoilo %s",apple,p[i][1]);
    }
    
    return 0;
}





#include <stdio.h>
#include <string.h>

*p[3]={ "Yes", "No", "Maybe. Rephrase the question" }; // global pointer array

int main ()
{
    char str[80];
    printf("Enter your question:\n");
    gets(str);
    
    printf(p[strlen(str)%3]);
    
    return 0;
}
