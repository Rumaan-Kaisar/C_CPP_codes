
/*  ------------------------    chapter    ------------------------

Overloading binary operators

11.9 Overloading Binary Operators
When a member operator function overloads a binary operator, the function will have only one parameter. 
	The parameter will receive the object that is on the right side of the operator. 
	The object on the left side is the object that generates the call to the operator function and is passed implicitly by this (pointer).
	Operator functions can be written in various way, some are shown in the examples:
	Example 1( return type, temporary object, no-operator modification ):  Overload the + operator relative to the coord class. This class is used to maintain X, Y coordinates.

class coord {	int x, y; 		/* coordinate */ 
	public :
		coord() { x=0; y=0; };
		coord(int i, int j) {x=i; y=j; }
		void get_xy(int &i, int &j) {
 					i=x; j=y; }
		coord operator+(coord ob2); };
	/* coord type used for overloaded operator */			/* Overload + relative to coord class.*/ 
coord coord :: operator +( coord ob2) {
	/* one coord for type and another is for class*/
		coord temp ;
		temp.x = x + ob2.x;
		temp.y = y + ob2.y;
		return temp ;
	}
		int main() { 	coord o1(10 , 10), o2(5, 3), o3;
				int x, y;
				o3 = o1 + o2; 	/* add two objects – "this" calls operator + */ 
				o3.get_xy(x, y);
				cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";
				return 0; }
Output:   (o1+o2) X: 15, Y: 13
	Notice that there is no ob1 in operator function (it is implicit here and used to call ob2), however we'll use both ob1 and ob2 in the friend operator function. 
	The reason that the operator+() function returns an object of type coord is: o3 = o1 + o2 is valid iff the result of o1 + o2 is a coord object that can be assigned to o3. If a different type had been returned, this statement would have been invalid. 
	Notice that a temporary object called temp is used inside operator+() to hold the result, and it is the returned object. 
	The reason for temp is: a temporary object is needed to hold the result. In this situation (as in most), the + has been overloaded in a manner consistent with its normal arithmetic use. Therefore, neither operand be changed. For example, for 10+4=14, the result is 14, but neither the 10 nor the 4 is modified.
	Because a coord object is returned, the statement: (o1+o2). get_xy (x, y); is also perfectly valid. Here the temporary object returned by operator+() is used directly and  after execution the temporary object is destroyed.
	Example 2( order of objects, implicit first object, assignment operator ):  Overload the +, - and "=" operator relative to the coord class. This class is used to maintain X, Y coordinates  similar to previous example.

		class coord { 	/* all elements of public are same, only declare operator functions*/
			public: 	. . . . . . . /* all elements similar to Example 1 */ . . . . . . 
				coord operator +( coord ob2); 
				coord operator -( coord ob2); 
				coord operator =( coord ob2); };
coord coord :: operator +( coord ob2) {
coord temp ;
	temp.x = x + ob2.x;
	temp.y = y + ob2.y;
	return temp ; }	coord coord :: operator -( coord ob2) {
coord temp ;
	temp.x = x - ob2.x;
	temp.y = y - ob2.y;
	return temp ; }	coord coord :: operator =( coord ob2) {
	x = ob2.x;
	y = ob2.y;
	return *this ; 
/* return the object that is assigned */  }
int main() {	coord o1(10 , 10) , o2(5, 3) , o3;
		int x, y;
o3 = o1+o2; 	o3.get_xy(x, y); cout<< "(o1+o2) X: "<< x <<", Y: "<< y <<"\n";  /* add two objects */ 
o3 = o1-o2; 	o3.get_xy(x, y); cout<< "(o1-o2) X: "<< x <<", Y: "<< y <<"\n";  /* subtract two objects */ 
o3 = o1; 	o3.get_xy(x, y); cout<< "(o3=o1) X: "<< x <<", Y: "<< y <<"\n";  /* assign an object */ 
return 0; }
	Order of the operands: The operator-() function is implemented similarly to operator+(). However the order of the operands is important while overloading an operator. 
	The order of the left-operand which "generates the call to operator-()" and the right-operand which "passed as an argument  to the operator-()" is important for subtraction because  A-B≠ B-A, It must be in the order:   x - ob2.x; . 
	The order of the left-operand and right-operand is also important when we use built-in-type variables as right-operand .
	The order of the left-operand and the right-operand is not important for addition.
	The assignment operator function:  Here the left-operand is modified by the operation (that is, the object being assigned a value).  This is in keeping with the normal meaning of assignment. 
	The function returns *this. That is, the operator=() function returns the object that is being assigned to. The reason for this is to allow a series of assignments to be made. Eg: we used a = b = c = d = 0; for variables, returning *this by overloaded assignment operator allows us to use o3 = o2 = o1; for multiple objects.
	There is no rule that requires an overloaded assignment function to return the object that receives the assignment. However, if you want the overloaded = to behave relative to its class the way it does for the built-in types, it must return *this.
	Example 3( built-in-type objects i.e. int-float-char, order of the operands ):  Overload the + operator relative to the coord class with built-in-type objects (i.e int, float, char etc). This class is used to maintain X, Y coordinates  similar to previous example.

class coord { 
	public: 	
/* all elements similar to Example 1 */ 
coord operator+(coord ob2); 	    //obj+obj
coord operator+(int i); };       //obj+int	coord coord :: operator +( coord ob2) {
coord temp ;
	temp.x = x + ob2.x;
	temp.y = y + ob2.y;
	return temp ; }	coord coord :: operator +( int i) {
coord temp ;
	temp.x = x + i;
	temp.y = y + i;
	return temp ; }
int main() {	coord o1(10 , 10) , o2(5, 3) , o3;
		int x, y;
o3 = o1+o2; 	o3.get_xy(x, y); cout<< "(o1+o2) X: "<< x <<", Y: "<< y <<"\n";     /* add two objects */ 
o3 = o1+100; 	o3.get_xy(x, y); cout<< "(o1+100) X: "<< x <<", Y: "<< y <<"\n";    /* add object + int */ 
return 0; }

	The order of the left-operand and right-operand is important when we use built-in-type variables as right-operand . The reason is: It is the object on the left that generates the call to the operator function. For instance,  o3 = 19 + o1; /* int + obj */ generates a compile-time error. Because there is no built-in operation defined to handle the addition of an integer to an object.
	The overloaded operator+(int i) function works only when the object is on the left. (However there is a solution around this restriction.)
	Example 4( reference parameter in operator funtion ):  Overload the + operator relative to the coord class using reference. This class is used to maintain X, Y coordinates  similar to previous example.

coord coord :: operator+( coord &ob2) {	coord temp ; 	/* using references.*/ 
temp.x = x + ob2.x;
temp.y = y + ob2.y;
return temp ; }
	Efficiency: Passing the address of an object is always quick and efficient and do not consume CPU cycles as much as normal object parameters do. If the operator is going to be used often, using a reference parameter is a good choice.
	Prevent temporary object/operand destruction after execution (recall 10.10):  when an argument is passed by value, a copy of that argument is made. If that object has a destructor function, when the function terminates, the copy's destructor is called. 
	Using a reference parameter instead of a value parameter is an easy (and efficient) way around the problem. 
	However, we could also define a copy constructor that would prevent this problem in the general case.
Note:
When a binary operator is overloaded, the left operand is passed implicitly to the function and the right operand is passed as an argument.


*/  
