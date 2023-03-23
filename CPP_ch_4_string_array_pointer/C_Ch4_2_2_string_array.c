

/* 
----------|    ARRAYS OF STRINGS    |----------
Arrays of strings, often called string tables.
A string table is created like any other "two-dimensional array". For example, here is a small string table. 
        char names[10][40];
    This statement specifies a table that can contain 10 strings, each up to 40 characters long (including the null terminator).
    To access a string within this table, specify only the left-most index.
    
    For example, to read a string from the keyboard into the third string in names :
        gets(names[2]);
    
    To output the first string, use this printf() statement:	
        printf (names[0] ) ;



----------|    Three-dimensional table of strings    |----------
 		char animals[3][5][80];
The declaration creates a three-dimensional table with "three lists of strings". 
Each list is five strings long, and 
each string can hold 80 characters.

To access a specific string in this situation, you must specify the two left-most indexes. 
    For example, to access the "second string" in the "third list", specify
        animals[2][1].  
*/




/* Example 1: This program lets you enter ten strings, then lets you display
                them, one at a time, in any order you choose. To stop the program, enter a negative number. */
#include <stdio.h>

int main(void){
    char text[10][80];
    int i;
    
    for(i=0; i<10; i++){
        printf("%d: ", i+1);
        gets(text[i]);
    }
    
    do{
       printf("Enter number of string (1-10) :");
       scanf("%d",&i);
       i--; //adjust value to match array index
       if(i>=0 && i<10) printf("%s\n", text[i]);
    }while(i>=0);

    return 0;
}




/* Example 2: You can initialize a string table as you would any other type of array. 
                For example, the following program uses an initialized
                string table to translate between German and English. Notice
                that curly braces are needed to surround the list. The only time
                they are not needed is when a single string is being initialized . */
//English to German translator

#include <stdio.h>
#include <string.h>

/* Unsized array of list, each list contain 1 english (index 0) and 1 german (index 0) word,
an word can be 40 char long */
char words[][2][40]={
    "dog","Hund",
    "no","nein",
    "year", "Jahr",
    "child", "Kind",
    "I", "Ich",
    "drive", "fahren",
    "house", "Haus",
    "to", "zu",
    "",""
};

int main(void){
    char english[80];
    int i;
    
    printf("Enter English word: ");
    gets(english);
    
    //look up the word
    i=0;
    //search while null string  not yet encountered
    while(strcmp(words[i][0],"")){
        if(!strcmp(english, words[i][0])){
            printf("German translation: %s", words[i][1]);
            break;
        }
        i++;
    }
    
    if(!strcmp(words[i][0],"")) printf("NOt in dictonary\n");
    
    return 0;
}




/* Example 3: You can access the individual characters that comprise a string
                within a string table by using the rightmost index. For example,
                the following program prints the strings in the table one
                character at a time. */
#include <stdio.h>

int main(void){
    char text[][80]={
        "When", "in", "the",
        "course", "of", "human",
        "events", ""
    };
    
    int i, j;
    
    //now display them
    for(i=0; text[i][0]; i++){
        for(j=0; text[i][j]; j++){
            printf("%c",text[i][j]);
            printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}




/* Example 4: Write a program that creates a string table containing the
English words for the numbers 0 through 9. Using this table,
allow the user to enter a digit (as a character) and then have
your program display the word equivalent. (Hint: to obtain an
index into the table, subtract '0' from the character entered.) */

#include<stdio.h>
#include <conio.h>
int main(void){

    char numbers[10][10]={
        "Zero",
        "One",
        "Two",
        "Three",
        "Four",
        "Five",
        "Six",
        "Seven",
        "Eight",
        "Nine",
    };

    char num;

    printf("Enter a number(0-9): ");
    num = getche();
    printf("Entered number %d\n", (int)num);
    // scanf(" %c", &num);

    num = num -'0'; // makes "num" between 0 and 9 during type promotion
    printf("Index number %d\n", (int)num);
    if(num>=0 && num<10) printf("%s", numbers[num]);

    return 0;
}




/* Example 5: Write a program that creates a string table consisting of names
                and telephone numbers. Initialize the array with some names of
                people you know and their phone numbers. Next, have the
                program request a name and print the associated telephone
                number. In other words, create a computerized telephone book. */


/* Notice "", "" used to determine end of the string-array */
/* --------|    A Simple computerized telephone book.    |-------- */
#include <stdio.h>
#include <string.h>
char phone[][2][15] = {
        "Omi", "0191817161",
        "Paula", "01971615",
        "Farin", "01534694346",
        "Fred", "555-1010",
        "Barney", "555-1234",
        "Ralph", "555-2347",
        "Tom", "555-8396",
        "", ""
};

int main(void){
    char name[80];
    int i;

    printf("Name? ");
    gets(name);

    for(i=0; phone[i][0][0]; i++){
        if( !strcmp(name, phone[i][0] ) ) printf ("number: %s", phone[i][1]);
    }

    return 0;
}

