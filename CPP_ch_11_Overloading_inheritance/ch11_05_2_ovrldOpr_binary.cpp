
/*  ------------------------    operator overloading : BINARY    ------------------------

    Overloading binary operators
        When a "member operator function" overloads a BINARY operator, the function will have only "one parameter"
        The parameter will "receive" the object that is on the "right side" of the operator
        The object on the "left side" generates the call to the operator function and is passed implicitly using the "this" pointer.






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


1. The following program overloads the + operator relative to the coord class. This class
is used to maintain X, Y coordinates.
// Overload the + relative to coord class
# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; };
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
coord operator +( coord ob2);
};
// Overload + relative to coord class .
coord coord :: operator +( coord ob2)
{
coord temp ;
temp .x = x + ob2 .x;
temp .y = y + ob2 .y;
return temp ;
}
int main ()
{
coord o1 (10 , 10) , o2 (5, 3) , o3;
int x, y;
o3 = o1 + o2; // add two objects - this calls operator +
o3. get_xy (x, y);
cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";
return 0;
}
This program displays the following:
150INTRODUCING OPERATOR OVERLOADING
6.2. OVERLOADING BINARY OPERATORS
(o1+o2) X: 15, Y: 13
Let’s look closely at this program. The operator+() function returns an object of type
coord that has the sum of each operand’s X coordinates in x and the sum of the Y
coordinates in y. Notice that a temporary object called temp is used inside operator+()
to hold the result, and it is this object that is returned. Notice also that neither operand
is modified. The reason for temp is easy to understand. In this situation (as in most), the
+ has been overloaded in a manner consistent with its normal arithmetic use. Therefor,
it was important that neither operand be changed. For example, when you add 10+4, the
result is 14, but neither the 10 nor the 4 is modified. Thus, a temporary object is needed
to hold the result.
The reason that the operator+() function returns an object of type coord is that it
allows the result of the addition of coord objects to be used in larger expressions. For
example, the statement
o3 = o1 + o2
is valid only because the result of o1 + o2 is a coord object that can be assigned to o3.
If a different type had been returned, this statement would have been invalid. Further, by
returning a coord object, the addition operator allows a string of additions. For example,
this is a valid statement:
o3 = o1 + o2 + o1 + o3;
Although there will be situations in which you want an operator function to return something other than an object for which it is defined, most of the time operator functions
that you create will return an object of their class. (The major exception to this rule is
when the relational and logical operators are overloaded. This situation is examined in
Section 6.3, "Overloading the Relational and Logical Operators," later in this chapter.)
One final point about this example. Because a coord object is returned, the following
statement is also perfectly valid:
(o1+o2). get_xy (x, y);
Here the temporary object returned by operator+() is used directly. Of course, after
this statement has executed, the temporary object is destroyed.
2. The following version of the preceding program overloads the - and the = operators
relative to the coord class.
// Overload the +, -, and = relative to coord class .
# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; };
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
coord operator +( coord ob2);
coord operator -( coord ob2);
coord operator =( coord ob2);
};
151TEACH YOURSELF
C++
// Overload + relative to coord class .
coord coord :: operator +( coord ob2)
{
coord temp ;
temp .x = x + ob2 .x;
temp .y = y + ob2 .y;
return temp ;
}
// Overload - relative to coord class .
coord coord :: operator -( coord ob2)
{
coord temp ;
temp .x = x - ob2 .x;
temp .y = y - ob2 .y;
return temp ;
}
// Overload = relative to coord class .
coord coord :: operator =( coord ob2)
{
x = ob2 .x;
y = ob2 .y;
return * this ; // return the object that is assigned
}
int main ()
{
coord o1 (10 , 10) , o2 (5, 3) , o3;
int x, y;
o3 = o1 + o2; // add two objects - this calls operator +
o3. get_xy (x, y);
cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";
o3 = o1 - o2; // subtract two objects
o3. get_xy (x, y);
cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";
o3 = o1; // assign an object
o3. get_xy (x, y);
cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";
return 0;
}
The operator-() function is implemented similarly to operator+(). However, the above
example illustrates a crucial point when you are overloading an operator in which the order
152INTRODUCING OPERATOR OVERLOADING
6.2. OVERLOADING BINARY OPERATORS
of the operands is important. When the operator+() function was created, it did not
matter which order the operands were in. (That is, A + B is the same as B + A.) However,
the subtraction operation is order dependent. Therefore, to subtract the operand on the
right from the operand on the left. Because it is the left operand that generates the call
to operator-(), the subtraction must be in this order:
x - ob2 .x;
Remember: When a binary operator is overloaded, the left operand is passed implicitly
to the function and the right operand is passed as an argument.
Now look at the assignment operator function. The first thing you should notice that the
left operand (that is, the object being assigned a value) is modified by the operation. This
is in keeping with the normal meaning of assignment. The second thing to notice is that
the function returns *this. That is, the operator=() function returns the object that is
being assigned to. The reason for this is to allow a series of assignments to be made. As
you should know, in C++, the following type of statement is syntactically correct (and
indeed very common):
a = b = c = d = 0;
By returning *this, the overloaded assignment operator allows objects of type coord to
be used in a similar fashion. For example, this is perfectly valid:
o3 = o2 = o1;
Keep in mind that there is no rule that requires an overloaded assignment function to
return the object that receives the assignment. However, if you want the overloaded = to
behave relative to its class the way it does for the built-in types, it must return *this.
3. It is possible to overload an operator relative to a class so that the operand on the right
side is an object of a built-in type, such as an integer, instead of the class for which the
operator function is a member. For example, here the + operator is overloaded to add an
integer value to a coord object:
// Overload the + for ob + int as well as ob + ob.
# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; };
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
coord operator +( coord ob2); // ob + ob
coord operator +( int i); // ob + int
};
// Overload + relative to coord class .
coord coord :: operator +( coord ob2)
{
coord temp ;
temp .x = x + ob2 .x;
temp .y = y + ob2 .y;
153TEACH YOURSELF
C++
return temp ;
}
// Overload + for ob + int
coord coord :: operator +( int i)
{
coord temp ;
temp .x = x + i;
temp .y = y + i;
return temp ;
}
int main ()
{
coord o1 (10 , 10) , o2 (5, 3) , o3;
int x, y;
o3 = o1 + o2; // add two objects - calls operator +( coord )
o3. get_xy (x, y);
cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";
o3 = o1 + 100; // add object + int - calls operator +( int )
o3. get_xy (x, y);
cout << "(o1 +100) X: " << x << ", Y: " << y << "\n";
return 0;
}
It is important to remember that when you are overloading a member operator function
so that an object can be used in an operation involving a built-in type, the built-in type
must be on the right side of the operator. The reason for this is easy to understand: It is
the object on the left that generates the call to the operator function. For instance, what
happens when the compiler sees the following statement?
o3 = 19 + o1; // int + ob
There is no built-in operation defined to handle the addition of an integer to an object.
The overloaded operator+(int i) function works only when the object is on the left.
Therefore, this statement generates a compile-time error. (Soon you will see one way
around this restriction.)
4. You can use a reference parameter in an operator function. For example, this is a perfectly
acceptable way to overload the + operator relative to the coord class:
// Overload + relative to coord class using references .
coord coord :: operator +( coord &ob2)
{
coord temp ;
temp .x = x + ob2 .x;
temp .y = y + ob2 .y;
154INTRODUCING OPERATOR OVERLOADING
6.3. OVERLOADING THE RELATIONAL AND LOGICAL OPERATORS
return temp ;
}
One reason for using a reference parameter in an operator function is efficiency. Passing
objects as parameters to functions often incurs a large amount of overhead and consumes
a significant number of CPU cycles. However, passing the address of an object is always
quick and efficient. If the operator is going to be used often, using a reference parameter
will generally improve performance significantly.
Another reason for using a reference parameter is to avoid the trouble caused when a
copy of an operand is destroyed. As you know from previous chapters, when an argument
is passed by value, a copy of that argument is made. If that object has a destructor
function, when the function terminates, the copy’s destructor is called. In some cases it is
possible for the destructor to destroy something needed by the calling object. If this is the
case, using a reference parameter instead of a value parameter is an easy (and efficient)
way around the problem. Of course, you could also define a copy constructor that would
prevent this problem in the general case.


EXERCISES
1. Relative to coord, overload the * and / operators. Demonstrate that they work.
2. Why would the following be an inappropriate use of an overloaded operator?
coord coord :: operator %( coord ob)
{
double i;
cout << " Enter a number : ";
cin >> i;
cout << " root of " << i << " is ";
cout << sqrt (i);
}
3. On your own, experiment by changing the return types of the operator functions to something other than coord. See what types of errors result
