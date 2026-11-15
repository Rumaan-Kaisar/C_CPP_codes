				
/*  ------------------------    C++ casting operators    ------------------------

    C++ has four new casting operators. They are:
        [1] dynamic_cast
        [2] const_cast
        [3] reinterpret_cast
        [4] static_cast


    --------  dynamic_cast  --------
    
    dynamic_cast is related to RTTI (Run-Time Type Information).
        It performs a run-time type conversion and checks whether the cast is valid.

    It is mainly used for casting between pointers or references of polymorphic classes. 
    It can convert:
        One type of pointer into another pointer type.
        One type of reference into another reference type.

    General form:

                dynamic_cast<target_type>(expr)

        target_type:
            specifies the target type of the cast
            The target type must be a pointer or reference type.

        expr:
            it is the expression being cast into the new type. 
            The expression must evaluate to a pointer or reference.

        If the cast is invalid during the execution of dynamic_cast, the cast fails. 



    --------  Casting Between Base and Derived  --------
    
    The purpose of dynamic_cast is to perform casts on polymorphic types,
    
    For example, given the two polymorphic classes B and D, assume:
        B is a polymorphic base class.
        D is derived from B.

    Base-to-derived casting (B* --> D*):
        The cast succeeds only if the object actually is a D object (or an object derived from D).
        Otherwise, the cast fails.

    Derived-to-base casting (D* --> B*):
        The cast succeeds because a derived-class object can always be accessed through a base-class pointer, 
            assuming a valid accessible base relationship.

    Note:
        A dynamic_cast can always cast a "D* pointer" into a "B* pointer" (D* --> B*).
            Because a "base pointer" can always point to a "derived".

        But a dynamic_cast can cast a B* pointer into a D* pointer only if 
            the object being pointed to actually is a "D object".



    --------  Success/Failure  --------

    In general, dynamic_cast will succeed if the "pointer (or reference) being cast" is a pointer (or reference) to 
        either an "object of the target type" or an "object derived from the target type".
        
        i.e. the cast succeeds if the object is "compatible" with the "target type". Otherwise, the cast fails.

        Otherwise, the cast will fail. 
            If the cast fails, dynamic_cast evaluates to null if the cast involves pointers. 
            If a dynamic_cast on reference types fails, a bad_cast exception is thrown.

    FAILURE OUTCOME i.e if the cast fails:
        For pointer types --> returns nullptr.
        For reference types --> throws a std::bad_cast exception.


    Example of Successful cast:
        Assume that "Base" is a polymorphic class and "Derived" is derived from "Base".

            Base *bp, b_ob;
            Derived *dp, d_ob;

            bp = &d_ob;         // base pointer points to Derived object : ok
            dp = dynamic_cast <Derived*>(bp);
            if(dp) cout << " Cast OK ";

        Here the cast from the "base pointer bp" to the "derived pointer dp" works 
            because "bp" is actually pointing to a "Derived" object. 
            It displays "Cast OK". 


    Example of Unsuccessful cast:
        In the next fragment, the "cast fails" because "bp" is pointing to a "Base" object 
        and it is "illegal" to cast a "base object" into a "derived object". 
        It displays "Cast Fails".

            bp = &b_ob;         // base pointer points to Base object : Wrong 
            dp = dynamic_cast <Derived*>(bp);
            if(!dp) cout << " Cast Fails ";

        reason:
            bp points to a Base object, not a Derived object.
            Therefore, the cast fails and dp becomes nullptr.

    Remember:
        If the base pointer points to a derived object, the cast succeeds.
        If the base pointer points to a base object, the cast fails.



    --------  dynamic_cast vs. typeid  --------

    The "dynamic_cast" operator can sometimes be used instead of "typeid". Consider the previous example-
    The following fragment will assign "dp" the address of the object pointed to by "bp"  iff  the object is really a "Derived object."

            Base *bp;
            Derived *dp;
            // ...
            if( typeid(*bp) == typeid(Derived) ) dp = (Derived*)bp;

    Above "C-style cast" is used to perform the cast. It's safe because 
        the "if" checks the legality of the cast using "typeid" before the cast actually occurs.

    This requires a separate type check and cast:
        "typeid" checks the object's run-time type.
        A C-style cast is then used to perform the conversion.


    Simpler and safer approach is:
        Replace the "typeid" operators and "if statement" with dynamic_cast:

            dp = dynamic_cast<Derived*>(bp);

        After this statement executes "dp" will contain either 
            a "null" or a "pointer to an object" of type "Derived".

        - dynamic_cast performs the "type check" and "cast" together.
        - If successful, dp contains a valid pointer.
        - If unsuccessful, dp becomes "nullptr".

        Because dynamic_cast succeeds only if the object being cast is either:
            - already an object of the target type or 
            - an object derived from the target type, 

        Since dynamic_cast succeeds only if the cast is legal, 
            Therefore, dynamic_cast simplifies the logic and avoids a separate typeid check.



    --------  Key Points  --------

    dynamic_cast performs run-time type checking.
        It is mainly used with polymorphic classes.

    It is safer than unchecked "downcasting".

    Base-to-derived casting succeeds only when the actual object is compatible with the target type.

    Remember:
        For dynamic_cast to work with class types, the "source type" must be polymorphic 
            when performing a run-time "downcast" or "cross-cast".

        A polymorphic class must have "at least one virtual function", 
            commonly a virtual destructor (e.g., virtual ~Base() = default;).
*/


