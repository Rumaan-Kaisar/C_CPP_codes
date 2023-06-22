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

    0L:
        Sometimes 0L is used
        0L is a long integer value with all the bits set to ZERO - that's generally the definition of 0.

        Note:   (~0L) is a long integer value with all the bits set to ONE according to TWO's complement.
                The "~" means to 'invert all the bits', which leaves you with a 'long integer' with all the bits set to one.

                The reason for using (~0L) instead of '-1L' is to be clearer about the intent - 
                    - it's not meant to be used as a number at all, but rather as a collection of bits

 


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




/* Example 1: The following program uses fseek() to report the value of any
                byte within the file specified on the command line. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    long loc;
    FILE *fp;

    // see if file name is specified
    if(argc!=2){
        printf("File name missing.\n");
        exit(1);
    }

    // open for reading the file
    if((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open file. \n");
        exit(1);
    }

    printf("Enter byte to seek to: ");
    scanf("%ld", &loc);
    if(fseek(fp, loc, SEEK_SET)){
        printf("Seek error. \n");
        exit(1);
    }

    printf("Value at loc %ld is %d", loc, getc(fp));
    fclose(fp);

    return 0;
}

// make the file name rand_io_1.c
// myFile_2 is a pre-existed file (there's text inside it)
// CLI commnads:
    // rand_io_1 myFile_2
    // Enter byte to seek to: 2
        // Value at loc 2 is 71




/* Example 2: Following uses ftell() and fseek() to copy the contents of one file into another in reverse order.
                Pay special attention to how the END of the "input/read file" is found.
                Since the program has sought to the EOF, the program "backs up one byte" so that
                    the 'current location' of the file associated with in is at the 'last actual character' in the file. */

// Copy a file in reverse order
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    long loc;
    FILE *in, *out;
    char ch;

    // see if correct number of command line arguments
    if(argc != 3){
        printf("Usage: revcopy <source> <destination>.\n");
        exit(1);
    }

    // open the first file for reding
    if((in = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open input file. \n");
        exit(1);
    }

    // open the second file for writing
    if((out = fopen(argv[2], "wb")) == NULL){
        printf("Cannot open input file. \n");
        exit(1);
    }


    // find end of source file
        // '0L' setes all bits to 0, its a long int, its besically defining the 0
    fseek(in, 0L, SEEK_END);
    loc = ftell(in);


    // copy file in reverse order
    loc = loc-1;    // back up past end-af-file EOF mark
    while(loc >= 0L) {
        fseek(in, loc, SEEK_SET);
        ch = fgetc(in);
        fputc(ch, out);
        loc--;
    }


    fclose(in) ;
    fclose(out) ;

    return 0;
}

// CLI commands
// rand_io_2 myFile_2 myfile




/* Example 3: This program writes ten double values to disk. It then asks you which one you want to see.
                This example shows:
                    How you can "RANDOMLY ACCESS DATA OF ANY TYPE":
                        You simply need to "multiply" the "size of the base data type" by its 'index' in the file. */
#include <stdio.h>
#include <stdlib.h>

double d[10] = {
        10.23, 19.87, 1002.23, 12.9, 0.897,
        11.45, 75.34, 0.0, 1.01, 875.875
    };

int main(void){
    long loc;
    double value;
    FILE *fp;

    // open the file for writing
    if((fp = fopen("myfile", "wb")) == NULL) {
        printf("Cannot open file. \n");
        exit(1);
    }

    // write the entire array in one step
    if(fwrite(d, sizeof d, 1, fp) != 1) {
        printf("Write error.\n");
        exit(1);
        }
    fclose(fp);

    // open the file for reading
    if((fp = fopen("myfile", "rb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    printf("Which element? ");
    scanf("%ld", &loc);
    // multiplying loc by size-of double
    if(fseek(fp, loc*sizeof(double), SEEK_SET)) {
        printf("Seek error.\n");
        exit(1);
    }

    fread(&value, sizeof(double), 1, fp);
    printf("Element %ld is %f", loc, value);
    fclose(fp);

    return 0;
}




/* Example 4: Write a program that uses fseek() to display every other byte in a text file.
                (Remember, you must open the text file as a binary file in order for fseek() to work properly.)
                Have the user specify the file on the command line. */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    long l;

    if(argc!=2){
        printf("You must specify the file.\n");
        exit(1);
    }

    // open file for reading
    if((fp = fopen(argv[1], "rb")) == NULL) {
        printf("Cannot open file.\n");
        exit(1) ;
    }

    fseek(fp, 0, SEEK_END);     // find end of file
    l = ftell (fp);     // determine the current location

    // go back to the start of the file
    fseek(fp, 0, SEEK_SET);
    for( ; l>=0; l=l-2L){
        // 2L defines 2 as a long.
        ch = fgetc(fp);
        putchar(ch);
        fseek(fp, 1L, SEEK_CUR);
    }


    fclose(fp);

    // what is "2L"?
    printf("\n\n\t %ld \n", 2L);
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


