
/* 
    --------------    BINARY I/O    --------------
    fprintf() and fscanf() are not efficient way to read and write numeric data. 
    data conversions occurs

    using fprintf() the number is converted from its binary format into ASCII text. 
    Conversely using fscanf() , it must be converted back into its binary representation. 


    moreover a file created by fprintf() will also be LARGER.



    --------------    any data read/write    --------------

    fread() & fwrite()
        These functions can read and write any type of data, using its "BINARY REPRESENTATION". 
            Prototypes are (with four parameters)

                size_t fread(void *buffer, size_t size, size_t num, FILE *fp);
                size_t fwrite(void *buffer, size_t size, size_t num, FILE *fp);


    fread():
        'fread()' function reads from the file associated with 'fp', 
        'num' is number of objects, 
        each object 'size' bytes long, 
        into the buffer pointed to by 'buffer'. 

        It returns the number of objects actually read. 
        If this value is less than num, either the EOF encountered or an error has occurred. 
            You can use feof() or ferror() to find out which.


    fwrite():
        'fwrite()' writes to the file associated with 'fp', 
        "num" number of objects, 
        each object "size" bytes long, 
        from the buffer pointed to by "buffer".

        It returns the number of objects written. 
        This value will be less than num only if an output error has occurred.



    void pointer/generic pointer: 
        It can point to "any type of data" without the use of a "TYPE CAST". 
        This is generally referred to as a generic pointer. 

        In C, void pointers are used for two primary purposes. 
            [1]	First, as illustrated by fread() and fwrite(), they are a way for a function to receive 
                a pointer to any type of data without causing a type mismatch error. 
                Therefore, the functions must be capable of receiving any sort of data pointed to by "buffer". 

            [2]	A second purpose they serve is to allow a function to return a generic pointer. 



    type size_t: 
        size_t is a type which is defined in the STDIO.H header file.
        A variable of this type is able to hold a value equal to the "size of the largest object" supported by the COMPILER. 
        
        you can think of size_t as being the same as unsigned or unsigned long. 
        But unsigned or unsigned long can change in different environment,  size_t is ENVIRONMENT INDEPENDENT.
 */




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

  
