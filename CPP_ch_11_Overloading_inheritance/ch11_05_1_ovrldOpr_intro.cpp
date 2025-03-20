
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


    --------    *this    --------
    Why use *this:
        *this represents the "current object". 
        In operator overloading, returning *this allows the function 
            to return the "modified object itself" rather than a "temporary copy". 
            This ensures proper chaining of operations like a = b = c; or ++a = b;.

    ----  Purpose of using * (dereferencing)?  ----
    Dereferencing (recall ch10_10_1_reference.cpp): 
        Dereferencing is the method where we are using a "pointer" to access the element whose address is being stored. 
        We use the * operator to get the value of the variable from its address.

        In return *this;, the * operator dereferences the "this" pointer to return the "actual object", not the pointer. 
            This ensures that the operator returns a reference or a value of the modified object, 
            making the overloaded operator behave naturally in expressions.


    What if *this is not used and "this" (a pointer) is returned instead:
        If *this is not used and "this" (a pointer) is returned instead not the actual object, 
            the function would return a "pointer to the current object" instead of the "current object itself." 
            This can lead to incorrect behavior and unintended pointer operations.

    Use *this: 
        When you want to return the object itself (this is the most common case in operator overloading).
        *this dereferences the "this" pointer, returning the "actual object" (not a pointer)
        The return type would be the object type itself 
        *this is the current object itself, obtained by dereferencing the this pointer.
        It’s the actual object itself (e.g., three_d if the object is of type three_d).
        When you dereference this, you get the object itself, which is what you typically return in operator overloads.

    Use this: 
        When you need to return a pointer to the object (less common in operator overloading).
        You would need to adjust the return type to be a pointer (class_name*)
        "this" is a pointer that points to the current object (the object on which the member function is called). 
        It points to the object, but to access the members of the object, you need to dereference it (e.g., this->x or (*this).x).
        If you return "this", you're returning a pointer to the current object.

        Example Without *:

                        three_d* three_d::operator++() {
                            x++;
                            y++;
                            z++;
                            return this;  // Returns a pointer, not the current object itself
                        }
        
            Problems:
                Returning a pointer when an object is expected may cause issues in expressions like ++a = b;, which expect an object reference.
                Expressions like a = ++b; won't work correctly because a expects an object, not a pointer.

        Correct Version Using *this:

                        three_d three_d::operator++() {
                            x++;
                            y++;
                            z++;
                            return *this;  // Returns the updated current object itself
                        }

            Why *this Works Correctly?
                It returns the modified object, allowing proper assignment and chaining.
                Ensures natural usage in expressions like a = ++b;.


    Operators that frequently use *this in their overloaded functions:

        1.  Assignment Operator (=)
        2.  Increment (++) and Decrement (--) Operators, for both prefix and postfix versions.
        3.  Compound Assignment Operators (+=, -=, *=, /=, etc.)
        4.  Dereference Operator (*). Often used in custom pointer-like classes (e.g., smart pointers).
        5.  Stream Insertion (<<) and Extraction (>>) or shift operators. Used in operator<< and operator>> for std::ostream and std::istream.

        Note: Both shift operators (<<, >>) and stream insertion-extraction operators (<<, >>) 
                use the same symbols but serve different purposes in C++. 
                The implementation of overloading differs based on how they are used.
*/




/* Example 1: Does an overloaded operator lose its original functionality?
            ans: 
                No. 
                When an operator is overloaded, it retains its original functionality for built-in data types. 
                Overloading only extends the operator's usability to user-defined types 
                    without affecting its existing operations on primitive types. 
*/




/* Example 2: Can an operator be overloaded for built-in data types?
            ans: 
                No. 
                An operator can only be overloaded for user-defined types (such as classes or structs). 
                C++ does not allow overloading an operator for built-in types like int, char, or float. 
*/




/* Example 3: Can overloading change the precedence or number of operands of an operator?

            Precedence: 
                No, overloading does not change the precedence of an operator. 
                It always follows the standard precedence rules defined in C++.

            Number of Operands: 
                No, the number of operands (arity) of an operator cannot be changed during overloading. 
                For example, a binary operator (e.g., +) must remain binary, 
                    and a unary operator (e.g., ++) must remain unary.
*/

