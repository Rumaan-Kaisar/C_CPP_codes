
/*  ------------------------    Custom manipulators    ------------------------
    
    Manipulators are special functions used with input/output streams (cin, cout).
    They help format data or perform repeated stream operations easily.


    Custom manipulators are important for two main reasons. 

    Combine repeated I/O steps:
        A custom manipulator can group several separate I/O operations that occur often in a program, 
        so we can perform them with a single command.

    Handle special devices:
        A custom manipulator allows us to perform I/O with "nonstandard devices" -
        for example, sending control codes to special hardware like printers or optical recognition systems.


    --------  Types of Manipulators  --------
    There are two basic types of manipulators: 
        Input stream manipulators (work with cin)
        Output stream manipulators (work with cout)

    There is a secondary division: 
        Parameterized manipulators
            Example: setw(10)
            
            Creating Parameterized manipulators is different across compilers, and 
            the steps are not consistent.
            So, for now, we will not cover how to create parameterized manipulators.

        Parameterless manipulators:
            Example: endl, flush
            (Easy and consistent across compilers.)



    --------  parameterless manipulators  --------
    
    The creation of parameterless manipulators is straightforward and the same for all compilers. 
    These follow a standard function format and always:
        Take a reference to the stream they operate on
        Return that same stream reference, allows chaining like:

                cout << manip1 << manip2;


    OUTPUT Manipulator Skeleton:
        All parameterless Output Manipulator Functions (used with 'cout') have this skeleton:

                ostream &manip_name( ostream &stream ) {
                    // your code here
                    return stream;
                }

            Here manip_name is the name of the manipulator and stream "&stream" is a reference to 
                the "invoking stream" which must be returned by the manipulator "return stream;".  
                This is necessary if a manipulator is used as part of a larger I/O expression. 

            Here the manipulator has a single argument "a reference to the stream upon which it is operating", 
                but no argument will be used when the manipulator is called in an output operation.


    INPUT Manipulator Skeleton:
        All parameterless Input Manipulator Functions (used with 'cin') have this skeleton:

                istream &manip_name( istream &stream ) {
                    // your code here
                    return stream;
                }

            An input manipulator receives a reference to the stream on which it was invoked. 
            This stream must be returned by the manipulator.


    The key point:
        The stream must be returned so it can continue to be used in a longer input/output expression.


// ----  rev[24-Oct-2025]  ----

---------------------------







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


/* Example 1: Following creates a manipulator called setup() that sets 
                    field width to 10, 
                    precision to 4, and 
                    fill character to *. 
*/

ostream &setup(ostream &stream){
stream.width(10);
stream.precision(4);
stream.fill('*');
return stream ;}
int main(){
cout <<setup<< 123.123456;
return 0;}
