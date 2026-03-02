
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


1. The following program demonstrates the seekp() function. It allows you to change a
specific character in a file. Specify a file name on the command line, followed by the
number of the byte in the file you want to change, followed by the new character. Notice
that the file is opened for read/write operations.
# include <iostream >
# include <fstream >
# include <cstdlib >
using namespace std ;
int main ( int argc , char * argv [])
251TEACH YOURSELF
C++
{
if( argc !=4)
{
cout << " Usage : CHANGE <filename > <byte > <char >\n";
return 1;
}
fstream out ( argv [1] , ios :: in | ios :: out | ios :: binary );
if (! out )
{
cout << " Cannot open file .\n";
return 1;
}
out . seekp ( atoi ( argv [2]) , ios :: beg);
out . put (* argv [3]) ;
out . close ();
return 0;
}
2. The next program uses seekg() to position the get pointer into the middle of a file and
then displays the contents of that file from that point. The name of the file and the
location to begin reading from are specified on the command line.
// Demonstrate seekg ()
# include <iostream >
# include <fstream >
# include <cstdlib >
using namespace std ;
int main ( int argc , char * argv [])
{
char ch;
if( argc !=3)
{
cout << " Usage : LOCATE <filename > <loc >\n";
return 1;
}
ifstream in( argv [1] , ios :: in | ios :: binary );
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
in. seekg ( atoi ( argv [2]) , ios :: beg );
252ADVANCED C++ I/O
9.6. CHECKING THE I/O STATUS
while (! in. eof ())
{
in. get (ch);
cout << ch;
}
in. close ();
return 0;
}
EXERCISES
1. Write a program that displays a text file backwards. Hint: Think about this before
creating your program. The solution is easier than you might imagine.
2. Write a program that swaps each character pair in a text file. For example, if the file
contains "1234", then after the program is run, the file will contain "2143". (For simplicity,
you may assume that the file contains an even number of characters.)


1. // Display a file backwards on the screen .
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
if( argc !=2)
{
cout << " Usage : REVERSE <filename >\n";
return 1;
}
ifstream in( argv [1] , ios :: in | ios :: binary );
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
char ch;
long i;
// go to end of file ( less eof char )
in. seekg (0, ios :: end );
i = ( long ) in. tellg (); // see how many bytes in file
i -= 2; // backup before eof
for ( ; i >=0; i --)
{
in. seekg (i, ios :: beg );
in. get (ch);
cout << ch;
}
in. close ();
534ANSWERS
9.6 EXERCISES
return 0;
}
2. // Swap characters in a file .
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
if( argc !=2)
{
cout << " Usage : SWAP <filename >\n";
return 1;
}
// opne file for input / output
fstream io( argv [1] , ios :: in | ios :: out | ios :: binary );
if (! io)
{
cout << " Cannot open file .\n";
return 1;
}
char ch1 , ch2 ;
long i;
for (i =0; !io. eof (); i +=2)
{
io. seekg (i, ios :: beg );
io. get ( ch1 );
if(io. eof ())
continue ;
io. get ( ch2 );
if (! io. eof ())
continue ;
io. seekg (i, ios :: beg );
io. put ( ch2 );
io. put ( ch1 );
}
io. close ();
return 0;
}
