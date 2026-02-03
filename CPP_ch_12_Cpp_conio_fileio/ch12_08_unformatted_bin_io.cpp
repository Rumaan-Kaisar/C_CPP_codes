
/*  ------------------------    Unformatted I/O & Binary I/O    ------------------------

    ====  combine cpp chapters (9.3 + 9.4)  ====


    What is Unformatted I/O?
        Deals with raw bytes (raw binary data), not formatted text.
        Data is read/written exactly in its internal binary form (as it exists in memory).

        Unformatted files store data in the same binary format used by the program,
            Unlike << and >>, no text conversion occurs.

        Thus, unformatted functions give you detailed control over files I/O.
        Commonly used for binary files, speed, and exact data storage.


    Used for:
        Fast file operations
        Storing complex data (objects, structs)
        Avoiding text conversion (e.g., newline translation)

    It uses read(), write(), get(), put() — not << or >>.



    --------  Lowest-level unformatted I/O  --------
    The lowest-level unformatted I/O functions are get() and put().
        get() is used to read a byte and put() is used to write a byte.
        These are members of all I/O stream classes respectively.
        Following are Common version of get() & put()
        Both return the stream, so chaining is possible.


    put()
        writes one byte (character).

            ostream &put(char &ch);

        Writes ch to the output stream.
        Returns reference to stream (for chaining).


    get()
        Reads one character from the associated stream and puts that in ch.
        Does not skip "whitespace".
        Returns a reference to the stream; if at EOF, stream evaluates to false.

            istream &get(char &ch);

        Note:
            Unlike cin >> ch, get() reads spaces and newlines too.


        --------  Overloaded get()  --------

        get() can be overloaded several different ways
        The prototypes for commonly used overloaded forms are:

                istream &get(char *buf, streamsize num);
                istream &get(char *buf, streamsize num, char delim);
                int get();


        get(buf, num):
            This form reads up to num-1 characters into "buf". 
            Stops at "newline" or "EOF"
            Buffer "buf" is null-terminated

            Newline remains in the stream
                if NEWLINE encountered, it is not extracted (inputted). 
                Instead stays in stream until the next input operation


        get(buf, num, delim):
            This form reads characters into the array pointed to by "buf" until one of these happens:
                num-1 characters are read,
                delimiter delim is found,
                or end-of-file (EOF) is reached.

            The array pointed to by "buf" will be null terminated by get(). 
            Buffer "buf" is null-terminated

            If delimiter encountered in the stream, it is not extracted (inputted). 
                Instead, it remains in the stream until the next input operation.
                Automatically adds a null (\0) at the end of the string.

            Note (Delimiter character): 
                A delimiter is one or more characters that separate text strings. 
                Common delimiters are: 
                    commas      ( , ), 
                    semicolon   ( ; ), 
                    quotes      ( ", ' ), 
                    braces      ( {} ), 
                    pipes       ( | ),      or slashes      ( / \ ). 
                    Newline character is also a delimiter. 


        int get():
            This form of get() returns next character (or EOF on end) from the stream.
            It is similar to C's getc() function.

        All versions null-terminate the buffer automatically.



    getline():
        getline() is another input function. 
        It is a member of each "input stream class". 

        Its prototypes:
                istream &getline(char *buf, streamsize num);
                istream &getline(char *buf, streamsize num, char delim);


        getline(buf, num):
            The first form reads characters into the array pointed to by "buf" until either:
                num-1 characters have been read, 
                a newline is found, or 
                the end-of-file (EOF) has been encountered. 

            If the newline encountered in the input stream, 
                it is extracted (inputted), but it is not put into "buf".


        getline(buf, num, delim):
            this form reads characters into the array pointed to by "buf" until either:
                num-1 characters are read,
                delimiter delim is found,
                or end-of-file (EOF) is reached.

            If the delimiter encountered in the input stream, 
                it is extracted (inputted), but it is not put into buf.

        In both case the array pointed to by "buf" will be null terminated by getline().

        Why getline() Solves Space Issues:
            ">>" stops at whitespace
            getline() reads full lines including spaces
            Acts like the old C gets() but safely



    --------  get() vs getline()  --------

    getline(buf, num) and getline(buf, num, delim) are virtually identical to the 
    get(buf, num) and get(buf, num, delim)

    The difference between get() and getline() is that:
        getline() reads and removes the "delimiter" from the input stream; get() does not.

    get():
        Delimiter stays in stream
        Use for Manual control

    getline():
        Removes Delimiter from stream
        Preferred for full line input

    Always use getline() over get() unless you need to keep the delimiter.
    For reading lines or strings with spaces, getline() is preferred.



    --------  Block I/O: read() and write()  --------

    To read and write blocks of data (blocks of bytes), use read() and write()
    These are members of the I & O stream classes, respectively. 
    
    Example: 
        Save/load entire structs or classes directly.


    Their PROTOTYPES are:

            istream &read(char *buf, streamsize num);
            ostream &write(const char *buf, streamsize num);


    read(buf, num):
        Reads num bytes into memory from the invoking stream and 
        puts them in the buffer pointed to by buf. 

        If the end-of-file is reached before num characters have been read, 
        read() simply stops, and the buffer contains as many characters as were available. 


    write(buf, num):
        Writes num bytes from memory to the associated stream from the buffer pointed to by buf. 

    Note:
        Blocks of raw data e.g., objects, arrays, structs

        streamsize:
            streamsize type is some form of integer. 
            An object of type streamsize is capable of holding the largest number of bytes 
            that will be transferred in any one I/O operation.

        Type Casting in read() / write():
            Buffers must be cast to (char*)
            Required due to C++ strong type checking
            Prevents unsafe pointer conversions


    gcount():
        this member function checks how many bytes (characters) were read

        The prototype is:
                streamsize gcount();

            Returns number of characters (bytes) read by last unformatted input (read(), getline(), etc.).
            Useful after partial reads (when read() stops early) to know actual data size.


    peek():
        Looks at the next character in the input stream without removing it from that stream
        It is a member of the input stream classes.
        
        prototype:
                int peek();

            It returns the next character in the stream.
            Does not remove it from the stream
            Returns EOF at end-of-file
            Useful when input type is unknown


    putback():
        Used to put the last read character back into the stream.
        i.e. return the last character read from a stream to that stream.

        It is a member of the input stream classes. 

        Prototype:
                istream &putback(char c);

            Puts character c back into input stream.
            Where c is the last character read.

        Allows rereading: Next get() or peek() will see it again.
        Helps when you read too far and want to "undo".


    Smart Parsing with peek() and putback():
        Useful when integers and strings are mixed
        peek() checks what comes next
        putback() restores unwanted characters
        Enables flexible input handling


    flush():
        When output is performed, data is not written immediately to the device linked to the stream.
        Instead, information is stored in a internal buffer in memory (RAM).
        The data is only written to disk when the buffer becomes full. 

        flush() force output immediately
        It force the information to be physically written to disk before the buffer is full.

        flush() is a member of the output stream classes and has this prototype:

                ostream &flush();

        Useful in critical situations (e.g., power failure risks) to ensure important data is not lost.
        
        Example: 
            Logging systems or real-time applications where immediate output is essential.



    --------  Binary Mode  --------
    For unformatted file I/O we always use binary operation (rather than text operations >> <<)

    ios::binary
        Always open binary files with it to prevents "automatic character translations"
        
            No \n → \r\n conversion (on Windows).
            Ensures exact byte matching.
            Essential for saving integers, floats, pointers, etc.

        However, it is perfectly acceptable to use the unformatted functions on a file 
            opened in text mode, but remember, some character translations may occur.

        Note:
            Prevents character translation
            Ensures exact byte-for-byte storage

            Required for:
                Integers
                Floating-point values
                Pointers
                Binary objects



    ----------------    Key Takeaways    ----------------

    Use unformatted I/O for speed and accuracy
    Use ios::binary for reliable binary storage
    Prefer getline() for text with SPACES
    Use peek() + putback() for intelligent parsing
    Use gcount() to verify read size
    Use flush() when immediate output matters

*/  


