/* 
    ---------------    THE STANDARD STREAMS    ---------------
    Standard  streams: 
        When a C program 'BEGINS EXECUTION', three streams are automatically opened and available for use.

                1. standard input (stdin), 
                2. standard output (stdout), and 
                3. standard error (stderr). 

        "stdin" inputs from the KEYBOARD;  
        "stdout" and "stderr" write to the SCREEN.

        By default, they refer to the "CONSOLE", 
            but in environments that Support redirectable I/O, they can be redirected by the OS to some other device.



    These 'standard streams' are "FILE pointers" and may be used with any function that requires a variable of type "FILE *". 

    ConIO using FileIO:
        You can use fprintf() to print "formatted output" to the screen by specifying "stdout" as its output stream. 
            The following two statements are functionally the same:
        
                // using FileIO function
                fprintf(stdout, "%d %c %s", 100, 'c', "this is a string");

                // usning ConIO function
                printf("%d %c %s", 100, 'c', "this is a string");


        In actuality, C makes little distinction between 'console-I/O' and 'file-I/O'. 
            As just shown, it is possible to perform "console I/O" using several of the 'file-system functions'. 



    Disk FileIO using ConIO:
        It is also possible to perform "DISK FILE I/O" using 'CONSOLE I/O' functions, such as printf().
            Because all "console I/O functions" are actually 'special-case file-system functions' that automatically operate on "stdin" and "stdout". 

        The console is simply another hardware device. 
            You don't actually need the 'console functions' to access the "console". Any 'file-system function' can access it. 
            (non-standard I/O functions like getche() are differentiated from the 'standard file-system functions' and operate "only on the console".) 



    Redirection of std streams: 
        In environments that allow "REDIRECTION OF I/O", 'stdin' and 'stdout' could refer to devices "other than the KEYBOARD and SCREEN". 
        
        Since the "console functions" operate on STDIN and STDOUT, if these streams are REDIRECTED, 
            the "console functions" can be made to operate on other devices. 
                For example, by redirecting the "STDOUT" to a "DISK FILE". you can use a "console I/O function" to write to a DISK FILE.



    Note that:
        stdin, stdout, and stderr are not variables. They may not be assigned a value using fopen() , 
            nor should you attempt to close them using fclose() . 
            These streams are "maintained internally" by the COMPILER. 
            You are free to use them, but 'not to change them'.
*/




/* Example 1: Assume that this program is called "TEST". If you execute TEST normally, it displays the string on the screen. 
                However, if an environment supports redirection of I/O, stdout can be redirected to a file. */
#include <stdio.h>

int main(void){
    printf("This is an example of redirection.\n");
    return 0;
}

// For example, in a DOS, OS/2, Windows, or UNIX environment, executing TEST like this
TEST > OUTPUT
// causes the output of TEST to be written to a file called OUTPUT. You might want to try this now for yourself.

// we named our source file "FL_IO_strm_1" and stored the output a file called "output_test"
FL_IO_strm_1 > output_test




/* Example 2: Input can also be redirected. For example, consider the following program.
                causes "STDIN" to be directed to the file called INPUT. 
                Assuming that INPUT contained the ASCII representation for an integer,
                the value of this integer will be read from the file and printed on the screen. */
#include <stdio.h>

int main (void){
    int i;

    scanf ("%d", &i);
    printf ("%d", i);
    return 0;
}

// Assuming it is called TEST, executing it as
TEST < INPUT

// we named our source file "FL_IO_strm_2" and stored the output a file called "input_test"
FL_IO_strm_2 < input_test



// Note: from above 2 Examples notice usage of ">" for "output" and "<" for "input"




/* Example 3: When using gets() it is possible to overrun the array that is being used to receive 
                the characters entered by the user because gets() provides "no bounds checking". 

                One way around this problem is to use
                    fgets(), specifying 'stdin' for the "input stream". 
                    Since fgets() requires you to specify a maximum length, it is possible to prevent an array overrun. 
                    The only trouble is that fgets() does not remove the newline character and gets() does. 
                    This means that you will have to manually remove it, as shown in the following program:     */
#include <stdio.h>
#include <string.h>

int main(void){
    char str[10];
    int i;

    printf("Enter a string: ");
    fgets(str, 10, stdin);

    // remove newline, if present
    i = strlen(str)-1;
    if(str[i]=='\n') str[i] = '\0';

    printf ("This is your string: %s", str);

    return 0;
}

