5.3 Parameters Advanced
Parameter and pointer, relation to arguments :  For computer languages in general, a subroutine ( function ) can be passed arguments in one of two ways. 
	The first is called call by value and there is no relation between parameters and arguments. 
	This method copies the value of an argument into the formal parameter of the subroutine. 
	Therefore, changes (Eg: interchange for swap) made to a parameter of the subroutine have no effect on the argument used to call it. 
	By default, C uses call by value to pass arguments. This means that you cannot alter the arguments used in a call to a function (Eg: cannot swap). What occurs to a parameter inside the function will have no effect on the argument outside the function.
	The second way a subroutine can have arguments passed to it is through can by reference (i.e. using pointers), in this method parameters and arguments are related to each others and data-types of arguments and parameter had to be same. 
	In this method, the address of an argument is copied into the parameter. Inside the subroutine, the address is used to access the actual argument. This means that changes made to the parameter will affect the, argument.
	It is possible to manually construct a call by reference by passing a pointer to an argument. Since this causes the address of the argument to be passed, it then is possible to change the value of the argument outside the function.
The classic example of a call-by-reference function is swap(). It exchanges the value of its two integer arguments.

#include <stdio.h>
void swap(int *i, int *j);
int main (void){int num1 , num2;
                num1 = 100;
                num2 = 800;
                printf("Before swap, num1: %d , num2: %d \n ", num1, num2 );
                swap(&num1, &num2);    /* Function call by location */
                printf("After swap, num1: %d , num2: %d \n ", num1, num2 );
        return 0;}

/* Exchange the values pointed to by two integer pointers . */
void swap(int *i, int *j){  int temp;
                            temp = *i;
                            *i = *j;
                            *j = temp;}

Since pointers to the two integers are passed to the function, the actual values pointed to by the arguments are exchanged.

Parameter and array: We know that when an array is used as an argument to a function, only the address of the array is passed, not a copy of the entire array, which implies call-by-reference. This means that the parameter declaration must be of a compatible pointer type.  There are three ways to declare a parameter that is to receive a pointer to an array.
	First, the parameter may be declared as an array of the same type and size as that used to call the function. 
	Second, it may be specified as an unsized array. 
	Finally, and most commonly, it may be specified as a pointer to the base type of the array. 

The following program demonstrates all three methods:

#include <stdio.h>
void f1(int num[5]), f2(int num[]), f3(int *num);
int main (void){    int count[5] = {1, 2, 3, 4, 5};
                    f1(count);  f2(count);  f3(count); 	/* All three function call */
                    return 0;}

/* parameter specified as array */
void f1(int num[5]){    int i;
                        for(i=0; i<5; i++) printf("%d ", num[i]); }

/* parameter specified as unsized array */
void f2(int num[]){ int i;
                    for(i=0; i<5; i++) printf("%d ", num[i]); }

/* parameter specified as pointer */
void f3(int *num){  int i;
                    for(i=0; i<5; i++) printf ("%d ", num[i]); }

Even though the three methods of declaring a parameter that will receive a pointer to an array look different, they all result in a pointer parameter being created.

Example : Following uses the function prompt() to display a prompting message and then to read a number entered by the user.

#include <stdio.h>
void prompt(char *msg, int *num); /* header function like declaration */
int main(void){ int i;
                prompt("Enter a num: ", &i);
                printf("\n Your number is: %d", i);
                return 0;}

void prompt(char *msg, int *num){   printf (msg);
                                    scanf("%d", num);}

Because the parameter num is already a pointer, you do not need to precede it with an & in the call to scanf( ) ( we used "&" in scanf() in all previous example and compare with the example of swap() ). In fact, it would be an error to do so. And in printf() we used the third way described in "parameter ad array" .

Note : 	pointer-address Mathematical formulation :
				pointer p = address of q
				⇒p  = &q
				⇒ *p = *(&q)
				⇒ *p=q,   ∴ *p=value of q




#include<stdio.h>
void prompt(char *msg,int *num);

int main ()
{
    int i;
    prompt("Enter a number ",&i);
    printf("Your number is %d",i);
}

void prompt(char *msg,int *num)
{
    printf(msg);
    scanf("%d", num);
}




#include<stdio.h>

void prompt(char *msg,char *num);

int main ()
{
    char i[80];
    prompt("Enter a number ",i);
    printf("Your number is %s",i);
}

void prompt(char *msg,char *num)
{
    printf(msg);
    scanf("%s", num);
}
