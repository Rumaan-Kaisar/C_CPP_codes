
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




    // ----  rev[05-Dec-2024]  ----


	The return type of an operator function is often the class for which it is defined. (operator function may free to return any type.) 
	The operator being overloaded is substituted for the #. For example, to overloaded + , the function name would be operator+.
	The contents of arg-list vary depending upon how the operator function is implemented and the type of operator being overloaded.
	Restrictions: 		The precedence of the operator cannot be changed. 
	Second, the number of operands that an operator takes cannot be altered. I.e. a binary operator cannot be overload as an unary operator. For example, you cannot overload the / operator so that it takes only one operand.
	These operators we cannot overload:   .   ::   .*     ?
	We cannot overload the preprocessor operators (i.e. #, ##). (The    .*    operator is highly specialized and not discussed in this book.)
	The [] subscript operators, the () function call operators, new and delete, and the . (dot) and -> (arrow) operators can be overloaded.
	Except for the =, operator functions are inherited by any derived class. However, a derived class is free to overload any operator it chooses (including those overloaded by the base class) relative to itself.
	You have been using two overloaded operators: << and >>. These operators have been overloaded to perform console I/O in C++. As mentioned, overloading these operators to perform I/O does not prevent them from performing their traditional jobs of left shift and right shift.
	However, do not use any operator overloading abnormally. 


*/  
