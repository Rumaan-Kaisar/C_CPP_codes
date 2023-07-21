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


		Notice the use of ";" after "variable-list", 
			we have to use it even if 'variable-list' is not present
			the structue is considered as a statement like int/float/char declaration statement

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
					ed			1  byte

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





	-----------------    Initialization of Structure variables    -----------------
	Like other data types, a structure variable can be initialized at compile time. It can be done in two different ways:

	without tag-name: 
		Initialize directly when we declaring a structure. In this case we don’t need tag-name to mention.

			struct {	
				type member_1;
				type member_2;
				type member_3;
				. . .
				. . .
				type member_N;
			} variable_name = {member_1_value, member_2_value, . . . , member_N_value };


	split variable declaration (commonly used):

				struct tag-name {	
					type member_1;
					type member_2;
					type member_3;
					. . .
					. . .
					type member_N; 
				};


				struct tag-name variable_name = {	
													member_1_value, 
													member_2_value, 
													. . ., 
													member_N_value 
													};


	Initialization restrictions:

		[1]	compile-time initialization must have the following elements:
				i.		The keyword "struct".
				ii.		The structure "tag-name". 
				iii.	The "name of the variable" to be declared.
				iv.		The assignment operator "=" .
				v.		A "set of values" for the members of the structure variable, 
							separated by "commas" and enclosed in "curly braces". 
				vi.		A terminating semicolon.

		[2]	We cannot initialize individual members inside the structure template.
		[3]	The "order of values"  must match the "order of members" in the structure definition.
		[4]	It is permitted to have a partial initialization. 
					We can initialize only the "first few members" and leave the remaining blank.
					The "uninitialized" members should be "only at the end" of the list.

				The uninitialized members will be assigned default values as follows:
					Zero for integer and floating point numbers. 
					'\0' for characters and strings. 

	
	Note:
	"Each instance" of a structure contains "its own copy of the members" of the structure. For example, 

			struct tag_name var1, var2, var3;

		The 'title' field of 'var1' is completely separate from the 'title' field of 'var2'. 
		The only relationship between var1, var2, and var3  is that they are all variables of the same type of structure.





	-----------------    "." operator to access members of a structure    -----------------

	'dot operator' or "member operator":
		must specify both "structure variable name" and the "member name" separated by a period '.' For example, 

			card.date = 1776;

		assigns the "date" field the value 1776 :	

 		C programmers often refer to the period as the dot operator. 


	Output data from a member of a structure:
		printf("Copyright date: %u", card.date);


	Input data to a member of a structure:
		scanf("%u", &card.date);

		Notice that the "&" goes before the 'structure name', not before the 'member name'.


	I/O of string and individual character of a string to/from a member of a structure: 
		
			gets(card.name);
			printf("%s", card.title);

		To access an individual character in the "title" field, simply index "title".

			printf("%c", card.title[2]);





 	---------------    Operations on individual members    ---------------	
	The precedence of the "member operator" (dot operator) is higher than all arithmetic and relational operators 
		therefore no parentheses are required. 
				
	Operations on individual members:  
		A member with the dot operator along with its structure variable can be treated like any other variable name
		 	Therefore can be manipulated using expressions and operators.  
			We can also apply increment and decrement operators to numeric type members. 
				For example  :  Consider

				struct item{
					int m; 
					float x; 
					char c;
					} ver_1, ver_2;

			We can perform the following operations:

				if(ver_1.m > 4) ver_2.m++;	 	// logical operator & increment operator
				float sum = ver_1.x + ver_2.x;





	--------------    array & Structures    --------------
	array of Structures:
		Structures can be arrayed in the same fashion as other data types. 
			For example, the following creates a 100-element array of structures of type catalog.

				struct catalog cat[100];

		Access:
				cat[0];

			To access a member within a specified structure of an array, follow the index with a period and the name of the member
				cat[33].ed = 2;


	Arrays within Structures:
		The following structure declaration is valid:

			struct marks{ 
				int number; 
				float subject[3]; 
				};

			struct marks student[2];

		These elements can be accessed using appropriate subscripts. For example, 

			student[1].subject[2];





	------------------    COPYING AND COMPARING STRUCTURE VARIABLES    ------------------
	Can assign the contents of one instance (variables) of a structure to another as long as they are both of the same type. 
	For example, this fragment is perfectly valid:

	struct s_type { 
		int a; 
		float f; 
		} var1, var2;

	var1.a = 10; 
	var2.f = 100.23; 	// assigning values to members of var1

	var2 = var1; 		// copying values of var1 to members of ver2

	After this fragment executes, "var2" will contain exactly the same thing as "var1".


	Two variables of the same structure type can be copied the same way as ordinary variables. 
		If personl and person2 belong to the same structure, then the following statements are valid:	

			person1 = person2;
			person2 = person1;


	Conditionals are not allowed on structure variables. The folloowing statements are not permitted
		person1 == person2;
		person1 != person2;


	If we need to compare them, we may do so by comparing members individually. 
		For Example following statements are valid: 

	person1.member_1 == person2.member_1;
	person1.member_2 <= person2.member_2;
	person1.member_3 != person2.member_3;





	------------------    Structures and Functions    ------------------
	
	we can pass structure values as arguments to functions. There are three methods 
	[1]	pass "each member" of the structure as an actual argument of the function call. 
			The actual arguments are then treated independently like ordinary vari¬ables. 
			But it becomes UNMANAGEABLE and INEFFICIENT when the structure size is large.


	[2]	Pass a copy of the "entire structure" to the called function. 
			Structures may be passed as parameters to functions just like any other type of value. 
			A function may also return a structure.

		Since the function is working on a copy of the structure, original remains the unchanged
		It is necessary for the function to 'return the entire structure' back to the calling function. 
		All compilers may not support passing the entire structure as a parameter.


	[3]	pass a pointer of the structure as an argument. In this case oroginal structure can be changed
			The function can access indirectly the entire structure and work on it.
			This is similar to the way arrays are passed to function. 
			This method is more efficient as compared to the second one.

	-----------    function returns structure    ----------- 
	Now we focus on the second method :

	function returns structure: 
		The general format of structure returning function

			struct structure_type_name function_name();


		The called function takes the following form:

			struct structure_type_name function_name() {
				struct structure_type_name var_name;
					. . .
				// Assignment of structure variable's members
					. . .
				return var_name;
			}
