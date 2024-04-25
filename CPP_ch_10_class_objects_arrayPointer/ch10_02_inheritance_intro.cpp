
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




/* Example 2: Derived class can call BASE class's 'public' member functions directly. */

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




/* Example 3: Here is a program that defines a generic base class called fruit that describes certain
                characteristics of fruit. This class is inherited by two derived classes Apple and Orange.
                These classes supply specific information to fruit that are related to these type of fruit. 
                
                
                Recall:
                    enum: A list of 'named integer constants' called an enumeration. 
                    These constants can then be used 'any place' an 'integer' can.
                */

// An example of class inheritance.
#include <iostream>
#include <cstring>


enum yn {no , yes};
enum color {red , yellow , green , orange};

void out(enum yn x);
char *c[] = {"red ", "yellow", "green", "orange"};


// Generic fruit class.
class fruit{
    // in this base , all elements are public
    public:
        enum yn annual;
        enum yn perennial;
        enum yn tree;
        enum yn tropical;
        enum color colr;
        char name[40];
};


// Derive Apple class .
class Apple : public fruit{
        enum yn cooking;
        enum yn crunchy;
        enum yn eating;
    public:
        void setApl(char *nm, enum color clr, enum yn cok, enum yn crnchy , enum yn eat);
        void show();
};

// Derive orange class .
class Orange : public fruit{
        enum yn juice;
        enum yn sour;
        enum yn eating;
    public:
        void setOrng (char *nm, enum color clr, enum yn juc, enum yn sur , enum yn eat);
        void show();
};

// define member functions
void Apple :: setApl(char *nm, enum color clr, enum yn cok, enum yn crnchy , enum yn eat){
    strcpy(name, nm);
    annual = no;
    perennial = yes;
    tree = yes;
    tropical = no;

    colr = clr;
    cooking = cok;
    crunchy = crnchy;
    eating = eat;
}

void Orange :: setOrng(char *nm, enum color clr, enum yn juc, enum yn sur , enum yn eat){
    strcpy(name, nm);
    annual = no;
    perennial = yes;
    tree = yes;
    tropical = yes;

    colr = clr;
    juice = juc;
    sour = sur;
    eating = eat;
}

void Apple :: show(){
    std::cout << name << " apple is: " << "\n";
    std::cout << " Annual : "; out(annual);
    std::cout << " Perennial : "; out(perennial);
    std::cout << " Tree : "; out(tree);
    std::cout << " Tropical : "; out(tropical);
    std::cout << " Color : " << c[colr] << "\n";
        // 'colr' is an enum, i.e. a number and it is used as an index of array 'c'
    std::cout << " Good for cooking : "; out(cooking);
    std::cout << " Crunchy : "; out(crunchy);
    std::cout << " Good for eating : "; out(eating);
    std::cout << "\n";
}

void Orange :: show(){
    std::cout << name << " orange is: " << "\n";
    std::cout << " Annual : "; out(annual);
    std::cout << " Perennial : "; out(perennial);
    std::cout << " Tree : "; out(tree);
    std::cout << " Tropical : "; out(tropical);
    std::cout << " Color : " << c[colr] << "\n"; 
        // 'colr' is an enum, i.e. a number and it is used as an index of array 'c'
    std::cout << " Good for juice : "; out(juice);
    std::cout << " Sour : "; out(juice);
    std::cout << " Good for eating : "; out(eating);
    std::cout << "\n";
}


// output function
void out(enum yn x){
    if(x == no) {
        std::cout << "no\n";
    }
    else {
        std::cout << "yes \n";
    }
}


int main(){
    Apple a1, a2;
    Orange o1, o2;

    a1. setApl(" Red Delicious ", red , no , yes , yes );
    a2. setApl(" Jonathan ", red , yes , no , yes );
    o1. setOrng(" Navel ", orange , no , no , yes );
    o2. setOrng(" Valencia ", orange , yes , yes , no);
    a1. show();
    a2. show();
    o1. show();
    o2. show();

    return 0;
}

/*  Notice, the BASE class 'fruit' defines several characteristics that are common to all types of fruit. 
        For example, all fruit grows on either 'annual' or 'perennial' plants, such as vines or bushes. 
        All fruit has a 'color' and a 'name'.

    This base class 'fruit' is then inherited by the 'Apple' and 'Orange' classes. 
        Each of these classes supplies information specific to its type of fruit.


    Use of inheritance:
        Notice the base class is created that defines the general traits associated with all fruit. 
        It is left to the derived classes to supply those traits that are specific to each individual case.

        another important fact about inheritance is:
            A base class is not exclusively "owned" by a derived class. 
            A base class can be inherited by any number of classes.
*/




/* Example 4: Given the following base class,

                    class area_cl{
                        public:
                            double height;
                            double width;
                    };

                Create two derived classes called 'rectangle' and 'isosceles' that inherit "area_cl". 
                Have each class include a function called area() 
                    that returns the area of a rectangle or isosceles triangle, as appropriate. 
                
                Use parameterized constructors to initialize height and width
*/

#include <iostream>

class area_c1{
    public:
        double height;
        double width;
};

// derived classes
class rectangle:public area_c1{
    public:
        rectangle(double h, double w);
        double area();
};

class isosceles:public area_c1{
    public:
        isosceles(double h, double w);
        double area();
};


// member functions of derived class
rectangle::rectangle(double h, double w){
    height = h;
    width = w;
}

isosceles::isosceles(double h, double w){
    height = h;
    width = w;
}

double rectangle::area(){
    return width*height;
}

double isosceles::area(){
    return 0.5*width*height;
}


int main(){
    rectangle b(10.0, 5.0);
    isosceles i(4.0, 6.0);

    std::cout << "Rectangle : " << b.area() << "\n";
    std::cout << "Triangle : " << i.area() << "\n";

    return 0;
}




/* Example 5: Given the following base class, 
                show how it can be inherited by a derived class called 'Mars'. 
*/

class planet{
        int moons;
        double dis_from_sun;
        double diameter;
        double mass;
    public:
        // ...
};

// Ans:  derived class called 'Mars'
class Mars:public planet{
    // ...
};


