
/* 
    ----------------    Other important File-System functions    ----------------

    rename() - Rename a file : 
        To rename a file use rename() :

            int rename(char *oldname, char *newname);

            "oldname" points to the original name of the file and 
            "newname" points to its new name. 
            The function returns 'ZERO' if 'SUCCESSFUL' and 
            'NONZERO' if an 'ERROR' occurs.



    remove() - Erase a file : 
        To erase a file use remove() : 

            int remove(char *file-name);

        will erase the file whose name matches that pointed to by 'file-name'. 
        It returns 'ZERO' if 'SUCCESSFUL' and 
        'NONZERO' if an 'ERROR' occurs.



    rewind() - Position change : 
        To position a file's current location to the "start of the file" use rewind().
        
            void rewind(FILE *fp);

            It rewinds the file associated with fp. 
            It has no return value, because any file that has been successfully opened can be rewind.



    fflush() - Flush disk buffer : 
        To cause a file's disk buffer to be flushed use fflush().
        
            int fflush(FILE *fp);

            It flushes the buffer of the file associated with 'fp'. 
            Returns "ZERO" if "SUCCESSFUL", 
            "EOF" if a "FAILURE" occurs. 
            
            If you call fflush() using a NULL for fp, all 'existing disk buffers' are "flushed".
*/

// Think of ways that rewind() and fflush() could be useful in real applications.


/* Example 1: This program demonstrates remove(). It prompts the user for
                the file to erase and also provides a safety check in case the user
                entered the wrong name. */

#include <stdio.h>
~inc:ude <stdlib.h>
_include <ctype.h>
int main(void)
{
)
char fname[BO};
printf("Enter name of file to erase: ");
gets (fname) ;
printf("Are you sure? (YIN) ");
if(toupper(getchar(»=='Y') remove (fname) ;
return 0;



/* Example 2: The following program demonstrates rewind() by displaying
                the contents of the file specified on the command line twice. */

#include <stdio.h>
#include cstdlih.h>
int main(int argc, char *argv(])
(
)
FILE *fp;
1* see if file name is specified */"
if(argc!=2) {
)
printf (-File name missing. \ n");
exitll) ;
if II fp = fopen largv [1J, "r"» ==NULL) (
printfC"Cannot open file. \ n-);
exit(1) ;
)
/* show it once * 1
whil,.l! feof Ifp) )
putcharlgetclfp»;
rewind ( £p) ;
1* show it twice • I
while I! feof Ifp) )
putchar(getc(fp» ;
fcloselfp) ;
return 0;



/* Example 3: This fragment causes the buffer associated with fp to be flushed to disk. */

FILE *fp;
fflush(fp) ;


/* Example 4: This program renames a file called MYFILE.TXT to YOURFILE.TXT. */
#include <stdio.h>
int main(void)
(
if (rename ( "myfi Ie. txt", ·yourfile. txt") )
printf ("Rename failed. \n") ;
else
printf (" Rename successful. \n ~ ) ;
return 0;
}


/* Example 5: Improve the erase program (Example 1) so that it notifies the user if he or
                she tries to renlove a nonexistent file */

#include <stdio.h>
.include <stdlib.h>
linclude <ctype.h>
int main(void)
(
char fname[BO];
printfC-Enter name of file to erase: .);
gets (fname) j
printfC-Are you sure? (YIN) .);
if(toupper(getchar(ll=='Y'}
if (remove (fname) )
-878
9.B EXERCISE
.,
printfC-'nFile not found or write' protected.\n-);
return 0;
1

