
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



/* Example 1: Using the feof() function, this code fragment shows how to read to the end of a file: */

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
    
