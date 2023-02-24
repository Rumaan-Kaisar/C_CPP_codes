// Example 1: how to pass a single-dimensional array to a function.

#include <stdio.h>  

void getarray(int arr[]);

int main(void)  {  
   int arr[5]={45,67,34,78,90};  
   getarray(arr);  
   return 0;  
}

void getarray(int arr[])  {  
    printf("Elements of array are : ");  
    for(int i=0;i<5;i++)  {  
        printf("%d ", arr[i]);  
    }  
} 


// Example 2: Passing array to a function as a pointer
#include <stdio.h>  
void printarray(char *arr);

int main(void) {  
  char arr[5]={'A','B','C','D','E'};  
  printarray(arr);  
  return 0;  
}  

void printarray(char *arr)  {  
    printf("Elements of array are : ");  
    for(int i=0;i<5;i++) printf("%c ", arr[i]); 
}  