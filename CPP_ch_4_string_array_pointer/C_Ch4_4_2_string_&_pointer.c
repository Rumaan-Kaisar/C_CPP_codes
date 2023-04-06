
/* 
    ---------|    Use pointers to string constants    |---------

    C allows string constants enclosed between double quotes "" to be used in a program.
        When the compiler encounters such a string, it stores it in the program's string table and generates a pointer to the string.

        char *p;
        p = "one two three";	 
        printf(p);

        'char *p;' means that it may 'point' to an "array of characters". When the compiler compiles the line p = "one two three";  
            it stores the string in the program's string table and assigns to p the address of the string in the table.

        Above code can be written more efficiently:
            char *P = "one two three";
            printf(p) ;
            
            Here , p is initialized to point to the string.



    Note: Using "pointers" to string constants can be very helpful when those "constants are quite long". 
            For example suppose that you had 'a program 'that at various times would prompt the user to insert a diskette into drive A. 
                Using a pointer has following advantages

        Following uses a 'initialized pointer to the string' and then simply use the pointer when the message needed to be displayed
            Another advantage to this approach is that to change the prompt, 
            you only need to change it once, and all references to it will reflect the change.

                char *InsDisk = "Insert disk into drive A then press ENTER ";
                . . . .
                printf(InsDisk);
                . . . .
                printf(InsDisk);
*/




// Example 1: folloWing program prints 'one two three' on the screen.
#include <stdio.h>
int main(void){
    char *p;
    p = "one two three";
    printf(p);

    return 0;
}

// Above code can be written more efficiently
#include <stdio.h>
int main(void){
    char *p = "one two three";
    printf(p);

    return 0;
}




// Example 2: Following program continues to read strings until you enter "stop":
#include <stdio.h>
#include <string.h>

int main(void){
    char *p="stop";
    char str[80];
    
    do{
        printf("Enter a string:");
        gets(str);
    } while(strcmp(p, str));
    
    return 0;
}




/* Eaxmple 3: Write a program that creates 3 character pointers and initialize them so that 
                one points to the string "one", the second to the string "two", and the third to the string "three".
                Next, have the program print all six permutations of these three strings,
                (For exatnple, one permutation is "one two three', another is "two one three".) */
#include <stdio.h>

int main (void){
    char *one = "one";
    char *two = "two"; 
    char *three = "three" ;
    
    printf("%s %s %s\n", one, two, three);
    printf("%s %s %s\n", one, three, two);
    printf("%s %s %s\n", two, three, one);
    printf("%s %s %s\n", two, one, three);
    printf("%s %s %s\n", three, one, two);
    printf("%s %s %s\n", three, two, one);

    return 0;
}




/* Example 4: Is this fragment correct? If not, why not? */
int main(void){
    char *p;

    printf("Enter a string: ");
    gets(p);

    return 0;
}
/* No. The pointer p has never been initialized to point to a valid
piece of memory that can hold a string */




/* Example 5: How do pointers and arrays relate to each other? */
Pointers and arrays are basically two ways of looking at the
same thing. They are virtually interchangeable.




/* Example 6: Given this fragment:
                char *p, str[80] = "this lS a test";
                p = str;
                show two ways to access the 'i' in "this" */

str[2];
*(str+2);
*(p+2);



	
/* Example 7: Below is a program that counts the Number of spaces in a string
                entered by the user. Rewrite the program so that it uses "pointer
                arithmetic" rather than 'array indeXing'.

                #include <stdio.h>

                int main(void){
                    char str[80];
                    int i, spaces;

                    printf("Enter a string: ");
                    gets(str);

                    spaces = 0;
                    for(i=0; str[i]; i++) if(str[i]==' ') spaces++;
                    printf("Number of spaces: %d", spaces);

                    return 0;
                }
                */
#include <stdio.h>

int main(void){
    char str[80], *p;
    int spaces;

    printf("Enter a string: ");
    gets(str);

    spaces = 0;
    p = str;
    while (*p){
        if(*p==' ') spaces++;
        p++;    //this is 'pointer icrement' on memory size
    }
    
    printf("Number of spaces: %d", spaces);

    return 0;
}




/* Example 8: Is following fragment correct? If it is correct, explain why it works.
            char *p = "this is a string"; */
Yes, the fragment is correct. It works because the compiler creates a string table entry for the string 'this is a string' and
assigns p a pointer to the start of it.
	
	
	
