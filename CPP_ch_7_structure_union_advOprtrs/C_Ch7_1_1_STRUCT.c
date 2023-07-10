/* 
	-----------------    User-defined Data-types of C    -----------------

	int, float, char data types are etc. Custom User-defined Data-types are created by combining the built-in data types.

		In C we can define five kind of custom data-types :
	
			[1]	Structure 
			[2]	Union
			[3]	Bit-field
			[4]	Enumeration
			[5]	Typedef 
	



	-----------------    STRUCTURE Basics    -----------------
	structures  
		It is a mechanism for "packing" data of "different types".
		A structure is an aggregate(=collection) (or conglomerate) data type that is composed of 
			two or more related variables called members. 
		
		fields/elements/members
			The members of a structure are also commonly referred to as fields or elements.
		
		General form:
						struct tag-name {
							type member_1;
							type member_2;
							type member_3;
							. . .
							. . .
							type member_N;
						} variable-list;


		each member of a structure can have its own type, which may differ from the types of the other members.

		The keyword struct tells the compiler that a "structure type" is being defined.

		The type of each member must be a valid C type. 

		The tag-name is essentially the "type-name" of the structure. 
			It is the user defined data-type-name like : int, char. We use the type name as we've used 'int' or 'char'.

		The "variable-list" is where actual 'instances' (the variables which use the structure data-type) of the structure are declared. 

		Either the tag-name or the variable-list is optional, but one must be present.

		Generally, the information contained in a structure is logically related. 
			For example, consider a structure to hold a person's address.
	
		


	-----------------    arrays vs structures    -----------------

	Arrays can be used to represent a group of data items that belong to the same type, such as int or float. 
		"structure" supports a collection of data items of "different types u"sing a "single name". 

	Both the arrays and structures are classified as "structured data types" 

	Any array behaves like a built-in data type. All we have to do is to declare an array variable and use it. 
		But in the case of a structure, we have to design and declare a "DATA STRUCTURE" 
			before the variables of that type are declared and used.
			
	Structures help to organize complex data in a more meaningful way.
*/	


/* Example 1:  The structure shown here defines fields that can hold card-catalog information: */

struct catalog {
	char name [40] ; 	// author name 
	char title[40] ; 	// title 
	char pub[40] ; 		// publisher 
	unsigned date;		// copyright date 
	unsigned char ed; 	// edition 
} card;



/* 
	-----------------    OBJECT of a structure    -----------------

	In previous example, 'catalog' is the "type name" of the structure. 
		It is not the name of a variable. 

	The only variable defined by this fragment is "card". 

	It is important to understand that a "structure DEFINITION" defines only a "logical entity", which is a 'new data type'. 
		When a variable of that type is declared an "OBJECT" of that type is created. 
		(In C++ class are use the similar principle) 

	Hence, 'catalog' is a logical template; 'card' has physical reality. 


	=====    How the card structure variable appears in memory (assuming 2-byte integers)    =====
					name [40]		40 byte
					title[40]		40 byte
					pub[40]			40 byte
					date date		2  byte
					ed				1  byte

					Card = Total 123 byte.




	-----------------    Variation of structure variables DECLARATION    -----------------

	Once you have defined a structure type (with already existing variable-list or no variable-list), 
		you can create additional variables of that type using this general form:

				struct tag-name additional_variable_list;


	Form 1: re-usable. 
		'tag-name' and 'variable-list' are present. 
		New additional variables can be declared along with old 'variable-list'.
		
				struct tag_name {
						type member_1;
						type member_2;
						type member_3;
						. . .
						. . .
						type member_N;
					} variable-list;	
	

	Form 2: usable only once.
		No tag-name is present. 
		Additional variables cannot be declared after defining structure.	

				struct {
						type member_1;
						type member_2;
						type member_3;
						. . .
						. . .
						type member_N;
					} variable-list;	


	Form 3: re-usable
		Only "tag-name" is present.
		all variables can be declares after defining the structure

				struct tag_name {
						type member_1;
						type member_2;
						type member_3;
						. . .
						. . .
						type member_N;
						};


	For these reason either the tag-name or the variable-list is optional, but one must be present. 
		For example this statement declares three variables of type struct catalog:

			struct catalog var1, var2, var3;

	It is not necessary to declare any variables when the structure type is defined. 
		You can declare them separately, as needed.



	Hence, Most used form of structure variables DECLARATION:

		Defining structure : 		
				struct tag-name {	type member_1;
									type member_2;
									type member_3;
									. . .
									. . .
									type member_N;};

		Declaring structure variables : 
			
				struct tag_name var_list;

*/



7.2.3 Structure variable initialization : 
Like any other data type, a structure variable can, be initialized at compile time. We can initialize a structure variable in two different ways:

	Along with structure declaration (without tag-name): We can initialize a structure variable directly when we declaring a structure. In this case we don’t need tag-name to mention. The general form is :

