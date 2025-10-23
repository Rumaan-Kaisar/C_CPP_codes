
/*  ------------------------    Custom manipulators    ------------------------
    
    Custom manipulators are important for two main reasons. 

    Combine repeated I/O steps:
        A custom manipulator can group several separate I/O operations that occur often in a program, 
        so we can perform them with a single command.

    Handle special devices:
        A custom manipulator allows us to perform I/O with "nonstandard devices" -
        for example, sending control codes to special hardware like printers or optical recognition systems.


// rev[21-Oct-2025]


    --------  Types of Manipulators  --------


there are two basic types of manipulators: those that operate on input streams and those that operate on output streams.  There is a secondary division: those manipulators that take an argument and those that don't:
    parameterized manipulator and 
    parameterless manipulator


parameterized manipulator: The procedures necessary to create a parameterized manipulator vary widely from compiler to compiler, and even between two different versions of the same compiler. For this reason, you must consult the documentation to your compiler for instructions on creating parameterized manipulators. Parameterized manipulator is out of scope of this note. 

parameterless manipulators: However, the creation of parameterless manipulators is straightforward and the same for all compilers. 

Output functions: All parameterless manipulator output functions have this skeleton:



ostream &manip_name( ostream &stream ){   // your code here
return stream ; }

Here manip_name is the name of the manipulator and 

stream " &stream " is a reference to the invoking stream which must be returned by the manipulator " return stream; ".  This is necessary if a manipulator is used as part of a larger I/O expression. 

Here the manipulator has a single argument "a reference to the stream upon which it is operating", but no argument will be used when the manipulator is called in an output operation.

Input functions: All parameterless input manipulator functions have this skeleton:




istream &manip_name( istream &stream ){   
// your code here 
return stream ; }

An input manipulator receives a reference to the stream on which it was invoked. This stream must be returned by the manipulator.


---------------------------


Here is a clear and simplified version of your text:

Manipulators: Clarified and Simplified ✅

Manipulators are special functions used with input/output streams (cin, cout).
They help format data or perform repeated stream operations easily.

Two main categories:

Input stream manipulators (work with cin)

Output stream manipulators (work with cout)

Another classification:

Parameterized manipulators – take arguments
Example: setw(10)
(These vary by compiler and are not covered here.)

Parameterless manipulators – take no arguments
Example: endl, flush
(Easy and consistent across compilers.)

Parameterless Manipulators

These follow a standard function format and always:

Take a reference to the stream they operate on

Return that same stream reference
→ This allows chaining like:

cout << manip1 << manip2;

Output Manipulator Skeleton

For manipulators used with cout:

ostream& manip_name(ostream& stream) {
    // your code here
    return stream;
}

Input Manipulator Skeleton

For manipulators used with cin:

istream& manip_name(istream& stream) {
    // your code here
    return stream;
}


✅ The key point:
The stream must be returned so it can continue to be used in a longer input/output expression.

If you'd like, I can show you a working example of a custom manipulator—like one that prints a line break with stars or skips input whitespace.


---------------------------


Example 1: Following creates a manipulator called setup() that sets field width to 10, precision to 4, and fill character to *.

ostream &setup(ostream &stream){
stream.width(10);
stream.precision(4);
stream.fill('*');
return stream ;}
int main(){
cout <<setup<< 123.123456;
return 0;}




Example 2: Following creates the getpass() input manipulator, which rings the bell and then prompts for a password:

#include<cstring >
// A simple input manipulator
istream &getpass(istream &stream){
        cout << '\a';   // sound bell
        cout << " Enter password : ";
        return stream ; }
        int main(){
        char pw[80];
// comparing password
        do{ cin >> getpass >> pw; }
        while(strcmp(pw, "password")); 
        cout << " Logon complete \n";
        return 0; }


*/  


