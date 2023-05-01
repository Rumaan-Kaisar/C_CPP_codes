
6.11 String I/O in a File with fputs() & fgets(). Text I/O with fprintf() & fscanf()
We use these two functions fputs() and fgets() , which write a string to and read a string from a file, respectively. Their prototypes are
int fputs(char *str, FILE *fp);
char *fgets(char *str, int num, FILE *fp);

fputs() : The fputs() function writes the string pointed to by str  to the file associated with fp. It returns EOF if an error occurs and a non-negative value if successful. The null that terminates str is not written. Also, unlike its related function puts() it does not automatically append a carriage return, linefeed pair. Example : fputs(str_1, f_point);

fgets() : The fgets() function reads characters from the file associated with fp into the string pointed to by str until "num-1" (one less than the string length number) characters have been read, a newline character is encountered, or the end of the file is reached. In any case, the string is null-terminated. Unlike its related function gets(), the newline character is retained. The function returns str if successful and a null pointer if an error occurs. Example : fgets(str_1, 79, f_point); /* 0 to 79 = 80 */

fprintf () & fscanf() : The C file system contains two very powerful functions fprintf() and fscanf() similar to printf() and scanf(). These functions operate exactly like printf() and scanf() except that they work with files. Their prototypes are:

int fprintf(FILE *fp, char *control-string, … );
int fscanf(FILE *fp, char * control-string, … );

Instead of directing their I/O operations to the console, these functions operate on the file specified by fp. Otherwise their operations are the same as their console-based relatives. The advantage to fprintf() and fscanf() is that they make it very easy to write a wide variety of data to a file using a text format.
