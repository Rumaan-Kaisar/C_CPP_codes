
/*  ------------------------    EXCEPTION HANDLING    ------------------------
    
    Exception Handling is a subsystem in C++ that allows structured and controlled handling of "run-time errors".
    By exception handling, the program can automatically invoke error-handling routines when errors occur.

    Exception handling is C++'s built-in error handling mechanism. 
    Mostly used to manage and respond to "run-time errors". 
    Instead of crashing, the program can execute an error-handling routine.


    ----------------    Core Mechanism    ----------------

    C++ exception handling is built upon three keywords: 
        try:        Contains code that may generate an exception.
        throw:      Generates (throws) an exception when an error occurs.
        catch:      Receives and handles the thrown exception.
 

    try BLOCK:
        Generally the program statements that you want to monitor for exceptions are contained in a "try" block. 
        
        Can enclose:
            A few statements
            An entire function
            Even the whole "main()" function (causes the entire program to be monitored).

        Any "statement throwing an exception" must be executed from within a "try" block 
        A function called from "within a try block" can also throw an exception.


    throw STATEMENT:
        If an exception (i.e., an error) occurs within the "try" block, it is thrown using "throw". 

        Syntax:     throw exception;    // It generates an exception.

        Used to signal that an error has occurred.
        Must be executed within a "try" block or a function called by the "try" block (directly or indirectly).

        The thrown value is called the "exception". (can be any data type, often class types).


        --------  Uncaught Exceptions  --------

        If no matching "catch" exists, STL function "terminate()" is invoked, 
        which calls "abort()" by default, causing "abnormal termination".

        You can specify your own termination handler by referring 
            to your compiler's library reference for details.

        In C++, a "termination handler" is used when the runtime system encounters a critical failure 
            during "exception propagation" and cannot safely continue executing. 

        When this happens, the standard library automatically calls std::terminate(), 
            which triggers either the default handler or a custom function registered via std::set_terminate().


    catch BLOCK:
        It Handles the thrown exception.
        Any exception must be caught and processed, using "catch", that immediately follows 
            the "try" statement that throws the exception.
        
        Matching type:
            Any type of data can be caught by catch, but "Class" types are frequently used as exceptions.
            The data type in "catch(type arg)" must match the type of the "thrown exception".

        Argument:
            "arg" receives the value of the exception. 
            It is optional if access to the value is not needed. Eg:

                catch(int) {
                    // Handle integer exception
                }

        There can be more than one catch associated with a try.
        The catch that is used is determined by the "type of the exception". 
            i.e, if the "data type" specified by a catch matches the "data type" of the exception, 
            that catch is executed (and all others are bypassed). 



    --------  Execution Flow  --------

    Place risky code inside a "try" block.
    If an error occurs, use "throw" to throw an exception.
    A matching "catch" block catches and processes the exception.

    General Form and try-catch blocks:

                try{
                    // try block: Code that may cause an exception
                }
                catch(type1 arg){
                    // catch block: Handle exception type1
                }
                catch(type2 arg){
                    // catch block: Handle another exception type2
                }
                catch(type3 arg){
                    // catch block
                }
                . . .
                catch(typeN arg){
                    // catch block
                }

        When an exception is thrown, control transfers immediately to the "matching catch block"; 
        Remaining statements in the "try block" are skipped.

        When an exception is caught, "arg" will receive its value. 
            If you don't need access to the exception itself, 
            "specify only type" in the catch clause- "arg" is optional. 
        
        After catch executes, control continues with statements following the catch block.

    Note: 
        A single "try" can have multiple "catch" blocks.
        Each "catch" must handle a different data type.
        Checked in order; only the first matching "catch" is executed.

        To catch all handler we can use 

            catch(...) {
                // Catch-all handler
            }



    --------  ellipsis ". . ."  --------

    Catch all exceptions with ellipsis ". . ."
    Use following form of catch:

            catch(...){  
                // process all exceptions   
            }

    Here the ellipsis matches any type of data. 
    Useful as a default handler to prevent abnormal program termination from unhandled exceptions.
    Often placed as the last catch block in a cluster.
    [". . ." called ellipsis. It indicates an intentional omission of a word/whole-line/text-section without altering original meaning.]



    ----------------    Appling restrictions to exceptions    ----------------

    Exception Specifications (Restricting Throws):
        We can restrict the type of exceptions that a function can throw back to its caller.
        We can control what "type of exceptions" a function can throw outside of itself.
        To apply these restrictions, you must add a "throw clause" to the function definition.

        Syntax:
                return_type func_name(arg_list)  throw(type_list){
                    // exceptions
                }

        Example:
                int func() throw(int, float) {
                    // ...
                }

        Preventing a function from throwing any exceptions:
            Empty arg List in throw() prevents the function from throwing *any* exceptions.
 
        Here only those "data types" contained in the comma-separated  "type-list"  may be thrown by the function. 

    Violation:
        Only the listed exception types can be thrown.
        If a function throws a disallowed type, "unexpected()" is called, 
        leading to "terminate()" and abnormal termination.

    For own termination handler: 
        Need to refer to compiler's documentation for directions on how this can be accomplished.

    If you don't want a function to be able to throw any exceptions, use an "empty list".


    --------  Rethrowing exceptions  --------

    To rethrow an expression from within an exception handler, call "throw", by itself with no exception.
    This causes the current exception to be passed on to an outer try/catch sequence.

    Syntax: 
            throw;      // used inside a "catch" block with no argument.

        Passes the current exception to an "outer try/catch" sequence.
        Allows "multiple handlers" to process different aspects of the same exception.

    The reason for "rethrow" an exception is to allow "multiple handlers access" to the exception. 
        For example, one exception handler manages one aspect of an exception and a second handler copes with another. 

    The rethrown exception is not caught by the "same catch block" that rethrew it.

    An exception can only be "rethrown" from within a "catch block" (or from any function called from within that block). 
        When you rethrow an exception, it will not be "recaught" by the "same catch statement". 
        It will propagate to an outer catch statement. 


    --------  Key Points  --------
    
    Exception handling deals with "run-time errors".

    Three keywords: "try", "throw", "catch".
        "try"   --> Monitor code.
        "throw" --> Raise exception.
        "catch" --> Handle exception.

    Multiple "catch" blocks are allowed.
    "catch(...)" catches all exceptions.
    Unhandled exceptions cause abnormal program termination ("terminate()" --> "abort()").
*/



