
/* ----------------------     CLASS intro     ---------------------- 
    Class is the core feature of C++ and OOP.
    The class is the mechanism that is used to create 'objects'. 

    A class is declared using the 'class' keyword. 
        The syntax of a class declaration is similar to that of a 'structure' 
        (actually class is a kind of "structure" with more feature). 
*/

// General form:
class class_name {
    // private functions and variables
    public :
        // public functions and variables
} object_list;



/* 
    Ways of class Declaration:
        In a class declaration, the 'object-list' and 'class_name' are optional. (Similar to structure)

        From a practical point of view 'class_name' is virtually always needed. 
            the 'class_nam'e acts like a DATA-TYPE name that is used to declare 'objects of the class'.



    Private and public members : 
        'Functions' and 'variables' declared inside a class declaration are said to be 'members' of that class.

        private by default: 
            By default, all functions and variables declared inside a class are private to that class. 
            they are accessible, only by other 'members of that class'. 

        public: 
            To declare public class members, the 'public' keyword is used, followed by a 'colon : '. 
            All functions and variables declared 'after the public specifier' are accessible both by 
                other members of the class and by any other part of the program that contains the class. 
*/


// Here is a simple class declaration: 
class myclass{
    // (default) private to myclass 
    int a;

    public:
        void set_a(int num );	// prototype 
        int get_a();		// prototype 
};

/* 
    Above class has one private variable, called 'a', and 
        two public functions, set_a() and get_a(). 

        Since 'a' is private, it is not accessible by any code outside "myclass". 
        since 'set_a()' and 'get_a()' are members of myclass, they can directly access  'a'.
        
        Further, 'set_a()' and 'get_a()' are declared as 'public members of myclass' and 
            can be called by any other part of the program that contains myclass.



    member functions:
        Functions that are declared to be part of a class are called "member functions". 
        Notice that set_a(int num ); and int get_a(); are 'function prototype' declaration inside the class.



    Defining the member functions: 
        Although the prototypes of the functions 'set_a()' and 'get_a()' are declared by myclass, they are 'not yet defined'.
        To define a member function, you must "LINK" the 'type_name of the class' with the name of the function. 
        You do this by preceding the function name with the class name followed by two colons '::' . 
            The two colons are called the "SCOPE RESOLUTION OPERATOR". 
*/


// --------    Defining the member functions of a CLASS    --------

ret_type class_name :: func_name(parameter_list) {
    // body of function
}

// class_name: is the name of the class to which the function belongs 
// ret_type: is the return type of the function which must be the 'same return type of the prototype' declared inside the class.




/* Example 1: For example, here member functions set_a() and get_a() are defined: */
void myclass :: set_a(int num) {
    	a = num;	
}

int myclass :: get_a() {
     	return a;	
}




/* --------    object of a class    --------
    Crating object of a class : 
        This is similar to declaring a 'structure variable' in C. 
            Since 'class is similar to structure' and "object is similar to variable". 
        
        The 'declaration of a class' did not define any objects of type of that class 
            - it only defines the type of object that will be created when one is actually declared. 
    
    
        To create an object, use the 'class_name' as a "type specifier" :

                class_name object_name1, object_name2, . . . , object_nameN; 
*/




/* Example 2: For example, this line declares two objects of type myclass: */
myclass ob1 , ob2; 		// these are objects of type myclass 



/* 
    // ----    CLASS & its OBJECT    ----
    A 'class declaration' is a "Logical ABSTRACTION" that defines a NEW TYPE. 
        It determines what an 'object of that type' will look like.

    An 'object declaration' creates a "Physical ENTITY" of that type. 
        i.e. an object occupies "memory space", but a type definition does not.



    // ----    local & global OBJECT    ----
    Like variables, there is 'local objects' and 'global objects'.



    // ----    accessing object members    ----
    Accessing members of an object: 
        your program can reference an objects "public members" by using the dot '.' (period) operator
        its the same way that structure members are accessed.

    'Each object' of a class has its 'own copy of every variable' declared within the class. 
        statements in following example set ob1's copy of 'a' to 10 and ob2's copy to 99. 
        This means that ob1's 'a' is DISTINCT and DIFFERENT from the 'a' linked to ob2.
*/




/* Example 3: Assuming the preceding object declaration, the following statement calls "set_a()" for objects 'ob1' and 'ob2': */

ob1.set_a(10);      // sets ob1's version of 'a' to 10
ob2.set_a(99);      // sets ob2's version of 'a' to 99




/* Example 2: Create a class that holds 'name' and 'address' information. 
                Store all the information in 'character strings' that are "private" members of the class. 

                Include a "public function" that stores the 'name' and 'address'. 
                Also include a "public function" that displays the 'name' and 'address'. 
                (Call these functions store() and display().)
*/




/* Example 4: What is wrong with the following fragment? */
#include <iostream>
using namespace std;

class myclass{
    int i;
    
    public:
        . 
        . 
        .
};

int main(){
    myclass ob;
    ob.i = 10;
    . 
    . 
    . 
}




