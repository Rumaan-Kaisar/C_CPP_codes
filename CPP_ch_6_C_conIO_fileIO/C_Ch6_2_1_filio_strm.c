
-------------------    INTRO    -------------------
/* 
    C does not define any File I/O keywords. But C's STL contains a very rich set of File I/O functions.

    Most C compilers supply two complete sets of file I/O functions.
        ANSI file system (or buffered file system).
        UNIX-like file system (or unbuffered file system). This file system is not defined by the ANSI C standard.

    Here we only discuss the "ANSI file system". Because its supported by most of the systems. 




    -----------------    STREAMS for file I/O in C    -----------------
    stream:
        A stream is a file I/O abstruction.
        A stream is a logical interface to a file.  
        All streams are the same: 
            Although files differ in form and capabilities, all streams are the same.

        A stream is linked to a file using an open operation. 
        A stream is disassociated from a file using a close operation.
        
        C program deals with a stream instead of directly with a file.
        A stream is an idealized flow of data to which the actual input or output is mapped.
        Streams enable the device-independent I/O. 



    file:
        The actual device providing I/O is called a file. A file is the actual physical entity that receives or supplies the data.
        It can refer to a disk file, the screen, the keyboard, memory, a port, any other types of I/O devices.
        The most common form of file is the disk file.



    TEXT and BINARY streams:
        There are two types of streams: text and binary. 

        TEXT stream:
            A text stream contains ASCII characters.
                character translations may take place. For example, '\n' is convertyed to '\r'.
                There are "no one-to-one correspondence" between what is sent to the 'stream' and what is written to the file (ASCII-text).
            A text stream consists of one or more lines. 
            A line in a text stream consists of zero or more characters plus a terminating new-line character.

        BINARY stream:
            Binary stream can be used with any type of data. No character translations will occur
            There is a one-to-one correspondence between what is sent to the stream and what is actually contained in the file.
            A binary stream is an "ordered sequence of characters" that can transparently record internal data. 
            Data written to a binary stream shall always equal the data that gets read out under the same implementation (one-one correspondence).
            null characters may appended to the end of the stream.



    Current location: 
        Current location/current position, is the location in a file where the next file access will occur. 
        For example, if a file is 100 bytes long and half the file has been read, the next read operation will occur at byte 50, which is the current location.





    -----------------    "input stream" & "output stream"    -----------------
    Stream is nothing but the sequence of bytes of data.

    input stream: 
        A sequence of bytes flowing into program is called input stream

    output stream: 
        A sequence of bytes flowing out of the program is called output stream.


    Predefined Streams:
        stdin	Standard Input
        stdout	Standard Output
        stderr	Standard Error
    

    "Standard Input" Stream Device :
        "stdin" stands for (Standard Input). Standard input is data (Often Text) going into a program.
            Keyboard is standard input device .

        The program requests data transfers by use of the "read" operation.
        Not all programs require input.


    "Standard Output" Stream Device :
        "stdout" stands for (Standard Output). Standard output is data (Often Text) going out from a program.
            Screen(Monitor) is standard output device .

        The program sends data to output device by using "write" operation. 
*/
    
    
