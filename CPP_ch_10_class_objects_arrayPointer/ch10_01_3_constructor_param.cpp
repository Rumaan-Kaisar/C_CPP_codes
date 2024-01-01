
/* ----------------------     Constructors with Parameters     ----------------------  */


Constructors with Parameters
It is possible to pass arguments to a constructor function. To allow this, simply add the appropriate parameters to the constructor function's declaration and definition. Then, when you declare an object, specify the arguments. By Constructors with Parameters we can initialize different objects with different values as we want.

class class_name{	/* private functions and variables */
          public :          	/* public functions and variables */	
class_name(type p1, type p2, . . . type pN);		/* constructor with parameter */
}; 			/* no object list. Objects declared separately */
. . .
. . .
class_name object1(p1, p2, . . . , pN); /* passing arguments to constructor */
	Actually, the syntax for passing an argument to a parameterized constructor is shorthand for this longer form (which use constructor function):
class_name object1 = class_name(p1, p2, . . . , pN);
however the short-hand form is  often used :  class_name object1(p1, p2, . . . , pN);
	Destructor functions cannot have parameters. The reason is there exists no mechanism by which to pass arguments to an object that is being destroyed.

Example:		class myclass{  int a;
                public :	myclass( int x ); /* constructor with parameter */
                    		void show();    };

myclass :: myclass( int x ) { cout << "In constructor \n";	a = x; }

void myclass :: show() {cout << a <<"\n";  }

int main() {    myclass ob(4); 	/* object with arguments to constructor */
                ob.show();  	/* calling function */
     			       return 0;}
	Here the constructor for myclass takes one parameter. 
	The value passed to myclass() is used to initialize a. 
	ob is declared in main() with arguments ob(4). The value 4, specified in the parentheses following ob, is the argument that is passed to myclass()'s parameter x, which is used to initialize a.
Note
[1]	However, most C++ programmers use the short form. Actually, there is a slight technical difference between the two forms that relates to copy constructors.
[2]	You can pass an object's constructor any valid expression, including variables. Actually objects can be constructed as needed to fit the exact situation at the time of their creation. 

