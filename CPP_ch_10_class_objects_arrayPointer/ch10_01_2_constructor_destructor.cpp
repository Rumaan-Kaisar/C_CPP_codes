
// ----------------------     CONSTRUCTOR & DESTRUCTOR     ----------------------  

// General form   of     CONSTRUCTOR	

class class_name{	
        // private functions and variables
    public :
        // public functions and variables	
        class_name();	// constructor
} object_list ;	




// General form   of     DESTRUCTOR

class class_name{	
        // private functions and variables
    public :
        // public functions and variables 	
        ~class_name();	// destructor 
} object_list ;


/* ------------    INITIALIZATION using "constructor"    ------------

    Object INITIALIZATION using "constructor": 
        When applied to real problems, virtually every object you create will require some sort of initialization. 
            To address this situation, C++ allows a constructor function to be included in a class declaration. 
            
        A class’s constructor is 'called each time an object of that class is created'. 
            Any initialization that needs to be 'performed on an object' can be done automatically by the constructor function.

        A constructor function has the 'same name as the class' of which it is a part 
            it has 'no return type'. It is 'illegal' for a constructor to have a 'return type'.

    
    The constructor is called when the object is created. 
        An object is 'created' when that object's declaration statement is EXECUTED. 


    For "GLOBAL objects", an object's constructor is 'called ONCE', when the program first begins execution. 
    For "LOCAL objects", the constructor is 'called EACH TIME' the declaration statement is executed.
 
*/


/* Example 1: construuctor in actioin for Local & Global object */

#include <iostream>
// using namespace std;

class myclass{
        int a;
    public :
        myclass(); // constructor
        void show();    
};


int main(){
    myclass ob; // object declaration

    ob.show();  // calling function
            
    return 0;
}


// member function definition
myclass :: myclass(){ 
    std::cout << "In constructor \n"; 
    a = 10; 
}

void myclass :: show(){
    std::cout << a;
}




/*  ------------    Destroy objects using "destructor"    ------------
    
    Destroy objects using "destructor":  
        The 'complement of a constructor' is the DESTRUCTOR. 
        This function is called when an object is destroyed. 
        
        For example, an object that allocates memory when it is created will 'want to free that memory' when it is destroyed. 
        
        The 'name' of destructor-function is the "name of its class", preceded by a "tilde" "~" . 

    It is not possible to take the ADDRESS of either a 'constructor' or a 'destructor'.

    A class's DESTRUCTOR is called when 'an object is destroyed'. 
        'Local' objects are destroyed when they go out of scope. 
        'Global' objects are destroyed when the program ends. Example: 	 

*/




/* Example 2: destructor & construuctor in actioin for Local & Global object */

#include <iostream>
// using namespace std;

class myclass{  
        int a;
    public : 
        myclass(); 	// constructor 
        ~myclass(); // destructor               
        void show();    
};


int main(){
    myclass ob; // object declaration

    ob.show();  // calling function
            
    return 0;
}


// member function definition
myclass :: myclass(){ 
    std::cout << "In constructor \n"; 
    a = 10; 
}

myclass :: ~myclass(){
    std::cout << "Destructing. . .. \n";
}

void myclass :: show(){
    std::cout << a <<"\n";
}


/* 
Difference between variable and object declaration: 

It is important to understand that in C++, a variable declaration statement is an "action statement." When you are programming in C, it is easy to think of declaration statements as simply establishing variables. However, in C++, because an object might have a constructor, a variable (i.e. object ) declaration statement may, in fact, cause a considerable number of actions to occur.


Other use Restriction: Having a constructor or destructor perform actions not directly related to the initialization or orderly destruction of an object makes for very poor programming style and should be avoided. Technically, a constructor or a destructor can perform any type of operation. The code within these functions does not have to initialize or reset anything related to the class for which they are defined. For example, a constructor for the preceding examples could have computed pi to 100 places. 

 */
