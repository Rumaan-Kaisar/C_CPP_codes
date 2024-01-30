
/* ----------------------     inheritance     ----------------------
    Introduction to INHERITANCE
        It is the mechanism by which one class can 'inherit the properties' of another. 
        Inheritance allows a 'hierarchy of classes' to be built, moving from the "most general" to the "most specific".


    BASE class and DERIVED class: 
        Base / Parent class: When one class is 'inherited' by another, the class that is 'inherited' is called the 'base class'. 
        Derived / Child: The 'inheriting' class is called the 'derived class'. 
        

    Process of INHERITANCE:
        The process of inheritance begins with the 'definition' of a BASE class. 
            BASE class defines all qualities that will be 'common' to any DERIVED classes.
            BASE class represents the 'most general description' of a set of traits. 
        A DERIVED class inherits those general traits from BASE class and 'adds properties' that are 'specific' to that class.

    
    GENERAL FORM:
        The general form used to inherit a base class is shown here:

                class derived_class_name : access_specifier base_class_name {
                            . . . 
                            . . .  
                };

        Here "access-specifier" is one of these three keywords: 
                public, 
                private, or 
                protected. 
*/




/* Example 1: Example of base class and derived class  */
// The declaration & definition for the BASE class	
class Bs {	
        int i;
	public : 
        void set_i(int n);
	    int get_i();  
};		

// Using base class, here is a derived class that inherits it:        
        // Define derived class .
class Drv : public Bs { 
        int j;
    public : 
        void set_k(int n);
        int mul();   
};

/*
    Notice that after the class name 'Drv' there is a colon ':' bofore the keyword 'public' and the class name 'Bs'. 
        This tells the compiler that class 'Drv' will INHERIT all components of class 'Bs'. 

    They keyword public tells the compiler that Bs will be inherited such that all public elements of the base class will also be public elements of the derived class. However, all private elements of the base class remain private to it and are not directly accessible by the derived class.

*/




/*  ----------------------     Inheritance ACCESS MODES: C++ Public, Protected and Private Inheritance     ----------------------
    In C++ inheritance, we can derive a child class from the base class in different 'ACCESS MODES'. For example,

        class Base {
            .... 
            .... 
            ....
        };

        class Derived : public Base {
            .... 
            .... 
            ....
        };


        Notice the keyword 'public' in the code:

                class Derived : public Base

            This means that we have created a derived class from the base class in 'public mode'. 
                Alternatively, we can also derive classes in 'protected' or 'private' modes.

            These 3 keywords (public, protected, and private) are known as access specifiers in C++ inheritance.



    public, protected, and private inheritance have the following features:

        public:
            public inheritance makes 'PUBLIC members' of the base class "public" in the derived class, and 
                the PROTECTED members of the base class "remain protected" in the derived class.

        protected:
            protected inheritance makes the 'PUBLIC and PROTECTED members' of the base class "protected" in the derived class.

        private:
            private inheritance makes the 'public and protected members' of the base class "private" in the derived class.

    Note: 'private members' of the base class are inaccessible to the derived class.

 */

// Inheritance ACCESS MODES: C++ Public, Protected and Private Inheritance
class Base {
    public:
        int x;
    protected:
        int y;
    private:
        int z;
};

class PublicDerived: public Base {
    // x is public
    // y is protected
    // z is not accessible from PublicDerived
};

class ProtectedDerived: protected Base {
    // x is protected
    // y is protected
    // z is not accessible from ProtectedDerived
};

class PrivateDerived: private Base {
    // x is private
    // y is private
    // z is not accessible from PrivateDerived
};




/* Examplpe 2: Derived class can call BASE class's 'public' member functions directly. */

// A simple example of inheritance .
#include <iostream>

// Define base class .
class B{
        int i;
    public:
        void set_i(int n);
        int get_i();
};

// Define derived class .
class D : public B{
        int j;
    public:
        void set_j(int n);
        int mul();
};


// Set value i in base
void B::set_i(int n){
    i = n;
}

// Return value of i in base .
int B::get_i(){
    return i;
}

// Set value of j in derived .
void D::set_j(int n){
    j = n;
}

// Return value of base ’s i times derived ’s j.
int D::mul(){
    // derived class can call base class public member functions
    return j*get_i();
}


int main(){
    D ob;

    ob.set_i(10);   // load i in base
    ob.set_j(4);    // load j in derived
    std::cout << ob. mul();    // displays 40

    return 0;
}

/* Notice carefully
                        int D::mul(){	
                            return j*get_i(); 
                        }
    
    Look at the definition of mul(). 
        Notice that it calls get_i(), which is a member of the base B, not of D, 'without linking' it to any specific object. 
        This is possible because the 'public members of B' become 'public members of D'. Since we used 'public inheritance'

    The reason that mul() must call get_i(), because 'i' is still priveate to D, and not accessable from D

    Remember: To maintain encapsulation, private members of a class are not accessible to derived classes.
*/