// ----  rev[30-Jan-2026] GPT simplify  ----



/* Example 1 (Save & Load Binary Data):
                Following uses write() to write a double and a string to a file called "test".

                The type cast to (char *) inside the call to write() is necessary when
                    outputting a buffer that is not defined as a character array. 

                Because of C++'s strong type checking, a pointer of one type 
                    will not automatically be converted into a pointer of another type.

                Note: (char *) and (char*) both acceptable
*/

#include <iostream>
#include <fstream>
#include <cstring>

int main(){
    // following combines two file I/O modes 'out' and 'binary'
    // recall "ch12_07_file_io_basics.cpp"
    ofstream out(" test ", std::ios::out | std::ios::binary );  

    if(!out){
        std::cout << " Cannot open output file .\n";
        return 1;
    }

    double num = 100.45;
    char str[] = " This is a test ";

    out.write( (char*) &num, sizeof(double));
    out.write(str, strlen(str));
    out.close();

    return 0;
}



// cp1


/* Example 2 (Saving and restoring exact binary value):
                This program uses read() to read the file created by the program in Example 1.
*/

#include <iostream>
#include <fstream>

using namespace std;

int main() {    ifstream in(" test ", ios :: in | ios :: binary );
if (!in) { cout << " Cannot open input file .\n"; return 1; }
double num;    char str[80];
in.read(( char *) &num , sizeof (double)) ;
in.read(str , 14) ;
str[14] = '\0 ';        // null terminate str
cout << num << ' ' << str ;
in.close();    
return 0;}

