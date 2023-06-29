
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
                        The first is the "name of the SOURCE FILE"
                        the second is the "name of the DESTINATION FILE". 
            If the DESTINATION file does not exist, it is CREATED. It includes full error checking. 
            (You might want to compare this version with the copy program you wrote for text files in the preceding section.) 
*/
// Copy a file.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *from, *to;
    char ch;
    
    // see if correct number of command line arguments (CLI arg)
    if (argc != 3) {
        printf("Usage: copy <source> <destination>\n");
        exit (1);
    }
    
    // open source file 
    if((from = fopen(argv[1], "rb"))==NULL){
        printf("Cannot open source file.\n");
        exit(1) ;
    }

    // open destination file
    if((to = fopen(argv[2], "wb"))==NULL){
        printf("Cannot open destination file.\n");
        exit(1);
    }


    // copy the file
    while( !feof(from) ) {
        ch = fgetc(from);
        if(ferror(from)) {
            printf("Error reading source file.\n");
            exit(1);
        }
        
        if(!feof(from)) fputc(ch, to);
        if(ferror(to)){
            printf("Error writing destination file.\n");
            exit(1);
        }
    }
    
    
    // closing the files
    if(fclose(from)==EOF) {
        printf("Error closing source file.\n");
        exit(1);
    }
    
    if(fclose(to)==EOF){
        printf("Error closing destination file.\n");
        exit(1);
    }
    
    
    return 0;
}   
// name this code-file "FL_IO_7cpy.c" then open CLI inside working folder, run following code in CLI
// FL_IO_7cpy myfile fileio_cpy    




/* Example 2: This program compares the two files whose names are specified on the command line.
                It either prints "Files are the same", or it displays the byte of the first mismatch.
                It also uses full error checking. */

