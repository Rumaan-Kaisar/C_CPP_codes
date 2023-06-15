/* 
    ----------------    Random access    ----------------

    write/read a file sequentially from its beginning to its end using:
            fgetc(), 
            fputc(), 
            fputs(), 
            fgets(), 
            fprintf(), 
            fscanf(), 
            fread() and 
            fwrite().


    fseek():
        Used to access a file randomly (i.e. any where/any point of a file ).
        The prototype of fseek() is

            int fseek(FILE *fp, long offset, int origin);

        returns 'zero' when 'successful'
        nonzero if a failure occurs.

        In most implementations, you may seek past the end of the file, 
            but you may never seek to a point before the start of the file.


        fp: 
            fp is associated with the file being accessed. 
        offset: 
            The value of "offset" determines the "number of bytes" from 'origin' to make the 'new current position'. 
        origin: 
            origin must be one of these "macros", shown here with their meanings:

                Origin	    Meaning

                SEEK_SET	Seek from start of file
                SEEK_CUR	Seek from current location
                SEEK_END	Seek from end of file

        These macros are defined in STDIO.H. 

        For example, if you wanted to set the 'current location' 100 bytes from the 'start of the file',  then 
            'origin' will be SEEK_SET and 
            'offset' will be 100.



    ftell():
        You can "determine" the CURRENT LOCATION of a file using ftell(). Its prototype:

            long ftell(FILE *fp);

        returns the "location" of the "current position" of the file associated with fp. 
        If a failure occurs, it returns -1.



    How you can "RANDOMLY ACCESS DATA OF ANY TYPE": 
        You simply need to "multiply" the "size of the base data type" by its 'index' in the file.



    NOTES:
        In general, use 'random access' only on 'binary files'. 
            Because text files may have character translations performed on them.
                there may not be a direct correspondence between file-content and the byte.

        The only time you should use fseek() with a "text file" is when seeking to a 
            position previously determined by ftell(), USing "SEEK_SET" as the "origin".

        text-file - can be opened as a binary file. 
            There is no inherent restriction about random access on files containing text. 
            The restriction applies only to files "opened as text files".
*/


// ///////  Review following =============



/* Example 1: The following program uses fseek() to report the value of any
                byte within the file specified on the command line. */

#include <stdio.h>
#include <stdlih.h>
int main(int argc, char *argv[])
(
)
long lOCi
FILE -fPi
/ * see if file name is specified */
H(argc!=2) (
)
print~{·File name missing.\n-);
exit(!) ;
if( (fp = fopen(argv(lJ , "rb"»==N1JLL) (
printf(-Cannot open file . \n~);
exitCl);
)
printf(~Enter byce to seek to: "I;
scanf("%ld~, &loc);
if ( f seek (fp, 10c, SEEK_SET» (
printf("Seek error. \ n~);
exi t (1) ;
)
printf("Va1ue at 10c 'ld is 'do, 10c, getc(fp);
fclose (fp) ;
returr. 0;



/* Example 2: Following uses ftell() and fseek() to copy the contents of one file into another in reverse order. 
                Pay special attention to how the END of the "input/read file" is found. 
                Since the program has sought to the EOF, the program "backs up one byte" so that 
                    the 'current location' of the file associated with in is at the 'last actual character' in the file. */

/* Copy a file in reverse order */
.include <stdio.h>
#include <stdlib.h>
iot main(int argc. char *argv[)

long loci
FILE • in, ·out;
char chi
/ * see if correct number of command line arguments */
if large! =3 l I
}
printf(-Usage: revcopy <source> <destination>.\n-);
exit(1);
ifllin = fopenlargv[l], "rb")}==NULL) (
printf(·Cannot open input file.\n·);
exit (1);
}
ifllout = fopen(argv[2], "",b"))==NULL) (
printf(-Cannot open output file.\n-);
exit(1) ;
}
I T find end of source file */
fseeklin, OL, SEEK_END);
lac = ftell(in);
1* copy file in reverse order *'
lac = lac-I; /* back up past end-af-file mark */
while Iloc >= OLl (
}
fseeklin, loc, SEEK_SET);
ch = fgetc(in);
fputc{ch. out);
loc--;
fclose(in) ;
fclose (out) ;
return 0;



/* Example 3: This program writes ten double values to disk. It then asks you which one you want to see. 
                This example shows: 
                    How you can "RANDOMLY ACCESS DATA OF ANY TYPE": 
                        You simply need to "multiply" the "size of the base data type" by its 'index' in the file. */
iinclude <stdio.h>
iinclude <stdlib.h>
double d[101 = {
},
10.23, 19.87, 1002.23, 12.9, 0.897,
11.45, 75.34, 0.0, 1.01, 875.875
int main(void}
{
}
long Icc;
double value;
FILE "'fp;
if«fp = fopen("myfile", "wb"))==NULL) {
printf ("Cannot open file. \n·) ;
exit(l) ,
}
/ * write the entire array in one step *'
H(fwrite(d, sizeof d, 1, fp} != 1) {
printf("Write error.\n"l i
exit (1);
fclose (fp) ,
if«fp = fopen("myfile", "rb"»==NULL) {
printf("Cannot open file.\n");
exit(l) ,
}
printf("Which element? .);
scanf("'ld", &loc),
if (fseek(fp, loc*sizeof(double) , SEEK-SET)) {
printf(·Seek error.\n");
exit(l) ,
}
fread(&value, sizeof(double) , 1, fp),
~rintf("Element 'ld is 'f", loc, value),
fclose(fp) ,
return 0;



Example 4: Write a program that uses fseek() to display every other byte
in a text file. (Remember, you must open the text file as a
binary file in order for fseek( ) to work properly.) Have the
user specify the file on the command line.
1. 'include <stdio.h>
.include <stdlib.h>
int mainlint argc. char *argv[])
(
FILE -fp;
char Chi
long 1;
if(argc!=2) (
}
printf(-You must specify the file.\n·);
exit(l);
if «fp = fopen(argv[l]. Orb") )== NULL) (
printf(-Cannot open file.\n-);
exit(1) ;
}
fseek(fp. O. SEEK_END); /. find' end of file ./
1 = ftell (fp);
/* go back to the start of the file */
fseek(fp. O. SEEK_SET);
for ( ; 1>=0; 1 = 1 - 2L) (
}
ch = fgetc (fp) ;
putchar (chi ;
fseek(fp. lL. SEEK_CUR);
fclose (fp) ;
return 0;
}



Example 5: Write a program that searches a file, specified on the command
line, for a specific integer value (also speCified on the command
line). If this value is found, have the program display its
location, in bytes, relative to the start of the file.

•include <stdio.h>
linclude <stdlib.h>
int main(int argc, char *argv[])
(
FILE *fp;
unsigned char ch, val;
if(argc!=3) {
}
prin-tf (·Usage: find <filename> <value>-);
exit(l) ;
if«fp = fopen(argv[l). "rb"))==NULL) (
printfC-Cannot open file.\n-);
exit (1);
}
val = atoi(argv[2}};
while ( ! feof (fp)) (
eh = fgete (fp);
if(eh == val)
printf("Found value at 'ld\n". ftell(fp));
}
felose(fp) ;
return 0:
}



