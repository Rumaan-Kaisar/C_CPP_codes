
/*  ------------------------    overload using FRIEND    ------------------------

    Friend functions basics: 
        previously discussed in "ch10_07_friend_func.cpp"
        Here we'll discuss OVERLOAD an operator relative to a class by using a FRIEND


    Overloading FRIEND OPERATOR FUNCTIONS
        We can overload an operator relative to a class by using a "FRIEND" rather than a "member" function.


    Since a FRIEND function does not have a "this" pointer: 
        For BINARY operators, a friend operator function is passed both operands explicitly
        For UNARY operators, the single operand is passed explicitly
        The assignment operator (=) cannot be overloaded using a friend function
            It can only be overloaded using a member function
*/




/* Example 1: Here operator+() is overloaded for the coord class using a FRIEND function.
                Notice that the left operand is passed to the first parameter and
                the right operand is passed to the second parameter. 
*/
#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // operator overlading using a friend
        friend coord operator+(coord ob1, coord ob2);   // passed both operands explicitly
};


// Overload + using a FRIEND
coord operator+(coord ob1, coord ob2){
    coord temp;
    temp.x = ob1.x + ob2.x;
    temp.y = ob1.y + ob2.y;
    return temp;
}


int main(){
    coord o1(10,10), o2(5,3), o3;
    int x, y;

    o3 = o1 + o2; // add two objects - this calls operator +()
    o3.get_xy(x, y);
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    return 0;
}




// rev[10-Jan-2025]

/* Example 2: All else being equal, there is no reason to use a "friend" function instead of a "member" operator function, 
                except for one important exception discussed in the following program. 
*/



	Example 2 (No-order for objects): For an overloaded member operator function ob1=10+ob2; is illegal. 
And the member operator function works only when the built-in object type is on the left.
	A friend operator function allows objects to be used in operations involving built-in types in which the built-in type is on the left side of the operator. 
	To do this we have to make the overloaded operator functions friends and define both possible situations. We can define one overloaded friend function so that the left operand is an object and the right operand is the other type. Then we could overload the operator again with the left operand being the built-in type and the right operand being the object. The following program illustrates this method:




class coord { 
	public: 	
/* all elements similar to Example 1 */ 
friend coord operator+(coord ob1, int i);
friend coord operator+(int i, coord ob1);
};  	/*  Overload + for ob + int   */
coord operator+(coord ob1, int i)
    {	coord temp ;
	temp.x = ob1.x + i;
	temp.y = ob1.y + i;
	return temp ;	}	/*  Overload + for int + ob  */
coord operator+( int i, coord ob1)
    {	coord temp ;
	temp.x = ob1.x + i;
	temp.y = ob1.y + i;
	return temp ;	}
int main() { coord o1(10, 10); int x, y;
  o1=o1+10;  	o1.get_xy(x, y); 	cout<< "(o1 +10) X:"<< x <<", Y:"<< y <<"\n"; /* object + integer */ 
  o1=99+o1;  	o1.get_xy(x, y); 	cout<< "(99+ o1) X:"<< x <<", Y:"<< y <<"\n"; /* integer + object  */
return 0; }



2. Overloading an operator by using a friend provides one very important feature that member functions do not. Using a friend operator function, you can allow objects to be used
in operations involving built-in types in which the built-in type is on the left side of the
operator. As you saw earlier in this chapter, it is possible to overload a binary member
operator function such that the left operand is an object and the right operand is a built-in
type. But it is not possible to use a member function to allow the built-in type to occur
on the left side of the operator. For example, assuming an overload member operator
function, the first statement shown here is legal; the second is not:
ob1 = ob2 + 10; // legal
ob1 = 10 + ob2 ; // illegal
While it is possible to organize such statements like the first, always having to make sure
that the object is on the left side of the operand and the built-in type on the right can be
cumbersome restriction. The solution to this problem is to make the overloaded operator
functions friends and define both possible situations.
As you know, a friend operator function is explicitly passed both operands. Thus, it is
possible to define one overloaded friend function so that the left operand is an object and
the right operand is the other type. Then you could overload the operator again with the
left operand being the built-in type and the right operand being the object. The following
program illustrates this method:
// Use friend operator functions to add flexibility .
# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; };
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
friend coord operator +( coord ob1 , int i);
friend coord operator +( int i, coord ob1 );
};
// Overload + for ob + int
coord operator +( coord ob1 , int i)
{
coord temp ;
temp .x = ob1 .x + i;
temp .y = ob1 .y + i;
return temp ;
}
// Overload + for int + ob
coord operator +( int i, coord ob1)
{
coord temp ;
161TEACH YOURSELF
C++
temp .x = ob1 .x + i;
temp .y = ob1 .y + i;
return temp ;
}
int main ()
{
coord o1 (10 , 10) ;
int x, y;
o1 = o1 + 10; // object + integer
o1. get_xy (x, y);
cout << "(o1 +10) X: " << x << ", Y: " << y << "\n";
o1 = 99 + o1; // integer + object
o1. get_xy (x, y);
cout << " (99+ o1) X: " << x << ", Y: " << y << "\n";
return 0;
}
As a result of overloading friend operator functions for both situations, both of these
statements are now valid:
o1 = o1 + 10;
o1 = 99 + o1;
3.










	Example 3 (unary friend operator with prefix, postfix and reference parameter ):  to overload either the ++ or -- unary operator, you must pass the operand to the function as a reference parameter (otherwise any modification inside the friend will not affect the object that generates the call). This is because friend functions do not have "this" pointers.
	If you pass the operand to the friend as a reference parameter, changes that occur inside the friend function affect the object that generates the call ("this"  connects the friend and object through reference). For example, here is a program that overloads the ++ operator by using a friend function:
class coord { 
	public: 	
/* all elements similar to Example 1 */ 
friend coord operator++(coord &ob1);
};  	/*  Using reference   */
coord operator++( coord &ob1) { ob.x++;
ob.y++;
return ob;    // return generates the call 
}  	int main() {
coord o1(10, 10); int x, y;
++o1;   /* o1 is passed by reference */ 
o1.get_xy(x, y);
cout<<"(++ o1) X:"<< x 
cout<<", Y:"<< y << "\n";
return 0; }
	To distinguish between the prefix and the postfix forms of the increment or decrement operators when using a friend operator function: simply add an integer parameter when defining the postfix version (similar to member operator). For example, consider the previous coord class, the prototypes for both will be:
coord operator++( coord &ob); 			// prefix
coord operator++( coord &ob, int notused ); 	// postfix
	If the ++ precedes its operand, the operator++(coord &ob) function is called. 
	If the ++ follows its operand, the operator++(coord &ob, int notused) function is used. In this case, notused will be passed the value 0.



*/  
