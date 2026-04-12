
/*  ------------------------    chapter    ------------------------

13. 5 Generic-Functions & Generic-Classes (GnF & GnC)
Generic functions and classes (reusable code): We create generic functions  & classes using templates. In a generic function or class, the type of data that operated upon is specified as a parameter. This allows you to use one function or class with several different types of data without specific explicit-code  for each different data type. 
	A GnF defines a general set of operations that will be applied to various types of data. A GnF has the type of data that it will operate upon passed to it as a parameter. 
	A GnF is the data-independent-code which defines the nature of the algorithm. The compiler automatically generates the correct code for the type of data during function execution. By a Gnf the function can automatically overload itself.
	It helps a lot because many algorithms are logically the same no matter what type of data is being operated upon. For example, the Quicksort algorithm is applicable for both integers and floats.  It is just that the type of the data being sorted is different.
	template: A GnF is created using the keyword template.  In C++ the keyword template  is used to create a template (or framework) that describes what a function will do, leaving it to the compiler to fill in the details as needed. The general form of a template is :

template <class Ttype> ret_type func_name(parameter list){ /* body of function */ }
	Here Ttype is a placeholder name for a data type used by the function. It can be used within the function definition. The compiler will automatically replace this placeholder with an actual data type during function execution.
	Class is used to specify a generic type in a template declaration. It is traditional; you can also use the keyword typename.
	Template function:  A generic function / GnF (that is, a function definition preceded by a template statement) is also called a template function.
	Generated function: When the compiler creates a specific version of this function, it is said to have created a generated function.
	Instantiating a function: The act of generating a function is referred to as instantiating it.  Put differently, a generated function is a specific instance of a template function.
	Generic-Classes (GnC):  When you define GnC you create a class that defines all algorithms used by that class, but the actual type of the data being manipulated will be specified as a parameter when objects of that class are created.
	GnC are useful when a class contains generalizable logic (i.e when data types varies). By using a GnC, you can create a class that will maintain a queue, a linked list, and so on for any type of data. 
	The compiler will automatically generate the correct type of object based upon the type you specify when the object is created.
	Member functions of a GnC are, themselves, automatically GnF. They need not be explicitly specified as such using template.
	The general form of a GnC declaration is:
template <class Ttype > class class_name { . . .
. . . };
	Here Ttype is the placeholder type name that will be specified when a class is instantiated. 
	If necessary, you can define more than one generic data type by using a comma-separated list.
	Once you have created a GnC, you create a specific instance of that class by using the following general form:
class_name <type> ob;
	Here type is the type name of the data that the class will be operating upon.
	One point to remember(?): in the case of GnC we create the object of that generic class using 
 class_name<type> obj_name ;
instead of ordinary " class_name obj_name ;". And we can access/define any function/member of that generic class "outside" of it by using: 
template <class Ttype > class_name<type> :: member(parametr){}
Here the key point is that " class_name<type>" considered the class name instead of ordinary " class_name" to define an object of its type or accessing any member outside of it.
	When you create a GnF, you are, in essence, allowing the compiler to generate as many different versions of that function as necessary to handle the various ways that your program calls that function.
	Example 1: The following program creates a GnF / Function template that swaps the values of the two variables it is called with. (Because the general process of exchanging two values is independent of the type of the variables)
template<class X> void swapargs(X &a, X &b){       X temp;
					         temp = a;
					         a = b;
					         b= temp ;  }
int main( ){	int i=10 , j =20;
		float x=10 , y =23.3;
		cout << " Original i, j: " << i << ' ' << j << endl ;
		cout << " Original x, y: " << x << ' ' << y << endl ;	
	swapargs(i, j); 		/* swap integers */ 
	swapargs(x, y); 		/* swap floats */ 

	cout << " Swapped i, j: " << i << ' ' << j << endl ;
	cout << " Swapped x, y: " << x << ' ' << y << endl ;
	
	return 0; }

	The keyword template is used to define a generic function. The line:
template<class X> void swapargs(X &a, X &b)
tells the compiler two things: that a template is being created and that a generic definition is beginning. 
	Here X is a generic type that is used as a placeholder. 
	After the template portion, function swapargs() is declared, using X as the data type of the values that will be swapped. 
	In main(), the swapargs() function is called using two different types of data: integers and floats. Because swapargs() is a generic function, the compiler automatically creates two versions of swapargs()-
	one that will exchange integer values and 
	one that will exchange floating-point values. 
	The template portion of a GnF definition does not have to be on the same line as the function's name. For example, 
template <class X>
void swapargs(X &a, X &b) { X temp;  temp=a;  a=b;  b=temp;  }
	No other statements can occur between the template statement and the start of the GnF definition. For example, the following fragment will not compile:
template <class X>
int i; 	/* this line causes error */ 
void swapargs (X &a, X &b) { X temp ; temp = a; a = b; b= temp ; }
	Instead of using the keyword class, we can use the keyword typename to specify a generic type in a template definition. Eg: 
template<typename X> void swapargs(X &a, X &b){ X temp; temp = a; a = b; b= temp; }
	The typename keyword can also be used to specify an unknown type within a template.
	To define more than one generic data-type with the template statement, use a comma-separated list. For example:
