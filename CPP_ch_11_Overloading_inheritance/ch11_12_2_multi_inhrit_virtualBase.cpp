
/*  ------------------------    virtual BASE and Multi inheritance   ------------------------

    Problems with "one derived" & "multiple direct base":
        A potential problem exists when multiple classes are directly inherited by a derived class. 

        When a class is inherited multiple times indirectly through different paths in a class hierarchy, 
            it can cause a problem called the "diamond problem" — 
            where a base class ends up with multiple copies in the final derived class.
        
        Consider the following class hierarchy:

                           Base
                          /   \
                         /     \
                        /       \
                    Derived1   Derived2
                        \       /
                         \     /
                          \   /
                        Derived3

            Here the base class "Base" is inherited by both "Derived1" and "Derived2". 
            "Derived3" directly inherits both "Derived1" and "Derived2". 

        Now, "Derived3" has two copies of Base — one through "Derived1" and one through "Derived2".
        This creates a conflict (ambiguity) if "Derived3" tries to access a member of "Base" — 
            because it won't be clear which "Base" to use.



    Virtual Base Class
        To avoid this problem, inherit "Base" as a "virtual base class" in both "Derived1" and "Derived2".
        This ensures only one shared copy of Base exists in "Derived3", no matter how many paths inherit it.
        The "virtual" keyword precedes the base class "access specifier" when it is inherited by a derived class.

        How to declare:

                class Derived1 : virtual public Base { };
                class Derived2 : virtual public Base { };

            The keyword "virtual" before the access specifier (public) handles this.


        It is important to understand that when a base is inherited as "virtual" by a derived, 
            that base still exists within that derived. 

        The only difference between a "normal base" and a "virtual base" occurs 
            when an object inherits the base more than once. 



    ----------------    How "virtual inheritance" works    ----------------

    It is important to understand that- even if a base class is inherited as virtual (derived1 or derived2),
    its members still exist inside the derived class (derived1, derived2). 

    The virtual keyword only ensures that one shared copy of the base class is included (eg: derived3), 
        avoiding duplication in cases of multiple inheritance — 
        but it doesn't remove the base's presence in derived1 or derived2.

        For example:
                    derived1 ob_drv1;
                    ob_drv1.i = 100;

            This is valid because i (from the base class) still exists inside derived1, 
            whether or not it was inherited virtually. 

        The "virtual inheritance" only affects how inheritance is managed in deeper hierarchies 
            (like when derived3 inherits both derived1 and derived2), 
            not the accessibility within direct derived classes.

*/  




/* Example 1:  Here virtual base class prevents two copies of base from being present in derived3.

                If derived1 and derived2 had not inherited base as virtual, the statement 
                            ob.i = 10; 
                would have been ambiguous and a "compile-time error" would have resulted.
*/

// This program uses a virtual base class .
# include <iostream>

class base {
    public:
        int i;
};


// Inherit base as virtual
class derived1 : virtual public base {
    public:
        int j;
};


// Inherit base as virtual here, too
class derived2 : virtual public base {
    public:
        int k;
};


// Here, derived3 inherits both derived1 and derived2 . However, only one copy of base is present
class derived3 : public derived1, public derived2 {
    public:
        int product() { return i*j*k; }
};


int main() {
    derived3 ob;

    ob.i = 10; // unambiguous because only one copy present
    ob.j = 3;
    ob.k = 5;

    std::cout << "Product is" << ob.product() << '\n';

    return 0;
}












/*  

// rev [03-Jun-2025]

2. Explain why a virtual base class might be necessary 
A virtual base class is needed when a derived class inherits two (or more) classes, both of
which are derived from the same base class. Without virtual base classes, two (or more)
copies of the common base class would exist in the final derived class, However, if the
original base is virtual, only one copy is present in the final derived class.


Example 2: Using the program in Example 1, remove the virtual keyword and try to compile the program. 
                See what type of errors result.




*/

