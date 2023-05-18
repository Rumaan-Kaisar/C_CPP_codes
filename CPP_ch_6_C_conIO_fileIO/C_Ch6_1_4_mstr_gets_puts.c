/*     
    ---------------    String IO    ---------------
                gets()
                puts()
    Prototypes:
        char *gets(char *str); // "pointer-function" returns char type & char type "pointer-parameter"
        int puts(char *str);   // " function" returns int type & char type "pointer-parameter"

        Both use STDIO.H. 
        Both do not perform bound checking (checking the size) before storing the string into the character array.



    puts():
    outputs the string pointed to by 'str' to the screen. 
    It automatically appends a carriage return. 
        Example : puts("one"); puts("two") ; puts("three"); outputs the words 'one', 'two', and 'three' on three separate lines.
    If successful, puts() returns a "non-negative value". 
    If an error occurs, EOF is returned.

    puts() is much smaller and faster than printf()



    gets():
        gets() reads characters until a CARRIAGE RETURN is read. 
        It stores the 'characters' in the array pointed to by "str". 
        The "CARRIAGE RETURN" is not added to the string. Instead, it is CONVERTED into the "NULL TERMINATOR". 
        If successful,  gets() returns a "pointer" to the "start of str". 
        If an error occurs, a 'null pointer' is returned.

    Even though gets() returns a pointer to the 'start of the string', it still must be called with a "POINTER TO AN ACTUAL ARRAY".

        For example, the following is wrong:
        char *p;
        p = gets(p); 	 // wrong!!!
        Here, "there is no ARRAY defined" into which gets() can put the string. This will result in a program failure. 
*/




/* Example 1: This program shows how you can use the return value of gets() to access the string holding the input information.
                Notice that this program also confirms that no error has occurred before attempting to use the string. */
#include <stdio.h>
int main(void){
    char *p, str[80];

    printf("Enter a string: ");

    p = gets(str);  // Notice "POINTER TO AN ACTUAL ARRAY"

    // if not null
    if(p) printf("%s %s", p, str);

    return 0;
}




/* Example 2: If you simply want to make sure that gets() did not encounter
                an error before proceeding, you can place gets() directly inside an if statement, 
                as illustrated by the following program: 
                Because a null pointer is false, there is no need for the
                intermediary variable p, and the gets() statement can be put directly inside the if.*/

#include <stdio.h>

int main(void){
    char str[80];

    printf("Enter a string: ");

    // if not null 
    if(gets(str)) printf("Here is your string: %s", str);

    return 0;
}




/* Example 3: Compile the program shown in Example 2, above. Note the size
                of the compiled code. Next, convert it so that it uses puts(), instead of printf( ).
                You will find that the printf() version is several byte, larger. */
#include <stdio.h>

int main(void){
    char str[80];

    puts("Enter a string: ");

    // if not null
    if(gets(str)) puts(str);

    return 0;
}




/* Example 4: It is important to understand that even though gets( ) returns a
pointer to the start of the string, it still must be called with a
pointer to an actual array. For example, the following is wrong: */

char *p;
p = gets(p); // wrong!!!

// Here, there is no array defined into which gets( ) can put the string. This will result in a program failure.




/* Example 5: This program outputs the words 'one', 'two', and 'three' on three separate lines. using puts( ). */
#include <stdio.h>

int main(void){
    puts("one");
    puts("two");
    puts("three");

    return 0;
}




/* Example 5: Following program is incorrect.
                Because gets() must be called with a "pointer to an actual array". */
#include<stdio.h>
int main(void) {
    char *p, *q;

    printf("Enter a string: ");
    p = gets(q);
    printf(p);

    return 0;
}




/* Example 6: What is one advantage to using puts() over printf() when
                you only need to output a string? What is one disadvantage to puts()? */
The pats() function is much smaller and faster than printf().
But, it can only output strings.

   
    
    
/* Example 7: What is EOF, and where is it defined? */
EOF is a macro that stands for "end-of-file". It is defined in STDIO.H.
    
    
    

/* Example 8: Write a program that is a "SIMPLE ELECTRONIC LIBRARY" card catalog. Have the program display this menu:

                                Card Catalog:
                                    1. Enter
                                    2. Search by Author
                                    3. Search by Title
                                    4. Quit

                                Choose your selection:

                If you choose Enter, have the program repeatedly input the name, author, and publisher of a book. 
                    Have this process continue until the user enters a blank line for the name of the book.

                For searches, prompt the user for the specified author or title and
                then, if a match is found, display the rest of the information. 

                In the next chapter we'll learn how to save the catalog to a disk file (File I/O). 
*/

// Note: There are many ways you could have written this program. This one is simply representative

/* =-=-=-=-=-=-=-=-=-=-=            An electronic card catalog             =-=-=-=-=-=-=-=-=-=-= */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Function prototypes
int menu(void);
void display(int i);
void author_search(void);
void title_search(void);
void enter(void);

// global variables
char names[MAX][80];    // author names
char titles[MAX][80];   // titles
char pubs[MAX][80];     //publisher

int top= 0;             // last location used


int main(void) {
    int choice;

    do{
        choice = menu();

        switch(choice) {
            case 1: enter(); // enter books
                    break;
            case 2: author_search(); // search by author
                    break;
            case 3: title_search(); // search by title
                    break;
        }
    } while(choice!=4);

    return 0;
}


// Return a menu selection
int menu(void){
    char str[80];
    int i;

    printf("Card Catalog: \n");
    printf(" 1. Enter\n");
    printf(" 2. Search by Author\n");
    printf(" 3. Search by Title\n");
    printf(" 4. Quit\n");

    do {
        printf("Choose your selection: ");
        gets(str);
        i = atoi(str);
        printf("\n") ;
    } while(i<1 || i>4);

    return i;
}


// Enter books into database.
void enter(void){
    int i;

    for(i=top; i<MAX; i++) {
        printf("Enter author name (hit-ENTER to quit): ");
        gets(names[i]);
        if(!*names[i]) break;
        printf("Enter title: ");
        gets(titles[i]);
        printf("Enter publisher: ");
        gets(pubs[i]);
    }
    top = i;
}


// Search by author
void author_search(void){
    char name[80];
    int i, found;

    printf("Name: ");
    gets(name);

    found = 0;

    for(i=0; i<top; i++){
        if(!strcmp(name, names[i])){
            display(i);
            found = 1;
            printf(" \n");
        }
    }

    if(!found) printf("Not Found\n");
}


// Search by title
void title_search(void){
    char title[80];
    int i, found;

    printf("Title: ");
    gets(title);

    found = 0;

    for(i=0; i<top; i++){
        if(!strcmp(title, titles[i])){
            display(i) ;
            found = 1;
            printf("\n");
        }
    }

    if(!found) printf("Not Found\n");
}


// Display catalog entry
void display(int i){
    printf("%s\n", titles[i]);
    printf("by %s\n", names[i]);
    printf("Published by %s\n", pubs[i]);
}



