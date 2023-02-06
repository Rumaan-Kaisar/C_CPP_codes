

// include header files here 
// function prototypes here 
int main(void){
    /*  ...  */
}

ret-type f1(param-lisf){
    /* '...  */
}

ret-type f2(param-lisf)(
    /*  ...  */
)

ret-type fN(param-lisf){
    /*  ...  */
}
/*
function prototype: 
    A function prototype consists of a function's name, its return type, and its parameter list.

    void myfunc(void){
        printf("This is a test.");
    }

    Its prototype is
        void myfunc(void);

 */

/* 
functions prototyope declares the function
after that we define the function anywhere in the code 
*/

/* ----------- Program with tow functions ----------- */
#include <stdio.h>

void func1(void);
int main(void){
    printf("I ");
    func1(); /*Calling the function*/
    printf("C");
    return 0;
}

void func1(void){
    printf("Love ");
}



/* ----------- Program with three functions ----------- */
#include <stdio.h>

void func1(void); /* Function Prototypes declarations */
void func2(void);

int main(void){
    /*Calling the function*/
    func2();
    printf(" 3 ");
    return 0;
}

/*function calls another function*/
void func2(void){
    func1();
    printf(" 2 ");
}

void func1(void){
    printf(" 1 ");
}


