
4.11 Multiple INDIRECTION
It is possible in C to have a pointer point to another pointer. This is called multiple indirection. When a pointer points to another pointer, the first pointer contains the address of the second pointer, which points to the location containing the object.

	To declare a pointer to a pointer, an additional asterisk is placed in front of the pointer's name For example, this declaration tells the compiler that nip is a pointer to a character pointer:
char **mp;
It is important to understand that mp is not a pointer to a character but rather a pointer to a character pointer.

	Accessing the target value indirectly pointed to by a pointer to a pointer requires that the asterisk operator be applied twice. For example,
char **mp, *p, ch;
p = &ch; 	/* get address of ch */ 
mp = &p; 	/* get address of p */
**mp = 'A'; 	/* assign ch the value A using multiple indirection */

As the comments suggest, ch is assigned a value indirectly using two pointers.

Note
	Not Recommended : Multiple indirection is not limited to merely "a pointer to a pointer." You can apply the * as often as needed. However, multiple indirection beyond a pointer to a pointer is very difficult to follow and is not recommended.
	As you learn more about C, you will see some examples in which it is very valuable.


#include <stdio.h>
int main ()
{
    float *fp, **mfp, val;
    
    fp=&val;
    mfp=&fp;
    
    **mfp=123.903;
    
    printf("%f %f",val,**mfp);
    
    return 0;
}


#include <stdio.h>

int main ()
{
    char *p,**mp,str[80];
    p=str;
    mp=&p;
    
    printf("Enter your name");
    gets(*mp);
    printf("hi %s",*mp);
    
    return 0;
}


#include <stdio.h>

int main ()
{
    int x, *p,**mp;
    p=&x;
    mp=&p;
    
    **mp=55;
    
    printf("%p %p %p",&x,p,mp);
    
    return 0;
}
