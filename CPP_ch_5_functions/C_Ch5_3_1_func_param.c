

/* 
    ---------|    Parameters Advanced    |---------
    Parameter and pointer, relation to arguments:
        In general, a subroutine ( function ) can be passed arguments in one of two ways. 

        call by value: 
                no relation between parameters and arguments. 
                This method copies the value of an argument into the formal parameter of the subroutine. 
            Therefore, changes (Eg: interchange for swap) made to a parameter of the subroutine have no effect on the argument used to call it. 
            By default, C uses call by value to pass arguments.
        
            This means that you cannot alter the arguments used in a call to a function (Eg: cannot swap). 
            What occurs to a parameter inside the function will have no effect on the argument outside the function.

        call by reference (i.e. using pointers):
            In this method parameters and arguments are related to each others and 
            data-types of arguments and parameter had to be same. 
            In this method, the "address" of an argument is copied into the parameter. Inside the subroutine, the address is used to access the actual argument.    
                This means that changes made to the parameter will affect the, argument.
        
            It is possible to manually construct a "call by reference" by passing a pointer to an argument. 
            Since this causes the address of the argument to be passed, it then is "possible to change the value of the argument outside" the function.

            The classic example of a "call-by-reference" function is swap(). It exchanges the value of its two integer arguments. 


    Difference between "CALL BY VALUE" and "CALL BY REFERENCE":
        In call by value, the value of an argument is passed to a function. 
        In can by reference, the address of an argument is passed to a function.
*/




/* -----------------|    swap using pointer    |----------------- */
/* Example 1: The classic example of a "call-by-reference" function is swap(). It exchanges the value of its two integer arguments. */
#include <stdio.h>

void swap(int *i, int *j);

int main (void){
    int num1 , num2;

    num1 = 100;
    num2 = 800;
    
    printf("Before swap, num1: %d , num2: %d \n ", num1, num2 );

    swap(&num1, &num2);    // Function call by location

    printf("After swap, num1: %d , num2: %d \n ", num1, num2 );

    return 0;
}

// Exchange the values pointed to by two integer pointers .
void swap(int *i, int *j){  
    int temp;

    temp = *i;
    *i = *j;
    *j = temp;
}

// Since pointers to the two integers are passed to the function, the actual values pointed to by the arguments are exchanged.



/* 
---------|    Parameter and array    |---------
when an array is used as an argument to a function, 
    only the 'address of the array' is passed, not a copy of the entire array, which implies call-by-reference. 
    
    This means that the parameter declaration must be of a compatible pointer type.  
    
    There are "THREE WAYS" to declare a parameter that is to receive a pointer to an array.
	    First, the "PARAMETER" may be declared "as an array" of the 'same type and size' as that used to call the function. 
	    Second, it may be specified as an "UNSIZED ARRAY". 
	    Finally, and most commonly, it may be "specified as a POINTER" to the "base type" of the array.  */




/* Example 2: The following program demonstrates all three methods: */

#include <stdio.h>

void f1(int num[5]);
void f2(int num[]);
void f3(int *num);

int main(void){    
    int count[5] = {1, 2, 3, 4, 5};

    // All three function call
    f1(count);  
    f2(count);  
    f3(count);
     	
    return 0;
}

/* parameter specified as array */
void f1(int num[5]){    
    int i;
    
    for(i=0; i<5; i++) printf("%d ", num[i]); 
}

/* parameter specified as unsized array */
void f2(int num[]){ 
    int i;
    
    for(i=0; num[i]; i++) printf("%d ", num[i]); 
}

/* parameter specified as pointer */
void f3(int *num){  
    int i;
    
    for(i=0; num[i]; i++) printf ("%d ", num[i]); }

/* Even though the three methods of declaring a parameter that will receive a pointer to an array look different, 
they all result in a pointer parameter being created. */




/* Example 3: Following uses the function prompt() to display a prompting message and then to read a number entered by the user. */

#include <stdio.h>

void prompt(char *msg, int *num); // header function like declaration

int main(void){ 
    int i;

    prompt("Enter a num: ", &i);
    printf("\n Your number is: %d", i);

    return 0;
}

void prompt(char *msg, int *num){   
    printf (msg);
    scanf("%d", num);
}

/* Because the parameter num is 'already a pointer', you do not need to precede it with an & in the call to scanf() 
( we used "&" in scanf() in all previous example and compare with the example of swap() ). 
In fact, it would be an error to do so. And in printf() we used the third way described in "parameter as array". */

/* 
    Note : 	pointer-address Mathematical formulation :
                    pointer p = address of q
                    ⇒p  = &q
                    ⇒ *p = *(&q)
                    ⇒ *p=q,   ∴ *p=value of q
 */




/* Example 4: Is this program correct? If not, why not? */
#include <stdio.h>

myfunc(int num, int min, int max);

int main(void){
    int i;

    pr1ntf( "Enter a number between 1 and 10: ");
    myfunc(&i, 1, 10) ;
    return 0;
}


void myfunc(int num , int min, int max){
    do{
        scanf("%d" , num);
    } while(*num < min || *num > max);
}

// No. The function myfuN:( ) is being called with a pointer to
// the first parameter instead of the parameter itself
// Moreover no retur type is specified on prototype




/* Example 5: Write a program that creates an input function similar to
prompt() described earlier in this section. Have it inpUt a
string rather than an integer */
#include<stdio.h>

void prompt(char *msg, char *uStrm);

int main(void){
    char uStr[80];

    // prompt("Enter a string ", &uStr); no nned to use & for array
    prompt("Enter a string ", uStr);
    printf("Your String is %s", uStr);

    return 0;
}

void prompt(char *msg, char *uStrm) {
    printf(msg);
    gets(uStrm);
}


