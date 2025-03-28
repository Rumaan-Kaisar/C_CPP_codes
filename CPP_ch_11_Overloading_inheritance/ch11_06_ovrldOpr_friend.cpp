
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




/* Example 5: Overload the coord class so it can use "coord objects" in operations in which 
                an integer value can be multiplied by each coordinate. 

                Allow the operations to use either order: 
                        ob * int    or    int * ob. 
*/

// Overload the '*' for ob*int and int*ob.
#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // above is similar to Example 1

        // Overload the * operator using a friend
        friend coord operator*(coord ob1, int i);
        friend coord operator*(int i, coord ob2);
};


// Overload * one way
coord operator*(coord ob1, int i){
    coord temp;
    temp.x = ob1.x*i;
    temp.y = ob1.y*i;
    return temp;
}


// Overload * another way
coord operator*(int i, coord ob2){
    coord temp;
    temp.x = ob2.x*i;
    temp.y = ob2.y*i;
    return temp;
}


int main(){
    coord o1(10,10), o2;
    int x, y;

    o2 = o1*2; // ob * int
    o2. get_xy (x, y);
    std::cout << "(o1*2) X: " << x << ", Y: " << y << "\n";

    o2 = 3*o1;
    o2. get_xy (x, y);
    std::cout << "(3*o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/* Example 6: Explain why the solution to Example 5 requires the use of friend operator functions. 

                ans:
                    By using "friend functions", you make it possible 
                        to have a "built-in type" as the "left operand".
                    
                    When "member functions" are used, the left operand must be an object 
                        of the class for which the operator is defined.
*/




/* Example 7: Using a FRIEND, show how to overload the "--" relative to the coord class. 
                Define both the prefix and postfix forms 
*/

// Overload the -- relative to coord class using a friend .
#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // above is similar to Example 1

        // Overload the "--" operator using a friend
        friend coord operator--(coord &ob);   // prefix
        friend coord operator--(coord &ob, int notused);     // postfix
};


// Overload -- (prefix) for coord class using a friend
coord operator--(coord &ob){
    ob.x--;
    ob.y--;
    return ob;
}


// Overload -- (postfix) for coord class using a friend
coord operator--(coord &ob, int notused){
    ob.x--;
    ob.y--;
    return ob;
}
// notice in both cases we don't need to use "this", as we did for member function


