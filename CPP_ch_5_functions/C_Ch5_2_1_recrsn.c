
5.2 Recursion
Recursion is the process by which something is defined in terms of itself. When applied to computer languages, recursion means that a function can call itself. Not all computer languages support recursive functions, but C does. 

A very simple example of recursion is shown in this program:
#include <stdio.h>
void recurse(int i);
int main(void){ recurse(0) ;    return 0;}

void recurse(int i){
    if(i<10){          	/* Condition to control recursion */
        recurse(i+1);      /* recursive call */
        printf(" %d ", i);
        }
}
This program prints 9 8 7 6 5 4 3 2 1 0  on the screen. 
Let's see why. 
	The recurse() function is first called with 0. This is recurse()'s first activation. Since 0 < 10, recurse() ,then calls itself with the value of (i = 0) + 1, 
	This is the second activation of recurse() and i = 1. Since 1<10 , this causes recurse() to be called again using the value (i=1) + 1. 
	This process repeats until recurse() is called with the value 10. Since 10≮10 This causes recurse() to return (and stops recursion). Since it returns to the point of its call, it will execute the printf ) statement in its previous activation (i.e. 9th  activation ), print 9, and return. 
	This, then, returns to the point of its call in the previous activation (8th activation), which causes print 8. 
	The process continues until all the calls return, and the program terminates. We can assemble this in following stages :
The recursion starts at i=0, from call recurse(0); The fuction is then activated
	Stage 0 : condition check : i=0<10. Call recurse() with (i=0)+1 i.e. recurse(1) is called.
	Stage 1 : condition check : i=1<10. Call recurse() with (i=1)+1 i.e. recurse(2) is called. 
	Stage 3 : condition check : i=2<10. Call recurse() with (i=2)+1 i.e. recurse(3) is called.
. . . . . . . . . . . . . . . . . . . . . . . . . .
. . . . . . . . . . . . . . . . . . . . . . . . . .
	Stage 9 : condition check : i=9<10. Call recurse() with (i=9)+1 i.e. recurse(10) is called.
	Stage 10 : condition check : i=10<10 is false and condition fails.  recurse() stopped. Function returns to stage 9.

After returning to stage 9 ,the next statement after the function calls executed i.e. prints i=9 using printf(). The stage 9 is now complete. It then returns to stage 8 and similarly prints i=8. This process repeats until stage 0 is complete. The function then returns  to main() and reach to the end of the program.

            i=0<10               i=1<10                   i=2<10               i=3<10                                                                          i=7<10                   i=8<10               i=9<10
[0]                        [1]                        [2]                        [3]                        [4]          . . . . . .  . . . . .                    [7]                        [8]                        [9]                        [10]

                       return                 return                    return                        return                    return                   return                    return                      return                      return

printf()              printf()              printf()              printf()              printf()    . . . . . .  . . . . .                    printf()              printf()               printf()              printf()
i = 0                     i = 1                    i = 2                     i = 3                     i = 4         . . . . . .  . . . . .                    i = 7                    i = 8                     i = 9                    

	We need to remember one point that, the value of i in each stage is stored before the recursive call. And the numbers displayed 9 8 7 6 5 …. 0.
	The reason for that is : the printf() is appeared after the recursive-call-point, in this case all recursive calls need to be done first and then proceed to printf() for each corresponding stage.
	However, if printf() appears before  the recursive-call-point it could display : 0 1 2 3 …. 9. As given below:

void recurse(int i){
    if(i<10){          	/* Condition to control recursion */
 printf(" %d ", i); /* printf() appears before the recursive-call-point */
        recurse(i+1);      /* recursive call */
        
        } 
}

Recursion and control statement : Recursion is essentially a new type of program control mechanism (i.e. it can be used as a control statement). This is why every recursive function you write will have a conditional statement that controls whether the function will call itself again or return. Without such a (conditional ) statement, a recursive function will simply run wild, using up all the memory allocated to the stack and then crashing the program.

Usage of recursion :  Recursion can be quite useful in simplifying certain algorithms. For example, the Quick-sort sorting algorithm is difficult to implement without the use of recursion.  If you are new to programming in general, you might find yourself uncomfortable with recursion. 


Note
	It is important to understand that there are not multiple copies of a recursive function. Instead, only one copy exists. When a function is called, storage for its parameters and local data are allocated on the stack. Thus, when a function is called recursively, the function begins executing with a new set of parameters and local variables, but the code that constitutes the function remains the same.
	Stack : A stack is a data structure which is used to store data in a particular way. Two operations can be performed on a stack : push operation which inserts an element into the stack. Pop operation which removes the last element that was added into the stack. It follows last in first out (LIFO) order




#include <stdio.h>

void recurse(int i);

int main ()
{
    recurse(0);
    return 0;
}

void recurse(int i)
{
    if(i<10)
    {
        printf("%d ",i);
        recurse(i+1);

    }
}




#include <stdio.h>

void rcopy(char *s1,char *s2);

int main ()
{
    char str[80];
    rcopy(str,"this is a test");
    printf(str);
    return 0;
}

void rcopy(char *s1,char *s2)
{
    if(*s2)
    {
        *s1++=*s2++;
        rcopy(s1,s2);
    }
    else *s1='\0';
}




#include <stdio.h>

void f2(int b);
void f1(int a);

int main ()
{
    f1(30);
    
    return 0;
}

void f1(int a)
{
    if(a) f2(a-1);
    printf("%d ",a);
}

void f2(int b)
{
    printf(".");
    if(b) f1(b-1);
}





#include <stdio.h>

int fact(int a);

int main ()
{
    int x;
    printf("Enter a number: ");
    scanf("%d",&x);
    x=fact(x);
    printf("Factorial is %d",x);
}

int fact(int a)
{
   if (a==1) return 1;
   else return a*fact(a-1);
}





#include <stdio.h>

void print(char *c);

int main ()
{
    char st[]="this is a test";
    print(st);
}

void print(char *c)
{
    if(*c)
    {
        printf("%c",*c);
        print(c+1);
    }
}



