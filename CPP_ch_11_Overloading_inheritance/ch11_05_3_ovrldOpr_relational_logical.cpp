
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




/* Example 3: Given the following partially completed program, fill in the "needed operator functions":

                Have the "overloaded +" add each element of each operand. 
                Have the "overloaded -" subtract each element of the "right operand" from the left. 
                Have the "overloaded ==" return 'true' if each element of each operand is the same 
                    and return 'false' otherwise.

                note 1:

                    In following context

                            is array::array(){
                                for(int i=0; i<10; i ++) nums[i] = 0;      
                                // Scope of i exists only inside the loop.
                            }

                    is same as

                            array::array(){ 
                                int i;      
                                // Scope of i exists throughout the constructor but is still local to the function.
                                for(i=0; i<10; i ++) nums[i] = 0;
                            }

                    However, the scope of i is different.
                    The first one is generally preferred for better scoping and readability.


                note 2:
                    In C++, you can change the return type of an overloaded operator to a basic data type instead of a user-defined type. 
                    This allows operators to return either basic or user-defined types based on the requirements.
                    So we can change "array operator==(array ob2);"  to  "int operator==(array ob2);"



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
                        array operator==(array ob2);
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


                // Fill in operator functions.


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

