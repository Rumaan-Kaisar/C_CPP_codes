


// ----  rev[09-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-



EXCP TN

1. Here is a simple example that shows the way C++ exception handling operates:
// A simple exception handling example .
293TEACH YOURSELF
C++
# include <iostream >
using namespace std ;
int main ()
{
cout << " start \n";
try // start a try block
{
cout << " Inside try block \n";
throw 10; // throw an error
cout << " This will not execute ";
}
catch ( int i) // catch an error
{
cout << " Caught One ! Number is: ";
cout << i << "\n";
}
cout << " end ";
return 0;
}
This program displays the following output:
start
Inside try block
Caught One! Number is: 10
end
Look carefully at this program. As you can see, there is a try block containing three
statements and a catch(int i) statement that processes an integer exception. Within the
try block, only two of the three statements will execute: the first cout statement and the
throw. Once an exception has been thrown, control passes to the catch expression and
the try block is terminated. That is, catch is not called. Rather, program execution is
transferred to it. (The stack is automatically reset as needed to accomplish this.) Thus,
the cout statement following the throw will never execute.
After the catch statement executes, program control continues with the statements following the catch. Often, however, a catch block will end with a call to exit(), abort(),
or some other function that causes program termination because exception handling is
frequently used to handle catastrophic errors.
2. As mentioned, the type of the exception must match the type specified in a catch statement. For example, in the preceding example, if you change the type in the catch statement to double, the exception will not be caught, and abnormal termination will occur.
This change is shown here:
// This example will not work .
# include <iostream >
using namespace std ;
294TEMPLATES AND EXCEPTION HANDLING
11.3. EXCEPTION HANDLING
int main ()
{
cout << " start \n";
try // start a try block
{
cout << " Inside try block \n";
throw 10; // throw an error
cout << " This will not execute ";
}
catch ( double i) // won ’t work for an int exception
{
cout << " Caught One ! Number is: ";
cout << i << "\n";
}
cout << " end ";
return 0;
}
This program produces the following output because the integer exception will not be
caught by a double catch statement.
start
Inside try block
Abnormal program termination
3. An exception can be thrown from a statement that is outside the try block as long as the
statement is within a function that is called from within the try block. For example, this
is a valid program:
/*
Throwing an exception from a function outside
the try block .
*/
# include <iostream >
using namespace std ;
void Xtest ( int test )
{
cout << " Inside Xtest , test is: " << test << "\n";
if( test )
throw test ;
}
int main ()
{
cout << " start \n";
try // start a try block
{
295TEACH YOURSELF
C++
Xtest (0) ;
Xtest (1) ;
Xtest (2) ;
}
catch ( int i) // catch an error
{
cout << " Caught One ! Number is: ";
cout << i << "\n";
}
cout << " end ";
return 0;
}
This program produces the following output:
start
Inside try block
Inside Xtest, test is: 0
Inside Xtest, test is: 1
Caught One! Number is: 1
end
4. A try block can be localized to a function. When this is the case, each time the function
is entered, the exception handling relative to that function is reset. For example, examine
this program:
# include <iostream >
using namespace std ;
// A try / catch can be inside a function other than main ().
void Xhandler ( int test )
{
try
{
if( test )
throw test ;
}
catch ( int i)
{
cout << " Caught One ! Ex , #: " << i << ’\n’;
}
}
int main ()
{
cout << " start \n";
Xhandler (1) ;
Xhandler (2) ;
296TEMPLATES AND EXCEPTION HANDLING
11.3. EXCEPTION HANDLING
Xhandler (0) ;
Xhandler (3) ;
cout << " end ";
return 0;
}
This program displays this output:
start
Caught One! Ex. #: 1
Caught One! Ex. #: 2
Caught One! Ex. #: 3
end
As you can see, three exceptions are thrown. After each exception, the function returns.
When the function is called again, the exception handling is reset.
5. As stated earlier, you can have more than one catch associated with a try. In fact, it
is common to do so. However, each catch must catch a different type of exception. For
example, the following program catches both integers and strings:
# include <iostream >
using namespace std ;
// Different types of exceptions can be caught .
void Xhandler ( int test )
{
try
{
if( test )
throw test ;
else
throw " Value is zero .";
}
catch ( int i)
{
cout << " Caught One ! Ex , #: " << i << ’\n’;
}
catch ( const char * str)
{
cout << " Caught a string : ";
cout << str << ’\n’;
}
}
int main ()
{
cout << " start \n";
Xhandler (1) ;
297TEACH YOURSELF
C++
Xhandler (2) ;
Xhandler (0) ;
Xhandler (3) ;
cout << " end ";
return 0;
}
This program produces the following output:
start
Caught One! Ex. #: 1
Caught One! Ex. #: 2
Caught a string: Value is zero
Caught One! Ex. #: 3
end
As you can see, each catch statement responds only to its own type.
In general, catch expressions are checked in the order in which they occur in a program.
Only a matching statement is executed. All other catch blocks are ignored.
EXERCISES
1. By far, the best way to understand how C++ exception handling works is to play with it.
Enter, compile, and run the preceding example programs. Then experiment with them,
altering pieces of them and observing the results.
2. What is wrong with this fragment?
int main ()
{
throw 12.23;
3. What is wrong with this fragment?
try
{
// ...
throw ’a’;
// ...
}
catch ( char *)
{
// ...
}
4. What will happen if an exception is thrown for which there is no corresponding catch
statement




11.3 EXERCISES
2. The throw is called before execution passes through a try block.
3. A character exception is thrown, but the catch statement will handle only a character
pointer. (That is, there is no corresponding catch statement to handle the character
exception.)
4. If an exception is thrown for which there is no corresponding catch, terminate() is called
and abnormal program termination might occur.
11.4 EXERCISES

  

