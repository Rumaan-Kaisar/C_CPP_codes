/* 
    ----------------    Random access    ----------------

    write/read a file sequentially from its beginning to its end using:
            fgetc(), 
            fputc(), 
            fputs(), 
            fgets(), 
            fprintf(), 
            fscanf(), 
            fread() and 
            fwrite().


    fseek():
        Used to access a file randomly (i.e. any where/any point of a file ).
        The prototype of fseek() is

            int fseek(FILE *fp, long offset, int origin);

        returns 'zero' when 'successful'
        nonzero if a failure occurs.

        In most implementations, you may seek past the end of the file, 
            but you may never seek to a point before the start of the file.


        fp: 
            fp is associated with the file being accessed. 
        offset: 
            The value of "offset" determines the "number of bytes" from 'origin' to make the 'new current position'. 
        origin: 
            origin must be one of these "macros", shown here with their meanings:

                Origin	    Meaning

                SEEK_SET	Seek from start of file
                SEEK_CUR	Seek from current location
                SEEK_END	Seek from end of file

        These macros are defined in STDIO.H. 

        For example, if you wanted to set the 'current location' 100 bytes from the 'start of the file',  then 
            'origin' will be SEEK_SET and 
            'offset' will be 100.



    ftell():
        You can "determine" the CURRENT LOCATION of a file using ftell(). Its prototype:

            long ftell(FILE *fp);

        returns the "location" of the "current position" of the file associated with fp. 
        If a failure occurs, it returns -1.



    NOTES:
        In general, use 'random access' only on 'binary files'. 
            Because text files may have character translations performed on them.
                there may not be a direct correspondence between file-content and the byte.

        The only time you should use fseek() with a "text file" is when seeking to a 
            position previously determined by ftell(), USing "SEEK_SET" as the "origin".

        text-file - can be opened as a binary file. 
            There is no inherent restriction about random access on files containing text. 
            The restriction applies only to files "opened as text files".
*/
