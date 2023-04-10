5.1 The PROTOTYPE
The general form of a function prototype is shown here:

type function_name(	type parameter_name1,
type parameter_name2,
. . . . .
type parameter_nameN);

A prototype declares three attributes associated with a function:
1.	 Its return type.
2.	The number of   its  parameters.
3.	The type of   its   parameters.

Arguments and parameter of a function: Let average(int a, int b, int c) is a function. In the declaration of this function i.e. declaring its prototype , eg: int average(int a, int b, int c) ; : the variable list with their data types "int a, int b, int c" is the parameter list. Parameter lists is also used in function definition (we discuss function definition later, definition and declaration of a function are not same, but declaration/prototype declaration can be replaced by definition in small program cases).
Arguments of a function are the variable list (or direct data list)  which is used in calling the function . Eg:  average(x, y, z) or average(2, 4, 5) in function arguments no data type declaration is required.

5.1.1 what a prototype does ?
[1]	Prototypes inform the compiler about the return type of a function.  When a function is called, the compiler needs to know the type of data returned by that function so that it can generate the proper code to handle that data.  Because : different data types have different sizes.

( a )	If you use a function that is not prototyped, then the compiler will simply assume that it is returning an integer. 

( b )	However, If it is returning some other type, an error will occur. If the function is in the same file as the rest of your program, then the compiler will catch this error. 

( c )	But if the function is in another file or a library, then the error will go uncaught-and this will lead to trouble when the program is executed.

[2]	Prototypes allow the compiler to find and report illegal type conversions between the type of arguments used to call a function and the type definition of its parameters. It is important to understand, however, that not all kinds of type conversions are illegal in a function call. In fact, C automatically converts most types of arguments into the type of data specified by the parameter. But a few type conversions are inherently wrong. For example, you cannot convert an integer into a pointer. A function prototype allows the compiler to catch and return this type of  conversion error.

[3]	Prototypes also enable the compiler to report when the number of arguments passed to a function is not the same as the number of parameters declared by the function.  In the absence of a function prototype, it is not syntactically wrong to call a function with incompatible arguments or with more or less arguments than the function has parameters. However these are wrong even though the compiler may accept. The use of a function prototype prevents these errors by enabling the compiler to find them.

5.1.2 Problems when prototype is not present/ OLD-Fashioned FORWARD DECLARATION: 
Although the old-style forward declaration is no longer used in new code, you will still find it quite frequently in older programs. In early versions of C, before prototypes were invented, it was still necessary to tell the compiler about the return type of a function. This was done using a forward declaration. A forward declaration is essentially truncated form of a prototype that declares only the return type of a function-not the type and number of its parameters. Compilers still allow this type of declarations. 
The following program demonstrates an old-style forward declaration, It uses it to inform the compiler of volume()'s return type.

#include <stdio.h>
double volume(); 	/* old-style forward declaration for volume() */