/* Example 1 (Execution process of Exception Handling): 
                Following shows the way C++ exception handling operates.

                Code after "throw" in the "try" block is "never executed".
                Control jumps directly to "catch".
                Stack is automatically reset.
*/

#include <iostream>

int main() {
    std::cout << " start \n";

    // start a try block
    try {
        std::cout << " Inside try block \n";
        throw 10; // throw an error
        std::cout << " This will not execute ";     // won't execute, control transferred to "catch" due to "throw 10"
    }
    // catch an error
    catch(int i) {
        std::cout << " Caught One ! Number is: ";
        std::cout << i << "\n";
    }

    std::cout << " end ";

    return 0;
}


/*  output:
        start 
        Inside try block 
        Caught One ! Number is: 10
        end 

    Notice:
        There is a "try block" containing three statements and
        A catch(int i) statement that processes an "integer exception".

        Within the try block, only two of the three statements will execute: 
            the first cout statement and the throw. 
            Once an exception has been thrown, control passes to the catch expression and the try block is terminated. 
            The "cout" statement following the "throw" will never execute.
            
            i.e. catch is not called, rather, program "execution is transferred" to it.
            (The stack is automatically reset as needed to accomplish this.) 

        After the "catch" statement executes, program control continues with the statements following the catch. 
        
        Often, however, a catch block will end with a call to 
            exit(), abort(), or some other function that causes program termination 
            because exception handling is frequently used to handle catastrophic errors.

    Note:
        The type of the exception must match the type specified in a catch statement.
        Considering Example 1, following won't  work .

            // 'catch' is double  type: won't work for an int exception 
            catch(double i){    
                std::cout << " Caught One ! Number is: ";
                std::cout << i << "\n";
            }

        This program-part produces the following output because the integer exception will not be caught by a double catch statement.
        
        output:
            start
            Inside try block
            Abnormal program termination
*/




