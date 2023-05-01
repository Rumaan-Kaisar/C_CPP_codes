6.12 READ AND WRITE BINARY DATA
We discussed earlier that how useful fprintf() and fscanf() are , but they have some problems :
	They are not necessarily the most efficient way to read and write numeric data. Because both functions perform conversions on the data. For example, when you output a number using fprintf() the number is converted from its binary format into ASCII text. Conversely, when you read a number using fscanf() , it must be converted back into its binary representation. For many applications, this conversion time will not be meaningful; for others, it will be a severe limitation. 
	Further, for some types of data, a file created by fprintf() will also be larger than one that contains a mirror image of the data using its binary format.

For these reasons, the C me system includes two important functions: fread() and fwrite(). These functions can read and write any type of data, using its binary representation. Their prototypes are (with four parameters)

size_t fread(void *buffer, size_t size, size_t num, FILE *fp);
size_t tw*rite(void *buffer, size_t size, size_t num, FILE *fp);

fread() : Description of the four parameters 
[1]	The fread() function reads from the file associated with fp, 
[2]	num number of objects, 
[3]	each object size bytes long, 
[4]	into the buffer pointed to by buffer. 
It returns the number of objects actually read. If this value is less than num, either the end of the file has been encountered or an error has occurred. You can use feof() or ferror() to find out which.

fwrite()  : The fwrite() function is the opposite of fread().Description of the four parameters
[1]	fwrite()   writes to the file associated with fp, 
[2]	num number of objects, 
[3]	each object size bytes long, 
[4]	from the buffer pointed to by buffer.
It returns the number of objects written. This value will be less than num only if an output error has occurred.

void pointer : A void pointer is a pointer that can point to any type of data without the use of a type cast. This is generally referred to as a generic pointer. In C, void pointers are used for two primary purposes. 
[1]	First, as illustrated by fread() and fwrite(), they are a way for a function to receive a pointer to any type of data without causing a type mismatch error. [As stated earlier, fread( ) and fwrite( ) can be used to read or write any type of data]. Therefore, the functions must be capable of receiving any sort of data pointed to by buffer. void pointers make this possible.
[2]	A second purpose they serve is to allow a function to return a generic pointer. 

type size_t  : size_t is a type which is defined in the STDIO.H header file. (We'll learn how to define types later ). A variable of this type is defined by the ANSI C standard as being able to hold a value equal to the size of the largest object supported by the compiler. For our purposes, you can think of size_t as being the same as unsigned or unsigned long. The reason that size_t is used instead of its equivalent built-in type is to allow C compilers running in different environments to accommodate the needs and confines of those environments.

Example : The following program writes an integer to a file called MYFILE_BI using its internal, binary representation and then reads it back. (The program assumes that integers are 2 bytes long.)

#include<stdio.h>
#include<stdlib.h>
int main(void){FILE *f_point;
int i, k;

/*open the file for output*/
if((f_point=fopen("myfile_bi", "wb"))==NULL){printf("File-Error\n"); exit(1);}

i=100; 			/* value written through i*/

/*write into the file and using "!=1" instead of "==EOF" for error checking */
if((fwrite(&i, 2, 1, f_point)!=1)){printf("Write-Error\n"); exit(1);}
fclose(f_point);

/*Open the file for the input*/
if((f_point=fopen("myfile_bi", "rb"))==NULL){printf("Opening-Error"); exit(1);}

/*read from file and output*/
if((fread(&k, 2, 1, f_point)!=1)){printf("Read-Error\n"); exit(1);}
printf(" i is %d ", k); 	/* value read through k*/
fclose(f_point);
return 0;}

Notice how error checking is easily performed in this program by simply comparing the number of items written or read with that requested. But in some situations, however, you will still need to use feof() or ferror() to determine if the end of the file has been reached or if an error has occurred.
The sizeof() keyword & its use : One thing wrong with the preceding example is that an assumption about the size of an integer has been made and this size is hardcoded into the program. Therefore, the program will not work properly with compilers that use 4-byte integers  [More generally, the size of many types of data changes between systems or is difficult to determine manually] . 
For this reason, C includes the keyword sizeof, which is a compile-time operator that returns the size , in bytes, of a data type or variable. It takes the general forms :
sizeof(type) 		or 	sizeof var_name
For example, if floats are four bytes long and f is a float variable, both of the following expressions evaluate to 4:
sizeof f 	or 	sizeof(float)
	When using sizeof with a type, the type must be enclosed between parentheses. No parentheses are needed when using a variable name, although the use of parentheses in this context is not an error.

Example : An improved version of the preceding program is shown here, using sizeof.
#include<stdio.h>
#include<stdlib.h>
int main(void){FILE *f_point;
int i, k;
/*open the file for output / append*/
if((f_point=fopen("myfile_4", "ab+"))==NULL){printf("File-Error\n"); exit(1);}

i=400; 			/* value written through i*/

/*write into the file and using "!=1" instead of "==EOF" for error checking */
if((fwrite(&i, sizeof(int), 1, f_point)!=1)){printf("Write-Error\n"); exit(1);}
fclose(f_point);

/*Open the file for the input*/
if((f_point=fopen("myfile_4", "rb"))==NULL){printf("Opening-Error"); exit(1);}
/*read from file and output*/
if((fread(&k, sizeof k, 1, f_point)!=1)){printf("Read-Error\n"); exit(1);}
printf(" i is %d ", k); 	/* value read through k*/
fclose(f_point);
return 0;}

Note
	When using fread() or fwrite() to input or output binary data, the file must be opened for binary operations. Forgetting this can cause hard-to-find problems.
	By using sizeof, not only do you save yourself the drudgery of computing the size of some object by hand, but you also ensure the portability of your code to new environments. 
