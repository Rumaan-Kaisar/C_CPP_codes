
/*  ------------------------    operator overloading : BINARY    ------------------------

    Overloading binary operators
        When a "member operator function" overloads a BINARY operator, the function will have only "one parameter"
        The parameter will "receive" the object that is on the "right side" of the operator
        The object on the "left side" generates the call to the operator function and is passed implicitly using the "this" pointer.


    Operator functions can be written in various way, some are shown in the examples:
        using return type, temporary object, no-operator modification
        using order of objects, implicit first object, assignment operator
        using built-in-type objects i.e. int-float-char, order of the operands
        using reference parameter in operator funtion
*/




/* Example 1: (return type, temporary object, no-operator modification )
                Following  overload the '+' operator relative to the "coord" class. This class is used to maintain X, Y coordinates.


                Purpose:
                    The + operator is overloaded to allow the "addition of two objects" of the coord class, combining their x and y values.


                Return Type: 
                    The return type of the overloaded operator is the same class type (coord) 
                    since the result of the addition is also a coord object.


                Function Signature: 
                    The function is a member of the coord class with the syntax:

                            coord coord::operator+(coord ob2)

                        Here, ob2 represents the object on the right-hand side of the operator.


                How it Works:
                    The "operator+" function is called when the expression "o1 + o2" is evaluated.
                    
                    The left-hand object (o1) is passed implicitly using the "this" pointer, 
                        and the right-hand object (o2) is passed as a parameter.
                    
                    Inside the function, the x and y values of o1 and o2 are added, 
                        and the result is stored in a temporary coord object, which is then returned.


                Main Function:
                    The overloaded operator is used as "o3 = o1 + o2;"
                    The resulting x and y values of the new coord object (o3) are displayed using get_xy.

*/

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord() { x =0; y =0; }
        coord(int i, int j) { x=i; y=j; }
        void get_xy(int &i, int &j) { i=x; j=y; }
        coord operator+(coord ob2);     // coord type used for overloaded operator
};


// Overload + relative to coord class: return_type class_name :: operator#(arg_list)
// Notice, return_type and class_name are the same here
coord coord::operator+(coord ob2){
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}


int main(){
    coord o1(10, 10), o2(5, 3), o3;
    int x, y;

    o3 = o1 + o2; // add two objects - this calls operator +
    o3.get_xy(x, y);
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    return 0;
}


/*  Output:   (o1+o2) X: 15, Y: 13

    Notice that there is no ob1 in operator function (it is implicit here and used to call ob2), 
        however we'll use both ob1 and ob2 in the friend operator function. 
    
    The reason that the operator+() function returns an object of type "coord" is: 
                o3 = o1 + o2 
        is valid iff the result of o1 + o2 is a "coord" object that can be assigned to o3. 
        If a different type had been returned, this statement would have been invalid. 
    
    Notice that a temporary object called "temp" is used inside operator+() to hold the result, and it is the returned object.
    
    The reason for temp is: 
        A temporary object is needed to hold the result. 
    
    In this situation (as in most), the + has been overloaded in a manner consistent with its normal arithmetic use. 
        Therefore, neither operand be changed. 
        For example, for 10+4=14, the result is 14, but neither the 10 nor the 4 is modified.

    Because a coord object is returned, the statement: 
                (o1+o2).get_xy(x, y);
        is also perfectly valid. 
        Here the temporary object returned by operator+() is used directly 
            and after execution the temporary object is destroyed.

*/




/* Example 2 (order of objects, implicit first object, assignment operator):
                Overload the +, - and "=" operator relative to the coord class. 
                This class is used to maintain X, Y coordinates  similar to previous example. 
*/

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord() { x =0; y =0; }
        coord(int i, int j) { x=i; y=j; }
        void get_xy(int &i, int &j) { i=x; j=y; }

        // OPERATOR OVERLOADING: coord type used for overloaded operator
        coord operator+(coord ob2);
        coord operator-(coord ob2);
        coord operator=(coord ob2);
};


// Overload '+' relative to coord class.
coord coord::operator+(coord ob2) {
    coord temp ;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp ; 
}	

// Overload '-' relative to coord class.
coord coord::operator-(coord ob2) {
    coord temp ;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    return temp ; 
}	

// Overload '=' relative to coord class.
coord coord::operator=(coord ob2) {
    x = ob2.x;
    y = ob2.y;
    return *this ; 
    // return the object that is assigned. Noticem, no "temp" is used
}