int main(void){	double vol;
vol = volume(12.2, 5.67. 9.03) ; printf(“Volume: %f" vol);
return 0;}

/* Compute the volume of a cube. */
double volume(double s1, double s2, double s3) {return s1*s2*s3;}

Since the old-style declaration does not inform the compiler about any of volume( )'s parameters it is not a function prototype. Instead, it simply states vo1tifne( )’§ return type. 

The problem/trouble is that the lack of a full prototype will allow volume( ) to be called using an incorrect type and/or number of arguments For example, the following will not generate a compiler error message even though it is wrong.

volume(120.2, 99.3);		 /* missing last argument */

Since the compiler has not been given information about volume( ) s parameters (no prototype declaration) it won't catch the fact that this call is wrong.
5.1.3 Two Resolved Issues when function prototypes were added to C:
[1]	The first issue was how to handle the old-style forward declaration, which does not use a parameter list. To do so, 

( a )	The ANSI C standard specifies that when a function declaration occurs without a parameter list, nothing whatsoever is being said about the parameters to the function. It might have parameters, it might not. 

( b )	How to prototype a function that takes no arguments? For example, this function simply outputs a line of periods:
void line (){	int i; for(i=0; i<80; i++) printf(".");	}
If you try to use the void line () as a prototype, it won't work because the compiler will think that as a old-style declaration method. 
The solution to this problem is through the use of the void keyword, when a function has no parameters, its prototype uses void inside the parentheses. For example, here is line( )’s proper prototype: void line(void);
This explicitly tells the compiler that the function has no parameters, and any call to that function that has parameters is an error. You must make sure to also use void when the function is defined (definition of function discussed later). For example, line( ) must look like this:
void line (void){	int i; for(i=0; i<80; i++) printf(".");	}

[2]	The second issue related to prototyping is the way it affects C's automatic type promotions. Because when a non-prototyped function is called, all integral promotions take place (for example, characters are converted to integers and all floats are converted to doubles). However, these type promotions seem to violate the purpose of the prototype. The resolution to this problem is that when a prototype exists, the types specified in the prototype are maintained, and no type promotions will occur.

5.1.4 Variable Length Argument in C
Variable length argument is a feature that allows a function to receive any number of arguments. There are situations where we want a function to handle variable number of arguments according to requirement. Variable number of arguments are represented by three dotes ( . . . ). It requires the header file STDARG.H .

Variable length argument lists relates to prototypes. We won't be creating any functions in this book that use a variable number of arguments because they require the use of some advanced techniques. It is sometimes quite useful. For example, both printf( ) and seanf( ) accept a variable number of arguments. To specify a variable number of arguments, use  ...  in the prototype. For example:

int myfunc(int a, ...);

specifies a function that has one integer parameter and a variable number of other parameters.

5.1.5 DEFINITION & DECLARATION of a Function
In C programming there has been a long-standing confusion about the usage of two terms: declaration and definition. A declaration specifies the type of an object. A definition causes storage for an object to be created. As these terms relate to functions, a prototype is a declaration. The function, itself, which contains the body of the function is a definition.

	In C, it is also legal to fully define a function prior to its first use, thus eliminating the need for a separate prototype. That is if a function is defined before it is called, it does  not require a separate prototype. However, this works only in very small programs.
For example :  
include<stdio.h>
void line (void){	int i; for(i=0; i<80; i++) printf(".");	} /*No PROTOTYPE is required*/
int main(void){ line(); return 0;}

That’s why some people define a function before main() to get rid of prototype declaration. Also its easy to renew the old fashion program by simply copying the defined functions and paste them before main().
 
	Remember that if a function does not return a value, then its return type should be specified as void-both in its definition and in its prototype .

5.1.6 why prototypes are important ?
[1]	Function prototypes enable you to write better, more reliable programs because they help ensure that the functions in your programs are being called with correct types and numbers of arguments. 
[2]	Fully prototyped programs are the norm and represent the current state of the art of C programming. Frankly, no professional C programmer today would write programs without them. 
[3]	Also, future versions of the ANSI C standard may mandate function prototypes and c++ requires them now.


Notes
[1]	As you know, the standard library function sqrt( ) returns a  double value. You might be wondering how the compiler knows this. The answer is that sqrt( ) is prototyped in its header file MATH.H. To see the importance of using the header file, try to program consisting sqrt() without its header file. 

[2]	In general, each of C's standard library functions has its prototype specified in a header file. For example, printf() and scanf() have their prototypes in STDIO.H. This is one of the reasons that it is important to include the appropriate header file for each library function you use.

[3]	Some 'character-based'-functions have a return type of int rather than char. For example, the getchar( ) function's return type is int, not char. The reason for this is found in the fact that C very cleanly handles the conversion of characters to integers and integers back to characters. There is no loss of information. For example, the following program is perfectly valid:
#include <stdio.h>
int char_as_int(void);	/*int type return value instead of char type*/
int main (void){ 	char ch;
ch = char_as_int();	printf("%c", ch);
return 0;	}
int char_as_int(void){	return 'a';	}

When char_as_int() returns, it elevates the character 'a' to an integer by adding a high-order byte (or bytes) containing zeros. When this value is assigned to ch in main( ), the high-order byte (or bytes) is removed. One reason to declare functions like char_as_int() as returning an integer instead of a character is to allow various error values to be returned that are intentionally outside the range of a char.

[4]	When a function returns a pointer, both the function and its prototype must declare the same pointer return type. 
#include <stdio.h>
int *in_it(int x); 	/*prototype of pointer returning function */
int count; 		/*count as global variable*/

int main(void){ 	int *p; /*global variable count is int type so p is int type pointer*/
p = in_it(110); 	/* return pointer equal : p=&count*/ 
printf("count (through p) is %d", *p);
return 0;}

int * in_it(int x){	count = x;
return &count; 	/* return a pointer */	}

Prints = count (through p) is 110
the function in_it( ) returns a pointer to the global variable count. Notice the way that the return type for in_it( ) is specified. This same general form is used for any sort of pointer return type. 

[5]	If a function returns a pointer, then it must make sure that the object being pointed to does not go out-of-scope when the function returns. This means that you must not return pointers to local variables.

[6]	The main( ) function does not have (nor does it require) a prototype. This allows you to define main( ) any way that is supported by your compiler. Here we use int main(void) { ... } because it is one of the most common forms. Another frequently used form of main( ) is 
void main(void) { ... }
This form is used when no value is returned by main( ). 

	The reason main( ) does not have a prototype is to allow C to be used in the widest variety of environments. Since the precise conditions present at program start-up and what actions must occur at program termination may differ widely from one operating system to the next, C allows the acceptable forms of main( ) to be determined by the compiler. However, nearly all compilers will accept int main(void) and void main(void) .




#include <stdio.h>

double volume(double s1,double s2, double s3);

int main ()
{
    double vol;
    vol=volume(12.2,5.67,9.03);
    printf("volume %f",vol);
    return 0;
}

double volume(double s1,double s2, double s3)
{
    return s1*s2*s3;
}



#include <stdio.h>

float getnum(void)
{
    float x;
    printf("Enter a number: ");
    scanf("%f",&x);
    return x;
}

int main ()
{
    float i;
    i=getnum();
    printf("%f",i);
    return 0;
}




#include <stdio.h>

int main ()
{
    double answer;
    
    answer=sqrt(16.0);
    
    printf("%f",answer);
    
    return 0;
}



#include<stdio.h>

int get_a_char(void)
{
   return 'a';
}

int main ()
{
    char ch;
    ch=get_a_char();
    printf("%c",ch);
    return 0;
}





#include <stdio.h>
int *init(int x);
int count;

int main ()
{
    int *p;
    p=init(110);
    printf("Count is %d",*p);
    return 0;
}

int *init(int x)
{
    count =x;
    return &count;
}




#include <stdio.h>

double avg();

int main()
{
    float average;
    average=avg();
    printf("%f",average);
    return 0;
}

double avg()
{
    float num,sum=0;
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter number: ");
        scanf("%f",&num);
        sum=sum+num;
    }
    return sum/10;
}




#include <stdio.h>

double avg(void);

int main()
{
    float average;
    average=avg();
    printf("%f",average);
    return 0;
}

double avg(void)
{
    float num,sum=0;
    int i;
    for(i=0;i<10;i++)
    {
        printf("Enter number: ");
        scanf("%f",&num);
        sum=sum+num;
    }
    return sum/10;
}