int main(){
    coord o1(10,10);
    int x, y;

    --o1;   // decrement an object
    o1.get_xy(x, y);
    std::cout << "(--o1) X: " << x << ", Y: " << y << "\n";

    o1--;
    o1.get_xy(x, y);
    std::cout << "(o1--) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/* Example 8: Given the class

                        class three_d {
                                int x, y, z;
                            public:
                                three_d(int i, int j, int k){ x = i; y = j; z = k; }
                                three_d(){ x =0; y =0; z=0; }
                                void get(int &i, int &j, int &k){ i = x; j = y; k = z; }
                        };

                overload the +, -, ++, and -- operators for this class. 
                (For the increment and decrement operators, overload only the prefix form.)
*/

#include <iostream>

class three_d{
        int x, y, z;
    public:
        three_d(int i, int j, int k){ x = i; y = j; z = k; }
        three_d(){ x =0; y =0; z=0; }
        void get ( int &i, int &j, int &k){ i = x; j = y; k = z; }

        // overload the +, -, ++, and -- operators
        three_d operator+( three_d ob2 );
        three_d operator-( three_d ob2 );
        three_d operator++();
        three_d operator--();
};


// overload +
three_d three_d::operator+( three_d ob2 ){
    three_d temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    temp.z = z + ob2.z;
    return temp;
}


// overload -
three_d three_d::operator-( three_d ob2 ){
    three_d temp;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    temp.z = z - ob2.z;
    return temp ;
}


// overload ++
three_d three_d::operator++(){
    x++;
    y++;
    z++;
    return *this;
}

// overload --
three_d three_d::operator--(){
    x--;
    y--;
    z--;
    return *this;
}


int main(){
    three_d o1(10,10,10), o2(2,3,4), o3;
    int x, y, z;

    o3 = o1 + o2;
    o3.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    o3 = o1 - o2;
    o3.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    ++o1;
    o1. get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    --o1;
    o1. get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    return 0;
}
/* 
    notice the use of *this:
        *this represents the "current object itself". 

        only 'this' represents the "pointer to current object itself"
            in this case You would need to adjust the return type to be a pointer (three_d*). 
            to return the current object itself (not a pointer to current object) we're using *this
*/




/* Example 9: Rewrite previous program so that it uses "reference parameters" 
                instead of value parameters to the operator functions. 
                (Hint: You will need to use friend functions for the increment and decrement operators.) 

                Purpose of Using friend for Overloading ++ and --

                    friend is Needed Because ++ and -- Are Unary Operators
                        ++ and -- operate on a single operand (the object itself).

                    When these overloaded as member functions, they implicitly receive the calling object as "this".
                        that's why we need to use "return *this"
                        
                    Friend Functions Allow Operator Overloading Without Using "this"
                        Since ++ and -- modify private members (x, y, z), a "non-member function" don't have acess to these
                        "friend" allows them direct access to the private data of the class.


            Notice:
                If operator++() were a member function
                    This function modifies the calling object (this->x, this->y, this->z).
                    It is called as ob1++ or ++ob1, where ob1 is the calling object.

                            three_d three_d::operator++() {
                                x++;
                                y++;
                                z++;
                                return *this;
                            }

                Using operator++() as a friend function:
                    Here, ob is explicitly passed as an argument (instead of using this).
                    The function modifies ob directly because it has friend access to x, y, z.

                            three_d operator++(three_d &ob) {
                                ob.x++;
                                ob.y++;
                                ob.z++;
                                return ob;
                            }
*/

#include <iostream>

class three_d{
        int x, y, z;
    public:
        three_d(int i, int j, int k){ x = i; y = j; z = k; }
        three_d(){ x =0; y =0; z=0; }
        void get(int &i, int &j, int &k){ i = x; j = y; k = z; }

        // overload the +, -, ++, and -- operators
        three_d operator+( three_d &ob2 );
        three_d operator-( three_d &ob2 );
        // notice the use of friend for overloading ++ and --
        friend three_d operator++( three_d &ob );
        friend three_d operator--( three_d &ob );
};
 


three_d three_d::operator+(three_d &ob2){
    three_d temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    temp.z = z + ob2.z;
    return temp;
}

three_d three_d::operator-(three_d &ob2){
    three_d temp;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;
    temp.z = z - ob2.z;
    return temp;
}

// notice: no use of "return *this;"
three_d operator++(three_d &ob){
    ob.x ++;
    ob.y ++;
    ob.z ++;
    return ob;
}

three_d operator--(three_d &ob){
    ob.x --;
    ob.y --;
    ob.z --;
    return ob;
}


int main(){
    three_d o1(10,10,10), o2(2,3,4), o3;
    int x, y, z;

    o3 = o1 + o2;
    o3.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    o3 = o1 - o2;
    o3.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    ++o1;
    o1.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    --o1;
    o1.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y;
    std::cout << ", Z: " << z << "\n";

    return 0;
}




/* Example 10: How do friend operator functions differ from member operator functions? 

                Binary:
                    A "binary member operator function" is passed the "left operand "implicitly via this pointer.
                    A "binary friend operator function" is passed "both operands" explicitly. 

                Unary:
                    An "Unary member operator functions" have no explicit parameters. 
                    A "friend unary operator function" has one parameter.
*/




/* Example 11: Can operator=() be a friend function? 
                ans: No.
*/




/* Example 12: Overload the '+' for the "three_d class" in 'Example 8' so that it accepts the following types of operations:
                    ob + int;
                    int + ob;

                three_d class:
                    class three_d {
                            int x, y, z;
                        public:
                            three_d(int i, int j, int k){ x = i; y = j; z = k; }
                            three_d(){ x =0; y =0; z=0; }
                            void get(int &i, int &j, int &k){ i = x; j = y; k = z; }
                    };
*/

#include <iostream>

class three_d{
        int x, y, z;
    public:
        three_d(int i, int j, int k){ x=i; y=j; z=k; }
        three_d(){ x=0; y=0; z=0; }
        void get(int &i, int &j, int &k){ i=x; j=y; k=z; }

        // overload the + using friend (No-order for objects)
        friend three_d operator+(three_d ob, int i);
        friend three_d operator+(int i, three_d ob);
};

three_d operator+(three_d ob, int i){
    three_d temp;
    temp.x = ob.x + i;
    temp.y = ob.y + i;
    temp.z = ob.z + i;
    return temp;
}

three_d operator+(int i, three_d ob){
    three_d temp;
    temp.x = ob.x + i;
    temp.y = ob.y + i;
    temp.z = ob.z + i;
    return temp;
}


int main(){
    three_d o1(10,10,10) ;
    int x, y, z;

    o1 = o1 + 10;
    o1.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y << ", Z: " << z << "\n";

    o1 = -20 + o1;
    o1.get(x, y, z);
    std::cout << "X: " << x << ", Y: " << y << ", Z: " << z << "\n";

    return 0;
}




/* Example 13: Overload the ==, !=, and || operators relative to the "three_d class" from Example 8. 


                Previously used:
                                int three_d::operator==(three_d ob2){
                                    return (x == ob2.x) && (y == ob2.y) && (z == ob2.z);
                                }

                                int three_d::operator!=(three_d ob2){
                                    return (x != ob2.x) && (y !=  ob2.y) && (z != ob2.z);
                                }

                                int three_d::operator||(three_d ob2){
                                    return (x || ob2.x) && (y || ob2.y) && (z || ob2.z);
                                }


            issues:
                The code isn’t entirely correct. Here are the issues:

                operator == is Correct:
                    It correctly returns true (nonzero) when all three coordinates are equal.

                operator != is Incorrect:
                    It uses logical AND (&&) to check if each coordinate is different, which means it will only return true if all coordinates differ.
                    The correct behavior is to return true if any coordinate is different (or simply the logical negation of operator==).
                    Fix it by using !(*this == ob2) to logically invert ==

                operator || is Non-Standard:
                    Its implementation returns true only if both objects have all coordinates nonzero (using && on each pair).
                    Usually, a logical OR would be expected to return true if at least one operand is "true" (nonzero) in any meaningful way.

*/
// corrected
#include <iostream>

class three_d{
        int x, y, z;
    public:
        three_d(int i, int j, int k){ x = i; y = j; z = k; }
        three_d(){ x =0; y =0; z=0; }
        void get(int &i, int &j, int &k){ i = x; j = y; k = z; }

        // Overload the ==, !=, and || operators
        int operator==(three_d ob2);
        int operator!=(three_d ob2);
        int operator||(three_d ob2);
};


int three_d::operator==(three_d ob2){
    return (x == ob2.x) && (y == ob2.y) && (z == ob2.z);
}

int three_d::operator!=(three_d ob2){
    return (x != ob2.x) || (y !=  ob2.y) || (z != ob2.z);
}

int three_d::operator||(three_d ob2){
    return (x || ob2.x) || (y || ob2.y) || (z || ob2.z);
}

int main(){
    three_d o1(10,10,10) , o2(2,3,4), o3(0,0,0);

    if(o1 == o1) std::cout << "o1 == o1\n";

    if(o1 != o2) std::cout << "o1 != o2\n";

    if(o3 || o1) std::cout << "o1 or o3 is true \n";

    return 0;
}



// VERSION 2: another version using == inversion and useing 'const' 
// using 'const' avoid making unnecessary copies
#include <iostream>

class three_d {
    int x, y, z;
public:
    three_d(int i, int j, int k) : x(i), y(j), z(k) {}
    three_d() : x(0), y(0), z(0) {}
    void get(int &i, int &j, int &k) const { i = x; j = y; k = z; }

    // Overloaded operators with const correctness and references
    bool operator==(const three_d &ob2) const;
    bool operator!=(const three_d &ob2) const;
    bool operator||(const three_d &ob2) const;
};

// Corrected == operator
bool three_d::operator==(const three_d &ob2) const {
    return (x == ob2.x) && (y == ob2.y) && (z == ob2.z);
}

// Corrected != operator using logical inversion of ==
bool three_d::operator!=(const three_d &ob2) const {
    return !(*this == ob2);
}

// Corrected || operator (now uses logical OR between coordinates)
bool three_d::operator||(const three_d &ob2) const {
    return (x || ob2.x) || (y || ob2.y) || (z || ob2.z);
}

int main() {
    three_d o1(10, 10, 10), o2(2, 3, 4), o3(0, 0, 0);

    if (o1 == o1) std::cout << "o1 == o1\n";          // Works
    if (o1 != o2) std::cout << "o1 != o2\n";          // Works
    if (o3 || o1) std::cout << "o1 or o3 is true\n";  // Now works correctly

    return 0;
}




/* Example 14: Convert the solution from "Example 3" from "ch11_05_3_ovrldOpr_relational_logical.cpp" 
                so it overloads the operators by using friend functions. 


                // overload +, -, == for array objects
                #include <iostream>

                class array{
                        int nums[10];
                    public:
                        array();
                        void set(int n[10]);
                        void show();
                        
                        // overload +, -, ==
                        array operator+(array ob2);
                        array operator-(array ob2);
                        int operator==(array ob2);
                };


                array::array(){
                    int i;
                    for(i=0; i<10; i ++) nums[i] = 0;
                }


                void array::set(int *n){
                    int i;
                    for(i=0; i<10; i++) nums[i] = n[i];
                }


                void array::show(){
                    int i;
                    for(i =0; i<10; i++) std::cout << nums[i] << ' ';
                    std::cout << "\n";
                }


                // implement overloading: Fill in operator functions.
                array array::operator+(array ob2){
                    int i;
                    array temp;
                    for(i=0; i<10; i++) temp.nums[i] = nums[i] + ob2.nums[i];
                    return temp;
                }


                array array::operator-(array ob2){
                    int i;
                    array temp;
                    for(i=0; i<10; i++) temp.nums[i] = nums[i] - ob2.nums[i];
                    return temp;
                }


                int array::operator==(array ob2){
                    int i;
                    for(i=0; i<10; i++) if(nums[i] != ob2.nums[i]) return 0;
                    return 1;
                }


                int main(){
                    array o1, o2, o3;
                    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10 };

                    o1.set(i);
                    o2.set(i);

                    o3 = o1 + o2;
                    o3.show();

                    o3 = o1 - o3;
                    o3.show();

                    if(o1 == o2) 
                        std::cout << "o1 equals o2\n";
                    else 
                        std::cout << "o1 does not equal o2\n";

                    if(o1 == o3) 
                        std::cout << "o1 equals o3\n";
                    else
                        std::cout << "o1 does not equal o3\n";

                    return 0;
                }
*/

// overload +, -, == for array objects using friend
#include <iostream>

class array{
        int nums[10];
    public:
        array();
        void set(int n[10]);
        void show();
        
        // overload +, -, == using friend
        friend array operator+(array ob1, array ob2);
        friend array operator-(array ob1, array ob2);
        friend int operator==(array ob1, array ob2);
};


array::array(){
    int i;
    for(i=0; i<10; i++) nums[i] = 0;
}


void array::set(int *n){
    int i;
    for(i=0; i<10; i++) nums[i] = n[i];
}


void array::show(){
    int i;
    for(i =0; i<10; i++) std::cout << nums[i] << ' ';
    std::cout << "\n";
}


// implement overloading: Fill in operator functions. notice no "::array" used
array operator+(array ob1, array ob2){
    int i;
    array temp;
    for(i=0; i<10; i++) temp.nums[i] = ob1.nums[i] + ob2.nums[i];
    return temp;
}


array operator-(array ob1, array ob2){
    int i;
    array temp;
    for(i=0; i<10; i++) temp.nums[i] = ob1.nums[i] - ob2.nums[i];
    return temp;
}


int operator==(array ob1, array ob2){
    int i;
    for(i=0; i<10; i++) if(ob1.nums[i] != ob2.nums[i]) return 0;
    return 1;
}


int main(){
    array o1, o2, o3;
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8 ,9 ,10 };

    o1.set(i);
    o2.set(i);

    o3 = o1 + o2;
    o3.show();

    o3 = o1 - o3;
    o3.show();

    if(o1 == o2) 
        std::cout << "o1 equals o2\n";
    else 
        std::cout << "o1 does not equal o2\n";

    if(o1 == o3) 
        std::cout << "o1 equals o3\n";
    else
        std::cout << "o1 does not equal o3\n";

    return 0;
}




