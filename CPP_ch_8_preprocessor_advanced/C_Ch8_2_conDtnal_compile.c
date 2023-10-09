
/* 
    -----------------    conditional compile    -----------------

    selective/conditional compilation:
        The 'C preprocessor' includes several DIRECTIVES that allow 
            'parts of the source code of a program' to be selectively compiled.

        This is called CONDITIONAL COMPILATLON. These directives are
 
                #if
                #else
                #elif
                #endif
                #ifdef
                #ifndef



    #if : 	
                #if constant-expression
                    statement-sequence
                #endif

        If 'constant-expression' is true the statements between #if and #endif are compiled. 
        If the constant-expression is false, the compiler skips the statement or statements.

        No variables may be used:
            note that the preprocessing stage is the 'first stage of compilation',
            So the constant-expression means exactly that. No variables may be used.



    #else : 
                #if constant-expression
                    statement-sequence
                #else
                    statement-sequence
                #endif

        Notice that there is only one #endif. The #else  automatically terminates the #if  block of statements. 
        If the constant-expression is false, the statements associated with the #else are compiled.



    #elif: 
        You can create an if-else-if ladder using the #elif directive

                #if constant-expression-1
                    statement-sequence
                #elif constant-expression-2
                    statement-sequence
                #elif constant-expression-3
                    statement-sequence
                #endif

        If first expression is true, the lines of code associated with that expression are compiled, 
            and the rest of the code is, skipped.



    #ifdef:
        It is used to check if a 'macro' has defined.

                #ifdef macro-name
                    statement-sequence
                #endif

        If the macro-name is currently defined, 
            then the statement-sequence associated with the #ifdef directive will be COMPILED. 
            Otherwise, it is skipped. 

        #else may also be used with #ifdef to provide an alternative.



    defined:
        Second way to determine if a macro name is defined: 
            use the #if in conjunction with the defined 'compile-time operator'. 

            The defined operator has this general form:

                #if  defined macro-name

            If macro-name is defined, then the outcome is true. Otherwise, it is false. 
            

        For example, the following two preprocessor directives are equivalent:

                #ifdef WIN32
                #if defined WIN32	// defined is a compile-time operator

            In this case you can also apply the '!' operator to defined to reverse the condition.



    #ifndef: 
        The complement of #ifdef is #ifndef. It has the same general form as #ifdef. 
        The only difference is that the 
            statement sequence associated with an #ifndef directive is compiled only if the macro-name is not defined.
            (alternative to !defined ).

*/

