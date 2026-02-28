
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

    Use the seekg() and seekp()  to perform RANDOM ACCESS (i.e. nonsequential access),
    these are members of the I & O stream classes, respectively.
    
    Important Note:
        Files used with seekg() and seekp() should usually be opened in BINARY "std::ios::binary"
        Because binary mode avoids character translation and ensures exact byte positions.

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
        seekg() moves the "input/get (read)" pointer "offset" number of bytes from the specified "origin".
        seekp() moves the "output/put (write)" pointer "offset" number of bytes from the specified "origin".

    usage:
        jump to any byte
        modify a specific part of a file
        read data from the middle
        skip unwanted parts

        No need to read everything before it.



    --------  current position  --------

    To determine the current position of each file pointer use:

            pos_type tellg();
            pos_type tellp();

        tellg()     current read position
        tellp()     current write position

        They return the current byte location in the file (return pos_type).

        "pos_type" is an integer type defined by "ios" that is capable of 
            holding the "largest value" that defines a file position.



    --------  Overloaded versions of seekg() and seekp()  --------

    Following overloaded versions of seekg() and seekp() used to
    jump directly to a position returned by tellg() or tellp().
    
    Their prototypes are:
        istream &seekg( pos_type position );
        ostream &seekp( pos_type position );

    You can move directly to a known position using those.


    Example:
        A program can open a file for 
        
            # reading and writing
            # Jump to a specific byte
            # Replace one character there

                CLI: changer_prog file_name 10 X

            This changes the character at byte 10 to X.


    NOTE on CLI:
        Some programs take input like:

            "program filename position character"

        These values are received using:

            int main(int argc, char* argv[])
*/




/* Example 1: The following program demonstrates the use of the seekp() function..

                It allows us to modify a specific character in a file.

 
                How to use: Provide command-line arguments in this order:

                    CLI:    changer_prog file_name 10 X

                    File name:
                        the file to modify.
                        
                    Byte number:
                        position in the file (number of the byte in the file you want to change).

                    New character:
                        the character to write at that position.

                    Notice that the file is opened for read/write operations.


                seekp() is used to move the "put" pointer (output position) to the specified byte location.
                After seeking, the new character is written at that position.
*/

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



/* Example 2:  In the above program uses seekg() to position the get pointer into the middle of a file named "in" and then displays the contents of that file from that point. The name of the file and the location to begin reading from are specified on the command line.
in.seekg( atoi(argv[2]), ios::beg );

Note : *argv[] and argc are used in main()'s arguments. They are called the command line arguments. (Recall: 5.4) */

