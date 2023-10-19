
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



/* Example 1: This program fills in the details and demonstrates the function pointer. 
                The program calls sum() indirectly using "p", and displays the result.
*/
#include <stdio.h>

int sum(int a, int b);

int main(void) {
    int (*p) (int x, int y);    // function pointer
    int result;

    p = sum; // get address of sun()
    result = (*p) (10, 20);

    printf("%d", result);

    return 0;
}

int sum(int a, int b){
    return a+b;
}




/* --------------    function pointer array    -------------- */

/* Example 2: The following program will give you a taste of full power of "function pointer"
                One important uses of function pointers occurs when a "FUNCTION-POINTER ARRAY" is created.
                    Each element in the array can point to a different function.
                    To call any specific function, the array is simply indexed.

                'Function-pointer arrays' are typically used when writing systems software, such as
                        a.  compilers,
                        b.  assemblers, and
                        c.  interpreters.

                Like the program in Example 1, this program prompts the user for two numbers.
                    Next, it asks the user to enter the 'number of the operation to perform'.
                    This number is then used to index the function-pointer array to execute the proper function.
                    Finally, the result is displayed.
*/

#include <stdio.h>

int sum(int a, int b);
int subtract(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int (*p[4]) (int x, int y);     // function-pointer array

int main (void) {
    int result;
    int i, j, op;

    p[0] = sum;        // get address of sum()
    p[1] = subtract;   // get address of subtract()
    p[2] = mul;        // get address of mul()
    p[3] = div;        // get address of div()

    printf("Enter two numbers: ");
    scanf("%d%d", &i, &j);

    printf("O: Add, 1: Subtract, 2: Multiply, 3: Oivide\n");

    do {
        printf("Enter number of operation: ");
        scanf("%d", &op);
    } while(op<0 || op>3);

    result = (*p[op]) (i, j);
    printf("%d", result);

    return 0;
}


int sum(int a, int b) {
    return a+b;
}

int subtract(int a, int b) {
    return a-b;
}

int mul(int a, int b) {
    return a*b;
}

int div(int a, int b) {
    if(b) return a/b;
    else return 0;
}





// #####    rev    #######


#include <stdio.h>
intL sum(int a, jot b);
IntL subt.ract(jnt a, mt b);
mt mul(int a, intL b);
irit div(intL a, jot b);
lot (*p[41) (lot x, intL y)
intL main (void)
mt result;
mt i, j, op;
P(01 = sum; /* get address of sum]) */
P(11 = subtract; /* get address of subtract() *1
p121 = mul; /* get address of mul() 1
p [31 = div; I get address of div() *1
printf('Enter two numbers:
scanf(%d%d', &i, &j);
printf("O: Add, 1: Subtract, 2; Multiply, 3; Divide\n);
do
printf(Enter number of operation:
scanf('%d, &op);
while(op<0 H op>3);
result = (*p[op)) (1, j);
printf('%d", result);
return 0;
lot sum(int & intb)
return a+b;
mt subtract(int a, mt b)


return a-b;
mt mul(int a, mt b)
return a*b;
mt div(int a, mt b)
if(b) return a/b;
else return 0;
When you study this code, it becomes clear that using a
function-pointer array to call the appropriate function is more
efficient than using a switch( ) statement.
Before leaving this example, we can use it to illustrate
one more point: function-pointer arrays can be initialized, just
like any other array. The following version of the program
shows this. -
*include <stdio.}i>
mt sum(int a, mt b);
mt subtract(int a, mt b);
jot mul(int a, jot b);
jot div(int a, jot b);
1* initialize the pointer array *1
mt (*p(4)) (mt x, jilt y ) = C
sum, subtract, mul, div
mt main (void)
jot result;
mt 1, j, op;
printf(Enter two numbers: );
scanf(%d%d', &i, &j);
printf(0: Add, 1: Subtract, 2: Multiply, 3: Divide\n);
do
printf("Enter number of operation: );


scanf("%d, &op);
while(op<O 11 op>3)
result = (*p[op]) (i,
printf("%d, result);
return 0;
mt sum(int a, intb)
return a+b;
mt subtract(int a, mt b)
return a-b;
mt mul(int a, mt b) -
return a*b;
mt div(int a, mt b)
if(b) return a/b;
else return 0;
3. One of the most common uses of a function pointer occurs
when utilizing another of C's standard library functions, qsort().
The qsort() function is a generic sort routine that can sort any
type of singly dimensioned array, using the Quicksort algorithm.
Its prototype is
void qsort(void *array, sizej number, size_t size,
mt ('compconst void a, const void Sb));
Here, array is a pointer to the first element in the array to be
sorted. The number of elements in the array is specified by
number, and the size of each element of the array is specified by


size. (Remember, size _t is defined by the C compiler and is
loosely the same as unsigned.) The final parameter is a pointer
to a function (which you create) that compares two elements of
the array and returns the following results:
a < b returns a negative value
== *b returns a zero
*a > 'b returns a sitive value
The qsort() function has no return value. It uses the STDLII3.1I
header file.
The following program loads a 100-element integer array
with random numbers, sorts it, and displays the sorted form.
Notice the necessary type casts within the comp( ) function,
#include <stdio.h>
#include <stdlib.h>
irit comp(const void i, const void j);
mt main(void)
inC sort(1001, i;
for(i=O; 1<100; 14+)
sortEil = rand));
qsort(sort 100, sizeof(irit), comp);
for(i=0; 1<100; 1+4)
printf("%d\n sort[il);
return 0;
mt comp(const void i, corist void *j)
return *(int)i - *(int*)j;

1. Compile and run all of the example programs. Experiment with
them, making minor changes.
2 Another of Cs standard library functions is called bscarch( ).
This function searches a sorted arra y, given a key. It returns a
pointer to the f irst entry in the array that matches the ke y . if no
match is found, a null pointer is returned. its prototype is
void bsearch(const void key, const void array, size_t number, size_t size,
nt comp)(const void 'a, const void 'b));
All the parameters to bsearcb( ) are the same as for qsort( )
except the first, which is a pointer to key, the object being
sought. The comp( ) function operates the same for bscarch( )
as it does t'r cjsort( ).
Modify :he program in Example 3 so that after the a , : iv is
sorted, the riser is prompted to enter a number. Next, USili
bsearch ( ) search the sorted array and report if a match is
Ibund.
3. Add a fume ion called modulus( ) to the final version ofthe
arithrneth. arograrn in Example 2. Have the function return the
result of a b. Add this option to the menu and full y integrate
it into the program.















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

