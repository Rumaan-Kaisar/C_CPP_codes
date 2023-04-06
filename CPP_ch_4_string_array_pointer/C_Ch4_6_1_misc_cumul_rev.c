




What is the advantage of using pointers over array indexing?
Pointers are often more convenient than array indexing and
may be faster in some cases.

Below is a program that counts the Number of spaces in a string
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

iinclude <stdio.h>
int main (·void)
{
char strl80], *p;
int spaces:
printf (-Enter a string: M ) i
gets (str) ;
spaces = 0;
p = str;
while (.p) (
if(*p==' , ) spaces++;
p++ ;
}
printf (-Number of spaces: .% d- • spac.as) ;
return 0;

Rewrite the following array reference using pointer arithmetic.
int count[100][10];
count[44][8] = 99;


#include <Stdio.h>

int main()
{
    int i,*p;
    p=&i;
    *p=6;
    printf("%d",i);
    
    return 0;
}

#include <Stdio.h>

int main ()
{
    float f,*p;
    p=&f;
    *p=1.22;
    printf("%f",f);
    
    return 0;
}

#include <stdio.h>

int main ()
{
    int a[10],i,ev=0,od=0;
    for(i=0;i<10;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<10;i++)
    {
        if(a[i]%2==0)
        {
            ev=ev+a[i];
        }
        else od=od+a[i];
    }
    printf("sum of odd integers %d and sum of even integers %d",od,ev);
    
    return 0;
}



#include<stdio.h>
#include<string.h>

int main ()
{
    char namebook[][2][20]={  "Amy", "0191817161", "Paul", "01971615", "Farin", "01534694346"};
    char name[20];
    int i;
    gets(name);
    for(i=0;i<4;i++)
    {
        if(!strcmp(name,  namebook[i][0]))
        {
            printf("%s", namebook[i][1]);
            return 0;
        }
    }
    printf("Name not found");
    return 0;
}



#include <stdio.h>

int main ()
{
    char pass[10]="Tristan", tr[10];
    int i;
    printf("Enter password: ");
    for(i=1;i<=3;i++)
    {
        scanf("%s",&tr);
        if( pass[0]==tr[0] && pass[1]==tr[1] && pass[2]==tr[2] && pass[3]==tr[3] && pass[4]==tr[4] && pass[5]==tr[5] && pass[6]==tr[6])
        {
            printf("Log-on successful");
            return 0;
        }
        else printf("try again\n");
    }
    printf("Access denied");
    return 0;
}



