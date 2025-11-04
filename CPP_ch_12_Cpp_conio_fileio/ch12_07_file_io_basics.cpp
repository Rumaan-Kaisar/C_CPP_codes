
/*  ------------------------    File I/O in C++    ------------------------

----  rev[31-Oct-2025]  ----


12.7 File I/O 
	The same class hierarchy that supports console I/O also supports file I/O.  To perform file I/O, you must include the header <fstream> in your program. It defines several classes, including ifstream, ofstream, and fstream which are derived from istream & ostream. And istream, ostream are derived fron ios. 
	So ifstream, ofstream, and fstream also have access to all operations defined by ios.
	In C++, a file is opened by linking it to a stream. Before you can open a file, you must first obtain a stream.  There are three types of streams: 
[1]	input: To create an input stream, declare an object of type ifstream.
[2]	output: To create an output stream, declare an object of type ofstream. 
[3]	input/output: Streams that will be performing both input and output operations must be declared as objects of type fstream. 

For example, this fragment creates an input stream, an output stream, and one stream capable of both input and output:
ifstream in; 		// input
ofstream out; 	// output
fstream io; 		// input and output
	Associate stream with a file: Use the function open() to associate a stream with a file. This function is a member of each ifstream, ofstream, and fstream. The prototype for each:

void ifstream :: open(const char *filename, openmode mode = ios::in);

void ofstream :: open(const char *filename, openmode mode = ios::out | ios::trunc );

void fstream :: open(const char *filename, openmode mode = ios::in | ios::out);

	Here filename is the name of the file, which can include a path specifier. 
	The value of mode determines how the file is opened. It must be a value of type openmode, which is an enumeration defined by ios that contains the following values:
1.	ios::app causes all output to that file to be appended to the end. This value can be used only with files capable of output. 
2.	ios::ate causes a seek to the end-of-file to occur when the file is opened (I/O can still occur anywhere within the file).
3.	ios::binary value causes a file to be opened in binary mode (text is default mode). In binary mode no character translations (carriage return/linefeed sequences) will occur.
4.	ios::in value specifies that the file is capable of input. 
5.	ios::out value specifies that the file is capable of output.
6.	ios::trunc value causes the contents of a preexisting file by the same name to be destroyed and the file to be truncated to zero length. 
	When output stream using ofstream created, any preexisting file with the same name is automatically truncated.
	These six values can be combined using OR.
	Example 1: The following fragment opens an output file called test:
ofstream mystream;
mystream.open(" test ");
	Since the mode parameter to open() defaults to a value appropriate to the type of stream being opened, there is no need to specify its value in the preceding example.
	Confirmation test: If open() fails, the stream will evaluate to false when used in a Boolean expression. Which can be used in a confirmation test (consider Example 1) :
if(!mystream) { 	cout << "Cannot open file. \n"; 
// handle error  	}
	Always check the result of a call to open() before attempting to access the file.
	Use the is_open() function to see if a file successfully opened. is_open() is a member of fstream, ifstream, and ofstream. It has this prototype:	 bool is_open();
	It returns true if the stream is linked to an open file and false otherwise. For example, the following checks if mystream is currently open:
if( !mystream.is_open() ){	cout << " File is not open .\n";
. . . . . }
	Bypass the open() function: Most of the times we don’t need to use the function open() because the ifstream, ofstream, and fstream classes have constructor functions that automatically open the file. And those constructor functions have the same parameters and defaults as the open().  Therefore, the most common way to open a file is:
ifstream mystream("myfile");  		// open file for input
	If the file cannot be opened, the stream variable will evaluate as false when used in a conditional/Boolean statement. 
	Therefore, in this case we also need the confirmation test as stated above.
	Closing a file: To close a file, use the member function close(). For example, to close the file linked to a stream called mystream:
mystream.close();
	The close() function takes no parameters and returns no value.
	The eof() function: Use the eof() member function of ios to detect when the end-of-input-file has been reach. It has this prototype:
bool eof();
	It returns true when the end-of-file has been encountered and false otherwise.
	Read/Write textual data: to read/write textual data from/to an opened file we simply use << and >> operators (more like C's fprintf() and fscanf()).
	A file produced by using << is a formatted text file. A file read by >> must be a formatted text file. 
	Typically, formatted text files are operated through the >> and << operators. They are not for binary mode.  Binary mode is best used on unformatted files.
	Example 2: Following creates an output file, write information to it, closes the file and opens it again as an input file, and reads in the information:
#include<iostream>
#include<fstream>
using namespace std;
int main(){ ofstream f_out("test"); 	// create output file
if(!f_out){	cout << "Cannot open output file .\n";
return 1;} 		//notice !f_out Boolean!!!
f_out << "Hello !\n";
f_out << 100 << ' ' << hex << 100 << endl ;
f_out.close(); 			//closing the created file 	ifstream f_in("test"); 	//open input file
if(!f_in ){ 	cout << "Cannot open input file .\n";
		return 1; }
char str[80];
int i;
f_in >> str >> i;
cout << str << ' ' << i << endl ;
f_in.close(); 		//closing the opened file
return 0; }
	When the << and >> operators are used to perform file I/O, information is formatted exactly as it would appear on the screen.




----  GPT  ----

Here’s a clear and simplified explanation of your note on C++ File I/O (Input/Output):

1. File I/O Basics

File I/O in C++ uses the same stream classes as console I/O.

To use file I/O, include:

#include <fstream>


The main classes are:

ifstream → for input (reading from file)

ofstream → for output (writing to file)

fstream → for both input and output

These are derived from istream and ostream, which are derived from ios.
So, they inherit all the features of standard I/O streams.



2. Creating Streams

There are three stream types:

ifstream in;   // input (read)
ofstream out;  // output (write)
fstream io;    // both input and output



3. Opening Files

Use the open() function:

ifstream::open(const char *filename, openmode mode = ios::in);
ofstream::open(const char *filename, openmode mode = ios::out | ios::trunc);
fstream::open(const char *filename, openmode mode = ios::in | ios::out);


Parameters:

filename → name or path of the file.

mode → defines how the file is opened (using flags from ios).



4. Common File Opening Modes
Mode	Meaning
ios::app	Append new data at end of file.
ios::ate	Move pointer to end of file on open (I/O anywhere still allowed).
ios::binary	Open file in binary mode (no text translation).
ios::in	Open file for input (reading).
ios::out	Open file for output (writing).
ios::trunc	Delete old contents if file already exists.

These modes can be combined using the bitwise OR operator (|).

Example:

ofstream mystream;
mystream.open("test.txt");


(Since the default mode for ofstream is ios::out | ios::trunc, no need to specify it.)



5. Checking if File Opened Successfully

You can check using:

if (!mystream) {
    cout << "Cannot open file.\n";
}


or

if (!mystream.is_open()) {
    cout << "File is not open.\n";
}


is_open() returns true if the file is successfully opened.



6. Alternative: Open File Using Constructor

Instead of using open(), you can open files directly when declaring:

ifstream mystream("myfile.txt");  // open file for reading


Still, check if it opened successfully:

if (!mystream) cout << "Cannot open file.\n";



7. Closing Files

Use:

mystream.close();


It takes no arguments and returns nothing.



8. Detecting End of File

Use the function:

bool eof();


It returns true if the end of file has been reached.



9. Reading and Writing Text

Use << and >> just like console I/O:

f_out << "Hello\n";
f_in >> str;


These work with formatted text files.

For binary files, use binary mode (ios::binary).



10. Example Program
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream f_out("test");  // create and open output file
    if (!f_out) {
        cout << "Cannot open output file.\n";
        return 1;
    }

    f_out << "Hello!\n";
    f_out << 100 << ' ' << hex << 100 << endl;
    f_out.close();

    ifstream f_in("test");  // open for reading
    if (!f_in) {
        cout << "Cannot open input file.\n";
        return 1;
    }

    char str[80];
    int i;
    f_in >> str >> i;
    cout << str << ' ' << i << endl;
    f_in.close();

    return 0;
}


Explanation:

Writes "Hello!" and two integers (100 and 100 in hex).

Then reopens the same file and reads the first two items.

Output on console:

Hello! 100


Would you like me to include a short diagram showing the hierarchy (ios → istream/ostream → ifstream/ofstream/fstream)? It’ll make this even clearer visually.

*/  
