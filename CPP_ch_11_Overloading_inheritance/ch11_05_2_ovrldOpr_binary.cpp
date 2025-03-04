
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


/*  ------------    restrictions    ------------

    The order of operands matters when using built-in types (e.g., int) as the "right operand" in operator overloading.
        This is because the "object on the left" generates the call to the operator function.
        For example:
                        o3 = 19 + ob1;   // int + object

            This causes a "compile-time error" since there is no built-in operation to handle adding an integer to an object.
            The overloaded operator function, such as operator+(int i), "only works" when the object is on the "left":

                        o3 = ob1 + 19;   // object + int

            This works as intended.

        To handle operations where the built-in type is on the left (e.g., int + object), a different approach must be used.
            There is a solution around this restriction
*/




/* Example 4 (reference parameter in operator funtion):  
                We can use a "reference parameter" in an operator function.

                Overload the + operator relative to the coord class using "reference". 
                This class is used to maintain X, Y coordinates  similar to previous example. 
*/

// Overload + relative to coord class using "references"
coord coord::operator+(coord &ob2){
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}


/*  Efficiency of Using Reference Parameters in Operator Overloading:

    Improved Performance:
        Passing the address of an object (using a reference) is faster and more efficient 
            than passing the object itself, as it avoids creating copies.
        This is especially important if the operator is used frequently, as it reduces CPU overhead.


    Preventing Temporary Object Destruction:
        (Recall ch10_06_2_pass_obj_to_func.cpp, ch10_06_3_return_obj_from_func.cpp passing/returning object to/form function)
        When an argument is passed by value, a copy of the object is created.
        If the object has a destructor, the destructor for the copy is called when the function ends, 
            potentially destroying something needed by the original object.
        Using a reference parameter avoids this problem by directly working with the original object instead of a copy.

        Alternative Solution:
            Defining a proper copy constructor can also handle the issue of object destruction, 
                but using references is a simpler and more efficient approach.


    In binary operator overloading-
        The left operand is passed implicitly to the operator function using the this pointer.
        The right operand is passed as an explicit argument.
*/




/* Example 5: Relative to coord, overload the * and / operators. Demonstrate that they work. 

                On your own, experiment by changing the "return types" of the operator functions to something other than coord. 
                See what types of errors result
*/

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; }
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // Overload the * and / relative to coord class
        coord operator *(coord ob2);
        coord operator /(coord ob2);
};

// Overload * relative to coord class .
coord coord::operator *( coord ob2){
    coord temp;
    temp.x = x*ob2.x;
    temp.y = y*ob2.y;
    return temp;
}

// Overload / relative to coord class .
coord coord::operator/(coord ob2){
    coord temp;
    temp.x = x/ob2.x;
    temp.y = y/ob2.y;
    return temp;
}


int main(){
    coord o1(10,10), o2(5,3), o3;
    int x, y;

    o3 = o1*o2;
    o3.get_xy(x, y);
    std::cout << "(o1*o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1/o2;
    o3.get_xy(x, y);
    std::cout << "(o1/o2) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/* Example 6: Why would the following be an inappropriate use of an overloaded operator? 

                coord coord::operator %( coord ob){
                    double i;
                    std::cout << " Enter a number : ";
                    std::cin >> i;
                    std::cout << " root of " << i << " is ";
                    std::cout << sqrt (i);
                }

                ans:
                    The overloading of the % operator is inappropriate 
                    because its operation is unrelated to the traditional use
*/




/* Example 7: Overload the >> and << shift operator relative to the coord class (ch11_05_1, ch11_05_2, ch11_05_3, ch11_05_4, ch11_06) 
                so that the following types of operations are allowed:

                        ob << integer
                        ob >> integer

                Make sure your operations shift the x and y values by the amount specified. 

                        class coord{
                                int x, y;   // coordinate values
                            public:
                                coord(){ x =0; y =0; };
                                coord(int i, int j){ x=i; y=j; }
                                void get_xy(int &i, int &j){ i=x; j=y; }
                        };
*/

#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // Overload << and >>. Notice in this case no referance is used
        coord operator<<(int i);
        coord operator>>(int i);
};

// Overload <<.
coord coord::operator<<(int i){
    coord temp;
    temp.x = x << i;
    temp.y = y << i;
    return temp ;
}

// Overload >>.
coord coord::operator>>(int i){
    coord temp;
    temp.x = x >> i;
    temp.y = y >> i;
    return temp;
}


int main(){
    coord o1(4,4), o2;
    int x, y;

    o2 = o1 << 2; // ob << int
    o2.get_xy(x,y);
    std::cout << "(o1 << 2) X: " << x << ", Y: " << y << '\n';

    o2 = o1 >> 2; // ob >> int
    o2.get_xy(x, y);
    std::cout << "(o1 >> 2) X: " << x << ", Y: " << y << '\n';

    return 0;
}

