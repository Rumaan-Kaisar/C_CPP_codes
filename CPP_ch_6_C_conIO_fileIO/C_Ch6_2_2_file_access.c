

/* 
    ----------------------    File Access & Modify    ----------------------

                File access: 
                    using fopen(), fclose() and 

                File read/write:
                    using fgetc(), fputc() 



    ----------------------    OPEN a File    ----------------------
    fopen():
        Opening a file: To open a file and associate it with a stream, use fopen() it uses  <STDIO.H>. Its prototype:

                FILE *fopen(char *fname, char *mode); 

                    Here "FILE" is a Structure (data-type). It is defined in STDIO.H
                        It holds various information about the file, such as size, current location, access modes. 
                        It essentially identifies the file. (A structure is a group of variables accessed under one name.)

        Generally we use the following form 

                FILE *file_pointer;
                file_pointer = fopen("file_name", "mode");

        IN the prototype, the name of the file to open is pointed to by "fname". It must be a valid file name, as defined by the operating system. 
        The string pointed to by "mode" determines how the file may be accessed. 


        If the open operation is successful, fopen() returns a valid file pointer.
            fopen() returns a pointer to the structure associated with the file by the open process. 
            This pointer will be used with all other functions that operate on the file. 

        If the fopen() function fails, it returns a null pointer.



    ----------------------    Always check the NULL pointer    ----------------------
        It is very important to ensure that a valid file pointer has been returned. 
        Use a condition to make sure that it is not NULL. 
        
    The proper way to open a file called "myfile" for text input :

            FILE *fp;
            if( (fp = fopen("myfile", "r") ) == NULL){ 
                printf("Error opening file.\n");
                exit(1); // or substitute your own error handler 
            }

    Here not only the "file error checking " happening inside the condition of "if" statement but also file is opened (if it exists) simultaneously. 
    It is actually equivalent to

            FILE *fp;
            fp=fopen("myfile", "r"); // file opening
            if(fp===NULL){      // file error checkin
                printf("file error\n");
                exit(1);        //  less effect of exit() : file error occurs before the conditional statement
            }

            There is no point of using exit(), after the file error occurred.
            There is no need for a separate comparison step because the assignment and the comparison can be performed at the same time within the if .




    ----------------------    Why use fopen() inside an if    ----------------------
        In the later case there is no point of using exit(), after the file error occurred.
        
        To prevent error of file opening if the file doesn't exist, the fopen() should occur inside the  "if" statement. 
            The program will stop if the file doesn't exist using exit(1) against the "NULL" condition. 
            And no error occurs during file closing (fclose()) or any crash. 

    Once the file is opened it never close until "fclose()" appeared to corresponding 'file pointer'.

    The point of using exit() is that: fclose() creates system error if its pointer argument is invalid on a null-pointer.




    ----------------------    CLOSING a File    ----------------------

    Closing a file : 
        To close a file and disassociate it with a stream, use fclose() it uses  STDIO.H. Its prototype is shown here:

                int fclose(FILE *fp);

        The fclose() function closes the file associated with "fp", which 
            must be a "valid file pointer" previously obtained using fopen(), and disassociates the stream from the file. 
            
        The fclose() function returns zero if successful. If an error occurs, EOF is returned.


        Be carefull with using fclose() : 
            NEVER call fclose() with an invalid argument. Doing so will "DAMAGE THE FILE SYSTEM" and possibly cause irretrievable "DATA LOSS".
            Invalid arguments means : you cannot use fclose() with "NULL OR EMPTY FILE POINTER" or invalid-error causing file pointer 
            NEVER use fclose before fopen with corresponding file.





    ----------------------    ANSI C standard values for mode are shown in Table.    ----------------------

                "r"     Open a text file for 'reading'	
                "r+"    Open a text file for 'read/write'
                "w"     Create a text file for 'writing'	
                "w+"	Create a text file for 'read/write'
                "a"     Append(means : edit/add) to a text file	
                "a+"	Append /create a text file for 'read/write'

                "rb"	Open a binary file for reading	
                "r+b" or "rb+"	Open a binary file for read/write. Also can use "rb+"

                "wb"	Create a binary file for writing	
                "w+b" or "wb+"	Create a binary file for read/write. Also can use "wb+"

                "ab"	Append to a binary file	
                "a+b" or "ab+"	Append/create a binary file for read/write. Also can use "ab+"


    Although most of the file modes are self-explanatory, a few comments are in order :
    [1]	"r": when opening a file for 'read-only' operations, the FILE DOES NOT EXIST, fopen() will "fail" and NULL-pointer will return.

    [2]	"a": When opening a file using append mode, if the FILE DOES NOT EXIST, it will be "created". 
                Further, append all new data written to the file, and will be written to the EOF. 
                The original contents will remain unchanged. 
            SAFE to use.

    [3]	"w": If, when a file is opened for writing, the FILE DOES NOT EXIST, it will be created. 
                If it does exist, the contents of the ORIGINAL FILE WILL BE DESTROYED and a new file created.
            Unsafe.

    [4]	"r+": It is similar to "r", "r+" will not create a file if it does not exist. 
                It can both read-write.

    [5]	"a+": It is similar to "a", moreover we can read with this mode. 
                IT can both read-append. 

    [6]	"w+": similar to "w". It can both read-write. Seems like "r+" & "w+" are same , but there are few differences. 
                Difference between "r+" & "w+": "r+" will not create a file if it does not exist; however, "w+" will. 
                Further, if the file already exists, opening it with "w+" destroys its contents (unsafe); opening it with "r+" does not (safe).


    Note: 
        For GENERAL PURPOSE use only "r+" and "a+" for 'read/write/append' but be careful using "w"/"w+".




    ----------------------    Flushing the buffer    ----------------------

        In order to improve efficiency, most file system implementations write data to disk one sector at a time.
            Therefore, data is buffered until it is physically written to disk. 
            When you call fclose(), it automatically writes any information remaining in a "partially full buffer" to disk. 




    ----------------------    fgetc, fputc : file Read/Write    ----------------------

    Reading and Writing from/to a files : 
    Once a file has been "opened", depending upon its "mode", you may read and/or write bytes (or characters) using these two functions:

                int fgetc(FILE *fp);
                int fputc(int ch, FILE *fp);


    fgetc() : 
        The fgetc() function "reads the NEXT byte" from the file described by "fp" as an "unsigned char" and returns it as an "integer". 
                (The character is returned in the low-order byte.) 
        If an error occurs, fgetc() returns EOF (int type EOF=-1).  
        fgetc() also returns EOF (i.e -1) when the "END OF THE FILE" is reached. 
        
        Although fgetc() returns 'integer', your can assign it to a "char" since the 'low-order byte' contains the character read from the file.



    fputc() : 
        The fputc() function 'writes' the byte contained in the "low-order byte" of 'ch' to the file associated with 'fp' as an "unsigned char". 
            Although ch is defined as an int, you may cal1 it using a char, which is the common procedure. 
        
        The fputc() returns the character written if successful or EOF if an error occurs.



    Historical note:
        The traditional names for fgetc() and fputc() are getc() and putc(). 
        The ANSI C standard still defines these names, and they are essential1y interchangeable with fgetc() and fputc().
        All other ANSI 'file system function names' begin with "f": so "f" was added to getc() and putc().         
*/