int main(){
    coord o1(10,10), o2(5,3), o3;
    int x, y;

    o3 = o1 + o2;   // add two objects - this calls operator +
    o3.get_xy(x,y);
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 - o2;   // subtract two objects
    o3.get_xy(x,y);
    std::cout << "(o1-o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1;        // assign an object
    o3.get_xy(x,y);
    std::cout << "(o3=o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/*  Order of the operands: 
        The operator-() function is implemented similarly to operator+(). 
            However the order of the operands is important while overloading an operator.

        The order of the left-operand which "generates the call to operator-()" and 
            the right-operand which "passed as an argument  to the operator-()" 
            is important for subtraction because  A-B not equal to B-A, 
            It must be in the order:        x - ob2.x;

        The order of the left-operand and right-operand is also important 
            when we use built-in-type variables as right-operand .

        When overloading a binary operator, the left operand is passed implicitly, 
            and the right operand is passed as an argument.

        The order of the left-operand and the right-operand is not important for addition.
            That is, A + B is the same as B + A
            However, the subtraction operation is order dependent.


    The assignment operator function:
        Here the left-operand is modified by the operation (that is, the object being assigned a value).  
            This is in keeping with the normal meaning of assignment. 

        The function returns *this:
            That is, the operator=() function "returns the object" that is being assigned to. 

        The reason for this is to allow a series of assignments to be made. 
            Eg: we used a = b = c = d = 0; 

        For variables, returning "*this" by overloaded assignment operator 
            allows us to use o3 = o2 = o1; for multiple objects.

        An overloaded assignment function isn't required to "return the object that receives the assignment"
        However, if you want the overloaded = to behave relative to its class 
            the way it does for the built-in types, it must return "*this"
*/




/* Example 3 (built-in-type objects i.e. int-float-char, order of the operands ):  
                Overload the + operator relative to the coord class with "built-in-type objects" (i.e int, float, char etc). 
                This class is used to maintain X, Y coordinates  similar to previous example.

                An operator can be overloaded relative to a class so that 
                    the right operand is a built-in type, like an int, 
                    instead of the class type for which the operator function is a member
*/

// Overload the + for "ob + int" as well as "ob + ob"
#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord() { x =0; y =0; }
        coord(int i, int j) { x=i; y=j; }
        void get_xy(int &i, int &j) { i=x; j=y; }

        // OPERATOR OVERLOADING: coord type used for overloaded operator
        coord operator+( coord ob2);    // ob + ob
        coord operator+( int i);        // ob + int
};


// Overload '+' relative to coord class (same as befire)
coord coord::operator+(coord ob2) {
    coord temp ;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp ; 
}	

// Overload + for ob + int (using built-in type)
coord coord::operator+(int i){
    coord temp;
    temp.x = x + i;
    temp.y = y + i;
    return temp;
}


int main(){
    coord o1(10,10), o2(5,3), o3;
    int x, y;

    o3 = o1 + o2;   // add two objects - calls operator +( coord )
    o3.get_xy(x, y);
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 + 100;  // add object + int - calls operator +( int )
    o3.get_xy(x, y);
    std::cout << "(o1 +100) X: " << x << ", Y: " << y << "\n";

    return 0;
}



// --------  rev[19-Dec-2024]  --------

// **** use GPT to explain the overloading in short word
/* 
	The order of the left-operand and right-operand is important when we use built-in-type variables as right-operand . The reason is: It is the object on the left that generates the call to the operator function. 
    For instance,  o3 = 19 + o1; // int + obj  
    generates a compile-time error. Because there is no built-in operation defined to handle the addition of an integer to an object.
	The overloaded operator+(int i) function works only when the object is on the left. (However there is a solution around this restriction.)

 */

/* Example 4 (reference parameter in operator funtion):  Overload the + operator relative to the coord class using reference. This class is used to maintain X, Y coordinates  similar to previous example. */

coord coord :: operator+( coord &ob2) {	coord temp ; 	// using references
temp.x = x + ob2.x;
temp.y = y + ob2.y;
return temp ; }
	Efficiency: Passing the address of an object is always quick and efficient and do not consume CPU cycles as much as normal object parameters do. If the operator is going to be used often, using a reference parameter is a good choice.
	Prevent temporary object/operand destruction after execution (recall 10.10):  when an argument is passed by value, a copy of that argument is made. If that object has a destructor function, when the function terminates, the copy's destructor is called. 
	Using a reference parameter instead of a value parameter is an easy (and efficient) way around the problem. 
	However, we could also define a copy constructor that would prevent this problem in the general case.
Note:
When a binary operator is overloaded, the left operand is passed implicitly to the function and the right operand is passed as an argument.
















For example, here the + operator is overloaded to add an
integer value to a coord object:



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



