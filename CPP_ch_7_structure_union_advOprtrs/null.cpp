
/* 
    ------------    Precedence of all C - OPERATORS    ------------

    Table shows the precedence of all the C Operators.

        Precedence	Operators
        Highest	
                    ( )  [ ]   ->  .
                    !  ~  +  -  ++  --  (type cast) *  &  sizeof 
                    *   /  % 
                    +   -
                    <<  >>
                    <  <=  >  >=
                    ==   !=
                    &
                    ^
                    |
                    &&
                    ||
                    ? :
                    =  +=  -+  *=  /= etc
                    ,
        Lowest	

*/



// ---------    MASTERY    ---------
// register
/* Example 1: What does the register specifier do? 
                The register specifier causes the C compiler to provide 
                the fastest access possible for the variable it precedes.
*/



/* Example 2: What do the 'const' and 'volatile' modifiers do? 
                'const' tells the compiler that no statement of the program can modify the variable
                    Also, a 'conat pointer' parameter may not be used to modify the object pointed to by the pointer.

                'volatile' tells the compiler that any variable it precedes may have its value changed 
                    in ways not explicitly specified by the program.
*/





/* Example 3: Write a program that sums the numbers 1 to J00. 
                Make the program execute as fast as possible (use register). */
#include <stdio.h>

int main(void){
    register int i, sum;

    sum = 0;
    for(i=1; i<101; i++) sum += i;
    printf ("%d", sum) ;

    return 0;
}





// typedef
/* Example 4: Is this statement valid? If so, what does it do? */

typedef long double bigfloat;

// Yes, the statement is valid. It creates another name for the type long double.



// shift opr & bitws
/* Example 5: Write a program that inputs two characters and compares corresponding 'bits'.
                Have the program display the 'number of each bit' in which a match occurs.
                    For example, if the two integers are
                            1001 0110
                            1110 1010
                the program will report that bits 7, 1, and 0 match. From Right to left index
                (Use the bitwise operators to solve this problem.)
*/

#include <stdio.h>
#include <conio.h>

int main(void) {
    char ch1, ch2;
    char mask, i;

    printf("Enter two characters: ");
    ch1 = getche();
    ch2 = getche();
    printf("\n");

    mask = 1;
    for(i=0; i<8; i++) {
        // find matching 1 in bits
        // notice the use of 'Logical-and' & 'bitwise-and'
        if((mask & ch1) && (mask & ch2)) printf("bits %d has the same 1's \n", i);
        // to find all matching 0's and 1's use following with '==' instead
        if((mask & ch1) == (mask & ch2)) printf("bits %d the same\n", i);
        mask <<= 1; // making left-shift
        printf("\n");
    }

    return 0;
}







// ---------    CUMULATIVE (rev-below)    ---------

/* Example 1: Write a program that swaps the 'low-order four bits of a byte' with the 'high-order four bits'.
                Demonstrate that your routine works by displaying the contents of the byte before and after,
                    using the show_binary() function developed earlier.
                (Change show_hinary() so that it works on an eight-bit quantity, however.) */

#include <stdio.h>

void show_binary(unsigned u);

int main(void){
    unsigned char ch, t1, t2;

    ch = 100;
    printf("%d\n", ch);
    show_binary(ch);

    t1 = ch;
    t2 = ch;

    t1 <<= 4;   // left shifing 4 bits
    t2 >>= 4;   // right shifing 4 bits

    ch = t1 | t2;   // unify sifted bits to make the 'swapped bits'

    show_binary(ch);
    printf("%d", ch);

    return 0;
}


void show_binary (unsigned u){
    unsigned n;

    for(n=128; n>0; n /= 2) {
        if(u & n) printf("l ");     // applying bitwise &
        else printf("0 ");
    }
    printf("\n");
}




/* Example 2: Earlier we wrote a program that encoded files using the 1's complement operator.
                Write a program that reads a text file encoded using this method
                    and displays its decoded contents.
                Leave the actual file encoded, however. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *in;
    unsigned char ch;

    if(argc!=2) {
        printf("Usage: code <in>\n");
        exit(1);
    }

    if((in = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open input file.\n");
        exit(1);
    }


    while (!feof(in)) {
        ch = fgetc(in);
        if(!feof(in)) putchar(~ch);
    }

    fclose(in);

    return 0;
}

// adv_cumul_4_1sc neg_encoded





/* Example 4: Optimize the telephorle-directory program we wrote earlier using STRUCTURE
                by selecting appropriate 'local variables' to become "register types". */

