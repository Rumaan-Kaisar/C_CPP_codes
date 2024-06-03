
/*  ------------    "this" pointer    ------------

    this:
        It is a special pointer that is AUTOMATICALLY PASSED to any "member function" when it is called, 
        It is a "pointer to the object" that generates the call (this works implicitly).

        For example, given this statement,
        ob.f1(); 	// accessing f1() member function from object "ob"

        The function f1() is automatically passed a pointer to "ob" -which is the object that invokes the call. 
            That pointer is referred to as "this"


    Restrictions:
        Only member functions are passed a "this" pointer. 
        A friend does NOT have a "this" pointer

*/



// --------    rev[03-jun-2024]    --------

/* Example 1: When a member function "refers" to another member of a class, 
                it does so DIRECTLY without qualifying the member with either a "class or an object specification"

                Examine following short program, which creates a simple "inventory" class
*/

// Demonstrate the this pointer .
#include <iostream>
#include <cstring>

class inventory{
        char item[20];
        double cost;
        int on_hand;
    public:
        inventory(char *i, double c, int o) {
            strcpy(item , i);
            cost = c;
            on_hand = o;
        }
    void show();
};

void inventory :: show(){
    std::cout << item ;
    std::cout << ": $" << cost ;
    std::cout << " On hand : " << on_hand << "\n";
}

int main(){
    inventory ob(" wrench ", 4.95 , 4);
    ob.show();
    
    return 0;
}

/*  Notice:
        In the functions inventory() and show(), 
            all the member variables "item", "cost", "on_hand" are referred to directly. 

        This is because a "member function" can be called only in CONJUNCTION with an "object". 
            Therefore, the compiler knows which object's data is being referred to.
            for example: "ob.show()"

*/







 

// however we can use "this" to access a class memebers
 
class inventory {	char item[20];
double cost ;
int on_hand ;
public : 
inventory( char *i, double c, int o) {
/* accessing through "this" pointer */
strcpy (this->item , i); 	
this->cost = c; 
this->on_hand= o; }	
void show (); };

void inventory :: show(){ 
 /* use "this" to access members*/
cout << this->item ; 	
cout << ": $" << this->cost ;
cout << " On hand : " << this->on_hand << "\n"; }


 
	Here the member variables are accessed explicitly through the this pointer. 
	Shorthand-form: within show(), these two statements are equivalent:
cost = 123.23;
this -> cost = 123.23;
the first form is a shorthand for the second.
Note
[1]	By default, all member functions are automatically passed a pointer to the invoking object.
[2]	The this pointer has several uses, including aiding in overloading operators.

