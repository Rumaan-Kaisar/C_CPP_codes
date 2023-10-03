
-----------------    conditional compile    -----------------

The C preprocessor includes several directives that allow parts of the source code of a program to be selectively compiled. This is called conditional compilatlon. These directives are
 
#if
#else
#elif
#endif
#ifdef
#ifndef
 

#if : The general form of #if is shown here: 	#if constant-expression
statement-sequence
#endif

If the value of the constant-expression is true the statement or statements between #if and #endif are compiled. If the constant-expression is false, the compiler skips the statement or statements. 
	The preprocessing stage is the first stage of compilation,
	So the constant-expression means exactly that. No variables may be used.
#else :  The #else can be used to form an alternative to the #if. Its general form is shown here:
#if constant-expression
statement-sequence
#else
statement-sequence
#endif
	Notice that there is only one #endif. The #else  automatically terminates the #if  block of statements. 
	If the constant-expression is false, the statement or statements associated with the #else are compiled.

#elif: You can create an if-else-if ladder using the #elif directive, as shown here:
#if constant-expression-1
statement-sequence
#elif constant-expression-2
statement-sequence
#elif constant-expression-3
statement-sequence
#endif
	As soon as the first expression is true, the lines of code associated with that expression are compiled, and the rest of the code is, skipped.

#ifdef: Another approach to conditional compilation is the #ifdef directive. It is used to check if a macro has defined. It has this general form:
#ifdef macro-name
statement-sequence
#endif
	If the macro-name is currently defined, then the statement-sequence associated with the #ifdef directive will be compiled. Otherwise, it is skipped. 
	The #else may also be used with #ifdef to provide an alternative.
	In addition to #ifdef, there is a second way to determine if a macro name is defined. You can use the #if directive in conjunction with the defined compile-time operator. The defined operator has this general form:
#if  defined macro-name
	If macro-name is defined, then the outcome is true. Otherwise, it is false. For example, the following two preprocessor directives are equivalent:
#ifdef WIN32
#if defined WIN32	/* defined is a compile-time operator */
	In this case you can also apply the ! operator to defined to reverse the condition.

#ifndef: The complement of #ifdef is #ifndef. It has the same general form as #ifdef. The only difference is that the statement sequence associated with an #ifndef directive is compiled only if the macro-name is not defined. (alternative to !defined ).

