
/*
    --------------    Function Pointers    --------------
    A FUNCTION POINTER is a 'variable' that contains the 'address of the entry point' to a function.


    how "Function Pointers" works: 

        COMPILER creates an 'entry point' for each function in the program during COMPILATION 
            The "ENTRY POINT" is the ADDRESS to which 'execution transfers' when a function is called. 
            Since the ENTRY POINT has an ADDRESS, it is possible to have a pointer variable point to it. 
        
        Once you have a "POINTER TO A FUNCTION", it is possible to actually CALL that FUNCTION using the POINTER. 


    To create a variable that can point to a function, 
        declare the pointer as having the 'same type' as the 'return type of the function', followed by any parameters. 

            For example, the following declares 'p' as a pointer to a function that 'returns an integer' and has two integer PARAMETERS, x and y;

                int (*p) (int x, int y);

    NOTE:
        The PARENTHESES surrounding *p are NECESSARY because of C's precedence rules. 




    ASSIGN the ADDRESS of a function to a function pointer:
        Simply use its 'NAME without any parentheses'.  For example, assuming that sum() has the prototype

                int sum(int a, int b);

        the following assignment statement is correct:

                p = sum;

            Once this has been done, you can call sum() 'indirectly through p' using a statement like:

                result = (*p) (10, 20);

            Again because of C's precedence rules the Parentheses are necessary around p.


        Actually, you can also just use p directly, like this:

                result = p(10, 20);
            
        NOTE:
            (*p) form inform anyone that reading your codes that a function pointer is being used 
                to call a function indirectly, instead of calling a function named p. 
*/