// As is the case with the program in the preceding example, the type cast (char *) inside read() is necessary because C++ will not automatically convert a pointer of one type to another.
// ios::out        Open file for output (writing).
// ios::in         Open file for input (reading).
// ios::binary     Open file in binary mode.


This program uses read() to read the file created by the program in Example 3:


# include <iostream >
# include <fstream >

int main ()
{
ifstream in(" test ", ios :: in | ios :: binary );
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
double num ;
char str [80];
in. read (( char *) &num , sizeof ( double )) ;
in. read (str , 14) ;
str [14] = ’\0 ’; // null terminate str
cout << num << ’ ’ << str ;
in. close ();
return 0;
}
As is the case with the program in the preceding example, the type cast inside read() is
necessary because C++ will not automatically convert a pointer of one type to another.









/* Example 3: Safe String Input with Spaces
Unlike >>, this doesn’t stop at space.

When you use >> to read a string, it stops reading when the first whitespace character is encountered. This makes it useless for reading a string containing spaces. getline() can resolve this problem: */

#include<iostream>
#includ <fstream>
using namespace std;
int main(){
    char str[80];
cout << " Enter your name : ";
cin.getline(str , 79);
cout << str << '\n';
return 0; }

/* Here, the delimited used by getline() is the newline. This makes getline() act like the standard gets() function. */




/* Example 4: Smart Input Using peek() and putback()

                Uses peek() to check type, then reads accordingly.
                Uses putback() to return unwanted character.

                Very useful for parsing mixed data.


In real programming situations, the functions peek() and putback() are especially useful because they let you more easily handle situations in which you do not know what type of information is being input at any point in time. The following program gives the flavor of this. It reads either strings or integers from a file. The strings and integers can occur in any order.
*/


#include <iostream>
#include <fstream>
#include <cctype>
#include <cstdlib>

using namespace std;

int main(){char ch;
ofstream out("test", ios::out | ios::binary );
if(!out ){ cout << "Cannot open output file .\n";
return 1; }     // confirmation

char str[80], *p;
out << 123 << "this is a test" << 23;
out << "Hello there !" << 99 << "sdf" << endl;
out.close();    // closing 1st time
ifstream in("test", ios::in | ios::binary);
if(!in) {       cout << "Cannot open input file .\n";
return 1; } // confirmation

do{ p = str;
ch = in.peek();             // see what type of char is next
if(isdigit(ch)){ while(isdigit( *p=in.get() ))   p++;           // read integer
in.putback(*p);         // return char to stream
*p = '\0 ';             // null - terminate the string
cout << " Integer : " << atoi(str ); }

else if(isalpha(ch)){while(isalpha*p=in.get() ))  p++;    // read a string
in.putback (*p);
*p = '\0 ';
cout << " String : " << str ; }
else    in.get();           // ignore 
cout << '\n'; }  while (! in.eof());
in.close();                 // final file closing 
return 0; }



