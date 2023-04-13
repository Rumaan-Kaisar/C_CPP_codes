
/*
    ----------|    PROTOTYPE    |----------
        The general form of a function prototype:

            type function_name(	type parameter_name1,
                                type parameter_name2,
                                . . . . .
                                type parameter_nameN);


        A prototype declares 'three attributes' associated with a function:
            1.	Its return type.
            2.	The number of   its  parameters.
            3.	The type of   its   parameters. 

        In general, each of C's standard library functions has its prototype specified in a header file.
            For example, printf() and scanf() have their prototypes in <stdio.h>.
            sqrt() is prototyped in its header file <math.h>. 




    ----------|    Arguments and Parameters    |----------
        Let average(int a, int b, int c) is a function. 

        parameters:
            In the declaration of this function i.e. its prototype , eg: 
                int average(int a, int b, int c); 
            the variable list with their data types "int a, int b, int c" is the parameter list. 
            Parameter lists is also used in function definition 
            ('function declaration'/prototype declaration can be replaced by 'definition' in small program cases).

        Arguments:
            Arguments of a function are the variable list (or direct data list)  which is used in calling the function. Eg:  
                average(x, y, z) 
                    or 
                average(2, 4, 5) 
            in function arguments no data type declaration is required.




    ----------|    what a prototype does    |----------
            Prototypes inform the compiler about the return type of a function. Because, different data types have different sizes.
                If a function is not prototyped, the compiler will simply assume that it is returning an "integer". 
                If it is returning some other type, an error will occur. 
                    If the function is in the same file as the rest of your program, then the compiler will catch this error. 
                    But if the function is in another file or a library, then the error will go uncaught and lead to trouble when the program is executed.

            Prototypes allow the compiler to find and report illegal type conversions between 
                the type of arguments used to call a function and the type definition of its parameters.
                For example, you cannot convert an integer into a pointer.

            Prototypes enables the compiler to report when 
                the number of arguments passed to a function is not the same as the number of parameters declared.
            
            


    ----------|    Variable Length Argument    |----------
        Allows a function to receive any number of arguments.
            Variable number of arguments are represented by THREE DOTES "..."
            It requires the header file STDARG.H .

        Following specifies a function that has one integer parameter and a variable number of other parameters.
            int myfunc(int a, ...);

        Both printf() and seanf() accept a variable number of arguments.
*/




/* ----------|    main() does not need prototype    |----------

    The main() function does not have (nor does it require) a prototype. 
        This allows you to define main() any way that is supported by your compiler. 
            we use      int main(void) { ... }      because it is one of the most common forms. 
            Another frequently used form of main( ) is          void main(void) { ... }
                This form is used when no value is returned by main( ). 

        The reason main() does not have a prototype is to allow C to be used in the widest variety of environments.
        However, nearly all compilers will accept int main(void) and void main(void). 
*/



/* 
    ----------|    DEFINITION & DECLARATION of a Function    |----------

    A declaration specifies the type of an object. 
    A definition causes storage for an object to be created.

    A prototype is a declaration. The function, itself, which contains the body of the function is a definition.

    It is legal to fully DEFINE A FUNCTION prior to its first use, thus eliminating the need for a "separate prototype".
        However, this works only in very small programs. For example: 
*/  

#include<stdio.h>
//No PROTOTYPE is required, only DEFINATION
void line (void){	
    int i; 
    
    for(i=0; i<80; i++) printf(".");	
} 

int main(void){ 
    line(); 
    return 0;
}
 
// Remember that if a function does not return a value, then its return type should be specified as void-both in its definition and in its prototype .




/*  
    ----------|    Problems when prototype is not present    |----------
    OLD-Fashioned FORWARD DECLARATION: 
    In early versions of C, before prototypes were invented, it was still necessary to tell the compiler about the return type of a function.
    This was done using a forward declaration. 

    A forward declaration is essentially truncated form of a "prototype" that declares "only the return type" of a function
        not the type and number of its parameters. Compilers still allow this type of declarations. 
    
    when a function declaration occurs without a parameter list. It might have parameters, it might not.

    When a non-prototyped function is called, all integral promotions take place.
        when a "prototype" exists, the types specified in the prototype are maintained, and no type promotions will occur.
*/




/* Example 1: The following program demonstrates an old-style "FORWARD DECLARATION", 
                It uses it to inform the compiler of volume()'s return type.

                Since the old-style declaration does not inform the compiler about any of volume()'s parameters it is "not a function prototype".
                    This will allow volume() to be called using an incorrect type and/or number of arguments.
                        Eg: following will not generate a compiler error message even though it is wrong.
                                volume(120.2, 99.3);		 // missing last argument */
#include <stdio.h>
double volume(); 	/* old-style FORWARD DECLARATION for volume() */

int main(void){	
    double vol;

    vol = volume(12.2, 5.67, 9.03); 
    printf("Volume: %f", vol);

    return 0;
}

/* volume(): Compute the volume of a cube. */
double volume(double s1, double s2, double s3) {
    return s1*s2*s3;
}




