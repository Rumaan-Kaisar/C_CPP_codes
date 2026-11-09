				
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

// ---- rev[08-Nov-2026] ----


    --------  Casting Between Base and Derived  --------
    
    The purpose of dynamic_cast is to perform casts on polymorphic types,
    
    For example, given the two polymorphic classes B and D, assume:
        B is a polymorphic base class.
        D is derived from B.

Base-to-derived casting (B* → D*):
- The cast succeeds only if the object actually is a D object (or an object derived from D).
- Otherwise, the cast fails.
Derived-to-base casting (D* → B*):
- The cast succeeds because a derived-class object can always be accessed through a base-class pointer, assuming a valid accessible base relationship.




Note:
    A dynamic_cast can always cast a "D* pointer" into a "B* pointer" (D* → B*).
        Because a "base pointer" can always point to a "derived".

    But a dynamic_cast can cast a B* pointer into a D* pointer only if 
        the object being pointed to actually is a "D object".

   In general, dynamic_cast will succeed if the pointer (or reference) being cast is a pointer (or reference) to either an object of the target type or an object derived from the target type. Otherwise, the cast will fail. 
   If the cast fails, dynamic_cast evaluates to null if the cast involves pointers. 
   If a dynamic_cast on reference types fails, a bad_cast exception is thrown.


   Example of Successful cast: Assume that Base is a polymorphic class and that Derived is derived from Base.
Base *bp, b_ob;
Derived *dp, d_ob;
bp = &d_ob ;            // base pointer points to Derived object : ok
dp = dynamic_cast < Derived * >(bp);
if(dp) cout << " Cast OK ";
   Here the cast from the base pointer bp to the derived pointer dp works because bp is actually pointing to a Derived object. It displays "Cast OK". 


   Example of Unsuccessful cast: In the next fragment, the cast fails because bp is pointing to a Base object and it is illegal to cast a base object into a derived object. It displays "Cast Fails".

bp = &b_ob ;            // base pointer points to Base object : Wrong 
dp = dynamic_cast < Derived *>(bp);
if (!dp) cout << " Cast Fails ";
Notes:
The dynamic_cast operator can sometimes be used instead of typeid. Consider the previous example. The following fragment will assign dp the address of the object pointed to by bp  iff  the object is really a Derived object.

Base *bp;
Derived *dp;
// ...
if( typeid(*bp) == typeid(Derived) ) dp  = (Derived *) bp;

   Here a C-style cast is used to perform the cast. It's safe because the if checks the legality of the cast using typeid before the cast actually occurs. 
   The better way to accomplish this is to replace the typeid operators and if statement with this dynamic_cast:
dp = dynamic_cast < Derived *> (bp);
   After this statement executes dp will contain either a null or a pointer to an object of type Derived. Because dynamic_cast succeeds only if the object being cast is either 
   already an object of the target type or 
   an object derived from the target type, 
   Since dynamic_cast succeeds only if the cast is legal, it can simplify the logic in certain situations.


*/  




/*  ----  GPT  ----



4. Success and Failure of dynamic_cast
- The cast succeeds if the object is compatible with the target type.
- Otherwise, the cast fails.
If the cast fails:
- For pointer types → returns nullptr.
- For reference types → throws a std::bad_cast exception.


5. Example of Successful Casting
Assume Base is polymorphic and Derived is derived from Base.
Base *bp, b_ob;
Derived *dp, d_ob;

bp = &d_ob;   // Base pointer points to Derived object

dp = dynamic_cast<Derived*>(bp);

if (dp)
    cout << "Cast OK";

Explanation:
- bp points to an actual Derived object.
- Therefore, the cast from Base* to Derived* succeeds.
- The output is:
Cast OK


6. Example of Unsuccessful Casting

bp = &b_ob;   // Base pointer points to Base object

dp = dynamic_cast<Derived*>(bp);

if (!dp)
    cout << "Cast Fails";

Explanation:
- bp points to a Base object, not a Derived object.
- Therefore, the cast fails and dp becomes nullptr.
- The output is:
Cast Fails


7. dynamic_cast vs. typeid

Previously, typeid could be used to check the object's type before casting:

if (typeid(*bp) == typeid(Derived))
    dp = (Derived*)bp;

- typeid checks the object's run-time type.
- A C-style cast is then used to perform the conversion.
- This requires a separate type check and cast.

A simpler and safer approach is:

dp = dynamic_cast<Derived*>(bp);

- dynamic_cast performs the type check and cast together.
- If successful, dp contains a valid pointer.
- If unsuccessful, dp becomes nullptr.
- Therefore, dynamic_cast simplifies the logic and avoids a separate typeid check.

Key Points to Remember
- dynamic_cast performs run-time type checking.
- It is mainly used with polymorphic classes.
- Base-to-derived casting succeeds only when the actual object is compatible with the target type.
- Failed pointer cast → nullptr.
- Failed reference cast → std::bad_cast.
- It is safer than unchecked downcasting.




Important correction:
For dynamic_cast to work with class types, the source type must be polymorphic when performing a run-time downcast or cross-cast. 
A polymorphic class must have at least one virtual function, commonly a virtual destructor.

*/