/* Example 1.1:  writing and reading a file. 
                This program demonstrates the four file-system functions.
                    First, it opens a file called MYFILE for output. 
                    Next, it writes the string "OMG!! Whatz goin on?" to the file. 
                    Then, it closes the file and 
                    reopens it for read operations. 
                    Finally, it displays the contents of the file on the screen and 
                    closes the file.
*/
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char str[80]="OMG!! Whatz goin on?";

    FILE *f_point;
    char *p;
    int i;

    // open the file for output, w - creartes a file
    if((f_point=fopen("myfile", "w"))==NULL){
        printf("File-Error\n"); 
        exit(1);
    }

    // write str into the file/disc
    p = str;
    while(*p){
        if((fputc(*p, f_point)==EOF)){
            printf("Write-Error\n"); 
            exit(1);
        }
    	p++; 
    }

    // closing the file after writing
    fclose(f_point);


    // Open the file for the input
    if((f_point=fopen("myfile", "r"))==NULL){
        printf("Opening-Error"); 
        exit(1);
    }

    // read back the file
    for(;;){
        i=fgetc(f_point);
        if(i==EOF) break;
        putchar(i);
        }
    fclose(f_point); // close the file aftre done reading

    return 0;
}

/* 
    Notes:
        while(*p){if((fputc(*p, f_point)==EOF)){printf("Write-Error\n"); exit(1);} p++; } 
        
        can be written as follows: using "p++" inside fputc()
            while(*p) if((fputc(*p++, f_point)==EOF)){printf("Write-Error\n"); exit(1);} 



    In this version, when reading from the file, the return value of fgetc() is assigned to an 'integer' variable called 'i'
        for(;;){i=fgetc(f_point); if(i==EOF) break; putchar(i);}



    For most compilers, you can simply assign the value returned by fgetc() to a char and still check for EOF: as following
        Char ch;
        for(;;){ch=fgetc(f_point); if(ch==EOF) break; putchar(i);}

        when a char is being compared to an int (the EOF , which is -1), the "char" is automatically ELEVATED to  "int"



    There is no need for a separate comparison step because the "assignment" and the "comparison" can be performed at the same time within the "if"
        for(;;) { if((ch = fgetc(f_point)) == EOF) break; putchar(ch); }

    Don't let the statement if((ch = fgetc(f_point)) == EOF) fool you.
        First, inside the if, the return value of 'fgetc()' is assigned to "ch". As you may recall, the assignment operation in C is an expression. 
        The entire value of (ch = fgetc(fp)) is equal to the return value of fgetc(). Therefore, it is this integer value that is tested against EOF.

        The fragment 

            for(;;) { if((ch = fgetc(f_point)) == EOF) break; putchar(ch); } 

            written by a "PROFESSIONAL C PROGRAMMER" as follows:

                while((ch = fgetc(f_point)) != EOF) putchar(ch);

        each character is read, assigned to ch, and tested against EOF, all within the expression of the "while" loop. 
*/
    
    