/* Example 2: How to prototype a function that takes no arguments? For example, this function simply outputs a line of periods:

                void line(){	
                    int i; 
                    
                    for(i=0; i<80; i++) printf(".");
                }

                If you try to use the void line() as a prototype, 
                    it won't work because the compiler will think that as a old-style declaration method. 
                The solution to this problem is through the use of the "void" keyword, when a function has no parameters.
                        void line(void);
                This explicitly tells the compiler that the function has no parameters, and any call to that function that has parameters is an error.  */

// You must make sure to also use "void" in definition of function.
void line(void){	
    int i; 
    
    for(i=0; i<80; i++) printf(".");
}




/* Example 3: To see how a function prototype can catch an error, try
                compiling this version of the volume program, which includes
                volume()'S full prototype: */
#include <stdio.h>

/* this is volume()'s full prototype */
double volume(double s1, double s2, double s3);

int main(void){
    double vol;

    vol = volume(12.2, 5.67, 9.03, 10.2);   // mismatch number of arguments, returns ERR
    // vol = volume(12.2, 5.67, 9.03);
    printf("volume %f",vol);
    return 0;
}

double volume(double s1,double s2, double s3){
    return s1*s2*s3;
}
/* program will not compile because the compiler knows that 
volume() is declared as having only three parameters */




/* Example 4: Some 'character-based'-functions have a return type of 'int' rather than 'char'. For example, the getchar() function's return type is int, not char. 
                The reason is to cleanly handle the "conversion of characters to integers and integers back to characters". There is no loss of information.
                For example, the following program is perfectly valid: */
#include <stdio.h>

int char_as_int(void);	//  int type return value instead of char type

int main(void){ 	
    char ch;

    ch = char_as_int();	
    printf("%c", ch);

    return 0;	
}

int char_as_int(void){	
    return 'a';	
}

/* When char_as_int() returns, it elevates the character 'a' to an integer by adding a high-order byte (or bytes) containing zeros. 
When this value is assigned to ch in main(), the high-order byte (or bytes) is removed. */

/* One reason to declare functions like char_as_int() as int instead of a char is to 
   allow various error values to be returned that are intentionally outside the range of a char. */




/* Example 5: When a function returns a "pointer", both the 'function' and its 'prototype' must declare the same pointer return type.  */
#include <stdio.h>

int *in_it(int x);      // prototype of pointer returning function

int count; 		// count as global variable

int main(void){ 	
    int *p;     // global variable 'count' is int type so p is int type pointer

    p = in_it(110); 	// return pointer equal : p=&count 
    printf("count (through p) is %d", *p);

    return 0;
}

int *in_it(int x){	
    count = x;
    return &count; 	// return a pointer
}

/* 
Notes: 
    Prints = count (through p) is 110
        the function in_it() returns a pointer to the global variable count. 
        Notice the way that the return type for in_it() is specified. This same general form is used for any sort of pointer return type. 

    GLOBAL var!! Why? 
        If a function returns a pointer, then it must make sure that the object being pointed to "does not go out-of-scope" when the function returns. 
        This means that you must not return pointers to 'LOCAL variables'.
*/




/* Example 6: As explained, if a function is defined before it is called. it does
not require a separate prototype. for example. the following
program is perfectly valid.
Do not use this kind of declaration, because 
Large programs are typically spread across several files. Since you can't define a
function more than once, prototypes are the only way to inform all files about a function.  */

#include <stdio.h>

/* define getnum() prior to its first use */

float getnum(void){
    float x;

    printf("Enter a number: ");
    scanf("%f",&x);
    return x;
}

int main(void){
    float i;

    i = getnum();
    printf("%f",i);
    return 0;
}




/* Example 7: Std library function sqrt()) returns a double value. it doesnot work without <math.h>, since it prptptyped in this header file.
this program wont work. */

#include <stdio.h>
// #include <math.h>

int main(void){
    double answer;
    
    answer = sqrt(16.0);
    printf("%f",answer);
    
    return 0;
}




/* Example 8: Write a program that creates a function, called avg(), that
reads ten floating-point numbers entered by the user and
returns their average. Use an old-style forward reference and not a function prototype */
#include <stdio.h>

double avg();

int main(void){
    printf("%f", avg());

    return 0;
}

double avg(){
    double num, sum = 0.0;
    int i;

    for(i=0; i<10; i++){
        printf("Enter number: ");
        scanf("%lf", &num);
        sum = sum + num;
    }
    return sum/10.0;
}




/* Example 9: Rewrite the program from Exercise 1 so that it uses a function prototype. */
#include <stdio.h>

double avg(void);

int main(void){
    printf("%f", avg());
    return 0;
}

double avg(void){
    double num, sum;
    int i;

    sum = 0.0;
    for(i=0; i<10; i++){
        printf("Enter number: ");
        scanf("%lf", &num);
        sum = sum + num;
    }
    return sum/10.0;
}




/* Example 10: Is the following program correct? If not, why not? If it is, can it
be made better? */
// No proper function prototyping
// the program would be better if a full function prototype were used when declaring myfunc( )
#include <stdio.h>

double myfunc();
// double myfunc(double num);

int main(void){
    printf("%f", myfunc(10.2));
    return 0;
}

double myfunc(double num){
    return num / 2.0;
}




/* Example 11: Show the prototype for a function called Purge() that has no parameters and returns a pointer to a double. */
doule *Purge(void);

