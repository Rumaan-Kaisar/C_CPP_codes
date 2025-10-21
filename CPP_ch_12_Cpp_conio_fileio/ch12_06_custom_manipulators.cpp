
/*  ------------------------    chapter    ------------------------

12.6 User Defined Manipulators

Custom manipulators are important for two main reasons. 

First, a manipulator can consolidate a sequence of several separate I/O operations: in which the same sequence of I/O operations occurs frequently within a program.

Second, a custom manipulator can be important when you need to perform I/O operations on a nonstandard device. For example, you could use a manipulator to send control codes to a special type of printer or an optic recognition system.


Types of Manipulators: there are two basic types of manipulators: those that operate on input streams and those that operate on output streams.  There is a secondary division: those manipulators that take an argument and those that don't:
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


