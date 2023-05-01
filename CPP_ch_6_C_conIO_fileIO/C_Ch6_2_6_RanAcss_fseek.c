6.13 Random access using fseek()
Above we discussed about write or read a file sequentially from its beginning to its end using fgetc(), fputc(), fputs(), fgets(), fprintf(), fscanf(), fread() and fwrite(). 

To access a file randomly (i.e. any where of a file ): Using fseek() we can access any point in a file at any time. It is another of C's file system functions. The prototype of fseek() is

int fseek(FILE *fp, long offset, int origin);

	The fseek() function returns zero when successful and nonzero if a failure occurs. In most implementations, you may seek past the end of the file, but you may never seek to a point before the start of the file.
	Here, fp is associated with the file being accessed. The value of offset determines the number of bytes from origin to make the new current position. origin must be one of these macros, shown here with their meanings:

Origin	Meaning
SEEK_SET	Seek from start of file
SEEK_CUR	Seek from current location
SEEK_END	Seek from end of file

These macros are defined in STDIO.H. For example, if you wanted to set the current location 100 bytes from the start of the file, then origin will be SEEK_SET and offset will be 100.

Determine the current location using ftell() : You can determine the current location of a file using ftell(). It is another of C's file system functions. Its prototype is
long ftell(FILE *fp);

It returns the location of the current position of the file associated with fp. If a failure occurs, it returns -1.

Notes
[1]	In general, use random access only on binary files. Because text files may have character translations performed on them, there may not be a direct correspondence between what is in the file and the byte to which it would appear that we want to seek. 
[2]	The only time you should use fseek() with a text file is when seeking to a position previously determined by ftell(), USing SEEK_SET as the origin.
[3]	Even a file that contains only text - can be opened as a binary file, if you like. There is no inherent restriction about random access on files containing text. The restriction applies only to files opened as text files.
