

4.12 Pointers as Parameters
Pointers may be passed to functions. For example, when you call a function like strlen() with the name of a string, you are actually passing a pointer to a function. 
	When you pass a pointer to a function, the function must be declared as receiving a pointer of the same type. In the case of strlen(), this is a character pointer.  EG: void my_func(char *p).  /* pointer of the same type */

	When you pass a pointer to a function, the code inside that function has access to the variable pointed to by the parameter. This means that the function can change the variable used to call the function. This is why functions like strcpy( ), for example, can work. Because it is passed a pointer, the function is able to modify the array that receives the string.

Note 
[1]	& in scanf(): why you need to precede a variable's name with an & when using scanf() ? In order for scanf() to modify the value of one of its arguments, it must be passed a pointer to that argument.

[2]	 puts() :Another of C's standard library' functions is called puts( ); it writes its string argument to the screen followed by a newline.

[3]	When the compiler encounters a string constant, it places it into the programs string table and generates a pointer to it. 



#include <stdio.h>

void myputs(char *p)
{
    while(*p)
    {
        printf("%c",*p);
        p++;
    }
    printf("\n");
}

int main ()
{
    myputs("this is a test");
    return 0;
}



#include <Stdio.h>

void mystrcpy(char *to, char *from)
{
    while(*from) *to++=*from++;
    *to='\0';
}

int main ()
{
    char str[]="this is";
    mystrcpy(str,"a test");
    printf(str);
    return 0;
}


#include <stdio.h>

void mystrcat(char *to,char *from)
{
    while(*to)
        *to++;
    while(*from)
        *to++=*from++;
        
    *to='\0';
}

int main ()
{
    char str[]="this is";
    mystrcat(str,"a test");
    printf(str);
    
    return 0;
}


#include <stdio.h>

void f(int *p)
{
    *p=-1;
}

int main ()
{
    int i;
    f(&i);
    printf("%d",i);
    
    return 0;
}

