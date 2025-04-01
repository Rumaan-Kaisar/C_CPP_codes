
/*  ------------------------    BASE class access    ------------------------

    INHERITANCE basics: 
        previously discussed in "ch10_02_inheritance_intro.cpp"


    Inheritance:
        When one class inherits another, it uses this general form:

                    class derived_class_name : access_specifier base_class_name { 
                        // ... 
                        // ... 
                    }

            Here access_specifier is one of three keywords: 
                public, 
                private, or 
                protected.



    --------  Access specifiers  --------
    We've already introduced these in "ch10_02_inheritance_intro.cpp"

    Access specifiers:        
        Access specifiers control how base class members are accessible in the derived class.
        The three access specifiers in C++ are public, private, and protected.

        These access specifiers define the "Inheritance Access Modes"
            The access specifier determines how elements of the base class are inherited by the derived class. 



--------    rev[31-Mar-25]    --------


    In C++ inheritance, we can derive a child class from the base class in different 'ACCESS MODES'. For example,

        class Base {
            // .... 
        };

        class Derived : public Base {
            // .... 
        };


        Notice the keyword 'public' in the code:

                class Derived : public Base

            This means that we have created a derived class from the base class in 'public mode'. 
                Alternatively, we can also derive classes in 'protected' or 'private' modes.

            These 3 keywords (public, protected, and private) are known as access specifiers in C++ inheritance.



    public, protected, and private inheritance have the following features:

        protected:
            protected inheritance makes the 'PUBLIC and PROTECTED members' of the base class "protected" in the derived class.

        private:
            Technically, private access is optional: If the specifier is not present,  it is private by default if the derived class is a class. 
            private inheritance makes the 'public and protected members' of the base class "private" in the derived class.
            If the access specifier is private, all public members of the base class become private members of the derived class. 
            But these private members are still accessible by member functions of the derived class.

        public:
            public inheritance makes 'PUBLIC members' of the base class "public" in the derived class, and 
                the PROTECTED members of the base class "remain protected" in the derived class.
            When the access specifer for the inherited base class is public, all public members of the base become public members of the derived class. 
            In either case (private/public), any private members of the base remain private to it and are inaccessible by the derived class.
            If the derived class is a struct, public is the default in the absence of an explicit access specifier.


    Note: 'private members' of the base class are inaccessible to the derived class.






	Example 1: Here because base is inherited as public, the public members of base- setx() and showx() - become public members of derived and are, therefore, accessible by any other part of the program. Specifically, they are legally called within main().
class base { int x;
    	public :
	void setx (int n) { x = n; }
	void showx() {cout<< x <<'\n';}     };	// Inherit as public .
class derived : public base { int y;
  public : void sety (int n) { y = n; }
           void showy() {cout<< y <<'\n';}  };
	int main() { 	derived ob; 		// derived type object 
			ob.setx(10) ; 	// access member of base class through the derived class's object 
			ob.sety(20) ; 	// access member of derived class 
			ob.showx(); 		// access member of base class through the derived class's object 
			ob.showy(); 		// access member of derived class 
	return 0; }
	Example 2: It is important to understand that just because a derived class inherits a base as public, it does not mean that the derived class has access to the base's private members. For example, in previous example 1 : 

class derived : public base { int y;
  			      public:  // Error! : x is a private member of base and not available within derived . 
   void show_sum() {cout<< x+y << '\n';}  
	In this example, the derived class attempts to access x, which is a private member of base. This is an error because the private parts of a base class remain private to it no matter how it is inherited.
	Example 3 (with private specifier, public member of base become private to derived): this time derived inherits base as private. 

class base { all same as Example 1     };
// Inherit as private .
class derived : private base { same inside };	int main(){ derived ob; 	// derived type object 
	ob.setx(10) ; // ERROR - now setx() private to derived class 
	ob.showx(); // ERROR - now showx() private to derived class 
return 0; }
	Both showx() and setx() become private to derived and are not accessible outside of it. Relative to objects of type derived, they become private.
	Keep in mind that showx() and setx() are still public within base no matter how they are inherited by some derived class. This means that an object of type base could access these functions anywhere. For example, given this fragment:
base base_ob ;
base_ob.setx(1) ; 
Is legal because base_ob is of type base  and the call to setx() is legal because setx() is public within base.
	Example 4: Even though public members of a base class become private members of a derived class when inherited using the private specifier, they are still accessible within the derived class. In this case, the functions setx() and showx() are accessed inside the derived class, which is perfectly legal because they are private members of that class.
class derived : private base { 
int y;
public :
void setxy(int n, int m) { setx(n); y=m; }  // setx is accessible from within derived  
void showxy() { showx(); cout<< y; }  };    // show is accessible from within derived 	
int main(){
derived ob; // derived type
    ob.setxy(10, 20);
    ob.showxy();
return 0; }

*/



