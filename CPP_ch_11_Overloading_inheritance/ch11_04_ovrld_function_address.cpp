
/*  ------------------------    address of an overloaded function    ------------------------

Finding the address of an overloaded function

recall function pointers: "C_Ch8_6_func_pointers.c"

Address of an OVERLOADED function :
    In C, you can assign the address of a function (that is, its entry point) to a pointer and access that function via that pointer. A function's address is obtained by putting its name on the right side of an assignment statement without any parentheses or arguments. For example, if zap() is a function, then we assign p the address of zap():	 p = zap;
    	In C, any type of pointer can be used to point to a function because there is only one function that it can point to. 
    	In C++ the situation is a bit more complex because a function can be overloaded.  When we assign the address of an overloaded function to a function pointer, it is the declaration of the pointer that determines which function's address is assigned. Further, the declaration of the function pointer must exactly match one and only one of the overloaded functions. If it does not, ambiguity will be introduced, causing a compile-time error.

void space(int n){ /* Type-1: Output n number of spaces */
		for( ; n ; n --) cout << ' '; }

void space(int n , char ch){ /* Type-2: Output n chs */
		for( ; n ; n --) cout << ch; }
int main() {
         /* pointer to void function with one int parameter */
void ( *fp1 )(int );  	/* matches to Type-1  */
         /* pointer to void function with int and character parameter. */
void ( *fp2 )(int, char); 	/* matches to Type-2  */	fp1 = space ; 	/* gets address of space(int)*/ 
fp2 = space ; 	/* gets address of space(int , char )*/ 
fp1(22) ; 		/* output 22 spaces */ 
cout << "|\n";
fp2 (30 , 'x'); 	/* output 30 x's */ 
cout << "|\n";
return 0;}

	Here two versions of a function called space(). The first version outputs n number of spaces to the screen. The second version outputs n number of whatever type of character is passed to ch. 
	In main(), two function pointers are declared. The first one is specified as a pointer to a function having only one integer parameter. The second is declared as a pointer to a function taking two parameters : one integer and one character.
	The compiler is able to determine which overloaded function to obtain the address of based upon how fp1 and fp2 are declared.


*/  