struct {	type member_1;
type member_2;
type member_3;
. . .
. . .
type member_N;
} variable_name = {member_1_value, member_2_value, . . ., member_N_value };

	Separately (split variable declaration) : We can initialize a structure variable using structure tag-name as we declared structure-variables before. This is the most used way. The general form is :

struct tag-name {	type member_1;
type member_2;
type member_3;
. . .
. . .
type member_N; } ;
. . . . . .
. . . . . .
struct tag-name variable_name = {member_1_value, member_2_value, . . ., member_N_value };

Rules and restrictions to initialize structure-variables :  There are a few rules to keep in mind while initializing structure variables at compile-time.

[1]	The compile-time initialization of a structure variable must have the following elements:
i.	The keyword struct.
ii.	The structure tag-name. 
iii.	The name of the variable to be declared.
iv.	The assignment operator = .
v.	A set of values for the members of the structure variable, separated by commas and enclosed in curly braces. 
vi.	A terminating semicolon.
[2]	We cannot initialize individual members inside the structure template.
[3]	The order of values enclosed in braces must match the order of members in the structure definition.
[4]	It is permitted to have a partial initialization. We can initialize only the first few members and leave the remaining blank..The uninitialized members should be only at the end of the list.
[5]	The uninitialized members will be assigned default values as follows:
•	Zero for integer and floating point numbers. 
•	'\0' for characters and strings. 
	
7.2.4 Accessing members of a structure & use of "." operator 
To access a member of a structure, you must specify both the structure variable name and the member name, separated by a period. For example, using card, the following statement assigns the date field the value 1776 :	card.date = 1776; 	C programmers often refer to the period as the dot operator. 
	Output data from a member of a structure - variable : To output data from a member of a structure – variable we specify both the structure variable name and the member name, separated by a period inside the console output functions : printf(), putchar(), puts(). For example: To print the copyright date of previous catalog structure, 
printf("Copyright date: %u", card.date);
	Input data to a member of a structure – variable : To input data to a member of a structure - variable we specify both the structure variable name and the member name, separated by a period inside the console input functions : scanf(), getchar(), gets(). For example: To input the date, use a scanf() statement such as:
scanf("%u", &card.date);
	Notice that the "&" goes before the structure name, not before the member name.
	I/O of string and individual character of a string to/from a member of a structure – variable : On a similar fashion, these statements input the author's name and output the title:
gets(card.name);
printf("%s", card.title);

	To access an individual character in the "title" field, simply index "title". For example, the following statement prints the third letter: 
printf("%c", card.title[2]);

	Operations on individual members :  A member with the dot operator along with its structure variable can be treated like any other variable name and therefore can be manipulated using expressions and operators.  We can also apply increment and decrement operators to numeric type members.  The precedence of the member operator (dot operator) is higher than all arithmetic and relational operators and therefore no parentheses are required. For example  :  Consider

struct item{int m; float x; char c;} ver_1, ver_2;

We can perform the following operations:

if(ver_1.m > 4) ver_2.m++;	 	/* logical operator & increment operator*/
float sum = ver_1.x + ver_2.x;

7.2.5 Structures as arrays :
Structures can be arrayed in the same fashion as other data types. For example, the following structure definition creates a 100-element array of structures of type catalog:
struct catalog cat[100];
	To access an individual structure of the array, you must index the array name. For example, the following accesses the first structure of catalog type structure array cat: 	cat[0];
	To access a member within a specified structure, follow the index with a period and the name of the member you want. For example, the following Statement loads the ed field (or member) of structure cat[33] of type catalog with the value of 2:     cat[33].ed = 2;

7.2.6 Arrays within Structures :
C permits the use of arrays as structure members. We have already used arrays of charac¬ters inside a structure. Similarly, we can use single-dimensional or multi-dimensional arrays of type int or float. For example, the following structure declaration is valid:

struct marks{ int number; 
 float subject[3]; 
} student[2];

These elements can be accessed using appropriate subscripts. For example, 

student[1].subject[2];

7.2.7 COPYING AND COMPARING STRUCTURE VARIABLES
You may assign the contents of one instance (variables) of a structure to another as long as they are both of the same type. For example, this fragment is perfectly valid:

struct s_type { int a; float f; } var1, var2;
var1.a = 10; var2.f = 100.23; 	/*assigning values to members of var1*/
var2 = var1; 				/*copying values of var1 to members of ver2 */

After this fragment executes, var2 will contain exactly the same thing as var1.

	Two variables of the same structure type can be copied the same way as ordinary variables. If personl and person2 belong to the same structure, then the following statements are valid:	
person1 = person2;
person2 = person1;
	However, the statements such as
person1 == person2;
person1 != person2;

are not permitted. C does not permit any logical operations on structure variables. In case, we need to compare them, we may do so by comparing members individually. For Example these statements are valid: 

person1.member_1 == person2.member_1;
person1.member_2 <= person2.member_2;
person1.member_3 != person2.member_3;

