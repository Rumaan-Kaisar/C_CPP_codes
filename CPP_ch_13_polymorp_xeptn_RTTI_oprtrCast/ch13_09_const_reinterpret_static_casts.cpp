
/*  ------------------------    chapter    ------------------------
13.9.2 const_cast, reinterpret_cast and static_cast
General forms of other three casting operators are:
const_cast< target_type > (expr)
reinterpret_cast< target_type > (expr)
static_cast< target_type > (expr)
	Here target_type specifies the target type of the cast and expr is the expression being cast into the new type.
	const_cast: The const_cast operator is used to explicitly override const and/or volatile in a cast.  The most common use of const_cast is to remove const-ness.
	The target_type must be the same as the source type except for the alteration of its const or volatile attributes. 
	static_cast: The static_cast operator performs a non-polymorphic cast. For example, it can be used to cast a base class pointer into a derived class pointer. 
	It can also be used for any standard conversion.		No run-time checks are performed.

	reinterpret_cast: The reinterpret_cast operator: 		Changes one pointer type into another (mainly different, pointer type).
	It can also change a pointer into an integer and an integer into a pointer. 
	A reinterpret_cast should be used for casting inherently incompatible pointer types.

Note: Only const_cast can cast away const-ness. That is, neither dynamic_cast, static_cast, nor reinterpret_cast can alter the const-ness of an object.

	Example 1: The following program demonstrates dynamic_cast:
class Base{ public : virtual void f(){ cout << "Inside Base \n"; } };
class Derived : public Base{ public : void f() { 
				cout << " Inside Derived \n"; } };

int main() { 	Base *bp , b_ob ;
Derived *dp , d_ob ;

dp = dynamic_cast < Derived *> (& d_ob );
if(dp) { 	cout << " Cast from Derived * to Derived * OK .\n";     dp ->f(); }
else 	cout << " Error \n";
cout << endl ;

bp = dynamic_cast < Base *> (& d_ob );
if(bp) {	cout << " Cast from Derived * to Base * OK .\n";    bp ->f(); }
else	cout << " Error \n";
cout << endl ;

bp = dynamic_cast < Base *> (& b_ob );
if(bp) { cout << " Cast from Base * to Base * OK .\n";    bp ->f();}
else	cout << " Error \n";
cout << endl ;

/*following is not ok*/
dp = dynamic_cast < Derived *> (& b_ob );
if(dp)	cout << " Error \n";
else	cout << " Cast from Base* to Derived* not OK .\n";
cout << endl ;	bp = &d_ob ;        /* base pointer bp points to Derived object */ 
dp = dynamic_cast < Derived *> (bp);
if(dp){cout  << " Casting bp to a Derived * OK .\n" 
	      <<" because bp is really	pointing \n"
 	      <<"to a Derived object .\n";
              dp ->f();}
else   cout << " Error \n";
cout << endl ;

bp = &b_ob ; 		/* bp points to Base object */ 
dp = dynamic_cast < Derived *> (bp);             /* NOT OK:  */
if(dp) cout << " Error \n";
else { cout  << "Now casting bp to a Derived *\n" 
	    << "is not OK because bp is really \n" 
	    <<" pointing to a Base object .\n"; }
cout << endl ;

dp = &d_ob ; 		/* dp points to Derived object */ 
bp = dynamic_cast < Base *> (dp);
if(bp){	cout << " Casting dp to a Base * is OK .\n";
	bp ->f(); }
else cout << " Error \n";
return 0; }

Output:
Cast from Derived * to Derived * OK.
Inside Derived
Cast from Derived * to Base * OK.
Inside Derived	
Cast from Base * to Base * OK.	Inside Base
Cast from Base * to Derived * not OK.
Casting bp to a Derived * OK.
because bp is really pointing
to a Derived object.
Inside Derived	Now casting bp to a Derived *
is not OK because bp is really
pointing to a Base object.
Casting dp to a Base * is OK.
Inside Derived

	Cast from base* to derived* means: derived pointer points to a base object via derived* cast. 
	Example 2: The following example illustrates how a dynamic_cast can be used to replace typeid.
# include <iostream >
# include <typeinfo >
using namespace std;

class Base { public : virtual void f() {} };
class Derived : public Base { public : void derivedOnly(){ cout << "Is a Derived Object \n";} 	 };	
Output :
Cast from Base to Derived failed.
Is a Derived Object
Cast from Base to Derived failed.
Is a Derived Object
int main() {  Base *bp , b_ob ;
	       Derived *dp , d_ob ;
	/* use typeid */
	bp = & b_ob ;
	if( typeid (* bp) == typeid ( Derived )){dp = ( Derived *) bp;
					   dp -> derivedOnly( );}
	else cout << " Cast from Base to Derived failed .\n";

	bp = & d_ob ;
if( typeid (* bp) == typeid ( Derived )){dp = ( Derived *) bp;
					     dp -> derivedOnly( );}
	else cout << "Error , cast should work !\n";	/* use dynamic_cast */
	bp = &b_ob ;
	dp = dynamic_cast < Derived *> (bp);
	if(dp) dp -> derivedOnly ();
	else cout << " Cast from Base to Derived failed .\n";

	bp = & d_ob ;
	dp = dynamic_cast < Derived *> (bp);
	if(dp) dp -> derivedOnly ();
	else cout << "Error , cast should work !\n";

return 0; }
	The use of dynamic_cast simplifies the logic required to cast a base pointer into a derived pointer. 
	 Example 3: The dynamic_cast operator can also be used with template classes. For example, the following program reworks the template class from Example 4 in the preceding section so that it uses dynamic_cast to determine the type of object returned by the generator() function.
/*  . . . . . . .  same as Exampole 4,   section 13.8   RTTI */
int main() { 	Num <double> ob1(10), *p1;
Square <double> ob2(100.0), *p2;
Sqr_root <double> ob3(999.2), *p3;
int i;

cout << " Generate some objects .\n";
for(i=0; i <10; i++) { 	p1 = generator();

p2 = dynamic_cast < Square<double> * > (p1);
if(p2) cout << " Square object : ";

p3 = dynamic_cast < Sqr_root<double> * > (p1);
if(p3) cout << " Sqr_root object : ";

cout << "Value is:" << p1 -> get_val();
cout << endl; }
return 0; }

	Example 4: The following program demonstrates the use of reinterpret_cast.
int main() { 	int i;
char *p = " This is a string ";

i = reinterpret_cast <int> (p); 		/* cast pointer to integer */ 
cout << i;
return 0;}

	Here reinterpret_cast converts the pointer p into an integer. This conversion represents a fundamental type change and is a good use of reinterpret_cast.

	Example 5 :The following program demonstrates const_cast.
void f( const int *p) { 	int *v;
v = const_cast <int *> (p); /* cast away const - ness */
*v = 100; 	/* now , modify object through v */ 	}
int main(){ 	int x = 99;
cout << "x before call : " << x << endl ;
f(&x);
cout << "x after call : " << x << endl ;
return 0; }	Output:
x before call: 99
x after call: 100

	As you can see, x was modified by f() even though the parameter to f() was specified as a const pointer.
	It must be stressed that the use of const_cast to cast way const-ness is a potentially dangerous feature. Use it with care.

	Example 6: The static_cast operator is essentially a substitute for the original cast operator. It simply performs a non-polymorphic cast. For example, the following casts a float into an int.
int main() {	int i; float f;
f = 199.22;
i = static_cast <int> (f);
cout << i;
return 0;}


*/  
