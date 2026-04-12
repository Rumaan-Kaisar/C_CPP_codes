
/*  ------------------------    chapter    ------------------------


13.9 C++ casting operators
C++ has four new casting operators. They are:	[1]	dynamic_cast	[2]	const_cast	[3]	reinterpret_cast	[4]	static_cast
13.9.1 dynamic_cast:
	The dynamic cast is related to RTTI, it performs a run-time cast that verifies the validity of a cast. Dynamic cast can be used to cast one type of pointer into another or one type of reference into another. The general form of dynamic cast is:
dynamic_cast<target_type>(expr)
	Here target_type  specifies the target type of the cast and expr is the expression being cast into the new type. 
	The target_type must be a pointer or reference type, and " expr "  the expression being cast must evaluate to a pointer or reference. 
	If the cast is invalid during the execution of dynamic_cast, the cast fails. 
	The purpose of dynamic_cast is to perform casts on polymorphic types: For example, given the two polymorphic classes B and D, with D derived from B.
	A dynamic_cast can always cast a D* pointer into a B* pointer. Because a base pointer can always point to a derived.
	But a dynamic_cast can cast a B* pointer into a D* pointer only if the object being pointed to actually is a D object. 
	In general, dynamic_cast will succeed if the pointer (or reference) being cast is a pointer (or reference) to either an object of the target type or an object derived from the target type. Otherwise, the cast will fail. 
	If the cast fails, dynamic_cast evaluates to null if the cast involves pointers. 
	If a dynamic_cast on reference types fails, a bad_cast exception is thrown.
	Example of Successful cast: Assume that Base is a polymorphic class and that Derived is derived from Base.
Base *bp, b_ob;
Derived *dp, d_ob;
bp = &d_ob ; 			/* base pointer points to Derived object : ok */ 
dp = dynamic_cast < Derived * >(bp);
if(dp) cout << " Cast OK ";
	Here the cast from the base pointer bp to the derived pointer dp works because bp is actually pointing to a Derived object. It displays "Cast OK". 
	Example of Unsuccessful cast: In the next fragment, the cast fails because bp is pointing to a Base object and it is illegal to cast a base object into a derived object. It displays "Cast Fails".

bp = &b_ob ; 			/* base pointer points to Base object : Wrong */ 
dp = dynamic_cast < Derived *>(bp);
if (!dp) cout << " Cast Fails ";
Notes:
The dynamic_cast operator can sometimes be used instead of typeid. Consider the previous example. The following fragment will assign dp the address of the object pointed to by bp  iff  the object is really a Derived object.

Base *bp;
Derived *dp;
// ...
if( typeid(*bp) == typeid(Derived) ) dp  = (Derived *) bp;

	Here a C-style cast is used to perform the cast. It's safe because the if checks the legality of the cast using typeid before the cast actually occurs. 
	The better way to accomplish this is to replace the typeid operators and if statement with this dynamic_cast:
dp = dynamic_cast < Derived *> (bp);
	After this statement executes dp will contain either a null or a pointer to an object of type Derived. Because dynamic_cast succeeds only if the object being cast is either 
	already an object of the target type or 
	an object derived from the target type, 
	Since dynamic_cast succeeds only if the cast is legal, it can simplify the logic in certain situations.


*/  