/* Example 15: Using the class and support functions from Exercise 14 (previous program), 
                overload the ++ operator by using a member function and
                overload the -- operator by using a friend. 
                (Overload only the prefix forms of ++ and --) 
*/

// overload +, -, == for array objects using friend
#include <iostream>

class array{
        int nums[10];
    public:
        array();
        void set(int n[10]);
        void show();
        
        // overload ++ as member, overload -- as friend
        array operator++();
        friend array operator--(array &ob);
};


array::array(){
    int i;
    for(i=0; i<10; i++) nums[i] = 0;
}


void array::set(int *n){
    int i;
    for(i=0; i<10; i++) nums[i] = n[i];
}


void array::show(){
    int i;
    for(i =0; i<10; i++) std::cout << nums[i] << ' ';
    std::cout << "\n";
}


// implement overloading:
// Overload "unary op" using member function
array array::operator++(){
    int i;
    for(i =0; i<10; i++) nums[i]++;
    return *this;
}

// Overload "unary op" using member function. (no need *this)
array operator--(array &ob){
    int i;
    for (i=0; i<10; i++)
    ob.nums[i]--;
    return ob;
}


int main(){
    array o1, o2, o3;
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    o1.set(i);
    o2.set(i);
    o3 = ++o1;
    o3.show();
    o3 = --o1;

    o3.show();

    return 0;
}


