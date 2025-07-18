
/*  ------------------------    C++ I/O Stream    ------------------------
    The C++ I/O system, like the C I/O system, operates through streams. 

    Some important points about streams are:
        A stream is a logical channel that sends or receives data.
        The C++ I/O system connects a stream to a physical device (like a file, screen, or printer).
        All streams work the same way, no matter which device they're connected to.
        For example, the same output function can send data to a screen, a file, or a printer.




	Predefined streams of C++: when a C program begins execution, three predefined streams are automatically opened: stdin, stdout, and stderr. Similarly when a C++ program begins, these four streams are automatically opened:
Stream	Meaning	Default Devices	Stream	Meaning	Default Devices
cin	Standard input	Keyboard	cerr	Standard error	Screen
cout	Standard output	Screen	clog	Buffered version of cerr	Screen
	The streams cin, cout, and cerr correspond to C's stdin, stdout, and stderr. clog is buffered version of cerr.
	Standard C++ also opens wide (16-bit) character versions of these streams called wcin, wcout, wcerr, and wclog.
	By default, the standard streams are used to communicate with the console. However, in proper environments these streams can be redirected to other devices.


Predefined Streams in C++:
Automatically opened streams in C++ at program start:

cin → standard input (keyboard)

cout → standard output (screen)

cerr → standard error (unbuffered, screen)

clog → buffered error output (screen)

Correspondence with C streams:

cin ↔ stdin

cout ↔ stdout

cerr ↔ stderr

clog → extra in C++, buffered version of cerr

Wide character versions also exist:

wcin, wcout, wcerr, wclog — for 16-bit character input/output

Default behavior:

These streams use the console (keyboard/screen) by default

They can be redirected to files or other devices in the right setup






	<iostream> and template classes: C++ provides support for its I/O system in the header file <iostream>. In this file, a rather complicated set of class hierarchies is defined that supports I/O operations.
	The I/O classes begin with a system of template classes. 
	Template classes/ generic classes: Template classes, also called generic classes (will be discussed in next Chapter). Briefly, a template class defines the form of a class without fully specifying the data upon which it will operate. Once a template class has been defined, specific instances of it can be created. 
	Standard C++ creates 2 specific versions of the I/O template classes: one for 8-bit characters and another for wide characters.


<iostream> and Template Classes in C++ I/O:
The <iostream> header provides support for C++ input/output.

It defines a complex class hierarchy for handling I/O.

The I/O system starts with template (generic) classes.

A template class defines a general structure without fixing the data type.

Later, specific versions (instances) of that class can be created with actual types.

C++ creates two versions of its I/O template classes:

One for 8-bit (normal) characters

One for wide (16-bit) characters







	The C++ I/O system is build upon two related, but different, template class hierarchies. 
	basic_streambuf: Derived from the low-level I/O class. This class supplies the basic, low-level input and output operations and provides the underlying support for the entire C++ I/O system. It is used in advanced I/O programming.
	basic_ios: The class hierarchy that you will most commonly be working with is derived from basic_ios. This is a high-level I/O class that provides: formatting, error-checking, and status information related to stream I/O. 
	basic_ios is used as a base for several derived classes, including : 
1:	basic_istream	2:	basic_ostream	3:	basic_iostream
These classes are used to create streams capable of input, output, and input/output, respectively.


C++ I/O Class Hierarchy (Simplified):
The C++ I/O system is built on two related template class hierarchies:

A. basic_streambuf (low-level)
Handles raw input/output operations

Forms the foundation of the I/O system

Used in advanced I/O programming

B. basic_ios (high-level)
Adds support for:

Formatting

Error-checking

Stream status info

Most of our work in C++ I/O is based on this class

basic_ios is the base for these key classes:

Class	Purpose
basic_istream	Input stream
basic_ostream	Output stream
basic_iostream	Input + Output stream






	The following character-based names will be used throughout the remainder of this note.
Template Class	8-Bit Character-Based Class	Template Class	8-Bit Character-Based Class
basic_ios		ios	basic_streambuf		streambuf
basic_istream		istream	basic_fstream		fstream
basic_ostream		ostream	basic_ifstream		ifstream
basic_iostream		iostream	basic_ofstream		ofstream

Note:
1:	If you include <iostream> in you program, you will have access to ios class.
2:	The ios class contains many member functions and variables that control or monitor the fundamental operation of a stream. 


Character-Based Class Names in C++ I/O:
C++ uses template classes for I/O, but provides shorter 8-bit versions for regular use.

Template Class	8-bit Character-Based
basic_ios	ios
basic_istream	istream
basic_ostream	ostream
basic_iostream	iostream
basic_streambuf	streambuf
basic_fstream	fstream
basic_ifstream	ifstream
basic_ofstream	ofstream

Notes:
Including <iostream> gives access to the ios class and other I/O types.

The ios class has many built-in functions and variables to:

Control stream behavior

Monitor stream status


*/  


