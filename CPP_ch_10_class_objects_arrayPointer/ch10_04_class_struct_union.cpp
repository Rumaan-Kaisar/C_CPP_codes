

10.4 Relation between STRUCTURES-UNIONS and CLASSES
	Structures: The class and the structure have virtually identical capabilities.  In C++ structures include member functions, including constructor and destructor functions,. In fact, the only difference between a structure and a class is that, by default, the members of a class are private but the members of a structure are public.  Because in C all structure members are public by default. General form of a structure in C++ :
struct type_name {
/* public function and data members */ 
private :
/* private function and data members */  
} object_list ;
	In C++  both struct and class create new class types.
	Notice that a new keyword is introduced. It is private, and it tells the compiler that the member that follow are private to that class  (applicable for both class and structure).
	Unions: In C++, a union defines a class type that can contain both functions and data as members. For a union all members are public by default until the private specifier is used. 
	In a union, however, all data members share the same memory location (just as in C). 
	Unions can contain constructor and destructor functions. 
	The union's ability to link code and data allows you to create class types in which all data uses a shared location. This is something that you cannot do using a class.
	There are several restrictions that apply to unions as they relate to C++. 
	First, they cannot inherit any other class and they cannot be used as a base class for any other type. 
	Unions also must not contain any object that has a constructor or destructor. The union, itself, can have a constructor and destructor though. 
	Unions must not have any static members. 
	Finally, unions cannot have virtual member functions. (Virtual functions are described later.)
	Anonymous union: An anonymous union special type of union that does not have a type name, and no variables can be declared for this sort of union. Instead, it tells the compiler that its members will share the same memory location.
	However, in all other, respects, the members act and are treated like normal variables. That is, the members are accessed directly, without the dot operator syntax.  For example, examine this fragment:
union  { int i; char ch [4]; }; 	/* an anonymous union */
i = 10; ch [0] = 'X'; 		/* access i and ch directly */ 
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
