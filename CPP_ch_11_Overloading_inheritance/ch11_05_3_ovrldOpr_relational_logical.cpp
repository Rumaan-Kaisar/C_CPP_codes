
/*  ------------------------    operator overloading : RELATIONAL and LOGICAL    ------------------------
    
    Relational (<, >, <=, >=, ==, !=) and logical operators (&&, ||, !) can be overloaded.

    Return Type:
        Operator functions should not return an "object" of the class they are defined for.
        Instead, return an integer (int) to indicate true (non-zero) or false (zero).
        This maintains traditional behavior and ensures compatibility with larger expressions.


    Modern C++ Option "bool":
        In modern C++ compilers, these operators can return a "bool" type.
        Although there's no functional advantage since bool automatically 
            converts to int (true → nonzero, false → 0) and vice versa.
*/




/* Example 1: The program overloads the == and && operators to compare two objects, 
                determining if they are the same (true) or different (false).

            
                overload the == and && relative to coord class as below:

                    Both objects corresponding "member elements" are compared, 
                        and the result is returned as true or false

                    Notice that both operator==() and operator&&() are declared to "return an int" functions
                        This is because 'true' and 'false' correspond to the integer values 1 and 0.
*/

#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; };
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // OPERATOR OVERLOADING
        int operator ==( coord ob2);
        int operator &&( coord ob2);
};


// Overload the == operator for coord .
int coord::operator==(coord ob2){
    return ((x == ob2.x) && (y == ob2.y));
}

// Overload the && operator for coord .
int coord::operator&&(coord ob2){
    return ((x && ob2.x) && (y && ob2.y));
}


int main(){
    coord o1(10,10), o2(5,3), o3(10,10), o4(0,0);

    if(o1 == o2) std::cout << "o1 same as o2\n";
    else std::cout << "o1 and o2 differs \n";

    if(o1 == o3) std::cout << "o1 same as o3\n";
    else std::cout << "o1 and o3 differ \n";

    if(o1 && o2) std::cout << "o1 && o2 is true \n";
    else std::cout << "o1 && o2 is false \n";

    if(o1 && o4) std::cout << "o1 && o4 is true \n";
    else std::cout << "o1 && o4 is false \n";

    return 0;
}




/* Example 2: Overload < and > operator relative to the coord class. 
                Notice the return types of overloaded operators 
*/
#include <iostream>

class coord{
        int x, y;   // coordinate values
    public:
        coord(){ x =0; y =0; }
        coord(int i, int j){ x=i; y=j; }
        void get_xy(int &i, int &j){ i=x; j=y; }

        // operator overload
        int operator <( coord ob2);
        int operator >( coord ob2);
};


// Overload < relative to coord class
int coord::operator<(coord ob2){
    return (x < ob2.x) && (y < ob2.y);
}


// Overload > relative to coord class .
int coord :: operator >( coord ob2){
    return (x > ob2.x) && (y > ob2.y);
}


int main(){
    coord o1(10,10), o2(5,3);
    int x, y;

    if(o1 > o2) std::cout << "o1 > o2\n";
    else std::cout << "o1 <= o2\n";

    if(o1 < o2) std::cout << "o1 < o2\n";
    else std::cout << "o1 >= o2\n";

    return 0;
}



