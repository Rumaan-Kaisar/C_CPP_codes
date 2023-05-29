
/* 
    ---------------    End of file [EOF]    ---------------
    End of file [EOF] feof() And file error checking ferror()


    fgetc() returns EOF either
    [1]	 an error has occurred 
    [2]	or the end of the file has been reached

    How do you know which event has taken place? 
        Further if you are operating on a binary file, all values are valid. It is possible that a byte will have the same value (when elevated to an int) as EOF.
            So how do you know if valid data has been returned or EOF reached?


    feof() and ferror(), are the solution:

            int feof(FILE *fp);
            int ferror(FILE *fp);



    feof(): 
        feof() returns 'nonzero' if the file associated with fp has reached the "EOF [literally End-Of-File]". 
        Otherwise it returns zero. (i.e 0 for error EOF)
        This function works for both binary files and text files. 


    ferror(): 
        ferror() returns 'nonzero' if the file associated with fp has an "ERROR". 
        Otherwise, it returns zero (for no ERR).

        Keep in mind that ferror() only reports the status of the file system relative to the "last file access". 
            Therefore, you must call it "after each file" operation.
*/



/* Example 0: Using the feof() function, this code fragment shows how to read to the end of a file: */

FILE *fp;
char ch;
. 
. 
. 
while(!feof(fp)) ch = fgetc(fp);

// This code works for any type of file and is better in general than checking for EOF. 
// However, it still does not provide any error checking. Error checking is added here:

FILE *fp;
char ch;

. . . 
. . .
while(!feof(fp)){
    ch = fgetc(fp); 
    if(ferror(fp)) {
        printf("File Error\n"); 
        break;
    }
}

// ferror() is inside feof() because it  checks for file error if feof() returns zero (no normal EOF). 
    



/* Example 1: This program copies any type of file, binary or text. It takes two command-line arguments. 
                        The first is the name of the source file
                        the second is the name of the destination file. 
            If the destination file does not exist, it is created. It includes full error checking. 
            (You might want to compare this version with the copy program you wrote for text files in the preceding section.) */

/* Copy a file. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
(
    FILE *from, *to;
    char ch;
    
    /* see if correct number of command line arguments */
    if (argc ! = 3) {
        printf("Usage: copy <source> <destination>\n");
        exit (1) ;
    }
    
    /* open source file */
    if((from = fopen(argv[l], "rb")==NULL)
        printf("Cannot open source file.\n");
        exit (1) ;
    )
    /* open destination file */
    if(to = fopen (argv [2], "wb")==NULL){
        printf("Cannot open destination file.\n");
        exit(1);
    )
    /* copy the file */
    
    while ( !feof (from) {
        ch = fgetc(from);
        if (ferror (from)) {
            printf("Error reading source file.\n");
            exit (1);
        }
        
        if (!feof (from)) fputc (ch, to);
        if(ferror(to)){
            printf("Error closing destination file.\n");
            exit(1);
        }
    }
    
    
    if(fclose(from)==EOF) (
        printf("Error closing source file.\n");
        exit(1);
    )
    
    
    if(fclose(to)==EOF){
        printf("Error closing destination file.\n");
        exit(1);
    }
    
    
    return 0;
}   
    

