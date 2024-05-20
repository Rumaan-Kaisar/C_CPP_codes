
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

        The reason is, the formal C++ syntax allows only one argument at a time in a "comma-separated list". 
            There is no way, for example, to specify two (or more) arguments per entry in the list. 

        Therefore, when you initialize "arrays of objects" that have constructors that take "more than one argument", 
            you must use the "long form" initialization syntax rather than the "shorthand form."


    You can always use the "long form of initialization" even if the object takes only one argument. 
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




/* Example 3: (Multidimensional arrays of objeects) here is a program
                that creates a 2D array of objects and initializes them: 

                notice the constructor takes one parameter, hence 'shorthand form' used
*/
// Create a two - dimensional array of objects .
#include <iostream>

class samp{
        int a;
    public:
        samp(int n) { a = n; }
        int get_a() { return a; }
};


int main(){
    // following initalize 8 objects
    samp ob[4][2] = { 
        1, 2,
        3, 4,
        5, 6,
        7, 8,
    };

    int i;

    for(i =0; i<4; i++){
        std::cout << ob[i][0].get_a() << ' ';
        std::cout << ob[i][1].get_a() << "\n";
    }
    std::cout << "\n";

    return 0;
}




// -=-=-=-    Initialization for a 2-D array of objects with a 2-parameter constructor    -=-=-=-

/* Example 4: A constructor can take more than one argument. 
                When initializing an array of objects whose constructor takes 
                more than one argument, you must use the "longer form" of initialization.  
*/

#include <iostream>

class samp{
        int a, b;
    public:
        samp( int n, int m) { a = n; b = m; }   // 2-parameter constructor
        int get_a() { return a; }
        int get_b() { return b; }
};


int main(){
    // following initalize 8 objects using "longer form"
    samp ob [4][2] = { 
        samp(1, 2),     samp(3, 4),
        samp(5, 6),     samp(7, 8),
        samp(9, 10),    samp(11, 12),
        samp(13 , 14),  samp(15, 16)
    };

    int i;

    for(i =0; i <4; i ++){
        std::cout << ob[i][0].get_a() << ' ';
        std::cout << ob[i][0].get_b() << "\n";
        std::cout << ob[i][1].get_a() << ' ';
        std::cout << ob[i][1].get_b() << "\n";
    }
    std::cout << "\n";

    return 0;
}

/*  In this example, samp's constructor takes two arguments.

    Here, they array "ob" is declared and initialized in main() by using "direct calls" to samp's constructor. 

    This is necessary because the formal C++ syntax allows only one argument at a time in a comma-separated list.
    There is no way, for example, to specify two (or more) arguments per entry in the list.

    Therefore, when you initialize arrays of objects that have constructors that take more
        than one argument, you must use the "long form" initialization syntax rather than the "shorthand form."
*/



// ----  rev[20-May-24]  ----

/* Example 5: Using the following class declaration, create a 10-element array and 
                initialize the ch element with the values 'A' through 'J'. 
                Demonstrate that the array does, indeed, contain these values. 

                class letters {
                        char ch;
                    public:
                        letters(char c){ ch = c; }
                        char get_ch(){ return ch; }
                };
*/
#include <iostream>

class letters {
        char ch;
    public:
        letters(char c) { ch = c; }
        char get_ch() { return ch; }
};

# include <iostream >
using namespace std ;
class letters
{
char ch;
public :
letters ( char c) { ch = c; }
char get_ch () { return ch; }
};
int main ()
{
letters ob [10] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j' };
int i;
for (i =0; i <10; i ++)
cout << ob[i]. get_ch () << ’ ’;
cout << "\n";
return 0;
}






/* Example 6: Using the following class declaration, create a 10-element array, 
                initialize "num" to the values 1 through 10, and 
                initialize "sqr" to num's square. 

                class squares {
                        int num , sqr;
                    public:
                        squares(int a, int b) { num = a; sqr = b; }
                        void show() { std::cout << num << ' ' << sqr << "\n"; }
                };                
*/
#include <iostream>

class squares {
        int num , sqr;
    public:
        squares(int a, int b) { num = a; sqr = b; }
        void show() { std::cout << num << ' ' << sqr << "\n"; }
};


# include <iostream >
using namespace std ;
class squares
{
int num , sqr ;
public :
squares ( int a, int b) { num = a; sqr = b; }
void show () { cout << num << ’ ’ << sqr << "\n"; }
};

int main ()
{
squares ob [10] = {
squares (1, 1) ,
squares (2, 4) ,
squares (3, 9) ,
squares (4, 16) ,
squares (5, 25) ,
squares (6, 36) ,
squares (7, 49) ,
squares (8, 64) ,
squares (9, 81) ,
squares (10 , 100) ,
};
int i;
for (i =0; i <10; i ++)
ob[i]. show ();
return 0;
}




/* Example 7: Change the initialization in "Example 5" so it uses the "long form of initialization". 
                (That is, invoke letter's constructor explicitly in the initialization list.) 
*/

#include <iostream>

class letters {
        char ch;
    public:
        letters( char c) { ch = c; }
        char get_ch() { return ch; }
};


int main(){
    letters ob [10] = {
        letters('a'),
        letters('b'),
        letters('c'),
        letters('d'),
        letters('e'),
        letters('f'),
        letters('g'),
        letters('h'),
        letters('i'),
        letters('j'),
    };

    int i;

    for(i=0; i<10; i++) std::cout << ob[i].get_ch() << ' ';
    std::cout << "\n";

    return 0;
}

