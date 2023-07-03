/* 
    --------------------    String/TEXT I/O in a File    --------------------

        String I/O in a File with fputs() & fgets(). 

        Text I/O with fprintf() & fscanf()




    --------------------    String I/O using fputs() and fgets()    --------------------

    fputs() and fgets()
        Writes a string to and read a string from a file, respectively. Their prototypes are

            int fputs(char *str, FILE *fp);     // writes
            char *fgets(char *str, int num, FILE *fp);      // reads


        fputs() 
            'fputs()' writes the string pointed to by "str"  to the file associated with "fp". 
                EOF returned if an error occurs and a 
                non-negative value returned if successful

            The 'null' that terminates 'str' is not written. 
            unlike its related function puts() it does not automatically append a carriage return, linefeed pair. 
                Example : 
                    fputs(str_1, f_point);


        fgets()
            'fgets()' reads characters from the file associated with "fp" into the string pointed to by "str"
                    until "num-1" (one less than the string length number) characters have been read, 
                    or a newline character is encountered, 
                    or the end of the file (EOF) is reached. 
                In any case, the string is null-terminated. 
            
            Unlike its related function gets(), the newline character is retained. 
            
            "str" is returned if successful 
            'null pointer' returned if an error occurs. 
                Example : 
                    fgets(str_1, 79, f_point); // 0 to 79 = 80




    --------------------    TEXT I/O using fputs() and fgets()    --------------------

    fprintf() & fscanf()
        fprintf() and fscanf() similar to printf() and scanf() except that they work with files. 
        Their prototypes are:

            int fprintf(FILE *fp, char *control-string, … );
            int fscanf(FILE *fp, char * control-string, … );

        These functions operate on the file specified by "fp".
        their operations are the same as printf() and scanf().
        
        fprintf() and fscanf() make it very easy to write a wide variety of data to a file using a text format.
*/




/* Example 1: This program demonstrates fputs() and fgets(). It reads lines entered by the user
                and writes them to the file specified on the command line.
                When the user enters a blank line, the input phase terminates, and the file is closed.
                Next, the file is reopened for input, and the program uses fgets() to display the contents of the file. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    char str[80];

    //check for command line argument
    if(argc != 2){
        printf("Sepcify file name.\n");
        exit(1);
    }

    // open file for output/write
    if((fp=fopen(argv[1],"w"))==NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    printf("Enter a blank line to stop.\n");
    do{
        printf(": ");
        gets(str);  // input from user
        strcat(str,"\n");   // add new line
        if(*str != '\n') fputs(str,fp); // writing to file
    } while(*str != '\n');
    fclose(fp);

    //open file for input/read
    if((fp=fopen(argv[1], "r"))==NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    //read back the file, display to the console
    do{
        fgets(str, 79, fp); // reads from file
        if(!feof(fp)) printf(str);  // writes to the console
    } while(!feof(fp));
    fclose(fp);

    return 0;
}

// name the above file "FL_IO_str_1"
/*  Following CREATES & WRITES to "myfile"
    ...\C_Cpp_codes\raw_test>  FL_IO_str_1 myfile
    Enter a blank line to stop.
    : my name is MYFILE i am a text file,
    : I live inside a PC
    : I wanna go to the internet, to see the world
    :
    my name is MYFILE i am a text file,
    I live inside a PC
    I wanna go to the internet, to see the world 
*/




/* Example 2: This program demonstrates fprintf() and fsacanf(). 
                It first writes a 'double', an 'int' and a 'string' to the file specified on the command line. 
                Next, it reads them back and displays their values as verification. 
                If you examine the file created by this program. you will see that it contains human-readable text. 

                This is because fprintf() writes to a disk file what printf() would write to the screen. 
                    No internal data formats are used. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *fp;
    double ld;
    int d;
    char str[80];
    
    //check for command line argument
    if(argc != 2){
        printf("Sepcify file name.\n");
        exit(1);
    }
    
    //open file for output/write
    if((fp=fopen(argv[1],"w"))==NULL){
        printf("Cannot open file.\n");
        exit(1);
    }
    
    fprintf(fp,"%f %d %s", 12345.342, 1908, "hello");
    fclose(fp);
    
    
    //open file for input/read
    if((fp=fopen(argv[1],"r"))==NULL){
        printf("Cannot open file.\n");
        exit(1);
    }
    
    fscanf(fp, "%lf%d%s", &ld, &d, str);
    printf("%f %d %s", ld, d, str);
    fclose(fp);
    
    return 0;
}

// name the above file "FL_IO_str_2 myfile"
/* 
Following CREATES & WRITES to "myfile" 
    FL_IO_str_2 myfile 
*/




/* Example 3: wrate a very simple telephone-directory program by allowing the directory to be saved to a disk fIle. 
                Have the program present a menu that looks like this:

                        1. Enter the names and numbers
                        2. Find numbers
                        3. Save directory to disk
                        4. Load directory from disk
                        5. Quit

                The program should be capable of storing 100 names and numbers. (Use only first names if you like.) 
                Use fprintf() to save the directory to disk and fscanf() to read it back into memory. */