*/




/* Example 2: The following program, for example, loads the members of var1 
				with the values 100 and 123.23 and then displays them on the screen. */

#include <stdio.h>

struct s_type { 
	int i; 
	double d; 
} ;

struct s_type f(void); // function as a structure

int main(void){
	struct s_type var1; 

	var1 = f() ; // calling the structure type function and assigned to var1
	printf("%d %f", var1.i, var1.d); 

	return 0;
}

struct s_type f(void){
	struct s_type temp;

	temp.i = 100; 
	temp.d = 123.23;
	
	return temp;
}



/* 
	---------------    Structure as function parameter    --------------- 
	The general format of sending a copy of a structure to the called function is

		function_name (structure_variable_name);


	The called function takes the following form:

		data_type function_name(struct structure_type_name var_name){
			. . .
			. . .
			expression;
		}

	Remember following points: 
	I.	The called function must be declared for corresponding structure's type-name, appropriate to the data type it is expected to return. 
			For example, if it is returning a copy of the entire structure, then it must be declared as "struct" with an appropriate "tag name".

	II.	The structure variable used as the actual argument and the corresponding formal argument in the called function must be of the same struct type.

	III. The expression may be any simple variable or structure variable or an expression using simple variables.

	IV.	When a function returns a structure, it "must be assigned" to a structure of identical type in the calling function. 
			And function "must be declared" as the 'corresponding structure type function'.

	V.	The called functions must be declared in the calling function appropriately. 
*/




/* Example 3: Structure parameter to a function */
#include <stdio.h>

struct s_type { 
	int i; 
	double d; 
};

void f(struct s_type temp); // structure as function parameter

