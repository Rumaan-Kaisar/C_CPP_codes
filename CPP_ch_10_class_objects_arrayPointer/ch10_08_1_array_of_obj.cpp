
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




/*  ------------    initialize an array of objects    ------------
    If a class type includes a constructor, an array of objects can be initialized.
        Shorthand form: 
                        samp ob[4] = { -1, -2, -3, -4 };
        longer form:
                        samp ob[4] = { samp(-1), samp(-2), samp(-3), samp(-4) }; 


    Notice (recall ch10_01_3_constructor_param.cpp):
        The syntax for passing an argument to a parameterized constructor is shorthand for this longer form:

                    myclass ob = myclass(4)

        And mostly we used the shorthand form:

                    myclass ob(4)


    However, the shorthand form is applicable when constructors take "only one argument". 
        We have to use the longer form for constructors with two or more argument 
        (eg: multidimensional arrays of objects)



*/


/* Example 2: (Initialize an array) Here "ob" is an initialized array.
                We used the array { -1, -2, -3, -4 } to initialize the array of obejects ob[4] 
*/
#include <iostream>

class samp{
        int a;
    public:
        samp(int n) { a = n; }      // constructor for initialization (in-line)
        int get_a(){ return a; }
};


int main(){
    samp ob[4] = { -1, -2, -3, -4 };
    int i;

    for (i =0; i <4; i ++) std::cout << ob[i].get_a() << ' ';
    std::cout << "\n";

    return 0;
}

/*  Note:
            samp ob[4] = { -1, -2, -3, -4 };

        is shorthand for following longer form:

            samp ob[4] = { samp(-1), samp(-2), samp(-3), samp(-4) }; 
*/



// ----    REV[16-MAY-24]    ----

	The reason is, the formal C++ syntax allows only one argument at a time in a comma-separated list. 
There is no way, for example, to specify two (or more) arguments per entry in the list. 

	Therefore, when you initialize arrays of objects that have constructors that take more than one argument, 
you must use the "long form" initialization syntax rather than the "shorthand form."

	You can always use the long form of initialization even if the object takes only one argument. 

class samp { 	int a, b;
public : samp(int n, int m) { a = n; b = m; } /* initialization for 2-D array */
int get_a() { return a; }
int get_b() { return b; }	};

int main() { 	samp ob[4][2] = {	samp(1, 2), 		samp(3, 4),
samp(5, 6), 		samp(7, 8),
samp(9, 10), 		samp(11 , 12),
samp(13 , 14), 	samp(15 , 16)   };
. . . . . }



