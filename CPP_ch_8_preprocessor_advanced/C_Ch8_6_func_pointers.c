
/*
    --------------    Function Pointers    --------------
    A FUNCTION POINTER is a 'variable' that contains the 'address of the entry point' to a function.


    how "Function Pointers" works: 

        COMPILER creates an 'entry point' for each function in the program during COMPILATION 
            The "ENTRY POINT" is the ADDRESS to which 'execution transfers' when a function is called. 
            Since the ENTRY POINT has an ADDRESS, it is possible to have a pointer variable point to it. 
        
        Once you have a "POINTER TO A FUNCTION", it is possible to actually CALL that FUNCTION using the POINTER. 


    To create a variable that can point to a function, 
        declare the pointer as having the 'same type' as the 'return type of the function', followed by any parameters. 

            For example, the following declares 'p' as a pointer to a function that 'returns an integer' and has two integer PARAMETERS, x and y;

                int (*p) (int x, int y);

    NOTE:
        The PARENTHESES surrounding *p are NECESSARY because of C's precedence rules. 




    ASSIGN the ADDRESS of a function to a function pointer:
        Simply use its 'NAME without any parentheses'.  For example, assuming that sum() has the prototype

                int sum(int a, int b);

        the following assignment statement is correct:

                p = sum;

            Once this has been done, you can call sum() 'indirectly through p' using a statement like:

                result = (*p) (10, 20);

            Again because of C's precedence rules the Parentheses are necessary around p.


        Actually, you can also just use p directly, like this:

                result = p(10, 20);
            
        NOTE:
            (*p) form inform anyone that reading your codes that a function pointer is being used 
                to call a function indirectly, instead of calling a function named p. 
*/


ofthei( value. Like the program in Example 1, this program
prompts the user for two numbers. Next, it asks the user to
enter the number of the operation to perform. This numbet is
then used to index the function-pointer array to execute the
proper funCtion. Finally, the result is displayed.
'include <stdio.h>
int sum(int a, int b) ;
int subtract (int a, int b) ;
int mul (int a, int b) ;
int div(int a, int b) ;
int (*p[4}) (int x. int y);
int main (void)
(
int result:
int i, j. op;
p [0 J = sum: f' get address of sum()
p [1 J = subtract; f' get address of
p [2 J = mul, f' get address of mul I)
p [3 J = div; f' Qet address of
printf{DEnter two numbers: ");
scanfl"%d%d" , &i, &j);
divl)
'f
subtract (I 'f
'f
'f
printf("O: Add, 1: Subtract, 2: Multiply, 3: Oivide\n-);
do I
)
printf(nEnter number of operation: .);
scanf(·'d-, &op);
) whilelop<O II op>3);
result = I'p[op») Ii, i);
printf(-'d-, result);
return 0;
int sum(int a, int b)
(
return a+b;
)
int subtract(int a, int bl

{
return a-b;
}
int mul{int a,
{
return a*bi
}
int div(int a,
(
if(b) return
else return
)
int b)
lnt b)
a l b:
0:
TIIlC~AllDSOME-Mc:m-
126 UNOERSTNoIO RJNCTION POIN1fIIS
When you study this code, it becomes clear that using a
function-pointer array to call the appropriate function is more
efficient than using a switch( ) statement.
Before leaving this example, we can use it to illustrate
one more point: function-pointer arrays can be initialized, just
like any other array. The following version of the program
shows this.
'include <stdio .h>
int sum (int a, int b) :
int subtract (int a , int b) :
int mul (int a, int b) :
int div(int a, int b) :
/ * initialize the pointer array */
int ('p[4]) (int x, int y) = ( .
sum, subtract. mul , div
) :
int main (void)
(
int result;
int i. j, op;
printf(-Enter two numbers: .);
scanf(-'d%d·, &i. &j);
printf("O: Add, 1: Subtract, 2: Multiply, 3: Divide\n"),
do (
printf(-Enter number of operation: .);

scanf("%d", &Op);
) while(op<O I I op>3 ) ;
resul t = ('p [op)) (i. j);
printf("%d~, result);
return 0;
int sum(int a, int b)
(
return a+b;
)
i nt subtract(int a, int b)
(
return a-b;
)
int mul(inL a, int b)
(
. return a·bi
)
int div(int a, int b)
(
)
iftb) return a l b:
else return 0;
3. One of the most common uses of a function pointer occurs
when utilizing another of C's standard library functions, qsort{ ).
The q80rt( ) function is a generic sort routine that can sort any
type of singly dimensioned array, using the Quicksort algorithm.
Its prototype is
void qsort(void 'array, size_t number, size_t size,
int (,comp)(const void '8. const void 'b));
Here, array is a pointeno the first element in the array to be
sorted. The number of elements in the array is specified by
number, and the size of each element of the array is specified by

size. (Remember, size_t is defined by the C compiler and is
loosely the same as unsigned.) The final parameter is a pointer
to a function (which you create) that compares twO elements of
the array and returns the following results:
·a <·b
·a ==·b
·a >·b
returns a negative value
returns a zero
returns a positive value
The qsort( ) function has no return value. It uses the STDLlB.H
header file.
The following program loads a JDO-element integer·array
with random numbers, sorts it, and displays the sorted form.
Notice the necessary type casts within the comp( ) function.
#include <stdio.h>
;include <stdlib.h>
int comp(const void *i, const void *j);
int main(void)
(
int sort[lOO], i;
fOl"(j:=O; i<100; i+ .... )
sort[ij := randr);
qsort(sort, 100, sizeof(int), comp):
)
for (i=l); i<100; i++)
printf{'"%d\n",sort[i]};
return 0;
int comp(const void
(
canst void *j)
return *(int*)i - *iint*)j;
)

1. Compile and run all of the example programs. Experiment with
them, making 1111nor changes.
2. Another of C's standard library functions is called bsearch ( ) .
This functlon searches a sorted a rray, gIven d key. It returns a
pointer to the first entry in the array thot matches the key If no
match is found, a null pointer is returned. Its prowtype is
void 'bsearch(consl VOid ' key, const void ' array, slze_t number. size_t Size,
Inl (, comp)(const void ' a, const void ' b));
All the pa rameters to b search( ) arc the same as for qsort( )
except the first. \\'hieh is a pOInter to kelj, the object bc:ing
,,,ught. The comp( ) fun, tlon operates the same for bscarch( )
", it does for qsort( ) .
.\lnd;fy the prugraln In L...dlr'pl~ 3 so that anf"r the iiff<-ly is
sOIlPd the tl~er IS prompted to cntpr a number :\'C\t. using
hscarch( ). search the s()rH~d arr.JY and repan ji a nla~ch is
found
3. Add a function call~d modulus( ) to the tinal verSion of the
.nithmctic progranl In Example 2. Ha\'e the functIOn return the
result of a % h . Ada tll1S optIOn to the menu dnd fully integrate
it lnW the progcam.