int main(void){
	struct s_type var1;

	// assigning values to struct. variable var1
	var1.i = 99; 
	var1.d = 98.6; 

	// passing structure-variable to function
	f(var1); 

	return 0;
}

// defining function that takes a structure-parameter
void f(struct s_type temp){
	printf("%d %f", temp.i, temp.d);
}



/* 
	---------------    SIZE OF STRUCTURES    --------------- 
	We normally use 
						structures, 
						unions, and 
						arrays 

	to create variables of large sizes.

	The actual size of these variables in terms of bytes may change from machine to machine.



	use sizeof for struct, union , and array:
		We may use the 'unary operator' sizeof to tell us the size of a structure (or any variable). The expression:

				sizof(struct x)  	

			will evaluate the number of bytes required to hold all the members of the structure x. 


		If y is a simple structure variable of type struct x, then the expression :	
			sizeof(y) 	
		would also give the same answer. 


		If y[n] is an array variable of type struct then sizeof(y) would give the total number of bytes the array y[n] requires.



	Find no. of elements using sizeof:
		Using sizeof we can determine the number of records in a database. For example, the expression

			sizeof(y)/sizeof(x)

		would give the number of elements in the array y.




	NOTE 
		To know the size of a structure, you should use the sizeof compile-time operator. 
			Do not try to manually add up the number of bytes in each field. 

		We need sizeof() because : in some situations, the compiler may need to align certain types of data on even word boundaries. 
			In this case, the size of the structure will be larger than the sum of its individual elements. 

		When using sizeof with a structure type, you must precede the tag name with the keyword struct, as shown in this program:
*/




/* Example 4: When using sizeof with a structure type, you must precede the tag name with the keyword struct, 
				as shown in following program. */
#include <stdio.h>

struct s_type { 
	int i; 
	char ch; 
	int *p; 
	double d; 
	} ver_s1, ver_sa[10];

int main(void){
	printf("s_type is %d bytes long", sizeof(struct s_type)); 
	printf("\n s_type variable ver_s1 is %d bytes long", sizeof(ver_s1)); 
	printf("\n s_type array variable ver_sa is %d bytes long", sizeof(ver_sa));

	return 0;
}




// ------------------    scanf with special character    ------------------
// notice the use of ':' after %d and space ' '  before %c . These are "control strings"

/* Example 5: This program demonstrates some ways to access structure members. */

#include <stdio.h>

struct s_type {
	int i;
	char ch;
	double d;
	char str[80];
} s;

int main(void){
	printf("Enter an integer: ");
	scanf("%d:", &s.i);		// notice ':'  after %d

	printf("Enter a character: ");
	scanf(" %c", &s.ch);	// notice ' '  before %c

	printf("Enter a floating point number: ");
	scanf("%lf", &s.d);

	printf("Enter a string: ");
	scanf("%s", s.str); 	// notice '&'  is not used because of being array

	printf("%d %c %f %s", s.i, s.ch, s.d, s.str);
	return 0;
}




/* Example 6: When you need to know the size of a structure, you should use the sizeof compile-time operator. 
				Do not try to manually add'up the number of bytes in each field.
				When using "sizeof" with a structure type, you must precede the tag name 
				with the keyword "struct", as shown in this program: */

#include <stdio.h>

struct s_type {
	int i;
	char ch;
	int *p;
	double d;
} s;

int main(void){
	printf("s__type is %d bytes long", sizeof(struct s_type));
	return 0;
}




/* Example 7:  Following is an improved version of the card-catalog program developed previously,
				it stores its information in a disk file called "CATALOG".

				Notice how using a 'structure' makes it easier to organize the information about each book.
				Also notice how the 'entire structure array' is written and read from disk in a 'single operation'.

                When the program begins, have it read the catalog into memory.
                Also, add an option to save the information to disk.

                Card Catalog:
                            1. Enter Books
                            2. Search by author
                            3. Search by Title
                            4. Save catalog
                            5. Quit


                If you choose Enter, have the program repeatedly input the name, author, and publisher of a book.
                    Have this process continue until the user enters a blank line for the name of the book.

                For searches, prompt the user for the specified author or title and
                then, if a match is found, display the rest of the information.

                The program should be capable of storing 100 book info.
*/

