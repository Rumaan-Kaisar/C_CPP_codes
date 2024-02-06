
/*  ----------------    structures-unions and classes    ----------------
    
    -=-=-=-    structures    -=-=-=-
    
    Structures:
        General form of a structure in C++ :

            struct type_name {
                    // PUBLIC function and data members
                private :
                    // PRIVATE function and data members
            } object_list;


    Note:
        by default members of a STRUCTURE are "public"
        by default members of a CLASS are "private"


    Relation between STRUCTURES and CLASSES:
        The 'class' and the 'structure' have virtually IDENTICAL capabilities.  
        In C++ structures include 'member functions', including constructor and destructor functions. 

        Only difference between a 'structure' and a 'class' is: 
            by default, the members of a CLASS are 'private' but 
            the members of a STRUCTURE are 'public'. Because in C all structure members are public by default. 

        In C++  both 'struct' and 'class' create new class types.


    private:
        it tells the compiler that the members that follow are 'private to that class'  (applicable for both class and structure).




    -=-=-=-    unions    -=-=-=-

    Unions: 
        In C++, a union defines a class type that can contain both "functions and data" as members. 
            All members are 'public' by default until the 'private' specifier is used. 
            All data members share the 'same memory location' (just as in C). 
            Unions can contain 'constructor' and 'destructor'

        Why it's unique?
            Union links code and data 
            It allows you to create "class types" in which all data uses a "SHARED LOCATION".
            you cannot do this kind of "shared location" using a CLASS.


        restrictions to apply UNIONS
            no inheritance:
                UNIONS cannot inherit any other class and they cannot be used as a base class for any other type. 

            object constructor/destructor not allowed:
                UNIONs 'must not contain' any OBJECT that has a constructor or destructor. 
                The union, itself, 'can have' a constructor and destructor though. 

            no static members:
                Unions must not have any static members.

            no virtual fn:
                UNIONs 'cannot have' virtual member functions. (Virtual functions are described later.)



    -=-=-=-    anonymous union    -=-=-=-

    ----  rev [6-feb-24]  ----
    
    Anonymous union: 
        An anonymous union special type of union that "does not have a TYPE name", and 
        No variables can be declared for this sort of union. 
        Instead, it tells the compiler that its 'members' will share the "same memory location".
        
        However, in all other, respects, the members act and are treated like normal variables. That is, the members are accessed directly, without the dot operator syntax.  For example, examine this fragment:
union  { int i; char ch [4]; }; 	// an anonymous union
i = 10; ch [0] = 'X'; 		// access i and ch directly
Here i and ch are accessed directly because they are not part of any object. They share the same memory space.
	Anonymous union is that it gives you a simple way to tell the compiler that you want two or more variables to share the same memory location. 
	Aside from this special attribute, members of an anonymous union behave like other variables.
	Anonymous unions have all of the restrictions that apply to normal unions, plus these additions.
	A global anonymous union must be declared static. 
	An anonymous union cannot contain private members. 
	The names of the members of an anonymous union must not conflict with other identifiers within the same scope.
Note
[1]	Although structures have the same capabilities as classes, most programmers restrict their use of structures to adhere to their C-like form and do not use them to include function members.
[2]	We reserve the use of struct for objects that have no function members.


----  rev [5-feb-24]  ----

 */