/*  Example 2: The type of the exception must match the type specified in a catch statement. 
                in the preceding example, if you change the type in the catch statement to double, 
                the exception will not be caught, and abnormal termination will occur.
*/
#include <iostream>

int main() {
    std::cout << " start \n";

    // start a try block
    try {
        std::cout << " Inside try block \n";
        throw 10; // throw an error
        std::cout << " This will not execute ";     // won't execute, control transferred to "catch" due to "throw 10"
    }
    // catch an error : won't work for an int exception
    catch(double i) {
        std::cout << " Caught One ! Number is: ";
        std::cout << i << "\n";
    }

    std::cout << " end ";

    return 0;
}




/* Example 3: An exception can be thrown from a statement that is outside the try block 
                as long as the statement is within a "function that is called from" within the try block 

            output:
                start
                Inside try block
                Inside Xtest, test is: 0
                Inside Xtest, test is: 1
                Caught One! Number is: 1
                end
*/

#include <iostream>

// following function throws an exception
void Xtest(int test) {
    std::cout << " Inside Xtest , test is: " << test << "\n";
    if(test) throw test;
}

int main() {
    std::cout << " start \n";
    // calling the exception throwing function within try block
    try {
        Xtest(0);
        Xtest(1);
        Xtest(2);
    }
    // catch an error
    catch(int i) {
        std::cout << " Caught One! Number is: ";
        std::cout << i << "\n";
    }
    std::cout << " end ";

    return 0;
}

/*  Once an exception is "thrown and caught", subsequent function calls in the "try" block are not executed.
    e.g., "Xtest(2)" is not executed, since "Xtest(1)" is caught.
*/




// --------  Localized Try-Catch in Functions  --------

/*  Example 3: [To avoid "error skipping" as Xtest(2) in Example 3] A try block can be "localized" to a function. 

                In this case, each time the function is entered, the exception handling relative to that function is reset.

                Placing "try-catch" inside a function (rather than "main") "resets exception handling" every time the function is called.
                Allows the program to continue executing subsequent calls to the function even if previous calls threw exceptions.
*/

#include <iostream>

// A try / catch can be inside a function other than main().
void Xhandler(int test) {
    try {
        if(test) throw test;
    }
    catch(int i) {
        std::cout << " Caught One ! Ex , #: " << i << '\n';
    }
}


int main(){
    std::cout << " start \n";

    Xhandler(1);
    Xhandler(2);
    Xhandler(0);
    Xhandler(3);

    std::cout << " end ";

    return 0;
}

/*  output:
        start
        Caught One! Ex. #: 1
        Caught One! Ex. #: 2
        Caught One! Ex. #: 3
        end

    Notice:
        "try block" is not inside main(), instead try-catch blocks containing function Xhandler() is called from main().

        Also notice, three exceptions are thrown. 
            After each exception, the function returns.
            When the function is called again, the exception handling is reset.
*/




/*  Example 4: We can use more than one catch associated with a try. 
                Each catch must catch a different type of exception 
                (two or more catch with same data-type returns error). 

                In general, catch expressions are checked in the order in which they occur in a program.
                    Only a matching statement is executed. 
                    All other catch blocks are ignored.

                For example, consider "Example 3" with the following Xhandler() 
                [catches both integers and strings]
*/

# include <iostream>