/* 

	The atoi() is one of C's standard library function, it returns the integer equivalent of the number represented by its string argument.
	The isalpba() function returns nonzero if ch is a letter of the alphabet; otherwise 0 is returned.
	The isdigit() function returns nonzero if ch is a digit (0 through 9); otherwise 0 is returned.
#include <ctype.h>
int isdigit(int ch);
int isalpha(int ch);
Eg: 	if(isalpha(ch)) printf("%c is a letter\n", ch);
		if(isdigit(ch)) printf("%c is a digit\n", ch);


🔹 Helper Functions

Binary Mode: ios::binary

Function
Header
Purpose

Helper Functions (<cctype>, <cstdlib>)

isdigit(ch) → checks digit
isdigit(ch)
<cctype>
Returns true if ch is digit '0'-'9'

isalpha(ch) → checks letter
isalpha(ch)
<cctype>
Returns true if ch is letter

atoi(str) → converts string to integer
atoi(str)
<cstdlib>
Converts string to integer


✅ Key Takeaways
Concept
Why It Matters
Use ios::binary
For accurate, no-translation file I/O
Prefer getline()
Over get() — cleaner delimiter handling
Cast to (char*)
Required in read()/write() due to type safety
peek() & putback()
Enable smart, flexible input logic
gcount()
Know how much was actually read
flush()
Force immediate write when needed
💡 Use unformatted I/O when speed, precision, or binary data matters!

Let me know if you'd like a cheat sheet version!


 */




1. The next program will display the contents of any file on the screen. 
It uses the get()
function.
243TEACH YOURSELF
C++
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
char ch;
if( argc !=2)
{
cout << " Usage : PR <filename >\n";
return 1;
}
ifstream in( argv [1] , ios :: in | ios :: binary );
if (! in)
{
cout << " Cannot open file .\n";
return 1;
}
while (! in. eof ())
{
in. get (ch);
cout << ch;
}
in. close ();
return 0;
}



2. This program uses put() to write characters to a file until the user enters a dollar sign:
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
char ch;
if( argc !=2)
{
cout << " Usage : WRITE <filename >\n";
return 1;
}
ofstream out ( argv [1] , ios :: out | ios :: binary );
if (! out )
{
cout << " Cannot open file .\n";
244ADVANCED C++ I/O
9.3. UNFORMATTED, BINARY I/O
return 1;
}
cout << " Enter a $ to stop \n";
do
{
cout << ": ";
cin . get (ch);
out . put (ch);
}
while (ch != ’$’);
out . close ();
return 0;
}
Notice that the program uses get() to read characters from cin. This prevents leading
spaces from being discarded.







5. The following program first writes an array of double values to a file and then reads them
back. It also reports the number of characters read.
// Demonstrate gcount ()
# include <iostream >
# include <fstream >
using namespace std ;
int main ()
{
ofstream out (" test ", ios :: out | ios :: binary );
if (! out )
{
cout << " Cannot open output file .\n";
return 1;
}
double nums [4] = {1.1 , 2.2 , 3.3 , 4.4};
out . write (( char *) nums , sizeof ( nums ));
out . close ();
246ADVANCED C++ I/O
9.4. MORE UNFORMATTED I/O FUNCTIONS
ifstream in(" test ", ios :: in | ios :: binary );
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
in. read (( char *) &nums , sizeof ( nums )) ;
int i;
for (i =0; i <4; i ++)
cout << nums [i] << ’ ’;
cout << ’\n’;
cout << in. gcount () << " characters read \n";
in. close ();
return 0;
}



// ----  EXERCISES  ----
1. Rewrite  Example 4 and 6 in ch12_07_file_io_basics.cpp so that
they use get(), put(), read(), and/or write(). (Use whichever of these functions you
deem most appropriate.)


/* Example 4: Write a program that copies a text file and counts how many characters are copied.
                After displaying the count, explain why this number is different 
                from the file size shown in the directory.

            ans:
                The program may show a different character count than the file size 
                    because "character translation" occurs.
                
                When a "carriage return and line feed" are read, they are treated as a "single newline character".
                However, when written back to the file, this "newline" is converted again 
                    into a "carriage return and line feed", increasing the file size.

                Save the program as "ch12_07_file_io_basics_3.cpp" then compile, 
                    and finally execute following command

            CLI:
                ch12_07_file_io_basics_3 input.txt out3.txt
*/