Note
A key concept to understand is that each instance of a structure contains its own copy of the members of the structure. For example, 

struct tag_name var1, var2, var3;

the title field of var1 is completely separate from the title field of var2. In fact, the only relationship that var1, var2, and var3 have with one another is that they are all variables of the same type of structure. There is no other linkage among the three.

7.2.8 Structures and Functions 
We know that the main philosophy of C language is the use of functions. And therefore, it is natural that C supports the passing of structure values as arguments to functions. There are three methods by which the values of a structure can be transferred from one function to
[1]	The first method is to pass each member of the structure as an actual argument of the function call. 
	The actual arguments are then treated independently like ordinary vari¬ables. 
	But it becomes unmanageable and inefficient when the structure size is large.

[2]	The second method involves passing of a copy of the entire structure to the called function. Structures may be passed as parameters to functions just like any other type of value. A function may also return a structure.

	Since the function is working on a copy of the structure, any changes to structure members within the function are not reflected in the original structure (in the calling function). 
	It is, therefore, necessary for the function to return the entire structure back to the calling function. 
	All compilers may not support this method of passing the entire structure as a parameter.

[3]	The third approach is to pass a pointer of the structure as an argu¬ment. In this case, the address location of the structure is passed to the called func¬tion. 
	The function can access indirectly the entire structure and work on it.
	This is similar to the way arrays are passed to function. 
	This method is more efficient as compared to the second one.
 
Now we focus on the second method :
function returns structure : The general format of structure returning function
struct structure_type_name function_name ();
The called function takes the following form:
struct structure_type_name function_name ()
{
struct structure_type_name var_name;
. . .
Assignment of structure variable's members
. . .
return var_name;}
example : The following program, for example, loads the members of  var1 with the values 100 and 123.23 and then displays them on the screen :
#include <stdio.h>

struct s_type { int i; double d; } ;

struct s_type f(void); /* function as a structure */

int main(void){struct s_type var1; 
var1 = f() ; /* calling the structure type function and assigned to var1 */
printf("%d %f", var1.i, var1.d); 
return 0;}

struct s_type f(void){struct s_type temp;
temp.i = 100; temp.d = 123.23;
return temp;}

Structure as function parameter: The general format of sending a copy of a structure to the called function is
function_name (structure_variable_name);

The called function takes the following form:
data_type function_name(struct structure_type_name var_name)
{. . .
 . . .
 expression;}
example : 
#include <stdio.h>

struct s_type { int i; double d; } ;

void f(struct s_type temp); /* structure as function parameter */

int main(void){struct s_type var1;
var1.i = 99; var1.d = 98.6; /*assigning values to struct. variable var1 */
f(var1); /* passing structure-variable to function*/
return 0;}

/* defining function using structure-members */
void f(struct s_type temp){printf("%d %f", temp.i, temp.d);}

Remember following points 
I.	The called function must be declared for corresponding structure's type-name, appropriate to the data type it is expected to return. For example, if it is returning a copy of the entire structure, then it must be declared as struct with an appropriate tag name.
II.	The structure variable used as the actual argument and the corresponding formal argument in the called function must be of the same struct type.
III.	The expression may be any simple variable or structure variable or an expression using simple variables.
IV.	When a function returns a structure, it must be assigned to a structure of identical type in the calling function. And function must be declared as the corresponding structure type function.
V.	The called functions must be declared in the calling function appropriately.

7.2.9 SIZE OF STRUCTURES
We normally use structures, unions, and arrays to create variables of large sizes. The actual size of these variables in terms of bytes may change from machine to machine. We may use the unary operator sizeof to tell us the size of a structure (or any variable). 
	The expression :  	sizof(struct x)  	will evaluate the number of bytes required to hold all the members of the structure x. 
	If y is a simple structure variable of type struct x, then the expression :	sizeof(y) 	would also give the same answer. 
	If y[n] is an array variable of type struct then sizeof(y) would give the total number of bytes the array y[n] requires.

So using these information we can determine the number of records in a database. For example, the expression
sizeof(y)/sizeof(x)
would give the number of elements in the array y.

note 
[1]	To know the size of a structure, you should use the sizeof compile-time operator. Do not try to manually add up the number of bytes in each field. 
[2]	We need sizeof() because : in some situations, the compiler may need to align certain types of data on even word boundaries. In this case, the size of the structure will be larger than the sum of its individual elements. 
[3]	When using sizeof with a structure type, you must precede the tag name with the keyword struct, as shown in this program:
#include <stdio.h>
struct s_type { int i; char ch; int *p; double d; } ver_s1, ver_sa[10];
int main(void){printf("s_type is %d bytes long", sizeof(struct s_type)); 
printf("\n s_type variable ver_s1 is %d bytes long", sizeof(ver_s1)); 
printf("\n s_type array variable ver_sa is %d bytes long", sizeof(ver_sa));
return 0;}