// A simple computerized telephone book.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char names[10][40], 
numbers[10][40];

int loc = 0;

int menu(void);
void enter(void);
void load(void);
void save(void);
void find(void);

int main(void){
    int choice;

    do{
        choice = menu();
        switch(choice){
            case 1: enter();
                break;
            case 2: find();
                break;
            case 3: save();
                break;
            case 4: load();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice
int menu(void){
    int i;
    char str[80];

    printf("1. Enter names and numbers\n");
    printf("2. Find numbers\n");
    printf("3. Save directory to disk\n");
    printf("4. Load directory from disk\n");
    printf("5. Quit\n");

    do{
        printf("Enter your choice\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


void enter(void){
    for( ; loc<10; loc++){
        if(loc<10){
            printf("Enter name and phone number:\n");
            gets(names[loc]);
            if(!*names[loc]) break;
            gets(numbers[loc]);
        }
    }
}


void find(void){
    char name[80];
    int i;

    printf("Enter name: ");
    gets(name);

    for(i=0; i<10; i++){
        if(!strcmp(name, names[i]))
            printf("%s %s\n",names[i], numbers[i]);
    }
}


void load(void){
    FILE *fp;

    if((fp = fopen("phone","r"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    loc = 0;
    // loading names and numbers from the file & re-building Phone-Book
    while(!feof(fp)){
        fscanf(fp,"%s%s", names[loc], numbers[loc]);
        loc++;
    }
    fclose(fp);
}


void save(void){
    FILE *fp;
    int i;

    if((fp = fopen("phone","w"))==NULL){
        printf("Cannot open file\n");
        exit(1);
    }

    for(i=0; i<loc; i++){
        fprintf(fp,"%s %s\n", names[i], numbers[i]);
    }

    fclose(fp);
}




/* Example 4: Write a program that uses fgets() to display the contents of a text file , one screenful at a time. 
                After each screen is displayed, have the program prompt the user for more. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]){
    FILE *fp;
    char ch;
    char str[80];
    int count;

    // see if correct number of command line arguments
    if(argc!=2){
        printf("Usage: display <file>\n");
        exit(1);
    }

    // open the file
    if((fp = fopen(argv[1], "r")) == NULL){
        printf("Cannot open file.\n");
        exit(1);
    }

    count = 0;
    while(!feof(fp)){
        fgets(str, 79, fp);
        printf("%s", str);
        count++;

        if(count==23){
            printf("More? (y/n) ");
            gets(str);
            if(toupper(*str)=='N') break;
            count = 0;
        }
    }

    fclose(fp);

    return 0;
}
// FL_IO_str_4 myfile




/* Example 5: Write a program that copies a text file . 
                Specify both the 'source' and 'destination' file names on the command line. 
                Use fgets() and fputs() to copy the file. Include full error checking */
// Copy a file
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *from, *to;
    char str[128];

    // see if correct line of command line arguments
    if(argc<3){
        printf("Usage: copy <source> <destination>\n");
        exit(1);
    }

    // open source file
    if((from = fopen(argv[1], "r")) == NULL){
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open destination file
    if((to = fopen(argv[2], "w")) == NULL){
        printf("Cannot open destination file.\n");
        exit(1);
    }


    // copy the file
    while(!feof(from)){
        
        fgets(str, 127, from);
        if(ferror(from)){
            printf("Error on input.\n");
            break;
        }

        if(!feof(from)) fputs(str,to);
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
// FL_IO_str_4 myfile cpy_myfl




/* Example 6: Write a program that copies a text file. Have the user specify both file names on the command line. 
                Have the copy program convert all LOWERCASE letters into UPPERCASE ones. */

// Copy a file and convert to uppercase.
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char *argv[]) {
    FILE *from, *to;
    char ch;

    // see if correct number of command line arguments·
    if(argc != 3){
        printf("Usage.: copy <source> <destination>\n");
        exit(1);
    }

    // open SOURCE file for reading
    if((from = fopen(argv[1], "r")) == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }

    // open DESTINATION file for writing
    if((to = fopen(argv[2], "w")) == NULL) {
        printf("Cannot open destination file.\n");
        exit(1);
    }


    // copy the file
    while(!feof(from)) {
        ch = fgetc(from);
        if(!feof(from)) fputc(toupper(ch), to);
    }

    fclose(from);
    fclose(to);

    return 0;
}
// FL_IO_ms2 fl_1 fl_3




/* Example 7: Enhance the "electronic Library" card-catalog program (from C_Ch6_1_4_mstr_gets_puts and concept from C_Ch6_2_4_stringio_fileio)
                that it stores its information in a disk file called "CATALOG".

                When the program begins, have it read the catalog into memory.
                Also, add an option to save the information to disk.

                Card Catalog:
                            1. Enter Books
                            2. Search by author
                            3. Search by Title
                            4. Save catalog
                            5. Quit


                If you choose Enter, have the program repeatedly input the name, author, and publisher of a book.
                    Have this process continue until the user enters a blank line for the name of the book.

                For searches, prompt the user for the specified author or title and
                then, if a match is found, display the rest of the information.

                The program should be capable of storing 100 book info.
*/

/* =-=-=-=-=-=-=-=-=-=-=            An electronic card catalog             =-=-=-=-=-=-=-=-=-=-= */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int menu(void);
void enter(void);
void load(void);
void save(void);

void display(int i);
void author_search(void);
void title_search(void);

char names[MAX][80];    // author name
char titles[MAX][80];   // titles
char pubs[MAX][80];     // publisher

int top = 0;    // last location used


int main(void){
    int choice;

    load();  // open to read in catalog

    do{
        choice = menu();
        switch(choice){
            case 1: enter(); // enter books
                break;
            case 2: author_search(); // search by author
                break;
            case 3: title_search(); // search by, title
                break;
            case 4: save();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice, select a choice
int menu(void){
    int i;
    char str[80];

    printf("Card Catalog:\n");
    printf("1. Enter Books\n");
    printf("2. Search by author\n");
    printf("3. Search by Title\n");
    printf("4. Save catalog\n");
    printf("5. Quit\n");

    do{
        printf("Choose your selection:\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


// Enter books into Database
void enter(void){
    int i;

    for( i=top; i<MAX; i++){
        printf("Enter author name (ENTER to quit): ");
        gets(names[i]);
        if(!*names[i]) break;

        printf("Enter title: ");
        gets(titles[i]);

        printf("Enter publisher: ");
        gets(pubs[i]);
    }

    top = i;
}


// Search by author
void author_search(void){
    char name[80];
    int i, found;

    printf("Name: ");
    gets(name);

    found= 0;

    for(i=0; i<top; i++){
        if(!strcmp(name, names[i])){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Search by TITLE
void title_search(void){
    char title[80];
    int i, found;

    printf("Title: ");
    gets(title);

    found= 0;

    for(i=0; i<top; i++){
        if(!strcmp(title, titles[i])){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Display catalog entry.
void display(int i){
    printf("%s\n", titles[i]);
    printf("By %s\n", names[i]);
    printf("Published by %s \n", pubs[i]);
}


// Load the catalog file
void load(void){
    FILE *fp;

    if((fp = fopen("catalog","r"))==NULL){
        printf("Catalog file not on disk\n");
        // exit(1); we don't use it because we won't terminate the program
        return; // we use "return" to continue the "main" function
    }

    fread(&top, sizeof top, 1, fp); // read count
    fread(names, sizeof names, 1, fp);
    fread(titles, sizeof titles, 1, fp);
    fread(pubs , sizeof pubs, 1, fp);

    fclose(fp);
}


void save(void){
    FILE *fp;

    // open for writing
    if((fp = fopen("catalog","w"))==NULL){
        printf("Cannot open catalog file\n");
        exit(1);
    }

    fwrite(&top, sizeof top, 1, fp); // write count
    fwrite(names, sizeof names, 1, fp);
    fwrite(titles, sizeof titles, 1, fp);
    fwrite(pubs, sizeof pubs, 1, fp);

    fclose(fp);
}




/* Example 2: Write a program that copies a file.
                Have the user specify both the "source" and "destination files" on the command line.
                Have the program remove tab characters, substituting the appropriate number of spaces. */

/*-=-=-=-=-=-=-=    Copy a file and remove tabs    -=-=-=-=-=-=-=*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *from, *to;
    char ch;
    int tab, count;

    // see if correct number of command line arguments
    if(argc!=3){
        printf("Usage: copy <source> <destination>\n");
        exit(1);
    }

    // open source file for reading
    if((from = fopen(argv[1], "r"))==NULL) {
        printf("Cannot open source file\n");
        exit(1);
    }

    // open destination file for writing
    if((to = fopen(argv[2], "w"))==NULL) {
        printf("Cannot open destination file\n");
        exit(1);
    }


    // copy the file
    count = 0;
    while(!feof(from)){
        ch = fgetc(from);
        if(ch=='\t') {
            for(tab = count; tab < 8; tab++) fputc(' ', to);
            count = 0;
        }
        else {
            if(!feof(from)) fputc(ch, to);
            count++;
            if(count==8 || ch=='\n') count = 0;
        }
    }

    fclose(from);
    fclose(to) ;

    return 0;
}
// CLI: FL_IO_cpy_rep new_catalog rmvtb
// why 8 is used: a tab is 8 spaces long, thats why count is between 0 and 8.




/* Example 3: On your own, create a small database to keep track of anything
                you desire in your CD collection; for example. */


