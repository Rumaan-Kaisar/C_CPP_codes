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
    
    