/* Example 1.2: For most compilers, you can simply assign the value returned by fgetc() to a char and still check for EOF: as following */
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char str[80]="OMG!! Whatz goin on?";

    FILE *f_point;
    char *p;
    char ch;

    // open the file for output, w - creartes a file
    if((f_point=fopen("myfile", "w"))==NULL){
        printf("File-Error\n"); 
        exit(1);
    }

    // write str into the file/disc
    p = str;
    while(*p){
        if((fputc(*p, f_point)==EOF)){
            printf("Write-Error\n"); 
            exit(1);
        }
    	p++; 
    }

    // closing the file after writing
    fclose(f_point);


    // Open the file for the input
    if((f_point=fopen("myfile", "r"))==NULL){
        printf("Opening-Error"); 
        exit(1);
    }

    // read back the file
        // using "char ch" instead of "int i"
    for(;;){
        // i=fgetc(f_point);
        // if(i==EOF) break;
        // putchar(i);
        ch = fgetc(f_point);
        if(ch == EOF) break;
        putchar(ch);
        }
    fclose(f_point); // close the file aftre done reading

    return 0;
}

/* 
There is no need for a separate comparison step because the "assignment" and the "comparison" can be performed at the same time within the "if"
    for(;;){ 
        if((ch = fgetc(f_point)) == EOF) break; 
        putchar(ch); 
    }

It can be written as more professionally:
    while((ch = fgetc(f_point)) != EOF) putchar(ch); 

*/




/* Example 1.3: The more PROFESSIONAL version */
#include<stdio.h>
#include<stdlib.h>

int main(void){
    char str[80]="OMG!! Whatz goin on?";

    FILE *f_point;
    char *p;
    char ch;

    // open the file for output, w - creartes a file
    if((f_point=fopen("myFile_2", "w"))==NULL){
        printf("File-Error\n");
        exit(1);
    }

    // write str into the file/disc: Notice increment p++ is inside "if"
    p = str;
    while(*p){
        if((fputc(*p++, f_point)==EOF)){
            printf("Write-Error\n");
            exit(1);
        }
    }

    // closing the file after writing
    fclose(f_point);


    // Open the file for the input
    if((f_point=fopen("myFile_2", "r"))==NULL){
        printf("Opening-Error");
        exit(1);
    }

    // read back the file
        // using "char ch" instead of "int i"
    while((ch = fgetc(f_point)) != EOF) putchar(ch);
    fclose(f_point); // close the file aftre done reading

    return 0;
}




/* Example 2: The following program takes two command-line arguments. 
                    The first is the name of a file, 
                    the second is a character. 
            The program searches the specified file, looking for the character. 
            If the file contains at least one of these characters, it reports this fact.
            Notice how it uses argv to access the file name and the character for which to search. */

// Search specified file for specified character. 
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    
    // see if correct number of command line arguments 
    if(argc!=3) {
        printf("Usage: find <file name> <ch>\n");
        exit(1) ;
    }
    
    // open file for input
    if( (fp = fopen(argv[1], "r") )==NULL){
        printf("Cannot open file.\n");
        exit(1) ;
    }
    
    // look for character 
    while( (ch = fgetc(fp)) != EOF)
    if (ch==*argv[2]) {
        printf("%c found", ch);
        break;
    }
    
    fclose(fp) ;
    
    return 0;
}
// E:\1_Development_2.0\C_Cpp_codes\raw_test>FL_IO_3 myfile M
// M found




