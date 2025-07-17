
/*  ------------------------    chapter    ------------------------

12.10 Random Access
Use the seekg() and seekp()  to perform random access, these are members of the I & O stream classes, respectively. Common forms:
istream &seekg(off_type offset, seekdir origin);
ostream &seekp(off_type offset, seekdir origin);
	off_type is an integer type defined by ios that is capable of containing the largest valid value that offset can have. 
	seekdir is an enumeration defined by ios that has these values:
[1]	ios::beg (Means-Seek from beginning)	[2]	ios::cur (Means-Seek from current location)	[3]	ios::end (Means-Seek from end)
	C++ I/O system manages two pointers associated with a file. The appropriate pointer is automatically applied for each I/O operation. 
	get pointer, which specifies where in the file the next input operation will occur. 
	put pointer, which specifies where in the file the next output operation will occur. 
	seekg() and seekp() can be used in nonsequential fashion.
	seekg() moves the associated file's current get pointer offset number of bytes from the specified origin. 
	seekp() moves the associated file's current put pointer offset number of bytes from the specified origin.
	Files that will be accessed via seekg() and seekp() should be opened for binary file operations. 
	Use following member functions to determine the current position of each file pointer.
pos_type tellg(); 		pos_type tellp();
	pos_type is an integer type defined by ios that is capable of holding the largest value that defines a file position.
	Overloaded versions of seekg() and seekp(): There are overloaded versions of seekg() and seekp() that move the file pointers to the location specified by the return values of tellg() and tellp(). Their prototypes are:
istream &seekg( pos_type position );
ostream &seekp( pos_type position );
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


*/  