/* =-=-=-=-=-=-=-=-=-=-=            An electronic card catalog             =-=-=-=-=-=-=-=-=-=-= */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

int menu(void);
void enter(void);
void load(void);
void save(void);

void display(int i);
void author_search(void);
void title_search(void);

// instead all of these we'll use a structure
// char names[MAX][80];    // author name
// char titles[MAX][80];   // titles
// char pubs[MAX][80];     // publisher

// ---------------------    new code    ---------------------
struct catalog{
	char name[80]; 		// author name
	char title[80];		// title
	char pub[80];  		// publisher
	unsigned date; 		// copyright date
	unsigned char ed; 	// edition
} cat[MAX];
// notice how the array of "catalog structure" is created
// -------------------    new code ends    -------------------


int top = 0;    // last location used


int main(void){
    int choice;

    load();  // open to read in catalog

    do{
        choice = menu();
        switch(choice){
            case 1: enter(); // enter books
                break;
            case 2: author_search(); // search by author
                break;
            case 3: title_search(); // search by, title
                break;
            case 4: save();
                break;
        }
    } while(choice!=5);

    return 0;
}


// Get menu choice, select a choice
int menu(void){
    int i;
    char str[80];

    printf("Card Catalog:\n");
    printf("1. Enter Books\n");
    printf("2. Search by author\n");
    printf("3. Search by Title\n");
    printf("4. Save catalog\n");
    printf("5. Quit\n");

    do{
        printf("Choose your selection:\n");
        gets(str);
        i = atoi(str);
        printf("\n");
    } while(i<1 || i>5);

    return i;
}


// Following codes are modified to access structure members
// Enter books into Database (modified code 1 )
void enter(void){
    int i;
	char temp[80];

    // for( i=top; i<MAX; i++){
    //     printf("Enter author name (ENTER to quit): ");
    //     gets(names[i]);
    //     if(!*names[i]) break;

    //     printf("Enter title: ");
    //     gets(titles[i]);

    //     printf("Enter publisher: ");
    //     gets(pubs[i]);
    // }

	// notice how structre members are accessed
    for( i=top; i<MAX; i++){
        printf("Enter author name (ENTER to quit): ");
        gets(cat[i].name);
        if(!*cat[i].name) break;

        printf("Enter title: ");
        gets(cat[i].title);

        printf("Enter publisher: ");
        gets(cat[i].pub);

		printf("Enter copyright date: ");
		gets(temp);
		cat[i].date = (unsigned) atoi(temp);

		printf("Enter edition: ");
		gets(temp);
		cat[i].ed = (unsigned char) atoi(temp);
    }

    top = i;
}



