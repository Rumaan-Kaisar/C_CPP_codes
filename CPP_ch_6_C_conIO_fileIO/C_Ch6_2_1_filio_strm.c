6.8 STREAMS for file I/O in C
The stream and the file : The C I/O system supplies a consistent interface to the programmer, independent of the actual I/O device being used. To accomplish this, C provides a level of abstraction between the programmer and the hardware. This abstraction is called a stream.

	The actual device providing I/O is called a file. A file is the actual physical entity that receives or supplies the data. As C defines the term file, it can refer to a disk file, the screen, the keyboard, memory, a port, a file on tape, and various other types of I/O devices. The most common form of file is, of course, the disk file.

	In C, disk I/O (like certain other types of I/O) is performed through a logical interface called a stream. All streams have similar properties, and all are operated on by the same I/O functions, no matter what type of file the stream is associated with. A stream is a logical interface to a file.  Although files differ in form and capabilities, all streams are the same. The advantage to this approach is that to the programmer, one hardware device will look much like any other. The stream automatically handles the differences. A stream is linked to a file using an open operation. A stream is disassociated from a file using a close operation.

	There are two types of streams: text and binary. 
	A text stream contains ASCII characters. When a text stream is being used, some character translations may take place. For example, when the newline character is output, it is usually converted into a carriage return, linefeed pair. For this reason, there may not be a one-to-one correspondence between what is sent to the stream and what is written to the file (ASCII-text).

	A binary stream may be used with any type of data. No character translations will occur, and there is a one-to-one correspondence between what is sent to the stream and what is actually contained in the file.

Current location : One final concept you need to understand is that of the current location. The current location, also referred to as the current position, is the location in a file where the next file access will occur. For example, if a file is 100 bytes long and half the file has been read, the next read operation will occur at byte 50, which is the current location.

Details on STREAM
Conceptually, the C program deals with a stream instead of directly with a file. A stream is an idealized flow of data to which the actual input or output is mapped. That means various kinds of input with differing properties are represented by streams with more uniform properties. The process of opening a file then becomes one of associating a stream with the file, and reading and writing take place via the stream.

Streams : Streams enable the device-independent input and output. Input and output, whether to or from physical devices such as terminals and tape drives, or whether to or from files supported on structured storage devices, are mapped into logical data streams, whose properties are more uniform than their various inputs and outputs. Two forms of mapping are supported: text streams and binary streams.

text streams :  A text stream consists of one or more lines. A line in a text stream consists of zero or more characters plus a terminating new-line character.  That's what any program expects when it reads text, and that's what any program produces when it writes text. The string of characters that go into, or come out of a text stream may have to be modified to conform to specific conventions. This results in a possible difference between the data that go into a text stream and the data that come out (not one-one correspondent). For instance, in some implementations when a space-character precedes a new-line character in the input, the space character gets removed out of the output. In general, when the data only consists of printable characters and control characters like horizontal tab and new-line, the input and output of a text stream are equal.

binary streams : Compared to a text stream, a binary stream is pretty straight forward. A binary stream is an ordered sequence of characters that can transparently record internal data. Data written to a binary stream shall always equal the data that gets read out under the same implementation (one-one correspondence). Binary streams, however, may have an implementation-defined number of null characters appended to the end of the stream.

Note
[1]	In C all input and output is done with streams.
[2]	Stream is nothing but the sequence of bytes of data.
[3]	A sequence of bytes flowing into program is called input stream.
[4]	A sequence of bytes flowing out of the program is called output stream.
[5]	Use of Stream make I/O machine independent.
[6]	Predefined Streams:
stdin	Standard Input
stdout	Standard Output
stderr	Standard Error
 

( a )	Standard Input Stream Device :
	stdin stands for (Standard Input)
	Keyboard is standard input device .
	Standard input is data (Often Text) going into a program.
	The program requests data transfers by use of the read operation.
	Not all programs require input.


( b )	Standard Output Stream Device :
	stdout stands for (Standard Output)
	Screen(Monitor) is standard output device .
	Standard output is data (Often Text) going out from a program.
	The program sends data to output device by using write operation.

 
Difference Between Std. Input and Output Stream Devices
Point	Std i/p Stream Device	Standard o/p Stream Device
Stands For	Standard Input	Standard Output
Example	Keyboard	Screen/Monitor
Data Flow	Data (Often Text) going into a program	data (Often Text) going out from a program
Operation	Read Operation	Write Operation

Some Important Summary:
Point	Input Stream	Output Stream
Standard Device 1	Keyboard	Screen
Standard Device 2	Scanner	Printer
IO Function	Scanf() and gets()	Printf() and puts()
IO Operation	Read	Write
Data	Data goes from stream	data comes into stream


