
/*  ------------------------    operator overloading    ------------------------
    
    ------------    The basics of "operator overloading"    ------------

    Overloading "Member Operator Functions":
        Operator overloading is a form of function overloading with extra rules.
        Operators are overloaded specifically for a "class" or user-defined type.

        To overload an operator, you write an operator function, which is often defined as a "member" of the class.
        Most often an operator function is:

                1. Member operator function
                2. Friend operator function


        Overloading an operator doesn't change its "original meaning".
        Instead, it gains additional meaning relative to the class for which it is defined.



    ------------    Member Operator Function and Friend Operator Function    ------------
    There's' a slight difference between a member operator function and a friend operator function. 

    The general form of a MEMBER operator function:

            return_type class_name :: operator#(arg_list ) {
                // operation to be performed
            }

        The operator function is defined as a member of the class.
        Tied to an object of the class.
        Can directly access the class's private members.
        left-hand operand of the operator (eg: 'a' of  "a+b" )
            must be a class object (or convertible to it).


    The general form of a FRIEND operator function:

            return_type operator#(arg_list) {
                // operation to be performed
            }

            class class_name {
                friend return_type operator#(arg_list);
            };

        The operator function is defined as a friend of the class and is not a member of the class.
        Not tied to a specific object of the class.
        Can access private members using the friend keyword.
        left-hand operand of the operator (eg: 'a' of  "a+b" )
            can be a non-class object, like a primitive type.



    Return Type of Operator Function:
        The "return type" of an Operator Function is often the class for which it is defined.
        However, the operator function may free to return any type

    Naming Convention:
        The operator being overloaded is substituted for '#' in the function name.
        For example, to overload +, the function name becomes "operator+".

    Argument List (arg-list):
        The argument list depends on how the operator function is implemented and the type of operator being overloaded.



    ------------    Restrictions    ------------

    Precedence:
        The precedence (order of operations) of the operator cannot be changed.

    Number of Operands:
        The number of operands for an operator cannot be changed.
        For example, a binary operator (like /) cannot be redefined as a unary operator.

    These operators cannot be overloaded:
            .       (dot operator)
            ::      (scope resolution operator)
            .*      (pointer-to-member operator)
            ?       (ternary conditional operator)
    
        We cannot overload preprocessor operators (i.e. #, ##)
        .*    operator is highly specialized and not discussed here

    Operators That Can Be Overloaded:
            []      (subscript operator)
            ()      (function call operator)
            new 
            delete
            .       (dot operator) and 
            ->      (arrow operator)


    Inheritance:
        All operator functions (except =) are inherited by derived classes.
        However, a derived class is free to overload any operator it chooses 
            (including those overloaded by the base class) relative to itself.


    Common Overloaded Operators:
        Operators << and >> have been overloaded for console I/O in C++.
        Despite overloading for I/O, these operators still retain their original functionality: "left shift" and "right shift"


    Finally, do not use any operator overloading abnormally that causes unexpected or illogical behavior
*/  