// Copy a text file and display number of chars copied .
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        std::cout << " Usage : CPY <input> <output>\n";
        return 1;
    }

    std::ifstream fin(argv[1]);     // open input file .
    std::ofstream fout(argv[2]);    // create output file

    if(!fin) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    if(!fout) {
        std::cout << " Cannot open output file .\n";
        return 1;
    }

    char ch;
    unsigned count = 0;

    fin.unsetf(std::ios::skipws);    // do not skip spaces

    while(!fin.eof()) {
        fin >> ch;
        if(!fin.eof()) {
            fout << ch;
            count++;
        }
    }

    std::cout << " Number of bytes copied : " << count << '\n';

    fin.close();
    fout.close();

    return 0;
}




/* Example 6: Write a program that "counts the number of words" in a file. 
                For simplicity, assume that anything surrounded by whitespace is a word. 

                Save the program as "COUNT.cpp" then compile, 
                    and finally execute following command

            CLI:
                COUNT phone.txt
*/

// Word count
#include <iostream>
#include <fstream>
#include <cctype>

int main(int argc, char *argv[]) {
    if(argc !=2) {
        std::cout << "Usage : COUNT <input>\n";
        return 1;
    }

    std::ifstream in(argv [1]);

    if(!in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    int count = 0;
    char ch;

    in >> ch; // find first non-space char
    // after first non-space found, do not skip spaces
    in.unsetf(std::ios::skipws); // do not skip spaces

    while(!in.eof()) {
        in >> ch;
        if(isspace(ch)) {
            count++;
            while(isspace(ch) && !in.eof()) in >> ch;
        }
    }

    std::cout << " Word count : " << count << '\n';
    in.close();

    return 0;
}




2. Given the following class, write a program that outputs the contents of the class to a file.
Create an inserter function for this purpose.
class account
{
int custnum ;
char name [80];
double balance ;
public :
account ( int c, char *n, double b)
{
custom = c;
strcpy (name , n);
balance = b;
}
// create inserter here
};



1a. // Copy a file and display number of chars copied .
# include <iostream >
# include <fstream >
using namespace std ;
int main ( int argc , char * argv [])
{
if( argc !=3)
{
cout << " Usage : CPY <input > <output >\n";
return 1;
}
ifstream fin ( argv [1] , ios :: in | ios :: binary ); // open
input file
ofstream fout ( argv [2] , ios :: out | ios :: binary ); // create
output file
if (! fin )
{
cout << " Cannot open input file \n";
return 1;
}
if (! fout )
{
cout << " Cannot open output file \n";
return 1;
}
char ch;
unsigned count =0;
while (! fin . eof ())
{
fin . get (ch);
if (! fin . eof ())
{
fout . put (ch);
count ++;
530ANSWERS
9.3 EXERCISES
}
}
cout << " Number of bytes copied : " << count << ’\n’;
fin . close ();
fout . close ();
return 0;
}


1b. // Word count .
# include <iostream >
# include <fstream >
# include <cctype >
using namespace std ;
int main ( int argc , char * argv [])
{
if( argc !=2)
{
cout << " Usage : COUNT <input >\n";
return 1;
}
ifstream in( argv [1] , ios :: in | ios :: binary );
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
int count = 0;
char ch;
// find first non - space char
do
{
in. get (ch);
}
while ( isspace (ch));
while (! in. eof ())
{
in. get (ch);
if( isspace (ch))
{
count ++;
while ( isspace (ch) && !in.eof ())
in. get (ch); // find next word
531TEACH YOURSELF
C++
}
}
cout << " Word count : " << count << ’\n’;
in. close ();
return 0;
}
2. // Output account info to a file using an inserter .
# include <iostream >
# include <fstream >
# include <cstring >
using namespace std ;
class account
{
int custnum ;
char name [80];
double balance ;
public :
account ( int c, char *n, double b)
{
custnum = c;
strcpy (name , n);
balance = b;
}
friend ostream & operator <<( ostream &stream , account ob);
};
ostream & operator <<( ostream &stream , account ob)
{
stream << ob. custnum << ’ ’;
stream << ob. name << ’ ’ << ob. balance ;
stream << ’\n’;
return stream ;
}
int main ()
{
account Rex (1011 , " Ralph Rex ", 12323.34) ;
ofstream out (" accounts ", ios :: out | ios :: binary );
if (! out )
{
cout << " Cannot open output file .\n";
return 1;
}
532ANSWERS
9.4 EXERCISES
out << Rex ;
out . close ();
return 0;
}

