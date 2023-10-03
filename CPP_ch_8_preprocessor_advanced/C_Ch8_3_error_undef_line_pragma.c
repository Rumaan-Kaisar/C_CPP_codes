
----------------    directives #error #undef #line  #pragma    ----------------

C's preprocessor supports four special-use directives: 

 
#error
#undef
#line 
#pragma
 

#error:  The #error directive has this general form:
#error error-message
It causes the compiler to stop compilation and issue the error-message along with other implementation-specific information, which will generally include the number of the line the #error directive is in and the name of the file. 
	Note that the error-message is not enclosed between quotes. 
	The principal use of the #error directive is in debugging.

#undef: The #undef directive undefines a macro name. Its general form is
#undef macro-name
	If the macro-name is currently undefined, #undef has no effect. 
	The principal use for #undef is to localize macro names.

#line: When a C compiler compiles a source file, it maintains two pieces of information: the number of the line currently being compiled and the name of the source file currently being compiled. The #line directive is used to change these values. Its general form is
#line line_num "filename"

Here, line_num becomes the number of the next line of source code, and filename becomes the name the compiler will associate with the source file. 
	The value of line_num must be between 1 and 32,767. 
	The filename may be a string consisting of any valid file name. 
	The principal use for #line is for debugging and for managing large projects.
#pragma: The #pragma directive allows a compiler's implementor to define other preprocessing instructions to be given to the compiler. It has this general form:
#pragma instructions
	If a compiler encounters a #pragma statement that it does not recognize, it ignores it. 
	Whether your compiler supports any #pragmas depends on how your compiler was implemented.


