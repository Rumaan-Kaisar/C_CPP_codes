
/*  ------------------------    chapter    ------------------------

13.6 EXCEPTION HANDLING
Exception handling (resilient code): Exception handling is the subsystem of C++ that allows us to handle errors that occur at run time in a structured and controlled way. By exception handling, your program can automatically invoke an error handling routine when an error occurs. 
	Exception handling is C++'s built-in error handling mechanism. Mostly used to manage and respond to run-time errors. C++ exception handling is built upon three keywords: try, catch, and throw. 
	Generally the program statements that you want to monitor for exceptions are contained in a try block. 
	If an exception (i.e., an error) occurs within the try block, it is thrown using throw. 
	The exception is caught, using catch, and processed. 
	General Form and try-catch blocks: The general form of try and catch are:

try{ 	/* try block */ }
catch(type1 arg){		/* catch block */ 	}
catch(type2 arg){		/* catch block */ 	}
catch(type3 arg){		/* catch block */ 	}
. . .
catch(typeN arg){		/* catch block */ 	}
	try: The try block must contain the portion of your program that you want to monitor for errors. This can be a few statements within one function or all-codes by enclosing the main() function within a try block (which causes the entire program to be monitored).
	Any statement that throws an exception must have been executed from within a try block. 
	A function called from within a try block can also throw an exception.
	catch: Any exception must be caught by a catch statement that immediately follows the try statement that throws the exception. Catch statement processes the exception. 
	Any type of data can be caught by catch. Class types are frequently used as exceptions.
	There can be more than one catch associated with a try. The catch that is used is determined by the type of the exception. I.e, if the data type specified by a catch matches the data type of the exception, that catch is executed (and all others are bypassed). 
	When an exception is caught, arg will receive its value. If you don't need access to the exception itself, specify only type in the catch clause-arg is optional. 
	General form of the throw: The general form of the throw statement is: 	throw exception ;
	throw must be executed either from within the try block proper or from any function that the code within the block calls (directly or indirectly). 
	exception is the value thrown. If you throw an exception for which there is no applicable catch statement, an abnormal program termination might occur. 
	In standard C++, throwing an unhandled exception causes the standard library function terminate() to be invoked. By default, terminate() calls abort() to stop your program.
	You can specify your own termination handler by referring to your compiler's library reference for details.

	Catch all exceptions with ellipsis ". . ." : To catch all exceptions instead of just a certain type, use following form of catch:
catch(...){  /* process all exceptions */  }
Here the ellipsis matches any type of data. [ ". . ." called ellipsis. It indicates an intentional omission of a word/whole-line/text-section without altering original meaning.]
	Appling restrictions to exceptions:	
	We can restrict the type of exceptions that a function can throw back to its caller. 
	We can control what type of exceptions a function can throw outside of itself. 
	We can also prevent a function from throwing any exceptions whatsoever. 
	To apply these restrictions, you must add a throw clause to the function definition. The general form is: 

ret_type func_name(arg_list)  throw(type_list){ /* exceptions */ }

	Here only those data types contained in the comma-separated  type-list  may be thrown by the function. 
	When a function attempts to throw a disallowed exception the standard library function unexpected() is called, this causes the terminate() function to be called, which causes abnormal program termination. 
	For own termination handler: need to refer to compiler's documentation for directions on how this can be accomplished.
	If you don't want a function to be able to throw any exceptions, use an empty list.
	Rethrowing exceptions: To rethrow an expression from within an exception handler: call throw, by itself with no exception. This causes the current exception to be passed on to an outer try/catch sequence.

	Example 1: (Execution process of Exception Handling): Following shows the way C++ exception handling operates:
int main(){cout << " start \n";
try{					/* start a try block */
	cout << " Inside try block \n";				 
throw 10; 				/* throw an error */ 
cout << " This will not execute "; /* not execute, control transferred to "catch" due to "throw 10"*/
}

catch(int i){  				/* beginning catch block: catch an error */ 
cout << " Caught One ! Number is: ";
cout << i << "\n"; }
cout << "end ";
return 0; }
	
		This program displays the output:	start