/* Improve the telephorle-directory program we wrote earlier in this chapter so that it includes each person's "mailing address".
                Store the address in its own structure, called 'address', which is nested inside the directory structure.


                we wrote a program that created a telephone directory that was stored on disk.
				    It uses an array of structures, each containing

							a person's name,
							area code, and
							telephone number.

					Store the area code as an integer.
					Store the name and telephone number as strings.
				Make the array MAX elements long, where MAX is any convenient value that you choose.


                Have the program present a menu that looks like this:

                        1. Enter the names and numbers
                        2. Find numbers
                        3. Save directory to disk
                        4. Load directory from disk
                        5. Quit

                The program should be capable of storing 100 names and numbers. (Use only first names if you like.)
                Use fprintf() to save the directory to disk and fscanf() to read it back into memory. */

// A simple computerized telephone book.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct address {
    char street[40];
    char city[40];
    char state[3];
    char zip[12];
};

struct phone_type{
	char name[40];
	int areacode;
	char number[9];
    struct address addr;
};

struct phone_type phone[MAX];   // creating array of "phone_type structure"

int loc = 0;

int menu(void);
void enter(void);
void load(void);
void save(void);
void find(void);

int main(void){
    register int choice;    // 'register' update

    do{
        choice = menu();
        switch(choice){
            case 1: enter();
                break;
            case 2: find();
                break;
            case 3: save();
                break;
            case 4: load();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice
int menu(void){
    register int i;     // 'register' update
    char str[80];

    printf("1. Enter names and numbers\n");
    printf("2. Find numbers\n");
    printf("3. Save directory to disk\n");
    printf("4. Load directory from disk\n");
    printf("5. Quit\n");

    do{
        printf("Enter your choice\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


void enter(void){
    char temp[80];

    for( ; loc<10; loc++){
        if(loc<10){
            printf("Enter name:\n");
            gets(phone[loc].name);
            if(!*phone[loc].name) break;

            printf("Enter area code:\n");
	        gets(temp);
	        phone[loc].areacode = atoi(temp);

	        printf("Enter number:\n");
            gets(phone[loc].number);

            // input address info
            printf("Enter street address: ");
            gets(phone[loc].addr.street);

            printf("Enter city: ");
            gets(phone[loc].addr.city);

            printf("Enter State: ");
            gets(phone[loc].addr.state);

            printf("Enter zip code: ");
            gets(phone[loc].addr.zip);
        }
    }
}


void find(void){
    char name[80];
    register int i;     // 'register' update

    printf("Enter name: ");
    gets(name);

	if(!*name) return;

    for(i=0; i<10; i++){
        if(!strcmp(name, phone[i].name)){
            printf("%s (%d) %s\n", phone[i].name, phone[i].areacode, phone[i].number);
            printf("%s\n%s %s %s\n", phone[i].addr.street, phone[i].addr.city, phone[i].addr.state, phone [i].addr.zip);
        }
    }
}


void load(void){
    FILE *fp;

    if((fp = fopen("phone","rb"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    loc = 0;
    // loading the array of structure
    // notice the use of '&' to read array
    while(!feof(fp)){
        fread(&phone[loc], sizeof phone[loc], 1, fp);
        // ----------    old code    -----------
        // fscanf(fp,"%s%d%s", phone[loc].name, &phone[loc].areacode, phone[loc].number);
        // printf("%s%d%s \n", phone[loc].name, &phone[loc].areacode, phone[loc].number);
        loc++;
    }
    fclose(fp);
}


void save(void){
    FILE *fp;
    register int i;     // 'register' update

    if((fp = fopen("phone","wb"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    for(i=0; i<loc; i++){
        fwrite(&phone[i], sizeof phone[i], 1, fp);  // write the array of structure
        // ----------    old code    -----------
        // notice the " " spaces after the specifiers, during write
        // fprintf(fp,"%s %d %s ", phone[i].name, phone[i].areacode, phone[i].number);
        // save in following format:
        // a 123 01901 b 234 01802 c 345 01703
    }

    fclose(fp);
}





// shift opr
/* Example 6: What do the << and >> operators do?
                The <<  and >> are the left and right shift operators, respectively. 
                They shift the bits. */



/* Example 7: Show how this statement can be rewritten:
                    c = c+ 10; 
*/
c += 10;


// ? opr
/* Example 8: Rewrite this statement using the ? operator. 
                    if(!done) count = 100;
                    else count = 0;
*/

count = done ? 0 : 100;

// value = condition ? true : false;



// enum
/* Example 9: What is an ENUMERATION? Show an example that enumerates the planets. 
                An enumeration is a list of named integer constants. 
                Here is one that enumerates the planets.
*/

enum planets {
    Mercury, Venus, Earth, Mars, Jupiter, Saturn, Neptune, Uranus, Pluto
};



// ---------    CUMULATIVE (rev-below)    ---------
This section checks how well you have integrated the material in
this chapter with that from earlier chapters.




Example 1: Write a program that swaps the low-order four bits of a byte
with the high-order four bits. Demonstrate that your routine
works by displaying the contents of the byte before and after,
using the show_binary( ) function developed earlier.
(Change show_hinary( ) so that it works on an eight-bit
quantity, however.)
'include <stdio.h>
void show_binary(unsigned u}:
int main (void)
(
}
unsigned char ch, t1, t2;
ch = 100;
show_binary (ch) ;
t1 = chi
t2 = ch i
tl «= 4:
t2 »= 4;
ch = t1 I t2;
show_binary(ch);
return 0;
void show_binar-y(unsigned u)
{
unsigned n;
for {n=128; n>O: n=n / 2}
if(u & n l printf("l '1;
else printf("O ");
printf("\n)
}



Example 2: Earlier you wrote a program that encoded files using the 1's
complement operator. Write a program that reads a text file
encoded using this method and displays its decoded contents.
Leave the. actual file encoded, however.
#include <stdio.h>
'include <8tdlib.h>
int main(int argc, char +argv£)
{
)
FILE -in;
unsigned char ch;
if (argc! =2) (
)
printf(~Usage: code <in>\n-);
exit(l);
if«in = fopen(argv[lJ. "rb"»==NULL) (
printf(-Cannot open input file.\n·);
exit(l);
)
while ( ! feof (in» (
ch = fgetc(in);
if! !feof(in» putchar(-ch) ;
}
fclose (in) ;
return 0:
}




Example 3: Is this fragment correct?
register FILE *fPi
Yes, any type .ofvariable can be specified using register.
However, on some types, it may have no effect.




Example 4: Using the program you developed for Chapter 10, Section 10.3,
ElIerCise 1, optimize the program by selecting appropriate local
variables to become register types.
/ * A simple computerized telephone book. */
'include <stdio.h>
'include <string.h>
'include <stdlib.h>
'define MAX 100
atruct address {
char street[40];
char city[40];
char state [3) ;
char zip[12],
) ,
struct phone_type {
char name [40] ,
int areacode;
char number [9] ,
struct address1addri
) phone [MAX] ,
int lac =0;
int menu (void) ;
void enter(void);
void load (void) ;
·void save (void) ;
void find(void);
int main (void)
{
)
register int choice;
do (
choice ;:: menu () ;
switch(choice) (
case 1: enter{);
break;
)
case 2: find ( ) ;
break;
case 3: savel);
break;
case 4: load () ;
} while(choice!=5);
return 0;
j* Get menu choice. */
menu (void)
{
register int i;
char str[eD],
printf(-l. Enter names and number s \n-);
printf("2. Find numbers\n-);
printf("3. Save directory to disk\n.):
printf(·4. Load directory from dis k\ n.);
printf("S. Quit\n" ) ;
do (
printf(-Enter your choice: .);
gets (str);
i = atoi (str);
printf (" \n") ;
) while(i<l II i>5);
return i;
void enter(void)
(
)
char temp [SO);
for (; loc<100: loc++) {
)
if (loc<100) (
printf (" Enter name: .);
gets(phonelloc] .name);
if(!*phoneIloc] . name) break;
printf {PEnter a=ea code: .);
gets (temp) ;
phone; loc 1 . areacode = atoi (tem:;-.) ;
printi("Enter number: .):
gets (phone[lcc] .number);
/ * input address ~nfc ' /
printf(-Enter street adciress: .);
gets {phonelloc ] . addr.str~ et ) ;
print! ( "Enter city: .);
gets (phone[locJ . ad~.city);
printfC'Enter State: .);
gets (phone[loc] .addr.state);
printf{-Enter zip code: - ) ;
gets{phone[locJ .addr.zip);
void find (void)
[)
char name(80):
register lnt i;
printf(·Enter name: .);
gets (name) ;
if(!*name) return;
.for(i=O; i<100; i++)
if(!strcmp(name, phone[i}.name» {
ANSWERS
CUMULATNE SKILLS CHECK
print£("%s (%d) %s\n", phone[i] . name ,
)
phoneli] .areacode. phoneli} .number);
printf(-%s\n%s %s %5\n", phone{i].addr.street,
phone[i] .addr.city. phone{i] .addr.state,
phone(i}.addr.zip) ;
'void load(void)
(
)
FILE ·fpi
i£«fp = fopen("phone", "rb"»==NULL) (
printf("Cannot open fi1e.\n"):
exit(1):
)
loe = 0;
while ('! feo£ (fp» {
fread(&phone[loc], sizeof phone [loc], 1, £p};
loc++:
)
fclose'(fp) ;
void save(voidl
(
FILE *£p;
register int i;
if«£p = fopen("phone", "wb"»==NULL) (
printf("Cannot open £i1e.\n");
exit (.!) ;
)
for(i=O; i<loc; i++) {
619
~620 TEACH YOURSW'
• C
fwritel&phone!iJ. sizeof phone!iJ. 1. fp);
J
fclose Ifp) ;
J


/* Example 3: Improve the telephorle-directory program we wrote earlier in this chapter so that it includes each person's "mailing address".
                Store the address in its own structure, called 'address', which is nested inside the directory structure.


                we wrote a program that created a telephone directory that was stored on disk.
				    It uses an array of structures, each containing

							a person's name,
							area code, and
							telephone number.

					Store the area code as an integer.
					Store the name and telephone number as strings.
				Make the array MAX elements long, where MAX is any convenient value that you choose.


                Have the program present a menu that looks like this:

                        1. Enter the names and numbers
                        2. Find numbers
                        3. Save directory to disk
                        4. Load directory from disk
                        5. Quit

                The program should be capable of storing 100 names and numbers. (Use only first names if you like.)
                Use fprintf() to save the directory to disk and fscanf() to read it back into memory. */

// A simple computerized telephone book.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

struct address {
    char street[40];
    char city[40];
    char state[3];
    char zip[12];
};

struct phone_type{
	char name[40];
	int areacode;
	char number[9];
    struct address addr;
};

struct phone_type phone[MAX];   // creating array of "phone_type structure"

int loc = 0;

int menu(void);
void enter(void);
void load(void);
void save(void);
void find(void);

int main(void){
    int choice;

    do{
        choice = menu();
        switch(choice){
            case 1: enter();
                break;
            case 2: find();
                break;
            case 3: save();
                break;
            case 4: load();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice
int menu(void){
    int i;
    char str[80];

    printf("1. Enter names and numbers\n");
    printf("2. Find numbers\n");
    printf("3. Save directory to disk\n");
    printf("4. Load directory from disk\n");
    printf("5. Quit\n");

    do{
        printf("Enter your choice\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


void enter(void){
    char temp[80];

    for( ; loc<10; loc++){
        if(loc<10){
            printf("Enter name:\n");
            gets(phone[loc].name);
            if(!*phone[loc].name) break;

            printf("Enter area code:\n");
	        gets(temp);
	        phone[loc].areacode = atoi(temp);

	        printf("Enter number:\n");
            gets(phone[loc].number);

            // input address info
            printf("Enter street address: ");
            gets(phone[loc].addr.street);

            printf("Enter city: ");
            gets(phone[loc].addr.city);

            printf("Enter State: ");
            gets(phone[loc].addr.state);

            printf("Enter zip code: ");
            gets(phone[loc].addr.zip);
        }
    }
}


void find(void){
    char name[80];
    int i;

    printf("Enter name: ");
    gets(name);

	if(!*name) return;

    for(i=0; i<10; i++){
        if(!strcmp(name, phone[i].name)){
            printf("%s (%d) %s\n", phone[i].name, phone[i].areacode, phone[i].number);
            printf("%s\n%s %s %s\n", phone[i].addr.street, phone[i].addr.city, phone[i].addr.state, phone [i].addr.zip);
        }
    }
}


void load(void){
    FILE *fp;

    if((fp = fopen("phone","rb"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    loc = 0;
    // loading the array of structure
    // notice the use of '&' to read array
    while(!feof(fp)){
        fread(&phone[loc], sizeof phone[loc], 1, fp);
        // ----------    old code    -----------
        // fscanf(fp,"%s%d%s", phone[loc].name, &phone[loc].areacode, phone[loc].number);
        // printf("%s%d%s \n", phone[loc].name, &phone[loc].areacode, phone[loc].number);
        loc++;
    }
    fclose(fp);
}


void save(void){
    FILE *fp;
    int i;

    if((fp = fopen("phone","wb"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    for(i=0; i<loc; i++){
        fwrite(&phone[i], sizeof phone[i], 1, fp);  // write the array of structure
        // ----------    old code    -----------
        // notice the " " spaces after the specifiers, during write
        // fprintf(fp,"%s %d %s ", phone[i].name, phone[i].areacode, phone[i].number);
        // save in following format:
        // a 123 01901 b 234 01802 c 345 01703
    }

    fclose(fp);
}




// ---------    REVIEW    ---------
Before proceeding you should be able to answer these questions and
perform these exercises:




Example 1: What is the major advantage gained when a variable is declared
using register?
Modifying a variable with register causes the compiler to store
the.variable in such a way that access to it is as fast as poSSIble.
For integer and character types. this typically means.storing it
in a register of the CPU.



Example 2: What is wrong with this function?
void myfunc(const int *i)
{
*i = *i / 2;
)
Because i is declared as const the function cannot modify any
object pointed to by it



Example 3: What is the outcome of these operations?
a. 11011101 & 1110 0110
b. 1101110111110 OllD
c. 11011101" 1110 0110
a. 11000100
b.11111111
c. 0011 1011



Example 4: Write a program that uses the left and right shift operators to
double and halve a number entered by the user.
#include <stdio.h>
int main(void)
(
)
int i;
printf("Enter a number: .);
scanf ("'d", &i);
printf(·Doubled: %d\n·, i « 1):
printf(-Halved: %d\n-, i » 1);
return 0;



Example 5: How can these statements be written differently?
a = 1;
b = 1·,
c = 1;
if(a<b) max; 100;
else max = 0;
i = i * 2;

a = b = c = 1;
max = a<b ? 100 0;
i *= 2:




Example 6: What is the extern type specifier for?
The extern modifier is principally used to inform the compiler'
about global variables defined in a different file. Placing extern
in front of a variable's declaration tells the compiler that the
variable is defined elsewhere, but allows the current file to
refer to it.






















/* 
    ------------    variable storage class specifire    ------------

    variable storage class specifire:
        Variables in C not only have "data types", they also have a "storage class". There are four types of variable storage class :
    
            [1]	Automatic variables,
            [2]	External variables,
            [3]	Register  variables,
            [4]	Static variables.
    
    Four type modifiers/specifiers:
        For the four different 'variable storage class', C defines 'four type modifiers' that affect how a variable is stored. They are
    
            [1]	auto
            [2]	extern
            [3]	register
            [4]	static
    
        These 'specifiers' precede the 'type name'. That is 

                                storage_class  data_type  variable_name;
            Example :   
                                extern int count; 




    auto : 
        The specifier 'auto' is completely UNNECESSARY. 
        Automatic variables are simply 'local variables', which are "auto by Default". 




    extern 
        extern is used for multi file source code to access GLOBAL data.

        As the size of a program grows, it takes 'longer' to COMPILE. 
            For this reason, C allows us to break a program into two or more files. 
        
        We can SEPARATELY COMPILE these files and then link them together  
            (the actual method of separate compilation and linking will be explained in the instructions that accompany your compiler). 

        GLOBAL DATA may need to be accessed by two or more files that form a program. But 'global data' can only be defined 'once'.
            In this case, each source file must 'inform the compiler about the global data' it uses. 
            To accomplish this you will need to use the keyword extern. 
*/




/* Example 1: To understand why we need 'extern', consider the following program, which is split between two files. */

/* FILE #1: ("main.c" file) */
#include <stdio.h>

int count;  // Global Data

void f1(void);  // function prototype

int main(void){ 
    int i;
    f1();       // set count's value
    for(i=0; i<count; i++) printf("%d", i);

    return 0;
}



/* FILE #2 ("fl.c" function definition) */
void f1(void){
    extern int count; // Accessing GLOBAL data count using "extern"
    count = 17;
}


/* 
    By placing 'extern' in front of count's declaration in FILE #2, you are telling the compiler that 'count' is an integer defined ELSEWHERE. 
        In other words, using 'extern' informs the compiler about the existence and the type of the variable it precedes, 
            but it does not cause storage for that variable. 


    If we didn't use 'extern' two errors would occur: 

    Error 1: 
        If we directly use : 

            // FILE #2 
            void f1(void){
                count = 17 ;
            } 
            
            An ERROR will be reported because 'count' is not defined. 


    Error 2:   
        If we even define count as :
            
            // FILE #2 
            void f1(void){ 
                int count; // re-declaring the variable i

                count = 17;
            } 
            
            many linkers will report a DUPLICATE-symbol ERROR, which means that 'count' is defined twice, and the linker doesn't know which to use.

    The solution to these problem is C's 'extern' specifier. 

*/





/* 
    // another use of "extern"
    Use 'extern' in SAME FILE to MENTION the global variable (not to treat as LOCAL variable): 
        We can use  'extern' inside a 'function' to declare a global variable defined ELSEWHERE in the same file 
        (i.e.  to mention that it is GLOBAL variable so that it won't be treated as a LOCAL variable ). 

        But it is rarely used. 
            Because, whenever the compiler encounters a 'variable name' not defined by the function as a LOCAL variable, it assumes that it is GLOBAL. 
            For example, the following is valid:
*/

// Use 'extern' in SAME FILE 
#include <stdio.h>

int count;

int main(void){ 	
    extern int count; // this refers to global count 

    count = 10;
    printf("%d", count);

    return 0;
}





//-------------------------    Linking multiple source files    -------------------------

// How to Link Multiple C++ Files with G++:
    // first install "GCC compiler" or "codeBlocks with GCC"
    // we have installed "codeBlocks with GCC"
    // find the intalled path, then find the "bin" folder where the "compilers" stored
    // copy the path, its usually: 'C:\Program Files\CodeBlocks\MinGW\bin\'
    // add this path to "user variable" and "system variable" to your SYSTEM's "Environment Variables" (place the at the top of the list)
    // alwways run CLI in "C:\Users\name" i.e. in system-user directory

// Use fillowing command to link: "main.c" and "fl.c"
        // if source files are in 'C:\Users\name':
        g++ main.c fl.c -o main

// if the files are in another destination:
        // if source files are in   'H:\shared_docs\codes_C_CPP\raw_runs\multi_file'
        g++ H:\shared_docs\codes_C_CPP\raw_runs\multi_file\main.c H:\shared_docs\codes_C_CPP\raw_runs\multi_file\fl.c -o H:\shared_docs\codes_C_CPP\raw_runs\multi_file\main

// for c++ compilation
        g++ main.cpp function_file.cpp -o main
        // -o main : it means we want the output file as one "main.exe"




// To link multiple files in code::block: 
    // use 'project', 
    // create new project (console), 
    // put the source code files in the project name folder. 
    // Compile,  
    // run the whole .cbp file.




/* 
    register (access AS FAST AS POSSIBLE): 
        When you specify a 'register variable' you are telling the compiler that you want ACCESS to that variable to be AS FAST AS POSSIBLE. 
        
        In 'early version of C 'it causes the variables to be held in a register of the CPU. (This is how the name register came about.)
            By using a register of the CPU, "EXTREMELY FAST ACCESS" times are achieved.


        In 'modern versions of C', the requirement that register variables must be held in a CPU register was 'removed'. 
            Now a register variable will be stored in such a way as to minimize access time. This means:

                register variables of type 'int' and 'char' continue to be held in a CPU register.
                
                No matter what storage method is used, only so many variables can be granted the fastest possible access time. 
                    e.g. the CPU has a limited number of registers. When fast-access locations are exhausted, 
                        the compiler is free to make register variables into regular variables.


        You must choose carefully which variables you modify with register.  
            use it for a frequently used variable, such as the variable that CONTROLS a LOOP, into a register variable.  
                The more times a variable is accessed, the greater the increase in performance when its access time is decreased.
                
            Generally, you can assume that 'at least two variables per function' can be truly optimized for access speed.

        pointers vs register:
            Restriction of using pointers: 
            Because a register variable may be stored in a register of the CPU, it may not have a 'memory address'. 
                This means that you cannot use the "&" to find the ADDRESS of a 'register variable' and cannot use POINTERS.




    static : 
        Recall how a local variable act: a local variable is created upon entry into its function and destroyed upon exit. And a global variable is active in whole program.

        -----------------    static LOCAL variable    -----------------

        Use of static modifier on local variables:  
            When you use the static modifier, you cause the contents of a local variable to be preserved between function calls 
                (That is it will not destroy when function exit and it act like a global variable inside its own function). 

        Unlike normal local variables, which are 'initialized each time a function is entered', a static local variable is "INITIALIZED only ONCE". 

        The advantage to using a 'static local variable' over a 'global': 
            The 'static local' variable is still known to and accessible by only the function in which it is declared.
            Global variables active outside any function.


        -----------------    static GLOBAL variable    -----------------

        Use of static modifier on global variables :  
            The 'static' modifier may also be used on 'global variables' (more like a local variable for its own file). 
            It causes the GLOBAL VARIABLE to be known to and accessible by ONLY the functions in the SAME FILE in which it is declared. 
            This static global variable has 'NO EFFECT ON OTHER FILE' (when we work with different files) which use the 'same named global variable'.

*/



/* Example 2: take a look at this program, notice how static is used. */

#include <stdio.h>

void f(void);

int main(void){ 
    int i;
    for(i=0; i<10; i++) f();
    return 0;
}

void f(void){   
    static int count = 0;
    // int count = 0;
    count++;
    printf("count is : %d  ", count);
}


// which displays the following output, . Here count retains its value between function calls. :
count is : 1 count is : 2 . . . .  count is : 10 

// but without static modifier int count = 0; gives the result : 
count is : 1 count is : 1 . . . .  count is : 1. Which is obvious and we explained in 3.2 in chapter 3.





/* Example 3: no name conflicts arise if a static global variable in one file has the same name as another global variable 
                in a different file of the same program. 
                For example, consider these two fragments, which are parts of the same program: */


// FilE #1
int count;  // global variable
. . .
. . .
count = 10;
printf("%d", count);



// FilE #2
static int count;   // static global variable (using same name of File#1's global var)
. . .
. . .
count = 5:
printf("%d", count);
 

// Because count is declared as static in FILE #2, no name conflicts arise. 
    // The printf() statement in FILE #1 displays 10 and the printf() statement in FILE #2 displays 5 
    // because the two counts are different variables.





/* Example 4: (Calculate the access time) In following program, we try to calculate the access time to a register variable.

                    -------------    clock()    -------------

                Use clock() from C's standard library.
                    It returns the number of system clock ticks since the program began execution. It's prototype:

                            clock_t clock(void);

                    It uses the <TIME.H> header. <TIME.H> also defines the 'clock_t type', which is more or less the same as 'long'.


                To time an event:
                    using clock(), call it immediately before 'the event you wish to time' and save its returned value.
                    Next, call it a second time 'after the event finishes 'and subtract the 'starting' value from the 'ending' value.


                Now we use this approach in this program to calculate the execution time of two loops
                    One loop will use normal "non-register" variable.
                    Another loop will use "register" variable. It'll controlled by a register variable.


                since there is a LIMIT of using register variables
                    we used only 'one register variable' for the nested loop
 */

#include <stdio.h>
#include <time.h>
int a;  // extra variables
int b;  // extra variables
int c;  // extra variables
int d;  // extra variables

int i;  // This will not be transformed into a REGISTER VARIABLE because it is GLOBAL

int main(void){
    register int j;     // REGISTER variable
    int k;
    clock_t start, finish;

    start = clock();
    for(k=0; k<10000; k++)
        for(i=0; i<32000; i++);     // just running the loops
    finish = clock();
    printf("Non-register loop: %ld ticKs \n", finish - start);

    start = clock();
    for(k=0; k<10000; k++)
        for(j=0; j<32000; j++);     // applying a REGISTER variable j to control this nested loop
    finish = clock();
    printf("Register loop: %ld ticKs \n", finish - start);

    return 0;
}

// Output:
// Non-register loop: 664 ticKs
// Register loop: 114 ticKs


/*
    NOTES:
        Automatic optimization for any local variable:
            virtually all compilers will automatically convert local variables not specified as register types
                into register types as an 'automatic optimization'.

        The non-register variable usually global.

        If you do not see the predicted results,
        it may mean that the compiler has automatically optimized global variable i into a register variable, too.

        Although you 'can't declare GLOBAL variables as REGISTER',  there is nothing that
            prevents a compiler from optimizing your program to this effeet.

        If you don't see much difference between the two loops,
            try creating "extra global variables" prior to i so that it will not be automatically optimized.


        For most compilers, the register-controlled loop will execute about twice as fast as the non-register controlled loop.
*/







-----------------    rev below    -----------------

Example 2: As you know, the compiler can optimize access speed for
only a limited number of register variables in anyone function
(perhaps as few as two). However, this does not mean that your
program can only have a few register variables. Because of the
way a C program executes, each function may utilize the
maximum number of register variables. For example, for the
average compiler, all the variables shown in the next program
will be optimized for speed:
#include <stdio.h>
void f2 (void) :
void f (void) ;
int main (void)
(
register int a , b;
)
void f (void)
(
register int i, j;c
void f2(voidl
(
register int j. k;
)



Example 3: Local static variables have several uses. One is to al1o-;'" a
function to perform various ininalizations only once, when it is
first called. For example, consider this function :
void myfunc(void)
(
}
static inc first = 1;
if{f~rst) { j* initialize the system */
rewH~d (fp) ;
)
a = 0;
lee = 0,
fprintf(~System IniLialized~);
first = 0;
Because first is static, it will hold its value between calls. Thus,
the initialization code will be executed only the first time the
function is called.



Example 4: Another interesting use for a local static variable is to control a
recursive function. For example. this program prints the
numbers 1 through 9 on the screen:
#include <stdio.h>
void f (void) ;
int main (void)
(
t();
return 0;
}ADVANCUI DATA TYPES AND OPERATORS 347
void f (void)
(
)
static int stop=O:
stop++;
if(stop==10) return;
printf("%d ", stop);
f(); /* recursive call *1
11.' USE THE STORAGE ClASS SPEC/FifRS
Notice how stop is used to prevent a recursive call to C( ) when
it equals 10.



Example 5: Here is another example of using extern to allow global data to
be accessed by two files:
FILE #1:
fiinclude <stdio.h>
char str[80];
void getname(void);
int main (void)
(
getname () ;
printf"{ -Hello %s·. str);
return 0;
)
FILE #Z,
'include <stdio.h>
extern char str[BO]:
void getname(void)
(
)
printf("Enter your first name: .. ,; .
gets (str);
~TEACH YOURSElF
C
EXERCISES



------------   exs   -------------



Example 1: Assume that your compiler will actually optimize access time of
only two register variables per function. In this program, which
two variables are the best ones to be made into register variables?
#include <stdio.h>
#include <conio.h>
int main (void)
{
)
int i. j, k, m;
do ("
printf t -Enter a value: .);
scanf ("M', &i);
m = 0;
for(j=O; j<i; j++)
for (k=Oi k<100i k++ )
m = k + mi
while t i>O) ;
return 0;

1. The best variables to make into resIatm" types are k and m,
because they are accessed most frequently



linclude <stdio.h>
,
void .~it(int value),
int ....in(void)
(
}
sWlLit(lO) ,
sum_it (20) ,
sWILit(30) ,
sWILit(40);
return OJ
void s~it{int value)
(
static int sum=O;
sum = sum + value;
printf(-CUrrent value: 'd\n·, sum);
}




Example 2: Write a program that contains a function called sum_it( ) that
has this .prototype:
void sum_it (int value);
Have this function use a local static integer variable to maintain
and display a running total of the values of the parameters iUs
called with. for example, if sum_it( ) is called three times with
the values 3,6, 4, then sum_it( ) will display 3, 9, and 13.




Example 3: Try the program descnbed in Example :.. Be sure to actually use
two files. If you are unsure how to compile and link a program
consisting of two files, check your compiler's user manual.




What is wrong with this fragment?
register int i;
int .p;
p = &i;

Example 4: You cannot obtain the address of a register variabl



