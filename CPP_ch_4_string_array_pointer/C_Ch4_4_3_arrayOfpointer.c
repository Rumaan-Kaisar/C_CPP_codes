
/* 
    ----------|    Arrays of Pointers    |----------
    Pointers can be arrayed like any other data type. 
        For example, the following is an "integer pointer array" that has 20 elements:
        The address of an integer variable called "myvar" is assigned to the "ninth element" of the array as follows:
                int *pa[20];
                pa[8] = &myvar;     // Assigning the address
        Because "pa" is an array of 'int pointers', the only values that the array elements may hold are the "addresses" of integer variables.

        To assign the integer pointed to by the third element of pa the value 100, use the statement:
                *pa[2] = 100;       // Assigning values by pointer

*/




/* Example 1: Common use of "arrays of pointers" is to create string tables similar to "unsized arrays". 
                Following function displays an error message based on the value of its parameter "err_num". */

char *p[] = {
    "Input exceeds field width",
    "Out of range",
    "Printer not turned on",
    "Paper out",
    "Disk full",
    "Disk write error"
};

void error(int err_num){
    printf(p[err_num]);
}




/* Example 2: The following program uses a two-dimensional array of pointers to create a string table that
                links apple varieties with their colors. To use the program, enter the name of the apple, and the
                program will tell you its color */
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
        "", "",     // terminate the table with 'null strings'
    };
    
int main(void){
    int i;
    char apple[80];

    printf("Enter name of apple");
    gets(apple);

    for(i=0; *p[i][0]; i++){
        if (!strcmp(apple, p[i][0]))
            printf("%s is %s\n",apple, p[i][1]);
    }
    
    return 0;
}
/* Look carefully at the condition controlling the for loop. 
The expression *p[i][0] gets the value of the first byte of the ith string. 
Since the list is terminated by "null strings", this value will be 0 (false) when the end of the table is reached. 
In all other cases it will be nonzero, and the loop will repeat. */




/* Example 3: create an 'executive decision aid'. 
                This is a program that answers yes, no, or maybe to a question entered at the keyboard. 
                To create this program use an array of character pointers and initialize them to point to these three strings: 
                        "Yes", "No', and 'Maybe Rephrase the queStiOn'. 
                Next, input thc user's question and find the length of the string. 
                Next, use following formula to cmnpute an index into the pointer array:
                        index = length % 3 */
#include <stdio.h>
#include <string.h>

int main(void){
    char *p[3] = { "Yes", "No", "Maybe. Rephrase the question" };
    char str[80];

    printf("Enter your question:\n");
    gets(str);
    
    printf(p[strlen(str)%3]);
    
    return 0;
}


