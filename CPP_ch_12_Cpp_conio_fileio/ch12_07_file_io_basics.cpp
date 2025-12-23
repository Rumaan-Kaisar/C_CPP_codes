
/*  ------------------------    File I/O in C++    ------------------------

    The same class hierarchy that supports "CONSOLE I/O" also supports "FILE I/O".  


    --------  File I/O Basics  --------

    To use file I/O, include:

                #include <fstream>

        It defines several classes, including:

            ifstream    -   for input (reading from file)
            ofstream    -   for output (writing to file)
            fstream     -   for both input and output

            These are derived from "istream" and "ostream", 
            And "istream", "ostream" are derived fron "ios".
            So, they inherit all the features of standard I/O streams.

    So ifstream, ofstream, and fstream also have access to all operations defined by ios.



    ----------------    Opening Files    ----------------

    In C++, a file is opened by "linking it to a STREAM". 
    Before you can open a file, you must first obtain a STREAM.  

    There are three types of streams: 

        input:
            To create an input stream, declare an object of type "ifstream".

        output:
            To create an output stream, declare an object of type "ofstream". 

        input/output:
            Streams that will be performing "both input and output operations" 
            must be declared as objects of type "fstream". 

    Example:
        Following fragment creates an input stream, an output stream, and 
        one stream capable of both input and output:

                ifstream in;        // input
                ofstream out;       // output
                fstream io;         // input and output



    --------  Associate STREAM with a file  --------

    Use the open() function to associate a STREAM with a file.
    open() is a member of each ifstream, ofstream, and fstream. 
    
    The prototype for each:

        void ifstream :: open(const char *filename, openmode mode = ios::in);
        void ofstream :: open(const char *filename, openmode mode = ios::out | ios::trunc );
        void fstream :: open(const char *filename, openmode mode = ios::in | ios::out);

        Parameters:
            filename: name or path of the file.
            mode: defines how the file is opened (using flags from ios).

            It must be a value of type "openmode", which is an enumeration defined by "ios" 
                that contains the following "File Opening Modes".


    --------  File Opening Modes  --------

    ----------------------------------------------------------------
    Mode            Meaning

    ios::app        Append new data at end of file.
                    This value can be used only with files capable of output.
    
    ios::ate        Move pointer to end-of-file when the file is opened 
                    (I/O can still occur anywhere within the file).

    ios::binary     Open file in binary mode.
                    In binary mode no character translations (carriage return/linefeed sequences) will occur.
                    (text is default IO mode)
    
    ios::in         Open file for input (reading).
    
    ios::out        Open file for output (writing).
    
    ios::trunc      Delete old contents if file already exists.
                    the file to be truncated to zero length.
    
    ----------------------------------------------------------------

    These modes can be combined using the bitwise OR operator (|).


    NOTE:
        Above six values can be combined using OR.

        default truncation:
            When output stream using "ofstream" created, 
            any preexisting file with the same name is automatically truncated.

    Example: 
        The following fragment opens an output file called "test":

                    ofstream mystream;
                    mystream.open("test");

            we can also sepecify the file extension:

                    ofstream mystream;
                    mystream.open("test.txt");

    Since the mode parameter to open() defaults to a value appropriate to the type of stream being opened, 
        there is no need to specify its value in the preceding example.


    --------  Confirmation test  --------
    If open() fails, the stream will evaluate to "false" when used in a Boolean expression. 
    Which can be used in a confirmation test (consider previous Example):    

    You can check using:

            if(!mystream) {
                cout << "Cannot open file.\n";
                // handle error
            }
    or
            if(!mystream.is_open()) {
                cout << "File is not open.\n";
                . . .
            }

        is_open() returns "true" if stream is linked to an open file and "false" otherwise.


    Note:
        Always check the result of a call to open() before attempting to access the file.
        Use the is_open() function to see if a file successfully opened.
        is_open() is a member of fstream, ifstream, and ofstream. 
        It has this prototype:	 
                    bool is_open();


    --------  Bypass the open() function  --------

    Because the ifstream, ofstream, and fstream classes have constructors 
        that automatically open the file. 
        And those constructors have the same parameters and defaults as the open().

        Therefore, Instead of using open(), you can open files directly when declaring:

                ifstream mystream("myfile.txt");    // open file for reading

    
    Still use confirmation test:
        If file opening failed, the "stream" variable will evaluate as false 
        when used in a conditional/Boolean statement. 

                if(!mystream) cout << "Cannot open file.\n";


----  rev[07-Dec-2025]  ----

    ----------------    closing a file    ----------------

    To close a file, use the member function close(). 
    For example, to close the file linked to a stream called "mystream":

                mystream.close();

        The close() function takes no parameters and returns no value.


    ----  eof  ----

    Use the eof() member function of "ios" to detect when the "end-of-input-file" has been reach. 
        It has this prototype:

                bool eof();

        It returns "true" when the end-of-file has been "encountered" and "false" otherwise.


    ----  text I/O  ----
    To read/write textual data from/to an opened file use "<<" and ">>" operators 
    (more like C's fprintf() and fscanf()).

    just like console I/O:

                f_out << "Hello\n";
                f_in >> str;

        A file produced by using << is a "formatted text file". 
        A file read by >> must be a "formatted text file." 

        Typically, formatted text files are operated through the >> and << operators. 
        They are not for binary mode.  

        Binary mode is best used on UNFORMATTED files.
*/  




