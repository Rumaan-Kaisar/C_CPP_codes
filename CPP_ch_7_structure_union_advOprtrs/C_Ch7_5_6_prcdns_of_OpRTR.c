
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

At this point you should be able to answer these questions and
perform these exercises:



Example 1: What does the register specifier do?
The register specifier causes the C compiler to provide the
fastest access possible for the variable it precedes


Example 2: What do the const and volatile modifiers do?
The const-specifier tells the C compiler that no statement in the
program·may modifY a variable declared aSCOJl8t. Also, a conat
pointer parameter may not be used to modifY the object pointed
to by the pointer. The volatile specifier tells the compiler thai814
...
3.
any variable it precedes may have its value changed in ways not
explicitly specified by the program.


Example 3: Write a program that sums the numbers J to J00. Make the
program execute as fast as possible.
ftinclude <stdio.h>
int main (void)
(
register int i. sum:
sum = 0;
for(i=l; i<101; i++)
swn = sum i;
printf ("%d", sum) ;
return 0;
}


Example 4: Is this statement valid? If so, what does it do?
typedef long double bigfloat;
Yes, the statement io valid. It creates another name for the ~'pe
long double.




Example 5: Write a program that inputs two characters and compares
corresponding bits. Have the program display the number of
each bit in which a match Occurs. For example, if the two
integers are
1001 0110
11101010
,I. ro KNOW THE PRECEDENCE SUMMARY
tre program will report that bits 7, 1, and 0 match. (Use the
bitwise operators to solve this problem.)
'include <stdio.h>
'include <coniOth>
}
int main (void)
(
char chI, ch2:
char mask, i;
printfC-Enter two characters: .);
chI = getche () ;
ch2 = getche ( , ;
printf (" \n", ;
mask = 1;
forCi=O; i<8; i++) {
)
if « ....sk " chII "" (....sk " ch2I I
printf("bits td the same\n", il;
mask «= 1;
return 0;



Example 6: What do the « and » operators do?
The < < and> > are the left and right shift operators,
respectively



Example 7: Show how this statement can be rewritten:
c=c+l0i
c >= 10;


Example 8:· Rewrite this statement using the? operator:
if(!done) count = 100;
else count = 0;
count = done? 0 : 100;


Example 9: What is an enumeration? Show an example that enumerates
the planets.
An enumeration is a list of named integer constants. Here is one
that enumerates the planets.
enum planets {Mercury. Venus. Earth , Mars, Jupiter.
Saturn, Neptune. Uranus, Pluto} :



// ---------    CUMULATIVE    ---------
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

