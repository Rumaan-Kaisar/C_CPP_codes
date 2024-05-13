
/* ------------    array of objects    ------------
    The syntax for declaring an "array of objects" is exactly similar to 
        array of any other type of variable. 

    Arrays of objects are accessed just like arrays of other types of variables.

*/



/* Example 1: Following program creates a four-element array of objects of type "samp" and 
                    then loads each element's a with a value between 0 and 3.  
    
                The array name, in this case "ob", is indexed; 
                then the "member access operator" is applied, 
                    followed by the name of the member function to be called. 
*/
#include <iostream>

class samp{	
        int a;
    public:
        void set_a(int n) { a = n; }
        int get_a() { return a; }
};

int main() {
    samp ob[4];	
    int i;

    // notice how "ob" is indexed and access a member
    for(i=0; i<4; i++) ob[i].set_a(i);
    for(i=0; i<4; i++) std::cout<< ob[i].get_a();
    std::cout<< "\n";
    
    return 0;
}



/* ------------    Array initialization    ------------


*/

	Initialization list (short and long form) for array with constructor: If a class type includes a constructor, an array of objects can be initialized. For example, here ob is an initialized array:

class samp { 	int a;
public :samp(int n) { a = n; } /* constructor for initialization*/
int get_a() { return a; } };

int main() { samp ob [4] = { -1, -2, -3, -4 };
. . . . . . }

Actually, the syntax shown in the initialization list samp ob [4] = { -1, -2, -3, -4 }; is shorthand for this longer form (first shown in 10.3 ):
samp ob[4] = { 	samp( -1), samp( -2),
samp( -3), samp( -4)    };
However, the shorthand form used in the program is applicable when constructors take only one argument. For constructors with two or more argument (multidimensional arrays of objects) we have to use the longer form.  For example, 

class samp { 	int a, b;
public : samp(int n, int m) { a = n; b = m; } /* initialization for 2-D array */
int get_a() { return a; }
int get_b() { return b; }	};

int main() { 	samp ob[4][2] = {	samp(1, 2), 		samp(3, 4),
samp(5, 6), 		samp(7, 8),
samp(9, 10), 		samp(11 , 12),
samp(13 , 14), 	samp(15 , 16)   };
. . . . . }

	The reason is, the formal C++ syntax allows only one argument at a time in a comma-separated list. There is no way, for example, to specify two (or more) arguments per entry in the list. 
	Therefore, when you initialize arrays of objects that have constructors that take more than one argument, you must use the "long form" initialization syntax rather than the "shorthand form."
	You can always use the long form of initialization even if the object takes only one argument. 