/* Example 2: Following creates an output file, write information to it, closes the file 
                and opens it again as an input file, and reads in the information.

                When the << and >> operators are used to perform file I/O, 
                    information is formatted exactly as it would appear on the screen.

                Here’s a clear and simplified explanation of your note on C++ File I/O (Input/Output):
*/

#include <iostream>
#include <fstream>

int main(){
    // ----  create  ----
    std::ofstream f_out("test");     // create output file

    // confirmation test
    if(!f_out){
        std::cout << "Cannot open output file .\n";
        return 1;   //notice !f_out Boolean!!!
    }

    f_out << "Hello!\n";   // using space in between will create a issue: "Hello !\n"
    // if we use a space ' ' like in "Hello !\n", then '!' is treated as a number
    f_out << 100 << ' ' << std::hex << 100 << std::endl ;
    f_out.close();  //closing the created file 	

    // ----  open  ----
    std::ifstream f_in("test"); //open input file

    if(!f_in ){ 
        std::cout << "Cannot open input file .\n";
        return 1; 
    }

    char str[80];
    int i, j;   // to print the hex value, use another variable 'j'

    f_in >> str >> i;
    std::cout << str << ' ' << i << std::endl ;
    // f_in >> str >> i >> j;
    // std::cout << str << ' ' << i << ' ' << j << std::endl ;
    f_in.close();   //closing the opened file

    return 0; 
}


/*  ----------------    Explanation    ----------------

    It Writes "Hello!" and two integers (100 and 100 in hex).
        Then reopens the same file and reads the first two items.

    Output on console:

                Hello! 100 64


    --------  why "Hello !" breaks it?  --------
    There is a "space" between Hello and !

    So operator '>>' tokenizes like this:

        "Hello"      ← token 1
        "!"          ← token 2
        "100"        ← token 3
        "64"         ← no token


    Now look at our read statement:

        f_in >> str >> i >> j;


    This becomes:

        Variable    What it tries to read       Token it sees       Result
        --------------------------------------------------------------------------------
        str         string token                "Hello"             OK
        i           integer token               "!"                 ❌ FAIL (not a number)
        j           integer token               "100"               NOT read because stream is in failed state
        -           no token                    "64"                NOT read


    So, following fragment will fail if "Hello !" is used:

                char str[80];
                int i, j;   // to print the hex value, use another variable 'j'

                f_in >> str >> i >> j;
                std::cout << str << ' ' << i << ' ' << j << std::endl ;

    following will solve the problem:

                char str[80], c;    // new char variable for '!'
                int i, j;   // to print the hex value, use another variable 'j'

                f_in >> str >> c >> i >> j;
                std::cout << str << ' ' << c << ' ' << i << ' ' << j << std::endl ;
*/




/* Example 2: Following program reads strings entered at the keyboard and writes them to disk (disk I/O). 
                The program stops when the user enters a '$' as the first character in a string.

                To use the program, specify the name of the output file on the command line.
                [Recall "C_Ch5_3_2_main_param.c" for Command-line argument] 


                save the program as "ch12_07_file_io_basics_1.cpp" after compile, 
                    in CLI execute following (in the directory where program compiled)

                        ch12_07_file_io_basics_1 output.txt

                then it ask for input and '$' to stop
*/

#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if(argc != 2){
        std::cout << " Usage : WRITE <filename >\n";
        return 1;
    }

    std::ofstream out(argv[1]) ; // output file

    if(!out){
        std::cout << " Cannot open output file .\n";
        return 1;
    }

    char str[80];

    std::cout << " Write strings to disk , '$' to stop \n";
    // writing to disk
    do{
        std::cout << ": ";
        std::cin >> str;
        out << str << std::endl;
    } while (*str != '$');
    
    out.close();

    return 0;
}