// ---- rev[14-Nov-2026] ----

1. The following program demonstrates dynamic cast:
// Demonstrate dynamic_cast .
# include <iostream >
using namespace std ;
class Base
{
public :
virtual void f() { cout << " Inside Base \n"; }
// ...
};
class Derived : public Base
{
public :
void f() { cout << " Inside Derived \n"; }
};
int main ()
{
Base *bp , b_ob ;
Derived *dp , d_ob ;
dp = dynamic_cast < Derived *> (& d_ob );
if(dp)
{
cout << " Cast from Derived * to Derived * OK .\n";
dp ->f();
}
else
cout << " Error \n";
cout << endl ;
bp = dynamic_cast < Base *> (& d_ob );
if(bp)
{
cout << " Cast from Derived * to Base * OK .\n";
bp ->f();
}
else
cout << " Error \n";
cout << endl ;
bp = dynamic_cast < Base *> (& b_ob );
if(bp)
{
cout << " Cast from Base * to Base * OK .\n";
bp ->f();
322RUN-TIME TYPE IDENTIFICATION AND THE CASTING OPERATORS
12.2. USING dynamic cast
}
else
cout << " Error \n";
cout << endl ;
dp = dynamic_cast < Derived *> (& b_ob );
if(dp)
cout << " Error \n";
else
cout << " Cast from Base * to Derived * not OK .\n";
cout << endl ;
bp = & d_ob ; // bp points to Derived object
dp = dynamic_cast < Derived *> (bp);
if(dp)
{
cout << " Casting bp to a Derived * OK .\n" <<
" because bp is really pointing \n" <<
"to a Derived object .\n";
dp ->f();
}
else
cout << " Error \n";
cout << endl ;
bp = & b_ob ; // bp points to Base object
dp = dynamic_cast < Derived *> (bp);
if(dp)
cout << " Error \n";
else
{
cout << " Now casting bp to a Derived *\n" <<
"is not OK because bp is really \n" <<
" pointing to a Base object .\n";
}
cout << endl ;
dp = & d_ob ; // dp points to Derived object
bp = dynamic_cast < Base *> (dp);
if(bp)
{
cout << " Casting dp to a Base * is OK .\n";
bp ->f();
}
else
cout << " Error \n";
323TEACH YOURSELF
C++
return 0;
}
The program produces the following output


Cast from Derived * to Derived * OK.
Inside Derived
Cast from Derived * to Base * OK.
Inside Derived
Cast from Base * to Base * OK.
Inside Base
Cast from Base * to Derived * not OK.
Casting bp to a Derived * OK.
because bp is really pointing
to a Derived object.
Inside Derived
Now casting bp to a Derived *
is not OK because bp is really
pointing to a Base object.
Casting dp to a Base * is OK.
Inside Derived



2. 
