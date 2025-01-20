
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
    std::cout << "(o1 + 10) X: " << x << ", Y: " << y << "\n";

    o1 = 99 + o1; // integer + object
    o1.get_xy(x, y);
    std::cout << "(99 + o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/* Example 3 (unary friend operator with prefix, postfix and reference parameter ):  
                To overload either the ++ or -- unary operator, 
                    you must pass the "operand" to the function "as a reference parameter" 
                (otherwise any modification inside the friend will not affect the object that generates the call). 
                This is because friend functions do not have "this" pointers.

                Without a reference parameter, the function will work on a copy of the object, 
                    and any changes made will not affect the original object

                If you pass the operand to the friend as a reference parameter, 
                    changes that occur inside the friend function affect the object that generates the call 
    
            How Reference Works:
                A reference acts as a link between the friend function and the object, 
                    effectively replicating the behavior of "this".
                This ensures that the friend function can modify the object directly, just like a member function can.

            Folloing program that overloads the ++ operator by using a friend function.
*/

#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // above is similar to Example 1

        // Overload the ++ using a friend
        friend coord operator++(coord &ob);     //  notice the referance
};


// Overload ++ using a friend
coord operator++(coord &ob){    // use reference parameter
    ob.x++;
    ob.y++;
    return ob;
}


int main(){
    coord o1(10,10);
    int x, y;

    ++o1;   // o1 is passed by reference
    o1.get_xy(x, y);
    std::cout << " (++o1) X: " << x << ", Y: " << y << "\n";
    
    return 0;
}


/* To distinguish between the prefix and the postfix forms of 
    the increment or decrement operators when using a friend operator function: 

        Simply "add an integer parameter" when defining the "postfix" version (similar to member operator)
        For example, consider the previous coord class, the prototypes for both will be:

            coord operator++( coord &ob );           // prefix
            coord operator++( coord &ob, int notused );      // postfix

        If the ++ precedes its operand, the operator++(coord &ob) function is called. 
        If the ++ follows its operand, the operator++(coord &ob, int notused) function is used. 
            In this case, notused will be passed the value 0.
*/




/* Example 4: Overload the - and / operators for the coord class using friend functions. */

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // above is similar to Example 1

        // Overload the - and / operators using a friend
        friend coord operator-(coord ob1, coord ob2);
        friend coord operator/(coord ob1, coord ob2);
};


// Overload - relative to coord class using friend .
coord operator-(coord ob1, coord ob2){
    coord temp;
    temp.x = ob1.x - ob2.x;
    temp.y = ob1.y - ob2.y;
    return temp;
}


// Overload / relative to coord class using friend .
coord operator/(coord ob1, coord ob2){
    coord temp;
    temp.x = ob1.x / ob2.x;
    temp.y = ob1.y / ob2.y;
    return temp;
}


int main(){
    coord o1(10,10), o2(5,3), o3;
    int x, y;

    o3 = o1 - o2;
    o3.get_xy(x, y);
    std::cout << "(o1-o2) X: " << x << ", Y: " << y << "\n";

    o3 = o1 / o2;
    o3.get_xy(x, y);
    std::cout << "(o1/o2) X: " << x << ", Y: " << y << "\n";

    return 0;
}




// ----  rev[18-Jan-2025]  ----

/* Example 5: Overload the coord class so it can use coord objects in operations in which an integer
value can be multiplied by each coordinate. Allow the operations to use either order: ob
* int or int * ob. */

// Overload the * for ob*int and int *ob.
# include <iostream >
using namespace std ;
class coord
{
480ANSWERS
6.5 EXERCISES
int x, y; // coordinate values
public :
coord () { x =0; y =0; }
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
friend coord operator *( coord ob1 , int i);
friend coord operator *( int i, coord ob2 );
};
// Overload * one way .
coord operator *( coord ob1 , int i)
{
coord temp ;
temp .x = ob1 .x * i;
temp .y = ob1 .y * i;
return temp ;
}
// Overload * another way .
coord operator *( int i, coord ob2)
{
coord temp ;
temp .x = ob2 .x * i;
temp .y = ob2 .y * i;
return temp ;
}
int main ()
{
coord o1 (10 , 10) , o2;
int x, y;
o2 = o1 * 2; // ob * int
o2. get_xy (x, y);
cout << "(o1 *2) X: " << x << ", Y: " << y << "\n";
o2 = 3 * o1;
o2. get_xy (x, y);
cout << " (3* o1) X: " << x << ", Y: " << y << "\n";
return 0;
}




/* Example 6: Explain why the solution to Example 5 requires the use of friend operator functions. */

By using friend functions, you make it possible to have a built-in type as the left operand.
When member functions are used, the left operand must be an object of the class for
which the operator is defined.




/* Example 7: Using a friend, show how to overload the { relative to the coord class. Define both the
prefix and postfix forms */

// Overload the -- relative to coord class using a friend .

# include <iostream >
using namespace std ;
class coord
{
int x, y; // coordinate values
public :
coord () { x =0; y =0; }
coord ( int i, int j) { x=i; y=j; }
void get_xy ( int &i, int &j) { i=x; j=y; }
friend coord operator --( coord &ob); // prefix
friend coord operator --( coord &ob , int notused ); //
postfix
};
// Overload -- ( prefix ) for coord class using a friend .
coord operator --( coord &ob)
{
ob.x --;
ob.y --;
return ob;
}
// Overload -- ( postfix ) for coord class using a friend .
coord operator --( coord &ob , int notused )
{
ob.x --;
ob.y --;
return ob;
}
int main ()
{
coord o1 (10 , 10) ;
int x, y;
--o1; // decrement an object
o1. get_xy (x, y);
cout << "(--o1) X: " << x << ", Y: " << y << "\n";
o1 --;
o1. get_xy (x, y);
cout << "(o1 --) X: " << x << ", Y: " << y << "\n";
return 0;
}


