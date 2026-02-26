
/*  ------------------------    Random Access    ------------------------

    Random Access:
        Normally, files are read or written "sequentially" (from start to end).
        But sometimes we want to "jump directly to a specific position" in the file.
        This is called RANDOM ACCESS.
    
        C++ provides two functions for this:
            seekg()     move input (read) position
            seekp()     move output (write) position

                istream& seekg(offset, origin);
                ostream& seekp(offset, origin);



    ----------------    seekg() and seekp()    ----------------

    Use the seekg() and seekp()  to perform RANDOM ACCESS,
    these are members of the I & O stream classes, respectively.
    
    Common forms:
                istream &seekg(off_type offset, seekdir origin);
                ostream &seekp(off_type offset, seekdir origin);

        off_type:
            is an "integer type" defined by "ios" that is capable of 
            containing the largest valid value that "offset" can have. 

        seekdir:
            is an enumeration defined by ios that has these values:
                ios::beg (Means-Seek from beginning of file)	
                ios::cur (Means-Seek from current location)	
                ios::end (Means-Seek from end of file)

        offset:
            how many bytes to move

        origin:
            where to start counting from


    File position pointers:
        C++ I/O system manages two pointers associated with a file. 
        The appropriate pointer is automatically applied for each I/O operation. 

        get pointer:
            where the next read will happen

        put pointer:
            where the next write will happen

        These two acts as separate position markers in a file.
        
        seekg() and seekp() can be used in nonsequential fashion.

        
    Functions:
        seekg() moves the "get" pointer "offset" number of bytes from the specified "origin".
        seekp() moves the "put" pointer "offset" number of bytes from the specified "origin".

    usage:
        jump to any byte
        modify a specific part of a file
        read data from the middle
        skip unwanted parts

        No need to read everything before it.





----  rev[25-Feb-2026]  ----


 


	



	Files that will be accessed via seekg() and seekp() should be opened for binary file operations. 


	Use following member functions to determine the current position of each file pointer.
pos_type tellg(); 		pos_type tellp();


	pos_type is an integer type defined by ios that is capable of holding the largest value that defines a file position.


	Overloaded versions of seekg() and seekp(): There are overloaded versions of seekg() and seekp() that move the file pointers to the location specified by the return values of tellg() and tellp(). Their prototypes are:
istream &seekg( pos_type position );
ostream &seekp( pos_type position );



----  qwen  ----

Here is a simplified and organized version of the notes:
File Pointer Manipulation (seek and tell)
1. Random Access
Functions: seekg() and seekp() allow nonsequential (random) access to files.
Requirement: Files using these functions should be opened in binary mode.
2. Moving Pointers (seek)
seekg(): Moves the input/get (read) pointer.
seekp(): Moves the output/put (write) pointer.
How it works: Moves the pointer by a specific offset from an origin, OR to an absolute position.
3. Getting Position (tell)
tellg(): Returns the current position of the input pointer.
tellp(): Returns the current position of the output pointer.
Return Type: Both return pos_type (an integer type defined by ios large enough to hold any file position).
4. Absolute Positioning
You can use the overloaded versions of seekg() and seekp() to jump directly to a position returned by tellg() or tellp().
Prototypes:
cpp
12
istream &seekg( pos_type position );
ostream &seekp( pos_type position );
Quick Summary:
g = Get (Read) | p = Put (Write)
seek = Move pointer | tell = Report pointer location
Always use binary mode for reliable seeking.






	Example 1: The following program demonstrates the seekp() function. It allows you to change a specific character in a file. Specify a file name on the command line, followed by the number of the byte in the file you want to change, followed by the new character. Notice that the file is opened for read/write operations.

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main (int argc, char *argv[]) {
 if(argc !=4) { cout << " Usage : CHANGE <filename > <byte > <char >\n"; return 1;}	fstream out( argv[1] , ios::in | ios::out | ios::binary );
if (!out){cout << " Cannot open file .\n"; return 1; }
out.seekp( atoi(argv [2]), ios::beg);
out.put(*argv[3]) ;
out.close();
return 0;}
	Example 2:  In the above program uses seekg() to position the get pointer into the middle of a file named "in" and then displays the contents of that file from that point. The name of the file and the location to begin reading from are specified on the command line.
in.seekg( atoi(argv[2]), ios::beg );

Note : *argv[] and argc are used in main()'s arguments. They are called the command line arguments. (Recall: 5.4)




----  GPT  ----


















🔹 Important recommendation

Files used with seekg() and seekp() should usually be opened in:

std::ios::binary

Because binary mode avoids character translation and ensures exact byte positions.



🔹 Checking current position

To know where the pointers currently are:

tellg() → current read position
tellp() → current write position

They return the current byte location in the file.

🔹 Another way to move pointers

You can also move directly to a known position:

seekg(position);
seekp(position);

Often used with values returned by tellg() or tellp().

🔹 Example idea (concept)

A program can:

Open a file for reading and writing

Jump to a specific byte

Replace one character there

For example:

CHANGE filename 10 X

This changes the character at byte 10 to X.

🔹 Command-line arguments reminder

Some programs take input like:

program filename position character

These values are received using:

int main(int argc, char* argv[])

This is called command-line arguments.

✅ Key summary

seekg() → move read position

seekp() → move write position

tellg() / tellp() → check current position

File has separate read and write pointers

Binary mode is best for precise positioning

If desired, a visual diagram showing pointer movement inside a file can be provided.
*/  
