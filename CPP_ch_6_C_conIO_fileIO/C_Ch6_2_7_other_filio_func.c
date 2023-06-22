
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



