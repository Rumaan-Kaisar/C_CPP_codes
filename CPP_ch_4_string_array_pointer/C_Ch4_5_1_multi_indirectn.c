
/* 
    ------------|    Multiple INDIRECTION    |------------
    a pointer points to another pointer. This is called multiple indirection.  When a "pointer" points to another pointer, 
    the 'first pointer' contains the 'address of the second pointer', which points to the 'location containing the object'.

    To declare a "pointer to a pointer", an "additional asterisk **" is placed in front of the pointer's name. 
    For example, this declaration tells the compiler that 'mp' is a "pointer" to a "character pointer":
                char **mp;
        It is important to understand that 'mp' is not a 'pointer to a character' but rather a "pointer to a character pointer".

    Accessing the target value indirectly pointed to by a "pointer to a pointer" requires that the asterisk operator * be applied twice. For example,

            char **mp, *p, ch;
            p = &ch; 	// get address of ch 
            mp = &p; 	// get address of p 
            **mp = 'A'; 	// assign ch the value A using multiple indirection, to 'ch'

        As the comments suggest, "ch" is assigned a value indirectly using two pointers.

    Note:
        Not Recommended : Multiple indirection is not limited to merely "a pointer to a pointer." 
        You can apply the * as often as needed. However, multiple indirection beyond a 'pointer to a pointer' is very difficult to follow and is not recommended.
*/    




/* Example 1: The fonowing program assigns "val" a value using multiple indirection. 
                It displays the value first directly, then through the use of multiple indirection. */
#include <stdio.h>

int main(void){
    float *fp, **mfp, val;
    
    fp = &val;
    mfp = &fp;
    
    **mfp = 123.903;
    printf("directly: %f, by multiple indirection: %f", val, **mfp);
    
    return 0;
}




/* Example 2: This program shows how you can input a string using gets() by using a "pointer to a pointer to the string".

                Notice that when mp is used as an argument to both gets() and printf(), only one * is used. 
                This is because both of these functions already require a pointer to a string for their operation .

                Rememher, **mp is a pointer to p. However, p is a pointer to the string str. 
                    Therefore. *mp is a pointer to str.  */
#include <stdio.h>

int main(void){
    char *p, **mp, str[80];

    p = str;    // no & is used with 'arrays' and 'strings' because these are already pointers
    mp = &p;
    
    printf("Enter your name");
    gets(*mp);
    printf("Hi %s", *mp);
    
    return 0;
}




/* Example 3: Write a program that assigns an "integer value" using a 'pointer to a pointer'. 
                Before the program ends, display the "addresses" of the
                integer variable, the pointer, and the 'pointer to the pointer'.
                (Remember, use %p to display a pointer value) */
#include <stdio.h>

int main(void){
    int x, *p, **mp;

    p  = &x;
    mp = &p;
    
    **mp = 13;
    
    printf("%p %p %p", &x, p, mp);  // &x is x's location
    
    return 0;
}


