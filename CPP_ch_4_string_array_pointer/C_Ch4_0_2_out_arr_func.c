// Example 1:  How to return an array from a function. Returning pointer pointing to the array.
#include <stdio.h>  
int *getarray()  
{  
    int arr[5];  
    printf("Enter the elements in an array : ");  
    for(int i=0;i<5;i++)  
    {  
        scanf("%d", &arr[i]);  
    }  
    return arr;  
}  
int main()  
{  
  int *n;  
  n=getarray();  
  printf("\nElements of array are :");  
  for(int i=0;i<5;i++)  
    {  
        printf("%d", n[i]);  
    }  
    return 0;  
}  

/* 
JavaTpoint:
In the above program, getarray() function returns a variable 'arr'. 
It returns a local variable, but it is an illegal memory location to be returned, which is allocated within a function in the stack. 
Since the program control comes back to the main() function, and all the variables in a stack are freed. 
Therefore, we can say that this program is returning memory location, which is already de-allocated, 
so the output of the program is a segmentation fault 
*/

/* 
There are three right ways of returning an array to a function:

Using dynamically allocated array
Using static array
Using structure 
*/

// Returning array by passing an array which is to be returned as a parameter to the function.

#include <stdio.h>  
int *getarray(int *a)  
{  
    
    printf("Enter the elements in an array : ");  
    for(int i=0;i<5;i++)  
    {  
        scanf("%d", &a[i]);  
    }  
    return a;  
}  
int main()  
{  
  int *n;  
  int a[5];  
  n=getarray(a);  
  printf("\nElements of array are :");  
  for(int i=0;i<5;i++)  
    {  
        printf("%d", n[i]);  
    }  
    return 0;  
}


Returning array using malloc() function.

#include <stdio.h>  
#include<malloc.h>  
int *getarray()  
{  
    int size;  
    printf("Enter the size of the array : ");  
    scanf("%d",&size);  
    int *p= malloc(sizeof(size));  
    printf("\nEnter the elements in an array");  
    for(int i=0;i<size;i++)  
    {  
        scanf("%d",&p[i]);  
    }  
    return p;  
}  
int main()  
{  
   int *ptr;  
   ptr=getarray();  
   int length=sizeof(*ptr);  
   printf("Elements that you have entered are : ");  
   for(int i=0;ptr[i]!='\0';i++)  
    {  
      printf("%d ", ptr[i]);  
    }  
  return 0;  
}


Using Static Variable


#include <stdio.h>  
int *getarray()  
{  
  static int arr[7];  
  printf("Enter the elements in an array : ");  
  for(int i=0;i<7;i++)  
  {  
      scanf("%d",&arr[i]);  
  }  
  return arr;  
      
}  
int main()  
{  
  int *ptr;  
  ptr=getarray();  
  printf("\nElements that you have entered are :");  
  for(int i=0;i<7;i++)  
  {  
      printf("%d ", ptr[i]);  
  }  
}  
In the above code, we have created the variable arr[] as static in getarray() function, which is available throughout the program. Therefore, the function getarray() returns the actual memory location of the variable 'arr'.

Output

Return an Array in C
Using Structure

The structure is a user-defined data type that can contain a collection of items of different types. Now, we will create a program that returns an array by using structure.
#include <stdio.h>  
#include<malloc.h>  
struct array  
{  
    int arr[8];  
};  
struct array getarray()  
{  
    struct array y;  
    printf("Enter the elements in an array : ");  
    for(int i=0;i<8;i++)  
    {  
        scanf("%d",&y.arr[i]);  
    }  
    return y;  
}  
int main()  
{  
  struct array x=getarray();  
  printf("Elements that you have entered are :");  
  for(int i=0;x.arr[i]!='\0';i++)  
  {  
      printf("%d ", x.arr[i]);  
  }  
    return 0;  
}