// Search by author (modified code 2 )
void author_search(void){
    char name[80];
    int i, found;

    printf("Name: ");
    gets(name);

    found= 0;

    for(i=0; i<top; i++){
        if(!strcmp(name, cat[i].name)){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Search by TITLE	(modified code 3 )
void title_search(void){
    char title[80];
    int i, found;

    printf("Title: ");
    gets(title);

    found= 0;

    for(i=0; i<top; i++){
        if(!strcmp(title, cat[i].title)){
            display(i) ;
            found = 1;
            printf( "\n" ) ;
        }
    }

    if(!found) printf("Not Found\n");
}


// Display catalog entry. (modified code 4 )
void display(int i){
    printf("%s\n", cat[i].title);
    printf("By %s\n", cat[i].name);
    printf("Published by %s \n", cat[i].pub);
	printf("Copyright: %u, %u edition\n", cat[i].date, cat[i].ed);
}


// Load the catalog file (modified code 5 )
void load(void){
    FILE *fp;

    if((fp = fopen("catalog2","r"))==NULL){
        printf("Catalog file not on disk\n");
        // exit(1); we don't use it because we won't terminate the program
        return; // we use "return" to continue the "main" function
    }

	// ---------     old code    ----------
	// fread(&top, sizeof top, 1, fp);		// read count
	// fread(cat, sizeof names, 1, fp);
    // fread(titles, sizeof titles, 1, fp);
    // fread(pubs , sizeof pubs, 1, fp);


	// ---------     new code    ----------
    // read count: with ERR cheking
	if(fread(&top, sizeof top, 1, fp) != 1){
		printf("Error reading count.\n");
		exit(1);
	}

	// READ DATA: i.e array of catalog-structures,
		// "struct" keyward not necessary for "array of stucture"
	if(fread(cat, sizeof cat, 1, fp) != 1){
		printf("Error reading catalog DATA.\n");
		exit(1);
	}

    fclose(fp);
}


// save the catalog file
void save(void){
    FILE *fp;

    // open for writing
    if((fp = fopen("catalog2","w"))==NULL){
        printf("Cannot open catalog file\n");
        exit(1);
    }

	// ---------     old code    ----------
    // fwrite(&top, sizeof top, 1, fp); // write count
    // fwrite(names, sizeof names, 1, fp);
    // fwrite(titles, sizeof titles, 1, fp);
    // fwrite(pubs, sizeof pubs, 1, fp);


	// ---------     new code    ----------
    // write count: with ERR cheking
	if(fwrite(&top, sizeof top, 1, fp) != 1){
		printf("Error writing count.\n");
		exit(1);
	}

	// WRITE DATA: i.e array of catalog-structures,
		// "struct" keyward not necessary for "array of stucture"
	if(fwrite(cat, sizeof cat, 1, fp) != 1){
		printf("Error writing catalog DATA.\n");
		exit(1);
	}

    fclose(fp);
}




/* Example 7: (Manage Space: decrease 25 Times) In the preceding example, the entire catalog array is stored on disk, 
				even if the array is not full. 
				
				If you like, you can change the load() and save() routines as follows, 
				So that only structures actually holding data are stored on disk: */


// Load the catalog file (modified code 5 )
void load(void){
    FILE *fp;
	int i;

    if((fp = fopen("catalog2","rb"))==NULL){
        printf("Catalog file not on disk\n");
        return; // we use "return" to continue the "main" function
    }

    // read count: with ERR cheking
	if(fread(&top, sizeof top, 1, fp) != 1){
		printf("Error reading count.\n");
		exit(1);
	}

	// READ DATA: i.e array of catalog-structures,
		// NOTICE: "struct" keyward is necessary for each "structure"
		// also notice the use of "&" to point the structures
	for(i=0; i<top; i++) {
		// access each structure from the array
		if(fread(&cat[i], sizeof(struct catalog), 1, fp) != 1){
			printf("Error reading catalog DATA.\n");
			exit(1);
		}
	}

    fclose(fp);
}


// save the catalog file
void save(void){
    FILE *fp;
	int i;

    // open for writing
    if((fp = fopen("catalog2","wb"))==NULL){
        printf("Cannot open catalog file\n");
        exit(1);
    }

    // write count: with ERR cheking
	if(fwrite(&top, sizeof top, 1, fp) != 1){
		printf("Error writing count.\n");
		exit(1);
	}

	// WRITE DATA: i.e array of catalog-structures,
		// NOTICE: "struct" keyward is necessary for each "structure"
		// also notice the use of "&"
	for(i=0; i<top; i++) {
		// access each structure from the array
		if(fwrite(&cat[i], sizeof(struct catalog), 1, fp) != 1){
			printf("Error writing catalog DATA.\n");
			exit(1);
		}
	}

    fclose(fp);
}





// -----------    ex    -------------

Example 5: The names of structure members will not conflict with other
variables usmg the same names. Because the member name is
linked with the structure name, it is separate from other
variables of the same name. For example, this program prints
10 100 101 on the screen.
• include <stdio.h>
int main (void)
(
struct s_type {
int i;
int j;
} 5;
int i;
i = 10;312 _'fUP f
... C
)
B.i = 100;
B.j = 101;
printf("d 'd 'd', i, B.i, B.j);
return 0;
The variable i and the structure member i have no relationship
to each other.


Example 6: As stated earlier, a: function may return a structure to the calling
procedure. The following program, for example, loads the
members of...arl with the values 100 and 123.23 and then
displays them on the screen:
'include <stdio.h>
at.....:t a_type (
int i;
double d;
) ;
st....ct s_type f(void);
int main (void)
(
struct s_type varl;
varl ~ fO;
printf("d 'f', varl.i, varl.d);
return 0;
)
.truct s_type f(void)
(
)
struct s_type temp;
temp. i = 100;
temp.d = 123.23;
return temp;
•STRUCTURES AND UNIONS 313
lal MASTER STRUCTURE BASICS


Example 7: This program passes a structure to a function:
'include <stdio.h>
struct s_type {
int i;
double d:
} ;
void f(struct s_type temp);
int main(void)
{
}
struct s_type varl;
varl.i = 99;
varl.d = 98.6;
f (varl);
return 0;
void f(struct s_type temp)
{
printf(M%d tf M , temp.i. temp.d);
)
.:1'

long 1;
char str[aO];
} 5;
~ = 10:
3. On your own, examine the header file STDIO.H and look at how
the FILE structure is defined.



// ===========    Exs    ============
j* A simple computerized telephone book. */
*include <stdio.h>
iinclude <string.h>
.include <stdlib.h>
*define MAX 100
struct phone_type {
char name (40J ;
int areacode;
char number (9 J ;
) phone (MAXJ ;
int loc=O;
int menu (void) ;
void enter(void);
void load (void) ;
void save (void) ;
void find(voidl;
int main (void)
(
int choice;
do {
choice = menu ( ) :
switch (choice) (
case 1: enter();
break:
)
case 2: find () :
break;
case 3: save () :
break;
case 4: load () :
) while(choice!=S):
return 0:
/* Get menu choice . */
menu (void)
{
J
int i;
char .tr(80J:
printf (-1 . Enter names and numbers\n·);.
printf("2. Find numbers\n"):
printf(-3. Save directory to disk\n-);
printf(-'. Load directory from disk\n-);
printf("S. Quit\n"):
do (
printf("Bnter your choice: "):
geta(atr):
i • atoi (str):
print! ("\rI") :
J while (i<l II i>5):
return i;
,
,
void enter(void)
{
,
char temp (80J :
tor (: loc<lOO: locH) (
if(loc<lOO) {
printf (-Enter name: .):
gets(phone[locJ .name):
if(!*phone(loc).name) break;
printf(-Enter area code: .);
gets (temp);
phone {loc] .areacode = atoi(temp);
printf!"Enter number: .);
gets (phone [loc] .number) ;
,a'
void find{void}
(
)
char name [801 ;
int i;
printf("Enter name: .);
gets (name) ;
if(!*name) return;
for(i=O; i<100; iT+,
if (!strcmp(name. phone[i] .name»
printf("%s !%d) %s\n", phone[i] .name,
phone[i] .areacode. phone(iJ.n~~er);
void load {void)
(
)
FILE 'fp;
if«fp = fopen("phone", "r"ll==NULL) (
printf("Cannot open file.\n");
exit(l);
)
loe = 0;
while (! feof (fp» (
)
fseanf(fp, "'s%d's", phone[loe) . name,
&phone{loc1.areacode. phone[loc] .number);
loc++;
felose (fp) :
void save (void)
{
FILE "fp;
int i;
if ((fp = topen ("phone", "W")) -=NULL) (
printf("Cannot open file. In");
eXit(l);
)
for(iIl:O; i<loc; i++) (
)
fprintf(fp, "'s 'd '8" phone [i) .name ,
Phone(iJ.areacode, phone[i).number);
fclose (fp) ;



2. The variable i is a member of structure a_type. Therefore, it
cannot be used by itself. Instead, it must be accessed using 8 and
the dot operator, as shown here.
s.i ~ 10;



