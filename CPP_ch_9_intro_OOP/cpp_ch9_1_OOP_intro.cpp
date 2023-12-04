
/* ----------------------     Object Oriented Programming : OOP     ----------------------

    Using OOP we can manage a very large programs.

    Structured programming:
        Structured programming relies on:
            well-defined control structures, 
            code blocks, 
            the absence (or at least minimal use) of the GOTO, and 
            stand-alone subroutines that support recursion and local variables. 
            
            The essence of structured programming is the 'reduction of a program into its constituent elements'. 
            Using structured programming, the average programmer can create and maintain programs that are up to 50,000 lines long. 
            
            To moderately complex programs 'Structured programming' fails at some point, after a program reaches a certain size :
                the problems were about 
                    data abstraction, 
                    code reusability and 
                    maintenance. 



    OOP:    
        object-oriented programming was invented to write 'complex programs'.
        OOP also allows more MANAGABLE codes

        OOP takes the best of the ideas embodied in 'structured programming' and combines them with 
            powerful new concepts that allow us to "ORGANIZE" our programs more EFFECTIVELY. 
            OOP lets us to 'decompose a problem' into its 'CONSTITUENT PARTS'. 
        
        Each component becomes a 'self-contained object' that contains its own 'instructions' and 'data' that relate to that object. 
            In this way, "complexity is reduced" and the programmer can 'manage larger programs'.

        All OOP languages, including C++, share three common defining traits: 

                    ENCAPSULATION, 
                    POLYMORPHISM and 
                    INHERITANCE
    


    ENCAPSULATION : 
        Encapsulation is the mechanism that 'binds together CODE and the DATA' it manipulates, and 
            keeps both safe from outside interference and misuse like a self-contained "black box". 
            As a result an OBJECT is created. 

        Within an object, code, data, or both may be 'PRIVATE' to that object or 'PUBLIC'. 
            Private code or data is known to and accessible oanly by another part of the object. 
                cannot be accessed outside the object.
            Public code or data are accessable to other parts of the program.

        Typically, the PUBLIC parts of an object are used to "provide a controlled interface" to the PRIVATE elements of the object.

        An "object" is can be treated as a variable of a 'user-defined type' (like a structure type variables)
            In C++ CLASSES are more like 'structures' and OBJECTS are more like 'variables' 



    POLYMORPHISM : 
        "To morph" means "to change". So "Morph = shape shifting" and "Morphism = shape shifting property". 
            Polymorphism (from the Greek, meaning "many forms")
        
        Polymorphism is the quality that allows one name to be used for two or more related but technically different purposes. 
        As it relates to OOP, polymorphism allows "one name to specify a general class of actions". 
            Within a general class of actions, the 'specific action' to be applied is "determined by the TYPE of data". 
            It allows us to handle 'greater complexity' by allowing the creation of 'standard interfaces to related activities'.

        For example, in C,  the 'absolute value action' requires three distinct function names: 
            abs(), return the absolute value of an integer
            labs(), return the absolute value of an long integer and 
            fabs(), return the absolute value of an long floating-point value
        
        using polymorphism, each function can be called by the same name, such as abs().
            there is no need for sepearte functions 
            [we'll discuss it later in "function overloading", one function name for many different purposes.].

	        The 'type of data' used to call the function DETERMINES "which specific version" of the function is actually executed.
	
        Polymorphism helps to reduce complexity by allowing 'one interface' to specify a "general class of action". 
            It is the "COMPILER's job" to select the 'specific action' as it applies to each situation.
            
            As in previous example, having three names for the absolute value function instead of just one 
                makes the general activity of obtaining the absolute value of a number more complex than it actually is.
	

    Operator overloading : 
            Polymorphism can be applied to operators, too. 
            Virtually all programming languages contain a limited application of polymorphism as it relates to the arithmetic operators. 
                For example, in C, the '+ sign' is used to add integers, long integers, characters, and floating-point values. 
                In these cases, the 'compiler automatically knows' which type of arithmetic to apply. 
                
                In C++, you can extend this concept to "other types of data" that you define. 
                    This type of POLYMORPHISM is called "operator overloading".



    INHERITANCE :  
        Inheritance is the process by which 'one object' can acquire the PROPERTIES of another. 
            More specifically, an object can inherit a 'general set of properties' to which it can add those features that are specific only to itself. 
	
        Inheritance is important because it allows an object to support the concept of "Hierarchical Classification". 
            Most information is made manageable by hierarchical classification. (More like set and their subsets). 
            
            For example, think about the description of a HOUSE. 
                A house is a part of the general class called BUILDING. 
                In turn, building is part of the more general class STRUCTURES. 
            
            In each case, the "child class" inherits all those qualities associated with the "parent" and 
                adds to them its own defining characteristics. 
	
        Through inheritance, it is possible to describe an object 
            by stating what general class (or classes) it belongs to along with those specific traits that make it unique. 

*/