/* Example 3: Write a program that displays the contents of the text file
                specified on the command line. */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;

    // see if filename is specified
    if(argc!=2){
        printf("File name is missing.\n");
        exit(1);
    }


    if((fp = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1) ;
    }

    while((ch=fgetc(fp)) != EOF) putchar(ch);

    fclose(fp) ;

    return 0;
}
// E:\1_Development_2.0\C_Cpp_codes\raw_test>FL_IO_4 myfile
// OMG!! Whatz goin on?




/* Example 4: Write a program that reads a text file and counts how many
                times each letter from 'A' to 'Z' occurs. Have it display the results.
                (Do not differentiate between upper- and lowercase letters.) */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int count[26];

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    int i;

    // see if filename is specified
    if(argc!=2){
        printf("File name is missing.\n");
        exit(1);
    }


    if((fp = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open file.\n");
        exit(1) ;
    }

    while((ch=fgetc(fp)) != EOF){
        ch=toupper(ch);
        if(ch>='A' && ch<='Z') count[ch-'A']++;
    }
    // ch-'A' is only a numeric value, whatever cahracter value "ch" holding
    // after subtracting "A"'s value, we get only the difference


    for(i=0;i<26;i++)
    if(count[i]) 
        printf("%c occured %d times\n", i+'A', count[i]);
    // ch+'A' and printing it with "c" specifier we got a character

    fclose(fp) ;

    return 0;
}

// E:\1_Development_2.0\C_Cpp_codes\raw_test>FL_IO_5 myfile
// A occured 1 times
// .G occured 2 times
// .H occured 1 times
// .I occured 1 times
// .M occured 1 times
// .N occured 2 times
// .O occured 3 times
// .T occured 1 times
// .W occured 1 times
// .Z occured 1 times




/* Example 5: Write a program that copies the contents of one text file to another. 
                Have the program accept three command-line arguments.
                        The first is the name of the source file, 
                        the second is the name of the destination file, 
                        the third is optional. 
                If present and if it equals 'watch," have the program display each character as it copies the files; 
                otherwise, do not have the program display any screen output. Ifthe destination file does not exist, create it. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *from, *to;
    char ch, watch;
    
    // see if correct number of command line arguments 
    if(argc<3){
        printf("Usage: copy <source> <destination>.\n");
        exit(1);
    }
    
    // open source file
    if((from = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open source file.\n");
        exit(1) ;
    }
    
    // open destination file
    if((to = fopen(argv[2], "r"))==NULL) {
        printf("Cannot open destination file.\n");
        exit(1) ;
    }
    
    // optional argument shows the file in the console
    if(argc==4 && !strcmp(argv[3], "watch"))
        watch=1;
    else 
        watch=0;
        

    // copy the file
    while((ch=fgetc(from)) != EOF){
        fputc(ch, to);
        if(watch)
            putchar(ch);
    }
    
    
    fclose(from);
    fclose(to);
    
    return 0;
}
// E:\1_Development_2.0\C_Cpp_codes\raw_test>FL_IO_6 myfile myFile_2 watch
// OMG!! Whatz goin on?
// Copy This: Jojo Rabbit.




/* Example 6: Write a program that copies a file (use Binary IO). Have the user specify both
                the source and destination file names on the command line.
                Include full error checking. */

// Copy a file.
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){

}

FILE *from, *to;
char ch;


// Copy a file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *from, *to;
    char str[128];

    // see if correct line of command line arguments
    if(argc<3){
        printf("Usage: copy <source> <destination>\n");
        exit(1);
    }

    // open source file : use binIO
    if((from = fopen(argv[1], "rb")) == NULL){
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination file: use binIO
    if((to = fopen(argv[2], "wb")) == NULL){
        printf("Cannot open destination file.\n");
        exit(1);
    }


    // copy the file
    while(!feof(from)){
        ch = fgetc(from);
        if(ferror(from)){
            printf("Error on input.\n");
            break;
        }

        if(!feof(from)) fputc(ch,to);
        if(ferror(to)){
            printf("Error on output.\n");
            break;
        }
    }

    if(fclose(from)==EOF){
        printf("Error closing source file.\n");
        exit(1);
    }

    if(fclose(to)==EOF){
        printf("Error closing destination file.\n");
        exit(1);
    }

    return 0;
}
// FL_IO_bincpy myfile bin_cpy_myfl