/* Copy a file. */
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
(
FILE *from, ·to;
char Chi
/* see if correct number of command line arguments * /
if (argc ! = 3) {
)
printf("Usage: copy <source> <destination>\n");
exi t (1) ;
/ * open source file * /
if{(from = fopen{argv[l]. "rb")::::::NULL)
printfC-Cannot open source file.\n");
exi t (1) ;
)
J * open destination file */
if«to = fopen (argv [2]' "wb"')==NULLI (
printf("Cannot open destination file.\n"j;
exit(1);
)
/* copy the file * j

while ( ! feof (from» {
ch = fgetc(from);
if Iferror I from)) (
)
)
printf(-Error reading source file.\nM);
exit (1);
if I! feof I from)) fputc Ich, to);
if(ferror(to)} (
)
printf(-Error writing dest~nation file.\n-);
exit(l);
if(fclose(from)==EOF) (
)
printf{-Error closing source file.\n·);
exit(1);
iflfcloseltoi==EOFi (
)
printf(-Error closing destination file.\nM);
exit(lJ;
return .0;
}



/* Example 2: This program compares the two files whose names are specified on the command line. 
                It either prints "Files are the same", or it displays the byte of the first mismatch. 
                It also uses full error checking. */

/* Compare files. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
(
    FILE *fp1, *fp2;
    char ch1, ch2, same;
    unsigned long l;
    
    /* see if correct number of command line arguments */
    if(argc!=3) {
        printf("Usage: compare <file 1> <file 2>\n");
        exit (1) ;
    }
    
    /* open first file */
    if((fp1 = fopen(argv[l], "rb"))==NULL} (
        printf("Cannot open first file.\n");
        exit(l);
    }
    
    /* open second file */
    if((fp2 = fopen(argv [2],"rb")==NULL) (
        printf("Cannot open second file.\n");
        exit(l);
    }
    
    l = 0;
    same = 1;
    /* compare the fi1es */
    while(!feof(fpl)){
        ch1 = fgetc(fp1);
        if (ferror ( fp1){
        printf ("Error reading first file.\n");
        exit(1);
        }
        ch2= fgetc(fp2);
        if (ferror ( fp2){
        printf ("Error reading second file.\n");
        exit(1);
        }
        
        if(chl!=ch2){
            printf("Files differ at byte number %lu", l);
            same = 0:
            break;
        }
        l++;
    }
    
        
    if (same) printf("Files are the same.\n");
    if(fclose(fpl)==EOF} (
        printf("Error closing first file.\n"):
        exit(1);
    }
    
    
    if (fclose(fp2)==EOF) {
        printf ("Error closing second file. \n");
        exit(1);
    }
    
    return 0;
}

'* Compare files. *j
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[t)
(
FILE *fpl, *fp2;
char chI. ch2, same;
unsigned long 1;
1* see if correct number of command line arguments */
if(argc!=3) {
printf(-Usage: compare <file 1> <file 2>\n-);
exit (1) ;
}
/* open first file *'
if((fpl = fopen(argv[lJ, "rb"}}=2NULL} (
printf("Cannot open first file.\n");
exit(l);
}
/* open second file *'
if((fp2 = fopen(argv [2]. "rb"»&=NULL) (
printf(-Cannot open second file.\n-);
exH (1) ;
}
1 = 0;
same '* compare = 1; the fi1es'*,
while(!feof(fpl» (
}
chl = fgetc(fpl);
if (ferror (fpl» (
printf '-Error
exit(l);
reading first file.\nW);
•
ch2 = fgetc(fp2);
if(ferror(fp2» (
}
printf(-Error reading second file.\n-);
exit(l) ;
if(chl!=ch2) .(
}
printf("Files differ at byte number 'lu", l);
same 'II: 0:
break;
1++;
if (same) printf("Files are the same.\n");
if(fclose(fpl)==EOF} (
}
printf(-Error closing first file.\ne):
exit(l):
if (fclose(fp2)==EOF) (
printf (-Error closiJ"".g second file. \n-) :
exit(l)
}
return 0;
}




/* Example 3: Write a program that counts the number of bytes in a file (text or binary) 
                and displays the result. Have the user specify the file to count on the command line. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    unsigned count;
    
    /* see if file name is specified */
    if(argc!=2){
        printf("File name missing.\n");
        exit (1);
    }
    
    // open  file
    if((fp = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1) ;
    }
    
    count = 0;
        
    while(!feof(fp)){
        fgetc(fp);
        if(ferror(fp))
        {
            printf("File error");
            exit(1);
        }
        count++;
    }
    
    
    printf("File has %u bytes", count-1);
    fclose(fp);
    
    return 0;
}







/* Example 4: (Swap the content betn files ) 
            Write a program that exchanges the contents of the two files whose names are specified on the command line. 
            That IS , given two files called FILE1 and FILE2, after the program has run ,
            FILE1 will contain the contents that originally were in FILE2,
            and FILE2 will contam FILE1 's original contents. 
            (Hint: Use a temporary file to aid in the exchange process. Works like a "temp" swap variable) */

// we will exchange two files
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *f1,*f2,*temp;
    char ch;
    
    /* see if correct line of command line arguments */
    if(argc!=3){
        printf("Usage: exchange <f1> <f2>.\n");
        exit (1);
    }
    
    // open first file
    if((f1 = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1) ;
    }
    
    // open second file
    if((f2 = fopen(argv[2], "r"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1) ;
    }
    
    // open temporary file
    if((temp = fopen("temp.tmp", "r"))==NULL) {
        printf("Cannot open temporary file.\n");
        exit(1) ;
    }
    
    /* copy f1 to temp */
    while (!feof(f1)){
        ch = fgetc(f1);
        if(!feof(f1)) fputc(ch, temp);
    }
    fclose(f1);
    
    // open first file for output
    if((f1 = fopen(argv[1], "wb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1) ;
    }
    
    /* copy f2 to f1 */
    while(!feof(f2)){
        ch = fgetc (f2) ;
        if(!feof(f2)) fputc(ch, f1);
    }
    fclose(f2);
    fclose(temp) ;
    
    // open second file for output
    if((f2 = fopen(argv[2], "wb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1) ;
    }
    
    // open temp file for input
    if((temp = fopen("temp.tmp", "rb"))==NULL) {
        printf("Cannot open temporary file.\n");
        exit(1) ;
    }
    
    // copy tmep to f2
    while(!feof(temp))
    {
        ch = fgetc(temp);
        if(!feof(temp))
            fputc(ch,f2);
    }
    
    fclose(f1);
    fclose(f2);
    fclose(temp);
    
    return 0;
}


