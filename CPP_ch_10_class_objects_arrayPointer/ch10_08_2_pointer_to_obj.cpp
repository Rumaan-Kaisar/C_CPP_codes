
/*  ------------    Object Pointers    ------------
    We've already discussed this topic in : ch10_03_obj_pointer.cpp
        However, let's review it again


    We can 'access' a member of an object via "pointer" to that object. 
    
    When a "pointer" is used, the "arrow operator" (->) rather than the dot (.) operator is employed.
        (it is exactly the same way "->" is used when given a "pointer to a structure")

    However using the dot operator "." to access members of an object is the correct method



    object pointer declaration is same as any other variable. 
        Specify its class name, and then precede the variable name with an asterisk "*"

    Note that, creation of an object pointer does not create an object- 
        it creates just a pointer to one. 



    address:
        To obtain the address of an object, precede the object with "&" operator

    pointer arithmetic:    
        like other types, when object pointer incremented, it will point to the next object of its type.

*/




/* Example 1: following use two ways to access a class member of an object of that class
                    use "." operator 
                    use "->" operator (pointer)
*/

#include <iostream>

class myclass{
        int a;
    public:
        myclass(int x) { a = x; }; // constructor
        int get() { return a; };
};


int main(){
    myclass ob(120); 	// create object
    myclass *ptr;       //  create pointer to object

    ptr = &ob; // put address of 'ob' into 'ptr'
    std::cout << " Access value using object : " << ob.get();  // dot-operator '.' is used
    std::cout << "\n";
    std::cout << " Access value using pointer : " << ptr->get(); // arrow-operator '->' is used

    return 0; 
}




/* Example 2: (Pointers to objects) Here is an example of object pointer arithmetic */

#include <iostream>

class samp{
        int a, b;
    public:
        samp(int n, int m){ a = n; b = m; }
        int get_a(){ return a; }
        int get_b(){ return b; }
};


int main(){
    // initialization
    samp ob[4] = {
        samp(1, 2),
        samp(3, 4),
        samp(5, 6),
        samp(7, 8)
    };

    int i;
    samp *p;    // object pointer

    p = ob;     // get starting address of array
    for(i =0; i<4; i++){
        std::cout << p -> get_a() << ' ';
        std::cout << p -> get_b() << "\n";
        p++;    // advance to next object
    }

    std::cout << "\n";

    return 0;
}




	Notice how the declaration          myclass *p; 	creates a pointer to an object of myclass. 
	The address of ob is put into p by using this statement:       p = &ob;
	Finally, the program shows how the members of an object can be accessed through a Pointer as using :      p->get()  .

	Pointer arithmetic using an object pointer is the same as it is for any other data type: it is performed relative to the type of the object. For example, when an object pointer is incremented, it points to the next object. When an object pointer is decremented, it points to the previous object.
 
class samp { int a, b;
/* inline function as constructor */
   public : samp(int n, int m) { a=n; b=m; } 
     int get_a() { return a; }
     int get_b() { return b; }   };
int main() {
samp ob[4] = {samp(1, 2), samp(3, 4),
samp(5, 6), samp(7, 8) };
int i;
samp *p;
p = ob;  /* get starting address of array */ 
for (i=0; i <4; i++){
cout << p->get_a () << ' ';
cout << p->get_b () << "\n";
p++;  /* advance to next object */ }
. . . . . }
 
	Each time p is incremented, it points to the next object in the array.