template<class type1, class type2> 
void myfunc(type1 x, type2 y){ cout<< x <<' '<< y << endl; }

int main(){ 	myfunc(10 , "hi");
myfunc (0.23 , 10L);
return 0; }
	The placeholder types type1 and type2 are replaced by the compiler with the data types int and char * and double and long, respectively, when the compiler generates the specific instances (or specific object) of myfunc().
	GnF are similar to overloaded functions except that they are more restrictive.
	For overloaded function different actions can be performed within the body of each function. 
	But a GnF must perform the same general action for all versions. 
	For example, the following overloaded functions cannot be replaced by a Gnf because they do not do the same thing:
void outdata(int i){ cout << i; }
void outdata(double d){ 	cout << setprecision(10) << setfill ('#');
cout << d;
cout << setprecision(6) << setfill (' '); }
	Example 2 (overloading GnF / template): Generally a template function overloads itself as needed. But we can explicitly overload one, too. If you overload a GnF, that overloaded function (our version) overrides (or "hides") the GnF relative to that specific version. For example, consider this version of Example 1:

template <class X> void swapargs(X &a, X &b) { X temp ; temp = a; a = b; b= temp ; }
void swapargs (int a, int b) { cout << " this is inside swapargs (int ,int )\n"; }	 /* This overrides the GnF swapargs().*/ 

int main( ){ 	int i=10, j =20;
float x=10, y =23.3;
cout << " Original i, j: " << i << ' ' << j << endl ;	   cout << " Original x, y: " << x << ' ' << y << endl ;
swapargs(i, j); 		/* calls overloaded swapargs(), because of matched int arguments  */ 
swapargs (x, y); 		/* swap floats */ 
cout << " Swapped i, j: " << i << ' '<< j << endl ; 	   cout << " Swapped x, y: " << x << ' ' << y << endl ;
return 0; }

	When swapargs(i,j) is called, it invokes the explicitly overloaded version of swapargs() defined in the program (because of int values). Thus, the compiler does not generate this version of the generic swapargs() function because the GnF is overridden by the explicit overloading.
	Manual overloading of a template, as shown in this example, allows you to tailor a version of a GnF to accommodate a special situation. 
	In general, if you need to have different versions of a function for different data types, you should use overloaded functions rather than templates.
	Example 3: This program creates a very simple generic singly linked list class. It then demonstrates the class by creating a linked list that stores characters.
template <class data_t > class list {	data_t data ;
list *next ;
public :
list ( data_t d);
void add(list *node){
node -> next = this; 
next = 0; }
list *getnext(){ return next ; }
data_t getdata(){ return data ; }
};

/* definition of member function 'list' */

template <class data_t > list <data_t >:: list ( data_t d) {	data = d;
						next = 0;}	int main(){	list<char>  start ('a');
		list<char>  *p, * last ;
		int i;
/* build a list */
	last = &start ;
	for (i=1; i <26; i++){  p = new list <char >( 'a' + i);
			     p->add ( last );
			     last = p;	}
/* follow the list */ 
	p = &start ;
	while(p) {  cout << p-> getdata();
		    p = p-> getnext();}
	return 0;}

	The actual data-type stored by the list is generic in the class declaration. Here objects and pointers are created inside main() that specify that the data-type of the list will be char.
	Setting data type in object declaration of a generic class-type: The desired data type is passed inside the angle brackets in the following declaration:
list< char > start('a') ;
	By simply changing the data-type specified "inside < >" when list objects are created, you can change the type of data stored by the list. For example, you could create another object that stores integers by using:
list< int > int_start(1) ;
	Use list to store data types that you create: For example, if you want to store address information, use following structure:
struct addr {	char name[40];
		char street[40];
		char city[30];
		char state[3];
		char zip[12]; }
	Then, to use list to generate objects that will store objects of type addr, use:	          list< addr > obj( structvar );
 (assuming that structvar contains a valid addr structure)
	A template class can have more than one generic data type. Simply declare all the data types required by the class in a comma-separated list within the template specification.
	Example 4:  the following short example creates a class that uses two generic data types:
template <class Type_1 , class Type_2> class myclass{ 	Type1 i;
						Type2 j;
	         public : myclass( Type1 a, Type2 b) {  i = a;   j = b; }
	         void show() { cout << i << ' ' << j << '\n'; }	     
	         };	int main(){         myclass< int, double > ob1 (10 , 0.23) ;
	              myclass<char , char *> ob2('X', " This is a test ");
		ob1.show(); 	/* show int , double */ 
		ob2.show(); 	/* show char , char **/ 
	   return 0; }
		This program produces the following output:	     10     0.23
							     X This is a test
	The program declares two types of objects. ob1 uses integer and double data. ob2 uses a character and a character pointer. 
	For both cases, the compiler automatically generates the appropriate data and functions for each object.

Note
[1]	C++ provides a library that is built upon template classes. This library is usually referred to as the Standard Template Library, or STL for short. 
[2]	STL provides generic versions of the most commonly used algorithms and data structures. 



*/  
