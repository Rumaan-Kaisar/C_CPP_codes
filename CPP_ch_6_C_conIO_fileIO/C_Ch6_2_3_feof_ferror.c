6.10 End of file [EOF] feof() And file error checking ferror()
As you know, when fgetc() returns EOF, 
[1]	either an error has occurred 
[2]	or the end of the file has been reached , 
but how do you know which event has taken place? Further if you are operating on a binary file, all values are valid. This means it is possible that a byte will have the same value (when elevated to an int) as EOF, so how do you know if valid data has been returned or if the end of the file has been reached?

The solution to these problems are the functions feof() and ferror(), whose prototypes are shown here:

int feof(FILE *fp);
int ferror(FILE *fp);

feof() : The feof( ) function returns nonzero if the file associated with fp has reached the end of the file [literally End-Of-File]. Otherwise it returns zero. This function works for both binary files and text files. 

ferror() : The ferror() function returns nonzero if the file associated with fp has experienced an error. Otherwise, it returns zero.

Using the feof() function, this code fragment shows how to read to the end of a file:

FILE *fp;
. . . 
while(!feof(fp))ch = fgetc(fp);

This code works for any type of file and is better in general than checking for EOF. However, it still does not provide any error checking. Error checking is added here:
FILE *fp;
. . . 
. . .
while(!feof(fp)) {	ch = fgetc(fp); 
if(ferror(fp)) {printf("File Error\n"); break;}
}
ferror is inside feof because it  checks for file error if feof returns zero. Here it works like, fgetc works until end-of-file is reached and during all time ferror works inside the while. (confused). 

Note
	Keep in mind that ferror() only reports the status of the file system relative to the last file access. Therefore, to provide the fullest error checking, you must call it after each file operation.
	Often the only types of errors that actually get passed back to your program are those caused by mistakes on your part, such as accessing a file in a way inconsistent with the mode used to open it or when you cause an out-of-range condition. Usually these types of errors can be trapped by checking the return type of the other file system functions rather than by calling ferror(). For this reason, you will frequently see examples of C code in which there are relatively few (if any) calls to ferror(). 
