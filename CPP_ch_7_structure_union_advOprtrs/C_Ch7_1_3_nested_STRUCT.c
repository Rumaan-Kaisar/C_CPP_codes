
// -------------------    NESTED STRUCTURES    -------------------

// A sctructure's members can also be other structures. These are referred to as nested structures. 


/* Example 1: Here is an example that uses nested structures to hold information on 
the performance of two assembly lines, each with ten workers: */

struct worker{
    char name[80];
    int avg_units_per_hour;
    int avg_errs_per_hour; 
};

struct asm_line{	
    int product_code;
    double material_cost;
    struct worker wkers[NUM_ON_ LINE];
};

struct asm_line line1, line2;


// ------------------    accessing nested structure members    ------------------
// Whenever you have nested structures, you begin with the "outermost " and end with the "innermost ".

// To assign the value 12 to the 'avg_units_per_hour' of the "second wkers structure of line1" , use this statement:

line1.wkers[1].avg_units_per_hour = 12;

// As you see, the structures are accessed from the outer to the inner. This is also the general case. 




Example 2: A nested structure can be used to improve the card catalog
program. Here, the mechanical information about each book is
stored in its own structure, which, in turn, is part of the catalog
structure. The entire catalog program using this approach is
shown here. Notice how the program now stores the length of
the book in pages.
/ - An electronic card catalog--3rd Improvement. */
#include <stdic.h>
#include <string.h>
#i~clude <stdlib.h>
#define MAX 100
int menu (void) ;
void display(int i);
void author_search (void);
void title~search(void);
void enter(void);
void save(void);
void load (void) i
struct book_type (
unsigned date; /. copyright
unsigned char ed; /. edition 'f
unsigned pages; f' length of
)
date ./
book 'f320 TEACH YOURSElf
~ C
/* author name *j
title */
publisher -/
catalog {
name[80] ;
title[80]; /-
pub[80]; /-
struct
char
char
char
struct book_type book; /* mechanical info wi
) cat [MAX] ;
int tOP = 0; '* last location used */
int main(voidl
{
)
int choice;
load(); /* read in catalog */
do {
choice = menu () ;
5witch (choice) (
case 1: enter(); '* enter books */
break;
case 2: author_search(); /* search by author */
break;
case 3: title_search(); /* search by title */
break;
case 4.: save();
)
} while(choice!=51;
returr. 0;
'* Return a menu selection. */
menu (void)
{
int i;
char str(80};
printf("Card catalog:\n");
printf(" 1. Enter\n");
printf{" 2. Search by Author\n");
printf{" 3. Search by Title\n");
printf'" 4.. Save catalog\n");
printf'" 5. Quit'n");
do {)
STRUCnJRES AND UNIONS
10.3 WORK WITH NESTED STRUCTURES
printf(-Choose your selection: R);
gets(str) ;
i = atoi(str);
pnntf("'n") ;
) while(i<l II i>5);
return i;
/* Enter books into database. */
void enter (void)
(
)
int i;
char temp(8D]:
for (i=top; i<MAX; i++) {
printf(NEnter author name (ENTER to quit): ~)
gets(cat(i] .name):
if(!*cat[i] .name) break;
printf{"Enter title: ");
gets(cat[i] .title):
printf("Enter publisher: ");
gets(cat(i] .pub) i
)
printf("Enter copyright date: ");
gets (temp) ;
cat[i] .book.date = (unsigned) atoi(temp);
printf("Enter edition: ");
gets (temp) ;
cat[i].book.ed = (unsigned char) atoi(temp);
printf("Enter number of pages: ");
gets (temp) ;
cat[i].book.pages = (unsigned) atoi(temp);
top = i;
/* Search by author. */
void author_search (void)
{
char name [80] ;
int i, found;
printf ("Na.'lle: ");
gets (name) ;
321
,.322 TEACH YOURSELF
c,
)
found = 0;
for(i=O; i<top; i++)
if(!strcmp(name. cat{i] .narne» {
display(i) ;
found = 1;
printf,-'n M ) ;
)
if(!foundl printf(MNot Found\n-);
/'" Search by title. "'I
void title_search(voidl
{
char titleIBO];
int i. found;
printftMTitle: .);
gets{':.ltle);
fCl1.:.nd = 0;
for{i=O; i<top; i++)
if(!strcmp(title. cat[ij.title» {
(hsplay (i) ;
found = 1;
printf!"\n-) ;
)
if(!foundl printf(-Not Founc\n*);
,- Display catalog entry. */
void display(int il
{
)
printf(-'s\n-, catli] .title);
printf(-by %5\n-, cat[~J .name);
printf(*Published by %s\n"', cat[i] .pub);
printf(·Copyright: %u. edition: %u\n-,
catli1.book.date. cat[i] .book.edl;
p~intf(·Pages: %u\n-, catli] .book.pages);
/* Load the catalog file. */}
void load(void)
(
FILE ·fp;
STRUCTURES AND UNIDNS 323
1a3 WORK WITH NESTED STRUCTURES
if«fp = fopen("catalog", "rb"))==NULL) (
printf("Catalog file not on disk.\n");
return;
}
if(fread(&top, sizeof top, 1, fp) != 1) ( /* read count */
printf("Error reading count.\n");
exit{l);
}
if(fread(cat, sizeof cat, 1, fp) != 1) { /* read data */
printi (~Error reading catalog data. \n") ;
exi t (I) ;
fclose (fp) ;
/* Save the catalog file. */
void save(void)
(
FILE "fp;
if({fp = fopen{"catalog", "wb."»==NULL) (
printf("Cannot open catalog file.\n");
exit(l) ;
}
if(fwrite(&top. sizeof top, 1, fp) != 1) { /* write count */
printf{"Error writing count.\n");
exit(l);
}
if(fwrite(cat, sizeof cat, 1. fp) != 1) ( /* write data */
printf(·Error writing catalog data.\n");
exit(!);324
"
TEACH YOURSELF
C
- . , 10.4 . '
)
)



// ---------------    EXERCISE    ----------------
1. 




Example 3: Improve the telephorle-directory program you wrote earlier in
this chapter so that it includes each person's mailing address.
Store the address in its own structure, called address, which is
nested inside the directory structure.
U N DERSTAND BIT-FIELD'* A simple computerized telephone book. *'
'include <stdio.h>
'include <string.h>
'include <stdlib.h>
'define MAX 100
struct address {
char street(40];
char city[40J;
char state[3];
char zip[12J;
) ;
struct phone_type {
char name [40J ;
int areacode;
char number [9] ;
struct address addr;
) phone [MAX] ;
int 10c=0;
int menu (void) ;
void enter(void);
void load(void);
void save (void) ;
void find(void);
int main (void)
(
int choice;
do (
choice = menu( );
...
••
1tACH YOURSELF
C
)
switch (choice) {
case 1: enter ( );
break;
)
case 2: find( );
break;
case 3: save ( ):
break;
case 4: load( ) ~
} while(choice!=5);
return 0;
/* Get menu choice. */
rnenu(void)
(
)
lnt i;
char str[80];
printf(-1. Enter names and nurnbers\n-);
printf(~2. Find numbers\n-):
printfC-3. Save directory to disk\n-);
printfC-4. Load directory from disk\n.);
printf('S. Quit\n');
do (
printfC-Enter your choice: .);
gets (str);
i = atoi (str) ;
printf (. \n· ) ;
) while(i<l II i>S);
return i;
void enter(void)
{
char tempI80];
for (; loc<lOO; loc++) {
if (10c<100) (
.
printfC-Enter name: .);
gets (phone {loc] .name):
if(!*phone(loc) . name) break;
printfC-Enter area code: .);
•)
)
gets Ctemp) ;
phone{loc] .areacode = atoi(temp);
printfC-Enter number: .);
gets Cphone [locJ .number);
j* input address info -j
printf(-Enter street address: .);
_ gets(phone[loc].addr.street);
print! (-Enter city: .);
getsCphone[locJ .addr.city);
printf(-Enter State: .);
)
gets (phone {loc] .addr.state):
printf ( . Enter zip code: .);
gets (phone(loc] .addr.zip):
-
EXERaSES
void find(void)
{
)
char name[80};
int i:
printfC-Enter name: W);
gets (name) ;
if(!*name) return;
for l i=O; i<100; i++)
)
if(!strcmp(name, phone(i] .name» {
printfC"%s C%q) %s\n", phone[iJ .name,
phone[i] .areacode, phone{i] .number):
printf(-'s\n%s %5 %s\n", phone[i] .addr.street,
phone[i] .addr.city, phone[i] .addr.state,
phone [iJ . addr. zip) ;
void load(voidl
(
FILE *fPi
ifCCfp = fopenC "phone" , "rb"))==NULL) (
printf(-Cannot open file.\n-);
exit(l) ;
)
H7
'If)
loc = 0;
whi1e(!feof(fp)) (
fread(&phone[1ocl. sizeof phone[1ocl. 1. fp l;
loc++;
)
fc1ose(fp) ;
void saveCvoid)
(
)
FILE *fp;
int i;
if«(fp = fopen("phone". "wb"))==NULL) {
printfC-Cannot open file.\n·};
exit(l);
)
for(i=O; i<loc; i++) (
fwrite(&phone[il. sizeof phone[il. 1. fp);
)
fclose(fp) ;
\
XERCISES
