
/*  ------------------------    C++ I/O Stream    ------------------------
    The C++ I/O system, like the C I/O system, operates through streams. 

    Some important points about streams are:
        A stream is a logical channel that sends or receives data.
        The C++ I/O system connects a stream to a physical device (like a file, screen, or printer).
        All streams work the same way, no matter which device they're connected to.
        For example, the same output function can send data to a screen, a file, or a printer.



    ----------------    Predefined Streams in C++    ----------------

    Three predefined streams "automatically" opened, when a "C program" begins execution:
            stdin
            stdout
            stderr

    Similarly when a C++ program begins, these four streams are automatically opened:

            cin
                standard input (keyboard)

            cout
                standard output (screen)

            cerr
                standard error (unbuffered, screen)

            clog
                buffered error output i.e. buffered version of cerr (screen)


        Correspondence with C streams:
            The streams cin, cout, and cerr correspond to C's stdin, stdout, and stderr. 
            clog is buffered version of cerr.

                cin     <>  stdin
                cout    <>  stdout
                cerr    <>  stderr
                clog:  extra in C++, buffered version of "cerr"



    --------    Wide Character Versions    --------

    above cin, cout, cerr, clog are 8-bit (narrow) versions
        Standard C++ uses char for regular 8-bit characters (ASCII-based)
        but for non-English languages (like Chinese, Arabic, Bengali, etc.), 8 bits aren’t enough.

    To solve this, C++ provides wide characters using the type "wchar_t", 
        which typically holds 16-bit or 32-bit characters.

                Narrow (8-bit)      Wide (16/32-bit) 

                cin                 wcin
                cout                wcout
                cerr                wcerr
                clog                wclog
    
        These wide streams work with "wchar_t" type instead of "char"


    Default behavior:
        These streams use the console (keyboard/screen) by default
        They can be redirected to files or other devices in the right setup




    --------    <iostream> and Template Classes    --------

    The <iostream> header provides support for C++ input/output.
        It defines a complex class hierarchy for handling I/O.
        The I/O classes begin with a "system of template classes". 

    Template classes/ generic classes (will be discussed in next Chapter) :
        A template class defines the form of a class "without fully specifying the data" upon which it will operate. 
        Once a template class has been defined, specific instances of it can be created/added.

    C++ creates two versions of its I/O template classes:
        One for 8-bit (normal) characters
        One for wide (16-bit) characters




    --------    C++ I/O template Class Hierarchy    --------
    The C++ I/O system is build upon two related, but different, template class hierarchies. 

    basic_streambuf:
        Derived from the low-level I/O class.
        Handles basic, low-level (raw) input/output operations.
        Forms the foundation of the I/O system.
        Used in advanced I/O programming.


    basic_ios:
        Most of our work in C++ I/O is based on this class
        
        This is a high-level I/O class that provides: 
            Formatting, 
            Error-checking, and 
            Stream status info

        basic_ios is used as a base for several derived classes, including : 
            1: basic_istream    -   Input stream
            2: basic_ostream    -   Output stream
            3: basic_iostream   -   Input + Output stream





-----------------------------



--------------  rev[24-Jul-2025]  ---------------

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


