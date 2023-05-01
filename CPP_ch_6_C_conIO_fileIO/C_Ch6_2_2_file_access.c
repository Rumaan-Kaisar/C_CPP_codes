6.9 File access using fopen(), fclose() and read/write using fgetc(), fputc() 
Opening a file : To open a file and associate it with a stream, use fopen() it uses  STDIO.H. Its prototype is shown here:

FILE *fopen(char *fname, char *mode); 

Generally we use the following form 

FILE *file_pointer;
file_pointer=fopen("file_name", "mode");

IN the prototype the name of the file to open is pointed to by fname. It must be a valid file name, as defined by the operating system. The string pointed to by mode determines how the file may be accessed. ANSI C standard values for mode are shown in Table. 
	The type FILE is defined in STDIO.H. It is a structure that holds various kinds of information about the file, such as its size, the current location of the file, and its access modes. It essentially identifies the file. (A structure is a group of variables accessed under one name.)

	If the open operation is successful, fopen() returns a valid file pointer.  The fopen() function returns a pointer to the structure associated with the file by the open process. This pointer will be used with all other functions that operate on the file. It can't be altered or the object it points to.

	If the fopen( ) function fails, it returns a null pointer. The header STDlO.H defines the macro NULL, which is defined to be a null pointer. It is very important to ensure that a valid file pointer has been returned. To do so, check the value returned by fopen( ) (using condition) to make sure that it is not NULL. for example, the proper way to open a file called my file for text input :

