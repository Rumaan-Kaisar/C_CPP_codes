
/*  ------------------------    chapter    ------------------------


12.8 UNFORMATTED I/O & BINARY I/O
Unformatted files contain the same binary representation of the data as that used internally by your program (rather than text data which is translated into by the << and >>). Thus, unformatted functions give you detailed control over how files are written and read.
	Lowest-level unformatted I/O: The lowest-level unformatted I/O functions are get() and put(). get() is used to read a byte and put()is used to write a byte. These are members of all I & O stream classes respectively.  Common version of get() & put() :
istream &get(char &ch);
ostream &put(char &ch);
	get() reads a single character from the associated stream and puts that value in ch. 
	It returns a reference to the stream. 
	If a read is attempted at end-of-file, on return the invoking stream will evaluate to false in Boolean expression. 
	put()  writes ch to the stream and returns a reference to the stream.
	Overloading get(): There are several different ways in which the get() function is overloaded. The prototypes for the three most commonly used overloaded forms are:
istream &get(char *buf, streamsize num);
istream &get(char *buf, streamsize num, char delim);
int get();
	The first form reads characters into the array pointed to by buf until either num-1 characters have been read, a newline is found, or the end-of-file has been encountered. 
	They array pointed to by buf will be null terminated by get(). 
	If the newline character is encountered in the input stream, it is not extracted (inputted). Instead, it remains in the stream until the next input operation.
	The second form reads characters into the array pointed to by buf until either num-1 characters have been read, the character specified by delim has been found, or the end-of-file has been encountered.
	The array pointed to by buf will be null terminated by get(). 
	If the delimiter character is encountered in the input stream, it is not extracted (inputted). Instead, it remains in the stream until the next input operation.
	Note (Delimiter character): A delimiter is one or more characters that separate text strings. Common delimiters are commas(,), semicolon(;), quotes(",'), braces({}), pipes(|), or slashes(/ \). Newline character is also a delimiter. 
	The third form of get() returns the next character from the stream. It returns EOF if the end-of-file is encountered. This form of get() is similar to C's getc() function.
	getline() with overloaded form: getline() is another input function. It is a member of each input stream class. Its prototypes:
istream &getline(char *buf, streamsize num);
istream &getline(char *buf, streamsize num, char delim);
	The first form reads characters into the array pointed to by buf until either num-1 characters have been read, a newline is found, or the end-of-file has been encountered. 
	They array pointed to by buf will be null terminated by getline(). 
	If the newline character is encountered in the input stream, it is extracted (inputted), but it is not put into buf.
	The second form reads characters into the array pointed to by buf until either num-1 characters have been read, the character specified by delim has been found, or the end-of-file has been encountered.
	The array pointed to by buf will be null terminated by getline(). 
	If the delimiter character is encountered in the input stream, it is extracted (inputted), but it is not put into buf.
	Comparison between get() and getline(): The two versions of getline() are virtually identical to the get(buf, num) and get(buf, num, delim) versions of get(). 
	The difference between get() and getline() is that getline() reads and removes the delimiter from the input stream; get() does not.
	Data blocks I/O: To read and write blocks of data, use the read() and write() functions, which are also members of the I & O stream classes, respectively. Their prototypes are:
istream &read (char *buf, streamsize num);
ostream &write (const char *buf, streamsize num);
	read() reads num bytes from the invoking stream and puts them in the buffer pointed to by buf. 
	write() writes num bytes to the associated stream from the buffer pointed to by buf. 
	streamsize type is some form of integer. An object of type streamsize is capable of holding the largest number of bytes that will be transferred in any one I/O operation.
	If the end-of-file is reached before num characters have been read, read() simply stops, and the buffer contains as many characters as were available. 
	gcount(): You can find out how many characters have been read by using the member function gcount(). The prototype is:
streamsize gcount();
	It returns the number of characters read by the last unformatted input operations.
	peek(): Use peek() to obtain the next character in the input stream without removing it from that stream . It is a member of the input stream classes and has this prototype:
int peek();
	It returns the next character in the stream.		It returns EOF if the end-of-file is encountered.
	putback():Use putback() to return the last character read from a stream to that stream. It is a member of the input stream classes. Its prototype is:
istream &putback(char c);
	Where c is the last character read.
	flush(): When output is performed, data is not immediately written to the physical device linked to the stream. Instead, information is stored in an internal buffer until the buffer is full. Only then are the contents of that buffer written to disk. 
	By calling flush() you can force the information to be physically written to disk before the buffer is full.  flush() is a member of the output stream classes and has this prototype:
ostream &flush();
	Calls to flush() might be warranted when a program is going to be used in adverse environments (in situations where power outages occur frequently, for example).
	ios :: binary: For unformatted file I/O we always use binary operation (rather than text operations >> <<).
	specifying ios::binary prevents any character translations from occurring. This is important when the binary representations of data such as integers, float, and pointers are stored in the file. 
	However, it is perfectly acceptable to use the unformatted functions on a file opened in text mode, but remember, some character translations may occur.
	Example 1: Following uses write() to write a double and a string to a file called test:

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
	Example 2: This program uses read() to read the file created by the program in Example 1:

	#include <iostream>
	#include <fstream>
	using namespace std;
int main() {	 ifstream in(" test ", ios :: in | ios :: binary );
		if (!in) { cout << " Cannot open input file .\n"; return 1; }
			double num;    char str[80];
in.read(( char *) &num , sizeof (double)) ;
in.read(str , 14) ;
str[14] = '\0 '; 		              /* null terminate str */ 
cout << num << ' ' << str ;
in. close(); 	return 0;}
	As is the case with the program in the preceding example, the type cast (char *) inside read() is necessary because C++ will not automatically convert a pointer of one type to another.
	Example 3: When you use >> to read a string, it stops reading when the first whitespace character is encountered. This makes it useless for reading a string containing spaces. getline() can resolve this problem:

	#include<iostream>
	#includ <fstream>
	using namespace std;	int main(){ 	char str[80];
		cout << " Enter your name : ";
		cin.getline(str , 79);
		cout << str << '\n';
		return 0; }
	Here, the delimited used by getline() is the newline. This makes getline() act like the standard gets() function.
	Example 4: In real programming situations, the functions peek() and putback() are especially useful because they let you more easily handle situations in which you do not know what type of information is being input at any point in time. The following program gives the flavor of this. It reads either strings or integers from a file. The strings and integers can occur in any order.

	#include <iostream >
	#include <fstream >
	#include <cctype >
	#include <cstdlib >
	using namespace std;

