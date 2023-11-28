

----------------------     conIO in C++     ----------------------


9.5 C++ Console I/O
We may still use functions such as printf() and scanf() these are I/O functions. In C++, I/O is performed using I/O operators instead of I/O functions. In order to use the C++ I/O operators, you must include the header <iostream> in your program.

Output :  The output operator is << .  In general, to output to the console, use this form of the << operator:

cout << expression ;

Here, expression can be any valid C++ expression-including another output expression. cout is a predefined stream that is automatically linked to the console when a C++ program begins execution. It is similar to C's stdout. 
	By using the << output operator, it is possible to output any of C++'s basic types. For example, this statement outputs the value 100.99:			cout << 100.99;
cout << " This string is output to the screen .\n";

Input :  To input a value from the keyboard, use the >> input operator. In general, to input values from the keyboard, use the form if >> :

cin >> variable ;

For example,       int num; cin >> num;    inputs an integer value into num.  Notice that num is not preceded by an &. When you use C's scanf() function to input values, variables must have their addresses passed to the function so they can receive the values entered by the user. This is not the case when you are using C++'s input operator.

Note
[1]	As you know, in C, these are the left and right shift operators, respectively. In C++, they still retain their original meanings (left shift and right shift) butt they also take on the expanded role of performing input and output.
[2]	As in C, C++ console I/O may be redirected, but for the rest of this discussion, it is assumed that the console is being used.