// Compare files.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp1, *fp2;
    char ch1, ch2, same;
    unsigned long l;

    // see if correct number of command line arguments
    if(argc!=3) {
        printf("Usage: compare <file 1> <file 2>\n");
        exit(1);
    }

    // open first file
    if((fp1 = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1);
    }

    // open second file
    if((fp2 = fopen(argv[2], "rb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1);
    }


    l = 0;
    same = 1;

    // compare the fi1es
    while(!feof(fp1)){

        ch1 = fgetc(fp1);
        if(ferror(fp1)){
            printf("Error reading first file.\n");
            exit(1);
        }

        ch2 = fgetc(fp2);
        if(ferror(fp2)){
            printf("Error reading second file.\n");
            exit(1);
        }

        if(ch1!=ch2){
            printf("Files differ at byte number %lu", l);
            same = 0;
            break;
        }

        l++;
    }


    if(same) printf("Files are the same.\n");


    // closing the files
    if(fclose(fp1)==EOF) {
        printf("Error closing first file. \n");
        exit(1);
    }

    if(fclose(fp2)==EOF) {
        printf("Error closing second file. \n");
        exit(1);
    }

    return 0;
}
// name this code-file "FL_IO_8cmpr.c" then open CLI inside working folder, run following code in CLI
// FL_IO_8cmpr myfile fileio_cpy




/* Example 3: Write a program that counts the number of bytes in a file (text or binary)
                and displays the result. Have the user specify the file to count on the command line. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    unsigned count;

    // see if file name is specified
    if(argc!=2){
        printf("File name missing.\n");
        exit(1);
    }

    // open  file
    // if((fp = fopen(argv[1], "rb"))==NULL) {
    if((fp = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1) ;
    }


    // count the bites
    count = 0;

    while(!feof(fp)){
        fgetc(fp);
        if(ferror(fp)){
            printf("File error");
            exit(1);
        }
        count++;
    }

    // we minus 1 because of EOF is also counted
    printf("File has %u bytes", count-1);
    fclose(fp);

    return 0;
}
// name the file "FL_IO_9bytcount.c"
//FL_IO_9bytcount swap_2




/* Example 4: (Swap / EXCHANGE the content betn files ) 
            Write a program that exchanges the contents of the two files whose names are specified on the command line. 
            That IS , given two files called FILE1 and FILE2, after the program has run ,
            FILE1 will contain the contents that originally were in FILE2,
            and FILE2 will contain FILE1 's original contents. 
            (Hint: Use a temporary file to aid in the exchange process. Works like a "temp" swap variable) 

Notice the usage of "rb" for READING and "wb" for WRITING            
*/

//  EXCHANGE two files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *f1,*f2,*temp;
    char ch;
    
    // see if correct line of command line arguments 
    if(argc!=3){
        printf("Usage: exchange <f1> <f2>.\n");
        exit(1);
    }
    
    // open first file for reading
    if((f1 = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1) ;
    }
    
    // open second file for reading
    if((f2 = fopen(argv[2], "rb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1) ;
    }
    

    // open temporary file for writing
    // following creates a Temporary file "temp.tmp"
    // if((temp = fopen("temp.tmp", "wb"))==NULL) {
    //     printf("Cannot open temporary file.\n");
    //     exit(1) ;
    // }

    // use this if you already have "temp" file
    if((temp = fopen("temp", "wb"))==NULL) {
        printf("Cannot open temporary file.\n");
        exit(1) ;
    }

    
    // copy f1 to temp 
    while(!feof(f1)){
        ch = fgetc(f1);
        if(!feof(f1)) fputc(ch, temp);
    }
    fclose(f1);
    

    // open first file for output/writing
    if((f1 = fopen(argv[1], "wb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1) ;
    }
    
    // copy f2 to f1
    while(!feof(f2)){
        ch = fgetc (f2) ;
        if(!feof(f2)) fputc(ch, f1);
    }
    fclose(f2);
    fclose(temp) ;
    
    // open second file for output/writing
    if((f2 = fopen(argv[2], "wb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1) ;
    }
    
    // open temp file for input/reading
    // if((temp = fopen("temp.tmp", "rb"))==NULL) {
    //     printf("Cannot open temporary file.\n");
    //     exit(1) ;
    // }
    // use this if you already have "temp" file
    if((temp = fopen("temp", "rb"))==NULL) {
        printf("Cannot open temporary file.\n");
        exit(1) ;
    }
    
    // copy tmep to f2
    while(!feof(temp))
    {
        ch = fgetc(temp);
        if(!feof(temp)) fputc(ch,f2);
    }
    
    fclose(f1);
    fclose(f2);
    fclose(temp);
    
    return 0;
}
// name this file "FL_IO_10swap.c"
// FL_IO_10swap swap_1 swap_2



// Version 2: In follwing version dont need to create "temp" file manually
//  EXCHANGE two files
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *f1,*f2,*temp;
    char ch;
    
    // see if correct line of command line arguments 
    if(argc!=3){
        printf("Usage: exchange <f1> <f2>.\n");
        exit(1);
    }
    
    // open first file for READING
    if((f1 = fopen(argv[1], "rb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1) ;
    }
    
    // open second file for READING
    if((f2 = fopen(argv[2], "rb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1) ;
    }
    
    // open temporary file for WRITING
    // following creates a Temporary file "temp.tmp"
    if((temp = fopen("temp.tmp", "wb"))==NULL) {
        printf("Cannot open temporary file.\n");
        exit(1) ;
    }


    // copy f1 to temp 
    while(!feof(f1)){
        ch = fgetc(f1);
        if(!feof(f1)) fputc(ch, temp);
    }
    
    fclose(f1);     // close first file (after reading)
    

    // open first file (again) for OUTPUT/WRITING
    if((f1 = fopen(argv[1], "wb"))==NULL) {
        printf("Cannot open first file.\n");
        exit(1) ;
    }
    
    // copy f2 to f1
    while(!feof(f2)){
        ch = fgetc (f2) ;
        if(!feof(f2)) fputc(ch, f1);
    }

    fclose(f2);     // close second file (after reading)
    fclose(temp) ;  // close temp file (after writing)
    

    // open second file (again) for OUTPUT/WRITING
    if((f2 = fopen(argv[2], "wb"))==NULL) {
        printf("Cannot open second file.\n");
        exit(1) ;
    }
    
    // open temp file (again) for INPUT/READING
    if((temp = fopen("temp.tmp", "rb"))==NULL) {
        printf("Cannot open temporary file.\n");
        exit(1) ;
    }
    

    // copy tmep to f2
    while(!feof(temp)){
        ch = fgetc(temp);
        if(!feof(temp)) fputc(ch,f2);
    }
    
    fclose(f1);     // close first file
    fclose(f2);     // close second file
    fclose(temp);   // close temp file (after reading)
    
    return 0;
}
// name this file "FL_IO_10swap_2.c"
// FL_IO_10swap_2 swap_1 swap_2

// Note: notice the usage of "rb" for READING and "wb" for WRITING




/* Example 5: Write a program that displays the contents of a text file (specified on the command line), one line at a time.
                After each line is displayed, ask the user ifhe or she wants to sec another line. */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char str[80];

    // see if file name is specified
    if(argc != 2){
        printf("File name missing. \n");
        exit(1);
    }

    // open file for reading
    if((fp = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open file.\n");
        exit(1);
    }

    while(!feof(fp)){
        fgets (str, 79, fp);
        if(!feof(fp)) printf("%s", str);

        printf("... More? (y/n)");
        if(toupper(getchar())=='N') break;
        printf ("\n");
    }


    fclose(fp);

    return 0;
}
// FL_IO_ms1 fl_1