int main(){char ch;
	ofstream out("test", ios::out | ios::binary );
	if(!out ){ cout << "Cannot open output file .\n";
		return 1; } 	       /* confirmation */

	char str[80], *p;
	out << 123 << "this is a test" << 23;
	out << "Hello there !" << 99 << "sdf" << endl;
	out.close(); 		   /* closing 1st time */
	ifstream in("test", ios::in | ios::binary);
if(!in) { 	cout << "Cannot open input file .\n";
	return 1; } /* confirmation */

do{ p = str;
       ch = in.peek(); 			/* see what type of char is next */ 
       if(isdigit(ch)){ while(isdigit( *p=in.get() ))   p++;	        /* read integer */ 
		in.putback(*p); 		           /* return char to stream */ 
		*p = '\0 '; 		    /* null - terminate the string */ 
		cout << " Integer : " << atoi(str ); }

       else if(isalpha(ch)){while(isalpha*p=in.get() ))  p++;    /* read a string */ 
		            in.putback (*p);
		            *p = '\0 ';
		            cout << " String : " << str ; }
       else	in.get(); 						/* ignore */ 
       cout << '\n'; }  while (! in.eof());
in.close(); 					   /* final file closing */
return 0; }
	The atoi() is one of C's standard library function, it returns the integer equivalent of the number represented by its string argument.
	The isalpba() function returns nonzero if ch is a letter of the alphabet; otherwise 0 is returned.
	The isdigit() function returns nonzero if ch is a digit (0 through 9); otherwise 0 is returned.
#include <ctype.h>
int isdigit(int ch);
int isalpha(int ch);
Eg: 	if(isalpha(ch)) printf("%c is a letter\n", ch);
		if(isdigit(ch)) printf("%c is a digit\n", ch);


*/  