// FL_IO_strm_3 < myFile_2ol



/* Example 4: Write a program that copies the contents of one text file to another. 
                However, use only "console IO functions" and redirection to accomplish the file copy. */

// -----------  review following

/* Copy using- r_edirection.
Execute like this:
C>NAME < in > out
*'
linclude <stdio.h>
int main(void)
{
char Chi
while ( !feof (stdin)) (
scanf(·'c·, &ch);
if(!feof(stdin}} printf("'c", ch};
1
return 0;
)


2. On your.own, experiment using fgets( ) to read strings entered
from the keyboard.






------------ mastry
Before continuing, you should be able to answer these questions
and complete these exercises:
1. Write a program that displays the contents of a text file (specified
on the command line), one line at a time. After each line is
displayed, ask the user ifhe or she wants to sec another line.

1. 'include <stdio.h>
'include <stdlib.h>
'include <ctype.h>
.
int main(int argc, char -argv[])
(
)
FILE tip;
char str(BO);
I- see if file name is specified -I
if(argc!=2) (
)
printf (-File name missing. \n·) ;
exit (1);
if «fp = fopen(argv(l], ·r·))==NULL) (
printf(-Cannot open file.\n-);
exit(l) i
)
while (! feof (fp» (
fgets (str, 79, fp);
)
if(!feof(fp» printf(·\S·, str);
printf (- ... More? (yin) .);
if(toupper(getchar(»=='N') break;
printf ( • \n·) ;
fclose (fp) ;
return 0;


2. Write a program that copies a text file. Have the user specify
both file na~es on the command line. Have the copy program
convert all lowercase letters into uppercase ones.
I- Copy a file and convert to uppercase. -/
'include <stdio.h>
'include <stdlib.h>
'include <ctype.. h>
int main(int argc, char *argv[l)
{
}
FILE ·from, -to;
char Chi
/* see if correct number of command line ar~ents· */
if (arge! =3) {
}
printf (·Usage.: copy <source> <destination>\n"');
exit(l) ;
/ * open source file * /
if«from = fopen(argv[lL "r"»=.NULL) (
printf("Cannot open source file.\n"):
Qxit (1);
}
/ . ope~ destinat10n file * /
if«to = fopen(argv[21. ·w")==NULLI {
printf (·Cannot open destination file. \n") ;
exit(l);
}
/* copy the file */
while (! feoE (from) {
ch = fgetc(from);
if(!feof(from») fputc(toupper(chl. to);
}
fclose(from) ;
fclose(to) ;
return 0;

3. What do fprintf( ) and fscanf( ) do?
The fprintf( ) and fseanf( ) functions operate exactly like
printf( ) and seanf( ), except that they work with files.


4. Write a program that uses fwrite( ) to write 100 randomly
generated integers to a file called RAND.
'include <stdio.h>
'include <stdlib.h>
i~t main (void)
(
FILE *fp;
int i, nwn;
if«fp = fopen("rand", "wb"))==NULL) (
printf{-Cannot open file,\n-);
exit(l);
}
for(i=O: i<100; i++) (
nurn = rand ( );
fwrite(&num. sizeof nurn, 1, £p);
}
fc10se (fp) ;
return 0;



5. Write a program that uses fread( ) to display the integers stored
in the file called RAND, created in Exercise 4.
'include <stdio.h>
jinclude <stdlib.h>
int main(void)
(
}
FILE '*fp;
int i. nurn;
H«fp = fopen("rand"\ "rb"))==NULL) (
printf("Cannot open file.\n");
exit (1);
)
for(i=O; i<100; i++) (
fread(&num, sizeof nurn, 1, £p);
printf("'d\n·, nurn);
}
fc1ose(fp) ;
return 0;


6. Using the file called RAND, write a program that uses fseek( )
to allow the user to access and display the value·of any integer
in the file.
'include <stdio.h>
'include <stdlib.h>
int main{void)
{
,
FILE *fp;
long i;
int num:
if«fp = fopen('rand', 'rb'»==NULL) (
printf(-Cannot open file.\n-);
exit(l);
)
printf('Which number 10-99)? ');
scanf(-'ld-, &i);
fseek (fp, i * sizeof (int) I SEEK_SET);
fread(&num, sizeof num, 1. fp);
printf 1' \d\n', nurn);
fclose 1fp) ;
return 0;



7. How do the "console' I/O functions relate to the file system?
The 'console' I/O functions are simply special cases of the
general file system .. ...


---------- cumul
This section checks how well you have integrated the material in
this chapter with that from earlier chapters.

1. Enhance the card-catalog program you wrote in Chapter 8 so
that it stores its information in a disk file called CATALOG.
When the program begins, have it read the catalog into memory.
Also, add an option to save the information to disk.
1 . / * An electronic card catalog. */
'include <stdio.h>
'incl~de <string.h>
'include <stdlib.h>
.define MAX 100
int menu (void) ;
void display(int il;
void author_search(void):
void title_search(void):
void enter(void);
void save (voidl ;
void load(void):
char names [MAX] [80]; /* author names * /
char titles[MAXJ [BOJ; /, titles ,/
char pubs[MAXJ [BOJ; /, publisher '/
int top = 0: /* last location used */
int main (void)
(
}
int choice;
load(): /* read in catalog */
do (
choice = menu():
switch (choice) {
}
case 1: enter(); /* enter books */
break;
case 2: author_search(); /* search by author */
break:
case 3: title_search(); 1* search by, title */
break;
case 4: save();
} while(choice!=5);
return 0 i
/* Return a menu selection. */
rnenu(void)
(
}
int i;
char str(80];
printf{-Card Catalog:\n-);
printf(- 1. Enter\n-):
printf (. 2. Search by author\n·);
printf(" 3. Search . by Title\n");
printf(-
printf("
do (
4. Save catalog\n-);
5. Quit\n");
printf(·Choose your selection: .);
gets (str) ;
i = atoi(str);
printf (" \n") ;
} while(i<l II i>5);
return i;

'* Enter books into database. */
void enter(void)
{
   int i:
___.

for(i=top: i<MAX: i++) {
printf("Enter author name (ENTER to quit) .);
gets (names (il ) ;
if(!*names[i]) break:
printf{"Enter title: .);
gets(titles[i»;
printf("Enter publisher: .);
gets(pubs[i» ;
)
top = i; 
}
'* Search by author. */
void author_search(void)
{
)
char name [80] i
int i. found;
printf ("Name: ");
gets (name) ;
found: 0;
for(i=O; i<top; i++)
if{ ! strcmp {name, names (i) » {
display (i) ;
found: 1;
printf ( "\n" ) ;
)
if(!found) printf("Not Found\n");
j* Search by title. */
void title_search(void)
(
char tit1e[80);
int i, found:
print£(IOTitle: .):
gets(tit1e) ;

found = 0;
for(i=O: i<top; i+.)
if(!strcmp(title, titlesli)) (
display (i) ;
found = 1;
printf (" In") ;
)
if(lfound) printf{~Not Found\n-);
/* Display catalog entry. */
void display{int i)
(
}
printfC-'s\n", titles[i]);
printf(-by %s\n-, names[i});
printf("Published by 'sIn", pubsli);
/* Load the catalog file. */
void load(void)
(
FILE jofp;
ifllfp = fopenl"cataloq", "r"»==NULL) (
printfC-Catalog file not on disk.\n-);
return;
}
fread(&top, sizeof top, 1, £Pl; I* -read count */
fread(names, sizeof names, 1, £pl;
fread(titles, ~izeof titles, 1, fp);
fread (pubs , sizeof pubs, 1. fp);
fclose Ifp) ;
,
1* save the catalog file. */
void save(void)
(
FILE 'fp;
if(lfp = fopen("catalog", "W"»==NULL) (
printf(-Cannot op~n catalog file.\n-);
exit (1);

)
fwrite(&top, sizeof top, 1, fpl:
fwrite(names. sizeof names, 1, fp);
fwrite(titles, sizeof titles. 1, fp);
fwrite(pubs. sizeof pubs, 1, fpl:
fclose(fp





2. Write a program that copies a file. Have the user specify both
the source and destination files on the command line. Have the
program remove tab characters, substituting the appropriate
number of spaces.
/* Copy a file and remove tabs. */
iinclude <stdio.h>
'include <stdlib.h>
'include <string.h>
int main(int argc, char *argv{])
(
FILE ·from. *to;
char chi
int tab. count;
/ * see if correct number of command line arguments *1
if(argc!=3) (
)
printfC-Usage: copy <source> <destination>\n-);
exit(l) ;
/ * open source file *1
if«from = fopen(argv[l). "r")I==NULL) {
print;f ("Cq,nnot ·open source file. Xn") ;
exit(l);
)
1* open destination file *1
if( (to = fopen(argv[2J. "W")I==NULL) (
printfC-Cannot open destination file.\n-);
exit(l);
)
1* copy the file *1
count = 0;
while(!feof(from» (
ch = fgetc (from) ;
if (ch== •\ t .) {
.for (tab = count; tab<8: tab++)

fputc (. '. to);
count = 0;
else {
if (! feof (from» fputc (ch, to);
count++:
if(count==8 I I ch=='\n') count = 0;
fclose (from) :
fclose (to) ;
return 0;


3. On your own, create a small database to keep track of anything
you desire-your CD collectiorl;" for el<ample:



-----------reviu
Before proceeding you should be able to answer these questions and
perform these exercises:
1. Write a program that copies a file. Have the user specifY both
the source and destination file names on the command line.
Include full error checking.

1. 1* Copy a file. *1
'include <stdio.h>
#include <stdlib.h>
int main(int argc. char *argv[)
(
FILE *from. *tOj
char chi
1* see if correct number of command line arguments t/
if(argc!=3) (
)
printf(MUsage: copy <source> ~destination>\n-';
exit(!);
j* open source file +1
if«from = fopen(argv(lJ, "rb"»==NULL) C
printf (-Cannot. open source file. \n -) :
exit (1);
)
It open destination file */
if«to = fopen(argv(2], "wb"»==NULL) (
printf(-Cannot open destination file.\n-);

exit(l);
)
j'* copy the file '*,
while(!feof(from)) (
)
ch = fgetc (from) ;
if(ferror(from)) (
printf(-Error on input.\n-);
break;
)
if(!feof(from)) fputc(ch, to),
tf (ferror (to)) (
)
printf(-Error on output.\n-);
break:
if(fclose(froM)=~EOF) {
)
printf (-Error closing source file. \n-);
exit(l);
if(fclose(to)·=gQF) (
)
printf(-Error closin~ destination file.\n-):
exit(l) ;
retuI11 0;





2. Write a program using fprintf( ) to create a file that contains
this information:
this is a string 1230.23 IFFF A
Use a string, a double, a hexadecimal integer, and character
format specifiers and values.

linclude <sedio.h>
'inc1ud$ <stdlib.h>
int main (void)
(
FILl!: 'fp;
j'* open file '*/
H«fp = fopen("myfile", "w"))~=NULL) (
printf("Cannot open file.\n");
exit(l),
)
fprintf(fp. -'s %.2£ \X 'c·, -this is a string-,
1230.23, OxlFFF, 'A');
fclose(fp) ;
return 0;
)




3. Write a program that contains a 20·element integer array.
Initialize the array so that it contains the numbers 1 through 20.
Using 0Tlly one fwrite( ) statement, save this array to a file
called TEMP.
#include <stdio.h>
'include <stdlib.h>
)
int main(vOid)
{
FILE -fPi
int countC20J, i;
/* open file */
if «fp = fopen ("TEMP", "wb"» ==NULL) {
printf (·Cannot open file. \n.) ;
exit(1);
)
for(i=O; i<20; i++) count[ij = i+l:
fwrite(count, sizeof count, 1, fp);
fclose (fp) ;
return 0


4. Write a program that reads the TEMP file created in Exercise 3
into an integer array using only one fread( ) statement. Display
the contents of the array.
'include <stdio.h>
.include <stdlib.h>
int main (void)
(
FILE *fp;
int count (20) , i;
1* open file */
if({fp = fopen{"TEMP", "rb"»==NULL) (
printf("Cannot open file.\n");
exit (1);
)
fread(count, sizeof count, 1, fp):

for(i=O; i<20: i++) printf(-'d· count[i]);
fclose(fp) ;
return 0;
)




5. What are stdin, stdout, and stderr?
5. stdin, stdout, and stderr are three streams that are opened
automatically when your C program begins executing. By
default they refer to the console, but in operating systems that
support 110 redirection, they can be redirected to other devices.


6. How do functions like printf( ) and scanf( ) relate to the C
file system?

6. The printf( ) and scanf( ) functions are part of the C file
system. They are simply special case functions that
automatically use stdin and stdout.