// ----  rev[16-Dec-2025]  ----


/* Example 3: Following is a program that "copies a text file" and, in the process, 
                converts all spaces into '|' symbols.

                Notice how eof() is used to check for the "end of input file". 

                Notice also how the input stream "f_in" has its "skipws" flag turned off. 
                    This prevents leading spaces from being skipped.
*/

// Convert spaces to |s.
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if(argc != 3) {
        std::cout << " Usage : CONVERT <input> <output>\n";
        return 1;
    }

    std::ifstream f_in(argv[1]);     // open input file
    std::ofstream f_out(argv[2]);    // create output file

    if(!f_out) {
        std::cout << " Cannot open output file.\n";
        return 1;
    }

    if(!f_in) {
        std::cout << " Cannot open input file .\n";
        return 1;
    }

    char ch;
    
    f_in.unsetf(std::ios::skipws ); // do not skip spaces
    while(!f_in.eof()) {
        f_in >> ch;
        if(ch == ' ') ch = '|';
        if(!f_in.eof()) f_out << ch;
    }

    f_in.close();
    f_out.close();

    return 0;
}



/* Example 4: There are some differences between C++’s "old I/O library" and the modern "Standard C++ library", 
                especially important when you updating or converting older code.


First, in the original I/O library, open() allowed a third parameter, which specified the
file’s protection mode. This parameter defaulted to a normal file. The modern I/O library
does not support this parameter.

Second, when you are using the old library to open a stream for input and output using
fstream, you must explicitly specify both the ios::in and the ios::out mode values. No
default value for mode is supplied. This applies to both the fstream constructor and to
its open() function. For example, using the old I/O library you must use a call to open()
as shown here to open a file for input and output:


fstream mystream ;
mystream . open (" test ", ios :: in | ios :: out);
In the modern I/O library, an object of type fstream automatically opens files for input
and output when the mode parameter is not supplied.
Finally, in the old I/O system, the mode parameter could also include either ios::nocreate(),
which causes the open() function to fail if the file does not already exist, or ios::noreplace,
which causes the open() function to fail if the file does not already exist. These values
are not supported by Standard C++
*/








/* Example 1: Write a program that will copy a text file. Have this program count the number of
characters copied and display this result. Why does the number displayed differ from that
shown when you list the output file in the directory? */

// Copy a text file and display number of chars copied .
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
ifstream fin ( argv [1]) ; // open input file .
ofstream fout ( argv [2]) ; // create output file
if (! fin )

{
cout << " Cannot open input file .\n";
return 1;
}
if (! fout )
{
cout << " Cannot open output file .\n";
return 1;
}
char ch;
unsigned count = 0;
fin . unsetf ( ios :: skipws ); // do not skip spaces
while (! fin . eof ())
{
fin >> ch;
if (! fin . eof ())
{
fout << ch;
count ++;
}
}
cout << " Number of bytes copied : " << count << ’\n’;
fin . close ();
fout . close ();
return 0;
}
The reason this program might display a result different from that shown when you list
the directory is that some character translations might be taking place. Specifically, when
a carriage-return/linefeed sequence is read, it is converted into a newline. When output,
newlines are counted as one character but converted back into a carriage-return/linefeed
sequence again.




/* Example 2: Write a program that writes the following table of information to a file called phone:
Isaac Newton, 415 555-3423
Robert Goddard, 213 555-2312
Enrico Fermi, 202 555-1111 */
# include <iostream >
# include <fstream >
using namespace std ;
int main ()
{
ofstream pout (" phone ");
if (! pout )
{
cout << " Cannot open PHONE file .\n";
return 1;
}

pout << " Isaac Newton 415 555 -3423\ n";
pout << " Robert Goddard 213 555 -2312\ n";
pout << " Enrico Fermi 202 555 -1111\ n";
pout . close ();
return 0;
}



/* Example 3: Write a program that counts the number of words in a file. For simplicity, assume that
anything surrounded by whitespace is a word. */

// Word count
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
ifstream in( argv [1]) ;
if (! in)
{
cout << " Cannot open input file .\n";
return 1;
}
int count = 0;
char ch;
in >> ch; // find first non - space char
// after first non - space found , do not skip spaces
in. unsetf ( ios :: skipws ); // do not skip spaces
while (! in. eof ())
{
in >> ch;
if( isspace (ch))
{
count ++;
while ( isspace (ch) && !in.eof ())
in >> ch;
}
}

cout << " Word count : " << count << ’\n’;
in. close ();
return 0;
}




/* Example 4: What does is open() do? */

The is open() function returns true if the invoking stream is linked to an open file.

