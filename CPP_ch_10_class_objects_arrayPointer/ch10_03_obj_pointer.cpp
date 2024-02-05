
/*  ------------------------    Object Pointers    ------------------------
    It is possible to 'access a member' of an object via POINTER to that object. 
        When a pointer is used, the arrow operator (->) rather than the dot '.' operator is employed. 
        (This is exactly the same way the arrow operator is used when given a pointer to a structure.)
        However using the dot operator to access members of an object is the correct method.

    Declaration:
        You declare an object pointer just like you declare a 'pointer to any other variable'. 
        Specify its class name, and then precede the variable name with an asterisk. 
            clss_name *obj_ptr;

    Address:
        To obtain the address of an object, precede the object with & operator, just as any other type of variable.
            obj_ptr = &obj;

    increment:
        Like other types, an object pointer, when 'incremented', will 'point to the next object' of its type.
        
    Note that creation of an object pointer 'does not create an object'- it creates just a pointer to one. 
*/



/* Example 1: consider myclass is a class, following creates a pointer of 'type myclass' */
int main(){
    myclass ob(120); 	// create object
    myclass *ptr;       //  create pointer to object

    ptr = &ob; // put address of 'ob' into 'ptr'
    std::cout << " Access value using object : " << ob.get();  // dot-operator '.' is used
    std::cout << "\n";
    std::cout << " Access value using pointer : " << ptr->get(); // arrow-operator '->' is used

    return 0; 
}

/*  Notice how the declaration
            myclass *ptr;
        creates a pointer to an object of myclass.
    
    The address of 'ob' is put into 'ptr' by using this statement:
            ptr = &ob;

    following shows how the 'members of an object' can be accessed through a Pointer as using :
            p->get()

    'Pointer arithmetic' using an object pointer is the same as it is for any other data type: 
        it is performed relative to the 'type' of the object. 
        For example, when an object pointer is 'INCREMENTED', it points to the 'next object'. 
        When an object pointer is 'DECREMENTED', it points to the previous object.
        Consider following example
*/




/* Example 1(full version): Here is a simple example that uses an object pointer: */
#include <iostream>

class myclass{
        int a;
    public:
        myclass(int x); // constructor
        int get();
};

myclass::myclass(int x){
    a = x;
}

int myclass::get(){
    return a;
}

int main(){
    myclass ob(120); 	// create object
    myclass *ptr;       //  create pointer to object

    ptr = &ob; // put address of 'ob' into 'ptr'
    std::cout << " Access value using object : " << ob.get();  // dot-operator '.' is used
    std::cout << "\n";
    std::cout << " Access value using pointer : " << ptr->get(); // arrow-operator '->' is used

    return 0; 
}




/* Example 2: following demostrates the pointer arithmetics for an 'object pointer' 
                Notice an inline function is used as a constructor
*/
#include <iostream>

class samp{
        int a, b;
   public : 
        samp(int n, int m) { a=n; b=m; } // inline function as constructor
        int get_a() { return a; }
        int get_b() { return b; }   
};

int main() {
    // array of 4 objects
    samp ob[4] = {
        samp(1, 2), 
        samp(3, 4),
        samp(5, 6), 
        samp(7, 8) 
    };

    int i;
    samp *p;

    p = ob;  // get starting address of array

    for(i=0; i<4; i++){
        std::cout << p->get_a() << ' ';
        std::cout << p->get_b() << "\n";
        p++;  // advance to next object 
    }

    // . . .
    // . . .

    return 0;
}

// Each time p is incremented, it points to the next object in the array.

