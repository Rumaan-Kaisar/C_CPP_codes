6.14 Some other important File-System functions
Rename a file : To rename a file use rename(), shown here:
int rename(char *oldname, char *newname);
Here, oldname points to the original name of the file and newname points to its new name. The function returns zero if successful and nonzero if an error occurs.

Erase a file : To erase a file use remove(), Its prototype is
int remove(char *file-name);
This function will erase the file whose name matches that pointed to by file-name. It returns zero if successful and nonzero if an error occurs.

Position change : To position a file's current location to the start of the file use rewind(). Its prototype is
void rewind(FILE *fp);
It rewinds the file associated with fp. The rewind() function has no return value, because any file that has been successfully opened can be rewound.

Flush disk buffer : To cause a file's disk buffer to be flushed use fflush(). Its prototype is
int fflush(FILE *fp);
It flushes the buffer of the file associated with fp. The function returns zero if successful, EOF if a failure occurs. If you call fflush() using a NULL for fp, all existing disk buffers are flushed.

