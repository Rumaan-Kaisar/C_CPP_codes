
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


// ----  rev[27-Jan-2026]  ----


==== codex ====



Example 1 (Save & Load Binary Data):
Following uses write() to write a double and a string to a file called test:


#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

int main(){ 	ofstream out(" test ", ios :: out | ios :: binary );
		if(!out ) { cout << " Cannot open output file .\n"; return 1; }	double num = 100.45;
char str[] = "This is a test";
out.write(( char *) &num, sizeof(double)) ;
out.write(str , strlen(str));
out.close();
return 0; }
	The type cast to (char *) inside the call to write() is necessary when outputting a buffer that is not defined as a character array. Because of C++'s strong type checking, a pointer of one type will not automatically be converted into a pointer of another type.




Example 2 (Saving and restoring exact binary value):

This program uses read() to read the file created by the program in Example 1:

	#include <iostream>
	#include <fstream>
	using namespace std;
int main() {	 ifstream in(" test ", ios :: in | ios :: binary );
		if (!in) { cout << " Cannot open input file .\n"; return 1; }
			double num;    char str[80];
in.read(( char *) &num , sizeof (double)) ;
in.read(str , 14) ;
str[14] = '\0 '; 		              // null terminate str
cout << num << ' ' << str ;
in. close(); 	return 0;}
	As is the case with the program in the preceding example, the type cast (char *) inside read() is necessary because C++ will not automatically convert a pointer of one type to another.





Example 3: Safe String Input with Spaces
Unlike >>, this doesn’t stop at space.

When you use >> to read a string, it stops reading when the first whitespace character is encountered. This makes it useless for reading a string containing spaces. getline() can resolve this problem:

	#include<iostream>
	#includ <fstream>
	using namespace std;	int main(){ 	char str[80];
		cout << " Enter your name : ";
		cin.getline(str , 79);
		cout << str << '\n';
		return 0; }

Here, the delimited used by getline() is the newline. This makes getline() act like the standard gets() function.




Example 4: Smart Input Using peek() and putback()

                Uses peek() to check type, then reads accordingly.
                Uses putback() to return unwanted character.

                Very useful for parsing mixed data.


In real programming situations, the functions peek() and putback() are especially useful because they let you more easily handle situations in which you do not know what type of information is being input at any point in time. The following program gives the flavor of this. It reads either strings or integers from a file. The strings and integers can occur in any order.

	#include <iostream >
	#include <fstream >
	#include <cctype >
	#include <cstdlib >
	using namespace std;

int main(){char ch;
	ofstream out("test", ios::out | ios::binary );
	if(!out ){ cout << "Cannot open output file .\n";
		return 1; } 	       // confirmation

	char str[80], *p;
	out << 123 << "this is a test" << 23;
	out << "Hello there !" << 99 << "sdf" << endl;
	out.close(); 		   // closing 1st time
	ifstream in("test", ios::in | ios::binary);
if(!in) { 	cout << "Cannot open input file .\n";
	return 1; } // confirmation

do{ p = str;
       ch = in.peek(); 			// see what type of char is next
       if(isdigit(ch)){ while(isdigit( *p=in.get() ))   p++;	        // read integer
		in.putback(*p); 		           // return char to stream
		*p = '\0 '; 		    // null - terminate the string
		cout << " Integer : " << atoi(str ); }

       else if(isalpha(ch)){while(isalpha*p=in.get() ))  p++;    // read a string
		            in.putback (*p);
		            *p = '\0 ';
		            cout << " String : " << str ; }
       else	in.get(); 						// ignore 
       cout << '\n'; }  while (! in.eof());
in.close(); 					   // final file closing 
return 0; }


	The atoi() is one of C's standard library function, it returns the integer equivalent of the number represented by its string argument.
	The isalpba() function returns nonzero if ch is a letter of the alphabet; otherwise 0 is returned.
	The isdigit() function returns nonzero if ch is a digit (0 through 9); otherwise 0 is returned.
#include <ctype.h>
int isdigit(int ch);
int isalpha(int ch);
Eg: 	if(isalpha(ch)) printf("%c is a letter\n", ch);
		if(isdigit(ch)) printf("%c is a digit\n", ch);




----  QWEN  ----







🔹 Helper Functions
Function
Header
Purpose
isdigit(ch)
<cctype>
Returns true if ch is digit '0'-'9'
isalpha(ch)
<cctype>
Returns true if ch is letter
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





----  GPT  ----

Below is a simplified, middle-ground explanation of Section 12.8: Unformatted I/O & Binary I/O, keeping the important details without overloading.




🔹 Binary Mode: ios::binary









🔹 Type Casting in read() / write()

Buffers must be cast to (char*)

Required due to C++ strong type checking

Prevents unsafe pointer conversions




🔹 Why getline() Solves Space Issues

>> stops at whitespace

getline() reads full lines including spaces

Acts like the old C gets() but safely




🔹 Smart Parsing with peek() and putback()

Useful when integers and strings are mixed

peek() checks what comes next

putback() restores unwanted characters

Enables flexible input handling




🔹 Helper Functions (<cctype>, <cstdlib>)

isdigit(ch) → checks digit

isalpha(ch) → checks letter

atoi(str) → converts string to integer

✅ Key Takeaways

Use unformatted I/O for speed and accuracy

Use ios::binary for reliable binary storage

Prefer getline() for text with spaces

Use peek() + putback() for intelligent parsing

Use gcount() to verify read size

Use flush() when immediate output matters

This keeps the conceptual clarity while preserving the technical correctness expected at this level.


*/  