// Different types of exceptions can be caught.
void Xhandler(int test){
    try {
        if(test) throw test;
        else throw "value is zero";
    }
    catch(int i){
        std::cout << " Caught One ! Ex. #: " << i << '\n';
    }
    catch(const char *str){       // *str is used to print "value is zero"
        std::cout << " Caught a string :";
        std::cout << str << '\n';
    }
}


int main(){
    std::cout << " start \n";

    Xhandler(1);
    Xhandler(2);
    Xhandler(0);
    Xhandler(3);

    std::cout << " end ";
    
    return 0;
}


/*  ----  string throw issue fix  ----
    
    The issue is in this line:

            throw "value is zero";

    A string literal has type "const char[]", which decays to "const char*". 
    Therefore, our handler:

            catch(char *str) { //... }

    does not match it.


    ----  Fix

    Change:
            catch(char *str)

    to:
            catch(const char *str)



    This program produces the following output:

        start
        Caught One! Ex. #: 1
        Caught One! Ex. #: 2
        Caught a string: Value is zero
        Caught One! Ex. #: 3
        end

    As you can see, each catch statement responds only to its own type.
*/




/*  Example 5: What is wrong with this fragment?

                int main() {
                    throw 12.23;

            ans:
                "throw" is called before execution passes through a "try block".
*/




/*  Example 6: What is wrong with this fragment?

                try{
                    // ...
                    throw 'a';
                    // ...
                }
                catch (char *){
                    // ...
                }

                What will happen if an exception is thrown 
                    for which there is no corresponding catch statement?


            ans:
                A "character exception" is thrown, but there is "no matching catch statement" to handle it, 
                    since the existing statement only catches a character pointer.

                If a thrown exception has no matching catch statement, 
                    the program calls terminate() and may "crash".
*/




/*  Example 7 & 8: Using "catch(...)"
    ==> "catch(...)" can handle integers, chars, doubles, etc., in a single block.
    ==> Best practice: Use specific catches first, then "catch(...)" as a fallback for miscellaneous errors. 
*/



/* Example 7: Following catches all exceptions [with ellipsis "..." ] using "catch(...)" 

            output:
                    start
                    Caught One!
                    Caught One!
                    Caught One!
                    end

                Notice, all three throws were caught using the one catch statement.
*/

#include <iostream>

void Xhandler(int test) {
    try { 
        if(test==0) throw test;     // throw int 
        if(test==1) throw 'a';      // throw char 
        if(test==2) throw 123.23;   // throw double 
    }
    catch(...){                     // catch all exceptions 
        std::cout << " Caught One !\n";
    }
}

int main(){ 
    std::cout << " start \n";
    Xhandler(0);
    Xhandler(1);
    Xhandler(2);
    std::cout << " end ";
        
    return 0;
}




/*  Example 8: One very good use for catch(...) is as the last catch of a "cluster of catches".
                Place catch(...) at the very end of your catch blocks to handle any unexpected errors. 
                It acts as a universal safety net.
                
                In this example, this updated code handles specific integer errors first, 
                while catch(...) quietly intercepts all other types.

            output:
                start
                Caught 0
                Caught One!
                Caught One!
                end

                By catching all exceptions, you prevent an unhandled exception from causing an abnormal program termination.
*/

#include <iostream>

void Xhandler(int test){
    try { 
        if(test==0) throw test;     // throw int 
        if(test==1) throw 'a';      // throw char 
        if(test==2) throw 123.23;   // throw double 
    }
    catch (int i){                  // catch an int exception
        std::cout << " Caught " << i << '\n';    
    }
    catch(...){                     // catch all other exceptions 
        std::cout << " Caught One !\n";
    }
}    

int main(){
    std::cout << " start \n";
    
    Xhandler(0);
    Xhandler(1);
    Xhandler(2);
    
    std::cout << "end ";
    
    return 0;
}




