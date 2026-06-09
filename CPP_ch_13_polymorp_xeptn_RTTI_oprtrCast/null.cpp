


// ----  rev[07-Jun-2026]  ----

// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-


// -=-=-=-=-=-=-=-=-    Cumulative Skills Check    -=-=-=-=-=-=-=-=-


// -=-=-=-=-=-=-=-    Review Skills Check    -=-=-=-=-=-=-=-








// -=-=-=-=-=-=-    Mastery Skills Check    -=-=-=-=-=-=-








 



// -=-=-=-=-=-=-=-=-    update this to GitHub first    -=-=-=-=-=-=-=-=-




// polymorph: compiled




/* Example 1:

            What is a virtual function? How do virtual functions differ from overloaded functions?

                A virtual function is a function declared as "virtual" in a "base" class 
                    and intended to be "overridden" by a derived class.
                    A base class that contains at least one pure virtual function is called an "abstract class".

                Difference from overloaded functions:
                    "Overloaded" functions must differ in the "number of parameters" or the "type of parameters".
                    An overridden virtual function "must have exactly the same prototype" as the original function.
                    (i.e. same return type, and same type and number of parameters) 



            What is a pure virtual function? 
            If a class declaration contains a pure virtual function, what is that class called? And
            What restrictions apply to its usage?

                A pure virtual function is a virtual function declared with "= 0" (e.g., virtual void func() = 0;) 
                    and typically has no implementation in the base class.

                A class containing at least one pure virtual function is called an "abstract class".

                Restrictions: 
                    You cannot instantiate (create objects of) an abstract class directly. 
                    It can only be used as a base class, and any derived class must override all pure virtual functions 
                    to become a concrete (instantiable) class.



            If, in a class hierarchy, a derived class neglects to override a (non-pure) virtual function, 
                what happens when an object of that derived class calls that function?
            
                If a derived class does not override a "non-pure virtual function", 
                the derived class will automatically inherit and use the "base class’s version" of that virtual function.



            What is the main advantage of "run-time polymorphism"? 
            What is its potential disadvantage?
            
                Main advantage: 
                    Flexibility.
                    It allows writing generic code that can work with objects of 
                    different derived classes through a common base class interface).
            
                Potential disadvantage: 
                    Loss of execution speed. 
                    Due to the slight overhead of "dynamic binding" and virtual table lookups at run-time.
*/