FILE *fp;
if( (fp = fopen("myfile", "r")) == NULL){ 
printf(“Error opening file.\n");
exit(1); /* or substitute your own error handler */ }

what actually happening here(CONFUSED !!!) : Here not only the "file error checking " happening inside the condition of "if" statement but also file is opened (if it exists) simultaneously. It is actually equivalent to

fp=fopen("myfile", "r"); /*file opening */
if(fp===NULL){ /*file error checking*/
printf("file error\n");
exit(1); /* less effect of exit() : file error occurs before the conditional statement*/}

There is no need for a separate comparison step because the assignment and the comparison can be performed at the same time within the if .

	In this case there is no point of using exit(), after the file error occurred.
	To prevent error of file opening if the file doesn't exist, the fopen() should occur inside the  "if" statement. The whole program will exit (shuts down)  if the file doesn't exist using exit(1) against the "NULL" condition. And no error occurs during file closing (fclose()) or any crash. 
	Inside the "if" condition the file is opened simultaneously during the "file error checking". But once the file is opened it never close until fclose appeared to corresponding file pointer.
	The point of using exit() is that when the proper condition occurs for exit(1) the program will shuts down immediately by returning 0 to the operating system. Her the point of using exit() is that : fclose() creates system error if its pointer argument is invalid on a null-pointer. Hence when a null-pointer occurs during file operation the program will shuts down.   

Mode	Meaning	Mode	Meaning
"r"	Open a text file for reading	"r+"	Open a text file for read/write
"w"	Create a text file for writing	"w+"	Create a text file for read/write
"a"	Append(means : edit/add) to a text file	"a+"	Append /create a text file for read/write
"rb"	Open a binary file for reading	"r+b" or "rb+"	Open a binary file for read/write. Also can use "rb+"
"wb"	Create a binary file for writing	"w+b" or "wb+"	Create a binary file for read/write. Also can use "wb+"
"ab"	Append to a binary file	"a+b" or "ab+"	Append/create a binary file for read/write. Also can use "ab+"

Although most of the file modes are self-explanatory, a few comments are in order :
[1]	"r": when opening a file for read-only operations, the file does not exist, fopen() will fail and NULL-pointer will return.
[2]	"a": When opening a file using append mode, if the file does not exist, it will be created. Further, when a file is opened for append all new data written to the file will be written to the end of the file. The original contents will remain unchanged. 
[3]	"w": If, when a file is opened for writing, the file does not exist, it will be created. If it does exist, the contents of the original file will be destroyed and a new file created. 
[4]	"r+": It is similar to "r", "r+" will not create a file if it does not exist. It can both read-write.
[5]	"a+": It is similar to "a", moreover we can read with this mode. IT can both read-append. 
[6]	"w+": similar to "w". It can both read-write. Seems like "r+" & "w+" are same , but there are few differences. 
[7]	Difference between "r+" & "w+": The difference between modes "r+" and "w+" is that "r+" will not create a file if it does not exist; however, "w+" will. Further, if the file already exists, opening it with "w+" destroys its contents; opening it with "r+" does not.
Note : For general purpose use only "r+" and "a+" for read-write-append but be careful using "w"/"w+"

Opening a file : To close a file and disassociate it with a stream, use fclose() it uses  STDIO.H. Its prototype is shown here:

int fclose(FILE *fp);

The fclose() function closes the file associated with fp, which must be a valid file pointer previously obtained using fopen(), and disassociates the stream from the file. 

	Be carefull with using fclose() : You must never call fclose() with an invalid argument. Doing so will damage the file system and possibly cause irretrievable data loss. Invalid arguments means : you cannot use fclose() with null or empty file pointer or invalid-error causing file pointer (i.e. can't use null-pointer ). Never use fclose before fopen with corresponding file.
	The fclose() function returns zero if successful. If an error occurs, EOF is returned.
	Flushing the buffer : In order to improve efficiency, most file system implementations write data to disk one sector at a time. Therefore, data is buffered until a sector's worth of information has been output before the buffer is physically written to disk. When you call fclose(), it automatically writes any information remaining in a partially full buffer to disk. This is often referred to as flushing the buffer.

Reading and Writing from/to a files : Once a file has been opened, depending upon its mode, you may read and/or write bytes (i.e., characters) using these two functions:

int fgetc(FILE *fp);
int fputc(int ch, FILE *fp);
	fgetc() : The fgetc() function reads the next byte from the file described by fp as an unsigned char and returns it as an integer. (The character is returned in the low-order byte.) If an error occurs, fgetc() returns EOF (int type EOF=-1).  The fgetc() function also returns EOF (i.e -1) when the end of the file is reached. Although fgetc() returns an integer value, your program can assign it to a char variable since the low-order byte contains the character read from the file.
	fputc() : The fputc() function writes the byte contained in the low-order byte of ch to the file associated with fp as an unsigned char. Although ch is defined as an int, you may cal1 it using a char, which is the common procedure. The fputc() function returns the character written if successful or EOF if an error occurs.

Historical note
The traditional names for fgetc() and fputc() are getc ) and putc(). The ANSI C standard still defines these names, and they are essential1y interchangeable with fgetc() and fputc(). One reason the new names were added was for consistency. Al1 other ANSI file system function names begin with "f": so "f" was added to getc() and putc(). 

Example :  writing and reading a file.
#include<stdio.h>
#include<stdlib.h>
int main(void){char str[80]="Yo babbay. Fuck the file sys!! Aye?";
FILE *f_point;
char *p;
int i;
/*open the file for output*/
if((f_point=fopen("myfile", "w"))==NULL){printf("File-Error\n"); exit(1);}
/*write into the file*/
p=str;
while(*p){if((fputc(*p, f_point)==EOF)){printf("Write-Error\n"); exit(1);}
    			p++; }
fclose(f_point);
/*Open the file for the input*/
if((f_point=fopen("myfile", "r"))==NULL){printf("Opening-Error"); exit(1);}
/*read from file and output*/
for(;;){i=fgetc(f_point);
           		if(i==EOF) break;
            		putchar(i);}
fclose(f_point);
return 0;}

	However while(*p){if((fputc(*p, f_point)==EOF)){printf("Write-Error\n"); exit(1);} p++; } can be written as :
while(*p) if((fputc(*p++, f_point)==EOF)){printf("Write-Error\n"); exit(1);} 
this is the ability of integrating operations, it makes C most powerful.

	In this version, when reading from the file, the return value of fgetc() is assigned to an integer variable called i
for(;;){i=fgetc(f_point); if(i==EOF) break; putchar(i);}
The value of this integer is then checked to see if the end of the file has been reached.
For most compilers, however, you can simply assign the value returned by fgetc() to a char and still check for EOF, as shown in the following fragment:
Char ch;
for(;;){ch=fgetc(f_point); if(ch==EOF) break; putchar(i);}
The reason this approach works is that when a char is being compared to an int (the EOF , which is -1), the char value is automatically elevated to an equivalent int value.

	There is no need for a separate comparison step because the assignment and the comparison can be performed at the same time within the if (Exactly what we did before for opening and closing a file), as shown here:

for(;;) { if((ch = fgetc(f_point)) == EOF) break; putchar(ch); }

Don't let the statement if((ch = fgetc(f_point)) == EOF) fool you. Here’s what is happening. First, inside the if, the return value of fgetc() is assigned to ch. As you may recall, the assignment operation in C is an expression. The entire value of (ch = fgetc(fp)) is equal to the return value of fgetc( ). Therefore, it is this integer value that is tested against EOF.

	those fragments written by a professional C programmer as follows:

while((ch = fgetc(f_point)) != EOF) putchar(ch);

Notice that now, each character is read, assigned to ch, and tested against EOF, all within the expression of the while loop that controls the input process. If you compare this with the original version, you can see how much more efficient this one is. In fact, the ability to integrate such operations is one reason C is so powerful. Later  we will explore such assignment statements more fully.