/*  Example 9: The following program shows how to restrict the "types of exceptions" that can be thrown from a function.

                // Restricting function throw types
                ret_type func_name(arg_list) throw(type_list){
                    // exceptions
                }

                The function Xhandler() is restricted to throwing only three types of exceptions: integers, characters, and doubles. 
                    Throwing any other type will crash the program (by calling unexpected()).
                    You can test this by removing int from the allowed list and running the program again.

                The restriction applies only when throwing an exception out of the function.
                (when an exception leaves the function and goes back to the calling try block.)

                Inside the function itself, a try block can throw any exception type, as long as it is caught before exiting that function.
*/

#include <iostream>

// This function can only throw ints, chars, and doubles
void Xhandler(int test) throw(int , char , double) {
    if(test==0) throw test;     // throw int 
    if(test==1) throw 'a';      // throw char 
    if(test==2) throw 123.23;   // throw double 
    // no "try-catch" is used here. Instead this function will be called from "try"
}    


int main() {
    std::cout << " start \n";
    try {
        Xhandler(0);    // also , try passing 1 and 2 to Xhandler
    }
    catch(int i) {
        std::cout << " Caught int \n";
    }
    catch(char c) {
        std::cout << " Caught char \n";
    }
    catch(double d) {
        std::cout << " Caught double \n";
    }
    std::cout << " end ";

    return 0;
}

/* Note: 
    the code wont compile in ISO C++17 and later.
    Instead try older versions like C++14 or C++11

    Use "https://www.onlinegdb.com/" and select older C++ version from setting.
*/




/*  Example 10: The following change to Xhandler() prevents it from throwing any exceptions:

                    // This function can thrown NO exceptions!
                    void Xhandler(int test) throw(){
                        if(test==0) throw test;
                        if(test==0) throw 'a;
                        if(test==2) throw 123.23;
                    }

                The above statements no longer work. Instead, they will cause an abnormal program termination.

                This throw() function is not allowed to let any exception escape, it has no "type list".


                Function Throw Restrictions:
                    "void func() throw(int, char)"  allows only int/char throws.
                    "void func() throw()"           allows no throws. Attempting to throw results in termination.
*/




/*  Example 11: The following program illustrates "rethrowing an exception". It rethrows a "char *" exception.

                Inner handler processes part of the error, 
                then uses "throw;" to pass it to the outer handler in "main" for further processing.

            output:
                start
                Caught const char * inside Xhandler
                Caught const char * inside main
                end
*/  

#include <iostream>

void Xhandler() {
    try{
        throw " hello "; // throw a const char *
    }
    // catch a const char *
    catch(const char *) {
        std::cout << " Caught const char * inside Xhandler \n";
        throw;  // "rethrow" const char * out of function
    }
}


int main() {
    std::cout << " start \n";
    try {
        Xhandler();
    }
    catch(const char *) {
        std::cout << " Caught const char * inside main \n";
    }
    std::cout << " end ";
    
    return 0;
}



// ----  rev[22-Aug-2026]  ----


/*  Example 12: What is wrong with this fragment?

                        try {
                            // ...
                            throw 10;
                        }
                        catch(int *p) {
                            // ...
                        }

                Show one way to fix the preceding fragment.

                What catch expression catches all types of exceptions?

            ans:
                There is no "corresponding catch statement" for the throw.




3. One way to fix the problem is to create a catch(int) handler. Another way to fix it is to
catch all exceptions with a catch(...) handler.





4. catch(...) catches all exceptions.
*/





/*  

*/














5. Here is a skeleton for a function called divide().
double divide ( double a, double b)
{
// add error handling
return a/b;
}
This function returns the result of dividing a by b. Add error checking to this function
using C++ exception handling. Specifically, prevent a divide-by-zero error. Demonstrate
your solution in a program.


5. # include <iostream >
# include <cstdlib >
using namespace std ;
double divide ( double a, double b)
{
try
{
if (!b)
throw (b);
}
catch ( double )
{
cout << " Cannot divide by zero .\n";
exit (1) ;
}
return a/b;
}
int main ()
{

cout << divide (10.0 , 2.5) << endl ;
cout << divide (10.0 , 0.0) ;
return 0;
}
