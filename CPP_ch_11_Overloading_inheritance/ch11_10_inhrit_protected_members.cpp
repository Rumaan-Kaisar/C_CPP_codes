
/*  ------------------------    inheritance and "protected"    ------------------------

    Protected:
        Sometimes we want to keep a member of a BASE class "private" but still allow a DERIVED class access to it.
        To do this, use the "protected" access specifier.


    Accessing PROTECTED members:
        Protected members of a base class can be accessed by any class derived from that base.
        Outside the base or derived classes, protected members are not accessible.
        The protected access specifier can occur anywhere in the class declaration
        They're usually placed after private (default) members and before public ones in a class.


    General form of a CLASS declaration with all ACCESS specifiers:

                class ClassName {  
                        // private members (default)

                    protected:  
                        // protected members (optional)

                    public:  
                        // public members
                };


        A "protected member" in a BASE class:
            Becomes protected in the derived class if "inherited as public".
            Becomes private in the derived class if "inherited as private".

        If a base class is "inherited as protected":
            Its public and protected members become protected in the derived class.

        Private members of the base class always stay private and are not accessible in the derived class.

        protected can also be used in "structs".

*/  




/* Example1: This program illustrates how public, private, and protected members of a class can be accessed 
                It also shows: what occurs when protected members are inherited as public: 

                Because a and b are PROTECTED in base and inherited as PUBLIC by derived, 
                they are available for use by member functions of derived as we used to showabc().

                However, outside of these two classes, a and b are effectively private and inaccessible.
*/

#include <iostream>

class base { 
        int t;      //  private member
    protected:
        int a, b;   //  private but accessible by derived *
    public:
        int s;
        void setab(int n, int m){ a=n; b=m; }
};


//  new class 
class derived : public base {   
        int c;  //  private in deived 
    public:
        void setc(int n){c = n;}
        // this has access to a and b from base 
        void showbc(){ std::cout<< a <<' '<< b <<' '<< c; }
};


int main(){ 
    base ob_bs; //  base type object 
    derived ob_drv; //  derived type object 

    // ob_bs.t=5;  //  error: t is private member of base
    // ob_bs.a=3;  //  error: 
    // ob_bs.b=4;  //  error: a,b is protected member of base but accessible inside derived
    ob_bs.s=9;   //  ok: s is public member of base

    ob_bs.setab (3, 4);     // ok: setab() is public member of base
    ob_drv.setab(1, 2);     // ok: setab() is also public to derived because it derived publicly
    ob_drv.setc(3);         // ok: c is public member of derived

    // ob_drv.a=3; //  error:
    // ob_drv.b=4; //  error: a,b is protected member of base but accessible inside derived
    ob_drv.showbc(); 	//  accessing a,b inside of derived class
    
    return 0;
}  



// following is more simplified version of previous program
// The commented line in main() is invalid because b is protected, so it's still hidden from outside the class.
# include <iostream>

class samp{
        // private by default
        int a;
    protected:
        // still private relative to samp
        int b;
    public:
        int c;
        samp(int n, int m){ a = n; b = m; }
        int geta(){ return a; }
        int getb(){ return b; }
};


int main(){
    samp ob(10 , 10);

    // ob.b = 99; Error ! b is protected and thus private
    ob.c = 30; // OK , c is public
    std::cout << ob.geta() << ' ';
    std::cout << ob.getb() << ' ' << ob.c << '\n';
    
    return 0;
}




/* Example 2: The following program illustrates what occurs when protected members are inherited as public.

                Because a and b are protected in base and inherited as public by derived, 
                    they are available for use by member functions of derived. 

                However, outside of these two classes, a and b are effectively private and inaccessible.
*/

#include <iostream>

class base{
    // private by default
    protected: 
        int a, b; // private to base, but still accessible by derived
    public:
        void setab(int n, int m){ a = n; b = m; }
};


class derived : public base{
        int c;
    public:
        void setc(int n){ c = n; }
        // this function has access to a and b from base
        void showabc(){ std::cout << a << ' ' << b << ' ' << c << '\n'; }
};


int main(){
    derived ob;

    // a and b are not accessible here because they are private to both "base" and "derived".
    ob.setab(1, 2);
    ob.setc(3);
    ob.showabc();

    return 0;
}




/* Example 3: When a base class is "inherited as protected", PUBLIC and PROTECTED members of the base class 
                become "protected" members of the DERIVED class. 

                For example following statement returns error because of inheriting base as protected instead of public 
                in the class declaration of derived in the preceding program


                        class derived : protected base {
                            //  same as before
                        }

                        int main(){ 
                            derived ob_drv;         // derived type object 
                            ob_drv.setab(1, 2);     // ERROR : setab() is now a protected member of base. setab() is not accessible here . 
                            // ...
                        }

                Because BASE is inherited as "protected", its "public" and "protected" elements become protected members of 
                DERIVED and are therefore inaccessible within main().
*/

// This program will not compile. To compile it- inherit "base" publicly
#include <iostream>

class base{
    // private by default
    protected: 
        int a, b; // private to base, but still accessible by derived
    public:
        void setab(int n, int m){ a = n; b = m; }
};

// inherit as protected
class derived : protected base{
        int c;
    public:
        void setc(int n){ c = n; }
        // this function has access to a and b from base
        void showabc(){ std::cout << a << ' ' << b << ' ' << c << '\n'; }
};


int main(){
    derived ob;
    
    // ERROR : setab() is now a protected member of base.
    ob.setab(1, 2); // setab() is not accessible here.
    ob.setc(3);
    ob.showabc();

    return 0;
}




/* Example 4: What is the resulting access level of a "protected member" 
                when inherited as public, private, or protected?

            ans:
                When a protected member of a base class is inherited as public, 
                    it becomes a protected member of the derived class. 
                If it is inherited as private, it becomes a private member of the derived class. 
                If it is inherited as protected, it becomes a protected member of the derived class.

*/






/* Example 5: Explain why the protected category is needed? */

The protected category is needed to allow a base class to keep certain members private
while still allowing a derived class to have access to them.




/* Example 6: In "Example 5 (skeleton-code)" from previous section (ch11_09_inhrit_BaseClass_access.cpp), if the a and b inside myclass were made into protected
instead of private (by default) members, would any of your answers to that exercise
change? If so, how? */

/* Example: Examine following skeleton-code:

                Within main(), which of the following statements are legal?

                    A. o1.getab(i, j);
                    B. o2.getab(i, j);
                    C. o1.c = 10;
                    D. o2.c = 10; 

            ans:
                A and C are valid.
*/

#include <iostream>

class mybase{
        int a, b;
    public:
        int c;
        void setab(int i, int j){ a = i; b = j; }
        void getab(int &i, int &j){ i = a; j = b; }
};

class derived1 : public mybase{
    // ...
};

class derived2 : private mybase{
    // ...
};


int main(){
    derived1 o1;
    derived2 o2;
    int i, j;
    // ...
}

// ANS: No.