Inside try block
Caught One! Number is: 10
end

	There is:		a try block containing three statements and
	a catch(int i) statement that processes an integer exception.
	Within the try block, only two of the three statements will execute: the first cout statement and the throw. Once an exception has been thrown, control passes to the catch expression and the try block is terminated. The cout statement following the throw will never execute.
	i.e. catch is not called, rather, program execution is transferred to it. (The stack is automatically reset as needed to accomplish this.) 
	After the catch statement executes, program control continues with the statements following the catch. 
	Often, however, a catch block will end with a call to exit(), abort(), or some other function that causes program termination because exception handling is frequently used to handle catastrophic errors.
	The type of the exception must match the type specified in a catch statement. Considering Example 1, following won't  work .
catch(double i){  	/* 'catch' is double  type: won't work for an int exception */ 
cout << " Caught One ! Number is: ";
cout << i << "\n"; }
	This program produces the following output because the integer exception will not be caught by a double catch statement.
	
		This program displays the output:	start
Inside try block
Abnormal program termination
	Example 2: An exception can be thrown from a statement that is outside the try block as long as the statement is within a function that is called from within the try block. For example, this is a valid program:
void Xtest(int test) { 	cout << " Inside Xtest , test is: " << test << "\n";
				if(test) throw test ; }
int main(){ 	cout << " start \n";
	   try{   /* throwing by the function Xtest : calling function within try block */
		Xtest(0); 
		Xtest(1);
		Xtest(2);}  /* it is also an exception but never thrown or executed */
	   catch(int i{   cout << " Caught One ! Number is: ";
			     cout << i << "\n";	}
	cout << "end ";
	return 0; }	
output:  start
	           Inside try block
	           Inside Xtest, test is: 0
	           Inside Xtest, test is: 1
	          Caught One! Number is: 1
	          end

	Xtest(2) is also exception but never thrown because of control transferred to "catch" after throwing 1 as exception.
	Example 3: [To avoid "error skipping" as Xtest(2) in Example 2] A try block can be localized to a function. In this case, each time the function is entered, the exception handling relative to that function is reset. For example:

	void Xhandler(int test){ 	try { 	if( test )
	throw test ; }
	catch(int i){ cout << " Caught One ! Ex. #: " << i << '\n'; }
	   }
	int main(){ 	cout << " start \n";
	Xhandler (1);
	Xhandler (2);
	Xhandler (0);
	Xhandler (3);
	cout << "end ";
	return 0;}	
output: 	start
		Caught One! Ex. #: 1
		Caught One! Ex. #: 2
		Caught One! Ex. #: 3
		end

	try block is not inside main(), instead try-catch blocks containing function Xhandler() is called from main().
	As you can see, three exceptions are thrown. After each exception, the function returns. When the function is called again, the exception handling is reset.
	Example 4: More than one catch associated with a try. Each catch must catch a different type of exception (two or more catch with same data-type returns error). For example, consider Example 3 with the following Xhandler() [catches both integers and strings]:

void Xhandler(int test){ 	try { 	if(test)  throw test ;
else throw "value is zero" }
	catch(int i){ cout << " Caught One ! Ex. #: " << i << '\n'; }
	catch(char *str){ 		/* *str is used to print ' value is zero ' */
cout << " Caught a string :";
cout << str << '\n';}	
   }
	In general, catch expressions are checked in the order in which they occur in a program. Only a matching statement is executed. All other catch blocks are ignored.
	Example 5: Following catches all exceptions [with ellipsis . . .] using catch(...):
void Xhandler (int test ) { 	try { if( test ==0) throw test ;      /* throw int */ 
			          if( test ==1) throw 'a'; 	         /* throw char */ 
			          if( test ==2) throw 123.23;  /* throw double */ 
			           }
			catch (...){  	               /* catch all exceptions */ 
				    cout << " Caught One !\n";    }
			}	int main(){ cout << " start \n";
		Xhandler(0);
		Xhandler(1);
		Xhandler(2);
	    cout << "end ";
	    return 0; }
	output:
      start
      Caught One!
      Caught One!
      Caught One!
      end

	All three throws were caught using the one catch statement.
	Example 6: Use catch(...) as the last catch of a cluster of catches [as last catch block for miscellaneous errors ]. In this capacity it provides a useful default or "catch all" statement. For example, this slightly different version of the preceding program explicitly catches integer exceptions but relies upon catch(...) to catch all others:
void Xhandler (int test ) { 	try { if( test ==0) throw test ;      /* throw int */ 
			          if( test ==1) throw 'a'; 	         /* throw char */ 
			          if( test ==2) throw 123.23;  /* throw double */ 
			           }
			catch (int i){  	             /* catch an int exception */ 
				    cout << " Caught" << i << '\n';    }
			catch (...){  	               /* all other  exceptions */ 
				    cout << " Caught One !\n";    }
			}	
int main(){ cout << " start \n";
		Xhandler(0);
		Xhandler(1);
		Xhandler(2);
	    cout << "end ";
	    return 0; }
	output:
      start
      Caught 0
      Caught One!
      Caught One!
      end

	By catching all exceptions, you prevent an unhandled exception from causing an abnormal program termination.
	Example 7: ret_type func_name(arg_list)  throw(type_list){ /* exceptions */ } to restrict the types of exceptions that can be thrown from a function:

void Xhandler(int test ) throw(int, char, double)  {
	if( test ==0) throw test ; 	/* throw int */ 
	if( test ==1) throw 'a'; 	/* throw char */ 
	if( test ==2) throw 123.23; 	/* throw double */    }	int main(){ cout<< "start \n";
		try{ Xhandler(0); 	}	/* 1 and 2 also  */   
		catch(int i) { cout << " Caught int \n";}
		catch ( char c) { cout << " Caught char \n"; }
		catch ( double d) { cout << " Caught double \n"; }
	cout << "end ";
	return 0; }
	In this program, the function Xhandler() can throw only integer, character, and double exceptions. If it attempts to throw any other type of exception, an abnormal program termination will occur. (That is, unexpected() will be called.) To see an example of this, remove int from the list and retry the program.
	A function can only be restricted in what types of exceptions it throws back to the try block that called it. That is, a try block within a function can thrown any type of exception so long as it is caught within that function.
	The restriction applies only when throwing an exception out of the function.
	Example 8: The following change to Xhandler() prevents it from throwing any exceptions:
void Xhandler(int test ) throw(){	if( test ==0) throw test ;
if( test ==0) throw 'a';
if( test ==2) throw 123.23; }
	The above statements no longer work . Instead , they will cause an abnormal program termination . 
	Example 9: The reason for rethrow an exception is to allow multiple handlers access to the exception. For example, perhaps one exception handler manages one aspect of an exception and a second handler copes with another. 
	An exception can only be rethrown from within a catch block (or from any function called from within that block). 
	When you rethrow an exception, it will not be recaught by the same catch statement. It will propagate to an outer catch statement. 
	The following program illustrates rethrowing an exception. It rethrows a char * exception.
void Xhandler() {
	try { throw " hello "; }	/* throw  char *  */ 
	catch( const char *) { 	/* catch  char *  */
		   cout << " char * inside Xhandler \n";
		   throw ;	        /* rethrow char * */      }
		}	int main(){ cout << " start \n";
	try { Xhandler (); }
	catch ( const char *) {
	       cout << "char * inside main \n"; }
         cout << "end ";
         return 0; }	output:
start
char * inside Xhandler
char * inside main
end




*/  
