
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




/* Example 2 (No-order for objects using FRIEND): 
                All else being equal, there is no reason to use a "friend" function instead of a "member" operator function, 
                except for one "Important Exception" discussed in the following program. 

                Overloading an operator using a "FRIEND" function provides a key advantage over "member" functions.
                Friend operator functions allow operations where a built-in type can appear on the "left side" of the operator, 
                which is not possible with member functions.
                
                For example:
                            ob1 = ob2 + 10;     // Legal  
                            ob1 = 10 + ob2;     // Illegal with member functions  

                    With "member" functions, the object must "always be on the left side"

                To solve this, you can make operator functions "friends" and define "two versions":
                    One where the LEFT operand is an "object" and the RIGHT operand is a "built-in type".
                    Another where the LEFT operand is a "built-in typ"e and the RIGHT operand is an "object".
                
                Since a friend operator function is explicitly passed both operands
                    This approach removes the "order restrictions" and allows flexibility in mixed-type operations.
                    
                    The following program demonstrates this method:


                As a result of overloading friend operator functions for both situations, 
                    both of these statements are now valid:

                        o1 = o1 + 10;
                        o1 = 99 + o1;
*/

// friend operator functions has flexibility : No-order for objects

#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // above is similar to Example 1
        
        // operator overlading using a friend, two versions makes sure No-order for objects
        friend coord operator+(coord ob1, int i);   // ob + int
        friend coord operator+(int i, coord ob1);   // int + ob
};


// Overload '+' for ob + int
coord operator+(coord ob1 , int i){
    coord temp;
    temp.x = ob1.x + i;
    temp.y = ob1.y + i;
    return temp;
}


// Overload '+' for int + ob
coord operator+(int i, coord ob1){
    coord temp;
    temp.x = ob1.x + i;
    temp.y = ob1.y + i;
    return temp;
}


int main(){
    coord o1(10,10);
    int x, y;

    o1 = o1 + 10; // object + integer
    o1.get_xy(x, y);
    std::cout << "(o1 +10) X: " << x << ", Y: " << y << "\n";

    o1 = 99 + o1; // integer + object
    o1.get_xy(x, y);
    std::cout << "(99+ o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}






// ----  rev[14-Jan-2025]  ----




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


3. If you want to use a friend operator function to overload either the ++ or { unary
operator, you must pass the operand to the function as a reference parameter. This is
because friend functions do not have this pointers. Remember that the increment and
decrement operators imply that the operand will be modified. However, if you overload
these operators by using a friend that uses a value parameter, any modifications that
occur to the parameter inside the friend operator function will not affect the object that
generated the call. And since no pointer to the object is passed implicitly (that is, there
is no this pointer) when a friend function is used, there is no way for the increment or
decrement to affect the operand.
However, if you pass the operand to the friend as a reference parameter, changes that
occur inside the friend function affect the object that generates the call. For example,
here is a program that overloads the ++ operator by using a friend function:
// Overload the ++ using a friend .
# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; };
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
friend coord operator ++( coord &ob);
162INTRODUCING OPERATOR OVERLOADING
6.6. A CLOSER LOOK AT THE ASSIGNMENT OPERATOR
};
// Overload ++ using a friend .
coord operator ++( coord &ob) // use reference parameter
{
ob.x ++;
ob.y ++;
return ob;
}
int main ()
{
coord o1 (10 , 10) ;
int x, y;
++ o1; // o1 is passed by reference
o1. get_xy (x, y);
cout << " (++ o1) X: " << x << ", Y: " << y << "\n";
return 0;
}
If you are using a modern compiler, you can also distinguish between the prefix and
the postfix forms of the increment or decrement operators when using a friend operator
function in much the same way you did when using member functions. You simply add an
integer parameter when defining the postfix version. For example, here are the prototypes
for both the prefix and postfix versions of the increment operator relative to the coord
class:
coord operator ++( coord &ob); // prefix
coord operator ++( coord &ob , int notused ); // postfix
If the ++ precedes its operand, the operator++(coord &ob) function is called. However, if the ++ follows its operand, the operator++(coord &ob, int notused) function is used. In this case, notused will be passed the value 0.
