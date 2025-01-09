
/*  ------------------------    operator overloading : unary    ------------------------
    Overloading A UNARY Operator
        Overloading is similar to binary operator except theres only one operand

        Overloading a "unary" operator as a member function requires "no parameters"
        The single operand triggers the call to the operator function
*/




/* Example 1: The following program overloads the increment operator (++) relative to the coord class 
                The overloaded ++ operator increases the object by 1.
                It modifies the object it operates on and returns the incremented object.
                This allows usage in larger statements like o2 = ++o1;.

                While it's not mandatory to overload a unary operator to match its usual behavior, 
                    it is generally recommended.
*/

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }
        // overloading ++
        coord operator++();
};


// Overload ++ for coord, notice the use of "this", and '*'
coord coord::operator++(){
    x++;
    y++;
    return *this;
}

int main(){
    coord o1(10,10);
    int x, y;

    ++o1; // increment an object
    o1.get_xy(x, y);
    std::cout << " (++ o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/*  ------------    Prefix and Postfix    ------------
    In early versions of C++, there was no way to differentiate whether the 
        "overloaded" ++ or -- came before (prefix) or after (postfix) the operand
        For example, o1++ and ++o1 were treated the same


    Modern C++ allows distinguishing between prefix and postfix operators 
        by using different function signatures.
        To accomplish this, create two versions of the operator++() function

        The first is defined as shown in the preceding example. As:

                coord coord::operator++();


        The second is declared like this:

                coord coord :: operator++(int notused);

        If the ++ "operator" precedes its operand, the operator++() function is called.
        if the ++ "follows" its operand, the operator++(int notused) function is used. 
            In this case, "notused" will always be passed the value 0



    ----  mechanisms  ----
    Prefix (++o1) modifies the operand and returns the object "directly".

            ++o1; // Increments the value of o1 and returns the updated o1

        it is more efficient since this approach does not require creating a temporary object


    "Postfix" typically creates a "temporary object", increments the operand, 
        and returns the temporary object to preserve the original value before the increment.

            o1++; // Returns the original value of o1 (via the temporary object) and then increments o1
*/




/* Example 2 (Use '–' as "unary" and "binary" both in a program): 
                The minus sign (-) serves as both a binary and unary operator in C++.
                
                To retain both uses for a custom class, overload it twice:
                    once as a binary operator and 
                    once as a unary operator.

                The process is straightforward and can be implemented easily.
*/

// Overload the - relative to coord class .
#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // operator overloading
        coord operator-(coord ob2);     // binary minus
        coord operator-();      // unary minus
};


// Overload binary '-' relative to coord class
coord coord::operator-(coord ob2){
    coord temp;
    temp.x = x - ob2.x;
    temp.y = y - ob2.y;

    return temp;
}


// Overload unary '-' relative to coord class
// notice the use of 'this' since the operator is now unary
coord coord::operator-(){
    x = -x;
    y = -y;
    return *this ;
}


int main(){
    coord o1(10,10), o2(5,7);
    int x, y;

    o1 = o1 - o2;   // subtraction. Binary operation
    o1.get_xy(x, y);
    std::cout << "(o1 -o2) X: " << x << ", Y: " << y << "\n";

    o1 = -o1;       // negation. Unary operation
    o1.get_xy(x, y);
    std::cout << "(-o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}



/* Notice:
        when '-' is overloaded as a BINARY operator, it takes "one" parameter.
        When '-' is overloaded as a UNARY operator, it takes no parameter.

        This difference in parameters allows the minus '-' to be "overloaded" for both operations
            For a binary minus, "operator-(coord ob2)" is called.
            For a unary minus, "operator-()" is called.
*/




/* Example 3: Overload the '--' operator for the coord class. 
                Create both its prefix and postfix forms
*/

#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; }
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // operator overloading
        coord operator--();     // prefix
        coord operator--( int notused );    // postfix
};


// Overload PREFIX -- for coord class
// notice the use of "this"
coord coord::operator--(){
    x --;
    y --;
    return *this;
}


// Overload POSTFIX -- for coord class
// notice the use of "this"
coord coord::operator--(int notused){
    x --;
    y --;
    return *this;
}


int main(){
    coord o1(10,10);
    int x, y;

    o1--; // decrement an object
    o1.get_xy(x, y);
    std::cout << "(o1--) X: " << x << ", Y: " << y << "\n";

    --o1; // decrement an object
    o1.get_xy (x, y);
    std::cout << "(--o1) X: " << x << ", Y: " << y << "\n";

    return 0;
}




/* Example 4: (making + an UNARY) Overload the + operator for the coord class 
                so that it is both a BINARY operator (as shown earlier) and a UNARY operator

            UNARY (absolute value):
                When it is used as a unary operator, have the + make any negative coordinate value positive 
*/

#include <iostream>

class coord{
        int x, y; // coordinate values
    public:
        coord(){ x =0; y =0; }
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // operator overloading
        coord operator+(coord ob2);     // binary plus
        coord operator+();      // unary plus
};


// Overload + relative to coord class .
coord coord::operator+(coord ob2){
    coord temp;
    temp.x = x + ob2.x;
    temp.y = y + ob2.y;
    return temp;
}


// Overload unary + for coord class, notice "this"
coord coord::operator+(){
        if(x < 0) x = -x;
        if(y < 0) y = -y;
        return *this;
}


int main(){
    coord o1(10,10), o2(-2,-2);
    int x, y;

    o1 = o1 + o2;   // addition
    o1.get_xy(x, y);
    std::cout << "(o1+o2) X: " << x << ", Y: " << y << "\n";

    o2 = +o2;   // absolute value
    o2.get_xy(x, y);
    std::cout << "(+o2) X: " << x << ", Y: " << y << "\n";

    return 0;
}


