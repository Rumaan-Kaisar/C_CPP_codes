
/*     ------------|    Pointers as PARAMETERS    |------------
    Pointers may be passed to functions. 
    For example, when you call a function like strlen() with the name of a string, you are actually "passing a pointer" to a function. 


    When you pass a pointer to a function, 
        the function must be declared as receiving a pointer of the 'same type'. In the case of strlen(), this is a "character pointer".  EG: 
                void my_func(char *p).  // pointer of the same type

        the code inside that function "has access to the variable" pointed to by the parameter. 
            This means that the function 'can change the variable' used to call the function. 
            This is why functions like strcpy(), for example, can work. 
                Because it is passed a pointer, the function is able to modify the array that receives the string.


    Note: 
        & in scanf(): why you need to precede a variable's name with an & when using scanf()? 
            In order for scanf() to modify the value of one of its arguments, it must be passed a pointer to that argument.

        puts():
            Another of C's standard library' functions, it "writes its string argument" to the screen followed by a 'newline'.

        When the compiler encounters a 'string constant', it places it into the 'programs string table' and generates a "pointer" to it. 
*/




/* Example 1: puts() writes its string argument to the screen followed by a newline.
                The program that follows creates its own version of puts() called myputs() . */
#include <stdio.h>

void myputs(char *p);

int main(void){
    myputs("this is a test");
    return 0;
}

void myputs(char *p){
    //loop as long as p does not point to the null that terminates the string
    while(*p){      
        printf("%c", *p);
        p++;    // go to next character
    }
    printf("\n");
}

/* Note: 
    When the compiler encounters a 'string constant', it places it into the 'programs string table' and generates a "pointer" to it.
    Therefore, the myputs() function is actually called with a 'character pointer' and 
        the parameter p must be declareed as a 'character pointer' in order to receive it. */




/* Example 2: The program that follows creates its own version of strcpy() function. called mystrcpy(). */
#include <stdio.h>

void mystrcpy(char *to, char *from);

int main(void){
    char str[] = "this is\n";

    printf(str);
    mystrcpy(str, "a test");
    printf(str);

    return 0;
}

void mystrcpy(char *to, char *from){
    while(*from) *to++ = *from++;
    *to = '\0'; // null terminates the string
}




/* Example 3: Write your own version of strcat() called mystrcat(), and write a short program that demonstrates it */
#include <stdio.h>
#include <string.h>

void mystrcat(char *to, char *from);

int main(void){
    char str[80];

    strcpy(str, "First part");

    mystrcat(str," second part");
    printf(str);
    
    return 0;
}

void mystrcat(char *to, char *from){
    // find the end  of 'to'
    while(*to) *to++;

    // concatenate the string
    while(*from) *to++= *from++;

    // add thge nul terminator        
    *to='\0';
}




/* Example 4: Write a program that "passes a pointer" to an integer variable to a function. 
                Inside that function, assign the variable the value -1.
                After the function has returned, demonstrate that the variable does, indeed, contain -1 by printing its value. */
#include <stdio.h>

void f(int *p);

int main(void){
    int i;

    f(&i);  // to modify the value of i
    printf("%d",i);
    
    return 0;
}

void f(int *p){
    *p = -1;
}


