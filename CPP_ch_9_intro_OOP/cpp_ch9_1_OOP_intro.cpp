
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
 

 
	ENCAPSULATION : Encapsulation is the mechanism that binds together code and the data it manipulates, and keeps both safe from outside interference and misuse like a self-contained "black box". When code and data are linked together in this fashion, an object is created. 
	Within an object, code, data, or both may be private to that object or public. 
	Private code or data is known to and accessible oanly by another part of the object. That is, private code or data cannot be accessed by a piece of the program that exists outside the object.
	When code or data is public, other parts of the program can access it even though it is defined within an object. 
	Typically, the public parts of an object are used to provide a controlled interface to the private elements of the object.
	For all intents and purposes, an object is a variable of a user-defined type (more like a structure type variables. In C++ classes are more like structures and objects are more like variables ). 

	POLYMORPHISM : "To morph" means "to change". So "Morph = shape shifting" and "Morphism = shape shifting property". Polymorphism (from the Greek, meaning "many forms") is the quality that allows one name to be used for two or more related but technically different purposes. As it relates to OOP, polymorphism allows one name to specify a general class of actions. Within a general class of actions, the specific action to be applied is determined by the type of data. It allows us to handle greater complexity by allowing the creation of standard interfaces to related activities.

For example, in C,  the absolute value action requires three distinct function names: abs(), labs(), and fabs(). These functions compute and return the absolute value of an integer, a long integer, and a floating-point value, respectively. However, in C++, which supports polymorphism, each function can be called by the same name, such as abs(). 
[we'll discuss it later in "function overloading". In C++, it is possible to use one function name for many different purposes. This is called function overloading.].
	The type of data used to call the function determines which specific version of the function is actually executed. 
	More generally, the concept of polymorphism is characterized by the idea of "one interface, multiple methods," which means using a generic interface for a group of related activities.
	Polymorphism helps to reduce complexity by allowing one interface to specify a general class of action. (It is the compiler's job to select the specific action as it applies to each situation.)  As in previous example, having three names for the absolute value function instead of just one makes the general activity of obtaining the absolute value of a number more complex than it actually is.
	Operator overloading : Polymorphism can be applied to operators, too. Virtually all programming languages contain a limited application of polymorphism as it relates to the arithmetic operators. For example, in C, the + sign is used to add integers, long integers, characters, and floating-point values. In these cases, the compiler automatically knows which type of arithmetic to apply. In C++, you can extend this concept to other types of data that you define. This type of polymorphism is called operator overloading.

	INHERITANCE :  Inheritance is the process by which one object can acquire the properties of another. More specifically, an object can inherit a general set of properties to which it can add those features that are specific only to itself. 
	Inheritance is important because it allows an object to support the concept of hierarchical classification. Most information is made manageable by hierarchical classification. (More like set and their subsets). For example, think about the description of a house. A house is a part of the general class called building. In turn, building is part of the more general class structures. In each case, the child class inherits all those qualities associated with the parent and adds to them its own defining characteristics. 
	Through inheritance, it is possible to describe an object by stating what general class (or classes) it belongs to along with those specific traits that make it unique. 

 */
