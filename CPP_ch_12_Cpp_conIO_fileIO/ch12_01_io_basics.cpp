
/*  ------------------------    chapter    ------------------------



12.1 C++ I/O Stream
	C++ I/O stream:  The C++ I/O system, like the C I/O system, operates through streams. Some important points about streams are:
	A stream is a logical device that either produces or consumes information. 
	A stream is linked to a physical device by the C++ I/O system. 
	All streams behave in the same manner, even if the actual physical devices they are linked to differ. For example, the same function that you use to write to the screen can be used to write to a disk file or to the printer.
	Predefined streams of C++: when a C program begins execution, three predefined streams are automatically opened: stdin, stdout, and stderr. Similarly when a C++ program begins, these four streams are automatically opened:
Stream	Meaning	Default Devices	Stream	Meaning	Default Devices
cin	Standard input	Keyboard	cerr	Standard error	Screen
cout	Standard output	Screen	clog	Buffered version of cerr	Screen
	The streams cin, cout, and cerr correspond to C's stdin, stdout, and stderr. clog is buffered version of cerr.
	Standard C++ also opens wide (16-bit) character versions of these streams called wcin, wcout, wcerr, and wclog.
	By default, the standard streams are used to communicate with the console. However, in proper environments these streams can be redirected to other devices.
	<iostream> and template classes: C++ provides support for its I/O system in the header file <iostream>. In this file, a rather complicated set of class hierarchies is defined that supports I/O operations.
	The I/O classes begin with a system of template classes. 
	Template classes/ generic classes: Template classes, also called generic classes (will be discussed in next Chapter). Briefly, a template class defines the form of a class without fully specifying the data upon which it will operate. Once a template class has been defined, specific instances of it can be created. 
	Standard C++ creates 2 specific versions of the I/O template classes: one for 8-bit characters and another for wide characters.
	The C++ I/O system is build upon two related, but different, template class hierarchies. 
	basic_streambuf: Derived from the low-level I/O class. This class supplies the basic, low-level input and output operations and provides the underlying support for the entire C++ I/O system. It is used in advanced I/O programming.
	basic_ios: The class hierarchy that you will most commonly be working with is derived from basic_ios. This is a high-level I/O class that provides: formatting, error-checking, and status information related to stream I/O. 
	basic_ios is used as a base for several derived classes, including : 
1:	basic_istream	2:	basic_ostream	3:	basic_iostream
These classes are used to create streams capable of input, output, and input/output, respectively.
	The following character-based names will be used throughout the remainder of this note.
Template Class	8-Bit Character-Based Class	Template Class	8-Bit Character-Based Class
basic_ios		ios	basic_streambuf		streambuf
basic_istream		istream	basic_fstream		fstream
basic_ostream		ostream	basic_ifstream		ifstream
basic_iostream		iostream	basic_ofstream		ofstream

Note:
1:	If you include <iostream> in you program, you will have access to ios class.
2:	The ios class contains many member functions and variables that control or monitor the fundamental operation of a stream. 



*/  
